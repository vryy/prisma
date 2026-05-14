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


#if !defined(KRATOS_QUADRILATERAL_2D_4_H_INCLUDED )
#define  KRATOS_QUADRILATERAL_2D_4_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/line_2d_2.h"
#include "integration/quadrilateral_gauss_legendre_integration_points.h"



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
template<class TPointType> class Quadrilateral2D4 : public Geometry<TPointType>
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
    typedef Line2D2<TPointType> EdgeType;

    /**
     * Pointer definition of Quadrilateral2D4
     */
    KRATOS_CLASS_POINTER_DEFINITION( Quadrilateral2D4 );

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

    Quadrilateral2D4( const PointType& FirstPoint,
                      const PointType& SecondPoint,
                      const PointType& ThirdPoint,
                      const PointType& FourthPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().push_back( typename PointType::Pointer( new PointType( FirstPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( SecondPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( ThirdPoint ) ) );
        this->Points().push_back( typename PointType::Pointer( new PointType( FourthPoint ) ) );
    }

    Quadrilateral2D4( typename PointType::Pointer pFirstPoint,
                      typename PointType::Pointer pSecondPoint,
                      typename PointType::Pointer pThirdPoint,
                      typename PointType::Pointer pFourthPoint )
        : BaseType( PointsArrayType(), &msGeometryData )
    {
        this->Points().push_back( pFirstPoint );
        this->Points().push_back( pSecondPoint );
        this->Points().push_back( pThirdPoint );
        this->Points().push_back( pFourthPoint );
    }

    Quadrilateral2D4( const PointsArrayType& ThisPoints )
        : BaseType( ThisPoints, &msGeometryData )
    {
        if ( this->PointsNumber() != 4 )
            KRATOS_ERROR << "Invalid points number. Expected 4, given " << this->PointsNumber();
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
    Quadrilateral2D4( Quadrilateral2D4 const& rOther )
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
    template<class TOtherPointType> Quadrilateral2D4( Quadrilateral2D4<TOtherPointType> const& rOther )
        : BaseType( rOther )
    {
    }

    ~Quadrilateral2D4() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Quadrilateral;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Quadrilateral2D4;
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
    Quadrilateral2D4& operator=( const Quadrilateral2D4& rOther )
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
    Quadrilateral2D4& operator=( Quadrilateral2D4<TOtherPointType> const & rOther )
    {
        BaseType::operator=( rOther );
        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create( PointsArrayType const& ThisPoints ) const override
    {
        return typename BaseType::Pointer( new Quadrilateral2D4( ThisPoints ) );
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for ( IndexType i = 0 ; i < this->Points().size() ; i++ )
            NewPoints.push_back( this->Points()[i] );

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone( new Quadrilateral2D4< Point<3, DataType> >( NewPoints ) );

        p_clone->ClonePoints();

        return p_clone;
    }

    Matrix& PointsLocalCoordinates( Matrix& rResult ) const override
    {
        if (rResult.size1() != 4 || rResult.size2() != 2)
            rResult.resize( 4, 2, false );
        rResult( 0, 0 ) = -1.0;
        rResult( 0, 1 ) = -1.0;
        rResult( 1, 0 ) =  1.0;
        rResult( 1, 1 ) = -1.0;
        rResult( 2, 0 ) =  1.0;
        rResult( 2, 1 ) =  1.0;
        rResult( 3, 0 ) = -1.0;
        rResult( 3, 1 ) =  1.0;
        return rResult;
    }

    Vector& LumpingFactors( Vector& rResult ) const override
    {
        if(rResult.size() != 4)
            rResult.resize( 4, false );
        std::fill( rResult.begin(), rResult.end(), 1.00 / 4.00 );
        return rResult;
    }

    ///@}
    ///@name Information
    ///@{

    DataType Length() const override
    {
        //return sqrt(std::abs( DeterminantOfJacobian(PointType())));
        DataType length = 0.000;
        length = std::sqrt( std::abs( Area() ) );
        return length;

    }

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

    SizeType EdgesNumber() const override
    {
        return 4;
    }

    GeometriesArrayType Edges() const override
    {
        GeometriesArrayType edges = GeometriesArrayType();
        edges.push_back( EdgeType( this->pGetPoint( 0 ), this->pGetPoint( 1 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 1 ), this->pGetPoint( 2 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 2 ), this->pGetPoint( 3 ) ) );
        edges.push_back( EdgeType( this->pGetPoint( 3 ), this->pGetPoint( 0 ) ) );
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

    ValueType ShapeFunctionValue( IndexType ShapeFunctionIndex, const LocalCoordinatesArrayType& rPoint ) const override
    {
        switch ( ShapeFunctionIndex )
        {
        case 0:
            return( 0.25*( 1.0 - rPoint[0] )*( 1.0 - rPoint[1] ) );
        case 1:
            return( 0.25*( 1.0 + rPoint[0] )*( 1.0 - rPoint[1] ) );
        case 2:
            return( 0.25*( 1.0 + rPoint[0] )*( 1.0 + rPoint[1] ) );
        case 3:
            return( 0.25*( 1.0 - rPoint[0] )*( 1.0 + rPoint[1] ) );
        default:
            KRATOS_ERROR << "Invalid index " << ShapeFunctionIndex << " of shape function!";
        }

        return 0;
    }

    ///@}
    ///@name Input and output
    ///@{

    std::string Info() const override
    {
        return "2 dimensional quadrilateral with four nodes in 2D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "2 dimensional quadrilateral with four nodes in 2D space";
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
        rResult.resize( 4, 2 );
        noalias( rResult ) = ZeroMatrix( 4, 2 );
        rResult( 0, 0 ) = -0.25 * ( 1.0 - rPoint[1] );
        rResult( 0, 1 ) = -0.25 * ( 1.0 - rPoint[0] );
        rResult( 1, 0 ) =  0.25 * ( 1.0 - rPoint[1] );
        rResult( 1, 1 ) = -0.25 * ( 1.0 + rPoint[0] );
        rResult( 2, 0 ) =  0.25 * ( 1.0 + rPoint[1] );
        rResult( 2, 1 ) =  0.25 * ( 1.0 + rPoint[0] );
        rResult( 3, 0 ) = -0.25 * ( 1.0 + rPoint[1] );
        rResult( 3, 1 ) =  0.25 * ( 1.0 - rPoint[0] );
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

        rResult[0]( 0, 0 ) = 0.0;
        rResult[0]( 0, 1 ) = 0.25;
        rResult[0]( 1, 0 ) = 0.25;
        rResult[0]( 1, 1 ) = 0.0;

        rResult[1]( 0, 0 ) = 0.0;
        rResult[1]( 0, 1 ) = -0.25;
        rResult[1]( 1, 0 ) = -0.25;
        rResult[1]( 1, 1 ) = 0.0;

        rResult[2]( 0, 0 ) = 0.0;
        rResult[2]( 0, 1 ) = 0.25;
        rResult[2]( 1, 0 ) = 0.25;
        rResult[2]( 1, 1 ) = 0.0;

        rResult[3]( 0, 0 ) = 0.0;
        rResult[3]( 0, 1 ) = -0.25;
        rResult[3]( 1, 0 ) = -0.25;
        rResult[3]( 1, 1 ) = 0.0;

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

        for ( unsigned int i = 0; i < this->PointsNumber(); i++ )
        {
            for ( unsigned int j = 0; j < 2; j++ )
            {
                rResult[i][j].resize( 2, 2 );
                noalias( rResult[i][j] ) = ZeroMatrix( 2, 2 );
            }
        }

        for ( int i = 0; i < 4; i++ )
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
     * There are no protected members in class Quadrilateral2D4
     */

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

    Quadrilateral2D4(): BaseType( PointsArrayType(), &msGeometryData ) {}

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
        typename BaseType::IntegrationMethod ThisMethod )
    {
        IntegrationPointsContainerType all_integration_points =
            AllIntegrationPoints();
        IntegrationPointsArrayType integration_points =
            all_integration_points[static_cast<int>(ThisMethod)];
        //number of integration points
        const int integration_points_number = integration_points.size();
        //number of nodes in current geometry
        const int points_number = 4;
        //setting up return matrix
        Matrix shape_function_values( integration_points_number, points_number );
        //loop over all integration points

        for ( int pnt = 0; pnt < integration_points_number; pnt++ )
        {
            shape_function_values( pnt, 0 ) =
                0.25 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() );
            shape_function_values( pnt, 1 ) =
                0.25 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 - integration_points[pnt].Y() );
            shape_function_values( pnt, 2 ) =
                0.25 * ( 1.0 + integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() );
            shape_function_values( pnt, 3 ) =
                0.25 * ( 1.0 - integration_points[pnt].X() )
                * ( 1.0 + integration_points[pnt].Y() );
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
            Matrix result( 4, 2 );
            result( 0, 0 ) = -0.25 * ( 1.0 - integration_points[pnt].Y() );
            result( 0, 1 ) = -0.25 * ( 1.0 - integration_points[pnt].X() );
            result( 1, 0 ) = 0.25 * ( 1.0 - integration_points[pnt].Y() );
            result( 1, 1 ) = -0.25 * ( 1.0 + integration_points[pnt].X() );
            result( 2, 0 ) = 0.25 * ( 1.0 + integration_points[pnt].Y() );
            result( 2, 1 ) = 0.25 * ( 1.0 + integration_points[pnt].X() );
            result( 3, 0 ) = -0.25 * ( 1.0 + integration_points[pnt].Y() );
            result( 3, 1 ) = 0.25 * ( 1.0 - integration_points[pnt].X() );
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
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(
                    GeometryData::IntegrationMethod::GI_GAUSS_5 )
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType
    AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients =
        {
            {
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_1 ),
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_2 ),
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_3 ),
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_4 ),
                Quadrilateral2D4<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients( GeometryData::IntegrationMethod::GI_GAUSS_5 )
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

    template<class TOtherPointType> friend class Quadrilateral2D4;

    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}
}; // Class Quadrilateral2D4

///@}
///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

template<class TPointType> const
GeometryData Quadrilateral2D4<TPointType>::msGeometryData(
    2, 2, 2,
    GeometryData::IntegrationMethod::GI_GAUSS_2,
    Quadrilateral2D4<TPointType>::AllIntegrationPoints(),
    Quadrilateral2D4<TPointType>::AllShapeFunctionsValues(),
    AllShapeFunctionsLocalGradients()
);

} // namespace Kratos.

#endif // KRATOS_QUADRILATERAL_2D_4_H_INCLUDED  defined
