//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//  Date:            13 Feb 2017
//


#if !defined(KRATOS_LAPACK_LS_SOLVER_H_INCLUDED )
#define  KRATOS_LAPACK_LS_SOLVER_H_INCLUDED



// System includes
#include <string>
#include <iostream>


// External includes

// Project includes
#include "includes/define.h"
#include "includes/matrix_vector_adapter.h"

namespace Kratos
{
///@addtogroup KratosCore
///@{

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

// definition for LAPACK functions
extern "C" void dgelsy_(const int* M, const int* N, const int* NRHS, double* A, const int* LDA,
                        double* B, const int* LDB, int* JPVT, const double* RCOND, int* RANK,
                        double* WORK, const int* LWORK, int* INFO);

extern "C" void dgelss_(const int* M, const int* N, const int* NRHS, double* A, const int* LDA,
                        double* B, const int* LDB, double* S, const double* RCOND, int* RANK,
                        double* WORK, const int* LWORK, int* INFO);

extern "C" double dlange_(const char* NORM, const int* M, const int* N, const double* A, const int* LDA, double* WORK);

extern "C" void dgetrf_(const int* M, const int* N, double* A, const int* LDA, int* IPIV, int* INFO);

extern "C" void dgecon_(const char* NORM, const int* N, const double* A, const int* LDA, const double* ANORM,
                        double* RCOND, double* WORK, int* IWORK, int* INFO);

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}
///@name Kratos Classes
///@{

/** Least square solver based on LAPACK
*/
class LapackLsSolver
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of LapackLsSolver
    KRATOS_CLASS_POINTER_DEFINITION(LapackLsSolver);

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    LapackLsSolver() {}

    /// Destructor.
    virtual ~LapackLsSolver() {}

    ///@}
    ///@name Operators
    ///@{


    ///@}
    ///@name Operations
    ///@{

    /// Estimate the reciprocal condition number of the matrix
    static double EstimateRCond(Matrix& rA, const std::string& norm_type = "1")
    {
        int M = static_cast<int>(rA.size1());
        int N = static_cast<int>(rA.size2());
        int LDA = M;
        int INFO;

        std::vector<double> A(M * N);
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                A[j * M + i] = rA(i, j); // column-major order

        std::vector<double> WORK(4 * N);
        double anorm = dlange_(norm_type.c_str(), &M, &N, A.data(), &LDA, WORK.data());

        std::vector<int> IPIV(std::min(M, N));
        dgetrf_(&M, &N, A.data(), &LDA, IPIV.data(), &INFO);

        std::vector<int> IWORK(N);
        double rcond;
        LDA = N;
        dgecon_(norm_type.c_str(), &N, A.data(), &LDA, &anorm, &rcond, WORK.data(), IWORK.data(), &INFO);

        return rcond;
    }

    /// Adapter function to solve the unconstrained non-square linear system using least square method.
    static int Solve(Matrix& rA, Vector& rX, Vector& rB, const std::string& variant = "QR")
    {
        double rcond_est = EstimateRCond(rA);
        if (variant == "QR")
            return SolveDGELSY(rA, rX, rB, rcond_est);
        else if (variant == "SVD")
            return SolveDGELSS(rA, rX, rB, rcond_est);
        else
            return -1;
    }

    /// Solve the unconstrained non-square linear system using least square method.
    /// This function uses the LAPACK routine DGELSY, which is based on QR factorization.
    /// On the input, an estimate of the reciprocal condition number of the matrix is required.
    /// This can be obtained by calling the function EstimateRCond() of this class.
    static int SolveDGELSY(Matrix& rA, Vector& rX, Vector& rB, const double rcond_est = 0.01)
    {
        int M = static_cast<int>(rA.size1());
        int N = static_cast<int>(rA.size2());
        int NRHS = 1;

        std::vector<double> A(M * N);
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                A[j * M + i] = rA(i, j); // column-major order

        int LDA = M;
        int INFO;
        int LDB = std::max(M, N);
        std::vector<double> b(LDB);
        for (int i = 0; i < M; ++i) { b[i] = rB(i); }
        std::vector<int> JPVT(N);
        for (int i = 0; i < N; ++i) JPVT[i] = 0;
        double RCOND = rcond_est;
        int RANK;
        int LWORK = -1; //std::max(std::min(M, N) + 3*N + 1, 2*std::min(M, N) + 1);
        double WORKS;

        // estimate the size of working array
        dgelsy_(&M, &N, &NRHS, A.data(), &LDA, b.data(), &LDB, JPVT.data(), &RCOND, &RANK, &WORKS, &LWORK, &INFO);
        LWORK = (int) WORKS;

        std::vector<double> WORK(LWORK);

        dgelsy_(&M, &N, &NRHS, A.data(), &LDA, b.data(), &LDB, JPVT.data(), &RCOND, &RANK, WORK.data(), &LWORK, &INFO);

        if (rX.size() != N)
            rX.resize(N, false);
        for (int i = 0; i < N; ++i)
            rX(i) = b[i];

        return 0;
    }

    /// Solve the unconstrained non-square linear system using least square method.
    /// This function uses the LAPACK routine DGELSS, which is based on SVD factorization.
    /// On the input, an estimate of the reciprocal condition number of the matrix is required.
    /// This can be obtained by calling the function EstimateRCond() of this class.
    static int SolveDGELSS(Matrix& rA, Vector& rX, Vector& rB, const double rcond_est = 1.0e-10)
    {
        int M = static_cast<int>(rA.size1());
        int N = static_cast<int>(rA.size2());
        int NRHS = 1;

        std::vector<double> A(M * N);
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                A[j * M + i] = rA(i, j); // column-major order

        int LDA = M;
        int INFO;
        int LDB = std::max(M, N);
        std::vector<double> b(LDB);
        for (int i = 0; i < M; ++i) { b[i] = rB(i); }
        std::vector<double> S(std::min(M, N));
        double RCOND = rcond_est;
        int RANK;
        int LWORK = -1;
        double WORKS;

        // estimate the size of working array
        dgelss_(&M, &N, &NRHS, A.data(), &LDA, b.data(), &LDB, S.data(), &RCOND, &RANK, &WORKS, &LWORK, &INFO);
        LWORK = (int) WORKS;

        std::vector<double> WORK(LWORK);

        dgelss_(&M, &N, &NRHS, A.data(), &LDA, b.data(), &LDB, S.data(), &RCOND, &RANK, WORK.data(), &LWORK, &INFO);

        if (rX.size() != N)
            rX.resize(N, false);
        for (int i = 0; i < N; ++i)
            rX(i) = b[i];

        return 0;
    }

    ///@}
    ///@name Access
    ///@{


    ///@}
    ///@name Inquiry
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "Least Square Solver based on LAPACK";
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << Info();
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {
    }

    ///@}
    ///@name Friends
    ///@{


    ///@}

protected:
    ///@name Protected static Member Variables
    ///@{


    ///@}
    ///@name Protected member Variables
    ///@{


    ///@}
    ///@name Protected Operators
    ///@{


    ///@}
    ///@name Protected Operations
    ///@{


    ///@}
    ///@name Protected  Access
    ///@{


    ///@}
    ///@name Protected Inquiry
    ///@{


    ///@}
    ///@name Protected LifeCycle
    ///@{


    ///@}

private:
    ///@name Static Member Variables
    ///@{


    ///@}
    ///@name Member Variables
    ///@{


    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{


    ///@}
    ///@name Private  Access
    ///@{


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{

    /// Assignment operator.
    LapackLsSolver& operator=(LapackLsSolver const& rOther);

    /// Copy constructor.
    LapackLsSolver(LapackLsSolver const& rOther);

    ///@}

}; // Class LapackLsSolver

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{

/// input stream function
inline std::istream& operator >> (std::istream& rIStream,
                                  LapackLsSolver& rThis)
{
    return rIStream;
}

/// output stream function
inline std::ostream& operator << (std::ostream& rOStream,
                                  const LapackLsSolver& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

///@} addtogroup block

}  // namespace Kratos.

#endif // KRATOS_LAPACK_LS_SOLVER_H_INCLUDED  defined
