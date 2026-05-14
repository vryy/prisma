//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.7 $
//
//

#if !defined(KRATOS_LINE_3D_2_H_INCLUDED )
#define  KRATOS_LINE_3D_2_H_INCLUDED

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
class Line3D2 : public Geometry<TPointType>
{
public:
    ///@name Type Definitions
    ///@{

    /// Geometry as base class.
    typedef Geometry<TPointType> BaseType;

    /// Pointer definition of Line3D2
    KRATOS_CLASS_POINTER_DEFINITION( Line3D2 );

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

    Line3D2( const PointType& FirstPoint, const PointType& SecondPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        BaseType::Points().push_back( typename PointType::Pointer( new PointType( FirstPoint ) ) );
        BaseType::Points().push_back( typename PointType::Pointer( new PointType( SecondPoint ) ) );
    }

    Line3D2( typename PointType::Pointer pFirstPoint, typename PointType::Pointer pSecondPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        BaseType::Points().push_back( pFirstPoint );
        BaseType::Points().push_back( pSecondPoint );
    }

    Line3D2( const PointsArrayType& ThisPoints )
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
    Line3D2( Line3D2 const& rOther )
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
    template<class TOtherPointType> Line3D2( Line3D2<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    ~Line3D2() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Linear;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Line3D2;
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
    Line3D2& operator=( const Line3D2& rOther )
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
    Line3D2& operator=( Line3D2<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );

        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Line3D2( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < BaseType::Points().size() ; i++ )
            NewPoints.push_back( BaseType::Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Line3D2< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

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

    DataType Length() const override
    {
        const TPointType& point0 = BaseType::GetPoint(0);
        const TPointType& point1 = BaseType::GetPoint(1);
        const DataType lx = point0.X() - point1.X();
        const DataType ly = point0.Y() - point1.Y();
        const DataType lz = point0.Z() - point1.Z();

        const DataType length = lx * lx + ly * ly + lz * lz;

        return sqrt( length );
    }

    DataType Area() const override
    {
        return 0.00;
    }

    DataType DomainSize() const override
    {
        return Length();
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
        MatrixType jacobian( 3, 1 );
        jacobian( 0, 0 ) = ( this->GetPoint( 1 ).X() - this->GetPoint( 0 ).X() ) * 0.5; //on the Gauss points (J is constant at each element)
        jacobian( 1, 0 ) = ( this->GetPoint( 1 ).Y() - this->GetPoint( 0 ).Y() ) * 0.5;
        jacobian( 2, 0 ) = ( this->GetPoint( 1 ).Z() - this->GetPoint( 0 ).Z() ) * 0.5;

        if ( rResult.size() != BaseType::IntegrationPointsNumber( ThisMethod ) )
        {
            // KLUDGE: While there is a bug in ublas vector resize, I have to put this beside resizing!!
            JacobiansType temp( BaseType::IntegrationPointsNumber( ThisMethod ) );
            rResult.swap( temp );
        }

        std::fill( rResult.begin(), rResult.end(), jacobian );

        return rResult;
    }

    JacobiansType& Jacobian( JacobiansType& rResult, IntegrationMethod ThisMethod, const MatrixType& DeltaPosition ) const override
    {
        MatrixType jacobian( 3, 1 );
        jacobian( 0, 0 ) = ( (this->GetPoint( 1 ).X() - DeltaPosition(1,0)) - (this->GetPoint( 0 ).X() - DeltaPosition(0,0)) ) * 0.5; //on the Gauss points (J is constant at each element)
        jacobian( 1, 0 ) = ( (this->GetPoint( 1 ).Y() - DeltaPosition(1,1)) - (this->GetPoint( 0 ).Y() - DeltaPosition(0,1)) ) * 0.5;
        jacobian( 2, 0 ) = ( (this->GetPoint( 1 ).Z() - DeltaPosition(1,2)) - (this->GetPoint( 0 ).Z() - DeltaPosition(0,2)) ) * 0.5;

        if ( rResult.size() != BaseType::IntegrationPointsNumber( ThisMethod ) )
        {
            // KLUDGE: While there is a bug in ublas vector resize, I have to put this beside resizing!!
            JacobiansType temp( BaseType::IntegrationPointsNumber( ThisMethod ) );
            rResult.swap( temp );
        }

        std::fill( rResult.begin(), rResult.end(), jacobian );

        return rResult;
    }

    MatrixType& Jacobian( MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        rResult.resize( 3, 1, false );
        //on the Gauss points (J is constant at each element)
        rResult( 0, 0 ) = ( this->GetPoint( 1 ).X() - this->GetPoint( 0 ).X() ) * 0.5;
        rResult( 1, 0 ) = ( this->GetPoint( 1 ).Y() - this->GetPoint( 0 ).Y() ) * 0.5;
        rResult( 2, 0 ) = ( this->GetPoint( 1 ).Z() - this->GetPoint( 0 ).Z() ) * 0.5;
        return rResult;
    }

    MatrixType& Jacobian( MatrixType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        rResult.resize( 3, 1, false );
        //on the Gauss points (J is constant at each element)
        rResult( 0, 0 ) = ( this->GetPoint( 1 ).X() - this->GetPoint( 0 ).X() ) * 0.5;
        rResult( 1, 0 ) = ( this->GetPoint( 1 ).Y() - this->GetPoint( 0 ).Y() ) * 0.5;
        rResult( 2, 0 ) = ( this->GetPoint( 1 ).Z() - this->GetPoint( 0 ).Z() ) * 0.5;
        return rResult;
    }

    VectorType& DeterminantOfJacobian( VectorType& rResult, IntegrationMethod ThisMethod ) const override
    {
        rResult = ZeroVector( 1 );
        rResult[0] = 0.5 * MathUtils<DataType>::Norm3(( this->GetPoint( 1 ) ) - ( this->GetPoint( 0 ) ) );
        return rResult;
    }

    DataType DeterminantOfJacobian( IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        return( 0.5*MathUtils<DataType>::Norm3(( this->GetPoint( 1 ) ) - ( this->GetPoint( 0 ) ) ) );
    }

    DataType DeterminantOfJacobian( const LocalCoordinatesArrayType& rPoint ) const override
    {
        return( 0.5*MathUtils<DataType>::Norm3(( this->GetPoint( 1 ) ) - ( this->GetPoint( 0 ) ) ) );
    }

    JacobiansType& InverseOfJacobian( JacobiansType& rResult, IntegrationMethod ThisMethod ) const override
    {
        rResult[0] = ZeroMatrix( 1, 1 );
        rResult[0]( 0, 0 ) = 2.0 * MathUtils<DataType>::Norm3(( this->GetPoint( 1 ) ) - ( this->GetPoint( 0 ) ) );
        return rResult;
    }

    MatrixType& InverseOfJacobian( MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod ) const override
    {
        rResult = ZeroMatrix( 1, 1 );
        rResult( 0, 0 ) = 2.0 * MathUtils<DataType>::Norm3(( this->GetPoint( 1 ) ) - ( this->GetPoint( 0 ) ) );
        return( rResult );
    }

    MatrixType& InverseOfJacobian( MatrixType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        rResult = ZeroMatrix( 1, 1 );
        rResult( 0, 0 ) = 2.0 * MathUtils<DataType>::Norm3(( this->GetPoint( 1 ) ) - ( this->GetPoint( 0 ) ) );
        return( rResult );
    }

    SizeType EdgesNumber() const override
    {
        return 2; // TODO check
    }

    SizeType FacesNumber() const override
    {
        return 2; // TODO check
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
            return( 0.5*( 1.0 - rPoint[0] ) );

        case 1:
            return( 0.5*( 1.0 + rPoint[0] ) );

        default:
            KRATOS_ERROR << "Wrong index of shape function!";
        }

        return 0;
    }

    Matrix& ShapeFunctionsLocalGradients( Matrix& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        rResult = ZeroMatrix( 2, 1 );
        rResult( 0, 0 ) = -0.5;
        rResult( 1, 0 ) =  0.5;
        return( rResult );
    }

    ShapeFunctionsIntegrationPointsGradientsType& ShapeFunctionsIntegrationPointsGradients(
        ShapeFunctionsIntegrationPointsGradientsType& rResult, IntegrationMethod ThisMethod ) const override
    {
        KRATOS_ERROR << "Not yet implemented";
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

        rResult[0].resize( 1, 1 );
        rResult[1].resize( 1, 1 );

        rResult[0]( 0, 0 ) = 0.0;
        rResult[1]( 0, 0 ) = 0.0;

        return rResult;
    }

    ShapeFunctionsThirdDerivativesType& ShapeFunctionsThirdDerivatives( ShapeFunctionsThirdDerivativesType& rResult, const LocalCoordinatesArrayType& rPoint ) const override
    {
        if ( rResult.size() != this->PointsNumber() )
        {
            // KLUDGE: While there is a bug in
            // ublas vector resize, I have to put this beside resizing!!
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

    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if (rResult.size1() != 2 || rResult.size2() != 1)
            rResult.resize( 2, 1, false );
        rResult( 0, 0 ) = -1.0;
        rResult( 1, 0 ) =  1.0;
        return rResult;
    }

    std::string Info() const override
    {
        return "1 dimensional line with 2 nodes in 3D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "1 dimensional line with 2 nodes in 3D space";
    }

    void PrintData( std::ostream& rOStream ) const override
    {
        BaseType::PrintData( rOStream );
        std::cout << std::endl;
        MatrixType jacobian;
        this->Jacobian( jacobian, LocalCoordinatesArrayType() );
        rOStream << "    Jacobian\t : " << jacobian;
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

    Line3D2(): BaseType( PointsArrayType(), &msGeometryData ) {}

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
            // DataType e = IntegrationPoints[it_gp].X();
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
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_1 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_2 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_3 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_4 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsValues( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_5 ),
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients = {{
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_1 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_2 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_3 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_4 ),
                Line3D2<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_EXTENDED_GAUSS_5 ),
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

    template<class TOtherPointType> friend class Line3D2;

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
const GeometryData Line3D2<TPointType>::msGeometryData( 3,
        3,
        1,
        GeometryData::IntegrationMethod::GI_GAUSS_1,
        Line3D2<TPointType>::AllIntegrationPoints(),
        Line3D2<TPointType>::AllShapeFunctionsValues(),
        AllShapeFunctionsLocalGradients() );

}  // namespace Kratos.

#endif // KRATOS_LINE_3D_2_H_INCLUDED  defined
