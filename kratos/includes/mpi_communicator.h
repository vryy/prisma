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

#if !defined(KRATOS_MPI_COMMUNICATOR_H_INCLUDED )
#define  KRATOS_MPI_COMMUNICATOR_H_INCLUDED

// System includes
#include <string>
#include <iostream>
#include <sstream>
#include <cstddef>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/model_part.h"
#include "mpi.h"

#define CUSTOMTIMER 1

/* Timer defines */
#ifdef CUSTOMTIMER
#include "utilities/timer.h"
#define KRATOS_TIMER_START(t) Timer::Start(t);
#define KRATOS_TIMER_STOP(t) Timer::Stop(t);
#else
#define KRATOS_TIMER_START(t)
#define KRATOS_TIMER_STOP(t)
#endif


namespace Kratos
{

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

template< class T >
inline MPI_Datatype DataTypeToMpiDataType(const T& Value);

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}
///@name Kratos Classes
///@{

/// Short class definition.

/** Detail class definition.
 */
template<class TNodeType = Node<3> >
class KRATOS_API(KRATOS_CORE) MPICommunicator : public Communicator<TNodeType>
{
public:
    ///@name  Enum's
    ///@{

    ///@}
    ///@name Type Definitions
    ///@{

    /// Pointer definition of MPICommunicator
    KRATOS_CLASS_POINTER_DEFINITION(MPICommunicator);

    typedef Communicator<TNodeType> BaseType;

    typedef typename BaseType::DataType DataType;

    typedef typename BaseType::IndexType IndexType;

    typedef typename BaseType::SizeType SizeType;

    typedef typename BaseType::NodeType NodeType;

    typedef typename BaseType::PropertiesType PropertiesType;

    typedef typename BaseType::ElementType ElementType;

    typedef typename BaseType::ConditionType ConditionType;

    typedef typename BaseType::NeighbourIndicesContainerType NeighbourIndicesContainerType;

    typedef typename BaseType::MeshType MeshType;

    typedef typename BaseType::MeshesContainerType MeshesContainerType;

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

    /** The type of nodal variables list. */
    typedef VariablesList<DataType> VariablesListType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    MPICommunicator(VariablesListType* Variables_list) : BaseType(), mpVariables_list(Variables_list), mComm(MPI_COMM_WORLD)
    {
        MyMpiDataType = DataTypeToMpiDataType(DataType());
    }

    /// Constructor with communicator
    MPICommunicator(VariablesListType* Variables_list, MPI_Comm Comm) : BaseType(), mpVariables_list(Variables_list), mComm(Comm)
    {
    }

    /// Copy constructor.
    MPICommunicator(MPICommunicator const& rOther) : BaseType(rOther)
    {
    }

    /// Destructor.
    ~MPICommunicator() override
    {
    }

    typename BaseType::Pointer Create() const override
    {
        KRATOS_TRY

        return typename BaseType::Pointer(new MPICommunicator(mpVariables_list));

        KRATOS_CATCH("");
    }

    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    MPICommunicator & operator=(MPICommunicator const& rOther)
    {
        BaseType::operator=(rOther);
        return *this;
    }

    int MyPID() const override
    {
        int rank;
        MPI_Comm_rank(mComm, &rank);
        return rank;
    }

    int TotalProcesses() const override
    {
        int nproc;
        MPI_Comm_size(mComm, &nproc);
        return nproc;
    }

    IndexType GetLastNodeId(const MeshType& rMesh) const override
    {
        IndexType lastNodeId = BaseType::GetLastNodeId(rMesh);

        unsigned long tmp = static_cast<unsigned long>(lastNodeId);
        this->MaxAll(tmp);

        return static_cast<IndexType>(tmp);
    }

    IndexType GetLastElementId(const MeshType& rMesh) const override
    {
        IndexType lastElementId = BaseType::GetLastElementId(rMesh);

        unsigned long tmp = static_cast<unsigned long>(lastElementId);
        this->MaxAll(tmp);

        return static_cast<IndexType>(tmp);
    }

    IndexType GetLastConditionId(const MeshType& rMesh) const override
    {
        IndexType lastCondId = BaseType::GetLastConditionId(rMesh);

        unsigned long tmp = static_cast<unsigned long>(lastCondId);
        this->MaxAll(tmp);

        return static_cast<IndexType>(tmp);
    }

    ///@}
    ///@name Access
    ///@{


    ///@}
    ///@name Operations
    ///@{

    void Barrier()
    {
        MPI_Barrier(mComm);
    }

    bool SumAll(int& rValue) const override
    {
        int local_value = rValue;
        MPI_Allreduce(&local_value, &rValue, 1, MPI_INT, MPI_SUM, mComm);
        return true;
    }

    bool SumAll(DataType& rValue) const override
    {
        DataType local_value = rValue;
        MPI_Allreduce(&local_value, &rValue, 1, MyMpiDataType, MPI_SUM, mComm);
        return true;
    }

    bool MinAll(int& rValue) const override
    {
        int local_value = rValue;
        MPI_Allreduce(&local_value, &rValue, 1, MPI_INT, MPI_MIN, mComm);
        return true;
    }

    bool MinAll(DataType& rValue) const override
    {
        DataType local_value = rValue;
        MPI_Allreduce(&local_value, &rValue, 1, MyMpiDataType, MPI_MIN, mComm);
        return true;
    }

    bool MaxAll(int& rValue) const override
    {
        int local_value = rValue;
        MPI_Allreduce(&local_value, &rValue, 1, MPI_INT, MPI_MAX, mComm);
        return true;
    }

    bool MaxAll(IndexType& rValue) const override
    {
        IndexType local_value = rValue;
        MPI_Datatype ThisMPI_DataType = DataTypeToMpiDataType(rValue);
        MPI_Allreduce(&local_value, &rValue, 1, ThisMPI_DataType, MPI_MAX, mComm);
        return true;
    }

#ifdef _MSC_VER
    bool MaxAll(unsigned long& rValue) const override
    {
        unsigned long local_value = rValue;
        MPI_Allreduce(&local_value, &rValue, 1, MPI_UNSIGNED_LONG, MPI_MAX, mComm);
        return true;
    }
#endif

    bool MaxAll(DataType& rValue) const override
    {
        double local_value = rValue;
        MPI_Allreduce(&local_value, &rValue, 1, MPI_DOUBLE, MPI_MAX, mComm);
        return true;
    }

    bool SynchronizeElementalIds() override
    {
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                ElementsContainerType& r_local_elements = this->LocalMesh(i_color).Elements();
                ElementsContainerType& r_ghost_elements = this->GhostMesh(i_color).Elements();

                unsigned int elemental_data_size = sizeof (std::size_t) / sizeof (int);
                unsigned int local_elements_size = r_local_elements.size();
                unsigned int ghost_elements_size = r_ghost_elements.size();
                unsigned int send_buffer_size = local_elements_size * elemental_data_size;
                unsigned int receive_buffer_size = ghost_elements_size * elemental_data_size;

                if ((local_elements_size == 0) && (ghost_elements_size == 0))
                    continue; // nothing to transfer!

                unsigned int position = 0;
                std::vector<double> send_buffer(send_buffer_size);
                std::vector<double> receive_buffer(receive_buffer_size);

                // Filling the send buffer
                for (auto i_element = r_local_elements.begin(); i_element != r_local_elements.end(); ++i_element)
                {
                    *(std::size_t*) (send_buffer.data() + position) = i_element->Id();
                    position += elemental_data_size;
                }

                MPI_Status status;

                int send_tag = i_color;
                int receive_tag = i_color;

                MPI_Sendrecv(send_buffer.data(), send_buffer_size, MPI_INT, destination, send_tag, receive_buffer.data(), receive_buffer_size, MPI_INT, destination, receive_tag,
                             mComm, &status);

                position = 0;
                for (auto i_element = r_ghost_elements.begin(); i_element != r_ghost_elements.end(); ++i_element)
                {
                    i_element->SetId(*reinterpret_cast<std::size_t*> (receive_buffer.data() + position));
                    position += elemental_data_size;
                }

                if (position > receive_buffer_size)
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;
            }

        return true;
    }

    bool SynchronizeNodalSolutionStepsData() override
    {
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                NodesContainerType& r_local_nodes = this->LocalMesh(i_color).Nodes();
                NodesContainerType& r_ghost_nodes = this->GhostMesh(i_color).Nodes();

                // Calculating send and received buffer size
                // NOTE: This part works ONLY when all nodes have the same variables list size!
                unsigned int nodal_data_size = 0;
                unsigned int local_nodes_size = r_local_nodes.size();
                unsigned int ghost_nodes_size = r_ghost_nodes.size();
                unsigned int send_buffer_size = 0;
                unsigned int receive_buffer_size = 0;

                if (local_nodes_size == 0)
                {
                    if (ghost_nodes_size == 0)
                        continue; // nothing to transfer!
                    else
                    {
                        nodal_data_size = r_ghost_nodes.begin()->SolutionStepData().TotalSize();
                        receive_buffer_size = ghost_nodes_size * nodal_data_size;
                    }
                }
                else
                {
                    nodal_data_size = r_local_nodes.begin()->SolutionStepData().TotalSize();
                    send_buffer_size = local_nodes_size * nodal_data_size;
                    if (ghost_nodes_size != 0)
                        receive_buffer_size = ghost_nodes_size * nodal_data_size;
                }

                unsigned int position = 0;
                std::vector<double> send_buffer(send_buffer_size);
                std::vector<double> receive_buffer(receive_buffer_size);

                // Filling the buffer
                for (auto i_node = r_local_nodes.begin(); i_node != r_local_nodes.end(); ++i_node)
                {
                    std::memcpy(send_buffer.data() + position, i_node->SolutionStepData().Data(), nodal_data_size * sizeof (double));
                    position += nodal_data_size;
                }

                MPI_Status status;

                if (position > send_buffer_size)
                    std::cout << rank << " Error in estimating send buffer size...." << std::endl;


                int send_tag = i_color;
                int receive_tag = i_color;


                MPI_Sendrecv(send_buffer.data(), send_buffer_size, MPI_DOUBLE, destination, send_tag, receive_buffer.data(), receive_buffer_size, MPI_DOUBLE, destination, receive_tag,
                             mComm, &status);

                // Updating nodes
                position = 0;
                for (auto i_node = this->GhostMesh(i_color).NodesBegin();
                        i_node != this->GhostMesh(i_color).NodesEnd(); i_node++)
                {
                    std::memcpy(i_node->SolutionStepData().Data(), receive_buffer.data() + position, nodal_data_size * sizeof (double));
                    position += nodal_data_size;
                }

                if (position > receive_buffer_size)
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;
            }

        return true;
    }

    bool SynchronizeDofs() override
    {
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                NodesContainerType& r_local_nodes = this->LocalMesh(i_color).Nodes();
                NodesContainerType& r_ghost_nodes = this->GhostMesh(i_color).Nodes();

                // Calculating send and received buffer size
                unsigned int send_buffer_size = 0;
                unsigned int receive_buffer_size = 0;

                for (auto i_node = r_local_nodes.begin(); i_node != r_local_nodes.end(); ++i_node)
                    send_buffer_size += i_node->GetDofs().size();

                for (auto i_node = r_ghost_nodes.begin(); i_node != r_ghost_nodes.end(); ++i_node)
                    receive_buffer_size += i_node->GetDofs().size();

                unsigned int position = 0;
                int* send_buffer = new int[send_buffer_size];
                int* receive_buffer = new int[receive_buffer_size];


                // Filling the buffer
                for (auto i_node = r_local_nodes.begin(); i_node != r_local_nodes.end(); ++i_node)
                    for (auto i_dof = i_node->GetDofs().begin(); i_dof != i_node->GetDofs().end(); i_dof++)
                    {
                        send_buffer[position++] = i_dof->EquationId();
                    }


                MPI_Status status;

                if (position > send_buffer_size)
                    std::cout << rank << " Error in estimating send buffer size...." << std::endl;


                int send_tag = i_color;
                int receive_tag = i_color;

                MPI_Sendrecv(send_buffer, send_buffer_size, MPI_INT, destination, send_tag, receive_buffer, receive_buffer_size, MPI_INT, destination, receive_tag,
                             mComm, &status);

                // Updating nodes
                position = 0;
                for (auto i_node = this->GhostMesh(i_color).NodesBegin();
                        i_node != this->GhostMesh(i_color).NodesEnd(); i_node++)
                    for (auto i_dof = i_node->GetDofs().begin(); i_dof != i_node->GetDofs().end(); i_dof++)
                        i_dof->SetEquationId(receive_buffer[position++]);

                if (position > receive_buffer_size)
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;

                delete [] send_buffer;
                delete [] receive_buffer;
            }

        return true;
    }

    bool SynchronizeVariable(Variable<int> const& ThisVariable) override
    {
        SynchronizeVariable<int,int>(ThisVariable);
        return true;
    }

    bool SynchronizeVariable(Variable<DataType> const& ThisVariable) override
    {
        SynchronizeVariable<DataType, DataType>(ThisVariable);
        return true;
    }

    bool SynchronizeVariable(Variable<array_1d<DataType, 3 > > const& ThisVariable) override
    {
        SynchronizeVariable<array_1d<DataType, 3 >, DataType >(ThisVariable);
        return true;
    }

    bool SynchronizeVariable(Variable<Vector> const& ThisVariable) override
    {
        SynchronizeVariable<Vector, DataType>(ThisVariable);
        return true;
    }

    bool SynchronizeVariable(Variable<Matrix> const& ThisVariable) override
    {
        SynchronizeVariable<Matrix, DataType>(ThisVariable);
        return true;
    }

    // This function is for test and will be changed. Pooyan.
    bool SynchronizeCurrentDataToMin(Variable<DataType> const& ThisVariable) override
    {
        SynchronizeMinThisVariable<DataType, DataType>(ThisVariable);
        return true;

    }

    bool AssembleCurrentData(Variable<int> const& ThisVariable) override
    {
        AssembleThisVariable<int, int>(ThisVariable);
        return true;
    }

    bool AssembleCurrentData(Variable<DataType> const& ThisVariable) override
    {
        AssembleThisVariable<DataType, DataType>(ThisVariable);
        return true;
    }

    bool AssembleCurrentData(Variable<array_1d<DataType, 3 > > const& ThisVariable) override
    {
        AssembleThisVariable<array_1d<DataType,3>, DataType>(ThisVariable);
        return true;
    }

    bool AssembleCurrentData(Variable<Vector> const& ThisVariable) override
    {
        AssembleThisVariable<Vector, DataType>(ThisVariable);
        return true;
    }

    bool AssembleCurrentData(Variable<Matrix> const& ThisVariable) override
    {
        AssembleThisVariable<Matrix, DataType>(ThisVariable);
        return true;
    }

    bool AssembleNonHistoricalData(Variable<int> const& ThisVariable) override
    {
        AssembleThisNonHistoricalVariable<int,int>(ThisVariable);
        return true;
    }

    bool AssembleNonHistoricalData(Variable<DataType> const& ThisVariable) override
    {
        AssembleThisNonHistoricalVariable<DataType, DataType>(ThisVariable);
        return true;
    }

    bool AssembleNonHistoricalData(Variable<array_1d<DataType, 3 > > const& ThisVariable) override
    {
        AssembleThisNonHistoricalVariable<array_1d<DataType,3>, DataType>(ThisVariable);
        return true;
    }

    bool AssembleNonHistoricalData(Variable<vector<array_1d<DataType,3> > > const& ThisVariable) override
    {
        AssembleThisNonHistoricalVariable<vector<array_1d<DataType,3> >, DataType>(ThisVariable);
        return true;
    }

    bool AssembleNonHistoricalData(Variable<Vector> const& ThisVariable) override
    {
        AssembleThisNonHistoricalVariable<Vector, DataType>(ThisVariable);
        return true;
    }

    bool AssembleNonHistoricalData(Variable<Matrix> const& ThisVariable) override
    {
        AssembleThisNonHistoricalVariable<Matrix, DataType>(ThisVariable);
        return true;
    }

    /////////////////////////////////////////////////////////////////////////////

    bool SynchronizeElementalNonHistoricalVariable(Variable<int> const& ThisVariable) override
    {
        SynchronizeElementalNonHistoricalVariable<int,int>(ThisVariable);
        return true;
    }

    bool SynchronizeElementalNonHistoricalVariable(Variable<DataType> const& ThisVariable) override
    {
        SynchronizeElementalNonHistoricalVariable<DataType, DataType>(ThisVariable);
        return true;
    }

    bool SynchronizeElementalNonHistoricalVariable(Variable<array_1d<DataType, 3 > > const& ThisVariable) override
    {
        SynchronizeElementalNonHistoricalVariable<array_1d<DataType,3>, DataType>(ThisVariable);
        return true;
    }

    bool SynchronizeElementalNonHistoricalVariable(Variable<vector<array_1d<DataType,3> > > const& ThisVariable) override
    {
        SynchronizeElementalNonHistoricalVariable<vector<array_1d<DataType,3> >, DataType>(ThisVariable);
        return true;
    }

    bool SynchronizeElementalNonHistoricalVariable(Variable<Vector> const& ThisVariable) override
    {
        SynchronizeElementalNonHistoricalVariable<Vector, DataType>(ThisVariable);
        return true;
    }

    bool SynchronizeElementalNonHistoricalVariable(Variable<Matrix> const& ThisVariable) override
    {
        SynchronizeElementalNonHistoricalVariable<Matrix, DataType>(ThisVariable);
        return true;
    }

    /////////////////////////////////////////////////////////////////////////////

    /**
     * Transfer objects from a given process to a destination process
     * @param SendObjects: list of objects to be send.      SendObjects[i] -> Objects to   process i
     * @param RecvObjects: list of objects to be received.  RecvObjects[i] -> objects from process i
     **/
    bool TransferObjects(std::vector<NodesContainerType>& SendObjects, std::vector<NodesContainerType>& RecvObjects) override
    {
        Serializer particleSerializer;
        AsyncSendAndReceiveObjects<NodesContainerType>(SendObjects,RecvObjects,particleSerializer);
        return true;
    }

    /**
    * Transfer objects from a given process to a destination process
    * @param SendObjects: list of objects to be send.      SendObjects[i] -> Objects to   process i
    * @param RecvObjects: list of objects to be received.  RecvObjects[i] -> objects from process i
    **/
    bool TransferObjects(std::vector<ElementsContainerType>& SendObjects, std::vector<ElementsContainerType>& RecvObjects) override
    {
        Serializer particleSerializer;
        AsyncSendAndReceiveObjects<ElementsContainerType>(SendObjects,RecvObjects,particleSerializer);
        return true;
    }

    /**
    * Transfer objects from a given process to a destination process
    * @param SendObjects: list of objects to be send.      SendObjects[i] -> Objects to   process i
    * @param RecvObjects: list of objects to be received.  RecvObjects[i] -> objects from process i
    **/
    bool TransferObjects(std::vector<ConditionsContainerType>& SendObjects, std::vector<ConditionsContainerType>& RecvObjects) override
    {
        Serializer particleSerializer;
        AsyncSendAndReceiveObjects<ConditionsContainerType>(SendObjects,RecvObjects,particleSerializer);
        return true;
    }

    /**
     * Transfer objects from a given process to a destination process
     * @param SendObjects: list of objects to be send.      SendObjects[i] -> Objects to   process i
     * @param RecvObjects: list of objects to be received.  RecvObjects[i] -> objects from process i
     **/
    bool TransferObjects(std::vector<NodesContainerType>& SendObjects, std::vector<NodesContainerType>& RecvObjects, Serializer& particleSerializer) override
    {
        AsyncSendAndReceiveObjects<NodesContainerType>(SendObjects,RecvObjects,particleSerializer);
        return true;
    }

    /**
    * Transfer objects from a given process to a destination process
    * @param SendObjects: list of objects to be send.      SendObjects[i] -> Objects to   process i
    * @param RecvObjects: list of objects to be received.  RecvObjects[i] -> objects from process i
    **/
    bool TransferObjects(std::vector<ElementsContainerType>& SendObjects, std::vector<ElementsContainerType>& RecvObjects, Serializer& particleSerializer) override
    {
        AsyncSendAndReceiveObjects<ElementsContainerType>(SendObjects,RecvObjects,particleSerializer);
        return true;
    }

    /**
    * Transfer objects from a given process to a destination process
    * @param SendObjects: list of objects to be send.      SendObjects[i] -> Objects to   process i
    * @param RecvObjects: list of objects to be received.  RecvObjects[i] -> objects from process i
    **/
    bool TransferObjects(std::vector<ConditionsContainerType>& SendObjects, std::vector<ConditionsContainerType>& RecvObjects, Serializer& particleSerializer) override
    {
        AsyncSendAndReceiveObjects<ConditionsContainerType>(SendObjects,RecvObjects,particleSerializer);
        return true;
    }

    /////////////////////////////////////////////////////////////////////////////

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
    std::string Info() const override
    {
        return "MPICommunicator";
    }

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << Info();
    }

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const override
    {
        for (IndexType i = 0; i < this->LocalMeshes().size(); i++)
        {
            rOStream << "    Local Mesh " << i << " : " << std::endl;
            this->LocalMesh(i).PrintData(rOStream);
            rOStream << "    Ghost Mesh " << i << " : " << std::endl;
            this->GhostMesh(i).PrintData(rOStream);
            rOStream << "    Interface Mesh " << i << " : " << std::endl;
            this->InterfaceMesh(i).PrintData(rOStream);
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

    MPI_Comm mComm;

    VariablesListType* mpVariables_list;

    /** The struct representing MPI data type. For some stupid reason, this variable cannot be marked constexpr */
    MPI_Datatype MyMpiDataType;

    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    void PrintNodesId()
    {
        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();

        int nproc;
        MPI_Comm_size(mComm, &nproc);
        int rank;
        MPI_Comm_rank(mComm, &rank);

        MPI_Barrier(mComm);
        for (int proc_id = 0; proc_id < nproc; proc_id++)
        {
            if (proc_id == rank)
            {
                for (int i_color = 0; i_color < static_cast<int>(neighbours_indices.size()); i_color++)
                {
                    if ((neighbours_indices[i_color]) >= 0)
                    {
                        NodesContainerType& r_local_nodes = this->LocalMesh(i_color).Nodes();
                        NodesContainerType& r_ghost_nodes = this->GhostMesh(i_color).Nodes();
                        std::string tag = "Local nodes in rank ";
                        PrintNodesId(r_local_nodes, tag, i_color);
                        tag = "Ghost nodes in rank ";
                        PrintNodesId(r_ghost_nodes, tag, i_color);
                        tag = "Interface nodes in rank ";
                        PrintNodesId(this->InterfaceMesh(i_color).Nodes(), tag, i_color);
                    }
                }
            }
            MPI_Barrier(mComm);
        }
    }

    template<class TNodesArrayType>
    void PrintNodesId(TNodesArrayType& rNodes, std::string Tag, int color) const
    {
        int rank;
        MPI_Comm_rank(mComm, &rank);
        std::cout << Tag << rank << " with color " << color << ":";
        for (auto i_node = rNodes.begin(); i_node != rNodes.end(); i_node++)
            std::cout << i_node->Id() << ", ";
        std::cout << std::endl;
    }

    template<class TDataType, class TSendType>
    bool AssembleThisVariable(Variable<TDataType> const& ThisVariable)
    {
        // PrintNodesId();
        /*  KRATOS_WATCH("AssembleThisVariable")
                KRATOS_WATCH(ThisVariable)*/
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();
        std::vector<TSendType*> receive_buffer(neighbours_indices.size());
        std::vector<int> receive_buffer_size(neighbours_indices.size());

        TSendType Value = TSendType();

        //first of all gather everything to the owner node
        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                NodesContainerType& r_local_nodes = this->InterfaceMesh(i_color).Nodes();
                NodesContainerType& r_ghost_nodes = this->InterfaceMesh(i_color).Nodes();

                // Calculating send and received buffer size
                // NOTE: This part can be optimized getting the offset from variables list and using pointers.
                unsigned int nodal_data_size = sizeof (TDataType) / sizeof (TSendType);
                unsigned int local_nodes_size = r_local_nodes.size();
                unsigned int ghost_nodes_size = r_ghost_nodes.size();
                unsigned int send_buffer_size = local_nodes_size * nodal_data_size;
                receive_buffer_size[i_color] = ghost_nodes_size * nodal_data_size;

                if ((local_nodes_size == 0) && (ghost_nodes_size == 0))
                    continue; // nothing to transfer!

                unsigned int position = 0;
                TSendType* send_buffer = new TSendType[send_buffer_size];
                receive_buffer[i_color] = new TSendType[receive_buffer_size[i_color]];

                // Filling the buffer
                for (auto i_node = r_local_nodes.begin(); i_node != r_local_nodes.end(); ++i_node)
                {
                    *(TDataType*) (send_buffer + position) = i_node->FastGetSolutionStepValue(ThisVariable);
                    position += nodal_data_size;
                }

                MPI_Status status;

                if (position > send_buffer_size)
                    std::cout << rank << " Error in estimating send buffer size...." << std::endl;

                int send_tag = i_color;
                int receive_tag = i_color;

                MPI_Sendrecv(send_buffer, send_buffer_size, MyMpiDataType, destination, send_tag,
                             receive_buffer[i_color], receive_buffer_size[i_color], MyMpiDataType, destination, receive_tag,
                             mComm, &status);

                delete [] send_buffer;
            }

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                // Updating nodes
                int position = 0;
                unsigned int nodal_data_size = sizeof (TDataType) / sizeof (TSendType);
                NodesContainerType& r_ghost_nodes = this->InterfaceMesh(i_color).Nodes();

                for (auto i_node = r_ghost_nodes.begin(); i_node != r_ghost_nodes.end(); ++i_node)
                {
                    i_node->FastGetSolutionStepValue(ThisVariable) += *reinterpret_cast<TDataType*> (receive_buffer[i_color] + position);
                    position += nodal_data_size;
                }

                if (position > receive_buffer_size[i_color])
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;

                delete [] receive_buffer[i_color];
            }

        //MPI_Barrier(mComm);

        //SynchronizeNodalSolutionStepsData();
        SynchronizeVariable<TDataType,TSendType>(ThisVariable);

        return true;
    }

    // this function is for test only and to be removed. Pooyan.
    template<class TDataType, class TSendType>
    bool SynchronizeMinThisVariable(Variable<TDataType> const& ThisVariable)
    {
        // PrintNodesId();
        /*  KRATOS_WATCH("AssembleThisVariable")
                KRATOS_WATCH(ThisVariable)*/
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();
        std::vector<TSendType*> receive_buffer(neighbours_indices.size());
        std::vector<int> receive_buffer_size(neighbours_indices.size());

        TSendType Value = TSendType();

        //first of all gather everything to the owner node
        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                NodesContainerType& r_local_nodes = this->InterfaceMesh(i_color).Nodes();
                NodesContainerType& r_ghost_nodes = this->InterfaceMesh(i_color).Nodes();

                // Calculating send and received buffer size
                // NOTE: This part can be optimized getting the offset from variables list and using pointers.
                unsigned int nodal_data_size = sizeof (TDataType) / sizeof (TSendType);
                unsigned int local_nodes_size = r_local_nodes.size();
                unsigned int ghost_nodes_size = r_ghost_nodes.size();
                unsigned int send_buffer_size = local_nodes_size * nodal_data_size;
                receive_buffer_size[i_color] = ghost_nodes_size * nodal_data_size;

                if ((local_nodes_size == 0) && (ghost_nodes_size == 0))
                    continue; // nothing to transfer!

                unsigned int position = 0;
                TSendType* send_buffer = new TSendType[send_buffer_size];
                receive_buffer[i_color] = new TSendType[receive_buffer_size[i_color]];

                // Filling the buffer
                for (auto i_node = r_local_nodes.begin(); i_node != r_local_nodes.end(); ++i_node)
                {
                    *(TDataType*) (send_buffer + position) = i_node->FastGetSolutionStepValue(ThisVariable);
                    position += nodal_data_size;
                }

                MPI_Status status;

                if (position > send_buffer_size)
                    std::cout << rank << " Error in estimating send buffer size...." << std::endl;

                int send_tag = i_color;
                int receive_tag = i_color;

                MPI_Sendrecv(send_buffer, send_buffer_size, MyMpiDataType, destination, send_tag,
                             receive_buffer[i_color], receive_buffer_size[i_color], MyMpiDataType, destination, receive_tag,
                             mComm, &status);

                delete [] send_buffer;
            }

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                // Updating nodes
                int position = 0;
                unsigned int nodal_data_size = sizeof (TDataType) / sizeof (TSendType);
                NodesContainerType& r_ghost_nodes = this->InterfaceMesh(i_color).Nodes();

                for (auto i_node = r_ghost_nodes.begin(); i_node != r_ghost_nodes.end(); ++i_node)
                {
                    TDataType& data = i_node->FastGetSolutionStepValue(ThisVariable);
                    data = std::min(data, *reinterpret_cast<TDataType*> (receive_buffer[i_color] + position));
                    position += nodal_data_size;
                }

                if (position > receive_buffer_size[i_color])
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;

                delete [] receive_buffer[i_color];
            }

        //MPI_Barrier(mComm);


        //SynchronizeNodalSolutionStepsData();
        SynchronizeVariable<TDataType,TSendType>(ThisVariable);

        return true;
    }

    template<class TDataType, class TSendType>
    bool SynchronizeVariable(Variable<TDataType> const& ThisVariable)
    {
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();

        TSendType Value = TSendType();

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                NodesContainerType& r_local_nodes = this->LocalMesh(i_color).Nodes();
                NodesContainerType& r_ghost_nodes = this->GhostMesh(i_color).Nodes();

                unsigned int nodal_data_size = sizeof (TDataType) / sizeof (TSendType);
                unsigned int local_nodes_size = r_local_nodes.size();
                unsigned int ghost_nodes_size = r_ghost_nodes.size();
                unsigned int send_buffer_size = local_nodes_size * nodal_data_size;
                unsigned int receive_buffer_size = ghost_nodes_size * nodal_data_size;

                if ((local_nodes_size == 0) && (ghost_nodes_size == 0))
                    continue; // nothing to transfer!

                unsigned int position = 0;
                TSendType* send_buffer = new TSendType[send_buffer_size];
                TSendType* receive_buffer = new TSendType[receive_buffer_size];

                // Filling the send buffer
                for (auto i_node = r_local_nodes.begin(); i_node != r_local_nodes.end(); ++i_node)
                {
                    *(TDataType*) (send_buffer + position) = i_node->FastGetSolutionStepValue(ThisVariable);
                    position += nodal_data_size;
                }

                MPI_Status status;

                int send_tag = i_color;
                int receive_tag = i_color;

                MPI_Sendrecv(send_buffer, send_buffer_size, MyMpiDataType, destination, send_tag, receive_buffer, receive_buffer_size, MyMpiDataType, destination, receive_tag,
                             mComm, &status);

                position = 0;
                for (auto i_node = r_ghost_nodes.begin(); i_node != r_ghost_nodes.end(); ++i_node)
                {
                    i_node->FastGetSolutionStepValue(ThisVariable) = *reinterpret_cast<TDataType*> (receive_buffer + position);
                    position += nodal_data_size;
                }

                if (position > receive_buffer_size)
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;

                delete [] send_buffer;
                delete [] receive_buffer;
            }

        return true;
    }


    template< class TDataType, class TSendType >
    bool AssembleThisNonHistoricalVariable(Variable<TDataType> const& ThisVariable)
    {
        // PrintNodesId();
        /*  KRATOS_WATCH("AssembleThisVariable")
                KRATOS_WATCH(ThisVariable)*/
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();
        std::vector<TSendType*> receive_buffer(neighbours_indices.size());
        std::vector<int> receive_buffer_size(neighbours_indices.size());

        TSendType Value = TSendType();

        //first of all gather everything to the owner node
        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                NodesContainerType& r_local_nodes = this->InterfaceMesh(i_color).Nodes();
                NodesContainerType& r_ghost_nodes = this->InterfaceMesh(i_color).Nodes();

                // Calculating send and received buffer size
                // NOTE: This part can be optimized getting the offset from variables list and using pointers.
                unsigned int nodal_data_size = sizeof (TDataType) / sizeof (TSendType);
                unsigned int local_nodes_size = r_local_nodes.size();
                unsigned int ghost_nodes_size = r_ghost_nodes.size();
                unsigned int send_buffer_size = local_nodes_size * nodal_data_size;
                receive_buffer_size[i_color] = ghost_nodes_size * nodal_data_size;

                if ((local_nodes_size == 0) && (ghost_nodes_size == 0))
                    continue; // nothing to transfer!

                unsigned int position = 0;
                TSendType* send_buffer = new TSendType[send_buffer_size];
                receive_buffer[i_color] = new TSendType[receive_buffer_size[i_color]];

                // Filling the buffer
                for (auto i_node = r_local_nodes.begin(); i_node != r_local_nodes.end(); ++i_node)
                {
                    *(TDataType*) (send_buffer + position) = i_node->GetValue(ThisVariable);
                    position += nodal_data_size;
                }

                MPI_Status status;

                if (position > send_buffer_size)
                    std::cout << rank << " Error in estimating send buffer size...." << std::endl;

                int send_tag = i_color;
                int receive_tag = i_color;

                MPI_Sendrecv(send_buffer, send_buffer_size, MyMpiDataType, destination, send_tag,
                             receive_buffer[i_color], receive_buffer_size[i_color], MyMpiDataType, destination, receive_tag,
                             mComm, &status);

                delete [] send_buffer;
            }

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                // Updating nodes
                int position = 0;
                unsigned int nodal_data_size = sizeof (TDataType) / sizeof (TSendType);
                NodesContainerType& r_ghost_nodes = this->InterfaceMesh(i_color).Nodes();

                for (auto i_node = r_ghost_nodes.begin(); i_node != r_ghost_nodes.end(); ++i_node)
                {
                    i_node->GetValue(ThisVariable) += *reinterpret_cast<TDataType*> (receive_buffer[i_color] + position);
                    position += nodal_data_size;
                }

                if (position > receive_buffer_size[i_color])
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;

                delete [] receive_buffer[i_color];
            }

        SynchronizeNonHistoricalVariable<TDataType,TSendType>(ThisVariable);

        return true;
    }

    template< class TDataType, class TSendType >
    bool SynchronizeNonHistoricalVariable(Variable<TDataType> const& ThisVariable)
    {
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();

        TSendType Value = TSendType();

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                NodesContainerType& r_local_nodes = this->LocalMesh(i_color).Nodes();
                NodesContainerType& r_ghost_nodes = this->GhostMesh(i_color).Nodes();

                unsigned int nodal_data_size = sizeof (TDataType) / sizeof (TSendType);
                unsigned int local_nodes_size = r_local_nodes.size();
                unsigned int ghost_nodes_size = r_ghost_nodes.size();
                unsigned int send_buffer_size = local_nodes_size * nodal_data_size;
                unsigned int receive_buffer_size = ghost_nodes_size * nodal_data_size;

                if ((local_nodes_size == 0) && (ghost_nodes_size == 0))
                    continue; // nothing to transfer!

                unsigned int position = 0;
                TSendType* send_buffer = new TSendType[send_buffer_size];
                TSendType* receive_buffer = new TSendType[receive_buffer_size];

                // Filling the send buffer
                for (auto i_node = r_local_nodes.begin(); i_node != r_local_nodes.end(); ++i_node)
                {
                    *(TDataType*) (send_buffer + position) = i_node->GetValue(ThisVariable);
                    position += nodal_data_size;
                }

                MPI_Status status;

                int send_tag = i_color;
                int receive_tag = i_color;

                MPI_Sendrecv(send_buffer, send_buffer_size, MyMpiDataType, destination, send_tag, receive_buffer, receive_buffer_size, MyMpiDataType, destination, receive_tag,
                             mComm, &status);

                position = 0;
                for (auto i_node = r_ghost_nodes.begin(); i_node != r_ghost_nodes.end(); ++i_node)
                {
                    i_node->GetValue(ThisVariable) = *reinterpret_cast<TDataType*> (receive_buffer + position);
                    position += nodal_data_size;
                }

                if (position > receive_buffer_size)
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;

                delete [] send_buffer;
                delete [] receive_buffer;
            }

        return true;
    }

    template< class TDataType, class TSendType >
    bool SynchronizeElementalNonHistoricalVariable(Variable<TDataType> const& ThisVariable)
    {
        int rank;
        MPI_Comm_rank(mComm, &rank);

        int destination = 0;

        NeighbourIndicesContainerType& neighbours_indices = this->NeighbourIndices();

        TSendType Value = TSendType();

        for (unsigned int i_color = 0; i_color < neighbours_indices.size(); i_color++)
            if ((destination = neighbours_indices[i_color]) >= 0)
            {
                ElementsContainerType& r_local_elements = this->LocalMesh(i_color).Elements();
                ElementsContainerType& r_ghost_elements = this->GhostMesh(i_color).Elements();

                unsigned int elemental_data_size = sizeof (TDataType) / sizeof (TSendType);
                unsigned int local_elements_size = r_local_elements.size();
                unsigned int ghost_elements_size = r_ghost_elements.size();
                unsigned int send_buffer_size = local_elements_size * elemental_data_size;
                unsigned int receive_buffer_size = ghost_elements_size * elemental_data_size;

                if ((local_elements_size == 0) && (ghost_elements_size == 0))
                    continue; // nothing to transfer!

                unsigned int position = 0;
                std::vector<DataType> send_buffer(send_buffer_size);
                std::vector<DataType> receive_buffer(receive_buffer_size);

                // Filling the send buffer
                for (auto i_element = r_local_elements.begin(); i_element != r_local_elements.end(); ++i_element)
                {
                    *(TDataType*) (send_buffer.data() + position) = i_element->GetValue(ThisVariable);
                    position += elemental_data_size;
                }

                MPI_Status status;

                int send_tag = i_color;
                int receive_tag = i_color;

                MPI_Sendrecv(send_buffer.data(), send_buffer_size, MyMpiDataType, destination, send_tag, receive_buffer.data(), receive_buffer_size, MyMpiDataType, destination, receive_tag,
                             mComm, &status);

                position = 0;
                for (auto i_element = r_ghost_elements.begin(); i_element != r_ghost_elements.end(); ++i_element)
                {
                    i_element->GetValue(ThisVariable) = *reinterpret_cast<TDataType*> (receive_buffer.data() + position);
                    position += elemental_data_size;
                }

                if (position > receive_buffer_size)
                    std::cout << rank << " Error in estimating receive buffer size...." << std::endl;
            }

        return true;
    }

    template<class TObjectType>
    bool AsyncSendAndReceiveObjects(std::vector<TObjectType>& SendObjects, std::vector<TObjectType>& RecvObjects, Serializer& externParticleSerializer)
    {
        int mpi_rank;
        int mpi_size;

        MPI_Comm_rank(mComm, &mpi_rank);
        MPI_Comm_size(mComm, &mpi_size);

        std::vector<int> msgSendSize(mpi_size);
        std::vector<int> msgRecvSize(mpi_size);

        char ** message = new char * [mpi_size];
        char ** mpi_send_buffer = new char * [mpi_size];

        for(int i = 0; i < mpi_size; i++)
        {
            msgSendSize[i] = 0;
            msgRecvSize[i] = 0;
        }

        for(int i = 0; i < mpi_size; i++)
        {
            if(mpi_rank != i)
            {
                Serializer particleSerializer;

                particleSerializer.save("VariableList",mpVariables_list);
                particleSerializer.save("ObjectList",SendObjects[i].GetContainer());

                std::stringstream * stream = (std::stringstream *)particleSerializer.pGetBuffer();
                const std::string & stream_str = stream->str();
                const char * cstr = stream_str.c_str();

                msgSendSize[i] = sizeof(char) * (stream_str.size()+1);
                mpi_send_buffer[i] = (char *)malloc(msgSendSize[i]);
                memcpy(mpi_send_buffer[i], cstr, msgSendSize[i]);
            }
        }

        MPI_Alltoall(msgSendSize.data(), 1, MPI_INT, msgRecvSize.data(), 1, MPI_INT, mComm);

        int NumberOfCommunicationEvents      = 0;
        int NumberOfCommunicationEventsIndex = 0;

        for(int j = 0; j < mpi_size; j++)
        {
            if(j != mpi_rank && msgRecvSize[j]) NumberOfCommunicationEvents++;
            if(j != mpi_rank && msgSendSize[j]) NumberOfCommunicationEvents++;
        }

        std::vector<MPI_Request> reqs(NumberOfCommunicationEvents);
        std::vector<MPI_Status> stats(NumberOfCommunicationEvents);

        //Set up all receive and send events
        for(int i = 0; i < mpi_size; i++)
        {
            if(i != mpi_rank && msgRecvSize[i])
            {
                message[i] = (char *)malloc(sizeof(char) * msgRecvSize[i]);

                MPI_Irecv(message[i], msgRecvSize[i], MPI_CHAR, i, 0, mComm, &reqs[NumberOfCommunicationEventsIndex++]);
            }

            if(i != mpi_rank && msgSendSize[i])
            {
                MPI_Isend(mpi_send_buffer[i], msgSendSize[i], MPI_CHAR, i, 0, mComm, &reqs[NumberOfCommunicationEventsIndex++]);
            }
        }

        //wait untill all communications finish
        int err = MPI_Waitall(NumberOfCommunicationEvents, reqs.data(), stats.data());

        if(err != MPI_SUCCESS)
            KRATOS_ERROR << "Error in mpi_communicator";

        MPI_Barrier(mComm);

        for(int i = 0; i < mpi_size; i++)
        {
            if (i != mpi_rank && msgRecvSize[i])
            {
                Serializer particleSerializer;
                std::stringstream * serializer_buffer;

                serializer_buffer = (std::stringstream *)particleSerializer.pGetBuffer();
                serializer_buffer->write(message[i], msgRecvSize[i]);

                VariablesListType* tmp_mpVariables_list = nullptr;

                particleSerializer.load("VariableList", tmp_mpVariables_list);

                if(tmp_mpVariables_list != nullptr)
                    delete tmp_mpVariables_list;
                tmp_mpVariables_list = mpVariables_list;

                particleSerializer.load("ObjectList", RecvObjects[i].GetContainer());
            }

            MPI_Barrier(mComm);
        }

        // Free buffers
        for(int i = 0; i < mpi_size; i++)
        {
            if(msgRecvSize[i])
                free(message[i]);

            if(msgSendSize[i])
                free(mpi_send_buffer[i]);
        }

        delete [] message;
        delete [] mpi_send_buffer;

        return true;
    }

    //       friend class boost::serialization::access;

    //       template<class TArchive>
    //    void serialize(TArchive & ThisArchive, const unsigned int ThisVersion)
    //    {
    // /*         ThisArchive & mName & mBufferSize & mCurrentIndex; */
    //    }

    //       void RemoveSolutionStepData(IndexType SolutionStepIndex, MeshType& ThisMesh)
    //  {
    //    for(NodeIterator i_node = ThisMesh.NodesBegin() ; i_node != ThisMesh.NodesEnd() ; ++i_node)
    //      i_node->RemoveSolutionStepNodalData(SolutionStepIndex);
    //  }

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

}; // Class MPICommunicator

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

template<> inline MPI_Datatype DataTypeToMpiDataType<short>(const short& Value) { return MPI_SHORT; }
template<> inline MPI_Datatype DataTypeToMpiDataType<int>(const int& Value) { return MPI_INT; }
template<> inline MPI_Datatype DataTypeToMpiDataType<unsigned int>(const unsigned int& Value) { return MPI_UNSIGNED; }
template<> inline MPI_Datatype DataTypeToMpiDataType<long>(const long& Value) { return MPI_LONG; }
template<> inline MPI_Datatype DataTypeToMpiDataType<long long>(const long long& Value) { return MPI_LONG_LONG; }
template<> inline MPI_Datatype DataTypeToMpiDataType<unsigned long>(const unsigned long& Value) { return MPI_UNSIGNED_LONG; }
#ifdef _MSC_VER
template<> inline MPI_Datatype DataTypeToMpiDataType<unsigned long long>(const unsigned long long& Value) { return MPI_UNSIGNED_LONG_LONG; }
#endif
template<> inline MPI_Datatype DataTypeToMpiDataType<float>(const float& Value) { return MPI_FLOAT; }
template<> inline MPI_Datatype DataTypeToMpiDataType<double>(const double& Value) { return MPI_DOUBLE; }
template<> inline MPI_Datatype DataTypeToMpiDataType<long double>(const long double& Value) { return MPI_LONG_DOUBLE; }

} // namespace Kratos.

#endif // KRATOS_MPI_COMMUNICATOR_H_INCLUDED  defined
