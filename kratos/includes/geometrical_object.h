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
//

#if !defined(KRATOS_GEOMETRICAL_OBJECT_H_INCLUDED )
#define  KRATOS_GEOMETRICAL_OBJECT_H_INCLUDED

// System includes
#include <string>
#include <iostream>
#include <sstream>
#include <cstddef>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/node.h"
#include "containers/flags.h"
#include "geometries/geometry.h"
#include "utilities/indexed_object.h"

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
 * @class GeometricalObject
 * @ingroup KratosCore
 * @brief This defines the geometrical object, base definition of the element and condition entities
 * @details Derives from IndexedObject, so it has an ID, and from Flags
 * @author Pooyan Dadvand
*/
template<class TNodeType>
class GeometricalObject : public IndexedObject, public Flags
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of GeometricalObject
    KRATOS_CLASS_POINTER_DEFINITION(GeometricalObject);

    /// Definition of the node type
    typedef TNodeType NodeType;

    /// The geometry type definition
    typedef Geometry<NodeType> GeometryType;

    /// Defines the index type
    typedef IndexedObject::IndexType IndexType;

    /// Defines the result type
    typedef IndexedObject::result_type result_type;

    /// Defines the size type
    typedef IndexedObject::result_type SizeType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    GeometricalObject(IndexType NewId = 0)
        : IndexedObject(NewId),
          Flags(),
          mpGeometry()
    {}

    /// Default constructor.
    GeometricalObject(IndexType NewId, typename GeometryType::Pointer pGeometry)
        : IndexedObject(NewId),
          Flags(),
          mpGeometry(pGeometry)
    {}

    /// Destructor.
    ~GeometricalObject() override {}

    /// Copy constructor.
    GeometricalObject(GeometricalObject const& rOther)
        : IndexedObject(rOther.Id()),
          Flags(rOther),
          mpGeometry(rOther.mpGeometry)
    {}


    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    GeometricalObject& operator=(GeometricalObject const& rOther)
    {
        IndexedObject::operator=(rOther);
        Flags::operator =(rOther);
        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    ///@}
    ///@name Access
    ///@{

    /**
     * @brief Returns the pointer to the geometry
     * @return The pointer of the geometry
     */
    typename GeometryType::Pointer pGetGeometry()
    {
        return mpGeometry;
    }

    /**
     * @brief Returns the pointer to the geometry (const version)
     * @return The pointer of the geometry
     */
    const typename GeometryType::Pointer pGetGeometry() const
    {
        return mpGeometry;
    }

    /**
     * @brief Returns the reference of the geometry
     * @return The reference of the geometry
     */
    GeometryType& GetGeometry()
    {
        return *mpGeometry;
    }

    /**
     * @brief Returns the reference of the geometry (const version)
     * @return The reference of the geometry
     */
    GeometryType const& GetGeometry() const
    {
        return *mpGeometry;
    }

    /**
     * @brief Returns the flags of the object
     * @return The  flags of the object
     */
    Flags& GetFlags()
    {
        return *this;
    }

    /**
     * @brief Returns the flags of the object (const version)
     * @return The  flags of the object
     */
    Flags const& GetFlags() const
    {
        return *this;
    }

    /**
     * @brief Sets the flags of the object
     * @param rThisFlags The flags to be set
     */
    void SetFlags(Flags const& rThisFlags)
    {
        Flags::operator=(rThisFlags);
    }

    ///@}
    ///@name Inquiry
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    std::string Info() const override
    {
        std::stringstream buffer;
        buffer << "Geometrical object # "
               << Id();
        return buffer.str();
    }

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << Info();
    }

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const override
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

    typename GeometryType::Pointer mpGeometry; /// Pointer to the entity geometry

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

    void save(Serializer& rSerializer) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, IndexedObject );
        KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, Flags );
        rSerializer.save("Geometry", mpGeometry);
    }

    void load(Serializer& rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, IndexedObject );
        KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, Flags );
        rSerializer.load("Geometry", mpGeometry);
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

}; // Class GeometricalObject

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{

/// input stream function
template<class TNodeType>
inline std::istream& operator >> (std::istream& rIStream, GeometricalObject<TNodeType>& rThis)
{
    return rIStream;
}

/// output stream function
template<class TNodeType>
inline std::ostream& operator << (std::ostream& rOStream, const GeometricalObject<TNodeType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

template<> struct DataTypeToString<WeakPointerVector<GeometricalObject<Node<3> > > > { static inline constexpr const char* Get() {return "WeakPointerVector<GeometricalObject<Node<3>>>";} };

}  // namespace Kratos.

#endif // KRATOS_GEOMETRICAL_OBJECT_H_INCLUDED  defined
