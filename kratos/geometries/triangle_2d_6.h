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


#if !defined(KRATOS_TRIANGLE_2D_6_H_INCLUDED )
#define  KRATOS_TRIANGLE_2D_6_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/line_2d_3.h"
#include "integration/triangle_gauss_legendre_integration_points.h"

namespace Kratos
{
///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}
///@name Kratos Classes
///@{

/**
 * A six node triangular geometry. While the shape functions are only defined in
 * 2D it is possible to define an arbitrary orientation in space. Thus it can be used for
 * defining surfaces on 3D elements.
 */
template<class TPointType> class Triangle2D6 : public Geometry<TPointType>
{
public:
    ///@}
    ///@name Type Definitions
    ///@{

    /**
     * Geometry as base class.
     */
    typedef Geometry<TPointType> BaseType;

    /**
     * Type of edge geometry
     */
    typedef Line2D3<TPointType> EdgeType;

    /**
     * Pointer definition of Triangle2D6
     */
    KRATOS_CLASS_POINTER_DEFINITION( Triangle2D6 );

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

    ///@}
    ///@name Life Cycle
    ///@{

    Triangle2D6( const PointType& FirstPoint,
                 const PointType& SecondPoint,
                 const PointType& ThirdPoint,
                 const PointType& FourthPoint,
                 const PointType& FifthPoint,
                 const PointType& SixthPoint
               )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().push_back( typename PointType::Pointer( new PointType( FirstPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( SecondPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( ThirdPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( FourthPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( FifthPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( SixthPoint ) ) );
    }

    Triangle2D6( typename PointType::Pointer pFirstPoint,
                 typename PointType::Pointer pSecondPoint,
                 typename PointType::Pointer pThirdPoint,
                 typename PointType::Pointer pFourthPoint,
                 typename PointType::Pointer pFifthPoint,
                 typename PointType::Pointer pSixthPoint
               )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().push_back( pFirstPoint );
        this->Points().push_back( pSecondPoint );
        this->Points().push_back( pThirdPoint );
        this->Points().push_back( pFourthPoint );
        this->Points().push_back( pFifthPoint );
        this->Points().push_back( pSixthPoint );
    }

    Triangle2D6( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 6 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                                "Invalid points number. Expected 6, given " , this->PointsNumber() );
    }

    /**
     * Copy constructor.
     * Construct this geometry as a copy of given geometry.
     *
     * @note This copy constructor does not copy the points and new
     * geometry shares points with given source geometry. It is
     * obvious that any change to this new geometry's point affect
     * source geometry's points too.
     */
    Triangle2D6( Triangle2D6 const& rOther )
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
     * @note This copy constructor does not copy the points and new
     * geometry shares points with given source geometry. It is
     * obvious that any change to this new geometry's point affect
     * source geometry's points too.
     */
    template<class TOtherPointType> Triangle2D6( Triangle2D6<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    /**
     * Destructor. Does nothing!!!
     */
    ~Triangle2D6() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Triangle;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Triangle2D6;
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
    Triangle2D6& operator=( const Triangle2D6& rOther )
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
    Triangle2D6& operator=( Triangle2D6<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );
        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Triangle2D6( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Triangle2D6< Point<3, DataType> >( NewPoints ) );
        p_clone->ClonePoints();

        return p_clone;
    }

    /**
     * returns the local coordinates of all nodes of the current geometry
     * @param rResult a Matrix object that will be overwritten by the result
     * @return the local coordinates of all nodes
     */
    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if (rResult.size1() != 6 || rResult.size2() != 2)
            rResult.resize( 6, 2, false );
        rResult( 0, 0 ) =  0.0;
        rResult( 0, 1 ) =  0.0;
        rResult( 1, 0 ) =  1.0;
        rResult( 1, 1 ) =  0.0;
        rResult( 2, 0 ) =  0.0;
        rResult( 2, 1 ) =  1.0;
        rResult( 3, 0 ) =  0.5;
        rResult( 3, 1 ) =  0.0;
        rResult( 4, 0 ) =  0.5;
        rResult( 4, 1 ) =  0.5;
        rResult( 5, 0 ) =  0.0;
        rResult( 5, 1 ) =  0.5;
        return rResult;
    }

    //lumping factors for the calculation of the lumped mass matrix
    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 6)
            rResult.resize( 6, false );
        std::fill( rResult.begin(), rResult.end(), 1.00 / 6.00 );
        return rResult;
    }

    ///@}
    ///@name Information
    ///@{

    /**
     * This method calculates and returns Length or charactereistic
     * length of this geometry depending on it's dimension.
     * For one dimensional geometry for example Line it returns
     * length of it and for the other geometries it gives Characteristic
     * length otherwise.
     * In the current geometry this function returns the determinant of
     * jacobian
     *
     * @return DataType value contains length or Characteristic
     * length
     * @see Area()
     * @see Volume()
     * @see DomainSize()
     */
    /**
     * :TODO: could be replaced by something more suitable
     * (comment by janosch)
     */
    DataType Length() const override
    {
        return std::sqrt( std::abs( Area() ) );
    }

    /** This method calculates and returns area or surface area of
     * this geometry depending to it's dimension. For one dimensional
     * geometry it returns zero, for two dimensional it gives area
     * and for three dimensional geometries it gives surface area.
     *
     * @return DataType value contains area or surfacede
     * area.
     * @see Length()
     * @see Volume()
     * @see DomainSize()
     */
    /**
     * :TODO: could be replaced by something more suitable
     * (comment by janosch)
     */
    DataType Area() const override
    {
        VectorType temp;
        this->DeterminantOfJacobian( temp, msGeometryData.DefaultIntegrationMethod() );

        const IntegrationPointsArrayType& integration_points = this->IntegrationPoints( msGeometryData.DefaultIntegrationMethod() );
        DataType area = 0.00;

        for ( unsigned int i = 0; i < integration_points.size(); i++ )
        {
            area += temp[i] * integration_points[i].Weight();
        }

        return area;
    }

    /** This method calculates and returns length, area or volume of
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
     * :TODO: could be replaced by something more suitable
     * (comment by janosch)
     */
    DataType DomainSize() const override
    {
        return std::abs( this->DeterminantOfJacobian( LocalCoordinatesArrayType() ) ) * 0.5;
    }

    /**
     * Returns whether given local point is inside the Geometry
     */
    bool IsInside( const LocalCoordinatesArrayType& rPoint ) const override
    {
        const ValueType zero = 1E-8;
        if( ( rPoint[0] >= (0.0-zero) ) && ( rPoint[0] <= 1.0 + zero ) )
            if( ( rPoint[1] >= 0.0-zero ) && (rPoint[1] <= 1.0 + zero ) )
                if(((1.0-(rPoint[0] + rPoint[1])) >= 0.0-zero) &&  ((1.0-(rPoint[0] + rPoint[1])) <= 1.0 + zero))
                    return true;

        return false;
    }

    ///@}
    ///@name Shape Function
    ///@{

    /**
     * TODO: implemented but not yet tested
     */
    /**
     * Calculates the value of a given shape function at a given point.
     *
     * @param ShapeFunctionIndex The number of the desired shape function
     * @param rPoint the given point in local coordinates at which the value of the shape
     * function is calculated
     *
     * @return the value of the shape function at the given point
     */
    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex, const LocalCoordinatesArrayType& rPoint ) const override
    {
        ValueType thirdCoord = 1 - rPoint[0] - rPoint[1];

        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( thirdCoord*( 2*thirdCoord - 1 ) );
        case 1:
            return( rPoint[0]*( 2*rPoint[0] - 1 ) );
        case 2:
            return( rPoint[1]*( 2*rPoint[1] - 1 ) );
        case 3:
            return( 4*thirdCoord*rPoint[0] );
        case 4:
            return( 4*rPoint[0]*rPoint[1] );
        case 5:
            return( 4*rPoint[1]*thirdCoord );

        default:
            KRATOS_THROW_ERROR( std::logic_error,
                                "Wrong index of shape function!" ,
                                *this );
        }

        return 0;
    }

    ///@}
    ///@name Input and output
    ///@{

    /**
     * Turn back information as a string.
     *
     * @return String contains information about this geometry.
     * @see PrintData()
     * @see PrintInfo()
     */
    std::string Info() const override
    {
        return "2 dimensional triangle with six nodes in 2D space";
    }

    /**
     * Print information about this object.
     * @param rOStream Stream to print into it.
     * @see PrintData()
     * @see Info()
     */
    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "2 dimensional triangle with six nodes in 2D space";
    }

    /**
     * Print geometry's data into given stream.
     * Prints it's points
     * by the order they stored in the geometry and then center
     * point of geometry.
     *
     * @param rOStream Stream to print into it.
     * @see PrintInfo()
     * @see Info()
     */
    /**
     * :TODO: needs to be reviewed because it is not properly implemented yet
     * (comment by janosch)
     */
    void PrintData( std::ostream& rOStream ) const override
    {
        PrintInfo( rOStream );
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian in the origin\t : " << jacobian;
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
        return 3;
    }

    /** This method gives you all edges of this geometry. This
    method will gives you all the edges with one dimension less
    than this geometry. for example a triangle would return
    three lines as its edges or a tetrahedral would return four
    triangle as its edges but won't return its six edge
    lines by this method.

    @return GeometriesArrayType containes this geometry edges.
    @see EdgesNumber()
    @see Edge()
     */
    GeometriesArrayType Edges( void ) const override
    {
        GeometriesArrayType edges = GeometriesArrayType();

        edges.push_back( EdgeType( this->pGetPoint( 0 ), this->pGetPoint( 3 ), this->pGetPoint( 1 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 1 ), this->pGetPoint( 4 ), this->pGetPoint( 2 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 2 ), this->pGetPoint( 5 ), this->pGetPoint( 0 ) ) );
        return edges;
    }

//    /**
//     * Calculates the local gradients for all integration points for
//     * given integration method
//     */
//    virtual ShapeFunctionsGradientsType ShapeFunctionsLocalGradients(
//        IntegrationMethod ThisMethod )
//    {
//        ShapeFunctionsGradientsType localGradients
//            = CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );
//        const int integration_points_number
//            = msGeometryData.IntegrationPointsNumber( ThisMethod );
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
//            = CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );
//        const int integration_points_number
//            = msGeometryData.IntegrationPointsNumber( ThisMethod );
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
     * @param rPoint the current point at which the gradients are calculated in local
     * coordinates
     * @return the gradients of all shape functions
     * \f$ \frac{\partial N^i}{\partial \xi_j} \f$
     */
    Matrix& ShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        rResult.resize( 6, 2 ,false);
        ValueType thirdCoord = 1 - rPoint[0] - rPoint[1];
        ValueType thirdCoord_DX = -1;
        ValueType thirdCoord_DY = -1;

        noalias( rResult ) = ZeroMatrix( 6, 2 );
        rResult( 0, 0 ) = ( 4 * thirdCoord - 1 ) * thirdCoord_DX;
        rResult( 0, 1 ) = ( 4 * thirdCoord - 1 ) * thirdCoord_DY;
        rResult( 1, 0 ) =  4 * rPoint[0] - 1;
        rResult( 1, 1 ) =  0;
        rResult( 2, 0 ) =  0;
        rResult( 2, 1 ) =  4 * rPoint[1] - 1;
        rResult( 3, 0 ) =  4 * thirdCoord_DX * rPoint[0] + 4 * thirdCoord;
        rResult( 3, 1 ) =  4 * thirdCoord_DY * rPoint[0];
        rResult( 4, 0 ) =  4 * rPoint[1];
        rResult( 4, 1 ) =  4 * rPoint[0];
        rResult( 5, 0 ) =  4 * rPoint[1] * thirdCoord_DX;
        rResult( 5, 1 ) =  4 * rPoint[1] * thirdCoord_DY + 4 * thirdCoord;
        return rResult;
    }



    /**
     * returns the shape function gradients in an arbitrary point,
     * given in local coordinates
     *
     * @param rResult the matrix of gradients,
     * will be overwritten with the gradients for all
     * shape functions in given point
     * @param rPoint the given point the gradients are calculated in
     */
    // Matrix& ShapeFunctionsGradients( Matrix& rResult, CoordinatesArrayType& rPoint ) const override
    // {
    //     rResult.resize( 6, 2 ,false);
    //     DataType thirdCoord = 1 - rPoint[0] - rPoint[1];
    //     DataType thirdCoord_DX = -1;
    //     DataType thirdCoord_DY = -1;

    //     noalias( rResult ) = ZeroMatrix( 6, 2 );
    //     rResult( 0, 0 ) = ( 4 * thirdCoord - 1 ) * thirdCoord_DX;
    //     rResult( 0, 1 ) = ( 4 * thirdCoord - 1 ) * thirdCoord_DY;
    //     rResult( 1, 0 ) =  4 * rPoint[0] - 1;
    //     rResult( 1, 1 ) =  0;
    //     rResult( 2, 0 ) =  0;
    //     rResult( 2, 1 ) =  4 * rPoint[1] - 1;
    //     rResult( 3, 0 ) =  4 * thirdCoord_DX * rPoint[0] + 4 * thirdCoord;
    //     rResult( 3, 1 ) =  4 * thirdCoord_DY * rPoint[0];
    //     rResult( 4, 0 ) =  4 * rPoint[1];
    //     rResult( 4, 1 ) =  4 * rPoint[0];
    //     rResult( 5, 0 ) =  4 * rPoint[1] * thirdCoord_DX;
    //     rResult( 5, 1 ) =  4 * rPoint[1] * thirdCoord_DY + 4 * thirdCoord;
    //     return rResult;
    // }

    /**
     * returns the second order derivatives of all shape functions
     * in given arbitrary pointers
     * @param rResult a third order tensor which contains the second derivatives
     * @param rPoint the given point the second order derivatives are calculated in
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

        rResult[0].resize( 2, 2 ,false);
        rResult[1].resize( 2, 2 ,false);
        rResult[2].resize( 2, 2 ,false);
        rResult[3].resize( 2, 2 ,false);
        rResult[4].resize( 2, 2 ,false);
        rResult[5].resize( 2, 2 ,false);

        rResult[0]( 0, 0 ) = 4.0;
        rResult[0]( 0, 1 ) = 4.0;
        rResult[0]( 1, 0 ) = 4.0;
        rResult[0]( 1, 1 ) = 4.0;
        rResult[1]( 0, 0 ) = 4.0;
        rResult[1]( 0, 1 ) = 0.0;
        rResult[1]( 1, 0 ) = 0.0;
        rResult[1]( 1, 1 ) = 0.0;
        rResult[2]( 0, 0 ) = 0.0;
        rResult[2]( 0, 1 ) = 0.0;
        rResult[2]( 1, 0 ) = 0.0;
        rResult[2]( 1, 1 ) = 4.0;
        rResult[3]( 0, 0 ) = -8.0;
        rResult[3]( 0, 1 ) = -4.0;
        rResult[3]( 1, 0 ) = -4.0;
        rResult[3]( 1, 1 ) = 0.0;
        rResult[4]( 0, 0 ) = 0.0;
        rResult[4]( 0, 1 ) = 4.0;
        rResult[4]( 1, 0 ) = 4.0;
        rResult[4]( 1, 1 ) = 0.0;
        rResult[5]( 0, 0 ) = 0.0;
        rResult[5]( 0, 1 ) = -4.0;
        rResult[5]( 1, 0 ) = -4.0;
        rResult[5]( 1, 1 ) = -8.0;

        return rResult;
    }

    /**
     * returns the third order derivatives of all shape functions
     * in given arbitrary pointers
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
            boost::numeric::ublas::vector<Matrix> temp( this->PointsNumber() );
            rResult[i].swap( temp );
        }

        rResult[0][0].resize( 2, 2 ,false);

        rResult[0][1].resize( 2, 2 ,false);
        rResult[1][0].resize( 2, 2 ,false);
        rResult[1][1].resize( 2, 2 ,false);
        rResult[2][0].resize( 2, 2 ,false);
        rResult[2][1].resize( 2, 2 ,false);
        rResult[3][0].resize( 2, 2 ,false);
        rResult[3][1].resize( 2, 2 ,false);
        rResult[4][0].resize( 2, 2 ,false);
        rResult[4][1].resize( 2, 2 ,false);
        rResult[5][0].resize( 2, 2 ,false);
        rResult[5][1].resize( 2, 2 ,false);


        for ( int i = 0; i < 6; i++ )
        {
            rResult[i][0]( 0, 0 ) = 0.0;
            rResult[i][0]( 0, 1 ) = 0.0;
            rResult[i][0]( 1, 0 ) = 0.0;
            rResult[i][0]( 1, 1 ) = 0.0;
            rResult[i][1]( 0, 0 ) = 0.0;
            rResult[i][1]( 0, 1 ) = 0.0;
            rResult[i][1]( 1, 0 ) = 0.0;
            rResult[i][1]( 1, 1 ) = 0.0;
        }

        return rResult;
    }

    ///@}
    ///@name Friends
    ///@{

    ///@}

protected:
    /**
     * There are no protected members in class Triangle2D6
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

    Triangle2D6(): BaseType( PointsArrayType(), &msGeometryData ) {}

    ///@}
    ///@name Member Variables
    ///@{


    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    /**
     * TODO: implemented but not yet tested
     */
    /**
     * Calculates the values of all shape function in all integration points.
     * Integration points are expected to be given in local coordinates
     * @param ThisMethod the current integration method
     * @return the matrix of values of every shape function in each integration point
     * :KLUDGE: number of points is hard-coded -> be careful if you want to copy and paste!
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
        const int points_number = 6;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            ValueType thirdCoord = 1 - integration_points[pnt].X() - integration_points[pnt].Y();

            shape_function_values( pnt, 0 ) = thirdCoord * ( 2 * thirdCoord - 1 ) ;
            shape_function_values( pnt, 1 ) = integration_points[pnt].X() * ( 2 * integration_points[pnt].X() - 1 ) ;
            shape_function_values( pnt, 2 ) =  integration_points[pnt].Y() * ( 2 * integration_points[pnt].Y() - 1 ) ;
            shape_function_values( pnt, 3 ) =  4 * thirdCoord * integration_points[pnt].X();
            shape_function_values( pnt, 4 ) =  4 * integration_points[pnt].X() * integration_points[pnt].Y();
            shape_function_values( pnt, 5 ) =  4 * integration_points[pnt].Y() * thirdCoord;
        }

        return shape_function_values;
    }

    /**
     * TODO: implemented but not yet tested
     */
    /**
     * Calculates the local gradients of all shape functions
     * in all integration points.
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
        //initialising container
        //std::fill(d_shape_f_values.begin(), d_shape_f_values.end(), Matrix(4,2));
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            Matrix result( 6, 2 );
            ValueType thirdCoord = 1 - integration_points[pnt].X() - integration_points[pnt].Y();
            ValueType thirdCoord_DX = -1;
            ValueType thirdCoord_DY = -1;

            noalias( result ) = ZeroMatrix( 6, 2 );
            result( 0, 0 ) = ( 4 * thirdCoord - 1 ) * thirdCoord_DX;
            result( 0, 1 ) = ( 4 * thirdCoord - 1 ) * thirdCoord_DY;
            result( 1, 0 ) =  4 * integration_points[pnt].X() - 1;
            result( 1, 1 ) =  0;
            result( 2, 0 ) =  0;
            result( 2, 1 ) =  4 * integration_points[pnt].Y() - 1;
            result( 3, 0 ) =  4 * thirdCoord_DX * integration_points[pnt].X() + 4 * thirdCoord;
            result( 3, 1 ) =  4 * thirdCoord_DY * integration_points[pnt].X();
            result( 4, 0 ) =  4 * integration_points[pnt].Y();
            result( 4, 1 ) =  4 * integration_points[pnt].X();
            result( 5, 0 ) =  4 * integration_points[pnt].Y() * thirdCoord_DX;
            result( 5, 1 ) =  4 * integration_points[pnt].Y() * thirdCoord_DY + 4 * thirdCoord;

            d_shape_f_values[pnt] = result;
        }

        return d_shape_f_values;
    }

    static const IntegrationPointsContainerType AllIntegrationPoints()
    {
        IntegrationPointsContainerType integration_points =
        {
            {
                Quadrature<TriangleGaussLegendreIntegrationPoints1, 2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<TriangleGaussLegendreIntegrationPoints2, 2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<TriangleGaussLegendreIntegrationPoints3, 2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<TriangleGaussLegendreIntegrationPoints4, 2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<TriangleGaussLegendreIntegrationPoints5, 2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
            }
        };
        return integration_points;
    }

    static const ShapeFunctionsValuesContainerType AllShapeFunctionsValues()
    {
        ShapeFunctionsValuesContainerType shape_functions_values =
        {
            {
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Triangle2D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
            }
        };
        return shape_functions_local_gradients;
    }

    ///@}
    ///@name Private  Access
    ///@{


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Private Friends
    ///@{

    template<class TOtherPointType> friend class Triangle2D6;

    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}
}; // Class Triangle2D6

///@}
///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

template<class TPointType> const
GeometryData Triangle2D6<TPointType>::msGeometryData(
    2, 2, 2,
    GeometryData::IntegrationMethod::GI_GAUSS_2,
    Triangle2D6<TPointType>::AllIntegrationPoints(),
    Triangle2D6<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

} // namespace Kratos.

#endif // KRATOS_TRIANGLE_2D_6_H_INCLUDED  defined
