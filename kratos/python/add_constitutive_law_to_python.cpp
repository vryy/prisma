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

// Project includes
#include "add_constitutive_law_to_python.h"
#include "includes/define_python.h"
#include "includes/constitutive_law.h"
#include "includes/node.h"
#include "includes/variables.h"
#include "includes/mesh.h"
#include "includes/element.h"
#include "includes/condition.h"
#include "includes/properties.h"
//#include "python/add_mesh_to_python.h"
//#include "python/pointer_vector_set_python_interface.h"
//#include "python/variable_indexing_python.h"

namespace Kratos
{

namespace Python
{

using namespace boost::python;

template<class TConstitutiveLawType, class TVariableType>
bool ConstitutiveLawHas(TConstitutiveLawType& this_constitutive_law, TVariableType const& rThisVariable) { return this_constitutive_law.Has(rThisVariable); }

template<class TConstitutiveLawType, class TDataType>
const TDataType ConstitutiveLawGetValue(TConstitutiveLawType& this_constitutive_law, const Variable<TDataType>& rThisVariable )
{
    TDataType tmp;
    tmp = this_constitutive_law.GetValue(rThisVariable, tmp);
    return tmp;
}

template<class TConstitutiveLawType, class TDataType>
void ConstitutiveLawSetValue(TConstitutiveLawType& this_constitutive_law, const Variable<TDataType>& rThisVariable, const TDataType& value, const ProcessInfo& rCurrentProcessInfo)
{
    this_constitutive_law.SetValue(rThisVariable, value, rCurrentProcessInfo);
}

template<class TConstitutiveLawType>
void ConstitutiveLawSetValueConstitutiveLaw(TConstitutiveLawType& this_constitutive_law, const Variable<typename TConstitutiveLawType::Pointer>& rThisVariable, typename TConstitutiveLawType::Pointer value, const ProcessInfo& rCurrentProcessInfo)
{
    this_constitutive_law.SetValue(rThisVariable, value, rCurrentProcessInfo);
}

//only exporting functions with the new interface - considering deprecated the old interface
template<class TConstitutiveLawType>
void NewInterfaceCalculateMaterialResponse(TConstitutiveLawType& this_constitutive_law, typename TConstitutiveLawType::Parameters& rValues, const BaseConstitutiveLaw::StressMeasure rStressMeasure)
{
    this_constitutive_law.CalculateMaterialResponse (rValues,rStressMeasure);
}

template<typename TConstitutiveLawType>
typename TConstitutiveLawType::DataType GetDeterminantF1(typename TConstitutiveLawType::Parameters& this_params) {return this_params.GetDeterminantF();}

template<typename TConstitutiveLawType>
typename TConstitutiveLawType::VectorType& GetStrainVector1(typename TConstitutiveLawType::Parameters& this_params) { return this_params.GetStrainVector(); }

template<typename TConstitutiveLawType>
typename TConstitutiveLawType::VectorType& GetStrainVector2(typename TConstitutiveLawType::Parameters& this_params, typename TConstitutiveLawType::VectorType& strain) { return this_params.GetStrainVector(strain); }

template<typename TConstitutiveLawType>
typename TConstitutiveLawType::VectorType& GetStressVector1(typename TConstitutiveLawType::Parameters& this_params) { return this_params.GetStressVector(); }

template<typename TConstitutiveLawType>
typename TConstitutiveLawType::VectorType& GetStressVector2(typename TConstitutiveLawType::Parameters& this_params, typename TConstitutiveLawType::VectorType& stress) { return this_params.GetStressVector(stress); }

template<typename TConstitutiveLawType>
typename TConstitutiveLawType::MatrixType& GetConstitutiveMatrix1(typename TConstitutiveLawType::Parameters& this_params) { return this_params.GetConstitutiveMatrix(); }

template<typename TConstitutiveLawType>
typename TConstitutiveLawType::MatrixType& GetConstitutiveMatrix2(typename TConstitutiveLawType::Parameters& this_params, typename TConstitutiveLawType::MatrixType& C) { return this_params.GetConstitutiveMatrix(C); }

template<typename TConstitutiveLawType>
const typename TConstitutiveLawType::MatrixType& GetDeformationGradientF1(typename TConstitutiveLawType::Parameters& this_params) { return this_params.GetDeformationGradientF(); }

template<typename TConstitutiveLawType>
typename TConstitutiveLawType::MatrixType& GetDeformationGradientF2(typename TConstitutiveLawType::Parameters& this_params, typename TConstitutiveLawType::MatrixType& F) { return this_params.GetDeformationGradientF(F); }

template<class TConstitutiveLawType>
void AddConstitutiveLawToPythonImpl(const std::string& Prefix)
{
    typedef TConstitutiveLawType ConstitutiveLawType;
    typedef typename ConstitutiveLawType::Parameters ParametersType;
    typedef typename ConstitutiveLawType::DataType DataType;
    typedef typename ConstitutiveLawType::VectorType VectorType;
    typedef typename ConstitutiveLawType::MatrixType MatrixType;

    class_< ParametersType, typename ParametersType::Pointer, boost::noncopyable>
    ((Prefix+"ConstitutiveLawParameters").c_str(), init<>() )
        .def(init< const typename ConstitutiveLawType::GeometryType&, const Properties&, const typename ConstitutiveLawType::ProcessInfoType& >() )
        .def("CheckAllParameters", &ParametersType::CheckAllParameters)
        .def("CheckMechanicalVariables", &ParametersType::CheckMechanicalVariables)
        .def("CheckShapeFunctions", &ParametersType::CheckShapeFunctions)
        .def("CheckInfoMaterialGeometry", &ParametersType::CheckInfoMaterialGeometry)
        .def("Set", &ParametersType::Set)
        .def("Reset", &ParametersType::Reset)
        .def("SetOptions", &ParametersType::SetOptions)
        .def("SetDeterminantF", &ParametersType::SetDeterminantF)
        .def("SetShapeFunctionsValues", &ParametersType::SetShapeFunctionsValues)
        .def("SetShapeFunctionsDerivatives", &ParametersType::SetShapeFunctionsDerivatives)
        .def("SetStrainVector", &ParametersType::SetStrainVector)
        .def("SetStressVector", &ParametersType::SetStressVector)
        .def("SetConstitutiveMatrix", &ParametersType::SetConstitutiveMatrix)
        .def("SetProcessInfo", &ParametersType::SetProcessInfo)
        .def("SetMaterialProperties", &ParametersType::SetMaterialProperties)
        .def("SetElementGeometry", &ParametersType::SetElementGeometry)
        .def("SetDeformationGradientF", &ParametersType::SetDeformationGradientF)
        .def("GetDeterminantF", GetDeterminantF1<ConstitutiveLawType>)
        // .def("GetShapeFunctionsValues", &ParametersType::GetShapeFunctionsValues)
        // .def("GetShapeFunctionsDerivatives", &ParametersType::GetShapeFunctionsDerivatives)
        .def("GetDeformationGradientF", &GetDeformationGradientF1<ConstitutiveLawType>, return_internal_reference<>())
        .def("GetDeformationGradientF", &GetDeformationGradientF2<ConstitutiveLawType>, return_internal_reference<>())
        .def("GetStrainVector", &GetStrainVector1<ConstitutiveLawType>, return_internal_reference<>())
        .def("GetStrainVector", &GetStrainVector2<ConstitutiveLawType>, return_internal_reference<>())
        .def("GetStressVector", &GetStressVector1<ConstitutiveLawType>, return_internal_reference<>())
        .def("GetStressVector", &GetStressVector2<ConstitutiveLawType>, return_internal_reference<>())
        .def("GetConstitutiveMatrix", &GetConstitutiveMatrix1<ConstitutiveLawType>, return_internal_reference<>())
        .def("GetConstitutiveMatrix", &GetConstitutiveMatrix2<ConstitutiveLawType>, return_internal_reference<>())
        .def("GetShapeFunctionsValues", &ParametersType::GetShapeFunctionsValues, return_internal_reference<>())
        .def("GetProcessInfo", &ParametersType::GetProcessInfo, return_internal_reference<>())
        .def("GetMaterialProperties", &ParametersType::GetMaterialProperties, return_internal_reference<>())
        .def("GetElementGeometry", &ParametersType::GetElementGeometry, return_internal_reference<>())
    ;

    class_< ConstitutiveLawType, typename ConstitutiveLawType::Pointer, bases<BaseConstitutiveLaw>, boost::noncopyable >
    ((Prefix+"ConstitutiveLaw").c_str(), init<>() )
    .def("Clone", &ConstitutiveLawType::Clone)
    .def("WorkingSpaceDimension",& ConstitutiveLawType::WorkingSpaceDimension)
    .def("GetStrainSize", &ConstitutiveLawType::GetStrainSize)
    .def("GetStressMeasure", &ConstitutiveLawType::GetStressMeasure)
    .def("IsIncremental", &ConstitutiveLawType::IsIncremental)
    .def("WorkingSpaceDimension", &ConstitutiveLawType::WorkingSpaceDimension)
    .def("GetStrainSize", &ConstitutiveLawType::GetStrainSize)
    .def("Has", &ConstitutiveLawHas<ConstitutiveLawType, Variable<bool> >)
    .def("Has", &ConstitutiveLawHas<ConstitutiveLawType, Variable<int> >)
    .def("Has", &ConstitutiveLawHas<ConstitutiveLawType, Variable<DataType> >)
    .def("Has", &ConstitutiveLawHas<ConstitutiveLawType, Variable<array_1d<DataType, 3> > >)
    .def("Has", &ConstitutiveLawHas<ConstitutiveLawType, Variable<VectorType> >)
    .def("Has", &ConstitutiveLawHas<ConstitutiveLawType, Variable<MatrixType> >)
    .def("GetValue", &ConstitutiveLawGetValue<ConstitutiveLawType, bool> )
    .def("GetValue", &ConstitutiveLawGetValue<ConstitutiveLawType, int> )
    .def("GetValue", &ConstitutiveLawGetValue<ConstitutiveLawType, DataType> )
    .def("GetValue", &ConstitutiveLawGetValue<ConstitutiveLawType, array_1d<DataType, 3> >)
    .def("GetValue", &ConstitutiveLawGetValue<ConstitutiveLawType, VectorType>)
    .def("GetValue", &ConstitutiveLawGetValue<ConstitutiveLawType, MatrixType>)
    .def("SetValue", &ConstitutiveLawSetValue<ConstitutiveLawType, bool> )
    .def("SetValue", &ConstitutiveLawSetValue<ConstitutiveLawType, int> )
    .def("SetValue", &ConstitutiveLawSetValue<ConstitutiveLawType, DataType> )
    .def("SetValue", &ConstitutiveLawSetValue<ConstitutiveLawType, array_1d<DataType, 3> >)
    .def("SetValue", &ConstitutiveLawSetValue<ConstitutiveLawType, VectorType>)
    .def("SetValue", &ConstitutiveLawSetValue<ConstitutiveLawType, MatrixType>)
    .def("SetValue", &ConstitutiveLawSetValue<ConstitutiveLawType, std::string >)
    .def("SetValue", &ConstitutiveLawSetValueConstitutiveLaw<ConstitutiveLawType>)
    .def("CalculateMaterialResponse", &NewInterfaceCalculateMaterialResponse<ConstitutiveLawType>)
    .def("CalculateMaterialResponsePK1", &ConstitutiveLawType::CalculateMaterialResponsePK1)
    .def("CalculateMaterialResponsePK2", &ConstitutiveLawType::CalculateMaterialResponsePK2)
    .def("CalculateMaterialResponseKirchhoff", &ConstitutiveLawType::CalculateMaterialResponseKirchhoff)
    .def("CalculateMaterialResponseCauchy", &ConstitutiveLawType::CalculateMaterialResponseCauchy)
    .def("FinalizeMaterialResponse", &ConstitutiveLawType::FinalizeMaterialResponse)
    .def("FinalizeMaterialResponsePK1", &ConstitutiveLawType::FinalizeMaterialResponsePK1)
    .def("FinalizeMaterialResponsePK2", &ConstitutiveLawType::FinalizeMaterialResponsePK2)
    .def("FinalizeMaterialResponseKirchhoff", &ConstitutiveLawType::FinalizeMaterialResponseKirchhoff)
    .def("FinalizeMaterialResponseCauchy", &ConstitutiveLawType::FinalizeMaterialResponseCauchy)
    .def("FinalizeSolutionStep", &ConstitutiveLawType::FinalizeSolutionStep)
    .def("InitializeSolutionStep", &ConstitutiveLawType::InitializeSolutionStep)
    .def("InitializeMaterial", &ConstitutiveLawType::InitializeMaterial)
    .def("ResetMaterial", &ConstitutiveLawType::ResetMaterial)
    .def("TransformStrains", &ConstitutiveLawType::TransformStrains, return_internal_reference<>())
//     .def("TransformStresses", &ConstitutiveLawType::TransformStresses)
//     .def("TransformStresses", &ConstitutiveLawType::TransformStresses)
    .def("TransformPK1Stresses", &ConstitutiveLawType::TransformPK1Stresses, return_internal_reference<>())
    .def("TransformPK2Stresses", &ConstitutiveLawType::TransformPK2Stresses, return_internal_reference<>())
    .def("TransformKirchhoffStresses", &ConstitutiveLawType::TransformKirchhoffStresses, return_internal_reference<>())
    .def("TransformCauchyStresses", &ConstitutiveLawType::TransformCauchyStresses, return_internal_reference<>())
    .def("PullBackConstitutiveMatrix", &ConstitutiveLawType::PullBackConstitutiveMatrix)
    .def("PushForwardConstitutiveMatrix", &ConstitutiveLawType::PushForwardConstitutiveMatrix)
    .def("Check", &ConstitutiveLawType::Check)
//     .def("GetLawFeatures", &ConstitutiveLawType::GetLawFeatures)
    ;
}

void AddConstitutiveLawToPython()
{
    enum_<BaseConstitutiveLaw::StrainMeasure>("StrainMeasure")
    .value("StrainMeasure_Infinitesimal", BaseConstitutiveLaw::StrainMeasure_Infinitesimal)
    .value("StrainMeasure_GreenLagrange", BaseConstitutiveLaw::StrainMeasure_GreenLagrange)
    .value("StrainMeasure_Hencky_Material", BaseConstitutiveLaw::StrainMeasure_Hencky_Material)
    .value("StrainMeasure_Hencky_Spatial", BaseConstitutiveLaw::StrainMeasure_Hencky_Spatial)
    .value("StrainMeasure_Deformation_Gradient", BaseConstitutiveLaw::StrainMeasure_Deformation_Gradient)
    .value("StrainMeasure_Right_CauchyGreen", BaseConstitutiveLaw::StrainMeasure_Right_CauchyGreen)
    .value("StrainMeasure_Left_CauchyGreen", BaseConstitutiveLaw::StrainMeasure_Left_CauchyGreen)
    ;

    enum_<BaseConstitutiveLaw::StressMeasure>("StressMeasure")
    .value("StressMeasure_PK1", BaseConstitutiveLaw::StressMeasure_PK1)
    .value("StressMeasure_PK2", BaseConstitutiveLaw::StressMeasure_PK2)
    .value("StressMeasure_Kirchhoff", BaseConstitutiveLaw::StressMeasure_Kirchhoff)
    .value("StressMeasure_Cauchy", BaseConstitutiveLaw::StressMeasure_Cauchy)
    ;

    class_< BaseConstitutiveLaw, BaseConstitutiveLaw::Pointer, bases<Flags>, boost::noncopyable >
    ("BaseConstitutiveLaw", init<>() )
    .def_readonly("COMPUTE_STRAIN", &BaseConstitutiveLaw::COMPUTE_STRAIN)
    .def_readonly("COMPUTE_STRESS", &BaseConstitutiveLaw::COMPUTE_STRESS)
    .def_readonly("COMPUTE_CONSTITUTIVE_TENSOR", &BaseConstitutiveLaw::COMPUTE_CONSTITUTIVE_TENSOR)
    .def_readonly("COMPUTE_STRAIN_ENERGY", &BaseConstitutiveLaw::COMPUTE_STRAIN_ENERGY)
    .def_readonly("ISOCHORIC_TENSOR_ONLY", &BaseConstitutiveLaw::ISOCHORIC_TENSOR_ONLY)
    .def_readonly("VOLUMETRIC_TENSOR_ONLY", &BaseConstitutiveLaw::VOLUMETRIC_TENSOR_ONLY)
    .def_readonly("TOTAL_TENSOR", &BaseConstitutiveLaw::TOTAL_TENSOR)
    .def_readonly("FINALIZE_MATERIAL_RESPONSE", &BaseConstitutiveLaw::FINALIZE_MATERIAL_RESPONSE)
    .def_readonly("FINITE_STRAINS", &BaseConstitutiveLaw::FINITE_STRAINS)
    .def_readonly("INFINITESIMAL_STRAINS", &BaseConstitutiveLaw::INFINITESIMAL_STRAINS)
    .def_readonly("PLANE_STRAIN_LAW", &BaseConstitutiveLaw::PLANE_STRAIN_LAW)
    .def_readonly("PLANE_STRESS_LAW", &BaseConstitutiveLaw::PLANE_STRESS_LAW)
    .def_readonly("AXISYMMETRIC_LAW", &BaseConstitutiveLaw::AXISYMMETRIC_LAW)
    .def_readonly("U_P_LAW", &BaseConstitutiveLaw::U_P_LAW)
    .def_readonly("ISOTROPIC", &BaseConstitutiveLaw::ISOTROPIC)
    .def_readonly("ANISOTROPIC", &BaseConstitutiveLaw::ANISOTROPIC)
    .def("Load", &Serializer_load_wrapper<BaseConstitutiveLaw>)
    .def("Save", &Serializer_save_wrapper<BaseConstitutiveLaw>)
    .def( self_ns::str( self ) )
    ;

    AddConstitutiveLawToPythonImpl<ConstitutiveLaw>("");
    AddConstitutiveLawToPythonImpl<ComplexConstitutiveLaw>("Complex");
    AddConstitutiveLawToPythonImpl<GComplexConstitutiveLaw>("GComplex");
}

}  // namespace Python.

}  // namespace Kratos.
