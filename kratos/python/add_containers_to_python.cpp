// Kratos Multi-Physics
//
// Copyright (c) 2016 Pooyan Dadvand, Riccardo Rossi, CIMNE (International Center for Numerical Methods in Engineering)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
// 	-	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// 	-	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
// 		in the documentation and/or other materials provided with the distribution.
// 	-	All advertising materials mentioning features or use of this software must display the following acknowledgement:
// 			This product includes Kratos Multi-Physics technology.
// 	-	Neither the name of the CIMNE nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED ANDON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THISSOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



// System includes

// External includes
#include <boost/python.hpp>


// Project includes
#include "includes/define.h"
#include "includes/ublas_interface.h"
#include "containers/data_value_container.h"
//#include "containers/hash_data_value_container.h"
#include "containers/variables_list_data_value_container.h"
#include "containers/fix_data_value_container.h"
#include "containers/vector_component_adaptor.h"
#include "containers/flags.h"
//#include "containers/all_variables_data_value_container.h"
#include "includes/kratos_flags.h"
#include "includes/variables.h"
#include "includes/constitutive_law.h"
#include "includes/convection_diffusion_settings.h"
#include "includes/radiation_settings.h"
#include "python/variable_indexing_python.h"
#include "python/vector_python_interface.h"
#include "python/vector_scalar_operator_python.h"
#include "python/vector_vector_operator_python.h"
#include "python/bounded_vector_python_interface.h"
#include "python/add_containers_to_python.h"


#ifdef KRATOS_REGISTER_IN_PYTHON_FLAG_IMPLEMENTATION
#undef KRATOS_REGISTER_IN_PYTHON_FLAG_IMPLEMENTATION
#endif
#define KRATOS_REGISTER_IN_PYTHON_FLAG_IMPLEMENTATION(flag) \
 scope().attr(#flag) = boost::ref(flag)      \

#ifdef KRATOS_REGISTER_IN_PYTHON_FLAG
#undef KRATOS_REGISTER_IN_PYTHON_FLAG
#endif
#define KRATOS_REGISTER_IN_PYTHON_FLAG(flag) \
    KRATOS_REGISTER_IN_PYTHON_FLAG_IMPLEMENTATION(flag);   \
    KRATOS_REGISTER_IN_PYTHON_FLAG_IMPLEMENTATION(NOT_##flag)

namespace Kratos
{

namespace Python
{

using namespace boost::python;

Flags FlagsOr(const Flags& Left, const Flags& Right )
{
    return (Left|Right);
}

void FlagsSet1(Flags& ThisFlag, const Flags& OtherFlag )
{
    ThisFlag.Set(OtherFlag);
}

void FlagsSet2(Flags& ThisFlag, const Flags& OtherFlag, bool Value )
{
    ThisFlag.Set(OtherFlag, Value);
}

template<class TContainerType>
struct Array1DModifier
{
    typedef typename TContainerType::size_type index_type;
    static void Resize( TContainerType& ThisContainer, typename TContainerType::size_type NewSize )
    {
    }
    static void MoveSlice( TContainerType& ThisContainer, index_type Index, index_type From, index_type To )
    {
    }
};

template<class TDataType>
void VariablesList_AddVariable(VariablesList& rDummy, Variable<TDataType> const& rThisVariable)
{
    rDummy.Add(rThisVariable);
}

void  AddContainersToPython()
{
    typedef KRATOS_DOUBLE_TYPE DataType;

    BoundedVectorPythonInterface<array_1d<DataType, 3>, 3>::CreateInterface( "Array3" )
    .def( init<vector_expression<array_1d<DataType, 3> > >() )
    .def( VectorScalarOperatorPython<array_1d<DataType, 3>, DataType, array_1d<DataType, 3> >() )
    .def( VectorVectorOperatorPython<array_1d<DataType, 3>, zero_vector<DataType>, array_1d<DataType, 3> >() )
    .def( VectorVectorOperatorPython<array_1d<DataType, 3>, unit_vector<DataType>, array_1d<DataType, 3> >() )
    .def( VectorVectorOperatorPython<array_1d<DataType, 3>, scalar_vector<DataType>, array_1d<DataType, 3> >() )
    .def( VectorVectorOperatorPython<array_1d<DataType, 3>, mapped_vector<DataType>, array_1d<DataType, 3> >() )
    ;

    BoundedVectorPythonInterface<array_1d<DataType, 2>, 2>::CreateInterface( "Array2" )
    .def( init<vector_expression<array_1d<DataType, 2> > >() )
    .def( VectorScalarOperatorPython<array_1d<DataType, 2>, DataType, array_1d<DataType, 2> >() )
    .def( VectorVectorOperatorPython<array_1d<DataType, 2>, zero_vector<DataType>, array_1d<DataType, 2> >() )
    .def( VectorVectorOperatorPython<array_1d<DataType, 2>, unit_vector<DataType>, array_1d<DataType, 2> >() )
    .def( VectorVectorOperatorPython<array_1d<DataType, 2>, scalar_vector<DataType>, array_1d<DataType, 2> >() )
    .def( VectorVectorOperatorPython<array_1d<DataType, 2>, mapped_vector<DataType>, array_1d<DataType, 2> >() )
    ;

    class_<VariableData>( "VariableData", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<std::string>, bases<VariableData>, boost::noncopyable >( "StringVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<bool>, bases<VariableData>, boost::noncopyable >( "BoolVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<int>, bases<VariableData>, boost::noncopyable >( "IntegerVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<vector<int> >, bases<VariableData>, boost::noncopyable >( "IntegerVectorVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<DataType>, bases<VariableData>, boost::noncopyable >( "DoubleVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<vector<DataType> >, bases<VariableData>, boost::noncopyable >( "VectorVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<array_1d<DataType, 3> >, bases<VariableData>, boost::noncopyable >( "Array1DVariable3", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<array_1d<DataType, 6> >, bases<VariableData>, boost::noncopyable >( "Array1DVariable6", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<matrix<DataType> >, bases<VariableData>, boost::noncopyable >( "MatrixVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<ConstitutiveLaw::Pointer>, bases<VariableData>, boost::noncopyable >( "ConstitutuveLawVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<Variable<ConvectionDiffusionSettings::Pointer > , bases<VariableData>, boost::noncopyable >("ConvectionDiffusionSettingsVariable", no_init)
    .def( self_ns::str( self ) )
    ;

    class_<Variable<RadiationSettings::Pointer > , bases<VariableData>, boost::noncopyable >("RadiationSettingsVariable", no_init)
    .def( self_ns::str( self ) )
    ;
    class_<VariableComponent<VectorComponentAdaptor<vector<DataType> > >, bases<VariableData>, boost::noncopyable >( "VectorComponentVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > >, bases<VariableData>, boost::noncopyable >( "Array1DComponentVariable", no_init )
    .def( self_ns::str( self ) )
    ;

    class_<DataValueContainer, DataValueContainer::Pointer>( "DataValueContainer" )
    .def( "__len__", &DataValueContainer::Size )
    .def( VariableIndexingPython<DataValueContainer, Variable<std::string> >() )
    .def( VariableIndexingPython<DataValueContainer, Variable<bool> >() )
    .def( VariableIndexingPython<DataValueContainer, Variable<int> >() )
    .def( VariableIndexingPython<DataValueContainer, Variable<DataType> >() )
    .def( VariableIndexingPython<DataValueContainer, Variable<array_1d<DataType, 3> > >() )
    .def( VariableIndexingPython<DataValueContainer, Variable<vector<DataType> > >() )
    .def( VariableIndexingPython<DataValueContainer, Variable<matrix<DataType> > >() )
    .def( VariableIndexingPython<DataValueContainer, Variable<ConvectionDiffusionSettings::Pointer > >() )
    .def( VariableIndexingPython<DataValueContainer, Variable<RadiationSettings::Pointer > >() )
    .def( VariableIndexingPython<DataValueContainer, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >() )
    .def( self_ns::str( self ) )
    ;

    class_<VariablesListDataValueContainer, VariablesListDataValueContainer::Pointer>( "VariablesListDataValueContainer" )
    .def( "__len__", &VariablesListDataValueContainer::Size )
    .def( VariableIndexingPython<VariablesListDataValueContainer, Variable<std::string> >() )
    .def( VariableIndexingPython<VariablesListDataValueContainer, Variable<bool> >() )
    .def( VariableIndexingPython<VariablesListDataValueContainer, Variable<int> >() )
    .def( VariableIndexingPython<VariablesListDataValueContainer, Variable<DataType> >() )
    .def( VariableIndexingPython<VariablesListDataValueContainer, Variable<array_1d<DataType, 3> > >() )
    .def( VariableIndexingPython<VariablesListDataValueContainer, Variable<vector<DataType> > >() )
    .def( VariableIndexingPython<VariablesListDataValueContainer, Variable<matrix<DataType> > >() )
    .def( VariableIndexingPython<VariablesListDataValueContainer, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >() )
    .def( self_ns::str( self ) )
    ;

    class_<VariablesList, VariablesList::Pointer, boost::noncopyable>( "VariablesList", init<>() )
    .def("Add", VariablesList_AddVariable<bool>)
    .def("Add", VariablesList_AddVariable<int>)
    .def("Add", VariablesList_AddVariable<DataType>)
    .def("Add", VariablesList_AddVariable<array_1d<DataType, 3 > >)
    .def("Add", VariablesList_AddVariable<Vector>)
    .def("Add", VariablesList_AddVariable<Matrix>)
    .def( self_ns::str( self ) )
    ;

    class_<Flags, Flags::Pointer>("Flags",init<>())
    .def(init<Flags>())
    .def("Is", &Flags::Is)
    .def("IsNot", &Flags::IsNot)
    .def("Set", FlagsSet1)
    .def("Set", FlagsSet2)
    .def("IsDefined", &Flags::IsDefined)
    .def("IsNotDefined", &Flags::IsNotDefined)
    .def("Reset", &Flags::Reset)
    .def("Flip", &Flags::Flip)
    .def("Clear", &Flags::Clear)
    .def("__or__", FlagsOr)
    .def("__and__", FlagsOr) // this is not an error, the and and or are considered both as add. Pooyan.
    .def( self_ns::str( self ) )
    ;


    KRATOS_REGISTER_IN_PYTHON_FLAG(STRUCTURE);
    KRATOS_REGISTER_IN_PYTHON_FLAG(INTERFACE);
    KRATOS_REGISTER_IN_PYTHON_FLAG(FLUID);
    KRATOS_REGISTER_IN_PYTHON_FLAG(INLET);
    KRATOS_REGISTER_IN_PYTHON_FLAG(OUTLET);
    KRATOS_REGISTER_IN_PYTHON_FLAG(VISITED);
    KRATOS_REGISTER_IN_PYTHON_FLAG(THERMAL);
    KRATOS_REGISTER_IN_PYTHON_FLAG(SELECTED);
    KRATOS_REGISTER_IN_PYTHON_FLAG(BOUNDARY);
    KRATOS_REGISTER_IN_PYTHON_FLAG(SLIP);
    KRATOS_REGISTER_IN_PYTHON_FLAG(CONTACT);
    KRATOS_REGISTER_IN_PYTHON_FLAG(TO_SPLIT);
    KRATOS_REGISTER_IN_PYTHON_FLAG(TO_ERASE);
    KRATOS_REGISTER_IN_PYTHON_FLAG(TO_REFINE);
    KRATOS_REGISTER_IN_PYTHON_FLAG(NEW_ENTITY);
    KRATOS_REGISTER_IN_PYTHON_FLAG(OLD_ENTITY);
    KRATOS_REGISTER_IN_PYTHON_FLAG(ACTIVE);
    KRATOS_REGISTER_IN_PYTHON_FLAG(MODIFIED);
    KRATOS_REGISTER_IN_PYTHON_FLAG(RIGID);
    KRATOS_REGISTER_IN_PYTHON_FLAG(SOLID);
    KRATOS_REGISTER_IN_PYTHON_FLAG(MPI_BOUNDARY);
    KRATOS_REGISTER_IN_PYTHON_FLAG(INTERACTION);
    KRATOS_REGISTER_IN_PYTHON_FLAG(ISOLATED);
    KRATOS_REGISTER_IN_PYTHON_FLAG(MASTER);
    KRATOS_REGISTER_IN_PYTHON_FLAG(SLAVE);
    KRATOS_REGISTER_IN_PYTHON_FLAG(INSIDE);
    KRATOS_REGISTER_IN_PYTHON_FLAG(FREE_SURFACE);
    KRATOS_REGISTER_IN_PYTHON_FLAG(BLOCKED);
    KRATOS_REGISTER_IN_PYTHON_FLAG(MARKER);
    KRATOS_REGISTER_IN_PYTHON_FLAG(HANGING);

    class_< ConvectionDiffusionSettings, ConvectionDiffusionSettings::Pointer, boost::noncopyable >	("ConvectionDiffusionSettings", init<	>() )
    .def("SetDensityVariable",&ConvectionDiffusionSettings::SetDensityVariable)
    .def("SetDiffusionVariable",&ConvectionDiffusionSettings::SetDiffusionVariable)
    .def("SetUnknownVariable",&ConvectionDiffusionSettings::SetUnknownVariable)
    .def("SetVolumeSourceVariable",&ConvectionDiffusionSettings::SetVolumeSourceVariable)
    .def("SetSurfaceSourceVariable",&ConvectionDiffusionSettings::SetSurfaceSourceVariable)
    .def("SetProjectionVariable",&ConvectionDiffusionSettings::SetProjectionVariable)
    .def("SetMeshVelocityVariable",&ConvectionDiffusionSettings::SetMeshVelocityVariable)
    .def("SetConvectionVariable",&ConvectionDiffusionSettings::SetConvectionVariable)
    .def("SetTransferCoefficientVariable",&ConvectionDiffusionSettings::SetTransferCoefficientVariable)
    .def("SetSpecificHeatVariable",&ConvectionDiffusionSettings::SetSpecificHeatVariable)
    .def("SetVelocityVariable",&ConvectionDiffusionSettings::SetVelocityVariable)


    .def("GetDensityVariable",&ConvectionDiffusionSettings::GetDensityVariable, return_internal_reference<>() )
    .def("GetDiffusionVariable",&ConvectionDiffusionSettings::GetDiffusionVariable, return_internal_reference<>() )
    .def("GetUnknownVariable",&ConvectionDiffusionSettings::GetUnknownVariable, return_internal_reference<>() )
    .def("GetVolumeSourceVariable",&ConvectionDiffusionSettings::GetVolumeSourceVariable, return_internal_reference<>() )
    .def("GetSurfaceSourceVariable",&ConvectionDiffusionSettings::GetSurfaceSourceVariable, return_internal_reference<>() )
    .def("GetProjectionVariable",&ConvectionDiffusionSettings::GetProjectionVariable, return_internal_reference<>() )
    .def("GetMeshVelocityVariable",&ConvectionDiffusionSettings::GetMeshVelocityVariable, return_internal_reference<>() )
    .def("GetConvectionVariable",&ConvectionDiffusionSettings::GetConvectionVariable, return_internal_reference<>() )
    .def("GetSpecificHeatVariable",&ConvectionDiffusionSettings::GetSpecificHeatVariable, return_internal_reference<>() )
    .def("GetVelocityVariable",&ConvectionDiffusionSettings::GetVelocityVariable, return_internal_reference<>() )
    .def("GetTransferCoefficientVariable",&ConvectionDiffusionSettings::GetTransferCoefficientVariable, return_internal_reference<>())

    .def("IsDefinedDensityVariable",&ConvectionDiffusionSettings::IsDefinedDensityVariable)
    .def("IsDefinedDiffusionVariable",&ConvectionDiffusionSettings::IsDefinedDiffusionVariable)
    .def("IsDefinedUnknownVariable",&ConvectionDiffusionSettings::IsDefinedUnknownVariable)
    .def("IsDefinedVolumeSourceVariable",&ConvectionDiffusionSettings::IsDefinedVolumeSourceVariable)
    .def("IsDefinedSurfaceSourceVariable",&ConvectionDiffusionSettings::IsDefinedSurfaceSourceVariable)
    .def("IsDefinedProjectionVariable",&ConvectionDiffusionSettings::IsDefinedProjectionVariable)
    .def("IsDefinedMeshVelocityVariable",&ConvectionDiffusionSettings::IsDefinedMeshVelocityVariable)
    .def("IsDefinedConvectionVariable",&ConvectionDiffusionSettings::IsDefinedConvectionVariable)
    .def("IsDefinedSpecificHeatVariable",&ConvectionDiffusionSettings::IsDefinedSpecificHeatVariable)
    .def("IsDefinedVelocityVariable",&ConvectionDiffusionSettings::IsDefinedVelocityVariable)
    .def("IsDefinedTransferCoefficientVariable",&ConvectionDiffusionSettings::IsDefinedTransferCoefficientVariable)
    ;

    class_< RadiationSettings, RadiationSettings::Pointer, boost::noncopyable >	("RadiationSettings", init<	>() )
    .def("SetDensityVariable",&RadiationSettings::SetDensityVariable)
    .def("SetDiffusionVariable",&RadiationSettings::SetDiffusionVariable)
    .def("SetUnknownVariable",&RadiationSettings::SetUnknownVariable)
    .def("SetVolumeSourceVariable",&RadiationSettings::SetVolumeSourceVariable)
    .def("SetSurfaceSourceVariable",&RadiationSettings::SetSurfaceSourceVariable)
    .def("SetProjectionVariable",&RadiationSettings::SetProjectionVariable)
    .def("SetMeshVelocityVariable",&RadiationSettings::SetMeshVelocityVariable)
    .def("GetDensityVariable",&RadiationSettings::GetDensityVariable, return_internal_reference<>() )
    .def("GetDiffusionVariable",&RadiationSettings::GetDiffusionVariable, return_internal_reference<>() )
    .def("GetUnknownVariable",&RadiationSettings::GetUnknownVariable, return_internal_reference<>() )
    .def("GetVolumeSourceVariable",&RadiationSettings::GetVolumeSourceVariable, return_internal_reference<>() )
    .def("GetSurfaceSourceVariable",&RadiationSettings::GetSurfaceSourceVariable, return_internal_reference<>() )
    //.def("GetSurfaceSourceVariable",&RadiationSettings::GetSurfaceSourceVariable, return_internal_reference<>() )
    .def("GetProjectionVariable",&RadiationSettings::GetProjectionVariable, return_internal_reference<>() )
    .def("GetMeshVelocityVariable",&RadiationSettings::GetMeshVelocityVariable, return_internal_reference<>() )
    ;

}

}  // namespace Python.

} // Namespace Kratos

#undef KRATOS_REGISTER_IN_PYTHON_FLAG
#undef KRATOS_REGISTER_IN_PYTHON_VARIABLE
#undef KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS
