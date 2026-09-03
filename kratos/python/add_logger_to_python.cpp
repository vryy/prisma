//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Carlos A. Roig
//
//

// External includes
#ifdef KRATOS_USE_MPI
#include "mpi.h"
#endif

// Project includes
#include "includes/define_python.h"
#include "utilities/logger.h"

namespace Kratos::Python {

namespace bp = boost::python;

/**
 * Prints the arguments from the python script using the Kratos Logger class. Implementation
 * @args tuple  representing the arguments of the function The first argument is the label
 * @kwargs dictionary  resenting key-value pairs for
 * @severity Logger::Severity The message level of severity @see Logger::Severity
 * @useKwargLabel bool Indicates if the label must be gather from kwargs (true) or is the first argument of the call (false)
 * name arguments
 * @printRank bool record the MPI rank in the output message.
 **/
void printImpl(
    bp::tuple args,
    bp::dict kwargs,
    Logger::Severity severity,
    bool useKwargLabel,
    LoggerMessage::DistributedFilter filterOption)
{
    if(bp::len(args) == 0)
        std::cout << "ERROR" << std::endl;

    std::stringstream buffer;
    Logger::Severity severityOption = severity;
    Logger::Category categoryOption = Logger::Category::STATUS;

    std::string label;
//     const char* label;

    // Get the label
    unsigned int to_skip = 0; //if the kwargs label is false, consider the first entry of the args as the label
    if(useKwargLabel) {
        if(kwargs.contains("label")) {
            label = bp::extract<std::string>(kwargs["label"]);
        } else {
            label = "";
        }
    } else {
        label = bp::extract<std::string>(args[0]); //if the kwargs label is false, consider the first entry of the args as the label
        to_skip = 1;
    }

    for(std::size_t counter = 0; counter < bp::len(args); ++counter)
    {
        std::string item = bp::extract<std::string>(bp::str(args[counter]));
        if(counter >= to_skip)
        {
            buffer << item;
            if(counter < bp::len(args))
                buffer << " ";
        }
    }

    // Extract the options
    if(kwargs.contains("severity")) {
        severityOption = bp::extract<Logger::Severity>(kwargs["severity"]);
    }

    if(kwargs.contains("category")) {
        categoryOption = bp::extract<Logger::Category>(kwargs["category"]);
    }

    // Send the message and options to the logger
    Logger logger(label);
    logger << buffer.str() << severityOption << categoryOption << std::endl;
}

bool isPrintingRank(bp::dict kwargs) {
    int rank = 0;
#ifdef KRATOS_USE_MPI
    int flag;
    MPI_Initialized(&flag);
    if (flag)
      MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif
    return rank == 0;
}

/**
 * Prints the arguments from the python script using the Kratos Logger class. Default function uses INFO severity.
 * @args bp::tuple bp::object representing the arguments of the function The first argument is the label
 * @kwargs bp::dictionary of bp::objects resenting key-value pairs for
 * name arguments
 **/
bp::object printDefault(bp::tuple args, bp::dict kwargs) {
    if (isPrintingRank(kwargs)) {
        printImpl(args, kwargs, Logger::Severity::INFO, true, LoggerMessage::DistributedFilter::FromRoot());
    }
    return bp::object();
}

/**
 * Prints the arguments from the python script using the Kratos Logger class using INFO severity.
 * @args bp::tuple bp::object representing the arguments of the function The first argument is the label
 * @kwargs bp::dictionary of bp::objects resenting key-value pairs for
 * name arguments
 **/
void printInfo(bp::tuple args, bp::dict kwargs) {
    if (isPrintingRank(kwargs)) {
        printImpl(args, kwargs, Logger::Severity::INFO, false, LoggerMessage::DistributedFilter::FromRoot());
    }
}

/**
 * Prints the arguments from the python script using the Kratos Logger class using WARNING severity.
 * @args bp::tuple bp::object representing the arguments of the function The first argument is the label
 * @kwargs bp::dictionary of bp::objects resenting key-value pairs for
 * name arguments
 **/
void printWarning(bp::tuple args, bp::dict kwargs) {
    if (isPrintingRank(kwargs)) {
        printImpl(args, kwargs, Logger::Severity::WARNING, false, LoggerMessage::DistributedFilter::FromRoot());
    }
}

void printDefaultOnAllRanks(bp::tuple args, bp::dict kwargs) {
    printImpl(args, kwargs, Logger::Severity::INFO, true, LoggerMessage::DistributedFilter::FromAllRanks());
}

void printInfoOnAllRanks(bp::tuple args, bp::dict kwargs) {
    printImpl(args, kwargs, Logger::Severity::INFO, false, LoggerMessage::DistributedFilter::FromAllRanks());
}

void printWarningOnAllRanks(bp::tuple args, bp::dict kwargs) {
    printImpl(args, kwargs, Logger::Severity::WARNING, false, LoggerMessage::DistributedFilter::FromAllRanks());
}

void  AddLoggerToPython()
{
    auto logger_output = bp::class_<LoggerOutput, LoggerOutput::Pointer, boost::noncopyable>("LoggerOutput", bp::no_init)
    .def("SetMaxLevel", &LoggerOutput::SetMaxLevel)
    .def("GetMaxLevel", &LoggerOutput::GetMaxLevel)
    .def("SetSeverity", &LoggerOutput::SetSeverity)
    .def("GetSeverity", &LoggerOutput::GetSeverity)
    .def("SetCategory", &LoggerOutput::SetCategory)
    .def("GetCategory", &LoggerOutput::GetCategory)
    .def("SetOption", &LoggerOutput::SetOption)
    .def("GetOption", &LoggerOutput::GetOption)
    ;
    logger_output.attr("WARNING_PREFIX") = LoggerOutput::WARNING_PREFIX;
    logger_output.attr("INFO_PREFIX") = LoggerOutput::INFO_PREFIX;
    logger_output.attr("DETAIL_PREFIX") = LoggerOutput::DETAIL_PREFIX;
    logger_output.attr("DEBUG_PREFIX") = LoggerOutput::DEBUG_PREFIX;
    logger_output.attr("TRACE_PREFIX") = LoggerOutput::TRACE_PREFIX;

    bp::class_<StdLoggerOutput, StdLoggerOutput::Pointer, bp::bases<LoggerOutput>, boost::noncopyable>("StdLoggerOutput", bp::no_init);

    bp::def("StdLoggerOutput", &StdLoggerOutput::GetInstance, bp::return_value_policy<bp::reference_existing_object>());

    bp::class_<Logger, boost::noncopyable> logger_scope("Logger", bp::no_init);
    logger_scope.def("Print", bp::raw_function(printDefault, 1)).staticmethod("Print"); // raw_function(printDefault,1))
    logger_scope.def("PrintInfo", printInfo).staticmethod("PrintInfo"); // raw_function(printInfo,1))
    logger_scope.def("PrintWarning", printWarning).staticmethod("PrintWarning"); //raw_function(printWarning,1))
    logger_scope.def("PrintOnAllRanks", printDefaultOnAllRanks).staticmethod("PrintOnAllRanks");
    logger_scope.def("PrintInfoOnAllRanks", printInfoOnAllRanks).staticmethod("PrintInfoOnAllRanks");
    logger_scope.def("PrintWarningOnAllRanks", printWarningOnAllRanks).staticmethod("PrintWarningOnAllRanks");
    logger_scope.def("Flush", &Logger::Flush);
    ;

    {
        bp::scope scope_owner = logger_scope;

        // Enums for Severity
        bp::enum_<Logger::Severity>("Severity")
        .value("WARNING", Logger::Severity::WARNING)
        .value("INFO", Logger::Severity::INFO)
        .value("DETAIL", Logger::Severity::DETAIL)
        .value("DEBUG", Logger::Severity::DEBUG)
        .value("TRACE", Logger::Severity::TRACE)
        .export_values();
    }

    {
        bp::scope scope_owner = logger_scope;

        // Enums for Category
        bp::enum_<Logger::Category>("Category")
        .value("STATUS", Logger::Category::STATUS)
        .value("CRITICAL", Logger::Category::CRITICAL)
        .value("STATISTICS", Logger::Category::STATISTICS)
        .value("PROFILING", Logger::Category::PROFILING)
        .value("CHECKING", Logger::Category::CHECKING)
        .export_values()
        ;
    }
}

}  // namespace Kratos::Python.
