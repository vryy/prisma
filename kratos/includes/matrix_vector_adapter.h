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


#if !defined(KRATOS_MATRIX_VECTOR_ADAPTER_H_INCLUDED )
#define  KRATOS_MATRIX_VECTOR_ADAPTER_H_INCLUDED

#if defined(KRATOS_USE_UBLAS_FOR_LINEAR_ALGEBRA)

    #include "includes/ublas_interface.h"

#elif defined(KRATOS_USE_AMATRIX_FOR_LINEAR_ALGEBRA)

    #error "AMatrix is not yet supported"

#elif defined(KRATOS_USE_EIGEN_FOR_LINEAR_ALGEBRA)

    #error "Eigen is not yet supported"

#else

    #error "The linear algebra backend is not yet defined"

#endif

#endif // KRATOS_MATRIX_VECTOR_ADAPTER_H_INCLUDED  defined
