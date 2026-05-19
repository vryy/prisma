//
//   Project Name:        Kratos
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: 19 May 2026 $
//
//


#if !defined(KRATOS_INTERFACE_CONTAINER_H_INCLUDED)
#define  KRATOS_INTERFACE_CONTAINER_H_INCLUDED


// System includes
#include <iostream>
#include <cmath>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/model_part.h"


namespace Kratos
{

/*
 * A naive container to provide interfaces for computations requiring interfaces,
 * such as error estimator or discontinuous Galerkin element.
 */
class InterfaceContainer
{
public:

    ///@name Type Definitions
    ///@{

    KRATOS_CLASS_POINTER_DEFINITION(InterfaceContainer);

    typedef Element::GeometryType GeometryType;

    typedef ModelPart::ElementsContainerType ElementsContainerType;

    struct Interface
    {
        GeometryType face;                      // the representative geometry of the face, used for searching, indexing
        GeometryType::Pointer left  = nullptr;  // the real geometry interface (relatively left)
        GeometryType::Pointer right = nullptr;  // the real geometry interface (relatively right)
        Element::Pointer first  = nullptr;      // the element on the left side
        Element::Pointer second = nullptr;      // the element on the right side
        // mutable double jump = 0.0;
    };

    struct Comparator
    {
        bool operator()(const Interface& a, const Interface& b) const
        {
            return a.face.IsLess(b.face);
        }
    };

    typedef std::set<Interface, Comparator> InterfaceSet;

    ///@}
    ///@name Life Cycle
    ///@{

    InterfaceContainer()
    {}

    InterfaceContainer(const ModelPart& r_model_part)
    {
        mInterfaces = ConstructInterfaces(r_model_part.Elements());
    }

    ///@}
    ///@name Access
    ///@{

    const InterfaceSet& GetInterfaces() const
    {
        return mInterfaces;
    }

    ///@}
    ///@name Operations
    ///@{

    void AddInterface(const GeometryType& face, GeometryType::Pointer left, GeometryType::Pointer right,
        Element::Pointer first, Element::Pointer second)
    {
        Interface hf;
        hf.face = face;
        hf.left = left;
        hf.right = right;
        hf.first = first;
        hf.second = second;
        mInterfaces.insert(hf);
    }

    ///@}
    ///@name Input and output
    ///@{

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << "InterfaceContainer, size = " << mInterfaces.size();
    }

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const
    {
        for (auto hf : mInterfaces)
        {
            for (std::size_t i = 0; i < hf.face.size(); ++i)
            {
                rOStream << "n" << i+1 << ": " << hf.face[i].Id() << ", ";
            }

            if (hf.first != nullptr)
                rOStream << "e1: " << hf.first->Id();
            else
                rOStream << ", e1: null";
            if (hf.second != nullptr)
                rOStream << ", e2: " << hf.second->Id();
            else
                rOStream << ", e2: null";

            rOStream << std::endl;
        }
    }

    ///@}

private:

    InterfaceSet mInterfaces;

    ///@name Operations
    ///@{

    /// Construct the interfaces
    static InterfaceSet ConstructInterfaces(const ElementsContainerType& rElements)
    {
        InterfaceSet interface_set;

        for (auto it = rElements.ptr_begin(); it != rElements.ptr_end(); ++it)
        {
            auto faces = (*it)->GetGeometry().Faces();

            for (std::size_t i = 0; i < faces.size(); ++i)
            {
                Interface hf;
                hf.face = faces[i];

                auto itf = interface_set.find(hf);
                if (itf == interface_set.end())
                {
                    hf.left = faces(i);
                    hf.first = *it;
                    interface_set.insert(hf);
                }
                else
                {
                    hf.left = itf->left;
                    hf.first = itf->first;
                    hf.right = faces(i);
                    hf.second = *it;
                    interface_set.erase(itf);
                    interface_set.insert(hf);
                }
            }
        }

        return interface_set;
    }

    ///@}

};

///@name Input and output
///@{

/// output stream function
inline std::ostream& operator << (std::ostream& rOStream,
                                  const InterfaceContainer& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

}  // namespace Kratos.

#endif // KRATOS_INTERFACE_CONTAINER_H_INCLUDED  defined
