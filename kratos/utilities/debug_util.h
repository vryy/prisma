//   
//   Project Name:        Kratos       
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: 25 Mar 2016 $
//   Revision:            $Revision: 1.0 $
//
//

#if !defined(KRATOS_DEBUG_UTIL_H_INCLUDED )
#define  KRATOS_DEBUG_UTIL_H_INCLUDED

// System includes
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>

// External includes 

// Project includes
#include "includes/define.h"


namespace Kratos
{
///@addtogroup ApplicationNameApplication
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


/// Short class definition.
/**
 */
class DebugUtil
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition
    KRATOS_CLASS_POINTER_DEFINITION(DebugUtil);
    
    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    DebugUtil() {}

    /// Destructor.
    virtual ~DebugUtil()
    {
    }

    ///@}
    ///@name Operators
    ///@{

    ///@}
    ///@name Operations
    ///@{

    template<class TOStream, class TData>
    static void Dump(TOStream& tos, const TData& r_data, const char* name, const char tc)
    {
        tos << name << " [" << r_data.size() << "]:";
#if __cplusplus > 199711L
        for(typename TData::const_iterator it = r_data.cbegin(); it != r_data.cend(); ++it)
#else
        for(typename TData::const_iterator it = r_data.begin(); it != r_data.end(); ++it)
#endif
            tos << tc << *it;
        tos << std::endl;
    }

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
    virtual std::string Info() const
    {
        std::stringstream buffer;
        buffer << "DebugUtil";
        return buffer.str();
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << "DebugUtil";
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {}

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

    ///@}
    ///@name Private Operators
    ///@{

    ///@}
    ///@name Private Operations
    ///@{
    
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
    DebugUtil& operator=(DebugUtil const& rOther)
    {
        return *this;
    }

    /// Copy constructor.
    DebugUtil(DebugUtil const& rOther)
    {
    }

    ///@}

}; // Class DebugUtil

///@}

///@name Type Definitions
///@{

///@}
///@name Input and output
///@{

/// input stream function
//inline std::istream& operator >>(std::istream& rIStream, DebugUtil& rThis)
//{
//    return rIStream;
//}

///// output stream function
//inline std::ostream& operator <<(std::ostream& rOStream,
//        const DebugUtil& rThis)
//{
//    rThis.PrintInfo(rOStream);
//    rOStream << std::endl;
//    rThis.PrintData(rOStream);

//    return rOStream;
//}
///@}

///@} addtogroup block

}// namespace Kratos.

#endif // KRATOS_DEBUG_UTIL_H_INCLUDED defined

