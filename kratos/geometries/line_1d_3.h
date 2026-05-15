//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   Hoang-Giang Bui $
//   Date:                $Date:   January 2026 $
//
//

#if !defined(KRATOS_LINE_1D_3_H_INCLUDED )
#define  KRATOS_LINE_1D_3_H_INCLUDED

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

template<class TPointType>
class Line1D3 : public Geometry<TPointType>
{
public:
    ///@name Type Definitions
    ///@{

    /// Geometry as base class.
    typedef Geometry<TPointType> BaseType;

    /// Pointer definition of Line1D3
    KRATOS_CLASS_POINTER_DEFINITION( Line1D3 );

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

    Line1D3( const PointType& FirstPoint, const PointType& SecondPoint, const PointType& ThirdPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        BaseType::Points().push_back( typename PointType::Pointer( new PointType( FirstPoint ) ) );
        BaseType::Points().push_back( typename PointType::Pointer( new PointType( SecondPoint ) ) );
        BaseType::Points().push_back( typename PointType::Pointer( new PointType( ThirdPoint ) ) );
    }

    Line1D3( typename PointType::Pointer pFirstPoint, typename PointType::Pointer pSecondPoint,
             typename PointType::Pointer pThirdPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        BaseType::Points().push_back( pFirstPoint );
        BaseType::Points().push_back( pSecondPoint );
        BaseType::Points().push_back( pThirdPoint );
    }

    Line1D3( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( BaseType::PointsNumber() != 3 )
            KRATOS_ERROR << "Invalid points number. Expected 3, given " << BaseType::PointsNumber();
    }

    /** Copy constructor.
     * Construct this geometry as a copy of given geometry.
     * @note This copy constructor don't copy the points and new
     * geometry shares points with given source geometry. It's
     * obvious that any change to this new geometry's point affect
     * source geometry's points too.
     */
    Line1D3( Line1D3 const& rOther )
        : BaseType( rOther )
    {
    }

    /** Copy constructor from a geometry with other point type.
     * Construct this geometry as a copy of given geometry which
     * has different type of points. The given goemetry's
     * TOtherPointType* must be implicity convertible to this
     * geometry PointType.
     * @note This copy constructor don't copy the points and new
     * geometry shares points with given source geometry. It's
     * obvious that any change to this new geometry's point affect
     * source geometry's points too.
     */
    template<class TOtherPointType> Line1D3( Line1D3<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    ~Line1D3() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Linear;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Line1D3;
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
    Line1D3& operator=( const Line1D3& rOther )
    {
        BaseType::operator=( rOther );
        return *this;
    }

    /** Assignment operator for geometries with different point type.
     * @note This operator don't copy the points and this
     * geometry shares points with given source geometry. It's
     * obvious that any change to this geometry's point affect
     * source geometry's points too.
     * @see Clone
     * @see ClonePoints
     */
    template<class TOtherPointType>
    Line1D3& operator=( Line1D3<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );
        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
      // line 3 conectivities order 1-3-2
      return typename BaseType::Pointer( new Line1D3( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < BaseType::Points().size() ; i++ )
            NewPoints.push_back( BaseType::Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Line1D3< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 3)
           rResult.resize( 3, false );
        rResult[0] = 0.25;
        rResult[2] = 0.5;
        rResult[1] = 0.25;
        return rResult;
    }

    ///@}
    ///@name Informations
    ///@{

    DataType Length() const override
    {
        const TPointType& point0 = BaseType::GetPoint(0);
        const TPointType& point1 = BaseType::GetPoint(2);
        const DataType lx = point0.X() - point1.X();
        const DataType ly = point0.Y() - point1.Y();

        const DataType length = lx * lx + ly * ly;

        return sqrt( length );
    }

    DataType Area() const override
    {
        return 0.00;
    }

    DataType DomainSize() const override
    {
        const TPointType& point0 = BaseType::GetPoint(0);
        const TPointType& point1 = BaseType::GetPoint(2);
        const DataType lx = point0.X() - point1.X();

        return std::abs( lx );
    }

    bool IsInside( const LocalCoordinatesArrayType& rPoint, const ValueType tol ) const override
    {
        if ( std::abs( rPoint[0] ) < 1 + tol )
            return true;

        return false;
    }

    ///@}
    ///@name Jacobian
    ///@{

    JacobiansType& Jacobian( JacobiansType& rResult, IntegrationMethod ThisMethod ) const override
    {
        //getting derivatives of shape functions
        ShapeFunctionsGradientsType shape_functions_gradients =
            CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );

        //getting values of shape functions
        MatrixType shape_functions_values =
            CalculateShapeFunctionsIntegrationPointsValues( ThisMethod );

        if ( rResult.size() != this->IntegrationPointsNumber( ThisMethod ) )
        {
            JacobiansType temp( this->IntegrationPointsNumber( ThisMethod ) );
            rResult.swap( temp );
        }

        //loop over all integration points
        for ( unsigned int pnt = 0; pnt < this->IntegrationPointsNumber( ThisMethod ); ++pnt )
        {
            //defining single jacobian matrix
            MatrixType jacobian = ZeroMatrix( 1, 1 );

            //loop over all nodes
            for ( unsigned int i = 0; i < this->PointsNumber(); ++i )
            {
                jacobian( 0, 0 ) += ( this->GetPoint( i ).X() ) * ( shape_functions_gradients[pnt]( i, 0 ) );
            }

            rResult[pnt] = jacobian;
        } //end of loop over all integration points

        return rResult;
    }

    JacobiansType& Jacobian( JacobiansType& rResult, IntegrationMethod ThisMethod, const MatrixType& DeltaPosition ) const override
    {
        //getting derivatives of shape functions
        ShapeFunctionsGradientsType shape_functions_gradients =
            CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );

        //getting values of shape functions
        MatrixType shape_functions_values =
            CalculateShapeFunctionsIntegrationPointsValues( ThisMethod );

        if ( rResult.size() != this->IntegrationPointsNumber( ThisMethod ) )
        {
            JacobiansType temp( this->IntegrationPointsNumber( ThisMethod ) );
            rResult.swap( temp );
        }

        //loop over all integration points
        for ( unsigned int pnt = 0; pnt < this->IntegrationPointsNumber( ThisMethod ); ++pnt )
        {
            //defining single jacobian matrix
            MatrixType jacobian = ZeroMatrix( 1, 1 );

            //loop over all nodes
            for ( unsigned int i = 0; i < this->PointsNumber(); ++i )
            {
                jacobian( 0, 0 ) += ( this->GetPoint( i ).X() + DeltaPosition(i, 0) ) * ( shape_functions_gradients[pnt]( i, 0 ) );
            }

            rResult[pnt] = jacobian;
        } //end of loop over all integration points

        return rResult;
    }

    MatrixType& Jacobian( MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        //setting up size of jacobian matrix
        rResult.resize( 1, 1 );
        //derivatives of shape functions
        ShapeFunctionsGradientsType shape_functions_gradients =
            CalculateShapeFunctionsIntegrationPointsLocalGradients( ThisMethod );
        MatrixType ShapeFunctionsGradientInIntegrationPoint =
            shape_functions_gradients( IntegrationPointIndex );

        //values of shape functions in integration points
        vector<double> ShapeFunctionValuesInIntegrationPoint = ZeroVector( 3 );
        ShapeFunctionValuesInIntegrationPoint = row( CalculateShapeFunctionsIntegrationPointsValues( ThisMethod ),
                                                IntegrationPointIndex );

        //Elements of jacobian matrix (e.g. J(1,1) = dX1/dXi1)
        double j0 = 0.0;
        //loop over all nodes
        for ( unsigned int i = 0; i < this->PointsNumber(); ++i )
        {
            j0 += ( this->GetPoint( i ).X() ) * ( ShapeFunctionsGradientInIntegrationPoint( i, 0 ) );
        }

        rResult( 0, 0 ) = j0;

        return rResult;
    }

    MatrixType& Jacobian( MatrixType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        //setting up size of jacobian matrix
        rResult.resize( 1, 1 );

        //derivatives of shape functions
        MatrixType shape_functions_gradients;
        shape_functions_gradients = ShapeFunctionsLocalGradients( shape_functions_gradients, rPoint );

        //Elements of jacobian matrix (e.g. J(1,1) = dX1/dXi1)
        double j0 = 0.0;

        //loop over all nodes
        for ( unsigned int i = 0; i < this->PointsNumber(); ++i )
        {
            j0 += ( this->GetPoint( i ).X() ) * ( shape_functions_gradients( i, 0 ) );
        }

        rResult( 0, 0 ) = j0;

        return rResult;
    }

    SizeType EdgesNumber() const override
    {
        return 1;
    }

    ///@}
    ///@name Shape Function
    ///@{

    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex,
                                  const LocalCoordinatesArrayType& rPoint ) const override
    {
        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( 0.5*( rPoint[0] - 1.0 )*rPoint[0] );
        case 1:
            return( 0.5*( rPoint[0] + 1.0 )*rPoint[0] );
        case 2:
            return( 1.0 -rPoint[0]*rPoint[0] );
        default:
            KRATOS_ERROR << "Wrong index of shape function!";
        }

        return 0;
    }

    ShapeFunctionsIntegrationPointsGradientsType& ShapeFunctionsIntegrationPointsGradients( ShapeFunctionsIntegrationPointsGradientsType& rResult, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_ERROR << "Not yet implemented";
        return rResult;
    }

    ///@}
    ///@name Input and output
    ///@{

    std::string Info() const override
    {
        return "1 dimensional line with 3 nodes in 1D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "1 dimensional line with 3 nodes in 1D space";
    }

    void PrintData( std::ostream& rOStream ) const override
    {
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian\t : " << jacobian;
    }

    Matrix& ShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        //setting up result matrix
        rResult.resize( 3, 1 );
        noalias( rResult ) = ZeroMatrix( 3, 1 );
        rResult( 0, 0 ) = rPoint[0] - 0.5;
        rResult( 2, 0 ) = -2.0 * rPoint[0];
        rResult( 1, 0 ) = rPoint[0] + 0.5;
        return( rResult );
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

        rResult[0].resize( 1, 1 );
        rResult[1].resize( 1, 1 );
        rResult[2].resize( 1, 1 );

        rResult[0]( 0, 0 ) = 1.0;
        rResult[2]( 0, 0 ) = -2.0;
        rResult[1]( 0, 0 ) = 1.0;

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

        rResult[0][0].resize( 1, 1, false );
        rResult[1][0].resize( 1, 1, false );
        rResult[2][0].resize( 1, 1, false );

        for ( int i = 0; i < 3; i++ )
        {
            rResult[i][0]( 0, 0 ) = 0.0;
        }

        return rResult;
    }

    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if (rResult.size1() != 3 || rResult.size2() != 1)
            rResult.resize( 3, 1, false );
        rResult( 0, 0 ) = -1.0;
        rResult( 2, 0 ) =  0.0;
        rResult( 1, 0 ) =  1.0;
        return rResult;
    }

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

    Line1D3(): BaseType( PointsArrayType(), &msGeometryData ) {}

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
        Matrix N( integration_points_number, 3 );

        for ( int it_gp = 0; it_gp < integration_points_number; it_gp++ )
        {
            ValueType e = IntegrationPoints[it_gp].X();
            N( it_gp, 0 ) = 0.5 * ( e - 1 ) * e;
            N( it_gp, 2 ) = 1.0 - e * e;
            N( it_gp, 1 ) = 0.5 * ( 1 + e ) * e;
        }

        return N;
    }

    static ShapeFunctionsGradientsType CalculateShapeFunctionsIntegrationPointsLocalGradients(
        typename BaseType::IntegrationMethod ThisMethod )
    {
        const IntegrationPointsContainerType& all_integration_points = AllIntegrationPoints();
        const IntegrationPointsArrayType& IntegrationPoints = all_integration_points[static_cast<int>(ThisMethod)];
        ShapeFunctionsGradientsType DN_De( IntegrationPoints.size() );
        std::fill( DN_De.begin(), DN_De.end(), Matrix( 3, 1 ) );

        for ( unsigned int it_gp = 0; it_gp < IntegrationPoints.size(); it_gp++ )
        {
            ValueType e = IntegrationPoints[it_gp].X();
            DN_De[it_gp]( 0, 0 ) = e - 0.5;
            DN_De[it_gp]( 2, 0 ) = -2.0 * e;
            DN_De[it_gp]( 1, 0 ) = e + 0.5;
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
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_1 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_2 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_3 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_4 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_5 ),
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients = {{
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_1 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_2 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_3 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_4 ),
                Line1D3<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_5 ),
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

    template<class TOtherPointType> friend class Line1D3;

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
const GeometryData Line1D3<TPointType>::msGeometryData( 1,
        1,
        1,
        GeometryData::IntegrationMethod::GI_GAUSS_2,
        Line1D3<TPointType>::AllIntegrationPoints(),
        Line1D3<TPointType>::AllShapeFunctionsValues(),
        AllShapeFunctionsLocalGradients() );

}  // namespace Kratos.

#endif // KRATOS_LINE_1D_3_H_INCLUDED  defined
