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
//                   Riccardo Rossi
//  Contributors:    Hoang-Giang Bui
//
//

#if !defined(KRATOS_COMMUNICATOR_H_INCLUDED )
#define  KRATOS_COMMUNICATOR_H_INCLUDED

// System includes
#include <string>
#include <iostream>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/condition.h"
#include "includes/element.h"
#include "includes/mesh.h"

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

/// The Commmunicator class manages communication for distributed ModelPart instances.
/** The base Communicator class only holds the required data (local and remote mesh interfaces)
 *  for communication. The actual communication is implemented in the derived MPICommunicator.
 */
template<class TNodeType = Node<3> >
class KRATOS_API(KRATOS_CORE) Communicator
{
public:
    ///@name  Enum's
    ///@{


    ///@}
    ///@name Type Definitions
    ///@{

    /// Pointer definition of Communicator
    KRATOS_CLASS_POINTER_DEFINITION(Communicator);

    typedef TNodeType NodeType;

    typedef Properties PropertiesType;

    typedef BaseElement<NodeType> ElementType;

    typedef BaseCondition<NodeType> ConditionType;

    typedef boost::numeric::ublas::vector<int> NeighbourIndicesContainerType;

    typedef Mesh<NodeType, PropertiesType, ElementType, ConditionType> MeshType;

    typedef typename NodeType::DofType::DataType DataType;

    typedef typename MeshType::IndexType IndexType;

    typedef typename MeshType::SizeType SizeType;

    typedef typename MatrixVectorTypeSelector<DataType>::MatrixType MatrixType;

    typedef typename MatrixVectorTypeSelector<DataType>::VectorType VectorType;

    typedef PointerVector<MeshType> MeshesContainerType;

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

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    Communicator() : mNumberOfColors(1)
        , mpLocalMesh(typename MeshType::Pointer(new MeshType))
        , mpGhostMesh(typename MeshType::Pointer(new MeshType))
        , mpInterfaceMesh(typename MeshType::Pointer(new MeshType))
    {
        MeshType mesh;
        mLocalMeshes.push_back(mesh.Clone());
        mGhostMeshes.push_back(mesh.Clone());
        mInterfaceMeshes.push_back(mesh.Clone());
    }

    /// Copy constructor.
    Communicator(Communicator const& rOther)
        : mNumberOfColors(rOther.mNumberOfColors)
        , mNeighbourIndices(rOther.mNeighbourIndices)
        , mpLocalMesh(typename MeshType::Pointer(rOther.mpLocalMesh))
        , mpGhostMesh(typename MeshType::Pointer(rOther.mpGhostMesh))
        , mpInterfaceMesh(typename MeshType::Pointer(rOther.mpInterfaceMesh))
        , mLocalMeshes(rOther.mLocalMeshes)
        , mGhostMeshes(rOther.mGhostMeshes)
        , mInterfaceMeshes(rOther.mInterfaceMeshes)
    {
    }

    virtual Communicator::Pointer Create() const
    {
        KRATOS_TRY

        return Communicator::Pointer(new Communicator);

        KRATOS_CATCH("");
    }

    /// Destructor.
    virtual ~Communicator()
    {
    }

    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.

    Communicator & operator=(Communicator const& rOther)
    {
        mNumberOfColors = rOther.mNumberOfColors;
        mNeighbourIndices = rOther.mNeighbourIndices;
        mpLocalMesh = rOther.mpLocalMesh;
        mpGhostMesh = rOther.mpGhostMesh;
        mpInterfaceMesh = rOther.mpInterfaceMesh;
        mLocalMeshes = rOther.mLocalMeshes;
        mGhostMeshes = rOther.mGhostMeshes;
        mInterfaceMeshes = rOther.mInterfaceMeshes;

        return *this;
    }

    ///@}
    ///@name Access
    ///@{

    virtual int MyPID() const
    {
        return 0;
    }

    virtual int TotalProcesses() const
    {
        return 1;
    }

    SizeType GetNumberOfColors() const
    {
        return mNumberOfColors;
    }

    void SetNumberOfColors(SizeType NewNumberOfColors)
    {
        if (mNumberOfColors == NewNumberOfColors)
            return;

        mNumberOfColors = NewNumberOfColors;
        MeshType mesh;

        mLocalMeshes.clear();
        mGhostMeshes.clear();
        mInterfaceMeshes.clear();

        for (IndexType i = 0; i < mNumberOfColors; i++)
        {
            mLocalMeshes.push_back(mesh.Clone());
            mGhostMeshes.push_back(mesh.Clone());
            mInterfaceMeshes.push_back(mesh.Clone());
        }
    }

    void AddColors(SizeType NumberOfAddedColors)
    {
        if (NumberOfAddedColors < 1)
            return;

        mNumberOfColors += NumberOfAddedColors;
        MeshType mesh;

        for (IndexType i = 0; i < NumberOfAddedColors; i++)
        {
            mLocalMeshes.push_back(mesh.Clone());
            mGhostMeshes.push_back(mesh.Clone());
            mInterfaceMeshes.push_back(mesh.Clone());
        }
    }

    NeighbourIndicesContainerType& NeighbourIndices()
    {
        return mNeighbourIndices;
    }

    NeighbourIndicesContainerType const& NeighbourIndices() const
    {
        return mNeighbourIndices;
    }

    // Set the local mesh pointer to the given mesh
    void SetLocalMesh(typename MeshType::Pointer pGivenMesh)
    {
        mpLocalMesh = pGivenMesh;
    }

    // Returns pointer to the mesh storing all local entites

    typename MeshType::Pointer pLocalMesh()
    {
        return mpLocalMesh;
    }

    // Returns pointer to the mesh storing all ghost entites

    typename MeshType::Pointer pGhostMesh()
    {
        return mpGhostMesh;
    }

    // Returns pointer to the mesh storing all interface entites

    typename MeshType::Pointer pInterfaceMesh()
    {
        return mpInterfaceMesh;
    }

    // Returns a constant pointer to the mesh storing all local entites

    const typename MeshType::Pointer pLocalMesh() const
    {
        return mpLocalMesh;
    }

    // Returns a constant pointer to the mesh storing all ghost entites

    const typename MeshType::Pointer pGhostMesh() const
    {
        return mpGhostMesh;
    }

    // Returns a constant pointer to the mesh storing all interface entites

    const typename MeshType::Pointer pInterfaceMesh() const
    {
        return mpInterfaceMesh;
    }

    typename MeshType::Pointer pLocalMesh(IndexType ThisIndex)
    {
        return mLocalMeshes(ThisIndex);
    }

    typename MeshType::Pointer pGhostMesh(IndexType ThisIndex)
    {
        return mGhostMeshes(ThisIndex);
    }

    typename MeshType::Pointer pInterfaceMesh(IndexType ThisIndex)
    {
        return mInterfaceMeshes(ThisIndex);
    }

    const typename MeshType::Pointer pLocalMesh(IndexType ThisIndex) const
    {
        return mLocalMeshes(ThisIndex);
    }

    const typename MeshType::Pointer pGhostMesh(IndexType ThisIndex) const
    {
        return mGhostMeshes(ThisIndex);
    }

    const typename MeshType::Pointer pInterfaceMesh(IndexType ThisIndex) const
    {
        return mInterfaceMeshes(ThisIndex);
    }

    // Returns the reference to the mesh storing all local entites

    MeshType& LocalMesh()
    {
        return *mpLocalMesh;
    }

    // Returns the reference to the mesh storing all ghost entites

    MeshType& GhostMesh()
    {
        return *mpGhostMesh;
    }

    // Returns the reference to the mesh storing all interface entites

    MeshType& InterfaceMesh()
    {
        return *mpInterfaceMesh;
    }

    // Returns a constant reference to the mesh storing all local entites

    MeshType const& LocalMesh() const
    {
        return *mpLocalMesh;
    }

    // Returns a constant reference to the mesh storing all ghost entites

    MeshType const& GhostMesh() const
    {
        return *mpGhostMesh;
    }

    // Returns a constant reference to the mesh storing all interface entites

    MeshType const& InterfaceMesh() const
    {
        return *mpInterfaceMesh;
    }

    MeshType& LocalMesh(IndexType ThisIndex)
    {
        return mLocalMeshes[ThisIndex];
    }

    MeshType& GhostMesh(IndexType ThisIndex)
    {
        return mGhostMeshes[ThisIndex];
    }

    MeshType& InterfaceMesh(IndexType ThisIndex)
    {
        return mInterfaceMeshes[ThisIndex];
    }

    MeshType const& LocalMesh(IndexType ThisIndex) const
    {
        return mLocalMeshes[ThisIndex];
    }

    MeshType const& GhostMesh(IndexType ThisIndex) const
    {
        return mGhostMeshes[ThisIndex];
    }

    MeshType const& InterfaceMesh(IndexType ThisIndex) const
    {
        return mInterfaceMeshes[ThisIndex];
    }

    MeshesContainerType& LocalMeshes()
    {
        return mLocalMeshes;
    }

    MeshesContainerType& GhostMeshes()
    {
        return mGhostMeshes;
    }

    MeshesContainerType& InterfaceMeshes()
    {
        return mInterfaceMeshes;
    }

    MeshesContainerType const& LocalMeshes() const
    {
        return mLocalMeshes;
    }

    MeshesContainerType const& GhostMeshes() const
    {
        return mGhostMeshes;
    }

    MeshesContainerType const& InterfaceMeshes() const
    {
        return mInterfaceMeshes;
    }

    IndexType GetLastNodeId() const
    {
        return this->GetLastNodeId(this->LocalMesh());
    }

    virtual IndexType GetLastNodeId(const MeshType& rMesh) const
    {
        IndexType lastNodeId = 0;
        for(typename NodesContainerType::const_iterator it = rMesh.Nodes().begin();
                it != rMesh.Nodes().end(); ++it)
        {
            if(it->Id() > lastNodeId)
                lastNodeId = it->Id();
        }

        return lastNodeId;
    }

    IndexType GetLastElementId() const
    {
        return this->GetLastElementId(this->LocalMesh());
    }

    virtual IndexType GetLastElementId(const MeshType& rMesh) const
    {
        IndexType lastElementId = 0;
        for(typename ElementsContainerType::const_iterator it = rMesh.Elements().begin();
                it != rMesh.Elements().end(); ++it)
        {
            if(it->Id() > lastElementId)
                lastElementId = it->Id();
        }

        return lastElementId;
    }

    IndexType GetLastConditionId() const
    {
        return this->GetLastConditionId(this->LocalMesh());
    }

    virtual IndexType GetLastConditionId(const MeshType& rMesh) const
    {
        IndexType lastCondId = 0;
        for(typename ConditionsContainerType::const_iterator it = rMesh.Conditions().begin();
                it != rMesh.Conditions().end(); ++it)
        {
            if(it->Id() > lastCondId)
                lastCondId = it->Id();
        }

        return lastCondId;
    }

    ///@}
    ///@name Operations
    ///@{

    virtual void Barrier() const
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
    }

    virtual bool SumAll(int& rValue) const
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool SumAll(IndexType& rValue) const
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool SumAll(DataType& rValue) const
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool MinAll(int& rValue) const
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool MinAll(IndexType& rValue) const
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool MinAll(DataType& rValue) const
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool MaxAll(int& rValue) const
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool MaxAll(IndexType& rValue) const
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

#ifdef _MSC_VER
    virtual bool MaxAll(unsigned long& rValue) const
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }
#endif

    virtual bool MaxAll(DataType& rValue) const
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool SynchronizeElementalIds()
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool SynchronizeNodalSolutionStepsData()
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;

    }

    virtual bool SynchronizeDofs()
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;

    }

    virtual bool SynchronizeVariable(Variable<int> const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool SynchronizeVariable(Variable<DataType> const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool SynchronizeVariable(Variable<array_1d<DataType, 3 > > const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool SynchronizeVariable(Variable<VectorType> const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    virtual bool SynchronizeVariable(Variable<MatrixType> const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;
    }

    // This function is for test and will be changed. Pooyan.
    virtual bool SynchronizeCurrentDataToMin(Variable<DataType> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;

    }

    virtual bool AssembleCurrentData(Variable<int> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;

    }

    virtual bool AssembleCurrentData(Variable<DataType> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;

    }

    virtual bool AssembleCurrentData(Variable<array_1d<DataType, 3 > > const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;

    }

    virtual bool AssembleCurrentData(Variable<VectorType> const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;

    }

    virtual bool AssembleCurrentData(Variable<MatrixType> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;

    }

    virtual bool AssembleNonHistoricalData(Variable<int> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;

    }

    virtual bool AssembleNonHistoricalData(Variable<DataType> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;

    }

    virtual bool AssembleNonHistoricalData(Variable<array_1d<DataType, 3 > > const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;

    }


    virtual bool AssembleNonHistoricalData(Variable<vector<array_1d<DataType,3> > > const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;

    }

    virtual bool AssembleNonHistoricalData(Variable<VectorType> const& ThisVariable)
    {
        // #if defined(KRATOS_USING_MPI )
        //  std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        // #endif
        return true;

    }

    virtual bool AssembleNonHistoricalData(Variable<MatrixType> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;

    }

    virtual bool SynchronizeElementalNonHistoricalVariable(Variable<int> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool SynchronizeElementalNonHistoricalVariable(Variable<DataType> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool SynchronizeElementalNonHistoricalVariable(Variable<array_1d<DataType, 3 > > const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool SynchronizeElementalNonHistoricalVariable(Variable<vector<array_1d<DataType,3> > > const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool SynchronizeElementalNonHistoricalVariable(Variable<VectorType> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool SynchronizeElementalNonHistoricalVariable(Variable<MatrixType> const& ThisVariable)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool TransferObjects(std::vector<NodesContainerType>& SendObjects, std::vector<NodesContainerType>& RecvObjects)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool TransferObjects(std::vector<ElementsContainerType>& SendObjects, std::vector<ElementsContainerType>& RecvObjects)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool TransferObjects(std::vector<ConditionsContainerType>& SendObjects, std::vector<ConditionsContainerType>& RecvObjects)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool TransferObjects(std::vector<NodesContainerType>& SendObjects, std::vector<NodesContainerType>& RecvObjects,Kratos::Serializer& particleSerializer)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool TransferObjects(std::vector<ElementsContainerType>& SendObjects, std::vector<ElementsContainerType>& RecvObjects,Kratos::Serializer& particleSerializer)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    virtual bool TransferObjects(std::vector<ConditionsContainerType>& SendObjects, std::vector<ConditionsContainerType>& RecvObjects,Kratos::Serializer& particleSerializer)
    {
        /*#if defined(KRATOS_USING_MPI )
                std::cout << "WARNING: Using serial communicator with MPI defined. Use ModelPart::SetCommunicator to set its communicator to MPICommunicator" << std::endl;
        #endif*/
        return true;
    }

    ///@}
    ///@name Access
    ///@{


    ///@}
    ///@name Inquiry
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "Communicator";
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << Info();
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {
        for (IndexType i = 0; i < mLocalMeshes.size(); i++)
        {
            rOStream << "    Local Mesh " << i << " : " << std::endl;
            LocalMesh(i).PrintData(rOStream);
            rOStream << "    Ghost Mesh " << i << " : " << std::endl;
            GhostMesh(i).PrintData(rOStream);
            rOStream << "    Interface Mesh " << i << " : " << std::endl;
            InterfaceMesh(i).PrintData(rOStream);
        }
    }


    ///@}
    ///@name Friends
    ///@{


    ///@}

protected:
    ///@name Protected static Member Variables
    ///@{


    ///@}
    ///@name Protected member Variables
    ///@{

    SizeType mNumberOfColors;

    NeighbourIndicesContainerType mNeighbourIndices;

    // To store all local entities
    typename MeshType::Pointer mpLocalMesh;

    // To store all ghost entities
    typename MeshType::Pointer mpGhostMesh;

    // To store all interface entities
    typename MeshType::Pointer mpInterfaceMesh;

    // To store interfaces local entities
    MeshesContainerType mLocalMeshes;

    // To store interfaces ghost entities
    MeshesContainerType mGhostMeshes;

    // To store interfaces ghost+local entities
    MeshesContainerType mInterfaceMeshes;

    ///@}
    ///@name Protected Operators
    ///@{


    ///@}
    ///@name Protected Operations
    ///@{


    ///@}
    ///@name Protected  Access
    ///@{


    ///@}
    ///@name Protected Inquiry
    ///@{


    ///@}
    ///@name Protected LifeCycle
    ///@{


    ///@}

private:
    ///@name Static Member Variables
    ///@{


    ///@}
    ///@name Member Variables
    ///@{




    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{


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

}; // Class Communicator

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{

/// input stream function
template<class TNodeType>
inline std::istream & operator >>(std::istream& rIStream, Communicator<TNodeType>& rThis)
{
    return rIStream;
}

/// output stream function
template<class TNodeType>
inline std::ostream & operator <<(std::ostream& rOStream, const Communicator<TNodeType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

} // namespace Kratos.

#endif // KRATOS_COMMUNICATOR_H_INCLUDED  defined
