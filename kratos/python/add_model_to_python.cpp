//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//                   Pooyan Dadvand
//

// System includes

// External includes

// Project includes
#include <boost/python.hpp>
#include "containers/model.h"
#include "python/add_model_to_python.h"

namespace Kratos {

namespace Python {

template<class TModelPartType>
TModelPartType& Model_CreateModelPart1(Model& rModel, const std::string& rName)
{
    return dynamic_cast<TModelPartType&>(rModel.CreateModelPart<TModelPartType>(rName));
}

template<class TModelPartType>
TModelPartType& Model_CreateModelPart2(Model& rModel, const std::string& rName, unsigned int BufferSize)
{
    return dynamic_cast<TModelPartType&>(rModel.CreateModelPart<TModelPartType>(rName, BufferSize));
}

BaseModelPart& Model_GetModelPart(Model& rModel, const std::string& rFullModelPartName)
{
    return rModel.GetBaseModelPart(rFullModelPartName);
}

Model& GetDefaultKratosModel()
{
    return *pKratosDefaultModel;
}

void AddModelToPython()
{
    using namespace boost::python;

    class_<Model, boost::noncopyable>("Model", init<>())
        .def("Reset", &Model::Reset)
        .def("CreateModelPart", &Model_CreateModelPart1<ModelPart>, return_internal_reference<>())
        .def("CreateModelPart", &Model_CreateModelPart2<ModelPart>, return_internal_reference<>())
        .def("CreateComplexModelPart", &Model_CreateModelPart1<ComplexModelPart>, return_internal_reference<>())
        .def("CreateComplexModelPart", &Model_CreateModelPart2<ComplexModelPart>, return_internal_reference<>())
        .def("CreateGComplexModelPart", &Model_CreateModelPart1<GComplexModelPart>, return_internal_reference<>())
        .def("CreateGComplexModelPart", &Model_CreateModelPart2<GComplexModelPart>, return_internal_reference<>())
        .def("DeleteModelPart", &Model::DeleteModelPart)
        .def("GetModelPart", &Model_GetModelPart, return_internal_reference<>())
        .def("HasModelPart", &Model::HasBaseModelPart)
        .def("GetModelPartNames", &Model::GetModelPartNames)
        .def("__getitem__", &Model_GetModelPart, return_internal_reference<>())
        .def(self_ns::str(self))
        ;

    def("GetDefaultKratosModel", &GetDefaultKratosModel, return_value_policy<reference_existing_object>());
}

}  // namespace Python.

} // Namespace Kratos
