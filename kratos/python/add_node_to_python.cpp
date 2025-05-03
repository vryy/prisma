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
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>


// Project includes
#include "includes/define.h"
#include "includes/mesh.h"
#include "includes/properties.h"
#include "includes/element.h"
#include "includes/condition.h"

#include "python/add_node_to_python.h"
#include "python/pointer_vector_set_python_interface.h"
#include "python/variable_indexing_python.h"
#include "python/solution_step_variable_indexing_python.h"

namespace Kratos
{

namespace Python
{

using namespace boost::python;

template<class TNodeType, class TVariableType> inline
void NodeFix(TNodeType& rThisNode, TVariableType const& rThisVariable)
{
    rThisNode.Fix(rThisVariable);
}

template<class TNodeType, class TVariableType> inline
void NodeFree(TNodeType& rThisNode, TVariableType const& rThisVariable)
{
    rThisNode.Free(rThisVariable);
}

template<class TNodeType, class TVariableType> inline
bool NodeIsFixed(TNodeType& rThisNode, TVariableType const& rThisVariable)
{
    return rThisNode.IsFixed(rThisVariable);
}

template<class TNodeType, class TVariableType> inline
bool NodeHasDofFor(TNodeType& rThisNode, TVariableType const& rThisVariable)
{
    return rThisNode.HasDofFor(rThisVariable);
}

template<class TNodeType, class TVariableType> inline
void NodeAddDof(TNodeType& rThisNode, TVariableType const& rThisVariable)
{
    rThisNode.pAddDof(rThisVariable);
}

template<class TNodeType, class TVariableType> inline
void NodeAddDofwithReaction(TNodeType& rThisNode, TVariableType const& rThisVariable,  TVariableType const& rReactionVariable)
{
    rThisNode.pAddDof(rThisVariable, rReactionVariable);
}

template<class TNodeType, class TVariableType>
bool NodeSolutionStepsDataHas(TNodeType& rThisNode, const TVariableType& rThisVariable)
{
    return rThisNode.SolutionStepsDataHas(rThisVariable);
}

template<class TNodeType>
void PointSetX0(TNodeType& ThisPoint, typename TNodeType::CoordinateType Value)
{
    ThisPoint.X0() = Value;
}

template<class TNodeType>
void PointSetY0(TNodeType& ThisPoint, typename TNodeType::CoordinateType Value)
{
    ThisPoint.Y0() = Value;
}

template<class TNodeType>
void PointSetZ0(TNodeType& ThisPoint, typename TNodeType::CoordinateType Value)
{
    ThisPoint.Z0() = Value;
}

template<class TNodeType>
typename TNodeType::CoordinateType PointGetX0(TNodeType& ThisPoint)
{
    return ThisPoint.X0();
}

template<class TNodeType>
typename TNodeType::CoordinateType PointGetY0(TNodeType& ThisPoint)
{
    return ThisPoint.Y0();
}

template<class TNodeType>
typename TNodeType::CoordinateType PointGetZ0(TNodeType& ThisPoint)
{
    return ThisPoint.Z0();
}

template<class TDofType>
void AddDofToPythonImpl(const std::string& Name)
{
    class_<TDofType, typename TDofType::Pointer, bases<IndexedObject> >(Name.c_str(), no_init)
    .def(self_ns::str(self))
    ;

    //class_<Dof, Dof::Pointer>("Dof", init<int, const Dof::VariableType&,  optional<const Dof::VariableType&, const Dof::VariableType&, const Dof::VariableType&> >())
    //.def("GetVariable", &Dof::GetVariable, return_internal_reference<>())
    //.def("GetReaction", &Dof::GetReaction, return_internal_reference<>())
    //.def("GetTimeDerivative", &Dof::GetTimeDerivative, return_internal_reference<>())
    //.def("GetSecondTimeDerivative", &Dof::GetSecondTimeDerivative, return_internal_reference<>())
    //.def("NodeIndex", &Dof::NodeIndex)
    //.add_property("EquationId", &Dof::EquationId, &Dof::SetEquationId)
    //.def("Fix", &Dof::FixDof)
    //.def("Free", &Dof::FreeDof)
    //.def("IsFixed", &Dof::IsFixed)
    //.def("HasTimeDerivative", &Dof::HasTimeDerivative)
    //.def("HasSecondTimeDerivative", &Dof::HasSecondTimeDerivative)
    //.def(self_ns::str(self))
    //      ;
}

template<class TNodeType>
void AddNodeToPythonImpl(const std::string& Name)
{
    typedef TNodeType NodeType;

    typedef typename NodeType::DofType DofType;

    typedef typename DofType::DataType DataType;

    typedef typename NodeType::CoordinateType CoordinateType;

    class_<NodeType, typename NodeType::Pointer, bases<typename NodeType::BaseType, IndexedObject, Flags > >
    (Name.c_str(), init<int, CoordinateType, CoordinateType, CoordinateType>())
    .def(init<int, const typename NodeType::PointType&>())
    .def(VariableIndexingPython<NodeType, Variable<bool> >())
    .def(VariableIndexingPython<NodeType, Variable<bool> >())
    .def(VariableIndexingPython<NodeType, Variable<int> >())
    .def(VariableIndexingPython<NodeType, Variable<DataType> >())
    .def(VariableIndexingPython<NodeType, Variable<array_1d<DataType, 3> > >())
    .def(VariableIndexingPython<NodeType, Variable<vector<DataType> > >())
    .def(VariableIndexingPython<NodeType, Variable<matrix<DataType> > >())
    .def(VariableIndexingPython<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >())
    .def(SolutionStepVariableIndexingPython<NodeType, Variable<bool> >())
    .def(SolutionStepVariableIndexingPython<NodeType, Variable<int> >())
    .def(SolutionStepVariableIndexingPython<NodeType, Variable<DataType> >())
    .def(SolutionStepVariableIndexingPython<NodeType, Variable<array_1d<DataType, 3> > >())
    .def(SolutionStepVariableIndexingPython<NodeType, Variable<vector<DataType> > >())
    .def(SolutionStepVariableIndexingPython<NodeType, Variable<matrix<DataType> > >())
    .def(SolutionStepVariableIndexingPython<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >())
    .def("GetBufferSize", &NodeType::GetBufferSize)
    .def("AddDof", NodeAddDof<NodeType, Variable<DataType> >)
    .def("AddDof", NodeAddDof<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)
    .def("AddDof", NodeAddDofwithReaction<NodeType, Variable<DataType> >)
    .def("AddDof", NodeAddDofwithReaction<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)
    .def("Fix", NodeFix<NodeType, Variable<DataType> >)
    .def("Fix", NodeFix<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)
    .def("Free", NodeFree<NodeType, Variable<DataType> >)
    .def("Free", NodeFree<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)
    .def("IsFixed", NodeIsFixed<NodeType, Variable<DataType> >)
    .def("IsFixed", NodeIsFixed<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)
    .def("HasDofFor", NodeHasDofFor<NodeType, Variable<DataType> >)
    .def("HasDofFor", NodeHasDofFor<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)
    .def("SolutionStepsDataHas", &NodeSolutionStepsDataHas<NodeType, Variable<bool> >)
    .def("SolutionStepsDataHas", &NodeSolutionStepsDataHas<NodeType, Variable<int> >)
    .def("SolutionStepsDataHas", &NodeSolutionStepsDataHas<NodeType, Variable<DataType> >)
    .def("SolutionStepsDataHas", &NodeSolutionStepsDataHas<NodeType, Variable<array_1d<DataType, 3> > >)
    .def("SolutionStepsDataHas", &NodeSolutionStepsDataHas<NodeType, Variable<vector<DataType> > >)
    .def("SolutionStepsDataHas", &NodeSolutionStepsDataHas<NodeType, Variable<matrix<DataType> > >)
    .def("SolutionStepsDataHas", &NodeSolutionStepsDataHas<NodeType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)
    .def("OverwriteSolutionStepData", &NodeType::OverwriteSolutionStepData)
    .add_property("X0", PointGetX0<NodeType>, PointSetX0<NodeType>)
    .add_property("Y0", PointGetY0<NodeType>, PointSetY0<NodeType>)
    .add_property("Z0", PointGetZ0<NodeType>, PointSetZ0<NodeType>)
    .def(self_ns::str(self))
    ;
}

void AddNodeToPython()
{
    class_<IndexedObject>("IndexedObject")
    .add_property("Id", &IndexedObject::GetId, &IndexedObject::SetId)
    .def(self_ns::str(self))
    ;

    AddDofToPythonImpl<Dof<KRATOS_DOUBLE_TYPE> >("Dof");
    AddDofToPythonImpl<Dof<KRATOS_COMPLEX_TYPE> >("ComplexDof");

    AddNodeToPythonImpl<Node<3, KRATOS_DOUBLE_TYPE, Dof<KRATOS_DOUBLE_TYPE> > >("Node");
    AddNodeToPythonImpl<Node<3, KRATOS_DOUBLE_TYPE, Dof<KRATOS_COMPLEX_TYPE> > >("ComplexNode");
    AddNodeToPythonImpl<Node<3, KRATOS_COMPLEX_TYPE, Dof<KRATOS_COMPLEX_TYPE> > >("GComplexNode");
}

}  // namespace Python.

} // Namespace Kratos
