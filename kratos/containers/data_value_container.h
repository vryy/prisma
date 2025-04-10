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

#if !defined(KRATOS_DATA_VALUE_CONTAINER_H_INCLUDED )
#define KRATOS_DATA_VALUE_CONTAINER_H_INCLUDED

// System includes
#include <string>
#include <iostream>
#include <cstddef>
#include <vector>

// External includes

// Project includes
#include "includes/define.h"
#include "containers/variable.h"
#include "containers/variable_component.h"
#include "includes/kratos_components.h"



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
 * @class DataValueContainer
 * @ingroup KratosCore
 * @brief Container for storing data values associated with variables.
 * @details This class provides a container for storing data values associated with variables.
 * @author Pooyan Dadvand
 */
class KRATOS_API(KRATOS_CORE) DataValueContainer
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of DataValueContainer
    KRATOS_CLASS_POINTER_DEFINITION(DataValueContainer);

    /// Type of the container used for variables
    typedef std::pair<const VariableData*, void*> ValueType;

    /// Type of the container used for variables
    typedef std::vector<ValueType> ContainerType;

    /// Type of the container used for variables
    typedef std::vector<ValueType>::iterator IteratorType;

    /// Type of the container used for variables
    typedef std::vector<ValueType>::const_iterator ConstantIteratorType;

    /// Type of the container used for variables
    typedef std::vector<ValueType>::size_type SizeType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    DataValueContainer() {}

    /// Copy constructor.
    DataValueContainer(DataValueContainer const& rOther)
    {
        for(ConstantIteratorType i = rOther.mData.begin() ; i != rOther.mData.end() ; ++i)
            mData.push_back(ValueType(i->first, i->first->Clone(i->second)));
    }

    /// Destructor.
    virtual ~DataValueContainer()
    {
        for(IteratorType i = mData.begin() ; i != mData.end() ; ++i)
            i->first->Delete(i->second);
    }

    ///@}
    ///@name Operators
    ///@{

    /**
     * @brief Accessor operator for retrieving a data value by a VariableData.
     * @details This operator allows you to retrieve a data value by providing a VariableData object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The VariableData object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TDataType>
    const TDataType& operator()(const VariableData& rThisVariable) const
    {
        return GetValue<TDataType>(rThisVariable);
    }

    /**
     * @brief Accessor operator for retrieving a data value by a Variable.
     * @details This operator allows you to retrieve a data value by providing a Variable object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The Variable object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TDataType>
    TDataType& operator()(const Variable<TDataType>& rThisVariable)
    {
        return GetValue<TDataType>(rThisVariable);
    }

    /**
     * @brief Accessor operator for retrieving a data value by a Variable (const version).
     * @details This operator allows you to retrieve a data value by providing a Variable object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The Variable object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TDataType>
    const TDataType& operator()(const Variable<TDataType>& rThisVariable) const
    {
        return GetValue<TDataType>(rThisVariable);
    }

    /**
     * @brief Accessor operator for retrieving a data value by a Variable.
     * @details This operator allows you to retrieve a data value by providing a Variable object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The Variable object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TAdaptorType>
    typename TAdaptorType::Type& operator()(const VariableComponent<TAdaptorType>& rThisVariable)
    {
        return rThisVariable.GetValue(GetValue(rThisVariable.GetSourceVariable()));
    }

    /**
     * @brief Accessor operator for retrieving a data value by a Variable (const version).
     * @details This operator allows you to retrieve a data value by providing a Variable object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The Variable object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TAdaptorType>
    const typename TAdaptorType::Type& operator()(const VariableComponent<TAdaptorType>& rThisVariable) const
    {
        return rThisVariable.GetValue(GetValue(rThisVariable.GetSourceVariable()));
    }

    /**
     * @brief Index operator for retrieving a data value by a VariableData.
     * @details This operator allows you to retrieve a data value by providing a VariableData object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The VariableData object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TDataType>
    TDataType& operator[](const VariableData& rThisVariable)
    {
        return GetValue<TDataType>(rThisVariable);
    }

    /**
     * @brief Index operator for retrieving a data value by a VariableData (const version).
     * @details This operator allows you to retrieve a data value by providing a VariableData object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The VariableData object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TDataType>
    const TDataType& operator[](const VariableData& rThisVariable) const
    {
        return GetValue<TDataType>(rThisVariable);
    }

    /**
     * @brief Index operator for retrieving a data value by a Variable.
     * @details This operator allows you to retrieve a data value by providing a Variable object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The Variable object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TDataType>
    TDataType& operator[](const Variable<TDataType>& rThisVariable)
    {
        return GetValue<TDataType>(rThisVariable);
    }

    /**
     * @brief Index operator for retrieving a data value by a Variable (const version).
     * @details This operator allows you to retrieve a data value by providing a Variable object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The Variable object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TDataType>
    const TDataType& operator[](const Variable<TDataType>& rThisVariable) const
    {
        return GetValue<TDataType>(rThisVariable);
    }

    /**
     * @brief Index operator for retrieving a data value by a Variable.
     * @details This operator allows you to retrieve a data value by providing a Variable object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The Variable object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TAdaptorType>
    typename TAdaptorType::Type& operator[](const VariableComponent<TAdaptorType>& rThisVariable)
    {
        return rThisVariable.GetValue(GetValue(rThisVariable.GetSourceVariable()));
    }

    /**
     * @brief Index operator for retrieving a data value by a Variable (const version).
     * @details This operator allows you to retrieve a data value by providing a Variable object.
     * @tparam TDataType The data type of the value to retrieve.
     * @param rThisVariable The Variable object specifying the variable.
     * @return A reference to the data value.
     */
    template<class TAdaptorType>
    const typename TAdaptorType::Type& operator[](const VariableComponent<TAdaptorType>& rThisVariable) const
    {
        return rThisVariable.GetValue(GetValue(rThisVariable.GetSourceVariable()));
    }

    /**
     * @brief Iterator pointing to the beginning of the container.
     * @return An iterator pointing to the beginning of the container.
     */
    IteratorType begin()
    {
        return mData.begin();
    }

    /**
     * @brief Const iterator pointing to the beginning of the container.
     * @return A const iterator pointing to the beginning of the container.
     */
    ConstantIteratorType begin() const
    {
        return mData.begin();
    }

    /**
     * @brief Iterator pointing to the end of the container.
     * @return An iterator pointing to the end of the container.
     */
    IteratorType end()
    {
        return mData.end();
    }

    /**
     * @brief Const iterator pointing to the end of the container.
     * @return A const iterator pointing to the end of the container.
     */
    ConstantIteratorType end() const
    {
        return mData.end();
    }

    /**
     * @brief Assignment operator for copying data from another DataValueContainer.
     * @details This operator allows you to assign the contents of another DataValueContainer to this container.
     * @param rOther The DataValueContainer to copy data from.
     * @return A reference to the modified DataValueContainer.
     */
    DataValueContainer& operator=(const DataValueContainer& rOther)
    {
        Clear();

        for(ConstantIteratorType i = rOther.mData.begin() ; i != rOther.mData.end() ; ++i)
            mData.push_back(ValueType(i->first, i->first->Clone(i->second)));

        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    /**
     * @brief Gets the value associated with a given variable.
     * @tparam TDataType The data type of the variable.
     * @param rThisVariable The variable for which the value is to be retrieved.
     * @return Reference to the value of the provided variable.
     */
    template<class TDataType>
    TDataType& GetValue(const Variable<TDataType>& rThisVariable)
    {
        typename ContainerType::iterator i;

        if ((i = std::find_if(mData.begin(), mData.end(), IndexCheck(rThisVariable.Key())))  != mData.end())
            return *static_cast<TDataType*>(i->second);

        mData.push_back(ValueType(&rThisVariable,new TDataType(rThisVariable.Zero())));

        return *static_cast<TDataType*>(mData.back().second);
    }

    /**
     * @brief Gets the value associated with a given variable (const version).
     * @tparam TDataType The data type of the variable.
     * @param rThisVariable The variable for which the value is to be retrieved.
     * @return Const reference to the value of the provided variable.
     * @todo Make the variable of the constant version consistent with the one of the "classical" one
     */
    template<class TDataType>
    const TDataType& GetValue(const Variable<TDataType>& rThisVariable) const
    {
        typename ContainerType::const_iterator i;

        if ((i = std::find_if(mData.begin(), mData.end(), IndexCheck(rThisVariable.Key())))  != mData.end())
            return *static_cast<const TDataType*>(i->second);

        return rThisVariable.Zero();
    }

    /**
     * @brief Gets the value associated with a given variable.
     * @tparam TDataType The data type of the variable.
     * @param rThisVariable The variable for which the value is to be retrieved.
     * @return Reference to the value of the provided variable.
     */
    template<class TAdaptorType>
    typename TAdaptorType::Type& GetValue(const VariableComponent<TAdaptorType>& rThisVariable)
    {
        return rThisVariable.GetValue(GetValue(rThisVariable.GetSourceVariable()));
    }

    /**
     * @brief Gets the value associated with a given variable (const version).
     * @tparam TDataType The data type of the variable.
     * @param rThisVariable The variable for which the value is to be retrieved.
     * @return Const reference to the value of the provided variable.
     * @todo Make the variable of the constant version consistent with the one of the "classical" one
     */
    template<class TAdaptorType>
    const typename TAdaptorType::Type& GetValue(const VariableComponent<TAdaptorType>& rThisVariable) const
    {
        return rThisVariable.GetValue(GetValue(rThisVariable.GetSourceVariable()));
    }

    /**
     * @brief Gets the size of the data container.
     * @return Size of the data container.
     */
    SizeType Size()
    {
        return mData.size();
    }

    /**
     * @brief Sets the value for a given variable.
     * @tparam TDataType The data type of the variable.
     * @param rThisVariable The variable for which the value is to be set.
     * @param rValue The value to be set for the variable.
     */
    template<class TDataType>
    void SetValue(const Variable<TDataType>& rThisVariable, TDataType const& rValue)
    {
        typename ContainerType::iterator i;

        if ((i = std::find_if(mData.begin(), mData.end(), IndexCheck(rThisVariable.Key())))  != mData.end())
            *static_cast<TDataType*>(i->second) = rValue;
        else
            mData.push_back(ValueType(&rThisVariable,new TDataType(rValue)));
    }

    /**
     * @brief Sets the value for a given variable.
     * @tparam TDataType The data type of the variable.
     * @param rThisVariable The variable for which the value is to be set.
     * @param rValue The value to be set for the variable.
     */
    template<class TAdaptorType>
void SetValue(const VariableComponent<TAdaptorType>& rThisVariable, typename TAdaptorType::Type const& rValue)
    {
        rThisVariable.GetValue(GetValue(rThisVariable.GetSourceVariable())) = rValue;
    }

    /**
     * @brief Erases the value associated with a given variable.
     * @tparam TDataType The data type of the variable.
     * @param rThisVariable The variable whose associated value is to be erased.
     */
    template<class TDataType>
    void Erase(const Variable<TDataType>& rThisVariable)
    {
        typename ContainerType::iterator i;

        if ((i = std::find_if(mData.begin(), mData.end(), IndexCheck(rThisVariable.Key())))  != mData.end())
        {
            i->first->Delete(i->second);
            mData.erase(i);
        }
    }

    /**
     * @brief Clears the entire data container.
     */
    void Clear()
    {
        for(ContainerType::iterator i = mData.begin() ; i != mData.end() ; i++)
            i->first->Delete(i->second);

        mData.clear();
    }

    ///@}
    ///@name Access
    ///@{

    ///@}
    ///@name Inquiry
    ///@{

    /**
     * @brief Checks if the data container has a value associated with a given variable.
     * @tparam TDataType The data type of the variable.
     * @param rThisVariable The variable for which the check is to be made.
     * @return True if the variable has an associated value in the container, otherwise false.
     */
    template<class TDataType>
    bool Has(const Variable<TDataType>& rThisVariable) const
    {
        return (std::find_if(mData.begin(), mData.end(), IndexCheck(rThisVariable.Key())) != mData.end());
    }

    template<class TAdaptorType> bool Has(const VariableComponent<TAdaptorType>& rThisVariable) const
    {
        return (std::find_if(mData.begin(), mData.end(), IndexCheck(rThisVariable.GetSourceVariable().Key())) != mData.end());
    }

    /**
     * @brief Checks if the data container is empty.
     * @return True if the container is empty, otherwise false.
     */
    bool IsEmpty() const
    {
        return mData.empty();
    }

    ///@}
    ///@name Input and output
    ///@{

    /**
     * @brief Retrieves a string representation of the data value container.
     * @return A string that describes the data value container.
     */
    virtual std::string Info() const
    {
        return std::string("data value container");
    }

    /**
     * @brief Outputs a brief description of the data value container to a given stream.
     * @param rOStream The output stream to which the information should be printed.
     */
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << "data value container";
    }

    /**
     * @brief Outputs the detailed data contents of the data value container to a given stream.
     * @details For each data entry, it prints the variable type and its associated value.
     * @param rOStream The output stream to which the data should be printed.
     */
    virtual void PrintData(std::ostream& rOStream) const
    {
        for(ConstantIteratorType i = mData.begin() ; i != mData.end() ; ++i)
        {
            rOStream <<"    ";
            i->first->Print(i->second, rOStream);
            rOStream << std::endl;
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
    ///@{

    /**
    * @brief Functor class used to check if a `ValueType` has a specific index key.
    * @details The `IndexCheck` class is designed to be used with algorithms like `std::find_if` to search for a `ValueType` with a specific source key.
    */
    class IndexCheck
    {
        std::size_t mI; /// The source key index to be checked against.

    public:

        /**
        * @brief Constructor that initializes the functor with a specific source key index.
        * @param I The source key index to be checked against.
        */
        IndexCheck(std::size_t I) : mI(I) {}

        /**
        * @brief Overloaded function call operator to compare the `ValueType`'s source key with the stored index.
        * @param I The `ValueType` whose source key is to be compared.
        * @return True if the `ValueType`'s source key matches the stored index, otherwise false.
        */
        bool operator()(const ValueType& I)
        {
            return I.first->Key() == mI;
        }
    };

    ///@}
    ///@name Static Member Variables
    ///@{

    ///@}
    ///@name Member Variables
    ///@{

    ContainerType mData; /// The data container considered

    ///@}
    ///@name Private Operators
    ///@{

    ///@}
    ///@name Private Operations
    ///@{

    ///@}
    ///@name Serialization
    ///@{

    /**
     * @class Serializer
     * @brief A fried class responsible for handling the serialization process.
     */
    friend class Serializer;

    /**
     * @brief Extract the object's state and uses the Serializer to store it.
     * @param rSerializer Serializer instance to be used for saving.
     */
    virtual void save(Serializer& rSerializer) const
    {
        std::size_t size = mData.size();
        rSerializer.save("Size", size);
        for(std::size_t i = 0 ; i < size ; i++)
        {
            rSerializer.save("Variable Name", mData[i].first->Name());
            mData[i].first->Save(rSerializer, mData[i].second);
        }
    }

    /**
     * @brief Set the object's state based on data provided by the Serializer.
     * @param rSerializer Serializer instance to be used for loading.
     */
    virtual void load(Serializer& rSerializer)
    {
        std::size_t size;
        rSerializer.load("Size", size);
        mData.resize(size);
        std::string name;
        for(std::size_t i = 0 ; i < size ; i++)
        {
            rSerializer.load("Variable Name", name);
            mData[i].first = KratosComponents<VariableData>::pGet(name);
            mData[i].first->Allocate(&(mData[i].second));
            mData[i].first->Load(rSerializer, mData[i].second);
        }
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

    ///@}
}; // Class DataValueContainer

///@}
///@name Type Definitions
///@{

///@}
///@name Input and output
///@{

/// input stream function
inline std::istream& operator >> (std::istream& rIStream,
                                  DataValueContainer& rThis)
{
    return rIStream;
}

/// output stream function
inline std::ostream& operator << (std::ostream& rOStream,
                                  const DataValueContainer& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}
///@}

}  // namespace Kratos.

#endif // KRATOS_DATA_VALUE_CONTAINER_H_INCLUDED  defined
