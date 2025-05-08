//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//  Contributors:    Hoang-Giang Bui
//
//

// System includes


// External includes


// Project includes
#include "includes/define.h"
#include "includes/node.h"
#include "includes/model_part.h"
#include "includes/process_info_with_dofs.h"
#include "containers/model.h"
#include "utilities/progress.h"
#include "boost/make_shared.hpp"

namespace Kratos
{

KRATOS_CREATE_LOCAL_FLAG(BaseModelPart, ALL_ENTITIES, 0);
KRATOS_CREATE_LOCAL_FLAG(BaseModelPart, OVERWRITE_ENTITIES, 1);

BaseModelPart::BaseModelPart()
    : DataValueContainer()
    , Flags()
    , mpParentModelPart(nullptr)
    , mSubModelParts()
    , mName("Default")
    , mpModel(nullptr)
{
}

BaseModelPart::BaseModelPart(std::string const& NewName)
    : DataValueContainer()
    , Flags()
    , mpParentModelPart(nullptr)
    , mSubModelParts()
    , mName(NewName)
    , mpModel(nullptr)
{
}

BaseModelPart::BaseModelPart(std::string const& NewName, Model& rOwnerModel)
    : DataValueContainer()
    , Flags()
    , mpParentModelPart(nullptr)
    , mSubModelParts()
    , mName(NewName)
    , mpModel(&rOwnerModel)
{
}

BaseModelPart::BaseModelPart(BaseModelPart const& rOther)
    : DataValueContainer(rOther)
    , Flags(rOther)
    , mpParentModelPart(rOther.mpParentModelPart)
    , mSubModelParts(rOther.mSubModelParts)
    , mName(rOther.mName)
    , mpModel(rOther.mpModel)
{
}

BaseModelPart& BaseModelPart::operator=(BaseModelPart const& rOther)
{
    mName = rOther.mName;
    // I should not set the parent for a model part while it breaks the hierarchy. Pooyan.
    //mpParentModelPart = rOther.mpParentModelPart;
    mSubModelParts = rOther.mSubModelParts;

    //KRATOS_THROW_ERROR(std::logic_error, "This method needs updating and is not working. Pooyan", "")

    return *this;
}

Model& BaseModelPart::GetModel()
{
    if (mpModel == nullptr)
    {
        std::cout << "The ModelPart " << this->Name() << " is not associated with any model" << std::endl;
        return *pKratosDefaultModel;
    }
    else
        return *mpModel;
}

const Model& BaseModelPart::GetModel() const
{
    if (mpModel == nullptr)
    {
        std::cout << "The ModelPart " << this->Name() << " is not associated with any model" << std::endl;
        return *pKratosDefaultModel;
    }
    else
        return *mpModel;
}

BaseModelPart& BaseModelPart::CreateSubModelPart(std::string const& NewSubModelPartName)
{
    KRATOS_ERROR << "Error calling base class function";
}

void BaseModelPart::AddSubModelPart(BaseModelPart& rThisSubModelPart)
{
    rThisSubModelPart.SetParentModelPart(this);
}

BaseModelPart& BaseModelPart::GetRootModelPart()
{
    if (IsSubModelPart())
        return mpParentModelPart->GetRootModelPart();
    else
        return *this;
}

const BaseModelPart& BaseModelPart::GetRootModelPart() const
{
    if (IsSubModelPart())
        return mpParentModelPart->GetRootModelPart();
    else
        return *this;
}

void BaseModelPart::RemoveSubModelPart(std::string const& ThisSubModelPartName)
{
    // finding the sub model part
    SubModelPartIterator i_sub_model_part = mSubModelParts.find(ThisSubModelPartName);

    if (i_sub_model_part == mSubModelParts.end())
        return; // TODO: send a warning here. Pooyan.

    // deallocate the sub model part
    delete i_sub_model_part.base()->second;

    // now erase the pointer from the list
    mSubModelParts.erase(ThisSubModelPartName);
}

void BaseModelPart::RemoveSubModelPart(BaseModelPart& ThisSubModelPart)
{
    std::string name = ThisSubModelPart.Name();
    // finding the sub model part
    SubModelPartIterator i_sub_model_part = mSubModelParts.find(name);

    if (i_sub_model_part == mSubModelParts.end())
        KRATOS_ERROR << "The sub modelpart  \"" << name << "\" does not exist in the \"" << Name() << "\" model part to be removed" << std::endl;

                // deallocate the sub model part
    delete i_sub_model_part.base()->second;

    mSubModelParts.erase(name);
}

std::vector<std::string> BaseModelPart::GetSubModelPartNames()
{
    std::vector<std::string> SubModelPartsNames;

    for(auto& r_sub_model_part : mSubModelParts)
    {
        SubModelPartsNames.push_back(r_sub_model_part.Name());
    }

    return SubModelPartsNames;
}

std::string BaseModelPart::Info() const
{
    return this->Name() + " model part";
}

void BaseModelPart::PrintInfo(std::ostream& rOStream) const
{
    rOStream << Info();
}

void BaseModelPart::PrintData(std::ostream& rOStream) const
{
    rOStream << "    Number of sub model parts : " << NumberOfSubModelParts() << std::endl;
    rOStream << std::endl;

    for (SubModelPartConstantIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        i_sub_model_part->PrintInfo(rOStream, "    ");
        rOStream << std::endl;
        i_sub_model_part->PrintData(rOStream, "    ");
    }
}

void BaseModelPart::PrintInfo(std::ostream& rOStream, std::string const& PrefixString) const
{
    rOStream << PrefixString << Info();
}

void BaseModelPart::PrintData(std::ostream& rOStream, std::string const& PrefixString) const
{
    rOStream << PrefixString << "    Number of sub model parts : " << NumberOfSubModelParts() << std::endl;
    rOStream << std::endl;

    for (SubModelPartConstantIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        i_sub_model_part->PrintInfo(rOStream, PrefixString + "    ");
        rOStream << std::endl;
        i_sub_model_part->PrintData(rOStream, PrefixString + "    ");
    }
}

void BaseModelPart::save(Serializer& rSerializer) const
{
    KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, DataValueContainer);
    rSerializer.save("Name", this->Name());
}

void BaseModelPart::load(Serializer& rSerializer)
{
    KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, DataValueContainer);
    rSerializer.load("Name", this->Name());
}

/// Default constructor.
template<class TNodeType>
ModelPartImpl<TNodeType>::ModelPartImpl()
    : BaseModelPart("Default")
    , mBufferSize(1)
    , mpProcessInfo(new ProcessInfo())
    , mIndices(1, 0)
    , mpVariablesList(new VariablesListType)
    , mpCommunicator(new CommunicatorType)
{
    MeshType mesh;
    mMeshes.push_back(mesh.Clone());
    mpCommunicator->SetLocalMesh(pGetMesh());  // assigning the current mesh to the local mesh of communicator for openmp cases
}

/// Constructor with name
template<class TNodeType>
ModelPartImpl<TNodeType>::ModelPartImpl(std::string const& NewName)
    : BaseModelPart(NewName)
    , mBufferSize(1)
    , mpProcessInfo(new ProcessInfo())
    , mIndices(1, 0)
    , mpVariablesList(new VariablesListType)
    , mpCommunicator(new CommunicatorType)
{
    MeshType mesh;
    mMeshes.push_back(mesh.Clone());
    mpCommunicator->SetLocalMesh(pGetMesh());  // assigning the current mesh to the local mesh of communicator for openmp cases
}

/// Constructor with name and bufferSize
template<class TNodeType>
ModelPartImpl<TNodeType>::ModelPartImpl(std::string const& NewName, IndexType NewBufferSize)
    : BaseModelPart(NewName)
    , mBufferSize(NewBufferSize)
    , mpProcessInfo(new ProcessInfo())
    , mIndices(NewBufferSize, 0)
    , mpVariablesList(new VariablesListType)
    , mpCommunicator(new CommunicatorType)
{
    MeshType mesh;
    mMeshes.push_back(mesh.Clone());
    mpCommunicator->SetLocalMesh(pGetMesh());  // assigning the current mesh to the local mesh of communicator for openmp cases
    std::cout << "odelPart " << Name() << "(" << this << ")" << " is created" << std::endl;
}

/// Constructor with name and bufferSize and the owner model
template<class TNodeType>
ModelPartImpl<TNodeType>::ModelPartImpl(std::string const& NewName, IndexType NewBufferSize, Model& rOwnerModel)
    : BaseModelPart(NewName, rOwnerModel)
    , mBufferSize(NewBufferSize)
    , mpProcessInfo(new ProcessInfo())
    , mIndices(NewBufferSize, 0)
    , mpVariablesList(new VariablesListType)
    , mpCommunicator(new CommunicatorType)
{
    MeshType mesh;
    mMeshes.push_back(mesh.Clone());
    mpCommunicator->SetLocalMesh(pGetMesh());  // assigning the current mesh to the local mesh of communicator for openmp cases
    std::cout << "ModelPart " << Name() << "(" << this << ")" << " is created" << std::endl;
}

// Copy constructor.
template<class TNodeType>
ModelPartImpl<TNodeType>::ModelPartImpl(ModelPartImpl<TNodeType> const& rOther)
    : BaseModelPart(rOther)
    , mBufferSize(rOther.mBufferSize)
    , mpProcessInfo(rOther.mpProcessInfo)
    , mIndices(rOther.mIndices)
    , mMeshes(rOther.mMeshes)
    , mpVariablesList(new VariablesListType(*rOther.mpVariablesList))
    , mpCommunicator(rOther.mpCommunicator)
{
    std::cout << "ModelPart " << Name() << "(" << this << ")" << " is copied from " << rOther.Name() << std::endl;
}

/// Destructor.
template<class TNodeType>
ModelPartImpl<TNodeType>::~ModelPartImpl()
{
    for (NodeIterator i_node = NodesBegin(); i_node != NodesEnd(); i_node++)
    {
        if (i_node->pGetVariablesList() == mpVariablesList)
            i_node->ClearSolutionStepsData();
    }

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
        delete i_sub_model_part.base()->second;

    auto* pProcessInfoWithDofs = dynamic_cast<ProcessInfoWithDofs<DofType>*>(mpProcessInfo.get());
    if (pProcessInfoWithDofs != nullptr)
        pProcessInfoWithDofs->Finalize();

    if (!IsSubModelPart())
        delete mpVariablesList;

    std::cout << "ModelPart " << Name() << "(" << this << ")" << " destructor is called" << std::endl;
}

/// Assignment operator.
template<class TNodeType>
ModelPartImpl<TNodeType>& ModelPartImpl<TNodeType>::operator=(ModelPartImpl<TNodeType> const& rOther)
{
    BaseModelPart::operator=(rOther);
    mBufferSize = rOther.mBufferSize;
    mpProcessInfo = rOther.mpProcessInfo;
    mIndices = rOther.mIndices;
    mMeshes = rOther.mMeshes;

    //KRATOS_THROW_ERROR(std::logic_error, "This method needs updating and is not working. Pooyan", "")

    *mpVariablesList = *rOther.mpVariablesList;

    return *this;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::CreateSolutionStep()
{
    KRATOS_ERROR << "This method needs updating and is not working. Pooyan";
    return 0;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::CloneSolutionStep()
{
    if (IsSubModelPart())
      //Todo KRATOS_THROW_ERROR(std::logic_error, "Calling the method of the sub model part ", Name())
      KRATOS_ERROR << "Calling the CloneSolutionStep method of the sub model part " << Name()
            << " please call the one of the parent modelpart : " << mpParentModelPart->Name() << std::endl;

    for (NodeIterator node_iterator = NodesBegin(); node_iterator != NodesEnd(); node_iterator++)
        node_iterator->CloneSolutionStepData();

    mpProcessInfo->CloneSolutionStepInfo();

    auto* pProcessInfoWithDofs = dynamic_cast<ProcessInfoWithDofs<DofType>*>(mpProcessInfo.get());
    if (pProcessInfoWithDofs != nullptr)
    {
        pProcessInfoWithDofs->CloneSolutionStepData();
    }

    mpProcessInfo->ClearHistory(mBufferSize);

    return 0;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::CloneTimeStep()
{
    if (IsSubModelPart())
        KRATOS_ERROR << "Calling the CloneTimeStep method of the sub model part " << Name()
                     << " please call the one of the parent modelpart : " << mpParentModelPart->Name() << std::endl;

    IndexType new_index = CloneSolutionStep();
    mpProcessInfo->SetAsTimeStepInfo();

    return new_index;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::CreateTimeStep(ValueType NewTime)
{
    if (IsSubModelPart())
        KRATOS_ERROR << "Calling the CreateTimeStep method of the sub model part " << Name()
                     << " please call the one of the parent modelpart : " << mpParentModelPart->Name() << std::endl;

    IndexType new_index = CreateSolutionStep();
    mpProcessInfo->SetAsTimeStepInfo(NewTime);

    return new_index;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::CloneTimeStep(ValueType NewTime)
{
    if (IsSubModelPart())
        KRATOS_ERROR << "Calling the CloneTimeStep method of the sub model part " << Name()
                     << " please call the one of the parent modelpart : " << mpParentModelPart->Name() << std::endl;

    IndexType new_index = CloneSolutionStep();
    mpProcessInfo->SetAsTimeStepInfo(NewTime);

    return new_index;
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::OverwriteSolutionStepData(IndexType SourceSolutionStepIndex, IndexType DestinationSourceSolutionStepIndex)
{
    if (IsSubModelPart())
        KRATOS_ERROR << "Calling the OverwriteSolutionStepData method of the sub model part " << Name()
                     << " please call the one of the parent modelpart : " << mpParentModelPart->Name() << std::endl;

    for (NodeIterator node_iterator = NodesBegin(); node_iterator != NodesEnd(); node_iterator++)
        node_iterator->OverwriteSolutionStepData(SourceSolutionStepIndex, DestinationSourceSolutionStepIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::ReduceTimeStep(ModelPartImpl<TNodeType>& rModelPart, ValueType NewTime)
{
    KRATOS_TRY

        //ATTENTION: this function does not touch the coordinates of the nodes.
        //It just resets the database values to the values at the beginning of the time step

        if (IsSubModelPart())
            KRATOS_ERROR << "Calling the OverwriteSolutionStepData method of the sub model part " << Name()
                         << " please call the one of the parent modelpart : " << mpParentModelPart->Name() << std::endl;

        rModelPart.OverwriteSolutionStepData(1, 0);
        rModelPart.GetProcessInfo().SetCurrentTime(NewTime);

    KRATOS_CATCH("error in reducing the time step")
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AddNode(typename ModelPartImpl<TNodeType>::NodeType::Pointer pNewNode, ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->AddNode(pNewNode, ThisIndex);
    }

    GetMesh(ThisIndex).AddNode(pNewNode);
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::NodeType::Pointer ModelPartImpl<TNodeType>::CreateNewNode(int Id, CoordinateType x, CoordinateType y, CoordinateType z, VariablesListType* pNewVariablesList, ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename NodeType::Pointer p_new_node = pParentModelPart->CreateNewNode(Id, x, y, z, pNewVariablesList, ThisIndex);
        GetMesh(ThisIndex).AddNode(p_new_node);

        return p_new_node;
    }

    //create a new node
    typename NodeType::Pointer p_new_node(new NodeType(Id, x, y, z));

    // Giving model part's variables list to the node
    p_new_node->SetSolutionStepVariablesList(pNewVariablesList);

    //set buffer size
    p_new_node->SetBufferSize(mBufferSize);

    //add the new node to the list of nodes
    GetMesh(ThisIndex).AddNode(p_new_node);

    return p_new_node;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::NodeType::Pointer ModelPartImpl<TNodeType>::CreateNewNode(ModelPartImpl<TNodeType>::IndexType Id,
        CoordinateType x, CoordinateType y, CoordinateType z, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename NodeType::Pointer p_new_node = pParentModelPart->CreateNewNode(Id, x, y, z, ThisIndex);
        GetMesh(ThisIndex).AddNode(p_new_node);

        return p_new_node;
    }

    //create a new node
    typename NodeType::Pointer p_new_node(new NodeType(Id, x, y, z));

    // Giving model part's variables list to the node
    p_new_node->SetSolutionStepVariablesList(mpVariablesList);

    //set buffer size
    p_new_node->SetBufferSize(mBufferSize);

    //add the new node to the list of nodes
    GetMesh(ThisIndex).AddNode(p_new_node);

    return p_new_node;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::NodeType::Pointer ModelPartImpl<TNodeType>::CreateNewNode(typename ModelPartImpl<TNodeType>::IndexType Id,
        CoordinateType x, CoordinateType y, CoordinateType z, DataType* pThisData, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename NodeType::Pointer p_new_node = pParentModelPart->CreateNewNode(Id, x, y, z, pThisData, ThisIndex);
        GetMesh(ThisIndex).AddNode(p_new_node);

        return p_new_node;
    }

    //create a new node
    typename NodeType::Pointer p_new_node(new NodeType(Id, x, y, z, mpVariablesList, pThisData, mBufferSize));

    //add the new node to the list of nodes
    GetMesh(ThisIndex).AddNode(p_new_node);

    return p_new_node;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::NodeType::Pointer ModelPartImpl<TNodeType>::CreateNewNode(typename ModelPartImpl<TNodeType>::IndexType NodeId,
        typename  ModelPartImpl<TNodeType>::NodeType const& rSourceNode, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename NodeType::Pointer p_new_node = pParentModelPart->CreateNewNode(NodeId, rSourceNode, ThisIndex);
        GetMesh(ThisIndex).AddNode(p_new_node);

        return p_new_node;
    }

    //create a new node
    typename NodeType::Pointer p_new_node(new NodeType(NodeId, rSourceNode.X(), rSourceNode.Y(), rSourceNode.Z()));

    // Giving model part's variables list to the node
    p_new_node->SetSolutionStepVariablesList(mpVariablesList);

    //set buffer size
    p_new_node->SetBufferSize(mBufferSize);

    //add the new node to the list of nodes
    GetMesh(ThisIndex).AddNode(p_new_node);

    return p_new_node;
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AssignNode(typename ModelPartImpl<TNodeType>::NodeType::Pointer pThisNode,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->AssignNode(pThisNode, ThisIndex);

        //add the new node to the list of nodes
        GetMesh(ThisIndex).AddNode(pThisNode);

        return;
    }

    // Giving model part's variables list to the node
    pThisNode->SetSolutionStepVariablesList(mpVariablesList);

    //set buffer size
    pThisNode->SetBufferSize(mBufferSize);

    //add the new node to the list of nodes
    GetMesh(ThisIndex).AddNode(pThisNode);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveNode(typename ModelPartImpl<TNodeType>::IndexType NodeId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveNode(NodeId);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveNode(NodeId, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveNode(typename ModelPartImpl<TNodeType>::NodeType& ThisNode, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveNode(ThisNode);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveNode(ThisNode, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveNode(typename ModelPartImpl<TNodeType>::NodeType::Pointer pThisNode, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveNode(pThisNode);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveNode(pThisNode, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveNodeFromAllLevels(typename ModelPartImpl<TNodeType>::IndexType NodeId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveNodeFromAllLevels(NodeId, ThisIndex);
        return;
    }
    RemoveNode(NodeId, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveNodeFromAllLevels(typename ModelPartImpl<TNodeType>::NodeType& ThisNode, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveNode(ThisNode, ThisIndex);
        return;
    }
    RemoveNode(ThisNode, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveNodeFromAllLevels(typename ModelPartImpl<TNodeType>::NodeType::Pointer pThisNode, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveNode(pThisNode, ThisIndex);
        return;
    }
    RemoveNode(pThisNode, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::SetNodalSolutionStepVariablesList()
{
    if (IsSubModelPart())
        KRATOS_ERROR << "Calling the SetNodalSolutionStepVariablesList method of the sub model part " << Name()
                     << " please call the one of the parent modelpart : " << mpParentModelPart->Name() << std::endl;

    for (NodeIterator i_node = NodesBegin(); i_node != NodesEnd(); ++i_node)
        i_node->SetSolutionStepVariablesList(mpVariablesList);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AddTable(typename ModelPartImpl<TNodeType>::IndexType TableId, typename ModelPartImpl<TNodeType>::TableType::Pointer pNewTable)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->AddTable(TableId, pNewTable);
    }

    mTables.insert(TableId, pNewTable);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveTable(typename ModelPartImpl<TNodeType>::IndexType TableId)
{
    mTables.erase(TableId);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveTable(TableId);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveTableFromAllLevels(typename ModelPartImpl<TNodeType>::IndexType TableId)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveTableFromAllLevels(TableId);
        return;
    }

    RemoveTable(TableId);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AddProperties(typename ModelPartImpl<TNodeType>::PropertiesType::Pointer pNewProperties,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->AddProperties(pNewProperties);
    }

    GetMesh(ThisIndex).AddProperties(pNewProperties);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveProperties(typename ModelPartImpl<TNodeType>::IndexType PropertiesId,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveProperties(PropertiesId);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveProperties(PropertiesId, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveProperties(typename ModelPartImpl<TNodeType>::PropertiesType& ThisProperties,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveProperties(ThisProperties);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveProperties(ThisProperties, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveProperties(typename ModelPartImpl<TNodeType>::PropertiesType::Pointer pThisProperties,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveProperties(pThisProperties);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveProperties(pThisProperties, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemovePropertiesFromAllLevels(typename ModelPartImpl<TNodeType>::IndexType PropertiesId,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemovePropertiesFromAllLevels(PropertiesId, ThisIndex);
        return;
    }

    RemoveProperties(PropertiesId, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemovePropertiesFromAllLevels(typename ModelPartImpl<TNodeType>::PropertiesType& ThisProperties,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveProperties(ThisProperties, ThisIndex);
    }

    RemoveProperties(ThisProperties, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemovePropertiesFromAllLevels(typename ModelPartImpl<TNodeType>::PropertiesType::Pointer pThisProperties,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveProperties(pThisProperties, ThisIndex);
    }

    RemoveProperties(pThisProperties, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AddElement(typename ModelPartImpl<TNodeType>::ElementType::Pointer pNewElement,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->AddElement(pNewElement, ThisIndex);
    }

    GetMesh(ThisIndex).AddElement(pNewElement);
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::ElementType::Pointer ModelPartImpl<TNodeType>::CreateNewElement(std::string ElementName,
        typename ModelPartImpl<TNodeType>::IndexType Id, const std::vector<typename ModelPartImpl<TNodeType>::IndexType>& ElementNodeIds,
        typename ModelPartImpl<TNodeType>::PropertiesType::Pointer pProperties,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename ElementType::Pointer p_new_element = pParentModelPart->CreateNewElement(ElementName, Id, ElementNodeIds, pProperties, ThisIndex);
        GetMesh(ThisIndex).AddElement(p_new_element);
        return p_new_element;
    }

    typename GeometryType::PointsArrayType pElementNodes;

    for (unsigned int i = 0; i < ElementNodeIds.size(); i++) {
        pElementNodes.push_back(pGetNode(ElementNodeIds[i]));
    }

    return CreateNewElement(ElementName, Id, pElementNodes, pProperties, ThisIndex);
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::ElementType::Pointer ModelPartImpl<TNodeType>::CreateNewElement(std::string ElementName,
        typename ModelPartImpl<TNodeType>::IndexType Id, typename GeometryType::PointsArrayType pElementNodes,
        typename ModelPartImpl<TNodeType>::PropertiesType::Pointer pProperties,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename ElementType::Pointer p_new_element = pParentModelPart->CreateNewElement(ElementName, Id, pElementNodes, pProperties, ThisIndex);
        GetMesh(ThisIndex).AddElement(p_new_element);
        return p_new_element;
    }

    //create the new element
    ElementType const& r_clone_element = KratosComponents<ElementType>::Get(ElementName);
    typename ElementType::Pointer p_element = r_clone_element.Create(Id, pElementNodes, pProperties);

    //add the new element
    GetMesh(ThisIndex).AddElement(p_element);

    return p_element;
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveElement(typename ModelPartImpl<TNodeType>::IndexType ElementId,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveElement(ElementId);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveElement(ElementId, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveElement(typename ModelPartImpl<TNodeType>::ElementType& ThisElement,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveElement(ThisElement);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveElement(ThisElement, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveElement(typename ModelPartImpl<TNodeType>::ElementType::Pointer pThisElement,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveElement(pThisElement);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveElement(pThisElement, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveElementFromAllLevels(typename ModelPartImpl<TNodeType>::IndexType ElementId,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveElement(ElementId, ThisIndex);
        return;
    }

    RemoveElement(ElementId, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveElementFromAllLevels(typename ModelPartImpl<TNodeType>::ElementType& ThisElement,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveElement(ThisElement, ThisIndex);
        return;
    }

    RemoveElement(ThisElement, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveElementFromAllLevels(typename ModelPartImpl<TNodeType>::ElementType::Pointer pThisElement,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveElement(pThisElement, ThisIndex);
        return;
    }

    RemoveElement(pThisElement, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AddMasterSlaveConstraint(typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer pNewMasterSlaveConstraint,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        // First add it to the parent modelpart
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->AddMasterSlaveConstraint(pNewMasterSlaveConstraint, ThisIndex);
        GetMesh(ThisIndex).AddMasterSlaveConstraint(pNewMasterSlaveConstraint);
    }
    else
    {
        auto existing_constraint_it = GetMesh(ThisIndex).MasterSlaveConstraints().find(pNewMasterSlaveConstraint->Id());
        if( existing_constraint_it == GetMesh(ThisIndex).MasterSlaveConstraintsEnd()) //master-slave constraint did not exist
        {
            GetMesh(ThisIndex).AddMasterSlaveConstraint(pNewMasterSlaveConstraint);
        }
        else //master-slave constraint did exist already
        {
            if(&(*existing_constraint_it) != (pNewMasterSlaveConstraint.get()))
                KRATOS_ERROR << "attempting to add Master-Slave constraint with Id :xxx , unfortunately a (different) condition with the same Id = " << pNewMasterSlaveConstraint->Id() << " already exists";
        }
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AddMasterSlaveConstraints(std::vector<typename ModelPartImpl<TNodeType>::IndexType> const& MasterSlaveConstraintIds,
        typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    KRATOS_TRY

    if(IsSubModelPart()) //does nothing if we are on the top model part
    {
        //obtain from the root model part the corresponding list of constraints
        ModelPartImpl<TNodeType>* root_model_part = dynamic_cast<ModelPartImpl<TNodeType>*>(&this->GetRootModelPart());
        KRATOS_ERROR_IF(root_model_part == nullptr) << "The root ModelPart is not the same type as the current ModelPart" << std::endl;
        ModelPartImpl<TNodeType>::MasterSlaveConstraintContainerType  aux;
        aux.reserve(MasterSlaveConstraintIds.size());
        for(unsigned int i=0; i<MasterSlaveConstraintIds.size(); i++)
        {
            auto it = root_model_part->MasterSlaveConstraints().find(MasterSlaveConstraintIds[i]);
            if(it != root_model_part->MasterSlaveConstraintsEnd())
                aux.push_back(*(it.base()));
            else
                KRATOS_ERROR << "the master-slave constraint with Id " << MasterSlaveConstraintIds[i] << " does not exist in the root model part";
        }

        ModelPartImpl<TNodeType>* current_part = this;
        while(current_part->IsSubModelPart())
        {
            for(auto it = aux.begin(); it!=aux.end(); it++)
                current_part->MasterSlaveConstraints().push_back( *(it.base()) );

            current_part->MasterSlaveConstraints().Unique();

            current_part = dynamic_cast<ModelPartImpl<TNodeType>*>(current_part->GetParentModelPart());
        }
    }

    KRATOS_CATCH("");
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer ModelPartImpl<TNodeType>::CreateNewMasterSlaveConstraint(const std::string& ConstraintName,
    const typename ModelPartImpl<TNodeType>::IndexType& Id, typename ModelPartImpl<TNodeType>::DofsVectorType& rMasterDofsVector, typename ModelPartImpl<TNodeType>::DofsVectorType& rSlaveDofsVector,
    const typename ModelPartImpl<TNodeType>::MatrixType& RelationMatrix, const typename ModelPartImpl<TNodeType>::VectorType& ConstantVector,
    const typename ModelPartImpl<TNodeType>::IndexType& ThisIndex)
{
    KRATOS_TRY

    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer p_new_constraint = pParentModelPart->CreateNewMasterSlaveConstraint(ConstraintName,
            Id, rMasterDofsVector, rSlaveDofsVector, RelationMatrix, ConstantVector, ThisIndex);
        GetMesh(ThisIndex).AddMasterSlaveConstraint(p_new_constraint);
        GetMesh(ThisIndex).MasterSlaveConstraints().Unique();

        return p_new_constraint;
    }

    auto existing_constraint_iterator = GetMesh(ThisIndex).MasterSlaveConstraints().find(Id);

    if(existing_constraint_iterator != GetMesh(ThisIndex).MasterSlaveConstraintsEnd() )
        KRATOS_ERROR << "trying to construct an master-slave constraint with ID " << Id << ", however a constraint with the same Id already exists";

    //create the new element
    ModelPartImpl<TNodeType>::MasterSlaveConstraintType const& r_clone_constraint = KratosComponents<MasterSlaveConstraintType>::Get(ConstraintName);
    typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer p_new_constraint = r_clone_constraint.Create(Id, rMasterDofsVector,
        rSlaveDofsVector, RelationMatrix, ConstantVector);

    GetMesh(ThisIndex).AddMasterSlaveConstraint(p_new_constraint);
    GetMesh(ThisIndex).MasterSlaveConstraints().Unique();

    return p_new_constraint;

    KRATOS_CATCH("")
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer ModelPartImpl<TNodeType>::CreateNewMasterSlaveConstraint(const std::string& ConstraintName,
    const ModelPartImpl<TNodeType>::IndexType& Id, typename ModelPartImpl<TNodeType>::NodeType& rMasterNode, const typename ModelPartImpl<TNodeType>::DoubleVariableType& rMasterVariable,
    typename ModelPartImpl<TNodeType>::NodeType& rSlaveNode, const typename ModelPartImpl<TNodeType>::DoubleVariableType& rSlaveVariable,
    const typename ModelPartImpl<TNodeType>::DataType& Weight, const typename ModelPartImpl<TNodeType>::DataType& Constant,
    const typename ModelPartImpl<TNodeType>::IndexType& ThisIndex)
{
    KRATOS_TRY

    if (rMasterNode.HasDofFor(rMasterVariable) && rSlaveNode.HasDofFor(rSlaveVariable) )
    {
        if (IsSubModelPart())
        {
            ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
            KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
            typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer p_new_constraint = pParentModelPart->CreateNewMasterSlaveConstraint(ConstraintName,
                Id, rMasterNode, rMasterVariable, rSlaveNode, rSlaveVariable, Weight, Constant, ThisIndex);

            GetMesh(ThisIndex).AddMasterSlaveConstraint(p_new_constraint);
            GetMesh(ThisIndex).MasterSlaveConstraints().Unique();
            return p_new_constraint;
        }

        if(GetMesh(ThisIndex).HasMasterSlaveConstraint(Id))
            KRATOS_ERROR << "trying to construct an master-slave constraint with ID " << Id << ", however a constraint with the same Id already exists";

            //create the new element
        ModelPartImpl<TNodeType>::MasterSlaveConstraintType const& r_clone_constraint = KratosComponents<MasterSlaveConstraintType>::Get(ConstraintName);
        typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer p_new_constraint = r_clone_constraint.Create(Id, rMasterNode,
            rMasterVariable, rSlaveNode, rSlaveVariable, Weight, Constant);

        GetMesh(ThisIndex).AddMasterSlaveConstraint(p_new_constraint);
        GetMesh(ThisIndex).MasterSlaveConstraints().Unique();

        return p_new_constraint;
    }
    else
    {
        KRATOS_ERROR << "Master or Slave node does not have requested DOF";
    }

    KRATOS_CATCH("")
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer ModelPartImpl<TNodeType>::CreateNewMasterSlaveConstraint(const std::string& ConstraintName,
    const typename ModelPartImpl<TNodeType>::IndexType& Id, typename ModelPartImpl<TNodeType>::NodeType& rMasterNode, const typename ModelPartImpl<TNodeType>::VariableComponentType& rMasterVariable,
    typename ModelPartImpl<TNodeType>::NodeType& rSlaveNode, const typename ModelPartImpl<TNodeType>::VariableComponentType& rSlaveVariable,
    const typename ModelPartImpl<TNodeType>::DataType& Weight, const typename ModelPartImpl<TNodeType>::DataType& Constant,
    const typename ModelPartImpl<TNodeType>::IndexType& ThisIndex)
{
    KRATOS_TRY

    if (rMasterNode.HasDofFor(rMasterVariable) && rSlaveNode.HasDofFor(rSlaveVariable) )
    {
        if (IsSubModelPart())
        {
            ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
            KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
            typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer p_new_constraint = pParentModelPart->CreateNewMasterSlaveConstraint(ConstraintName,
                Id, rMasterNode, rMasterVariable, rSlaveNode, rSlaveVariable, Weight, Constant, ThisIndex);

            GetMesh(ThisIndex).AddMasterSlaveConstraint(p_new_constraint);
            GetMesh(ThisIndex).MasterSlaveConstraints().Unique();
            return p_new_constraint;
        }

        auto existing_constraint_iterator = GetMesh(ThisIndex).MasterSlaveConstraints().find(Id);
        if(existing_constraint_iterator != GetMesh(ThisIndex).MasterSlaveConstraintsEnd() )
            KRATOS_ERROR << "trying to construct an master-slave constraint with ID " << Id << ", however a constraint with the same Id already exists";

        //create the new element
        ModelPartImpl<TNodeType>::MasterSlaveConstraintType const& r_clone_constraint = KratosComponents<MasterSlaveConstraintType>::Get(ConstraintName);
        typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer p_new_constraint = r_clone_constraint.Create(Id, rMasterNode,
            rMasterVariable, rSlaveNode, rSlaveVariable, Weight, Constant);

        GetMesh(ThisIndex).AddMasterSlaveConstraint(p_new_constraint);
        GetMesh(ThisIndex).MasterSlaveConstraints().Unique();

        return p_new_constraint;
    }
    else
    {
        KRATOS_ERROR << "Master or Slave node does not have requested DOF";
    }

    KRATOS_CATCH("")
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer ModelPartImpl<TNodeType>::CreateNewMasterSlaveConstraintNoUnique(const std::string& ConstraintName,
    const typename ModelPartImpl<TNodeType>::IndexType& Id, typename ModelPartImpl<TNodeType>::DofsVectorType& rMasterDofsVector, typename ModelPartImpl<TNodeType>::DofsVectorType& rSlaveDofsVector,
    const typename ModelPartImpl<TNodeType>::MatrixType& RelationMatrix, const typename ModelPartImpl<TNodeType>::VectorType& ConstantVector,
    const typename ModelPartImpl<TNodeType>::IndexType& ThisIndex)
{
    KRATOS_TRY

    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer p_new_constraint = pParentModelPart->CreateNewMasterSlaveConstraint(ConstraintName,
            Id, rMasterDofsVector, rSlaveDofsVector, RelationMatrix, ConstantVector, ThisIndex);
        GetMesh(ThisIndex).AddMasterSlaveConstraint(p_new_constraint);

        return p_new_constraint;
    }

    auto existing_constraint_iterator = GetMesh(ThisIndex).MasterSlaveConstraints().find(Id);

    if(existing_constraint_iterator != GetMesh(ThisIndex).MasterSlaveConstraintsEnd() )
        KRATOS_ERROR << "trying to construct an master-slave constraint with ID " << Id << ", however a constraint with the same Id already exists";

    //create the new element
    ModelPartImpl<TNodeType>::MasterSlaveConstraintType const& r_clone_constraint = KratosComponents<MasterSlaveConstraintType>::Get(ConstraintName);
    typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer p_new_constraint = r_clone_constraint.Create(Id, rMasterDofsVector,
        rSlaveDofsVector, RelationMatrix, ConstantVector);

    GetMesh(ThisIndex).AddMasterSlaveConstraint(p_new_constraint);

    return p_new_constraint;

    KRATOS_CATCH("")
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveMasterSlaveConstraint(typename ModelPartImpl<TNodeType>::IndexType MasterSlaveConstraintId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveMasterSlaveConstraint(MasterSlaveConstraintId);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveMasterSlaveConstraint(MasterSlaveConstraintId, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveMasterSlaveConstraint(typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType& ThisMasterSlaveConstraint, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveMasterSlaveConstraint(ThisMasterSlaveConstraint);
    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveMasterSlaveConstraint(ThisMasterSlaveConstraint, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveMasterSlaveConstraintFromAllLevels(typename ModelPartImpl<TNodeType>::IndexType MasterSlaveConstraintId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveMasterSlaveConstraintFromAllLevels(MasterSlaveConstraintId, ThisIndex);
    }

    RemoveMasterSlaveConstraint(MasterSlaveConstraintId, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveMasterSlaveConstraintFromAllLevels(typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType& ThisMasterSlaveConstraint, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveMasterSlaveConstraintFromAllLevels(ThisMasterSlaveConstraint, ThisIndex);
    }

    RemoveMasterSlaveConstraint(ThisMasterSlaveConstraint, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveMasterSlaveConstraints(Flags IdentifierFlag)
{
    // This method is optimized to free the memory loop over all the meshes
    auto& meshes = this->GetMeshes();
    for(auto it_mesh = meshes.begin() ; it_mesh != meshes.end() ; it_mesh++) {
        // Count the constraints to be erase
        const SizeType nconstraints = it_mesh->MasterSlaveConstraints().size();
        SizeType erase_count = 0;
        #pragma omp parallel for reduction(+:erase_count)
        for(int i=0; i<static_cast<int>(nconstraints); ++i) {
            auto it_const = it_mesh->MasterSlaveConstraintsBegin() + i;

            if( it_const->IsNot(IdentifierFlag) )
                erase_count++;
        }

        ModelPartImpl<TNodeType>::MasterSlaveConstraintContainerType temp_constraints_container;
        temp_constraints_container.reserve(it_mesh->MasterSlaveConstraints().size() - erase_count);

        temp_constraints_container.swap(it_mesh->MasterSlaveConstraints());

        for(auto it_const = temp_constraints_container.begin() ; it_const != temp_constraints_container.end(); it_const++) {
            if( it_const->IsNot(IdentifierFlag) )
                (it_mesh->MasterSlaveConstraints()).push_back(std::move(*(it_const.base())));
        }
    }

    // Now recursively remove the constraints in the submodelparts
    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveMasterSlaveConstraints(IdentifierFlag);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveMasterSlaveConstraintsFromAllLevels(Flags IdentifierFlag)
{
    ModelPartImpl<TNodeType>* root_model_part = dynamic_cast<ModelPartImpl<TNodeType>*>(&this->GetRootModelPart());
    KRATOS_ERROR_IF(root_model_part == nullptr) << "The root ModelPart is not the same type as the current ModelPart" << std::endl;
    root_model_part->RemoveMasterSlaveConstraints(IdentifierFlag);
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType::Pointer ModelPartImpl<TNodeType>::pGetMasterSlaveConstraint(typename ModelPartImpl<TNodeType>::IndexType MasterSlaveConstraintId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    return GetMesh(ThisIndex).pGetMasterSlaveConstraint(MasterSlaveConstraintId);
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType& ModelPartImpl<TNodeType>::GetMasterSlaveConstraint(typename ModelPartImpl<TNodeType>::IndexType MasterSlaveConstraintId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    return GetMesh(ThisIndex).GetMasterSlaveConstraint(MasterSlaveConstraintId);
}

template<class TNodeType>
const typename ModelPartImpl<TNodeType>::MasterSlaveConstraintType& ModelPartImpl<TNodeType>::GetMasterSlaveConstraint(typename ModelPartImpl<TNodeType>::IndexType MasterSlaveConstraintId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex) const
{
    return GetMesh(ThisIndex).GetMasterSlaveConstraint(MasterSlaveConstraintId);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AddCondition(typename ModelPartImpl<TNodeType>::ConditionType::Pointer pNewCondition, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->AddCondition(pNewCondition, ThisIndex);
    }

    GetMesh(ThisIndex).AddCondition(pNewCondition);
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::ConditionType::Pointer ModelPartImpl<TNodeType>::CreateNewCondition(std::string ConditionName,
    typename ModelPartImpl<TNodeType>::IndexType Id, const std::vector<typename ModelPartImpl<TNodeType>::IndexType>& ConditionNodeIds,
    typename ModelPartImpl<TNodeType>::PropertiesType::Pointer pProperties, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    typename GeometryType::PointsArrayType pConditionNodes;

    for (unsigned int i = 0; i < ConditionNodeIds.size(); i++) {
        pConditionNodes.push_back(pGetNode(ConditionNodeIds[i]));
    }

    return CreateNewCondition(ConditionName, Id, pConditionNodes, pProperties, ThisIndex);
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::ConditionType::Pointer ModelPartImpl<TNodeType>::CreateNewCondition(std::string ConditionName,
    typename ModelPartImpl<TNodeType>::IndexType Id, typename GeometryType::PointsArrayType pConditionNodes,
    typename ModelPartImpl<TNodeType>::PropertiesType::Pointer pProperties, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        typename ConditionType::Pointer p_new_condition = pParentModelPart->CreateNewCondition(ConditionName, Id, pConditionNodes, pProperties, ThisIndex);
        GetMesh(ThisIndex).AddCondition(p_new_condition);
        return p_new_condition;
    }

    //get the condition
    ConditionType const& r_clone_condition = KratosComponents<ConditionType>::Get(ConditionName);
    typename ConditionType::Pointer p_condition = r_clone_condition.Create(Id, pConditionNodes, pProperties);

    //add the new condition
    GetMesh(ThisIndex).AddCondition(p_condition);

    return p_condition;
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveCondition(typename ModelPartImpl<TNodeType>::IndexType ConditionId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveCondition(ConditionId);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveCondition(ConditionId, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveCondition(typename ModelPartImpl<TNodeType>::ConditionType& ThisCondition, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveCondition(ThisCondition);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveCondition(ThisCondition, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveCondition(typename ModelPartImpl<TNodeType>::ConditionType::Pointer pThisCondition, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    GetMesh(ThisIndex).RemoveCondition(pThisCondition);

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->RemoveCondition(pThisCondition, ThisIndex);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveConditionFromAllLevels(typename ModelPartImpl<TNodeType>::IndexType ConditionId, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveCondition(ConditionId, ThisIndex);
        return;
    }

    RemoveCondition(ConditionId, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveConditionFromAllLevels(typename ModelPartImpl<TNodeType>::ConditionType& ThisCondition, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveCondition(ThisCondition, ThisIndex);
        return;
    }

    RemoveCondition(ThisCondition, ThisIndex);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::RemoveConditionFromAllLevels(typename ModelPartImpl<TNodeType>::ConditionType::Pointer pThisCondition, typename ModelPartImpl<TNodeType>::IndexType ThisIndex)
{
    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->RemoveCondition(pThisCondition, ThisIndex);
        return;
    }

    RemoveCondition(pThisCondition, ThisIndex);
}

template<class TNodeType>
BaseModelPart& ModelPartImpl<TNodeType>::CreateSubModelPart(std::string const& NewSubModelPartName)
{
    if (mSubModelParts.find(NewSubModelPartName) == mSubModelParts.end())
    {
        ModelPartImpl<TNodeType>* p_model_part = new ModelPartImpl<TNodeType>(NewSubModelPartName);
        p_model_part->SetParentModelPart(this);
        delete p_model_part->mpVariablesList;
        p_model_part->mpVariablesList = mpVariablesList;
        p_model_part->mBufferSize = this->mBufferSize;
        p_model_part->mpProcessInfo = this->mpProcessInfo;
        auto it = mSubModelParts.insert(static_cast<BaseModelPart*>(p_model_part));
        return *it;
    }
    else
        // Here a warning would be enough. To be disscussed. Pooyan.
        KRATOS_ERROR << "There is an already existing sub model part with name \"" << NewSubModelPartName << "\" in model part: \"" << Name() << "\"" << std::endl;
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::AddSubModelPart(BaseModelPart& rThisSubModelPart)
{
    if (mSubModelParts.find(rThisSubModelPart.Name()) != mSubModelParts.end())
        // Here a warning would be enough. To be disscussed. Pooyan.
        KRATOS_ERROR << "There is an already existing sub model part with name " << rThisSubModelPart.Name();

    if (IsSubModelPart())
    {
        ModelPartImpl<TNodeType>* pParentModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(mpParentModelPart);
        KRATOS_ERROR_IF(pParentModelPart == nullptr) << "The parent ModelPart is not the same type as the current ModelPart" << std::endl;
        // make a check if the adding sub ModelPart is the same type
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&rThisSubModelPart);
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The adding ModelPart is not the same type as the current ModelPart" << std::endl;
        pParentModelPart->AddSubModelPart(rThisSubModelPart);
        return;
    }

    BaseModelPart::AddSubModelPart(rThisSubModelPart);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::SetBufferSize(typename ModelPartImpl<TNodeType>::IndexType NewBufferSize)
{
    if (IsSubModelPart())
        KRATOS_ERROR << "Calling the SetBufferSize method of the sub model part " << Name()
                     << " please call the one of the parent modelpart : " << mpParentModelPart->Name() << std::endl;

    for (SubModelPartIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        ModelPartImpl<TNodeType>* pThisSubModelPart = dynamic_cast<ModelPartImpl<TNodeType>*>(&(*i_sub_model_part));
        KRATOS_ERROR_IF(pThisSubModelPart == nullptr) << "The sub ModelPart is not the same type as the current ModelPart" << std::endl;
        pThisSubModelPart->SetBufferSize(NewBufferSize);
    }

    mBufferSize = NewBufferSize;

    for (NodeIterator node_iterator = NodesBegin(); node_iterator != NodesEnd(); node_iterator++)
        node_iterator->SetBufferSize(mBufferSize);

    auto* pProcessInfoWithDofs = dynamic_cast<ProcessInfoWithDofs<DofType>*>(mpProcessInfo.get());
    if (pProcessInfoWithDofs != nullptr)
    {
        pProcessInfoWithDofs->SetBufferSize(mBufferSize);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::SetProcessInfo(ProcessInfo::Pointer pNewProcessInfo)
{
    mpProcessInfo = pNewProcessInfo;
    auto* pProcessInfoWithDofs = dynamic_cast<ProcessInfoWithDofs<DofType>*>(mpProcessInfo.get());
    if (pProcessInfoWithDofs != nullptr)
    {
        pProcessInfoWithDofs->SetSolutionStepVariablesList(*mpVariablesList);
        pProcessInfoWithDofs->SetBufferSize(mBufferSize);
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::SetProcessInfo(ProcessInfo& NewProcessInfo)
{
    *mpProcessInfo = NewProcessInfo;
    auto* pProcessInfoWithDofs = dynamic_cast<ProcessInfoWithDofs<DofType>*>(mpProcessInfo.get());
    if (pProcessInfoWithDofs != nullptr)
    {
        pProcessInfoWithDofs->SetSolutionStepVariablesList(*mpVariablesList);
        pProcessInfoWithDofs->SetBufferSize(mBufferSize);
    }
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::GetLastNodeId() const
{
    IndexType lastNodeId = 0;
    for(typename NodesContainerType::const_iterator it = this->Nodes().begin();
            it != this->Nodes().end(); ++it)
    {
        if(it->Id() > lastNodeId)
            lastNodeId = it->Id();
    }

    this->GetCommunicator().MaxAll(lastNodeId);

    return lastNodeId;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::GetLastElementId() const
{
    IndexType lastElementId = 0;
    for(typename ElementsContainerType::const_iterator it = this->Elements().begin();
            it != this->Elements().end(); ++it)
    {
        if(it->Id() > lastElementId)
            lastElementId = it->Id();
    }

    this->GetCommunicator().MaxAll(lastElementId);

    return lastElementId;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::GetLastConditionId() const
{
    IndexType lastCondId = 0;
    for(typename ConditionsContainerType::const_iterator it = this->Conditions().begin();
            it != this->Conditions().end(); ++it)
    {
        if(it->Id() > lastCondId)
            lastCondId = it->Id();
    }

    this->GetCommunicator().MaxAll(lastCondId);

    return lastCondId;
}

template<class TNodeType>
typename ModelPartImpl<TNodeType>::IndexType ModelPartImpl<TNodeType>::GetLastConstraintId() const
{
    IndexType lastConstraintId = 0;
    for(typename ModelPartImpl<TNodeType>::MasterSlaveConstraintContainerType::const_iterator it = this->MasterSlaveConstraints().begin();
            it != this->MasterSlaveConstraints().end(); ++it)
    {
        if(it->Id() > lastConstraintId)
            lastConstraintId = it->Id();
    }

    this->GetCommunicator().MaxAll(lastConstraintId);

    return lastConstraintId;
}

template<class TNodeType>
int ModelPartImpl<TNodeType>::Check(ProcessInfo& rCurrentProcessInfo) const
{
    KRATOS_TRY

    int err = 0;

    Kratos::progress_display show_progress_elements( NumberOfElements() );
    std::cout << "Checking elements:" << std::endl;
    for (ElementConstantIterator elem_iterator = ElementsBegin(); elem_iterator != ElementsEnd(); ++elem_iterator)
    {
        err = elem_iterator->Check(rCurrentProcessInfo);
        ++show_progress_elements;
    }

    Kratos::progress_display show_progress_conditions( NumberOfConditions() );
    std::cout << "Checking conditions:" << std::endl;
    for (ConditionConstantIterator condition_iterator = ConditionsBegin(); condition_iterator != ConditionsEnd(); ++condition_iterator)
    {
        err = condition_iterator->Check(rCurrentProcessInfo);
        ++show_progress_conditions;
    }

    Kratos::progress_display show_progress_constraints( NumberOfMasterSlaveConstraints() );
    std::cout << "Checking constraints:" << std::endl;
    for (MasterSlaveConstraintConstantIteratorType constraint_iterator = MasterSlaveConstraintsBegin();
            constraint_iterator != MasterSlaveConstraintsEnd(); ++constraint_iterator)
    {
        err = constraint_iterator->Check(rCurrentProcessInfo);
        ++show_progress_constraints;
    }

    return err;

    KRATOS_CATCH("");
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::PrintInfo(std::ostream& rOStream) const
{
    rOStream << Info() << ", Dof = " << DataTypeToString<DataType>::Get();
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::PrintData(std::ostream& rOStream) const
{
    if (!IsSubModelPart())
        rOStream  << "    Buffer Size : " << mBufferSize << std::endl;
    rOStream << "    Number of tables : " << NumberOfTables() << std::endl;
    rOStream << "    Number of sub model parts : " << NumberOfSubModelParts() << std::endl;
    if (!IsSubModelPart())
        mpProcessInfo->PrintData(rOStream);
    rOStream << std::endl;
    for (IndexType i = 0; i < mMeshes.size(); i++)
    {
        rOStream << "    Mesh " << i << " : " << std::endl;
        GetMesh(i).PrintData(rOStream, "    ");
    }

    for (SubModelPartConstantIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        i_sub_model_part->PrintInfo(rOStream, "    ");
        rOStream << std::endl;
        i_sub_model_part->PrintData(rOStream, "    ");
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::PrintInfo(std::ostream& rOStream, std::string const& PrefixString) const
{
    rOStream << PrefixString << Info() << ", Dof = " << DataTypeToString<DataType>::Get();
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::PrintData(std::ostream& rOStream, std::string const& PrefixString) const
{
    if (!IsSubModelPart())
        rOStream << PrefixString << "    Buffer Size : " << mBufferSize << std::endl;
    rOStream << PrefixString << "    Number of tables : " << NumberOfTables() << std::endl;
    rOStream << PrefixString << "    Number of sub model parts : " << NumberOfSubModelParts() << std::endl;
    if (!IsSubModelPart())
        mpProcessInfo->PrintData(rOStream);
    rOStream << std::endl;
    for (IndexType i = 0; i < mMeshes.size(); i++)
    {
        rOStream << PrefixString << "    Mesh " << i << " : " << std::endl;
        GetMesh(i).PrintData(rOStream, PrefixString + "    ");
    }

    for (SubModelPartConstantIterator i_sub_model_part = SubModelPartsBegin(); i_sub_model_part != SubModelPartsEnd(); i_sub_model_part++)
    {
        i_sub_model_part->PrintInfo(rOStream, PrefixString + "    ");
        rOStream << std::endl;
        i_sub_model_part->PrintData(rOStream, PrefixString + "    ");
    }
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::save(Serializer& rSerializer) const
{
    KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, BaseModelPart);
    rSerializer.save("Buffer Size", mBufferSize);
    rSerializer.save("ProcessInfo", mpProcessInfo);
    //const VariablesListType* p_list = &mVariablesList;
    // I'm saving it as pointer so the nodes pointers will point to it as stored pointer. Pooyan.
    rSerializer.save("Variables List", mpVariablesList);
    rSerializer.save("Meshes", mMeshes);
}

template<class TNodeType>
void ModelPartImpl<TNodeType>::load(Serializer& rSerializer)
{
    KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, BaseModelPart);
    rSerializer.load("Buffer Size", mBufferSize);
    rSerializer.load("ProcessInfo", mpProcessInfo);
    //VariablesListType* p_list = &mVariablesList;
    rSerializer.load("Variables List", mpVariablesList);
    rSerializer.load("Meshes", mMeshes);
}

/// template class instantiation
template class ModelPartImpl<RealNode>;
template class ModelPartImpl<ComplexNode>;
template class ModelPartImpl<GComplexNode>;

}  // namespace Kratos.