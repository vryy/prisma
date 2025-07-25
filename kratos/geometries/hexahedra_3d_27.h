//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//                   Janosch Stascheit
//                   Felix Nagel
//  contributors:    Hoang Giang Bui
//                   Josep Maria Carbonell
//



#if !defined(KRATOS_HEXAHEDRA_3D_27_H_INCLUDED )
#define  KRATOS_HEXAHEDRA_3D_27_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/quadrilateral_3d_9.h"
#include "integration/hexahedron_gauss_legendre_integration_points.h"


namespace Kratos
{

/**
 * A twenty-seven node hexahedra geometry with second order shape functions
 *      3----10----2
 *      |\         |\
 *      |15    23  | 14
 *      11  \ 20   9  \
 *      |   7----18+---6
 *      |24 |  26  | 22|
 *      0---+-8----1   |
 *       \ 19    25 \  17
 *       12 |  21    13|
 *         \|         \|
 *          4----16----5
 */
template<class TPointType> class Hexahedra3D27 : public Geometry<TPointType>
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
    typedef Quadrilateral3D9<TPointType> FaceType;

    /**
     * Pointer definition of Hexahedra3D27
     */
    KRATOS_CLASS_POINTER_DEFINITION( Hexahedra3D27 );

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

    Hexahedra3D27( const PointType& Point1, const PointType& Point2, const PointType& Point3,
                   const PointType& Point4, const PointType& Point5, const PointType& Point6,
                   const PointType& Point7, const PointType& Point8, const PointType& Point9,
                   const PointType& Point10, const PointType& Point11, const PointType& Point12,
                   const PointType& Point13, const PointType& Point14, const PointType& Point15,
                   const PointType& Point16, const PointType& Point17, const PointType& Point18,
                   const PointType& Point19, const PointType& Point20, const PointType& Point21,
                   const PointType& Point22, const PointType& Point23, const PointType& Point24,
                   const PointType& Point25, const PointType& Point26, const PointType& Point27
                 )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
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
        this->Points().push_back( typename PointType::Pointer( new PointType( Point16 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point17 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point18 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point19 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point20 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point21 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point22 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point23 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point24 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point25 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point26 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point27 ) ) );
    }

    Hexahedra3D27( typename PointType::Pointer pPoint1,
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
                   typename PointType::Pointer pPoint15,
                   typename PointType::Pointer pPoint16,
                   typename PointType::Pointer pPoint17,
                   typename PointType::Pointer pPoint18,
                   typename PointType::Pointer pPoint19,
                   typename PointType::Pointer pPoint20,
                   typename PointType::Pointer pPoint21,
                   typename PointType::Pointer pPoint22,
                   typename PointType::Pointer pPoint23,
                   typename PointType::Pointer pPoint24,
                   typename PointType::Pointer pPoint25,
                   typename PointType::Pointer pPoint26,
                   typename PointType::Pointer pPoint27 )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
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
        this->Points().push_back( pPoint16 );
        this->Points().push_back( pPoint17 );
        this->Points().push_back( pPoint18 );
        this->Points().push_back( pPoint19 );
        this->Points().push_back( pPoint20 );
        this->Points().push_back( pPoint21 );
        this->Points().push_back( pPoint22 );
        this->Points().push_back( pPoint23 );
        this->Points().push_back( pPoint24 );
        this->Points().push_back( pPoint25 );
        this->Points().push_back( pPoint26 );
        this->Points().push_back( pPoint27 );
    }

    Hexahedra3D27( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 27 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                                "Invalid points number. Expected 27, given " ,
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
    Hexahedra3D27( Hexahedra3D27 const& rOther )
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
    template<class TOtherPointType> Hexahedra3D27( Hexahedra3D27<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    /// Destructor. Does nothing!!!
    ~Hexahedra3D27() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Hexahedra;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Hexahedra3D27;
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
    Hexahedra3D27& operator=( const Hexahedra3D27& rOther )
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
    Hexahedra3D27& operator=( Hexahedra3D27<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }


    /**
     * Operations
     */

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Hexahedra3D27( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Hexahedra3D27< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    //lumping factors for the calculation of the lumped mass matrix
    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 27)
            rResult.resize( 27, false );

        for ( int i = 0; i < 8; i++ ) rResult[i] = 1.00 / 216.00;

        for ( int i = 8; i < 20; i++ ) rResult[i] = 1.00 / 54.00;

        for ( int i = 20; i < 26; i++ ) rResult[i] = 2.00 / 27.00;

        rResult[26] = 8.00 / 27.00;

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
     */
    /**
     * :TODO: TO BE VERIFIED
     */
    DataType Length() const override
    {
        DataType length = 0.000;
        length = cbrt( std::abs( Area() ) );
        return length;
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
     */
    /**
     * :TODO: TO BE VERIFIED
     */
    DataType Area() const override
    {
        return Volume();
    }

    DataType Volume() const override //Not a closed formula for a hexahedra
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
     */
    /**
     * :TODO: TO BE VERIFIED
     */
    DataType DomainSize() const override
    {
        return Volume();
    }

    /**
     * Returns whether given local point is inside the Geometry
     */
    bool IsInside( const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( std::abs( rPoint[0] ) < 1 + 1.0e-8 )
            if ( std::abs( rPoint[1] ) < 1 + 1.0e-8 )
                if ( std::abs( rPoint[2] ) < 1 + 1.0e-8 )
                    return true;

        return false;
    }

    /**
     * Jacobian
     */


    /** This method gives you number of all edges of this
    geometry.
    @return SizeType containes number of this geometry edges.
    @see Edges()
    @see Edge()
     */
    // will be used by refinement algorithm, thus uncommented. janosch.
    SizeType EdgesNumber() const override
    {
        return 12;
    }

    SizeType FacesNumber() const override
    {
        return 6;
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
        //0
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 8 ),
                                              this->pGetPoint( 1 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 9 ),
                                              this->pGetPoint( 2 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 10 ),
                                              this->pGetPoint( 3 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 11 ),
                                              this->pGetPoint( 0 ) ) ) );

        //4
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 16 ),
                                              this->pGetPoint( 5 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 17 ),
                                              this->pGetPoint( 6 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 18 ),
                                              this->pGetPoint( 7 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 19 ),
                                              this->pGetPoint( 4 ) ) ) );

        //8
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 12 ),
                                              this->pGetPoint( 4 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 13 ),
                                              this->pGetPoint( 5 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 14 ),
                                              this->pGetPoint( 6 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 15 ),
                                              this->pGetPoint( 7 ) ) ) );
        return edges;
    }

    GeometriesArrayType Faces( void ) const override
    {
        GeometriesArrayType faces = GeometriesArrayType();
        typedef typename Geometry<TPointType>::Pointer FacePointerType;

        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 10 ),
                                              this->pGetPoint( 9 ),
                                              this->pGetPoint( 8 ),
                                              this->pGetPoint( 11 ),
                                              this->pGetPoint( 20 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 8 ),
                                              this->pGetPoint( 13 ),
                                              this->pGetPoint( 16 ),
                                              this->pGetPoint( 12 ),
                                              this->pGetPoint( 21 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 14 ),
                                              this->pGetPoint( 17 ),
                                              this->pGetPoint( 13 ),
                                              this->pGetPoint( 9 ),
                                              this->pGetPoint( 22 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 18 ),
                                              this->pGetPoint( 14 ),
                                              this->pGetPoint( 10 ),
                                              this->pGetPoint( 15 ),
                                              this->pGetPoint( 23 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 15 ),
                                              this->pGetPoint( 11 ),
                                              this->pGetPoint( 12 ),
                                              this->pGetPoint( 19 ),
                                              this->pGetPoint( 24 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 16 ),
                                              this->pGetPoint( 17 ),
                                              this->pGetPoint( 18 ),
                                              this->pGetPoint( 19 ),
                                              this->pGetPoint( 25 ) ) ) );
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
        ValueType fx1 = 0.5 * ( rPoint[0] - 1.0 ) * ( rPoint[0] );
        ValueType fx2 = 0.5 * ( rPoint[0] + 1.0 ) * ( rPoint[0] );
        ValueType fx3 = 1.0 - ( rPoint[0] * rPoint[0] );
        ValueType fy1 = 0.5 * ( rPoint[1] - 1.0 ) * ( rPoint[1] );
        ValueType fy2 = 0.5 * ( rPoint[1] + 1.0 ) * ( rPoint[1] );
        ValueType fy3 = 1.0 - ( rPoint[1] * rPoint[1] );
        ValueType fz1 = 0.5 * ( rPoint[2] - 1.0 ) * ( rPoint[2] );
        ValueType fz2 = 0.5 * ( rPoint[2] + 1.0 ) * ( rPoint[2] );
        ValueType fz3 = 1.0 - ( rPoint[2] * rPoint[2] );

        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( fx1*fy1*fz1 );
        case 1:
            return( fx2*fy1*fz1 );
        case 2:
            return( fx2*fy2*fz1 );
        case 3:
            return( fx1*fy2*fz1 );
        case 4:
            return( fx1*fy1*fz2 );
        case 5:
            return( fx2*fy1*fz2 );
        case 6:
            return( fx2*fy2*fz2 );
        case 7:
            return( fx1*fy2*fz2 );
        case 8:
            return( fx3*fy1*fz1 );
        case 9:
            return( fx2*fy3*fz1 );
        case 10:
            return( fx3*fy2*fz1 );
        case 11:
            return( fx1*fy3*fz1 );
        case 12:
            return( fx1*fy1*fz3 );
        case 13:
            return( fx2*fy1*fz3 );
        case 14:
            return( fx2*fy2*fz3 );
        case 15:
            return( fx1*fy2*fz3 );
        case 16:
            return( fx3*fy1*fz2 );
        case 17:
            return( fx2*fy3*fz2 );
        case 18:
            return( fx3*fy2*fz2 );
        case 19:
            return( fx1*fy3*fz2 );
        case 20:
            return( fx3*fy3*fz1 );
        case 21:
            return( fx3*fy1*fz3 );
        case 22:
            return( fx2*fy3*fz3 );
        case 23:
            return( fx3*fy2*fz3 );
        case 24:
            return( fx1*fy3*fz3 );
        case 25:
            return( fx3*fy3*fz2 );
        case 26:
            return( fx3*fy3*fz3 );

        default:
            KRATOS_THROW_ERROR( std::logic_error,
                                "Wrong index of shape function!" , *this );
        }

        return 0;
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
        return "3 dimensional hexahedra with 27 nodes and quadratic shape functions in 3D space";
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
        rOStream << "3 dimensional hexahedra with 27 nodes and quadratic shape functions in 3D space";
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
        rOStream << "Jacobian in the origin\t : " << jacobian;
    }

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
    Matrix& ShapeFunctionsLocalGradients( Matrix& result, const LocalCoordinatesArrayType& rPoint ) const override
    {
        ValueType fx1 = 0.5 * ( rPoint[0] - 1.0 ) * ( rPoint[0] );
        ValueType fx2 = 0.5 * ( rPoint[0] + 1.0 ) * ( rPoint[0] );
        ValueType fx3 = 1.0 - ( rPoint[0] * rPoint[0] );
        ValueType fy1 = 0.5 * ( rPoint[1] - 1.0 ) * ( rPoint[1] );
        ValueType fy2 = 0.5 * ( rPoint[1] + 1.0 ) * ( rPoint[1] );
        ValueType fy3 = 1.0 - ( rPoint[1] * rPoint[1] );
        ValueType fz1 = 0.5 * ( rPoint[2] - 1.0 ) * ( rPoint[2] );
        ValueType fz2 = 0.5 * ( rPoint[2] + 1.0 ) * ( rPoint[2] );
        ValueType fz3 = 1.0 - ( rPoint[2] * rPoint[2] );

        ValueType gx1 = 0.5 * ( 2.0 * rPoint[0] - 1.0 );
        ValueType gx2 = 0.5 * ( 2.0 * rPoint[0] + 1.0 );
        ValueType gx3 = -2 * rPoint[0];
        ValueType gy1 = 0.5 * ( 2.0 * rPoint[1] - 1.0 );
        ValueType gy2 = 0.5 * ( 2.0 * rPoint[1] + 1.0 );
        ValueType gy3 = -2 * rPoint[1];
        ValueType gz1 = 0.5 * ( 2.0 * rPoint[2] - 1.0 );
        ValueType gz2 = 0.5 * ( 2.0 * rPoint[2] + 1.0 );
        ValueType gz3 = -2 * rPoint[2];

        //setting up result matrix
        if ( result.size1() != 27 || result.size2() != 3 )
            result.resize( 27, 3, false );

        result( 0, 0 ) = gx1 * fy1 * fz1;

        result( 0, 1 ) = fx1 * gy1 * fz1;

        result( 0, 2 ) = fx1 * fy1 * gz1;

        result( 1, 0 ) = gx2 * fy1 * fz1;

        result( 1, 1 ) = fx2 * gy1 * fz1;

        result( 1, 2 ) = fx2 * fy1 * gz1;

        result( 2, 0 ) = gx2 * fy2 * fz1;

        result( 2, 1 ) = fx2 * gy2 * fz1;

        result( 2, 2 ) = fx2 * fy2 * gz1;

        result( 3, 0 ) = gx1 * fy2 * fz1;

        result( 3, 1 ) = fx1 * gy2 * fz1;

        result( 3, 2 ) = fx1 * fy2 * gz1;

        result( 4, 0 ) = gx1 * fy1 * fz2;

        result( 4, 1 ) = fx1 * gy1 * fz2;

        result( 4, 2 ) = fx1 * fy1 * gz2;

        result( 5, 0 ) = gx2 * fy1 * fz2;

        result( 5, 1 ) = fx2 * gy1 * fz2;

        result( 5, 2 ) = fx2 * fy1 * gz2;

        result( 6, 0 ) = gx2 * fy2 * fz2;

        result( 6, 1 ) = fx2 * gy2 * fz2;

        result( 6, 2 ) = fx2 * fy2 * gz2;

        result( 7, 0 ) = gx1 * fy2 * fz2;

        result( 7, 1 ) = fx1 * gy2 * fz2;

        result( 7, 2 ) = fx1 * fy2 * gz2;

        result( 8, 0 ) = gx3 * fy1 * fz1;

        result( 8, 1 ) = fx3 * gy1 * fz1;

        result( 8, 2 ) = fx3 * fy1 * gz1;

        result( 9, 0 ) = gx2 * fy3 * fz1;

        result( 9, 1 ) = fx2 * gy3 * fz1;

        result( 9, 2 ) = fx2 * fy3 * gz1;

        result( 10, 0 ) = gx3 * fy2 * fz1;

        result( 10, 1 ) = fx3 * gy2 * fz1;

        result( 10, 2 ) = fx3 * fy2 * gz1;

        result( 11, 0 ) = gx1 * fy3 * fz1;

        result( 11, 1 ) = fx1 * gy3 * fz1;

        result( 11, 2 ) = fx1 * fy3 * gz1;

        result( 12, 0 ) = gx1 * fy1 * fz3;

        result( 12, 1 ) = fx1 * gy1 * fz3;

        result( 12, 2 ) = fx1 * fy1 * gz3;

        result( 13, 0 ) = gx2 * fy1 * fz3;

        result( 13, 1 ) = fx2 * gy1 * fz3;

        result( 13, 2 ) = fx2 * fy1 * gz3;

        result( 14, 0 ) = gx2 * fy2 * fz3;

        result( 14, 1 ) = fx2 * gy2 * fz3;

        result( 14, 2 ) = fx2 * fy2 * gz3;

        result( 15, 0 ) = gx1 * fy2 * fz3;

        result( 15, 1 ) = fx1 * gy2 * fz3;

        result( 15, 2 ) = fx1 * fy2 * gz3;

        result( 16, 0 ) = gx3 * fy1 * fz2;

        result( 16, 1 ) = fx3 * gy1 * fz2;

        result( 16, 2 ) = fx3 * fy1 * gz2;

        result( 17, 0 ) = gx2 * fy3 * fz2;

        result( 17, 1 ) = fx2 * gy3 * fz2;

        result( 17, 2 ) = fx2 * fy3 * gz2;

        result( 18, 0 ) = gx3 * fy2 * fz2;

        result( 18, 1 ) = fx3 * gy2 * fz2;

        result( 18, 2 ) = fx3 * fy2 * gz2;

        result( 19, 0 ) = gx1 * fy3 * fz2;

        result( 19, 1 ) = fx1 * gy3 * fz2;

        result( 19, 2 ) = fx1 * fy3 * gz2;

        result( 20, 0 ) = gx3 * fy3 * fz1;

        result( 20, 1 ) = fx3 * gy3 * fz1;

        result( 20, 2 ) = fx3 * fy3 * gz1;

        result( 21, 0 ) = gx3 * fy1 * fz3;

        result( 21, 1 ) = fx3 * gy1 * fz3;

        result( 21, 2 ) = fx3 * fy1 * gz3;

        result( 22, 0 ) = gx2 * fy3 * fz3;

        result( 22, 1 ) = fx2 * gy3 * fz3;

        result( 22, 2 ) = fx2 * fy3 * gz3;

        result( 23, 0 ) = gx3 * fy2 * fz3;

        result( 23, 1 ) = fx3 * gy2 * fz3;

        result( 23, 2 ) = fx3 * fy2 * gz3;

        result( 24, 0 ) = gx1 * fy3 * fz3;

        result( 24, 1 ) = fx1 * gy3 * fz3;

        result( 24, 2 ) = fx1 * fy3 * gz3;

        result( 25, 0 ) = gx3 * fy3 * fz2;

        result( 25, 1 ) = fx3 * gy3 * fz2;

        result( 25, 2 ) = fx3 * fy3 * gz2;

        result( 26, 0 ) = gx3 * fy3 * fz3;

        result( 26, 1 ) = fx3 * gy3 * fz3;

        result( 26, 2 ) = fx3 * fy3 * gz3;

        return( result );
    }

    /**
     * Calculates the second derivatives in terms of local coordinateds
     * of all shape functions in a given point.
     *
     * @param rResult the given container will be overwritten by the results
     * @param rPoint the given local coordinates the derivatives will be evaluated for.
     * @return a third order tensor containing the second order derivatives for each shape function
     */
    ShapeFunctionsSecondDerivativesType& ShapeFunctionsSecondDerivatives( ShapeFunctionsSecondDerivativesType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( rResult.size() != this->PointsNumber() )
        {
            // KLUDGE: While there is a bug in
            // ublas vector resize, I have to put this beside resizing!!
            ShapeFunctionsGradientsType temp( this->PointsNumber() );
            rResult.swap( temp );
        }

        for ( unsigned int i = 0; i < this->PointsNumber(); ++i )
        {
            rResult[i].resize(3, 3, false);
        }

        ValueType fx1 = 0.5 * ( rPoint[0] - 1.0 ) * ( rPoint[0] );
        ValueType fx2 = 0.5 * ( rPoint[0] + 1.0 ) * ( rPoint[0] );
        ValueType fx3 = 1.0 - ( rPoint[0] * rPoint[0] );
        ValueType fy1 = 0.5 * ( rPoint[1] - 1.0 ) * ( rPoint[1] );
        ValueType fy2 = 0.5 * ( rPoint[1] + 1.0 ) * ( rPoint[1] );
        ValueType fy3 = 1.0 - ( rPoint[1] * rPoint[1] );
        ValueType fz1 = 0.5 * ( rPoint[2] - 1.0 ) * ( rPoint[2] );
        ValueType fz2 = 0.5 * ( rPoint[2] + 1.0 ) * ( rPoint[2] );
        ValueType fz3 = 1.0 - ( rPoint[2] * rPoint[2] );

        ValueType gx1 = 0.5 * ( 2.0 * rPoint[0] - 1.0 );
        ValueType gx2 = 0.5 * ( 2.0 * rPoint[0] + 1.0 );
        ValueType gx3 = -2 * rPoint[0];
        ValueType gy1 = 0.5 * ( 2.0 * rPoint[1] - 1.0 );
        ValueType gy2 = 0.5 * ( 2.0 * rPoint[1] + 1.0 );
        ValueType gy3 = -2 * rPoint[1];
        ValueType gz1 = 0.5 * ( 2.0 * rPoint[2] - 1.0 );
        ValueType gz2 = 0.5 * ( 2.0 * rPoint[2] + 1.0 );
        ValueType gz3 = -2 * rPoint[2];

        ValueType lx1 = 1.0;
        ValueType lx2 = 1.0;
        ValueType lx3 = -2.0;
        ValueType ly1 = 1.0;
        ValueType ly2 = 1.0;
        ValueType ly3 = -2.0;
        ValueType lz1 = 1.0;
        ValueType lz2 = 1.0;
        ValueType lz3 = -2.0;

        rResult[0]( 0, 0 ) = lx1 * fy1 * fz1;
        rResult[0]( 0, 1 ) = gx1 * gy1 * fz1;
        rResult[0]( 0, 2 ) = gx1 * fy1 * gz1;
        rResult[0]( 1, 0 ) = gx1 * gy1 * fz1;
        rResult[0]( 1, 1 ) = fx1 * ly1 * fz1;
        rResult[0]( 1, 2 ) = fx1 * gy1 * gz1;
        rResult[0]( 2, 0 ) = gx1 * fy1 * gz1;
        rResult[0]( 2, 1 ) = fx1 * gy1 * gz1;
        rResult[0]( 2, 2 ) = fx1 * fy1 * lz1;

        rResult[1]( 0, 0 ) = lx2 * fy1 * fz1;
        rResult[1]( 0, 1 ) = gx2 * gy1 * fz1;
        rResult[1]( 0, 2 ) = gx2 * fy1 * gz1;
        rResult[1]( 1, 0 ) = gx2 * gy1 * fz1;
        rResult[1]( 1, 1 ) = fx2 * ly1 * fz1;
        rResult[1]( 1, 2 ) = fx2 * gy1 * gz1;
        rResult[1]( 2, 0 ) = gx2 * fy1 * gz1;
        rResult[1]( 2, 1 ) = fx2 * gy1 * gz1;
        rResult[1]( 2, 2 ) = fx2 * fy1 * lz1;

        rResult[2]( 0, 0 ) = lx2 * fy2 * fz1;
        rResult[2]( 0, 1 ) = gx2 * gy2 * fz1;
        rResult[2]( 0, 2 ) = gx2 * fy2 * gz1;
        rResult[2]( 1, 0 ) = gx2 * gy2 * fz1;
        rResult[2]( 1, 1 ) = fx2 * ly2 * fz1;
        rResult[2]( 1, 2 ) = fx2 * gy2 * gz1;
        rResult[2]( 2, 0 ) = gx2 * fy2 * gz1;
        rResult[2]( 2, 1 ) = fx2 * gy2 * gz1;
        rResult[2]( 2, 2 ) = fx2 * fy2 * lz1;

        rResult[3]( 0, 0 ) = lx1 * fy2 * fz1;
        rResult[3]( 0, 1 ) = gx1 * gy2 * fz1;
        rResult[3]( 0, 2 ) = gx1 * fy2 * gz1;
        rResult[3]( 1, 0 ) = gx1 * gy2 * fz1;
        rResult[3]( 1, 1 ) = fx1 * ly2 * fz1;
        rResult[3]( 1, 2 ) = fx1 * gy2 * gz1;
        rResult[3]( 2, 0 ) = gx1 * fy2 * gz1;
        rResult[3]( 2, 1 ) = fx1 * gy2 * gz1;
        rResult[3]( 2, 2 ) = fx1 * fy2 * lz1;

        rResult[4]( 0, 0 ) = lx1 * fy1 * fz2;
        rResult[4]( 0, 1 ) = gx1 * gy1 * fz2;
        rResult[4]( 0, 2 ) = gx1 * fy1 * gz2;
        rResult[4]( 1, 0 ) = gx1 * gy1 * fz2;
        rResult[4]( 1, 1 ) = fx1 * ly1 * fz2;
        rResult[4]( 1, 2 ) = fx1 * gy1 * gz2;
        rResult[4]( 2, 0 ) = gx1 * fy1 * gz2;
        rResult[4]( 2, 1 ) = fx1 * gy1 * gz2;
        rResult[4]( 2, 2 ) = fx1 * fy1 * lz2;

        rResult[5]( 0, 0 ) = lx2 * fy1 * fz2;
        rResult[5]( 0, 1 ) = gx2 * gy1 * fz2;
        rResult[5]( 0, 2 ) = gx2 * fy1 * gz2;
        rResult[5]( 1, 0 ) = gx2 * gy1 * fz2;
        rResult[5]( 1, 1 ) = fx2 * ly1 * fz2;
        rResult[5]( 1, 2 ) = fx2 * gy1 * gz2;
        rResult[5]( 2, 0 ) = gx2 * fy1 * gz2;
        rResult[5]( 2, 1 ) = fx2 * gy1 * gz2;
        rResult[5]( 2, 2 ) = fx2 * fy1 * lz2;

        rResult[6]( 0, 0 ) = lx2 * fy2 * fz2;
        rResult[6]( 0, 1 ) = gx2 * gy2 * fz2;
        rResult[6]( 0, 2 ) = gx2 * fy2 * gz2;
        rResult[6]( 1, 0 ) = gx2 * gy2 * fz2;
        rResult[6]( 1, 1 ) = fx2 * ly2 * fz2;
        rResult[6]( 1, 2 ) = fx2 * gy2 * gz2;
        rResult[6]( 2, 0 ) = gx2 * fy2 * gz2;
        rResult[6]( 2, 1 ) = fx2 * gy2 * gz2;
        rResult[6]( 2, 2 ) = fx2 * fy2 * lz2;

        rResult[7]( 0, 0 ) = lx1 * fy2 * fz2;
        rResult[7]( 0, 1 ) = gx1 * gy2 * fz2;
        rResult[7]( 0, 2 ) = gx1 * fy2 * gz2;
        rResult[7]( 1, 0 ) = gx1 * gy2 * fz2;
        rResult[7]( 1, 1 ) = fx1 * ly2 * fz2;
        rResult[7]( 1, 2 ) = fx1 * gy2 * gz2;
        rResult[7]( 2, 0 ) = gx1 * fy2 * gz2;
        rResult[7]( 2, 1 ) = fx1 * gy2 * gz2;
        rResult[7]( 2, 2 ) = fx1 * fy2 * lz2;

        rResult[8]( 0, 0 ) = lx3 * fy1 * fz1;
        rResult[8]( 0, 1 ) = gx3 * gy1 * fz1;
        rResult[8]( 0, 2 ) = gx3 * fy1 * gz1;
        rResult[8]( 1, 0 ) = gx3 * gy1 * fz1;
        rResult[8]( 1, 1 ) = fx3 * ly1 * fz1;
        rResult[8]( 1, 2 ) = fx3 * gy1 * gz1;
        rResult[8]( 2, 0 ) = gx3 * fy1 * gz1;
        rResult[8]( 2, 1 ) = fx3 * gy1 * gz1;
        rResult[8]( 2, 2 ) = fx3 * fy1 * lz1;

        rResult[9]( 0, 0 ) = lx2 * fy3 * fz1;
        rResult[9]( 0, 1 ) = gx2 * gy3 * fz1;
        rResult[9]( 0, 2 ) = gx2 * fy3 * gz1;
        rResult[9]( 1, 0 ) = gx2 * gy3 * fz1;
        rResult[9]( 1, 1 ) = fx2 * ly3 * fz1;
        rResult[9]( 1, 2 ) = fx2 * gy3 * gz1;
        rResult[9]( 2, 0 ) = gx2 * fy3 * gz1;
        rResult[9]( 2, 1 ) = fx2 * gy3 * gz1;
        rResult[9]( 2, 2 ) = fx2 * fy3 * lz1;

        rResult[10]( 0, 0 ) = lx3 * fy2 * fz1;
        rResult[10]( 0, 1 ) = gx3 * gy2 * fz1;
        rResult[10]( 0, 2 ) = gx3 * fy2 * gz1;
        rResult[10]( 1, 0 ) = gx3 * gy2 * fz1;
        rResult[10]( 1, 1 ) = fx3 * ly2 * fz1;
        rResult[10]( 1, 2 ) = fx3 * gy2 * gz1;
        rResult[10]( 2, 0 ) = gx3 * fy2 * gz1;
        rResult[10]( 2, 1 ) = fx3 * gy2 * gz1;
        rResult[10]( 2, 2 ) = fx3 * fy2 * lz1;

        rResult[11]( 0, 0 ) = lx1 * fy3 * fz1;
        rResult[11]( 0, 1 ) = gx1 * gy3 * fz1;
        rResult[11]( 0, 2 ) = gx1 * fy3 * gz1;
        rResult[11]( 1, 0 ) = gx1 * gy3 * fz1;
        rResult[11]( 1, 1 ) = fx1 * ly3 * fz1;
        rResult[11]( 1, 2 ) = fx1 * gy3 * gz1;
        rResult[11]( 2, 0 ) = gx1 * fy3 * gz1;
        rResult[11]( 2, 1 ) = fx1 * gy3 * gz1;
        rResult[11]( 2, 2 ) = fx1 * fy3 * lz1;

        rResult[12]( 0, 0 ) = lx1 * fy1 * fz3;
        rResult[12]( 0, 1 ) = gx1 * gy1 * fz3;
        rResult[12]( 0, 2 ) = gx1 * fy1 * gz3;
        rResult[12]( 1, 0 ) = gx1 * gy1 * fz3;
        rResult[12]( 1, 1 ) = fx1 * ly1 * fz3;
        rResult[12]( 1, 2 ) = fx1 * gy1 * gz3;
        rResult[12]( 2, 0 ) = gx1 * fy1 * gz3;
        rResult[12]( 2, 1 ) = fx1 * gy1 * gz3;
        rResult[12]( 2, 2 ) = fx1 * fy1 * lz3;

        rResult[13]( 0, 0 ) = lx2 * fy1 * fz3;
        rResult[13]( 0, 1 ) = gx2 * gy1 * fz3;
        rResult[13]( 0, 2 ) = gx2 * fy1 * gz3;
        rResult[13]( 1, 0 ) = gx2 * gy1 * fz3;
        rResult[13]( 1, 1 ) = fx2 * ly1 * fz3;
        rResult[13]( 1, 2 ) = fx2 * gy1 * gz3;
        rResult[13]( 2, 0 ) = gx2 * fy1 * gz3;
        rResult[13]( 2, 1 ) = fx2 * gy1 * gz3;
        rResult[13]( 2, 2 ) = fx2 * fy1 * lz3;

        rResult[14]( 0, 0 ) = lx2 * fy2 * fz3;
        rResult[14]( 0, 1 ) = gx2 * gy2 * fz3;
        rResult[14]( 0, 2 ) = gx2 * fy2 * gz3;
        rResult[14]( 1, 0 ) = gx2 * gy2 * fz3;
        rResult[14]( 1, 1 ) = fx2 * ly2 * fz3;
        rResult[14]( 1, 2 ) = fx2 * gy2 * gz3;
        rResult[14]( 2, 0 ) = gx2 * fy2 * gz3;
        rResult[14]( 2, 1 ) = fx2 * gy2 * gz3;
        rResult[14]( 2, 2 ) = fx2 * fy2 * lz3;

        rResult[15]( 0, 0 ) = lx1 * fy2 * fz3;
        rResult[15]( 0, 1 ) = gx1 * gy2 * fz3;
        rResult[15]( 0, 2 ) = gx1 * fy2 * gz3;
        rResult[15]( 1, 0 ) = gx1 * gy2 * fz3;
        rResult[15]( 1, 1 ) = fx1 * ly2 * fz3;
        rResult[15]( 1, 2 ) = fx1 * gy2 * gz3;
        rResult[15]( 2, 0 ) = gx1 * fy2 * gz3;
        rResult[15]( 2, 1 ) = fx1 * gy2 * gz3;
        rResult[15]( 2, 2 ) = fx1 * fy2 * lz3;

        rResult[16]( 0, 0 ) = lx3 * fy1 * fz2;
        rResult[16]( 0, 1 ) = gx3 * gy1 * fz2;
        rResult[16]( 0, 2 ) = gx3 * fy1 * gz2;
        rResult[16]( 1, 0 ) = gx3 * gy1 * fz2;
        rResult[16]( 1, 1 ) = fx3 * ly1 * fz2;
        rResult[16]( 1, 2 ) = fx3 * gy1 * gz2;
        rResult[16]( 2, 0 ) = gx3 * fy1 * gz2;
        rResult[16]( 2, 1 ) = fx3 * gy1 * gz2;
        rResult[16]( 2, 2 ) = fx3 * fy1 * lz2;

        rResult[17]( 0, 0 ) = lx2 * fy3 * fz2;
        rResult[17]( 0, 1 ) = gx2 * gy3 * fz2;
        rResult[17]( 0, 2 ) = gx2 * fy3 * gz2;
        rResult[17]( 1, 0 ) = gx2 * gy3 * fz2;
        rResult[17]( 1, 1 ) = fx2 * ly3 * fz2;
        rResult[17]( 1, 2 ) = fx2 * gy3 * gz2;
        rResult[17]( 2, 0 ) = gx2 * fy3 * gz2;
        rResult[17]( 2, 1 ) = fx2 * gy3 * gz2;
        rResult[17]( 2, 2 ) = fx2 * fy3 * lz2;

        rResult[18]( 0, 0 ) = lx3 * fy2 * fz2;
        rResult[18]( 0, 1 ) = gx3 * gy2 * fz2;
        rResult[18]( 0, 2 ) = gx3 * fy2 * gz2;
        rResult[18]( 1, 0 ) = gx3 * gy2 * fz2;
        rResult[18]( 1, 1 ) = fx3 * ly2 * fz2;
        rResult[18]( 1, 2 ) = fx3 * gy2 * gz2;
        rResult[18]( 2, 0 ) = gx3 * fy2 * gz2;
        rResult[18]( 2, 1 ) = fx3 * gy2 * gz2;
        rResult[18]( 2, 2 ) = fx3 * fy2 * lz2;

        rResult[19]( 0, 0 ) = lx1 * fy3 * fz2;
        rResult[19]( 0, 1 ) = gx1 * gy3 * fz2;
        rResult[19]( 0, 2 ) = gx1 * fy3 * gz2;
        rResult[19]( 1, 0 ) = gx1 * gy3 * fz2;
        rResult[19]( 1, 1 ) = fx1 * ly3 * fz2;
        rResult[19]( 1, 2 ) = fx1 * gy3 * gz2;
        rResult[19]( 2, 0 ) = gx1 * fy3 * gz2;
        rResult[19]( 2, 1 ) = fx1 * gy3 * gz2;
        rResult[19]( 2, 2 ) = fx1 * fy3 * lz2;

        rResult[20]( 0, 0 ) = lx3 * fy3 * fz1;
        rResult[20]( 0, 1 ) = gx3 * gy3 * fz1;
        rResult[20]( 0, 2 ) = gx3 * fy3 * gz1;
        rResult[20]( 1, 0 ) = gx3 * gy3 * fz1;
        rResult[20]( 1, 1 ) = fx3 * ly3 * fz1;
        rResult[20]( 1, 2 ) = fx3 * gy3 * gz1;
        rResult[20]( 2, 0 ) = gx3 * fy3 * gz1;
        rResult[20]( 2, 1 ) = fx3 * gy3 * gz1;
        rResult[20]( 2, 2 ) = fx3 * fy3 * lz1;

        rResult[21]( 0, 0 ) = lx3 * fy1 * fz3;
        rResult[21]( 0, 1 ) = gx3 * gy1 * fz3;
        rResult[21]( 0, 2 ) = gx3 * fy1 * gz3;
        rResult[21]( 1, 0 ) = gx3 * gy1 * fz3;
        rResult[21]( 1, 1 ) = fx3 * ly1 * fz3;
        rResult[21]( 1, 2 ) = fx3 * gy1 * gz3;
        rResult[21]( 2, 0 ) = gx3 * fy1 * gz3;
        rResult[21]( 2, 1 ) = fx3 * gy1 * gz3;
        rResult[21]( 2, 2 ) = fx3 * fy1 * lz3;

        rResult[22]( 0, 0 ) = lx2 * fy3 * fz3;
        rResult[22]( 0, 1 ) = gx2 * gy3 * fz3;
        rResult[22]( 0, 2 ) = gx2 * fy3 * gz3;
        rResult[22]( 1, 0 ) = gx2 * gy3 * fz3;
        rResult[22]( 1, 1 ) = fx2 * ly3 * fz3;
        rResult[22]( 1, 2 ) = fx2 * gy3 * gz3;
        rResult[22]( 2, 0 ) = gx2 * fy3 * gz3;
        rResult[22]( 2, 1 ) = fx2 * gy3 * gz3;
        rResult[22]( 2, 2 ) = fx2 * fy3 * lz3;

        rResult[23]( 0, 0 ) = lx3 * fy2 * fz3;
        rResult[23]( 0, 1 ) = gx3 * gy2 * fz3;
        rResult[23]( 0, 2 ) = gx3 * fy2 * gz3;
        rResult[23]( 1, 0 ) = gx3 * gy2 * fz3;
        rResult[23]( 1, 1 ) = fx3 * ly2 * fz3;
        rResult[23]( 1, 2 ) = fx3 * gy2 * gz3;
        rResult[23]( 2, 0 ) = gx3 * fy2 * gz3;
        rResult[23]( 2, 1 ) = fx3 * gy2 * gz3;
        rResult[23]( 2, 2 ) = fx3 * fy2 * lz3;

        rResult[24]( 0, 0 ) = lx1 * fy3 * fz3;
        rResult[24]( 0, 1 ) = gx1 * gy3 * fz3;
        rResult[24]( 0, 2 ) = gx1 * fy3 * gz3;
        rResult[24]( 1, 0 ) = gx1 * gy3 * fz3;
        rResult[24]( 1, 1 ) = fx1 * ly3 * fz3;
        rResult[24]( 1, 2 ) = fx1 * gy3 * gz3;
        rResult[24]( 2, 0 ) = gx1 * fy3 * gz3;
        rResult[24]( 2, 1 ) = fx1 * gy3 * gz3;
        rResult[24]( 2, 2 ) = fx1 * fy3 * lz3;

        rResult[25]( 0, 0 ) = lx3 * fy3 * fz2;
        rResult[25]( 0, 1 ) = gx3 * gy3 * fz2;
        rResult[25]( 0, 2 ) = gx3 * fy3 * gz2;
        rResult[25]( 1, 0 ) = gx3 * gy3 * fz2;
        rResult[25]( 1, 1 ) = fx3 * ly3 * fz2;
        rResult[25]( 1, 2 ) = fx3 * gy3 * gz2;
        rResult[25]( 2, 0 ) = gx3 * fy3 * gz2;
        rResult[25]( 2, 1 ) = fx3 * gy3 * gz2;
        rResult[25]( 2, 2 ) = fx3 * fy3 * lz2;

        rResult[26]( 0, 0 ) = lx3 * fy3 * fz3;
        rResult[26]( 0, 1 ) = gx3 * gy3 * fz3;
        rResult[26]( 0, 2 ) = gx3 * fy3 * gz3;
        rResult[26]( 1, 0 ) = gx3 * gy3 * fz3;
        rResult[26]( 1, 1 ) = fx3 * ly3 * fz3;
        rResult[26]( 1, 2 ) = fx3 * gy3 * gz3;
        rResult[26]( 2, 0 ) = gx3 * fy3 * gz3;
        rResult[26]( 2, 1 ) = fx3 * gy3 * gz3;
        rResult[26]( 2, 2 ) = fx3 * fy3 * lz3;

        return rResult;
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

    Hexahedra3D27(): BaseType( PointsArrayType(), &msGeometryData ) {}

    /**
     * Private Operations
     */


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
     * KLUDGE: values are hard-coded!
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
        const int points_number = 27;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            ValueType fx1 = 0.5 * ( integration_points[pnt].X() - 1.0 ) * ( integration_points[pnt].X() );
            ValueType fx2 = 0.5 * ( integration_points[pnt].X() + 1.0 ) * ( integration_points[pnt].X() );
            ValueType fx3 = 1.0 - ( integration_points[pnt].X() * integration_points[pnt].X() );
            ValueType fy1 = 0.5 * ( integration_points[pnt].Y() - 1.0 ) * ( integration_points[pnt].Y() );
            ValueType fy2 = 0.5 * ( integration_points[pnt].Y() + 1.0 ) * ( integration_points[pnt].Y() );
            ValueType fy3 = 1.0 - ( integration_points[pnt].Y() * integration_points[pnt].Y() );
            ValueType fz1 = 0.5 * ( integration_points[pnt].Z() - 1.0 ) * ( integration_points[pnt].Z() );
            ValueType fz2 = 0.5 * ( integration_points[pnt].Z() + 1.0 ) * ( integration_points[pnt].Z() );
            ValueType fz3 = 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() );

            shape_function_values( pnt, 0 ) = ( fx1 * fy1 * fz1 );
            shape_function_values( pnt, 1 ) = ( fx2 * fy1 * fz1 );
            shape_function_values( pnt, 2 ) = ( fx2 * fy2 * fz1 );
            shape_function_values( pnt, 3 ) = ( fx1 * fy2 * fz1 );
            shape_function_values( pnt, 4 ) = ( fx1 * fy1 * fz2 );
            shape_function_values( pnt, 5 ) = ( fx2 * fy1 * fz2 );
            shape_function_values( pnt, 6 ) = ( fx2 * fy2 * fz2 );
            shape_function_values( pnt, 7 ) = ( fx1 * fy2 * fz2 );
            shape_function_values( pnt, 8 ) = ( fx3 * fy1 * fz1 );
            shape_function_values( pnt, 9 ) = ( fx2 * fy3 * fz1 );
            shape_function_values( pnt, 10 ) = ( fx3 * fy2 * fz1 );
            shape_function_values( pnt, 11 ) = ( fx1 * fy3 * fz1 );
            shape_function_values( pnt, 12 ) = ( fx1 * fy1 * fz3 );
            shape_function_values( pnt, 13 ) = ( fx2 * fy1 * fz3 );
            shape_function_values( pnt, 14 ) = ( fx2 * fy2 * fz3 );
            shape_function_values( pnt, 15 ) = ( fx1 * fy2 * fz3 );
            shape_function_values( pnt, 16 ) = ( fx3 * fy1 * fz2 );
            shape_function_values( pnt, 17 ) = ( fx2 * fy3 * fz2 );
            shape_function_values( pnt, 18 ) = ( fx3 * fy2 * fz2 );
            shape_function_values( pnt, 19 ) = ( fx1 * fy3 * fz2 );
            shape_function_values( pnt, 20 ) = ( fx3 * fy3 * fz1 );
            shape_function_values( pnt, 21 ) = ( fx3 * fy1 * fz3 );
            shape_function_values( pnt, 22 ) = ( fx2 * fy3 * fz3 );
            shape_function_values( pnt, 23 ) = ( fx3 * fy2 * fz3 );
            shape_function_values( pnt, 24 ) = ( fx1 * fy3 * fz3 );
            shape_function_values( pnt, 25 ) = ( fx3 * fy3 * fz2 );
            shape_function_values( pnt, 26 ) = ( fx3 * fy3 * fz3 );
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
        //initialising container                //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            ValueType fx1 = 0.5 * ( integration_points[pnt].X() - 1.0 ) * ( integration_points[pnt].X() );
            ValueType fx2 = 0.5 * ( integration_points[pnt].X() + 1.0 ) * ( integration_points[pnt].X() );
            ValueType fx3 = 1.0 - ( integration_points[pnt].X() * integration_points[pnt].X() );
            ValueType fy1 = 0.5 * ( integration_points[pnt].Y() - 1.0 ) * ( integration_points[pnt].Y() );
            ValueType fy2 = 0.5 * ( integration_points[pnt].Y() + 1.0 ) * ( integration_points[pnt].Y() );
            ValueType fy3 = 1.0 - ( integration_points[pnt].Y() * integration_points[pnt].Y() );
            ValueType fz1 = 0.5 * ( integration_points[pnt].Z() - 1.0 ) * ( integration_points[pnt].Z() );
            ValueType fz2 = 0.5 * ( integration_points[pnt].Z() + 1.0 ) * ( integration_points[pnt].Z() );
            ValueType fz3 = 1.0 - ( integration_points[pnt].Z() * integration_points[pnt].Z() );

            ValueType gx1 = 0.5 * ( 2.0 * integration_points[pnt].X() - 1.0 );
            ValueType gx2 = 0.5 * ( 2.0 * integration_points[pnt].X() + 1.0 );
            ValueType gx3 = -2 * integration_points[pnt].X();
            ValueType gy1 = 0.5 * ( 2.0 * integration_points[pnt].Y() - 1.0 );
            ValueType gy2 = 0.5 * ( 2.0 * integration_points[pnt].Y() + 1.0 );
            ValueType gy3 = -2 * integration_points[pnt].Y();
            ValueType gz1 = 0.5 * ( 2.0 * integration_points[pnt].Z() - 1.0 );
            ValueType gz2 = 0.5 * ( 2.0 * integration_points[pnt].Z() + 1.0 );
            ValueType gz3 = -2 * integration_points[pnt].Z();
            //setting up result matrix
            Matrix result = ZeroMatrix( 27, 3 );

            result( 0, 0 ) = gx1 * fy1 * fz1;
            result( 0, 1 ) = fx1 * gy1 * fz1;
            result( 0, 2 ) = fx1 * fy1 * gz1;

            result( 1, 0 ) = gx2 * fy1 * fz1;
            result( 1, 1 ) = fx2 * gy1 * fz1;
            result( 1, 2 ) = fx2 * fy1 * gz1;

            result( 2, 0 ) = gx2 * fy2 * fz1;
            result( 2, 1 ) = fx2 * gy2 * fz1;
            result( 2, 2 ) = fx2 * fy2 * gz1;

            result( 3, 0 ) = gx1 * fy2 * fz1;
            result( 3, 1 ) = fx1 * gy2 * fz1;
            result( 3, 2 ) = fx1 * fy2 * gz1;

            result( 4, 0 ) = gx1 * fy1 * fz2;
            result( 4, 1 ) = fx1 * gy1 * fz2;
            result( 4, 2 ) = fx1 * fy1 * gz2;

            result( 5, 0 ) = gx2 * fy1 * fz2;
            result( 5, 1 ) = fx2 * gy1 * fz2;
            result( 5, 2 ) = fx2 * fy1 * gz2;

            result( 6, 0 ) = gx2 * fy2 * fz2;
            result( 6, 1 ) = fx2 * gy2 * fz2;
            result( 6, 2 ) = fx2 * fy2 * gz2;

            result( 7, 0 ) = gx1 * fy2 * fz2;
            result( 7, 1 ) = fx1 * gy2 * fz2;
            result( 7, 2 ) = fx1 * fy2 * gz2;

            result( 8, 0 ) = gx3 * fy1 * fz1;
            result( 8, 1 ) = fx3 * gy1 * fz1;
            result( 8, 2 ) = fx3 * fy1 * gz1;

            result( 9, 0 ) = gx2 * fy3 * fz1;
            result( 9, 1 ) = fx2 * gy3 * fz1;
            result( 9, 2 ) = fx2 * fy3 * gz1;

            result( 10, 0 ) = gx3 * fy2 * fz1;
            result( 10, 1 ) = fx3 * gy2 * fz1;
            result( 10, 2 ) = fx3 * fy2 * gz1;

            result( 11, 0 ) = gx1 * fy3 * fz1;
            result( 11, 1 ) = fx1 * gy3 * fz1;
            result( 11, 2 ) = fx1 * fy3 * gz1;

            result( 12, 0 ) = gx1 * fy1 * fz3;
            result( 12, 1 ) = fx1 * gy1 * fz3;
            result( 12, 2 ) = fx1 * fy1 * gz3;

            result( 13, 0 ) = gx2 * fy1 * fz3;
            result( 13, 1 ) = fx2 * gy1 * fz3;
            result( 13, 2 ) = fx2 * fy1 * gz3;

            result( 14, 0 ) = gx2 * fy2 * fz3;
            result( 14, 1 ) = fx2 * gy2 * fz3;
            result( 14, 2 ) = fx2 * fy2 * gz3;

            result( 15, 0 ) = gx1 * fy2 * fz3;
            result( 15, 1 ) = fx1 * gy2 * fz3;
            result( 15, 2 ) = fx1 * fy2 * gz3;

            result( 16, 0 ) = gx3 * fy1 * fz2;
            result( 16, 1 ) = fx3 * gy1 * fz2;
            result( 16, 2 ) = fx3 * fy1 * gz2;

            result( 17, 0 ) = gx2 * fy3 * fz2;
            result( 17, 1 ) = fx2 * gy3 * fz2;
            result( 17, 2 ) = fx2 * fy3 * gz2;

            result( 18, 0 ) = gx3 * fy2 * fz2;
            result( 18, 1 ) = fx3 * gy2 * fz2;
            result( 18, 2 ) = fx3 * fy2 * gz2;

            result( 19, 0 ) = gx1 * fy3 * fz2;
            result( 19, 1 ) = fx1 * gy3 * fz2;
            result( 19, 2 ) = fx1 * fy3 * gz2;

            result( 20, 0 ) = gx3 * fy3 * fz1;
            result( 20, 1 ) = fx3 * gy3 * fz1;
            result( 20, 2 ) = fx3 * fy3 * gz1;

            result( 21, 0 ) = gx3 * fy1 * fz3;
            result( 21, 1 ) = fx3 * gy1 * fz3;
            result( 21, 2 ) = fx3 * fy1 * gz3;

            result( 22, 0 ) = gx2 * fy3 * fz3;
            result( 22, 1 ) = fx2 * gy3 * fz3;
            result( 22, 2 ) = fx2 * fy3 * gz3;

            result( 23, 0 ) = gx3 * fy2 * fz3;
            result( 23, 1 ) = fx3 * gy2 * fz3;
            result( 23, 2 ) = fx3 * fy2 * gz3;

            result( 24, 0 ) = gx1 * fy3 * fz3;
            result( 24, 1 ) = fx1 * gy3 * fz3;
            result( 24, 2 ) = fx1 * fy3 * gz3;

            result( 25, 0 ) = gx3 * fy3 * fz2;
            result( 25, 1 ) = fx3 * gy3 * fz2;
            result( 25, 2 ) = fx3 * fy3 * gz2;

            result( 26, 0 ) = gx3 * fy3 * fz3;
            result( 26, 1 ) = fx3 * gy3 * fz3;
            result( 26, 2 ) = fx3 * fy3 * gz3;

            d_shape_f_values[pnt] = result;
        }

        return d_shape_f_values;
    }

    static const IntegrationPointsContainerType AllIntegrationPoints()
    {
        IntegrationPointsContainerType integration_points =
        {
            {
                Quadrature < HexahedronGaussLegendreIntegrationPoints<1>, 3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < HexahedronGaussLegendreIntegrationPoints<2>, 3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < HexahedronGaussLegendreIntegrationPoints<3>, 3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < HexahedronGaussLegendreIntegrationPoints<4>, 3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < HexahedronGaussLegendreIntegrationPoints<5>, 3, IntegrationPoint<3> >::GenerateIntegrationPoints()
            }
        };
        return integration_points;
    }

    static const ShapeFunctionsValuesContainerType AllShapeFunctionsValues()
    {
        ShapeFunctionsValuesContainerType shape_functions_values =
        {
            {
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_5 )
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Hexahedra3D27<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 )
            }
        };
        return shape_functions_local_gradients;
    }

    /**
     * Private Friends
     */

    template<class TOtherPointType> friend class Hexahedra3D27;


    /**
     * Un accessible methods
     */

}; // Class Hexahedra3D27

template<class TPointType> const
GeometryData Hexahedra3D27<TPointType>::msGeometryData(
    3, 3, 3, GeometryData::IntegrationMethod::GI_GAUSS_3,
    Hexahedra3D27<TPointType>::AllIntegrationPoints(),
    Hexahedra3D27<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

}// namespace Kratos.

#endif // KRATOS_HEXAHEDRA_3D_27_H_INCLUDED  defined
