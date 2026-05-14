//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.6 $
//
//

#if !defined(KRATOS_QUADRILATERAL_2D_8_H_INCLUDED )
#define  KRATOS_QUADRILATERAL_2D_8_H_INCLUDED


// System includes

// External includes

// Project includes
#include "geometries/line_2d_3.h"
#include "integration/quadrilateral_gauss_legendre_integration_points.h"


namespace Kratos
{

/**
 * A four node quadrilateral geometry. While the shape functions are only define in
 * 2D it is possible to define an arbitrary orientation in space. Thus it can be used for
 * defining surfaces on 3D elements.
 */
template<class TPointType> class Quadrilateral2D8 : public Geometry<TPointType>
{
public:
    ///@name Type Definitions
    ///@{

    /**
     * Base Type: Geometry
     */
    typedef Geometry<TPointType> BaseType;

    /**
     * Geometry as base class.
     */
    typedef Line2D3<TPointType> EdgeType;

    /**
     * Pointer definition of Quadrilateral2D8
     */
    KRATOS_CLASS_POINTER_DEFINITION( Quadrilateral2D8 );

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

    typedef typename BaseType::ShapeFunctionsIntegrationPointsGradientsType ShapeFunctionsIntegrationPointsGradientsType;

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

    Quadrilateral2D8( const PointType& Point1, const PointType& Point2,
                      const PointType& Point3, const PointType& Point4,
                      const PointType& Point5, const PointType& Point6,
                      const PointType& Point7, const PointType& Point8
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
    }

    Quadrilateral2D8( typename PointType::Pointer pPoint1, typename PointType::Pointer pPoint2,
                      typename PointType::Pointer pPoint3, typename PointType::Pointer pPoint4,
                      typename PointType::Pointer pPoint5, typename PointType::Pointer pPoint6,
                      typename PointType::Pointer pPoint7, typename PointType::Pointer pPoint8 )
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

    Quadrilateral2D8( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 8 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                          "Invalid points number. Expected 8, given " , this->PointsNumber() );
    }

    /**
     * Copy constructor.
     * Constructs this geometry as a copy of given geometry.
     *
     * @note This copy constructor don't copy the points and new
     * geometry shares points with given source geometry. It's
     * obvious that any change to this new geometry's point affect
     * source geometry's points too.
     */
    Quadrilateral2D8( Quadrilateral2D8 const& rOther )
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
    template<class TOtherPointType> Quadrilateral2D8( Quadrilateral2D8<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    ~Quadrilateral2D8() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Quadrilateral;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Quadrilateral2D8;
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
    Quadrilateral2D8& operator=( const Quadrilateral2D8& rOther )
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
    Quadrilateral2D8& operator=( Quadrilateral2D8<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Quadrilateral2D8( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Quadrilateral2D8< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    Vector& LumpingFactors( Vector& rResult ) const override
    {
	if(rResult.size() != 8)
           rResult.resize( 8, false );

        for ( int i = 0; i < 4; i++ ) rResult[i] = 1.00 / 36.00;

        for ( int i = 4; i < 8; i++ ) rResult[i] = 1.00 / 9.00;

        return rResult;
    }

    ///@}
    ///@name Information
    ///@{

    DataType Length() const override
    {
        DataType length = 0.000;
        length = std::sqrt( std::abs( Area() ) );
        return length;
    }

    DataType Area() const override
    {
        VectorType temp;
        this->DeterminantOfJacobian( temp, msGeometryData.DefaultIntegrationMethod() );
        const IntegrationPointsArrayType& integration_points = this->IntegrationPoints( msGeometryData.DefaultIntegrationMethod() );
        DataType Area = 0.00;

        for ( unsigned int i = 0; i < integration_points.size(); i++ )
        {
            Area += temp[i] * integration_points[i].Weight();
        }

        return Area;
    }

    DataType DomainSize() const override
    {
        return Area();
    }

    bool IsInside( const LocalCoordinatesArrayType& rPoint, const ValueType tol ) const override
    {
        if ( std::abs( rPoint[0] ) < 1 + tol )
            if ( std::abs( rPoint[1] ) < 1 + tol )
                return true;

        return false;
    }

    SizeType EdgesNumber() const override
    {
        return 4;
    }

    SizeType FacesNumber() const override
    {
        return 4;
    }

    GeometriesArrayType Edges() const override
    {
        GeometriesArrayType edges = GeometriesArrayType();
        edges.push_back( EdgeType( this->pGetPoint( 0 ), this->pGetPoint( 4 ), this->pGetPoint( 1 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 1 ), this->pGetPoint( 5 ), this->pGetPoint( 2 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 2 ), this->pGetPoint( 6 ), this->pGetPoint( 3 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 3 ), this->pGetPoint( 7 ), this->pGetPoint( 0 ) ) );
        return edges;
    }

    GeometriesArrayType Faces() const override
    {
        return Edges();
    }

    ///@}
    ///@name Shape Function
    ///@{

    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex, const LocalCoordinatesArrayType& rPoint ) const override
    {
        switch ( ShapeFunctionIndex )
        {
        case 0:
            return -(( 1.0 - rPoint[0] )*( 1.0 - rPoint[1] )
                     *( 1.0 + rPoint[0]
                        + rPoint[1] ) ) / 4.0;
        case 1:
            return -(( 1.0 + rPoint[0] )
                     *( 1.0 - rPoint[1] )*( 1.0
                                            - rPoint[0] + rPoint[1] ) ) / 4.0;
        case 2 :
            return -(( 1.0 + rPoint[0] )
                     *( 1.0 + rPoint[1] )*( 1.0
                                            - rPoint[0] - rPoint[1] ) ) / 4.0;
        case 3 :
            return -(( 1.0 - rPoint[0] )*( 1.0
                                           + rPoint[1] )*( 1.0 )*( 1.0
                                                   + rPoint[0] - rPoint[1] ) ) / 4.0;
        case 4 :
            return (( 1.0 -rPoint[0]*rPoint[0] )
                    *( 1.0 - rPoint[1] ) ) / 2.0;
        case 5 :
            return (( 1.0 + rPoint[0] )
                    *( 1.0 - rPoint[1]*rPoint[1] ) ) / 2.0 ;
        case 6 :
            return (( 1.0 -rPoint[0]
                      *rPoint[0] )*( 1.0 + rPoint[1] ) ) / 2.0 ;
        case 7 :
            return (( 1.0 -rPoint[0] )
                    *( 1.0 - rPoint[1]*rPoint[1] ) ) / 2.0 ;
        default:
            KRATOS_THROW_ERROR( std::logic_error,
                          "Wrong index of shape function!" , *this );
        }

        return 0;
    }

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
            rResult[pnt].resize( 4, 2 );

            for ( unsigned int i = 0; i < 4; i++ )
            {
                for ( unsigned int j = 0; j < 2; j++ )
                {
                    rResult[pnt]( i, j ) =
                        ( locG[pnt]( i, 0 ) * invJ[pnt]( j, 0 ) )
                        + ( locG[pnt]( i, 1 ) * invJ[pnt]( j, 1 ) );
                }
            }
        } //end of loop over integration points

        return rResult;
    }

    ///@}
    ///@name Input and output
    ///@{

    std::string Info() const override
    {
        return "2 dimensional quadrilateral with eight nodes in 2D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "2 dimensional quadrilateral with eight nodes in 2D space";
    }

    void PrintData( std::ostream& rOStream ) const override
    {
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian in the origin\t : " << jacobian;
    }

    Matrix& ShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        //setting up result matrix
        rResult.resize( 8, 2 );
        noalias( rResult ) = ZeroMatrix( 8, 2 );

        rResult( 0, 0 ) = (( -1.0 + rPoint[1] ) * ( -2.0 ) * ( 1.0 + 2.0
                           * rPoint[0] + rPoint[1] - 1.0 ) ) / 8.0;
        rResult( 0, 1 ) = (( -1.0 + rPoint[0] ) * ( -2.0 ) * ( 1.0 + rPoint[0] + 2.0
                           * rPoint[1] - 1.0 ) ) / 8.0;

        rResult( 1, 0 ) = -(( -1.0 + rPoint[1] ) * ( -2.0 ) * ( 1.0 - 2.0
                            * rPoint[0] + rPoint[1] - 1.0 ) ) / 8.0;
        rResult( 1, 1 ) = (( 1.0 + rPoint[0] ) * ( -1.0 + rPoint[0] - 2.0
                           * rPoint[1] + 1.0 ) * ( -2.0 ) ) / 8.0;

        rResult( 2, 0 ) = -(( 1.0 + rPoint[1] ) * ( -1.0 + 2.0
                            * rPoint[0] + rPoint[1] + 1.0 ) * ( -2.0 ) ) / 8.0;
        rResult( 2, 1 ) = -(( 1.0 + rPoint[0] ) * ( -1.0 + rPoint[0] + 2.0
                            * rPoint[1] + 1.0 ) * ( -2.0 ) ) / 8.0;

        rResult( 3, 0 ) = (( 1.0 + rPoint[1] ) * ( -1.0 - 2.0
                           * rPoint[0] + rPoint[1] + 1.0 ) * ( -2.0 ) ) / 8.0;
        rResult( 3, 1 ) = -(( -1.0 + rPoint[0] ) * ( -2.0 ) * ( 1.0 + rPoint[0] - 2.0
                            * rPoint[1] - 1.0 ) ) / 8.0;

        rResult( 4, 0 ) = -( rPoint[0] * ( -1.0 + rPoint[1] ) * ( -2.0 ) ) / 2.0;
        rResult( 4, 1 ) = -(( -1.0 + rPoint[0] * rPoint[0] ) * ( -2.0 ) ) / 4.0;

        rResult( 5, 0 ) = (( -1.0 + rPoint[1] * rPoint[1] ) * ( -2.0 ) ) / 4.0;
        rResult( 5, 1 ) = (( 1.0 + rPoint[0] ) * rPoint[1] * ( -2.0 ) ) / 2.0;

        rResult( 6, 0 ) = ( rPoint[0] * ( 1.0 + rPoint[1] ) * ( -2.0 ) ) / 2.0;
        rResult( 6, 1 ) = (( -1.0 + rPoint[0] * rPoint[0] ) * ( -2.0 ) ) / 4.0;

        rResult( 7, 0 ) = -(( -1.0 + rPoint[1] * rPoint[1] ) * ( -2.0 ) ) / 4.0;
        rResult( 7, 1 ) = -(( -1.0 + rPoint[0] ) * rPoint[1] * ( -2.0 ) ) / 2.0;

        return( rResult );
    }

    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if (rResult.size1() != 8 || rResult.size2() != 2)
            rResult.resize( 8, 2, false );
        rResult( 0, 0 ) = -1.0;
        rResult( 0, 1 ) = -1.0;
        rResult( 1, 0 ) =  1.0;
        rResult( 1, 1 ) = -1.0;
        rResult( 2, 0 ) =  1.0;
        rResult( 2, 1 ) =  1.0;
        rResult( 3, 0 ) = -1.0;
        rResult( 3, 1 ) =  1.0;
        rResult( 4, 0 ) =  0.0;
        rResult( 4, 1 ) = -1.0;
        rResult( 5, 0 ) =  1.0;
        rResult( 5, 1 ) =  0.0;
        rResult( 6, 0 ) =  0.0;
        rResult( 6, 1 ) =  1.0;
        rResult( 7, 0 ) = -1.0;
        rResult( 7, 1 ) =  0.0;
        return rResult;
    }

    ShapeFunctionsSecondDerivativesType& ShapeFunctionsSecondDerivatives( ShapeFunctionsSecondDerivativesType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( rResult.size() != this->PointsNumber() )
        {
            // KLUDGE: While there is a bug in ublas
            // vector resize, I have to put this beside resizing!!
            ShapeFunctionsGradientsType temp( this->PointsNumber() );
            rResult.swap( temp );
        }

        for ( unsigned  int i = 0; i < this->PointsNumber(); i++ )
        {
            rResult[i].resize( 2, 2 );
            noalias( rResult[i] ) = ZeroMatrix( 2, 2 );
        }

        rResult[0]( 0, 0 ) = ( 4.0 - 4 * rPoint[1] ) / 8.0;

        rResult[0]( 0, 1 ) = ( -2.0 ) * ( 1.0 + 2.0 * rPoint[0] + rPoint[1] - 1.0 ) / 8.0
                             + (( -1.0 + rPoint[1] ) * ( -2.0 ) ) / 8.0;
        rResult[0]( 1, 0 ) = ( -2.0 ) * ( 1.0 + rPoint[0] + 2.0 * rPoint[1] - 1.0 ) / 8.0
                             + (( -1.0 + rPoint[0] ) * ( -2.0 ) ) / 8.0;
        rResult[0]( 1, 1 ) = (( -1.0 + rPoint[0] ) * ( -2.0 ) * ( 2.0 ) ) / 8.0;

        rResult[1]( 0, 0 ) = -(( -1.0 + rPoint[1] ) * ( -2.0 ) * ( -2.0 ) ) / 8.0;
        rResult[1]( 0, 1 ) = ( 2.0 ) * ( 1.0 - 2.0 * rPoint[0] + rPoint[1] - 1.0 ) / 8.0
                             - (( -1.0 + rPoint[1] ) * ( -2.0 ) ) / 8.0;
        rResult[1]( 1, 0 ) = ( -1.0 + rPoint[0] - 2.0 * rPoint[1] + 1.0 ) * ( -2.0 ) / 8.0
                             + (( 1.0 + rPoint[0] ) * ( -2.0 ) ) / 8.0;
        rResult[1]( 1, 1 ) = (( 1.0 + rPoint[0] ) * ( -2.0 ) * ( -2.0 ) ) / 8.0;

        rResult[2]( 0, 0 ) = -(( 1.0 + rPoint[1] ) * ( 2.0 ) * ( -2.0 ) ) / 8.0;
        rResult[2]( 0, 1 ) = -(( 1.0 ) * ( -1.0 + 2.0 * rPoint[0] + rPoint[1] + 1.0 ) * ( -2.0 ) ) / 8.0
                             - (( 1.0 + rPoint[1] ) * ( -2.0 ) ) / 8.0;
        rResult[2]( 1, 0 ) = -(( 1.0 ) * ( -1.0 + rPoint[0] + 2.0 * rPoint[1] + 1.0 ) * ( -2.0 ) ) / 8.0
                             - (( 1.0 + rPoint[0] ) * ( -2.0 ) ) / 8.0;
        rResult[2]( 1, 1 ) = -(( 1.0 + rPoint[0] ) * ( 2.0 ) * ( -2.0 ) ) / 8.0;

        rResult[3]( 0, 0 ) = (( 1.0 + rPoint[1] ) * ( -2.0 ) * ( -2.0 ) ) / 8.0;
        rResult[3]( 0, 1 ) = (( 1.0 ) * ( -1.0 - 2.0 * rPoint[0] + rPoint[1] + 1.0 ) * ( -2.0 ) ) / 8.0
                             + (( 1.0 + rPoint[1] ) * ( -2.0 ) ) / 8.0;
        rResult[3]( 1, 0 ) = -(( -2.0 ) * ( 1.0 + rPoint[0] - 2.0 * rPoint[1] - 1.0 ) ) / 8.0
                             - (( -1.0 + rPoint[0] ) * ( -2.0 ) ) / 8.0;
        rResult[3]( 1, 1 ) = -(( -1.0 + rPoint[0] ) * ( -2.0 ) * ( -2.0 ) ) / 8.0;

        rResult[4]( 0, 0 ) = -(( -1.0 + rPoint[1] ) * ( -2.0 ) ) / 2.0;
        rResult[4]( 0, 1 ) = -( rPoint[0] * ( -2.0 ) ) / 2.0;
        rResult[4]( 1, 0 ) = -(( 2.0 * rPoint[0] ) * ( -2.0 ) ) / 4.0;
        rResult[4]( 1, 1 ) = 0.0;

        rResult[5]( 0, 0 ) = 0.0;
        rResult[5]( 0, 1 ) = (( 2.0 * rPoint[1] ) * ( -2.0 ) ) / 4.0;
        rResult[5]( 1, 0 ) = ( rPoint[1] * ( -2.0 ) ) / 2.0;
        rResult[5]( 1, 1 ) = (( 1.0 + rPoint[0] ) * ( -2.0 ) ) / 2.0;

        rResult[6]( 0, 0 ) = (( 1.0 + rPoint[1] ) * ( -2.0 ) ) / 2.0;
        rResult[6]( 0, 1 ) = ( rPoint[0] * ( -2.0 ) ) / 2.0;
        rResult[6]( 1, 0 ) = (( 2.0 * rPoint[0] ) * ( -2.0 ) ) / 4.0;
        rResult[6]( 1, 1 ) = 0.0;

        rResult[7]( 0, 0 ) = 0.0;
        rResult[7]( 0, 1 ) = -(( 2.0 * rPoint[1] ) * ( -2.0 ) ) / 4.0;
        rResult[7]( 1, 0 ) = -( rPoint[1] * ( -2.0 ) ) / 2.0;
        rResult[7]( 1, 1 ) = -(( -1.0 + rPoint[0] ) * ( -2.0 ) ) / 2.0;

        return rResult;
    }

    ShapeFunctionsThirdDerivativesType& ShapeFunctionsThirdDerivatives( ShapeFunctionsThirdDerivativesType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {

        if ( rResult.size() != this->PointsNumber() )
        {
            // KLUDGE: While there is a bug in
            // ublas vector resize, I have to put this beside resizing!!
//                 ShapeFunctionsGradientsType
            ShapeFunctionsThirdDerivativesType temp( this->PointsNumber() );
            rResult.swap( temp );
        }

        for ( IndexType i = 0; i < rResult.size(); i++ )
        {
            DenseVector<Matrix> temp( this->PointsNumber() );
            rResult[i].swap( temp );
        }

        for ( unsigned int i = 0; i < this->PointsNumber(); i++ )
        {
            for ( int j = 0; j < 2; j++ )
            {
                rResult[i][j].resize( 2, 2 );
                noalias( rResult[i][j] ) = ZeroMatrix( 2, 2 );
            }
        }

        rResult[0][0]( 0, 0 ) = 0.0;

        rResult[0][0]( 0, 1 ) = -0.5;
        rResult[0][0]( 1, 0 ) = -0.5;
        rResult[0][0]( 1, 1 ) = -0.5;
        rResult[0][1]( 0, 0 ) = -0.5;
        rResult[0][1]( 0, 1 ) = -0.5;
        rResult[0][1]( 1, 0 ) = -0.5;
        rResult[0][1]( 1, 1 ) = 0.0;
        rResult[1][0]( 0, 0 ) = 0.0;
        rResult[1][0]( 0, 1 ) = -0.5;
        rResult[1][0]( 1, 0 ) = -0.5;
        rResult[1][0]( 1, 1 ) = 0.5;
        rResult[1][1]( 0, 0 ) = -0.5;
        rResult[1][1]( 0, 1 ) = 0.5;
        rResult[1][1]( 1, 0 ) = 0.5;
        rResult[1][1]( 1, 1 ) = 0.0;
        rResult[2][0]( 0, 0 ) = 0.0;
        rResult[2][0]( 0, 1 ) = 0.5;
        rResult[2][0]( 1, 0 ) = 0.5;
        rResult[2][0]( 1, 1 ) = 0.5;
        rResult[2][1]( 0, 0 ) = 0.5;
        rResult[2][1]( 0, 1 ) = 0.5;
        rResult[2][1]( 1, 0 ) = 0.5;
        rResult[2][1]( 1, 1 ) = 0.0;
        rResult[3][0]( 0, 0 ) = 0.0;
        rResult[3][0]( 0, 1 ) = 0.5;
        rResult[3][0]( 1, 0 ) = 0.5;
        rResult[3][0]( 1, 1 ) = -0.5;
        rResult[3][1]( 0, 0 ) = 0.5;
        rResult[3][1]( 0, 1 ) = -0.5;
        rResult[3][1]( 1, 0 ) = -0.5;
        rResult[3][1]( 1, 1 ) = 0.0;
        rResult[4][0]( 0, 0 ) = 0.0;
        rResult[4][0]( 0, 1 ) = 1.0;
        rResult[4][0]( 1, 0 ) = 1.0;
        rResult[4][0]( 1, 1 ) = 0.0;
        rResult[4][1]( 0, 0 ) = 1.0;
        rResult[4][1]( 0, 1 ) = 0.0;
        rResult[4][1]( 1, 0 ) = 0.0;
        rResult[4][1]( 1, 1 ) = 0.0;
        rResult[5][0]( 0, 0 ) = 0.0;
        rResult[5][0]( 0, 1 ) = 0.0;
        rResult[5][0]( 1, 0 ) = 0.0;
        rResult[5][0]( 1, 1 ) = -1.0;
        rResult[5][1]( 0, 0 ) = 0.0;
        rResult[5][1]( 0, 1 ) = -1.0;
        rResult[5][1]( 1, 0 ) = 1.0;
        rResult[5][1]( 1, 1 ) = 0.0;
        rResult[6][0]( 0, 0 ) = 0.0;
        rResult[6][0]( 0, 1 ) = -1.0;
        rResult[6][0]( 1, 0 ) = -1.0;
        rResult[6][0]( 1, 1 ) = 0.0;
        rResult[6][1]( 0, 0 ) = -1.0;
        rResult[6][1]( 0, 1 ) = 0.0;
        rResult[6][1]( 1, 0 ) = 0.0;
        rResult[6][1]( 1, 1 ) = 0.0;
        rResult[7][0]( 0, 0 ) = 0.0;
        rResult[7][0]( 0, 1 ) = 0.0;
        rResult[7][0]( 1, 0 ) = 0.0;
        rResult[7][0]( 1, 1 ) = 1.0;
        rResult[7][1]( 0, 0 ) = 0.0;
        rResult[7][1]( 0, 1 ) = 1.0;
        rResult[7][1]( 1, 0 ) = -1.0;
        rResult[7][1]( 1, 0 ) = 0.0;

        return rResult;
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

    Quadrilateral2D8(): BaseType( PointsArrayType(), &msGeometryData ) {}

    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    /**
     * Calculates the values of all shape function in all integration points.
     * Integration points are expected to be given in local coordinates
     * @param ThisMethod the current integration method
     * @return the matrix of values of every shape function in each integration point
     *
     * :KLUDGE: the number of points is hard-coded -> be careful when copying!
     */
    static Matrix CalculateShapeFunctionsIntegrationPointsValues( typename BaseType::IntegrationMethod ThisMethod )
    {
        IntegrationPointsContainerType all_integration_points = AllIntegrationPoints();
        IntegrationPointsArrayType integration_points = all_integration_points[static_cast<int>(ThisMethod)];
        //number of integration points
        const int integration_points_number = integration_points.size();
        //number of nodes in current geometry
        const int points_number = 8;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            row( shape_function_values, pnt )( 0 ) =
                -(( 1.0 - integration_points[pnt].X() )
                  * ( 1.0 - integration_points[pnt].Y() )
                  * ( 1.0 + integration_points[pnt].X()
                      + integration_points[pnt].Y() ) ) / 4.0;
            row( shape_function_values, pnt )( 1 ) =
                -(( 1.0 + integration_points[pnt].X() )
                  * ( 1.0 - integration_points[pnt].Y() ) * ( 1.0
                          - integration_points[pnt].X()
                          + integration_points[pnt].Y() ) ) / 4.0;
            row( shape_function_values, pnt )( 2 ) =
                -(( 1.0 + integration_points[pnt].X() )
                  * ( 1.0 + integration_points[pnt].Y() ) * ( 1.0
                          - integration_points[pnt].X()
                          - integration_points[pnt].Y() ) ) / 4.0;
            row( shape_function_values, pnt )( 3 ) =
                -(( 1.0 - integration_points[pnt].X() ) * ( 1.0
                        + integration_points[pnt].Y() ) * ( 1.0 ) * ( 1.0
                                + integration_points[pnt].X()
                                - integration_points[pnt].Y() ) ) / 4.0;
            row( shape_function_values, pnt )( 4 ) =
                (( 1.0 - integration_points[pnt].X()
                   * integration_points[pnt].X() )
                 * ( 1.0 - integration_points[pnt].Y() ) ) / 2.0;
            row( shape_function_values, pnt )( 5 ) =
                (( 1.0 + integration_points[pnt].X() )
                 * ( 1.0 - integration_points[pnt].Y()
                     * integration_points[pnt].Y() ) ) / 2.0 ;
            row( shape_function_values, pnt )( 6 ) =
                (( 1.0 - integration_points[pnt].X()
                   * integration_points[pnt].X() )
                 * ( 1.0 + integration_points[pnt].Y() ) ) / 2.0 ;
            row( shape_function_values, pnt )( 7 ) =
                (( 1.0 - integration_points[pnt].X() )
                 * ( 1.0 - integration_points[pnt].Y()
                     * integration_points[pnt].Y() ) ) / 2.0 ;
        }

        return shape_function_values;
    }

    /**
     * Calculates the local gradients of all shape functions in all integration points.
     * Integration points are expected to be given in local coordinates
     *
     * @param ThisMethod the current integration method
     * @return the vector of the gradients of all shape functions in each integration
     * point
     */
    static ShapeFunctionsGradientsType CalculateShapeFunctionsIntegrationPointsLocalGradients(
        typename BaseType::IntegrationMethod ThisMethod )
    {
        IntegrationPointsContainerType all_integration_points = AllIntegrationPoints();
        IntegrationPointsArrayType integration_points = all_integration_points[static_cast<int>(ThisMethod)];
        //number of integration points
        const int integration_points_number = integration_points.size();
        ShapeFunctionsGradientsType d_shape_f_values( integration_points_number );
        //initialising container
        //std::fill(d_shape_f_values.begin(), d_shape_f_values.end(), Matrix(4,2));
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            Matrix result = ZeroMatrix( 8, 2 );

            result( 0, 0 ) = (( -1.0 + integration_points[pnt].Y() )
                              * ( -2.0 ) * ( 1.0 + 2.0
                                             * integration_points[pnt].X()
                                             + integration_points[pnt].Y() - 1.0 ) ) / 8.0;
            result( 0, 1 ) = (( -1.0 + integration_points[pnt].X() ) * ( -2.0 ) * ( 1.0
                              + integration_points[pnt].X() + 2.0
                              * integration_points[pnt].Y() - 1.0 ) ) / 8.0;

            result( 1, 0 ) = -(( -1.0 + integration_points[pnt].Y() )
                               * ( -2.0 ) * ( 1.0 - 2.0 * integration_points[pnt].X()
                                              + integration_points[pnt].Y() - 1.0 ) ) / 8.0;
            result( 1, 1 ) = (( 1.0 + integration_points[pnt].X() ) * ( -1.0
                              + integration_points[pnt].X() - 2.0
                              * integration_points[pnt].Y() + 1.0 ) * ( -2.0 ) ) / 8.0;

            result( 2, 0 ) = -(( 1.0 + integration_points[pnt].Y() )
                               * ( -1.0 + 2.0 * integration_points[pnt].X()
                                   + integration_points[pnt].Y() + 1.0 ) * ( -2.0 ) ) / 8.0;
            result( 2, 1 ) = -(( 1.0 + integration_points[pnt].X() ) * ( -1.0
                               + integration_points[pnt].X() + 2.0
                               * integration_points[pnt].Y() + 1.0 ) * ( -2.0 ) ) / 8.0;

            result( 3, 0 ) = (( 1.0 + integration_points[pnt].Y() ) * ( -1.0 - 2.0
                              * integration_points[pnt].X()
                              + integration_points[pnt].Y() + 1.0 ) * ( -2.0 ) ) / 8.0;
            result( 3, 1 ) = -(( -1.0 + integration_points[pnt].X() ) * ( -2.0 ) * ( 1.0
                               + integration_points[pnt].X() - 2.0
                               * integration_points[pnt].Y() - 1.0 ) ) / 8.0;

            result( 4, 0 ) = -( integration_points[pnt].X() * ( -1.0
                                + integration_points[pnt].Y() ) * ( -2.0 ) ) / 2.0;

            result( 4, 1 ) = -(( -1.0
                                 + integration_points[pnt].X()
                                 * integration_points[pnt].X() ) * ( -2.0 ) ) / 4.0;

            result( 5, 0 ) = (( -1.0
                                + integration_points[pnt].Y()
                                * integration_points[pnt].Y() ) * ( -2.0 ) ) / 4.0;

            result( 5, 1 ) = (( 1.0
                                + integration_points[pnt].X() )
                              * integration_points[pnt].Y() * ( -2.0 ) ) / 2.0;

            result( 6, 0 ) = ( integration_points[pnt].X() * ( 1.0
                               + integration_points[pnt].Y() ) * ( -2.0 ) ) / 2.0;
            result( 6, 1 ) = (( -1.0
                                + integration_points[pnt].X()
                                * integration_points[pnt].X() ) * ( -2.0 ) ) / 4.0;

            result( 7, 0 ) = -(( -1.0
                                 + integration_points[pnt].Y()
                                 * integration_points[pnt].Y() ) * ( -2.0 ) ) / 4.0;

            result( 7, 1 ) = -(( -1.0
                                 + integration_points[pnt].X() )
                               * integration_points[pnt].Y() * ( -2.0 ) ) / 2.0;

            d_shape_f_values[pnt] = result;
        }

        return d_shape_f_values;
    }

    static const IntegrationPointsContainerType AllIntegrationPoints()
    {
        IntegrationPointsContainerType integration_points =
        {
            {
                //Quadrature< QuadrilateralGaussLegendreIntegrationPointsNeu1,
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints1,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints2,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints3,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints4,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints5,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints()
            }
        };
        return integration_points;
    }

    static const ShapeFunctionsValuesContainerType AllShapeFunctionsValues()
    {
        ShapeFunctionsValuesContainerType shape_functions_values =
        {
            {
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_5 )
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Quadrilateral2D8<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_5 )
            }
        };
        return shape_functions_local_gradients;
    }

    ///@}
    ///@name Private Friends
    ///@{

    template<class TOtherPointType> friend class Quadrilateral2D8;

    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}
}; // Class Quadrilateral2D8

template<class TPointType> const GeometryData
Quadrilateral2D8<TPointType>::msGeometryData( 2, 2, 2,
        GeometryData::IntegrationMethod::GI_GAUSS_3,
        Quadrilateral2D8<TPointType>::AllIntegrationPoints(),
        Quadrilateral2D8<TPointType>::AllShapeFunctionsValues(),
        AllShapeFunctionsLocalGradients()
                                            );

}  // namespace Kratos.

#endif // KRATOS_QUADRILATERAL_2D_8_H_INCLUDED  defined
