//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.6 $
//
//

#if !defined(KRATOS_QUADRILATERAL_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED )
#define  KRATOS_QUADRILATERAL_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED


// System includes

// External includes

// Project includes
#include "integration/quadrature.h"


namespace Kratos
{

class QuadrilateralGaussLegendreIntegrationPoints1
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 1> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 1;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( 0.00 , 0.00 , 4.00 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 1 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints1

class QuadrilateralGaussLegendreIntegrationPoints2
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 4> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 4;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00/std::sqrt(3.0) , -1.00/std::sqrt(3.0), 1.00 ),
            IntegrationPointType(  1.00/std::sqrt(3.0) , -1.00/std::sqrt(3.0), 1.00 ),
            IntegrationPointType(  1.00/std::sqrt(3.0) ,  1.00/std::sqrt(3.0), 1.00 ),
            IntegrationPointType( -1.00/std::sqrt(3.0) ,  1.00/std::sqrt(3.0), 1.00 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 2 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints2

class QuadrilateralGaussLegendreIntegrationPoints3
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 9> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 9;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -std::sqrt(3.00/5.00) , -std::sqrt(3.00/5.00), 25.00/81.00 ),
            IntegrationPointType(  std::sqrt(3.00/5.00) , -std::sqrt(3.00/5.00), 25.00/81.00 ),
            IntegrationPointType(  std::sqrt(3.00/5.00) ,  std::sqrt(3.00/5.00), 25.00/81.00 ),
            IntegrationPointType( -std::sqrt(3.00/5.00) ,  std::sqrt(3.00/5.00), 25.00/81.00 ),
            IntegrationPointType(             0.00 , -std::sqrt(3.00/5.00), 40.00/81.00 ),
            IntegrationPointType(  std::sqrt(3.00/5.00) ,             0.00, 40.00/81.00 ),
            IntegrationPointType(             0.00 ,  std::sqrt(3.00/5.00), 40.00/81.00 ),
            IntegrationPointType( -std::sqrt(3.00/5.00) ,             0.00, 40.00/81.00 ),
            IntegrationPointType(             0.00 ,             0.00, 64.00/81.00 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 3 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints3

class QuadrilateralGaussLegendreIntegrationPoints4
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 16> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()    {  return 16; }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType( -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType( -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType( -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0)),

            IntegrationPointType( -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType( -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType( -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType( -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0)),

            IntegrationPointType(  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType(  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType(  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType(  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0)),

            IntegrationPointType(  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType(  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType(  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0)),
            IntegrationPointType(  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0)),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 4 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints4

class QuadrilateralGaussLegendreIntegrationPoints5 {
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 25> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber() {return 25;}

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -0.906179845938664, -0.906179845938664, 0.236926885056189 * 0.236926885056189),
            IntegrationPointType( -0.906179845938664, -0.538469310105683, 0.236926885056189 * 0.478628670499366),
            IntegrationPointType( -0.906179845938664, 0.000000000000000, 0.236926885056189 * 0.568888888888889),
            IntegrationPointType( -0.906179845938664, 0.538469310105683, 0.236926885056189 * 0.478628670499366),
            IntegrationPointType( -0.906179845938664, 0.906179845938664, 0.236926885056189 * 0.236926885056189),

            IntegrationPointType( -0.538469310105683, -0.906179845938664, 0.478628670499366 * 0.236926885056189),
            IntegrationPointType( -0.538469310105683, -0.538469310105683, 0.478628670499366 * 0.478628670499366),
            IntegrationPointType( -0.538469310105683, 0.000000000000000, 0.478628670499366 * 0.568888888888889),
            IntegrationPointType( -0.538469310105683, 0.538469310105683, 0.478628670499366 * 0.478628670499366),
            IntegrationPointType( -0.538469310105683, 0.906179845938664, 0.478628670499366 * 0.236926885056189),

            IntegrationPointType( 0.000000000000000, -0.906179845938664, 0.568888888888889 * 0.236926885056189),
            IntegrationPointType( 0.000000000000000, -0.538469310105683, 0.568888888888889 * 0.478628670499366),
            IntegrationPointType( 0.000000000000000, 0.000000000000000, 0.568888888888889 * 0.568888888888889),
            IntegrationPointType( 0.000000000000000, 0.538469310105683, 0.568888888888889 * 0.478628670499366),
            IntegrationPointType( 0.000000000000000, 0.906179845938664, 0.568888888888889 * 0.236926885056189),

            IntegrationPointType( 0.538469310105683, -0.906179845938664, 0.478628670499366 * 0.236926885056189),
            IntegrationPointType( 0.538469310105683, -0.538469310105683, 0.478628670499366 * 0.478628670499366),
            IntegrationPointType( 0.538469310105683, 0.000000000000000, 0.478628670499366 * 0.568888888888889),
            IntegrationPointType( 0.538469310105683, 0.538469310105683, 0.478628670499366 * 0.478628670499366),
            IntegrationPointType( 0.538469310105683, 0.906179845938664, 0.478628670499366 * 0.236926885056189),

            IntegrationPointType( 0.906179845938664, -0.906179845938664, 0.236926885056189 * 0.236926885056189),
            IntegrationPointType( 0.906179845938664, -0.538469310105683, 0.236926885056189 * 0.478628670499366),
            IntegrationPointType( 0.906179845938664, 0.000000000000000, 0.236926885056189 * 0.568888888888889),
            IntegrationPointType( 0.906179845938664, 0.538469310105683, 0.236926885056189 * 0.478628670499366),
            IntegrationPointType( 0.906179845938664, 0.906179845938664, 0.236926885056189 * 0.236926885056189),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 5 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints5

class QuadrilateralGaussLegendreIntegrationPoints6 {
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 36> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber() {return 36;}

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -0.9324695142031521, -0.9324695142031521, 0.1713244923791704*0.1713244923791704 ),
            IntegrationPointType( -0.9324695142031521, -0.6612093864662645, 0.1713244923791704*0.3607615730481386 ),
            IntegrationPointType( -0.9324695142031521, -0.2386191860831969, 0.1713244923791704*0.4679139345726910 ),
            IntegrationPointType( -0.9324695142031521, 0.2386191860831969, 0.1713244923791704*0.4679139345726910 ),
            IntegrationPointType( -0.9324695142031521, 0.6612093864662645, 0.1713244923791704*0.3607615730481386 ),
            IntegrationPointType( -0.9324695142031521, 0.9324695142031521, 0.1713244923791704*0.1713244923791704 ),

            IntegrationPointType( -0.6612093864662645, -0.9324695142031521, 0.3607615730481386*0.1713244923791704 ),
            IntegrationPointType( -0.6612093864662645, -0.6612093864662645, 0.3607615730481386*0.3607615730481386 ),
            IntegrationPointType( -0.6612093864662645, -0.2386191860831969, 0.3607615730481386*0.4679139345726910 ),
            IntegrationPointType( -0.6612093864662645, 0.2386191860831969, 0.3607615730481386*0.4679139345726910 ),
            IntegrationPointType( -0.6612093864662645, 0.6612093864662645, 0.3607615730481386*0.3607615730481386 ),
            IntegrationPointType( -0.6612093864662645, 0.9324695142031521, 0.3607615730481386*0.1713244923791704 ),

            IntegrationPointType( -0.2386191860831969, -0.9324695142031521, 0.4679139345726910*0.1713244923791704 ),
            IntegrationPointType( -0.2386191860831969, -0.6612093864662645, 0.4679139345726910*0.3607615730481386 ),
            IntegrationPointType( -0.2386191860831969, -0.2386191860831969, 0.4679139345726910*0.4679139345726910 ),
            IntegrationPointType( -0.2386191860831969, 0.2386191860831969, 0.4679139345726910*0.4679139345726910 ),
            IntegrationPointType( -0.2386191860831969, 0.6612093864662645, 0.4679139345726910*0.3607615730481386 ),
            IntegrationPointType( -0.2386191860831969, 0.9324695142031521, 0.4679139345726910*0.1713244923791704 ),

            IntegrationPointType( 0.2386191860831969, -0.9324695142031521, 0.4679139345726910*0.1713244923791704 ),
            IntegrationPointType( 0.2386191860831969, -0.6612093864662645, 0.4679139345726910*0.3607615730481386 ),
            IntegrationPointType( 0.2386191860831969, -0.2386191860831969, 0.4679139345726910*0.4679139345726910 ),
            IntegrationPointType( 0.2386191860831969, 0.2386191860831969, 0.4679139345726910*0.4679139345726910 ),
            IntegrationPointType( 0.2386191860831969, 0.6612093864662645, 0.4679139345726910*0.3607615730481386 ),
            IntegrationPointType( 0.2386191860831969, 0.9324695142031521, 0.4679139345726910*0.1713244923791704 ),

            IntegrationPointType( 0.6612093864662645, -0.9324695142031521, 0.3607615730481386*0.1713244923791704 ),
            IntegrationPointType( 0.6612093864662645, -0.6612093864662645, 0.3607615730481386*0.3607615730481386 ),
            IntegrationPointType( 0.6612093864662645, -0.2386191860831969, 0.3607615730481386*0.4679139345726910 ),
            IntegrationPointType( 0.6612093864662645, 0.2386191860831969, 0.3607615730481386*0.4679139345726910 ),
            IntegrationPointType( 0.6612093864662645, 0.6612093864662645, 0.3607615730481386*0.3607615730481386 ),
            IntegrationPointType( 0.6612093864662645, 0.9324695142031521, 0.3607615730481386*0.1713244923791704 ),

            IntegrationPointType( 0.9324695142031521, -0.9324695142031521, 0.1713244923791704*0.1713244923791704 ),
            IntegrationPointType( 0.9324695142031521, -0.6612093864662645, 0.1713244923791704*0.3607615730481386 ),
            IntegrationPointType( 0.9324695142031521, -0.2386191860831969, 0.1713244923791704*0.4679139345726910 ),
            IntegrationPointType( 0.9324695142031521, 0.2386191860831969, 0.1713244923791704*0.4679139345726910 ),
            IntegrationPointType( 0.9324695142031521, 0.6612093864662645, 0.1713244923791704*0.3607615730481386 ),
            IntegrationPointType( 0.9324695142031521, 0.9324695142031521, 0.1713244923791704*0.1713244923791704 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 6 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints6

class QuadrilateralGaussLegendreIntegrationPoints7 {
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 49> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber() {return 49;}

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -0.9491079123427585, -0.9491079123427585, 0.1294849661688697*0.1294849661688697 ),
            IntegrationPointType( -0.9491079123427585, -0.7415311855993945, 0.1294849661688697*0.2797053914892766 ),
            IntegrationPointType( -0.9491079123427585, -0.4058451513773972, 0.1294849661688697*0.3818300505051189 ),
            IntegrationPointType( -0.9491079123427585, 0.0000000000000000, 0.1294849661688697*0.4179591836734694 ),
            IntegrationPointType( -0.9491079123427585, 0.4058451513773972, 0.1294849661688697*0.3818300505051189 ),
            IntegrationPointType( -0.9491079123427585, 0.7415311855993945, 0.1294849661688697*0.2797053914892766 ),
            IntegrationPointType( -0.9491079123427585, 0.9491079123427585, 0.1294849661688697*0.1294849661688697 ),

            IntegrationPointType( -0.7415311855993945, -0.9491079123427585, 0.2797053914892766*0.1294849661688697 ),
            IntegrationPointType( -0.7415311855993945, -0.7415311855993945, 0.2797053914892766*0.2797053914892766 ),
            IntegrationPointType( -0.7415311855993945, -0.4058451513773972, 0.2797053914892766*0.3818300505051189 ),
            IntegrationPointType( -0.7415311855993945, 0.0000000000000000, 0.2797053914892766*0.4179591836734694 ),
            IntegrationPointType( -0.7415311855993945, 0.4058451513773972, 0.2797053914892766*0.3818300505051189 ),
            IntegrationPointType( -0.7415311855993945, 0.7415311855993945, 0.2797053914892766*0.2797053914892766 ),
            IntegrationPointType( -0.7415311855993945, 0.9491079123427585, 0.2797053914892766*0.1294849661688697 ),

            IntegrationPointType( -0.4058451513773972, -0.9491079123427585, 0.3818300505051189*0.1294849661688697 ),
            IntegrationPointType( -0.4058451513773972, -0.7415311855993945, 0.3818300505051189*0.2797053914892766 ),
            IntegrationPointType( -0.4058451513773972, -0.4058451513773972, 0.3818300505051189*0.3818300505051189 ),
            IntegrationPointType( -0.4058451513773972, 0.0000000000000000, 0.3818300505051189*0.4179591836734694 ),
            IntegrationPointType( -0.4058451513773972, 0.4058451513773972, 0.3818300505051189*0.3818300505051189 ),
            IntegrationPointType( -0.4058451513773972, 0.7415311855993945, 0.3818300505051189*0.2797053914892766 ),
            IntegrationPointType( -0.4058451513773972, 0.9491079123427585, 0.3818300505051189*0.1294849661688697 ),

            IntegrationPointType( 0.0000000000000000, -0.9491079123427585, 0.4179591836734694*0.1294849661688697 ),
            IntegrationPointType( 0.0000000000000000, -0.7415311855993945, 0.4179591836734694*0.2797053914892766 ),
            IntegrationPointType( 0.0000000000000000, -0.4058451513773972, 0.4179591836734694*0.3818300505051189 ),
            IntegrationPointType( 0.0000000000000000, 0.0000000000000000, 0.4179591836734694*0.4179591836734694 ),
            IntegrationPointType( 0.0000000000000000, 0.4058451513773972, 0.4179591836734694*0.3818300505051189 ),
            IntegrationPointType( 0.0000000000000000, 0.7415311855993945, 0.4179591836734694*0.2797053914892766 ),
            IntegrationPointType( 0.0000000000000000, 0.9491079123427585, 0.4179591836734694*0.1294849661688697 ),

            IntegrationPointType( 0.4058451513773972, -0.9491079123427585, 0.3818300505051189*0.1294849661688697 ),
            IntegrationPointType( 0.4058451513773972, -0.7415311855993945, 0.3818300505051189*0.2797053914892766 ),
            IntegrationPointType( 0.4058451513773972, -0.4058451513773972, 0.3818300505051189*0.3818300505051189 ),
            IntegrationPointType( 0.4058451513773972, 0.0000000000000000, 0.3818300505051189*0.4179591836734694 ),
            IntegrationPointType( 0.4058451513773972, 0.4058451513773972, 0.3818300505051189*0.3818300505051189 ),
            IntegrationPointType( 0.4058451513773972, 0.7415311855993945, 0.3818300505051189*0.2797053914892766 ),
            IntegrationPointType( 0.4058451513773972, 0.9491079123427585, 0.3818300505051189*0.1294849661688697 ),

            IntegrationPointType( 0.7415311855993945, -0.9491079123427585, 0.2797053914892766*0.1294849661688697 ),
            IntegrationPointType( 0.7415311855993945, -0.7415311855993945, 0.2797053914892766*0.2797053914892766 ),
            IntegrationPointType( 0.7415311855993945, -0.4058451513773972, 0.2797053914892766*0.3818300505051189 ),
            IntegrationPointType( 0.7415311855993945, 0.0000000000000000, 0.2797053914892766*0.4179591836734694 ),
            IntegrationPointType( 0.7415311855993945, 0.4058451513773972, 0.2797053914892766*0.3818300505051189 ),
            IntegrationPointType( 0.7415311855993945, 0.7415311855993945, 0.2797053914892766*0.2797053914892766 ),
            IntegrationPointType( 0.7415311855993945, 0.9491079123427585, 0.2797053914892766*0.1294849661688697 ),

            IntegrationPointType( 0.9491079123427585, -0.9491079123427585, 0.1294849661688697*0.1294849661688697 ),
            IntegrationPointType( 0.9491079123427585, -0.7415311855993945, 0.1294849661688697*0.2797053914892766 ),
            IntegrationPointType( 0.9491079123427585, -0.4058451513773972, 0.1294849661688697*0.3818300505051189 ),
            IntegrationPointType( 0.9491079123427585, 0.0000000000000000, 0.1294849661688697*0.4179591836734694 ),
            IntegrationPointType( 0.9491079123427585, 0.4058451513773972, 0.1294849661688697*0.3818300505051189 ),
            IntegrationPointType( 0.9491079123427585, 0.7415311855993945, 0.1294849661688697*0.2797053914892766 ),
            IntegrationPointType( 0.9491079123427585, 0.9491079123427585, 0.1294849661688697*0.1294849661688697 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 7 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints7

class QuadrilateralGaussLegendreIntegrationPoints8 {
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 64> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber() {return 64;}

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -0.9602898564975363, -0.9602898564975363, 0.1012285362903763*0.1012285362903763 ),
            IntegrationPointType( -0.9602898564975363, -0.7966664774136267, 0.1012285362903763*0.2223810344533745 ),
            IntegrationPointType( -0.9602898564975363, -0.5255324099163290, 0.1012285362903763*0.3137066458778873 ),
            IntegrationPointType( -0.9602898564975363, -0.1834346424956498, 0.1012285362903763*0.3626837833783620 ),
            IntegrationPointType( -0.9602898564975363, 0.1834346424956498, 0.1012285362903763*0.3626837833783620 ),
            IntegrationPointType( -0.9602898564975363, 0.5255324099163290, 0.1012285362903763*0.3137066458778873 ),
            IntegrationPointType( -0.9602898564975363, 0.7966664774136267, 0.1012285362903763*0.2223810344533745 ),
            IntegrationPointType( -0.9602898564975363, 0.9602898564975363, 0.1012285362903763*0.1012285362903763 ),

            IntegrationPointType( -0.7966664774136267, -0.9602898564975363, 0.2223810344533745*0.1012285362903763 ),
            IntegrationPointType( -0.7966664774136267, -0.7966664774136267, 0.2223810344533745*0.2223810344533745 ),
            IntegrationPointType( -0.7966664774136267, -0.5255324099163290, 0.2223810344533745*0.3137066458778873 ),
            IntegrationPointType( -0.7966664774136267, -0.1834346424956498, 0.2223810344533745*0.3626837833783620 ),
            IntegrationPointType( -0.7966664774136267, 0.1834346424956498, 0.2223810344533745*0.3626837833783620 ),
            IntegrationPointType( -0.7966664774136267, 0.5255324099163290, 0.2223810344533745*0.3137066458778873 ),
            IntegrationPointType( -0.7966664774136267, 0.7966664774136267, 0.2223810344533745*0.2223810344533745 ),
            IntegrationPointType( -0.7966664774136267, 0.9602898564975363, 0.2223810344533745*0.1012285362903763 ),

            IntegrationPointType( -0.5255324099163290, -0.9602898564975363, 0.3137066458778873*0.1012285362903763 ),
            IntegrationPointType( -0.5255324099163290, -0.7966664774136267, 0.3137066458778873*0.2223810344533745 ),
            IntegrationPointType( -0.5255324099163290, -0.5255324099163290, 0.3137066458778873*0.3137066458778873 ),
            IntegrationPointType( -0.5255324099163290, -0.1834346424956498, 0.3137066458778873*0.3626837833783620 ),
            IntegrationPointType( -0.5255324099163290, 0.1834346424956498, 0.3137066458778873*0.3626837833783620 ),
            IntegrationPointType( -0.5255324099163290, 0.5255324099163290, 0.3137066458778873*0.3137066458778873 ),
            IntegrationPointType( -0.5255324099163290, 0.7966664774136267, 0.3137066458778873*0.2223810344533745 ),
            IntegrationPointType( -0.5255324099163290, 0.9602898564975363, 0.3137066458778873*0.1012285362903763 ),

            IntegrationPointType( -0.1834346424956498, -0.9602898564975363, 0.3626837833783620*0.1012285362903763 ),
            IntegrationPointType( -0.1834346424956498, -0.7966664774136267, 0.3626837833783620*0.2223810344533745 ),
            IntegrationPointType( -0.1834346424956498, -0.5255324099163290, 0.3626837833783620*0.3137066458778873 ),
            IntegrationPointType( -0.1834346424956498, -0.1834346424956498, 0.3626837833783620*0.3626837833783620 ),
            IntegrationPointType( -0.1834346424956498, 0.1834346424956498, 0.3626837833783620*0.3626837833783620 ),
            IntegrationPointType( -0.1834346424956498, 0.5255324099163290, 0.3626837833783620*0.3137066458778873 ),
            IntegrationPointType( -0.1834346424956498, 0.7966664774136267, 0.3626837833783620*0.2223810344533745 ),
            IntegrationPointType( -0.1834346424956498, 0.9602898564975363, 0.3626837833783620*0.1012285362903763 ),

            IntegrationPointType( 0.1834346424956498, -0.9602898564975363, 0.3626837833783620*0.1012285362903763 ),
            IntegrationPointType( 0.1834346424956498, -0.7966664774136267, 0.3626837833783620*0.2223810344533745 ),
            IntegrationPointType( 0.1834346424956498, -0.5255324099163290, 0.3626837833783620*0.3137066458778873 ),
            IntegrationPointType( 0.1834346424956498, -0.1834346424956498, 0.3626837833783620*0.3626837833783620 ),
            IntegrationPointType( 0.1834346424956498, 0.1834346424956498, 0.3626837833783620*0.3626837833783620 ),
            IntegrationPointType( 0.1834346424956498, 0.5255324099163290, 0.3626837833783620*0.3137066458778873 ),
            IntegrationPointType( 0.1834346424956498, 0.7966664774136267, 0.3626837833783620*0.2223810344533745 ),
            IntegrationPointType( 0.1834346424956498, 0.9602898564975363, 0.3626837833783620*0.1012285362903763 ),

            IntegrationPointType( 0.5255324099163290, -0.9602898564975363, 0.3137066458778873*0.1012285362903763 ),
            IntegrationPointType( 0.5255324099163290, -0.7966664774136267, 0.3137066458778873*0.2223810344533745 ),
            IntegrationPointType( 0.5255324099163290, -0.5255324099163290, 0.3137066458778873*0.3137066458778873 ),
            IntegrationPointType( 0.5255324099163290, -0.1834346424956498, 0.3137066458778873*0.3626837833783620 ),
            IntegrationPointType( 0.5255324099163290, 0.1834346424956498, 0.3137066458778873*0.3626837833783620 ),
            IntegrationPointType( 0.5255324099163290, 0.5255324099163290, 0.3137066458778873*0.3137066458778873 ),
            IntegrationPointType( 0.5255324099163290, 0.7966664774136267, 0.3137066458778873*0.2223810344533745 ),
            IntegrationPointType( 0.5255324099163290, 0.9602898564975363, 0.3137066458778873*0.1012285362903763 ),

            IntegrationPointType( 0.7966664774136267, -0.9602898564975363, 0.2223810344533745*0.1012285362903763 ),
            IntegrationPointType( 0.7966664774136267, -0.7966664774136267, 0.2223810344533745*0.2223810344533745 ),
            IntegrationPointType( 0.7966664774136267, -0.5255324099163290, 0.2223810344533745*0.3137066458778873 ),
            IntegrationPointType( 0.7966664774136267, -0.1834346424956498, 0.2223810344533745*0.3626837833783620 ),
            IntegrationPointType( 0.7966664774136267, 0.1834346424956498, 0.2223810344533745*0.3626837833783620 ),
            IntegrationPointType( 0.7966664774136267, 0.5255324099163290, 0.2223810344533745*0.3137066458778873 ),
            IntegrationPointType( 0.7966664774136267, 0.7966664774136267, 0.2223810344533745*0.2223810344533745 ),
            IntegrationPointType( 0.7966664774136267, 0.9602898564975363, 0.2223810344533745*0.1012285362903763 ),

            IntegrationPointType( 0.9602898564975363, -0.9602898564975363, 0.1012285362903763*0.1012285362903763 ),
            IntegrationPointType( 0.9602898564975363, -0.7966664774136267, 0.1012285362903763*0.2223810344533745 ),
            IntegrationPointType( 0.9602898564975363, -0.5255324099163290, 0.1012285362903763*0.3137066458778873 ),
            IntegrationPointType( 0.9602898564975363, -0.1834346424956498, 0.1012285362903763*0.3626837833783620 ),
            IntegrationPointType( 0.9602898564975363, 0.1834346424956498, 0.1012285362903763*0.3626837833783620 ),
            IntegrationPointType( 0.9602898564975363, 0.5255324099163290, 0.1012285362903763*0.3137066458778873 ),
            IntegrationPointType( 0.9602898564975363, 0.7966664774136267, 0.1012285362903763*0.2223810344533745 ),
            IntegrationPointType( 0.9602898564975363, 0.9602898564975363, 0.1012285362903763*0.1012285362903763 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 8 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints8

class QuadrilateralGaussLegendreIntegrationPoints9 {
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 81> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber() {return 81;}

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -0.9681602395076261, -0.9681602395076261, 0.0812743883615744*0.0812743883615744 ),
            IntegrationPointType( -0.9681602395076261, -0.8360311073266358, 0.0812743883615744*0.1806481606948574 ),
            IntegrationPointType( -0.9681602395076261, -0.6133714327005904, 0.0812743883615744*0.2606106964029354 ),
            IntegrationPointType( -0.9681602395076261, -0.3242534234038089, 0.0812743883615744*0.3123470770400029 ),
            IntegrationPointType( -0.9681602395076261, 0.0000000000000000, 0.0812743883615744*0.3302393550012598 ),
            IntegrationPointType( -0.9681602395076261, 0.3242534234038089, 0.0812743883615744*0.3123470770400029 ),
            IntegrationPointType( -0.9681602395076261, 0.6133714327005904, 0.0812743883615744*0.2606106964029354 ),
            IntegrationPointType( -0.9681602395076261, 0.8360311073266358, 0.0812743883615744*0.1806481606948574 ),
            IntegrationPointType( -0.9681602395076261, 0.9681602395076261, 0.0812743883615744*0.0812743883615744 ),

            IntegrationPointType( -0.8360311073266358, -0.9681602395076261, 0.1806481606948574*0.0812743883615744 ),
            IntegrationPointType( -0.8360311073266358, -0.8360311073266358, 0.1806481606948574*0.1806481606948574 ),
            IntegrationPointType( -0.8360311073266358, -0.6133714327005904, 0.1806481606948574*0.2606106964029354 ),
            IntegrationPointType( -0.8360311073266358, -0.3242534234038089, 0.1806481606948574*0.3123470770400029 ),
            IntegrationPointType( -0.8360311073266358, 0.0000000000000000, 0.1806481606948574*0.3302393550012598 ),
            IntegrationPointType( -0.8360311073266358, 0.3242534234038089, 0.1806481606948574*0.3123470770400029 ),
            IntegrationPointType( -0.8360311073266358, 0.6133714327005904, 0.1806481606948574*0.2606106964029354 ),
            IntegrationPointType( -0.8360311073266358, 0.8360311073266358, 0.1806481606948574*0.1806481606948574 ),
            IntegrationPointType( -0.8360311073266358, 0.9681602395076261, 0.1806481606948574*0.0812743883615744 ),

            IntegrationPointType( -0.6133714327005904, -0.9681602395076261, 0.2606106964029354*0.0812743883615744 ),
            IntegrationPointType( -0.6133714327005904, -0.8360311073266358, 0.2606106964029354*0.1806481606948574 ),
            IntegrationPointType( -0.6133714327005904, -0.6133714327005904, 0.2606106964029354*0.2606106964029354 ),
            IntegrationPointType( -0.6133714327005904, -0.3242534234038089, 0.2606106964029354*0.3123470770400029 ),
            IntegrationPointType( -0.6133714327005904, 0.0000000000000000, 0.2606106964029354*0.3302393550012598 ),
            IntegrationPointType( -0.6133714327005904, 0.3242534234038089, 0.2606106964029354*0.3123470770400029 ),
            IntegrationPointType( -0.6133714327005904, 0.6133714327005904, 0.2606106964029354*0.2606106964029354 ),
            IntegrationPointType( -0.6133714327005904, 0.8360311073266358, 0.2606106964029354*0.1806481606948574 ),
            IntegrationPointType( -0.6133714327005904, 0.9681602395076261, 0.2606106964029354*0.0812743883615744 ),

            IntegrationPointType( -0.3242534234038089, -0.9681602395076261, 0.3123470770400029*0.0812743883615744 ),
            IntegrationPointType( -0.3242534234038089, -0.8360311073266358, 0.3123470770400029*0.1806481606948574 ),
            IntegrationPointType( -0.3242534234038089, -0.6133714327005904, 0.3123470770400029*0.2606106964029354 ),
            IntegrationPointType( -0.3242534234038089, -0.3242534234038089, 0.3123470770400029*0.3123470770400029 ),
            IntegrationPointType( -0.3242534234038089, 0.0000000000000000, 0.3123470770400029*0.3302393550012598 ),
            IntegrationPointType( -0.3242534234038089, 0.3242534234038089, 0.3123470770400029*0.3123470770400029 ),
            IntegrationPointType( -0.3242534234038089, 0.6133714327005904, 0.3123470770400029*0.2606106964029354 ),
            IntegrationPointType( -0.3242534234038089, 0.8360311073266358, 0.3123470770400029*0.1806481606948574 ),
            IntegrationPointType( -0.3242534234038089, 0.9681602395076261, 0.3123470770400029*0.0812743883615744 ),

            IntegrationPointType( 0.0000000000000000, -0.9681602395076261, 0.3302393550012598*0.0812743883615744 ),
            IntegrationPointType( 0.0000000000000000, -0.8360311073266358, 0.3302393550012598*0.1806481606948574 ),
            IntegrationPointType( 0.0000000000000000, -0.6133714327005904, 0.3302393550012598*0.2606106964029354 ),
            IntegrationPointType( 0.0000000000000000, -0.3242534234038089, 0.3302393550012598*0.3123470770400029 ),
            IntegrationPointType( 0.0000000000000000, 0.0000000000000000, 0.3302393550012598*0.3302393550012598 ),
            IntegrationPointType( 0.0000000000000000, 0.3242534234038089, 0.3302393550012598*0.3123470770400029 ),
            IntegrationPointType( 0.0000000000000000, 0.6133714327005904, 0.3302393550012598*0.2606106964029354 ),
            IntegrationPointType( 0.0000000000000000, 0.8360311073266358, 0.3302393550012598*0.1806481606948574 ),
            IntegrationPointType( 0.0000000000000000, 0.9681602395076261, 0.3302393550012598*0.0812743883615744 ),

            IntegrationPointType( 0.3242534234038089, -0.9681602395076261, 0.3123470770400029*0.0812743883615744 ),
            IntegrationPointType( 0.3242534234038089, -0.8360311073266358, 0.3123470770400029*0.1806481606948574 ),
            IntegrationPointType( 0.3242534234038089, -0.6133714327005904, 0.3123470770400029*0.2606106964029354 ),
            IntegrationPointType( 0.3242534234038089, -0.3242534234038089, 0.3123470770400029*0.3123470770400029 ),
            IntegrationPointType( 0.3242534234038089, 0.0000000000000000, 0.3123470770400029*0.3302393550012598 ),
            IntegrationPointType( 0.3242534234038089, 0.3242534234038089, 0.3123470770400029*0.3123470770400029 ),
            IntegrationPointType( 0.3242534234038089, 0.6133714327005904, 0.3123470770400029*0.2606106964029354 ),
            IntegrationPointType( 0.3242534234038089, 0.8360311073266358, 0.3123470770400029*0.1806481606948574 ),
            IntegrationPointType( 0.3242534234038089, 0.9681602395076261, 0.3123470770400029*0.0812743883615744 ),

            IntegrationPointType( 0.6133714327005904, -0.9681602395076261, 0.2606106964029354*0.0812743883615744 ),
            IntegrationPointType( 0.6133714327005904, -0.8360311073266358, 0.2606106964029354*0.1806481606948574 ),
            IntegrationPointType( 0.6133714327005904, -0.6133714327005904, 0.2606106964029354*0.2606106964029354 ),
            IntegrationPointType( 0.6133714327005904, -0.3242534234038089, 0.2606106964029354*0.3123470770400029 ),
            IntegrationPointType( 0.6133714327005904, 0.0000000000000000, 0.2606106964029354*0.3302393550012598 ),
            IntegrationPointType( 0.6133714327005904, 0.3242534234038089, 0.2606106964029354*0.3123470770400029 ),
            IntegrationPointType( 0.6133714327005904, 0.6133714327005904, 0.2606106964029354*0.2606106964029354 ),
            IntegrationPointType( 0.6133714327005904, 0.8360311073266358, 0.2606106964029354*0.1806481606948574 ),
            IntegrationPointType( 0.6133714327005904, 0.9681602395076261, 0.2606106964029354*0.0812743883615744 ),

            IntegrationPointType( 0.8360311073266358, -0.9681602395076261, 0.1806481606948574*0.0812743883615744 ),
            IntegrationPointType( 0.8360311073266358, -0.8360311073266358, 0.1806481606948574*0.1806481606948574 ),
            IntegrationPointType( 0.8360311073266358, -0.6133714327005904, 0.1806481606948574*0.2606106964029354 ),
            IntegrationPointType( 0.8360311073266358, -0.3242534234038089, 0.1806481606948574*0.3123470770400029 ),
            IntegrationPointType( 0.8360311073266358, 0.0000000000000000, 0.1806481606948574*0.3302393550012598 ),
            IntegrationPointType( 0.8360311073266358, 0.3242534234038089, 0.1806481606948574*0.3123470770400029 ),
            IntegrationPointType( 0.8360311073266358, 0.6133714327005904, 0.1806481606948574*0.2606106964029354 ),
            IntegrationPointType( 0.8360311073266358, 0.8360311073266358, 0.1806481606948574*0.1806481606948574 ),
            IntegrationPointType( 0.8360311073266358, 0.9681602395076261, 0.1806481606948574*0.0812743883615744 ),

            IntegrationPointType( 0.9681602395076261, -0.9681602395076261, 0.0812743883615744*0.0812743883615744 ),
            IntegrationPointType( 0.9681602395076261, -0.8360311073266358, 0.0812743883615744*0.1806481606948574 ),
            IntegrationPointType( 0.9681602395076261, -0.6133714327005904, 0.0812743883615744*0.2606106964029354 ),
            IntegrationPointType( 0.9681602395076261, -0.3242534234038089, 0.0812743883615744*0.3123470770400029 ),
            IntegrationPointType( 0.9681602395076261, 0.0000000000000000, 0.0812743883615744*0.3302393550012598 ),
            IntegrationPointType( 0.9681602395076261, 0.3242534234038089, 0.0812743883615744*0.3123470770400029 ),
            IntegrationPointType( 0.9681602395076261, 0.6133714327005904, 0.0812743883615744*0.2606106964029354 ),
            IntegrationPointType( 0.9681602395076261, 0.8360311073266358, 0.0812743883615744*0.1806481606948574 ),
            IntegrationPointType( 0.9681602395076261, 0.9681602395076261, 0.0812743883615744*0.0812743883615744 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 9 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints9

class QuadrilateralGaussLegendreIntegrationPoints10 {
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 100> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber() {return 100;}

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -0.9739065285171717, -0.9739065285171717, 0.0666713443086881*0.0666713443086881 ),
            IntegrationPointType( -0.9739065285171717, -0.8650633666889845, 0.0666713443086881*0.1494513491505806 ),
            IntegrationPointType( -0.9739065285171717, -0.6794095682990244, 0.0666713443086881*0.2190863625159820 ),
            IntegrationPointType( -0.9739065285171717, -0.4333953941292472, 0.0666713443086881*0.2692667193099963 ),
            IntegrationPointType( -0.9739065285171717, -0.1488743389816312, 0.0666713443086881*0.2955242247147529 ),
            IntegrationPointType( -0.9739065285171717, 0.1488743389816312, 0.0666713443086881*0.2955242247147529 ),
            IntegrationPointType( -0.9739065285171717, 0.4333953941292472, 0.0666713443086881*0.2692667193099963 ),
            IntegrationPointType( -0.9739065285171717, 0.6794095682990244, 0.0666713443086881*0.2190863625159820 ),
            IntegrationPointType( -0.9739065285171717, 0.8650633666889845, 0.0666713443086881*0.1494513491505806 ),
            IntegrationPointType( -0.9739065285171717, 0.9739065285171717, 0.0666713443086881*0.0666713443086881 ),

            IntegrationPointType( -0.8650633666889845, -0.9739065285171717, 0.1494513491505806*0.0666713443086881 ),
            IntegrationPointType( -0.8650633666889845, -0.8650633666889845, 0.1494513491505806*0.1494513491505806 ),
            IntegrationPointType( -0.8650633666889845, -0.6794095682990244, 0.1494513491505806*0.2190863625159820 ),
            IntegrationPointType( -0.8650633666889845, -0.4333953941292472, 0.1494513491505806*0.2692667193099963 ),
            IntegrationPointType( -0.8650633666889845, -0.1488743389816312, 0.1494513491505806*0.2955242247147529 ),
            IntegrationPointType( -0.8650633666889845, 0.1488743389816312, 0.1494513491505806*0.2955242247147529 ),
            IntegrationPointType( -0.8650633666889845, 0.4333953941292472, 0.1494513491505806*0.2692667193099963 ),
            IntegrationPointType( -0.8650633666889845, 0.6794095682990244, 0.1494513491505806*0.2190863625159820 ),
            IntegrationPointType( -0.8650633666889845, 0.8650633666889845, 0.1494513491505806*0.1494513491505806 ),
            IntegrationPointType( -0.8650633666889845, 0.9739065285171717, 0.1494513491505806*0.0666713443086881 ),

            IntegrationPointType( -0.6794095682990244, -0.9739065285171717, 0.2190863625159820*0.0666713443086881 ),
            IntegrationPointType( -0.6794095682990244, -0.8650633666889845, 0.2190863625159820*0.1494513491505806 ),
            IntegrationPointType( -0.6794095682990244, -0.6794095682990244, 0.2190863625159820*0.2190863625159820 ),
            IntegrationPointType( -0.6794095682990244, -0.4333953941292472, 0.2190863625159820*0.2692667193099963 ),
            IntegrationPointType( -0.6794095682990244, -0.1488743389816312, 0.2190863625159820*0.2955242247147529 ),
            IntegrationPointType( -0.6794095682990244, 0.1488743389816312, 0.2190863625159820*0.2955242247147529 ),
            IntegrationPointType( -0.6794095682990244, 0.4333953941292472, 0.2190863625159820*0.2692667193099963 ),
            IntegrationPointType( -0.6794095682990244, 0.6794095682990244, 0.2190863625159820*0.2190863625159820 ),
            IntegrationPointType( -0.6794095682990244, 0.8650633666889845, 0.2190863625159820*0.1494513491505806 ),
            IntegrationPointType( -0.6794095682990244, 0.9739065285171717, 0.2190863625159820*0.0666713443086881 ),

            IntegrationPointType( -0.4333953941292472, -0.9739065285171717, 0.2692667193099963*0.0666713443086881 ),
            IntegrationPointType( -0.4333953941292472, -0.8650633666889845, 0.2692667193099963*0.1494513491505806 ),
            IntegrationPointType( -0.4333953941292472, -0.6794095682990244, 0.2692667193099963*0.2190863625159820 ),
            IntegrationPointType( -0.4333953941292472, -0.4333953941292472, 0.2692667193099963*0.2692667193099963 ),
            IntegrationPointType( -0.4333953941292472, -0.1488743389816312, 0.2692667193099963*0.2955242247147529 ),
            IntegrationPointType( -0.4333953941292472, 0.1488743389816312, 0.2692667193099963*0.2955242247147529 ),
            IntegrationPointType( -0.4333953941292472, 0.4333953941292472, 0.2692667193099963*0.2692667193099963 ),
            IntegrationPointType( -0.4333953941292472, 0.6794095682990244, 0.2692667193099963*0.2190863625159820 ),
            IntegrationPointType( -0.4333953941292472, 0.8650633666889845, 0.2692667193099963*0.1494513491505806 ),
            IntegrationPointType( -0.4333953941292472, 0.9739065285171717, 0.2692667193099963*0.0666713443086881 ),

            IntegrationPointType( -0.1488743389816312, -0.9739065285171717, 0.2955242247147529*0.0666713443086881 ),
            IntegrationPointType( -0.1488743389816312, -0.8650633666889845, 0.2955242247147529*0.1494513491505806 ),
            IntegrationPointType( -0.1488743389816312, -0.6794095682990244, 0.2955242247147529*0.2190863625159820 ),
            IntegrationPointType( -0.1488743389816312, -0.4333953941292472, 0.2955242247147529*0.2692667193099963 ),
            IntegrationPointType( -0.1488743389816312, -0.1488743389816312, 0.2955242247147529*0.2955242247147529 ),
            IntegrationPointType( -0.1488743389816312, 0.1488743389816312, 0.2955242247147529*0.2955242247147529 ),
            IntegrationPointType( -0.1488743389816312, 0.4333953941292472, 0.2955242247147529*0.2692667193099963 ),
            IntegrationPointType( -0.1488743389816312, 0.6794095682990244, 0.2955242247147529*0.2190863625159820 ),
            IntegrationPointType( -0.1488743389816312, 0.8650633666889845, 0.2955242247147529*0.1494513491505806 ),
            IntegrationPointType( -0.1488743389816312, 0.9739065285171717, 0.2955242247147529*0.0666713443086881 ),

            IntegrationPointType( 0.1488743389816312, -0.9739065285171717, 0.2955242247147529*0.0666713443086881 ),
            IntegrationPointType( 0.1488743389816312, -0.8650633666889845, 0.2955242247147529*0.1494513491505806 ),
            IntegrationPointType( 0.1488743389816312, -0.6794095682990244, 0.2955242247147529*0.2190863625159820 ),
            IntegrationPointType( 0.1488743389816312, -0.4333953941292472, 0.2955242247147529*0.2692667193099963 ),
            IntegrationPointType( 0.1488743389816312, -0.1488743389816312, 0.2955242247147529*0.2955242247147529 ),
            IntegrationPointType( 0.1488743389816312, 0.1488743389816312, 0.2955242247147529*0.2955242247147529 ),
            IntegrationPointType( 0.1488743389816312, 0.4333953941292472, 0.2955242247147529*0.2692667193099963 ),
            IntegrationPointType( 0.1488743389816312, 0.6794095682990244, 0.2955242247147529*0.2190863625159820 ),
            IntegrationPointType( 0.1488743389816312, 0.8650633666889845, 0.2955242247147529*0.1494513491505806 ),
            IntegrationPointType( 0.1488743389816312, 0.9739065285171717, 0.2955242247147529*0.0666713443086881 ),

            IntegrationPointType( 0.4333953941292472, -0.9739065285171717, 0.2692667193099963*0.0666713443086881 ),
            IntegrationPointType( 0.4333953941292472, -0.8650633666889845, 0.2692667193099963*0.1494513491505806 ),
            IntegrationPointType( 0.4333953941292472, -0.6794095682990244, 0.2692667193099963*0.2190863625159820 ),
            IntegrationPointType( 0.4333953941292472, -0.4333953941292472, 0.2692667193099963*0.2692667193099963 ),
            IntegrationPointType( 0.4333953941292472, -0.1488743389816312, 0.2692667193099963*0.2955242247147529 ),
            IntegrationPointType( 0.4333953941292472, 0.1488743389816312, 0.2692667193099963*0.2955242247147529 ),
            IntegrationPointType( 0.4333953941292472, 0.4333953941292472, 0.2692667193099963*0.2692667193099963 ),
            IntegrationPointType( 0.4333953941292472, 0.6794095682990244, 0.2692667193099963*0.2190863625159820 ),
            IntegrationPointType( 0.4333953941292472, 0.8650633666889845, 0.2692667193099963*0.1494513491505806 ),
            IntegrationPointType( 0.4333953941292472, 0.9739065285171717, 0.2692667193099963*0.0666713443086881 ),

            IntegrationPointType( 0.6794095682990244, -0.9739065285171717, 0.2190863625159820*0.0666713443086881 ),
            IntegrationPointType( 0.6794095682990244, -0.8650633666889845, 0.2190863625159820*0.1494513491505806 ),
            IntegrationPointType( 0.6794095682990244, -0.6794095682990244, 0.2190863625159820*0.2190863625159820 ),
            IntegrationPointType( 0.6794095682990244, -0.4333953941292472, 0.2190863625159820*0.2692667193099963 ),
            IntegrationPointType( 0.6794095682990244, -0.1488743389816312, 0.2190863625159820*0.2955242247147529 ),
            IntegrationPointType( 0.6794095682990244, 0.1488743389816312, 0.2190863625159820*0.2955242247147529 ),
            IntegrationPointType( 0.6794095682990244, 0.4333953941292472, 0.2190863625159820*0.2692667193099963 ),
            IntegrationPointType( 0.6794095682990244, 0.6794095682990244, 0.2190863625159820*0.2190863625159820 ),
            IntegrationPointType( 0.6794095682990244, 0.8650633666889845, 0.2190863625159820*0.1494513491505806 ),
            IntegrationPointType( 0.6794095682990244, 0.9739065285171717, 0.2190863625159820*0.0666713443086881 ),

            IntegrationPointType( 0.8650633666889845, -0.9739065285171717, 0.1494513491505806*0.0666713443086881 ),
            IntegrationPointType( 0.8650633666889845, -0.8650633666889845, 0.1494513491505806*0.1494513491505806 ),
            IntegrationPointType( 0.8650633666889845, -0.6794095682990244, 0.1494513491505806*0.2190863625159820 ),
            IntegrationPointType( 0.8650633666889845, -0.4333953941292472, 0.1494513491505806*0.2692667193099963 ),
            IntegrationPointType( 0.8650633666889845, -0.1488743389816312, 0.1494513491505806*0.2955242247147529 ),
            IntegrationPointType( 0.8650633666889845, 0.1488743389816312, 0.1494513491505806*0.2955242247147529 ),
            IntegrationPointType( 0.8650633666889845, 0.4333953941292472, 0.1494513491505806*0.2692667193099963 ),
            IntegrationPointType( 0.8650633666889845, 0.6794095682990244, 0.1494513491505806*0.2190863625159820 ),
            IntegrationPointType( 0.8650633666889845, 0.8650633666889845, 0.1494513491505806*0.1494513491505806 ),
            IntegrationPointType( 0.8650633666889845, 0.9739065285171717, 0.1494513491505806*0.0666713443086881 ),

            IntegrationPointType( 0.9739065285171717, -0.9739065285171717, 0.0666713443086881*0.0666713443086881 ),
            IntegrationPointType( 0.9739065285171717, -0.8650633666889845, 0.0666713443086881*0.1494513491505806 ),
            IntegrationPointType( 0.9739065285171717, -0.6794095682990244, 0.0666713443086881*0.2190863625159820 ),
            IntegrationPointType( 0.9739065285171717, -0.4333953941292472, 0.0666713443086881*0.2692667193099963 ),
            IntegrationPointType( 0.9739065285171717, -0.1488743389816312, 0.0666713443086881*0.2955242247147529 ),
            IntegrationPointType( 0.9739065285171717, 0.1488743389816312, 0.0666713443086881*0.2955242247147529 ),
            IntegrationPointType( 0.9739065285171717, 0.4333953941292472, 0.0666713443086881*0.2692667193099963 ),
            IntegrationPointType( 0.9739065285171717, 0.6794095682990244, 0.0666713443086881*0.2190863625159820 ),
            IntegrationPointType( 0.9739065285171717, 0.8650633666889845, 0.0666713443086881*0.1494513491505806 ),
            IntegrationPointType( 0.9739065285171717, 0.9739065285171717, 0.0666713443086881*0.0666713443086881 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 10 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLegendreIntegrationPoints10

///@name Type Definitions
///@{

template<int TDegree>
class QuadrilateralGaussLegendreIntegrationPoints;

template<>
class QuadrilateralGaussLegendreIntegrationPoints<1> : public QuadrilateralGaussLegendreIntegrationPoints1
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<2> : public QuadrilateralGaussLegendreIntegrationPoints2
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<3> : public QuadrilateralGaussLegendreIntegrationPoints3
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<4> : public QuadrilateralGaussLegendreIntegrationPoints4
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<5> : public QuadrilateralGaussLegendreIntegrationPoints5
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<6> : public QuadrilateralGaussLegendreIntegrationPoints6
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<7> : public QuadrilateralGaussLegendreIntegrationPoints7
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<8> : public QuadrilateralGaussLegendreIntegrationPoints8
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<9> : public QuadrilateralGaussLegendreIntegrationPoints9
{};

template<>
class QuadrilateralGaussLegendreIntegrationPoints<10> : public QuadrilateralGaussLegendreIntegrationPoints10
{};

///@}
///@name Input and output
///@{


///@}


}  // namespace Kratos.

#endif // KRATOS_QUADRILATERAL_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED  defined
