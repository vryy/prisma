//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//  Date:            16 Aug 2026
//


#if !defined(KRATOS_LAWSON_NNLS_SOLVER_H_INCLUDED )
#define  KRATOS_LAWSON_NNLS_SOLVER_H_INCLUDED

// System includes
#include <string>
#include <iostream>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/ublas_interface.h"

namespace Kratos
{

namespace Lawson
{

#ifdef _WIN32
    // Intel Fortran compiler on Windows does not append underscores to names
    // and also uses uppercase for the names
#define nnls_wrapper NNLS
#else
#define nnls_wrapper nnls_
#endif

extern "C" void nnls_wrapper(double* A, int* MDA, int* M, int* N, double* B, double* X,
    double* RNORM, double* W, double* ZZ, int* INDEX, int* MODE);

/** Non-negative least square solver based on NNLS
 * The method by lawson.f does not use QR factorization, so the results are not sparse.
 * But the residuals are very good.
 * This can be good for problem requiring high accuracy, such as moment-fitting.
 */
class NnlsSolver
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of NnlsSolver
    KRATOS_CLASS_POINTER_DEFINITION(NnlsSolver);

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    NnlsSolver() {}

    /// Destructor.
    virtual ~NnlsSolver() {}

    ///@}
    ///@name Operations
    ///@{

    static int Solve(Matrix& rA, Vector& rX, Vector& rB, int echo_level)
    {
        /* initialization */
        int M = static_cast<int>(rA.size1());
        int N = static_cast<int>(rA.size2());
        int MDA = M;

        std::vector<double> dA(M * N);
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                dA[j * M + i] = rA(i, j); // column-major order

        std::vector<double> dB(M);
        for (int i = 0; i < M; ++i)
            dB[i] = rB(i);

        std::vector<double> dX(N, 0.0);
        double rnorm = 0.0;
        std::vector<double> w(N, 0.0);
        std::vector<double> zz(M, 0.0);
        int mode = -1;
        std::vector<int> index(N, 0);

        nnls_wrapper(dA.data(), &MDA, &M, &N, dB.data(), dX.data(), &rnorm,
                w.data(), zz.data(), index.data(), &mode);

        if (rX.size() != N)
            rX.resize(N, false);
        for (std::size_t i = 0; i < N; ++i)
            rX(i) = dX[i];

        if (echo_level > 0)
        {
            if (mode == 1)
                std::cout << "NNLS: optimization successful, rnorm = " << rnorm << std::endl;
            else if (mode == 2)
                std::cout << "NNLS: The dimensions of the problem are bad, either M <= 0 or N <= 0" << std::endl;
            else if (mode == 3)
                std::cout << "NNLS: iteration count exceeded. More than " << 3*N << " iterations" << std::endl;
        }

        return mode;
    }

    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "Nonnegative Least Square Solver based on Lawson";
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

}; // Class NnlsSolver

///@}

///@name Input and output
///@{

/// input stream function
inline std::istream& operator >> (std::istream& rIStream,
                                  NnlsSolver& rThis)
{
    return rIStream;
}

/// output stream function
inline std::ostream& operator << (std::ostream& rOStream,
                                  const NnlsSolver& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

} // namespace Lawson

} // namespace Kratos.

#endif // KRATOS_LAWSON_NNLS_SOLVER_H_INCLUDED  defined
