//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Jordi Cotela
//










#if !defined(KRATOS_CFD_VARIABLES_H_INCLUDED )
#define  KRATOS_CFD_VARIABLES_H_INCLUDED



// System includes


// External includes


// Project includes
#include "includes/define.h"
#include "containers/variable_component.h"
#include "containers/vector_component_adaptor.h"


#undef  KRATOS_EXPORT_MACRO
#define KRATOS_EXPORT_MACRO KRATOS_API

//TODO: move to the FluidDynamics application
namespace Kratos
{

    // Useful variables
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ADVPROJ )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( CONV_PROJ )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( PRESS_PROJ )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DIVPROJ )
    KRATOS_DEFINE_DOUBLE_VARIABLE( PRESSURE_OLD_IT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( C_SMAGORINSKY )
    KRATOS_DEFINE_DOUBLE_VARIABLE( MOLECULAR_VISCOSITY )
    KRATOS_DEFINE_DOUBLE_VARIABLE( TURBULENT_VISCOSITY )
    KRATOS_DEFINE_DOUBLE_VARIABLE( Y_WALL)
    KRATOS_DEFINE_VARIABLE( int, FRACTIONAL_STEP )
    KRATOS_DEFINE_VARIABLE( int, OSS_SWITCH )

    // Legacy variables
    KRATOS_DEFINE_DOUBLE_VARIABLE( DYNAMIC_TAU )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DYNAMIC_VISCOSITY)
    KRATOS_DEFINE_DOUBLE_VARIABLE( EFFECTIVE_VISCOSITY )
    KRATOS_DEFINE_DOUBLE_VARIABLE( KINEMATIC_VISCOSITY)
    KRATOS_DEFINE_DOUBLE_VARIABLE( THAWONE )
    KRATOS_DEFINE_DOUBLE_VARIABLE( THAWTWO )
    KRATOS_DEFINE_DOUBLE_VARIABLE( M )

    KRATOS_DEFINE_DOUBLE_VARIABLE( CROSS_WIND_STABILIZATION_FACTOR )

} // namespace Kratos

#undef  KRATOS_EXPORT_MACRO
#define KRATOS_EXPORT_MACRO KRATOS_NO_EXPORT

#endif // KRATOS_CFD_VARIABLES_H_INCLUDED  defined

