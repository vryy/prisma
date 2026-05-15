//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.7 $
//
//

#if !defined(KRATOS_LINE_2D_H_INCLUDED )
#define  KRATOS_LINE_2D_H_INCLUDED

// System includes

// External includes

// Project includes
#include "geometries/geometry.h"
#include "integration/line_gauss_legendre_integration_points.h"


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
class Line2D : public Geometry<TPointType>
{
public:
    ///@name Type Definitions
    ///@{

    /// Geometry as base class.
    typedef Geometry<TPointType> BaseType;

    /// Pointer definition of Line2D
    KRATOS_CLASS_POINTER_DEFINITION(Line2D);

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

    Line2D(const PointType& FirstPoint, const PointType& SecondPoint)
        : BaseType(PointsArrayType(), &msGeometryData)
    {
        BaseType::Points().push_back(typename PointType::Pointer(new PointType(FirstPoint)));
        BaseType::Points().push_back(typename PointType::Pointer(new PointType(SecondPoint)));
    }

    Line2D(typename PointType::Pointer pFirstPoint, typename PointType::Pointer pSecondPoint)
        : BaseType(PointsArrayType(), &msGeometryData)
    {
        BaseType::Points().push_back(pFirstPoint);
        BaseType::Points().push_back(pSecondPoint);
    }

    Line2D(const PointsArrayType& ThisPoints)
        : BaseType(ThisPoints, &msGeometryData)
    {
        if( BaseType::PointsNumber() != 2)
            KRATOS_THROW_ERROR(std::invalid_argument,
                         "Invalid points number. Expected 2, given " , BaseType::PointsNumber());
    }

    /** Copy constructor.
    Construct this geometry as a copy of given geometry.

    @note This copy constructor don't copy the points and new
    geometry shares points with given source geometry. It's
    obvious that any change to this new geometry's point affect
    source geometry's points too.
    */
    Line2D(Line2D const& rOther)
        : BaseType(rOther)
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
    template<class TOtherPointType> Line2D(Line2D<TOtherPointType> const& rOther)
        : BaseType(rOther)
    {
    }

    ~Line2D() override {}

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
    Line2D& operator=(const Line2D& rOther)
    {
        BaseType::operator=(rOther);

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
    Line2D& operator=(Line2D<TOtherPointType> const & rOther)
    {
        BaseType::operator=(rOther);

        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    typename BaseType::Pointer Create(PointsArrayType const& ThisPoints) const override
    {
        return typename BaseType::Pointer(new Line2D(ThisPoints));
    }

    typename Geometry< Point<3, DataType> >::Pointer Clone() const override
    {
        typename Geometry< Point<3, DataType> >::PointsArrayType NewPoints;

        //making a copy of the nodes TO POINTS (not Nodes!!!)
        for(IndexType i = 0 ; i < BaseType::Points().size() ; i++)
            NewPoints.push_back(BaseType::Points()[i]);

        //creating a geometry with the new points
        typename Geometry< Point<3, DataType> >::Pointer p_clone(new Line2D< Point<3, DataType> >(NewPoints));
        p_clone->ClonePoints();

        return p_clone;
    }

    Vector& LumpingFactors(Vector& rResult) const override
    {
    if(rResult.size() != 2)
           rResult.resize(2, false);
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
        const TPointType& point1 = BaseType::GetPoint(1);
        const DataType lx = point0.X() - point1.X();
        const DataType ly = point0.Y() - point1.Y();

        const DataType length = lx * lx + ly * ly;

        return sqrt( length );
    }

    ///@}
    ///@name Jacobian
    ///@{

    JacobiansType& Jacobian(JacobiansType& rResult, IntegrationMethod ThisMethod) const override
    {
        MatrixType jacobian(2,1);
        jacobian(0,0)=(BaseType::GetPoint(1).X()-BaseType::GetPoint(0).X())*0.5;    //on the Gauss points (J is constant at each element)
        jacobian(1,0)=(BaseType::GetPoint(1).Y()-BaseType::GetPoint(0).Y())*0.5;

        if(rResult.size() != BaseType::IntegrationPointsNumber(ThisMethod))
        {
            // KLUDGE: While there is a bug in ublas vector resize, I have to put this beside resizing!!
            JacobiansType temp(BaseType::IntegrationPointsNumber(ThisMethod));
            rResult.swap(temp);
        }
        std::fill(rResult.begin(), rResult.end(), jacobian);
        return rResult;
    }

    JacobiansType& Jacobian(JacobiansType& rResult, IntegrationMethod ThisMethod, const MatrixType & DeltaPosition ) const override
    {
        MatrixType jacobian(2,1);
        jacobian(0,0)=(BaseType::GetPoint(1).X() - DeltaPosition(1,0) - BaseType::GetPoint(0).X() - DeltaPosition(0,0))*0.5;    //on the Gauss points (J is constant at each element)
        jacobian(1,0)=(BaseType::GetPoint(1).Y() - DeltaPosition(1,1) - BaseType::GetPoint(0).Y() - DeltaPosition(0,1))*0.5;

        if(rResult.size() != BaseType::IntegrationPointsNumber(ThisMethod))
        {
            // KLUDGE: While there is a bug in ublas vector resize, I have to put this beside resizing!!
            JacobiansType temp(BaseType::IntegrationPointsNumber(ThisMethod));
            rResult.swap(temp);
        }
        std::fill(rResult.begin(), rResult.end(), jacobian);
        return rResult;
    }

    MatrixType& Jacobian(MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod) const override
    {
        MatrixType jacobian(2,1);
        jacobian(0,0)=(BaseType::GetPoint(1).X()-BaseType::GetPoint(0).X())*0.5;    //on the Gauss points (J is constant at each element)
        jacobian(1,0)=(BaseType::GetPoint(1).Y()-BaseType::GetPoint(0).Y())*0.5;
        return rResult;
    }

    MatrixType& Jacobian(MatrixType& rResult, const LocalCoordinatesArrayType& rPoint) const override
    {
        MatrixType jacobian(2,1);
        jacobian(0,0)=(BaseType::GetPoint(1).X()-BaseType::GetPoint(0).X())*0.5;    //on the Gauss points (J is constant at each element)
        jacobian(1,0)=(BaseType::GetPoint(1).Y()-BaseType::GetPoint(0).Y())*0.5;
        return rResult;
    }

    VectorType& DeterminantOfJacobian(VectorType& rResult, IntegrationMethod ThisMethod) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
    }

    DataType DeterminantOfJacobian(IndexType IntegrationPointIndex, IntegrationMethod ThisMethod) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
    }

    DataType DeterminantOfJacobian(const LocalCoordinatesArrayType& rPoint) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
    }

    JacobiansType& InverseOfJacobian(JacobiansType& rResult, IntegrationMethod ThisMethod) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
    }

    MatrixType& InverseOfJacobian(MatrixType& rResult, IndexType IntegrationPointIndex, IntegrationMethod ThisMethod) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
    }

    MatrixType& InverseOfJacobian(MatrixType& rResult, const LocalCoordinatesArrayType& rPoint) const override
    {
        KRATOS_ERROR << "Jacobian is not square";
    }

    SizeType EdgesNumber() const override
    {
        return 1;
    }

    ///@}
    ///@name Shape Function
    ///@{

    ValueType ShapeFunctionValue(IndexType ShapeFunctionIndex,
                                 const LocalCoordinatesArrayType& rPoint) const override
    {
        KRATOS_ERROR << "This method is not implemented yet!";;
        return 0;
    }

    ShapeFunctionsIntegrationPointsGradientsType& ShapeFunctionsIntegrationPointsGradients(ShapeFunctionsIntegrationPointsGradientsType& rResult, IntegrationMethod ThisMethod) const override
    {
        KRATOS_ERROR << "Not yet implemented";
        return rResult;
    }

    ///@}
    ///@name Input and output
    ///@{

    std::string Info() const override
    {
        return "1 dimensional line in 2D space";
    }

    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << "1 dimensional line in 2D space";
    }

    void PrintData(std::ostream& rOStream) const override
    {
        BaseType::PrintData(rOStream);
        std::cout << std::endl;
        MatrixType jacobian;
        Jacobian(jacobian, PointType());
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

    Line2D(): BaseType( PointsArrayType(), &msGeometryData ) {}


    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    static Matrix CalculateShapeFunctionsIntegrationPointsValues(typename BaseType::IntegrationMethod ThisMethod)
    {
        const IntegrationPointsContainerType& all_integration_points = AllIntegrationPoints();
        const IntegrationPointsArrayType& IntegrationPoints = all_integration_points[static_cast<int>(ThisMethod)];
        int integration_points_number = IntegrationPoints.size();
        Matrix N(integration_points_number,2);
        for(int it_gp = 0; it_gp < integration_points_number; it_gp++)
        {
            ValueType e = IntegrationPoints[it_gp].X();
            N(it_gp,0) = 0.5*(1-e);
            N(it_gp,1) = 0.5*(1+e);
        }

        return N;
    }

    static ShapeFunctionsGradientsType CalculateShapeFunctionsIntegrationPointsLocalGradients(typename BaseType::IntegrationMethod ThisMethod)
    {
        const IntegrationPointsContainerType& all_integration_points = AllIntegrationPoints();
        const IntegrationPointsArrayType& IntegrationPoints = all_integration_points[static_cast<int>(ThisMethod)];
        ShapeFunctionsGradientsType DN_De(IntegrationPoints.size());
        std::fill(DN_De.begin(), DN_De.end(), Matrix(2,1));

        for(unsigned int it_gp = 0; it_gp < IntegrationPoints.size(); it_gp++)
        {
            //  ValueType e = IntegrationPoints[it_gp].X();
            DN_De[it_gp](0,0) = -0.5;
            DN_De[it_gp](1,0) =  0.5;
        }
        return DN_De;

    }

    static const IntegrationPointsContainerType AllIntegrationPoints()
    {
        IntegrationPointsContainerType integration_points = {{
                Quadrature<LineGaussLegendreIntegrationPoints1, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLegendreIntegrationPoints2, 1, IntegrationPoint<3> >::GenerateIntegrationPoints(),
                Quadrature<LineGaussLegendreIntegrationPoints3, 1, IntegrationPoint<3> >::GenerateIntegrationPoints()
            }
        };
        return integration_points;
    }

    static const ShapeFunctionsValuesContainerType AllShapeFunctionsValues()
    {
        ShapeFunctionsValuesContainerType shape_functions_values = {{
                Line2D<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(GeometryData::IntegrationMethod::GI_GAUSS_1),
                Line2D<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(GeometryData::IntegrationMethod::GI_GAUSS_2),
                Line2D<TPointType>::CalculateShapeFunctionsIntegrationPointsValues(GeometryData::IntegrationMethod::GI_GAUSS_3)
            }
        };
        return shape_functions_values;
    }

    static const ShapeFunctionsLocalGradientsContainerType AllShapeFunctionsLocalGradients()
    {
        ShapeFunctionsLocalGradientsContainerType shape_functions_local_gradients = {{
                Line2D<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(GeometryData::IntegrationMethod::GI_GAUSS_1),
                Line2D<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(GeometryData::IntegrationMethod::GI_GAUSS_2),
                Line2D<TPointType>::CalculateShapeFunctionsIntegrationPointsLocalGradients(GeometryData::IntegrationMethod::GI_GAUSS_3)
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

    template<class TOtherPointType> friend class Line2D;

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
const GeometryData Line2D<TPointType>::msGeometryData(2,
        2,
        1,
        GeometryData::IntegrationMethod::GI_GAUSS_1,
        Line2D<TPointType>::AllIntegrationPoints(),
        Line2D<TPointType>::AllShapeFunctionsValues(),
        AllShapeFunctionsLocalGradients());

}  // namespace Kratos.

#endif // KRATOS_LINE_2D_H_INCLUDED  defined
