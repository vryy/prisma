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

// System includes


// External includes
#ifdef KRATOS_USE_MPI
#include "mpi.h"
#endif

// Project includes
#include "logger_message.h"

namespace Kratos
{
  LoggerMessage::MessageSource::MessageSource()
  {
#ifdef KRATOS_USE_MPI
    int flag;
    MPI_Initialized(&flag);
    if (flag)
      // using MPI_COMM_WORLD by default. In the future, it should be from the communicator.
      MPI_Comm_rank(MPI_COMM_WORLD, &mRank);
    else
      mRank = 0;
#else
    mRank = 0;
#endif
  }

  std::string LoggerMessage::Info() const
  {
    return "LoggerMessage";
  }

  /// Print information about this object.
  void LoggerMessage::PrintInfo(std::ostream& rOStream) const
  {
    rOStream << Info();
  }

  /// Print object's data.
  void LoggerMessage::PrintData(std::ostream& rOStream) const
  {
    rOStream << mMessage;
  }

  /// char stream function
  LoggerMessage& LoggerMessage::operator << (const char * rString)
  {
    mMessage.append(rString);

    return *this;
  }

  LoggerMessage& LoggerMessage::operator << (std::ostream& (*pf)(std::ostream&))
  {
    std::stringstream buffer;
    pf(buffer);

    mMessage.append(buffer.str());

    return *this;
  }

  LoggerMessage& LoggerMessage::operator << (CodeLocation const& TheLocation)
  {
    mLocation = TheLocation;

    return *this;
  }

  LoggerMessage& LoggerMessage::operator << (Severity const& TheSeverity)
  {
    mSeverity = TheSeverity;

    return *this;
  }

  LoggerMessage& LoggerMessage::operator << (Category const& TheCategory)
  {
    mCategory = TheCategory;

    return *this;
  }

  LoggerMessage& LoggerMessage::operator << (DistributedFilter const& TheFilter)
  {
    mDistributedFilter = TheFilter;

    return *this;
  }

  /// output stream function
  std::ostream& operator << (std::ostream& rOStream,
    const LoggerMessage& rThis)
  {
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
  }

}  // namespace Kratos.
