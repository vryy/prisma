//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//  Date:            20 Aug 2026
//


#if !defined(KRATOS_LAPACK_NNLS_SOLVER_H_INCLUDED )
#define  KRATOS_LAPACK_NNLS_SOLVER_H_INCLUDED



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

extern "C" void dgelsd_(const int* M, const int* N, const int* NRHS, double* A, const int* LDA,
                        double* B, const int* LDB, double* S, const double* RCOND, int* RANK,
                        double* WORK, const int* LWORK, int* IWORK, int* INFO);

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}
///@name Kratos Classes
///@{

/** Non-negative least square solver based on LAPACK
 * Because the QR factorization is used, it will lead to sparse solution if matrix A
 * is rank deficient. This can be beneficial for projection-based POD problem like ECSW.
 * Ref: lsqnonneg (Octave)
 */
class LapackNnlsSolver
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of LapackNnlsSolver
    KRATOS_CLASS_POINTER_DEFINITION(LapackNnlsSolver);

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    LapackNnlsSolver() {}

    /// Destructor.
    virtual ~LapackNnlsSolver() {}

    ///@}
    ///@name Operators
    ///@{


    ///@}
    ///@name Operations
    ///@{

    // LAPACK wrapper using DGELSY (Complete Orthogonal Factorization via QR with Pivoting)
    static Vector SolveDGELSY(const Matrix& rA, const std::vector<int>& p, const Vector& rB) {
        int m = rA.size1();
        int k = p.size();
        if (k == 0) return Vector(0);

        // Pack active submatrix columns into continuous column-major array
        std::vector<double> A(m * k);
        for (int j = 0; j < k; ++j) {
            for (int i = 0; i < m; ++i) {
                A[i + j * m] = rA(i, p[j]);
            }
        }

        int ldb = std::max(m, k);
        std::vector<double> B(ldb, 0.0);
        for (int i = 0; i < m; ++i) B[i] = rB(i);

        int nrhs = 1, lda = m, rank = 0, info = 0;
        double rcond = -1.0; // Automatically use machine epsilon for rank detection

        // Pivoting vector: 0 means free to pivot
        std::vector<int> jpvt(k, 0);

        // Workspace query
        double query_work;
        int lwork = -1;
        dgelsy_(&m, &k, &nrhs, A.data(), &lda, B.data(), &ldb,
                jpvt.data(), &rcond, &rank, &query_work, &lwork, &info);

        lwork = static_cast<int>(query_work);
        std::vector<double> work(lwork);

        // Solve minimum-norm problem using DGELSY
        dgelsy_(&m, &k, &nrhs, A.data(), &lda, B.data(), &ldb,
                jpvt.data(), &rcond, &rank, work.data(), &lwork, &info);

        Vector xtmp(k);
        for (int i = 0; i < k; ++i) xtmp(i) = B[i];
        return xtmp;
    }

    // LAPACK wrapper handling rank deficiency via SVD (dgelsd)
    static Vector SolveDGELSD(const Matrix& rA, const std::vector<int>& p, const Vector& rB)
    {
        int m = rA.size1();
        int k = p.size();
        if (k == 0) return Vector(0);

        // Flatten selected active columns into C-array (Column-Major for LAPACK)
        std::vector<double> A(m * k);
        for (int j = 0; j < k; ++j) {
            for (int i = 0; i < m; ++i) {
                A[i + j * m] = rA(i, p[j]);
            }
        }

        int ldb = std::max(m, k);
        std::vector<double> B(ldb, 0.0);
        for (int i = 0; i < m; ++i) B[i] = rB(i);

        int nrhs = 1, lda = m, rank = 0, info = 0;
        double rcond = -1.0; // Use machine precision threshold for rank determination
        std::vector<double> s(std::min(m, k));

        // Workspace query
        double query_work;
        int lwork = -1;
        std::vector<int> iwork(1);

        dgelsd_(&m, &k, &nrhs, A.data(), &lda, B.data(), &ldb,
                s.data(), &rcond, &rank, &query_work, &lwork, iwork.data(), &info);

        lwork = static_cast<int>(query_work);
        std::vector<double> work(lwork);

        // Allocate integer workspace based on DGELSD requirements
        int min_dim = std::min(m, k);
        int nlvl = std::max(0, static_cast<int>(std::log2(min_dim)) + 1);
        iwork.resize(std::max(1, 3 * min_dim * nlvl + 11 * min_dim));

        // Solve minimum-norm problem for rank-deficient submatrix
        dgelsd_(&m, &k, &nrhs, A.data(), &lda, B.data(), &ldb,
                s.data(), &rcond, &rank, work.data(), &lwork, iwork.data(), &info);

        Vector xtmp(k);
        for (int i = 0; i < k; ++i) xtmp(i) = B[i];
        return xtmp;
    }

    /// Adapter function to solve the unconstrained non-square linear system using least square method.
    static int Solve(Matrix& rA, Vector& rX, Vector& rB,
            const std::string& variant="QR", int max_iter=1000, double tolx=1e-13)
    {
        int m = rA.size1();
        int n = rA.size2();

        if (rX.size() != n)
            rX.resize(n, false);

        for (int i = 0; i < n; ++i) rX(i) = 0.0;
        std::vector<int> p;

        if (tolx < 0) {
            double eps = 2.220446049250313e-16;
            double normA = norm_1(rA);
            tolx = 10.0 * eps * normA * m;
        }

        int iter = 0;
        while (iter < max_iter) {
            while (iter < max_iter) {
                iter++;
                if (p.empty()) break;

                Vector xtmp;
                if (variant == "QR")
                    xtmp = SolveDGELSY(rA, p, rB);
                else if (variant == "SVD")
                    xtmp = SolveDGELSD(rA, p, rB);
                else
                    KRATOS_ERROR << "Unsupported variant " << variant;

                std::vector<int> idx;
                for (int i = 0; i < xtmp.size(); ++i) {
                    if (xtmp(i) <= 0.0) idx.push_back(i);
                }

                if (idx.empty()) {
                    for (int i = 0; i < n; ++i) rX(i) = 0.0;
                    for (size_t i = 0; i < p.size(); ++i) rX(p[i]) = xtmp(i);
                    break;
                }

                double alpha = 1.0;
                for (int i : idx) {
                    double sf = rX(p[i]) / (rX(p[i]) - xtmp(i));
                    if (sf < alpha) alpha = sf;
                }

                for (size_t i = 0; i < p.size(); ++i) {
                    rX(p[i]) += alpha * (xtmp(i) - rX(p[i]));
                }

                std::vector<int> new_p;
                for (size_t i = 0; i < p.size(); ++i) {
                    if (rX(p[i]) > 1e-13) {
                        new_p.push_back(p[i]);
                    } else {
                        rX(p[i]) = 0.0;
                    }
                }
                p = new_p;
            }

            // Gradient calculation: w = rA' * (rB - rA*rX)
            Vector residual(m);
            for (int i = 0; i < m; ++i) {
                residual(i) = rB(i);
                for (int j = 0; j < n; ++j) residual(i) -= rA(i, j) * rX(j);
            }

            Vector w(n);
            for (int j = 0; j < n; ++j) {
                w(j) = 0.0;
                for (int i = 0; i < m; ++i) w(j) += rA(i, j) * residual(i);
            }

            for (int idx_p : p) w(idx_p) = 0.0;

            double max_w = -1e308;
            int max_idx = -1;
            for (int j = 0; j < n; ++j) {
                if (std::find(p.begin(), p.end(), j) == p.end() && w(j) > max_w) {
                    max_w = w(j);
                    max_idx = j;
                }
            }

            if (max_w <= tolx || max_idx == -1) break;

            p.push_back(max_idx);
            std::sort(p.begin(), p.end());
        }

        if (iter < max_iter)
            return 0;
        else
            return -1;
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
    LapackNnlsSolver& operator=(LapackNnlsSolver const& rOther);

    /// Copy constructor.
    LapackNnlsSolver(LapackNnlsSolver const& rOther);

    ///@}

}; // Class LapackNnlsSolver

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{

/// input stream function
inline std::istream& operator >> (std::istream& rIStream,
                                  LapackNnlsSolver& rThis)
{
    return rIStream;
}

/// output stream function
inline std::ostream& operator << (std::ostream& rOStream,
                                  const LapackNnlsSolver& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

///@} addtogroup block

}  // namespace Kratos.

#endif // KRATOS_LAPACK_NNLS_SOLVER_H_INCLUDED  defined
