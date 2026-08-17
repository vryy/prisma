//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         finite_cell_application/LICENSE.txt
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//  Date:            27 Jul 2018
//


#if !defined(KRATOS_SS_NNLS_SOLVER_H_INCLUDED )
#define  KRATOS_SS_NNLS_SOLVER_H_INCLUDED

// System includes
#include <string>
#include <iostream>

// External includes
#include "nnls/nnls.h"

// Project includes
#include "includes/define.h"
#include "includes/ublas_interface.h"

namespace Kratos
{

namespace SS
{

/** Non-negative least square solver based on NNLS
 * REF: http://suvrit.de/work/soft/nnls.html
 *      D. Kim, S. Sra, I. S. Dhillon. "A non-monotonic method for large-scale non-negative least squares." Optimization Methods and Software, Jan. 2012
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

    static int Solve(Matrix& rA, Vector& rX, Vector& rB, double tol, int maxit, int echo_level)
    {
        /* initialization */
        std::size_t M = rA.size1();
        std::size_t N = rA.size2();

        double* dA = new double[M * N];
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                dA[i * N + j] = rA(i, j); // row-major order

        nsNNLS::matrix* A;
        nsNNLS::vector* b;
        nsNNLS::vector* x;
        nsNNLS::nnls*   solver;
        int     flag;

        A = new nsNNLS::denseMatrix(M, N, dA);

        b = new nsNNLS::vector(M);
        for (std::size_t i = 0; i < M; ++i)
            b->set(i, rB(i));

        solver = new nsNNLS::nnls(A, b, maxit);
        solver->setPgTol(tol);

        /* solve - optimize */
        if (echo_level > 0) { std::cout << "Optimizing...\n"; }
        flag = solver->optimize();
        if (echo_level > 0) { std::cout << "Done!\n"; }

        if (echo_level > 1) { printf("Optimization time: %.2e seconds\n", solver->getOptimizationTime()); }

        if (flag < 0)
        {
            KRATOS_ERROR << "NNLS: Solver terminated with error flag " << flag;
            return flag;
        }

        x = solver->getSolution();

        if (echo_level > 2) { solver->saveStats(std::cout); }

        if (rX.size() != N)
            rX.resize(N, false);
        for (std::size_t i = 0; i < N; ++i)
            rX(i) = x->get(i);

        delete solver;
        delete A, b, x;
        delete dA;

        return 0;
    }

    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "Nonnegative Least Square Solver based on NNLS";
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

} // namespace SS

} // namespace Kratos.

#endif // KRATOS_SS_NNLS_SOLVER_H_INCLUDED  defined
