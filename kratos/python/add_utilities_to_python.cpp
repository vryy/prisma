//
//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                     Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//


// System includes

// External includes
#include <boost/python.hpp>


// Project includes
#include "includes/define.h"
#include "python/add_utilities_to_python.h"
#include "utilities/openmp_utils.h"
#include "utilities/constraint_utilities.h"
#include "utilities/timer.h"
#include "utilities/geometry_tester.h"


namespace Kratos
{

    namespace Python
    {

        template<class TConstraintUtilitiesType>
        void ConstraintUtilities_PrintConstraint(TConstraintUtilitiesType& rDummy,
                const typename TConstraintUtilitiesType::MasterSlaveConstraintType& rConstraint)
        {
            rDummy.PrintConstraint(rConstraint);
        }

        void AddUtilitiesToPython()
        {
            using namespace boost::python;

            class_<Timer> ("Timer", init<>())
                    .add_property("PrintOnScreen", &Timer::GetPrintOnScreen, &Timer::SetPrintOnScreen)
                    .def("Start", &Timer::Start)
                    .def("Stop", &Timer::Stop)
                    .staticmethod("Start")
                    .staticmethod("Stop")
                    //         .def("PrintTimingInformation",Timer::PrintTimingInformation)
                    .def(self_ns::str(self))
                    ;

            class_<OpenMPUtils> ("OpenMPUtils", init<>())
                    .def("SetNumThreads", &OpenMPUtils::SetNumThreads)
                    .staticmethod("SetNumThreads")
                    .def("PrintOMPInfo", &OpenMPUtils::PrintOMPInfo)
                    .staticmethod("PrintOMPInfo")
                    ;

            class_<GeometryTesterUtility, boost::noncopyable> ("GeometryTesterUtility", init< >())
                    .def("RunTest", &GeometryTesterUtility::RunTest)
                    ;

            class_<ConstraintUtilities<ModelPart>, boost::noncopyable > ("ConstraintUtilities", init< >())
                    .def("PrintConstraint", &ConstraintUtilities_PrintConstraint<ConstraintUtilities<ModelPart> >)
                    ;

            class_<ConstraintUtilities<ComplexModelPart>, boost::noncopyable > ("ComplexConstraintUtilities", init< >())
                    .def("PrintConstraint", &ConstraintUtilities_PrintConstraint<ConstraintUtilities<ComplexModelPart> >)
                    ;
        }

    } // namespace Python.

} // Namespace Kratos

