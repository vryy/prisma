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
    ///@name Type Definitions
    ///@{

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

    ~Quadrilateral3D9() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Quadrilateral;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Quadrilateral3D9;
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

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
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

    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 9)
            rResult.resize( 9, false );

        for ( int i = 0; i < 4; i++ ) rResult[i] = 1.00 / 36.00;

        for ( int i = 4; i < 8; i++ ) rResult[i] = 1.00 / 9.00;

        rResult[8] = 4.00 / 9.00;

        return rResult;
    }

    ///@}
    ///@name Information
    ///@{

    DataType Length() const override
    {
        return std::sqrt( Area() );
    }

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

    LocalCoordinatesArrayType& PointLocalCoordinates( LocalCoordinatesArrayType& rResult, const CoordinatesArrayType& rPoint,
        const bool force_error = true, const ValueType tol = 1.0e-8 ) const override
    {
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
        const MatrixType& DeltaPosition, const bool force_error = true, const ValueType tol = 1.0e-8 ) const override
    {
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

    ///@}
    ///@name Jacobian
    ///@{

    VectorType& DeterminantOfJacobian( VectorType& rResult, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return rResult;
    }

    DataType DeterminantOfJacobian( IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return 0.0;
    }

    DataType DeterminantOfJacobian( const LocalCoordinatesArrayType& rPoint ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return 0.0;
    }

    JacobiansType& InverseOfJacobian( JacobiansType& rResult, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return rResult;
    }

    MatrixType& InverseOfJacobian( MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return rResult;
    }

    MatrixType& InverseOfJacobian( MatrixType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        KRATOS_THROW_ERROR( std::logic_error, "Quadrilateral3D9::DeterminantOfJacobian", "Jacobian is not square" );
        return rResult;
    }

    SizeType EdgesNumber() const override
    {
        return 4;
    }

    GeometriesArrayType Edges( void ) const override
    {
        GeometriesArrayType edges = GeometriesArrayType();
        edges.push_back( EdgeType( this->pGetPoint( 0 ), this->pGetPoint( 4 ), this->pGetPoint( 1 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 1 ), this->pGetPoint( 5 ), this->pGetPoint( 2 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 2 ), this->pGetPoint( 6 ), this->pGetPoint( 3 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 3 ), this->pGetPoint( 7 ), this->pGetPoint( 0 ) ) );
        return edges;
    }

    SizeType FacesNumber() const override
    {
        return 4;
    }

    GeometriesArrayType Faces() const override
    {
        return Edges();
    }

    ///@}
    ///@name Shape Function
    ///@{

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

    ///@}
    ///@name Input and output
    ///@{

    std::string Info() const override
    {
        return "2 dimensional quadrilateral with nine nodes in 3D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "2 dimensional quadrilateral with nine nodes in 3D space";
    }

    void PrintData( std::ostream& rOStream ) const override
    {
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian in the origin\t : " << jacobian;
        rOStream << std::endl;
    }

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
            DenseVector<Matrix> temp( this->PointsNumber() );
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

    Quadrilateral3D9(): BaseType( PointsArrayType(), &msGeometryData ) {}

    ///@}
    ///@name Private Operations
    ///@{

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

    ///@}
    ///@name Private Friends
    ///@{

    template<class TOtherPointType> friend class Quadrilateral3D9;

    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}
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
