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

// Project includes
#include "includes/model_part_io.h"
#include "utilities/timer.h"

namespace Kratos
{
    /// Constructor with  filenames.
    template<class TModelPartType>
    ModelPartIO<TModelPartType>::ModelPartIO(std::string const& Filename, const Flags Options )
        : mNumberOfLines(1)
        , mBaseFilename(Filename)
        , mFilename(Filename + ".mdpa")
        , mOptions(Options)
    {
        if (mOptions.Is(BaseType::READ))
        {
            mFile.open(mFilename.c_str(), std::fstream::in);
            if(!(mFile.is_open()))
                KRATOS_ERROR << "Error opening input file " << mFilename;
        }
        else if (mOptions.Is(BaseType::APPEND))
        {
            mFile.open(mFilename.c_str(), std::fstream::in|std::fstream::app);
            if(!(mFile.is_open()))
                KRATOS_ERROR << "Error opening input file " << mFilename;
        }
        else if(mOptions.Is(BaseType::WRITE))
        {
            mFile.open(mFilename.c_str(), std::fstream::out);
            if(!(mFile.is_open()))
                KRATOS_ERROR << "Error opening output file " << mFilename;
        }
        else // if none of the READ, WRITE or APPEND are defined we will take READ as defualt.
        {
            mFile.open(mFilename.c_str(), std::fstream::in);
            if(!(mFile.is_open()))
                KRATOS_ERROR << "Error opening input file " << mFilename;
        }

        Timer::SetOutputFile(Filename + ".time");
    }

    /// Destructor.
    template<class TModelPartType>
    ModelPartIO<TModelPartType>::~ModelPartIO()
    {
        if(mFile.is_open())
            mFile.close();
    }

    ///@}
    ///@name Operators
    ///@{


    ///@}
    ///@name Operations
    ///@{

    template<class TModelPartType>
    bool ModelPartIO<TModelPartType>::ReadNode(NodeType& rThisNode)
    {
        KRATOS_ERROR << "Calling base class member. Please check the definition of derived class.";
    }

    template<class TModelPartType>
    bool ModelPartIO<TModelPartType>::ReadNodes(NodesContainerType& rThisNodes)
    {
        KRATOS_TRY
        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "Nodes")
                ReadNodesBlock(rThisNodes);
            else
                SkipBlock(word);
        }

        return true;
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReadNodesNumber()
    {
        KRATOS_TRY;

        ResetInput();
        std::string word;
        SizeType num_nodes = 0;
        while(true)
        {
            ReadWord(word);
            if (mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "Nodes")
                num_nodes += CountNodesInBlock();
            else
                SkipBlock(word);
        }

        return num_nodes;

        KRATOS_CATCH("");
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteNodes(NodesContainerType const& rThisNodes)
    {
        mFile << "Begin Nodes" << std::endl;
        for(typename NodesContainerType::const_iterator i_node = rThisNodes.begin() ; i_node != rThisNodes.end() ; i_node++)
            mFile << i_node->Id() << "\t" << i_node->X()  << "\t" << i_node->Y() << "\t" << i_node->Z() << std::endl;
        mFile << "End Nodes" << std::endl;
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadProperties(Properties& rThisProperties)
    {
        KRATOS_ERROR << "Calling base class member. Please check the definition of derived class";
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadProperties(PropertiesContainerType& rThisProperties)
    {
        KRATOS_TRY
        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "Properties")
                ReadPropertiesBlock(rThisProperties);
            else
                SkipBlock(word);
        }
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteProperties(PropertiesContainerType& rThisProperties)
    {
        for(typename PropertiesContainerType::const_iterator i_properties = rThisProperties.begin() ; i_properties != rThisProperties.end() ; i_properties++)
        {
            mFile << "Begin Properties " << i_properties->Id() << std::endl;
            i_properties->PrintData(mFile);
            mFile << std::endl;
            mFile << "End Properties" << std::endl;
        }
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadElement(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, typename ElementType::Pointer& pThisElements)
    {
        KRATOS_ERROR << "Calling base class member. Please check the definition of derived class";
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadElements(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, ElementsContainerType& rThisElements)
    {
        KRATOS_TRY
        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "Elements")
                ReadElementsBlock(rThisNodes,rThisProperties,rThisElements);
            else
                SkipBlock(word);
        }
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReadElementsConnectivities(ConnectivitiesContainerType& rElementsConnectivities)
    {
        KRATOS_TRY

        SizeType number_of_elements = 0;
        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "Elements")
                number_of_elements += ReadElementsConnectivitiesBlock(rElementsConnectivities);
            else
                SkipBlock(word);
        }
        return number_of_elements;

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteElements(ElementsContainerType const& rThisElements)
    {
        KRATOS_ERROR << "This method has not been implemented yet!";
        mFile << "Begin Elements" << std::endl;
        mFile << "End Elements" << std::endl;
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadConditions(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, ConditionsContainerType& rThisConditions)
    {
        KRATOS_TRY
        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "Conditions")
                ReadConditionsBlock(rThisNodes,rThisProperties,rThisConditions);
            else
                SkipBlock(word);
        }
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReadConditionsConnectivities(ConnectivitiesContainerType& rConditionsConnectivities)
    {
        KRATOS_TRY

        SizeType number_of_conditions = 0;
        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "Conditions")
                number_of_conditions += ReadConditionsConnectivitiesBlock(rConditionsConnectivities);
            else
                SkipBlock(word);
        }

        return number_of_conditions;

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteConditions(ConditionsContainerType const& rThisConditions)
    {
        KRATOS_ERROR << "This method has not been implemented yet!";
        mFile << "Begin Conditions" << std::endl;
        mFile << "End Conditions" << std::endl;
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadInitialValues(ModelPartType& rThisModelPart)
    {
        KRATOS_TRY

        ElementsContainerType& rThisElements = rThisModelPart.Elements();
        ConditionsContainerType& rThisConditions = rThisModelPart.Conditions();


        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "NodalData")
                ReadNodalDataBlock(rThisModelPart);
            else if(word == "ElementalData")
                ReadElementalDataBlock(rThisElements);
            else if(word == "ConditionalData")
                ReadConditionalDataBlock(rThisConditions);
            else
                SkipBlock(word);
        }

        KRATOS_CATCH("")
    }

//       void ReadGeometries(NodesContainerType& rThisNodes, GeometriesContainerType& rResults);

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadConditionalScalarVariableData(std::string variable_name, std::vector<SizeType>& rConditionIndices, std::vector<int>& rConditionalDataValues)
    {
        ReadConditionalScalarVariableDataImpl(variable_name, rConditionIndices, rConditionalDataValues);
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadConditionalScalarVariableData(std::string variable_name, std::vector<SizeType>& rConditionIndices, std::vector<DataType>& rConditionalDataValues)
    {
        ReadConditionalScalarVariableDataImpl(variable_name, rConditionIndices, rConditionalDataValues);
    }

    template<class TModelPartType>
    template<class TDataType>
    void ModelPartIO<TModelPartType>::ReadConditionalScalarVariableDataImpl(std::string variable_name, std::vector<SizeType>& rConditionIndices, std::vector<TDataType>& rConditionalDataValues)
    {
        KRATOS_TRY

        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if (word == "ConditionalData")
            {
                std::string read_variable_name;
                ReadWord(read_variable_name);

                if(read_variable_name == variable_name)
                {
                    if(KratosComponents<Variable<TDataType> >::Has(variable_name))
                    {
                        SizeType id;
                        TDataType conditional_value;

                        std::string value;

                        while(!mFile.eof())
                        {
                            ReadWord(value); // reading id
                            if(CheckEndBlock("ConditionalData", value))
                                break;

                            ExtractValue(value, id);

                            // reading nodal_value
                            ReadWord(value);
                            ExtractValue(value, conditional_value);

                            rConditionIndices.push_back(ReorderedConditionId(id));
                            rConditionalDataValues.push_back(conditional_value);
                        }
                    }
                    else
                    {
                        KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                                     << " [Line " << mNumberOfLines << " ]";
                    }
                }
                else
                    SkipBlock(word);
            }
            else
                SkipBlock(word);
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadMesh(MeshType & rThisMesh)
    {
        KRATOS_ERROR << "ModelPartIO does not implement this method.";
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteMesh(MeshType & rThisMesh)
    {
        WriteProperties(rThisMesh.Properties());
        WriteNodes(rThisMesh.Nodes());
        WriteElements(rThisMesh.Elements());
        WriteConditions(rThisMesh.Conditions());
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadModelPart(ModelPartType & rThisModelPart)
    {
        KRATOS_TRY

        Timer::Start("Reading Input");

        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "ModelPartData")
                ReadModelPartDataBlock(rThisModelPart);
            else if(word == "Table")
                ReadTableBlock(rThisModelPart.Tables());
            else if(word == "Properties")
                ReadPropertiesBlock(rThisModelPart.rProperties());
            else if(word == "Nodes")
                ReadNodesBlock(rThisModelPart);
            else if(word == "Elements")
                ReadElementsBlock(rThisModelPart);
            else if(word == "Conditions")
                ReadConditionsBlock(rThisModelPart);
            else if(word == "NodalData")
                ReadNodalDataBlock(rThisModelPart);
            else if(word == "ElementalData")
                ReadElementalDataBlock(rThisModelPart.Elements());
            else if (word == "ConditionalData")
                ReadConditionalDataBlock(rThisModelPart.Conditions());
            else if(word == "CommunicatorData")
            {
                ReadCommunicatorDataBlock(rThisModelPart.GetCommunicator(), rThisModelPart.Nodes());
                //Adding the elements and conditions to the communicator
                rThisModelPart.GetCommunicator().LocalMesh().Elements() = rThisModelPart.Elements();
                rThisModelPart.GetCommunicator().LocalMesh().Conditions() = rThisModelPart.Conditions();
            }
            else if (word == "Mesh")
                ReadMeshBlock(rThisModelPart);
            else if (word == "SubModelPart")
                ReadSubModelPartBlock(rThisModelPart, rThisModelPart);
        }
        std::cout << "  [Total Lines Read : " << mNumberOfLines<<"]";
        std::cout << std::endl;
        Timer::Stop("Reading Input");
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteModelPart(ModelPartType & rThisModelPart)
    {
        KRATOS_ERROR << "This method has not been implemented yet!";
        mFile << "Begin ModelPartData" << std::endl;
        mFile << "End ModelPartData" << std::endl;
        WriteMesh(rThisModelPart.GetMesh());
    }

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
    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReadNodalGraph(int **NodeIndices, int **NodeConnectivities)
    {
        // 1. Define an auxiliary vector of vectors
        ConnectivitiesContainerType aux_connectivities(0);

        // 2. Fill the auxiliary vector by reading elemental and conditional connectivities
        ResetInput();
        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if (word == "Elements")
                FillNodalConnectivitiesFromElementBlock(aux_connectivities);
            else if (word == "Conditions")
                FillNodalConnectivitiesFromConditionBlock(aux_connectivities);
            else
                SkipBlock(word);
        }

        // Check that node indices are consecutive
        unsigned int n = 0;
        for (typename ConnectivitiesContainerType::iterator inode = aux_connectivities.begin(); inode != aux_connectivities.end(); inode++)
        {
            n++;
            if (inode->size() == 0)
            {
                KRATOS_ERROR << "Nodes are not consecutively numbered. Node " << n << " was not found in mdpa file." << std::endl;
            }
        }

        // 3. Sort each entry in the auxiliary connectivities vector, remove duplicates
        SizeType num_entries = 0;
        for (typename ConnectivitiesContainerType::iterator it = aux_connectivities.begin(); it != aux_connectivities.end(); ++it)
        {
            std::sort(it->begin(),it->end());
            typename std::vector<SizeType>::iterator unique_end = std::unique(it->begin(),it->end());
            it->resize(unique_end - it->begin());
            num_entries += it->size();
        }

        // 4. Write connectivity data in CSR format
        SizeType num_nodes = aux_connectivities.size();
        *NodeIndices = new int[num_nodes+1];
        (*NodeIndices)[0] = 0;
        *NodeConnectivities = new int[num_entries];

        SizeType i = 0;
        SizeType aux_index = 0;

        for (typename ConnectivitiesContainerType::iterator it = aux_connectivities.begin(); it != aux_connectivities.end(); ++it)
        {
            for (typename std::vector<SizeType>::iterator entry_it = it->begin(); entry_it != it->end(); entry_it++)
                (*NodeConnectivities)[aux_index++] = (*entry_it - 1); // substract 1 to make Ids start from 0
            (*NodeIndices)[++i] = aux_index;
        }

        return num_nodes;
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideInputToPartitions(SizeType NumberOfPartitions, GraphType const& DomainsColoredGraph,
                                         PartitionIndicesType const& NodesPartitions,
                                         PartitionIndicesType const& ElementsPartitions,
                                         PartitionIndicesType const& ConditionsPartitions,
                                         PartitionIndicesContainerType const& NodesAllPartitions,
                                         PartitionIndicesContainerType const& ElementsAllPartitions,
                                         PartitionIndicesContainerType const& ConditionsAllPartitions)
    {
        KRATOS_TRY
        ResetInput();
        std::string word;
        OutputFilesContainerType output_files;

        for(SizeType i = 0 ; i < NumberOfPartitions ; i++)
        {
            std::stringstream buffer;
            buffer << mBaseFilename << "_" << i << ".mdpa";
            std::ofstream* p_ofstream = new std::ofstream(buffer.str().c_str());
            if(!(*p_ofstream))
                KRATOS_ERROR << "Error opening output file " << buffer.str();

            output_files.push_back(p_ofstream);
        }

        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            ReadBlockName(word);
            if(word == "ModelPartData")
                DivideModelPartDataBlock(output_files);
            else if(word == "Table")
                DivideTableBlock(output_files);
            else if(word == "Properties")
                DividePropertiesBlock(output_files);
            else if(word == "Nodes")
                DivideNodesBlock(output_files, NodesAllPartitions);
            else if(word == "Elements")
                DivideElementsBlock(output_files, ElementsAllPartitions);
            else if(word == "Conditions")
                DivideConditionsBlock(output_files, ConditionsAllPartitions);
            else if(word == "NodalData")
                DivideNodalDataBlock(output_files, NodesAllPartitions);
            else if(word == "ElementalData")
                DivideElementalDataBlock(output_files, ElementsAllPartitions);
            else if(word == "ConditionalData")
                DivideConditionalDataBlock(output_files, ConditionsAllPartitions);
            else if (word == "Mesh")
                DivideMeshBlock(output_files, NodesAllPartitions, ElementsAllPartitions, ConditionsAllPartitions);
            else if (word == "SubModelPart")
                DivideSubModelPartBlock(output_files, NodesAllPartitions, ElementsAllPartitions, ConditionsAllPartitions);

        }

        WritePartitionIndices(output_files, NodesPartitions, NodesAllPartitions);

        WriteCommunicatorData(output_files, NumberOfPartitions, DomainsColoredGraph, NodesPartitions, ElementsPartitions, ConditionsPartitions, NodesAllPartitions, ElementsAllPartitions, ConditionsAllPartitions);
        std::cout << "  [Total Lines Read : " << mNumberOfLines<<"]";
        std::cout << std::endl;

        for(SizeType i = 0 ; i < NumberOfPartitions ; i++)
            delete output_files[i];
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    std::string& ModelPartIO<TModelPartType>::ReadBlockName(std::string& rBlockName)
    {
        KRATOS_TRY

        CheckStatement("Begin", rBlockName);
        ReadWord(rBlockName);

        return rBlockName;

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::SkipBlock(std::string const& BlockName)
    {
        KRATOS_TRY

        std::string word;

        while(!mFile.eof())
        {
            ReadWord(word);
            if(word == "End")
            {
                ReadWord(word);
                if(word == BlockName)
                    break;
            }

        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    bool ModelPartIO<TModelPartType>::CheckEndBlock(std::string const& BlockName, std::string& rWord)
    {
        if(rWord == "End")
        {
            ReadWord(rWord);
            CheckStatement(BlockName, rWord);
            return true;
        }

        return false;
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadModelPartDataBlock(ModelPartType& rModelPart)
    {
        KRATOS_TRY

        std::string variable_name;

        while(!mFile.eof())
        {
            ReadWord(variable_name);
            if(CheckEndBlock("ModelPartData", variable_name))
                break;
            if(KratosComponents<Variable<ValueType> >::Has(variable_name))
            {
                std::string value;
                ValueType temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                rModelPart[KratosComponents<Variable<ValueType> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<DataType> >::Has(variable_name))
            {
                std::string value;
                DataType temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                rModelPart[KratosComponents<Variable<DataType> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<bool> >::Has(variable_name))
            {
                std::string value;
                bool temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                rModelPart[KratosComponents<Variable<bool> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<int> >::Has(variable_name))
            {
                std::string value;
                int temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                rModelPart[KratosComponents<Variable<int> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<array_1d<ValueType, 3> > >::Has(variable_name))
            {
                Vector temp_vector; // defining a Vector because for array_1d the operator >> is not defined yet!
                ReadVectorialValue(temp_vector);
                rModelPart[KratosComponents<Variable<array_1d<ValueType, 3> > >::Get(variable_name)] = temp_vector;
            }
            else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
            {
                VectorType temp_vector; // defining a Vector because for array_1d the operator >> is not defined yet!
                ReadVectorialValue(temp_vector);
                rModelPart[KratosComponents<Variable<array_1d<DataType, 3> > >::Get(variable_name)] = temp_vector;
            }
            else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
            {
                ReadVectorialValue(rModelPart[KratosComponents<Variable<Matrix> >::Get(variable_name)]);
            }
            else
            {
                KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                             << " [Line " << mNumberOfLines << " ]";
            }
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    template<class TablesContainerType>
    void ModelPartIO<TModelPartType>::ReadTableBlock(TablesContainerType& rTables)
    {
        KRATOS_TRY

        typedef typename TablesContainerType::TableType TableType;

        TableType temp_table;

        //SizeType table_id;
        std::string word;

        std::string variable_name;
        ReadWord(variable_name);

        if(!KratosComponents<VariableData>::Has(variable_name))
        {
            KRATOS_ERROR << variable_name << " is not a valid argument variable!!! Table only accepts " << Kratos::DataTypeToString<DataType>::Get() << " arguments." << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }

        VariableData const& r_x_variable = KratosComponents<VariableData>::Get(variable_name);

        ReadWord(variable_name);

        if(!KratosComponents<VariableData>::Has(variable_name))
        {
            KRATOS_ERROR << variable_name << " is not a valid value variable!!! Table only accepts " << Kratos::DataTypeToString<DataType>::Get() << " values." << std::endl
                         << " [Line " << mNumberOfLines << " ]";

        }
        VariableData const& r_y_variable = KratosComponents<VariableData>::Get(variable_name);

        while(!mFile.eof())
        {
            typename TableType::argument_type x;
            typename TableType::result_type y;
            ReadWord(word);
            if(CheckEndBlock("Table", word))
                break;

            ExtractValue(word, x);
            ReadWord(word);
            ExtractValue(word, y);

            temp_table.insert(x, y);
        }

        rTables.SetTable(r_x_variable, r_y_variable, temp_table);

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadTableBlock(typename ModelPartType::TablesContainerType& rTables)
    {
        KRATOS_TRY

        typename ModelPartType::TableType temp_table;

        SizeType table_id;
        std::string word;

        ReadWord(word);
        ExtractValue(word, table_id);

        std::string variable_name;

        ReadWord(variable_name);

        //if(!KratosComponents<Variable<double> >::Has(variable_name))
        //{
        //    std::stringstream buffer;
        //    buffer << variable_name << " is not a valid argument variable!!! Table only accepts double arguments." << std::endl;
        //    buffer << " [Line " << mNumberOfLines << " ]";
        //    KRATOS_ERROR << buffer.str();

        //}

        ReadWord(variable_name);

        //if(!KratosComponents<Variable<double> >::Has(variable_name))
        //{
        //    std::stringstream buffer;
        //    buffer << variable_name << " is not a valid value variable!!! Table only accepts double values." << std::endl;
        //    buffer << " [Line " << mNumberOfLines << " ]";
        //    KRATOS_ERROR << buffer.str();

        //}

        while(!mFile.eof())
        {
            ValueType x;
            DataType y;
            ReadWord(word);
            if(CheckEndBlock("Table", word))
                break;

            ExtractValue(word, x);
            ReadWord(word);
            ExtractValue(word, y);

            temp_table.insert(x, y);
        }

        rTables.insert(table_id, temp_table);

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadNodesBlock(NodesContainerType& rThisNodes)
    {
        KRATOS_TRY
//         KRATOS_ERROR << "this function shall be removed ReadNodesBlock(NodesContainerType& rThisNodes)","")

        NodeType temp_node;
        SizeType temp_id;

        std::string word;

        SizeType number_of_nodes_read = 0;

        std::cout << "  [Reading Nodes    : ";

        while(!mFile.eof())
        {
            ReadWord(word);
            if(CheckEndBlock("Nodes", word))
                break;

            ExtractValue(word, temp_id);
            temp_node.SetId(ReorderedNodeId(temp_id));
            ReadWord(word);
            ExtractValue(word, temp_node.X());
            ReadWord(word);
            ExtractValue(word, temp_node.Y());
            ReadWord(word);
            ExtractValue(word, temp_node.Z());

            temp_node.X0() = temp_node.X();
            temp_node.Y0() = temp_node.Y();
            temp_node.Z0() = temp_node.Z();


            rThisNodes.push_back(temp_node);
            number_of_nodes_read++;
        }
        std::cout << number_of_nodes_read << " nodes read]" << std::endl;

        unsigned int numer_of_nodes_read = rThisNodes.size();
        rThisNodes.Unique();
        if(rThisNodes.size() != numer_of_nodes_read)
            std::cout << "attention! we read " << numer_of_nodes_read << " but there are only " << rThisNodes.size() << " non repeated nodes" << std::endl;

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadNodesBlock(ModelPartType& rModelPart)
    {
        KRATOS_TRY
  /*
  NodeType temp_node;
        SizeType temp_id;

        // Giving model part's variables list to the node
        temp_node.SetSolutionStepVariablesList(&rModelPart.GetNodalSolutionStepVariablesList());

        //set buffer size
        temp_node.SetBufferSize(rModelPart.GetBufferSize());


        std::string word;

        SizeType number_of_nodes_read = 0;

        std::cout << "  [Reading Nodes    : ";

        while(!mFile.eof())
        {
            ReadWord(word);
            if(CheckEndBlock("Nodes", word))
                break;

            ExtractValue(word, temp_id);
            temp_node.SetId(ReorderedNodeId(temp_id));
            ReadWord(word);
            ExtractValue(word, temp_node.X());
            ReadWord(word);
            ExtractValue(word, temp_node.Y());
            ReadWord(word);
            ExtractValue(word, temp_node.Z());

            temp_node.X0() = temp_node.X();
            temp_node.Y0() = temp_node.Y();
            temp_node.Z0() = temp_node.Z();


            rModelPart.Nodes().push_back(temp_node);
            number_of_nodes_read++;
        }
        std::cout << number_of_nodes_read << " nodes read]" << std::endl;

        unsigned int numer_of_nodes_read = rModelPart.Nodes().size();
        rModelPart.Nodes().Unique();
        if(rModelPart.Nodes().size() != numer_of_nodes_read)
            std::cout << "attention! we read " << numer_of_nodes_read << " but there are only " << rModelPart.Nodes().size() << " non repeated nodes" << std::endl;
*/
        SizeType id;
        CoordinateType x, y, z;

        std::string word;

        SizeType number_of_nodes_read = 0;

        typedef std::map< unsigned int, array_1d<CoordinateType, 3> > map_type;
        map_type read_coordinates;

        std::cout << "  [Reading Nodes    : ";

        while(!mFile.eof())
        {
            ReadWord(word);
            if(CheckEndBlock("Nodes", word))
                break;

            ExtractValue(word, id);
            ReadWord(word);
            ExtractValue(word, x);
            ReadWord(word);
            ExtractValue(word, y);
            ReadWord(word);
            ExtractValue(word, z);

            array_1d<CoordinateType, 3> coords;
            coords[0] = x;
            coords[1] = y;
            coords[2] = z;
            read_coordinates[id] = coords;
            number_of_nodes_read++;
        }
        std::cout << number_of_nodes_read << " nodes read]" << std::endl;

        for(typename map_type::const_iterator it = read_coordinates.begin(); it!=read_coordinates.end(); ++it)
        {
            const unsigned int node_id = it->first;
            const auto& coords = it->second;
            rModelPart.CreateNewNode(node_id, coords[0], coords[1], coords[2]);
        }
        if(rModelPart.Nodes().size() != number_of_nodes_read)
            std::cout << "attention! we read " << number_of_nodes_read << " but there are only " << rModelPart.Nodes().size() << " non repeated nodes" << std::endl;

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::CountNodesInBlock()
    {
        KRATOS_TRY;

        std::vector<SizeType> found_ids;

        SizeType temp_id;

        std::string word;

        SizeType number_of_nodes_read = 0;

    //std::cout << "  [Reading Nodes    : ";

        while(!mFile.eof())
        {
            ReadWord(word);
            if(CheckEndBlock("Nodes", word))
                break;

            ExtractValue(word, temp_id);
            found_ids.push_back(temp_id);

            ReadWord(word); // skip X coordinate
            ReadWord(word); // skip Y
            ReadWord(word); // skip Z

            number_of_nodes_read++;
        }
        //std::cout << number_of_nodes_read << " nodes read]" << std::endl;

        // Error check: look for duplicate nodes
        std::sort(found_ids.begin(),found_ids.end());
        typename std::vector<SizeType>::iterator unique_end = std::unique(found_ids.begin(),found_ids.end());
        SizeType number_of_unique_nodes = std::distance(found_ids.begin(),unique_end);

        if(number_of_unique_nodes != number_of_nodes_read)
            std::cout << "attention! we read " << number_of_nodes_read << " but there are only " << number_of_unique_nodes << " non repeated nodes" << std::endl;

        return number_of_nodes_read;

        KRATOS_CATCH("");
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadPropertiesBlock(PropertiesContainerType& rThisProperties)
    {
        KRATOS_TRY

        Properties temp_properties;

        std::string word;
        std::string variable_name;

        SizeType temp_properties_id;

        ReadWord(word);
        ExtractValue(word, temp_properties_id);
        temp_properties.SetId(temp_properties_id);

        while(!mFile.eof())
        {
            ReadWord(variable_name);
            if(CheckEndBlock("Properties", variable_name))
                break;

            if(variable_name == "Begin") // here we have some nested block.
            {
                ReadBlockName(variable_name);
                if(variable_name == "Table") // At this moment the only supported nested block is a table
                    ReadTableBlock(temp_properties);
            }
            else if(KratosComponents<Variable<std::string> >::Has(variable_name))
            {
                std::string value;
                std::string  temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<std::string> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<ValueType> >::Has(variable_name))
            {
                std::string value;
                ValueType temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<ValueType> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<DataType> >::Has(variable_name))
            {
                std::string value;
                DataType temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<DataType> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<int> >::Has(variable_name))
            {
                std::string value;
                int temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<int> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<bool> >::Has(variable_name))
            {
                std::string value;
                bool temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<bool> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<array_1d<ValueType, 3> > >::Has(variable_name))
            {
                Vector temp_vector; // defining a Vector because for array_1d the operator >> is not defined yet!
                ReadVectorialValue(temp_vector);
                temp_properties[KratosComponents<Variable<array_1d<ValueType, 3> > >::Get(variable_name)] = temp_vector;
            }
            else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
            {
                VectorType temp_vector; // defining a Vector because for array_1d the operator >> is not defined yet!
                ReadVectorialValue(temp_vector);
                temp_properties[KratosComponents<Variable<array_1d<DataType, 3> > >::Get(variable_name)] = temp_vector;
            }
            else if(KratosComponents<Variable<Vector> >::Has(variable_name))
            {
                ReadVectorialValue(temp_properties[KratosComponents<Variable<Vector> >::Get(variable_name)]);
            }
            else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
            {
                ReadVectorialValue(temp_properties[KratosComponents<Variable<Matrix> >::Get(variable_name)]);
            }
            else
            {
                KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                             << " [Line " << mNumberOfLines << " ]";
            }
        }

        rThisProperties.push_back(temp_properties);

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadElementsBlock(ModelPartType& rModelPart)
    {
        ReadElementsBlock(rModelPart.Nodes(), rModelPart.rProperties(), rModelPart.Elements());
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadElementsBlock(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, ElementsContainerType& rThisElements)
    {
        KRATOS_TRY

        SizeType id;
        SizeType properties_id;
        SizeType node_id;
        SizeType number_of_read_elements = 0;

        std::string word;
        std::string element_name;

        ReadWord(element_name);
        std::cout << "  [Reading Elements : ";

        if(!KratosComponents<ElementType>::Has(element_name))
        {
            KRATOS_ERROR << "Element " << element_name << " is not registered in Kratos,"
                         << " or is incompatible with " << ModelPartTypeToString<TModelPartType>::Get()
                         << ". Please check the spelling of the element name and see if the application which containing it, is registered corectly."
                         << " [Line " << mNumberOfLines << " ]";
            return;
        }

        ElementType const& r_clone_element = KratosComponents<ElementType>::Get(element_name);
        SizeType number_of_nodes = r_clone_element.GetGeometry().size();
        typename ElementType::NodesArrayType temp_element_nodes;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the element id or End
            if(CheckEndBlock("Elements", word))
                break;

            ExtractValue(word,id);
            ReadWord(word); // Reading the properties id;
            ExtractValue(word, properties_id);
            Properties::Pointer p_temp_properties = *(FindKey(rThisProperties, properties_id, "Properties").base());
            temp_element_nodes.clear();
            for(SizeType i = 0 ; i < number_of_nodes ; i++)
            {
                ReadWord(word); // Reading the node id;
                ExtractValue(word, node_id);
                temp_element_nodes.push_back( *(FindKey(rThisNodes, ReorderedNodeId(node_id), "Node").base()));
            }

            rThisElements.push_back(r_clone_element.Create(ReorderedElementId(id), temp_element_nodes, p_temp_properties));
            number_of_read_elements++;

        }
        std::cout << number_of_read_elements << " elements read] [Type: " <<element_name << "]" << std::endl;
        rThisElements.Unique();

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadConditionsBlock(ModelPartType& rModelPart)
    {
        ReadConditionsBlock(rModelPart.Nodes(), rModelPart.rProperties(), rModelPart.Conditions());
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadConditionsBlock(NodesContainerType& rThisNodes, PropertiesContainerType& rThisProperties, ConditionsContainerType& rThisConditions)
    {
        KRATOS_TRY

        SizeType id;
        SizeType properties_id;
        SizeType node_id;
        SizeType number_of_read_conditions = 0;


        std::string word;
        std::string condition_name;

        ReadWord(condition_name);
        std::cout << "  [Reading Conditions : ";

        if(!KratosComponents<ConditionType>::Has(condition_name))
        {
            KRATOS_ERROR << "Condition " << condition_name << " is not registered in Kratos,"
                         << " or is incompatible with " << ModelPartTypeToString<TModelPartType>::Get()
                         << ". Please check the spelling of the condition name and see if the application containing it is registered corectly."
                         << " [Line " << mNumberOfLines << " ]";
            return;
        }

        ConditionType const& r_clone_condition = KratosComponents<ConditionType>::Get(condition_name);
        SizeType number_of_nodes = r_clone_condition.GetGeometry().size();
        typename ConditionType::NodesArrayType temp_condition_nodes;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the condition id or End
            if(CheckEndBlock("Conditions", word))
                break;

            ExtractValue(word,id);
            ReadWord(word); // Reading the properties id;
            ExtractValue(word, properties_id);
            Properties::Pointer p_temp_properties = *(FindKey(rThisProperties, properties_id, "Properties").base());
            temp_condition_nodes.clear();
            for(SizeType i = 0 ; i < number_of_nodes ; i++)
            {
                ReadWord(word); // Reading the node id;
                ExtractValue(word, node_id);
                temp_condition_nodes.push_back( *(FindKey(rThisNodes, ReorderedNodeId(node_id), "Node").base()));
            }

            rThisConditions.push_back(r_clone_condition.Create(ReorderedConditionId(id), temp_condition_nodes, p_temp_properties));
            number_of_read_conditions++;
        }
        std::cout << number_of_read_conditions << " conditions read] [Type: " << condition_name << "]" << std::endl;
        rThisConditions.Unique();

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadNodalDataBlock(ModelPartType& rThisModelPart)
    {
        KRATOS_TRY

        NodesContainerType& rThisNodes = rThisModelPart.Nodes();

        typedef VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > array_1d_component_type;

        std::string variable_name;

        ReadWord(variable_name);

        VariablesList r_modelpart_nodal_variables_list = rThisModelPart.GetNodalSolutionStepVariablesList();

        if(KratosComponents<Flags >::Has(variable_name))
        {
            ReadNodalFlags(rThisNodes, static_cast<Flags const& >(KratosComponents<Flags >::Get(variable_name)));
        }
        else if(KratosComponents<Variable<int> >::Has(variable_name))
        {
            bool has_been_added = r_modelpart_nodal_variables_list.Has(KratosComponents<Variable<int> >::Get(variable_name)) ;
            if( !has_been_added && mOptions.Is(BaseType::IGNORE_VARIABLES_ERROR) ) {
                std::cout<<std::endl<<"WARNING: Skipping NodalData block. Variable "<<variable_name<<" has not been added to ModelPartType '"<<rThisModelPart.Name()<<"'"<<std::endl<<std::endl;
                SkipBlock("NodalData");
            }
            else if (!has_been_added)
            {
                KRATOS_ERROR << "The nodal solution step container does not have variable " << variable_name;
            }
            else
            {
                ReadNodalScalarVariableData(rThisNodes, static_cast<Variable<int> const& >(KratosComponents<Variable<int> >::Get(variable_name)));
            }
        }
        else if(KratosComponents<Variable<DataType> >::Has(variable_name))
        {
            bool has_been_added = r_modelpart_nodal_variables_list.Has(KratosComponents<Variable<DataType> >::Get(variable_name)) ;
            if( !has_been_added && mOptions.Is(BaseType::IGNORE_VARIABLES_ERROR) ) {
                std::cout<<std::endl<<"WARNING: Skipping NodalData block. Variable "<<variable_name<<" has not been added to ModelPartType '"<<rThisModelPart.Name()<<"'"<<std::endl<<std::endl;
                SkipBlock("NodalData");
            }
            else if (!has_been_added)
            {
                KRATOS_ERROR << "The nodal solution step container does not have variable " << variable_name;
            }
            else
            {
                ReadNodalDofVariableData(rThisNodes, static_cast<Variable<DataType> const& >(KratosComponents<Variable<DataType> >::Get(variable_name)));
            }
        }
        else if(KratosComponents<array_1d_component_type>::Has(variable_name))
        {
            ReadNodalDofVariableData(rThisNodes, static_cast<array_1d_component_type const& >(KratosComponents<array_1d_component_type>::Get(variable_name)));
        }
        else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
        {
            bool has_been_added = r_modelpart_nodal_variables_list.Has(KratosComponents<Variable<array_1d<DataType, 3> > >::Get(variable_name)) ;
            if( !has_been_added && mOptions.Is(BaseType::IGNORE_VARIABLES_ERROR) ) {
                std::cout<<std::endl<<"WARNING: Skipping NodalData block. Variable "<<variable_name<<" has not been added to ModelPartType '"<<rThisModelPart.Name()<<"'"<<std::endl<<std::endl;
            }
            else if (!has_been_added)
            {
                KRATOS_ERROR << "The nodal solution step container does not have variable " << variable_name;
            }
            else
            {
                ReadNodalVectorialVariableData(rThisNodes, static_cast<Variable<array_1d<DataType, 3> > const& >(KratosComponents<Variable<array_1d<DataType, 3> > >::Get(variable_name)), Vector(3));
            }
        }
        else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
        {
            ReadNodalVectorialVariableData(rThisNodes, static_cast<Variable<Matrix > const& >(KratosComponents<Variable<Matrix> >::Get(variable_name)), Matrix(3,3));
        }
        else if(KratosComponents<Variable<Vector> >::Has(variable_name))
        {
            ReadNodalVectorialVariableData(rThisNodes, static_cast<Variable<Vector > const& >(KratosComponents<Variable<Vector> >::Get(variable_name)), Vector(3));
        }
        else if(KratosComponents<VariableData>::Has(variable_name))
        {
            KRATOS_ERROR << variable_name << " is not supported to be read by this IO or the type of variable is not registered correctly" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }
        else
        {
            KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    template<class TVariableType>
    void ModelPartIO<TModelPartType>::ReadNodalDofVariableData(NodesContainerType& rThisNodes, const TVariableType& rVariable)
    {
        KRATOS_TRY

        SizeType id;
        bool is_fixed;
        DataType nodal_value;

        std::string value;


        while(!mFile.eof())
        {
            ReadWord(value); // reading id
            if(CheckEndBlock("NodalData", value))
                break;

            ExtractValue(value, id);
            typename NodesContainerType::iterator i_node = FindKey(rThisNodes, ReorderedNodeId(id), "Node");

            // reading is_fixed
            ReadWord(value);
            ExtractValue(value, is_fixed);
            if(is_fixed)
                i_node->Fix(rVariable);

            // reading nodal_value
            ReadWord(value);
            ExtractValue(value, nodal_value);

            i_node->GetSolutionStepValue(rVariable, 0) =  nodal_value;
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadNodalFlags(NodesContainerType& rThisNodes, Flags const& rFlags)
    {

        KRATOS_TRY

        SizeType id;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(value); // reading id
            if(CheckEndBlock("NodalData", value))
                break;

            ExtractValue(value, id);

            FindKey(rThisNodes, ReorderedNodeId(id), "Node")->Set(rFlags);
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    template<class TVariableType>
    void ModelPartIO<TModelPartType>::ReadNodalScalarVariableData(NodesContainerType& rThisNodes, const TVariableType& rVariable)
    {
        KRATOS_TRY

        SizeType id;
        bool is_fixed;
        typename TVariableType::Type nodal_value;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(value); // reading id
            if(CheckEndBlock("NodalData", value))
                break;

            ExtractValue(value, id);

            // reading is_fixed
            ReadWord(value);
            ExtractValue(value, is_fixed);
            if(is_fixed)
            {
                KRATOS_ERROR << "Only " << Kratos::DataTypeToString<DataType>::Get() << " variables or components can be fixed."
                             <<  " [Line " << mNumberOfLines << " ]";
            }

            // reading nodal_value
            ReadWord(value);
            ExtractValue(value, nodal_value);

            FindKey(rThisNodes, ReorderedNodeId(id), "Node")->GetSolutionStepValue(rVariable, 0) =  nodal_value;
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    template<class TVariableType, class TDataType>
    void ModelPartIO<TModelPartType>::ReadNodalVectorialVariableData(NodesContainerType& rThisNodes, const TVariableType& rVariable, TDataType Dummy)
    {
        KRATOS_TRY

        SizeType id;
        bool is_fixed;
        TDataType nodal_value;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(value); // reading id
            if(CheckEndBlock("NodalData", value))
                break;

            ExtractValue(value, id);

            // reading is_fixed
            ReadWord(value);
            ExtractValue(value, is_fixed);
            if(is_fixed)
            {
                KRATOS_ERROR << "Only " << Kratos::DataTypeToString<DataType>::Get() << " variables or components can be fixed."
                             <<  " [Line " << mNumberOfLines << " ]";
            }

            // reading nodal_value
            ReadVectorialValue(nodal_value);

            FindKey(rThisNodes, ReorderedNodeId(id), "Node")->GetSolutionStepValue(rVariable, 0) =  nodal_value;
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadElementalDataBlock(ElementsContainerType& rThisElements)
    {
        KRATOS_TRY

        typedef VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > array_1d_component_type;

        std::string variable_name;

        ReadWord(variable_name);

        if(KratosComponents<Variable<bool> >::Has(variable_name))
        {
            ReadElementalScalarVariableData(rThisElements, static_cast<Variable<bool> const& >(KratosComponents<Variable<bool> >::Get(variable_name)));
        }
        else if(KratosComponents<Variable<int> >::Has(variable_name))
        {
            ReadElementalScalarVariableData(rThisElements, static_cast<Variable<int> const& >(KratosComponents<Variable<int> >::Get(variable_name)));
        }
        else if(KratosComponents<Variable<DataType> >::Has(variable_name))
        {
            ReadElementalScalarVariableData(rThisElements, static_cast<Variable<DataType> const& >(KratosComponents<Variable<DataType> >::Get(variable_name)));
        }
        else if(KratosComponents<array_1d_component_type>::Has(variable_name))
        {
            ReadElementalScalarVariableData(rThisElements, static_cast<array_1d_component_type const& >(KratosComponents<array_1d_component_type>::Get(variable_name)));
        }
        else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
        {
            ReadElementalVectorialVariableData(rThisElements, static_cast<Variable<array_1d<DataType, 3> > const& >(KratosComponents<Variable<array_1d<DataType, 3> > >::Get(variable_name)), Vector(3));
        }
        else if(KratosComponents<Variable<Vector> >::Has(variable_name))
        {
            ReadElementalVectorialVariableData(rThisElements, static_cast<Variable<Vector > const& >(KratosComponents<Variable<Vector> >::Get(variable_name)), Vector(3));
        }
        else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
        {
            ReadElementalVectorialVariableData(rThisElements, static_cast<Variable<Matrix > const& >(KratosComponents<Variable<Matrix> >::Get(variable_name)), Matrix(3,3));
        }
        else
        {
            KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    template<class TVariableType>
    void ModelPartIO<TModelPartType>::ReadElementalScalarVariableData(ElementsContainerType& rThisElements, const TVariableType& rVariable)
    {
        KRATOS_TRY

        SizeType id;
        typename TVariableType::Type elemental_value;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(value); // reading id
            if(CheckEndBlock("ElementalData", value))
                break;

            ExtractValue(value, id);

            // reading nodal_value
            ReadWord(value);
            ExtractValue(value, elemental_value);

            typename ModelPartType::ElementIterator i_result = rThisElements.find(ReorderedElementId(id));
            if(i_result != rThisElements.end())
                i_result->GetValue(rVariable) =  elemental_value;
            else
                std::cout  << "WARNING! Assigning " << rVariable.Name() << " to not existing element #" << id << " [Line " << mNumberOfLines << " ]" << std::endl;
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    template<class TVariableType, class TDataType>
    void ModelPartIO<TModelPartType>::ReadElementalVectorialVariableData(ElementsContainerType& rThisElements, const TVariableType& rVariable, TDataType Dummy)
    {
        KRATOS_TRY

        SizeType id;
        TDataType elemental_value;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(value); // reading id
            if(CheckEndBlock("ElementalData", value))
                break;

            ExtractValue(value, id);



            // reading nodal_value
            ReadVectorialValue(elemental_value);
            ExtractValue(value, elemental_value);

            typename ModelPartType::ElementIterator i_result = rThisElements.find(ReorderedElementId(id));
            if(i_result != rThisElements.end())
                i_result->GetValue(rVariable) =  elemental_value;
            else
                std::cout  << "WARNING! Assigning " << rVariable.Name() << " to not existing element #" << id << " [Line " << mNumberOfLines << " ]" << std::endl;
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadConditionalDataBlock(ConditionsContainerType& rThisConditions)
    {
        KRATOS_TRY

        typedef VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > array_1d_component_type;

        std::string variable_name;

        ReadWord(variable_name);

        if(KratosComponents<Variable<DataType> >::Has(variable_name))
        {
            ReadConditionalScalarVariableData(rThisConditions, static_cast<Variable<DataType> const& >(KratosComponents<Variable<DataType> >::Get(variable_name)));
        }
        else if(KratosComponents<Variable<bool> >::Has(variable_name))
        {
            ReadConditionalScalarVariableData(rThisConditions, static_cast<Variable<bool> const& >(KratosComponents<Variable<bool> >::Get(variable_name)));
        }
        else if(KratosComponents<Variable<int> >::Has(variable_name))
        {
            ReadConditionalScalarVariableData(rThisConditions, static_cast<Variable<int> const& >(KratosComponents<Variable<int> >::Get(variable_name)));
        }
        else if(KratosComponents<array_1d_component_type>::Has(variable_name))
        {
            ReadConditionalScalarVariableData(rThisConditions, static_cast<array_1d_component_type const& >(KratosComponents<array_1d_component_type>::Get(variable_name)));
        }
        else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
        {
            ReadConditionalVectorialVariableData(rThisConditions, static_cast<Variable<array_1d<DataType, 3> > const& >(KratosComponents<Variable<array_1d<DataType, 3> > >::Get(variable_name)), Vector(3));
        }
        else if(KratosComponents<Variable<Vector> >::Has(variable_name))
        {
            ReadConditionalVectorialVariableData(rThisConditions, static_cast<Variable<Vector > const& >(KratosComponents<Variable<Vector> >::Get(variable_name)), Vector(3));
        }
        else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
        {
            ReadConditionalVectorialVariableData(rThisConditions, static_cast<Variable<Matrix > const& >(KratosComponents<Variable<Matrix> >::Get(variable_name)), Matrix(3,3));
        }
        else
        {
            KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    template<class TVariableType>
    void ModelPartIO<TModelPartType>::ReadConditionalScalarVariableData(ConditionsContainerType& rThisConditions, const TVariableType& rVariable)
    {
        KRATOS_TRY

        SizeType id;
        typename TVariableType::Type conditional_value;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(value); // reading id
            if(CheckEndBlock("ConditionalData", value))
                break;

            ExtractValue(value, id);

            // reading nodal_value
            ReadWord(value);
            ExtractValue(value, conditional_value);

            typename ModelPartType::ConditionIterator i_result = rThisConditions.find(ReorderedConditionId(id));
            if(i_result != rThisConditions.end())
                i_result->GetValue(rVariable) =  conditional_value;
            else
                std::cout  << "WARNING! Assigning " << rVariable.Name() << " to not existing condition #" << id << " [Line " << mNumberOfLines << " ]" << std::endl;
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    template<class TVariableType, class TDataType>
    void ModelPartIO<TModelPartType>::ReadConditionalVectorialVariableData(ConditionsContainerType& rThisConditions, const TVariableType& rVariable, TDataType Dummy)
    {
        KRATOS_TRY

        SizeType id;
        TDataType conditional_value;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(value); // reading id
            if(CheckEndBlock("ConditionalData", value))
                break;

            ExtractValue(value, id);

            // reading nodal_value
            ReadVectorialValue(conditional_value);
            ExtractValue(value, conditional_value);

            typename ModelPartType::ConditionIterator i_result = rThisConditions.find(ReorderedConditionId(id));
            if(i_result != rThisConditions.end())
                i_result->GetValue(rVariable) =  conditional_value;
            else
                std::cout  << "WARNING! Assigning " << rVariable.Name() << " to not existing condition #" << id << " [Line " << mNumberOfLines << " ]" << std::endl;
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReadElementsConnectivitiesBlock(ConnectivitiesContainerType& rThisConnectivities)
    {
        KRATOS_TRY

        SizeType id;
        SizeType node_id;
        SizeType number_of_connectivities = 0;

        std::string word;
        std::string element_name;

        ReadWord(element_name);
        if(!KratosComponents<ElementType>::Has(element_name))
        {
            KRATOS_ERROR << "Element " << element_name << " is not registered in Kratos,"
                         << " or is incompatible with " << ModelPartTypeToString<TModelPartType>::Get()
                         << ". Please check the spelling of the element name and see if the application containing it is registered corectly."
                         << " [Line " << mNumberOfLines << " ]";
            return number_of_connectivities;
        }

        ElementType const& r_clone_element = KratosComponents<ElementType>::Get(element_name);
        SizeType number_of_nodes = r_clone_element.GetGeometry().size();
        typename ConnectivitiesContainerType::value_type temp_element_nodes;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the element id or End
            if(CheckEndBlock("Elements", word))
                break;

            ExtractValue(word,id);
            ReadWord(word); // Reading the properties id;
            temp_element_nodes.clear();
            for(SizeType i = 0 ; i < number_of_nodes ; i++)
            {
                ReadWord(word); // Reading the node id;
                ExtractValue(word, node_id);
                temp_element_nodes.push_back(ReorderedNodeId(node_id));
            }
            const int index = ReorderedElementId(id) - 1;
            const int size = rThisConnectivities.size();
            if(index == size)  // I do push back instead of resizing to size+1
                rThisConnectivities.push_back(temp_element_nodes);
            else if(index < size)
                rThisConnectivities[index]= temp_element_nodes;
            else
            {
                rThisConnectivities.resize(index+1);
                rThisConnectivities[index]= temp_element_nodes;

            }
            number_of_connectivities++;
        }

        return number_of_connectivities;

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReadConditionsConnectivitiesBlock(ConnectivitiesContainerType& rThisConnectivities)
    {
        KRATOS_TRY

        SizeType id;
        SizeType node_id;
        SizeType number_of_connectivities = 0;


        std::string word;
        std::string condition_name;

        ReadWord(condition_name);
        if(!KratosComponents<ConditionType>::Has(condition_name))
        {
            KRATOS_ERROR << "Condition " << condition_name << " is not registered in Kratos,"
                         << " or is incompatible with " << ModelPartTypeToString<TModelPartType>::Get()
                         << ". Please check the spelling of the condition name and see if the application containing it is registered corectly."
                         << " [Line " << mNumberOfLines << " ]";
            return number_of_connectivities;
        }

        ConditionType const& r_clone_condition = KratosComponents<ConditionType>::Get(condition_name);
        SizeType number_of_nodes = r_clone_condition.GetGeometry().size();
        typename ConnectivitiesContainerType::value_type temp_condition_nodes;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the condition id or End
            if(CheckEndBlock("Conditions", word))
                break;

            ExtractValue(word,id);
            ReadWord(word); // Reading the properties id;
            temp_condition_nodes.clear();
            for(SizeType i = 0 ; i < number_of_nodes ; i++)
            {
                ReadWord(word); // Reading the node id;
                ExtractValue(word, node_id);
                temp_condition_nodes.push_back(ReorderedNodeId(node_id));
            }

            const int index = ReorderedConditionId(id) - 1;
            const int size = rThisConnectivities.size();
            if(index == size)  // I do push back instead of resizing to size+1
                rThisConnectivities.push_back(temp_condition_nodes);
            else if(index < size)
                rThisConnectivities[index]= temp_condition_nodes;
            else
            {
                rThisConnectivities.resize(index+1);
                rThisConnectivities[index]= temp_condition_nodes;

            }
            number_of_connectivities++;
        }

        return number_of_connectivities;

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::FillNodalConnectivitiesFromElementBlock(ConnectivitiesContainerType& rNodalConnectivities)
    {
        KRATOS_TRY;

        SizeType id;
        SizeType node_id;
        SizeType position;
        SizeType used_size = rNodalConnectivities.size();
        SizeType reserved_size = (rNodalConnectivities.capacity() > 0) ? rNodalConnectivities.capacity() : 1;

        std::string word;
        std::string element_name;

        ReadWord(element_name);
        if(!KratosComponents<ElementType>::Has(element_name))
        {
            KRATOS_ERROR << "Element " << element_name << " is not registered in Kratos,"
                         << " or is incompatible with " << ModelPartTypeToString<TModelPartType>::Get()
                         << ". Please check the spelling of the element name and see if the application containing it is registered corectly."
                         << " [Line " << mNumberOfLines << " ]";
        }

        ElementType const& r_clone_element = KratosComponents<ElementType>::Get(element_name);
        SizeType n_nodes_in_elem = r_clone_element.GetGeometry().size();
        typename ConnectivitiesContainerType::value_type temp_element_nodes;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the element id or End
            if(CheckEndBlock("Elements", word))
                break;

            ExtractValue(word,id);
            ReadWord(word); // Reading the properties id;
            temp_element_nodes.clear();
            for(SizeType i = 0 ; i < n_nodes_in_elem ; i++)
            {
                ReadWord(word); // Reading the node id;
                ExtractValue(word, node_id);
                temp_element_nodes.push_back(ReorderedNodeId(node_id));
            }

            for (SizeType i = 0; i < n_nodes_in_elem; i++)
            {
                position = temp_element_nodes[i]-1; // Ids start from 1, position in rNodalConnectivities starts from 0
                if (position >= used_size)
                {
                    used_size = position+1;
                    if (position >= reserved_size)
                    {
                        reserved_size = (used_size > reserved_size) ? 2*used_size : 2*reserved_size;
                        rNodalConnectivities.reserve(reserved_size);
                    }
                    rNodalConnectivities.resize(used_size);
                }

                for (SizeType j = 0; j < i; j++)
                    rNodalConnectivities[position].push_back(temp_element_nodes[j]);
                for (SizeType j = i+1; j < n_nodes_in_elem; j++)
                    rNodalConnectivities[position].push_back(temp_element_nodes[j]);
            }
        }

        KRATOS_CATCH("");
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::FillNodalConnectivitiesFromConditionBlock(ConnectivitiesContainerType& rNodalConnectivities)
    {
        KRATOS_TRY;

        SizeType id;
        SizeType node_id;
        SizeType position;
        SizeType used_size = rNodalConnectivities.size();
        SizeType reserved_size = (rNodalConnectivities.capacity() > 0) ? rNodalConnectivities.capacity() : 1;

        std::string word;
        std::string condition_name;

        ReadWord(condition_name);
        if(!KratosComponents<ConditionType>::Has(condition_name))
        {
            KRATOS_ERROR << "Condition " << condition_name << " is not registered in Kratos,"
                         << " or is incompatible with " << ModelPartTypeToString<TModelPartType>::Get()
                         << ". Please check the spelling of the condition name and see if the application containing it is registered corectly."
                         << " [Line " << mNumberOfLines << " ]";
        }

        ConditionType const& r_clone_condition = KratosComponents<ConditionType>::Get(condition_name);
        SizeType n_nodes_in_cond = r_clone_condition.GetGeometry().size();
        typename ConnectivitiesContainerType::value_type temp_condition_nodes;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the condition id or End
            if(CheckEndBlock("Conditions", word))
                break;

            ExtractValue(word,id);
            ReadWord(word); // Reading the properties id;
            temp_condition_nodes.clear();
            for(SizeType i = 0 ; i < n_nodes_in_cond ; i++)
            {
                ReadWord(word); // Reading the node id;
                ExtractValue(word, node_id);
                temp_condition_nodes.push_back(ReorderedNodeId(node_id));
            }

            for (SizeType i = 0; i < n_nodes_in_cond; i++)
            {
                position = temp_condition_nodes[i]-1; // Ids start from 1, position in rNodalConnectivities starts from 0
                if (position >= used_size)
                {
                    used_size = position+1;
                    if (position >= reserved_size)
                    {
                        reserved_size = (used_size > reserved_size) ? 2*used_size : 2*reserved_size;
                        rNodalConnectivities.reserve(reserved_size);
                    }
                    rNodalConnectivities.resize(used_size);
                }

                for (SizeType j = 0; j < i; j++)
                    rNodalConnectivities[position].push_back(temp_condition_nodes[j]);
                for (SizeType j = i+1; j < n_nodes_in_cond; j++)
                    rNodalConnectivities[position].push_back(temp_condition_nodes[j]);
            }
        }

        KRATOS_CATCH("");
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadCommunicatorDataBlock(CommunicatorType& rThisCommunicator, NodesContainerType& rThisNodes)
    {
        KRATOS_TRY

//  KRATOS_WATCH("begin reading CommunicatorDataBlock")

        std::string word;
        while(true)
        {
            ReadWord(word);
            if(mFile.eof())
                break;
            if(CheckEndBlock("CommunicatorData", word))
                break;
            if(word == "NEIGHBOURS_INDICES")
                ReadVectorialValue(rThisCommunicator.NeighbourIndices());
            else if(word == "NUMBER_OF_COLORS")
            {
                ReadWord(word);
                SizeType number_of_colors;
                ExtractValue(word, number_of_colors);
                rThisCommunicator.SetNumberOfColors(number_of_colors);
            }
            else
            {
                ReadBlockName(word);
                if(word == "LocalNodes")
                    ReadCommunicatorLocalNodesBlock(rThisCommunicator, rThisNodes);
                else if(word == "GhostNodes")
                    ReadCommunicatorGhostNodesBlock(rThisCommunicator, rThisNodes);
                else
                    SkipBlock(word);
            }
        }

//  KRATOS_WATCH("finished reading CommunicatorDataBlock")

        return ;

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadCommunicatorLocalNodesBlock(CommunicatorType& rThisCommunicator, NodesContainerType& rThisNodes)
    {
        KRATOS_TRY

//  KRATOS_WATCH("begin reading CommunicatorLocalNodesBlock")

        SizeType interface_id;
        SizeType node_id;


        std::string word;
        std::string condition_name;

        ReadWord(word); // reading the interface id
        ExtractValue(word,interface_id);


        if(interface_id > rThisCommunicator.GetNumberOfColors())
        {
            KRATOS_ERROR << "Interface " << interface_id << " is not valid."
                         << " The number of colors is " << rThisCommunicator.GetNumberOfColors() << " and the interface id must be les than or equal to number of colors"
                         << " [Line " << mNumberOfLines << " ]";
        }

        typename CommunicatorType::MeshType* p_local_mesh;
        typename CommunicatorType::MeshType* p_interface_mesh;

        if(interface_id == 0)
        {
            p_local_mesh = &(rThisCommunicator.LocalMesh());
            p_interface_mesh = &(rThisCommunicator.InterfaceMesh());
        }
        else
        {
            p_local_mesh = &(rThisCommunicator.LocalMesh(interface_id-1));
            p_interface_mesh = &(rThisCommunicator.InterfaceMesh(interface_id-1));
        }

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the node id or End
            if(CheckEndBlock("LocalNodes", word))
                break;

            ExtractValue(word,node_id);
            typename NodesContainerType::iterator i_node = FindKey(rThisNodes, ReorderedNodeId(node_id), "Node");
            p_local_mesh->Nodes().push_back(*(i_node.base()));
            p_interface_mesh->Nodes().push_back(*(i_node.base()));
        }

        p_local_mesh->Nodes().Sort();
        p_interface_mesh->Nodes().Sort();
//  KRATOS_WATCH("finished reading CommunicatorLocalNodesBlock")

//  KRATOS_WATCH(rThisCommunicator)
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadCommunicatorGhostNodesBlock(CommunicatorType& rThisCommunicator, NodesContainerType& rThisNodes)
    {
        KRATOS_TRY

//  KRATOS_WATCH("begin reading CommunicatorGhostNodesBlock")


        SizeType interface_id;
        SizeType node_id;


        std::string word;
        std::string condition_name;

        ReadWord(word); // reading the interface id
        ExtractValue(word,interface_id);


        if(interface_id > rThisCommunicator.GetNumberOfColors())
        {
            KRATOS_ERROR << "Interface " << interface_id << " is not valid."
                         << " The number of colors is " << rThisCommunicator.GetNumberOfColors() << " and the interface id must be les than or equal to number of colors"
                         << " [Line " << mNumberOfLines << " ]";
        }

        typename CommunicatorType::MeshType* p_ghost_mesh;
        typename CommunicatorType::MeshType* p_interface_mesh;

        if(interface_id == 0)
        {
            p_ghost_mesh = &(rThisCommunicator.GhostMesh());
            p_interface_mesh = &(rThisCommunicator.InterfaceMesh());
        }
        else
        {
            p_ghost_mesh = &(rThisCommunicator.GhostMesh(interface_id-1));
            p_interface_mesh = &(rThisCommunicator.InterfaceMesh(interface_id-1));
        }

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the node id or End
            if(CheckEndBlock("GhostNodes", word))
                break;

            ExtractValue(word,node_id);
            typename NodesContainerType::iterator i_node = FindKey(rThisNodes, ReorderedNodeId(node_id), "Node");
            p_ghost_mesh->Nodes().push_back(*(i_node.base()));
            p_interface_mesh->Nodes().push_back(*(i_node.base()));
        }

        p_ghost_mesh->Nodes().Sort();
        p_interface_mesh->Nodes().Sort();


//  KRATOS_WATCH(rThisCommunicator)
        KRATOS_CATCH("")

//  KRATOS_WATCH("finished reading CommunicatorGhostNodesBlock")

    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadMeshBlock(ModelPartType& rModelPart)
    {
        KRATOS_TRY

        std::string word;
        SizeType mesh_id;

        ReadWord(word);
        ExtractValue(word, mesh_id);

        SizeType number_of_meshes = rModelPart.NumberOfMeshes();

        if(mesh_id > 1000000) // this would be a case of error in reading.
            KRATOS_ERROR << mesh_id << " is too large";

        if(mesh_id == 0) // this would be a case of error in reading.
            KRATOS_ERROR << "The mesh id zero is the reference mesh and already created. You cannot create a mesh 0 with mesh block.";

        // adding necessary meshes to the model part.
        MeshType empty_mesh;
        for(SizeType i = number_of_meshes ; i < mesh_id + 1 ; i++)
            rModelPart.GetMeshes().push_back(empty_mesh.Clone());

        MeshType& mesh = rModelPart.GetMesh(mesh_id);

        while(true)
        {
            ReadWord(word);

            if(mFile.eof())
            {
                break;
            }

            if(CheckEndBlock("Mesh", word))
            {
                 break;
            }

            ReadBlockName(word);
            if(word == "MeshData")
            {
               ReadMeshDataBlock(mesh);
            }
            else if(word == "MeshNodes")
            {
               ReadMeshNodesBlock(rModelPart, mesh);
            }

            else if(word == "MeshElements")
            {
               ReadMeshElementsBlock(rModelPart, mesh);
            }

            else if(word == "MeshConditions")
            {
               ReadMeshConditionsBlock(rModelPart, mesh);
            }

//             else if(word == "MeshProperties")
//                 ReadMeshPropertiesBlock(rModelPart, mesh);

         else
             {
                 SkipBlock(word);
             }
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadMeshDataBlock(MeshType& rMesh)
    {
        KRATOS_TRY

        std::string variable_name;

        while(!mFile.eof())
        {
            ReadWord(variable_name);
            if(CheckEndBlock("MeshData", variable_name))
                break;
            if(KratosComponents<Variable<DataType> >::Has(variable_name))
            {
                std::string value;
                DataType temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                rMesh[KratosComponents<Variable<DataType> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<bool> >::Has(variable_name))
            {
                std::string value;
                bool temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                rMesh[KratosComponents<Variable<bool> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<int> >::Has(variable_name))
            {
                std::string value;
                int temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                rMesh[KratosComponents<Variable<int> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
            {
                Vector temp_vector; // defining a Vector because for array_1d the operator >> is not defined yet!
                ReadVectorialValue(temp_vector);
                rMesh[KratosComponents<Variable<array_1d<DataType,3> > >::Get(variable_name)] = temp_vector;
            }
            else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
            {
                ReadVectorialValue(rMesh[KratosComponents<Variable<Matrix> >::Get(variable_name)]);
            }
            else if(KratosComponents<Variable<std::string> >::Has(variable_name))
            {
                std::string value;
                std::string temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                rMesh[KratosComponents<Variable<std::string> >::Get(variable_name)] = temp;
            }
            else
            {
                KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                             << " [Line " << mNumberOfLines << " ]";
            }
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadMeshNodesBlock(ModelPartType& rModelPart, MeshType& rMesh)
    {
        KRATOS_TRY

        SizeType node_id;

        std::string word;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the node id or End
            if(CheckEndBlock("MeshNodes", word))
                break;

            ExtractValue(word,node_id);
            typename NodesContainerType::iterator i_node = FindKey(rModelPart.Nodes(), ReorderedNodeId(node_id), "Node");
            rMesh.Nodes().push_back(*(i_node.base()));
        }

        rMesh.Nodes().Sort();
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadMeshElementsBlock(ModelPartType& rModelPart, MeshType& rMesh)
    {
        KRATOS_TRY

        SizeType element_id;

        std::string word;


        while(!mFile.eof())
        {
            ReadWord(word); // Reading the element id or End
            if(CheckEndBlock("MeshElements", word))
                break;

            ExtractValue(word,element_id);
            typename ElementsContainerType::iterator i_element = FindKey(rModelPart.Elements(), ReorderedElementId(element_id), "Element");
            rMesh.Elements().push_back(*(i_element.base()));
        }

        rMesh.Elements().Sort();

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadMeshConditionsBlock(ModelPartType& rModelPart, MeshType& rMesh)
    {
        KRATOS_TRY

        SizeType condition_id;

        std::string word;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the element id or End
            if(CheckEndBlock("MeshConditions", word))
                break;

            ExtractValue(word,condition_id);
            typename ConditionsContainerType::iterator i_condition = FindKey(rModelPart.Conditions(), ReorderedConditionId(condition_id), "Condition");
            rMesh.Conditions().push_back(*(i_condition.base()));
        }

        rMesh.Conditions().Sort();

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadMeshPropertiesBlock(ModelPartType& rModelPart, MeshType& rMesh)
    {
        KRATOS_TRY

        Properties temp_properties;

        std::string word;
        std::string variable_name;

        SizeType temp_properties_id;

        ReadWord(word);
        ExtractValue(word, temp_properties_id);
        temp_properties.SetId(temp_properties_id);

        while(!mFile.eof())
        {
            ReadWord(variable_name);
            if(CheckEndBlock("MeshProperties", variable_name))
                break;

            if(KratosComponents<Variable<std::string> >::Has(variable_name))
            {
                std::string value;
                std::string  temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<std::string> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<ValueType> >::Has(variable_name))
            {
                std::string value;
                ValueType temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<ValueType> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<DataType> >::Has(variable_name))
            {
                std::string value;
                DataType temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<DataType> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<int> >::Has(variable_name))
            {
                std::string value;
                int temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<int> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<bool> >::Has(variable_name))
            {
                std::string value;
                bool temp;

                ReadWord(value); // reading value
                ExtractValue(value, temp);
                temp_properties[KratosComponents<Variable<bool> >::Get(variable_name)] = temp;
            }
            else if(KratosComponents<Variable<array_1d<ValueType, 3> > >::Has(variable_name))
            {
                Vector temp_vector; // defining a Vector because for array_1d the operator >> is not defined yet!
                ReadVectorialValue(temp_vector);
                temp_properties[KratosComponents<Variable<array_1d<ValueType, 3> > >::Get(variable_name)] = temp_vector;
            }
            else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
            {
                VectorType temp_vector; // defining a Vector because for array_1d the operator >> is not defined yet!
                ReadVectorialValue(temp_vector);
                temp_properties[KratosComponents<Variable<array_1d<DataType, 3> > >::Get(variable_name)] = temp_vector;
            }
            else if(KratosComponents<Variable<Vector> >::Has(variable_name))
            {
                ReadVectorialValue(temp_properties[KratosComponents<Variable<Vector> >::Get(variable_name)]);
            }
            else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
            {
                ReadVectorialValue(temp_properties[KratosComponents<Variable<Matrix> >::Get(variable_name)]);
            }
            else
            {
                KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                             << " [Line " << mNumberOfLines << " ]";
            }
        }

        rMesh.Properties().push_back(temp_properties);

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadSubModelPartBlock(ModelPartType& rMainModelPart, ModelPartType& rParentModelPart)
    {
        KRATOS_TRY

        std::string word;

        ReadWord(word); // Reading the name of the sub model part

        ModelPartType& r_sub_model_part = dynamic_cast<ModelPartType&>(rParentModelPart.CreateSubModelPart(word));

        while (true)
        {
            ReadWord(word);
            //if (mFile.eof())
            //  break;
            if (CheckEndBlock("SubModelPart", word))
                break;

            ReadBlockName(word);
            if (word == "SubModelPartData")
                ReadModelPartDataBlock(r_sub_model_part);
            else if (word == "SubModelPartTables")
                ReadSubModelPartTablesBlock(rMainModelPart, r_sub_model_part);
            else if (word == "SubModelPartProperties")
                ReadSubModelPartPropertiesBlock(rMainModelPart, r_sub_model_part);
            else if (word == "SubModelPartNodes")
                ReadSubModelPartNodesBlock(rMainModelPart, r_sub_model_part);
            else if (word == "SubModelPartElements")
                ReadSubModelPartElementsBlock(rMainModelPart, r_sub_model_part);
            else if (word == "SubModelPartConditions")
                ReadSubModelPartConditionsBlock(rMainModelPart, r_sub_model_part);
            // TODO: Add the following blocks. Pooyan.
            //else if (word == "CommunicatorData")
            //{
            //  ReadCommunicatorDataBlock(rThisModelPart.GetCommunicator(), rThisModelPart.Nodes());
            //  //Adding the elements and conditions to the communicator
            //  rThisModelPart.GetCommunicator().LocalMesh().Elements() = rThisModelPart.Elements();
            //  rThisModelPart.GetCommunicator().LocalMesh().Conditions() = rThisModelPart.Conditions();
            //}
            //else if (word == "Mesh")
            //  ReadMeshBlock(rThisModelPart);
            else if (word == "SubModelPart")
                ReadSubModelPartBlock(rMainModelPart, r_sub_model_part);
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadSubModelPartTablesBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart)
    {
        KRATOS_TRY

        SizeType table_id;
        std::string word;

        while (!mFile.eof())
        {
            ReadWord(word); // Reading the node id or End
            if (CheckEndBlock("SubModelPartTables", word))
                break;

            ExtractValue(word, table_id);
            typename ModelPartType::TablesContainerType::iterator i_table = FindKey(rMainModelPart.Tables(), table_id, "Table");
            rSubModelPart.AddTable((i_table.base())->first, (i_table.base())->second);
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadSubModelPartPropertiesBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart)
    {
        KRATOS_TRY

        SizeType properties_id;
        std::string word;

        while (!mFile.eof())
        {
            ReadWord(word); // Reading the node id or End
            if (CheckEndBlock("SubModelPartProperties", word))
                break;

            ExtractValue(word, properties_id);
            typename PropertiesContainerType::iterator i_properties = FindKey(rMainModelPart.rProperties(), properties_id, "Properties");
            rSubModelPart.AddProperties(*(i_properties.base()));
        }
        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadSubModelPartNodesBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart)
    {
        KRATOS_TRY

        SizeType node_id;
        std::string word;

        while (!mFile.eof())
        {
            ReadWord(word); // Reading the node id or End
            if (CheckEndBlock("SubModelPartNodes", word))
                break;

            ExtractValue(word, node_id);
            typename NodesContainerType::iterator i_node = FindKey(rMainModelPart.Nodes(), ReorderedNodeId(node_id), "Node");
            rSubModelPart.AddNode(*(i_node.base()));
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadSubModelPartElementsBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart)
    {
        KRATOS_TRY

        SizeType element_id;
        std::string word;

        while (!mFile.eof())
        {
            ReadWord(word); // Reading the node id or End
            if (CheckEndBlock("SubModelPartElements", word))
                break;

            ExtractValue(word, element_id);
            typename ElementsContainerType::iterator i_element = FindKey(rMainModelPart.Elements(), ReorderedElementId(element_id), "Element");
            rSubModelPart.AddElement(*(i_element.base()));
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ReadSubModelPartConditionsBlock(ModelPartType& rMainModelPart, ModelPartType& rSubModelPart)
    {
        KRATOS_TRY

        SizeType condition_id;
        std::string word;

        while (!mFile.eof())
        {
            ReadWord(word); // Reading the node id or End
            if (CheckEndBlock("SubModelPartConditions", word))
                break;

            ExtractValue(word, condition_id);
            typename ConditionsContainerType::iterator i_condition = FindKey(rMainModelPart.Conditions(), ReorderedConditionId(condition_id), "Condition");
            rSubModelPart.AddCondition(*(i_condition.base()));
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideModelPartDataBlock(OutputFilesContainerType& OutputFiles)
    {
        KRATOS_TRY

        std::string block;

        WriteInAllFiles(OutputFiles, "Begin ModelPartData");

        ReadBlock(block, "ModelPartData");
        WriteInAllFiles(OutputFiles, block);

        WriteInAllFiles(OutputFiles, "End ModelPartData\n");
        KRATOS_WATCH("DivideModelPartDataBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideTableBlock(OutputFilesContainerType& OutputFiles)
    {
        KRATOS_TRY

        std::string block;

        WriteInAllFiles(OutputFiles, "Begin Table ");

        ReadBlock(block, "Table");
        WriteInAllFiles(OutputFiles, block);

        WriteInAllFiles(OutputFiles, "End Table\n");
        KRATOS_WATCH("DivideTableBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DividePropertiesBlock(OutputFilesContainerType& OutputFiles)
    {
        KRATOS_TRY

        std::string block;

        WriteInAllFiles(OutputFiles, "Begin Properties ");

        ReadBlock(block, "Properties");
        WriteInAllFiles(OutputFiles, block);

        WriteInAllFiles(OutputFiles, "End Properties\n");
        KRATOS_WATCH("DividePropertiesBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideNodesBlock(OutputFilesContainerType& OutputFiles,
                                       PartitionIndicesContainerType const& NodesAllPartitions)
    {
        KRATOS_TRY

        std::string word;

        WriteInAllFiles(OutputFiles, "Begin Nodes \n");

        SizeType id;

        while(!mFile.eof())
        {
            ReadWord(word);
            if(CheckEndBlock("Nodes", word))
                break;

            ExtractValue(word, id);

            if(ReorderedNodeId(id) > NodesAllPartitions.size())
            {
                KRATOS_ERROR << "Invalid node id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            std::stringstream node_data;
            node_data << ReorderedNodeId(id) << '\t'; // id
            ReadWord(word);
            node_data << word << '\t'; // x
            ReadWord(word);
            node_data << word << '\t'; // y
            ReadWord(word);
            node_data << word << '\n'; // z

            for(SizeType i = 0 ; i < NodesAllPartitions[ReorderedNodeId(id)-1].size() ; i++)
            {
                SizeType partition_id = NodesAllPartitions[ReorderedNodeId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for node " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << node_data.str();
            }

        }

        WriteInAllFiles(OutputFiles, "End Nodes\n");
        KRATOS_WATCH("DivideNodesBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideElementsBlock(OutputFilesContainerType& OutputFiles,
                                          PartitionIndicesContainerType const& ElementsAllPartitions)
    {
        KRATOS_TRY

        KRATOS_WATCH("DivideElementsBlock started");

        std::string word;
        std::string element_name;

        ReadWord(element_name);
        if(!KratosComponents<ElementType>::Has(element_name))
        {
            KRATOS_ERROR << "Element " << element_name << " is not registered in Kratos,"
                         << " or is incompatible with " << ModelPartTypeToString<TModelPartType>::Get()
                         << ". Please check the spelling of the element name and see if the application containing it is registered corectly."
                         << " [Line " << mNumberOfLines << " ]";
            return;
        }

        ElementType const& r_clone_element = KratosComponents<ElementType>::Get(element_name);
        SizeType number_of_nodes = r_clone_element.GetGeometry().size();

        WriteInAllFiles(OutputFiles, "Begin Elements " +  element_name);

        SizeType id;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the element id or End
            if(CheckEndBlock("Elements", word))
                break;

            ExtractValue(word,id);
            if(ReorderedElementId(id) > ElementsAllPartitions.size())
            {
                KRATOS_ERROR << "Invalid element id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            std::stringstream element_data;
            element_data << '\n' << ReorderedElementId(id) << '\t'; // id
            ReadWord(word); // Reading the properties id;
            element_data << word << '\t'; // properties id

            for(SizeType i = 0 ; i < number_of_nodes ; i++)
            {
                ReadWord(word); // Reading the node id;
                SizeType node_id;
                ExtractValue(word, node_id);
                element_data << ReorderedNodeId(node_id) << '\t'; // node id
            }


            for(SizeType i = 0 ; i < ElementsAllPartitions[ReorderedElementId(id)-1].size() ; i++)
            {
                SizeType partition_id = ElementsAllPartitions[ReorderedElementId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for node " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << element_data.str();
            }

        }

        WriteInAllFiles(OutputFiles, "\nEnd Elements\n");

        KRATOS_WATCH("DivideElementsBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideConditionsBlock(OutputFilesContainerType& OutputFiles,
                                            PartitionIndicesContainerType const& ConditionsAllPartitions)
    {
        KRATOS_TRY

        std::string word;
        std::string condition_name;

        ReadWord(condition_name);
        if(!KratosComponents<ConditionType>::Has(condition_name))
        {
            KRATOS_ERROR << "Condition " << condition_name << " is not registered in Kratos,"
                         << " or is incompatible with " << ModelPartTypeToString<TModelPartType>::Get()
                         << ". Please check the spelling of the condition name and see if the application containing it is registered corectly."
                         << " [Line " << mNumberOfLines << " ]";
            return;
        }

        ConditionType const& r_clone_condition = KratosComponents<ConditionType>::Get(condition_name);
        SizeType number_of_nodes = r_clone_condition.GetGeometry().size();

        WriteInAllFiles(OutputFiles, "Begin Conditions " +  condition_name);

        SizeType id;

        while(!mFile.eof())
        {
            ReadWord(word); // Reading the condition id or End
            if(CheckEndBlock("Conditions", word))
                break;

            ExtractValue(word,id);
            if(ReorderedConditionId(id) > ConditionsAllPartitions.size())
            {
                KRATOS_ERROR << "Invalid condition id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            std::stringstream condition_data;
            condition_data << '\n' << ReorderedConditionId(id) << '\t'; // id
            ReadWord(word); // Reading the properties id;
            condition_data << word << '\t'; // properties id

            for(SizeType i = 0 ; i < number_of_nodes ; i++)
            {
                ReadWord(word); // Reading the node id;
                SizeType node_id;
                ExtractValue(word, node_id);
                condition_data << ReorderedNodeId(node_id) << '\t'; // node id
            }


            for(SizeType i = 0 ; i < ConditionsAllPartitions[ReorderedConditionId(id)-1].size() ; i++)
            {
                SizeType partition_id = ConditionsAllPartitions[ReorderedConditionId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for node " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << condition_data.str();
            }

        }

        WriteInAllFiles(OutputFiles, "\nEnd Conditions\n");

        KRATOS_WATCH("DivideConditionsBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideNodalDataBlock(OutputFilesContainerType& OutputFiles,
                                           PartitionIndicesContainerType const& NodesAllPartitions)
    {
        KRATOS_TRY

        typedef VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > array_1d_component_type;

        std::string word;

        WriteInAllFiles(OutputFiles, "Begin NodalData ");

        std::string variable_name;

        ReadWord(variable_name);

        WriteInAllFiles(OutputFiles, variable_name);
        WriteInAllFiles(OutputFiles, "\n");

        if(KratosComponents<Variable<DataType> >::Has(variable_name))
        {
            DivideDofVariableData(OutputFiles, NodesAllPartitions);
        }
        else if(KratosComponents<Variable<int> >::Has(variable_name))
        {
            DivideDofVariableData(OutputFiles, NodesAllPartitions);
        }
        else if(KratosComponents<Variable<bool> >::Has(variable_name))
        {
            DivideDofVariableData(OutputFiles, NodesAllPartitions);
        }
        else if(KratosComponents<array_1d_component_type>::Has(variable_name))
        {
            DivideDofVariableData(OutputFiles, NodesAllPartitions);
        }
        else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
        {
            DivideVectorialVariableData(OutputFiles, NodesAllPartitions, "NodalData");
        }
        else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
        {
            DivideMatrixVariableData(OutputFiles, NodesAllPartitions, "NodalData" );
        }
        else if(KratosComponents<VariableData>::Has(variable_name))
        {
            KRATOS_ERROR << variable_name << " is not supported to be read by this IO or the type of variable is not registered correctly" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }
        else
        {
            KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }

        WriteInAllFiles(OutputFiles, "End NodalData\n");

        KRATOS_WATCH("DivideNodalDataBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideDofVariableData(OutputFilesContainerType& OutputFiles,
                                            PartitionIndicesContainerType const& NodesAllPartitions)
    {
        KRATOS_TRY

        SizeType id;

        std::string word;

        while(!mFile.eof())
        {
            ReadWord(word); // reading id
            if(CheckEndBlock("NodalData", word))
                break;

            ExtractValue(word, id);

            if(ReorderedNodeId(id) > NodesAllPartitions.size())
            {
                KRATOS_ERROR << "Invalid node id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            std::stringstream node_data;
            node_data << ReorderedNodeId(id) << '\t'; // id
            ReadWord(word);
            node_data << word << '\t'; // is fixed
            ReadWord(word);
            node_data << word << '\n'; // value

            for(SizeType i = 0 ; i < NodesAllPartitions[ReorderedNodeId(id)-1].size() ; i++)
            {
                SizeType partition_id = NodesAllPartitions[ReorderedNodeId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for node " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << node_data.str();
            }
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideVectorialVariableData(OutputFilesContainerType& OutputFiles,
                                                  PartitionIndicesContainerType const& EntitiesPartitions,
                                                  std::string BlockName)
    {
        KRATOS_TRY

        SizeType id;

        std::string word;

        bool is_fixed;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(word); // reading id
            if(CheckEndBlock(BlockName, word))
                break;

            ExtractValue(word, id);

            if(ReorderedNodeId(id) > EntitiesPartitions.size())
            {
                KRATOS_ERROR << "Invalid node id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            std::stringstream entity_data;
            entity_data << ReorderedNodeId(id) << '\t'; // id

            if(BlockName == "NodalData")
            {
                // reading is_fixed
                ReadWord(value);
                ExtractValue(value, is_fixed);
                if(is_fixed)
                {
                    KRATOS_ERROR << "Only " << Kratos::DataTypeToString<DataType>::Get() << " variables or components can be fixed."
                                 <<  " [Line " << mNumberOfLines << " ]";
                }
                entity_data << is_fixed << "\t"; // is_fixed
            }

            Vector temp_vector;
            ReadVectorialValue(temp_vector);

            for(SizeType i = 0 ; i < EntitiesPartitions[ReorderedNodeId(id)-1].size() ; i++)
            {
                SizeType partition_id = EntitiesPartitions[ReorderedNodeId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for node " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << entity_data.str() << temp_vector << std::endl;
            }
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideMatrixVariableData(OutputFilesContainerType& OutputFiles,
                                               PartitionIndicesContainerType const& EntitiesPartitions,
                                               std::string BlockName)
    {
        KRATOS_TRY

        SizeType id;

        std::string word;

        bool is_fixed;

        std::string value;

        while(!mFile.eof())
        {
            ReadWord(word); // reading id
            if(CheckEndBlock(BlockName, word))
                break;

            ExtractValue(word, id);

            if(ReorderedNodeId(id) > EntitiesPartitions.size())
            {
                KRATOS_ERROR << "Invalid node id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            std::stringstream entity_data;
            entity_data << ReorderedNodeId(id) << '\t'; // id

            if(BlockName == "NodalData")
            {
                // reading is_fixed
                ReadWord(value);
                ExtractValue(value, is_fixed);
                if(is_fixed)
                {
                    KRATOS_ERROR << "Only " << Kratos::DataTypeToString<DataType>::Get() << " variables or components can be fixed."
                                 <<  " [Line " << mNumberOfLines << " ]";
                }
                entity_data << is_fixed << "\t"; // is_fixed
            }

            Matrix temp_matrix;
            ReadVectorialValue(temp_matrix);

            for(SizeType i = 0 ; i < EntitiesPartitions[ReorderedNodeId(id)-1].size() ; i++)
            {
                SizeType partition_id = EntitiesPartitions[ReorderedNodeId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for node " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << entity_data.str() << temp_matrix << std::endl;
            }
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideElementalDataBlock(OutputFilesContainerType& OutputFiles,
                                               PartitionIndicesContainerType const& ElementsAllPartitions)
    {
        KRATOS_TRY

        typedef VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > array_1d_component_type;

        std::string word;

        WriteInAllFiles(OutputFiles, "Begin ElementalData ");

        std::string variable_name;

        ReadWord(variable_name);

        WriteInAllFiles(OutputFiles, variable_name);
        WriteInAllFiles(OutputFiles, "\n");

        if(KratosComponents<Variable<DataType> >::Has(variable_name))
        {
            DivideScalarVariableData(OutputFiles, ElementsAllPartitions, "ElementalData");
        }
        else if(KratosComponents<Variable<bool> >::Has(variable_name))
        {
            DivideScalarVariableData(OutputFiles, ElementsAllPartitions, "ElementalData");
        }
        else if(KratosComponents<Variable<int> >::Has(variable_name))
        {
            DivideScalarVariableData(OutputFiles, ElementsAllPartitions, "ElementalData");
        }
        else if(KratosComponents<array_1d_component_type>::Has(variable_name))
        {
            DivideScalarVariableData(OutputFiles, ElementsAllPartitions, "ElementalData");
        }
        else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
        {
            DivideVectorialVariableData(OutputFiles, ElementsAllPartitions, "ElementalData");
        }
        else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
        {
            DivideMatrixVariableData(OutputFiles, ElementsAllPartitions, "ElementalData");
        }
        else if(KratosComponents<VariableData>::Has(variable_name))
        {
            KRATOS_ERROR << variable_name << " is not supported to be read by this IO or the type of variable is not registered correctly" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }
        else
        {
            KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }

        WriteInAllFiles(OutputFiles, "End ElementalData\n");

        KRATOS_WATCH("DivideElementalDataBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideScalarVariableData(OutputFilesContainerType& OutputFiles,
                                               PartitionIndicesContainerType const& EntitiesPartitions,
                                               std::string BlockName)
    {
        KRATOS_TRY

        SizeType id;

        std::string word;

        while(!mFile.eof())
        {
            ReadWord(word); // reading id
            if(CheckEndBlock(BlockName, word))
                break;

            ExtractValue(word, id);
            SizeType index = 0;
            if(BlockName == "ElementalData")
                index = ReorderedElementId(id);
            else if(BlockName == "ConditionalData")
                index = ReorderedConditionId(id);
            else
                KRATOS_ERROR << "Invalid block name " << BlockName;

            if(index > EntitiesPartitions.size())
            {
                KRATOS_ERROR << "Invalid id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            std::stringstream entity_data;
            entity_data << index << '\t'; // id
            ReadWord(word);
            entity_data << word <<'\n'; // value

            for(SizeType i = 0 ; i < EntitiesPartitions[index-1].size() ; i++)
            {
                SizeType partition_id = EntitiesPartitions[index-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for entity " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << entity_data.str();
            }
        }

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideConditionalDataBlock(OutputFilesContainerType& OutputFiles,
                                                 PartitionIndicesContainerType const& ConditionsAllPartitions)
    {
        KRATOS_TRY

        typedef VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > array_1d_component_type;

        std::string word;

        WriteInAllFiles(OutputFiles, "Begin ConditionalData ");

        std::string variable_name;

        ReadWord(variable_name);

        WriteInAllFiles(OutputFiles, variable_name);
        WriteInAllFiles(OutputFiles, "\n");

        if(KratosComponents<Variable<DataType> >::Has(variable_name))
        {
            DivideScalarVariableData(OutputFiles, ConditionsAllPartitions, "ConditionalData");
        }
        else if(KratosComponents<Variable<bool> >::Has(variable_name))
        {
            DivideScalarVariableData(OutputFiles, ConditionsAllPartitions, "ConditionalData");
        }
        else if(KratosComponents<Variable<int> >::Has(variable_name))
        {
            DivideScalarVariableData(OutputFiles, ConditionsAllPartitions, "ConditionalData");
        }
        else if(KratosComponents<array_1d_component_type>::Has(variable_name))
        {
            DivideScalarVariableData(OutputFiles, ConditionsAllPartitions, "ConditionalData");
        }
        else if(KratosComponents<Variable<array_1d<DataType, 3> > >::Has(variable_name))
        {
            DivideVectorialVariableData(OutputFiles, ConditionsAllPartitions, "ConditionalData");
        }
        else if(KratosComponents<Variable<Matrix> >::Has(variable_name))
        {
            DivideMatrixVariableData(OutputFiles, ConditionsAllPartitions, "ConditionalData");
        }
        else if(KratosComponents<VariableData>::Has(variable_name))
        {
            KRATOS_ERROR << variable_name << " is not supported to be read by this IO or the type of variable is not registered correctly" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }
        else
        {
            KRATOS_ERROR << variable_name << " is not a valid variable!!!" << std::endl
                         << " [Line " << mNumberOfLines << " ]";
        }

        WriteInAllFiles(OutputFiles, "End ConditionalData\n");

        KRATOS_WATCH("DivideConditionalDataBlock completed");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideMeshBlock(OutputFilesContainerType& OutputFiles,
                                      PartitionIndicesContainerType const& NodesAllPartitions,
                                      PartitionIndicesContainerType const& ElementsAllPartitions,
                                      PartitionIndicesContainerType const& ConditionsAllPartitions)
    {
        KRATOS_TRY

        std::string word;
        ReadWord(word);

        word += "\n";


        WriteInAllFiles(OutputFiles, "Begin Mesh " + word);

        while(!mFile.eof())
        {
            ReadWord(word);

            if(CheckEndBlock("Mesh", word))
                break;

            ReadBlockName(word);
            if(word == "MeshData")
               DivideMeshDataBlock(OutputFiles);
            else if(word == "MeshNodes")
               DivideMeshNodesBlock(OutputFiles, NodesAllPartitions);
            else if(word == "MeshElements")
               DivideMeshElementsBlock(OutputFiles, ElementsAllPartitions);
            else if(word == "MeshConditions")
               DivideMeshConditionsBlock(OutputFiles, ConditionsAllPartitions);
            else
               SkipBlock(word);
        }

        WriteInAllFiles(OutputFiles, "End Mesh\n");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideSubModelPartBlock(OutputFilesContainerType& OutputFiles,
                                              PartitionIndicesContainerType const& NodesAllPartitions,
                                              PartitionIndicesContainerType const& ElementsAllPartitions,
                                              PartitionIndicesContainerType const& ConditionsAllPartitions)
    {
        KRATOS_ERROR << "This Method is not yet implemented!" << std::endl;
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideMeshDataBlock(OutputFilesContainerType& OutputFiles)
    {
        KRATOS_TRY

        std::string block;

        WriteInAllFiles(OutputFiles, "Begin MeshData");

        ReadBlock(block, "MeshData");
        WriteInAllFiles(OutputFiles, block);

        WriteInAllFiles(OutputFiles, "End MeshData\n");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideMeshNodesBlock(OutputFilesContainerType& OutputFiles,
                                           PartitionIndicesContainerType const& NodesAllPartitions)
    {
        KRATOS_TRY

        std::string word;

        WriteInAllFiles(OutputFiles, "Begin MeshNodes \n");

        SizeType id;

        while(!mFile.eof())
        {
            ReadWord(word);

            if(CheckEndBlock("MeshNodes", word))
                break;

            ExtractValue(word, id);

            if(ReorderedNodeId(id) > NodesAllPartitions.size())
            {
                KRATOS_ERROR << "Invalid node id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            for(SizeType i = 0 ; i < NodesAllPartitions[ReorderedNodeId(id)-1].size() ; i++)
            {
                SizeType partition_id = NodesAllPartitions[ReorderedNodeId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for node " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << ReorderedNodeId(id) << std::endl;
            }

        }

        WriteInAllFiles(OutputFiles, "End MeshNodes\n");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideMeshElementsBlock(OutputFilesContainerType& OutputFiles,
                                              PartitionIndicesContainerType const& ElementsAllPartitions)
    {
        KRATOS_TRY

        std::string word;

        WriteInAllFiles(OutputFiles, "Begin MeshElements \n");

        SizeType id;

        while(!mFile.eof())
        {
            ReadWord(word);

            if(CheckEndBlock("MeshElements", word))
                break;

            ExtractValue(word, id);

            if(ReorderedElementId(id) > ElementsAllPartitions.size())
            {
                KRATOS_ERROR << "Invalid element id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            for(SizeType i = 0 ; i < ElementsAllPartitions[ReorderedElementId(id)-1].size() ; i++)
            {
                SizeType partition_id = ElementsAllPartitions[ReorderedElementId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for element " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << ReorderedElementId(id) << std::endl;
            }

        }

        WriteInAllFiles(OutputFiles, "End MeshElements\n");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::DivideMeshConditionsBlock(OutputFilesContainerType& OutputFiles,
                                                PartitionIndicesContainerType const& ConditionsAllPartitions)
    {
        KRATOS_TRY

        std::string word;

        WriteInAllFiles(OutputFiles, "Begin MeshConditions \n");

        SizeType id;

        while(!mFile.eof())
        {
            ReadWord(word);

            if(CheckEndBlock("MeshConditions", word))
                break;

            ExtractValue(word, id);

            if(ReorderedConditionId(id) > ConditionsAllPartitions.size())
            {
                KRATOS_ERROR << "Invalid condition id : " << id
                             << " [Line " << mNumberOfLines << " ]";
            }

            for(SizeType i = 0 ; i < ConditionsAllPartitions[ReorderedConditionId(id)-1].size() ; i++)
            {
                SizeType partition_id = ConditionsAllPartitions[ReorderedConditionId(id)-1][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for condition " << id << " [Line " << mNumberOfLines << " ]";
                }

                *(OutputFiles[partition_id]) << ReorderedConditionId(id) << std::endl;
            }

        }

        WriteInAllFiles(OutputFiles, "End MeshConditions\n");

        KRATOS_CATCH("")
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WritePartitionIndices(OutputFilesContainerType& OutputFiles, PartitionIndicesType const&  NodesPartitions, PartitionIndicesContainerType const& NodesAllPartitions)
    {
        WriteInAllFiles(OutputFiles, "Begin NodalData PARTITION_INDEX\n");

        for(SizeType i_node = 0 ; i_node != NodesAllPartitions.size() ; i_node++)
        {
            for(SizeType i = 0 ; i < NodesAllPartitions[i_node].size() ; i++)
            {
                SizeType partition_id = NodesAllPartitions[i_node][i];
                if(partition_id > OutputFiles.size())
                {
                    KRATOS_ERROR << "Invalid partition id : " << partition_id
                                 << " for node " << i_node+1 << " [Line " << mNumberOfLines << " ]";
                }

                const SizeType node_partition = NodesPartitions[i_node];
                *(OutputFiles[partition_id]) << i_node + 1 << "  0  " << node_partition << std::endl;
            }
        }

        WriteInAllFiles(OutputFiles, "End NodalData \n");
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteCommunicatorData(OutputFilesContainerType& OutputFiles, SizeType NumberOfPartitions, GraphType const& DomainsColoredGraph,
                                            PartitionIndicesType const& NodesPartitions,
                                            PartitionIndicesType const& ElementsPartitions,
                                            PartitionIndicesType const& ConditionsPartitions,
                                            PartitionIndicesContainerType const& NodesAllPartitions,
                                            PartitionIndicesContainerType const& ElementsAllPartitions,
                                            PartitionIndicesContainerType const& ConditionsAllPartitions)
    {
        WriteInAllFiles(OutputFiles, "Begin CommunicatorData \n");

        // Writing the domains neighbours
        WriteInAllFiles(OutputFiles, "NEIGHBOURS_INDICES    ");
        for(SizeType i_partition = 0 ; i_partition < NumberOfPartitions ; i_partition++)
        {
            boost::numeric::ublas::vector<int> indices = row(DomainsColoredGraph, i_partition);
            *(OutputFiles[i_partition]) << indices << std::endl;
        }

        SizeType number_of_colors = 0;

        for(SizeType i_partition = 0 ; i_partition < DomainsColoredGraph.size1() ; i_partition++)
            for(SizeType i_interface = 0 ; i_interface < DomainsColoredGraph.size2() ; i_interface++)
                if(DomainsColoredGraph(i_partition, i_interface) >= 0)
                    if(number_of_colors < i_interface)
                        number_of_colors = i_interface;

        number_of_colors++; // I have to add one to it to get the correct number

        // Writing the max colors
        for(SizeType i_partition = 0 ; i_partition < NumberOfPartitions ; i_partition++)
        {
            boost::numeric::ublas::vector<int> indices = row(DomainsColoredGraph, i_partition);
            *(OutputFiles[i_partition]) << "NUMBER_OF_COLORS    " << number_of_colors << std::endl;
        }

        // Writing the all local nodes
        WriteInAllFiles(OutputFiles, "    Begin LocalNodes 0\n");

        for(SizeType i = 0 ; i < NodesPartitions.size() ; i++)
            *(OutputFiles[NodesPartitions[i]]) << "    " << i+1 << std::endl;

        WriteInAllFiles(OutputFiles, "    End LocalNodes \n");

        std::vector<PartitionIndicesContainerType> local_nodes_indices(NumberOfPartitions, PartitionIndicesContainerType(number_of_colors));
        std::vector<PartitionIndicesContainerType> ghost_nodes_indices(NumberOfPartitions, PartitionIndicesContainerType(number_of_colors));

        matrix<int> interface_indices = scalar_matrix<int>(NumberOfPartitions, NumberOfPartitions, -1);

        for(SizeType i_partition = 0 ; i_partition < NumberOfPartitions ; i_partition++)
        {
            vector<int> neighbours_indices = row(DomainsColoredGraph, i_partition);

            for(SizeType i = 0 ; i <  neighbours_indices.size() ; i++)
                if(SizeType(neighbours_indices[i]) < NumberOfPartitions)
                    interface_indices(i_partition,neighbours_indices[i]) = i;
        }

        for(SizeType i = 0 ; i < NodesPartitions.size() ; i++)
        {
            const SizeType node_partition = NodesPartitions[i];
            const SizeType node_id = i + 1;

            PartitionIndicesType const& node_all_partitions = NodesAllPartitions[i];

            for(SizeType j = 0 ; j < node_all_partitions.size() ; j++)
            {
                SizeType i_node_partition = node_all_partitions[j];
                if(node_partition != i_node_partition)
                {
                    int local_interface_index = interface_indices(node_partition, i_node_partition);
                    int ghost_interface_index = interface_indices(i_node_partition, node_partition);
                    if(local_interface_index == -1)
                    {
                        KRATOS_WATCH(node_partition)
                        KRATOS_WATCH(i_node_partition)
                        KRATOS_ERROR << "local_interface_index is -1";
                    }
                    if(ghost_interface_index == -1)
                    {
                        KRATOS_WATCH(node_partition)
                        KRATOS_WATCH(i_node_partition)
                        KRATOS_ERROR << "ghost_interface_index is -1";
                    }
                    local_nodes_indices[node_partition][local_interface_index].push_back(node_id);
                    ghost_nodes_indices[i_node_partition][ghost_interface_index].push_back(node_id);
                }
            }

        }

        for(SizeType i_partition = 0 ; i_partition < NumberOfPartitions ; i_partition++)
        {
            PartitionIndicesContainerType& partition_local_nodes_indices = local_nodes_indices[i_partition];

            for(SizeType i_interface = 0 ; i_interface < partition_local_nodes_indices.size() ; i_interface++)
            {
                if(partition_local_nodes_indices[i_interface].size() > 0)
                {
                    *(OutputFiles[i_partition]) << "    Begin LocalNodes " << i_interface + 1 << std::endl;
                    for(SizeType i_interface_node = 0 ; i_interface_node < partition_local_nodes_indices[i_interface].size() ; i_interface_node++)
                        *(OutputFiles[i_partition]) << "    " << partition_local_nodes_indices[i_interface][i_interface_node] << std::endl;
                    *(OutputFiles[i_partition]) << "    End LocalNodes " << std::endl;
                }
            }

            PartitionIndicesContainerType& partition_ghost_nodes_indices = ghost_nodes_indices[i_partition];

            std::set<unsigned int> all_ghost_nodes_indices;

            for(SizeType i_interface = 0 ; i_interface < partition_ghost_nodes_indices.size() ; i_interface++)
            {
                if(partition_ghost_nodes_indices[i_interface].size() > 0)
                {
                    *(OutputFiles[i_partition]) << "    Begin GhostNodes " << i_interface + 1 << std::endl;
                    for(SizeType i_interface_node = 0 ; i_interface_node < partition_ghost_nodes_indices[i_interface].size() ; i_interface_node++)
                    {
                        *(OutputFiles[i_partition]) << "    " << partition_ghost_nodes_indices[i_interface][i_interface_node] << std::endl;
                        all_ghost_nodes_indices.insert(partition_ghost_nodes_indices[i_interface][i_interface_node]);
                    }
                    *(OutputFiles[i_partition]) << "    End GhostNodes "  << std::endl;
                }
            }

            *(OutputFiles[i_partition]) << "    Begin GhostNodes " << 0 << std::endl;
            for(std::set<unsigned int>::iterator id = all_ghost_nodes_indices.begin() ; id != all_ghost_nodes_indices.end() ; id++)
            {
                *(OutputFiles[i_partition]) << "    " << *id << std::endl;
            }
            *(OutputFiles[i_partition]) << "    End GhostNodes "  << std::endl;
        }

        WriteInAllFiles(OutputFiles, "End CommunicatorData \n");
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteCommunicatorLocalNodes(OutputFilesContainerType& OutputFiles, SizeType NumberOfPartitions, PartitionIndicesType const& NodesPartitions, PartitionIndicesContainerType const& NodesAllPartitions)
    {
        WriteInAllFiles(OutputFiles, "    Begin LocalNodes 0\n");

        for(SizeType i = 0 ; i < NodesPartitions.size() ; i++)
            *(OutputFiles[NodesPartitions[i]]) << "    " << i+1 << std::endl;

        WriteInAllFiles(OutputFiles, "    End LocalNodes \n");

        PartitionIndicesContainerType local_nodes_indices(NumberOfPartitions);
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::WriteInAllFiles(OutputFilesContainerType& OutputFiles, std::string const& ThisWord)
    {
        for(SizeType i = 0 ; i < OutputFiles.size() ; i++)
            *(OutputFiles[i]) << ThisWord;
    }

    template<class TModelPartType>
    ModelPartIO<TModelPartType>& ModelPartIO<TModelPartType>::ReadWord(std::string& Word)
    {
        Word.clear();

        char c = SkipWhiteSpaces();
        while(!mFile.eof() && !IsWhiteSpace(c))
        {
            Word += c;
            c = GetCharacter();
        }

        return *this;
    }

    template<class TModelPartType>
    ModelPartIO<TModelPartType>& ModelPartIO<TModelPartType>::ReadBlock(std::string& Block, std::string const& BlockName)
    {
        Block.clear();
        std::vector<std::string> nested_block_names;
        nested_block_names.push_back(BlockName);

        char c = GetCharacter();
        std::string word;

        while(!mFile.eof())
        {
            if(c == 'E')
            {
                word.clear();
                while(!mFile.eof() && !IsWhiteSpace(c))
                {
                    word += c;
                    c = GetCharacter();
                }
                if (CheckEndBlock(nested_block_names.back(), word))
                {
                    nested_block_names.pop_back();
                    if(nested_block_names.empty())
                    {
                        break;
                    }
                    else
                    {
                        Block += "End ";
                    }
                }

                Block += word;
            }
            else if (c == 'B')
            {
                word.clear();
                while (!mFile.eof() && !IsWhiteSpace(c))
                {
                    word += c;
                    c = GetCharacter();
                }
                if (word == "Begin")
                {
                    Block += word;
                    Block += c;
                    ReadWord(word);
                    nested_block_names.push_back(word);
                }

                Block += word;
            }

            Block += c;

            c = GetCharacter();
        }

        return *this;
    }

    template<class TModelPartType>
    char ModelPartIO<TModelPartType>::SkipWhiteSpaces()
    {
        char c = GetCharacter();
        while(IsWhiteSpace(c))
            c = GetCharacter();
        return c;
    }

    template<class TModelPartType>
    bool ModelPartIO<TModelPartType>::IsWhiteSpace(char C) const
    {
        return ((C == ' ') || (C == '\t') || (C == '\r') || (C == '\n'));
    }

    template<class TModelPartType>
    char ModelPartIO<TModelPartType>::GetCharacter() //Getting the next character skipping comments
    {
        char c;
        if(mFile.get(c))
        {
            if(c == '\n')
                mNumberOfLines++;
            else if(c == '/') // it may be a comment!
            {
                char next_c = mFile.peek();
                if(next_c == '/') // it's a line comment
                {
                    while((mFile.get(c)) && (c != '\n')); // so going to the end of line
                    if(!mFile.eof())
                        mNumberOfLines++;
                }
                else if(next_c == '*') // it's a block comment
                {
                    while((mFile.get(c)) && !((c == '*') && (mFile.peek() == '/'))) // so going to the end of block
                        if(c == '\n')
                            mNumberOfLines++;
                    mFile.get(c);
                    c = GetCharacter(); // read a new character after comment
                }
            }
        }
        else
            c = 0;

        return c;
    }

    template<class TModelPartType>
    bool ModelPartIO<TModelPartType>::CheckStatement(std::string const& rStatement, std::string const& rGivenWord) const
    {
        bool result = false;
        if(rGivenWord != rStatement)
        {
            KRATOS_ERROR << "A \"" << rStatement << "\" statement was expected but the given statement was \""
                         <<  rGivenWord << "\"" << " [Line " << mNumberOfLines << " ]";
        }
        else
            result = true;

        return result;
    }

    template<class TModelPartType>
    void ModelPartIO<TModelPartType>::ResetInput()
    {
        mFile.clear();
        mFile.seekg(0, std::ios_base::beg);
        mNumberOfLines = 1;
    }

    /// Unaccessible assignment operator.
    template<class TModelPartType>
    ModelPartIO<TModelPartType>& ModelPartIO<TModelPartType>::operator=(ModelPartIO const& rOther) {return *this;}

    /// Unaccessible copy constructor.
    template<class TModelPartType>
    ModelPartIO<TModelPartType>::ModelPartIO(ModelPartIO const& rOther) {}

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReorderedNodeId(SizeType NodeId)
    {
        // The ModelPartIO does not reorder the nodes
        // This method is the one to be overriden by some reordering IO class
        return NodeId;
    }

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReorderedElementId(SizeType ElementId)
    {
        // The ModelPartIO does not reorder the elements
        // This method is the one to be overriden by some reordering IO class
        return ElementId;
    }

    template<class TModelPartType>
    typename ModelPartIO<TModelPartType>::SizeType ModelPartIO<TModelPartType>::ReorderedConditionId(SizeType ConditionId)
    {
        // The ModelPartIO does not reorder the conditions
        // This method is the one to be overriden by some reordering IO class
        return ConditionId;
    }

    /// template class instantiation
    template class ModelPartIO<ModelPart>;
    template class ModelPartIO<ComplexModelPart>;
    template class ModelPartIO<GComplexModelPart>;

}  // namespace Kratos.
