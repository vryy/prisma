//    |  /           |
//    ' /   __| _` | __|  _  \  __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//

// System includes

// External includes

// Project includes
#include "includes/define_python.h"
#include "includes/hardening_law.h"
#include "includes/piecewise_linear_hardening_law.h"
#include "python/add_hardening_laws_to_python.h"

namespace Kratos
{

namespace Python
{

using namespace boost::python;

void HardeningLaw_Assign(HardeningLaw& rDummy,
    Variable<HardeningLaw::Pointer>& rThisVariable, HardeningLaw::Pointer pLaw, Properties::Pointer pProperties)
{
    rDummy.Assign(rThisVariable, pLaw, pProperties);
}

void AddHardeningLawsToPython()
{
    class_<Variable<HardeningLaw::Pointer>, bases<VariableData>, boost::noncopyable >( "HardeningLawVariable", no_init );

    double(HardeningLaw::*pointer_to_GetValue)(const double) const = &HardeningLaw::GetValue;
    double(HardeningLaw::*pointer_to_GetDerivative)(const double) const = &HardeningLaw::GetDerivative;

    class_< HardeningLaw, bases< Flags >, boost::noncopyable >
    ( "HardeningLaw", init<>() )
    .def("GetValue", pointer_to_GetValue)
    .def("GetDerivative", pointer_to_GetDerivative)
    .def("Assign", &HardeningLaw_Assign)
    ;

    class_< PiecewiseLinearHardeningLaw, bases< HardeningLaw >, boost::noncopyable >
    ( "PiecewiseLinearHardeningLaw", init<>() )
    .def("AddPoint", &PiecewiseLinearHardeningLaw::AddPoint)
    ;
}

}  // namespace Python.

}  // namespace Kratos.
