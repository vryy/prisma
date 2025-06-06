//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//                   Riccardo Rossi
//  Collaborator:    Vicente Mataix Ferrandiz
//
//

#if !defined(KRATOS_VARIABLE_H_INCLUDED )
#define  KRATOS_VARIABLE_H_INCLUDED

// System includes
#include <string>
#include <iostream>

// External includes

// Project includes
#include "includes/define.h"
#include "variable_data.h"


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

/**
 * @class Variable
 * @brief Variable class contains all information needed to store and retrive data from a data container.
 * @details Variable class contains all information needed to store and retrive data from a data container.  It contains key value which is needed for searching in data container. Also a zero value to use as a default value in the container. Finally it has the type of the Variable as its template parameter so the container can find it in its relative part.
* @tparam TDataType The data type hold by the variable
* @ingroup KratosCore
* @author Pooyan Dadvand
*/
template<class TDataType>
class Variable : public VariableData
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of Variable
    KRATOS_CLASS_POINTER_DEFINITION(Variable);

    /// type of this variable
    typedef TDataType Type;

    // Type used for key values which defined in VariableData
    typedef VariableData::KeyType KeyType;

    // Type of this varible with given TDataType
    typedef Variable<TDataType> VariableType;

    ///@}
    ///@name Life Cycle
    ///@{

    /**
     * @brief Constructor with specific name and zero value
     * @param NewName The name to be assigned to the new variable
     * @param Zero The value to be assigned to the variable as zero. In case of not definition will take the value given by the constructor of the time
     */
    Variable(const std::string& NewName, const TDataType Zero = TDataType())
        : VariableData(NewName, sizeof(TDataType)), mZero(Zero)
    {
        // Here we don't register as we asume that the origin is already registered
    }

    /// Copy constructor.
    Variable(const VariableType& rOtherVariable) : VariableData(rOtherVariable), mZero(rOtherVariable.mZero) {}

    /// Destructor.
    ~Variable() override {}

    ///@}
    ///@name Operators
    ///@{

    /**
     * @brief Assignment operator, deleted to avoid misuse which can lead to memory problems
     */
    VariableType& operator=(const VariableType& rOtherVariable) = delete;

    ///@}
    ///@name Operations
    ///@{

    /**
     * @brief Clone creates a copy of the object using a copy constructor of the class.
     * @details It is useful to avoid shallow copying of complex objects and also without actually having information about the variable type.
     * @param pSource The pointer of the variable to be cloned
     * @return A raw pointer of the variable
     */
    void* Clone(const void* pSource) const override
    {
        return new TDataType(*static_cast<const TDataType* >(pSource) );
    }

    /**
     * @brief Copy is very similar to Clone except that it also the destination pointer also passed to it.
     * @details It is a helpful method specially to create a copy of heterogeneous data arrays
     * @param pSource The pointer of the variable to be copied
     * @param pDestination The pointer of the destination variable
     * @return A raw pointer of the variable
     */
    void* Copy(const void* pSource, void* pDestination) const override
    {
        return new(pDestination) TDataType(*static_cast<const TDataType* >(pSource) );
    }

    /**
     * @brief Assign is very similar to Copy. It just differs in using an assignment operator besides the copy constructor. Copy creates a new object while
     * @details Assign does the assignment for two existing objects.
     * @param pSource The pointer of the value to be assigned
     * @param pDestination The pointer of the destination value
     */
    void Assign(const void* pSource, void* pDestination) const override
    {
        (*static_cast<TDataType* >(pDestination) ) = (*static_cast<const TDataType* >(pSource) );
    }

    /**
     * @brief AssignZero is a special case of Assign for which variable zero value used as source.
     * @details This method is useful for initializing arrays or resetting values in memory.
     * @param pDestination The pointer of the destination variable
     */
    void AssignZero(void* pDestination) const override
    {
        //(*static_cast<TDataType* >(pDestination) ) = mZero;
        new (pDestination) TDataType(mZero);
    }

    /**
     * @brief Delete removes an object of variable type from memory.
     * @details It calls a destructor of objects to prevent memory leak and frees the memory allocated for this object assuming that the object is allocated in heap.
     * @param pSource The pointer of the variable to be deleted
     */
    void Delete(void* pSource) const override
    {
        delete static_cast<TDataType* >(pSource);
    }

    /**
     * @brief Destruct eliminates an object maintaining the memory it is using.
     * @details However, the unlike Delete it does nothing with the memory allocated to it.
     * So it is very useful in case of reallocating a part of the memory.
     * @param pSource The pointer of the variable to be destructed
     */
    void Destruct(void* pSource) const override
    {
        static_cast<TDataType* >(pSource)->~TDataType();
    }

    /**
     * @brief Print is an auxiliary method to produce output of given variable knowing its address.
     * @details For example writing an heterogenous container in an output stream can be done using this method. Point assumes that the streaming operator is defined for the variable type.
     * @param pSource The pointer of the variable to be printed
     * @param rOStream The stream used to print the information
     */
    void Print(const void* pSource, std::ostream& rOStream) const override
    {
        rOStream << Name() << " : " << *static_cast<const TDataType* >(pSource) ;
    }

    /**
     * @brief The save operation which backups the data of the class
     * @param rSerializer The serializer used to preserve the information
     * @param pData A pointer to the data to be saved
     */
    void Save(Serializer& rSerializer, void* pData) const override
    {
        // I'm saving by the value, it can be done by the pointer to detect shared data. Pooyan.
        rSerializer.save("Data",*static_cast<TDataType* >(pData));
    }

    /**
     * @brief This method allocates the data of the variable
     * @param pData A pointer to the data to be allocated
     */
    void Allocate(void** pData) const override
    {
        *pData = new TDataType;
    }

    /**
     * @brief The load operation which restores the data of the class
     * @param rSerializer The serializer used to preserve the information
     * @param pData A pointer to the data to be loaded
     */
    void Load(Serializer& rSerializer, void* pData) const override
    {
        rSerializer.load("Data",*static_cast<TDataType* >(pData));
    }

    /**
     * @brief This method returns the variable type
     * @return The type of the variable
     */
    static const VariableType& StaticObject()
    {
        const static Variable<TDataType> static_object("NONE");
        return static_object;
    }

    ///@}
    ///@name Access
    ///@{

    /**
     * @brief This method returns the zero value of the variable type
     * @return The zero value of the corresponding variable
     */
    const TDataType& Zero() const
    {
        return mZero;
    }

    const void* pZero() const override {
       return &mZero;
    }

    ///@}
    ///@name Inquiry
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    /**
     * Turn back information as a string.
     */
    std::string Info() const override
    {
        std::stringstream buffer;
        buffer << Name() << " " << DataTypeToString<TDataType>::Get() << " variable";
        return buffer.str();
    }

    /**
     * Print information about this object.
     * @param rOStream The stream used to print the information
     */
    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << Info();
    }

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const override
    {
        VariableData::PrintData(rOStream);
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

    static const VariableType msStaticObject;               /// Definition of the static variable

    ///@}
    ///@name Member Variables
    ///@{

    TDataType mZero;                                        /// The zero type contains the null value of the current variable type

    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    ///@}
    ///@name Serialization
    ///@{

    friend class Serializer;

    /**
     * The save operation which copies the database of the class
     * @param rSerializer The serializer used to preserve the information
     */
    void save(Serializer& rSerializer) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, VariableData);
        rSerializer.save("Zero", mZero);
    }

    /**
     * The load operation which restores the database of the class
     * @param rSerializer The serializer used to preserve the information
     */
    void load(Serializer& rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, VariableData);
        rSerializer.load("Zero", mZero);
    }

    ///@}
    ///@name Private  Access
    ///@{


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{

    /** Default constructor is un accessible due to the fact that
    each variable must have a name defined.*/
    Variable() {}

    ///@}

}; // Class Variable

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{

/// input stream function
template<class TDataType>
inline std::istream& operator >> (std::istream& rIStream,
                                  Variable<TDataType>& rThis)
{
    return rIStream;
}

/// output stream function
template<class TDataType>
inline std::ostream& operator << (std::ostream& rOStream,
                                  const Variable<TDataType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

}  // namespace Kratos.

#endif // KRATOS_VARIABLE_H_INCLUDED  defined
