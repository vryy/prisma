//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//


// System includes

// External includes
#include <boost/python.hpp>


// Project includes
#include "includes/define.h"
#include "processes/process.h"
#include "python/add_processes_to_python.h"
#include "processes/find_nodal_neighbours_process.h"
#include "processes/find_conditions_neighbours_process.h"
#include "processes/find_elements_neighbours_process.h"

namespace Kratos
{

namespace Python
{

void  AddProcessesToPython()
{
    using namespace boost::python;

    class_<Process, Process::Pointer>("Process")
    .def("Execute", &Process::Execute)
    .def("ExecuteInitialize", &Process::ExecuteInitialize)
    .def("ExecuteBeforeSolutionLoop", &Process::ExecuteBeforeSolutionLoop)
    .def("ExecuteInitializeSolutionStep", &Process::ExecuteInitializeSolutionStep)
    .def("ExecuteFinalizeSolutionStep", &Process::ExecuteFinalizeSolutionStep)
    .def("ExecuteBeforeOutputStep", &Process::ExecuteBeforeOutputStep)
    .def("ExecuteAfterOutputStep", &Process::ExecuteAfterOutputStep)
    .def("ExecuteFinalize", &Process::ExecuteFinalize)
    .def(self_ns::str(self))
    ;

    class_<FindNodalNeighboursProcess, bases<Process> >("FindNodalNeighboursProcess",
            init<ModelPart&, int, int>())
    .def("ClearNeighbours",&FindNodalNeighboursProcess::ClearNeighbours)
    ;

    class_<FindConditionsNeighboursProcess, bases<Process> >("FindConditionsNeighboursProcess",
            init<ModelPart&, int, int>())
    .def("ClearNeighbours",&FindConditionsNeighboursProcess::ClearNeighbours)
    ;

    class_<FindElementalNeighboursProcess, bases<Process> >("FindElementalNeighboursProcess",
            init<ModelPart&, int, int>())
    .def("ClearNeighbours",&FindElementalNeighboursProcess::ClearNeighbours)
    ;
}

}  // namespace Python.

} // Namespace Kratos
