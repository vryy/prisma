//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//


#if !defined(KRATOS_LEGACY_STRUCTURAL_APP_VARS_H_INCLUDED )
#define  KRATOS_LEGACY_STRUCTURAL_APP_VARS_H_INCLUDED

// System includes
#include <string>
#include <iostream>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/kratos_components.h"
#include "includes/ublas_interface.h"
#include "includes/node.h"
#include "includes/element.h"
#include "includes/condition.h"
#include "containers/variable.h"
#include "containers/variable_component.h"
#include "containers/vector_component_adaptor.h"
#include "containers/array_1d.h"
#include "containers/weak_pointer_vector.h"
#include "containers/periodic_variables_container.h"

#undef  KRATOS_EXPORT_MACRO
#define KRATOS_EXPORT_MACRO KRATOS_API

namespace Kratos
{
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_OLD )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_NULL )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_EINS )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_NULL_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_EINS_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_DT2 )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_NULL_DT2 )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAMBDA_EINS_DT2 )
    KRATOS_DEFINE_MATRIX_VARIABLE( LAMBDAS_T )
    KRATOS_DEFINE_MATRIX_VARIABLE( DELTA_LAMBDAS_T )
    KRATOS_DEFINE_MATRIX_VARIABLE( CONTACT_LINK_M )
    KRATOS_DEFINE_MATRIX_VARIABLE( AUXILIARY_MATRIX_1 )
    KRATOS_DEFINE_MATRIX_VARIABLE( ELASTIC_LEFT_CAUCHY_GREEN_OLD )
    KRATOS_DEFINE_MATRIX_VARIABLE( STRAIN_INTERPOLATION_OPERATOR )

    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_OLD )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_DT )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_NULL )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_NULL_DT )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ACCELERATION_NULL )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_EINS )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_EINS_DT )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ACCELERATION_EINS )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( VELOCITY_OLD )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ACCELERATION_OLD )

    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ROTATION_OLD )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ROTATION_DT )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ROTATION_NULL )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ROTATION_NULL_DT )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ANGULAR_ACCELERATION_NULL )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ROTATION_EINS )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ROTATION_EINS_DT )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( ANGULAR_ACCELERATION_EINS )

    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( FORCE_NULL )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( FORCE_EINS )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( FACE_LOAD_NULL )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( FACE_LOAD_EINS )

    KRATOS_DEFINE_VECTOR_VARIABLE( PENALTY_T )
    KRATOS_DEFINE_DOUBLE_VARIABLE( INITIAL_PENALTY_T )
    KRATOS_DEFINE_VECTOR_VARIABLE( LAMBDAS )
    KRATOS_DEFINE_VECTOR_VARIABLE( GAPS )
    KRATOS_DEFINE_VECTOR_VARIABLE( DELTA_LAMBDAS )
    KRATOS_DEFINE_VECTOR_VARIABLE( STICK )
    KRATOS_DEFINE_DOUBLE_VARIABLE( CONTACT_STICK )

    KRATOS_DEFINE_VARIABLE( bool, USE_DISTRIBUTED_PROPERTIES )
    KRATOS_DEFINE_VARIABLE( bool, SET_CALCULATE_REACTION )

    KRATOS_DEFINE_VARIABLE( int, CONTACT_RAMP )
    KRATOS_DEFINE_VARIABLE( int, CONTACT_SLAVE_INTEGRATION_POINT_INDEX )
    KRATOS_DEFINE_VARIABLE( int, CONTACT_DOUBLE_CHECK )
//    KRATOS_DEFINE_VARIABLE( int, FIRST_TIME_STEP )
//    KRATOS_DEFINE_VARIABLE( int, QUASI_STATIC_ANALYSIS )

    KRATOS_DEFINE_VARIABLE( int, INTEGRATION_ORDER )
    KRATOS_DEFINE_DOUBLE_VARIABLE( INTEGRATION_WEIGHT )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS(INTEGRATION_POINT_GLOBAL)
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS(INTEGRATION_POINT_GLOBAL_IN_REFERENCE_CONFIGURATION)
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS(INTEGRATION_POINT_GLOBAL_IN_CURRENT_CONFIGURATION)
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS(INTEGRATION_POINT_LOCAL)

//    KRATOS_DEFINE_VARIABLE( int, OSS_SWITCH )
    KRATOS_DEFINE_VARIABLE( int, WRINKLING_APPROACH )
    KRATOS_DEFINE_VARIABLE( int, CALCULATE_INSITU_STRESS )
//    KRATOS_DEFINE_VARIABLE( int, PERIODIC_PAIR_INDEX )
//    KRATOS_DEFINE_VARIABLE( int, STATIONARY )

//    KRATOS_DEFINE_VARIABLE( int, PARTITION_MASK )

//    KRATOS_DEFINE_DOUBLE_VARIABLE( FACE_HEAT_FLUX )

//    KRATOS_DEFINE_DOUBLE_VARIABLE( NODAL_VOLUME )

    KRATOS_DEFINE_DOUBLE_VARIABLE( PRESSURE_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( PRESSURE_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( WATER_PRESSURE_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( WATER_PRESSURE_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( WATER_PRESSURE_NULL )
    KRATOS_DEFINE_DOUBLE_VARIABLE( WATER_PRESSURE_NULL_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( WATER_PRESSURE_NULL_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( WATER_PRESSURE_EINS )
    KRATOS_DEFINE_DOUBLE_VARIABLE( WATER_PRESSURE_EINS_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( WATER_PRESSURE_EINS_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( REACTION_LAGRANGE_WATER_PRESSURE )

    KRATOS_DEFINE_DOUBLE_VARIABLE( AIR_PRESSURE_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( AIR_PRESSURE_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( AIR_PRESSURE_NULL )
    KRATOS_DEFINE_DOUBLE_VARIABLE( AIR_PRESSURE_NULL_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( AIR_PRESSURE_NULL_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( AIR_PRESSURE_EINS )
    KRATOS_DEFINE_DOUBLE_VARIABLE( AIR_PRESSURE_EINS_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( AIR_PRESSURE_EINS_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( REACTION_LAGRANGE_AIR_PRESSURE )
    KRATOS_DEFINE_DOUBLE_VARIABLE( SUCTION )
    KRATOS_DEFINE_3D_VARIABLE_WITH_COMPONENTS( AIR_FLOW )
//    KRATOS_DEFINE_DOUBLE_VARIABLE( FLAG_VARIABLE )

//    KRATOS_DEFINE_DOUBLE_VARIABLE( DP_EPSILON )
//    KRATOS_DEFINE_DOUBLE_VARIABLE( DP_ALPHA1 )
//    KRATOS_DEFINE_DOUBLE_VARIABLE( DP_K )

//    KRATOS_DEFINE_DOUBLE_VARIABLE( EQ_STRAIN_RATE )
//    KRATOS_DEFINE_DOUBLE_VARIABLE( RHS_WATER )
//    KRATOS_DEFINE_DOUBLE_VARIABLE( RHS_AIR )

    KRATOS_DEFINE_DOUBLE_VARIABLE( PERMEABILITY_28_DAYS )
    KRATOS_DEFINE_DOUBLE_VARIABLE( PERMEABILITY_1_DAY )
    KRATOS_DEFINE_DOUBLE_VARIABLE( PERMEABILITY_TRANSITION )

    KRATOS_DEFINE_DOUBLE_VARIABLE( TEMPERATURE_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( TEMPERATURE_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( TEMPERATURE_NULL )
    KRATOS_DEFINE_DOUBLE_VARIABLE( TEMPERATURE_NULL_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( TEMPERATURE_NULL_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( TEMPERATURE_EINS )
    KRATOS_DEFINE_DOUBLE_VARIABLE( TEMPERATURE_EINS_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( TEMPERATURE_EINS_ACCELERATION )

    KRATOS_DEFINE_DOUBLE_VARIABLE( DENSITY_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DENSITY_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DENSITY_NULL )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DENSITY_NULL_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DENSITY_NULL_ACCELERATION )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DENSITY_EINS )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DENSITY_EINS_DT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( DENSITY_EINS_ACCELERATION )

//    KRATOS_DEFINE_DOUBLE_VARIABLE( EFFECTIVE_VISCOSITY )
//    KRATOS_DEFINE_DOUBLE_VARIABLE( KINEMATIC_VISCOSITY)
//    KRATOS_DEFINE_DOUBLE_VARIABLE( DYNAMIC_VISCOSITY)
//    KRATOS_DEFINE_DOUBLE_VARIABLE( WEIGHT_FATHER_NODES )

    KRATOS_DEFINE_VARIABLE( int, PARENT_ELEMENT_ID )
    KRATOS_DEFINE_VARIABLE( int, INTEGRATION_POINT_INDEX )

    KRATOS_DEFINE_VARIABLE( int, IS_CONTACT_MASTER )
    KRATOS_DEFINE_VARIABLE( int, IS_CONTACT_SLAVE )
//    KRATOS_DEFINE_DOUBLE_VARIABLE( IS_BOUNDARY )
//    KRATOS_DEFINE_DOUBLE_VARIABLE( IS_VISITED )

    KRATOS_DEFINE_DOUBLE_VARIABLE( LAGRANGE_MULTIPLIER_CONSTRAINT )
    KRATOS_DEFINE_DOUBLE_VARIABLE( LAGRANGE_MULTIPLIER_CONSTRAINT_REACTION )

    KRATOS_DEFINE_VARIABLE( int, IS_SHAPE_FUNCTION_REQUIRED )
    KRATOS_DEFINE_VARIABLE( int, RESET_CONFIGURATION )
    KRATOS_DEFINE_VECTOR_VARIABLE( SHAPE_FUNCTION_VALUES )
    KRATOS_DEFINE_MATRIX_VARIABLE( SHAPE_FUNCTION_DERIVATIVES )

    KRATOS_DEFINE_VARIABLE( Node<3>::Pointer, ASSOCIATED_NODE )
    KRATOS_DEFINE_VARIABLE( Element::Pointer, ASSOCIATED_ELEMENT )
    KRATOS_DEFINE_VARIABLE( Condition::Pointer, ASSOCIATED_CONDITION )

    KRATOS_DEFINE_DOUBLE_VARIABLE( JACOBIAN_0 )

    KRATOS_DEFINE_VARIABLE( int, TIME_INTEGRATION_SCHEME )
    KRATOS_DEFINE_DOUBLE_VARIABLE( NEWMARK_ALPHAF )
    KRATOS_DEFINE_DOUBLE_VARIABLE( NEWMARK_ALPHAM )

}  // namespace Kratos.

#undef  KRATOS_EXPORT_MACRO
#define KRATOS_EXPORT_MACRO KRATOS_NO_EXPORT

#endif // KRATOS_LEGACY_STRUCTURAL_APP_VARS_H_INCLUDED  defined
