/*
==============================================================================
Kratos
A General Purpose Software for Multi-Physics Finite Element Analysis
Version 1.0 (Released on march 05, 2007).

Copyright 2007
Pooyan Dadvand, Riccardo Rossi
pooyan@cimne.upc.edu
rrossi@cimne.upc.edu
CIMNE (International Center for Numerical Methods in Engineering),
Gran Capita' s/n, 08034 Barcelona, Spain

Permission is hereby granted, free  of charge, to any person obtaining
a  copy  of this  software  and  associated  documentation files  (the
"Software"), to  deal in  the Software without  restriction, including
without limitation  the rights to  use, copy, modify,  merge, publish,
distribute,  sublicense and/or  sell copies  of the  Software,  and to
permit persons to whom the Software  is furnished to do so, subject to
the following condition:

Distribution of this code for  any  commercial purpose  is permissible
ONLY BY DIRECT ARRANGEMENT WITH THE COPYRIGHT OWNER.

The  above  copyright  notice  and  this permission  notice  shall  be
included in all copies or substantial portions of the Software.

THE  SOFTWARE IS  PROVIDED  "AS  IS", WITHOUT  WARRANTY  OF ANY  KIND,
EXPRESS OR  IMPLIED, INCLUDING  BUT NOT LIMITED  TO THE  WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT  SHALL THE AUTHORS OR COPYRIGHT HOLDERS  BE LIABLE FOR ANY
CLAIM, DAMAGES OR  OTHER LIABILITY, WHETHER IN AN  ACTION OF CONTRACT,
TORT  OR OTHERWISE, ARISING  FROM, OUT  OF OR  IN CONNECTION  WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

==============================================================================
*/

//
//   Project Name:        Kratos
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: 28 Aug 2017 $
//   Revision:            $Revision: 1.0 $
//
//


#if !defined(KRATOS_PAIR_INDEXED_OBJECT_H_INCLUDED )
#define  KRATOS_PAIR_INDEXED_OBJECT_H_INCLUDED



// System includes
#include <string>
#include <iostream>
#include <sstream>
#include <cstddef>


// External includes


// Project includes
#include "includes/define.h"


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
/** An object representing a pair integer for indexing.
*/
class PairIndexedObject
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of PairIndexedObject
    KRATOS_CLASS_POINTER_DEFINITION(PairIndexedObject);

    typedef std::size_t IndexType;

    typedef std::pair<std::size_t, std::size_t> result_type;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Empty constructor.
    PairIndexedObject() : mId1(0), mId2(0) {}

    /// Default constructor.
    PairIndexedObject(IndexType NewId1, IndexType NewId2) : mId1(NewId1), mId2(NewId2) {}

    /// Destructor.
    virtual ~PairIndexedObject() {}

    /// Copy constructor.
    PairIndexedObject(PairIndexedObject const& rOther) : mId1(rOther.mId1), mId2(rOther.mId2) {}


    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    PairIndexedObject& operator=(PairIndexedObject const& rOther)
    {
        mId1 = rOther.mId1;
        mId2 = rOther.mId2;

        return *this;
    }

    template<class TObjectType>
    result_type operator()(TObjectType const& rThisObject) const
    {
        return result_type(rThisObject.Id1(), rThisObject.Id2());
    }


    ///@}
    ///@name Operations
    ///@{


    ///@}
    ///@name Access
    ///@{

    IndexType Id1() const
    {
        return mId1;
    }

    IndexType Id2() const
    {
        return mId2;
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
        buffer << "indexed object # ("
               << mId1 << "," << mId2 << ")";
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

    IndexType mId1;
    IndexType mId2;


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
        rSerializer.save("Id1",mId1);
        rSerializer.save("Id2",mId2);
    }

    virtual void load(Serializer& rSerializer)
    {
        rSerializer.load("Id1",mId1);
        rSerializer.load("Id2",mId2);
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

}; // Class PairIndexedObject

class PairIndexedObjectCompare
{
public:
    typedef bool result_type;

    template<class TKeyType>
    result_type operator()(TKeyType const& Key1, TKeyType const& Key2) const
    {
        if (Key1.first != Key2.first)
        {
            return (Key1.first < Key2.first);
        }
        else
        {
            return (Key1.second < Key2.second);
        }
    }
};

class PairIndexedObjectEqual
{
public:
    typedef bool result_type;

    template<class TKeyType>
    result_type operator()(TKeyType const& Key1, TKeyType const& Key2) const
    {
        return (Key1.first == Key2.first) && (Key1.second == Key2.second);
    }
};

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


/// input stream function
inline std::istream& operator >> (std::istream& rIStream,
                                  PairIndexedObject& rThis);

/// output stream function
inline std::ostream& operator << (std::ostream& rOStream,
                                  const PairIndexedObject& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}
///@}


}  // namespace Kratos.

#endif // KRATOS_PAIR_INDEXED_OBJECT_H_INCLUDED  defined 


