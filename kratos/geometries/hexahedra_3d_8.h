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

#if !defined(KRATOS_HEXAHEDRA_3D_8_H_INCLUDED )
#define  KRATOS_HEXAHEDRA_3D_8_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/quadrilateral_3d_4.h"
#include "integration/hexahedron_gauss_legendre_integration_points.h"


namespace Kratos
{

/**
 * An eight node hexahedra geometry with linear shape functions
 *             v
 *      3----------2
 *      |\     ^   |\
 *      | \    |   | \
 *      |  \   |   |  \
 *      |   7------+---6
 *      |   |  +-- |-- | -> u
 *      0---+---\--1   |
 *       \  |    \  \  |
 *        \ |     \  \ |
 *         \|      w  \|
 *          4----------5
 */
template<class TPointType> class Hexahedra3D8 : public Geometry<TPointType>
{
public:
    ///@name Type Definitions
    ///@{

    /**
     * Geometry as base class.
     */
    typedef Geometry<TPointType> BaseType;

    /**
     * Type of edge and face geometries
     */
    typedef Line3D2<TPointType> EdgeType;
    typedef Quadrilateral3D4<TPointType> FaceType;

    /**
     * Pointer definition of Hexahedra3D8
     */
    KRATOS_CLASS_POINTER_DEFINITION( Hexahedra3D8 );

    typedef typename BaseType::IntegrationMethod IntegrationMethod;

    typedef typename BaseType::GeometriesArrayType GeometriesArrayType;

    typedef typename BaseType::DataType DataType;

    typedef typename BaseType::ValueType ValueType;

    typedef typename BaseType::IndexType IndexType;

    typedef typename BaseType::SizeType SizeType;

    typedef typename BaseType::PointType PointType;

    typedef typename BaseType::PointsArrayType PointsArrayType;

    typedef typename BaseType::IntegrationPointType IntegrationPointType;

    typedef typename BaseType::IntegrationPointsArrayType IntegrationPointsArrayType;

    typedef typename BaseType::IntegrationPointsContainerType IntegrationPointsContainerType;

    typedef typename BaseType::ShapeFunctionsValuesContainerType ShapeFunctionsValuesContainerType;

    typedef typename BaseType::ShapeFunctionsLocalGradientsContainerType ShapeFunctionsLocalGradientsContainerType;

    typedef typename BaseType::JacobiansType JacobiansType;

    typedef typename BaseType::ShapeFunctionsGradientsType ShapeFunctionsGradientsType;

    typedef typename BaseType::ShapeFunctionsSecondDerivativesType ShapeFunctionsSecondDerivativesType;

    typedef typename BaseType::ShapeFunctionsThirdDerivativesType ShapeFunctionsThirdDerivativesType;

    typedef typename BaseType::NormalType NormalType;

    typedef typename BaseType::CoordinatesArrayType CoordinatesArrayType;

    typedef typename BaseType::LocalCoordinatesArrayType LocalCoordinatesArrayType;

    typedef typename BaseType::MatrixType MatrixType;
    typedef typename BaseType::ZeroMatrixType ZeroMatrixType;

    typedef typename BaseType::VectorType VectorType;
    typedef typename BaseType::ZeroVectorType ZeroVectorType;

    ///@}
    ///@name Life Cycle
    ///@{

    Hexahedra3D8( const PointType& Point1, const PointType& Point2,
                  const PointType& Point3, const PointType& Point4,
                  const PointType& Point5, const PointType& Point6,
                  const PointType& Point7, const PointType& Point8 )
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
    }

    Hexahedra3D8( typename PointType::Pointer pPoint1,
                  typename PointType::Pointer pPoint2,
                  typename PointType::Pointer pPoint3,
                  typename PointType::Pointer pPoint4,
                  typename PointType::Pointer pPoint5,
                  typename PointType::Pointer pPoint6,
                  typename PointType::Pointer pPoint7,
                  typename PointType::Pointer pPoint8 )
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
    }

    Hexahedra3D8( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 8 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                                "Invalid points number. Expected 8, given " ,
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
    Hexahedra3D8( Hexahedra3D8 const& rOther )
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
    template<class TOtherPointType> Hexahedra3D8( Hexahedra3D8<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    ~Hexahedra3D8() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Hexahedra;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Hexahedra3D8;
    }

    ///@}
    ///@name Operators
    ///@{

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
    Hexahedra3D8& operator=( const Hexahedra3D8& rOther )
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
    Hexahedra3D8& operator=( Hexahedra3D8<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Hexahedra3D8( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Hexahedra3D8< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 8)
            rResult.resize( 8, false );
        std::fill( rResult.begin(), rResult.end(), 1.00 / 8.00 );
        return rResult;
    }

    ///@}
    ///@name Information
    ///@{

    DataType Length() const override
    {
        DataType length = 0.000;
        length = cbrt( std::abs( Area() ) );
        return length;
    }

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

    DataType DomainSize() const override
    {
        return Volume();
    }

    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if ( rResult.size1() != 8 || rResult.size2() != 3 )
            rResult.resize( 8, 3, false );

        rResult( 0, 0 ) = -1.0;
        rResult( 0, 1 ) = -1.0;
        rResult( 0, 2 ) = -1.0;

        rResult( 1, 0 ) = 1.0;
        rResult( 1, 1 ) = -1.0;
        rResult( 1, 2 ) = -1.0;

        rResult( 2, 0 ) = 1.0;
        rResult( 2, 1 ) = 1.0;
        rResult( 2, 2 ) = -1.0;

        rResult( 3, 0 ) = -1.0;
        rResult( 3, 1 ) = 1.0;
        rResult( 3, 2 ) = -1.0;

        rResult( 4, 0 ) = -1.0;
        rResult( 4, 1 ) = -1.0;
        rResult( 4, 2 ) = 1.0;

        rResult( 5, 0 ) = 1.0;
        rResult( 5, 1 ) = -1.0;
        rResult( 5, 2 ) = 1.0;

        rResult( 6, 0 ) = 1.0;
        rResult( 6, 1 ) = 1.0;
        rResult( 6, 2 ) = 1.0;

        rResult( 7, 0 ) = -1.0;
        rResult( 7, 1 ) = 1.0;
        rResult( 7, 2 ) = 1.0;

        return rResult;
    }

    bool IsInside( const LocalCoordinatesArrayType& rPoint, const ValueType tol ) const override
    {
        if ( std::abs( rPoint[0] ) < 1 + tol )
            if ( std::abs( rPoint[1] ) < 1 + tol )
                if ( std::abs( rPoint[2] ) < 1 + tol )
                    return true;

        return false;
    }

    SizeType EdgesNumber() const override
    {
        return 12;
    }

    SizeType FacesNumber() const override
    {
        return 6;
    }

    GeometriesArrayType Edges() const override
    {
        GeometriesArrayType edges = GeometriesArrayType();
        typedef typename Geometry<TPointType>::Pointer EdgePointerType;
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 1 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 2 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 3 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 0 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 5 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 6 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 7 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 4 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 4 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 5 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 6 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 7 ) ) ) );
        return edges;
    }

    GeometriesArrayType Faces() const override
    {
        GeometriesArrayType faces = GeometriesArrayType();
        typedef typename Geometry<TPointType>::Pointer FacePointerType;
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 0 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 4 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 1 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 3 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 7 ),
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 4 ) ) ) );
        faces.push_back( FacePointerType( new FaceType(
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 6 ),
                                              this->pGetPoint( 7 ) ) ) );
        return faces;
    }

    ///@}
    ///@name Shape Function
    ///@{

    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex, const LocalCoordinatesArrayType& rPoint ) const override
    {
        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( 0.125*( 1.0 - rPoint[0] )*( 1.0 - rPoint[1] )*( 1.0 - rPoint[2] ) );
        case 1:
            return( 0.125*( 1.0 + rPoint[0] )*( 1.0 - rPoint[1] )*( 1.0 - rPoint[2] ) );
        case 2:
            return( 0.125*( 1.0 + rPoint[0] )*( 1.0 + rPoint[1] )*( 1.0 - rPoint[2] ) );
        case 3:
            return( 0.125*( 1.0 - rPoint[0] )*( 1.0 + rPoint[1] )*( 1.0 - rPoint[2] ) );
        case 4:
            return( 0.125*( 1.0 - rPoint[0] )*( 1.0 - rPoint[1] )*( 1.0 + rPoint[2] ) );
        case 5:
            return( 0.125*( 1.0 + rPoint[0] )*( 1.0 - rPoint[1] )*( 1.0 + rPoint[2] ) );
        case 6:
            return( 0.125*( 1.0 + rPoint[0] )*( 1.0 + rPoint[1] )*( 1.0 + rPoint[2] ) );
        case 7:
            return( 0.125*( 1.0 - rPoint[0] )*( 1.0 + rPoint[1] )*( 1.0 + rPoint[2] ) );
        default:
            KRATOS_THROW_ERROR( std::logic_error,
                                "Wrong index of shape function!" , *this );
        }

        return 0;
    }

    Matrix& ShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( rResult.size1() != 8 || rResult.size2() != 3 )
            rResult.resize( 8, 3, false );

        rResult( 0, 0 ) = -0.125 * ( 1.0 - rPoint[1] ) * ( 1.0 - rPoint[2] );
        rResult( 0, 1 ) = -0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 - rPoint[2] );
        rResult( 0, 2 ) = -0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 - rPoint[1] );
        rResult( 1, 0 ) =  0.125 * ( 1.0 - rPoint[1] ) * ( 1.0 - rPoint[2] );
        rResult( 1, 1 ) = -0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 - rPoint[2] );
        rResult( 1, 2 ) = -0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 - rPoint[1] );
        rResult( 2, 0 ) =  0.125 * ( 1.0 + rPoint[1] ) * ( 1.0 - rPoint[2] );
        rResult( 2, 1 ) =  0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 - rPoint[2] );
        rResult( 2, 2 ) = -0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 + rPoint[1] );
        rResult( 3, 0 ) = -0.125 * ( 1.0 + rPoint[1] ) * ( 1.0 - rPoint[2] );
        rResult( 3, 1 ) =  0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 - rPoint[2] );
        rResult( 3, 2 ) = -0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 + rPoint[1] );
        rResult( 4, 0 ) = -0.125 * ( 1.0 - rPoint[1] ) * ( 1.0 + rPoint[2] );
        rResult( 4, 1 ) = -0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 + rPoint[2] );
        rResult( 4, 2 ) =  0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 - rPoint[1] );
        rResult( 5, 0 ) =  0.125 * ( 1.0 - rPoint[1] ) * ( 1.0 + rPoint[2] );
        rResult( 5, 1 ) = -0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 + rPoint[2] );
        rResult( 5, 2 ) =  0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 - rPoint[1] );
        rResult( 6, 0 ) =  0.125 * ( 1.0 + rPoint[1] ) * ( 1.0 + rPoint[2] );
        rResult( 6, 1 ) =  0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 + rPoint[2] );
        rResult( 6, 2 ) =  0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 + rPoint[1] );
        rResult( 7, 0 ) = -0.125 * ( 1.0 + rPoint[1] ) * ( 1.0 + rPoint[2] );
        rResult( 7, 1 ) =  0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 + rPoint[2] );
        rResult( 7, 2 ) =  0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 + rPoint[1] );

        return rResult;
    }

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

        rResult[0]( 0, 0 ) = 0.0;
        rResult[0]( 0, 1 ) = 0.125 * ( 1.0 - rPoint[2] );
        rResult[0]( 0, 2 ) = 0.125 * ( 1.0 - rPoint[1] );
        rResult[0]( 1, 0 ) = 0.125 * ( 1.0 - rPoint[2] );
        rResult[0]( 1, 1 ) = 0.0;
        rResult[0]( 1, 2 ) = 0.125 * ( 1.0 - rPoint[0] );
        rResult[0]( 2, 0 ) = 0.125 * ( 1.0 - rPoint[1] );
        rResult[0]( 2, 1 ) = 0.125 * ( 1.0 - rPoint[0] );
        rResult[0]( 2, 2 ) = 0.0;

        rResult[1]( 0, 0 ) = 0.0;
        rResult[1]( 0, 1 ) = -0.125 * ( 1.0 - rPoint[2] );
        rResult[1]( 0, 2 ) = -0.125 * ( 1.0 - rPoint[1] );
        rResult[1]( 1, 0 ) = -0.125 * ( 1.0 - rPoint[2] );
        rResult[1]( 1, 1 ) = 0.0;
        rResult[1]( 1, 2 ) = 0.125 * ( 1.0 + rPoint[0] );
        rResult[1]( 2, 0 ) = -0.125 * ( 1.0 - rPoint[1] );
        rResult[1]( 2, 1 ) = 0.125 * ( 1.0 + rPoint[0] );
        rResult[1]( 2, 2 ) = 0.0;

        rResult[2]( 0, 0 ) = 0.0;
        rResult[2]( 0, 1 ) = 0.125 * ( 1.0 - rPoint[2] );
        rResult[2]( 0, 2 ) = -0.125 * ( 1.0 + rPoint[1] );
        rResult[2]( 1, 0 ) = 0.125 * ( 1.0 - rPoint[2] );
        rResult[2]( 1, 1 ) = 0.0;
        rResult[2]( 1, 2 ) = -0.125 * ( 1.0 + rPoint[0] );
        rResult[2]( 2, 0 ) = -0.125 * ( 1.0 + rPoint[1] );
        rResult[2]( 2, 1 ) = -0.125 * ( 1.0 + rPoint[0] );
        rResult[2]( 2, 2 ) = 0.0;

        rResult[3]( 0, 0 ) = 0.0;
        rResult[3]( 0, 1 ) = -0.125 * ( 1.0 - rPoint[2] );
        rResult[3]( 0, 2 ) = 0.125 * ( 1.0 + rPoint[1] );
        rResult[3]( 1, 0 ) = -0.125 * ( 1.0 - rPoint[2] );
        rResult[3]( 1, 1 ) = 0.0;
        rResult[3]( 1, 2 ) = -0.125 * ( 1.0 - rPoint[0] );
        rResult[3]( 2, 0 ) = 0.125 * ( 1.0 + rPoint[1] );
        rResult[3]( 2, 1 ) = -0.125 * ( 1.0 - rPoint[0] );
        rResult[3]( 2, 2 ) = 0.0;

        rResult[4]( 0, 0 ) = 0.0;
        rResult[4]( 0, 1 ) = 0.125 * ( 1.0 + rPoint[2] );
        rResult[4]( 0, 2 ) = -0.125 * ( 1.0 - rPoint[1] );
        rResult[4]( 1, 0 ) = 0.125 * ( 1.0 + rPoint[2] );
        rResult[4]( 1, 1 ) = 0.0;
        rResult[4]( 1, 2 ) = -0.125 * ( 1.0 - rPoint[0] );
        rResult[4]( 2, 0 ) = -0.125 * ( 1.0 - rPoint[1] );
        rResult[4]( 2, 1 ) = -0.125 * ( 1.0 - rPoint[0] );
        rResult[4]( 2, 2 ) = 0.0;

        rResult[5]( 0, 0 ) = 0.0;
        rResult[5]( 0, 1 ) = -0.125 * ( 1.0 + rPoint[2] );
        rResult[5]( 0, 2 ) = 0.125 * ( 1.0 - rPoint[1] );
        rResult[5]( 1, 0 ) = -0.125 * ( 1.0 + rPoint[2] );
        rResult[5]( 1, 1 ) = 0.0;
        rResult[5]( 1, 2 ) = -0.125 * ( 1.0 + rPoint[0] );
        rResult[5]( 2, 0 ) = 0.125 * ( 1.0 - rPoint[1] );
        rResult[5]( 2, 1 ) = -0.125 * ( 1.0 + rPoint[0] );
        rResult[5]( 2, 2 ) = 0.0;

        rResult[6]( 0, 0 ) = 0.0;
        rResult[6]( 0, 1 ) = 0.125 * ( 1.0 + rPoint[2] );
        rResult[6]( 0, 2 ) = 0.125 * ( 1.0 + rPoint[1] );
        rResult[6]( 1, 0 ) = 0.125 * ( 1.0 + rPoint[2] );
        rResult[6]( 1, 1 ) = 0.0;
        rResult[6]( 1, 2 ) = 0.125 * ( 1.0 + rPoint[0] );
        rResult[6]( 2, 0 ) = 0.125 * ( 1.0 + rPoint[1] );
        rResult[6]( 2, 1 ) = 0.125 * ( 1.0 + rPoint[0] );
        rResult[6]( 2, 2 ) = 0.0;

        rResult[7]( 0, 0 ) = 0.0;
        rResult[7]( 0, 1 ) = -0.125 * ( 1.0 + rPoint[2] );
        rResult[7]( 0, 2 ) = -0.125 * ( 1.0 + rPoint[1] );
        rResult[7]( 1, 0 ) = -0.125 * ( 1.0 + rPoint[2] );
        rResult[7]( 1, 1 ) = 0.0;
        rResult[7]( 1, 2 ) = 0.125 * ( 1.0 - rPoint[0] );
        rResult[7]( 2, 0 ) = -0.125 * ( 1.0 + rPoint[1] );
        rResult[7]( 2, 1 ) = 0.125 * ( 1.0 - rPoint[0] );
        rResult[7]( 2, 2 ) = 0.0;

        return rResult;
    }

    ///@}
    ///@name Input and Output
    ///@{

    std::string Info() const override
    {
        return "3 dimensional hexahedra with eight nodes in 3D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "3 dimensional hexahedra with eight nodes in 3D space";
    }

    void PrintData( std::ostream& rOStream ) const override
    {
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian in the origin\t : " << jacobian;
    }

    ///@}
    ///@name Friends
    ///@{

    ///@}

protected:
    /**
     * there are no protected class members
     */

private:

    ///@name Static Member Variables
    ///@{

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

    Hexahedra3D8(): BaseType( PointsArrayType(), &msGeometryData ) {}

    ///@}
    ///@name Private Operations
    ///@{

    /**
     * Calculates the gradients in terms of local coordinateds
     * of all shape functions in a given point.
     *
     * @param rPoint the current point at which the gradients are calculated
     * @return the gradients of all shape functions
     * \f$ \frac{\partial N^i}{\partial \xi_j} \f$
     */
    static Matrix ShapeFunctionsLocalGradients( const LocalCoordinatesArrayType& rPoint )
    {
        Matrix result = ZeroMatrix( 8, 3 );
        result( 0, 0 ) = -0.125 * ( 1.0 - rPoint[1] ) * ( 1.0 - rPoint[2] );
        result( 0, 1 ) = -0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 - rPoint[2] );
        result( 0, 2 ) = -0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 - rPoint[1] );
        result( 1, 0 ) =  0.125 * ( 1.0 - rPoint[1] ) * ( 1.0 - rPoint[2] );
        result( 1, 1 ) = -0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 - rPoint[2] );
        result( 1, 2 ) = -0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 - rPoint[1] );
        result( 2, 0 ) =  0.125 * ( 1.0 + rPoint[1] ) * ( 1.0 - rPoint[2] );
        result( 2, 1 ) =  0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 - rPoint[2] );
        result( 2, 2 ) = -0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 + rPoint[1] );
        result( 3, 0 ) = -0.125 * ( 1.0 + rPoint[1] ) * ( 1.0 - rPoint[2] );
        result( 3, 1 ) =  0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 - rPoint[2] );
        result( 3, 2 ) = -0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 + rPoint[1] );
        result( 4, 0 ) = -0.125 * ( 1.0 - rPoint[1] ) * ( 1.0 + rPoint[2] );
        result( 4, 1 ) = -0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 + rPoint[2] );
        result( 4, 2 ) =  0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 - rPoint[1] );
        result( 5, 0 ) =  0.125 * ( 1.0 - rPoint[1] ) * ( 1.0 + rPoint[2] );
        result( 5, 1 ) = -0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 + rPoint[2] );
        result( 5, 2 ) =  0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 - rPoint[1] );
        result( 6, 0 ) =  0.125 * ( 1.0 + rPoint[1] ) * ( 1.0 + rPoint[2] );
        result( 6, 1 ) =  0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 + rPoint[2] );
        result( 6, 2 ) =  0.125 * ( 1.0 + rPoint[0] ) * ( 1.0 + rPoint[1] );
        result( 7, 0 ) = -0.125 * ( 1.0 + rPoint[1] ) * ( 1.0 + rPoint[2] );
        result( 7, 1 ) =  0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 + rPoint[2] );
        result( 7, 2 ) =  0.125 * ( 1.0 - rPoint[0] ) * ( 1.0 + rPoint[1] );
        return result;
    }

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
        IntegrationPointsContainerType all_integration_points = AllIntegrationPoints();
        IntegrationPointsArrayType& integration_points = all_integration_points[static_cast<int>(ThisMethod)];

        //number of integration points
        const int integration_points_number = integration_points.size();
        //number of nodes in current geometry
        const int points_number = 8;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            shape_function_values( pnt, 0 ) =
                0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() )
                * ( 1.0 - integration_points[pnt].Z() );
            shape_function_values( pnt, 1 ) =
                0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() )
                * ( 1.0 - integration_points[pnt].Z() );
            shape_function_values( pnt, 2 ) =
                0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() )
                * ( 1.0 - integration_points[pnt].Z() );
            shape_function_values( pnt, 3 ) =
                0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() )
                * ( 1.0 - integration_points[pnt].Z() );
            shape_function_values( pnt, 4 ) =
                0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() )
                * ( 1.0 + integration_points[pnt].Z() );
            shape_function_values( pnt, 5 ) =
                0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() )
                * ( 1.0 + integration_points[pnt].Z() );
            shape_function_values( pnt, 6 ) =
                0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() )
                * ( 1.0 + integration_points[pnt].Z() );
            shape_function_values( pnt, 7 ) =
                0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() )
                * ( 1.0 + integration_points[pnt].Z() );
        }

        return shape_function_values;
    }

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
            Matrix& result = d_shape_f_values[pnt];
            result = ZeroMatrix( 8, 3 );
            result( 0, 0 ) =
                -0.125 * ( 1.0 - integration_points[pnt].Y() )
                * ( 1.0 - integration_points[pnt].Z() );
            result( 0, 1 ) =
                -0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Z() );
            result( 0, 2 ) =
                -0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() );
            result( 1, 0 ) =
                0.125 * ( 1.0 - integration_points[pnt].Y() )
                * ( 1.0 - integration_points[pnt].Z() );
            result( 1, 1 ) =
                -0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Z() );
            result( 1, 2 ) =
                -0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() );
            result( 2, 0 ) =
                0.125 * ( 1.0 + integration_points[pnt].Y() )
                * ( 1.0 - integration_points[pnt].Z() );
            result( 2, 1 ) =
                0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Z() );
            result( 2, 2 ) =
                -0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() );
            result( 3, 0 ) =
                -0.125 * ( 1.0 + integration_points[pnt].Y() )
                * ( 1.0 - integration_points[pnt].Z() );
            result( 3, 1 ) =
                0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Z() );
            result( 3, 2 ) =
                -0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() );
            result( 4, 0 ) =
                -0.125 * ( 1.0 - integration_points[pnt].Y() )
                * ( 1.0 + integration_points[pnt].Z() );
            result( 4, 1 ) =
                -0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Z() );
            result( 4, 2 ) =
                0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() );
            result( 5, 0 ) =
                0.125 * ( 1.0 - integration_points[pnt].Y() )
                * ( 1.0 + integration_points[pnt].Z() );
            result( 5, 1 ) =
                -0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Z() );
            result( 5, 2 ) =
                0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() );
            result( 6, 0 ) =
                0.125 * ( 1.0 + integration_points[pnt].Y() )
                * ( 1.0 + integration_points[pnt].Z() );
            result( 6, 1 ) =
                0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Z() );
            result( 6, 2 ) =
                0.125 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() );
            result( 7, 0 ) =
                -0.125 * ( 1.0 + integration_points[pnt].Y() )
                * ( 1.0 + integration_points[pnt].Z() );
            result( 7, 1 ) =
                0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Z() );
            result( 7, 2 ) =
                0.125 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() );
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
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_5 )
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Hexahedra3D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 )
            }
        };
        return shape_functions_local_gradients;
    }

    ///@}
    ///@name Private Friends
    ///@{

    template<class TOtherPointType> friend class Hexahedra3D8;

    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}
}; // Class Hexahedra3D8

template<class TPointType> const
GeometryData Hexahedra3D8<TPointType>::msGeometryData(
    3, 3, 3, GeometryData::IntegrationMethod::GI_GAUSS_2,
    Hexahedra3D8<TPointType>::AllIntegrationPoints(),
    Hexahedra3D8<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

} // namespace Kratos.

#endif // KRATOS_HEXAHEDRA_3D_8_H_INCLUDED  defined
