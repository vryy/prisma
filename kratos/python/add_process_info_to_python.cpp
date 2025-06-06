// Kratos Multi-Physics
//
// Copyright (c) 2016 Pooyan Dadvand, Riccardo Rossi, CIMNE (International Center for Numerical Methods in Engineering)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
//  -   Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//  -   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
//      in the documentation and/or other materials provided with the distribution.
//  -   All advertising materials mentioning features or use of this software must display the following acknowledgement:
//          This product includes Kratos Multi-Physics technology.
//  -   Neither the name of the CIMNE nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
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
#include "includes/process_info.h"
#include "includes/process_info_with_dofs.h"
#include "python/add_process_info_to_python.h"
#include "containers/data_value_container.h"

namespace Kratos
{

namespace Python
{

template< class TContainerType, class TVariableType > void MySetValueHelperFunction1(
    TContainerType& el,
    const TVariableType& rVar,
    const typename TVariableType::Type& Data)
{
    el.SetValue(rVar,Data);
}

template< class TContainerType, class TVariableType >
typename TVariableType::Type MyGetValueHelperFunction1( TContainerType& el,
        const TVariableType& rVar )
{
    return el.GetValue(rVar);
}

//
void AddProcessInfoToPython()
{
    using namespace boost::python;

    class_<ProcessInfo, ProcessInfo::Pointer, bases<DataValueContainer, Flags>, boost::noncopyable>("ProcessInfo")
    .def(init<>())
    .def("CreateSolutionStepInfo", &ProcessInfo::CreateSolutionStepInfo)
//              .def("CreateTimeStepInfo",(void (ProcessInfo::*)(std::size_t)) &ProcessInfo::CreateTimeStepInfo)
//              .def("CreateTimeStepInfo",&ProcessInfo::CreateTimeStepInfo)
//              .def("CloneTimeStepInfo",(void (ProcessInfo::*)(std::size_t) )&ProcessInfo::CloneTimeStepInfo)
//              .def("SetAsTimeStepInfo",(void (ProcessInfo::*)()) &ProcessInfo::SetAsTimeStepInfo)
    .def(self_ns::str(self))
    ;

    typedef Variable<KRATOS_DOUBLE_TYPE> DoubleVariableType;
    typedef VariableComponent<Kratos::VectorComponentAdaptor<Kratos::array_1d<KRATOS_DOUBLE_TYPE, 3>>> VariableComponentType;

    typedef ProcessInfoWithDofs<Dof<KRATOS_DOUBLE_TYPE> > ProcessInfoWithDoubleDofs;
    class_<ProcessInfoWithDoubleDofs, typename ProcessInfoWithDoubleDofs::Pointer, bases<ProcessInfo>, boost::noncopyable>("ProcessInfoWithDofs")
    .def(init<>())
    .def("AddDof", &ProcessInfoWithDoubleDofs::AddDof<DoubleVariableType>)
    .def("AddDof", &ProcessInfoWithDoubleDofs::AddDof<VariableComponentType>)
    .def("FixDof", &ProcessInfoWithDoubleDofs::FixDof<DoubleVariableType>)
    .def("FixDof", &ProcessInfoWithDoubleDofs::FixDof<VariableComponentType>)
    ;

    typedef Variable<KRATOS_COMPLEX_TYPE> ComplexVariableType;
    typedef VariableComponent<Kratos::VectorComponentAdaptor<Kratos::array_1d<KRATOS_COMPLEX_TYPE, 3>>> ComplexVariableComponentType;

    typedef ProcessInfoWithDofs<Dof<KRATOS_COMPLEX_TYPE> > ProcessInfoWithComplexDofs;
    class_<ProcessInfoWithComplexDofs, typename ProcessInfoWithComplexDofs::Pointer, bases<ProcessInfo>, boost::noncopyable>("ProcessInfoWithComplexDofs")
    .def(init<>())
    .def("AddDof", &ProcessInfoWithComplexDofs::AddDof<ComplexVariableType>)
    .def("AddDof", &ProcessInfoWithComplexDofs::AddDof<ComplexVariableComponentType>)
    .def("FixDof", &ProcessInfoWithComplexDofs::FixDof<ComplexVariableType>)
    .def("FixDof", &ProcessInfoWithComplexDofs::FixDof<ComplexVariableComponentType>)
    ;

}

}  // namespace Python.

} // Namespace Kratos
