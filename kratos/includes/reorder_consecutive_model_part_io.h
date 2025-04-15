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


#if !defined(KRATOS_REORDER_CONSECUTIVE_MODEL_PART_IO_H_INCLUDED )
#define  KRATOS_REORDER_CONSECUTIVE_MODEL_PART_IO_H_INCLUDED


// System includes
#include <string>
#include <fstream>
#include <set>

// External includes


// Project includes
#include "includes/define.h"
#include "includes/model_part_io.h"
#include "utilities/timer.h"


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
/** This class writes all modelpart data including the meshes.
*/
template<class TModelPartType = ModelPart>
class KRATOS_API(KRATOS_CORE) ReorderConsecutiveModelPartIO : public ModelPartIO<TModelPartType>
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of ReorderConsecutiveModelPartIO
    KRATOS_CLASS_POINTER_DEFINITION(ReorderConsecutiveModelPartIO);

    typedef ModelPartIO<TModelPartType> BaseType;

    typedef typename BaseType::NodeType NodeType;

    typedef typename BaseType::MeshType MeshType;

    typedef typename BaseType::NodesContainerType NodesContainerType;

    typedef typename BaseType::PropertiesContainerType PropertiesContainerType;

    typedef typename BaseType::ElementsContainerType ElementsContainerType;

    typedef typename BaseType::ConditionsContainerType ConditionsContainerType;

    typedef typename BaseType::ConnectivitiesContainerType ConnectivitiesContainerType;

    typedef typename BaseType::OutputFilesContainerType OutputFilesContainerType;

    typedef typename BaseType::SizeType SizeType;

    typedef std::map<SizeType, SizeType> IdMapType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Constructor with  filenames.
    ReorderConsecutiveModelPartIO(std::string const& Filename, const Flags Options = BaseType::READ|BaseType::NOT_IGNORE_VARIABLES_ERROR);


    /// Destructor.
    ~ReorderConsecutiveModelPartIO() override;


    ///@}
    ///@name Operators
    ///@{


    ///@}
    ///@name Operations
    ///@{


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

    SizeType ReorderedNodeId(SizeType NodeId) override;
    SizeType ReorderedElementId(SizeType ElementId) override;
    SizeType ReorderedConditionId(SizeType ConditionId) override;

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

    ///@name Member Variables
    ///@{

    SizeType mNumberOfNodes;
    SizeType mNumberOfElements;
    SizeType mNumberOfConditions;

    IdMapType mNodeIdMap;
    IdMapType mElementIdMap;
    IdMapType mConditionIdMap;

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
    ReorderConsecutiveModelPartIO& operator=(ReorderConsecutiveModelPartIO const& rOther);

    /// Copy constructor.
    ReorderConsecutiveModelPartIO(ReorderConsecutiveModelPartIO const& rOther);


    ///@}

}; // Class ReorderConsecutiveModelPartIO

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

}  // namespace Kratos.

#endif // KRATOS_REORDER_CONSECUTIVE_MODEL_PART_IO_H_INCLUDED  defined

