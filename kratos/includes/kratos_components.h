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
//                   Riccardo Rossi
//

#if !defined(KRATOS_KRATOS_COMPONENTS_H_INCLUDED )
#define  KRATOS_KRATOS_COMPONENTS_H_INCLUDED

// System includes
#include <string>
#include <iostream>
#include <map>
#include <typeinfo>

// External includes

// Project includes
#include "includes/define.h"
#include "containers/variable_component.h"
#include "containers/vector_component_adaptor.h"
#include "containers/flags.h"

namespace Kratos
{

/**
 * @class KratosComponents
 * @brief KratosComponents class encapsulates a lookup table for a family of classes in a generic way.
 * @details Prototypes must be added to this table by unique names to be accessible by IO.
 * These names can be created automatically using C++ RTTI or given manually for each component.
 * In this design the manual approach is chosen, so shorter and more clear names can be given
 * to each component and also there is a flexibility to give different names to different
 * states of an object and create them via different prototypes.
 * For example having TriangularThermal and  both
 * @ingroup KratosCore
 * @author Pooyan Dadvand
 * @tparam TComponentType The type of components to be stored in this table.
 */
template<class TComponentType>
class KRATOS_API(KRATOS_CORE) KratosComponents
{
public:

    ///@name Type Definitions
    ///@{

    /// Pointer definition of KratosComponents
    KRATOS_CLASS_POINTER_DEFINITION(KratosComponents);

    typedef std::map<std::string, const TComponentType* > ComponentsContainerType;
    typedef typename ComponentsContainerType::value_type ValueType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    KratosComponents() {}

    /// Destructor.
    virtual ~KratosComponents() {}

    ///@}
    ///@name Operators
    ///@{

    ///@}
    ///@name Operations
    ///@{

    /**
     * @brief Adds a component to the collection.
     * @param rName the name of the component
     * @param rComponent the component to add
     * @throws std::runtime_error if a different object was already registered with the same name
     */
    static void Add(const std::string& rName, const TComponentType& rComponent)
    {
        // Check if a different object was already registered with this name, since this is undefined behavior
        typename ComponentsContainerType::iterator it_comp =  msComponents.find(rName);
        if (it_comp != msComponents.end() && typeid(*(it_comp->second)) != typeid(rComponent))
            KRATOS_ERROR << "An object of different type was already registered with name " << rName;
        msComponents.insert(ValueType(rName , &rComponent));
    }

    /**
     * @brief Removes a component with the specified name.
     * @param rName The name of the component to remove.
     * @throws ErrorType If the component with the specified name does not exist.
     */
    static void Remove(const std::string& rName)
    {
        std::size_t num_erased = msComponents.erase(rName);
        if (num_erased == 0)
            KRATOS_ERROR << "Trying to remove inexistent component " << rName;
    }

    /**
     * @brief Retrieves a component with the specified name.
     * @details This function retrieves a component from the ComponentsContainer using the provided name.
     * @param rName The name of the component to retrieve.
     * @return A reference to the retrieved component.
     * @note If the component is not found in debug, an error message will be printed and the program may terminate.
     */
    static const TComponentType& Get(const std::string& rName)
    {
        typename ComponentsContainerType::iterator it_comp = msComponents.find(rName);
        if (it_comp == msComponents.end())
            KRATOS_ERROR << GetMessageUnregisteredComponent(rName);
        return *(it_comp->second);
    }

    /**
     * @brief Registers the function.
     */
    static void Register()
    {
    }

    ///@}
    ///@name Access
    ///@{

    /**
     * @brief Retrieves the ComponentsContainer.
     * @details This function returns a reference to the ComponentsContainer, which stores all the components.
     * @return A reference to the ComponentsContainer.
     */
    static ComponentsContainerType& GetComponents()
    {
        return msComponents;
    }

    /**
     * @brief Retrieves the pointer to the ComponentsContainerType object.
     * @return Pointer to the ComponentsContainerType object.
     */
    static ComponentsContainerType* pGetComponents()
    {
        return &msComponents;
    }

    ///@}
    ///@name Inquiry
    ///@{

    /**
     * @brief Check if the given name exists in the set of components.
     * @param rName the name to check
     * @return true if the name exists, false otherwise
     */
    static bool Has(const std::string& rName)
    {
        return (msComponents.find(rName) != msComponents.end());
    }

    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "Kratos components";
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << "Kratos components";
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {
        for(typename ComponentsContainerType::const_iterator i = msComponents.begin() ; i != msComponents.end() ; ++i)
            rOStream << "    " << i->first << std::endl;
    }

    ///@}
    ///@name Friends
    ///@{

    ///@}
private:
    ///@name Static Member Variables
    ///@{

    static ComponentsContainerType msComponents; /// Component container

    ///@}
    ///@name Member Variables
    ///@{

    ///@}
    ///@name Private Operators
    ///@{

    ///@}
    ///@name Private Operations
    ///@{

    /**
     * @brief Retrieves a message indicating that the component with the given name is not registered.
     * @param rName The name of the component that is not registered.
     * @return A string containing the error message.
     */
    static std::string GetMessageUnregisteredComponent(const std::string& rName)
    {
        std::stringstream msg;
        msg << "The component \"" << rName << "\" is not registered!\nMaybe you need to import the application where it is defined?\nThe following components of this type are registered:" << std::endl;
        KratosComponents instance; // creating an instance for using "PrintData"
        instance.PrintData(msg);
        return msg.str();
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

    /// Assignment operator.
    KratosComponents& operator=(const KratosComponents& rOther);

    /// Copy constructor.
    KratosComponents(const KratosComponents& rOther);

    ///@}

}; // Class KratosComponents


///@}
template<>
class KRATOS_API(KRATOS_CORE) KratosComponents<VariableData>
{
public:

    ///@name Type Definitions
    ///@{

    /// Pointer definition of KratosComponents
    KRATOS_CLASS_POINTER_DEFINITION(KratosComponents);

    typedef std::map<std::string, VariableData*> ComponentsContainerType;
    typedef ComponentsContainerType::value_type ValueType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    KratosComponents() {}

    /// Destructor.
    virtual ~KratosComponents() {}

    ///@}
    ///@name Operators
    ///@{

    ///@}
    ///@name Operations
    ///@{

    /**
     * @brief Adds a new element to the msComponents map.
     * @param rName the name of the element to add
     * @param rComponent the VariableData object to add
     */
    static void Add(const std::string& rName, VariableData& rComponent)
    {
        msComponents.insert(ValueType(rName, &rComponent));
    }

    /**
     * @brief Remove a component from the list by name.
     * @param rName the name of the component to remove
     */
    static void Remove(const std::string& rName)
    {
        std::size_t num_erased = msComponents.erase(rName);
        if (num_erased == 0)
            KRATOS_ERROR << "Trying to remove inexistent component " << rName;
    }

    /**
     * @brief Get the size of the components.
     * @return The size of the components.
     */
    static std::size_t Size()
    {
        return msComponents.size();
    }

    /**
     * @brief Retrieves the VariableData with the specified name.
     * @details This function retrieves the VariableData associated with the provided name from the msComponents container.
     * @param rName The name of the VariableData to retrieve.
     * @return A reference to the retrieved VariableData.
     * @note If the VariableData is not found in debug, an error message will be printed and the program may terminate.
     */
    static VariableData& Get(const std::string& rName)
    {
        typename ComponentsContainerType::iterator it_comp =  msComponents.find(rName);
        if (it_comp == msComponents.end())
            KRATOS_ERROR << GetMessageUnregisteredVariable(rName);
        return *(it_comp->second);
    }

    /**
     * @brief Retrieves the variable data associated with the given name.
     * @param rName the name of the variable
     * @return a pointer to the variable data, or nullptr if not found
     */
    static VariableData* pGet(const std::string& rName)
    {
        typename ComponentsContainerType::iterator it_comp =  msComponents.find(rName);
        if (it_comp == msComponents.end())
            KRATOS_ERROR << GetMessageUnregisteredVariable(rName);
        return it_comp->second;
    }

    /**
     * @brief Registers the function.
     */
    static void Register()
    {
    }

    ///@}
    ///@name Access
    ///@{

    /**
     * @brief Retrieves the ComponentsContainer.
     * @details This function returns a reference to the ComponentsContainer, which stores all the components.
     * @return A reference to the ComponentsContainer.
     */
    static ComponentsContainerType& GetComponents()
    {
        return msComponents;
    }

    /**
     * @brief Returns a pointer to the ComponentsContainerType object.
     * @return a pointer to the ComponentsContainerType object
     */
    static ComponentsContainerType* pGetComponents()
    {
        return &msComponents;
    }

    ///@}
    ///@name Inquiry
    ///@{

    /**
     * @brief Checks if the specified name exists in the set of components.
     * @param rName the name to check
     * @return true if the name exists in the set, false otherwise
     */
    static bool Has(const std::string& rName)
    {
        return (msComponents.find(rName) != msComponents.end());
    }

    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "Kratos components <VariableData>";
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << "Kratos components <VariableData>";
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {
        for(ComponentsContainerType::const_iterator i = msComponents.begin() ; i != msComponents.end() ; ++i)
            rOStream << "    " << *(i->second) << std::endl;
    }

    ///@}
    ///@name Friends
    ///@{

    ///@}
private:

    ///@name Static Member Variables
    ///@{

    static ComponentsContainerType msComponents; /// Component container

    ///@}
    ///@name Member Variables
    ///@{

    ///@}
    ///@name Private Operators
    ///@{

    ///@}
    ///@name Private Operations
    ///@{

    /**
     * @brief Generates the error message for an unregistered variable.
     * @param rName The name of the unregistered variable.
     * @return The error message string.
     */
    static std::string GetMessageUnregisteredVariable(const std::string& rName)
    {
        std::stringstream msg;
        msg << "The variable \"" << rName << "\" is not registered!\nMaybe you need to import the application where it is defined?\nThe following variables are registered:" << std::endl;
        KratosComponents instance; // creating an instance for using "PrintData"
        instance.PrintData(msg);
        return msg.str();
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

    /// Assignment operator.
    KratosComponents& operator=(const KratosComponents& rOther);

    /// Copy constructor.
    KratosComponents(const KratosComponents& rOther);

    ///@}

}; // Class KratosComponents

#ifdef KratosCore_EXPORTS
template<class TComponentType>
typename KratosComponents<TComponentType>::ComponentsContainerType KratosComponents<TComponentType>::msComponents;
#endif

///@name Input and output
///@{

/// output stream function
template<class TComponentType>
inline std::ostream& operator << (std::ostream& rOStream,
                                  const KratosComponents<TComponentType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<bool>& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<int>& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<unsigned int>& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<double>& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<array_1d<double, 3> >& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<array_1d<double, 4> >& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<array_1d<double, 6> >& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<array_1d<double, 9> >& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<Vector>& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<Matrix>& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<std::string>& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const VariableComponent<VectorComponentAdaptor<array_1d<double, 3> > >& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Flags& rComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(const std::string& rName, const Variable<Flags>& rComponent);

template<class TComponentType> void AddKratosComponent(const std::string& rName, const TComponentType& rComponent) {}

}  // namespace Kratos.

#endif // KRATOS_KRATOS_COMPONENTS_H_INCLUDED  defined
