//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.7 $
//
//

#if !defined(KRATOS_QUADRILATERAL_3D_9_H_INCLUDED )
#define  KRATOS_QUADRILATERAL_3D_9_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/line_3d_3.h"
#include "integration/quadrilateral_gauss_legendre_integration_points.h"


namespace Kratos
{

/**
  * A nine node quadrilateral geometry. While the shape functions are only defined in
  * 2D it is possible to define an arbitrary orientation in space. Thus it can be used for
  * defining surfaces on 3D elements.
 */
template<class TPointType> class Quadrilateral3D9 : public Geometry<TPointType>
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
    typedef Line3D3<TPointType> EdgeType;

    /**
     * Pointer definition of Quadrilateral3D9
     */
    KRATOS_CLASS_POINTER_DEFINITION( Quadrilateral3D9 );

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

    Quadrilateral3D9( const PointType& Point1, const PointType& Point2,
                      const PointType& Point3, const PointType& Point4,
                      const PointType& Point5, const PointType& Point6,
                      const PointType& Point7, const PointType& Point8,
                      const PointType& Point9 )
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
    }

    Quadrilateral3D9( typename PointType::Pointer pPoint1,
                      typename PointType::Pointer pPoint2,
                      typename PointType::Pointer pPoint3,
                      typename PointType::Pointer pPoint4,
                      typename PointType::Pointer pPoint5,
                      typename PointType::Pointer pPoint6,
                      typename PointType::Pointer pPoint7,
                      typename PointType::Pointer pPoint8,
                      typename PointType::Pointer pPoint9 )
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
    }

    Quadrilateral3D9( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 9 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                          "Invalid points number. Expected 9, given " , this->PointsNumber() );
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
    Quadrilateral3D9( Quadrilateral3D9 const& rOther )
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
    template<class TOtherPointType> Quadrilateral3D9(
        Quadrilateral3D9<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    /**
     * Destructor. Does nothing
     */
    ~Quadrilateral3D9() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Quadrilateral;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Quadrilateral3D9;
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
    Quadrilateral3D9& operator=( const Quadrilateral3D9& rOther )
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
    Quadrilateral3D9& operator=( Quadrilateral3D9<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }

    /**
     * Operations
     */
    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const
    {
        return typename BaseType::Pointer( new Quadrilateral3D9( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Quadrilateral3D9< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    /**
     * lumping factors for the calculation of the lumped mass matrix
     */
    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 9)
            rResult.resize( 9, false );

        for ( int i = 0; i < 4; i++ ) rResult[i] = 1.00 / 36.00;

        for ( int i = 4; i < 8; i++ ) rResult[i] = 1.00 / 9.00;

        rResult[8] = 4.00 / 9.00;

        return rResult;
    }

    /**
     * Informations
     */

    /**
     * :TODO: the charactereistic sizes have to be reviewed
     * by the one who is willing to use them!
     */
    /** This method calculates and returns Length or charactereistic
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
    DataType Length() const override
    {
        return std::sqrt( Area() );
    }

    /**
     * :TODO: the charactereistic sizes have to be reviewed
     * by the one who is willing to use them!
     */
    /**
     * This method calculates and returns area or surface area of
     * this geometry depending to it's dimension. For one dimensional
     * geometry it returns zero, for two dimensional it gives area
     * and for three dimensional geometries it gives surface area.
     * @return DataType value contains area or surface
     * area.
     * @see Length()
     * @see Volume()
     * @see DomainSize()
     */
    DataType Area() const override
    {
        JacobiansType J;
        this->Jacobian( J, msGeometryData.DefaultIntegrationMethod() );
        const IntegrationPointsArrayType& integration_points = this->IntegrationPoints( msGeometryData.DefaultIntegrationMethod() );

        DataType Area = 0.0;
        for ( unsigned int i = 0; i < integration_points.size(); i++ )
        {
            DataType dA = std::sqrt(MathUtils<DataType>::Det(MatrixType(prod(trans(J[i]), J[i]))));
            Area += dA * integration_points[i].Weight();
        }

        return Area;
    }


    DataType Volume() const override
    {
        return Area();
    }

    /**
     * :TODO: the charactereistic sizes have to be reviewed
     * by the one who is willing to use them!
     */
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

    LocalCoordinatesArrayType& PointLocalCoordinates( LocalCoordinatesArrayType& rResult, const CoordinatesArrayType& rPoint,
            bool force_error = true ) const override
    {
        ValueType tol = 1.0e-8;
        int maxiter = 1000;
        //check orientation of surface
        std::vector< unsigned int> orientation( 3 );

        DataType dummy = this->GetPoint( 0 ).X();

        if ( std::abs( this->GetPoint( 1 ).X() - dummy ) <= tol && std::abs( this->GetPoint( 2 ).X() - dummy ) <= tol && std::abs( this->GetPoint( 3 ).X() - dummy ) <= tol )
            orientation[0] = 0;

        dummy = this->GetPoint( 0 ).Y();

        if ( std::abs( this->GetPoint( 1 ).Y() - dummy ) <= tol && std::abs( this->GetPoint( 2 ).Y() - dummy ) <= tol && std::abs( this->GetPoint( 3 ).Y() - dummy ) <= tol )
            orientation[0] = 1;

        dummy = this->GetPoint( 0 ).Z();

        if ( std::abs( this->GetPoint( 1 ).Z() - dummy ) <= tol && std::abs( this->GetPoint( 2 ).Z() - dummy ) <= tol && std::abs( this->GetPoint( 3 ).Z() - dummy ) <= tol )
            orientation[0] = 2;

        switch ( orientation[0] )
        {
        case 0:
            orientation[0] = 1;
            orientation[1] = 2;
            orientation[2] = 0;
            break;
        case 1:
            orientation[0] = 0;
            orientation[1] = 2;
            orientation[2] = 1;
            break;
        case 2:
            orientation[0] = 0;
            orientation[1] = 1;
            orientation[2] = 2;
            break;
        default:
            orientation[0] = 0;
            orientation[1] = 1;
            orientation[2] = 2;
        }

        MatrixType J = ZeroMatrixType( 2, 2 );

        MatrixType invJ = ZeroMatrixType( 2, 2 );

        if ( rResult.size() != 2 )
            rResult.resize( 2, false );

        //starting with xi = 0
        rResult = ZeroVector( 2 );

        Vector DeltaXi = ZeroVector( 2 );

        CoordinatesArrayType CurrentGlobalCoords( ZeroVectorType( 3 ) );

        //Newton iteration:
        for ( int k = 0; k < maxiter; k++ )
        {
            CurrentGlobalCoords = ZeroVectorType( 3 );
            this->GlobalCoordinates( CurrentGlobalCoords, rResult );
            noalias( CurrentGlobalCoords ) = rPoint - CurrentGlobalCoords;

            //Caluclate Inverse of Jacobian
            noalias(J) = ZeroMatrixType( 2, 2 );

            //derivatives of shape functions
            Matrix shape_functions_gradients;
            shape_functions_gradients = ShapeFunctionsLocalGradients(
                                            shape_functions_gradients, rResult );

            //Elements of jacobian matrix (e.g. J(1,1) = dX1/dXi1)
            //loop over all nodes
            for ( unsigned int i = 0; i < this->PointsNumber(); i++ )
            {
                Point<3, DataType> dummyPoint = this->GetPoint( i );
                J( 0, 0 ) += ( dummyPoint[orientation[0]] ) * ( shape_functions_gradients( i, 0 ) );
                J( 0, 1 ) += ( dummyPoint[orientation[0]] ) * ( shape_functions_gradients( i, 1 ) );
                J( 1, 0 ) += ( dummyPoint[orientation[1]] ) * ( shape_functions_gradients( i, 0 ) );
                J( 1, 1 ) += ( dummyPoint[orientation[1]] ) * ( shape_functions_gradients( i, 1 ) );
            }

            //deteminant of Jacobian
            DataType det_j = J( 0, 0 ) * J( 1, 1 ) - J( 0, 1 ) * J( 1, 0 );

            //filling matrix
            invJ( 0, 0 ) = ( J( 1, 1 ) ) / ( det_j );

            invJ( 1, 0 ) = -( J( 1, 0 ) ) / ( det_j );

            invJ( 0, 1 ) = -( J( 0, 1 ) ) / ( det_j );

            invJ( 1, 1 ) = ( J( 0, 0 ) ) / ( det_j );

            if constexpr (std::is_same<ValueType, DataType>::value)
            {
                DeltaXi( 0 ) = invJ( 0, 0 ) * CurrentGlobalCoords( orientation[0] ) + invJ( 0, 1 ) * CurrentGlobalCoords( orientation[1] );

                DeltaXi( 1 ) = invJ( 1, 0 ) * CurrentGlobalCoords( orientation[0] ) + invJ( 1, 1 ) * CurrentGlobalCoords( orientation[1] );
            }
            else
            {
                // TODO to be implemented
                KRATOS_ERROR << "Update local coordinates with complex coordinates is not supported";
            }

            noalias( rResult ) += DeltaXi;

            if ( MathUtils<ValueType>::Norm3( DeltaXi ) > 30 )
            {
                if (force_error)
                    KRATOS_THROW_ERROR(std::logic_error,"computation of local coordinates failed at iteration ", k)
                break;
            }

            if ( MathUtils<ValueType>::Norm3( DeltaXi ) < tol )
            {
                if ( !( std::abs( CurrentGlobalCoords( orientation[2] ) ) <= tol ) )
                    rResult( 0 ) = 2.0;

                break;
            }
        }

        return( rResult );
    }

    LocalCoordinatesArrayType& PointLocalCoordinates( LocalCoordinatesArrayType& rResult, const CoordinatesArrayType& rPoint,
        const MatrixType& DeltaPosition, bool force_error = true ) const override
    {
        ValueType tol = 1.0e-8;
        int maxiter = 1000;
        //check orientation of surface
        std::vector< unsigned int> orientation( 3 );

        DataType dummy = this->GetPoint( 0 ).X() - DeltaPosition( 0, 0 );

        if ( std::abs( this->GetPoint( 1 ).X() - DeltaPosition( 1, 0 ) - dummy ) <= tol
          && std::abs( this->GetPoint( 2 ).X() - DeltaPosition( 2, 0 ) - dummy ) <= tol
          && std::abs( this->GetPoint( 3 ).X() - DeltaPosition( 3, 0 ) - dummy ) <= tol )
            orientation[0] = 0;

        dummy = this->GetPoint( 0 ).Y();

        if ( std::abs( this->GetPoint( 1 ).Y() - DeltaPosition( 1, 1 ) - dummy ) <= tol
          && std::abs( this->GetPoint( 2 ).Y() - DeltaPosition( 2, 1 ) - dummy ) <= tol
          && std::abs( this->GetPoint( 3 ).Y() - DeltaPosition( 3, 1 ) - dummy ) <= tol )
            orientation[0] = 1;

        dummy = this->GetPoint( 0 ).Z();

        if ( std::abs( this->GetPoint( 1 ).Z() - DeltaPosition( 1, 2 ) - dummy ) <= tol
          && std::abs( this->GetPoint( 2 ).Z() - DeltaPosition( 2, 2 ) - dummy ) <= tol
          && std::abs( this->GetPoint( 3 ).Z() - DeltaPosition( 3, 2 ) - dummy ) <= tol )
            orientation[0] = 2;

        switch ( orientation[0] )
        {
        case 0:
            orientation[0] = 1;
            orientation[1] = 2;
            orientation[2] = 0;
            break;
        case 1:
            orientation[0] = 0;
            orientation[1] = 2;
            orientation[2] = 1;
            break;
        case 2:
            orientation[0] = 0;
            orientation[1] = 1;
            orientation[2] = 2;
            break;
        default:
            orientation[0] = 0;
            orientation[1] = 1;
            orientation[2] = 2;
        }

        MatrixType J = ZeroMatrixType( 2, 2 );

        MatrixType invJ = ZeroMatrixType( 2, 2 );

        if ( rResult.size() != 2 )
            rResult.resize( 2, false );

        //starting with xi = 0
        rResult = ZeroVector( 2 );

        Vector DeltaXi = ZeroVector( 2 );

        CoordinatesArrayType CurrentGlobalCoords( ZeroVectorType( 3 ) );

        //Newton iteration:
        for ( int k = 0; k < maxiter; k++ )
        {
            CurrentGlobalCoords = ZeroVectorType( 3 );
            this->GlobalCoordinates( CurrentGlobalCoords, rResult, DeltaPosition );
            noalias( CurrentGlobalCoords ) = rPoint - CurrentGlobalCoords;

            //Caluclate Inverse of Jacobian
            noalias(J) = ZeroMatrixType( 2, 2 );

            //derivatives of shape functions
            Matrix shape_functions_gradients;
            shape_functions_gradients = ShapeFunctionsLocalGradients(
                                            shape_functions_gradients, rResult );

            //Elements of jacobian matrix (e.g. J(1,1) = dX1/dXi1)
            //loop over all nodes
            for ( unsigned int i = 0; i < this->PointsNumber(); i++ )
            {
                Point<3, DataType> dummyPoint = static_cast<Point<3, DataType> >(this->GetPoint( i ) - row( DeltaPosition, i ));
                J( 0, 0 ) += ( dummyPoint[orientation[0]] ) * ( shape_functions_gradients( i, 0 ) );
                J( 0, 1 ) += ( dummyPoint[orientation[0]] ) * ( shape_functions_gradients( i, 1 ) );
                J( 1, 0 ) += ( dummyPoint[orientation[1]] ) * ( shape_functions_gradients( i, 0 ) );
                J( 1, 1 ) += ( dummyPoint[orientation[1]] ) * ( shape_functions_gradients( i, 1 ) );
            }

            //deteminant of Jacobian
            DataType det_j = J( 0, 0 ) * J( 1, 1 ) - J( 0, 1 ) * J( 1, 0 );

            //filling matrix
            invJ( 0, 0 ) = ( J( 1, 1 ) ) / ( det_j );

            invJ( 1, 0 ) = -( J( 1, 0 ) ) / ( det_j );

            invJ( 0, 1 ) = -( J( 0, 1 ) ) / ( det_j );

            invJ( 1, 1 ) = ( J( 0, 0 ) ) / ( det_j );

            if constexpr (std::is_same<ValueType, DataType>::value)
            {
                DeltaXi( 0 ) = invJ( 0, 0 ) * CurrentGlobalCoords( orientation[0] ) + invJ( 0, 1 ) * CurrentGlobalCoords( orientation[1] );

                DeltaXi( 1 ) = invJ( 1, 0 ) * CurrentGlobalCoords( orientation[0] ) + invJ( 1, 1 ) * CurrentGlobalCoords( orientation[1] );
            }
            else
            {
                // TODO to be implemented
                KRATOS_ERROR << "Update local coordinates with complex coordinates is not supported";
            }

            noalias( rResult ) += DeltaXi;

            if ( MathUtils<ValueType>::Norm3( DeltaXi ) > 30 )
            {
                if (force_error)
                    KRATOS_THROW_ERROR(std::logic_error,"computation of local coordinates failed at iteration ", k)
                break;
            }

            if ( MathUtils<ValueType>::Norm3( DeltaXi ) < tol )
            {
                if ( !( std::abs( CurrentGlobalCoords( orientation[2] ) ) <= tol ) )
                    rResult( 0 ) = 2.0;

                break;
            }
        }

        return( rResult );
    }

    /**
     * Jacobian
     */

    /**
     * :TODO: implemented but not yet tested
     */
    /**
     * Determinant of jacobians for given integration method. This
     * method calculate determinant of jacobian in all
     * integrations points of given integration method.
     *
     * @return Vector of DataType which is vector of determinants of
     * jacobians \f$ |J|_i \f$ where \f$ i=1,2,...,n \f$ is the
     * integration point index of given integration method.
     *
     * @see Jacobian
     * @see InverseOfJacobian
     */
    VectorType& DeterminantOfJacobian( VectorType& rResult,
                                       IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return rResult;
    }

    /**
     * :TODO: implemented but not yet tested
     */
    /**
     * Determinant of jacobian in specific integration point of
     * given integration method. This method calculate determinant
     * of jacobian in given integration point of given integration
     * method.
     *
     * @param IntegrationPointIndex index of integration point which jacobians has to
     * be calculated in it.
     * @param IntegrationPointIndex index of integration point
     * which determinant of jacobians has to be calculated in it.
     *
     * @return Determinamt of jacobian matrix \f$ |J|_i \f$ where \f$
     * i \f$ is the given integration point index of given
     * integration method.
     *
     * @see Jacobian
     * @see InverseOfJacobian
     * KLUDGE: works only with explicitly generated Matrix object
     */
    DataType DeterminantOfJacobian( IndexType IntegrationPointIndex,
                                    IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return 0.0;
    }

    /**
     * :TODO: check out, whether the PointType might be replaced
     * by a general Point. This would be the clean way
     */
    /**
     * Determinant of jacobian in given point.
     * This method calculate determinant of jacobian
     * matrix in given point.
     *
     * @param rPoint point which determinant of jacobians has to
     * be calculated in it.
     *
     * @return Determinamt of jacobian matrix \f$ |J| \f$ in given
     * point.
     *
     * @see DeterminantOfJacobian
     * @see InverseOfJacobian
     *
     * KLUDGE: PointType needed for proper functionality
     * KLUDGE: works only with explicitly generated Matrix object
     */
    DataType DeterminantOfJacobian( const LocalCoordinatesArrayType& rPoint ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return 0.0;
    }

    /**
     * :TODO: implemented but not yet tested
     */
    /**
     * Inverse of jacobians for given integration method.
     * This method calculates the inverse of jacobians
     * matrices in all integrations points of
     * given integration method.
     *
     * @param ThisMethod integration method which inverse of jacobians has to
     * be calculated in its integration points.
     *
     * @return Inverse of jacobian
     * matrices \f$ J^{-1}_i \f$ where \f$ i=1,2,...,n \f$ is the integration
     * point index of given integration method.
     *
     * @see Jacobian
     * @see DeterminantOfJacobian
     *
     * KLUDGE: works only with explicitly generated Matrix object
     */
    JacobiansType& InverseOfJacobian( JacobiansType& rResult,
            IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return rResult;
    }

    /**
     * :TODO: implemented but not yet tested
     */
    /**
     * Inverse of jacobian in specific integration point of given integration
     * method. This method calculate Inverse of jacobian matrix in given
     * integration point of given integration method.
     *
     * @param IntegrationPointIndex index of integration point which inverse
     * of jacobians has to be calculated in it.
     *
     * @param ThisMethod integration method which inverse of jacobians has to
     * be calculated in its integration points.
     *
     * @return Inverse of jacobian matrix \f$ J^{-1}_i \f$ where \f$
     * i \f$ is the given integration point index of given
     * integration method.
     *
     * @see Jacobian
     * @see DeterminantOfJacobian
     *
     * KLUDGE: works only with explicitly generated Matrix object
     */
    MatrixType& InverseOfJacobian( MatrixType& rResult,
                                   IndexType IntegrationPointIndex,
                                   IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return rResult;
    }

    /**
     * :TODO: implemented but not yet tested
     */
    /**
     * Inverse of jacobian in given point.
     * This method calculate inverse of jacobian
     * matrix in given point.
     *
     * @param rPoint point which inverse of jacobians has to
     * be calculated in it.
     * @return Inverse of jacobian matrix \f$ J^{-1} \f$ in given point.
     *
     * @see DeterminantOfJacobian
     * @see InverseOfJacobian
     *
     * KLUDGE: works only with explicitly generated Matrix object
     */
    MatrixType& InverseOfJacobian( MatrixType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return rResult;
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
    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex,
                                  const LocalCoordinatesArrayType& rPoint ) const override
    {
        ValueType fx1 = 0.5 * ( rPoint[0] - 1 ) * rPoint[0];
        ValueType fx2 = 0.5 * ( rPoint[0] + 1 ) * rPoint[0];
        ValueType fx3 = 1 - rPoint[0] * rPoint[0];
        ValueType fy1 = 0.5 * ( rPoint[1] - 1 ) * rPoint[1];
        ValueType fy2 = 0.5 * ( rPoint[1] + 1 ) * rPoint[1];
        ValueType fy3 = 1 - rPoint[1] * rPoint[1];

        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( fx1*fy1 );
        case 1:
            return( fx2*fy1 );
        case 2:
            return( fx2*fy2 );
        case 3:
            return( fx1*fy2 );
        case 4:
            return( fx3*fy1 );
        case 5:
            return( fx2*fy3 );
        case 6:
            return( fx3*fy2 );
        case 7:
            return( fx1*fy3 );
        case 8:
            return( fx3*fy3 );
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
     * Calculates the gradients of the shape functions with
     * regard to the global coordinates in all
     * integration points (\f$ \frac{\partial N^i}{\partial X_j} \f$)
     *
     * @param rResult a container which takes the calculated gradients
     * @param ThisMethod the given IntegrationMethod
     * @return the gradients of all shape functions with regard to the
     * global coordinates
     *
     * KLUDGE: method call only works with explicit JacobiansType rather than creating
     * JacobiansType within argument list
     */
    ShapeFunctionsIntegrationPointsGradientsType& ShapeFunctionsIntegrationPointsGradients(
        ShapeFunctionsIntegrationPointsGradientsType& rResult, IntegrationMethod ThisMethod ) const override
    {
        const unsigned int integration_points_number = msGeometryData.IntegrationPointsNumber( ThisMethod );

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

        JacobiansType invJ = InverseOfJacobian( temp, ThisMethod );

        //loop over all integration points
        for ( unsigned int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            rResult[pnt].resize( 4, 2, false );

            for ( int i = 0; i < 4; i++ )
            {
                for ( int j = 0; j < 2; j++ )
                {
                    rResult[pnt]( i, j ) = ( locG[pnt]( i, 0 ) * invJ[pnt]( j, 0 ) )
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
        return "2 dimensional quadrilateral with nine nodes in 3D space";
    }

    /**
     * Print information about this object.
     * @param rOStream Stream to print into it.
     * @see PrintData()
     * @see Info()
     */
    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "2 dimensional quadrilateral with nine nodes in 3D space";
    }

    /**
     * Print geometry's data into given stream. Prints it's points
     * by the order they stored in the geometry and then center
     * point of geometry.
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
        rOStream << std::endl;
    }

    /**
     * Calculates the local gradients for all integration points for
     * given integration method
     */
    // ShapeFunctionsGradientsType ShapeFunctionsLocalGradients( IntegrationMethod ThisMethod ) const override
    // {
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
     * Calculates the gradients in terms of local coordinateds of
     * all shape functions in a given point.
     *
     * @param rPoint the current point at which the gradients are calculated
     * @return the gradients of all shape functions
     * \f$ \frac{\partial N^i}{\partial \xi_j} \f$
     */
    Matrix& ShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        ValueType fx1 = 0.5 * ( rPoint[0] - 1 ) * rPoint[0];
        ValueType fx2 = 0.5 * ( rPoint[0] + 1 ) * rPoint[0];
        ValueType fx3 = 1 - rPoint[0] * rPoint[0];
        ValueType fy1 = 0.5 * ( rPoint[1] - 1 ) * rPoint[1];
        ValueType fy2 = 0.5 * ( rPoint[1] + 1 ) * rPoint[1];
        ValueType fy3 = 1 - rPoint[1] * rPoint[1];

        ValueType gx1 = 0.5 * ( 2 * rPoint[0] - 1 );
        ValueType gx2 = 0.5 * ( 2 * rPoint[0] + 1 );
        ValueType gx3 = -2.0 * rPoint[0];
        ValueType gy1 = 0.5 * ( 2 * rPoint[1] - 1 );
        ValueType gy2 = 0.5 * ( 2 * rPoint[1] + 1 );
        ValueType gy3 = -2.0 * rPoint[1];

        rResult.resize( 9, 2, false );
        noalias( rResult ) = ZeroMatrix( 9, 2 );
        rResult( 0, 0 ) = gx1 * fy1;
        rResult( 0, 1 ) = fx1 * gy1;
        rResult( 1, 0 ) = gx2 * fy1;
        rResult( 1, 1 ) = fx2 * gy1;
        rResult( 2, 0 ) = gx2 * fy2;
        rResult( 2, 1 ) = fx2 * gy2;
        rResult( 3, 0 ) = gx1 * fy2;
        rResult( 3, 1 ) = fx1 * gy2;
        rResult( 4, 0 ) = gx3 * fy1;
        rResult( 4, 1 ) = fx3 * gy1;
        rResult( 5, 0 ) = gx2 * fy3;
        rResult( 5, 1 ) = fx2 * gy3;
        rResult( 6, 0 ) = gx3 * fy2;
        rResult( 6, 1 ) = fx3 * gy2;
        rResult( 7, 0 ) = gx1 * fy3;
        rResult( 7, 1 ) = fx1 * gy3;
        rResult( 8, 0 ) = gx3 * fy3;
        rResult( 8, 1 ) = fx3 * gy3;

        return rResult;
    }

    /**
     * returns the local coordinates of all nodes of the current geometry
     * @param rResult a Matrix object that will be overwritten by the result
     * @return the local coordinates of all nodes
     */
    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if (rResult.size1() != 9 || rResult.size2() != 2)
            rResult.resize( 9, 2, false );
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
        rResult( 8, 0 ) =  0.0;
        rResult( 8, 1 ) =  0.0;
        return rResult;
    }

    /**
     * returns the shape function gradients in an arbitrary point,
     * given in local coordinates
     *
     * @param rResult the matrix of gradients, will be overwritten
     * with the gradients for all shape functions in given point
     * @param rPoint the given point the gradients are calculated in
     */
    // Matrix& ShapeFunctionsGradients( Matrix& rResult, PointType& rPoint ) override
    // {
    //     ValueType fx1 = 0.5 * ( rPoint.X() - 1 ) * rPoint.X();
    //     ValueType fx2 = 0.5 * ( rPoint.X() + 1 ) * rPoint.X();
    //     ValueType fx3 = 1 - rPoint.X() * rPoint.X();
    //     ValueType fy1 = 0.5 * ( rPoint.Y() - 1 ) * rPoint.Y();
    //     ValueType fy2 = 0.5 * ( rPoint.Y() + 1 ) * rPoint.Y();
    //     ValueType fy3 = 1 - rPoint.Y() * rPoint.Y();

    //     ValueType gx1 = 0.5 * ( 2 * rPoint.X() - 1 );
    //     ValueType gx2 = 0.5 * ( 2 * rPoint.X() + 1 );
    //     ValueType gx3 = -2.0 * rPoint.X();
    //     ValueType gy1 = 0.5 * ( 2 * rPoint.Y() - 1 );
    //     ValueType gy2 = 0.5 * ( 2 * rPoint.Y() + 1 );
    //     ValueType gy3 = -2.0 * rPoint.Y();

    //     rResult.resize( 9, 2, false );
    //     noalias( rResult ) = ZeroMatrix( 9, 2 );
    //     rResult( 0, 0 ) = gx1 * fy1;
    //     rResult( 0, 1 ) = fx1 * gy1;
    //     rResult( 1, 0 ) = gx2 * fy1;
    //     rResult( 1, 1 ) = fx2 * gy1;
    //     rResult( 2, 0 ) = gx2 * fy2;
    //     rResult( 2, 1 ) = fx2 * gy2;
    //     rResult( 3, 0 ) = gx1 * fy2;
    //     rResult( 3, 1 ) = fx1 * gy2;
    //     rResult( 4, 0 ) = gx3 * fy1;
    //     rResult( 4, 1 ) = fx3 * gy1;
    //     rResult( 5, 0 ) = gx2 * fy3;
    //     rResult( 5, 1 ) = fx2 * gy3;
    //     rResult( 6, 0 ) = gx3 * fy2;
    //     rResult( 6, 1 ) = fx3 * gy2;
    //     rResult( 7, 0 ) = gx1 * fy3;
    //     rResult( 7, 1 ) = fx1 * gy3;
    //     rResult( 8, 0 ) = gx3 * fy3;
    //     rResult( 8, 1 ) = fx3 * gy3;

    //     return rResult;
    // }

    /**
     * returns the second order derivatives of all shape functions
     * in given arbitrary points
     * @param rResult a third order tensor which contains the second derivatives
     * @param rPoint the given point the second order derivatives are calculated in
     */
    ShapeFunctionsSecondDerivativesType& ShapeFunctionsSecondDerivatives( ShapeFunctionsSecondDerivativesType& rResult,
            const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( rResult.size() != this->PointsNumber() )
        {
            // KLUDGE: While there is a bug in ublas vector resize, I have to put this beside resizing!!
            ShapeFunctionsGradientsType temp( this->PointsNumber() );
            rResult.swap( temp );
        }

        for ( unsigned int i = 0; i < this->PointsNumber(); i++ )
        {
            rResult[i].resize( 2, 2, false );
            noalias( rResult[i] ) = ZeroMatrix( 2, 2 );
        }

        ValueType fx1 = 0.5 * ( rPoint[0] - 1 ) * rPoint[0];
        ValueType fx2 = 0.5 * ( rPoint[0] + 1 ) * rPoint[0];
        ValueType fx3 = 1 - rPoint[0] * rPoint[0];
        ValueType fy1 = 0.5 * ( rPoint[1] - 1 ) * rPoint[1];
        ValueType fy2 = 0.5 * ( rPoint[1] + 1 ) * rPoint[1];
        ValueType fy3 = 1 - rPoint[1] * rPoint[1];

        ValueType gx1 = 0.5 * ( 2 * rPoint[0] - 1 );
        ValueType gx2 = 0.5 * ( 2 * rPoint[0] + 1 );
        ValueType gx3 = -2.0 * rPoint[0];
        ValueType gy1 = 0.5 * ( 2 * rPoint[1] - 1 );
        ValueType gy2 = 0.5 * ( 2 * rPoint[1] + 1 );
        ValueType gy3 = -2.0 * rPoint[1];

        ValueType hx1 = 1.0;
        ValueType hx2 = 1.0;
        ValueType hx3 = -2.0;
        ValueType hy1 = 1.0;
        ValueType hy2 = 1.0;
        ValueType hy3 = -2.0;

        rResult[0]( 0, 0 ) = hx1 * fy1;
        rResult[0]( 0, 1 ) = gx1 * gy1;
        rResult[0]( 1, 0 ) = gx1 * gy1;
        rResult[0]( 1, 1 ) = fx1 * hy1;

        rResult[1]( 0, 0 ) = hx2 * fy1;
        rResult[1]( 0, 1 ) = gx2 * gy1;
        rResult[1]( 1, 0 ) = gx2 * gy1;
        rResult[1]( 1, 1 ) = fx2 * hy1;

        rResult[2]( 0, 0 ) = hx2 * fy2;
        rResult[2]( 0, 1 ) = gx2 * gy2;
        rResult[2]( 1, 0 ) = gx2 * gy2;
        rResult[2]( 1, 1 ) = fx2 * hy2;

        rResult[3]( 0, 0 ) = hx1 * fy2;
        rResult[3]( 0, 1 ) = gx1 * gy2;
        rResult[3]( 1, 0 ) = gx1 * gy2;
        rResult[3]( 1, 1 ) = fx1 * hy2;

        rResult[4]( 0, 0 ) = hx3 * fy1;
        rResult[4]( 0, 1 ) = gx3 * gy1;
        rResult[4]( 1, 0 ) = gx3 * gy1;
        rResult[4]( 1, 1 ) = fx3 * hy1;

        rResult[5]( 0, 0 ) = hx2 * fy3;
        rResult[5]( 0, 1 ) = gx2 * gy3;
        rResult[5]( 1, 0 ) = gx2 * gy3;
        rResult[5]( 1, 1 ) = fx2 * hy3;

        rResult[6]( 0, 0 ) = hx3 * fy2;
        rResult[6]( 0, 1 ) = gx3 * gy2;
        rResult[6]( 1, 0 ) = gx3 * gy2;
        rResult[6]( 1, 1 ) = fx3 * hy2;

        rResult[7]( 0, 0 ) = hx1 * fy3;
        rResult[7]( 0, 1 ) = gx1 * gy3;
        rResult[7]( 1, 0 ) = gx1 * gy3;
        rResult[7]( 1, 1 ) = fx1 * hy3;

        rResult[8]( 0, 0 ) = hx3 * fy3;
        rResult[8]( 0, 1 ) = gx3 * gy3;
        rResult[8]( 1, 0 ) = gx3 * gy3;
        rResult[8]( 1, 1 ) = fx3 * hy3;

        return rResult;
    }


    /**
    * returns the third order derivatives of all shape functions
    * in given arbitrary points
    * @param rResult a fourth order tensor which contains the third derivatives
    * @param rPoint the given point the third order derivatives are calculated in
     */
    ShapeFunctionsThirdDerivativesType& ShapeFunctionsThirdDerivatives( ShapeFunctionsThirdDerivativesType& rResult,
            const LocalCoordinatesArrayType& rPoint ) const override
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

        for ( unsigned int i = 0; i < this->PointsNumber(); i++ )
        {
            for ( unsigned int j = 0; j < 2; j++ )
            {
                rResult[i][j].resize( 2, 2, false );
                noalias( rResult[i][j] ) = ZeroMatrix( 2, 2 );
            }
        }

//                 ValueType fx1 = 0.5*(rPoint[0]-1)*rPoint[0];
//                 ValueType fx2 = 0.5*(rPoint[0]+1)*rPoint[0];
//                 ValueType fx3 = 1-rPoint[0]*rPoint[0];
//                 ValueType fy1 = 0.5*(rPoint[1]-1)*rPoint[1];
//                 ValueType fy2 = 0.5*(rPoint[1]+1)*rPoint[1];
//                 ValueType fy3 = 1-rPoint[1]*rPoint[1];

        ValueType gx1 = 0.5 * ( 2 * rPoint[0] - 1 );

        ValueType gx2 = 0.5 * ( 2 * rPoint[0] + 1 );

        ValueType gx3 = -2.0 * rPoint[0];

        ValueType gy1 = 0.5 * ( 2 * rPoint[1] - 1 );

        ValueType gy2 = 0.5 * ( 2 * rPoint[1] + 1 );

        ValueType gy3 = -2.0 * rPoint[1];

        ValueType hx1 = 1.0;

        ValueType hx2 = 1.0;

        ValueType hx3 = -2.0;

        ValueType hy1 = 1.0;

        ValueType hy2 = 1.0;

        ValueType hy3 = -2.0;

        rResult[0][0]( 0, 0 ) = 0.0;

        rResult[0][0]( 0, 1 ) = hx1 * gy1;

        rResult[0][0]( 1, 0 ) = hx1 * gy1;

        rResult[0][0]( 1, 1 ) = gx1 * hy1;

        rResult[0][1]( 0, 0 ) = hx1 * gy1;

        rResult[0][1]( 0, 1 ) = gx1 * hy1;

        rResult[0][1]( 1, 0 ) = gx1 * hy1;

        rResult[0][1]( 1, 1 ) = 0.0;

        rResult[1][0]( 0, 0 ) = 0.0;

        rResult[1][0]( 0, 1 ) = hx2 * gy1;

        rResult[1][0]( 1, 0 ) = hx2 * gy1;

        rResult[1][0]( 1, 1 ) = gx2 * hy1;

        rResult[1][1]( 0, 0 ) = hx2 * gy1;

        rResult[1][1]( 0, 1 ) = gx2 * hy1;

        rResult[1][1]( 1, 0 ) = gx2 * hy1;

        rResult[1][1]( 1, 1 ) = 0.0;

        rResult[2][0]( 0, 0 ) = 0.0;

        rResult[2][0]( 0, 1 ) = hx2 * gy2;

        rResult[2][0]( 1, 0 ) = hx2 * gy2;

        rResult[2][0]( 1, 1 ) = gx2 * hy2;

        rResult[2][1]( 0, 0 ) = hx2 * gy2;

        rResult[2][1]( 0, 1 ) = gx2 * hy2;

        rResult[2][1]( 1, 0 ) = gx2 * hy2;

        rResult[2][1]( 1, 1 ) = 0.0;

        rResult[3][0]( 0, 0 ) = 0.0;

        rResult[3][0]( 0, 1 ) = hx1 * gy2;

        rResult[3][0]( 1, 0 ) = hx1 * gy2;

        rResult[3][0]( 1, 1 ) = gx1 * hy2;

        rResult[3][1]( 0, 0 ) = hx1 * gy2;

        rResult[3][1]( 0, 1 ) = gx1 * hy2;

        rResult[3][1]( 1, 0 ) = gx1 * hy2;

        rResult[3][1]( 1, 1 ) = 0.0;

        rResult[4][0]( 0, 0 ) = 0.0;

        rResult[4][0]( 0, 1 ) = hx3 * gy1;

        rResult[4][0]( 1, 0 ) = hx3 * gy1;

        rResult[4][0]( 1, 1 ) = gx3 * hy1;

        rResult[4][1]( 0, 0 ) = hx3 * gy1;

        rResult[4][1]( 0, 1 ) = gx3 * hy1;

        rResult[4][1]( 1, 0 ) = gx3 * hy1;

        rResult[4][1]( 1, 1 ) = 0.0;

        rResult[5][0]( 0, 0 ) = 0.0;

        rResult[5][0]( 0, 1 ) = hx2 * gy3;

        rResult[5][0]( 1, 0 ) = hx2 * gy3;

        rResult[5][0]( 1, 1 ) = gx2 * hy3;

        rResult[5][1]( 0, 0 ) = hx2 * gy3;

        rResult[5][1]( 0, 1 ) = gx2 * hy3;

        rResult[5][1]( 1, 0 ) = gx2 * hy3;

        rResult[5][1]( 1, 1 ) = 0.0;

        rResult[6][0]( 0, 0 ) = 0.0;

        rResult[6][0]( 0, 1 ) = hx3 * gy2;

        rResult[6][0]( 1, 0 ) = hx3 * gy2;

        rResult[6][0]( 1, 1 ) = gx3 * hy2;

        rResult[6][1]( 0, 0 ) = hx3 * gy2;

        rResult[6][1]( 0, 1 ) = gx3 * hy2;

        rResult[6][1]( 1, 0 ) = gx3 * hy2;

        rResult[6][1]( 1, 1 ) = 0.0;

        rResult[7][0]( 0, 0 ) = 0.0;

        rResult[7][0]( 0, 1 ) = hx1 * gy3;

        rResult[7][0]( 1, 0 ) = hx1 * gy3;

        rResult[7][0]( 1, 1 ) = gx1 * hy3;

        rResult[7][1]( 0, 0 ) = hx1 * gy3;

        rResult[7][1]( 0, 1 ) = gx1 * hy3;

        rResult[7][1]( 1, 0 ) = gx1 * hy3;

        rResult[7][1]( 1, 1 ) = 0.0;

        rResult[8][0]( 0, 0 ) = 0.0;

        rResult[8][0]( 0, 1 ) = hx3 * gy3;

        rResult[8][0]( 1, 0 ) = hx3 * gy3;

        rResult[8][0]( 1, 1 ) = gx3 * hy3;

        rResult[8][1]( 0, 0 ) = hx3 * gy3;

        rResult[8][1]( 0, 1 ) = gx3 * hy3;

        rResult[8][1]( 1, 0 ) = gx3 * hy3;

        rResult[8][1]( 1, 1 ) = 0.0;


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

    Quadrilateral3D9(): BaseType( PointsArrayType(), &msGeometryData ) {}

    /**
     * Private Operations
     */


    /**
     * :TODO: implemented but not yet tested
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
        IntegrationMethod ThisMethod )
    {
        IntegrationPointsContainerType all_integration_points = AllIntegrationPoints();
        IntegrationPointsArrayType integration_points = all_integration_points[static_cast<int>(ThisMethod)];
        //number of integration points
        const int integration_points_number = integration_points.size();
        //number of nodes in current geometry
        const int points_number = 9;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            ValueType fx1 = 0.5 * ( integration_points[pnt].X() - 1 ) * integration_points[pnt].X();
            ValueType fx2 = 0.5 * ( integration_points[pnt].X() + 1 ) * integration_points[pnt].X();
            ValueType fx3 = 1 - integration_points[pnt].X() * integration_points[pnt].X();
            ValueType fy1 = 0.5 * ( integration_points[pnt].Y() - 1 ) * integration_points[pnt].Y();
            ValueType fy2 = 0.5 * ( integration_points[pnt].Y() + 1 ) * integration_points[pnt].Y();
            ValueType fy3 = 1 - integration_points[pnt].Y() * integration_points[pnt].Y();

            shape_function_values( pnt, 0 ) = ( fx1 * fy1 );
            shape_function_values( pnt, 1 ) = ( fx2 * fy1 );
            shape_function_values( pnt, 2 ) = ( fx2 * fy2 );
            shape_function_values( pnt, 3 ) = ( fx1 * fy2 );
            shape_function_values( pnt, 4 ) = ( fx3 * fy1 );
            shape_function_values( pnt, 5 ) = ( fx2 * fy3 );
            shape_function_values( pnt, 6 ) = ( fx3 * fy2 );
            shape_function_values( pnt, 7 ) = ( fx1 * fy3 );
            shape_function_values( pnt, 8 ) = ( fx3 * fy3 );
        }

        return shape_function_values;
    }

    /**
     * :TODO: implemented but not yet tested
     */
    /**
     * Calculates the local gradients of all shape functions in
     * all integration points.
     * Integration points are expected to be given in local coordinates
     *
     * @param ThisMethod the current integration method
     * @return the vector of the gradients of all shape functions
     * in each integration point
     */
    static ShapeFunctionsGradientsType CalculateShapeFunctionsIntegrationPointsLocalGradients(
        IntegrationMethod ThisMethod )
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
            ValueType fx1 = 0.5 * ( integration_points[pnt].X() - 1 ) * integration_points[pnt].X();
            ValueType fx2 = 0.5 * ( integration_points[pnt].X() + 1 ) * integration_points[pnt].X();
            ValueType fx3 = 1 - integration_points[pnt].X() * integration_points[pnt].X();
            ValueType fy1 = 0.5 * ( integration_points[pnt].Y() - 1 ) * integration_points[pnt].Y();
            ValueType fy2 = 0.5 * ( integration_points[pnt].Y() + 1 ) * integration_points[pnt].Y();
            ValueType fy3 = 1 - integration_points[pnt].Y() * integration_points[pnt].Y();

            ValueType gx1 = 0.5 * ( 2 * integration_points[pnt].X() - 1 );
            ValueType gx2 = 0.5 * ( 2 * integration_points[pnt].X() + 1 );
            ValueType gx3 = -2.0 * integration_points[pnt].X();
            ValueType gy1 = 0.5 * ( 2 * integration_points[pnt].Y() - 1 );
            ValueType gy2 = 0.5 * ( 2 * integration_points[pnt].Y() + 1 );
            ValueType gy3 = -2.0 * integration_points[pnt].Y();

            Matrix result( 9, 2 );
            result( 0, 0 ) = gx1 * fy1;
            result( 0, 1 ) = fx1 * gy1;
            result( 1, 0 ) = gx2 * fy1;
            result( 1, 1 ) = fx2 * gy1;
            result( 2, 0 ) = gx2 * fy2;
            result( 2, 1 ) = fx2 * gy2;
            result( 3, 0 ) = gx1 * fy2;
            result( 3, 1 ) = fx1 * gy2;
            result( 4, 0 ) = gx3 * fy1;
            result( 4, 1 ) = fx3 * gy1;
            result( 5, 0 ) = gx2 * fy3;
            result( 5, 1 ) = fx2 * gy3;
            result( 6, 0 ) = gx3 * fy2;
            result( 6, 1 ) = fx3 * gy2;
            result( 7, 0 ) = gx1 * fy3;
            result( 7, 1 ) = fx1 * gy3;
            result( 8, 0 ) = gx3 * fy3;
            result( 8, 1 ) = fx3 * gy3;

            d_shape_f_values[pnt] = result;
        }

        return d_shape_f_values;
    }

    static const IntegrationPointsContainerType AllIntegrationPoints()
    {
        IntegrationPointsContainerType integration_points =
        {
            {
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints1,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints2,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints3,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints4,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints5,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints6,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints7,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints8,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints9,
                2, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature < QuadrilateralGaussLegendreIntegrationPoints10,
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
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_5 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_1 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_2 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_3 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_4 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_5 )
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_1 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_2 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_3 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_4 ),
                Quadrilateral3D9<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients
                ( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_5 )
            }
        };
        return shape_functions_local_gradients;
    }

    /**
     * Private Friends
     */

    template<class TOtherPointType> friend class Quadrilateral3D9;

    /**
     * Un accessible methods
     */
}; // Class Quadrilateral3D9

template<class TPointType>
const GeometryData Quadrilateral3D9<TPointType>::msGeometryData(
    2, 3, 2,
    GeometryData::IntegrationMethod::GI_GAUSS_3,
    Quadrilateral3D9<TPointType>::AllIntegrationPoints(),
    Quadrilateral3D9<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

}  // namespace Kratos.

#endif // KRATOS_QUADRILATERAL_3D_9_H_INCLUDED  defined
