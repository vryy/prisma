//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//

#if !defined(KRATOS_MODEL_PART_IO_H_INCLUDED )
#define  KRATOS_MODEL_PART_IO_H_INCLUDED

// System includes
#include <string>
#include <fstream>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/io.h"
#include "containers/flags.h"

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

/// An IO class for reading and writing a modelpart
/** This class reads and writes all modelpart data including the meshes.
*/
template<class TModelPartType = ModelPart>
class KRATOS_API(KRATOS_CORE) ModelPartIO : public IO<TModelPartType>
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of ModelPartIO
    KRATOS_CLASS_POINTER_DEFINITION(ModelPartIO);

    typedef IO<TModelPartType> BaseType;

    typedef typename BaseType::NodeType NodeType;

    typedef typename BaseType::IndexType IndexType;

    typedef typename BaseType::SizeType SizeType;

    typedef typename BaseType::ValueType ValueType;

    typedef typename BaseType::VectorType VectorType;

    typedef typename BaseType::CoordinateType CoordinateType;

    typedef typename BaseType::DataType DataType;

    typedef typename BaseType::ElementType ElementType;

    typedef typename BaseType::ConditionType ConditionType;

    typedef typename BaseType::MeshType MeshType;

    typedef typename BaseType::ModelPartType ModelPartType;

    typedef typename BaseType::NodesContainerType NodesContainerType;

    typedef typename BaseType::PropertiesContainerType PropertiesContainerType;

    typedef typename BaseType::ElementsContainerType ElementsContainerType;

    typedef typename BaseType::ConditionsContainerType ConditionsContainerType;

    typedef typename BaseType::ConnectivitiesContainerType ConnectivitiesContainerType;

    typedef typename BaseType::GraphType GraphType;

    typedef typename BaseType::PartitionIndicesType PartitionIndicesType;

    typedef typename BaseType::PartitionIndicesContainerType PartitionIndicesContainerType;

    typedef std::vector<std::ofstream*> OutputFilesContainerType;

    typedef typename ModelPartType::CommunicatorType CommunicatorType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Constructor with  filenames.
    ModelPartIO(std::string const& Filename, const Flags Options = BaseType::READ|BaseType::NOT_IGNORE_VARIABLES_ERROR);


    /// Constructor with filenames.
//       ModelPartIO(std::string const& InputFilename, std::string const& OutputFilename)
//  : mNumberOfLines(0), mInput(std::ifstream(InputFilename.c_str())), mOutput(std::ofstream(OutputFilename.c_str()))
//       {
//       }


    /// Destructor.
    ~ModelPartIO() override;


    ///@}
    ///@name Operators
    ///@{


    ///@}
    ///@name Operations
    ///@{

    bool ReadNode(NodeType& rThisNode) override;

    bool ReadNodes(NodesContainerType& rThisNodes) override;

    SizeType ReadNodesNumber() override;

    void WriteNodes(NodesContainerType const& rThisNodes) override;

    void ReadProperties(Properties& rThisProperties) override;

    void ReadProperties(PropertiesContainerType& rThisProperties) override;

    virtual void WriteProperties(PropertiesContainerType& rThisProperties);

    void ReadElement(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, typename ElementType::Pointer& pThisElements) override;

    void ReadElements(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, ElementsContainerType& rThisElements) override;

    SizeType ReadElementsConnectivities(ConnectivitiesContainerType& rElementsConnectivities) override;

    void WriteElements(ElementsContainerType const& rThisElements) override;

    void ReadConditions(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, ConditionsContainerType& rThisConditions) override;

    SizeType ReadConditionsConnectivities(ConnectivitiesContainerType& rConditionsConnectivities) override;

    virtual void WriteConditions(ConditionsContainerType const& rThisConditions);

    void ReadInitialValues(ModelPartType& rThisModelPart) override;

    void ReadConditionalScalarVariableData(std::string variable_name, std::vector<SizeType>& rConditionIndices, std::vector<int>& rConditionalDataValues) override;

    void ReadConditionalScalarVariableData(std::string variable_name, std::vector<SizeType>& rConditionIndices, std::vector<DataType>& rConditionalDataValues) override;

    void ReadMesh(MeshType& rThisMesh) override;

    virtual void WriteMesh(MeshType& rThisMesh);

    void ReadModelPart(ModelPartType& rThisModelPart) override;

    virtual void WriteModelPart(ModelPartType & rThisModelPart);


    /// Read the input file and create the nodal connectivities graph, stored in CSR format.
    /**
     * This function produces input for Metis' nodal graph partitioning algorithms.
     * The nodal graph is stored as a (compressed) matrix where index (i,j) is non-zero if
     * there is an edge in the mesh joining nodes i and j (note that nodes are numbered from zero here,
     * to make integration with Metis simpler).
     * @param NodeIndices After call, will point to C array of size NumNodes+1 containing the
     * first CSR array: entries related to node k are stored between positions (*NodeIndices)[k]
     * and (*NodeIndices)[k+1] of *NodeConnectivities.
     * @param NodeConnectivities After call, will point to a C array of size (*NodeIndices)[NumNodes].
     * entries between (*NodeIndices)[k] and (*NodeIndices)[k+1] are a list of all nodes connected
     * to node k (counting from 0).
     * @return Number of nodes.
     */
    SizeType ReadNodalGraph(int **NodeIndices, int **NodeConnectivities) override;

    void DivideInputToPartitions(SizeType NumberOfPartitions, GraphType const& DomainsColoredGraph,
                                 PartitionIndicesType const& NodesPartitions,
                                 PartitionIndicesType const& ElementsPartitions,
                                 PartitionIndicesType const& ConditionsPartitions,
                                 PartitionIndicesContainerType const& NodesAllPartitions,
                                 PartitionIndicesContainerType const& ElementsAllPartitions,
                                 PartitionIndicesContainerType const& ConditionsAllPartitions) override;

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
        return "ModelPartIO";
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

    virtual SizeType ReorderedNodeId(SizeType NodeId);
    virtual SizeType ReorderedElementId(SizeType ElementId);
    virtual SizeType ReorderedConditionId(SizeType ConditionId);

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

protected:
    ///@name Static Member Variables
    ///@{


    ///@}
    ///@name Member Variables
    ///@{

    SizeType mNumberOfLines;
    std::string mBaseFilename;
    std::string mFilename;
    std::fstream mFile;
    Flags mOptions;

    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    std::string& ReadBlockName(std::string& rBlockName);

    void SkipBlock(std::string const& BlockName);

    bool CheckEndBlock(std::string const& BlockName, std::string& rWord);

    void ReadModelPartDataBlock(ModelPartType& rModelPart);

    template<class TablesContainerType>
    void ReadTableBlock(TablesContainerType& rTables);

    void ReadTableBlock(typename ModelPartType::TablesContainerType& rTables);

    void ReadNodesBlock(NodesContainerType& rThisNodes);

    void ReadNodesBlock(ModelPartType& rModelPart);

    SizeType CountNodesInBlock();

    void ReadPropertiesBlock(PropertiesContainerType& rThisProperties);

    void ReadElementsBlock(ModelPartType& rModelPart);

    void ReadElementsBlock(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, ElementsContainerType& rThisElements);

    void ReadConditionsBlock(ModelPartType& rModelPart);

    void ReadConditionsBlock(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, ConditionsContainerType& rThisConditions);

    void ReadNodalDataBlock(ModelPartType& rThisModelPart);

    template<class TVariableType>
    void ReadNodalDofVariableData(NodesContainerType& rThisNodes, const TVariableType& rVariable);

    void ReadNodalFlags(NodesContainerType& rThisNodes, Flags const& rFlags);

    template<class TVariableType>
    void ReadNodalScalarVariableData(NodesContainerType& rThisNodes, const TVariableType& rVariable);

    template<class TVariableType, class TDataType>
    void ReadNodalVectorialVariableData(NodesContainerType& rThisNodes, const TVariableType& rVariable, TDataType Dummy);

    void ReadElementalDataBlock(ElementsContainerType& rThisElements);

    template<class TVariableType>
    void ReadElementalScalarVariableData(ElementsContainerType& rThisElements, const TVariableType& rVariable);

    template<class TVariableType, class TDataType>
    void ReadElementalVectorialVariableData(ElementsContainerType& rThisElements, const TVariableType& rVariable, TDataType Dummy);
    void ReadConditionalDataBlock(ConditionsContainerType& rThisConditions);

    template<class TVariableType>
    void ReadConditionalScalarVariableData(ConditionsContainerType& rThisConditions, const TVariableType& rVariable);

    template<class TVariableType, class TDataType>
    void ReadConditionalVectorialVariableData(ConditionsContainerType& rThisConditions, const TVariableType& rVariable, TDataType Dummy);

    template<class TDataType>
    void ReadConditionalScalarVariableDataImpl(std::string variable_name, std::vector<SizeType>& rConditionIndices, std::vector<TDataType>& rConditionalDataValues);

    SizeType ReadElementsConnectivitiesBlock(ConnectivitiesContainerType& rThisConnectivities);

    SizeType ReadConditionsConnectivitiesBlock(ConnectivitiesContainerType& rThisConnectivities);

    void FillNodalConnectivitiesFromElementBlock(ConnectivitiesContainerType& rNodalConnectivities);

    void FillNodalConnectivitiesFromConditionBlock(ConnectivitiesContainerType& rNodalConnectivities);

    void ReadCommunicatorDataBlock(CommunicatorType& rThisCommunicator, NodesContainerType& rThisNodes);

    void ReadCommunicatorLocalNodesBlock(CommunicatorType& rThisCommunicator, NodesContainerType& rThisNodes);

    void ReadCommunicatorGhostNodesBlock(CommunicatorType& rThisCommunicator, NodesContainerType& rThisNodes);

    void ReadMeshBlock(ModelPartType& rModelPart);

    void ReadMeshDataBlock(MeshType& rMesh);

    void ReadMeshNodesBlock(ModelPartType& rModelPart, MeshType& rMesh);

    void ReadMeshElementsBlock(ModelPartType& rModelPart, MeshType& rMesh);

    void ReadMeshConditionsBlock(ModelPartType& rModelPart, MeshType& rMesh);

    void ReadMeshPropertiesBlock(ModelPartType& rModelPart, MeshType& rMesh);

    void ReadSubModelPartBlock(ModelPartType& rMainModelPart, ModelPartType& rParentModelPart);

    void ReadSubModelPartTablesBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart);

    void ReadSubModelPartPropertiesBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart);

    void ReadSubModelPartNodesBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart);

    void ReadSubModelPartElementsBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart);

    void ReadSubModelPartConditionsBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart);

    void DivideModelPartDataBlock(OutputFilesContainerType& OutputFiles);

    void DivideTableBlock(OutputFilesContainerType& OutputFiles);

    void DividePropertiesBlock(OutputFilesContainerType& OutputFiles);

    void DivideNodesBlock(OutputFilesContainerType& OutputFiles,
                          PartitionIndicesContainerType const& NodesAllPartitions);

    void DivideElementsBlock(OutputFilesContainerType& OutputFiles,
                             PartitionIndicesContainerType const& ElementsAllPartitions);

    void DivideConditionsBlock(OutputFilesContainerType& OutputFiles,
                               PartitionIndicesContainerType const& ConditionsAllPartitions);

    void DivideNodalDataBlock(OutputFilesContainerType& OutputFiles,
                              PartitionIndicesContainerType const& NodesAllPartitions);

    void DivideDofVariableData(OutputFilesContainerType& OutputFiles,
                               PartitionIndicesContainerType const& NodesAllPartitions);

    void DivideVectorialVariableData(OutputFilesContainerType& OutputFiles,
                                     PartitionIndicesContainerType const& EntitiesPartitions,
                                     std::string BlockName);

    void DivideMatrixVariableData(OutputFilesContainerType& OutputFiles,
                                  PartitionIndicesContainerType const& EntitiesPartitions,
                                  std::string BlockName);

    void DivideElementalDataBlock(OutputFilesContainerType& OutputFiles,
                                  PartitionIndicesContainerType const& ElementsAllPartitions);

    void DivideScalarVariableData(OutputFilesContainerType& OutputFiles,
                                  PartitionIndicesContainerType const& EntitiesPartitions,
                                  std::string BlockName);

    void DivideConditionalDataBlock(OutputFilesContainerType& OutputFiles,
                                    PartitionIndicesContainerType const& ConditionsAllPartitions);

    void DivideMeshBlock(OutputFilesContainerType& OutputFiles,
                                         PartitionIndicesContainerType const& NodesAllPartitions,
                                         PartitionIndicesContainerType const& ElementsAllPartitions,
                                         PartitionIndicesContainerType const& ConditionsAllPartitions);

    void DivideSubModelPartBlock(OutputFilesContainerType& OutputFiles,
                                 PartitionIndicesContainerType const& NodesAllPartitions,
                                 PartitionIndicesContainerType const& ElementsAllPartitions,
                                 PartitionIndicesContainerType const& ConditionsAllPartitions);

    void DivideMeshDataBlock(OutputFilesContainerType& OutputFiles);


    void DivideMeshNodesBlock(OutputFilesContainerType& OutputFiles,
                              PartitionIndicesContainerType const& NodesAllPartitions);


    void DivideMeshElementsBlock(OutputFilesContainerType& OutputFiles,
                                 PartitionIndicesContainerType const& ElementsAllPartitions);

    void DivideMeshConditionsBlock(OutputFilesContainerType& OutputFiles,
                                   PartitionIndicesContainerType const& ConditionsAllPartitions);

    void WritePartitionIndices(OutputFilesContainerType& OutputFiles, PartitionIndicesType const&  NodesPartitions, PartitionIndicesContainerType const& NodesAllPartitions);

    void WriteCommunicatorData(OutputFilesContainerType& OutputFiles, SizeType NumberOfPartitions, GraphType const& DomainsColoredGraph,
                               PartitionIndicesType const& NodesPartitions,
                               PartitionIndicesType const& ElementsPartitions,
                               PartitionIndicesType const& ConditionsPartitions,
                               PartitionIndicesContainerType const& NodesAllPartitions,
                               PartitionIndicesContainerType const& ElementsAllPartitions,
                               PartitionIndicesContainerType const& ConditionsAllPartitions);

    void WriteCommunicatorLocalNodes(OutputFilesContainerType& OutputFiles, SizeType NumberOfPartitions, PartitionIndicesType const& NodesPartitions, PartitionIndicesContainerType const& NodesAllPartitions);

    void WriteInAllFiles(OutputFilesContainerType& OutputFiles, std::string const& ThisWord);

    template<class TContainerType, class TKeyType>
    typename TContainerType::iterator FindKey(TContainerType& ThisContainer, const TKeyType ThisKey, const std::string& ComponentName) const
    {
        auto i_result = ThisContainer.find(ThisKey);
        if(i_result == ThisContainer.end())
        {
            KRATOS_ERROR << ComponentName << " #" << ThisKey << " is not found."
                         << " [Line " << mNumberOfLines << " ]";
        }

        return i_result;
    }

    // Basically it starts to read the character sequence until reaching a
    // "(" and then goes until corresponding ")" which means the vector or
    // matrix value is completely read. It can be used to read any kind of
    // vector or matrix with operator >> defined and writtern in following
    // format for a vector: [size] ( value1, value2,...., valueN )
    // format for a matrix: [size1,size2] ( )( )...( ) //look props read
    template<class TValueType>
    TValueType& ReadVectorialValue(TValueType& rValue)
    {
        std::stringstream value;

        char c = SkipWhiteSpaces();
        while((c != '(') && !mFile.eof())
        {
            value << c;
            c = GetCharacter();
        }
        int open_parantesis = 1;
        while((open_parantesis != 0) && !mFile.eof())
        {
            value << c;
            c = GetCharacter();
            if(c == '(')
                open_parantesis++;
            if(c == ')')
                open_parantesis--;
        }
        value << c; // adding the final parantesis

        value >>  rValue;

        return rValue;
    }

    template<class TValueType>
    TValueType& ExtractValue(const std::string& rWord, TValueType& rValue) const
    {
        std::stringstream value(rWord);

        value >> rValue;

        return rValue;
    }

    // TODO specialize ExtractValue for complex number, the current form only supports "(x,y)"

    ModelPartIO& ReadWord(std::string& Word);

    ModelPartIO& ReadBlock(std::string& Block, std::string const& BlockName);

    char SkipWhiteSpaces();

    bool IsWhiteSpace(char C) const;

    char GetCharacter();

    bool CheckStatement(std::string const& rStatement, std::string const& rGivenWord) const;

    void ResetInput();

    ///@}
    ///@name Private  Access
    ///@{


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{

    /// Assignment operator.
    ModelPartIO& operator=(ModelPartIO const& rOther);

    /// Copy constructor.
    ModelPartIO(ModelPartIO const& rOther);

    ///@}

}; // Class ModelPartIO

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

}  // namespace Kratos.

#endif // KRATOS_MODEL_PART_IO_H_INCLUDED  defined
