//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.6 $
//
//

#if !defined(KRATOS_PRISM_3D_15_H_INCLUDED )
#define  KRATOS_PRISM_3D_15_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/triangle_3d_6.h"
#include "geometries/quadrilateral_3d_8.h"
#include "integration/prism_gauss_legendre_integration_points.h"

namespace Kratos
{

/**
 * An eight node hexahedra geometry with linear shape functions
 */
template<class TPointType> class Prism3D15 : public Geometry<TPointType>
{
public:
    /**
     * Type Definitions
     */

    /**
     * Geometry as base class.
     */
    typedef Geometry<TPointType> BaseType;

    /**
     * Type of edge and face geometries
     */
    typedef Line3D3<TPointType> EdgeType;
    typedef Triangle3D6<TPointType> FaceType1;
    typedef Quadrilateral3D8<TPointType> FaceType2;

    /**
     * Pointer definition of Prism3D15
     */
    KRATOS_CLASS_POINTER_DEFINITION( Prism3D15 );

    /**
     * Integration methods implemented in geometry.
     */
    typedef GeometryData::IntegrationMethod IntegrationMethod;

    /**
     * A Vector of counted pointers to Geometries. Used for
     * returning edges of the geometry.
     */
    typedef typename BaseType::GeometriesArrayType GeometriesArrayType;

    /**
     * Type used for coordinate value.
     */
    typedef typename BaseType::DataType DataType;

    /**
     * Type used for shape function value.
     */
    typedef typename BaseType::ValueType ValueType;

    /**
     * Type used for indexing in geometry class.std::size_t used for indexing
     * point or integration point access methods and also all other
     * methods which need point or integration point index.
     */
    typedef typename BaseType::IndexType IndexType;

    /**
     * This typed used to return size or dimension in
     * geometry. Dimension, WorkingDimension, PointsNumber and
     * ... return this type as their results.
     */
    typedef typename BaseType::SizeType SizeType;

    /**
     * Redefinition of template parameter TPointType.
     */
    typedef typename BaseType::PointType PointType;

    /**
     * Array of counted pointers to point. This type used to hold
     * geometry's points.
     */
    typedef typename BaseType::PointsArrayType PointsArrayType;

    /**
     * This type used for representing an integration point in
     * geometry. This integration point is a point with an
     * additional weight component.
     */
    typedef typename BaseType::IntegrationPointType IntegrationPointType;

    /**
     * A Vector of IntegrationPointType which used to hold
     * integration points related to an integration
     * method. IntegrationPoints functions used this type to return
     * their results.
     */
    typedef typename BaseType::IntegrationPointsArrayType IntegrationPointsArrayType;

    /**
     * A Vector of IntegrationPointsArrayType which used to hold
     * integration points related to different integration method
     * implemented in geometry.
     */
    typedef typename BaseType::IntegrationPointsContainerType IntegrationPointsContainerType;

    /**
     * A third order tensor used as shape functions' values
     * container.
     */
    typedef typename BaseType::ShapeFunctionsValuesContainerType ShapeFunctionsValuesContainerType;

    /**
     * A fourth order tensor used as shape functions' local
     * gradients container in geometry.
     */
    typedef typename BaseType::ShapeFunctionsLocalGradientsContainerType ShapeFunctionsLocalGradientsContainerType;

    /**
     * A third order tensor to hold jacobian matrices evaluated at
     * integration points. Jacobian and InverseOfJacobian functions
     * return this type as their result.
     */
    typedef typename BaseType::JacobiansType JacobiansType;

    /**
     * A third order tensor to hold shape functions' local gradients at all integration points.
     * ShapefunctionsLocalGradients function return this
     * type as its result.
     */
    typedef typename BaseType::ShapeFunctionsGradientsType ShapeFunctionsGradientsType;

    /**
     * A third order tensor to hold shape functions' local second derivatives at a point.
     * ShapeFunctionsSecondDerivatives function return this
     * type as its result.
     */
    typedef typename BaseType::ShapeFunctionsSecondDerivativesType ShapeFunctionsSecondDerivativesType;

    /**
    * A fourth order tensor to hold shape functions' local third derivatives at a point.
    * ShapeFunctionsThirdDerivatives function return this
    * type as its result.
    */
    typedef typename BaseType::ShapeFunctionsThirdDerivativesType ShapeFunctionsThirdDerivativesType;

    /**
     * A third order tensor to hold shape functions' gradients at all integration points.
     * ShapeFunctionsIntegrationPointsGradients function return this
     * type as its result.
     */
    typedef typename BaseType::ShapeFunctionsIntegrationPointsGradientsType ShapeFunctionsIntegrationPointsGradientsType;

    /**
     * Type of the normal vector used for normal to edges in geomety.
     */
    typedef typename BaseType::NormalType NormalType;

    /**
     * Type of coordinates array
     */
    typedef typename BaseType::CoordinatesArrayType CoordinatesArrayType;

    /** This type used for representing the local coordinates of
    an integration point
    */
    typedef typename BaseType::LocalCoordinatesArrayType LocalCoordinatesArrayType;

    /**
     * Type of Matrix
     */
    typedef typename BaseType::MatrixType MatrixType;
    typedef typename BaseType::ZeroMatrixType ZeroMatrixType;

    /**
     * Type of Vector
     */
    typedef typename BaseType::VectorType VectorType;
    typedef typename BaseType::ZeroVectorType ZeroVectorType;

    /**
     * Life Cycle
     */

    Prism3D15( const PointType& Point1, const PointType& Point2,
               const PointType& Point3, const PointType& Point4, const PointType& Point5,
               const PointType& Point6, const PointType& Point7, const PointType& Point8,
               const PointType& Point9, const PointType& Point10, const PointType& Point11,
               const PointType& Point12, const PointType& Point13, const PointType& Point14,
               const PointType& Point15 )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().reserve( 15 );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point1 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point2 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point3 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point4 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point5 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point6 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point7 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point8 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point9 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point10 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point11 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point12 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point13 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point14 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point15 ) ) );
    }

    Prism3D15( typename PointType::Pointer pPoint1,
               typename PointType::Pointer pPoint2,
               typename PointType::Pointer pPoint3,
               typename PointType::Pointer pPoint4,
               typename PointType::Pointer pPoint5,
               typename PointType::Pointer pPoint6,
               typename PointType::Pointer pPoint7,
               typename PointType::Pointer pPoint8,
               typename PointType::Pointer pPoint9,
               typename PointType::Pointer pPoint10,
               typename PointType::Pointer pPoint11,
               typename PointType::Pointer pPoint12,
               typename PointType::Pointer pPoint13,
               typename PointType::Pointer pPoint14,
               typename PointType::Pointer pPoint15 )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().reserve( 15 );
        this->Points().push_back( pPoint1 );
        this->Points().push_back( pPoint2 );
        this->Points().push_back( pPoint3 );
        this->Points().push_back( pPoint4 );
        this->Points().push_back( pPoint5 );
        this->Points().push_back( pPoint6 );
        this->Points().push_back( pPoint7 );
        this->Points().push_back( pPoint8 );
        this->Points().push_back( pPoint9 );
        this->Points().push_back( pPoint10 );
        this->Points().push_back( pPoint11 );
        this->Points().push_back( pPoint12 );
        this->Points().push_back( pPoint13 );
        this->Points().push_back( pPoint14 );
        this->Points().push_back( pPoint15 );
    }

    Prism3D15( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 15 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                          "Invalid points number. Expected 15, given " ,
                          this->PointsNumber() );
    }

    /**
     * Copy constructor.
     * Construct this geometry as a copy of given geometry.
     *
     * @note This copy constructor don't copy the points and new
     * geometry shares points with given source geometry. It's
     * obvious that any change to this new geometry's point affect
     * source geometry's points too.
     */
    Prism3D15( Prism3D15 const& rOther )
        : BaseType( rOther )
    {
    }

    /**
     * Copy constructor from a geometry with other point type.
     * Construct this geometry as a copy of given geometry which
     * has different type of points. The given goemetry's
     * TOtherPointType* must be implicity convertible to this
     * geometry PointType.
     *
     * @note This copy constructor don't copy the points and new
     * geometry shares points with given source geometry. It's
     * obvious that any change to this new geometry's point affect
     * source geometry's points too.
     */
    template<class TOtherPointType> Prism3D15( Prism3D15<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    /// Destructor. Does nothing!!!
    ~Prism3D15() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Prism;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Prism3D15;
    }

    /**
     * Operators
     */

    /**
     * Assignment operator.
     *
     * @note This operator don't copy the points and this
     * geometry shares points with given source geometry. It's
     * obvious that any change to this geometry's point affect
     * source geometry's points too.
     *
     * @see Clone
     * @see ClonePoints
     */
    Prism3D15& operator=( const Prism3D15& rOther )
    {
        BaseType::operator=( rOther );
        return *this;
    }

    /**
     * Assignment operator for geometries with different point type.
     *
     * @note This operator don't copy the points and this
     * geometry shares points with given source geometry. It's
     * obvious that any change to this geometry's point affect
     * source geometry's points too.
     *
     * @see Clone
     * @see ClonePoints
     */
    template<class TOtherPointType>
    Prism3D15& operator=( Prism3D15<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }

    /**
     * Operations
     */

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Prism3D15( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Prism3D15< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    //lumping factors for the calculation of the lumped mass matrix
    Vector& LumpingFactors( Vector& rResult ) const override
    {
    if(rResult.size() != 15)
           rResult.resize( 15, false );
        std::fill( rResult.begin(), rResult.end(), 1.00 / 15.00 );
        return rResult;
    }

    /**
     * Informations
     */

    /**
     * This method calculates and returns Length or charactereistic
     * length of this geometry depending on it's dimension. For one
     * dimensional geometry for example Line it returns length of it
     * and for the other geometries it gives Characteristic length
     * otherwise.
     *
     * @return DataType value contains length or Characteristic
     * length
     * @see Area()
     * @see Volume()
     * @see DomainSize()
     *
     * :TODO: might be necessary to reimplement
     */
    DataType Length() const override
    {
        return std::sqrt( std::abs( this->DeterminantOfJacobian( LocalCoordinatesArrayType() ) ) );
    }

    /**
     * This method calculates and returns area or surface area of
     * this geometry depending to it's dimension. For one dimensional
     * geometry it returns zero, for two dimensional it gives area
     * and for three dimensional geometries it gives surface area.
     *
     *
     * @return DataType value contains area or surface area.
     * @see Length()
     * @see Volume()
     * @see DomainSize()
     *
     * :TODO: might be necessary to reimplement
     */
    DataType Area() const override
    {
        return std::abs( this->DeterminantOfJacobian( LocalCoordinatesArrayType() ) ) * 0.5;
    }

    DataType Volume() const override
    {
        VectorType temp;
        this->DeterminantOfJacobian( temp, msGeometryData.DefaultIntegrationMethod() );
        const IntegrationPointsArrayType& integration_points = this->IntegrationPoints( msGeometryData.DefaultIntegrationMethod() );

        DataType Volume = 0.00;
        for ( unsigned int i = 0; i < integration_points.size(); i++ )
        {
            Volume += temp[i] * integration_points[i].Weight();
        }

        return Volume;
    }

    /**
     * This method calculate and return length, area or volume of
     * this geometry depending to it's dimension. For one dimensional
     * geometry it returns its length, for two dimensional it gives area
     * and for three dimensional geometries it gives its volume.
     *
     * @return DataType value contains length, area or volume.
     * @see Length()
     * @see Area()
     * @see Volume()
     *
     * :TODO: might be necessary to reimplement
     */
    DataType DomainSize() const override
    {
        return std::abs( this->DeterminantOfJacobian( LocalCoordinatesArrayType() ) ) * 0.5;
    }

    /**
    * Returns a matrix of the local coordinates of all points
    * @param rResult a Matrix that will be overwritten by the results
    * @return the coordinates of all points of the current geometry
    */
    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if ( rResult.size1() != 15 || rResult.size2() != 3 )
            rResult.resize( 15, 3 );

        rResult( 0, 0 ) = 0.0;
        rResult( 0, 1 ) = 0.0;
        rResult( 0, 2 ) = -1.0;

        rResult( 1, 0 ) = 1.0;
        rResult( 1, 1 ) = 0.0;
        rResult( 1, 2 ) = -1.0;

        rResult( 2, 0 ) = 0.0;
        rResult( 2, 1 ) = 1.0;
        rResult( 2, 2 ) = -1.0;

        rResult( 3, 0 ) = 0.0;
        rResult( 3, 1 ) = 0.0;
        rResult( 3, 2 ) = 1.0;

        rResult( 4, 0 ) = 1.0;
        rResult( 4, 1 ) = 0.0;
        rResult( 4, 2 ) = 1.0;

        rResult( 5, 0 ) = 0.0;
        rResult( 5, 1 ) = 1.0;
        rResult( 5, 2 ) = 1.0;

        rResult( 6, 0 ) = 0.5;
        rResult( 6, 1 ) = 0.0;
        rResult( 6, 2 ) = -1.0;

        rResult( 7, 0 ) = 0.5;
        rResult( 7, 1 ) = 0.5;
        rResult( 7, 2 ) = -1.0;

        rResult( 8, 0 ) = 0.0;
        rResult( 8, 1 ) = 0.5;
        rResult( 8, 2 ) = -1.0;

        rResult( 9, 0 ) = 0.0;
        rResult( 9, 1 ) = 0.0;
        rResult( 9, 2 ) = 0.0;

        rResult( 10, 0 ) = 1.0;
        rResult( 10, 1 ) = 0.0;
        rResult( 10, 2 ) = 0.0;

        rResult( 11, 0 ) = 0.0;
        rResult( 11, 1 ) = 1.0;
        rResult( 11, 2 ) = 0.0;

        rResult( 12, 0 ) = 0.5;
        rResult( 12, 1 ) = 0.0;
        rResult( 12, 2 ) = 1.0;

        rResult( 13, 0 ) = 0.5;
        rResult( 13, 1 ) = 0.5;
        rResult( 13, 2 ) = 1.0;

        rResult( 14, 0 ) = 0.0;
        rResult( 14, 1 ) = 0.5;
        rResult( 14, 2 ) = 1.0;

        return rResult;
    }

    /**
     * Returns whether given arbitrary point is inside the Geometry
     */
    bool IsInside( const CoordinatesArrayType& rPoint, LocalCoordinatesArrayType& rResult ) const override
    {
        this->PointLocalCoordinates( rResult, rPoint );

        if ( rResult[0] >= 0.0 - 1.0e-8 && rResult[0] <= 1.0 + 1.0e-8 )
            if ( rResult[1] >= 0.0 - 1.0e-8 && rResult[1] <= 1.0 + 1.0e-8 )
                if ( rResult[2] >= -1.0 - 1.0e-8 && rResult[2] <= 1.0 + 1.0e-8 )
                    if ((( 1.0 - ( rResult[0] + rResult[1] ) ) >= 0.0 - 1.0e-8 ) && (( 1.0 - ( rResult[0] + rResult[1] ) ) <= 1.0 + 1.0e-8 ) )
                        return true;

        return false;
    }

    /**
     * Returns whether given arbitrary point is inside the Geometry
     */
    bool IsInside( const CoordinatesArrayType& rPoint, LocalCoordinatesArrayType& rResult, const MatrixType& DeltaPosition ) const override
    {
        this->PointLocalCoordinates( rResult, rPoint, DeltaPosition );

        if ( rResult[0] >= 0.0 - 1.0e-8 && rResult[0] <= 1.0 + 1.0e-8 )
            if ( rResult[1] >= 0.0 - 1.0e-8 && rResult[1] <= 1.0 + 1.0e-8 )
                if ( rResult[2] >= -1.0 - 1.0e-8 && rResult[2] <= 1.0 + 1.0e-8 )
                    if ((( 1.0 - ( rResult[0] + rResult[1] ) ) >= 0.0 - 1.0e-8 ) && (( 1.0 - ( rResult[0] + rResult[1] ) ) <= 1.0 + 1.0e-8 ) )
                        return true;

        return false;
    }

    /** This method gives you number of all edges of this
    geometry.
    @return SizeType containes number of this geometry edges.
    @see Edges()
    @see Edge()
     */
    // will be used by refinement algorithm, thus uncommented. janosch.
    SizeType EdgesNumber() const override
    {
        return 9;
    }

    SizeType FacesNumber() const override
    {
        return 5;
    }

    /** This method gives you all edges of this geometry.

    @return GeometriesArrayType containes this geometry edges.
    @see EdgesNumber()
    @see Edge()
     */
    GeometriesArrayType Edges( void ) const override
    {
        GeometriesArrayType edges = GeometriesArrayType();
        typedef typename Geometry<TPointType>::Pointer EdgePointerType;
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 1 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 2 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 8 ),
                                              this->pGetPoint( 0 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 12 ),
                                              this->pGetPoint( 4 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 13 ),
                                              this->pGetPoint( 5 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 14 ),
                                              this->pGetPoint( 3 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 9 ),
                                              this->pGetPoint( 3 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 10 ),
                                              this->pGetPoint( 4 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 11 ),
                                              this->pGetPoint( 5 ) ) ) );
        return edges;
    }

    GeometriesArrayType Faces( void ) const override
    {
        GeometriesArrayType faces = GeometriesArrayType();
        typedef typename Geometry<TPointType>::Pointer FacePointerType;
        faces.push_back( FacePointerType( new FaceType1(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 8 ),
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 6 ) ) ) );
        faces.push_back( FacePointerType( new FaceType1(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 12 ),
                                              this->pGetPoint( 13 ),
                                              this->pGetPoint( 14 ) ) ) );
        faces.push_back( FacePointerType( new FaceType2(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 10 ),
                                              this->pGetPoint( 12 ),
                                              this->pGetPoint( 9 ) ) ) );
        faces.push_back( FacePointerType( new FaceType2(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 8 ),
                                              this->pGetPoint( 9 ),
                                              this->pGetPoint( 14 ),
                                              this->pGetPoint( 11 ) ) ) );
        faces.push_back( FacePointerType( new FaceType2(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 11 ),
                                              this->pGetPoint( 13 ),
                                              this->pGetPoint( 10 ) ) ) );
        return faces;
    }

    /**
     * Shape Function
     */

    /**
     * Calculates the value of a given shape function at a given point.
     *
     * @param ShapeFunctionIndex The number of the desired shape function
     * @param rPoint the given point in local coordinates at which the
     * value of the shape function is calculated
     *
     * @return the value of the shape function at the given point
     * TODO: TO BE VERIFIED
     */
    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex, const LocalCoordinatesArrayType& rPoint ) const override
    {
        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( 0.5*(( 1.0 - rPoint[0] - rPoint[1] )*( 2.0*( 1.0 - rPoint[0] - rPoint[1] ) - 1.0 )*( 1.0 - rPoint[2] ) - ( 1.0 - rPoint[0] - rPoint[1] )*( 1.0 - ( rPoint[2]*rPoint[2] ) ) ) );
        case 1:
            return( 0.5*( rPoint[0]*( 2.0*rPoint[0] - 1.0 )*( 1.0 - rPoint[2] ) - rPoint[0]*( 1.0 - ( rPoint[2]*rPoint[2] ) ) ) );
        case 2:
            return( 0.5*( rPoint[1]*( 2.0*rPoint[1] - 1.0 )*( 1.0 - rPoint[2] ) - rPoint[1]*( 1.0 - ( rPoint[2]*rPoint[2] ) ) ) );
        case 3:
            return( 0.5*(( 1.0 - rPoint[0] - rPoint[1] )*( 2.0*( 1.0 - rPoint[0] - rPoint[1] ) - 1.0 )*( 1.0 + rPoint[2] ) - ( 1.0 - rPoint[0] - rPoint[1] )*( 1.0 - ( rPoint[2]*rPoint[2] ) ) ) );
        case 4:
            return( 0.5*( rPoint[0]*( 2.0*rPoint[0] - 1.0 )*( 1.0 + rPoint[2] ) - rPoint[0]*( 1.0 - ( rPoint[2]*rPoint[2] ) ) ) );
        case 5:
            return( 0.5*( rPoint[1]*( 2.0*rPoint[1] - 1.0 )*( 1.0 + rPoint[2] ) - rPoint[1]*( 1.0 - ( rPoint[2]*rPoint[2] ) ) ) );
        case 6:
            return( 2.0*( 1.0 - rPoint[0] - rPoint[1] )*rPoint[0]*( 1.0 - rPoint[2] ) );
        case 7:
            return( 2.0*rPoint[0]*rPoint[1]*( 1.0 - rPoint[2] ) );
        case 8:
            return( 2.0*rPoint[1]*( 1.0 - rPoint[0] - rPoint[1] )*( 1.0 - rPoint[2] ) );
        case 9:
            return(( 1.0 -rPoint[0] - rPoint[1] )*( 1.0 - ( rPoint[2]*rPoint[2] ) ) );
        case 10:
            return( rPoint[0]*( 1.0 - ( rPoint[2]*rPoint[2] ) ) );
        case 11:
            return( rPoint[1]*( 1.0 - ( rPoint[2]*rPoint[2] ) ) );
        case 12:
            return( 2.0*( 1.0 - rPoint[0] - rPoint[1] )*rPoint[0]*( 1.0 + rPoint[2] ) );
        case 13:
            return( 2.0*rPoint[0]*rPoint[1]*( 1.0 + rPoint[2] ) );
        case 14:
            return( 2.0*rPoint[1]*( 1.0 - rPoint[0] - rPoint[1] )*( 1.0 + rPoint[2] ) );
        default:
            KRATOS_THROW_ERROR( std::logic_error,
                          "Wrong index of shape function!" , *this );
        }

        return 0;
    }

    /**
     * Calculates the Gradients of the shape functions.
     * Calculates the gradients of the shape functions with regard to the global
     * coordinates in all
     * integration points (\f$ \frac{\partial N^i}{\partial X_j} \f$)
     *
     * @param rResult a container which takes the calculated gradients
     * @param ThisMethod the given IntegrationMethod
     * @return the gradients of all shape functions with regard to the global coordinates
     *
     * KLUDGE: method call only works with explicit JacobiansType rather than creating
     * JacobiansType within argument list
     *
     * :TODO: TESTING!!!
     */
    ShapeFunctionsIntegrationPointsGradientsType& ShapeFunctionsIntegrationPointsGradients(
        ShapeFunctionsIntegrationPointsGradientsType& rResult, IntegrationMethod ThisMethod ) const override
    {
        const unsigned int integration_points_number =
            msGeometryData.IntegrationPointsNumber( ThisMethod );

        if ( integration_points_number == 0 )
            KRATOS_THROW_ERROR( std::logic_error,
                          "This integration method is not supported" , *this );

        //workaround by riccardo
        if ( rResult.size() != integration_points_number )
        {
            // KLUDGE: While there is a bug in ublas
            // vector resize, I have to put this beside resizing!!
            ShapeFunctionsIntegrationPointsGradientsType temp( integration_points_number );
            rResult.swap( temp );
        }

        //calculating the local gradients
        ShapeFunctionsGradientsType locG =
            CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );

        //getting the inverse jacobian matrices
        JacobiansType temp( integration_points_number );

        JacobiansType invJ = this->InverseOfJacobian( temp, ThisMethod );

        //loop over all integration points
        for ( unsigned int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            rResult[pnt].resize( 15, 3 );

            for ( int i = 0; i < 15; i++ )
            {
                for ( int j = 0; j < 3; j++ )
                {
                    rResult[pnt]( i, j ) =
                        ( locG[pnt]( i, 0 ) * invJ[pnt]( j, 0 ) )
                        + ( locG[pnt]( i, 1 ) * invJ[pnt]( j, 1 ) )
                        + ( locG[pnt]( i, 2 ) * invJ[pnt]( j, 2 ) );
                }
            }
        }//end of loop over integration points

        return rResult;
    }

    /** This method gives gradient of all shape functions evaluated
     * in given point.
     * There is no calculation and it just give it from
     * shape functions values container if they are
     * existing. Otherwise it gives you error which this value is
     * not exist.
     * @param rResult the given Container that will be overwritten by the solution
     * @param rPoint the given local coordinates the gradients will be evaluated for
     * @return a matrix of gradients for each shape function
     */
    Matrix& ShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        return CalculateShapeFunctionsLocalGradients( rResult, rPoint );
    }

    /**
     * Input and output
     */

    /**
     * Turn back information as a string.
     *
     * @return String contains information about this geometry.
     * @see PrintData()
     * @see PrintInfo()
     */
    std::string Info() const override
    {
        return "3 dimensional prism with fiftheen nodes in 3D space";
    }

    /**
     * Print information about this object.
     *
     * @param rOStream Stream to print into it.
     * @see PrintData()
     * @see Info()
     */
    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "3 dimensional prism with fifthteen nodes in 3D space";
    }

    /**
     * Print geometry's data into given stream.
     * Prints it's points by the order they stored in the geometry
     * and then center point of geometry.
     *
     * @param rOStream Stream to print into it.
     * @see PrintInfo()
     * @see Info()
     */
    void PrintData( std::ostream& rOStream ) const override
    {
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian in the origin\t : " << jacobian;
    }

protected:

    /**
     * there are no protected class members
     */

private:

    /**
     * Static Member Variables
     */
    static const GeometryData msGeometryData;


    ///@}
    ///@name Serialization
    ///@{

    friend class Serializer;

    void save( Serializer& rSerializer ) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS( rSerializer, PointsArrayType );
    }

    void load( Serializer& rSerializer ) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS( rSerializer, PointsArrayType );
    }

    Prism3D15(): BaseType( PointsArrayType(), &msGeometryData ) {}


    /**
     * Private Operations
     */

    /**
     * TODO: TO BE VERIFIED
     */
    /**
     * Calculates the gradients in terms of local coordinateds
     * of all shape functions in a given point.
     *
     * @param rPoint the current point at which the gradients are calculated
     * @return the gradients of all shape functions
     * \f$ \frac{\partial N^i}{\partial \xi_j} \f$
     */
    static Matrix& CalculateShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint )
    {
        rResult( 0, 0 ) = 0.5 * ( 1.0 - ( -1.0 + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) ) * ( 1.0 - rPoint[2] ) - 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * ( 1 - rPoint[2] ) - ( rPoint[2] * rPoint[2] ) );
        rResult( 0, 1 ) = 0.5 * ( 1.0 - ( -1.0 + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) ) * ( 1.0 - rPoint[2] ) - 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * ( 1 - rPoint[2] ) - ( rPoint[2] * rPoint[2] ) );
        rResult( 0, 2 ) = 0.5 * ( -( -1.0 + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) ) * ( 1.0 - rPoint[0] - rPoint[1] ) + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * rPoint[2] );
        rResult( 1, 0 ) = 0.5 * ( -1.0 + 2.0 * rPoint[0] * ( 1.0 - rPoint[2] ) + ( -1.0 + 2.0 * rPoint[0] ) * ( 1.0 - rPoint[2] ) + ( rPoint[2] * rPoint[2] ) );
        rResult( 1, 1 ) = 0.0;
        rResult( 1, 2 ) = 0.5 * ( -rPoint[0] * ( -1.0 + 2.0 * rPoint[0] ) + 2.0 * rPoint[0] * rPoint[2] );
        rResult( 2, 0 ) = 0.0;
        rResult( 2, 1 ) = 0.5 * ( -1.0 + 2.0 * rPoint[1] * ( 1.0 - rPoint[2] ) + ( -1.0 + 2.0 * rPoint[1] ) * ( 1.0 - rPoint[2] ) + ( rPoint[2] * rPoint[2] ) );
        rResult( 2, 2 ) = 0.5 * ( -rPoint[1] * ( -1.0 + 2.0 * rPoint[1] ) + 2.0 * rPoint[1] * rPoint[2] );
        rResult( 3, 0 ) = 0.5 * ( 1.0 - ( rPoint[2] * rPoint[2] ) - ( -1.0 + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) ) * ( 1.0 + rPoint[2] ) - 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * ( 1.0 + rPoint[2] ) );
        rResult( 3, 1 ) = 0.5 * ( 1.0 - ( rPoint[2] * rPoint[2] ) - ( -1.0 + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) ) * ( 1.0 + rPoint[2] ) - 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * ( 1.0 + rPoint[2] ) );
        rResult( 3, 2 ) = 0.5 * (( -1.0 + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) ) * ( 1.0 - rPoint[0] - rPoint[1] ) + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * rPoint[2] );
        rResult( 4, 0 ) = 0.5 * ( -1.0 + ( rPoint[2] * rPoint[2] ) + 2.0 * rPoint[0] * ( 1.0 + rPoint[2] ) + ( -1.0 + 2.0 * rPoint[0] ) * ( 1.0 + rPoint[2] ) );
        rResult( 4, 1 ) = 0.0;
        rResult( 4, 2 ) = 0.5 * ( rPoint[0] * ( -1.0 + 2.0 * rPoint[0] ) + 2.0 * rPoint[0] * rPoint[2] );
        rResult( 5, 0 ) = 0.0;
        rResult( 5, 1 ) = 0.5 * ( -1.0 + ( rPoint[2] * rPoint[2] ) + 2.0 * rPoint[1] * ( 1.0 + rPoint[2] ) + ( -1.0 + 2.0 * rPoint[1] ) * ( 1.0 + rPoint[2] ) );
        rResult( 5, 2 ) = 0.5 * ( rPoint[1] * ( -1.0 + 2.0 * rPoint[1] ) + 2.0 * rPoint[1] * rPoint[2] );
        rResult( 6, 0 ) = -2.0 * rPoint[0] * ( 1.0 - rPoint[2] ) + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * ( 1.0 - rPoint[2] );
        rResult( 6, 1 ) = -2.0 * rPoint[0] * ( 1.0 - rPoint[2] );
        rResult( 6, 2 ) = -2.0 * rPoint[0] * ( 1.0 - rPoint[0] - rPoint[1] );
        rResult( 7, 0 ) = 2.0 * rPoint[1] * ( 1.0 - rPoint[2] );
        rResult( 7, 1 ) = 2.0 * rPoint[0] * ( 1.0 - rPoint[2] );
        rResult( 7, 2 ) = -2.0 * rPoint[0] * rPoint[1];
        rResult( 8, 0 ) = -2.0 * rPoint[1] * ( 1.0 - rPoint[2] );
        rResult( 8, 1 ) = 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * ( 1.0 - rPoint[2] ) - 2.0 * rPoint[1] * ( 1.0 - rPoint[2] );
        rResult( 8, 2 ) = -2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * rPoint[1];
        rResult( 9, 0 ) = -1.0 + ( rPoint[2] * rPoint[2] );
        rResult( 9, 1 ) = -1.0 + ( rPoint[2] * rPoint[2] );
        rResult( 9, 2 ) = -2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * rPoint[2];
        rResult( 10, 0 ) = 1.0 - ( rPoint[2] * rPoint[2] );
        rResult( 10, 1 ) = 0.0;
        rResult( 10, 2 ) = -2.0 * rPoint[0] * rPoint[2];
        rResult( 11, 0 ) = 0.0;
        rResult( 11, 1 ) = 1.0 - ( rPoint[2] * rPoint[2] );
        rResult( 11, 2 ) = -2.0 * rPoint[1] * rPoint[2];
        rResult( 12, 0 ) = -2.0 * rPoint[0] * ( 1.0 + rPoint[2] ) + 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * ( 1.0 + rPoint[2] );
        rResult( 12, 1 ) = -2.0 * rPoint[0] * ( 1.0 + rPoint[2] );
        rResult( 12, 2 ) = 2.0 * rPoint[0] * ( 1.0 - rPoint[0] - rPoint[1] );
        rResult( 13, 0 ) = 2.0 * rPoint[1] * ( 1.0 + rPoint[2] );
        rResult( 13, 1 ) = 2.0 * rPoint[0] * ( 1.0 + rPoint[2] );
        rResult( 13, 2 ) = 2.0 * rPoint[0] * rPoint[1];
        rResult( 14, 0 ) = -2.0 * rPoint[1] * ( 1.0 + rPoint[2] );
        rResult( 14, 1 ) = 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * ( 1.0 + rPoint[2] ) - 2.0 * rPoint[1] * ( 1.0 + rPoint[2] );
        rResult( 14, 2 ) = 2.0 * ( 1.0 - rPoint[0] - rPoint[1] ) * rPoint[1];
        return rResult;
    }

    /**
     * TODO: TO BE VERIFIED
     */
    /**
     * Calculates the values of all shape function in all integration points.
     * Integration points are expected to be given in local coordinates
     *
     * @param ThisMethod the current integration method
     * @return the matrix of values of every shape function in each integration point
     *
     */
    static Matrix CalculateShapeFunctionsIntegrationPointsValues(
        typename BaseType::IntegrationMethod ThisMethod )
    {
        IntegrationPointsContainerType all_integration_points =
            AllIntegrationPoints();
        IntegrationPointsArrayType integration_points =
            all_integration_points[static_cast<int>(ThisMethod)];
        //number of integration points
        const int integration_points_number = integration_points.size();
        //number of nodes in current geometry
        const int points_number = 15;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            shape_function_values( pnt, 0 ) = ( 0.5 * (( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) - 1.0 ) * ( 1.0 - integration_points[pnt].Z() ) - ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) ) );
            shape_function_values( pnt, 1 ) = ( 0.5 * ( integration_points[pnt].X() * ( 2.0 * integration_points[pnt].X() - 1.0 ) * ( 1.0 - integration_points[pnt].Z() ) - integration_points[pnt].X() * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) ) );
            shape_function_values( pnt, 2 ) = ( 0.5 * ( integration_points[pnt].Y() * ( 2.0 * integration_points[pnt].Y() - 1.0 ) * ( 1.0 - integration_points[pnt].Z() ) - integration_points[pnt].Y() * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) ) );
            shape_function_values( pnt, 3 ) = ( 0.5 * (( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) - 1.0 ) * ( 1.0 + integration_points[pnt].Z() ) - ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) ) );
            shape_function_values( pnt, 4 ) = ( 0.5 * ( integration_points[pnt].X() * ( 2.0 * integration_points[pnt].X() - 1.0 ) * ( 1.0 + integration_points[pnt].Z() ) - integration_points[pnt].X() * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) ) );
            shape_function_values( pnt, 5 ) = ( 0.5 * ( integration_points[pnt].Y() * ( 2.0 * integration_points[pnt].Y() - 1.0 ) * ( 1.0 + integration_points[pnt].Z() ) - integration_points[pnt].Y() * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) ) );
            shape_function_values( pnt, 6 ) = ( 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * integration_points[pnt].X() * ( 1.0 - integration_points[pnt].Z() ) );
            shape_function_values( pnt, 7 ) = ( 2.0 * integration_points[pnt].X() * integration_points[pnt].Y() * ( 1.0 - integration_points[pnt].Z() ) );
            shape_function_values( pnt, 8 ) = ( 2.0 * integration_points[pnt].Y() * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 - integration_points[pnt].Z() ) );
            shape_function_values( pnt, 9 ) = (( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) );
            shape_function_values( pnt, 10 ) = ( integration_points[pnt].X() * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) );
            shape_function_values( pnt, 11 ) = ( integration_points[pnt].Y() * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) ) );
            shape_function_values( pnt, 12 ) = ( 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * integration_points[pnt].X() * ( 1.0 + integration_points[pnt].Z() ) );
            shape_function_values( pnt, 13 ) = ( 2.0 * integration_points[pnt].X() * integration_points[pnt].Y() * ( 1.0 + integration_points[pnt].Z() ) );
            shape_function_values( pnt, 14 ) = ( 2.0 * integration_points[pnt].Y() * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 + integration_points[pnt].Z() ) );
        }

        return shape_function_values;
    }

    /**
     * TODO: TO BE VERIFIED
     */
    /**
     * Calculates the local gradients of all shape functions in all integration points.
     * Integration points are expected to be given in local coordinates
     *
     * @param ThisMethod the current integration method
     * @return the vector of the gradients of all shape functions
     * in each integration point
     *
     */
    static ShapeFunctionsGradientsType CalculateShapeFunctionsIntegrationPointsLocalGradients(
        typename BaseType::IntegrationMethod ThisMethod )
    {
        IntegrationPointsContainerType all_integration_points =
            AllIntegrationPoints();
        IntegrationPointsArrayType integration_points =
            all_integration_points[static_cast<int>(ThisMethod)];
        //number of integration points
        const int integration_points_number = integration_points.size();
        ShapeFunctionsGradientsType d_shape_f_values( integration_points_number );
        //initialising container
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            Matrix result = ZeroMatrix( 15, 3 );
            result( 0, 0 ) = 0.5 * ( 1.0 - ( -1.0 + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) ) * ( 1.0 - integration_points[pnt].Z() ) - 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1 - integration_points[pnt].Z() ) - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) );
            result( 0, 1 ) = 0.5 * ( 1.0 - ( -1.0 + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) ) * ( 1.0 - integration_points[pnt].Z() ) - 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1 - integration_points[pnt].Z() ) - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) );
            result( 0, 2 ) = 0.5 * ( -( -1.0 + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) ) * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * integration_points[pnt].Z() );
            result( 1, 0 ) = 0.5 * ( -1.0 + 2.0 * integration_points[pnt].X() * ( 1.0 - integration_points[pnt].Z() ) + ( -1.0 + 2.0 * integration_points[pnt].X() ) * ( 1.0 - integration_points[pnt].Z() ) + ( integration_points[pnt].Z() * integration_points[pnt].Z() ) );
            result( 1, 1 ) = 0.0;
            result( 1, 2 ) = 0.5 * ( -integration_points[pnt].X() * ( -1.0 + 2.0 * integration_points[pnt].X() ) + 2.0 * integration_points[pnt].X() * integration_points[pnt].Z() );
            result( 2, 0 ) = 0.0;
            result( 2, 1 ) = 0.5 * ( -1.0 + 2.0 * integration_points[pnt].Y() * ( 1.0 - integration_points[pnt].Z() ) + ( -1.0 + 2.0 * integration_points[pnt].Y() ) * ( 1.0 - integration_points[pnt].Z() ) + ( integration_points[pnt].Z() * integration_points[pnt].Z() ) );
            result( 2, 2 ) = 0.5 * ( -integration_points[pnt].Y() * ( -1.0 + 2.0 * integration_points[pnt].Y() ) + 2.0 * integration_points[pnt].Y() * integration_points[pnt].Z() );
            result( 3, 0 ) = 0.5 * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) - ( -1.0 + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) ) * ( 1.0 + integration_points[pnt].Z() ) - 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 + integration_points[pnt].Z() ) );
            result( 3, 1 ) = 0.5 * ( 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() ) - ( -1.0 + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) ) * ( 1.0 + integration_points[pnt].Z() ) - 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 + integration_points[pnt].Z() ) );
            result( 3, 2 ) = 0.5 * (( -1.0 + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) ) * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * integration_points[pnt].Z() );
            result( 4, 0 ) = 0.5 * ( -1.0 + ( integration_points[pnt].Z() * integration_points[pnt].Z() ) + 2.0 * integration_points[pnt].X() * ( 1.0 + integration_points[pnt].Z() ) + ( -1.0 + 2.0 * integration_points[pnt].X() ) * ( 1.0 + integration_points[pnt].Z() ) );
            result( 4, 1 ) = 0.0;
            result( 4, 2 ) = 0.5 * ( integration_points[pnt].X() * ( -1.0 + 2.0 * integration_points[pnt].X() ) + 2.0 * integration_points[pnt].X() * integration_points[pnt].Z() );
            result( 5, 0 ) = 0.0;
            result( 5, 1 ) = 0.5 * ( -1.0 + ( integration_points[pnt].Z() * integration_points[pnt].Z() ) + 2.0 * integration_points[pnt].Y() * ( 1.0 + integration_points[pnt].Z() ) + ( -1.0 + 2.0 * integration_points[pnt].Y() ) * ( 1.0 + integration_points[pnt].Z() ) );
            result( 5, 2 ) = 0.5 * ( integration_points[pnt].Y() * ( -1.0 + 2.0 * integration_points[pnt].Y() ) + 2.0 * integration_points[pnt].Y() * integration_points[pnt].Z() );
            result( 6, 0 ) = -2.0 * integration_points[pnt].X() * ( 1.0 - integration_points[pnt].Z() ) + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 - integration_points[pnt].Z() );
            result( 6, 1 ) = -2.0 * integration_points[pnt].X() * ( 1.0 - integration_points[pnt].Z() );
            result( 6, 2 ) = -2.0 * integration_points[pnt].X() * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() );
            result( 7, 0 ) = 2.0 * integration_points[pnt].Y() * ( 1.0 - integration_points[pnt].Z() );
            result( 7, 1 ) = 2.0 * integration_points[pnt].X() * ( 1.0 - integration_points[pnt].Z() );
            result( 7, 2 ) = -2.0 * integration_points[pnt].X() * integration_points[pnt].Y();
            result( 8, 0 ) = -2.0 * integration_points[pnt].Y() * ( 1.0 - integration_points[pnt].Z() );
            result( 8, 1 ) = 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 - integration_points[pnt].Z() ) - 2.0 * integration_points[pnt].Y() * ( 1.0 - integration_points[pnt].Z() );
            result( 8, 2 ) = -2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * integration_points[pnt].Y();
            result( 9, 0 ) = -1.0 + ( integration_points[pnt].Z() * integration_points[pnt].Z() );
            result( 9, 1 ) = -1.0 + ( integration_points[pnt].Z() * integration_points[pnt].Z() );
            result( 9, 2 ) = -2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * integration_points[pnt].Z();
            result( 10, 0 ) = 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() );
            result( 10, 1 ) = 0.0;
            result( 10, 2 ) = -2.0 * integration_points[pnt].X() * integration_points[pnt].Z();
            result( 11, 0 ) = 0.0;
            result( 11, 1 ) = 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() );
            result( 11, 2 ) = -2.0 * integration_points[pnt].Y() * integration_points[pnt].Z();
            result( 12, 0 ) = -2.0 * integration_points[pnt].X() * ( 1.0 + integration_points[pnt].Z() ) + 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 + integration_points[pnt].Z() );
            result( 12, 1 ) = -2.0 * integration_points[pnt].X() * ( 1.0 + integration_points[pnt].Z() );
            result( 12, 2 ) = 2.0 * integration_points[pnt].X() * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() );
            result( 13, 0 ) = 2.0 * integration_points[pnt].Y() * ( 1.0 + integration_points[pnt].Z() );
            result( 13, 1 ) = 2.0 * integration_points[pnt].X() * ( 1.0 + integration_points[pnt].Z() );
            result( 13, 2 ) = 2.0 * integration_points[pnt].X() * integration_points[pnt].Y();
            result( 14, 0 ) = -2.0 * integration_points[pnt].Y() * ( 1.0 + integration_points[pnt].Z() );
            result( 14, 1 ) = 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * ( 1.0 + integration_points[pnt].Z() ) - 2.0 * integration_points[pnt].Y() * ( 1.0 + integration_points[pnt].Z() );
            result( 14, 2 ) = 2.0 * ( 1.0 - integration_points[pnt].X() - integration_points[pnt].Y() ) * integration_points[pnt].Y();
            d_shape_f_values[pnt] = result;
        }

        return d_shape_f_values;
    }

    static const IntegrationPointsContainerType AllIntegrationPoints()
    {
        IntegrationPointsContainerType integration_points =
        {
            {
                Quadrature < PrismGaussLegendreIntegrationPoints1,
                3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < PrismGaussLegendreIntegrationPoints2,
                3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < PrismGaussLegendreIntegrationPoints3,
                3, IntegrationPoint<3> >::GenerateIntegrationPoints()
            }
        };
        return integration_points;
    }

    static const ShapeFunctionsValuesContainerType AllShapeFunctionsValues()
    {
        ShapeFunctionsValuesContainerType shape_functions_values =
        {
            {
                Prism3D15<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Prism3D15<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Prism3D15<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_3 )

            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType
    AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Prism3D15<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Prism3D15<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Prism3D15<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_3 )
            }
        };
        return shape_functions_local_gradients;
    }

    /**
     * Private Friends
     */

    template<class TOtherPointType> friend class Prism3D15;


    /**
     * Un accessible methods
     */

}; // Class Prism3D15

template<class TPointType> const
GeometryData Prism3D15<TPointType>::msGeometryData(
    3, 3, 3, GeometryData::IntegrationMethod::GI_GAUSS_3,
    Prism3D15<TPointType>::AllIntegrationPoints(),
    Prism3D15<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

}// namespace Kratos.

#endif // KRATOS_PRISM_3D_15_H_INCLUDED  defined
