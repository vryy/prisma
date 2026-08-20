//
//   Project Name:        Kratos
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: 15 Aug 2026 $
//
//

// External includes
#include <boost/python.hpp>

// Project includes
#include "add_least_square_solvers_to_python.h"
#ifdef KRATOS_USE_BLAS_LAPACK
#include "least_square_solvers/lapack_ls_solver.h"
#include "least_square_solvers/lapack_nnls_solver.h"
#endif
#ifdef KRATOS_USE_SS_NNLS
#include "least_square_solvers/ss_nnls_solver.h"
#endif
#ifdef KRATOS_USE_LAWSON
#include "least_square_solvers/lawson_nnls_solver.h"
#endif

namespace Kratos
{

namespace Python
{

using namespace boost::python;

void AddLeastSquareSolversToPython()
{
#ifdef KRATOS_USE_BLAS_LAPACK
    class_<LapackLsSolver, LapackLsSolver::Pointer, boost::noncopyable>
    ("LapackLsSolver", init<>())
    .def("EstimateRCond", &LapackLsSolver::EstimateRCond, args("A", "norm_type"), "Estimate the reciprocal condition number of matrix A")
        .staticmethod("EstimateRCond")
    .def("Solve", &LapackLsSolver::Solve, args("A", "X", "B", "variant"), "Solve the unconstrained least square problem Ax=B")
        .staticmethod("Solve")
    ;

    class_<LapackNnlsSolver, LapackNnlsSolver::Pointer, boost::noncopyable>
    ("LapackNnlsSolver", init<>())
    .def("Solve", &LapackNnlsSolver::Solve, args("A", "X", "B", "variant", "max_iter", "tolerance"), "Solve the non-negative least square problem Ax=B")
        .staticmethod("Solve")
    ;
#endif

#ifdef KRATOS_USE_SS_NNLS
    class_<SS::NnlsSolver, SS::NnlsSolver::Pointer, boost::noncopyable>
    ("SsNnlsSolver", init<>())
    .def("Solve", &SS::NnlsSolver::Solve, args("A", "X", "B", "tolerance", "maxit", "echo_level"), "Solve the non-negative least square problem Ax=B")
        .staticmethod("Solve")
    ;
#endif

#ifdef KRATOS_USE_LAWSON
    class_<Lawson::NnlsSolver, Lawson::NnlsSolver::Pointer, boost::noncopyable>
    ("LawsonNnlsSolver", init<>())
    .def("Solve", &Lawson::NnlsSolver::Solve, args("A", "X", "B", "echo_level"), "Solve the non-negative least square problem Ax=B")
        .staticmethod("Solve")
    ;
#endif
}

} // namespace Python.

} // namespace Kratos.
