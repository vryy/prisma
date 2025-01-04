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

#ifdef KRATOS_USE_BACKTRACE
#define BOOST_STACKTRACE_USE_BACKTRACE
#endif
#include <boost/stacktrace.hpp>

#include "includes/kratos_exception.h"


namespace Kratos
{

    class ExceptionImplementation
    {
    public:
        /**
        * A user-defined message that explains what happened.
        */
        std::string message;

        /**
        * The generated stacktrace which is used to construct a nice error message when calling
        * what().
        */
        boost::stacktrace::stacktrace stacktrace;

        /**
         * The full message that is returned by what. This message is composed of all the other
         * information stored in this class.
         *
         * @note This needs to be stored here since we only return a `const char*` from what().
         */
        mutable std::string what_message_{};
    };

    std::string simplify_stacktrace_entry(const boost::stacktrace::frame& frame)
    {
        // Extract function name
        std::string function_name = frame.name();

        // Simplify argument names (e.g., strip function arguments)
        std::size_t pos = function_name.find('(');
        if (pos != std::string::npos)
        {
            function_name = function_name.substr(0, pos) + "(...)";
        }

        // Simplify template-heavy names (e.g., strip template arguments)
        pos = function_name.find('<');
        if (pos != std::string::npos)
        {
            // get the last name in the trail (the function name is called in runtime)
            std::string func_name;
            std::size_t pos2 = function_name.rfind("::"); // find the last occurrence of "::" in the long function name
            if (pos2 != std::string::npos)
            {
                func_name = function_name.substr(pos2 + 2);  // Skip past the "::"
            }

            function_name = function_name.substr(0, pos) + "<...>::" + func_name;
        }

        return function_name + " at " + frame.source_file() + ":" + std::to_string(frame.source_line());
    }

    std::string simplify_stacktrace(const boost::stacktrace::stacktrace& stack)
    {
        std::stringstream ss;
        for (std::size_t i = 0; i < stack.size(); ++i)
        {
            ss << " " << i << "# " << simplify_stacktrace_entry(stack[i]) << "\n";
        }
        return ss.str();
    }

    // This number tells the stack trace class to skip a certain number of frames that are introduced
    // by our exception framework itself. Users are not interested in these calls, and providing them
    // exposes unnecessary details.
    constexpr std::size_t skip_frames = 0;

    KratosException::KratosException()
        : std::exception(), mMessage("Unknown Error")
        , mCallStack()
        , pimpl_(new ExceptionImplementation{
            mMessage, boost::stacktrace::stacktrace(skip_frames, /*max_depth=*/-1)})
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
        , pimpl_(new ExceptionImplementation{
            mMessage, boost::stacktrace::stacktrace(skip_frames, /*max_depth=*/-1)})

    {
        add_to_call_stack(Location);
        update_what();
    }

    KratosException::KratosException(const KratosException& Other)
        : std::exception(Other), mMessage(Other.mMessage), mWhat(Other.mWhat), mCallStack(Other.mCallStack)
        , pimpl_(new ExceptionImplementation{
            mMessage, boost::stacktrace::stacktrace(skip_frames, /*max_depth=*/-1)})
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

        #ifdef KRATOS_USE_BACKTRACE
        buffer << "Stacktrace:" << std::endl;
        #else
        buffer << "Stacktrace: (please compile in Debug mode with backtrace support for filename and line number)" << std::endl;
        #endif
        buffer << simplify_stacktrace(pimpl_->stacktrace);
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
