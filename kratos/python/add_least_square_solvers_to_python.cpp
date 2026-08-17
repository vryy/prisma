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
#include "least_square_solvers/lapack_ls_solver.h"
#ifdef KRATOS_USE_SS_NNLS
#include "least_square_solvers/ss_nnls_solver.h"
#endif

namespace Kratos
{

namespace Python
{

using namespace boost::python;

void AddLeastSquareSolversToPython()
{
    class_<LapackLsSolver, LapackLsSolver::Pointer, boost::noncopyable>
    ("LapackLsSolver", init<>())
    ;

#ifdef KRATOS_USE_SS_NNLS
    class_<SS::NnlsSolver, SS::NnlsSolver::Pointer, boost::noncopyable>
    ("SsNnlsSolver", init<>())
    .def("Solve", &SS::NnlsSolver::Solve, args("A", "X", "B", "tolerance", "maxit", "echo_level"), "Solve the non-negative least square problem Ax=B")
        .staticmethod("Solve")
    ;
#endif
}

} // namespace Python.

} // namespace Kratos.
