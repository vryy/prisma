//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.7 $
//
//

#if !defined(KRATOS_LINE_2D_2_H_INCLUDED )
#define  KRATOS_LINE_2D_2_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/geometry.h"
#include "integration/line_gauss_legendre_integration_points.h"
#include "integration/line_gauss_lobatto_integration_points.h"


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
*/
template<class TPointType>
class Line2D2 : public Geometry<TPointType>
{
public:
    ///@}
    ///@name Type Definitions
    ///@{

    /// Geometry as base class.
    typedef Geometry<TPointType> BaseType;

    /// Pointer definition of Line2D2
    KRATOS_CLASS_POINTER_DEFINITION( Line2D2 );

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

    ///@}
    ///@name Life Cycle
    ///@{

    Line2D2( const PointType& FirstPoint, const PointType& SecondPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        BaseType::Points().push_back( typename PointType::Pointer( new PointType( FirstPoint ) ) );
        BaseType::Points().push_back( typename PointType::Pointer( new PointType( SecondPoint ) ) );
    }

    Line2D2( typename PointType::Pointer pFirstPoint, typename PointType::Pointer pSecondPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        BaseType::Points().push_back( pFirstPoint );
        BaseType::Points().push_back( pSecondPoint );
    }

    Line2D2( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( BaseType::PointsNumber() != 2 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                          "Invalid points number. Expected 2, given " , BaseType::PointsNumber() );
    }

    /** Copy constructor.
    Construct this geometry as a copy of given geometry.

    @note This copy constructor don't copy the points and new
    geometry shares points with given source geometry. It's
    obvious that any change to this new geometry's point affect
    source geometry's points too.
    */
    Line2D2( Line2D2 const& rOther )
        : BaseType( rOther )
    {
    }


    /** Copy constructor from a geometry with other point type.
    Construct this geometry as a copy of given geometry which
    has different type of points. The given goemetry's
    TOtherPointType* must be implicity convertible to this
    geometry PointType.

    @note This copy constructor don't copy the points and new
    geometry shares points with given source geometry. It's
    obvious that any change to this new geometry's point affect
    source geometry's points too.
    */
    template<class TOtherPointType> Line2D2( Line2D2<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    /// Destructor. Do nothing!!!
    ~Line2D2() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Linear;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Line2D2;
    }

    ///@}
    ///@name Operators
    ///@{

    /** Assignment operator.

    @note This operator don't copy the points and this
    geometry shares points with given source geometry. It's
    obvious that any change to this geometry's point affect
    source geometry's points too.

    @see Clone
    @see ClonePoints
    */
    Line2D2& operator=( const Line2D2& rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }

    /** Assignment operator for geometries with different point type.

    @note This operator don't copy the points and this
    geometry shares points with given source geometry. It's
    obvious that any change to this geometry's point affect
    source geometry's points too.

    @see Clone
    @see ClonePoints
    */
    template<class TOtherPointType>
    Line2D2& operator=( Line2D2<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Line2D2( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < BaseType::Points().size() ; i++ )
            NewPoints.push_back( BaseType::Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Line2D2< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    //lumping factors for the calculation of the lumped mass matrix
    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 2)
           rResult.resize( 2, false );

        rResult[0] = 0.5;
        rResult[1] = 0.5;
        return rResult;
    }

    ///@}
    ///@name Informations
    ///@{

    /** This method calculate and return Length or charactereistic
    length of this geometry depending to it's dimension. For one
    dimensional geometry for example Line it returns length of it
    and for the other geometries it gives Characteristic length
    otherwise.

    @return double value contains length or Characteristic
    length
    @see Area()
    @see Volume()
    @see DomainSize()
    */
    DataType Length() const override
    {
        const TPointType& point0 = BaseType::GetPoint(0);
        const TPointType& point1 = BaseType::GetPoint(1);
        const DataType lx = point0.X() - point1.X();
        const DataType ly = point0.Y() - point1.Y();

        const DataType length = lx * lx + ly * ly;

        return sqrt( length );
    }

    /** This method calculate and return area or surface area of
    this geometry depending to it's dimension. For one dimensional
    geometry it returns zero, for two dimensional it gives area
    and for three dimensional geometries it gives surface area.

    @return double value contains area or surface
    area.
    @see Length()
    @see Volume()
    @see DomainSize()
    */
    DataType Area() const override
    {
        return 0.00;
    }


    /** This method calculate and return length, area or volume of
    this geometry depending to it's dimension. For one dimensional
    geometry it returns its length, for two dimensional it gives area
    and for three dimensional geometries it gives its volume.

    @return double value contains length, area or volume.
    @see Length()
    @see Area()
    @see Volume()
    */
    DataType DomainSize() const override
    {
        const TPointType& point0 = BaseType::GetPoint(0);
        const TPointType& point1 = BaseType::GetPoint(1);
        const DataType lx = point0.X() - point1.X();
        const DataType ly = point0.Y() - point1.Y();

        const DataType length = lx * lx + ly * ly;

        return sqrt( length );
    }


    /**
     * Returns whether given local point is inside the Geometry
     */
    bool IsInside( const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( std::abs( rPoint[0] ) < 1 + 1.0e-8 )
            return true;

        return false;
    }


//      virtual void Bounding_Box(BoundingBox<TPointType, BaseType>& rResult) const
//              {
//                 //rResult.Geometry() = *(this);
//                 BaseType::Bounding_Box(rResult.LowPoint(), rResult.HighPoint());
//              }





    ///@}
    ///@name Jacobian
    ///@{


    /** Jacobians for given  method. This method
    calculate jacobians matrices in all integrations points of
    given integration method.

    @param ThisMethod integration method which jacobians has to
    be calculated in its integration points.

    @return JacobiansType a Vector of jacobian
    matrices \f$ J_i \f$ where \f$ i=1,2,...,n \f$ is the integration
    point index of given integration method.

    @see DeterminantOfJacobian
    @see InverseOfJacobian
    */
    JacobiansType& Jacobian( JacobiansType& rResult, IntegrationMethod ThisMethod ) const override
    {
        MatrixType jacobian( 2, 1 );
        jacobian( 0, 0 ) = ( BaseType::GetPoint( 1 ).X() - BaseType::GetPoint( 0 ).X() ) * 0.5; //on the Gauss points (J is constant at each element)
        jacobian( 1, 0 ) = ( BaseType::GetPoint( 1 ).Y() - BaseType::GetPoint( 0 ).Y() ) * 0.5;

        if ( rResult.size() != BaseType::IntegrationPointsNumber( ThisMethod ) )
        {
            // KLUDGE: While there is a bug in ublas vector resize, I have to put this beside resizing!!
            JacobiansType temp( BaseType::IntegrationPointsNumber( ThisMethod ) );
            rResult.swap( temp );
        }

        std::fill( rResult.begin(), rResult.end(), jacobian );

        return rResult;
    }

    /** Jacobians for given  method. This method
    calculate jacobians matrices in all integrations points of
    given integration method.

    @param ThisMethod integration method which jacobians has to
    be calculated in its integration points.

    @return JacobiansType a Vector of jacobian
    matrices \f$ J_i \f$ where \f$ i=1,2,...,n \f$ is the integration
    point index of given integration method.

    @param DeltaPosition Matrix with the nodes position increment which describes
    the configuration where the jacobian has to be calculated.

    @see DeterminantOfJacobian
    @see InverseOfJacobian
    */
    JacobiansType& Jacobian( JacobiansType& rResult, IntegrationMethod ThisMethod, const MatrixType& DeltaPosition ) const override
    {
        MatrixType jacobian( 2, 1 );
        jacobian( 0, 0 ) = ( (BaseType::GetPoint( 1 ).X() - DeltaPosition(1,0)) - (BaseType::GetPoint( 0 ).X() - DeltaPosition(0,0)) ) * 0.5; //on the Gauss points (J is constant at each element)
        jacobian( 1, 0 ) = ( (BaseType::GetPoint( 1 ).Y() - DeltaPosition(1,1)) - (BaseType::GetPoint( 0 ).Y() - DeltaPosition(0,1)) ) * 0.5;

        if ( rResult.size() != BaseType::IntegrationPointsNumber( ThisMethod ) )
        {
            // KLUDGE: While there is a bug in ublas vector resize, I have to put this beside resizing!!
            JacobiansType temp( BaseType::IntegrationPointsNumber( ThisMethod ) );
            rResult.swap( temp );
        }

        std::fill( rResult.begin(), rResult.end(), jacobian );

        return rResult;
    }

    /** Jacobian in specific integration point of given integration
    method. This method calculate jacobian matrix in given
    integration point of given integration method.

    @param IntegrationPointIndex index of integration point which jacobians has to
    be calculated in it.

    @param ThisMethod integration method which jacobians has to
    be calculated in its integration points.

    @return Matrix<double> Jacobian matrix \f$ J_i \f$ where \f$
    i \f$ is the given integration point index of given
    integration method.

    @see DeterminantOfJacobian
    @see InverseOfJacobian
    */
    MatrixType& Jacobian( MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        rResult.resize( 2, 1, false );
        //on the Gauss points (J is constant at each element)
        rResult( 0, 0 ) = ( BaseType::GetPoint( 1 ).X() - BaseType::GetPoint( 0 ).X() ) * 0.5;
        rResult( 1, 0 ) = ( BaseType::GetPoint( 1 ).Y() - BaseType::GetPoint( 0 ).Y() ) * 0.5;
        return rResult;
    }

    /** Jacobian in given point. This method calculate jacobian
    matrix in given point.

    @param rPoint point which jacobians has to
    be calculated in it.

    @return Matrix of double which is jacobian matrix \f$ J \f$ in given point.

    @see DeterminantOfJacobian
    @see InverseOfJacobian
    */
    MatrixType& Jacobian( MatrixType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        rResult.resize( 2, 1, false );
        //on the Gauss points (J is constant at each element)
        rResult( 0, 0 ) = ( BaseType::GetPoint( 1 ).X() - BaseType::GetPoint( 0 ).X() ) * 0.5;
        rResult( 1, 0 ) = ( BaseType::GetPoint( 1 ).Y() - BaseType::GetPoint( 0 ).Y() ) * 0.5;
        return rResult;
    }

    /** Determinant of jacobians for given integration method. This
    method calculate determinant of jacobian in all
    integrations points of given integration method.

    @return Vector of double which is vector of determinants of
    jacobians \f$ |J|_i \f$ where \f$ i=1,2,...,n \f$ is the
    integration point index of given integration method.

    @see Jacobian
    @see InverseOfJacobian
    */
    VectorType& DeterminantOfJacobian( VectorType& rResult, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Jacobian is not square" , "" );
        return rResult;
    }

    /** Determinant of jacobian in specific integration point of
    given integration method. This method calculate determinant
    of jacobian in given integration point of given integration
    method.

    @param IntegrationPointIndex index of integration point which jacobians has to
    be calculated in it.

    @param IntegrationPointIndex index of integration point
    which determinant of jacobians has to be calculated in it.

    @return Determinamt of jacobian matrix \f$ |J|_i \f$ where \f$
    i \f$ is the given integration point index of given
    integration method.

    @see Jacobian
    @see InverseOfJacobian
    */
    DataType DeterminantOfJacobian( IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Jacobian is not square" , "" );
        return 0.0;
    }

    /** Determinant of jacobian in given point. This method calculate determinant of jacobian
    matrix in given point.

    @param rPoint point which determinant of jacobians has to
    be calculated in it.

    @return Determinamt of jacobian matrix \f$ |J| \f$ in given
    point.

    @see DeterminantOfJacobian
    @see InverseOfJacobian
    */
    DataType DeterminantOfJacobian( const LocalCoordinatesArrayType& rPoint ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Jacobian is not square" , "" );
        return 0.0;
    }


    /** Inverse of jacobians for given integration method. This method
    calculate inverse of jacobians matrices in all integrations points of
    given integration method.

    @param ThisMethod integration method which inverse of jacobians has to
    be calculated in its integration points.

    @return Inverse of jacobian
    matrices \f$ J^{-1}_i \f$ where \f$ i=1,2,...,n \f$ is the integration
    point index of given integration method.

    @see Jacobian
    @see DeterminantOfJacobian
    */
    JacobiansType& InverseOfJacobian( JacobiansType& rResult, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Jacobian is not square" , "" );
        return rResult;
    }

    /** Inverse of jacobian in specific integration point of given integration
    method. This method calculate Inverse of jacobian matrix in given
    integration point of given integration method.

    @param IntegrationPointIndex index of integration point which inverse of jacobians has to
    be calculated in it.

    @param ThisMethod integration method which inverse of jacobians has to
    be calculated in its integration points.

    @return Inverse of jacobian matrix \f$ J^{-1}_i \f$ where \f$
    i \f$ is the given integration point index of given
    integration method.

    @see Jacobian
    @see DeterminantOfJacobian
    */
    MatrixType& InverseOfJacobian( MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Jacobian is not square" , "" );
        return rResult;
    }

    /** Inverse of jacobian in given point. This method calculate inverse of jacobian
    matrix in given point.

    @param rPoint point which inverse of jacobians has to
    be calculated in it.

    @return Inverse of jacobian matrix \f$ J^{-1} \f$ in given point.

    @see DeterminantOfJacobian
    @see InverseOfJacobian
    */
    MatrixType& InverseOfJacobian( MatrixType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Jacobian is not square" , "" );
        return rResult;
    }

    /** EdgesNumber
    @return SizeType containes number of this geometry edges.
    */
    SizeType EdgesNumber() const override
    {
        return 2;
    }

    ///@}
    ///@name Shape Function
    ///@{

    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex, const LocalCoordinatesArrayType& rPoint ) const override
    {
        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( 0.5*( 1.0 - rPoint[0] ) );
        case 1:
            return( 0.5*( 1.0 + rPoint[0] ) );
        default:
            KRATOS_THROW_ERROR( std::logic_error,
                          "Wrong index of shape function!" ,
                          *this );
        }

        return 0;
    }

    ShapeFunctionsIntegrationPointsGradientsType& ShapeFunctionsIntegrationPointsGradients( ShapeFunctionsIntegrationPointsGradientsType& rResult, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Jacobian is not square" , "" );
        return rResult;
    }

    ///@}
    ///@name Input and output
    ///@{

    /** Turn back information as a string.

    @return String contains information about this geometry.
    @see PrintData()
    @see PrintInfo()
    */
    std::string Info() const override
    {
        return "1 dimensional line in 2D space";
    }

    /** Print information about this object.

    @param rOStream Stream to print into it.
    @see PrintData()
    @see Info()
    */
    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "1 dimensional line in 2D space";
    }

    /** Print geometry's data into given stream. Prints it's points
    by the order they stored in the geometry and then center
    point of geometry.

    @param rOStream Stream to print into it.
    @see PrintInfo()
    @see Info()
    */
    void PrintData( std::ostream& rOStream ) const override
    {
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian\t : " << jacobian;
    }

    /**
     * Calculates the local gradients for all integration points for the
     * default integration method
     */
    // ShapeFunctionsGradientsType ShapeFunctionsLocalGradients() const override
    // {
    //     IntegrationMethod ThisMethod = msGeometryData.DefaultIntegrationMethod();
    //     ShapeFunctionsGradientsType localGradients
    //     = CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );
    //     const int integration_points_number
    //     = msGeometryData.IntegrationPointsNumber( ThisMethod );
    //     ShapeFunctionsGradientsType Result( integration_points_number );

    //     for ( int pnt = 0; pnt < integration_points_number; pnt++ )
    //     {
    //         Result[pnt] = localGradients[pnt];
    //     }

    //     return Result;
    // }


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
        rResult.resize( 2, 1 );
        noalias( rResult ) = ZeroMatrix( 2, 1 );
        rResult( 0, 0 ) = -0.5;
        rResult( 1, 0 ) =  0.5;
        return( rResult );
    }

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

        rResult[0].resize( 1, 1 );
        rResult[1].resize( 1, 1 );

        rResult[0]( 0, 0 ) = 0.0;
        rResult[1]( 0, 0 ) = 0.0;

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
            DenseVector<Matrix> temp( this->PointsNumber() );
            rResult[i].swap( temp );
        }

        rResult[0][0].resize( 1, 1, false );
        rResult[1][0].resize( 1, 1, false );

        for ( int i = 0; i < 2; i++ )
        {
            rResult[i][0]( 0, 0 ) = 0.0;
        }

        return rResult;
    }

    /**
     * returns the local coordinates of all nodes of the current geometry
     * @param rResult a Matrix object that will be overwritten by the result
     * @return the local coordinates of all nodes
     */
    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if (rResult.size1() != 2 || rResult.size2() != 1)
            rResult.resize( 2, 1, false );
        rResult( 0, 0 ) = -1.0;
        rResult( 1, 0 ) =  1.0;
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
    // Matrix& ShapeFunctionsGradients( Matrix& rResult, LocalCoordinatesArrayType& rPoint ) const override
    // {
    //     rResult.resize( 2, 1 );
    //     noalias( rResult ) = ZeroMatrix( 2, 1 );

    //     rResult( 0, 0 ) = -0.5;
    //     rResult( 1, 0 ) = 0.5;
    //     return rResult;
    // }



    ///@}
    ///@name Friends
    ///@{


    ///@}

protected:
    ///@name Protected static Member Variables
    ///@{


    ///@}
    ///@name Protected member Variables
    ///@{


    ///@}
    ///@name Protected Operators
    ///@{


    ///@}
    ///@name Protected Operations
    ///@{


    ///@}
    ///@name Protected  Access
    ///@{


    ///@}
    ///@name Protected Inquiry
    ///@{


    ///@}
    ///@name Protected LifeCycle
    ///@{


    ///@}

private:
    ///@name Static Member Variables
    ///@{

    static const GeometryData msGeometryData;

    ///@}
    ///@name Member Variables
    ///@{

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

    Line2D2(): BaseType( PointsArrayType(), &msGeometryData ) {}

    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    static Matrix CalculateShapeFunctionsIntegrationPointsValues( typename BaseType::IntegrationMethod ThisMethod )
    {
        const IntegrationPointsContainerType& all_integration_points = AllIntegrationPoints();
        const IntegrationPointsArrayType& IntegrationPoints = all_integration_points[static_cast<int>(ThisMethod)];
        int integration_points_number = IntegrationPoints.size();
        Matrix N( integration_points_number, 2 );

        for ( int it_gp = 0; it_gp < integration_points_number; it_gp++ )
        {
            ValueType e = IntegrationPoints[it_gp].X();
            N( it_gp, 0 ) = 0.5 * ( 1 - e );
            N( it_gp, 1 ) = 0.5 * ( 1 + e );
        }

        return N;
    }

    static ShapeFunctionsGradientsType CalculateShapeFunctionsIntegrationPointsLocalGradients( typename BaseType::IntegrationMethod ThisMethod )
    {
        const IntegrationPointsContainerType& all_integration_points = AllIntegrationPoints();
        const IntegrationPointsArrayType& IntegrationPoints = all_integration_points[static_cast<int>(ThisMethod)];
        ShapeFunctionsGradientsType DN_De( IntegrationPoints.size() );
        std::fill( DN_De.begin(), DN_De.end(), Matrix( 2, 1 ) );

        for ( unsigned int it_gp = 0; it_gp < IntegrationPoints.size(); it_gp++ )
        {
            // ValueType e = IntegrationPoints[it_gp].X();
            DN_De[it_gp]( 0, 0 ) = -0.5;
            DN_De[it_gp]( 1, 0 ) =  0.5;
        }

        return DN_De;

    }

    static const IntegrationPointsContainerType AllIntegrationPoints()
    {
        IntegrationPointsContainerType integration_points = {{
                Quadrature<LineGaussLegendreIntegrationPoints1, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLegendreIntegrationPoints2, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLegendreIntegrationPoints3, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLegendreIntegrationPoints4, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLegendreIntegrationPoints5, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLobattoIntegrationPoints1, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLobattoIntegrationPoints2, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLobattoIntegrationPoints3, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLobattoIntegrationPoints4, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLobattoIntegrationPoints5, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
            }
        };
        return integration_points;
    }

    static const ShapeFunctionsValuesContainerType AllShapeFunctionsValues()
    {
        ShapeFunctionsValuesContainerType shape_functions_values = {{
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_1 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_2 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_3 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_4 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_5 ),
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients = {{
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_1 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_2 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_3 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_4 ),
                Line2D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_5 ),
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

    template<class TOtherPointType> friend class Line2D2;

    ///@}
    ///@name Un accessible methods
    ///@{



    ///@}

}; // Class Geometry

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{

///@}

template<class TPointType>
const GeometryData Line2D2<TPointType>::msGeometryData( 2,
        2,
        1,
        GeometryData::IntegrationMethod::GI_GAUSS_1,
        Line2D2<TPointType>::AllIntegrationPoints(),
        Line2D2<TPointType>::AllShapeFunctionsValues(),
        AllShapeFunctionsLocalGradients() );

}  // namespace Kratos.

#endif // KRATOS_LINE_2D_H_INCLUDED  defined
