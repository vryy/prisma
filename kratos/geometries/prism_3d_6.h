//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.6 $
//
//

#if !defined(KRATOS_PRISM_3D_6_H_INCLUDED )
#define  KRATOS_PRISM_3D_6_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/triangle_3d_3.h"
#include "geometries/quadrilateral_3d_4.h"
#include "integration/prism_gauss_legendre_integration_points.h"

namespace Kratos
{

/**
 * An eight node hexahedra geometry with linear shape functions
 */
template<class TPointType> class Prism3D6 : public Geometry<TPointType>
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
    typedef Line3D2<TPointType> EdgeType;
    typedef Triangle3D3<TPointType> FaceType1;
    typedef Quadrilateral3D4<TPointType> FaceType2;

    /**
     * Pointer definition of Prism3D6
     */
    KRATOS_CLASS_POINTER_DEFINITION( Prism3D6 );

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

    Prism3D6( const PointType& Point1, const PointType& Point2,
              const PointType& Point3, const PointType& Point4,
              const PointType& Point5, const PointType& Point6 )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().reserve( 6 );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point1 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point2 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point3 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point4 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point5 ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( Point6 ) ) );
    }

    Prism3D6( typename PointType::Pointer pPoint1,
              typename PointType::Pointer pPoint2,
              typename PointType::Pointer pPoint3,
              typename PointType::Pointer pPoint4,
              typename PointType::Pointer pPoint5,
              typename PointType::Pointer pPoint6 )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().reserve( 6 );
        this->Points().push_back( pPoint1 );
        this->Points().push_back( pPoint2 );
        this->Points().push_back( pPoint3 );
        this->Points().push_back( pPoint4 );
        this->Points().push_back( pPoint5 );
        this->Points().push_back( pPoint6 );
    }

    Prism3D6( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 6 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                          "Invalid points number. Expected 6, given " ,
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
    Prism3D6( Prism3D6 const& rOther )
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
    template<class TOtherPointType> Prism3D6( Prism3D6<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    /// Destructor. Does nothing!!!
    ~Prism3D6() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Prism;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Prism3D6;
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
    Prism3D6& operator=( const Prism3D6& rOther )
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
    Prism3D6& operator=( Prism3D6<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }

    /**
     * Operations
     */

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Prism3D6( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Prism3D6< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    //lumping factors for the calculation of the lumped mass matrix
    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 6)
           rResult.resize( 6, false );
        std::fill( rResult.begin(), rResult.end(), 1.00 / 6.00 );
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
        VectorType temp;
        this->DeterminantOfJacobian( temp, msGeometryData.DefaultIntegrationMethod() );
        const IntegrationPointsArrayType& integration_points = this->IntegrationPoints( msGeometryData.DefaultIntegrationMethod() );

        DataType Volume = 0.00;
        for ( unsigned int i = 0; i < integration_points.size(); i++ )
        {
            Volume += temp[i] * integration_points[i].Weight();
        }

        return std::pow(Volume, 1.0/3.0)/3.0;
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
        if ( rResult.size1() != 6 || rResult.size2() != 3 )
            rResult.resize( 6, 3 );

        rResult( 0, 0 ) = 0.0;
        rResult( 0, 1 ) = 0.0;
        rResult( 0, 2 ) = 0.0;

        rResult( 1, 0 ) = 1.0;
        rResult( 1, 1 ) = 0.0;
        rResult( 1, 2 ) = 0.0;

        rResult( 2, 0 ) = 0.0;
        rResult( 2, 1 ) = 1.0;
        rResult( 2, 2 ) = 0.0;

        rResult( 3, 0 ) = 0.0;
        rResult( 3, 1 ) = 0.0;
        rResult( 3, 2 ) = 1.0;

        rResult( 4, 0 ) = 1.0;
        rResult( 4, 1 ) = 0.0;
        rResult( 4, 2 ) = 1.0;

        rResult( 5, 0 ) = 0.0;
        rResult( 5, 1 ) = 1.0;
        rResult( 5, 2 ) = 1.0;

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
                if ( rResult[2] >= 0.0 - 1.0e-8 && rResult[2] <= 1.0 + 1.0e-8 )
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
                if ( rResult[2] >= 0.0 - 1.0e-8 && rResult[2] <= 1.0 + 1.0e-8 )
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
                                              this->pGetPoint( 1 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 2 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 0 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 4 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 5 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 3 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 3 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 4 ) ) ) );
        edges.push_back( EdgePointerType( new EdgeType(
                                              this->pGetPoint( 2 ),
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
                                              this->pGetPoint( 1 ) ) ) );
        faces.push_back( FacePointerType( new FaceType1(
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 5 ) ) ) );
        faces.push_back( FacePointerType( new FaceType2(
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 2 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 4 ) ) ) );
        faces.push_back( FacePointerType( new FaceType2(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 3 ),
                                              this->pGetPoint( 5 ),
                                              this->pGetPoint( 2 ) ) ) );
        faces.push_back( FacePointerType( new FaceType2(
                                              this->pGetPoint( 0 ),
                                              this->pGetPoint( 1 ),
                                              this->pGetPoint( 4 ),
                                              this->pGetPoint( 3 ) ) ) );
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
            return( 1.0 -( rPoint[0] + rPoint[1] + rPoint[2] - ( rPoint[0]*rPoint[2] ) - ( rPoint[1]*rPoint[2] ) ) );
        case 1:
            return( rPoint[0] - ( rPoint[0]*rPoint[2] ) );
        case 2:
            return( rPoint[1] - ( rPoint[1]*rPoint[2] ) );
        case 3:
            return( rPoint[2] - ( rPoint[0]*rPoint[2] ) - ( rPoint[1]*rPoint[2] ) );
        case 4:
            return( rPoint[0]*rPoint[2] );
        case 5:
            return( rPoint[1]*rPoint[2] );
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
        return "3 dimensional prism with six nodes in 3D space";
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
        rOStream << "3 dimensional prism with six nodes in 3D space";
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

    Prism3D6(): BaseType( PointsArrayType(), &msGeometryData ) {}

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
        rResult( 0, 0 ) = -1.0 + rPoint[2];
        rResult( 0, 1 ) = -1.0 + rPoint[2];
        rResult( 0, 2 ) = -1.0 + rPoint[0] + rPoint[1];
        rResult( 1, 0 ) =  1.0 - rPoint[2];
        rResult( 1, 1 ) =  0.0;
        rResult( 1, 2 ) = -rPoint[0];
        rResult( 2, 0 ) =  0.0;
        rResult( 2, 1 ) =  1.0 - rPoint[2];
        rResult( 2, 2 ) = -rPoint[1];
        rResult( 3, 0 ) = -rPoint[2];
        rResult( 3, 1 ) = -rPoint[2];
        rResult( 3, 2 ) =  1.0 - rPoint[0] - rPoint[1];
        rResult( 4, 0 ) =  rPoint[2];
        rResult( 4, 1 ) =  0.0;
        rResult( 4, 2 ) =  rPoint[0];
        rResult( 5, 0 ) =  0.0;
        rResult( 5, 1 ) =  rPoint[2];
        rResult( 5, 2 ) =  rPoint[1];
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
        const int points_number = 6;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            shape_function_values( pnt, 0 ) = ( 1.0
                                                - integration_points[pnt].X()
                                                - integration_points[pnt].Y()
                                                - integration_points[pnt].Z()
                                                + ( integration_points[pnt].X() * integration_points[pnt].Z() )
                                                + ( integration_points[pnt].Y() * integration_points[pnt].Z() ) );
            shape_function_values( pnt, 1 ) = integration_points[pnt].X()
                                              - ( integration_points[pnt].X() * integration_points[pnt].Z() );
            shape_function_values( pnt, 2 ) = integration_points[pnt].Y()
                                              - ( integration_points[pnt].Y() * integration_points[pnt].Z() );
            shape_function_values( pnt, 3 ) = integration_points[pnt].Z()
                                              - ( integration_points[pnt].X() * integration_points[pnt].Z() )
                                              - ( integration_points[pnt].Y() * integration_points[pnt].Z() );
            shape_function_values( pnt, 4 ) = ( integration_points[pnt].X() * integration_points[pnt].Z() );
            shape_function_values( pnt, 5 ) = ( integration_points[pnt].Y() * integration_points[pnt].Z() );
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
            Matrix result = ZeroMatrix( 6, 3 );
            result( 0, 0 ) = -1.0 + integration_points[pnt].Z();
            result( 0, 1 ) = -1.0 + integration_points[pnt].Z();
            result( 0, 2 ) = -1.0 + integration_points[pnt].X() + integration_points[pnt].Y();
            result( 1, 0 ) =  1.0 - integration_points[pnt].Z();
            result( 1, 1 ) =  0.0;
            result( 1, 2 ) =  -integration_points[pnt].X();
            result( 2, 0 ) =  0.0;
            result( 2, 1 ) =  1.0 - integration_points[pnt].Z();
            result( 2, 2 ) =  -integration_points[pnt].Y();
            result( 3, 0 ) =  -integration_points[pnt].Z();
            result( 3, 1 ) =  -integration_points[pnt].Z();
            result( 3, 2 ) =  1.0 - integration_points[pnt].X() - integration_points[pnt].Y();
            result( 4, 0 ) =  integration_points[pnt].Z();
            result( 4, 1 ) =  0.0;
            result( 4, 2 ) =  integration_points[pnt].X();
            result( 5, 0 ) =  0.0;
            result( 5, 1 ) =  integration_points[pnt].Z();
            result( 5, 2 ) =  integration_points[pnt].Y();
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
                3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < PrismGaussLegendreIntegrationPoints4,
                3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < PrismGaussLegendreIntegrationPoints5,
                3, IntegrationPoint<3> >::GenerateIntegrationPoints(),
            }
        };
        return integration_points;
    }

    static const ShapeFunctionsValuesContainerType AllShapeFunctionsValues()
    {
        ShapeFunctionsValuesContainerType shape_functions_values =
        {
            {
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
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
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Prism3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(
                    GeometryData::IntegrationMethod::GI_GAUSS_5 )
            }
        };
        return shape_functions_local_gradients;
    }

    /**
     * Private Friends
     */

    template<class TOtherPointType> friend class Prism3D6;


    /**
     * Un accessible methods
     */

}; // Class Prism3D6

template<class TPointType> const
GeometryData Prism3D6<TPointType>::msGeometryData(
    3, 3, 3, GeometryData::IntegrationMethod::GI_GAUSS_2,
    Prism3D6<TPointType>::AllIntegrationPoints(),
    Prism3D6<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

}// namespace Kratos.

#endif // KRATOS_PRISM_3D_6_H_INCLUDED  defined
