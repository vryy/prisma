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
    ///@name Type Definitions
    ///@{

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

    ~Prism3D6() override {}

    GeometryData::KratosGeometryFamily GetGeometryFamily() const final
    {
        return GeometryData::KratosGeometryFamily::Kratos_Prism;
    }

    GeometryData::KratosGeometryType GetGeometryType() const final
    {
        return GeometryData::KratosGeometryType::Kratos_Prism3D6;
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

    ///@}
    ///@name Operations
    ///@{

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

    DataType DomainSize() const override
    {
        return std::abs( this->DeterminantOfJacobian( LocalCoordinatesArrayType() ) ) * 0.5;
    }

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

    bool IsInside( const LocalCoordinatesArrayType& rPoint, const ValueType tol ) const override
    {
        if ( rPoint[0] >= 0.0 - tol && rPoint[0] <= 1.0 + tol )
            if ( rPoint[1] >= 0.0 - tol && rPoint[1] <= 1.0 + tol )
                if ( rPoint[2] >= 0.0 - tol && rPoint[2] <= 1.0 + tol )
                    if ((( 1.0 - ( rPoint[0] + rPoint[1] ) ) >= 0.0 - tol ) && (( 1.0 - ( rPoint[0] + rPoint[1] ) ) <= 1.0 + tol ) )
                        return true;

        return false;
    }

    SizeType EdgesNumber() const override
    {
        return 9;
    }

    SizeType FacesNumber() const override
    {
        return 5;
    }

    GeometriesArrayType Edges() const override
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

    GeometriesArrayType Faces() const override
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

    ///@}
    ///@name Shape Function
    ///@{

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
            KRATOS_ERROR << "Wrong index of shape function!";
        }

        return 0;
    }

    ///@}
    ///@name Input and output
    ///@{

    std::string Info() const override
    {
        return "3 dimensional prism with six nodes in 3D space";
    }

    void PrintInfo( std::ostream& rOStream ) const override
    {
        rOStream << "3 dimensional prism with six nodes in 3D space";
    }

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

    Prism3D6(): BaseType( PointsArrayType(), &msGeometryData ) {}

    ///@}
    ///@name Private Operations
    ///@{

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

    ///@}
    ///@name Private Friends
    ///@{

    template<class TOtherPointType> friend class Prism3D6;

    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}

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
