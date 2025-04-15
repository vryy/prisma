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
//
//

#if !defined(KRATOS_MODEL_PART_H_INCLUDED )
#define  KRATOS_MODEL_PART_H_INCLUDED

// System includes
#include <string>
#include <iostream>
#include <cstddef>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/serializer.h"
#include "includes/process_info.h"
#include "containers/data_value_container.h"
#include "includes/mesh.h"
#include "includes/element.h"
#include "includes/condition.h"
#include "includes/communicator.h"
#include "includes/table.h"
#include "containers/pointer_vector_map.h"
#include "containers/pointer_hash_map_set.h"
// #include "utilities/logger.h"
#include "includes/master_slave_constraint.h"

namespace Kratos
{

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}
///@name Kratos Classes
///@{

//forward declaring Model to be avoid cross references
class Model;

/**
* @class BaseModelPart
* @ingroup KratosCore
* @brief This class aims to manage meshes for multi-physics simulations
* @author Pooyan Dadvand
* @author Riccardo Rossi
*/
class BaseModelPart : public DataValueContainer, public Flags
{
protected:
    class GetModelPartName
    {
    public:

        using argument_type = const BaseModelPart* const;
        using result_type = std::string;

        std::string const& operator()(const BaseModelPart& rModelPart) const
        {
            return rModelPart.Name();
        }
    };

public:
    ///@name  Enum's
    ///@{

    enum OwnershipType
    {
        Kratos_All,
        Kratos_Local,
        Kratos_Ghost,
        Kratos_Ownership_Size
    };

    ///@}
    ///@name Flags
    ///@{

    KRATOS_DEFINE_LOCAL_FLAG(ALL_ENTITIES);
    KRATOS_DEFINE_LOCAL_FLAG(OVERWRITE_ENTITIES);

    ///@}

    ///@name Type Definitions
    ///@{

    /// The container of the sub model parts. A hash table is used.
    /**
    */
    typedef PointerHashMapSet<BaseModelPart, std::hash<std::string>, GetModelPartName, BaseModelPart*>  SubModelPartsContainerType;

    /// Iterator over the sub model parts of this model part.
    /** Note that this iterator only iterates over the next level of
        sub model parts and does not go through the hierarchy of the
        sub model parts
    */
    typedef typename SubModelPartsContainerType::iterator SubModelPartIterator;

    /// Constant iterator over the sub model parts of this model part.
    /** Note that this iterator only iterates over the next level of
        sub model parts and does not go through the hierarchy of the
        sub model parts
    */
    typedef typename SubModelPartsContainerType::const_iterator SubModelPartConstantIterator;

    ///@}

    /// Default constructor.
    BaseModelPart();

    /// Constructor with name
    BaseModelPart(std::string const& NewName);

    /// Copy constructor.
    BaseModelPart(BaseModelPart const& rOther);

    ///@name Operators
    ///@{

    /// Assignment operator.
    BaseModelPart & operator=(BaseModelPart const& rOther);

    ///@}

    ///@name Operations
    ///@{

    //this function returns the "Owner" Model
    Model& GetModel();
    const Model& GetModel() const;

    std::string& Name()
    {
        return mName;
    }

    std::string const& Name() const
    {
        return mName;
    }

    BaseModelPart* GetParentModelPart() const
    {
        return mpParentModelPart;
    }

    /** this function gives back the "root" model part, that is the model_part that has no father (non-const version)*/
    BaseModelPart& GetRootModelPart();

    /** this function gives back the "root" model part, that is the model_part that has no father (const version)*/
    const BaseModelPart& GetRootModelPart() const;

    /**
     * @brief This method returns the full name of the model part (including the parents model parts)
     * @details This is evaluated in a recursive way
     * @return The full name of the model part
     */
    std::string FullName() const
    {
        std::string full_name = this->Name();
        if (this->IsSubModelPart()) {
            full_name = this->GetParentModelPart()->FullName() + "." + full_name;
        }
        return full_name;
    }

    ///@}

    ///@name Sub model parts
    ///@{

    SizeType NumberOfSubModelParts() const
    {
        return mSubModelParts.size();
    }

    /** Creates a new sub model part with given name.
    Does nothing if a sub model part with the same name exist.
    */
    virtual BaseModelPart& CreateSubModelPart(std::string const& NewSubModelPartName);

    /** Add an existing model part as a sub model part.
        All the meshes will be added to the parents.
        NOTE: The added sub model part should not have
        mesh entities with id in conflict with other ones in the parent
        In the case of conflict the new one would replace the old one
        resulting inconsitency in parent.
    */
    virtual void AddSubModelPart(BaseModelPart& rThisSubModelPart);

    /** Returns a reference to the sub_model part with given string name
        In debug gives an error if does not exist.
    */
    virtual BaseModelPart& GetSubModelPart(std::string const& SubModelPartName)
    {
        SubModelPartIterator i = mSubModelParts.find(SubModelPartName);
        if(i == mSubModelParts.end())
            KRATOS_ERROR << "There is no sub model part with name " << SubModelPartName;
          //TODO: KRATOS_ERROR << "There is no sub model part with name : \"" << SubModelPartName << "\" in this model part"; // << std::endl;

        return *i;
    }

    /** Remove a sub modelpart with given name.
    */
    void RemoveSubModelPart(std::string const& ThisSubModelPartName);

    /** Remove given sub model part.
    */
    void RemoveSubModelPart(BaseModelPart& ThisSubModelPart);

    SubModelPartIterator SubModelPartsBegin()
    {
        return mSubModelParts.begin();
    }

    SubModelPartConstantIterator SubModelPartsBegin() const
    {
        return mSubModelParts.begin();
    }

    SubModelPartIterator SubModelPartsEnd()
    {
        return mSubModelParts.end();
    }

    SubModelPartConstantIterator SubModelPartsEnd() const
    {
        return mSubModelParts.end();
    }

    SubModelPartsContainerType& SubModelParts()
    {
        return mSubModelParts;
    }

    bool HasSubModelPart(std::string const& ThisSubModelPartName)
    {
        return (mSubModelParts.find(ThisSubModelPartName) != mSubModelParts.end());
    }

    ///@}

    ///@name Inquiry
    ///@{

    bool IsSubModelPart() const
    {
        return (mpParentModelPart != NULL);
    }

    /**
     * @brief This method returns the name list of submodelparts
     * @return A vector conrtaining the list of submodelparts contained
     */
    std::vector<std::string> GetSubModelPartNames();

    ///@}

    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    std::string Info() const override;

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override;

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const override;

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream, std::string const& PrefixString) const;

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream, std::string const& PrefixString) const;

    ///@}

protected:

    BaseModelPart* mpParentModelPart = nullptr; /// The parent model part of the current model part

    SubModelPartsContainerType mSubModelParts; /// The container of the submodelparts, mSubModelParts()

    friend class Model;

    /// Constructor with name and owner model
    BaseModelPart(std::string const& NewName, Model& rOwnerModel);

    ///@name Serialization
    ///@{

    friend class Serializer;

    void save(Serializer& rSerializer) const override;

    void load(Serializer& rSerializer) override;

    ///@}

    ///@name Protected Operations
    ///@{

    void SetParentModelPart(BaseModelPart* pParentModelPart)
    {
        mpParentModelPart = pParentModelPart;
    }

    ///@}

private:

    std::string mName; /// The name of the model part

    Model* mpModel; /// The model which contains this model part
};

/**
* @class ModelPartImpl
* @ingroup KratosCore
* @brief Concrete implementation of ModelPart for different nodal dof type, including complex
* @author Pooyan Dadvand
* @author Riccardo Rossi
*/
template<class TNodeType>
class ModelPartImpl : public BaseModelPart
{
public:
    ///@name  Enum's
    ///@{

    ///@}
    ///@name Type Definitions
    ///@{

    /// Pointer definition of ModelPartImpl
    KRATOS_CLASS_POINTER_DEFINITION(ModelPartImpl);

    typedef TNodeType NodeType;
    typedef Properties PropertiesType;
    typedef BaseElement<NodeType> ElementType;
    typedef BaseCondition<NodeType> ConditionType;

    typedef typename ElementType::GeometryType GeometryType;

    typedef typename NodeType::DofType DofType;
    typedef std::vector< typename DofType::Pointer > DofsVectorType;
    typedef PointerVectorSet<DofType, SetIdentityFunction<DofType> > DofsArrayType;

    typedef typename NodeType::VariablesListType VariablesListType;

    typedef Mesh<NodeType, PropertiesType, ElementType, ConditionType> MeshType;

    typedef typename DofType::DataType DataType;
    // the DataType is value kept at a Dof. It can be std::complex or a primitive type

    typedef typename DataTypeToValueType<DataType>::value_type ValueType;
    // the ValueType is always a real type. It is used to store time, table first entry, ...

    typedef typename NodeType::CoordinateType CoordinateType;
    // the CoordinateType is the value of the nodal coordinates. It can be std::complex.

    typedef typename MeshType::IndexType IndexType;

    typedef typename MeshType::SizeType SizeType;

    typedef PointerVector<MeshType> MeshesContainerType;

    typedef Variable<DataType> DoubleVariableType;
    typedef VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3>>> VariableComponentType;
    typedef typename MatrixVectorTypeSelector<DataType>::MatrixType MatrixType;
    typedef typename MatrixVectorTypeSelector<DataType>::VectorType VectorType;

    /// Nodes container. Which is a vector set of nodes with their Id's as key.
    typedef typename MeshType::NodesContainerType NodesContainerType;

    /** Iterator over the nodes. This iterator is an indirect
        iterator over Node::Pointer which turn back a reference to
        node by * operator and not a pointer for more convenient
        usage. */
    typedef typename MeshType::NodeIterator NodeIterator;

    /** Const iterator over the nodes. This iterator is an indirect
        iterator over Node::Pointer which turn back a reference to
        node by * operator and not a pointer for more convenient
        usage. */
    typedef typename MeshType::NodeConstantIterator NodeConstantIterator;

    /** Iterator over the properties. This iterator is an indirect
        iterator over Properties::Pointer which turn back a reference to
        properties by * operator and not a pointer for more convenient
        usage. */

    /// Properties container. Which is a vector set of Properties with their Id's as key.
    typedef typename MeshType::PropertiesContainerType PropertiesContainerType;

    /** Iterator over the Properties. This iterator is an indirect
        iterator over Node::Pointer which turn back a reference to
        node by * operator and not a pointer for more convenient
        usage. */
    typedef typename MeshType::PropertiesIterator PropertiesIterator;

    /** Const iterator over the Properties. This iterator is an indirect
        iterator over Properties::Pointer which turn back a reference to
        Properties by * operator and not a pointer for more convenient
        usage. */
    typedef typename MeshType::PropertiesConstantIterator PropertiesConstantIterator;

    /** Iterator over the properties. This iterator is an indirect
        iterator over Properties::Pointer which turn back a reference to
        properties by * operator and not a pointer for more convenient
        usage. */

    /// Element container. A vector set of Elements with their Id's as key.
    typedef typename MeshType::ElementsContainerType ElementsContainerType;

    /** Iterator over the Elements. This iterator is an indirect
        iterator over Elements::Pointer which turn back a reference to
        Element by * operator and not a pointer for more convenient
        usage. */
    typedef typename MeshType::ElementIterator ElementIterator;

    /** Const iterator over the Elements. This iterator is an indirect
        iterator over Elements::Pointer which turn back a reference to
        Element by * operator and not a pointer for more convenient
        usage. */
    typedef typename MeshType::ElementConstantIterator ElementConstantIterator;

    /// Condintions container. A vector set of Conditions with their Id's as key.
    typedef typename MeshType::ConditionsContainerType ConditionsContainerType;

    /** Iterator over the Conditions. This iterator is an indirect
       iterator over Conditions::Pointer which turn back a reference to
       Condition by * operator and not a pointer for more convenient
       usage. */
    typedef typename MeshType::ConditionIterator ConditionIterator;

    /** Const iterator over the Conditions. This iterator is an indirect
        iterator over Conditions::Pointer which turn back a reference to
        Condition by * operator and not a pointer for more convenient
        usage. */
    typedef typename MeshType::ConditionConstantIterator ConditionConstantIterator;

    /// Defining a table with DataType argument and result type as table type.
    typedef Table<ValueType, DataType> TableType;

    /// The container of the tables. A vector map of the tables.
    typedef PointerVectorMap<SizeType, TableType> TablesContainerType;

    /** Iterator over the Tables. This iterator is an indirect
    iterator over Tables::Pointer which turn back a reference to
    Table by * operator and not a pointer for more convenient
    usage. */
    typedef typename TablesContainerType::iterator TableIterator;

    /** Const iterator over the Tables. This iterator is an indirect
    iterator over Table::Pointer which turn back a reference to
    Table by * operator and not a pointer for more convenient
    usage. */
    typedef typename TablesContainerType::const_iterator TableConstantIterator;
    /**
     *
     */
    /// The container of the constraints
    typedef typename MeshType::MasterSlaveConstraintType MasterSlaveConstraintType;
    typedef typename MeshType::MasterSlaveConstraintContainerType MasterSlaveConstraintContainerType;

    /** Iterator over the constraints. This iterator is an indirect
    iterator over MasterSlaveConstraint::Pointer which turn back a reference to
    MasterSlaveConstraint by * operator and not a pointer for more convenient
    usage. */
    typedef typename MeshType::MasterSlaveConstraintIteratorType MasterSlaveConstraintIteratorType;

    /** Const iterator over the constraints. This iterator is an indirect
    iterator over MasterSlaveConstraint::Pointer which turn back a reference to
    Table by * operator and not a pointer for more convenient
    usage. */
    typedef typename MeshType::MasterSlaveConstraintConstantIteratorType MasterSlaveConstraintConstantIteratorType;

    /// Type of the communicator
    typedef Communicator<NodeType> CommunicatorType;

    ///@}
    ///@name Flags
    ///@{

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    ModelPartImpl();

    /// Constructor with name
    ModelPartImpl(std::string const& NewName);

    /// Constructor with name and bufferSize
    ModelPartImpl(std::string const& NewName, IndexType NewBufferSize);

    /// Copy constructor.
    ModelPartImpl(ModelPartImpl const& rOther);

    /// Destructor.
    ~ModelPartImpl() override;

    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    ModelPartImpl & operator=(ModelPartImpl const& rOther);

    ///@}
    ///@name Solution Steps
    ///@{

    IndexType CreateSolutionStep();

    IndexType CloneSolutionStep();

    // commented due to a bug, Pooyan.
    //       IndexType CreateTimeStep()
    //  {
    //    IndexType new_index = CreateSolutionStep();
    //    mProcessInfo.SetAsTimeStepInfo();

    //    return new_index;
    //  }

    IndexType CloneTimeStep();

    IndexType CreateTimeStep(ValueType NewTime);

    IndexType CloneTimeStep(ValueType NewTime);

    void OverwriteSolutionStepData(IndexType SourceSolutionStepIndex, IndexType DestinationSourceSolutionStepIndex);

    ///ATTENTION: this function does not touch the coordinates of the nodes.
    ///It just resets the database values to the values at the beginning of the time step
    void ReduceTimeStep(ModelPartImpl& rModelPart, ValueType NewTime);

    ///@}
    ///@name Nodes
    ///@{

    SizeType NumberOfNodes(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).NumberOfNodes();
    }

    /** Inserts a node in the current mesh.
     */
    void AddNode(typename NodeType::Pointer pNewNode, IndexType ThisIndex = 0);

    /** Inserts a node in the current mesh.
     */
    typename NodeType::Pointer CreateNewNode(int Id, CoordinateType x, CoordinateType y, CoordinateType z, VariablesListType* pNewVariablesList, IndexType ThisIndex = 0);

    typename NodeType::Pointer CreateNewNode(IndexType Id, CoordinateType x, CoordinateType y, CoordinateType z, IndexType ThisIndex = 0);

    typename NodeType::Pointer CreateNewNode(IndexType Id, CoordinateType x, CoordinateType y, CoordinateType z, DataType* pThisData, IndexType ThisIndex = 0);

    typename NodeType::Pointer CreateNewNode(IndexType NodeId, NodeType const& rSourceNode, IndexType ThisIndex = 0);

    void AssignNode(typename NodeType::Pointer pThisNode, IndexType ThisIndex = 0);

    /** Returns if the Node corresponding to it's identifier exists */
    bool HasNode(IndexType NodeId, IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).HasNode(NodeId);
    }

    /** Returns the Node::Pointer  corresponding to it's identifier */
    typename NodeType::Pointer pGetNode(IndexType NodeId, IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pGetNode(NodeId);
    }

    /** Returns the Node::Pointer corresponding to it's identifier */
    const typename NodeType::Pointer pGetNode(const IndexType NodeId, const IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).pGetNode(NodeId);
    }

    /** Returns a reference node corresponding to it's identifier */
    NodeType& GetNode(IndexType NodeId, IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).GetNode(NodeId);
    }

    const NodeType& GetNode(IndexType NodeId, IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).GetNode(NodeId);
    }

    /** Remove the node with given Id from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveNode(IndexType NodeId, IndexType ThisIndex = 0);

    /** Remove given node from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveNode(NodeType& ThisNode, IndexType ThisIndex = 0);

    /** Remove given node from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveNode(typename NodeType::Pointer pThisNode, IndexType ThisIndex = 0);

    /** Remove the node with given Id from mesh with ThisIndex in parents and children.
    */
    void RemoveNodeFromAllLevels(IndexType NodeId, IndexType ThisIndex = 0);

    /** Remove given node from current mesh with ThisIndex in parents and children.
    */
    void RemoveNodeFromAllLevels(NodeType& ThisNode, IndexType ThisIndex = 0);

    /** Remove given node from current mesh with ThisIndex in parents and children.
    */
    void RemoveNodeFromAllLevels(typename NodeType::Pointer pThisNode, IndexType ThisIndex = 0);

    NodeIterator NodesBegin(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).NodesBegin();
    }

    NodeConstantIterator NodesBegin(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).NodesBegin();
    }

    NodeIterator NodesEnd(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).NodesEnd();
    }

    NodeConstantIterator NodesEnd(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).NodesEnd();
    }

    NodesContainerType& Nodes(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).Nodes();
    }

    const NodesContainerType& Nodes(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).Nodes();
    }

    typename NodesContainerType::Pointer pNodes(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pNodes();
    }

    void SetNodes(typename NodesContainerType::Pointer pOtherNodes, IndexType ThisIndex = 0)
    {
        GetMesh(ThisIndex).SetNodes(pOtherNodes);
    }

    typename NodesContainerType::ContainerType& NodesArray(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).NodesArray();
    }

    template<class TOtherDataType>
    void AddNodalSolutionStepVariable(Variable<TOtherDataType> const& ThisVariable)
    {
        mpVariablesList->Add(ThisVariable);
    }

    bool HasNodalSolutionStepVariable(VariableData const& ThisVariable) const
    {
        return mpVariablesList->Has(ThisVariable);
    }

    VariablesListType& GetNodalSolutionStepVariablesList()
    {
        return *mpVariablesList;
    }

    VariablesListType const& GetNodalSolutionStepVariablesList() const
    {
        return *mpVariablesList;
    }

    const VariablesListType* pGetNodalSolutionStepVariablesList() const
    {
        return mpVariablesList;
    }

    void SetNodalSolutionStepVariablesList();

    void SetNodalSolutionStepVariablesList(VariablesListType* pNewVariablesList)
    {
        mpVariablesList = pNewVariablesList;
    }

    SizeType GetNodalSolutionStepDataSize()
    {
        return mpVariablesList->DataSize();
    }

    SizeType GetNodalSolutionStepTotalDataSize()
    {
        return mpVariablesList->DataSize() * mBufferSize;
    }

    ///@}
    ///@name Tables
    ///@{

    SizeType NumberOfTables() const
    {
        return mTables.size();
    }

    /** Inserts a Table
     */
    void AddTable(IndexType TableId, typename TableType::Pointer pNewTable);

    /** Returns the Table::Pointer  corresponding to it's identifier */
    typename TableType::Pointer pGetTable(IndexType TableId)
    {
        return mTables(TableId);
    }

    /** Returns a reference to Table corresponding to the identifier */
    TableType& GetTable(IndexType TableId)
    {
        return mTables[TableId];
    }

    /** Remove the Table with given Id from current mesh in this modelpart and all its subs.
    */
    void RemoveTable(IndexType TableId);

    /** Remove the Table with given Id from current mesh in parents, itself and all children.
    */
    void RemoveTableFromAllLevels(IndexType TableId);


    TableIterator TablesBegin()
    {
        return mTables.begin();
    }

    TableConstantIterator TablesBegin() const
    {
        return mTables.begin();
    }

    TableIterator TablesEnd()
    {
        return mTables.end();
    }

    TableConstantIterator TablesEnd() const
    {
        return mTables.end();
    }

    TablesContainerType& Tables()
    {
        return mTables;
    }

    typename TablesContainerType::ContainerType& TablesArray()
    {
        return mTables.GetContainer();
    }

    ///@}
    ///@name MasterSlaveConstraints
    ///@{

    SizeType NumberOfMasterSlaveConstraints(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).NumberOfMasterSlaveConstraints();
    }

    MasterSlaveConstraintContainerType& MasterSlaveConstraints(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).MasterSlaveConstraints();
    }

    const MasterSlaveConstraintContainerType& MasterSlaveConstraints(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).MasterSlaveConstraints();
    }

    typename MasterSlaveConstraintContainerType::Pointer pMasterSlaveConstraints(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pMasterSlaveConstraints();
    }

    MasterSlaveConstraintConstantIteratorType  MasterSlaveConstraintsBegin(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).MasterSlaveConstraintsBegin();
    }

    MasterSlaveConstraintConstantIteratorType  MasterSlaveConstraintsEnd(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).MasterSlaveConstraintsEnd();
    }

    MasterSlaveConstraintIteratorType  MasterSlaveConstraintsBegin(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).MasterSlaveConstraintsBegin();
    }

    MasterSlaveConstraintIteratorType  MasterSlaveConstraintsEnd(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).MasterSlaveConstraintsEnd();
    }

    /** Inserts a master-slave constraint in the current modelpart.
     */
    void AddMasterSlaveConstraint(typename MasterSlaveConstraintType::Pointer pNewMasterSlaveConstraint, IndexType ThisIndex = 0);

    /** Inserts a list of master-slave constraints to a submodelpart provided their Id. Does nothing if applied to the top model part
     */
    void AddMasterSlaveConstraints(std::vector<IndexType> const& MasterSlaveConstraintIds, IndexType ThisIndex = 0);

    /** Inserts a list of pointers to Master-Slave constraints
     */
    template<class TIteratorType >
    void AddMasterSlaveConstraints(TIteratorType constraints_begin,  TIteratorType constraints_end, IndexType ThisIndex = 0)
    {
        KRATOS_TRY
        ModelPartImpl::MasterSlaveConstraintContainerType  aux;
        ModelPartImpl::MasterSlaveConstraintContainerType  aux_root;
        ModelPartImpl* root_model_part = &this->GetRootModelPart();

        for(TIteratorType it = constraints_begin; it!=constraints_end; it++)
        {
            auto it_found = root_model_part->MasterSlaveConstraints().find(it->Id());
            if(it_found == root_model_part->MasterSlaveConstraintsEnd()) //node does not exist in the top model part
            {
                aux_root.push_back( *(it.base()) );
                aux.push_back( *(it.base()) );
            }
            else //if it does exist verify it is the same node
            {
                if(&(*it_found) != &(*it))//check if the pointee coincides
                    KRATOS_ERROR << "attempting to add a new master-slave constraint with Id :" << it_found->Id() << ", unfortunately a (different) master-slave constraint with the same Id already exists" << std::endl;
                else
                    aux.push_back( *(it.base()) );
            }
        }

        for(auto it = aux_root.begin(); it!=aux_root.end(); it++)
                root_model_part->MasterSlaveConstraints().push_back( *(it.base()) );
        root_model_part->MasterSlaveConstraints().Unique();

        //add to all of the leaves

        ModelPartImpl* current_part = this;
        while(current_part->IsSubModelPart())
        {
            for(auto it = aux.begin(); it!=aux.end(); it++)
                current_part->MasterSlaveConstraints().push_back( *(it.base()) );

            current_part->MasterSlaveConstraints().Unique();

            current_part = current_part->GetParentModelPart();
        }

        KRATOS_CATCH("")
    }

    /**
     * @brief Creates a new master-slave constraint in the current modelpart.
     * @todo Replace these 3 functions by one that perfectly forwards arguments, then just define these 3 interfaces on the pybind side
     */
    typename MasterSlaveConstraintType::Pointer CreateNewMasterSlaveConstraint(const std::string& ConstraintName,
        const IndexType& Id, DofsVectorType& rMasterDofsVector, DofsVectorType& rSlaveDofsVector,
        const MatrixType& RelationMatrix, const VectorType& ConstantVector, const IndexType& ThisIndex = 0);

    typename MasterSlaveConstraintType::Pointer CreateNewMasterSlaveConstraint(const std::string& ConstraintName,
        const IndexType& Id, NodeType& rMasterNode, const DoubleVariableType& rMasterVariable,
        NodeType& rSlaveNode, const DoubleVariableType& rSlaveVariable,
        const DataType& Weight, const DataType& Constant, const IndexType& ThisIndex = 0);

    typename MasterSlaveConstraintType::Pointer CreateNewMasterSlaveConstraint(const std::string& ConstraintName,
        const IndexType& Id, NodeType& rMasterNode, const VariableComponentType& rMasterVariable,
        NodeType& rSlaveNode, const VariableComponentType& rSlaveVariable,
        const DataType& Weight, const DataType& Constant, const IndexType& ThisIndex = 0);

    typename MasterSlaveConstraintType::Pointer CreateNewMasterSlaveConstraintNoUnique(const std::string& ConstraintName,
        const IndexType& Id, DofsVectorType& rMasterDofsVector, DofsVectorType& rSlaveDofsVector,
        const MatrixType& RelationMatrix, const VectorType& ConstantVector, const IndexType& ThisIndex = 0);
    /**
     * @brief Remove the master-slave constraint with given Id from mesh with ThisIndex in this modelpart and all its subs.
     */
    void RemoveMasterSlaveConstraint(IndexType MasterSlaveConstraintId, IndexType ThisIndex = 0);

    /**
     * @brief Remove given master-slave constraint from mesh with ThisIndex in this modelpart and all its subs.
     */
    void RemoveMasterSlaveConstraint(MasterSlaveConstraintType& ThisMasterSlaveConstraint, IndexType ThisIndex = 0);

    /**
     * @brief Remove the master-slave constraint with given Id from mesh with ThisIndex in parents, itself and children.
     */
    void RemoveMasterSlaveConstraintFromAllLevels(IndexType MasterSlaveConstraintId, IndexType ThisIndex = 0);

    /**
     * @brief Remove given master-slave constraint from mesh with ThisIndex in parents, itself and children.
     */
    void RemoveMasterSlaveConstraintFromAllLevels(MasterSlaveConstraintType& ThisMasterSlaveConstraint, IndexType ThisIndex = 0);

    /**
     * @brief It erases all constraints identified by "IdentifierFlag" by removing the pointer.
     * @details Pointers are erased from this level downwards nodes will be automatically destructured when no pointer is left to them
     * @param IdentifierFlag The flag that identifies the constraints to remove
     */
    void RemoveMasterSlaveConstraints(Flags IdentifierFlag = TO_ERASE);

    /**
     * @brief It erases all constraints identified by "IdentifierFlag" by removing the pointer.
     * @details Pointers will be erase from all levels nodes will be automatically destructured when no pointer is left to them
     * @param IdentifierFlag The flag that identifies the constraints to remove
     */
    void RemoveMasterSlaveConstraintsFromAllLevels(Flags IdentifierFlag = TO_ERASE);

    /**
     * @brief Returns if the MasterSlaveConstraint corresponding to it's identifier exists
     * @param MasterSlaveConstraintId The ID of master-slave constraint
     * @param ThisIndex The mesh index
     */
    bool HasMasterSlaveConstraint(
        const IndexType MasterSlaveConstraintId,
        IndexType ThisIndex = 0
        ) const
    {
        return GetMesh(ThisIndex).HasMasterSlaveConstraint(MasterSlaveConstraintId);
    }

    /** Returns the MasterSlaveConstraint::Pointer  corresponding to it's identifier */
    typename MasterSlaveConstraintType::Pointer pGetMasterSlaveConstraint(IndexType ConstraintId, IndexType ThisIndex = 0);

    /** Returns a reference MasterSlaveConstraint corresponding to it's identifier */
    MasterSlaveConstraintType& GetMasterSlaveConstraint(IndexType MasterSlaveConstraintId, IndexType ThisIndex = 0);

    /** Returns a const reference MasterSlaveConstraint corresponding to it's identifier */
    const MasterSlaveConstraintType& GetMasterSlaveConstraint(IndexType MasterSlaveConstraintId, IndexType ThisIndex = 0) const ;

    ///@}
    ///@name Properties
    ///@{

    /**
     * @brief Returns the number of properties of the mesh
     * @param ThisIndex The index identifying the mesh
     * @return The number of properties of the mesh
     */
    SizeType NumberOfProperties(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).NumberOfProperties();
    }

    /**
     * @brief Inserts a properties in the current mesh.
     * @param pNewProperties The new property pointer to be added
     * @param ThisIndex The index identifying the mesh
     */
    void AddProperties(PropertiesType::Pointer pNewProperties, IndexType ThisIndex = 0);

    /** Returns the Properties::Pointer  corresponding to it's identifier */
    PropertiesType::Pointer pGetProperties(IndexType PropertiesId, IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pGetProperties(PropertiesId);
    }

    /** Returns a reference Properties corresponding to it's identifier */
    PropertiesType& GetProperties(IndexType PropertiesId, IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).GetProperties(PropertiesId);
    }

    /** Remove the Properties with given Id from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveProperties(IndexType PropertiesId, IndexType ThisIndex = 0);

    /** Remove given Properties from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveProperties(PropertiesType& ThisProperties, IndexType ThisIndex = 0);

    /** Remove given Properties from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveProperties(PropertiesType::Pointer pThisProperties, IndexType ThisIndex = 0);

    /** Remove the Properties with given Id from mesh with ThisIndex in parents, itself and children.
    */
    void RemovePropertiesFromAllLevels(IndexType PropertiesId, IndexType ThisIndex = 0);

    /** Remove given Properties from mesh with ThisIndex in parents, itself and children.
    */
    void RemovePropertiesFromAllLevels(PropertiesType& ThisProperties, IndexType ThisIndex = 0);

    /** Remove given Properties from mesh with ThisIndex in parents, itself and children.
    */
    void RemovePropertiesFromAllLevels(PropertiesType::Pointer pThisProperties, IndexType ThisIndex = 0);

    PropertiesIterator PropertiesBegin(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).PropertiesBegin();
    }

    PropertiesConstantIterator PropertiesBegin(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).PropertiesBegin();
    }

    PropertiesIterator PropertiesEnd(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).PropertiesEnd();
    }

    PropertiesConstantIterator PropertiesEnd(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).PropertiesEnd();
    }

    /**
     * temporarily renamed Properties() function because the declaration of Properties()
     * here violates the declaration of Properties() in properties.h
     * (janosch, in agreement with pooyan)
     */
    PropertiesContainerType& rProperties(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).Properties();
    }

    typename PropertiesContainerType::Pointer pProperties(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pProperties();
    }

    void SetProperties(typename PropertiesContainerType::Pointer pOtherProperties, IndexType ThisIndex = 0)
    {
        GetMesh(ThisIndex).SetProperties(pOtherProperties);
    }

    typename PropertiesContainerType::ContainerType& PropertiesArray(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).PropertiesArray();
    }

    const typename PropertiesContainerType::ContainerType& PropertiesArray(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).PropertiesArray();
    }

    ///@}
    ///@name Elements
    ///@{

    SizeType NumberOfElements(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).NumberOfElements();
    }

    /** Inserts a element in the current mesh.
     */
    void AddElement(typename ElementType::Pointer pNewElement, IndexType ThisIndex = 0);

    /** Inserts an element in the current mesh.
     */
    typename ElementType::Pointer CreateNewElement(std::string ElementName, IndexType Id, const std::vector<IndexType>& ElementNodeIds, PropertiesType::Pointer pProperties, IndexType ThisIndex = 0);

    /** Inserts an element in the current mesh.
     */
    typename ElementType::Pointer CreateNewElement(std::string ElementName, IndexType Id, typename GeometryType::PointsArrayType pElementNodes, PropertiesType::Pointer pProperties, IndexType ThisIndex = 0);

    /** Returns the Element::Pointer  corresponding to it's identifier */
    typename ElementType::Pointer pGetElement(IndexType ElementId, IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pGetElement(ElementId);
    }

    /** Returns a reference element corresponding to it's identifier */
    ElementType& GetElement(IndexType ElementId, IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).GetElement(ElementId);
    }

    /** Returns a reference element corresponding to it's identifier */
    const ElementType& GetElement(IndexType ElementId, IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).GetElement(ElementId);
    }

    /** Remove the element with given Id from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveElement(IndexType ElementId, IndexType ThisIndex = 0);

    /** Remove given element from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveElement(ElementType& ThisElement, IndexType ThisIndex = 0);

    /** Remove given element from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveElement(typename ElementType::Pointer pThisElement, IndexType ThisIndex = 0);

    /** Remove the element with given Id from mesh with ThisIndex in parents, itself and children.
    */
    void RemoveElementFromAllLevels(IndexType ElementId, IndexType ThisIndex = 0);

    /** Remove given element from mesh with ThisIndex in parents, itself and children.
    */
    void RemoveElementFromAllLevels(ElementType& ThisElement, IndexType ThisIndex = 0);

    /** Remove given element from mesh with ThisIndex in parents, itself and children.
    */
    void RemoveElementFromAllLevels(typename ElementType::Pointer pThisElement, IndexType ThisIndex = 0);

    ElementIterator ElementsBegin(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).ElementsBegin();
    }

    ElementConstantIterator ElementsBegin(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).ElementsBegin();
    }

    ElementIterator ElementsEnd(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).ElementsEnd();
    }

    ElementConstantIterator ElementsEnd(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).ElementsEnd();
    }

    ElementsContainerType& Elements(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).Elements();
    }

    const ElementsContainerType& Elements(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).Elements();
    }

    typename ElementsContainerType::Pointer pElements(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pElements();
    }

    void SetElements(typename ElementsContainerType::Pointer pOtherElements, IndexType ThisIndex = 0)
    {
        GetMesh(ThisIndex).SetElements(pOtherElements);
    }

    typename ElementsContainerType::ContainerType& ElementsArray(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).ElementsArray();
    }

    const typename ElementsContainerType::ContainerType& ElementsArray(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).ElementsArray();
    }

    ///@}
    ///@name Conditions
    ///@{

    SizeType NumberOfConditions(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).NumberOfConditions();
    }

    /** Inserts a condition in the current mesh.
     */
    void AddCondition(typename ConditionType::Pointer pNewCondition, IndexType ThisIndex = 0);

    /** Inserts a condition in the current mesh.
     */
    typename ConditionType::Pointer CreateNewCondition(std::string ConditionName,
        IndexType Id, const std::vector<IndexType>& ConditionNodeIds,
        PropertiesType::Pointer pProperties, IndexType ThisIndex = 0);

    /** Inserts a condition in the current mesh.
     */
    typename ConditionType::Pointer CreateNewCondition(std::string ConditionName,
        IndexType Id, typename GeometryType::PointsArrayType pConditionNodes,
        PropertiesType::Pointer pProperties, IndexType ThisIndex = 0);

    /** Returns the Condition::Pointer  corresponding to it's identifier */
    typename ConditionType::Pointer pGetCondition(IndexType ConditionId, IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pGetCondition(ConditionId);
    }

    /** Returns a reference condition corresponding to it's identifier */
    ConditionType& GetCondition(IndexType ConditionId, IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).GetCondition(ConditionId);
    }

    /** Returns a reference condition corresponding to it's identifier */
    const ConditionType& GetCondition(IndexType ConditionId, IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).GetCondition(ConditionId);
    }

    /**  Remove the condition with given Id from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveCondition(IndexType ConditionId, IndexType ThisIndex = 0);

    /** Remove given condition from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveCondition(ConditionType& ThisCondition, IndexType ThisIndex = 0);

    /** Remove given condition from mesh with ThisIndex in this modelpart and all its subs.
    */
    void RemoveCondition(typename ConditionType::Pointer pThisCondition, IndexType ThisIndex = 0);

    /**  Remove the condition with given Id from mesh with ThisIndex in parents, itself and children.
    */
    void RemoveConditionFromAllLevels(IndexType ConditionId, IndexType ThisIndex = 0);

    /** Remove given condition from mesh with ThisIndex in parents, itself and children.
    */
    void RemoveConditionFromAllLevels(ConditionType& ThisCondition, IndexType ThisIndex = 0);

    /** Remove given condition from mesh with ThisIndex in parents, itself and children.
    */
    void RemoveConditionFromAllLevels(typename ConditionType::Pointer pThisCondition, IndexType ThisIndex = 0);

    ConditionIterator ConditionsBegin(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).ConditionsBegin();
    }

    ConditionConstantIterator ConditionsBegin(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).ConditionsBegin();
    }

    ConditionIterator ConditionsEnd(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).ConditionsEnd();
    }

    ConditionConstantIterator ConditionsEnd(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).ConditionsEnd();
    }

    ConditionsContainerType& Conditions(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).Conditions();
    }

    const ConditionsContainerType& Conditions(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).Conditions();
    }

    typename ConditionsContainerType::Pointer pConditions(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).pConditions();
    }

    void SetConditions(typename ConditionsContainerType::Pointer pOtherConditions, IndexType ThisIndex = 0)
    {
        GetMesh(ThisIndex).SetConditions(pOtherConditions);
    }

    typename ConditionsContainerType::ContainerType& ConditionsArray(IndexType ThisIndex = 0)
    {
        return GetMesh(ThisIndex).ConditionsArray();
    }

    const typename ConditionsContainerType::ContainerType& ConditionsArray(IndexType ThisIndex = 0) const
    {
        return GetMesh(ThisIndex).ConditionsArray();
    }

    ///@}
    ///@name Sub model parts
    ///@{

    /** Creates a new sub model part with given name.
    Does nothing if a sub model part with the same name exist.
    */
    BaseModelPart& CreateSubModelPart(std::string const& NewSubModelPartName) override;

    /** Add an existing model part as a sub model part.
        All the meshes will be added to the parents.
        NOTE: The added sub model part should not have
        mesh entities with id in conflict with other ones in the parent
        In the case of conflict the new one would replace the old one
        resulting inconsitency in parent.
    */
    void AddSubModelPart(BaseModelPart& rThisSubModelPart) override;

    ///@}
    ///@name Access
    ///@{

    ProcessInfo& GetProcessInfo()
    {
        return *mpProcessInfo;
    }

    ProcessInfo const& GetProcessInfo() const
    {
        return *mpProcessInfo;
    }

    ProcessInfo::Pointer pGetProcessInfo()
    {
        return mpProcessInfo;
    }

    const ProcessInfo::Pointer pGetProcessInfo() const
    {
        return mpProcessInfo;
    }

    void SetProcessInfo(ProcessInfo::Pointer pNewProcessInfo);

    void SetProcessInfo(ProcessInfo& NewProcessInfo);

    SizeType NumberOfMeshes()
    {
        return mMeshes.size();
    }

    typename MeshType::Pointer pGetMesh(IndexType ThisIndex = 0)
    {
        return mMeshes(ThisIndex);
    }

    const typename MeshType::Pointer pGetMesh(IndexType ThisIndex = 0) const
    {
        return mMeshes(ThisIndex);
    }

    MeshType& GetMesh(IndexType ThisIndex = 0)
    {
        return mMeshes[ThisIndex];
    }

    MeshType const& GetMesh(IndexType ThisIndex = 0) const
    {
        return mMeshes[ThisIndex];
    }

    MeshesContainerType& GetMeshes()
    {
        return mMeshes;
    }

    MeshesContainerType const& GetMeshes() const
    {
        return mMeshes;
    }

    CommunicatorType& GetCommunicator()
    {
        return *mpCommunicator;
    }

    CommunicatorType const& GetCommunicator() const
    {
        return *mpCommunicator;
    }

    typename CommunicatorType::Pointer pGetCommunicator()
    {
        return mpCommunicator;
    }

    void SetCommunicator(typename CommunicatorType::Pointer pNewCommunicator)
    {
        mpCommunicator = pNewCommunicator;
    }

    ///@}
    ///@name Operations
    ///@{

    void SetBufferSize(IndexType NewBufferSize);

    /**
     * @brief This method gets the suffer size of the model part database
     * @return mBufferSize The buffer size
     */
    IndexType GetBufferSize() const
    {
        return mBufferSize;
    }

    /// run input validation
    virtual int Check( ProcessInfo& rCurrentProcessInfo ) const;

    ///@}
    ///@name Access
    ///@{


    ///@}
    ///@name Inquiry
    ///@{

    /// Get the last node id of the model part
    IndexType GetLastNodeId() const;

    /// Get the last element id of the model part
    IndexType GetLastElementId() const;

    /// Get the last condition id of the model part
    IndexType GetLastConditionId() const;

    /// Get the last constraint id of the model part
    IndexType GetLastConstraintId() const;

    ///@}
    ///@name Input and output
    ///@{

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override;

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const override;

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream, std::string const& PrefixString) const override;

    /// Print object's data.
    void PrintData(std::ostream& rOStream, std::string const& PrefixString) const override;

    ///@}
    ///@name Friends
    ///@{


    ///@}

private:

    friend class Model;

    /// Constructor with name and bufferSize and owner model
    ModelPartImpl(std::string const& NewName, IndexType NewBufferSize, Model& rOwnerModel);

    ///@name Static Member Variables
    ///@{


    ///@}
    ///@name Member Variables
    ///@{

    IndexType mBufferSize; /// The buffers size of the database

    ProcessInfo::Pointer mpProcessInfo; /// The process info instance

    TablesContainerType mTables; /// The tables contained on the model part

    std::vector<IndexType> mIndices;

    MeshesContainerType mMeshes; /// The container of all meshes

    VariablesListType* mpVariablesList;

    typename CommunicatorType::Pointer mpCommunicator; /// The communicator

    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    template <typename TEntitiesContainerType>
    void AddEntities(TEntitiesContainerType const& Source, TEntitiesContainerType& rDestination, Flags Options)
    {
        //if (Options->Is(ALL_ENTITIES))
        //{
        //  if(Options->Is())
        //}
    }

    ///@}
    ///@name Serialization
    ///@{

    friend class Serializer;

    void save(Serializer& rSerializer) const override;

    void load(Serializer& rSerializer) override;

    ///@}
    ///@name Private  Access
    ///@{


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}

}; // Class ModelPartImpl

// Officially define the ModelPart
typedef ModelPartImpl<Node<3, KRATOS_DOUBLE_TYPE, Dof<KRATOS_DOUBLE_TYPE> > > ModelPart;            // this is the typical ModelPart with geometry coordinates as double and Dof as double
typedef ModelPartImpl<Node<3, KRATOS_DOUBLE_TYPE, Dof<KRATOS_COMPLEX_TYPE> > > ComplexModelPart;    // this is the ModelPart with double geometry coordinates but Dof as complex(double)
typedef ModelPartImpl<Node<3, KRATOS_COMPLEX_TYPE, Dof<KRATOS_COMPLEX_TYPE> > > GComplexModelPart;  // this ModelPart works with complex geometry coordinates and complex Dof

///@}

///@name Type Definitions
///@{

template<typename TEntityType>
struct ModelPartEntitiesContainerSelector
{};

template<>
struct ModelPartEntitiesContainerSelector<Element>
{
    typedef ModelPart::ElementsContainerType EntitiesContainerType;
};

template<>
struct ModelPartEntitiesContainerSelector<Condition>
{
    typedef ModelPart::ConditionsContainerType EntitiesContainerType;
};

///@}
///@name Input and output
///@{

/// input stream function
KRATOS_API(KRATOS_CORE) inline std::istream & operator >>(std::istream& rIStream,
        BaseModelPart& rThis)
{
    return rIStream;
}

/// output stream function
KRATOS_API(KRATOS_CORE) inline std::ostream & operator <<(std::ostream& rOStream,
        const BaseModelPart& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

} // namespace Kratos.

#endif // KRATOS_MODEL_PART_H_INCLUDED  defined
