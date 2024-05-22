//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.7 $
//
//

#if !defined(KRATOS_QUADRILATERAL_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED )
#define  KRATOS_QUADRILATERAL_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED


// System includes

// External includes

// Project includes
#include "integration/quadrature.h"

//TO BE COMPLETED: Only the needed ones have been implemented

namespace Kratos
{

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints1
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
            IntegrationPointType( 0.00 , 0.00, 4.00 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Lobatto integration 1 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLobattoIntegrationPoints1

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints2
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
            IntegrationPointType( -1.00 , -1.00, 1.00 ),
            IntegrationPointType(  1.00 , -1.00, 1.00 ),
            IntegrationPointType(  1.00 ,  1.00, 1.00 ),
            IntegrationPointType( -1.00 ,  1.00, 1.00 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Lobatto integration 2 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLobattoIntegrationPoints2

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints3
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
            IntegrationPointType( -1.00 , -1.00, 1.00 / 9.0 ),
            IntegrationPointType( -1.00 , 0.00, 4.00 / 9.0 ),
            IntegrationPointType( -1.00 , 1.00, 1.00 / 9.0 ),
            IntegrationPointType( 0.00 , -1.00, 4.00 / 9.0 ),
            IntegrationPointType( 0.00 , 0.00, 16.00 / 9.0 ),
            IntegrationPointType( 0.00 , 1.00, 4.00 / 9.0 ),
            IntegrationPointType( 1.00 , -1.00, 1.00 / 9.0 ),
            IntegrationPointType( 1.00 , 0.00, 4.00 / 9.0 ),
            IntegrationPointType( 1.00 , 1.00, 1.00 / 9.0 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Lobatto integration 3 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLobattoIntegrationPoints3

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints4
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 16> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 16;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-1.00, -1.00, 1.00 / 36.00),
            IntegrationPointType(-std::sqrt(5.00) / 5.00, -1.00, 5.00 / 36.00),
            IntegrationPointType( std::sqrt(5.00) / 5.00, -1.00, 5.00 / 36.00),
            IntegrationPointType( 1.00, -1.00, 1.00 / 36.00),
            IntegrationPointType(-1.00, -std::sqrt(5.00) / 5.00, 5.00 / 36.00),
            IntegrationPointType(-std::sqrt(5.00) / 5.00, -std::sqrt(5.00) / 5.00, 25.00 / 36.00),
            IntegrationPointType( std::sqrt(5.00) / 5.00, -std::sqrt(5.00) / 5.00, 25.00 / 36.00),
            IntegrationPointType( 1.00, -std::sqrt(5.00) / 5.00, 5.00 / 36.00),
            IntegrationPointType(-1.00, std::sqrt(5.00) / 5.00, 5.00 / 36.00),
            IntegrationPointType(-std::sqrt(5.00) / 5.00, std::sqrt(5.00) / 5.00, 25.00 / 36.00),
            IntegrationPointType( std::sqrt(5.00) / 5.00, std::sqrt(5.00) / 5.00, 25.00 / 36.00),
            IntegrationPointType( 1.00, std::sqrt(5.00) / 5.00, 5.00 / 36.00),
            IntegrationPointType(-1.00, 1.00, 1.00 / 36.00),
            IntegrationPointType(-std::sqrt(5.00) / 5.00, 1.00, 5.00 / 36.00),
            IntegrationPointType( std::sqrt(5.00) / 5.00, 1.00, 5.00 / 36.00),
            IntegrationPointType( 1.00, 1.00, 1.00 / 36.00)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Lobatto integration 4 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLobattoIntegrationPoints4

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints5
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 25> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 25;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-1.00, -1.00, 1.00 / 10.00 * 1.00 / 10.00),
            IntegrationPointType(-std::sqrt(21.00) / 7.00, -1.00, 49.00 / 90.00 * 1.00 / 10.00),
            IntegrationPointType( 0.00, -1.00, 32.00 / 45.00 * 1.00 / 10.00),
            IntegrationPointType( std::sqrt(21.00) / 7.00, -1.00, 49.00 / 90.00 * 1.00 / 10.00),
            IntegrationPointType( 1.00, -1.00, 1.00 / 10.00 * 1.00 / 10.00),

            IntegrationPointType(-1.00, -std::sqrt(21.00) / 7.00, 1.00 / 10.00 * 49.00 / 90.00),
            IntegrationPointType(-std::sqrt(21.00) / 7.00, -std::sqrt(21.00) / 7.00, 49.00 / 90.00 * 49.00 / 90.00),
            IntegrationPointType( 0.00, -std::sqrt(21.00) / 7.00, 32.00 / 45.00 * 49.00 / 90.00),
            IntegrationPointType( std::sqrt(21.00) / 7.00, -std::sqrt(21.00) / 7.00, 49.00 / 90.00 * 49.00 / 90.00),
            IntegrationPointType( 1.00, -std::sqrt(21.00) / 7.00, 1.00 / 10.00 * 49.00 / 90.00),

            IntegrationPointType(-1.00, 0.00, 1.00 / 10.00 * 32.00 / 45.00),
            IntegrationPointType(-std::sqrt(21.00) / 7.00, 0.00, 49.00 / 90.00 * 32.00 / 45.00),
            IntegrationPointType( 0.00, 0.00, 32.00 / 45.00 * 32.00 / 45.00),
            IntegrationPointType( std::sqrt(21.00) / 7.00, 0.00, 49.00 / 90.00 * 32.00 / 45.00),
            IntegrationPointType( 1.00, 0.00, 1.00 / 10.00 * 32.00 / 45.00),

            IntegrationPointType(-1.00, std::sqrt(21.00) / 7.00, 1.00 / 10.00 * 49.00 / 90.00),
            IntegrationPointType(-std::sqrt(21.00) / 7.00, std::sqrt(21.00) / 7.00, 49.00 / 90.00 * 49.00 / 90.00),
            IntegrationPointType( 0.00, std::sqrt(21.00) / 7.00, 32.00 / 45.00 * 49.00 / 90.00),
            IntegrationPointType( std::sqrt(21.00) / 7.00, std::sqrt(21.00) / 7.00, 49.00 / 90.00 * 49.00 / 90.00),
            IntegrationPointType( 1.00, std::sqrt(21.00) / 7.00, 1.00 / 10.00 * 49.00 / 90.00),

            IntegrationPointType(-1.00, 1.00, 1.00 / 10.00 * 1.00 / 10.00),
            IntegrationPointType(-std::sqrt(21.00) / 7.00, 1.00, 49.00 / 90.00 * 1.00 / 10.00),
            IntegrationPointType( 0.00, 1.00, 32.00 / 45.00 * 1.00 / 10.00),
            IntegrationPointType( std::sqrt(21.00) / 7.00, 1.00, 49.00 / 90.00 * 1.00 / 10.00),
            IntegrationPointType( 1.00, 1.00, 1.00 / 10.00 * 1.00 / 10.00)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Lobatto integration 5 ";
        return buffer.str();
    }
}; // Class QuadrilateralGaussLobattoIntegrationPoints5

///@name Type Definitions
///@{

template<int TDegree>
class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints;

template<>
class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints<1> : public QuadrilateralGaussLobattoIntegrationPoints1
{};

template<>
class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints<2> : public QuadrilateralGaussLobattoIntegrationPoints2
{};

template<>
class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints<3> : public QuadrilateralGaussLobattoIntegrationPoints3
{};

template<>
class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints<4> : public QuadrilateralGaussLobattoIntegrationPoints4
{};

template<>
class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLobattoIntegrationPoints<5> : public QuadrilateralGaussLobattoIntegrationPoints5
{};

}

#endif // KRATOS_QUADRILATERAL_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED defined
