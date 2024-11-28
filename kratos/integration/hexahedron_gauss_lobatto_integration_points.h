//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.7 $
//
//

#if !defined(KRATOS_HEXAHEDRON_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED )
#define  KRATOS_HEXAHEDRON_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED


// System includes

// External includes

// Project includes
#include "integration/quadrature.h"

namespace Kratos
{

class HexahedronGaussLobattoIntegrationPoints1
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 1> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 1;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( 0.00 , 0.00, 0.00, 8.00 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 1 ";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints1

class HexahedronGaussLobattoIntegrationPoints2
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 8> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 8;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00 , -1.00, -1.00, 1.00 ),
            IntegrationPointType(  1.00 , -1.00, -1.00, 1.00 ),
            IntegrationPointType(  1.00 ,  1.00, -1.00, 1.00 ),
            IntegrationPointType( -1.00 ,  1.00, -1.00, 1.00 ),
            IntegrationPointType( -1.00 , -1.00,  1.00, 1.00 ),
            IntegrationPointType(  1.00 , -1.00,  1.00, 1.00 ),
            IntegrationPointType(  1.00 ,  1.00,  1.00, 1.00 ),
            IntegrationPointType( -1.00 ,  1.00,  1.00, 1.00 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 2 ";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints2

class HexahedronGaussLobattoIntegrationPoints3
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 27> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 27;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00, -1.00, -1.00, 1.00/3.00 * 1.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( -1.00, -1.00, 0.00, 1.00/3.00 * 1.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( -1.00, -1.00, 1.00, 1.00/3.00 * 1.00/3.00 * 1.00/3.00 ),

            IntegrationPointType( -1.00, 0.00, -1.00, 1.00/3.00 * 4.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( -1.00, 0.00, 0.00, 1.00/3.00 * 4.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( -1.00, 0.00, 1.00, 1.00/3.00 * 4.00/3.00 * 1.00/3.00 ),

            IntegrationPointType( -1.00, 1.00, -1.00, 1.00/3.00 * 1.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( -1.00, 1.00, 0.00, 1.00/3.00 * 1.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( -1.00, 1.00, 1.00, 1.00/3.00 * 1.00/3.00 * 1.00/3.00 ),

            IntegrationPointType( 0.00, -1.00, -1.00, 4.00/3.00 * 1.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( 0.00, -1.00, 0.00, 4.00/3.00 * 1.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( 0.00, -1.00, 1.00, 4.00/3.00 * 1.00/3.00 * 1.00/3.00 ),

            IntegrationPointType( 0.00, 0.00, -1.00, 4.00/3.00 * 4.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( 0.00, 0.00, 0.00, 4.00/3.00 * 4.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( 0.00, 0.00, 1.00, 4.00/3.00 * 4.00/3.00 * 1.00/3.00 ),

            IntegrationPointType( 0.00, 1.00, -1.00, 4.00/3.00 * 1.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( 0.00, 1.00, 0.00, 4.00/3.00 * 1.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( 0.00, 1.00, 1.00, 4.00/3.00 * 1.00/3.00 * 1.00/3.00 ),

            IntegrationPointType( 1.00, -1.00, -1.00, 1.00/3.00 * 1.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( 1.00, -1.00, 0.00, 1.00/3.00 * 1.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( 1.00, -1.00, 1.00, 1.00/3.00 * 1.00/3.00 * 1.00/3.00 ),

            IntegrationPointType( 1.00, 0.00, -1.00, 1.00/3.00 * 4.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( 1.00, 0.00, 0.00, 1.00/3.00 * 4.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( 1.00, 0.00, 1.00, 1.00/3.00 * 4.00/3.00 * 1.00/3.00 ),

            IntegrationPointType( 1.00, 1.00, -1.00, 1.00/3.00 * 1.00/3.00 * 1.00/3.00 ),
            IntegrationPointType( 1.00, 1.00, 0.00, 1.00/3.00 * 1.00/3.00 * 4.00/3.00 ),
            IntegrationPointType( 1.00, 1.00, 1.00, 1.00/3.00 * 1.00/3.00 * 1.00/3.00 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 3 ";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints3

class HexahedronGaussLobattoIntegrationPoints4
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 64> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 64;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00, -1.00, -1.00, 1.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( -1.00, -1.00, -std::sqrt(5.00)/5.00, 1.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -1.00, -1.00, std::sqrt(5.00)/5.00, 1.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -1.00, -1.00, 1.00, 1.00/6.00 * 1.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( -1.00, -std::sqrt(5.00)/5.00, -1.00, 1.00/6.00 * 5.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( -1.00, -std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 1.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -1.00, -std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 1.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -1.00, -std::sqrt(5.00)/5.00, 1.00, 1.00/6.00 * 5.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( -1.00, std::sqrt(5.00)/5.00, -1.00, 1.00/6.00 * 5.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( -1.00, std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 1.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -1.00, std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 1.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -1.00, std::sqrt(5.00)/5.00, 1.00, 1.00/6.00 * 5.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( -1.00, 1.00, -1.00, 1.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( -1.00, 1.00, -std::sqrt(5.00)/5.00, 1.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -1.00, 1.00, std::sqrt(5.00)/5.00, 1.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -1.00, 1.00, 1.00, 1.00/6.00 * 1.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( -std::sqrt(5.00)/5.00, -1.00, -1.00, 5.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, -1.00, -std::sqrt(5.00)/5.00, 5.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, -1.00, std::sqrt(5.00)/5.00, 5.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, -1.00, 1.00, 5.00/6.00 * 1.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( -std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, -1.00, 5.00/6.00 * 5.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 5.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 5.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 1.00, 5.00/6.00 * 5.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( -std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, -1.00, 5.00/6.00 * 5.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 5.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 5.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 1.00, 5.00/6.00 * 5.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( -std::sqrt(5.00)/5.00, 1.00, -1.00, 5.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, 1.00, -std::sqrt(5.00)/5.00, 5.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, 1.00, std::sqrt(5.00)/5.00, 5.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( -std::sqrt(5.00)/5.00, 1.00, 1.00, 5.00/6.00 * 1.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( std::sqrt(5.00)/5.00, -1.00, -1.00, 5.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, -1.00, -std::sqrt(5.00)/5.00, 5.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, -1.00, std::sqrt(5.00)/5.00, 5.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, -1.00, 1.00, 5.00/6.00 * 1.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, -1.00, 5.00/6.00 * 5.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 5.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 5.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 1.00, 5.00/6.00 * 5.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, -1.00, 5.00/6.00 * 5.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 5.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 5.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 1.00, 5.00/6.00 * 5.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( std::sqrt(5.00)/5.00, 1.00, -1.00, 5.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, 1.00, -std::sqrt(5.00)/5.00, 5.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, 1.00, std::sqrt(5.00)/5.00, 5.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( std::sqrt(5.00)/5.00, 1.00, 1.00, 5.00/6.00 * 1.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( 1.00, -1.00, -1.00, 1.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( 1.00, -1.00, -std::sqrt(5.00)/5.00, 1.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( 1.00, -1.00, std::sqrt(5.00)/5.00, 1.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( 1.00, -1.00, 1.00, 1.00/6.00 * 1.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( 1.00, -std::sqrt(5.00)/5.00, -1.00, 1.00/6.00 * 5.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( 1.00, -std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 1.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( 1.00, -std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 1.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( 1.00, -std::sqrt(5.00)/5.00, 1.00, 1.00/6.00 * 5.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( 1.00, std::sqrt(5.00)/5.00, -1.00, 1.00/6.00 * 5.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( 1.00, std::sqrt(5.00)/5.00, -std::sqrt(5.00)/5.00, 1.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( 1.00, std::sqrt(5.00)/5.00, std::sqrt(5.00)/5.00, 1.00/6.00 * 5.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( 1.00, std::sqrt(5.00)/5.00, 1.00, 1.00/6.00 * 5.00/6.00 * 1.00/6.00 ),

            IntegrationPointType( 1.00, 1.00, -1.00, 1.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
            IntegrationPointType( 1.00, 1.00, -std::sqrt(5.00)/5.00, 1.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( 1.00, 1.00, std::sqrt(5.00)/5.00, 1.00/6.00 * 1.00/6.00 * 5.00/6.00 ),
            IntegrationPointType( 1.00, 1.00, 1.00, 1.00/6.00 * 1.00/6.00 * 1.00/6.00 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 4 ";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints4

class HexahedronGaussLobattoIntegrationPoints5
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 125> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 125;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00, -1.00, -1.00, 1.00/10.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( -1.00, -1.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, -1.00, 0.00, 1.00/10.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( -1.00, -1.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, -1.00, 1.00, 1.00/10.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( -1.00, -std::sqrt(21.00)/7.00, -1.00, 1.00/10.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( -1.00, -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, -std::sqrt(21.00)/7.00, 0.00, 1.00/10.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( -1.00, -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, -std::sqrt(21.00)/7.00, 1.00, 1.00/10.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( -1.00, 0.00, -1.00, 1.00/10.00 * 32.00/45.00 * 1.00/10.00 ),
            IntegrationPointType( -1.00, 0.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, 0.00, 0.00, 1.00/10.00 * 32.00/45.00 * 32.00/45.00 ),
            IntegrationPointType( -1.00, 0.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, 0.00, 1.00, 1.00/10.00 * 32.00/45.00 * 1.00/10.00 ),

            IntegrationPointType( -1.00, std::sqrt(21.00)/7.00, -1.00, 1.00/10.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( -1.00, std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, std::sqrt(21.00)/7.00, 0.00, 1.00/10.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( -1.00, std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, std::sqrt(21.00)/7.00, 1.00, 1.00/10.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( -1.00, 1.00, -1.00, 1.00/10.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( -1.00, 1.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, 1.00, 0.00, 1.00/10.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( -1.00, 1.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( -1.00, 1.00, 1.00, 1.00/10.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( -std::sqrt(21.00)/7.00, -1.00, -1.00, 49.00/90.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, -1.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, -1.00, 0.00, 49.00/90.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, -1.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, -1.00, 1.00, 49.00/90.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, -1.00, 49.00/90.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 0.00, 49.00/90.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 1.00, 49.00/90.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( -std::sqrt(21.00)/7.00, 0.00, -1.00, 49.00/90.00 * 32.00/45.00 * 1.00/10.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, 0.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, 0.00, 0.00, 49.00/90.00 * 32.00/45.00 * 32.00/45.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, 0.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, 0.00, 1.00, 49.00/90.00 * 32.00/45.00 * 1.00/10.00 ),

            IntegrationPointType( -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, -1.00, 49.00/90.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 0.00, 49.00/90.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 1.00, 49.00/90.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( -std::sqrt(21.00)/7.00, 1.00, -1.00, 49.00/90.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, 1.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, 1.00, 0.00, 49.00/90.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, 1.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( -std::sqrt(21.00)/7.00, 1.00, 1.00, 49.00/90.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( 0.00, -1.00, -1.00, 32.00/45.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( 0.00, -1.00, -std::sqrt(21.00)/7.00, 32.00/45.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, -1.00, 0.00, 32.00/45.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( 0.00, -1.00, std::sqrt(21.00)/7.00, 32.00/45.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, -1.00, 1.00, 32.00/45.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( 0.00, -std::sqrt(21.00)/7.00, -1.00, 32.00/45.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( 0.00, -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 32.00/45.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, -std::sqrt(21.00)/7.00, 0.00, 32.00/45.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( 0.00, -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 32.00/45.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, -std::sqrt(21.00)/7.00, 1.00, 32.00/45.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( 0.00, 0.00, -1.00, 32.00/45.00 * 32.00/45.00 * 1.00/10.00 ),
            IntegrationPointType( 0.00, 0.00, -std::sqrt(21.00)/7.00, 32.00/45.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, 0.00, 0.00, 32.00/45.00 * 32.00/45.00 * 32.00/45.00 ),
            IntegrationPointType( 0.00, 0.00, std::sqrt(21.00)/7.00, 32.00/45.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, 0.00, 1.00, 32.00/45.00 * 32.00/45.00 * 1.00/10.00 ),

            IntegrationPointType( 0.00, std::sqrt(21.00)/7.00, -1.00, 32.00/45.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( 0.00, std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 32.00/45.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, std::sqrt(21.00)/7.00, 0.00, 32.00/45.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( 0.00, std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 32.00/45.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, std::sqrt(21.00)/7.00, 1.00, 32.00/45.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( 0.00, 1.00, -1.00, 32.00/45.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( 0.00, 1.00, -std::sqrt(21.00)/7.00, 32.00/45.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, 1.00, 0.00, 32.00/45.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( 0.00, 1.00, std::sqrt(21.00)/7.00, 32.00/45.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( 0.00, 1.00, 1.00, 32.00/45.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( std::sqrt(21.00)/7.00, -1.00, -1.00, 49.00/90.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, -1.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, -1.00, 0.00, 49.00/90.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, -1.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, -1.00, 1.00, 49.00/90.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, -1.00, 49.00/90.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 0.00, 49.00/90.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 1.00, 49.00/90.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( std::sqrt(21.00)/7.00, 0.00, -1.00, 49.00/90.00 * 32.00/45.00 * 1.00/10.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, 0.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, 0.00, 0.00, 49.00/90.00 * 32.00/45.00 * 32.00/45.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, 0.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, 0.00, 1.00, 49.00/90.00 * 32.00/45.00 * 1.00/10.00 ),

            IntegrationPointType( std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, -1.00, 49.00/90.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 0.00, 49.00/90.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 1.00, 49.00/90.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( std::sqrt(21.00)/7.00, 1.00, -1.00, 49.00/90.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, 1.00, -std::sqrt(21.00)/7.00, 49.00/90.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, 1.00, 0.00, 49.00/90.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, 1.00, std::sqrt(21.00)/7.00, 49.00/90.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( std::sqrt(21.00)/7.00, 1.00, 1.00, 49.00/90.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( 1.00, -1.00, -1.00, 1.00/10.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( 1.00, -1.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, -1.00, 0.00, 1.00/10.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( 1.00, -1.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, -1.00, 1.00, 1.00/10.00 * 1.00/10.00 * 1.00/10.00 ),

            IntegrationPointType( 1.00, -std::sqrt(21.00)/7.00, -1.00, 1.00/10.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( 1.00, -std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, -std::sqrt(21.00)/7.00, 0.00, 1.00/10.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( 1.00, -std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, -std::sqrt(21.00)/7.00, 1.00, 1.00/10.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( 1.00, 0.00, -1.00, 1.00/10.00 * 32.00/45.00 * 1.00/10.00 ),
            IntegrationPointType( 1.00, 0.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, 0.00, 0.00, 1.00/10.00 * 32.00/45.00 * 32.00/45.00 ),
            IntegrationPointType( 1.00, 0.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 32.00/45.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, 0.00, 1.00, 1.00/10.00 * 32.00/45.00 * 1.00/10.00 ),

            IntegrationPointType( 1.00, std::sqrt(21.00)/7.00, -1.00, 1.00/10.00 * 49.00/90.00 * 1.00/10.00 ),
            IntegrationPointType( 1.00, std::sqrt(21.00)/7.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, std::sqrt(21.00)/7.00, 0.00, 1.00/10.00 * 49.00/90.00 * 32.00/45.00 ),
            IntegrationPointType( 1.00, std::sqrt(21.00)/7.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 49.00/90.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, std::sqrt(21.00)/7.00, 1.00, 1.00/10.00 * 49.00/90.00 * 1.00/10.00 ),

            IntegrationPointType( 1.00, 1.00, -1.00, 1.00/10.00 * 1.00/10.00 * 1.00/10.00 ),
            IntegrationPointType( 1.00, 1.00, -std::sqrt(21.00)/7.00, 1.00/10.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, 1.00, 0.00, 1.00/10.00 * 1.00/10.00 * 32.00/45.00 ),
            IntegrationPointType( 1.00, 1.00, std::sqrt(21.00)/7.00, 1.00/10.00 * 1.00/10.00 * 49.00/90.00 ),
            IntegrationPointType( 1.00, 1.00, 1.00, 1.00/10.00 * 1.00/10.00 * 1.00/10.00 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 5";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints5

class HexahedronGaussLobattoIntegrationPoints6
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 216> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 216;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00, -1.00, -1.00, 1.00/15.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( -1.00, -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -1.00, 1.00, 1.00/15.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -1.00, 1.00, -1.00, 1.00/15.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( -1.00, 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -1.00, 1.00, 1.00, 1.00/15.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, -1.00, (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, 1.00, (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, -1.00, (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, 1.00, (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, -1.00, (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, 1.00, (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, -1.00, (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, 1.00, (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, -1.00, (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, 1.00, (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, -1.00, (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, 1.00, (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, -1.00, (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, 1.00, (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, -1.00, (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, 1.00, (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( 1.00, -1.00, -1.00, 1.00/15.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( 1.00, -1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -1.00, 1.00, 1.00/15.00 * 1.00/15.00 * 1.00/15.00 ),

            IntegrationPointType( 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -1.00, 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00, 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -1.00, 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00, 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 ),

            IntegrationPointType( 1.00, 1.00, -1.00, 1.00/15.00 * 1.00/15.00 * 1.00/15.00 ),
            IntegrationPointType( 1.00, 1.00, -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, 1.00, -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, 1.00, std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, 1.00, std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00), 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 ),
            IntegrationPointType( 1.00, 1.00, 1.00, 1.00/15.00 * 1.00/15.00 * 1.00/15.00 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 6";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints6

class HexahedronGaussLobattoIntegrationPoints7
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 343> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 343;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00, -1.00, -1.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -1.00, -1.00, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, -1.00, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, -1.00, 0.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -1.00, -1.00, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, -1.00, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, -1.00, 1.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -1.00, -0.830223896278566929872032213967, -1.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -1.00, -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, -0.830223896278566929872032213967, 0.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -1.00, -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, -0.830223896278566929872032213967, 1.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -1.00, -0.468848793470714213803771881909, -1.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -1.00, -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, -0.468848793470714213803771881909, 0.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -1.00, -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, -0.468848793470714213803771881909, 1.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -1.00, 0.00, -1.00, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -1.00, 0.00, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, 0.00, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, 0.00, 0.00, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -1.00, 0.00, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, 0.00, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, 0.00, 1.00, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -1.00, 0.468848793470714213803771881909, -1.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -1.00, 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, 0.468848793470714213803771881909, 0.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -1.00, 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, 0.468848793470714213803771881909, 1.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -1.00, 0.830223896278566929872032213967, -1.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -1.00, 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, 0.830223896278566929872032213967, 0.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -1.00, 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, 0.830223896278566929872032213967, 1.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -1.00, 1.00, -1.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -1.00, 1.00, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, 1.00, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, 1.00, 0.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -1.00, 1.00, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -1.00, 1.00, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -1.00, 1.00, 1.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.830223896278566929872032213967, -1.00, -1.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, -1.00, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, -1.00, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, -1.00, 0.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, -1.00, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, -1.00, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, -1.00, 1.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.830223896278566929872032213967, -0.830223896278566929872032213967, -1.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.830223896278566929872032213967, 1.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.830223896278566929872032213967, -0.468848793470714213803771881909, -1.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, -0.468848793470714213803771881909, 1.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.830223896278566929872032213967, 0.00, -1.00, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.00, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.00, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.00, 0.00, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.00, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.00, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.00, 1.00, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.830223896278566929872032213967, 0.468848793470714213803771881909, -1.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.468848793470714213803771881909, 1.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.830223896278566929872032213967, 0.830223896278566929872032213967, -1.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, 0.830223896278566929872032213967, 1.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.830223896278566929872032213967, 1.00, -1.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, 1.00, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, 1.00, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, 1.00, 0.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.830223896278566929872032213967, 1.00, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.830223896278566929872032213967, 1.00, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.830223896278566929872032213967, 1.00, 1.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.468848793470714213803771881909, -1.00, -1.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, -1.00, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, -1.00, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, -1.00, 0.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, -1.00, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, -1.00, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, -1.00, 1.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.468848793470714213803771881909, -0.830223896278566929872032213967, -1.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.830223896278566929872032213967, 1.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.468848793470714213803771881909, -0.468848793470714213803771881909, -1.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, -0.468848793470714213803771881909, 1.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.468848793470714213803771881909, 0.00, -1.00, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.00, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.00, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.00, 0.00, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.00, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.00, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.00, 1.00, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.468848793470714213803771881909, 0.468848793470714213803771881909, -1.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.468848793470714213803771881909, 1.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.468848793470714213803771881909, 0.830223896278566929872032213967, -1.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, 0.830223896278566929872032213967, 1.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( -0.468848793470714213803771881909, 1.00, -1.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, 1.00, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, 1.00, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, 1.00, 0.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( -0.468848793470714213803771881909, 1.00, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( -0.468848793470714213803771881909, 1.00, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( -0.468848793470714213803771881909, 1.00, 1.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.00, -1.00, -1.00, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.00, -1.00, -0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, -1.00, -0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, -1.00, 0.00, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.00, -1.00, 0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, -1.00, 0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, -1.00, 1.00, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.00, -0.830223896278566929872032213967, -1.00, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.00, -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, -0.830223896278566929872032213967, 0.00, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.00, -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, -0.830223896278566929872032213967, 1.00, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.00, -0.468848793470714213803771881909, -1.00, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.00, -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, -0.468848793470714213803771881909, 0.00, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.00, -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, -0.468848793470714213803771881909, 1.00, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.00, 0.00, -1.00, 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.00, 0.00, -0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, 0.00, -0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, 0.00, 0.00, 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.00, 0.00, 0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, 0.00, 0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, 0.00, 1.00, 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.00, 0.468848793470714213803771881909, -1.00, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.00, 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, 0.468848793470714213803771881909, 0.00, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.00, 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, 0.468848793470714213803771881909, 1.00, 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.00, 0.830223896278566929872032213967, -1.00, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.00, 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, 0.830223896278566929872032213967, 0.00, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.00, 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, 0.830223896278566929872032213967, 1.00, 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.00, 1.00, -1.00, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.00, 1.00, -0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, 1.00, -0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, 1.00, 0.00, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.00, 1.00, 0.468848793470714213803771881909, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.00, 1.00, 0.830223896278566929872032213967, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.00, 1.00, 1.00, 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.468848793470714213803771881909, -1.00, -1.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, -1.00, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, -1.00, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, -1.00, 0.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, -1.00, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, -1.00, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, -1.00, 1.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.468848793470714213803771881909, -0.830223896278566929872032213967, -1.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.830223896278566929872032213967, 1.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.468848793470714213803771881909, -0.468848793470714213803771881909, -1.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, -0.468848793470714213803771881909, 1.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.468848793470714213803771881909, 0.00, -1.00, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.00, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.00, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.00, 0.00, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.00, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.00, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.00, 1.00, 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.468848793470714213803771881909, 0.468848793470714213803771881909, -1.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.468848793470714213803771881909, 1.00, 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.468848793470714213803771881909, 0.830223896278566929872032213967, -1.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, 0.830223896278566929872032213967, 1.00, 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.468848793470714213803771881909, 1.00, -1.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, 1.00, -0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, 1.00, -0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, 1.00, 0.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.468848793470714213803771881909, 1.00, 0.468848793470714213803771881909, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.468848793470714213803771881909, 1.00, 0.830223896278566929872032213967, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.468848793470714213803771881909, 1.00, 1.00, 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.830223896278566929872032213967, -1.00, -1.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, -1.00, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, -1.00, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, -1.00, 0.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, -1.00, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, -1.00, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, -1.00, 1.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.830223896278566929872032213967, -0.830223896278566929872032213967, -1.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.830223896278566929872032213967, 1.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.830223896278566929872032213967, -0.468848793470714213803771881909, -1.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, -0.468848793470714213803771881909, 1.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.830223896278566929872032213967, 0.00, -1.00, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.00, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.00, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.00, 0.00, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.00, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.00, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.00, 1.00, 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.830223896278566929872032213967, 0.468848793470714213803771881909, -1.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.468848793470714213803771881909, 1.00, 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.830223896278566929872032213967, 0.830223896278566929872032213967, -1.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, 0.830223896278566929872032213967, 1.00, 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 0.830223896278566929872032213967, 1.00, -1.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, 1.00, -0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, 1.00, -0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, 1.00, 0.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 0.830223896278566929872032213967, 1.00, 0.468848793470714213803771881909, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 0.830223896278566929872032213967, 1.00, 0.830223896278566929872032213967, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 0.830223896278566929872032213967, 1.00, 1.00, 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 1.00, -1.00, -1.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 1.00, -1.00, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, -1.00, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, -1.00, 0.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 1.00, -1.00, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, -1.00, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, -1.00, 1.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 1.00, -0.830223896278566929872032213967, -1.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 1.00, -0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, -0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, -0.830223896278566929872032213967, 0.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 1.00, -0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, -0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, -0.830223896278566929872032213967, 1.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 1.00, -0.468848793470714213803771881909, -1.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 1.00, -0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, -0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, -0.468848793470714213803771881909, 0.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 1.00, -0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, -0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, -0.468848793470714213803771881909, 1.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 1.00, 0.00, -1.00, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 1.00, 0.00, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, 0.00, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, 0.00, 0.00, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 1.00, 0.00, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, 0.00, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, 0.00, 1.00, 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 1.00, 0.468848793470714213803771881909, -1.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 1.00, 0.468848793470714213803771881909, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, 0.468848793470714213803771881909, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, 0.468848793470714213803771881909, 0.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 1.00, 0.468848793470714213803771881909, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, 0.468848793470714213803771881909, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, 0.468848793470714213803771881909, 1.00, 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 1.00, 0.830223896278566929872032213967, -1.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 1.00, 0.830223896278566929872032213967, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, 0.830223896278566929872032213967, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, 0.830223896278566929872032213967, 0.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 1.00, 0.830223896278566929872032213967, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, 0.830223896278566929872032213967, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, 0.830223896278566929872032213967, 1.00, 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 ),

            IntegrationPointType( 1.00, 1.00, -1.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
            IntegrationPointType( 1.00, 1.00, -0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, 1.00, -0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, 1.00, 0.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 ),
            IntegrationPointType( 1.00, 1.00, 0.468848793470714213803771881909, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 ),
            IntegrationPointType( 1.00, 1.00, 0.830223896278566929872032213967, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 ),
            IntegrationPointType( 1.00, 1.00, 1.00, 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 7";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints7

class HexahedronGaussLobattoIntegrationPoints8
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 512> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 512;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00, -1.00, -1.00, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -1.00, -1.00, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, -1.00, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, -1.00, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, -1.00, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, -1.00, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, -1.00, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, -1.00, 1.00, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -1.00, -0.871740148509606615337445761221, -1.00, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -1.00, -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, -0.871740148509606615337445761221, 1.00, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -1.00, -0.591700181433142302144510731398, -1.00, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -1.00, -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, -0.591700181433142302144510731398, 1.00, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -1.00, -0.209299217902478868768657260345, -1.00, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -1.00, -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, -0.209299217902478868768657260345, 1.00, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -1.00, 0.209299217902478868768657260345, -1.00, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -1.00, 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, 0.209299217902478868768657260345, 1.00, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -1.00, 0.591700181433142302144510731398, -1.00, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -1.00, 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, 0.591700181433142302144510731398, 1.00, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -1.00, 0.871740148509606615337445761221, -1.00, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -1.00, 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, 0.871740148509606615337445761221, 1.00, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -1.00, 1.00, -1.00, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -1.00, 1.00, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, 1.00, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, 1.00, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, 1.00, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -1.00, 1.00, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -1.00, 1.00, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -1.00, 1.00, 1.00, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.871740148509606615337445761221, -1.00, -1.00, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.871740148509606615337445761221, -1.00, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, -1.00, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, -1.00, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, -1.00, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, -1.00, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, -1.00, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, -1.00, 1.00, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.871740148509606615337445761221, -0.871740148509606615337445761221, -1.00, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.871740148509606615337445761221, 1.00, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.871740148509606615337445761221, -0.591700181433142302144510731398, -1.00, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.591700181433142302144510731398, 1.00, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.871740148509606615337445761221, -0.209299217902478868768657260345, -1.00, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, -0.209299217902478868768657260345, 1.00, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.871740148509606615337445761221, 0.209299217902478868768657260345, -1.00, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.209299217902478868768657260345, 1.00, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.871740148509606615337445761221, 0.591700181433142302144510731398, -1.00, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.591700181433142302144510731398, 1.00, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.871740148509606615337445761221, 0.871740148509606615337445761221, -1.00, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, 0.871740148509606615337445761221, 1.00, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.871740148509606615337445761221, 1.00, -1.00, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.871740148509606615337445761221, 1.00, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, 1.00, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, 1.00, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, 1.00, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.871740148509606615337445761221, 1.00, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.871740148509606615337445761221, 1.00, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.871740148509606615337445761221, 1.00, 1.00, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.591700181433142302144510731398, -1.00, -1.00, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.591700181433142302144510731398, -1.00, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, -1.00, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, -1.00, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, -1.00, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, -1.00, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, -1.00, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, -1.00, 1.00, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.591700181433142302144510731398, -0.871740148509606615337445761221, -1.00, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.871740148509606615337445761221, 1.00, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.591700181433142302144510731398, -0.591700181433142302144510731398, -1.00, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.591700181433142302144510731398, 1.00, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.591700181433142302144510731398, -0.209299217902478868768657260345, -1.00, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, -0.209299217902478868768657260345, 1.00, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.591700181433142302144510731398, 0.209299217902478868768657260345, -1.00, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.209299217902478868768657260345, 1.00, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.591700181433142302144510731398, 0.591700181433142302144510731398, -1.00, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.591700181433142302144510731398, 1.00, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.591700181433142302144510731398, 0.871740148509606615337445761221, -1.00, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, 0.871740148509606615337445761221, 1.00, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.591700181433142302144510731398, 1.00, -1.00, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.591700181433142302144510731398, 1.00, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, 1.00, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, 1.00, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, 1.00, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.591700181433142302144510731398, 1.00, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.591700181433142302144510731398, 1.00, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.591700181433142302144510731398, 1.00, 1.00, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.209299217902478868768657260345, -1.00, -1.00, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.209299217902478868768657260345, -1.00, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, -1.00, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, -1.00, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, -1.00, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, -1.00, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, -1.00, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, -1.00, 1.00, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.209299217902478868768657260345, -0.871740148509606615337445761221, -1.00, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.871740148509606615337445761221, 1.00, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.209299217902478868768657260345, -0.591700181433142302144510731398, -1.00, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.591700181433142302144510731398, 1.00, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.209299217902478868768657260345, -0.209299217902478868768657260345, -1.00, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, -0.209299217902478868768657260345, 1.00, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.209299217902478868768657260345, 0.209299217902478868768657260345, -1.00, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.209299217902478868768657260345, 1.00, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.209299217902478868768657260345, 0.591700181433142302144510731398, -1.00, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.591700181433142302144510731398, 1.00, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.209299217902478868768657260345, 0.871740148509606615337445761221, -1.00, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, 0.871740148509606615337445761221, 1.00, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( -0.209299217902478868768657260345, 1.00, -1.00, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( -0.209299217902478868768657260345, 1.00, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, 1.00, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, 1.00, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, 1.00, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( -0.209299217902478868768657260345, 1.00, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( -0.209299217902478868768657260345, 1.00, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( -0.209299217902478868768657260345, 1.00, 1.00, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.209299217902478868768657260345, -1.00, -1.00, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.209299217902478868768657260345, -1.00, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, -1.00, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, -1.00, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, -1.00, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, -1.00, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, -1.00, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, -1.00, 1.00, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.209299217902478868768657260345, -0.871740148509606615337445761221, -1.00, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.871740148509606615337445761221, 1.00, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.209299217902478868768657260345, -0.591700181433142302144510731398, -1.00, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.591700181433142302144510731398, 1.00, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.209299217902478868768657260345, -0.209299217902478868768657260345, -1.00, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, -0.209299217902478868768657260345, 1.00, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.209299217902478868768657260345, 0.209299217902478868768657260345, -1.00, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.209299217902478868768657260345, 1.00, 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.209299217902478868768657260345, 0.591700181433142302144510731398, -1.00, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.591700181433142302144510731398, 1.00, 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.209299217902478868768657260345, 0.871740148509606615337445761221, -1.00, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, 0.871740148509606615337445761221, 1.00, 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.209299217902478868768657260345, 1.00, -1.00, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.209299217902478868768657260345, 1.00, -0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, 1.00, -0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, 1.00, -0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, 1.00, 0.209299217902478868768657260345, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.209299217902478868768657260345, 1.00, 0.591700181433142302144510731398, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.209299217902478868768657260345, 1.00, 0.871740148509606615337445761221, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.209299217902478868768657260345, 1.00, 1.00, 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.591700181433142302144510731398, -1.00, -1.00, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.591700181433142302144510731398, -1.00, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, -1.00, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, -1.00, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, -1.00, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, -1.00, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, -1.00, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, -1.00, 1.00, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.591700181433142302144510731398, -0.871740148509606615337445761221, -1.00, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.871740148509606615337445761221, 1.00, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.591700181433142302144510731398, -0.591700181433142302144510731398, -1.00, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.591700181433142302144510731398, 1.00, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.591700181433142302144510731398, -0.209299217902478868768657260345, -1.00, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, -0.209299217902478868768657260345, 1.00, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.591700181433142302144510731398, 0.209299217902478868768657260345, -1.00, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.209299217902478868768657260345, 1.00, 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.591700181433142302144510731398, 0.591700181433142302144510731398, -1.00, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.591700181433142302144510731398, 1.00, 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.591700181433142302144510731398, 0.871740148509606615337445761221, -1.00, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, 0.871740148509606615337445761221, 1.00, 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.591700181433142302144510731398, 1.00, -1.00, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.591700181433142302144510731398, 1.00, -0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, 1.00, -0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, 1.00, -0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, 1.00, 0.209299217902478868768657260345, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.591700181433142302144510731398, 1.00, 0.591700181433142302144510731398, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.591700181433142302144510731398, 1.00, 0.871740148509606615337445761221, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.591700181433142302144510731398, 1.00, 1.00, 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.871740148509606615337445761221, -1.00, -1.00, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.871740148509606615337445761221, -1.00, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, -1.00, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, -1.00, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, -1.00, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, -1.00, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, -1.00, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, -1.00, 1.00, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.871740148509606615337445761221, -0.871740148509606615337445761221, -1.00, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.871740148509606615337445761221, 1.00, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.871740148509606615337445761221, -0.591700181433142302144510731398, -1.00, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.591700181433142302144510731398, 1.00, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.871740148509606615337445761221, -0.209299217902478868768657260345, -1.00, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, -0.209299217902478868768657260345, 1.00, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.871740148509606615337445761221, 0.209299217902478868768657260345, -1.00, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.209299217902478868768657260345, 1.00, 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.871740148509606615337445761221, 0.591700181433142302144510731398, -1.00, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.591700181433142302144510731398, 1.00, 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.871740148509606615337445761221, 0.871740148509606615337445761221, -1.00, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, 0.871740148509606615337445761221, 1.00, 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 0.871740148509606615337445761221, 1.00, -1.00, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 0.871740148509606615337445761221, 1.00, -0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, 1.00, -0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, 1.00, -0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, 1.00, 0.209299217902478868768657260345, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 0.871740148509606615337445761221, 1.00, 0.591700181433142302144510731398, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 0.871740148509606615337445761221, 1.00, 0.871740148509606615337445761221, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 0.871740148509606615337445761221, 1.00, 1.00, 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 1.00, -1.00, -1.00, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 1.00, -1.00, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, -1.00, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, -1.00, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, -1.00, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, -1.00, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, -1.00, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, -1.00, 1.00, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 1.00, -0.871740148509606615337445761221, -1.00, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 1.00, -0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, -0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, -0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, -0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, -0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, -0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, -0.871740148509606615337445761221, 1.00, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 1.00, -0.591700181433142302144510731398, -1.00, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 1.00, -0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, -0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, -0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, -0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, -0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, -0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, -0.591700181433142302144510731398, 1.00, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 1.00, -0.209299217902478868768657260345, -1.00, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 1.00, -0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, -0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, -0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, -0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, -0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, -0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, -0.209299217902478868768657260345, 1.00, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 1.00, 0.209299217902478868768657260345, -1.00, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 1.00, 0.209299217902478868768657260345, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, 0.209299217902478868768657260345, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, 0.209299217902478868768657260345, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, 0.209299217902478868768657260345, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, 0.209299217902478868768657260345, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, 0.209299217902478868768657260345, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, 0.209299217902478868768657260345, 1.00, 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 1.00, 0.591700181433142302144510731398, -1.00, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 1.00, 0.591700181433142302144510731398, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, 0.591700181433142302144510731398, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, 0.591700181433142302144510731398, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, 0.591700181433142302144510731398, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, 0.591700181433142302144510731398, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, 0.591700181433142302144510731398, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, 0.591700181433142302144510731398, 1.00, 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 1.00, 0.871740148509606615337445761221, -1.00, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 1.00, 0.871740148509606615337445761221, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, 0.871740148509606615337445761221, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, 0.871740148509606615337445761221, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, 0.871740148509606615337445761221, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, 0.871740148509606615337445761221, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, 0.871740148509606615337445761221, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, 0.871740148509606615337445761221, 1.00, 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 ),

            IntegrationPointType( 1.00, 1.00, -1.00, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
            IntegrationPointType( 1.00, 1.00, -0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, 1.00, -0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, 1.00, -0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, 1.00, 0.209299217902478868768657260345, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 ),
            IntegrationPointType( 1.00, 1.00, 0.591700181433142302144510731398, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 ),
            IntegrationPointType( 1.00, 1.00, 0.871740148509606615337445761221, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 ),
            IntegrationPointType( 1.00, 1.00, 1.00, 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 8";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints8

class HexahedronGaussLobattoIntegrationPoints9
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 729> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 729;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00, -1.00, -1.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, -1.00, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, -1.00, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, -1.00, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, -1.00, 0.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, -1.00, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, -1.00, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, -1.00, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, -1.00, 1.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -1.00, -0.899757995411460157312345244418, -1.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, -0.899757995411460157312345244418, 0.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, -0.899757995411460157312345244418, 1.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -1.00, -0.677186279510737753445885427091, -1.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, -0.677186279510737753445885427091, 0.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, -0.677186279510737753445885427091, 1.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -1.00, -0.363117463826178158710752068709, -1.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, -0.363117463826178158710752068709, 0.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, -0.363117463826178158710752068709, 1.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -1.00, 0.00, -1.00, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, 0.00, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 0.00, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 0.00, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 0.00, 0.00, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, 0.00, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 0.00, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 0.00, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 0.00, 1.00, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -1.00, 0.363117463826178158710752068709, -1.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 0.363117463826178158710752068709, 0.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 0.363117463826178158710752068709, 1.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -1.00, 0.677186279510737753445885427091, -1.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 0.677186279510737753445885427091, 0.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 0.677186279510737753445885427091, 1.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -1.00, 0.899757995411460157312345244418, -1.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 0.899757995411460157312345244418, 0.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 0.899757995411460157312345244418, 1.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -1.00, 1.00, -1.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -1.00, 1.00, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 1.00, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 1.00, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 1.00, 0.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -1.00, 1.00, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -1.00, 1.00, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -1.00, 1.00, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -1.00, 1.00, 1.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, -1.00, -1.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, -1.00, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, -1.00, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, -1.00, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, -1.00, 0.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, -1.00, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, -1.00, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, -1.00, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, -1.00, 1.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, -1.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.899757995411460157312345244418, 1.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, -1.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.677186279510737753445885427091, 1.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, -1.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, -0.363117463826178158710752068709, 1.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, 0.00, -1.00, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.00, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.00, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.00, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.00, 0.00, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.00, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.00, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.00, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.00, 1.00, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, -1.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.363117463826178158710752068709, 1.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, -1.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.677186279510737753445885427091, 1.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, -1.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 0.899757995411460157312345244418, 1.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.899757995411460157312345244418, 1.00, -1.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.899757995411460157312345244418, 1.00, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 1.00, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 1.00, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 1.00, 0.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.899757995411460157312345244418, 1.00, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.899757995411460157312345244418, 1.00, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.899757995411460157312345244418, 1.00, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.899757995411460157312345244418, 1.00, 1.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, -1.00, -1.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, -1.00, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, -1.00, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, -1.00, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, -1.00, 0.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, -1.00, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, -1.00, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, -1.00, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, -1.00, 1.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, -1.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.899757995411460157312345244418, 1.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, -1.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.677186279510737753445885427091, 1.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, -1.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, -0.363117463826178158710752068709, 1.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, 0.00, -1.00, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.00, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.00, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.00, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.00, 0.00, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.00, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.00, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.00, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.00, 1.00, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, -1.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.363117463826178158710752068709, 1.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, -1.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.677186279510737753445885427091, 1.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, -1.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 0.899757995411460157312345244418, 1.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.677186279510737753445885427091, 1.00, -1.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.677186279510737753445885427091, 1.00, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 1.00, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 1.00, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 1.00, 0.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.677186279510737753445885427091, 1.00, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.677186279510737753445885427091, 1.00, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.677186279510737753445885427091, 1.00, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.677186279510737753445885427091, 1.00, 1.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, -1.00, -1.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, -1.00, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, -1.00, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, -1.00, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, -1.00, 0.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, -1.00, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, -1.00, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, -1.00, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, -1.00, 1.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, -1.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.899757995411460157312345244418, 1.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, -1.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.677186279510737753445885427091, 1.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, -1.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, -0.363117463826178158710752068709, 1.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, 0.00, -1.00, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.00, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.00, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.00, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.00, 0.00, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.00, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.00, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.00, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.00, 1.00, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, -1.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.363117463826178158710752068709, 1.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, -1.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.677186279510737753445885427091, 1.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, -1.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 0.899757995411460157312345244418, 1.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( -0.363117463826178158710752068709, 1.00, -1.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( -0.363117463826178158710752068709, 1.00, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 1.00, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 1.00, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 1.00, 0.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( -0.363117463826178158710752068709, 1.00, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( -0.363117463826178158710752068709, 1.00, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( -0.363117463826178158710752068709, 1.00, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( -0.363117463826178158710752068709, 1.00, 1.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, -1.00, -1.00, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, -1.00, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, -1.00, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, -1.00, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, -1.00, 0.00, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, -1.00, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, -1.00, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, -1.00, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, -1.00, 1.00, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, -0.899757995411460157312345244418, -1.00, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, -0.899757995411460157312345244418, 0.00, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, -0.899757995411460157312345244418, 1.00, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, -0.677186279510737753445885427091, -1.00, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, -0.677186279510737753445885427091, 0.00, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, -0.677186279510737753445885427091, 1.00, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, -0.363117463826178158710752068709, -1.00, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, -0.363117463826178158710752068709, 0.00, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, -0.363117463826178158710752068709, 1.00, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, 0.00, -1.00, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, 0.00, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 0.00, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 0.00, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 0.00, 0.00, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, 0.00, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 0.00, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 0.00, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 0.00, 1.00, 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, 0.363117463826178158710752068709, -1.00, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 0.363117463826178158710752068709, 0.00, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 0.363117463826178158710752068709, 1.00, 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, 0.677186279510737753445885427091, -1.00, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 0.677186279510737753445885427091, 0.00, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 0.677186279510737753445885427091, 1.00, 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, 0.899757995411460157312345244418, -1.00, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 0.899757995411460157312345244418, 0.00, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 0.899757995411460157312345244418, 1.00, 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.00, 1.00, -1.00, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.00, 1.00, -0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 1.00, -0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 1.00, -0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 1.00, 0.00, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.00, 1.00, 0.363117463826178158710752068709, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.00, 1.00, 0.677186279510737753445885427091, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.00, 1.00, 0.899757995411460157312345244418, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.00, 1.00, 1.00, 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, -1.00, -1.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, -1.00, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, -1.00, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, -1.00, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, -1.00, 0.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, -1.00, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, -1.00, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, -1.00, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, -1.00, 1.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, -1.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.899757995411460157312345244418, 1.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, -1.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.677186279510737753445885427091, 1.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, -1.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, -0.363117463826178158710752068709, 1.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, 0.00, -1.00, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.00, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.00, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.00, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.00, 0.00, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.00, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.00, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.00, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.00, 1.00, 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, -1.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.363117463826178158710752068709, 1.00, 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, -1.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.677186279510737753445885427091, 1.00, 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, -1.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 0.899757995411460157312345244418, 1.00, 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.363117463826178158710752068709, 1.00, -1.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.363117463826178158710752068709, 1.00, -0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 1.00, -0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 1.00, -0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 1.00, 0.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.363117463826178158710752068709, 1.00, 0.363117463826178158710752068709, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.363117463826178158710752068709, 1.00, 0.677186279510737753445885427091, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.363117463826178158710752068709, 1.00, 0.899757995411460157312345244418, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.363117463826178158710752068709, 1.00, 1.00, 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, -1.00, -1.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, -1.00, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, -1.00, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, -1.00, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, -1.00, 0.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, -1.00, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, -1.00, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, -1.00, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, -1.00, 1.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, -1.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.899757995411460157312345244418, 1.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, -1.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.677186279510737753445885427091, 1.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, -1.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, -0.363117463826178158710752068709, 1.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, 0.00, -1.00, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.00, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.00, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.00, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.00, 0.00, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.00, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.00, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.00, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.00, 1.00, 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, -1.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.363117463826178158710752068709, 1.00, 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, -1.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.677186279510737753445885427091, 1.00, 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, -1.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 0.899757995411460157312345244418, 1.00, 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.677186279510737753445885427091, 1.00, -1.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.677186279510737753445885427091, 1.00, -0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 1.00, -0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 1.00, -0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 1.00, 0.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.677186279510737753445885427091, 1.00, 0.363117463826178158710752068709, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.677186279510737753445885427091, 1.00, 0.677186279510737753445885427091, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.677186279510737753445885427091, 1.00, 0.899757995411460157312345244418, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.677186279510737753445885427091, 1.00, 1.00, 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, -1.00, -1.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, -1.00, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, -1.00, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, -1.00, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, -1.00, 0.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, -1.00, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, -1.00, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, -1.00, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, -1.00, 1.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, -1.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.899757995411460157312345244418, 1.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, -1.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.677186279510737753445885427091, 1.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, -1.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, -0.363117463826178158710752068709, 1.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, 0.00, -1.00, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.00, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.00, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.00, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.00, 0.00, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.00, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.00, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.00, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.00, 1.00, 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, -1.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.363117463826178158710752068709, 1.00, 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, -1.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.677186279510737753445885427091, 1.00, 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, -1.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 0.899757995411460157312345244418, 1.00, 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 0.899757995411460157312345244418, 1.00, -1.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 0.899757995411460157312345244418, 1.00, -0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 1.00, -0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 1.00, -0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 1.00, 0.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 0.899757995411460157312345244418, 1.00, 0.363117463826178158710752068709, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 0.899757995411460157312345244418, 1.00, 0.677186279510737753445885427091, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 0.899757995411460157312345244418, 1.00, 0.899757995411460157312345244418, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 0.899757995411460157312345244418, 1.00, 1.00, 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, -1.00, -1.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, -1.00, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, -1.00, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, -1.00, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, -1.00, 0.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, -1.00, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, -1.00, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, -1.00, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, -1.00, 1.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, -0.899757995411460157312345244418, -1.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, -0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, -0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, -0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, -0.899757995411460157312345244418, 0.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, -0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, -0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, -0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, -0.899757995411460157312345244418, 1.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, -0.677186279510737753445885427091, -1.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, -0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, -0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, -0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, -0.677186279510737753445885427091, 0.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, -0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, -0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, -0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, -0.677186279510737753445885427091, 1.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, -0.363117463826178158710752068709, -1.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, -0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, -0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, -0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, -0.363117463826178158710752068709, 0.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, -0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, -0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, -0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, -0.363117463826178158710752068709, 1.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, 0.00, -1.00, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, 0.00, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 0.00, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 0.00, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 0.00, 0.00, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, 0.00, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 0.00, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 0.00, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 0.00, 1.00, 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, 0.363117463826178158710752068709, -1.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, 0.363117463826178158710752068709, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 0.363117463826178158710752068709, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 0.363117463826178158710752068709, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 0.363117463826178158710752068709, 0.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, 0.363117463826178158710752068709, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 0.363117463826178158710752068709, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 0.363117463826178158710752068709, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 0.363117463826178158710752068709, 1.00, 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, 0.677186279510737753445885427091, -1.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, 0.677186279510737753445885427091, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 0.677186279510737753445885427091, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 0.677186279510737753445885427091, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 0.677186279510737753445885427091, 0.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, 0.677186279510737753445885427091, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 0.677186279510737753445885427091, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 0.677186279510737753445885427091, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 0.677186279510737753445885427091, 1.00, 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, 0.899757995411460157312345244418, -1.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, 0.899757995411460157312345244418, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 0.899757995411460157312345244418, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 0.899757995411460157312345244418, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 0.899757995411460157312345244418, 0.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, 0.899757995411460157312345244418, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 0.899757995411460157312345244418, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 0.899757995411460157312345244418, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 0.899757995411460157312345244418, 1.00, 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 ),

            IntegrationPointType( 1.00, 1.00, -1.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
            IntegrationPointType( 1.00, 1.00, -0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 1.00, -0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 1.00, -0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 1.00, 0.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 ),
            IntegrationPointType( 1.00, 1.00, 0.363117463826178158710752068709, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 ),
            IntegrationPointType( 1.00, 1.00, 0.677186279510737753445885427091, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 ),
            IntegrationPointType( 1.00, 1.00, 0.899757995411460157312345244418, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 ),
            IntegrationPointType( 1.00, 1.00, 1.00, 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 9";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints9

class HexahedronGaussLobattoIntegrationPoints10
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 3;

    typedef IntegrationPoint<3> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 1000> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 1000;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( -1.00, -1.00, -1.00, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, -1.00, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -1.00, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -1.00, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -1.00, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -1.00, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -1.00, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -1.00, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -1.00, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -1.00, 1.00, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, -0.919533908166458813828932660822, -1.00, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -0.919533908166458813828932660822, 1.00, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, -0.73877386510550507500310617486, -1.00, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -0.73877386510550507500310617486, 1.00, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, -0.477924949810444495661175092731, -1.00, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -0.477924949810444495661175092731, 1.00, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, -0.165278957666387024626219765958, -1.00, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, -0.165278957666387024626219765958, 1.00, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, 0.165278957666387024626219765958, -1.00, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 0.165278957666387024626219765958, 1.00, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, 0.477924949810444495661175092731, -1.00, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 0.477924949810444495661175092731, 1.00, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, 0.73877386510550507500310617486, -1.00, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 0.73877386510550507500310617486, 1.00, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, 0.919533908166458813828932660822, -1.00, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 0.919533908166458813828932660822, 1.00, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -1.00, 1.00, -1.00, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -1.00, 1.00, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 1.00, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 1.00, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 1.00, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 1.00, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -1.00, 1.00, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -1.00, 1.00, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -1.00, 1.00, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -1.00, 1.00, 1.00, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, -1.00, -1.00, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -1.00, 1.00, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, -1.00, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.919533908166458813828932660822, 1.00, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, -1.00, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.73877386510550507500310617486, 1.00, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, -1.00, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.477924949810444495661175092731, 1.00, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, -1.00, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, -0.165278957666387024626219765958, 1.00, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, -1.00, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.165278957666387024626219765958, 1.00, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, -1.00, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.477924949810444495661175092731, 1.00, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, -1.00, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.73877386510550507500310617486, 1.00, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, -1.00, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 0.919533908166458813828932660822, 1.00, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.919533908166458813828932660822, 1.00, -1.00, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.919533908166458813828932660822, 1.00, 1.00, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, -1.00, -1.00, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -1.00, 1.00, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, -1.00, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.919533908166458813828932660822, 1.00, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, -1.00, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.73877386510550507500310617486, 1.00, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, -1.00, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.477924949810444495661175092731, 1.00, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, -1.00, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, -0.165278957666387024626219765958, 1.00, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, -1.00, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.165278957666387024626219765958, 1.00, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, -1.00, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.477924949810444495661175092731, 1.00, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, -1.00, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.73877386510550507500310617486, 1.00, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, -1.00, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 0.919533908166458813828932660822, 1.00, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.73877386510550507500310617486, 1.00, -1.00, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.73877386510550507500310617486, 1.00, 1.00, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, -1.00, -1.00, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -1.00, 1.00, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, -1.00, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.919533908166458813828932660822, 1.00, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, -1.00, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.73877386510550507500310617486, 1.00, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, -1.00, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.477924949810444495661175092731, 1.00, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, -1.00, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, -0.165278957666387024626219765958, 1.00, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, -1.00, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.165278957666387024626219765958, 1.00, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, -1.00, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.477924949810444495661175092731, 1.00, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, -1.00, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.73877386510550507500310617486, 1.00, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, -1.00, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 0.919533908166458813828932660822, 1.00, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.477924949810444495661175092731, 1.00, -1.00, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.477924949810444495661175092731, 1.00, 1.00, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, -1.00, -1.00, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -1.00, 1.00, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, -1.00, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.919533908166458813828932660822, 1.00, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, -1.00, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.73877386510550507500310617486, 1.00, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, -1.00, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.477924949810444495661175092731, 1.00, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, -1.00, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, -0.165278957666387024626219765958, 1.00, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, -1.00, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.165278957666387024626219765958, 1.00, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, -1.00, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.477924949810444495661175092731, 1.00, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, -1.00, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.73877386510550507500310617486, 1.00, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, -1.00, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 0.919533908166458813828932660822, 1.00, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( -0.165278957666387024626219765958, 1.00, -1.00, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( -0.165278957666387024626219765958, 1.00, 1.00, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, -1.00, -1.00, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -1.00, 1.00, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, -1.00, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.919533908166458813828932660822, 1.00, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, -1.00, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.73877386510550507500310617486, 1.00, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, -1.00, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.477924949810444495661175092731, 1.00, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, -1.00, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, -0.165278957666387024626219765958, 1.00, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, -1.00, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.165278957666387024626219765958, 1.00, 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, -1.00, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.477924949810444495661175092731, 1.00, 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, -1.00, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.73877386510550507500310617486, 1.00, 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, -1.00, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 0.919533908166458813828932660822, 1.00, 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.165278957666387024626219765958, 1.00, -1.00, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, -0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, -0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, -0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, -0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, 0.165278957666387024626219765958, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, 0.477924949810444495661175092731, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, 0.73877386510550507500310617486, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, 0.919533908166458813828932660822, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.165278957666387024626219765958, 1.00, 1.00, 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, -1.00, -1.00, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -1.00, 1.00, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, -1.00, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.919533908166458813828932660822, 1.00, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, -1.00, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.73877386510550507500310617486, 1.00, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, -1.00, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.477924949810444495661175092731, 1.00, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, -1.00, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, -0.165278957666387024626219765958, 1.00, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, -1.00, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.165278957666387024626219765958, 1.00, 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, -1.00, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.477924949810444495661175092731, 1.00, 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, -1.00, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.73877386510550507500310617486, 1.00, 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, -1.00, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 0.919533908166458813828932660822, 1.00, 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.477924949810444495661175092731, 1.00, -1.00, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, -0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, -0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, -0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, -0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, 0.165278957666387024626219765958, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, 0.477924949810444495661175092731, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, 0.73877386510550507500310617486, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, 0.919533908166458813828932660822, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.477924949810444495661175092731, 1.00, 1.00, 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, -1.00, -1.00, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -1.00, 1.00, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, -1.00, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.919533908166458813828932660822, 1.00, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, -1.00, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.73877386510550507500310617486, 1.00, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, -1.00, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.477924949810444495661175092731, 1.00, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, -1.00, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, -0.165278957666387024626219765958, 1.00, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, -1.00, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.165278957666387024626219765958, 1.00, 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, -1.00, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.477924949810444495661175092731, 1.00, 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, -1.00, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.73877386510550507500310617486, 1.00, 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, -1.00, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 0.919533908166458813828932660822, 1.00, 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.73877386510550507500310617486, 1.00, -1.00, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, -0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, -0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, -0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, -0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, 0.165278957666387024626219765958, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, 0.477924949810444495661175092731, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, 0.73877386510550507500310617486, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, 0.919533908166458813828932660822, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.73877386510550507500310617486, 1.00, 1.00, 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, -1.00, -1.00, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -1.00, 1.00, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, -1.00, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.919533908166458813828932660822, 1.00, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, -1.00, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.73877386510550507500310617486, 1.00, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, -1.00, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.477924949810444495661175092731, 1.00, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, -1.00, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, -0.165278957666387024626219765958, 1.00, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, -1.00, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.165278957666387024626219765958, 1.00, 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, -1.00, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.477924949810444495661175092731, 1.00, 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, -1.00, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.73877386510550507500310617486, 1.00, 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, -1.00, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 0.919533908166458813828932660822, 1.00, 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 0.919533908166458813828932660822, 1.00, -1.00, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, -0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, -0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, -0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, -0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, 0.165278957666387024626219765958, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, 0.477924949810444495661175092731, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, 0.73877386510550507500310617486, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, 0.919533908166458813828932660822, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 0.919533908166458813828932660822, 1.00, 1.00, 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, -1.00, -1.00, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, -1.00, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -1.00, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -1.00, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -1.00, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -1.00, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -1.00, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -1.00, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -1.00, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -1.00, 1.00, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, -0.919533908166458813828932660822, -1.00, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -0.919533908166458813828932660822, 1.00, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, -0.73877386510550507500310617486, -1.00, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -0.73877386510550507500310617486, 1.00, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, -0.477924949810444495661175092731, -1.00, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -0.477924949810444495661175092731, 1.00, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, -0.165278957666387024626219765958, -1.00, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, -0.165278957666387024626219765958, 1.00, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, 0.165278957666387024626219765958, -1.00, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 0.165278957666387024626219765958, 1.00, 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, 0.477924949810444495661175092731, -1.00, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 0.477924949810444495661175092731, 1.00, 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, 0.73877386510550507500310617486, -1.00, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 0.73877386510550507500310617486, 1.00, 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, 0.919533908166458813828932660822, -1.00, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 0.919533908166458813828932660822, 1.00, 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 ),

            IntegrationPointType( 1.00, 1.00, -1.00, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
            IntegrationPointType( 1.00, 1.00, -0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 1.00, -0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 1.00, -0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 1.00, -0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 1.00, 0.165278957666387024626219765958, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 ),
            IntegrationPointType( 1.00, 1.00, 0.477924949810444495661175092731, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 ),
            IntegrationPointType( 1.00, 1.00, 0.73877386510550507500310617486, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 ),
            IntegrationPointType( 1.00, 1.00, 0.919533908166458813828932660822, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 ),
            IntegrationPointType( 1.00, 1.00, 1.00, 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 ),
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 10";
        return buffer.str();
    }
}; // Class HexahedronGaussLobattoIntegrationPoints10

///@name Type Definitions
///@{

template<int TDegree>
class HexahedronGaussLobattoIntegrationPoints;

template<>
class HexahedronGaussLobattoIntegrationPoints<1> : public HexahedronGaussLobattoIntegrationPoints1
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<2> : public HexahedronGaussLobattoIntegrationPoints2
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<3> : public HexahedronGaussLobattoIntegrationPoints3
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<4> : public HexahedronGaussLobattoIntegrationPoints4
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<5> : public HexahedronGaussLobattoIntegrationPoints5
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<6> : public HexahedronGaussLobattoIntegrationPoints6
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<7> : public HexahedronGaussLobattoIntegrationPoints7
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<8> : public HexahedronGaussLobattoIntegrationPoints8
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<9> : public HexahedronGaussLobattoIntegrationPoints9
{};

template<>
class HexahedronGaussLobattoIntegrationPoints<10> : public HexahedronGaussLobattoIntegrationPoints10
{};

}

#endif // KRATOS_HEXAHEDRON_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED defined
