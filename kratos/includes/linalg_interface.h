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


#if !defined(KRATOS_LINALG_INTERFACE_H_INCLUDED )
#define  KRATOS_LINALG_INTERFACE_H_INCLUDED

#ifdef KRATOS_USE_BOOST_UBLAS_FOR_LINEAR_ALGEBRA

    #include "ublas_interface.h"

#elif KRATOS_USE_EIGEN_FOR_LINEAR_ALGEBRA

    #include "eigen_interface.h"

#else

    #pragma error "Linear algebra backend is not defined"

#endif

#endif // KRATOS_LINALG_INTERFACE_H_INCLUDED  defined
