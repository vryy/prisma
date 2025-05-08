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
//  Contributors:    Hoang-Giang Bui
//
//

#if !defined(KRATOS_INDEXED_OBJECT_H_INCLUDED )
#define  KRATOS_INDEXED_OBJECT_H_INCLUDED

// System includes
#include <string>
#include <iostream>
#include <sstream>
#include <cstddef>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/serializer.h"


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

/// Short class definition.
/** Detail class definition.
*/
template<typename TIndexType>
class KRATOS_API(KRATOS_CORE) BaseIndexedObject
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of BaseIndexedObject
    KRATOS_CLASS_POINTER_DEFINITION(BaseIndexedObject);

    typedef TIndexType IndexType;

    typedef TIndexType result_type;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    BaseIndexedObject(IndexType NewId = 0) : mId(NewId) {}

    /// Destructor.
    virtual ~BaseIndexedObject() {}

    /// Copy constructor.
    BaseIndexedObject(BaseIndexedObject const& rOther) : mId(rOther.mId) {}

    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    BaseIndexedObject& operator=(BaseIndexedObject const& rOther)
    {
        mId = rOther.mId;

        return *this;
    }

    template<class TObjectType>
    IndexType operator()(TObjectType const& rThisObject) const
    {
        return rThisObject.Id();
    }

    ///@}
    ///@name Operations
    ///@{


    ///@}
    ///@name Access
    ///@{

    IndexType Id() const
    {
        return mId;
    }

    IndexType GetId() const
    {
        return mId;
    }

    virtual void SetId(IndexType NewId)
    {
        mId = NewId;
    }

    /// TODO: remove this function when removing data_file_io object.
    IndexType& DepricatedIdAccess()
    {
        return mId;
    }

    ///@}
    ///@name Inquiry
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        std::stringstream buffer;
        buffer << "indexed object # "
               << mId;
        return buffer.str();
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << Info();
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {
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

    IndexType mId;

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

    virtual void save(Serializer& rSerializer) const
    {
        rSerializer.save("Id", mId);
    }

    virtual void load(Serializer& rSerializer)
    {
        rSerializer.load("Id", mId);
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

}; // Class BaseIndexedObject

///@}

///@name Type Definitions
///@{

using IndexedObject = BaseIndexedObject<KRATOS_INDEX_TYPE>;

///@}
///@name Input and output
///@{

/// input stream function
template<typename TIndexType>
inline std::istream& operator >> (std::istream& rIStream,
                                  BaseIndexedObject<TIndexType>& rThis)
{
    return rIStream;
}

/// output stream function
template<typename TIndexType>
inline std::ostream& operator << (std::ostream& rOStream,
                                  const BaseIndexedObject<TIndexType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

}  // namespace Kratos.

#endif // KRATOS_INDEXED_OBJECT_H_INCLUDED  defined
