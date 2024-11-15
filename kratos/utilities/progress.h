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

#if !defined(KRATOS_PROGRESS_H_INCLUDED )
#define  KRATOS_PROGRESS_H_INCLUDED

#include "boost/version.hpp"

#if BOOST_VERSION < 108100
#include "boost/progress.hpp"
#else
#include "boost/timer/progress_display.hpp"
#endif

namespace Kratos
{

#if BOOST_VERSION < 108100
using progress_display = boost::progress_display;
#else
using progress_display = boost::timer::progress_display;
#endif

} // end namespace Kratos

#endif
