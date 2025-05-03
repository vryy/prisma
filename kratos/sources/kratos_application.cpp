//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//


// This define must be HERE
#define DKRATOS_EXPORT_INTERFACE_2 1

// System includes
#include <string>
#include <iostream>
#include <vector>

// External includes

// Project includes
#include "includes/define.h"
#include "includes/variables.h"
#include "includes/kernel.h"
#include "includes/node.h"
#include "includes/element.h"
#include "includes/condition.h"
#include "includes/constitutive_law.h"
#include "includes/geometrical_object.h"
#include "includes/master_slave_constraint.h"

#include "geometries/line_2d.h"
#include "geometries/line_2d_2.h"
#include "geometries/line_2d_3.h"
#include "geometries/line_3d_2.h"
#include "geometries/line_gl_3d_2.h"
#include "geometries/line_3d_3.h"
#include "geometries/point.h"
#include "geometries/point_2d.h"
#include "geometries/point_3d.h"
#include "geometries/triangle_2d_3.h"
#include "geometries/triangle_2d_6.h"
#include "geometries/triangle_3d_3.h"
#include "geometries/triangle_3d_6.h"
#include "geometries/quadrilateral_2d_4.h"
#include "geometries/quadrilateral_2d_8.h"
#include "geometries/quadrilateral_2d_9.h"
#include "geometries/quadrilateral_3d_4.h"
#include "geometries/quadrilateral_3d_8.h"
#include "geometries/quadrilateral_3d_9.h"
#include "geometries/tetrahedra_3d_4.h"
#include "geometries/tetrahedra_3d_10.h"
#include "geometries/prism_3d_6.h"
#include "geometries/prism_3d_15.h"
#include "geometries/hexahedra_3d_8.h"
#include "geometries/hexahedra_3d_20.h"
#include "geometries/hexahedra_3d_27.h"

#include "includes/deprecated_variables.h"
#include "includes/convection_diffusion_settings.h"
#include "includes/radiation_settings.h"

#include "includes/kratos_flags.h"

#include "includes/kratos_application.h"

namespace Kratos
{

  KratosApplication::KratosApplication() : // DEPRECATED
    mApplicationName("ApplicationName"),
    mCondition3D( 0, Element::GeometryType::Pointer( new Triangle3D3<Node<3> >( Element::GeometryType::PointsArrayType( 3, Node<3>() ) ) ) ),
    mCondition2D( 0, Element::GeometryType::Pointer( new Geometry<Node<3> >( Element::GeometryType::PointsArrayType( 2, Node<3>() ) ) ) ),
    mPeriodicCondition(0, Element::GeometryType::Pointer( new Line2D2<Node<3> >( Element::GeometryType::PointsArrayType( 2, Node<3>() ) ) ) ),
    mPeriodicConditionEdge(0, Element::GeometryType::Pointer( new Quadrilateral3D4<Node<3> >( Element::GeometryType::PointsArrayType( 4, Node<3>() ) ) ) ),
    mPeriodicConditionCorner(0, Element::GeometryType::Pointer( new Hexahedra3D8<Node<3> >( Element::GeometryType::PointsArrayType( 8, Node<3>() ) ) ) ),
    mElement3D4N( 0, Element::GeometryType::Pointer( new Tetrahedra3D4<Node<3> >( Element::GeometryType::PointsArrayType( 4, Node<3>() ) ) ) ),
    mElement2D3N( 0, Element::GeometryType::Pointer( new Triangle2D3<Node<3> >( Element::GeometryType::PointsArrayType( 3, Node<3>() ) ) ) ),
    mpVariableData( KratosComponents<VariableData>::pGetComponents() ),
    mpIntVariables( KratosComponents<Variable<int> >::pGetComponents() ),
    mpUnsignedIntVariables( KratosComponents<Variable<unsigned int> >::pGetComponents() ),
    mpDoubleVariables( KratosComponents<Variable<double> >::pGetComponents() ),
    mpArray1DVariables( KratosComponents<Variable<array_1d<double, 3> > >::pGetComponents() ),
    mpVectorVariables( KratosComponents<Variable<Vector> >::pGetComponents() ),
    mpMatrixVariables( KratosComponents<Variable<Matrix> >::pGetComponents() ),
    mpArray1DVariableComponents( KratosComponents<VariableComponent<VectorComponentAdaptor<array_1d<double, 3> > > >::pGetComponents() ),
    mpElements( KratosComponents<Element>::pGetComponents() ),
    mpConditions( KratosComponents<Condition>::pGetComponents() ),
    mpRegisteredObjects( &( Serializer::GetRegisteredObjects() ) ),
    mpRegisteredObjectsName( &( Serializer::GetRegisteredObjectsName() ) ),

    // Master-Slave Constraint
    mMasterSlaveConstraint(),
    mLinearConstraint(),
    mLinearMasterSlaveConstraint()

  {}

  KratosApplication::KratosApplication(const std::string& Name) :
    mApplicationName(Name),
    mCondition3D( 0, Element::GeometryType::Pointer( new Triangle3D3<Node<3> >( Element::GeometryType::PointsArrayType( 3, Node<3>() ) ) ) ),
    mCondition2D( 0, Element::GeometryType::Pointer( new Geometry<Node<3> >( Element::GeometryType::PointsArrayType( 2, Node<3>() ) ) ) ),
    mPeriodicCondition(0, Element::GeometryType::Pointer( new Line2D2<Node<3> >( Element::GeometryType::PointsArrayType( 2, Node<3>() ) ) ) ),
    mPeriodicConditionEdge(0, Element::GeometryType::Pointer( new Quadrilateral3D4<Node<3> >( Element::GeometryType::PointsArrayType( 4, Node<3>() ) ) ) ),
    mPeriodicConditionCorner(0, Element::GeometryType::Pointer( new Hexahedra3D8<Node<3> >( Element::GeometryType::PointsArrayType( 8, Node<3>() ) ) ) ),
    mElement3D4N( 0, Element::GeometryType::Pointer( new Tetrahedra3D4<Node<3> >( Element::GeometryType::PointsArrayType( 4, Node<3>() ) ) ) ),
    mElement2D3N( 0, Element::GeometryType::Pointer( new Triangle2D3<Node<3> >( Element::GeometryType::PointsArrayType( 3, Node<3>() ) ) ) ),
    mpVariableData( KratosComponents<VariableData>::pGetComponents() ),
    mpIntVariables( KratosComponents<Variable<int> >::pGetComponents() ),
    mpUnsignedIntVariables( KratosComponents<Variable<unsigned int> >::pGetComponents() ),
    mpDoubleVariables( KratosComponents<Variable<double> >::pGetComponents() ),
    mpArray1DVariables( KratosComponents<Variable<array_1d<double, 3> > >::pGetComponents() ),
    mpVectorVariables( KratosComponents<Variable<Vector> >::pGetComponents() ),
    mpMatrixVariables( KratosComponents<Variable<Matrix> >::pGetComponents() ),
    mpArray1DVariableComponents( KratosComponents<VariableComponent<VectorComponentAdaptor<array_1d<double, 3> > > >::pGetComponents() ),
    mpElements( KratosComponents<Element>::pGetComponents() ),
    mpConditions( KratosComponents<Condition>::pGetComponents() ),
    mpRegisteredObjects( &( Serializer::GetRegisteredObjects() ) ),
    mpRegisteredObjectsName( &( Serializer::GetRegisteredObjectsName() ) ),

    // Master-Slave Constraint
    mMasterSlaveConstraint(),
    mLinearConstraint(),
    mLinearMasterSlaveConstraint()

  {}

  void KratosApplication::RegisterVariables()
  {

      KratosApplication::RegisterDeprecatedVariables();
      KratosApplication::RegisterC2CVariables(); //TODO: move to application
      KratosApplication::RegisterCFDVariables(); //TODO: move to application
      KratosApplication::RegisterDEMVariables(); //TODO: move to application
      KratosApplication::RegisterLegacyStructuralAppVariables(); //TODO: move to application

      // Variables that should be moved to applications (but have too many dependencies)
      KRATOS_REGISTER_VARIABLE( FRACTIONAL_STEP )
      KRATOS_REGISTER_VARIABLE( POWER_LAW_N )
      KRATOS_REGISTER_VARIABLE( POWER_LAW_K )
      KRATOS_REGISTER_VARIABLE( EQ_STRAIN_RATE )
      KRATOS_REGISTER_VARIABLE( YIELD_STRESS )

      // Variables with general names that can be used across applications
      KRATOS_REGISTER_VARIABLE( MU )
      KRATOS_REGISTER_VARIABLE( TAU )
      KRATOS_REGISTER_VARIABLE( ALPHA )

      //--------------- GENERAL VARIABLES FOR MULTIPLE APPLICATIONS -------------------//
      KRATOS_REGISTER_VARIABLE( DOMAIN_SIZE )

      //STRATEGIES
      KRATOS_REGISTER_VARIABLE( LOAD_RESTART )
      KRATOS_REGISTER_VARIABLE( COMPUTE_LUMPED_MASS_MATRIX )

      KRATOS_REGISTER_VARIABLE( STEP )
      KRATOS_REGISTER_VARIABLE( TIME_STEPS )
      KRATOS_REGISTER_VARIABLE( RIGID_BODY_ID )

      KRATOS_REGISTER_VARIABLE( TIME )
      KRATOS_REGISTER_VARIABLE( START_TIME )
      KRATOS_REGISTER_VARIABLE( END_TIME )
      KRATOS_REGISTER_VARIABLE( DELTA_TIME )

      KRATOS_REGISTER_VARIABLE( RESIDUAL_NORM )
      KRATOS_REGISTER_VARIABLE( CONVERGENCE_RATIO )


      //ROTATION
      //movement
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( ROTATION )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( DELTA_ROTATION )
      //reaction
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( TORQUE )
      //movement time derivatives
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( ANGULAR_VELOCITY )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( ANGULAR_ACCELERATION )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( VELOCITY_LAPLACIAN )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( VELOCITY_LAPLACIAN_RATE )

      //DISPLACEMENT
      //movement
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT )
      // std::cout << "Variable " << DISPLACEMENT << " is registerred" << std::endl;
      //reaction
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( REACTION )
      //movement time derivatives
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( VELOCITY )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( ACCELERATION )


      //THERMAL DOFS
      KRATOS_REGISTER_VARIABLE( TEMPERATURE )
      // std::cout << "Variable " << TEMPERATURE << " is registerred" << std::endl;

      //PRESSURE DOFS
      KRATOS_REGISTER_VARIABLE( PRESSURE )

      //EXTERNAL CONDITIONS
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( VOLUME_ACCELERATION )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( FORCE )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( MOMENT )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( FACE_LOAD )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( NORMAL )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( BODY_FORCE ) //to be deleted ?

      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( FORCE_RESIDUAL )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( MOMENT_RESIDUAL )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( INTERNAL_FORCE )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( EXTERNAL_FORCE )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( CONTACT_FORCE )

      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( LINEAR_MOMENTUM )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( ANGULAR_MOMENTUM )

      KRATOS_REGISTER_VARIABLE( MARKER_LABELS )
      KRATOS_REGISTER_VARIABLE( MARKER_MESHES )

      KRATOS_REGISTER_VARIABLE( CONSTRAINT_LABELS )
      KRATOS_REGISTER_VARIABLE( CONSTRAINT_MESHES )

      KRATOS_REGISTER_VARIABLE( LOAD_LABELS )
      KRATOS_REGISTER_VARIABLE( LOAD_MESHES )

      KRATOS_REGISTER_VARIABLE( NEGATIVE_FACE_PRESSURE )
      KRATOS_REGISTER_VARIABLE( POSITIVE_FACE_PRESSURE )

      KRATOS_REGISTER_VARIABLE( FACE_HEAT_FLUX )


      //CONSTITUTIVE LAW AND PROPERTIES
      KRATOS_REGISTER_CONSTITUTIVE_LAW_VARIABLE( CONSTITUTIVE_LAW )
      KRATOS_REGISTER_VARIABLE( DENSITY )
      KRATOS_REGISTER_VARIABLE( YOUNG_MODULUS )
      KRATOS_REGISTER_VARIABLE( POISSON_RATIO )
      KRATOS_REGISTER_VARIABLE( THICKNESS )
      KRATOS_REGISTER_VARIABLE( STABILIZATION_FACTOR )

      KRATOS_REGISTER_VARIABLE( TIME_INTEGRATION_THETA )

      KRATOS_REGISTER_VARIABLE( NEWMARK_GAMMA )
      KRATOS_REGISTER_VARIABLE( NEWMARK_BETA )
      KRATOS_REGISTER_VARIABLE( BOSSAK_ALPHA )
      KRATOS_REGISTER_VARIABLE( EQUILIBRIUM_POINT )

//      KRATOS_REGISTER_VARIABLE( LOCAL_INERTIA )
      KRATOS_REGISTER_VARIABLE( LOCAL_CONSTITUTIVE_MATRIX )

      //STRAIN MEASURES
      KRATOS_REGISTER_VARIABLE( GREEN_LAGRANGE_STRAIN_TENSOR )

      //STRESS MEASURES
      KRATOS_REGISTER_VARIABLE( CAUCHY_STRESS_TENSOR )
      KRATOS_REGISTER_VARIABLE( PK2_STRESS_TENSOR )

      //GEOMETRICAL
      KRATOS_REGISTER_VARIABLE( NODAL_H )

      KRATOS_REGISTER_VARIABLE( NEIGHBOUR_NODES )
      KRATOS_REGISTER_VARIABLE( FATHER_NODES )
      KRATOS_REGISTER_VARIABLE( NEIGHBOUR_ELEMENTS )
      KRATOS_REGISTER_VARIABLE( NEIGHBOUR_CONDITIONS )

      //ENERGIES
      KRATOS_REGISTER_VARIABLE( KINETIC_ENERGY )
      KRATOS_REGISTER_VARIABLE( INTERNAL_ENERGY )
      KRATOS_REGISTER_VARIABLE( STRAIN_ENERGY )
      KRATOS_REGISTER_VARIABLE( EXTERNAL_ENERGY )

      //--------------- GENERAL VARIABLES FOR MULTIPLE APPLICATIONS -------------------//



      //--------------- STRUCTURAL Application -------------------//

      KRATOS_REGISTER_VARIABLE( FIRST_TIME_STEP )
      KRATOS_REGISTER_VARIABLE( QUASI_STATIC_ANALYSIS )

      KRATOS_REGISTER_VARIABLE( NL_ITERATION_NUMBER )
      KRATOS_REGISTER_VARIABLE( PERIODIC_PAIR_INDEX )
      KRATOS_REGISTER_VARIABLE( STATIONARY )
      KRATOS_REGISTER_VARIABLE( ACTIVATION_LEVEL )

      KRATOS_REGISTER_VARIABLE( FRICTION_COEFFICIENT )
      KRATOS_REGISTER_VARIABLE( LAMBDA )
      KRATOS_REGISTER_VARIABLE( MIU )
      KRATOS_REGISTER_VARIABLE( NORMAL_CONTACT_STRESS )
      KRATOS_REGISTER_VARIABLE( TANGENTIAL_CONTACT_STRESS )

      KRATOS_REGISTER_VARIABLE( PARTITION_INDEX )
      KRATOS_REGISTER_VARIABLE( TEMPERATURE_OLD_IT )
      KRATOS_REGISTER_VARIABLE( VISCOSITY )
      KRATOS_REGISTER_VARIABLE( ERROR_RATIO )
      KRATOS_REGISTER_VARIABLE( RHS_WATER )
      KRATOS_REGISTER_VARIABLE( RHS_AIR )
      KRATOS_REGISTER_VARIABLE( WEIGHT_FATHER_NODES )
      KRATOS_REGISTER_VARIABLE( INITIAL_PENALTY )
      KRATOS_REGISTER_VARIABLE( DP_EPSILON )
      KRATOS_REGISTER_VARIABLE( DP_ALPHA1 )
      KRATOS_REGISTER_VARIABLE( DP_K )
      KRATOS_REGISTER_VARIABLE( INTERNAL_FRICTION_ANGLE )
      KRATOS_REGISTER_VARIABLE( K0 )
      KRATOS_REGISTER_VARIABLE( NODAL_VOLUME )

      KRATOS_REGISTER_VARIABLE( WATER_PRESSURE )
      KRATOS_REGISTER_VARIABLE( REACTION_WATER_PRESSURE )

      KRATOS_REGISTER_VARIABLE( AIR_PRESSURE )
      KRATOS_REGISTER_VARIABLE( REACTION_AIR_PRESSURE )
      KRATOS_REGISTER_VARIABLE( FLAG_VARIABLE )
      KRATOS_REGISTER_VARIABLE( DISTANCE )

      KRATOS_REGISTER_VARIABLE( LAGRANGE_AIR_PRESSURE )
      KRATOS_REGISTER_VARIABLE( LAGRANGE_WATER_PRESSURE )
      KRATOS_REGISTER_VARIABLE( LAGRANGE_TEMPERATURE )

      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( MOMENTUM )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( LAGRANGE_DISPLACEMENT )

      KRATOS_REGISTER_VARIABLE( ELEMENTAL_DISTANCES )
      KRATOS_REGISTER_VARIABLE( MATERIAL_PARAMETERS )
      KRATOS_REGISTER_VARIABLE( INTERNAL_VARIABLES )
      KRATOS_REGISTER_VARIABLE( INSITU_STRESS )

      KRATOS_REGISTER_VARIABLE( PENALTY )
      KRATOS_REGISTER_VARIABLE( NORMAL_STRESS )
      KRATOS_REGISTER_VARIABLE( TANGENTIAL_STRESS )
      KRATOS_REGISTER_VARIABLE( STRESSES )
      KRATOS_REGISTER_VARIABLE( STRAIN )

      KRATOS_REGISTER_VARIABLE( NEIGHBOURS_INDICES )

      KRATOS_REGISTER_VARIABLE( INERTIA )

      KRATOS_REGISTER_VARIABLE( NEIGHBOUR_EMBEDDED_FACES )
      KRATOS_REGISTER_VARIABLE( CONVECTION_DIFFUSION_SETTINGS )
      KRATOS_REGISTER_VARIABLE( RADIATION_SETTINGS )

      //--------------- STRUCTURAL Application -------------------//

      //--------------- MULTISCALE Application -------------------//

      KRATOS_REGISTER_VARIABLE( INITIAL_STRAIN )
      KRATOS_REGISTER_VARIABLE( COEFFICIENT_THERMAL_EXPANSION )
      KRATOS_REGISTER_VARIABLE( CHARACTERISTIC_LENGTH_MULTIPLIER )

      //--------------- Incompressible Fluid Application ---------//


      //--------------- ALE Application -------------------//

      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( DETERMINANT )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( ELEMENTSHAPE )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( MESH_VELOCITY )
      KRATOS_REGISTER_VARIABLE( AUX_MESH_VAR )


      //--------------- ALE Application -------------------//

      //--------------- Adjoint Fluid Application -------------------//
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( ADJOINT_VELOCITY )
      KRATOS_REGISTER_VARIABLE( ADJOINT_PRESSURE )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( PRIMAL_VELOCITY )
      KRATOS_REGISTER_VARIABLE( PRIMAL_PRESSURE )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( SHAPE_SENSITIVITY )
      KRATOS_REGISTER_VARIABLE( NORMAL_SENSITIVITY )

      //--------------- Adjoint Fluid Application -------------------//


      //--------------- FOTOELECTRIC Application -------------------//


      //--------------- PFEM fluids Application -------------------//

      KRATOS_REGISTER_VARIABLE( NODAL_AREA )

      KRATOS_REGISTER_VARIABLE( BULK_MODULUS )
      KRATOS_REGISTER_VARIABLE( SATURATION )
      KRATOS_REGISTER_VARIABLE( DENSITY_WATER )
      KRATOS_REGISTER_VARIABLE( VISCOSITY_WATER )
      KRATOS_REGISTER_VARIABLE( DENSITY_AIR )
      KRATOS_REGISTER_VARIABLE( VISCOSITY_AIR )
      KRATOS_REGISTER_VARIABLE( POROSITY )
      KRATOS_REGISTER_VARIABLE( DIAMETER )
      KRATOS_REGISTER_VARIABLE( LIN_DARCY_COEF )
      KRATOS_REGISTER_VARIABLE( NONLIN_DARCY_COEF )

      KRATOS_REGISTER_VARIABLE( AIR_ENTRY_VALUE )
      KRATOS_REGISTER_VARIABLE( FIRST_SATURATION_PARAM )
      KRATOS_REGISTER_VARIABLE( SECOND_SATURATION_PARAM )
      KRATOS_REGISTER_VARIABLE( PERMEABILITY_WATER )
      KRATOS_REGISTER_VARIABLE( PERMEABILITY_AIR )
      KRATOS_REGISTER_VARIABLE( BULK_AIR )

      KRATOS_REGISTER_VARIABLE( TEMP_CONV_PROJ )
      KRATOS_REGISTER_VARIABLE( CONVECTION_COEFFICIENT )

      KRATOS_REGISTER_VARIABLE( SCALE )
      KRATOS_REGISTER_VARIABLE( IS_JACK_LINK )
      KRATOS_REGISTER_VARIABLE( IMPOSED_PRESSURE )

      KRATOS_REGISTER_VARIABLE( SOUND_VELOCITY )
      KRATOS_REGISTER_VARIABLE( AIR_SOUND_VELOCITY )
      KRATOS_REGISTER_VARIABLE( WATER_SOUND_VELOCITY )

      KRATOS_REGISTER_VARIABLE( NODAL_MASS )
      KRATOS_REGISTER_VARIABLE( AUX_INDEX )
      KRATOS_REGISTER_VARIABLE( EXTERNAL_PRESSURE )
      KRATOS_REGISTER_VARIABLE( BDF_COEFFICIENTS )
      KRATOS_REGISTER_VARIABLE( VELOCITY_PERIOD )
      KRATOS_REGISTER_VARIABLE( ANGULAR_VELOCITY_PERIOD )
      KRATOS_REGISTER_VARIABLE( IDENTIFIER )

      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( GRAVITY )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( NORMAL_TO_WALL )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( STRUCTURE_VELOCITY )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( DRAG_FORCE )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( EMBEDDED_VELOCITY )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( FRACT_VEL )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( ROTATION_CENTER )

      //--------------- PFEM fluids Application -------------------//


      //--------------- Other Applications -------------------//

      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( SEEPAGE_DRAG )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( MASS )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( RHS )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( FORCE_CM )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( MOMENTUM_CM )

//       KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( xi_c )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( DIRECTION )
      KRATOS_REGISTER_3D_VARIABLE_WITH_COMPONENTS( Y )

      KRATOS_REGISTER_VARIABLE( ARRHENIUS )
      KRATOS_REGISTER_VARIABLE( ARRHENIUSAUX )
      KRATOS_REGISTER_VARIABLE( ARRHENIUSAUX_ )
      KRATOS_REGISTER_VARIABLE( PRESSUREAUX )
      KRATOS_REGISTER_VARIABLE( NODAL_MAUX )
      KRATOS_REGISTER_VARIABLE( NODAL_PAUX )
      KRATOS_REGISTER_VARIABLE( HEAT_FLUX )
      KRATOS_REGISTER_VARIABLE( TC )
      KRATOS_REGISTER_VARIABLE( CONDUCTIVITY )
      KRATOS_REGISTER_VARIABLE( SPECIFIC_HEAT )
      KRATOS_REGISTER_VARIABLE( MATERIAL_VARIABLE )
      KRATOS_REGISTER_VARIABLE( FUEL )
      KRATOS_REGISTER_VARIABLE( YO )
      KRATOS_REGISTER_VARIABLE( YF )
      KRATOS_REGISTER_VARIABLE( YI )
      KRATOS_REGISTER_VARIABLE( Y1 )
      KRATOS_REGISTER_VARIABLE( Y2 )
      KRATOS_REGISTER_VARIABLE( YP )


      KRATOS_REGISTER_VARIABLE( ABSORPTION_COEFFICIENT )
      KRATOS_REGISTER_VARIABLE( STEFAN_BOLTZMANN_CONSTANT )

      KRATOS_REGISTER_VARIABLE( EMISSIVITY )
      KRATOS_REGISTER_VARIABLE( ENTHALPY )
      KRATOS_REGISTER_VARIABLE( MIXTURE_FRACTION )

      KRATOS_REGISTER_VARIABLE(YCH4)
      KRATOS_REGISTER_VARIABLE(YO2)
      KRATOS_REGISTER_VARIABLE(YCO2)
      KRATOS_REGISTER_VARIABLE(YH2O)
      KRATOS_REGISTER_VARIABLE(YN2)

      KRATOS_REGISTER_VARIABLE( WET_VOLUME)
      KRATOS_REGISTER_VARIABLE( CUTTED_AREA)
      KRATOS_REGISTER_VARIABLE( NET_INPUT_MATERIAL)

      KRATOS_REGISTER_VARIABLE( INCIDENT_RADIATION_FUNCTION )

      KRATOS_REGISTER_VARIABLE( SWITCH_TEMPERATURE )
      KRATOS_REGISTER_VARIABLE( NODAL_SWITCH )


      //--------------- OTHER Applications -------------------//


      //--------------- XFEM Set Application -------------------//

      KRATOS_REGISTER_VARIABLE( CRACK_OPENING )
      KRATOS_REGISTER_VARIABLE( CRACK_TRANSLATION )

      //--------------- XFEM Application -------------------//



      //--------------- Level Set Application -------------------//

      KRATOS_REGISTER_VARIABLE( REFINEMENT_LEVEL )
      KRATOS_REGISTER_VARIABLE( MIN_DT )
      KRATOS_REGISTER_VARIABLE( MAX_DT )
      KRATOS_REGISTER_VARIABLE( VEL_ART_VISC )
      KRATOS_REGISTER_VARIABLE( PR_ART_VISC )

      //--------------- Level Set Application -------------------//



      KRATOS_REGISTER_VARIABLE( PERIODIC_VARIABLES )


      //--------------- Vulcan Application -------------------//
      KRATOS_REGISTER_VARIABLE( LATENT_HEAT )
//       KRATOS_REGISTER_VARIABLE( SOLID_TEMPERATURE )
//       KRATOS_REGISTER_VARIABLE( FLUID_TEMPERATURE )
//       KRATOS_REGISTER_VARIABLE( AVERAGE_TEMPERATURE )
//       KRATOS_REGISTER_VARIABLE( INLET_TEMPERATURE)
       KRATOS_REGISTER_VARIABLE( AMBIENT_TEMPERATURE )
//       KRATOS_REGISTER_VARIABLE( COUNTER )
//       KRATOS_REGISTER_VARIABLE( DISTANCE_CORRECTION )
//       KRATOS_REGISTER_VARIABLE( COMPUTED_DISTANCE )
//       KRATOS_REGISTER_VARIABLE( MATERIAL )

      KRATOS_REGISTER_VARIABLE( ENRICHED_PRESSURES )

      KRATOS_REGISTER_VARIABLE( SEARCH_RADIUS )

      //Register objects with general definition
      Serializer::Register( "Node", RealNode() );
      Serializer::Register( "ComplexNode", ComplexNode() );
      Serializer::Register( "GComplexNode", GComplexNode() );
      Serializer::Register( "Dof", Dof<KRATOS_DOUBLE_TYPE>() );
      Serializer::Register( "ComplexDof", Dof<KRATOS_COMPLEX_TYPE>() );
      Serializer::Register( "Element", Element() );
      Serializer::Register( "ComplexElement", ComplexElement() );
      Serializer::Register( "GComplexElement", GComplexElement() );
      Serializer::Register( "Condition", Condition() );
      Serializer::Register( "ComplexCondition", ComplexCondition() );
      Serializer::Register( "GComplexCondition", GComplexCondition() );
      Serializer::Register( "Properties", Properties() );
      Serializer::Register( "GeometricalObject", GeometricalObject<Node<3> >() );

      Serializer::Register("MasterSlaveConstraint", MasterSlaveConstraint());

      //Register specific conditions ( must be completed : conditions defined in kratos_appliction.h)
      KRATOS_REGISTER_CONDITION( "Condition3D", mCondition3D )
      KRATOS_REGISTER_CONDITION( "Condition2D", mCondition2D )
      KRATOS_REGISTER_CONDITION( "PeriodicCondition", mPeriodicCondition )
      KRATOS_REGISTER_CONDITION( "PeriodicConditionEdge", mPeriodicConditionEdge )
      KRATOS_REGISTER_CONDITION( "PeriodicConditionCorner", mPeriodicConditionCorner )

      //master-slave constraints
      KRATOS_REGISTER_CONSTRAINT("MasterSlaveConstraint", mMasterSlaveConstraint)
      KRATOS_REGISTER_CONSTRAINT("LinearConstraint", mLinearConstraint)
      KRATOS_REGISTER_CONSTRAINT("LinearMasterSlaveConstraint", mLinearMasterSlaveConstraint)

      //Register specific elements ( must be completed : elements defined in kratos_appliction.h)
      KRATOS_REGISTER_ELEMENT( "Element3D4N", mElement3D4N )
      KRATOS_REGISTER_ELEMENT( "Element2D3N", mElement2D3N )

      //Register general geometries:

      //Points:
      Serializer::Register( "Point", Point<3>() );

      Point2D<Node<3> > Point2DPrototype( Element::GeometryType::PointsArrayType( 1, Node<3>() ) );
      Serializer::Register( "Point2D", Point2DPrototype );

      Point3D<Node<3> > Point3DPrototype( Element::GeometryType::PointsArrayType( 1, Node<3>() ) );
      Serializer::Register( "Point3D", Point3DPrototype );

      //Lines:
      Line2D<Node<3> > Line2DPrototype( Element::GeometryType::PointsArrayType( 2, Node<3>() ) );
      Serializer::Register( "Line2D", Line2DPrototype );

      Line2D2<Node<3> > Line2D2Prototype( Element::GeometryType::PointsArrayType( 2, Node<3>() ) );
      Serializer::Register( "Line2D2", Line2D2Prototype );

      Line2D3<Node<3> > Line2D3Prototype( Element::GeometryType::PointsArrayType( 3, Node<3>() ) );
      Serializer::Register( "Line2D3", Line2D3Prototype );

      Line3D2<Node<3> > Line3D2Prototype( Element::GeometryType::PointsArrayType( 2, Node<3>() ) );
      Serializer::Register( "Line3D2", Line3D2Prototype );

      Line3D3<Node<3> > Line3D3Prototype( Element::GeometryType::PointsArrayType( 3, Node<3>() ) );
      Serializer::Register( "Line3D3", Line3D3Prototype );

      //Triangles:
      Triangle2D3<Node<3> > Triangle2D3Prototype( Element::GeometryType::PointsArrayType( 3, Node<3>() ) );
      Serializer::Register( "Triangle2D3", Triangle2D3Prototype );

      Triangle2D6<Node<3> > Triangle2D6Prototype( Element::GeometryType::PointsArrayType( 6, Node<3>() ) );
      Serializer::Register( "Triangle2D6", Triangle2D6Prototype );

      Triangle3D3<Node<3> > Triangle3D3Prototype( Element::GeometryType::PointsArrayType( 3, Node<3>() ) );
      Serializer::Register( "Triangle3D3", Triangle3D3Prototype );

      Triangle3D6<Node<3> > Triangle3D6Prototype( Element::GeometryType::PointsArrayType( 6, Node<3>() ) );
      Serializer::Register( "Triangle3D6", Triangle3D6Prototype );

      //Quadrilaterals:
      Quadrilateral2D4<Node<3> > Quadrilateral2D4Prototype( Element::GeometryType::PointsArrayType( 4, Node<3>() ) );
      Serializer::Register( "Quadrilateral2D4", Quadrilateral2D4Prototype );

      Quadrilateral2D8<Node<3> > Quadrilateral2D8Prototype( Element::GeometryType::PointsArrayType( 8, Node<3>() ) );
      Serializer::Register( "Quadrilateral2D8", Quadrilateral2D8Prototype );

      Quadrilateral2D9<Node<3> > Quadrilateral2D9Prototype( Element::GeometryType::PointsArrayType( 9, Node<3>() ) );
      Serializer::Register( "Quadrilateral2D9", Quadrilateral2D9Prototype );

      Quadrilateral3D4<Node<3> > Quadrilateral3D4Prototype( Element::GeometryType::PointsArrayType( 4, Node<3>() ) );
      Serializer::Register( "Quadrilateral3D4", Quadrilateral3D4Prototype );

      Quadrilateral3D8<Node<3> > Quadrilateral3D8Prototype( Element::GeometryType::PointsArrayType( 8, Node<3>() ) );
      Serializer::Register( "Quadrilateral3D8", Quadrilateral3D8Prototype );

      Quadrilateral3D9<Node<3> > Quadrilateral3D9Prototype( Element::GeometryType::PointsArrayType( 9, Node<3>() ) );
      Serializer::Register( "Quadrilateral3D9", Quadrilateral3D9Prototype );


      //Tetrahedra:
      Tetrahedra3D4 <Node<3> > Tetrahedra3D4Prototype( Element::GeometryType::PointsArrayType( 4, Node<3>() ) );
      Serializer::Register( "Tetrahedra3D4", Tetrahedra3D4Prototype );

      Tetrahedra3D10 <Node<3> > Tetrahedra3D10Prototype( Element::GeometryType::PointsArrayType( 10, Node<3>() ) );
      Serializer::Register( "Tetrahedra3D10", Tetrahedra3D10Prototype );

      //Prisms:
      Prism3D6<Node<3> > Prism3D6Prototype( Element::GeometryType::PointsArrayType( 6, Node<3>() ) );
      Serializer::Register( "Prism3D6", Prism3D6Prototype );

      Prism3D15<Node<3> > Prism3D15Prototype( Element::GeometryType::PointsArrayType( 15, Node<3>() ) );
      Serializer::Register( "Prism3D15", Prism3D15Prototype );

      //Hexahedra:
      Hexahedra3D8<Node<3> > Hexahedra3D8Prototype( Element::GeometryType::PointsArrayType( 8, Node<3>() ) );
      Serializer::Register( "Hexahedra3D8", Hexahedra3D8Prototype );

      Hexahedra3D20<Node<3> > Hexahedra3D20Prototype( Element::GeometryType::PointsArrayType( 20, Node<3>() ) );
      Serializer::Register( "Hexahedra3D20", Hexahedra3D20Prototype );

      Hexahedra3D27<Node<3> > Hexahedra3D27Prototype( Element::GeometryType::PointsArrayType( 27, Node<3>() ) );
      Serializer::Register( "Hexahedra3D27", Hexahedra3D27Prototype );

      // Register flags:
      KRATOS_REGISTER_FLAG(STRUCTURE);
      KRATOS_REGISTER_FLAG(FLUID);
      KRATOS_REGISTER_FLAG(THERMAL);
      KRATOS_REGISTER_FLAG(VISITED);
      KRATOS_REGISTER_FLAG(SELECTED);
      KRATOS_REGISTER_FLAG(BOUNDARY);
      KRATOS_REGISTER_FLAG(INLET);
      KRATOS_REGISTER_FLAG(OUTLET);
      KRATOS_REGISTER_FLAG(SLIP);
      KRATOS_REGISTER_FLAG(INTERFACE);
      KRATOS_REGISTER_FLAG(CONTACT);
      KRATOS_REGISTER_FLAG(TO_SPLIT);
      KRATOS_REGISTER_FLAG(TO_ERASE);
      KRATOS_REGISTER_FLAG(TO_REFINE);
      KRATOS_REGISTER_FLAG(NEW_ENTITY);
      KRATOS_REGISTER_FLAG(OLD_ENTITY);
      KRATOS_REGISTER_FLAG(ACTIVE);
      KRATOS_REGISTER_FLAG(MODIFIED);
      KRATOS_REGISTER_FLAG(RIGID);
      KRATOS_REGISTER_FLAG(SOLID);
      KRATOS_REGISTER_FLAG(MPI_BOUNDARY);
      KRATOS_REGISTER_FLAG(INTERACTION);
      KRATOS_REGISTER_FLAG(ISOLATED);
      KRATOS_REGISTER_FLAG(MASTER);
      KRATOS_REGISTER_FLAG(SLAVE);
      KRATOS_REGISTER_FLAG(INSIDE);
      KRATOS_REGISTER_FLAG(FREE_SURFACE);
      KRATOS_REGISTER_FLAG(BLOCKED);
      KRATOS_REGISTER_FLAG(MARKER);
      KRATOS_REGISTER_FLAG(HANGING);
  }

}  // namespace Kratos.

// This define must be HERE
#undef DKRATOS_EXPORT_INTERFACE_2
