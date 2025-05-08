/*
==============================================================================
Kratos
A General Purpose Software for Multi-Physics Finite Element Analysis
Version 1.0 (Released on march 05, 2007).

Copyright 2007
Pooyan Dadvand, Riccardo Rossi
pooyan@cimne.upc.edu
rrossi@cimne.upc.edu
CIMNE (International Center for Numerical Methods in Engineering),
Gran Capita' s/n, 08034 Barcelona, Spain

Permission is hereby granted, free  of charge, to any person obtaining
a  copy  of this  software  and  associated  documentation files  (the
"Software"), to  deal in  the Software without  restriction, including
without limitation  the rights to  use, copy, modify,  merge, publish,
distribute,  sublicense and/or  sell copies  of the  Software,  and to
permit persons to whom the Software  is furnished to do so, subject to
the following condition:

Distribution of this code for  any  commercial purpose  is permissible
ONLY BY DIRECT ARRANGEMENT WITH THE COPYRIGHT OWNER.

The  above  copyright  notice  and  this permission  notice  shall  be
included in all copies or substantial portions of the Software.

THE  SOFTWARE IS  PROVIDED  "AS  IS", WITHOUT  WARRANTY  OF ANY  KIND,
EXPRESS OR  IMPLIED, INCLUDING  BUT NOT LIMITED  TO THE  WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT  SHALL THE AUTHORS OR COPYRIGHT HOLDERS  BE LIABLE FOR ANY
CLAIM, DAMAGES OR  OTHER LIABILITY, WHETHER IN AN  ACTION OF CONTRACT,
TORT  OR OTHERWISE, ARISING  FROM, OUT  OF OR  IN CONNECTION  WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

==============================================================================
 */

//
//   Project Name:        Kratos
//   Last modified by:    $Author: rrossi $
//   Date:                $Date: 2008-06-20 17:38:25 $
//   Revision:            $Revision: 1.14 $
//
//

// System includes

// External includes
#include <boost/foreach.hpp>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <boost/python/operators.hpp>



// Project includes
#include "includes/define.h"
#include "includes/model_part.h"
#include "python/add_model_part_to_python.h"
#include "python/pointer_vector_set_python_interface.h"
#include "includes/process_info.h"
#include "utilities/constraint_utilities.h"

namespace Kratos
{

namespace Python
{

template<class TModelPartType, typename TDataType>
void AddNodalSolutionStepVariable(TModelPartType& rModelPart, Variable<TDataType> const& rThisVariable)
{
    rModelPart.AddNodalSolutionStepVariable(rThisVariable);
}

template<class TModelPartType>
void SetModelPartName(TModelPartType& rModelPart, std::string const& NewName)
{
    rModelPart.Name() = NewName;
}

template<class TModelPartType>
std::string GetModelPartName(TModelPartType const& rModelPart)
{
    return rModelPart.Name();
}

template<class TModelPartType>
std::string GetModelPartType(TModelPartType const& rModelPart)
{
    return ModelPartTypeToString<TModelPartType>::Get();
}

template<class TModelPartType>
ProcessInfo& GetProcessInfo(TModelPartType& rModelPart)
{
    return rModelPart.GetProcessInfo();
}

template<class TModelPartType>
void SetProcessInfo(TModelPartType& rModelPart, ProcessInfo& NewProcessInfo)
{
    rModelPart.SetProcessInfo(NewProcessInfo);
}

template<class TModelPartType>
typename TModelPartType::MeshType::Pointer ModelPartGetMesh(TModelPartType& rModelPart)
{
    return rModelPart.pGetMesh();
}

template<class TModelPartType>
typename TModelPartType::MeshType::Pointer ModelPartGetMesh2(TModelPartType& rModelPart, typename TModelPartType::IndexType MeshIndex)
{
    typename TModelPartType::IndexType number_of_meshes = rModelPart.NumberOfMeshes();
    // adding necessary meshes to the model part.
    typename TModelPartType::MeshType empty_mesh;
    for(typename TModelPartType::IndexType i = number_of_meshes ; i < MeshIndex + 1 ; i++)
        rModelPart.GetMeshes().push_back(empty_mesh.Clone());

    return rModelPart.pGetMesh(MeshIndex);
}

template<class TModelPartType, typename TDataType>
typename TModelPartType::NodeType::Pointer ModelPartCreateNewNode(TModelPartType& rModelPart, int Id, TDataType x, TDataType y, TDataType z)
{
    return rModelPart.CreateNewNode(Id, x, y, z);
}

template<class TModelPartType>
typename TModelPartType::ElementType::Pointer ModelPartCreateNewElement(TModelPartType& rModelPart, std::string ElementName,
        typename TModelPartType::IndexType Id, boost::python::list& NodeIdList, typename TModelPartType::PropertiesType::Pointer pProperties)
{
    typename TModelPartType::GeometryType::PointsArrayType pElementNodeList;

    for(unsigned int i = 0; i < len(NodeIdList); i++)
    {
        pElementNodeList.push_back(rModelPart.pGetNode(boost::python::extract<int>(NodeIdList[i])));
    }

    return rModelPart.CreateNewElement(ElementName, Id, pElementNodeList, pProperties);
}

template<class TModelPartType>
typename TModelPartType::ConditionType::Pointer ModelPartCreateNewCondition(TModelPartType& rModelPart, std::string ConditionName,
        typename TModelPartType::IndexType Id, boost::python::list& NodeIdList, typename TModelPartType::PropertiesType::Pointer pProperties)
{
    typename TModelPartType::GeometryType::PointsArrayType pConditionNodeList;

    for(unsigned int i = 0; i < len(NodeIdList); i++)
    {
        pConditionNodeList.push_back(rModelPart.pGetNode(boost::python::extract<int>(NodeIdList[i])));
    }

    return rModelPart.CreateNewCondition(ConditionName, Id, pConditionNodeList, pProperties);
}

template<class TModelPartType>
typename TModelPartType::SizeType ModelPartNumberOfNodes1(TModelPartType& rModelPart)
{
    return rModelPart.NumberOfNodes();
}

template<class TModelPartType>
typename TModelPartType::NodesContainerType::Pointer ModelPartGetNodes1(TModelPartType& rModelPart)
{
    return rModelPart.pNodes();
}

template<class TModelPartType>
typename TModelPartType::NodesContainerType::Pointer ModelPartGetNodes2(TModelPartType& rModelPart, typename TModelPartType::IndexType ThisIndex)
{
    return rModelPart.pNodes(ThisIndex);
}

template<class TModelPartType>
void ModelPartSetNodes1(TModelPartType& rModelPart, typename TModelPartType::NodesContainerType::Pointer pOtherNodes)
{
    rModelPart.SetNodes(pOtherNodes);
}

template<class TModelPartType>
void ModelPartSetNodes2(TModelPartType& rModelPart, typename TModelPartType::NodesContainerType::Pointer pOtherNodes, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.SetNodes(pOtherNodes, ThisIndex);
}

template<class TModelPartType>
typename TModelPartType::NodeType::Pointer ModelPartGetNode1(TModelPartType& rModelPart, typename TModelPartType::IndexType NodeId)
{
    return rModelPart.pGetNode(NodeId);
}

template<class TModelPartType>
typename TModelPartType::NodeType::Pointer ModelPartGetNode2(TModelPartType& rModelPart, typename TModelPartType::IndexType NodeId, typename TModelPartType::IndexType ThisIndex)
{
    return rModelPart.pGetNode(NodeId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveNode1(TModelPartType& rModelPart, typename TModelPartType::IndexType NodeId)
{
    rModelPart.RemoveNode(NodeId);
}

template<class TModelPartType>
void ModelPartRemoveNode2(TModelPartType& rModelPart, typename TModelPartType::IndexType NodeId, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveNode(NodeId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveNode3(TModelPartType& rModelPart, typename TModelPartType::NodeType::Pointer pThisNode)
{
    rModelPart.RemoveNode(pThisNode);
}

template<class TModelPartType>
void ModelPartRemoveNode4(TModelPartType& rModelPart, typename TModelPartType::NodeType::Pointer pThisNode, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveNode(pThisNode, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveNodeFromAllLevels1(TModelPartType& rModelPart, typename TModelPartType::IndexType NodeId)
{
    rModelPart.RemoveNodeFromAllLevels(NodeId);
}

template<class TModelPartType>
void ModelPartRemoveNodeFromAllLevels2(TModelPartType& rModelPart, typename TModelPartType::IndexType NodeId, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveNodeFromAllLevels(NodeId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveNodeFromAllLevels3(TModelPartType& rModelPart, typename TModelPartType::NodeType::Pointer pThisNode)
{
    rModelPart.RemoveNodeFromAllLevels(pThisNode);
}

template<class TModelPartType>
void ModelPartRemoveNodeFromAllLevels4(TModelPartType& rModelPart, typename TModelPartType::NodeType::Pointer pThisNode, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveNodeFromAllLevels(pThisNode, ThisIndex);
}

template<class TModelPartType>
typename TModelPartType::SizeType  ModelPartNumberOfProperties1(TModelPartType& rModelPart)
{
    return rModelPart.NumberOfProperties();
}

template<class TModelPartType>
void ModelPartAddProperties1(TModelPartType& rModelPart, Properties::Pointer pNewProperties)
{
    rModelPart.AddProperties(pNewProperties);
}

template<class TModelPartType>
void ModelPartAddProperties2(TModelPartType& rModelPart, Properties::Pointer pNewProperties, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.AddProperties(pNewProperties, ThisIndex);
}

template<class TModelPartType>
typename TModelPartType::PropertiesContainerType::Pointer ModelPartGetProperties1(TModelPartType& rModelPart)
{
    return rModelPart.pProperties();
}

template<class TModelPartType>
typename TModelPartType::PropertiesContainerType::Pointer ModelPartGetProperties2(TModelPartType& rModelPart, typename TModelPartType::IndexType ThisIndex)
{
    return rModelPart.pProperties(ThisIndex);
}

template<class TModelPartType>
void ModelPartSetProperties1(TModelPartType& rModelPart, typename TModelPartType::PropertiesContainerType::Pointer pOtherProperties)
{
    rModelPart.SetProperties(pOtherProperties);
}

template<class TModelPartType>
void ModelPartSetProperties2(TModelPartType& rModelPart, typename TModelPartType::PropertiesContainerType::Pointer pOtherProperties, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.SetProperties(pOtherProperties, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveProperties1(TModelPartType& rModelPart, typename TModelPartType::IndexType PropertiesId)
{
    rModelPart.RemoveProperties(PropertiesId);
}

template<class TModelPartType>
void ModelPartRemoveProperties2(TModelPartType& rModelPart, typename TModelPartType::IndexType PropertiesId, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveProperties(PropertiesId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveProperties3(TModelPartType& rModelPart, typename TModelPartType::PropertiesType::Pointer pThisProperties)
{
    rModelPart.RemoveProperties(pThisProperties);
}

template<class TModelPartType>
void ModelPartRemoveProperties4(TModelPartType& rModelPart, typename TModelPartType::PropertiesType::Pointer pThisProperties, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveProperties(pThisProperties, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemovePropertiesFromAllLevels1(TModelPartType& rModelPart, typename TModelPartType::IndexType PropertiesId)
{
    rModelPart.RemovePropertiesFromAllLevels(PropertiesId);
}

template<class TModelPartType>
void ModelPartRemovePropertiesFromAllLevels2(TModelPartType& rModelPart, typename TModelPartType::IndexType PropertiesId, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemovePropertiesFromAllLevels(PropertiesId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemovePropertiesFromAllLevels3(TModelPartType& rModelPart, typename TModelPartType::PropertiesType::Pointer pThisProperties)
{
    rModelPart.RemovePropertiesFromAllLevels(pThisProperties);
}

template<class TModelPartType>
void ModelPartRemovePropertiesFromAllLevels4(TModelPartType& rModelPart, typename TModelPartType::PropertiesType::Pointer pThisProperties, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemovePropertiesFromAllLevels(pThisProperties, ThisIndex);
}

template<class TModelPartType>
typename TModelPartType::SizeType ModelPartNumberOfElements1(TModelPartType& rModelPart)
{
    return rModelPart.NumberOfElements();
}

template<class TModelPartType>
typename TModelPartType::ElementsContainerType::Pointer ModelPartGetElements1(TModelPartType& rModelPart)
{
    return rModelPart.pElements();
}

template<class TModelPartType>
typename TModelPartType::ElementsContainerType::Pointer ModelPartGetElements2(TModelPartType& rModelPart, typename TModelPartType::IndexType ThisIndex)
{
    return rModelPart.pElements(ThisIndex);
}

template<class TModelPartType>
void ModelPartSetElements1(TModelPartType& rModelPart, typename TModelPartType::ElementsContainerType::Pointer pOtherElements)
{
    rModelPart.SetElements(pOtherElements);
}

template<class TModelPartType>
void ModelPartSetElements2(TModelPartType& rModelPart, typename TModelPartType::ElementsContainerType::Pointer pOtherElements, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.SetElements(pOtherElements, ThisIndex);
}

template<class TModelPartType>
void ModelPartAddElement1(TModelPartType& rModelPart, typename TModelPartType::ElementType::Pointer newElement)
{
    rModelPart.AddElement( newElement );
}

template<class TModelPartType>
void ModelPartAddElement2(TModelPartType& rModelPart, typename TModelPartType::ElementType::Pointer newElement, unsigned int ThisIndex)
{
    rModelPart.AddElement( newElement, ThisIndex );
}

template<class TModelPartType>
typename TModelPartType::ElementType::Pointer ModelPartGetElement1(TModelPartType& rModelPart, typename TModelPartType::IndexType ElementId)
{
    return rModelPart.pGetElement(ElementId);
}

template<class TModelPartType>
typename TModelPartType::ElementType::Pointer ModelPartGetElement2(TModelPartType& rModelPart, typename TModelPartType::IndexType ElementId, typename TModelPartType::IndexType ThisIndex)
{
    return rModelPart.pGetElement(ElementId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveElement1(TModelPartType& rModelPart, typename TModelPartType::IndexType ElementId)
{
    rModelPart.RemoveElement(ElementId);
}

template<class TModelPartType>
void ModelPartRemoveElement2(TModelPartType& rModelPart, typename TModelPartType::IndexType ElementId, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveElement(ElementId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveElement3(TModelPartType& rModelPart, typename TModelPartType::ElementType::Pointer pThisElement)
{
    rModelPart.RemoveElement(pThisElement);
}

template<class TModelPartType>
void ModelPartRemoveElement4(TModelPartType& rModelPart, typename TModelPartType::ElementType::Pointer pThisElement, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveElement(pThisElement, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveElementFromAllLevels1(TModelPartType& rModelPart, typename TModelPartType::IndexType ElementId)
{
    rModelPart.RemoveElementFromAllLevels(ElementId);
}

template<class TModelPartType>
void ModelPartRemoveElementFromAllLevels2(TModelPartType& rModelPart, typename TModelPartType::IndexType ElementId, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveElementFromAllLevels(ElementId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveElementFromAllLevels3(TModelPartType& rModelPart, typename TModelPartType::ElementType::Pointer pThisElement)
{
    rModelPart.RemoveElementFromAllLevels(pThisElement);
}

template<class TModelPartType>
void ModelPartRemoveElementFromAllLevels4(TModelPartType& rModelPart, typename TModelPartType::ElementType::Pointer pThisElement, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveElementFromAllLevels(pThisElement, ThisIndex);
}

template<class TModelPartType>
typename TModelPartType::SizeType ModelPartNumberOfConditions1(TModelPartType& rModelPart)
{
    return rModelPart.NumberOfConditions();
}

template<class TModelPartType>
typename TModelPartType::ConditionsContainerType::Pointer ModelPartGetConditions1(TModelPartType& rModelPart)
{
    return rModelPart.pConditions();
}

template<class TModelPartType>
typename TModelPartType::ConditionsContainerType::Pointer ModelPartGetConditions2(TModelPartType& rModelPart, typename TModelPartType::IndexType ThisIndex)
{
    return rModelPart.pConditions(ThisIndex);
}

template<class TModelPartType>
void ModelPartSetConditions1(TModelPartType& rModelPart, typename TModelPartType::ConditionsContainerType::Pointer pOtherConditions)
{
    rModelPart.SetConditions(pOtherConditions);
}

template<class TModelPartType>
void ModelPartSetConditions2(TModelPartType& rModelPart, typename TModelPartType::ConditionsContainerType::Pointer pOtherConditions, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.SetConditions(pOtherConditions, ThisIndex);
}

template<class TModelPartType>
void ModelPartAddCondition1(TModelPartType& rModelPart, typename TModelPartType::ConditionType::Pointer newCondition)
{
    rModelPart.AddCondition( newCondition );
}

template<class TModelPartType>
void ModelPartAddCondition2(TModelPartType& rModelPart, typename TModelPartType::ConditionType::Pointer newCondition, unsigned int ThisIndex)
{
    rModelPart.AddCondition( newCondition, ThisIndex );
}

template<class TModelPartType>
typename TModelPartType::ConditionType::Pointer ModelPartGetCondition1(TModelPartType& rModelPart, typename TModelPartType::IndexType ConditionId)
{
    return rModelPart.pGetCondition(ConditionId);
}

template<class TModelPartType>
typename TModelPartType::ConditionType::Pointer ModelPartGetCondition2(TModelPartType& rModelPart, typename TModelPartType::IndexType ConditionId, typename TModelPartType::IndexType ThisIndex)
{
    return rModelPart.pGetCondition(ConditionId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveCondition1(TModelPartType& rModelPart, typename TModelPartType::IndexType ConditionId)
{
    rModelPart.RemoveCondition(ConditionId);
}

template<class TModelPartType>
void ModelPartRemoveCondition2(TModelPartType& rModelPart, typename TModelPartType::IndexType ConditionId, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveCondition(ConditionId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveCondition3(TModelPartType& rModelPart, typename TModelPartType::ConditionType::Pointer pThisCondition)
{
    rModelPart.RemoveCondition(pThisCondition);
}

template<class TModelPartType>
void ModelPartRemoveCondition4(TModelPartType& rModelPart, typename TModelPartType::ConditionType::Pointer pThisCondition, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveCondition(pThisCondition, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveConditionFromAllLevels1(TModelPartType& rModelPart, typename TModelPartType::IndexType ConditionId)
{
    rModelPart.RemoveConditionFromAllLevels(ConditionId);
}

template<class TModelPartType>
void ModelPartRemoveConditionFromAllLevels2(TModelPartType& rModelPart, typename TModelPartType::IndexType ConditionId, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveConditionFromAllLevels(ConditionId, ThisIndex);
}

template<class TModelPartType>
void ModelPartRemoveConditionFromAllLevels3(TModelPartType& rModelPart, typename TModelPartType::ConditionType::Pointer pThisCondition)
{
    rModelPart.RemoveConditionFromAllLevels(pThisCondition);
}

template<class TModelPartType>
void ModelPartRemoveConditionFromAllLevels4(TModelPartType& rModelPart, typename TModelPartType::ConditionType::Pointer pThisCondition, typename TModelPartType::IndexType ThisIndex)
{
    rModelPart.RemoveConditionFromAllLevels(pThisCondition, ThisIndex);
}

template<class TModelPartType>
void CreateNewMasterSlaveConstraint1(TModelPartType& rModelPart,
    std::string ConstraintName,
    typename TModelPartType::IndexType Id,
    typename TModelPartType::DofsVectorType& rMasterDofsVector,
    typename TModelPartType::DofsVectorType& rSlaveDofsVector,
    const typename TModelPartType::MatrixType& RelationMatrix,
    const typename TModelPartType::VectorType& ConstantVector)
{
    rModelPart.CreateNewMasterSlaveConstraint(ConstraintName, Id, rMasterDofsVector, rSlaveDofsVector, RelationMatrix, ConstantVector);
}

template<class TModelPartType>
void CreateNewMasterSlaveConstraint2(TModelPartType& rModelPart,
    std::string ConstraintName,
    typename TModelPartType::IndexType Id,
    typename TModelPartType::NodeType& rMasterNode,
    typename TModelPartType::DoubleVariableType& rMasterVariable,
    typename TModelPartType::NodeType& rSlaveNode,
    typename TModelPartType::DoubleVariableType& rSlaveVariable,
    typename TModelPartType::DataType Weight,
    typename TModelPartType::DataType Constant)
{
    rModelPart.CreateNewMasterSlaveConstraint(ConstraintName, Id, rMasterNode, rMasterVariable, rSlaveNode, rSlaveVariable, Weight, Constant);
}

template<class TModelPartType>
void CreateNewMasterSlaveConstraint3(TModelPartType& rModelPart,
    std::string ConstraintName,
    typename TModelPartType::IndexType Id,
    typename TModelPartType::NodeType& rMasterNode,
    typename TModelPartType::VariableComponentType& rMasterVariable,
    typename TModelPartType::NodeType& rSlaveNode,
    typename TModelPartType::VariableComponentType& rSlaveVariable,
    typename TModelPartType::DataType Weight,
    typename TModelPartType::DataType Constant)
{
    rModelPart.CreateNewMasterSlaveConstraint(ConstraintName, Id, rMasterNode, rMasterVariable, rSlaveNode, rSlaveVariable, Weight, Constant);
}

template<class TModelPartType>
void ModelPartAddMasterSlaveConstraint(TModelPartType& rModelPart, typename TModelPartType::MasterSlaveConstraintType::Pointer pMasterSlaveConstraint)
{
    rModelPart.AddMasterSlaveConstraint(pMasterSlaveConstraint);
}

template<class TModelPartType>
void AddMasterSlaveConstraintsByIds(TModelPartType& rModelPart, std::vector<typename TModelPartType::IndexType>& ConstraintIds )
{
    rModelPart.AddMasterSlaveConstraints(ConstraintIds);
}

template<class TModelPartType, typename TVariableType>
void CreateNewLinearMasterSlaveConstraint(TModelPartType& rModelPart,
    std::string ConstraintName,
    typename TModelPartType::IndexType Id,
    typename TModelPartType::NodeType::Pointer pSlaveNode,
    boost::python::list py_master_nodes,
    const TVariableType& rVariable,
    const typename TModelPartType::MatrixType& RelationMatrix,
    const typename TModelPartType::VectorType& ConstantVector)
{
    std::vector<typename TModelPartType::NodeType::Pointer> pMasterNodes;

    typedef boost::python::stl_input_iterator<typename TModelPartType::NodeType::Pointer> iterator_value_type;
    BOOST_FOREACH(const typename iterator_value_type::value_type& p_node, std::make_pair(iterator_value_type(py_master_nodes), iterator_value_type() ) )
    {
        pMasterNodes.push_back(p_node);
    }

    ConstraintUtilities<TModelPartType>::CreateLinearConstraint(rModelPart, ConstraintName, Id, pSlaveNode, pMasterNodes, rVariable, RelationMatrix, ConstantVector);
}

template<class TModelPartType>
typename TModelPartType::MasterSlaveConstraintContainerType::Pointer ModelPartGetMasterSlaveConstraints1(TModelPartType& rModelPart)
{
    return rModelPart.pMasterSlaveConstraints();
}

template<class TModelPartType>
typename TModelPartType::SizeType ModelPartNumberOfMasterSlaveConstraints1(TModelPartType& rModelPart)
{
    return rModelPart.NumberOfMasterSlaveConstraints();
}

// template<class TModelPartType>
// TModelPartType::MasterSlaveConstraintType::Pointer ModelPartGetMasterSlaveConstraint1(TModelPartType& rModelPart, typename TModelPartType::IndexType MasterSlaveConstraintId)
// {
//     return rModelPart.pGetMasterSlaveConstraint(MasterSlaveConstraintId);
// }

template<class TModelPartType>
void ModelPartRemoveMasterSlaveConstraint1(TModelPartType& rModelPart, typename TModelPartType::IndexType MasterSlaveConstraintId)
{
    rModelPart.RemoveMasterSlaveConstraint(MasterSlaveConstraintId);
}

template<class TModelPartType>
void ModelPartRemoveMasterSlaveConstraint2(TModelPartType& rModelPart, typename TModelPartType::MasterSlaveConstraintType& rOtherMasterSlaveConstraint)
{
    rModelPart.RemoveMasterSlaveConstraint(rOtherMasterSlaveConstraint);
}

template<class TModelPartType>
void ModelPartRemoveMasterSlaveConstraintFromAllLevels1(TModelPartType& rModelPart, typename TModelPartType::IndexType MasterSlaveConstraintId)
{
    rModelPart.RemoveMasterSlaveConstraintFromAllLevels(MasterSlaveConstraintId);
}

template<class TModelPartType>
void ModelPartRemoveMasterSlaveConstraintFromAllLevels2(TModelPartType& rModelPart, typename TModelPartType::MasterSlaveConstraintType& rMasterSlaveConstraint)
{
    rModelPart.RemoveMasterSlaveConstraintFromAllLevels(rMasterSlaveConstraint);
}

template<class TCommunicatorType>
int CommunicatorSumAllInt(TCommunicatorType& rCommunicator, const int& value)
{
    int temp = value;
    rCommunicator.SumAll(temp);
    return temp;
}

template<class TCommunicatorType, typename TDataType>
TDataType CommunicatorSumAllDouble(TCommunicatorType& rCommunicator, const TDataType& value)
{
    TDataType temp = value;
    rCommunicator.SumAll(temp);
    return temp;
}

template<class TCommunicatorType>
int CommunicatorMinAllInt(TCommunicatorType& rCommunicator, const int& value)
{
    int temp = value;
    rCommunicator.MinAll(temp);
    return temp;
}

template<class TCommunicatorType, typename TDataType>
TDataType CommunicatorMinAllDouble(TCommunicatorType& rCommunicator, const TDataType& value)
{
    TDataType temp = value;
    rCommunicator.MinAll(temp);
    return temp;
}

template<class TCommunicatorType>
int CommunicatorMaxAllInt(TCommunicatorType& rCommunicator, const int& value)
{
    int temp = value;
    rCommunicator.MaxAll(temp);
    return temp;
}

template<class TCommunicatorType, typename TDataType>
TDataType CommunicatorMaxAllDouble(TCommunicatorType& rCommunicator, const TDataType& value)
{
    TDataType temp = value;
    rCommunicator.MaxAll(temp);
    return temp;
}

template<class TCommunicatorType>
typename TCommunicatorType::MeshType& CommunicatorGetLocalMesh(TCommunicatorType& rCommunicator)
{
    return rCommunicator.LocalMesh();
}

template<class TCommunicatorType>
typename TCommunicatorType::MeshType& CommunicatorGetLocalMeshWithIndex(TCommunicatorType& rCommunicator, typename TCommunicatorType::IndexType Index)
{
    return rCommunicator.LocalMesh(Index);
}

template<class TCommunicatorType>
typename TCommunicatorType::MeshType& CommunicatorGetGhostMesh(TCommunicatorType& rCommunicator)
{
    return rCommunicator.GhostMesh();
}

template<class TCommunicatorType>
typename TCommunicatorType::MeshType& CommunicatorGetGhostMeshWithIndex(TCommunicatorType& rCommunicator, typename TCommunicatorType::IndexType Index)
{
    return rCommunicator.GhostMesh(Index);
}

template<class TCommunicatorType>
typename TCommunicatorType::MeshType& CommunicatorGetInterfaceMesh(TCommunicatorType& rCommunicator)
{
    return rCommunicator.InterfaceMesh();
}

template<class TCommunicatorType>
typename TCommunicatorType::MeshType& CommunicatorGetInterfaceMeshWithIndex(TCommunicatorType& rCommunicator, typename TCommunicatorType::IndexType Index)
{
    return rCommunicator.InterfaceMesh(Index);
}

template<class TCommunicatorType>
typename TCommunicatorType::NeighbourIndicesContainerType const&  NeighbourIndicesConst(TCommunicatorType& rCommunicator)
{
    return rCommunicator.NeighbourIndices();
}

template<class TCommunicatorType>
typename TCommunicatorType::IndexType CommunicatorGetLastNodeId(TCommunicatorType& rCommunicator)
{
    return rCommunicator.GetLastNodeId();
}

template<class TCommunicatorType>
typename TCommunicatorType::IndexType CommunicatorGetLastElementId(TCommunicatorType& rCommunicator)
{
    return rCommunicator.GetLastElementId();
}

template<class TCommunicatorType>
typename TCommunicatorType::IndexType CommunicatorGetLastConditionId(TCommunicatorType& rCommunicator)
{
    return rCommunicator.GetLastConditionId();
}

template<class TModelPartType>
typename TModelPartType::CommunicatorType& ModelPartGetCommunicator(TModelPartType& rModelPart)
{
    return rModelPart.GetCommunicator();
}

template<class TModelPartType>
void RemoveSubModelPart1(TModelPartType& rModelPart, std::string const& ThisSubModelPartName)
{
    rModelPart.RemoveSubModelPart(ThisSubModelPartName);
}

template<class TModelPartType>
void RemoveSubModelPart2(TModelPartType& rModelPart, TModelPartType& ThisSubModelPart)
{
    rModelPart.RemoveSubModelPart(ThisSubModelPart);
}

template<class TCommunicatorType, typename TDataType>
bool CommunicatorAssembleCurrentData(TCommunicatorType& rCommunicator, Variable<TDataType> const& ThisVariable)
{
    return rCommunicator.AssembleCurrentData(ThisVariable);
}

template<class TCommunicatorType, typename TDataType>
bool CommunicatorAssembleNonHistoricalData(TCommunicatorType& rCommunicator, Variable<TDataType> const& ThisVariable)
{
    return rCommunicator.AssembleNonHistoricalData(ThisVariable);
}

template<class TModelPartType>
void AddModelPartToPythonImpl(const std::string& Prefix)
{
    typedef typename TModelPartType::CommunicatorType CommunicatorType;
    typedef typename TModelPartType::IndexType IndexType;
    typedef typename TModelPartType::DataType DataType;
    typedef typename TModelPartType::VectorType VectorType;
    typedef typename TModelPartType::MatrixType MatrixType;

    IndexType(TModelPartType::*pointer_to_clone_time_step_1)(void) = &TModelPartType::CloneTimeStep;
    IndexType(TModelPartType::*pointer_to_clone_time_step_2)(typename TModelPartType::ValueType) = &TModelPartType::CloneTimeStep;
    ProcessInfo::Pointer(TModelPartType::*pointer_to_get_process_info)(void) = &TModelPartType::pGetProcessInfo;
    void (TModelPartType::*pointer_to_set_process_info)(ProcessInfo::Pointer) = &TModelPartType::SetProcessInfo;
    // TModelPartType::MeshType::Pointer (TModelPartType::*pointer_to_get_mesh)() = &TModelPartType::pGetMesh;
    //    std::string& (TModelPartType::*pointer_to_name)(void) = &TModelPartType::Name;

    using namespace boost::python;

    class_<CommunicatorType>((Prefix + "Communicator").c_str())
    .def(init<>())
    .def("MyPID", &CommunicatorType::MyPID)
    .def("TotalProcesses", &CommunicatorType::TotalProcesses)
    .def("GetNumberOfColors", &CommunicatorType::GetNumberOfColors)
    .def("NeighbourIndices", NeighbourIndicesConst<CommunicatorType>, return_internal_reference<>())
    .def("SynchronizeNodalSolutionStepsData", &CommunicatorType::SynchronizeNodalSolutionStepsData)
    .def("SynchronizeDofs", &CommunicatorType::SynchronizeDofs)
    .def("SumAll", CommunicatorSumAllInt<CommunicatorType> )
    .def("SumAll", CommunicatorSumAllDouble<CommunicatorType, DataType> )
    .def("MinAll", CommunicatorMinAllInt<CommunicatorType> )
    .def("MinAll", CommunicatorMinAllDouble<CommunicatorType, DataType> )
    .def("MaxAll", CommunicatorMaxAllInt<CommunicatorType> )
    .def("MaxAll", CommunicatorMaxAllDouble<CommunicatorType, DataType> )
    .def("LocalMesh", CommunicatorGetLocalMesh<CommunicatorType>, return_internal_reference<>() )
    .def("LocalMesh", CommunicatorGetLocalMeshWithIndex<CommunicatorType>, return_internal_reference<>() )
    .def("GhostMesh", CommunicatorGetGhostMesh<CommunicatorType>, return_internal_reference<>() )
    .def("GhostMesh", CommunicatorGetGhostMeshWithIndex<CommunicatorType>, return_internal_reference<>() )
    .def("InterfaceMesh", CommunicatorGetInterfaceMesh<CommunicatorType>, return_internal_reference<>() )
    .def("InterfaceMesh", CommunicatorGetInterfaceMeshWithIndex<CommunicatorType>, return_internal_reference<>() )
    .def("GetLastNodeId", CommunicatorGetLastNodeId<CommunicatorType> )
    .def("GetLastElementId", CommunicatorGetLastElementId<CommunicatorType> )
    .def("GetLastConditionId", CommunicatorGetLastConditionId<CommunicatorType> )
    .def("AssembleCurrentData", CommunicatorAssembleCurrentData<CommunicatorType, int> )
    .def("AssembleCurrentData", CommunicatorAssembleCurrentData<CommunicatorType, DataType> )
    .def("AssembleCurrentData", CommunicatorAssembleCurrentData<CommunicatorType, array_1d<DataType,3> > )
    .def("AssembleCurrentData", CommunicatorAssembleCurrentData<CommunicatorType, VectorType> )
    .def("AssembleCurrentData", CommunicatorAssembleCurrentData<CommunicatorType, MatrixType> )
    .def("AssembleNonHistoricalData", CommunicatorAssembleNonHistoricalData<CommunicatorType, int> )
    .def("AssembleNonHistoricalData", CommunicatorAssembleNonHistoricalData<CommunicatorType, DataType> )
    .def("AssembleNonHistoricalData", CommunicatorAssembleNonHistoricalData<CommunicatorType, array_1d<DataType,3> > )
    .def("AssembleNonHistoricalData", CommunicatorAssembleNonHistoricalData<CommunicatorType, VectorType> )
    .def("AssembleNonHistoricalData", CommunicatorAssembleNonHistoricalData<CommunicatorType, MatrixType> )
    ;

    PointerVectorSetPythonInterface<typename TModelPartType::MasterSlaveConstraintContainerType>::CreateInterface((Prefix + "MasterSlaveConstraintsArray").c_str());

    class_<TModelPartType, bases<DataValueContainer, Flags> >((Prefix + "ModelPart").c_str(), init<>())
    .def(init<std::string const&>())
    .add_property("Name", GetModelPartName<TModelPartType>, SetModelPartName<TModelPartType>)
    .add_property("Type", GetModelPartType<TModelPartType>)
    //  .add_property("ProcessInfo", GetProcessInfo, SetProcessInfo)
    .add_property("ProcessInfo", pointer_to_get_process_info, pointer_to_set_process_info)
    .def("CreateSolutionStep", &TModelPartType::CreateSolutionStep)
    .def("CloneSolutionStep", &TModelPartType::CloneSolutionStep)
    .def("CreateTimeStep", &TModelPartType::CreateTimeStep)
    .def("ReduceTimeStep", &TModelPartType::ReduceTimeStep)
    .def("CloneTimeStep", pointer_to_clone_time_step_1)
    .def("CloneTimeStep", pointer_to_clone_time_step_2)
    //    .def("CopySolutionStepData",&TModelPartType::CopySolutionStepData)
    .def("NumberOfNodes", &TModelPartType::NumberOfNodes)
    .def("NumberOfNodes", ModelPartNumberOfNodes1<TModelPartType>)
    .def("SetBufferSize", &TModelPartType::SetBufferSize)
    .def("GetBufferSize", &TModelPartType::GetBufferSize)
    .def("NumberOfElements", ModelPartNumberOfElements1<TModelPartType>)
    .def("NumberOfElements", &TModelPartType::NumberOfElements)
    .def("NumberOfConditions", ModelPartNumberOfConditions1<TModelPartType>)
    .def("NumberOfConditions", &TModelPartType::NumberOfConditions)
    .def("NumberOfMasterSlaveConstraints", ModelPartNumberOfMasterSlaveConstraints1<TModelPartType>)
    .def("NumberOfMasterSlaveConstraints", &TModelPartType::NumberOfMasterSlaveConstraints)
    .def("NumberOfMeshes", &TModelPartType::NumberOfMeshes)
    .def("NumberOfProperties", &TModelPartType::NumberOfProperties)
    .def("NumberOfProperties", ModelPartNumberOfProperties1<TModelPartType>)
    .def("GetMesh", ModelPartGetMesh<TModelPartType>)
    .def("GetMesh", ModelPartGetMesh2<TModelPartType>)
    .add_property("Nodes", ModelPartGetNodes1<TModelPartType>, ModelPartSetNodes1<TModelPartType>)
    .def("GetNode", ModelPartGetNode1<TModelPartType>)
    .def("GetNode", ModelPartGetNode2<TModelPartType>)
    .def("GetNodes", ModelPartGetNodes1<TModelPartType>)
    .def("SetNodes", ModelPartSetNodes1<TModelPartType>)
    .def("GetNodes", ModelPartGetNodes2<TModelPartType>)
    .def("SetNodes", ModelPartSetNodes2<TModelPartType>)
    .def("RemoveNode", ModelPartRemoveNode1<TModelPartType>)
    .def("RemoveNode", ModelPartRemoveNode2<TModelPartType>)
    .def("RemoveNode", ModelPartRemoveNode3<TModelPartType>)
    .def("RemoveNode", ModelPartRemoveNode4<TModelPartType>)
    .def("RemoveNodeFromAllLevels", ModelPartRemoveNodeFromAllLevels1<TModelPartType>)
    .def("RemoveNodeFromAllLevels", ModelPartRemoveNodeFromAllLevels2<TModelPartType>)
    .def("RemoveNodeFromAllLevels", ModelPartRemoveNodeFromAllLevels3<TModelPartType>)
    .def("RemoveNodeFromAllLevels", ModelPartRemoveNodeFromAllLevels4<TModelPartType>)
    .def("NodesArray", &TModelPartType::NodesArray, return_internal_reference<>())
    .def("NumberOfTables", &TModelPartType::NumberOfTables)
    .def("AddTable", &TModelPartType::AddTable)
    .def("GetTable", &TModelPartType::pGetTable)
    .add_property("Properties", ModelPartGetProperties1<TModelPartType>, ModelPartSetProperties1<TModelPartType>)
    .def("AddProperties", ModelPartAddProperties1<TModelPartType>)
    .def("AddProperties", ModelPartAddProperties2<TModelPartType>)
    .def("GetProperties", ModelPartGetProperties1<TModelPartType>)
    .def("SetProperties", ModelPartSetProperties1<TModelPartType>)
    .def("GetProperties", ModelPartGetProperties2<TModelPartType>)
    .def("SetProperties", ModelPartSetProperties2<TModelPartType>)
    .def("RemoveProperties", ModelPartRemoveProperties1<TModelPartType>)
    .def("RemoveProperties", ModelPartRemoveProperties2<TModelPartType>)
    .def("RemoveProperties", ModelPartRemoveProperties3<TModelPartType>)
    .def("RemoveProperties", ModelPartRemoveProperties4<TModelPartType>)
    .def("RemovePropertiesFromAllLevels", ModelPartRemovePropertiesFromAllLevels1<TModelPartType>)
    .def("RemovePropertiesFromAllLevels", ModelPartRemovePropertiesFromAllLevels2<TModelPartType>)
    .def("RemovePropertiesFromAllLevels", ModelPartRemovePropertiesFromAllLevels3<TModelPartType>)
    .def("RemovePropertiesFromAllLevels", ModelPartRemovePropertiesFromAllLevels4<TModelPartType>)
    // .def("PropertiesArray", &TModelPartType::PropertiesArray, return_internal_reference<>())
    .add_property("Elements", ModelPartGetElements1<TModelPartType>, ModelPartSetElements1<TModelPartType>)
    .def("GetElement", ModelPartGetElement1<TModelPartType>)
    .def("GetElement", ModelPartGetElement2<TModelPartType>)
    .def("GetElements", ModelPartGetElements1<TModelPartType>)
    .def("SetElements", ModelPartSetElements1<TModelPartType>)
    .def("GetElements", ModelPartGetElements2<TModelPartType>)
    .def("SetElements", ModelPartSetElements2<TModelPartType>)
    .def("AddElement", ModelPartAddElement1<TModelPartType>)
    .def("AddElement", ModelPartAddElement2<TModelPartType>)
    .def("RemoveElement", ModelPartRemoveElement1<TModelPartType>)
    .def("RemoveElement", ModelPartRemoveElement2<TModelPartType>)
    .def("RemoveElement", ModelPartRemoveElement3<TModelPartType>)
    .def("RemoveElement", ModelPartRemoveElement4<TModelPartType>)
    .def("RemoveElementFromAllLevels", ModelPartRemoveElementFromAllLevels1<TModelPartType>)
    .def("RemoveElementFromAllLevels", ModelPartRemoveElementFromAllLevels2<TModelPartType>)
    .def("RemoveElementFromAllLevels", ModelPartRemoveElementFromAllLevels3<TModelPartType>)
    .def("RemoveElementFromAllLevels", ModelPartRemoveElementFromAllLevels4<TModelPartType>)
    // .def("ElementsArray", &TModelPartType::ElementsArray, return_internal_reference<>())
    .add_property("Conditions", ModelPartGetConditions1<TModelPartType>, ModelPartSetConditions1<TModelPartType>)
    .def("GetCondition", ModelPartGetCondition1<TModelPartType>)
    .def("GetCondition", ModelPartGetCondition2<TModelPartType>)
    .def("GetConditions", ModelPartGetConditions1<TModelPartType>)
    .def("SetConditions", ModelPartSetConditions1<TModelPartType>)
    .def("GetConditions", ModelPartGetConditions2<TModelPartType>)
    .def("SetConditions", ModelPartSetConditions2<TModelPartType>)
    .def("AddCondition", ModelPartAddCondition1<TModelPartType>)
    .def("AddCondition", ModelPartAddCondition2<TModelPartType>)
    .def("RemoveCondition", ModelPartRemoveCondition1<TModelPartType>)
    .def("RemoveCondition", ModelPartRemoveCondition2<TModelPartType>)
    .def("RemoveCondition", ModelPartRemoveCondition3<TModelPartType>)
    .def("RemoveCondition", ModelPartRemoveCondition4<TModelPartType>)
    .def("RemoveConditionFromAllLevels", ModelPartRemoveConditionFromAllLevels1<TModelPartType>)
    .def("RemoveConditionFromAllLevels", ModelPartRemoveConditionFromAllLevels2<TModelPartType>)
    .def("RemoveConditionFromAllLevels", ModelPartRemoveConditionFromAllLevels3<TModelPartType>)
    .def("RemoveConditionFromAllLevels", ModelPartRemoveConditionFromAllLevels4<TModelPartType>)
    .def("CreateSubModelPart", &TModelPartType::CreateSubModelPart, return_internal_reference<>())
    .def("NumberOfSubModelParts", &TModelPartType::NumberOfSubModelParts)
    .def("GetSubModelPart", &TModelPartType::GetSubModelPart, return_internal_reference<>())
    .def("RemoveSubModelPart", RemoveSubModelPart1<TModelPartType>)
    .def("RemoveSubModelPart", RemoveSubModelPart2<TModelPartType>)
    .def("HasSubModelPart", &TModelPartType::HasSubModelPart)
    // .def("ConditionsArray", &TModelPartType::ConditionsArray, return_internal_reference<>())
    .def("AddNodalSolutionStepVariable", AddNodalSolutionStepVariable<TModelPartType, bool>)
    .def("AddNodalSolutionStepVariable", AddNodalSolutionStepVariable<TModelPartType, int>)
    .def("AddNodalSolutionStepVariable", AddNodalSolutionStepVariable<TModelPartType, DataType>)
    .def("AddNodalSolutionStepVariable", AddNodalSolutionStepVariable<TModelPartType, array_1d<DataType, 3 > >)
    .def("AddNodalSolutionStepVariable", AddNodalSolutionStepVariable<TModelPartType, VectorType>)
    .def("AddNodalSolutionStepVariable", AddNodalSolutionStepVariable<TModelPartType, MatrixType>)
    .def("GetNodalSolutionStepDataSize", &TModelPartType::GetNodalSolutionStepDataSize)
    .def("GetNodalSolutionStepTotalDataSize", &TModelPartType::GetNodalSolutionStepTotalDataSize)
    .def("OverwriteSolutionStepData", &TModelPartType::OverwriteSolutionStepData)
    .def("CreateNewNode", ModelPartCreateNewNode<TModelPartType, typename TModelPartType::ValueType>)
    .def("CreateNewElement", ModelPartCreateNewElement<TModelPartType>)
    .def("CreateNewCondition", ModelPartCreateNewCondition<TModelPartType>)
    .def("GetCommunicator", ModelPartGetCommunicator<TModelPartType>, return_internal_reference<>())
    .def("Check", &TModelPartType::Check)
    .def("IsSubModelPart", &TModelPartType::IsSubModelPart)
    .def("GetLastNodeId", &TModelPartType::GetLastNodeId )
    .def("GetLastElementId", &TModelPartType::GetLastElementId )
    .def("GetLastConditionId", &TModelPartType::GetLastConditionId )
    .def("GetLastConstraintId", &TModelPartType::GetLastConstraintId )

    .add_property("MasterSlaveConstraints", ModelPartGetMasterSlaveConstraints1<TModelPartType>)
    // .def("GetMasterSlaveConstraint", ModelPartGetMasterSlaveConstraint1<TModelPartType>)
    // .def("GetMasterSlaveConstraints", ModelPartGetMasterSlaveConstraints1<TModelPartType>)
    .def("RemoveMasterSlaveConstraint", ModelPartRemoveMasterSlaveConstraint1<TModelPartType>)
    .def("RemoveMasterSlaveConstraint", ModelPartRemoveMasterSlaveConstraint2<TModelPartType>)
    .def("RemoveMasterSlaveConstraintFromAllLevels", ModelPartRemoveMasterSlaveConstraintFromAllLevels1<TModelPartType>)
    .def("RemoveMasterSlaveConstraintFromAllLevels", ModelPartRemoveMasterSlaveConstraintFromAllLevels2<TModelPartType>)
    .def("RemoveMasterSlaveConstraints", &TModelPartType::RemoveMasterSlaveConstraints)
    .def("RemoveMasterSlaveConstraintsFromAllLevels", &TModelPartType::RemoveMasterSlaveConstraintsFromAllLevels)
    .def("AddMasterSlaveConstraint", ModelPartAddMasterSlaveConstraint<TModelPartType>)
    .def("AddMasterSlaveConstraints", AddMasterSlaveConstraintsByIds<TModelPartType>)
    .def("CreateNewMasterSlaveConstraint", CreateNewMasterSlaveConstraint1<TModelPartType>)
    .def("CreateNewMasterSlaveConstraint", CreateNewMasterSlaveConstraint2<TModelPartType>)
    .def("CreateNewMasterSlaveConstraint", CreateNewMasterSlaveConstraint3<TModelPartType>)
    .def("CreateNewLinearMasterSlaveConstraint", CreateNewLinearMasterSlaveConstraint<TModelPartType, typename TModelPartType::VariableComponentType>)
    .def("CreateNewLinearMasterSlaveConstraint", CreateNewLinearMasterSlaveConstraint<TModelPartType, typename TModelPartType::DoubleVariableType>)
    .def(self_ns::str(self))
    ;

    class_<typename TModelPartType::DofsArrayType, boost::noncopyable>((Prefix + "DofsArrayType").c_str(), init<>());
}

void AddModelPartToPython()
{
    AddModelPartToPythonImpl<ModelPart>("");
    AddModelPartToPythonImpl<ComplexModelPart>("Complex");
    AddModelPartToPythonImpl<GComplexModelPart>("GComplex");
}

} // namespace Python.

} // Namespace Kratos
