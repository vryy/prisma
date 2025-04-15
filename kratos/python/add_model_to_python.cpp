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

ModelPart& Model_CreateModelPart1(Model& rModel, const std::string& rName)
{
    return dynamic_cast<ModelPart&>(rModel.CreateModelPart<ModelPart>(rName));
}

ModelPart& Model_CreateModelPart2(Model& rModel, const std::string& rName, unsigned int BufferSize)
{
    return dynamic_cast<ModelPart&>(rModel.CreateModelPart<ModelPart>(rName, BufferSize));
}

ComplexModelPart& Model_CreateComplexModelPart1(Model& rModel, const std::string& rName)
{
    return dynamic_cast<ComplexModelPart&>(rModel.CreateModelPart<ComplexModelPart>(rName));
}

ComplexModelPart& Model_CreateComplexModelPart2(Model& rModel, const std::string& rName, unsigned int BufferSize)
{
    return dynamic_cast<ComplexModelPart&>(rModel.CreateModelPart<ComplexModelPart>(rName, BufferSize));
}

BaseModelPart& Model_GetModelPart(Model& rModel, const std::string& rFullModelPartName)
{
    return rModel.GetModelPart(rFullModelPartName);
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
        .def("CreateModelPart", &Model_CreateModelPart1, return_internal_reference<>())
        .def("CreateModelPart", &Model_CreateModelPart2, return_internal_reference<>())
        .def("CreateComplexModelPart", &Model_CreateComplexModelPart1, return_internal_reference<>())
        .def("CreateComplexModelPart", &Model_CreateComplexModelPart2, return_internal_reference<>())
        .def("DeleteModelPart", &Model::DeleteModelPart)
        .def("GetModelPart", &Model_GetModelPart, return_internal_reference<>())
        .def("HasModelPart", &Model::HasModelPart)
        .def("GetModelPartNames", &Model::GetModelPartNames)
        .def("__getitem__", &Model_GetModelPart, return_internal_reference<>())
        .def(self_ns::str(self))
        ;

    def("GetDefaultKratosModel", &GetDefaultKratosModel, return_value_policy<reference_existing_object>());
}

}  // namespace Python.

} // Namespace Kratos
