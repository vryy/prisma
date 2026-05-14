//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.6 $
//
//

#if !defined(KRATOS_TRIANGLE_3D_3_H_INCLUDED )
#define  KRATOS_TRIANGLE_3D_3_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/line_3d_2.h"
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
template<class TPointType> class Triangle3D3 : public Geometry<TPointType>
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
    typedef Line3D2<TPointType> EdgeType;

    /**
     * Pointer definition of Triangle3D3
     */
    KRATOS_CLASS_POINTER_DEFINITION( Triangle3D3 );

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

    Triangle3D3( const PointType& FirstPoint,
                 const PointType& SecondPoint,
                 const PointType& ThirdPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().push_back( typename PointType::Pointer( new PointType( FirstPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( SecondPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( ThirdPoint ) ) );
    }

    Triangle3D3( typename PointType::Pointer pFirstPoint,
                 typename PointType::Pointer pSecondPoint,
                 typename PointType::Pointer pThirdPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().push_back( pFirstPoint );
        this->Points().push_back( pSecondPoint );
        this->Points().push_back( pThirdPoint );
    }

    Triangle3D3( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 3 )
            KRATOS_THROW_ERROR( std::invalid_argument,
                          "Invalid points number. Expected 3, given " , this->PointsNumber() );
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
    Triangle3D3( Triangle3D3 const& rOther )
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
    template<class TOtherPointType> Triangle3D3( Triangle3D3<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    ~Triangle3D3() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Triangle;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Triangle3D3;
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
    Triangle3D3& operator=( const Triangle3D3& rOther )
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
    Triangle3D3& operator=( Triangle3D3<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );
        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Triangle3D3( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Triangle3D3< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if (rResult.size1() != 3 || rResult.size2() != 2)
            rResult.resize( 3, 2, false );
        rResult( 0, 0 ) =  0.0;
        rResult( 0, 1 ) =  0.0;
        rResult( 1, 0 ) =  1.0;
        rResult( 1, 1 ) =  0.0;
        rResult( 2, 0 ) =  0.0;
        rResult( 2, 1 ) =  1.0;
        return rResult;
    }

    Vector& LumpingFactors( Vector& rResult ) const override
    {
        rResult.resize( 3, false );
        std::fill( rResult.begin(), rResult.end(), 1.00 / 3.00 );
        return rResult;
    }

    ///@}
    ///@name Information
    ///@{

    DataType Length() const override
    {
        return std::sqrt( 2.0 * Area() );
    }

    DataType Area() const override
    {
        //heron formula
        VectorType side_a = ( this->GetPoint( 0 ) - this->GetPoint( 1 ) );
        DataType a = MathUtils<DataType>::Norm3( side_a );
        VectorType side_b = ( this->GetPoint( 1 ) - this->GetPoint( 2 ) );
        DataType b = MathUtils<DataType>::Norm3( side_b );
        VectorType side_c = ( this->GetPoint( 2 ) - this->GetPoint( 0 ) );
        DataType c = MathUtils<DataType>::Norm3( side_c );
        DataType s = ( a + b + c ) / 2;
        return( std::sqrt( s*( s - a )*( s - b )*( s - c ) ) );
    }

    DataType DomainSize() const override
    {
        return( Area() );
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
        array_1d<DataType,3> CurrentGlobalCoords;

        //Newton iteration:
        for ( int k = 0; k < maxiter; k++ )
        {
            noalias(CurrentGlobalCoords) = ZeroVector( 3 );
            this->GlobalCoordinates( CurrentGlobalCoords, rResult );

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

    LocalCoordinatesArrayType& PointLocalCoordinates( LocalCoordinatesArrayType& rResult, const CoordinatesArrayType& rPoint,
        const MatrixType& DeltaPosition, const bool force_error = true, const ValueType tol = 1.0e-8 ) const override
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

        MatrixType J = ZeroMatrix( 2, 2 );
        MatrixType invJ = ZeroMatrix( 2, 2 );

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
        KRATOS_ERROR << "Jacobian is not square" ;
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

    SizeType EdgesNumber() const override
    {
        return 3;
    }

    GeometriesArrayType Edges() const override
    {
        GeometriesArrayType edges = GeometriesArrayType();

        edges.push_back( EdgeType( this->pGetPoint( 0 ), this->pGetPoint( 1 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 1 ), this->pGetPoint( 2 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 2 ), this->pGetPoint( 0 ) ) );

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

    ///@}
    ///@name Shape Function
    ///@{

    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex, const LocalCoordinatesArrayType& rPoint ) const override
    {
        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( 1.0 -rPoint[0] - rPoint[1] );
        case 1:
            return( rPoint[0] );
        case 2:
            return( rPoint[1] );
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
            rResult[pnt].resize( 3, 2 );

            for ( int i = 0; i < 3; i++ )
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
        return "2 dimensional triangle with three nodes in 3D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "2 dimensional triangle with three nodes in 3D space";
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
        rResult.resize( 3, 2 );
        noalias( rResult ) = ZeroMatrix( 3, 2 );
        rResult( 0, 0 ) = -1.0;
        rResult( 0, 1 ) = -1.0;
        rResult( 1, 0 ) =  1.0;
        rResult( 1, 1 ) =  0.0;
        rResult( 2, 0 ) =  0.0;
        rResult( 2, 1 ) =  1.0;
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
        rResult[0]( 0, 0 ) = 0.0;
        rResult[0]( 0, 1 ) = 0.0;
        rResult[0]( 1, 0 ) = 0.0;
        rResult[0]( 1, 1 ) = 0.0;
        rResult[1]( 0, 0 ) = 0.0;
        rResult[1]( 0, 1 ) = 0.0;
        rResult[1]( 1, 0 ) = 0.0;
        rResult[1]( 1, 1 ) = 0.0;
        rResult[2]( 0, 0 ) = 0.0;
        rResult[2]( 0, 1 ) = 0.0;
        rResult[2]( 1, 0 ) = 0.0;
        rResult[2]( 1, 1 ) = 0.0;
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

        rResult[0][0].resize( 2, 2 );

        rResult[0][1].resize( 2, 2 );
        rResult[1][0].resize( 2, 2 );
        rResult[1][1].resize( 2, 2 );
        rResult[2][0].resize( 2, 2 );
        rResult[2][1].resize( 2, 2 );

        for ( int i = 0; i < 3; i++ )
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
     * There are no protected members in class Triangle3D3
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

    Triangle3D3() : BaseType( PointsArrayType(), &msGeometryData ) {}

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
        const int points_number = 3;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            row( shape_function_values, pnt )[0] = 1.0
                                                   - integration_points[pnt].X()
                                                   - integration_points[pnt].Y();
            row( shape_function_values, pnt )[1] = integration_points[pnt].X();
            row( shape_function_values, pnt )[2] = integration_points[pnt].Y();
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
            Matrix result( 3, 2 );
            result( 0, 0 ) = -1.0;
            result( 0, 1 ) = -1.0;
            result( 1, 0 ) =  1.0;
            result( 1, 1 ) =  0.0;
            result( 2, 0 ) =  0.0;
            result( 2, 1 ) =  1.0;
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
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Triangle3D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
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

    template<class TOtherPointType> friend class Triangle3D3;

    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}
}; // Class Triangle3D3

///@}
///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

template<class TPointType> const
GeometryData Triangle3D3<TPointType>::msGeometryData(
    2, 3, 2,
    GeometryData::IntegrationMethod::GI_GAUSS_1,
    Triangle3D3<TPointType>::AllIntegrationPoints(),
    Triangle3D3<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

} // namespace Kratos.

#endif // KRATOS_QUADRILATERAL_3D_4_H_INCLUDED  defined
