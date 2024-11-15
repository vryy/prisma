//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//
//

#if !defined(KRATOS_TIMING_H_INCLUDED )
#define  KRATOS_TIMING_H_INCLUDED

#include <ostream>

#include "boost/version.hpp"

#if BOOST_VERSION < 108100
#include "boost/timer.hpp"
#else
#include "boost/timer/timer.hpp"
#endif

namespace Kratos
{

#if BOOST_VERSION < 108100
using timer = boost::timer;
#else
using timer = boost::timer::cpu_timer;

inline std::ostream& operator<<(std::ostream& rOStream, const boost::timer::cpu_times& rThis)
{
    rOStream << rThis.wall;
    return rOStream;
}

#endif

} // end namespace Kratos

#endif
