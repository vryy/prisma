//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:   Pooyan Dadvand
//
//

#include <sstream>

#include "includes/kratos_exception.h"


namespace Kratos
{

    KratosException::KratosException()
        : std::exception(), mMessage("Unknown Error")
        , mCallStack()
    {
        update_what();
    }

    KratosException::KratosException(const std::string& rWhat )
        : std::exception(), mMessage(rWhat), mCallStack()
        , pimpl_(new ExceptionImplementation{
            mMessage, boost::stacktrace::stacktrace(skip_frames, /*max_depth=*/-1)})
    {
        update_what();
    }

    KratosException::KratosException(const std::string& rWhat, const CodeLocation& Location)
        : std::exception(), mMessage(rWhat), mCallStack()

    {
        add_to_call_stack(Location);
        update_what();
    }

    KratosException::KratosException(const KratosException& Other)
        : std::exception(Other), mMessage(Other.mMessage), mWhat(Other.mWhat), mCallStack(Other.mCallStack)
    {
    }


    KratosException::~KratosException() throw()
    {
    }

    void KratosException::append_message(std::string const& rMessage)
    {
        mMessage.append(rMessage);
        update_what();
    }

    void KratosException::add_to_call_stack(CodeLocation const& TheLocation)
    {
        mCallStack.push_back(TheLocation);
        update_what();
    }

    void KratosException::update_what()
    {
        std::stringstream buffer;
        buffer << mMessage << std::endl;
        if(mCallStack.empty())
            buffer << "in Unknown Location";
        else
        {
            buffer << "in " << mCallStack[0] << std::endl;
            for(auto i = mCallStack.begin() + 1; i!= mCallStack.end(); i++)
                buffer << "   " << *i << std::endl;
        }
        mWhat = buffer.str();
    }

    const char* KratosException::what() const throw() //noexcept
    {
        return mWhat.c_str();
    }

    const CodeLocation KratosException::where() const
    {
        if(mCallStack.empty())
            return CodeLocation("Unknown File", "Unknown Location", 0);
        return mCallStack[0];
    }

    const std::string& KratosException::message() const
    {
        return mMessage;
    }

    std::string KratosException::Info() const
    {
        return "KratosException";
    }

      /// Print information about this object.
    void KratosException::PrintInfo(std::ostream& rOStream) const
    {
        rOStream << Info();
    }
      /// Print object's data.
    void KratosException::PrintData(std::ostream& rOStream) const
    {
        rOStream << "Error: " << mMessage << std::endl;
        rOStream << "   in: " << where();
    }


    KratosException& KratosException::operator << (CodeLocation const& TheLocation)
    {
        add_to_call_stack(TheLocation);

        return *this;
    }

    /// input stream function
    std::istream& operator >> (std::istream& rIStream, KratosException& rThis)
    {
        return rIStream;
    }

    /// char stream function
    KratosException& KratosException::operator << (const char * rString)
    {
        append_message(rString);

        return *this;
    }

    KratosException& KratosException::operator << (std::ostream& (*pf)(std::ostream&))
    {
        std::stringstream buffer;
        pf(buffer);

        append_message(buffer.str());

        return *this;
    }

    std::ostream& operator << (std::ostream& rOStream, const KratosException& rThis)
    {
        rThis.PrintInfo(rOStream);
        rOStream << std::endl;
        rThis.PrintData(rOStream);

        return rOStream;
    }

}  // namespace Kratos.
