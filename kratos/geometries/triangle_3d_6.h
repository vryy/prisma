//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.7 $
//
//

#if !defined(KRATOS_TRIANGLE_3D_6_H_INCLUDED )
#define  KRATOS_TRIANGLE_3D_6_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/line_3d_3.h"
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
 * A four node quadrilateral geometry. While the shape functions are only defined in
 * 2D it is possible to define an arbitrary orientation in space. Thus it can be used for
 * defining surfaces on 3D elements.
 */
template<class TPointType> class Triangle3D6 : public Geometry<TPointType>
{
public:
    ///@name Type Definitions
    ///@{

    /**
     * Geometry as base class.
     */
    typedef Geometry<TPointType> BaseType;

    /**
     * Type of edge geometry
     */
    typedef Line3D3<TPointType> EdgeType;

    /**
     * Pointer definition of Triangle3D6
     */
    KRATOS_CLASS_POINTER_DEFINITION( Triangle3D6 );

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

    Triangle3D6( const PointType& FirstPoint,
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

    Triangle3D6( typename PointType::Pointer pFirstPoint,
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

    Triangle3D6( const PointsArrayType& ThisPoints )
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
    Triangle3D6( Triangle3D6 const& rOther )
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
    template<class TOtherPointType> Triangle3D6( Triangle3D6<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    ~Triangle3D6() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Triangle;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Triangle3D6;
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
    Triangle3D6& operator=( const Triangle3D6& rOther )
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
    Triangle3D6& operator=( Triangle3D6<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );
        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Triangle3D6( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Triangle3D6< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

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

    DataType Length() const override
    {
        // return sqrt( std::abs( DeterminantOfJacobian( PointType() ) ) );
        // Approximation to avoid errors. Can be improved.

        array_1d<DataType, 3> p0 = BaseType::GetPoint( 0 );
        array_1d<DataType, 3> p1 = BaseType::GetPoint( 1 );

        array_1d<DataType, 3> vx( p1 - p0 );

        return MathUtils<DataType>::Norm3(vx);
    }

    DataType Area() const override
    {
        //return std::abs( DeterminantOfJacobian( PointType() ) ) * 0.5;
        // Approximation to avoid errors. Can be improved.

        array_1d<DataType, 3> p0 = BaseType::GetPoint( 0 );
        array_1d<DataType, 3> p1 = BaseType::GetPoint( 1 );
        array_1d<DataType, 3> p2 = BaseType::GetPoint( 2 );
        array_1d<DataType, 3> p3 = BaseType::GetPoint( 3 );

        array_1d<DataType, 3> vx( p1 - p0 );
        array_1d<DataType, 3> vy( p2 - p3 );

        DataType base = MathUtils<DataType>::Norm3(vx);
        DataType length = MathUtils<DataType>::Norm3(vy);

        return base*length*0.5;
    }

    DataType DomainSize() const override
    {
        return Area();
    }

    bool IsInside( const LocalCoordinatesArrayType& rPoint, const ValueType zero ) const override
    {
        if( ( rPoint[0] >= (0.0-zero) ) && ( rPoint[0] <= 1.0 + zero ) )
            if( ( rPoint[1] >= 0.0-zero ) && (rPoint[1] <= 1.0 + zero ) )
                if(((1.0-(rPoint[0] + rPoint[1])) >= 0.0-zero) &&  ((1.0-(rPoint[0] + rPoint[1])) <= 1.0 + zero))
                    return true;

        return false;
    }

    LocalCoordinatesArrayType& PointLocalCoordinates( LocalCoordinatesArrayType& rResult, const CoordinatesArrayType& rPoint,
        const bool force_error = true, const ValueType tol = 1.0e-8 ) const override
    {
        BoundedMatrix<DataType,3,3> X;
        BoundedMatrix<DataType,3,2> DN;
        for(unsigned int i=0; i<this->size();i++)
        {
            X(0,i ) = this->GetPoint( i ).X();
            X(1,i ) = this->GetPoint( i ).Y();
            X(2,i ) = this->GetPoint( i ).Z();
        }

        int maxiter = 1000;

        MatrixType J = ZeroMatrixType( 2, 2 );
        MatrixType invJ = ZeroMatrixType( 2, 2 );

        //starting with xi = 0
        rResult = ZeroVector( 3 );
        Vector DeltaXi = ZeroVector( 2 );
        array_1d<DataType, 3> CurrentGlobalCoords;

        //Newton iteration:
        for ( int k = 0; k < maxiter; k++ )
        {
            noalias(CurrentGlobalCoords) = ZeroVectorType( 3 );
            this->GlobalCoordinates( CurrentGlobalCoords, rResult );

            noalias( CurrentGlobalCoords ) = rPoint - CurrentGlobalCoords;

            //derivatives of shape functions
            Matrix shape_functions_gradients;
            shape_functions_gradients = ShapeFunctionsLocalGradients(shape_functions_gradients, rResult );
            noalias(DN) = prod(X,shape_functions_gradients);

            noalias(J) = prod(trans(DN), DN);
            VectorType res = prod(trans(DN), CurrentGlobalCoords);

            //deteminant of Jacobian
            DataType det_j = J( 0, 0 ) * J( 1, 1 ) - J( 0, 1 ) * J( 1, 0 );

            //filling matrix
            invJ( 0, 0 ) = ( J( 1, 1 ) ) / ( det_j );
            invJ( 1, 0 ) = -( J( 1, 0 ) ) / ( det_j );
            invJ( 0, 1 ) = -( J( 0, 1 ) ) / ( det_j );
            invJ( 1, 1 ) = ( J( 0, 0 ) ) / ( det_j );

            if constexpr (std::is_same<ValueType, DataType>::value)
            {
                DeltaXi( 0 ) = invJ( 0, 0 ) * res[0] + invJ( 0, 1 ) * res[1];
                DeltaXi( 1 ) = invJ( 1, 0 ) * res[0] + invJ( 1, 1 ) * res[1];
            }
            else
            {
                // TODO to be implemented
                KRATOS_ERROR << "Update local coordinates with complex coordinates is not supported";
            }

            rResult[0] += DeltaXi[0];
            rResult[1] += DeltaXi[1];
            rResult[2] = 0.0;

            if ( k>0 && norm_2( DeltaXi ) > 30 )
            {
                if (force_error)
                    KRATOS_THROW_ERROR(std::logic_error,"computation of local coordinates failed at iteration ", k)
                break;
            }

            if ( norm_2( DeltaXi ) < tol )
            {
                break;
            }
        }

        return( rResult );
    }

    LocalCoordinatesArrayType& PointLocalCoordinates( LocalCoordinatesArrayType& rResult, const CoordinatesArrayType& rPoint, const MatrixType& DeltaPosition,
        const bool force_error = true, const ValueType tol = 1.0e-8 ) const override
    {
        BoundedMatrix<DataType,3,3> X;
        BoundedMatrix<DataType,3,2> DN;
        for(unsigned int i=0; i<this->size();i++)
        {
            X(0,i ) = this->GetPoint( i ).X() - DeltaPosition( i, 0 );
            X(1,i ) = this->GetPoint( i ).Y() - DeltaPosition( i, 1 );
            X(2,i ) = this->GetPoint( i ).Z() - DeltaPosition( i, 2 );
        }

        int maxiter = 1000;

        MatrixType J = ZeroMatrixType( 2, 2 );
        MatrixType invJ = ZeroMatrixType( 2, 2 );

        //starting with xi = 0
        rResult = ZeroVector( 3 );
        Vector DeltaXi = ZeroVector( 2 );
        array_1d<DataType, 3> CurrentGlobalCoords;

        //Newton iteration:
        for ( int k = 0; k < maxiter; k++ )
        {
            noalias(CurrentGlobalCoords) = ZeroVectorType( 3 );
            this->GlobalCoordinates( CurrentGlobalCoords, rResult, DeltaPosition );

            noalias( CurrentGlobalCoords ) = rPoint - CurrentGlobalCoords;

            //derivatives of shape functions
            Matrix shape_functions_gradients;
            shape_functions_gradients = ShapeFunctionsLocalGradients(shape_functions_gradients, rResult );
            noalias(DN) = prod(X,shape_functions_gradients);

            noalias(J) = prod(trans(DN),DN);
            VectorType res = prod(trans(DN), CurrentGlobalCoords);

            //deteminant of Jacobian
            DataType det_j = J( 0, 0 ) * J( 1, 1 ) - J( 0, 1 ) * J( 1, 0 );

            //filling matrix
            invJ( 0, 0 ) = ( J( 1, 1 ) ) / ( det_j );
            invJ( 1, 0 ) = -( J( 1, 0 ) ) / ( det_j );
            invJ( 0, 1 ) = -( J( 0, 1 ) ) / ( det_j );
            invJ( 1, 1 ) = ( J( 0, 0 ) ) / ( det_j );

            if constexpr (std::is_same<ValueType, DataType>::value)
            {
                DeltaXi( 0 ) = invJ( 0, 0 ) * res[0] + invJ( 0, 1 ) * res[1];
                DeltaXi( 1 ) = invJ( 1, 0 ) * res[0] + invJ( 1, 1 ) * res[1];
            }
            else
            {
                // TODO to be implemented
                KRATOS_ERROR << "Update local coordinates with complex coordinates is not supported";
            }

            rResult[0] += DeltaXi[0];
            rResult[1] += DeltaXi[1];
            rResult[2] = 0.0;

            if ( k>0 && norm_2( DeltaXi ) > 30 )
            {
                if (force_error)
                    KRATOS_THROW_ERROR(std::logic_error,"computation of local coordinates failed at iteration ", k)
                break;
            }

            if ( norm_2( DeltaXi ) < tol )
            {
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
        KRATOS_ERROR << "Jacobian is not square";
        return rResult;
    }

    DataType DeterminantOfJacobian( IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
        return 0.0;
    }

    DataType DeterminantOfJacobian( const LocalCoordinatesArrayType& rPoint ) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
        return 0.0;
    }

    JacobiansType& InverseOfJacobian( JacobiansType& rResult, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
        return rResult;
    }

    MatrixType& InverseOfJacobian( MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
        return rResult;
    }

    MatrixType& InverseOfJacobian( MatrixType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
        return rResult;
    }

    ///@}
    ///@name Shape Function
    ///@{

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

        JacobiansType invJ = InverseOfJacobian( temp, ThisMethod );

        //loop over all integration points
        for ( unsigned int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            rResult[pnt].resize( 6, 2 );

            for ( int i = 0; i < 6; i++ )
            {
                for ( int j = 0; j < 2; j++ )
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
        return "2 dimensional triangle with six nodes in 2D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "2 dimensional triangle with six nodes in 2D space";
    }

    void PrintData( std::ostream& rOStream ) const override
    {
        PrintInfo( rOStream );
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian in the origin\t : " << jacobian;
    }

    SizeType EdgesNumber() const override
    {
        return 3;
    }

    GeometriesArrayType Edges() const override
    {
        GeometriesArrayType edges = GeometriesArrayType();

        edges.push_back( EdgeType( this->pGetPoint( 0 ), this->pGetPoint( 3 ), this->pGetPoint( 1 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 1 ), this->pGetPoint( 4 ), this->pGetPoint( 2 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 2 ), this->pGetPoint( 5 ), this->pGetPoint( 0 ) ) );

        return edges;
    }

    SizeType FacesNumber() const override
    {
        return 3;
    }

    GeometriesArrayType Faces() const override
    {
        return Edges();
    }

    Matrix& ShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        rResult.resize( 6, 2 );
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

    ShapeFunctionsSecondDerivativesType& ShapeFunctionsSecondDerivatives( ShapeFunctionsSecondDerivativesType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( rResult.size() != this->PointsNumber() )
        {
            // KLUDGE: While there is a bug in
            // ublas vector resize, I have to put this beside resizing!!
            ShapeFunctionsGradientsType temp( this->PointsNumber() );
            rResult.swap( temp );
        }

        rResult[0].resize( 2, 2 );
        rResult[1].resize( 2, 2 );
        rResult[2].resize( 2, 2 );
        rResult[3].resize( 2, 2 );
        rResult[4].resize( 2, 2 );
        rResult[5].resize( 2, 2 );

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

    ShapeFunctionsThirdDerivativesType& ShapeFunctionsThirdDerivatives( ShapeFunctionsThirdDerivativesType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( rResult.size() != this->PointsNumber() )
        {
            rResult.resize( this->PointsNumber() );
        }

        for ( IndexType i = 0; i < rResult.size(); i++ )
        {
            rResult[i].resize( this->PointsNumber() );
        }

        rResult[0][0].resize( 2, 2 );

        rResult[0][1].resize( 2, 2 );
        rResult[1][0].resize( 2, 2 );
        rResult[1][1].resize( 2, 2 );
        rResult[2][0].resize( 2, 2 );
        rResult[2][1].resize( 2, 2 );
        rResult[3][0].resize( 2, 2 );
        rResult[3][1].resize( 2, 2 );
        rResult[4][0].resize( 2, 2 );
        rResult[4][1].resize( 2, 2 );
        rResult[5][0].resize( 2, 2 );
        rResult[5][1].resize( 2, 2 );

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
     * There are no protected members in class Triangle3D6
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

    Triangle3D6(): BaseType( PointsArrayType(), &msGeometryData ) {}

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
     * Calculates the values of all shape function in all integration points.
     * Integration points are expected to be given in local coordinates
     * @param ThisMethod the current integration method
     * @return the matrix of values of every shape function in each integration point
     * :KLUDGE: number of points is hard-coded -> be careful if you want to copy and paste!
     */
    static Matrix CalculateShapeFunctionsIntegrationPointsValues(
        IntegrationMethod ThisMethod )
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
     * Calculates the local gradients of all shape functions
     * in all integration points.
     * Integration points are expected to be given in local coordinates
     *
     * @param ThisMethod the current integration method
     * @return the vector of the gradients of all shape functions
     * in each integration point
     */
    static ShapeFunctionsGradientsType CalculateShapeFunctionsIntegrationPointsLocalGradients(
        IntegrationMethod ThisMethod )
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
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Triangle3D6<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
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

    template<class TOtherPointType> friend class Triangle3D6;

    ///@}
    ///@name Un accessible methods
    ///@{

    ///@}
}; // Class Triangle3D6

///@}
///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

template<class TPointType> const
GeometryData Triangle3D6<TPointType>::msGeometryData(
    2, 3, 2,
    GeometryData::IntegrationMethod::GI_GAUSS_2,
    Triangle3D6<TPointType>::AllIntegrationPoints(),
    Triangle3D6<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

} // namespace Kratos.

#endif // KRATOS_TRIANGLE_3D_6_H_INCLUDED defined
