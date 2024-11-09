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

#if !defined(KRATOS_SET_IDENTITY_FUNCTION_H_INCLUDED )
#define  KRATOS_SET_IDENTITY_FUNCTION_H_INCLUDED

// System includes

// External includes

// Project includes

namespace Kratos
{
///@name Kratos Classes
///@{

/**
 * @class SetIdentityFunction
 * @brief A functor that serves as the identity function.
 * @details This class provides two overloaded operator() functions, one for non-const objects
 * and another for const objects. The operator() returns the input object as it is,
 * effectively acting as an identity function.
 * The purpose of this functor is to allow objects to be used as keys in sets or other
 * containers that require comparison. By using this functor, you can avoid defining
 * custom comparison functions or operators when the object itself can be considered
 * for comparison.
 * @tparam TDataType The data type of the object that the functor operates on.
 * @author Pooyan Dadvand
 */
template<class TDataType> 
class SetIdentityFunction
{
public:

    typedef TDataType result_type; // to be STL-conformant

    /**
     * @brief Operator that returns a non-const reference to the input object.
     * @param data The input object of type TDataType.
     * @return A non-const reference to the same object as provided in the parameter.
     */
    TDataType& operator()(TDataType& data)
    {
        return data;
    }

    /**
     * @brief Operator that returns a const reference to the input object.
     * @param data The input object of type TDataType.
     * @return A const reference to the same object as provided in the parameter.
     */
    const TDataType& operator()(const TDataType& data) const
    {
        return data;
    }
};

///@}

}  // namespace Kratos.

#endif // KRATOS_SET_IDENTITY_FUNCTION_H_INCLUDED  defined 
