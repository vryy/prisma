//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//                   Pooyan Dadvand
//  Contributors:    Hoang-Giang Bui
//

#if !defined(KRATOS_MODEL_H_INCLUDED )
#define  KRATOS_MODEL_H_INCLUDED

// System includes
#include <string>
#include <iostream>
#include <map>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/model_part.h"

namespace Kratos
{
///@addtogroup KratosCore
///@{

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

/**
* @class Model
* @ingroup KratosCore
* @brief This class aims to manage different model parts across multi-physics simulations
* @details The class behaves as a manager of the different model parts. It uses map of the variables and the model parts for that purpose
* @author Riccardo Rossi
*/
class KRATOS_API(KRATOS_CORE) Model final
{
public:
    ///@name Type Definitions
    ///@{

    /// Definition of the index type
    typedef KRATOS_INDEX_TYPE IndexType;

    /// Pointer definition of Model
    KRATOS_CLASS_POINTER_DEFINITION(Model);

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    Model() : mName("ModelName") {};

    /// Constructor with name.
    Model(const std::string& Name) : mName(Name) {};

    /// Destructor.
    ~Model();

    Model(const Model&) = delete;

    ///@}
    ///@name Operators
    ///@{

    Model & operator=(const Model&) = delete;

    ///@}
    ///@name Operations
    ///@{

    /**
     * @brief This method clears the database of modelparts
     * @details Executes a clear on the model part map
     */
    void Reset();

    /**
     * @brief This method creates a new model part contained in the current Model with a given name and buffer size
     * @param ModelPartName The name of the new model part to be created
     * @param NewBufferSize The size of the buffer of the new model part created
     */
    template<class TModelPartType>
    TModelPartType& CreateModelPart( const std::string& ModelPartName, IndexType NewBufferSize=1 );

    /**
     * @brief This method deletes a modelpart with a given name
     * @details Raises a warning in case the model part does not exists
     * @param ModelPartName The name of the model part to be removed
     */
    void DeleteModelPart( const std::string& ModelPartName );

    /**
     * @brief This method renames a modelpart with a given name
     * @details Raises an error in case the model part does not exists as root model part
     * @param OldName The name of the model part to be renamed
     * @param NewName The new name for the model part to be renamed
     */
    void RenameModelPart( const std::string& OldName, const std::string& NewName );

    /**
     * @brief This method returns a model part given a certain name
     * @details Iterates over the list of submodelparts of the root model part
     * @param rFullModelPartName The name of the model part to be returned
     * @return Reference to the model part of interest
     */
    BaseModelPart& GetBaseModelPart(const std::string& rFullModelPartName);

    /**
     * @brief This method returns a model part given a certain name
     * Unlike the old version of this function. The type must be given in the template argument.
     * This poses additional step to obtain the needed model part. But user knows what
     * he should get at the end, right?
     * @details Iterates over the list of submodelparts of the root model part
     * @param rFullModelPartName The name of the model part to be returned
     * @return Reference to the model part of interest
     */
    template<class TModelPartType>
    TModelPartType& GetModelPart(const std::string& rFullModelPartName);

    /**
     * @brief This method returns a model part given a certain name
     * @details Iterates over the list of submodelparts of the root model part
     * @param rFullModelPartName The name of the model part to be returned
     * @return Reference to the model part of interest
     */
    const BaseModelPart& GetBaseModelPart(const std::string& rFullModelPartName) const;

    /**
     * @brief This method returns a model part given a certain name
     * Unlike the old version of this function. The type must be given in the template argument.
     * This poses additional step to obtain the needed model part. But user knows what
     * he should get at the end, right?
     * @details Iterates over the list of submodelparts of the root model part
     * @param rFullModelPartName The name of the model part to be returned
     * @return Reference to the model part of interest
     */
    template<class TModelPartType>
    const TModelPartType& GetModelPart(const std::string& rFullModelPartName) const;

    /**
     * @brief This method checks if a certain a model part exists given a certain name
     * @details Iterates over the list of submodelparts of the root model part
     * @param rFullModelPartName The name of the model part to be checked
     * @return True if the model part exists, false otherwise
     */
    bool HasBaseModelPart(const std::string& rFullModelPartName) const;

    /**
     * @brief This method checks if a certain a model part exists given a certain name
     *  Furthermore, the type of the model part must match the specified type in the template argument
     * @details Iterates over the list of submodelparts of the root model part
     * @param rFullModelPartName The name of the model part to be checked
     * @return True if the model part exists, false otherwise
     */
    template<class TModelPartType>
    bool HasModelPart(const std::string& rFullModelPartName) const;

    /**
     * @brief This returns a vector containing a list of model parts names contained on the model
     * @details Iterates over the list of submodelparts of the root model part
     * @return A vector of strings containing the model parts names
     */
    std::vector<std::string> GetModelPartNames() const;

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
    std::string Info() const;

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const;

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const;

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

    std::string mName;

    std::map< std::string, std::unique_ptr<BaseModelPart> > mRootModelPartMap; /// The map containing the list of model parts

    ///@}
    ///@name Private Operators
    ///@{

    ///@}
    ///@name Private Operations
    ///@{

    /**
     * @brief This method searchs recursively a sub model part in a model part
     * @param rModelPartName The name to be search
     * @param pModelPart Pointer of the model part where search recursively
     * @return The pointer of the model part of interest
     */
    BaseModelPart* RecursiveSearchByName(const std::string& rModelPartName, BaseModelPart* pModelPart) const;

    /**
     * @brief This method splits the name of the model part using "." to define the hierarchy
     * @param rFullModelPartName The name with the full hierarchy
     * @return The vector containing each part of the name defining the model part hierarchy
     */
    std::vector<std::string> SplitSubModelPartHierarchy(const std::string& rFullModelPartName) const;

    /**
     * @brief This method creates a new model part contained in the current Model with a given name and buffer size
     * @param ModelPartName The name of the new model part to be created
     * @param NewBufferSize The size of the buffer of the new model part created
     */
    template<class TModelPartType>
    void CreateRootModelPart(const std::string& ModelPartName, IndexType NewBufferSize);

    /**
     * @brief This method gets the names of all parent-modelparts given a submodelpart-name
     * @param rModelPart The SubModelPart for which the parents-modelpart-names are to be extracted
     * @param rModelPartNames The names of the ModelParts
     * @TODO remove this function when the flat-map is removed (it will no longer be needed)
     */
    void GetNameWithAscendants(const BaseModelPart& rModelPart, std::vector<std::string>& rModelPartNames) const;

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
//       Model& operator=(Model const& rOther);

    /// Copy constructor.
//       Model(Model const& rOther);

    ///@}
    ///@name Serialization
    ///@{

    friend class Serializer;

    void save(Serializer& rSerializer) const;
    void load(Serializer& rSerializer);

    ///@}

}; // Class Model

///@}

///@name Type Definitions
///@{

extern KRATOS_API(KRATOS_CORE) std::unique_ptr<Model> pKratosDefaultModel; // a temporary model to use to contain a model_part if it is created standalone

///@}
///@name Input and output
///@{

/// input stream function
inline std::istream& operator >> (std::istream& rIStream, Model& rThis)
{
    return rIStream;
}

/// output stream function
inline std::ostream& operator << (std::ostream& rOStream, const Model& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}
///@}

///@} addtogroup block

}  // namespace Kratos.

#endif // KRATOS_MODEL_H_INCLUDED  defined
