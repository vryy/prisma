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
    /**
     * Type Definitions
     */
    /**
     * Base Type: Geometry
     */
    typedef Geometry<TPointType> BaseType;

    /**
     * Type of edge geometry
     */
    typedef Line2D3<TPointType> EdgeType;

    /**
     * Pointer definition of Quadrilateral2D8
     */
    KRATOS_CLASS_POINTER_DEFINITION( Quadrilateral2D8 );

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

    /**
     * Destructor. Does nothing!!!
     */
    ~Quadrilateral2D8() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Quadrilateral;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Quadrilateral2D8;
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

    /**
     * Operations
     */
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

    /**
     * :TODO: the lumpig factors need to be reviewed and
     * probably reimplemented
     * (comment by janosch)
     */
    //lumping factors for the calculation of the lumped mass matrix
    Vector& LumpingFactors( Vector& rResult ) const override
    {
	if(rResult.size() != 8)
           rResult.resize( 8, false );

        for ( int i = 0; i < 4; i++ ) rResult[i] = 1.00 / 36.00;

        for ( int i = 4; i < 8; i++ ) rResult[i] = 1.00 / 9.00;

        return rResult;
    }

    /**
     * Information
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
     * :TODO: the characteristic length is to be reviewed
     * (comment by janosch)
     */
    DataType Length() const override
    {
        DataType length = 0.000;
        length = std::sqrt( std::abs( Area() ) );
        return length;
    }

    /**
     * This method calculates and returns area or surface area of
     * this geometry depending to it's dimension. For one dimensional
     * geometry it returns zero, for two dimensional it gives area
     * and for three dimensional geometries it gives surface area.
     *
     * @return DataType value contains area or surface
     * area.
     * @see Length()
     * @see Volume()
     * @see DomainSize()
     */
    /**
     * :TODO: the characteristic area is to be reviewed
     * (comment by janosch)
     */
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


    /**
     * This method calculates and returns length, area or volume of
     * this geometry depending to it's dimension. For one dimensional
     * geometry it returns its length, for two dimensional it gives area
     * and for three dimensional geometries it gives its volume.
     * @return DataType value contains length, area or volume.
     * @see Length()
     * @see Area()
     * @see Volume()
     */
    /**
     * :TODO: the characteristic domain size is to be reviewed
     * (comment by janosch)
     */
    DataType DomainSize() const override
    {
        return Area();
    }

    /**
     * Returns whether given local point is inside the Geometry
     */
    bool IsInside( const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( std::abs( rPoint[0] ) < 1 + 1.0e-8 )
            if ( std::abs( rPoint[1] ) < 1 + 1.0e-8 )
                return true;

        return false;
    }

    /** This method gives you number of all edges of this
    geometry. This method will gives you number of all the edges
    with one dimension less than this geometry. for example a
    triangle would return three or a tetrahedral would return
    four but won't return nine related to its six edge lines.

    @return SizeType containes number of this geometry edges.
    @see Edges()
    @see Edge()
     */
    SizeType EdgesNumber() const override
    {
        return 4;
    }

    /** This method gives you all edges of this geometry. This
     * method will gives you all the edges with one dimension less
     * than this geometry. for example a triangle would return
     * three lines as its edges or a tetrahedral would return four
     * triangle as its edges but won't return its six edge
     * lines by this method.
     *
     * @return GeometriesArrayType containes this geometry edges.
     * @see EdgesNumber()
     * @see Edge()
     */
    GeometriesArrayType Edges( void ) const override
    {
        GeometriesArrayType edges = GeometriesArrayType();
        edges.push_back( EdgeType( this->pGetPoint( 0 ), this->pGetPoint( 4 ), this->pGetPoint( 1 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 1 ), this->pGetPoint( 5 ), this->pGetPoint( 2 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 2 ), this->pGetPoint( 6 ), this->pGetPoint( 3 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 3 ), this->pGetPoint( 7 ), this->pGetPoint( 0 ) ) );
        return edges;
    }

    /**
     * Shape Function
     */

    /**
     * :TODO: implemented but not yet tested
     */
    /**
     * Calculates the value of a given shape function at a given point.
     *
     * @param ShapeFunctionIndex The number of the desired shape function
     * @param rPoint the given point in local coordinates at which the
     * value of the shape function is calculated
     *
     * @return the value of the shape function at the given point
     */
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

    /**
     * :TODO: implemented but not yet tested
     */
    /**
     * Calculates the Gradients of the shape functions.
     * Calculates the gradients of the shape functions with regard to the global
     * coordinates in all
     * integration points (\f$ \frac{\partial N^i}{\partial X_j} \f$)
     *
     * @param rResult a container which takes the calculated gradients
     * @param ThisMethod the given IntegrationMethod
     *
     * @return the gradients of all shape functions with regard to the
     * global coordinates
     *
     * KLUDGE: method call only works with explicit JacobiansType
     * rather than creating JacobiansType within argument list
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

    /**
     * Input and Output
     */

    /**
     * Turn back information as a string.
     * @return String contains information about this geometry.
     * @see PrintData()
     * @see PrintInfo()
     */
    std::string Info() const override
    {
        return "2 dimensional quadrilateral with eight nodes in 2D space";
    }

    /**
     * Print information about this object.
     * @param rOStream Stream to print into it.
     * @see PrintData()
     * @see Info()
     */
    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "2 dimensional quadrilateral with eight nodes in 2D space";
    }

    /**
     * Print geometry's data into given stream.
     * Prints it's points by the order they stored in
     * the geometry and then center point of geometry.
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

//    /**
//     * Calculates the local gradients for all integration points for
//     * given integration method
//     */
//    virtual ShapeFunctionsGradientsType ShapeFunctionsLocalGradients(
//        IntegrationMethod ThisMethod )
//    {
//        ShapeFunctionsGradientsType localGradients
//        = CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );
//        const int integration_points_number
//        = msGeometryData.IntegrationPointsNumber( ThisMethod );
//        ShapeFunctionsGradientsType Result( integration_points_number );

//        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
//        {
//            Result[pnt] = localGradients[pnt];
//        }

//        return Result;
//    }

//    /**
//     * Calculates the local gradients for all integration points for the
//     * default integration method
//     */
//    virtual ShapeFunctionsGradientsType ShapeFunctionsLocalGradients()
//    {
//        IntegrationMethod ThisMethod = msGeometryData.DefaultIntegrationMethod();
//        ShapeFunctionsGradientsType localGradients
//        = CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );
//        const int integration_points_number
//        = msGeometryData.IntegrationPointsNumber( ThisMethod );
//        ShapeFunctionsGradientsType Result( integration_points_number );

//        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
//        {
//            Result[pnt] = localGradients[pnt];
//        }

//        return Result;
//    }

    /**
    * Calculates the gradients in terms of local coordinates
    * of all shape functions in a given point.
    *
    * @param rPoint the current point at which the gradients are calculated
    * @return the gradients of all shape functions
    * \f$ \frac{\partial N^i}{\partial \xi_j} \f$
     */
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

    /**
     * returns the local coordinates of all nodes of the current geometry
     * @param rResult a Matrix object that will be overwritten by the result
     * @return the local coordinates of all nodes
     */
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

    /**
     * returns the shape function gradients in an arbitrary point,
     * given in local coordinates
     * @param rResult the matrix of gradients, will be overwritten
     * with the gradients for all
     * shape functions in given point
     * @param rPoint the given point the gradients are calculated in
     */
    // Matrix& ShapeFunctionsGradients( Matrix& rResult, PointType& rPoint ) const override
    // {
    //     rResult.resize( 8, 2 );
    //     noalias( rResult ) = ZeroMatrix( 8, 2 );

    //     rResult( 0, 0 ) = (( -1.0 + rPoint.Y() ) * ( -2.0 ) * ( 1.0 + 2.0
    //                        * rPoint.X() + rPoint.Y() - 1.0 ) ) / 8.0;
    //     rResult( 0, 1 ) = (( -1.0 + rPoint.X() ) * ( -2.0 ) * ( 1.0 + rPoint.X() + 2.0
    //                        * rPoint.Y() - 1.0 ) ) / 8.0;

    //     rResult( 1, 0 ) = -(( -1.0 + rPoint.Y() ) * ( -2.0 ) * ( 1.0 - 2.0
    //                         * rPoint.X() + rPoint.Y() - 1.0 ) ) / 8.0;
    //     rResult( 1, 1 ) = (( 1.0 + rPoint.X() ) * ( -1.0 + rPoint.X() - 2.0
    //                        * rPoint.Y() + 1.0 ) * ( -2.0 ) ) / 8.0;

    //     rResult( 2, 0 ) = -(( 1.0 + rPoint.Y() ) * ( -1.0 + 2.0
    //                         * rPoint.X() + rPoint.Y() + 1.0 ) * ( -2.0 ) ) / 8.0;
    //     rResult( 2, 1 ) = -(( 1.0 + rPoint.X() ) * ( -1.0 + rPoint.X() + 2.0
    //                         * rPoint.Y() + 1.0 ) * ( -2.0 ) ) / 8.0;

    //     rResult( 3, 0 ) = (( 1.0 + rPoint.Y() ) * ( -1.0 - 2.0
    //                        * rPoint.X() + rPoint.Y() + 1.0 ) * ( -2.0 ) ) / 8.0;
    //     rResult( 3, 1 ) = -(( -1.0 + rPoint.X() ) * ( -2.0 ) * ( 1.0 + rPoint.X() - 2.0
    //                         * rPoint.Y() - 1.0 ) ) / 8.0;

    //     rResult( 4, 0 ) = -( rPoint.X() * ( -1.0 + rPoint.Y() ) * ( -2.0 ) ) / 2.0;
    //     rResult( 4, 1 ) = -(( -1.0 + rPoint.X() * rPoint.X() ) * ( -2.0 ) ) / 4.0;

    //     rResult( 5, 0 ) = (( -1.0 + rPoint.Y() * rPoint.Y() ) * ( -2.0 ) ) / 4.0;
    //     rResult( 5, 1 ) = (( 1.0 + rPoint.X() ) * rPoint.Y() * ( -2.0 ) ) / 2.0;

    //     rResult( 6, 0 ) = ( rPoint.X() * ( 1.0 + rPoint.Y() ) * ( -2.0 ) ) / 2.0;
    //     rResult( 6, 1 ) = (( -1.0 + rPoint.X() * rPoint.X() ) * ( -2.0 ) ) / 4.0;

    //     rResult( 7, 0 ) = -(( -1.0 + rPoint.Y() * rPoint.Y() ) * ( -2.0 ) ) / 4.0;
    //     rResult( 7, 1 ) = -(( -1.0 + rPoint.X() ) * rPoint.Y() * ( -2.0 ) ) / 2.0;

    //     return rResult;
    // }

    /**
     * returns the second order derivatives of all shape functions
     * in given arbitrary points
     *
     * @param rResult a third order tensor which contains the second derivatives
     * @param rPoint the given point the second order derivatives are calculated in
     */
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

    /**
    * returns the third order derivatives of all shape functions
    * in given arbitrary points
    *
    * @param rResult a fourth order tensor which contains the third derivatives
    * @param rPoint the given point the third order derivatives are calculated in
     */
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

    Quadrilateral2D8(): BaseType( PointsArrayType(), &msGeometryData ) {}

    /**
     * Private Operations
     */



    /**
     * :TODO: implemented but not yet tested
     */
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
     * :TODO: implemented but not yet tested
     */
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

    /**
     * Private Friends
     */

    template<class TOtherPointType> friend class Quadrilateral2D8;

    /**
     * Un accessible methods
     */
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
