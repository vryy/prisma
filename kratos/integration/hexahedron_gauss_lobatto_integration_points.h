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

//TO BE COMPLETED: Only the needed ones have been implemented

namespace Kratos
{

//TODO
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints1
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( 0.00 , 0.00, 0.00, 8.00 );
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 1 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;
    
}; // Class HexahedronGaussLobattoIntegrationPoints1

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints2
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        // This is added to solve the problem of static initialization. Pooyan.
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00, -1.00, 1.00 );
        msIntegrationPoints[1] = IntegrationPointType(  1.00 , -1.00, -1.00, 1.00 );
        msIntegrationPoints[2] = IntegrationPointType(  1.00 ,  1.00, -1.00, 1.00 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00 ,  1.00, -1.00, 1.00 );
		
        msIntegrationPoints[4] = IntegrationPointType( -1.00 , -1.00,  1.00, 1.00 );
        msIntegrationPoints[5] = IntegrationPointType(  1.00 , -1.00,  1.00, 1.00 );
        msIntegrationPoints[6] = IntegrationPointType(  1.00 ,  1.00,  1.00, 1.00 );
        msIntegrationPoints[7] = IntegrationPointType( -1.00 ,  1.00,  1.00, 1.00 );
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 2 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints2

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints3
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00 , -1.00 , 1.00/3.00 * 1.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[1] = IntegrationPointType( -1.00 , -1.00 , 0.00 , 1.00/3.00 * 1.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[2] = IntegrationPointType( -1.00 , -1.00 , 1.00 , 1.00/3.00 * 1.00/3.00 * 1.00/3.00 );

        msIntegrationPoints[3] = IntegrationPointType( -1.00 , 0.00 , -1.00 , 1.00/3.00 * 4.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[4] = IntegrationPointType( -1.00 , 0.00 , 0.00 , 1.00/3.00 * 4.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[5] = IntegrationPointType( -1.00 , 0.00 , 1.00 , 1.00/3.00 * 4.00/3.00 * 1.00/3.00 );

        msIntegrationPoints[6] = IntegrationPointType( -1.00 , 1.00 , -1.00 , 1.00/3.00 * 1.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[7] = IntegrationPointType( -1.00 , 1.00 , 0.00 , 1.00/3.00 * 1.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[8] = IntegrationPointType( -1.00 , 1.00 , 1.00 , 1.00/3.00 * 1.00/3.00 * 1.00/3.00 );

        msIntegrationPoints[9] = IntegrationPointType( 0.00 , -1.00 , -1.00 , 4.00/3.00 * 1.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[10] = IntegrationPointType( 0.00 , -1.00 , 0.00 , 4.00/3.00 * 1.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[11] = IntegrationPointType( 0.00 , -1.00 , 1.00 , 4.00/3.00 * 1.00/3.00 * 1.00/3.00 );

        msIntegrationPoints[12] = IntegrationPointType( 0.00 , 0.00 , -1.00 , 4.00/3.00 * 4.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[13] = IntegrationPointType( 0.00 , 0.00 , 0.00 , 4.00/3.00 * 4.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[14] = IntegrationPointType( 0.00 , 0.00 , 1.00 , 4.00/3.00 * 4.00/3.00 * 1.00/3.00 );

        msIntegrationPoints[15] = IntegrationPointType( 0.00 , 1.00 , -1.00 , 4.00/3.00 * 1.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[16] = IntegrationPointType( 0.00 , 1.00 , 0.00 , 4.00/3.00 * 1.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[17] = IntegrationPointType( 0.00 , 1.00 , 1.00 , 4.00/3.00 * 1.00/3.00 * 1.00/3.00 );

        msIntegrationPoints[18] = IntegrationPointType( 1.00 , -1.00 , -1.00 , 1.00/3.00 * 1.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[19] = IntegrationPointType( 1.00 , -1.00 , 0.00 , 1.00/3.00 * 1.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[20] = IntegrationPointType( 1.00 , -1.00 , 1.00 , 1.00/3.00 * 1.00/3.00 * 1.00/3.00 );

        msIntegrationPoints[21] = IntegrationPointType( 1.00 , 0.00 , -1.00 , 1.00/3.00 * 4.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[22] = IntegrationPointType( 1.00 , 0.00 , 0.00 , 1.00/3.00 * 4.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[23] = IntegrationPointType( 1.00 , 0.00 , 1.00 , 1.00/3.00 * 4.00/3.00 * 1.00/3.00 );

        msIntegrationPoints[24] = IntegrationPointType( 1.00 , 1.00 , -1.00 , 1.00/3.00 * 1.00/3.00 * 1.00/3.00 );
        msIntegrationPoints[25] = IntegrationPointType( 1.00 , 1.00 , 0.00 , 1.00/3.00 * 1.00/3.00 * 4.00/3.00 );
        msIntegrationPoints[26] = IntegrationPointType( 1.00 , 1.00 , 1.00 , 1.00/3.00 * 1.00/3.00 * 1.00/3.00 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 3 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints3

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints4
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00 , -1.00 , 1.00/6.00 * 1.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[1] = IntegrationPointType( -1.00 , -1.00 , -std::sqrt(5.00)/5.00 , 1.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[2] = IntegrationPointType( -1.00 , -1.00 , std::sqrt(5.00)/5.00 , 1.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00 , -1.00 , 1.00 , 1.00/6.00 * 1.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[4] = IntegrationPointType( -1.00 , -std::sqrt(5.00)/5.00 , -1.00 , 1.00/6.00 * 5.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[5] = IntegrationPointType( -1.00 , -std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 1.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[6] = IntegrationPointType( -1.00 , -std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 1.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[7] = IntegrationPointType( -1.00 , -std::sqrt(5.00)/5.00 , 1.00 , 1.00/6.00 * 5.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[8] = IntegrationPointType( -1.00 , std::sqrt(5.00)/5.00 , -1.00 , 1.00/6.00 * 5.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[9] = IntegrationPointType( -1.00 , std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 1.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[10] = IntegrationPointType( -1.00 , std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 1.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[11] = IntegrationPointType( -1.00 , std::sqrt(5.00)/5.00 , 1.00 , 1.00/6.00 * 5.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[12] = IntegrationPointType( -1.00 , 1.00 , -1.00 , 1.00/6.00 * 1.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[13] = IntegrationPointType( -1.00 , 1.00 , -std::sqrt(5.00)/5.00 , 1.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[14] = IntegrationPointType( -1.00 , 1.00 , std::sqrt(5.00)/5.00 , 1.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[15] = IntegrationPointType( -1.00 , 1.00 , 1.00 , 1.00/6.00 * 1.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[16] = IntegrationPointType( -std::sqrt(5.00)/5.00 , -1.00 , -1.00 , 5.00/6.00 * 1.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[17] = IntegrationPointType( -std::sqrt(5.00)/5.00 , -1.00 , -std::sqrt(5.00)/5.00 , 5.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[18] = IntegrationPointType( -std::sqrt(5.00)/5.00 , -1.00 , std::sqrt(5.00)/5.00 , 5.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[19] = IntegrationPointType( -std::sqrt(5.00)/5.00 , -1.00 , 1.00 , 5.00/6.00 * 1.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[20] = IntegrationPointType( -std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , -1.00 , 5.00/6.00 * 5.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[21] = IntegrationPointType( -std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 5.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[22] = IntegrationPointType( -std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 5.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[23] = IntegrationPointType( -std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 1.00 , 5.00/6.00 * 5.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[24] = IntegrationPointType( -std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , -1.00 , 5.00/6.00 * 5.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[25] = IntegrationPointType( -std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 5.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[26] = IntegrationPointType( -std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 5.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[27] = IntegrationPointType( -std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 1.00 , 5.00/6.00 * 5.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[28] = IntegrationPointType( -std::sqrt(5.00)/5.00 , 1.00 , -1.00 , 5.00/6.00 * 1.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[29] = IntegrationPointType( -std::sqrt(5.00)/5.00 , 1.00 , -std::sqrt(5.00)/5.00 , 5.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[30] = IntegrationPointType( -std::sqrt(5.00)/5.00 , 1.00 , std::sqrt(5.00)/5.00 , 5.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[31] = IntegrationPointType( -std::sqrt(5.00)/5.00 , 1.00 , 1.00 , 5.00/6.00 * 1.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[32] = IntegrationPointType( std::sqrt(5.00)/5.00 , -1.00 , -1.00 , 5.00/6.00 * 1.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[33] = IntegrationPointType( std::sqrt(5.00)/5.00 , -1.00 , -std::sqrt(5.00)/5.00 , 5.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[34] = IntegrationPointType( std::sqrt(5.00)/5.00 , -1.00 , std::sqrt(5.00)/5.00 , 5.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[35] = IntegrationPointType( std::sqrt(5.00)/5.00 , -1.00 , 1.00 , 5.00/6.00 * 1.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[36] = IntegrationPointType( std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , -1.00 , 5.00/6.00 * 5.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[37] = IntegrationPointType( std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 5.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[38] = IntegrationPointType( std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 5.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[39] = IntegrationPointType( std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 1.00 , 5.00/6.00 * 5.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[40] = IntegrationPointType( std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , -1.00 , 5.00/6.00 * 5.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[41] = IntegrationPointType( std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 5.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[42] = IntegrationPointType( std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 5.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[43] = IntegrationPointType( std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 1.00 , 5.00/6.00 * 5.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[44] = IntegrationPointType( std::sqrt(5.00)/5.00 , 1.00 , -1.00 , 5.00/6.00 * 1.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[45] = IntegrationPointType( std::sqrt(5.00)/5.00 , 1.00 , -std::sqrt(5.00)/5.00 , 5.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[46] = IntegrationPointType( std::sqrt(5.00)/5.00 , 1.00 , std::sqrt(5.00)/5.00 , 5.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[47] = IntegrationPointType( std::sqrt(5.00)/5.00 , 1.00 , 1.00 , 5.00/6.00 * 1.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[48] = IntegrationPointType( 1.00 , -1.00 , -1.00 , 1.00/6.00 * 1.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[49] = IntegrationPointType( 1.00 , -1.00 , -std::sqrt(5.00)/5.00 , 1.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[50] = IntegrationPointType( 1.00 , -1.00 , std::sqrt(5.00)/5.00 , 1.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[51] = IntegrationPointType( 1.00 , -1.00 , 1.00 , 1.00/6.00 * 1.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[52] = IntegrationPointType( 1.00 , -std::sqrt(5.00)/5.00 , -1.00 , 1.00/6.00 * 5.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[53] = IntegrationPointType( 1.00 , -std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 1.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[54] = IntegrationPointType( 1.00 , -std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 1.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[55] = IntegrationPointType( 1.00 , -std::sqrt(5.00)/5.00 , 1.00 , 1.00/6.00 * 5.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[56] = IntegrationPointType( 1.00 , std::sqrt(5.00)/5.00 , -1.00 , 1.00/6.00 * 5.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[57] = IntegrationPointType( 1.00 , std::sqrt(5.00)/5.00 , -std::sqrt(5.00)/5.00 , 1.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[58] = IntegrationPointType( 1.00 , std::sqrt(5.00)/5.00 , std::sqrt(5.00)/5.00 , 1.00/6.00 * 5.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[59] = IntegrationPointType( 1.00 , std::sqrt(5.00)/5.00 , 1.00 , 1.00/6.00 * 5.00/6.00 * 1.00/6.00 );

        msIntegrationPoints[60] = IntegrationPointType( 1.00 , 1.00 , -1.00 , 1.00/6.00 * 1.00/6.00 * 1.00/6.00 );
        msIntegrationPoints[61] = IntegrationPointType( 1.00 , 1.00 , -std::sqrt(5.00)/5.00 , 1.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[62] = IntegrationPointType( 1.00 , 1.00 , std::sqrt(5.00)/5.00 , 1.00/6.00 * 1.00/6.00 * 5.00/6.00 );
        msIntegrationPoints[63] = IntegrationPointType( 1.00 , 1.00 , 1.00 , 1.00/6.00 * 1.00/6.00 * 1.00/6.00 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 4 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints4

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints5
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00 , -1.00 , 1.00/10.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[1] = IntegrationPointType( -1.00 , -1.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[2] = IntegrationPointType( -1.00 , -1.00 , 0.00 , 1.00/10.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00 , -1.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[4] = IntegrationPointType( -1.00 , -1.00 , 1.00 , 1.00/10.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[5] = IntegrationPointType( -1.00 , -std::sqrt(21.00)/7.00 , -1.00 , 1.00/10.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[6] = IntegrationPointType( -1.00 , -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[7] = IntegrationPointType( -1.00 , -std::sqrt(21.00)/7.00 , 0.00 , 1.00/10.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[8] = IntegrationPointType( -1.00 , -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[9] = IntegrationPointType( -1.00 , -std::sqrt(21.00)/7.00 , 1.00 , 1.00/10.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[10] = IntegrationPointType( -1.00 , 0.00 , -1.00 , 1.00/10.00 * 32.00/45.00 * 1.00/10.00 );
        msIntegrationPoints[11] = IntegrationPointType( -1.00 , 0.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[12] = IntegrationPointType( -1.00 , 0.00 , 0.00 , 1.00/10.00 * 32.00/45.00 * 32.00/45.00 );
        msIntegrationPoints[13] = IntegrationPointType( -1.00 , 0.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[14] = IntegrationPointType( -1.00 , 0.00 , 1.00 , 1.00/10.00 * 32.00/45.00 * 1.00/10.00 );

        msIntegrationPoints[15] = IntegrationPointType( -1.00 , std::sqrt(21.00)/7.00 , -1.00 , 1.00/10.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[16] = IntegrationPointType( -1.00 , std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[17] = IntegrationPointType( -1.00 , std::sqrt(21.00)/7.00 , 0.00 , 1.00/10.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[18] = IntegrationPointType( -1.00 , std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[19] = IntegrationPointType( -1.00 , std::sqrt(21.00)/7.00 , 1.00 , 1.00/10.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[20] = IntegrationPointType( -1.00 , 1.00 , -1.00 , 1.00/10.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[21] = IntegrationPointType( -1.00 , 1.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[22] = IntegrationPointType( -1.00 , 1.00 , 0.00 , 1.00/10.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[23] = IntegrationPointType( -1.00 , 1.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[24] = IntegrationPointType( -1.00 , 1.00 , 1.00 , 1.00/10.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[25] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -1.00 , -1.00 , 49.00/90.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[26] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -1.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[27] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -1.00 , 0.00 , 49.00/90.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[28] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -1.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[29] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -1.00 , 1.00 , 49.00/90.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[30] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , -1.00 , 49.00/90.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[31] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[32] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 0.00 , 49.00/90.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[33] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[34] = IntegrationPointType( -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 1.00 , 49.00/90.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[35] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 0.00 , -1.00 , 49.00/90.00 * 32.00/45.00 * 1.00/10.00 );
        msIntegrationPoints[36] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 0.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[37] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 0.00 , 0.00 , 49.00/90.00 * 32.00/45.00 * 32.00/45.00 );
        msIntegrationPoints[38] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 0.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[39] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 0.00 , 1.00 , 49.00/90.00 * 32.00/45.00 * 1.00/10.00 );

        msIntegrationPoints[40] = IntegrationPointType( -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , -1.00 , 49.00/90.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[41] = IntegrationPointType( -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[42] = IntegrationPointType( -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 0.00 , 49.00/90.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[43] = IntegrationPointType( -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[44] = IntegrationPointType( -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 1.00 , 49.00/90.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[45] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 1.00 , -1.00 , 49.00/90.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[46] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 1.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[47] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 1.00 , 0.00 , 49.00/90.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[48] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 1.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[49] = IntegrationPointType( -std::sqrt(21.00)/7.00 , 1.00 , 1.00 , 49.00/90.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[50] = IntegrationPointType( 0.00 , -1.00 , -1.00 , 32.00/45.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[51] = IntegrationPointType( 0.00 , -1.00 , -std::sqrt(21.00)/7.00 , 32.00/45.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[52] = IntegrationPointType( 0.00 , -1.00 , 0.00 , 32.00/45.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[53] = IntegrationPointType( 0.00 , -1.00 , std::sqrt(21.00)/7.00 , 32.00/45.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[54] = IntegrationPointType( 0.00 , -1.00 , 1.00 , 32.00/45.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[55] = IntegrationPointType( 0.00 , -std::sqrt(21.00)/7.00 , -1.00 , 32.00/45.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[56] = IntegrationPointType( 0.00 , -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 32.00/45.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[57] = IntegrationPointType( 0.00 , -std::sqrt(21.00)/7.00 , 0.00 , 32.00/45.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[58] = IntegrationPointType( 0.00 , -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 32.00/45.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[59] = IntegrationPointType( 0.00 , -std::sqrt(21.00)/7.00 , 1.00 , 32.00/45.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[60] = IntegrationPointType( 0.00 , 0.00 , -1.00 , 32.00/45.00 * 32.00/45.00 * 1.00/10.00 );
        msIntegrationPoints[61] = IntegrationPointType( 0.00 , 0.00 , -std::sqrt(21.00)/7.00 , 32.00/45.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[62] = IntegrationPointType( 0.00 , 0.00 , 0.00 , 32.00/45.00 * 32.00/45.00 * 32.00/45.00 );
        msIntegrationPoints[63] = IntegrationPointType( 0.00 , 0.00 , std::sqrt(21.00)/7.00 , 32.00/45.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[64] = IntegrationPointType( 0.00 , 0.00 , 1.00 , 32.00/45.00 * 32.00/45.00 * 1.00/10.00 );

        msIntegrationPoints[65] = IntegrationPointType( 0.00 , std::sqrt(21.00)/7.00 , -1.00 , 32.00/45.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[66] = IntegrationPointType( 0.00 , std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 32.00/45.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[67] = IntegrationPointType( 0.00 , std::sqrt(21.00)/7.00 , 0.00 , 32.00/45.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[68] = IntegrationPointType( 0.00 , std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 32.00/45.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[69] = IntegrationPointType( 0.00 , std::sqrt(21.00)/7.00 , 1.00 , 32.00/45.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[70] = IntegrationPointType( 0.00 , 1.00 , -1.00 , 32.00/45.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[71] = IntegrationPointType( 0.00 , 1.00 , -std::sqrt(21.00)/7.00 , 32.00/45.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[72] = IntegrationPointType( 0.00 , 1.00 , 0.00 , 32.00/45.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[73] = IntegrationPointType( 0.00 , 1.00 , std::sqrt(21.00)/7.00 , 32.00/45.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[74] = IntegrationPointType( 0.00 , 1.00 , 1.00 , 32.00/45.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[75] = IntegrationPointType( std::sqrt(21.00)/7.00 , -1.00 , -1.00 , 49.00/90.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[76] = IntegrationPointType( std::sqrt(21.00)/7.00 , -1.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[77] = IntegrationPointType( std::sqrt(21.00)/7.00 , -1.00 , 0.00 , 49.00/90.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[78] = IntegrationPointType( std::sqrt(21.00)/7.00 , -1.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[79] = IntegrationPointType( std::sqrt(21.00)/7.00 , -1.00 , 1.00 , 49.00/90.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[80] = IntegrationPointType( std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , -1.00 , 49.00/90.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[81] = IntegrationPointType( std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[82] = IntegrationPointType( std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 0.00 , 49.00/90.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[83] = IntegrationPointType( std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[84] = IntegrationPointType( std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 1.00 , 49.00/90.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[85] = IntegrationPointType( std::sqrt(21.00)/7.00 , 0.00 , -1.00 , 49.00/90.00 * 32.00/45.00 * 1.00/10.00 );
        msIntegrationPoints[86] = IntegrationPointType( std::sqrt(21.00)/7.00 , 0.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[87] = IntegrationPointType( std::sqrt(21.00)/7.00 , 0.00 , 0.00 , 49.00/90.00 * 32.00/45.00 * 32.00/45.00 );
        msIntegrationPoints[88] = IntegrationPointType( std::sqrt(21.00)/7.00 , 0.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[89] = IntegrationPointType( std::sqrt(21.00)/7.00 , 0.00 , 1.00 , 49.00/90.00 * 32.00/45.00 * 1.00/10.00 );

        msIntegrationPoints[90] = IntegrationPointType( std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , -1.00 , 49.00/90.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[91] = IntegrationPointType( std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[92] = IntegrationPointType( std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 0.00 , 49.00/90.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[93] = IntegrationPointType( std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[94] = IntegrationPointType( std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 1.00 , 49.00/90.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[95] = IntegrationPointType( std::sqrt(21.00)/7.00 , 1.00 , -1.00 , 49.00/90.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[96] = IntegrationPointType( std::sqrt(21.00)/7.00 , 1.00 , -std::sqrt(21.00)/7.00 , 49.00/90.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[97] = IntegrationPointType( std::sqrt(21.00)/7.00 , 1.00 , 0.00 , 49.00/90.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[98] = IntegrationPointType( std::sqrt(21.00)/7.00 , 1.00 , std::sqrt(21.00)/7.00 , 49.00/90.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[99] = IntegrationPointType( std::sqrt(21.00)/7.00 , 1.00 , 1.00 , 49.00/90.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[100] = IntegrationPointType( 1.00 , -1.00 , -1.00 , 1.00/10.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[101] = IntegrationPointType( 1.00 , -1.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[102] = IntegrationPointType( 1.00 , -1.00 , 0.00 , 1.00/10.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[103] = IntegrationPointType( 1.00 , -1.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[104] = IntegrationPointType( 1.00 , -1.00 , 1.00 , 1.00/10.00 * 1.00/10.00 * 1.00/10.00 );

        msIntegrationPoints[105] = IntegrationPointType( 1.00 , -std::sqrt(21.00)/7.00 , -1.00 , 1.00/10.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[106] = IntegrationPointType( 1.00 , -std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[107] = IntegrationPointType( 1.00 , -std::sqrt(21.00)/7.00 , 0.00 , 1.00/10.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[108] = IntegrationPointType( 1.00 , -std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[109] = IntegrationPointType( 1.00 , -std::sqrt(21.00)/7.00 , 1.00 , 1.00/10.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[110] = IntegrationPointType( 1.00 , 0.00 , -1.00 , 1.00/10.00 * 32.00/45.00 * 1.00/10.00 );
        msIntegrationPoints[111] = IntegrationPointType( 1.00 , 0.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[112] = IntegrationPointType( 1.00 , 0.00 , 0.00 , 1.00/10.00 * 32.00/45.00 * 32.00/45.00 );
        msIntegrationPoints[113] = IntegrationPointType( 1.00 , 0.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 32.00/45.00 * 49.00/90.00 );
        msIntegrationPoints[114] = IntegrationPointType( 1.00 , 0.00 , 1.00 , 1.00/10.00 * 32.00/45.00 * 1.00/10.00 );

        msIntegrationPoints[115] = IntegrationPointType( 1.00 , std::sqrt(21.00)/7.00 , -1.00 , 1.00/10.00 * 49.00/90.00 * 1.00/10.00 );
        msIntegrationPoints[116] = IntegrationPointType( 1.00 , std::sqrt(21.00)/7.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[117] = IntegrationPointType( 1.00 , std::sqrt(21.00)/7.00 , 0.00 , 1.00/10.00 * 49.00/90.00 * 32.00/45.00 );
        msIntegrationPoints[118] = IntegrationPointType( 1.00 , std::sqrt(21.00)/7.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 49.00/90.00 * 49.00/90.00 );
        msIntegrationPoints[119] = IntegrationPointType( 1.00 , std::sqrt(21.00)/7.00 , 1.00 , 1.00/10.00 * 49.00/90.00 * 1.00/10.00 );

        msIntegrationPoints[120] = IntegrationPointType( 1.00 , 1.00 , -1.00 , 1.00/10.00 * 1.00/10.00 * 1.00/10.00 );
        msIntegrationPoints[121] = IntegrationPointType( 1.00 , 1.00 , -std::sqrt(21.00)/7.00 , 1.00/10.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[122] = IntegrationPointType( 1.00 , 1.00 , 0.00 , 1.00/10.00 * 1.00/10.00 * 32.00/45.00 );
        msIntegrationPoints[123] = IntegrationPointType( 1.00 , 1.00 , std::sqrt(21.00)/7.00 , 1.00/10.00 * 1.00/10.00 * 49.00/90.00 );
        msIntegrationPoints[124] = IntegrationPointType( 1.00 , 1.00 , 1.00 , 1.00/10.00 * 1.00/10.00 * 1.00/10.00 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 5";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints5

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints6
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00 , -1.00 , 1.00/15.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[1] = IntegrationPointType( -1.00 , -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[2] = IntegrationPointType( -1.00 , -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00 , -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[4] = IntegrationPointType( -1.00 , -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[5] = IntegrationPointType( -1.00 , -1.00 , 1.00 , 1.00/15.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[6] = IntegrationPointType( -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[7] = IntegrationPointType( -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[8] = IntegrationPointType( -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[9] = IntegrationPointType( -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[10] = IntegrationPointType( -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[11] = IntegrationPointType( -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[12] = IntegrationPointType( -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[13] = IntegrationPointType( -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[14] = IntegrationPointType( -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[15] = IntegrationPointType( -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[16] = IntegrationPointType( -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[17] = IntegrationPointType( -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[18] = IntegrationPointType( -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[19] = IntegrationPointType( -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[20] = IntegrationPointType( -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[21] = IntegrationPointType( -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[22] = IntegrationPointType( -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[23] = IntegrationPointType( -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[24] = IntegrationPointType( -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[25] = IntegrationPointType( -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[26] = IntegrationPointType( -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[27] = IntegrationPointType( -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[28] = IntegrationPointType( -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[29] = IntegrationPointType( -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[30] = IntegrationPointType( -1.00 , 1.00 , -1.00 , 1.00/15.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[31] = IntegrationPointType( -1.00 , 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[32] = IntegrationPointType( -1.00 , 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[33] = IntegrationPointType( -1.00 , 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[34] = IntegrationPointType( -1.00 , 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[35] = IntegrationPointType( -1.00 , 1.00 , 1.00 , 1.00/15.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[36] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , -1.00 , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[37] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[38] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[39] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[40] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[41] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00 , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[42] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[43] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[44] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[45] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[46] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[47] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[48] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[49] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[50] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[51] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[52] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[53] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[54] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[55] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[56] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[57] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[58] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[59] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[60] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[61] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[62] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[63] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[64] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[65] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[66] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , -1.00 , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[67] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[68] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[69] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[70] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[71] = IntegrationPointType( -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00 , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[72] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , -1.00 , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[73] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[74] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[75] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[76] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[77] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00 , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[78] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[79] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[80] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[81] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[82] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[83] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[84] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[85] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[86] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[87] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[88] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[89] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[90] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[91] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[92] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[93] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[94] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[95] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[96] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[97] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[98] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[99] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[100] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[101] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[102] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , -1.00 , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[103] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[104] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[105] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[106] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[107] = IntegrationPointType( -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00 , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[108] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , -1.00 , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[109] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[110] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[111] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[112] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[113] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00 , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[114] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[115] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[116] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[117] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[118] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[119] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[120] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[121] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[122] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[123] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[124] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[125] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[126] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[127] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[128] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[129] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[130] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[131] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[132] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[133] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[134] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[135] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[136] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[137] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[138] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , -1.00 , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[139] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[140] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[141] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[142] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[143] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00 , (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[144] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , -1.00 , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[145] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[146] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[147] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[148] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[149] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00 , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[150] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[151] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[152] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[153] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[154] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[155] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[156] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[157] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[158] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[159] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[160] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[161] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[162] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[163] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[164] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[165] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[166] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[167] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[168] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[169] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[170] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[171] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[172] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[173] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[174] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , -1.00 , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[175] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[176] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[177] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[178] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[179] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00 , (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[180] = IntegrationPointType( 1.00 , -1.00 , -1.00 , 1.00/15.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[181] = IntegrationPointType( 1.00 , -1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[182] = IntegrationPointType( 1.00 , -1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[183] = IntegrationPointType( 1.00 , -1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[184] = IntegrationPointType( 1.00 , -1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[185] = IntegrationPointType( 1.00 , -1.00 , 1.00 , 1.00/15.00 * 1.00/15.00 * 1.00/15.00 );

        msIntegrationPoints[186] = IntegrationPointType( 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[187] = IntegrationPointType( 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[188] = IntegrationPointType( 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[189] = IntegrationPointType( 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[190] = IntegrationPointType( 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[191] = IntegrationPointType( 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[192] = IntegrationPointType( 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[193] = IntegrationPointType( 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[194] = IntegrationPointType( 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[195] = IntegrationPointType( 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[196] = IntegrationPointType( 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[197] = IntegrationPointType( 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[198] = IntegrationPointType( 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[199] = IntegrationPointType( 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[200] = IntegrationPointType( 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[201] = IntegrationPointType( 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[202] = IntegrationPointType( 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[203] = IntegrationPointType( 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[204] = IntegrationPointType( 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -1.00 , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );
        msIntegrationPoints[205] = IntegrationPointType( 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[206] = IntegrationPointType( 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[207] = IntegrationPointType( 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[208] = IntegrationPointType( 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[209] = IntegrationPointType( 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00 , 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 * 1.00/15.00 );

        msIntegrationPoints[210] = IntegrationPointType( 1.00 , 1.00 , -1.00 , 1.00/15.00 * 1.00/15.00 * 1.00/15.00 );
        msIntegrationPoints[211] = IntegrationPointType( 1.00 , 1.00 , -std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[212] = IntegrationPointType( 1.00 , 1.00 , -std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[213] = IntegrationPointType( 1.00 , 1.00 , std::sqrt((7.00-2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00+std::sqrt(7.00))/30.00 );
        msIntegrationPoints[214] = IntegrationPointType( 1.00 , 1.00 , std::sqrt((7.00+2.00*std::sqrt(7.00))/21.00) , 1.00/15.00 * 1.00/15.00 * (14.00-std::sqrt(7.00))/30.00 );
        msIntegrationPoints[215] = IntegrationPointType( 1.00 , 1.00 , 1.00 , 1.00/15.00 * 1.00/15.00 * 1.00/15.00 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 6";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints6

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints7
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00 , -1.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[1] = IntegrationPointType( -1.00 , -1.00 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[2] = IntegrationPointType( -1.00 , -1.00 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00 , -1.00 , 0.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[4] = IntegrationPointType( -1.00 , -1.00 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[5] = IntegrationPointType( -1.00 , -1.00 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[6] = IntegrationPointType( -1.00 , -1.00 , 1.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[7] = IntegrationPointType( -1.00 , -0.830223896278566929872032213967 , -1.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[8] = IntegrationPointType( -1.00 , -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[9] = IntegrationPointType( -1.00 , -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[10] = IntegrationPointType( -1.00 , -0.830223896278566929872032213967 , 0.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[11] = IntegrationPointType( -1.00 , -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[12] = IntegrationPointType( -1.00 , -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[13] = IntegrationPointType( -1.00 , -0.830223896278566929872032213967 , 1.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[14] = IntegrationPointType( -1.00 , -0.468848793470714213803771881909 , -1.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[15] = IntegrationPointType( -1.00 , -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[16] = IntegrationPointType( -1.00 , -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[17] = IntegrationPointType( -1.00 , -0.468848793470714213803771881909 , 0.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[18] = IntegrationPointType( -1.00 , -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[19] = IntegrationPointType( -1.00 , -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[20] = IntegrationPointType( -1.00 , -0.468848793470714213803771881909 , 1.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[21] = IntegrationPointType( -1.00 , 0.00 , -1.00 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[22] = IntegrationPointType( -1.00 , 0.00 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[23] = IntegrationPointType( -1.00 , 0.00 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[24] = IntegrationPointType( -1.00 , 0.00 , 0.00 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[25] = IntegrationPointType( -1.00 , 0.00 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[26] = IntegrationPointType( -1.00 , 0.00 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[27] = IntegrationPointType( -1.00 , 0.00 , 1.00 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[28] = IntegrationPointType( -1.00 , 0.468848793470714213803771881909 , -1.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[29] = IntegrationPointType( -1.00 , 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[30] = IntegrationPointType( -1.00 , 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[31] = IntegrationPointType( -1.00 , 0.468848793470714213803771881909 , 0.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[32] = IntegrationPointType( -1.00 , 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[33] = IntegrationPointType( -1.00 , 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[34] = IntegrationPointType( -1.00 , 0.468848793470714213803771881909 , 1.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[35] = IntegrationPointType( -1.00 , 0.830223896278566929872032213967 , -1.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[36] = IntegrationPointType( -1.00 , 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[37] = IntegrationPointType( -1.00 , 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[38] = IntegrationPointType( -1.00 , 0.830223896278566929872032213967 , 0.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[39] = IntegrationPointType( -1.00 , 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[40] = IntegrationPointType( -1.00 , 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[41] = IntegrationPointType( -1.00 , 0.830223896278566929872032213967 , 1.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[42] = IntegrationPointType( -1.00 , 1.00 , -1.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[43] = IntegrationPointType( -1.00 , 1.00 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[44] = IntegrationPointType( -1.00 , 1.00 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[45] = IntegrationPointType( -1.00 , 1.00 , 0.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[46] = IntegrationPointType( -1.00 , 1.00 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[47] = IntegrationPointType( -1.00 , 1.00 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[48] = IntegrationPointType( -1.00 , 1.00 , 1.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[49] = IntegrationPointType( -0.830223896278566929872032213967 , -1.00 , -1.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[50] = IntegrationPointType( -0.830223896278566929872032213967 , -1.00 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[51] = IntegrationPointType( -0.830223896278566929872032213967 , -1.00 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[52] = IntegrationPointType( -0.830223896278566929872032213967 , -1.00 , 0.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[53] = IntegrationPointType( -0.830223896278566929872032213967 , -1.00 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[54] = IntegrationPointType( -0.830223896278566929872032213967 , -1.00 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[55] = IntegrationPointType( -0.830223896278566929872032213967 , -1.00 , 1.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[56] = IntegrationPointType( -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , -1.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[57] = IntegrationPointType( -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[58] = IntegrationPointType( -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[59] = IntegrationPointType( -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[60] = IntegrationPointType( -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[61] = IntegrationPointType( -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[62] = IntegrationPointType( -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 1.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[63] = IntegrationPointType( -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , -1.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[64] = IntegrationPointType( -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[65] = IntegrationPointType( -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[66] = IntegrationPointType( -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[67] = IntegrationPointType( -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[68] = IntegrationPointType( -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[69] = IntegrationPointType( -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 1.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[70] = IntegrationPointType( -0.830223896278566929872032213967 , 0.00 , -1.00 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[71] = IntegrationPointType( -0.830223896278566929872032213967 , 0.00 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[72] = IntegrationPointType( -0.830223896278566929872032213967 , 0.00 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[73] = IntegrationPointType( -0.830223896278566929872032213967 , 0.00 , 0.00 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[74] = IntegrationPointType( -0.830223896278566929872032213967 , 0.00 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[75] = IntegrationPointType( -0.830223896278566929872032213967 , 0.00 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[76] = IntegrationPointType( -0.830223896278566929872032213967 , 0.00 , 1.00 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[77] = IntegrationPointType( -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , -1.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[78] = IntegrationPointType( -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[79] = IntegrationPointType( -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[80] = IntegrationPointType( -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[81] = IntegrationPointType( -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[82] = IntegrationPointType( -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[83] = IntegrationPointType( -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 1.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[84] = IntegrationPointType( -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , -1.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[85] = IntegrationPointType( -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[86] = IntegrationPointType( -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[87] = IntegrationPointType( -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[88] = IntegrationPointType( -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[89] = IntegrationPointType( -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[90] = IntegrationPointType( -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 1.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[91] = IntegrationPointType( -0.830223896278566929872032213967 , 1.00 , -1.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[92] = IntegrationPointType( -0.830223896278566929872032213967 , 1.00 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[93] = IntegrationPointType( -0.830223896278566929872032213967 , 1.00 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[94] = IntegrationPointType( -0.830223896278566929872032213967 , 1.00 , 0.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[95] = IntegrationPointType( -0.830223896278566929872032213967 , 1.00 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[96] = IntegrationPointType( -0.830223896278566929872032213967 , 1.00 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[97] = IntegrationPointType( -0.830223896278566929872032213967 , 1.00 , 1.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[98] = IntegrationPointType( -0.468848793470714213803771881909 , -1.00 , -1.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[99] = IntegrationPointType( -0.468848793470714213803771881909 , -1.00 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[100] = IntegrationPointType( -0.468848793470714213803771881909 , -1.00 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[101] = IntegrationPointType( -0.468848793470714213803771881909 , -1.00 , 0.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[102] = IntegrationPointType( -0.468848793470714213803771881909 , -1.00 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[103] = IntegrationPointType( -0.468848793470714213803771881909 , -1.00 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[104] = IntegrationPointType( -0.468848793470714213803771881909 , -1.00 , 1.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[105] = IntegrationPointType( -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , -1.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[106] = IntegrationPointType( -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[107] = IntegrationPointType( -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[108] = IntegrationPointType( -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[109] = IntegrationPointType( -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[110] = IntegrationPointType( -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[111] = IntegrationPointType( -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 1.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[112] = IntegrationPointType( -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , -1.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[113] = IntegrationPointType( -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[114] = IntegrationPointType( -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[115] = IntegrationPointType( -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[116] = IntegrationPointType( -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[117] = IntegrationPointType( -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[118] = IntegrationPointType( -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 1.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[119] = IntegrationPointType( -0.468848793470714213803771881909 , 0.00 , -1.00 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[120] = IntegrationPointType( -0.468848793470714213803771881909 , 0.00 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[121] = IntegrationPointType( -0.468848793470714213803771881909 , 0.00 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[122] = IntegrationPointType( -0.468848793470714213803771881909 , 0.00 , 0.00 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[123] = IntegrationPointType( -0.468848793470714213803771881909 , 0.00 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[124] = IntegrationPointType( -0.468848793470714213803771881909 , 0.00 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[125] = IntegrationPointType( -0.468848793470714213803771881909 , 0.00 , 1.00 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[126] = IntegrationPointType( -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , -1.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[127] = IntegrationPointType( -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[128] = IntegrationPointType( -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[129] = IntegrationPointType( -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[130] = IntegrationPointType( -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[131] = IntegrationPointType( -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[132] = IntegrationPointType( -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 1.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[133] = IntegrationPointType( -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , -1.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[134] = IntegrationPointType( -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[135] = IntegrationPointType( -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[136] = IntegrationPointType( -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[137] = IntegrationPointType( -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[138] = IntegrationPointType( -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[139] = IntegrationPointType( -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 1.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[140] = IntegrationPointType( -0.468848793470714213803771881909 , 1.00 , -1.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[141] = IntegrationPointType( -0.468848793470714213803771881909 , 1.00 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[142] = IntegrationPointType( -0.468848793470714213803771881909 , 1.00 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[143] = IntegrationPointType( -0.468848793470714213803771881909 , 1.00 , 0.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[144] = IntegrationPointType( -0.468848793470714213803771881909 , 1.00 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[145] = IntegrationPointType( -0.468848793470714213803771881909 , 1.00 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[146] = IntegrationPointType( -0.468848793470714213803771881909 , 1.00 , 1.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[147] = IntegrationPointType( 0.00 , -1.00 , -1.00 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[148] = IntegrationPointType( 0.00 , -1.00 , -0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[149] = IntegrationPointType( 0.00 , -1.00 , -0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[150] = IntegrationPointType( 0.00 , -1.00 , 0.00 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[151] = IntegrationPointType( 0.00 , -1.00 , 0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[152] = IntegrationPointType( 0.00 , -1.00 , 0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[153] = IntegrationPointType( 0.00 , -1.00 , 1.00 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[154] = IntegrationPointType( 0.00 , -0.830223896278566929872032213967 , -1.00 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[155] = IntegrationPointType( 0.00 , -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[156] = IntegrationPointType( 0.00 , -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[157] = IntegrationPointType( 0.00 , -0.830223896278566929872032213967 , 0.00 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[158] = IntegrationPointType( 0.00 , -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[159] = IntegrationPointType( 0.00 , -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[160] = IntegrationPointType( 0.00 , -0.830223896278566929872032213967 , 1.00 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[161] = IntegrationPointType( 0.00 , -0.468848793470714213803771881909 , -1.00 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[162] = IntegrationPointType( 0.00 , -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[163] = IntegrationPointType( 0.00 , -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[164] = IntegrationPointType( 0.00 , -0.468848793470714213803771881909 , 0.00 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[165] = IntegrationPointType( 0.00 , -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[166] = IntegrationPointType( 0.00 , -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[167] = IntegrationPointType( 0.00 , -0.468848793470714213803771881909 , 1.00 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[168] = IntegrationPointType( 0.00 , 0.00 , -1.00 , 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[169] = IntegrationPointType( 0.00 , 0.00 , -0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[170] = IntegrationPointType( 0.00 , 0.00 , -0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[171] = IntegrationPointType( 0.00 , 0.00 , 0.00 , 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[172] = IntegrationPointType( 0.00 , 0.00 , 0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[173] = IntegrationPointType( 0.00 , 0.00 , 0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[174] = IntegrationPointType( 0.00 , 0.00 , 1.00 , 0.487619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[175] = IntegrationPointType( 0.00 , 0.468848793470714213803771881909 , -1.00 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[176] = IntegrationPointType( 0.00 , 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[177] = IntegrationPointType( 0.00 , 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[178] = IntegrationPointType( 0.00 , 0.468848793470714213803771881909 , 0.00 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[179] = IntegrationPointType( 0.00 , 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[180] = IntegrationPointType( 0.00 , 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[181] = IntegrationPointType( 0.00 , 0.468848793470714213803771881909 , 1.00 , 0.487619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[182] = IntegrationPointType( 0.00 , 0.830223896278566929872032213967 , -1.00 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[183] = IntegrationPointType( 0.00 , 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[184] = IntegrationPointType( 0.00 , 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[185] = IntegrationPointType( 0.00 , 0.830223896278566929872032213967 , 0.00 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[186] = IntegrationPointType( 0.00 , 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[187] = IntegrationPointType( 0.00 , 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[188] = IntegrationPointType( 0.00 , 0.830223896278566929872032213967 , 1.00 , 0.487619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[189] = IntegrationPointType( 0.00 , 1.00 , -1.00 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[190] = IntegrationPointType( 0.00 , 1.00 , -0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[191] = IntegrationPointType( 0.00 , 1.00 , -0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[192] = IntegrationPointType( 0.00 , 1.00 , 0.00 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[193] = IntegrationPointType( 0.00 , 1.00 , 0.468848793470714213803771881909 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[194] = IntegrationPointType( 0.00 , 1.00 , 0.830223896278566929872032213967 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[195] = IntegrationPointType( 0.00 , 1.00 , 1.00 , 0.487619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[196] = IntegrationPointType( 0.468848793470714213803771881909 , -1.00 , -1.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[197] = IntegrationPointType( 0.468848793470714213803771881909 , -1.00 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[198] = IntegrationPointType( 0.468848793470714213803771881909 , -1.00 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[199] = IntegrationPointType( 0.468848793470714213803771881909 , -1.00 , 0.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[200] = IntegrationPointType( 0.468848793470714213803771881909 , -1.00 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[201] = IntegrationPointType( 0.468848793470714213803771881909 , -1.00 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[202] = IntegrationPointType( 0.468848793470714213803771881909 , -1.00 , 1.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[203] = IntegrationPointType( 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , -1.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[204] = IntegrationPointType( 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[205] = IntegrationPointType( 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[206] = IntegrationPointType( 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[207] = IntegrationPointType( 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[208] = IntegrationPointType( 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[209] = IntegrationPointType( 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 1.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[210] = IntegrationPointType( 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , -1.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[211] = IntegrationPointType( 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[212] = IntegrationPointType( 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[213] = IntegrationPointType( 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[214] = IntegrationPointType( 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[215] = IntegrationPointType( 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[216] = IntegrationPointType( 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 1.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[217] = IntegrationPointType( 0.468848793470714213803771881909 , 0.00 , -1.00 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[218] = IntegrationPointType( 0.468848793470714213803771881909 , 0.00 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[219] = IntegrationPointType( 0.468848793470714213803771881909 , 0.00 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[220] = IntegrationPointType( 0.468848793470714213803771881909 , 0.00 , 0.00 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[221] = IntegrationPointType( 0.468848793470714213803771881909 , 0.00 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[222] = IntegrationPointType( 0.468848793470714213803771881909 , 0.00 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[223] = IntegrationPointType( 0.468848793470714213803771881909 , 0.00 , 1.00 , 0.431745381209862623417871022281 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[224] = IntegrationPointType( 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , -1.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[225] = IntegrationPointType( 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[226] = IntegrationPointType( 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[227] = IntegrationPointType( 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[228] = IntegrationPointType( 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[229] = IntegrationPointType( 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[230] = IntegrationPointType( 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 1.00 , 0.431745381209862623417871022281 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[231] = IntegrationPointType( 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , -1.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[232] = IntegrationPointType( 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[233] = IntegrationPointType( 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[234] = IntegrationPointType( 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[235] = IntegrationPointType( 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[236] = IntegrationPointType( 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[237] = IntegrationPointType( 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 1.00 , 0.431745381209862623417871022281 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[238] = IntegrationPointType( 0.468848793470714213803771881909 , 1.00 , -1.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[239] = IntegrationPointType( 0.468848793470714213803771881909 , 1.00 , -0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[240] = IntegrationPointType( 0.468848793470714213803771881909 , 1.00 , -0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[241] = IntegrationPointType( 0.468848793470714213803771881909 , 1.00 , 0.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[242] = IntegrationPointType( 0.468848793470714213803771881909 , 1.00 , 0.468848793470714213803771881909 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[243] = IntegrationPointType( 0.468848793470714213803771881909 , 1.00 , 0.830223896278566929872032213967 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[244] = IntegrationPointType( 0.468848793470714213803771881909 , 1.00 , 1.00 , 0.431745381209862623417871022281 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[245] = IntegrationPointType( 0.830223896278566929872032213967 , -1.00 , -1.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[246] = IntegrationPointType( 0.830223896278566929872032213967 , -1.00 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[247] = IntegrationPointType( 0.830223896278566929872032213967 , -1.00 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[248] = IntegrationPointType( 0.830223896278566929872032213967 , -1.00 , 0.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[249] = IntegrationPointType( 0.830223896278566929872032213967 , -1.00 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[250] = IntegrationPointType( 0.830223896278566929872032213967 , -1.00 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[251] = IntegrationPointType( 0.830223896278566929872032213967 , -1.00 , 1.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[252] = IntegrationPointType( 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , -1.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[253] = IntegrationPointType( 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[254] = IntegrationPointType( 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[255] = IntegrationPointType( 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[256] = IntegrationPointType( 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[257] = IntegrationPointType( 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[258] = IntegrationPointType( 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 1.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[259] = IntegrationPointType( 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , -1.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[260] = IntegrationPointType( 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[261] = IntegrationPointType( 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[262] = IntegrationPointType( 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[263] = IntegrationPointType( 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[264] = IntegrationPointType( 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[265] = IntegrationPointType( 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 1.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[266] = IntegrationPointType( 0.830223896278566929872032213967 , 0.00 , -1.00 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[267] = IntegrationPointType( 0.830223896278566929872032213967 , 0.00 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[268] = IntegrationPointType( 0.830223896278566929872032213967 , 0.00 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[269] = IntegrationPointType( 0.830223896278566929872032213967 , 0.00 , 0.00 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[270] = IntegrationPointType( 0.830223896278566929872032213967 , 0.00 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[271] = IntegrationPointType( 0.830223896278566929872032213967 , 0.00 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[272] = IntegrationPointType( 0.830223896278566929872032213967 , 0.00 , 1.00 , 0.27682604736156594801070040629 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[273] = IntegrationPointType( 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , -1.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[274] = IntegrationPointType( 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[275] = IntegrationPointType( 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[276] = IntegrationPointType( 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[277] = IntegrationPointType( 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[278] = IntegrationPointType( 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[279] = IntegrationPointType( 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 1.00 , 0.27682604736156594801070040629 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[280] = IntegrationPointType( 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , -1.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[281] = IntegrationPointType( 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[282] = IntegrationPointType( 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[283] = IntegrationPointType( 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[284] = IntegrationPointType( 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[285] = IntegrationPointType( 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[286] = IntegrationPointType( 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 1.00 , 0.27682604736156594801070040629 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[287] = IntegrationPointType( 0.830223896278566929872032213967 , 1.00 , -1.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[288] = IntegrationPointType( 0.830223896278566929872032213967 , 1.00 , -0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[289] = IntegrationPointType( 0.830223896278566929872032213967 , 1.00 , -0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[290] = IntegrationPointType( 0.830223896278566929872032213967 , 1.00 , 0.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[291] = IntegrationPointType( 0.830223896278566929872032213967 , 1.00 , 0.468848793470714213803771881909 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[292] = IntegrationPointType( 0.830223896278566929872032213967 , 1.00 , 0.830223896278566929872032213967 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[293] = IntegrationPointType( 0.830223896278566929872032213967 , 1.00 , 1.00 , 0.27682604736156594801070040629 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[294] = IntegrationPointType( 1.00 , -1.00 , -1.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[295] = IntegrationPointType( 1.00 , -1.00 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[296] = IntegrationPointType( 1.00 , -1.00 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[297] = IntegrationPointType( 1.00 , -1.00 , 0.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[298] = IntegrationPointType( 1.00 , -1.00 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[299] = IntegrationPointType( 1.00 , -1.00 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[300] = IntegrationPointType( 1.00 , -1.00 , 1.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[301] = IntegrationPointType( 1.00 , -0.830223896278566929872032213967 , -1.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[302] = IntegrationPointType( 1.00 , -0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[303] = IntegrationPointType( 1.00 , -0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[304] = IntegrationPointType( 1.00 , -0.830223896278566929872032213967 , 0.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[305] = IntegrationPointType( 1.00 , -0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[306] = IntegrationPointType( 1.00 , -0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[307] = IntegrationPointType( 1.00 , -0.830223896278566929872032213967 , 1.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[308] = IntegrationPointType( 1.00 , -0.468848793470714213803771881909 , -1.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[309] = IntegrationPointType( 1.00 , -0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[310] = IntegrationPointType( 1.00 , -0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[311] = IntegrationPointType( 1.00 , -0.468848793470714213803771881909 , 0.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[312] = IntegrationPointType( 1.00 , -0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[313] = IntegrationPointType( 1.00 , -0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[314] = IntegrationPointType( 1.00 , -0.468848793470714213803771881909 , 1.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[315] = IntegrationPointType( 1.00 , 0.00 , -1.00 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[316] = IntegrationPointType( 1.00 , 0.00 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[317] = IntegrationPointType( 1.00 , 0.00 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[318] = IntegrationPointType( 1.00 , 0.00 , 0.00 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[319] = IntegrationPointType( 1.00 , 0.00 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[320] = IntegrationPointType( 1.00 , 0.00 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[321] = IntegrationPointType( 1.00 , 0.00 , 1.00 , 0.047619047619047619047619047619 * 0.487619047619047619047619047619 * 0.047619047619047619047619047619 );

        msIntegrationPoints[322] = IntegrationPointType( 1.00 , 0.468848793470714213803771881909 , -1.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );
        msIntegrationPoints[323] = IntegrationPointType( 1.00 , 0.468848793470714213803771881909 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[324] = IntegrationPointType( 1.00 , 0.468848793470714213803771881909 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[325] = IntegrationPointType( 1.00 , 0.468848793470714213803771881909 , 0.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.487619047619047619047619047619 );
        msIntegrationPoints[326] = IntegrationPointType( 1.00 , 0.468848793470714213803771881909 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.431745381209862623417871022281 );
        msIntegrationPoints[327] = IntegrationPointType( 1.00 , 0.468848793470714213803771881909 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.27682604736156594801070040629 );
        msIntegrationPoints[328] = IntegrationPointType( 1.00 , 0.468848793470714213803771881909 , 1.00 , 0.047619047619047619047619047619 * 0.431745381209862623417871022281 * 0.047619047619047619047619047619 );

        msIntegrationPoints[329] = IntegrationPointType( 1.00 , 0.830223896278566929872032213967 , -1.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );
        msIntegrationPoints[330] = IntegrationPointType( 1.00 , 0.830223896278566929872032213967 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[331] = IntegrationPointType( 1.00 , 0.830223896278566929872032213967 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[332] = IntegrationPointType( 1.00 , 0.830223896278566929872032213967 , 0.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.487619047619047619047619047619 );
        msIntegrationPoints[333] = IntegrationPointType( 1.00 , 0.830223896278566929872032213967 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.431745381209862623417871022281 );
        msIntegrationPoints[334] = IntegrationPointType( 1.00 , 0.830223896278566929872032213967 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.27682604736156594801070040629 );
        msIntegrationPoints[335] = IntegrationPointType( 1.00 , 0.830223896278566929872032213967 , 1.00 , 0.047619047619047619047619047619 * 0.27682604736156594801070040629 * 0.047619047619047619047619047619 );

        msIntegrationPoints[336] = IntegrationPointType( 1.00 , 1.00 , -1.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );
        msIntegrationPoints[337] = IntegrationPointType( 1.00 , 1.00 , -0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[338] = IntegrationPointType( 1.00 , 1.00 , -0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[339] = IntegrationPointType( 1.00 , 1.00 , 0.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.487619047619047619047619047619 );
        msIntegrationPoints[340] = IntegrationPointType( 1.00 , 1.00 , 0.468848793470714213803771881909 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.431745381209862623417871022281 );
        msIntegrationPoints[341] = IntegrationPointType( 1.00 , 1.00 , 0.830223896278566929872032213967 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.27682604736156594801070040629 );
        msIntegrationPoints[342] = IntegrationPointType( 1.00 , 1.00 , 1.00 , 0.047619047619047619047619047619 * 0.047619047619047619047619047619 * 0.047619047619047619047619047619 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 7";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints7

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints8
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00 , -1.00 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[1] = IntegrationPointType( -1.00 , -1.00 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[2] = IntegrationPointType( -1.00 , -1.00 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00 , -1.00 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[4] = IntegrationPointType( -1.00 , -1.00 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[5] = IntegrationPointType( -1.00 , -1.00 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[6] = IntegrationPointType( -1.00 , -1.00 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[7] = IntegrationPointType( -1.00 , -1.00 , 1.00 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[8] = IntegrationPointType( -1.00 , -0.871740148509606615337445761221 , -1.00 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[9] = IntegrationPointType( -1.00 , -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[10] = IntegrationPointType( -1.00 , -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[11] = IntegrationPointType( -1.00 , -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[12] = IntegrationPointType( -1.00 , -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[13] = IntegrationPointType( -1.00 , -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[14] = IntegrationPointType( -1.00 , -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[15] = IntegrationPointType( -1.00 , -0.871740148509606615337445761221 , 1.00 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[16] = IntegrationPointType( -1.00 , -0.591700181433142302144510731398 , -1.00 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[17] = IntegrationPointType( -1.00 , -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[18] = IntegrationPointType( -1.00 , -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[19] = IntegrationPointType( -1.00 , -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[20] = IntegrationPointType( -1.00 , -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[21] = IntegrationPointType( -1.00 , -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[22] = IntegrationPointType( -1.00 , -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[23] = IntegrationPointType( -1.00 , -0.591700181433142302144510731398 , 1.00 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[24] = IntegrationPointType( -1.00 , -0.209299217902478868768657260345 , -1.00 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[25] = IntegrationPointType( -1.00 , -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[26] = IntegrationPointType( -1.00 , -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[27] = IntegrationPointType( -1.00 , -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[28] = IntegrationPointType( -1.00 , -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[29] = IntegrationPointType( -1.00 , -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[30] = IntegrationPointType( -1.00 , -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[31] = IntegrationPointType( -1.00 , -0.209299217902478868768657260345 , 1.00 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[32] = IntegrationPointType( -1.00 , 0.209299217902478868768657260345 , -1.00 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[33] = IntegrationPointType( -1.00 , 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[34] = IntegrationPointType( -1.00 , 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[35] = IntegrationPointType( -1.00 , 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[36] = IntegrationPointType( -1.00 , 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[37] = IntegrationPointType( -1.00 , 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[38] = IntegrationPointType( -1.00 , 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[39] = IntegrationPointType( -1.00 , 0.209299217902478868768657260345 , 1.00 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[40] = IntegrationPointType( -1.00 , 0.591700181433142302144510731398 , -1.00 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[41] = IntegrationPointType( -1.00 , 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[42] = IntegrationPointType( -1.00 , 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[43] = IntegrationPointType( -1.00 , 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[44] = IntegrationPointType( -1.00 , 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[45] = IntegrationPointType( -1.00 , 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[46] = IntegrationPointType( -1.00 , 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[47] = IntegrationPointType( -1.00 , 0.591700181433142302144510731398 , 1.00 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[48] = IntegrationPointType( -1.00 , 0.871740148509606615337445761221 , -1.00 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[49] = IntegrationPointType( -1.00 , 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[50] = IntegrationPointType( -1.00 , 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[51] = IntegrationPointType( -1.00 , 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[52] = IntegrationPointType( -1.00 , 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[53] = IntegrationPointType( -1.00 , 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[54] = IntegrationPointType( -1.00 , 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[55] = IntegrationPointType( -1.00 , 0.871740148509606615337445761221 , 1.00 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[56] = IntegrationPointType( -1.00 , 1.00 , -1.00 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[57] = IntegrationPointType( -1.00 , 1.00 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[58] = IntegrationPointType( -1.00 , 1.00 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[59] = IntegrationPointType( -1.00 , 1.00 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[60] = IntegrationPointType( -1.00 , 1.00 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[61] = IntegrationPointType( -1.00 , 1.00 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[62] = IntegrationPointType( -1.00 , 1.00 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[63] = IntegrationPointType( -1.00 , 1.00 , 1.00 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[64] = IntegrationPointType( -0.871740148509606615337445761221 , -1.00 , -1.00 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[65] = IntegrationPointType( -0.871740148509606615337445761221 , -1.00 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[66] = IntegrationPointType( -0.871740148509606615337445761221 , -1.00 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[67] = IntegrationPointType( -0.871740148509606615337445761221 , -1.00 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[68] = IntegrationPointType( -0.871740148509606615337445761221 , -1.00 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[69] = IntegrationPointType( -0.871740148509606615337445761221 , -1.00 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[70] = IntegrationPointType( -0.871740148509606615337445761221 , -1.00 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[71] = IntegrationPointType( -0.871740148509606615337445761221 , -1.00 , 1.00 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[72] = IntegrationPointType( -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , -1.00 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[73] = IntegrationPointType( -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[74] = IntegrationPointType( -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[75] = IntegrationPointType( -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[76] = IntegrationPointType( -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[77] = IntegrationPointType( -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[78] = IntegrationPointType( -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[79] = IntegrationPointType( -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 1.00 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[80] = IntegrationPointType( -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , -1.00 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[81] = IntegrationPointType( -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[82] = IntegrationPointType( -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[83] = IntegrationPointType( -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[84] = IntegrationPointType( -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[85] = IntegrationPointType( -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[86] = IntegrationPointType( -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[87] = IntegrationPointType( -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 1.00 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[88] = IntegrationPointType( -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , -1.00 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[89] = IntegrationPointType( -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[90] = IntegrationPointType( -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[91] = IntegrationPointType( -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[92] = IntegrationPointType( -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[93] = IntegrationPointType( -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[94] = IntegrationPointType( -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[95] = IntegrationPointType( -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 1.00 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[96] = IntegrationPointType( -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , -1.00 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[97] = IntegrationPointType( -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[98] = IntegrationPointType( -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[99] = IntegrationPointType( -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[100] = IntegrationPointType( -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[101] = IntegrationPointType( -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[102] = IntegrationPointType( -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[103] = IntegrationPointType( -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 1.00 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[104] = IntegrationPointType( -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , -1.00 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[105] = IntegrationPointType( -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[106] = IntegrationPointType( -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[107] = IntegrationPointType( -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[108] = IntegrationPointType( -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[109] = IntegrationPointType( -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[110] = IntegrationPointType( -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[111] = IntegrationPointType( -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 1.00 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[112] = IntegrationPointType( -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , -1.00 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[113] = IntegrationPointType( -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[114] = IntegrationPointType( -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[115] = IntegrationPointType( -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[116] = IntegrationPointType( -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[117] = IntegrationPointType( -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[118] = IntegrationPointType( -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[119] = IntegrationPointType( -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 1.00 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[120] = IntegrationPointType( -0.871740148509606615337445761221 , 1.00 , -1.00 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[121] = IntegrationPointType( -0.871740148509606615337445761221 , 1.00 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[122] = IntegrationPointType( -0.871740148509606615337445761221 , 1.00 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[123] = IntegrationPointType( -0.871740148509606615337445761221 , 1.00 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[124] = IntegrationPointType( -0.871740148509606615337445761221 , 1.00 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[125] = IntegrationPointType( -0.871740148509606615337445761221 , 1.00 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[126] = IntegrationPointType( -0.871740148509606615337445761221 , 1.00 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[127] = IntegrationPointType( -0.871740148509606615337445761221 , 1.00 , 1.00 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[128] = IntegrationPointType( -0.591700181433142302144510731398 , -1.00 , -1.00 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[129] = IntegrationPointType( -0.591700181433142302144510731398 , -1.00 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[130] = IntegrationPointType( -0.591700181433142302144510731398 , -1.00 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[131] = IntegrationPointType( -0.591700181433142302144510731398 , -1.00 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[132] = IntegrationPointType( -0.591700181433142302144510731398 , -1.00 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[133] = IntegrationPointType( -0.591700181433142302144510731398 , -1.00 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[134] = IntegrationPointType( -0.591700181433142302144510731398 , -1.00 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[135] = IntegrationPointType( -0.591700181433142302144510731398 , -1.00 , 1.00 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[136] = IntegrationPointType( -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , -1.00 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[137] = IntegrationPointType( -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[138] = IntegrationPointType( -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[139] = IntegrationPointType( -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[140] = IntegrationPointType( -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[141] = IntegrationPointType( -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[142] = IntegrationPointType( -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[143] = IntegrationPointType( -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 1.00 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[144] = IntegrationPointType( -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , -1.00 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[145] = IntegrationPointType( -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[146] = IntegrationPointType( -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[147] = IntegrationPointType( -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[148] = IntegrationPointType( -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[149] = IntegrationPointType( -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[150] = IntegrationPointType( -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[151] = IntegrationPointType( -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 1.00 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[152] = IntegrationPointType( -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , -1.00 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[153] = IntegrationPointType( -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[154] = IntegrationPointType( -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[155] = IntegrationPointType( -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[156] = IntegrationPointType( -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[157] = IntegrationPointType( -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[158] = IntegrationPointType( -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[159] = IntegrationPointType( -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 1.00 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[160] = IntegrationPointType( -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , -1.00 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[161] = IntegrationPointType( -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[162] = IntegrationPointType( -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[163] = IntegrationPointType( -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[164] = IntegrationPointType( -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[165] = IntegrationPointType( -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[166] = IntegrationPointType( -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[167] = IntegrationPointType( -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 1.00 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[168] = IntegrationPointType( -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , -1.00 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[169] = IntegrationPointType( -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[170] = IntegrationPointType( -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[171] = IntegrationPointType( -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[172] = IntegrationPointType( -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[173] = IntegrationPointType( -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[174] = IntegrationPointType( -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[175] = IntegrationPointType( -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 1.00 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[176] = IntegrationPointType( -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , -1.00 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[177] = IntegrationPointType( -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[178] = IntegrationPointType( -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[179] = IntegrationPointType( -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[180] = IntegrationPointType( -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[181] = IntegrationPointType( -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[182] = IntegrationPointType( -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[183] = IntegrationPointType( -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 1.00 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[184] = IntegrationPointType( -0.591700181433142302144510731398 , 1.00 , -1.00 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[185] = IntegrationPointType( -0.591700181433142302144510731398 , 1.00 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[186] = IntegrationPointType( -0.591700181433142302144510731398 , 1.00 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[187] = IntegrationPointType( -0.591700181433142302144510731398 , 1.00 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[188] = IntegrationPointType( -0.591700181433142302144510731398 , 1.00 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[189] = IntegrationPointType( -0.591700181433142302144510731398 , 1.00 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[190] = IntegrationPointType( -0.591700181433142302144510731398 , 1.00 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[191] = IntegrationPointType( -0.591700181433142302144510731398 , 1.00 , 1.00 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[192] = IntegrationPointType( -0.209299217902478868768657260345 , -1.00 , -1.00 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[193] = IntegrationPointType( -0.209299217902478868768657260345 , -1.00 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[194] = IntegrationPointType( -0.209299217902478868768657260345 , -1.00 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[195] = IntegrationPointType( -0.209299217902478868768657260345 , -1.00 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[196] = IntegrationPointType( -0.209299217902478868768657260345 , -1.00 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[197] = IntegrationPointType( -0.209299217902478868768657260345 , -1.00 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[198] = IntegrationPointType( -0.209299217902478868768657260345 , -1.00 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[199] = IntegrationPointType( -0.209299217902478868768657260345 , -1.00 , 1.00 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[200] = IntegrationPointType( -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , -1.00 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[201] = IntegrationPointType( -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[202] = IntegrationPointType( -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[203] = IntegrationPointType( -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[204] = IntegrationPointType( -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[205] = IntegrationPointType( -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[206] = IntegrationPointType( -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[207] = IntegrationPointType( -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 1.00 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[208] = IntegrationPointType( -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , -1.00 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[209] = IntegrationPointType( -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[210] = IntegrationPointType( -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[211] = IntegrationPointType( -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[212] = IntegrationPointType( -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[213] = IntegrationPointType( -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[214] = IntegrationPointType( -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[215] = IntegrationPointType( -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 1.00 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[216] = IntegrationPointType( -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , -1.00 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[217] = IntegrationPointType( -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[218] = IntegrationPointType( -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[219] = IntegrationPointType( -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[220] = IntegrationPointType( -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[221] = IntegrationPointType( -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[222] = IntegrationPointType( -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[223] = IntegrationPointType( -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 1.00 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[224] = IntegrationPointType( -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , -1.00 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[225] = IntegrationPointType( -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[226] = IntegrationPointType( -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[227] = IntegrationPointType( -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[228] = IntegrationPointType( -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[229] = IntegrationPointType( -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[230] = IntegrationPointType( -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[231] = IntegrationPointType( -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 1.00 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[232] = IntegrationPointType( -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , -1.00 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[233] = IntegrationPointType( -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[234] = IntegrationPointType( -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[235] = IntegrationPointType( -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[236] = IntegrationPointType( -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[237] = IntegrationPointType( -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[238] = IntegrationPointType( -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[239] = IntegrationPointType( -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 1.00 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[240] = IntegrationPointType( -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , -1.00 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[241] = IntegrationPointType( -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[242] = IntegrationPointType( -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[243] = IntegrationPointType( -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[244] = IntegrationPointType( -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[245] = IntegrationPointType( -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[246] = IntegrationPointType( -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[247] = IntegrationPointType( -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 1.00 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[248] = IntegrationPointType( -0.209299217902478868768657260345 , 1.00 , -1.00 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[249] = IntegrationPointType( -0.209299217902478868768657260345 , 1.00 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[250] = IntegrationPointType( -0.209299217902478868768657260345 , 1.00 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[251] = IntegrationPointType( -0.209299217902478868768657260345 , 1.00 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[252] = IntegrationPointType( -0.209299217902478868768657260345 , 1.00 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[253] = IntegrationPointType( -0.209299217902478868768657260345 , 1.00 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[254] = IntegrationPointType( -0.209299217902478868768657260345 , 1.00 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[255] = IntegrationPointType( -0.209299217902478868768657260345 , 1.00 , 1.00 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[256] = IntegrationPointType( 0.209299217902478868768657260345 , -1.00 , -1.00 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[257] = IntegrationPointType( 0.209299217902478868768657260345 , -1.00 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[258] = IntegrationPointType( 0.209299217902478868768657260345 , -1.00 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[259] = IntegrationPointType( 0.209299217902478868768657260345 , -1.00 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[260] = IntegrationPointType( 0.209299217902478868768657260345 , -1.00 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[261] = IntegrationPointType( 0.209299217902478868768657260345 , -1.00 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[262] = IntegrationPointType( 0.209299217902478868768657260345 , -1.00 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[263] = IntegrationPointType( 0.209299217902478868768657260345 , -1.00 , 1.00 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[264] = IntegrationPointType( 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , -1.00 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[265] = IntegrationPointType( 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[266] = IntegrationPointType( 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[267] = IntegrationPointType( 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[268] = IntegrationPointType( 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[269] = IntegrationPointType( 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[270] = IntegrationPointType( 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[271] = IntegrationPointType( 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 1.00 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[272] = IntegrationPointType( 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , -1.00 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[273] = IntegrationPointType( 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[274] = IntegrationPointType( 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[275] = IntegrationPointType( 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[276] = IntegrationPointType( 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[277] = IntegrationPointType( 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[278] = IntegrationPointType( 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[279] = IntegrationPointType( 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 1.00 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[280] = IntegrationPointType( 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , -1.00 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[281] = IntegrationPointType( 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[282] = IntegrationPointType( 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[283] = IntegrationPointType( 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[284] = IntegrationPointType( 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[285] = IntegrationPointType( 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[286] = IntegrationPointType( 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[287] = IntegrationPointType( 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 1.00 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[288] = IntegrationPointType( 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , -1.00 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[289] = IntegrationPointType( 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[290] = IntegrationPointType( 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[291] = IntegrationPointType( 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[292] = IntegrationPointType( 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[293] = IntegrationPointType( 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[294] = IntegrationPointType( 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[295] = IntegrationPointType( 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 1.00 , 0.4124587946587038815670529714 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[296] = IntegrationPointType( 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , -1.00 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[297] = IntegrationPointType( 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[298] = IntegrationPointType( 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[299] = IntegrationPointType( 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[300] = IntegrationPointType( 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[301] = IntegrationPointType( 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[302] = IntegrationPointType( 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[303] = IntegrationPointType( 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 1.00 , 0.4124587946587038815670529714 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[304] = IntegrationPointType( 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , -1.00 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[305] = IntegrationPointType( 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[306] = IntegrationPointType( 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[307] = IntegrationPointType( 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[308] = IntegrationPointType( 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[309] = IntegrationPointType( 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[310] = IntegrationPointType( 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[311] = IntegrationPointType( 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 1.00 , 0.4124587946587038815670529714 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[312] = IntegrationPointType( 0.209299217902478868768657260345 , 1.00 , -1.00 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[313] = IntegrationPointType( 0.209299217902478868768657260345 , 1.00 , -0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[314] = IntegrationPointType( 0.209299217902478868768657260345 , 1.00 , -0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[315] = IntegrationPointType( 0.209299217902478868768657260345 , 1.00 , -0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[316] = IntegrationPointType( 0.209299217902478868768657260345 , 1.00 , 0.209299217902478868768657260345 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[317] = IntegrationPointType( 0.209299217902478868768657260345 , 1.00 , 0.591700181433142302144510731398 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[318] = IntegrationPointType( 0.209299217902478868768657260345 , 1.00 , 0.871740148509606615337445761221 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[319] = IntegrationPointType( 0.209299217902478868768657260345 , 1.00 , 1.00 , 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[320] = IntegrationPointType( 0.591700181433142302144510731398 , -1.00 , -1.00 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[321] = IntegrationPointType( 0.591700181433142302144510731398 , -1.00 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[322] = IntegrationPointType( 0.591700181433142302144510731398 , -1.00 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[323] = IntegrationPointType( 0.591700181433142302144510731398 , -1.00 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[324] = IntegrationPointType( 0.591700181433142302144510731398 , -1.00 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[325] = IntegrationPointType( 0.591700181433142302144510731398 , -1.00 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[326] = IntegrationPointType( 0.591700181433142302144510731398 , -1.00 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[327] = IntegrationPointType( 0.591700181433142302144510731398 , -1.00 , 1.00 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[328] = IntegrationPointType( 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , -1.00 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[329] = IntegrationPointType( 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[330] = IntegrationPointType( 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[331] = IntegrationPointType( 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[332] = IntegrationPointType( 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[333] = IntegrationPointType( 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[334] = IntegrationPointType( 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[335] = IntegrationPointType( 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 1.00 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[336] = IntegrationPointType( 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , -1.00 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[337] = IntegrationPointType( 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[338] = IntegrationPointType( 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[339] = IntegrationPointType( 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[340] = IntegrationPointType( 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[341] = IntegrationPointType( 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[342] = IntegrationPointType( 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[343] = IntegrationPointType( 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 1.00 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[344] = IntegrationPointType( 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , -1.00 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[345] = IntegrationPointType( 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[346] = IntegrationPointType( 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[347] = IntegrationPointType( 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[348] = IntegrationPointType( 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[349] = IntegrationPointType( 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[350] = IntegrationPointType( 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[351] = IntegrationPointType( 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 1.00 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[352] = IntegrationPointType( 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , -1.00 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[353] = IntegrationPointType( 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[354] = IntegrationPointType( 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[355] = IntegrationPointType( 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[356] = IntegrationPointType( 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[357] = IntegrationPointType( 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[358] = IntegrationPointType( 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[359] = IntegrationPointType( 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 1.00 , 0.34112269248350436476424067711 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[360] = IntegrationPointType( 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , -1.00 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[361] = IntegrationPointType( 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[362] = IntegrationPointType( 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[363] = IntegrationPointType( 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[364] = IntegrationPointType( 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[365] = IntegrationPointType( 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[366] = IntegrationPointType( 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[367] = IntegrationPointType( 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 1.00 , 0.34112269248350436476424067711 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[368] = IntegrationPointType( 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , -1.00 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[369] = IntegrationPointType( 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[370] = IntegrationPointType( 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[371] = IntegrationPointType( 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[372] = IntegrationPointType( 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[373] = IntegrationPointType( 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[374] = IntegrationPointType( 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[375] = IntegrationPointType( 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 1.00 , 0.34112269248350436476424067711 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[376] = IntegrationPointType( 0.591700181433142302144510731398 , 1.00 , -1.00 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[377] = IntegrationPointType( 0.591700181433142302144510731398 , 1.00 , -0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[378] = IntegrationPointType( 0.591700181433142302144510731398 , 1.00 , -0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[379] = IntegrationPointType( 0.591700181433142302144510731398 , 1.00 , -0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[380] = IntegrationPointType( 0.591700181433142302144510731398 , 1.00 , 0.209299217902478868768657260345 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[381] = IntegrationPointType( 0.591700181433142302144510731398 , 1.00 , 0.591700181433142302144510731398 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[382] = IntegrationPointType( 0.591700181433142302144510731398 , 1.00 , 0.871740148509606615337445761221 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[383] = IntegrationPointType( 0.591700181433142302144510731398 , 1.00 , 1.00 , 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[384] = IntegrationPointType( 0.871740148509606615337445761221 , -1.00 , -1.00 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[385] = IntegrationPointType( 0.871740148509606615337445761221 , -1.00 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[386] = IntegrationPointType( 0.871740148509606615337445761221 , -1.00 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[387] = IntegrationPointType( 0.871740148509606615337445761221 , -1.00 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[388] = IntegrationPointType( 0.871740148509606615337445761221 , -1.00 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[389] = IntegrationPointType( 0.871740148509606615337445761221 , -1.00 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[390] = IntegrationPointType( 0.871740148509606615337445761221 , -1.00 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[391] = IntegrationPointType( 0.871740148509606615337445761221 , -1.00 , 1.00 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[392] = IntegrationPointType( 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , -1.00 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[393] = IntegrationPointType( 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[394] = IntegrationPointType( 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[395] = IntegrationPointType( 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[396] = IntegrationPointType( 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[397] = IntegrationPointType( 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[398] = IntegrationPointType( 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[399] = IntegrationPointType( 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 1.00 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[400] = IntegrationPointType( 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , -1.00 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[401] = IntegrationPointType( 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[402] = IntegrationPointType( 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[403] = IntegrationPointType( 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[404] = IntegrationPointType( 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[405] = IntegrationPointType( 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[406] = IntegrationPointType( 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[407] = IntegrationPointType( 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 1.00 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[408] = IntegrationPointType( 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , -1.00 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[409] = IntegrationPointType( 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[410] = IntegrationPointType( 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[411] = IntegrationPointType( 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[412] = IntegrationPointType( 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[413] = IntegrationPointType( 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[414] = IntegrationPointType( 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[415] = IntegrationPointType( 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 1.00 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[416] = IntegrationPointType( 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , -1.00 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[417] = IntegrationPointType( 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[418] = IntegrationPointType( 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[419] = IntegrationPointType( 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[420] = IntegrationPointType( 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[421] = IntegrationPointType( 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[422] = IntegrationPointType( 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[423] = IntegrationPointType( 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 1.00 , 0.21070422714350603938299206578 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[424] = IntegrationPointType( 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , -1.00 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[425] = IntegrationPointType( 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[426] = IntegrationPointType( 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[427] = IntegrationPointType( 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[428] = IntegrationPointType( 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[429] = IntegrationPointType( 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[430] = IntegrationPointType( 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[431] = IntegrationPointType( 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 1.00 , 0.21070422714350603938299206578 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[432] = IntegrationPointType( 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , -1.00 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[433] = IntegrationPointType( 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[434] = IntegrationPointType( 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[435] = IntegrationPointType( 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[436] = IntegrationPointType( 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[437] = IntegrationPointType( 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[438] = IntegrationPointType( 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[439] = IntegrationPointType( 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 1.00 , 0.21070422714350603938299206578 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[440] = IntegrationPointType( 0.871740148509606615337445761221 , 1.00 , -1.00 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[441] = IntegrationPointType( 0.871740148509606615337445761221 , 1.00 , -0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[442] = IntegrationPointType( 0.871740148509606615337445761221 , 1.00 , -0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[443] = IntegrationPointType( 0.871740148509606615337445761221 , 1.00 , -0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[444] = IntegrationPointType( 0.871740148509606615337445761221 , 1.00 , 0.209299217902478868768657260345 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[445] = IntegrationPointType( 0.871740148509606615337445761221 , 1.00 , 0.591700181433142302144510731398 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[446] = IntegrationPointType( 0.871740148509606615337445761221 , 1.00 , 0.871740148509606615337445761221 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[447] = IntegrationPointType( 0.871740148509606615337445761221 , 1.00 , 1.00 , 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[448] = IntegrationPointType( 1.00 , -1.00 , -1.00 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[449] = IntegrationPointType( 1.00 , -1.00 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[450] = IntegrationPointType( 1.00 , -1.00 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[451] = IntegrationPointType( 1.00 , -1.00 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[452] = IntegrationPointType( 1.00 , -1.00 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[453] = IntegrationPointType( 1.00 , -1.00 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[454] = IntegrationPointType( 1.00 , -1.00 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[455] = IntegrationPointType( 1.00 , -1.00 , 1.00 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[456] = IntegrationPointType( 1.00 , -0.871740148509606615337445761221 , -1.00 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[457] = IntegrationPointType( 1.00 , -0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[458] = IntegrationPointType( 1.00 , -0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[459] = IntegrationPointType( 1.00 , -0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[460] = IntegrationPointType( 1.00 , -0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[461] = IntegrationPointType( 1.00 , -0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[462] = IntegrationPointType( 1.00 , -0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[463] = IntegrationPointType( 1.00 , -0.871740148509606615337445761221 , 1.00 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[464] = IntegrationPointType( 1.00 , -0.591700181433142302144510731398 , -1.00 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[465] = IntegrationPointType( 1.00 , -0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[466] = IntegrationPointType( 1.00 , -0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[467] = IntegrationPointType( 1.00 , -0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[468] = IntegrationPointType( 1.00 , -0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[469] = IntegrationPointType( 1.00 , -0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[470] = IntegrationPointType( 1.00 , -0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[471] = IntegrationPointType( 1.00 , -0.591700181433142302144510731398 , 1.00 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[472] = IntegrationPointType( 1.00 , -0.209299217902478868768657260345 , -1.00 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[473] = IntegrationPointType( 1.00 , -0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[474] = IntegrationPointType( 1.00 , -0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[475] = IntegrationPointType( 1.00 , -0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[476] = IntegrationPointType( 1.00 , -0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[477] = IntegrationPointType( 1.00 , -0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[478] = IntegrationPointType( 1.00 , -0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[479] = IntegrationPointType( 1.00 , -0.209299217902478868768657260345 , 1.00 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[480] = IntegrationPointType( 1.00 , 0.209299217902478868768657260345 , -1.00 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[481] = IntegrationPointType( 1.00 , 0.209299217902478868768657260345 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[482] = IntegrationPointType( 1.00 , 0.209299217902478868768657260345 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[483] = IntegrationPointType( 1.00 , 0.209299217902478868768657260345 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[484] = IntegrationPointType( 1.00 , 0.209299217902478868768657260345 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.4124587946587038815670529714 );
        msIntegrationPoints[485] = IntegrationPointType( 1.00 , 0.209299217902478868768657260345 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.34112269248350436476424067711 );
        msIntegrationPoints[486] = IntegrationPointType( 1.00 , 0.209299217902478868768657260345 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.21070422714350603938299206578 );
        msIntegrationPoints[487] = IntegrationPointType( 1.00 , 0.209299217902478868768657260345 , 1.00 , 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[488] = IntegrationPointType( 1.00 , 0.591700181433142302144510731398 , -1.00 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[489] = IntegrationPointType( 1.00 , 0.591700181433142302144510731398 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[490] = IntegrationPointType( 1.00 , 0.591700181433142302144510731398 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[491] = IntegrationPointType( 1.00 , 0.591700181433142302144510731398 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[492] = IntegrationPointType( 1.00 , 0.591700181433142302144510731398 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.4124587946587038815670529714 );
        msIntegrationPoints[493] = IntegrationPointType( 1.00 , 0.591700181433142302144510731398 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.34112269248350436476424067711 );
        msIntegrationPoints[494] = IntegrationPointType( 1.00 , 0.591700181433142302144510731398 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.21070422714350603938299206578 );
        msIntegrationPoints[495] = IntegrationPointType( 1.00 , 0.591700181433142302144510731398 , 1.00 , 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[496] = IntegrationPointType( 1.00 , 0.871740148509606615337445761221 , -1.00 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[497] = IntegrationPointType( 1.00 , 0.871740148509606615337445761221 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[498] = IntegrationPointType( 1.00 , 0.871740148509606615337445761221 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[499] = IntegrationPointType( 1.00 , 0.871740148509606615337445761221 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[500] = IntegrationPointType( 1.00 , 0.871740148509606615337445761221 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.4124587946587038815670529714 );
        msIntegrationPoints[501] = IntegrationPointType( 1.00 , 0.871740148509606615337445761221 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.34112269248350436476424067711 );
        msIntegrationPoints[502] = IntegrationPointType( 1.00 , 0.871740148509606615337445761221 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.21070422714350603938299206578 );
        msIntegrationPoints[503] = IntegrationPointType( 1.00 , 0.871740148509606615337445761221 , 1.00 , 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 * 0.0357142857142857142857142857143 );

        msIntegrationPoints[504] = IntegrationPointType( 1.00 , 1.00 , -1.00 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );
        msIntegrationPoints[505] = IntegrationPointType( 1.00 , 1.00 , -0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[506] = IntegrationPointType( 1.00 , 1.00 , -0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[507] = IntegrationPointType( 1.00 , 1.00 , -0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[508] = IntegrationPointType( 1.00 , 1.00 , 0.209299217902478868768657260345 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.4124587946587038815670529714 );
        msIntegrationPoints[509] = IntegrationPointType( 1.00 , 1.00 , 0.591700181433142302144510731398 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.34112269248350436476424067711 );
        msIntegrationPoints[510] = IntegrationPointType( 1.00 , 1.00 , 0.871740148509606615337445761221 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.21070422714350603938299206578 );
        msIntegrationPoints[511] = IntegrationPointType( 1.00 , 1.00 , 1.00 , 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 * 0.0357142857142857142857142857143 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 8";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints8

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints9
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00 , -1.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[1] = IntegrationPointType( -1.00 , -1.00 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[2] = IntegrationPointType( -1.00 , -1.00 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00 , -1.00 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[4] = IntegrationPointType( -1.00 , -1.00 , 0.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[5] = IntegrationPointType( -1.00 , -1.00 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[6] = IntegrationPointType( -1.00 , -1.00 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[7] = IntegrationPointType( -1.00 , -1.00 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[8] = IntegrationPointType( -1.00 , -1.00 , 1.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[9] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , -1.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[10] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[11] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[12] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[13] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , 0.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[14] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[15] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[16] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[17] = IntegrationPointType( -1.00 , -0.899757995411460157312345244418 , 1.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[18] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , -1.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[19] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[20] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[21] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[22] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , 0.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[23] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[24] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[25] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[26] = IntegrationPointType( -1.00 , -0.677186279510737753445885427091 , 1.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[27] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , -1.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[28] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[29] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[30] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[31] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , 0.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[32] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[33] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[34] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[35] = IntegrationPointType( -1.00 , -0.363117463826178158710752068709 , 1.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[36] = IntegrationPointType( -1.00 , 0.00 , -1.00 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[37] = IntegrationPointType( -1.00 , 0.00 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[38] = IntegrationPointType( -1.00 , 0.00 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[39] = IntegrationPointType( -1.00 , 0.00 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[40] = IntegrationPointType( -1.00 , 0.00 , 0.00 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[41] = IntegrationPointType( -1.00 , 0.00 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[42] = IntegrationPointType( -1.00 , 0.00 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[43] = IntegrationPointType( -1.00 , 0.00 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[44] = IntegrationPointType( -1.00 , 0.00 , 1.00 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[45] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , -1.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[46] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[47] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[48] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[49] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , 0.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[50] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[51] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[52] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[53] = IntegrationPointType( -1.00 , 0.363117463826178158710752068709 , 1.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[54] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , -1.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[55] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[56] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[57] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[58] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , 0.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[59] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[60] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[61] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[62] = IntegrationPointType( -1.00 , 0.677186279510737753445885427091 , 1.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[63] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , -1.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[64] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[65] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[66] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[67] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , 0.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[68] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[69] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[70] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[71] = IntegrationPointType( -1.00 , 0.899757995411460157312345244418 , 1.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[72] = IntegrationPointType( -1.00 , 1.00 , -1.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[73] = IntegrationPointType( -1.00 , 1.00 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[74] = IntegrationPointType( -1.00 , 1.00 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[75] = IntegrationPointType( -1.00 , 1.00 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[76] = IntegrationPointType( -1.00 , 1.00 , 0.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[77] = IntegrationPointType( -1.00 , 1.00 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[78] = IntegrationPointType( -1.00 , 1.00 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[79] = IntegrationPointType( -1.00 , 1.00 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[80] = IntegrationPointType( -1.00 , 1.00 , 1.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[81] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , -1.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[82] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[83] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[84] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[85] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , 0.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[86] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[87] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[88] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[89] = IntegrationPointType( -0.899757995411460157312345244418 , -1.00 , 1.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[90] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , -1.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[91] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[92] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[93] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[94] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[95] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[96] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[97] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[98] = IntegrationPointType( -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 1.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[99] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , -1.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[100] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[101] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[102] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[103] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[104] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[105] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[106] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[107] = IntegrationPointType( -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 1.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[108] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , -1.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[109] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[110] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[111] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[112] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[113] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[114] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[115] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[116] = IntegrationPointType( -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 1.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[117] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , -1.00 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[118] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[119] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[120] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[121] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , 0.00 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[122] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[123] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[124] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[125] = IntegrationPointType( -0.899757995411460157312345244418 , 0.00 , 1.00 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[126] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , -1.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[127] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[128] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[129] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[130] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[131] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[132] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[133] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[134] = IntegrationPointType( -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 1.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[135] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , -1.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[136] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[137] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[138] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[139] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[140] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[141] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[142] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[143] = IntegrationPointType( -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 1.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[144] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , -1.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[145] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[146] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[147] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[148] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[149] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[150] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[151] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[152] = IntegrationPointType( -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 1.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[153] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , -1.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[154] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[155] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[156] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[157] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , 0.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[158] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[159] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[160] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[161] = IntegrationPointType( -0.899757995411460157312345244418 , 1.00 , 1.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[162] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , -1.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[163] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[164] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[165] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[166] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , 0.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[167] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[168] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[169] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[170] = IntegrationPointType( -0.677186279510737753445885427091 , -1.00 , 1.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[171] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , -1.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[172] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[173] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[174] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[175] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[176] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[177] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[178] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[179] = IntegrationPointType( -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 1.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[180] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , -1.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[181] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[182] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[183] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[184] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[185] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[186] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[187] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[188] = IntegrationPointType( -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 1.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[189] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , -1.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[190] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[191] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[192] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[193] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[194] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[195] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[196] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[197] = IntegrationPointType( -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 1.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[198] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , -1.00 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[199] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[200] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[201] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[202] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , 0.00 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[203] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[204] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[205] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[206] = IntegrationPointType( -0.677186279510737753445885427091 , 0.00 , 1.00 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[207] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , -1.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[208] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[209] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[210] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[211] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[212] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[213] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[214] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[215] = IntegrationPointType( -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 1.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[216] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , -1.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[217] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[218] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[219] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[220] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[221] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[222] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[223] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[224] = IntegrationPointType( -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 1.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[225] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , -1.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[226] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[227] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[228] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[229] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[230] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[231] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[232] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[233] = IntegrationPointType( -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 1.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[234] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , -1.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[235] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[236] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[237] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[238] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , 0.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[239] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[240] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[241] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[242] = IntegrationPointType( -0.677186279510737753445885427091 , 1.00 , 1.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[243] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , -1.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[244] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[245] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[246] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[247] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , 0.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[248] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[249] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[250] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[251] = IntegrationPointType( -0.363117463826178158710752068709 , -1.00 , 1.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[252] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , -1.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[253] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[254] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[255] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[256] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[257] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[258] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[259] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[260] = IntegrationPointType( -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 1.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[261] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , -1.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[262] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[263] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[264] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[265] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[266] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[267] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[268] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[269] = IntegrationPointType( -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 1.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[270] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , -1.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[271] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[272] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[273] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[274] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[275] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[276] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[277] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[278] = IntegrationPointType( -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 1.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[279] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , -1.00 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[280] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[281] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[282] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[283] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , 0.00 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[284] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[285] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[286] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[287] = IntegrationPointType( -0.363117463826178158710752068709 , 0.00 , 1.00 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[288] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , -1.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[289] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[290] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[291] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[292] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[293] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[294] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[295] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[296] = IntegrationPointType( -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 1.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[297] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , -1.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[298] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[299] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[300] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[301] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[302] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[303] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[304] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[305] = IntegrationPointType( -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 1.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[306] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , -1.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[307] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[308] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[309] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[310] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[311] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[312] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[313] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[314] = IntegrationPointType( -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 1.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[315] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , -1.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[316] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[317] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[318] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[319] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , 0.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[320] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[321] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[322] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[323] = IntegrationPointType( -0.363117463826178158710752068709 , 1.00 , 1.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[324] = IntegrationPointType( 0.00 , -1.00 , -1.00 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[325] = IntegrationPointType( 0.00 , -1.00 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[326] = IntegrationPointType( 0.00 , -1.00 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[327] = IntegrationPointType( 0.00 , -1.00 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[328] = IntegrationPointType( 0.00 , -1.00 , 0.00 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[329] = IntegrationPointType( 0.00 , -1.00 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[330] = IntegrationPointType( 0.00 , -1.00 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[331] = IntegrationPointType( 0.00 , -1.00 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[332] = IntegrationPointType( 0.00 , -1.00 , 1.00 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[333] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , -1.00 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[334] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[335] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[336] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[337] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , 0.00 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[338] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[339] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[340] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[341] = IntegrationPointType( 0.00 , -0.899757995411460157312345244418 , 1.00 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[342] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , -1.00 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[343] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[344] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[345] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[346] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , 0.00 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[347] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[348] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[349] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[350] = IntegrationPointType( 0.00 , -0.677186279510737753445885427091 , 1.00 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[351] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , -1.00 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[352] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[353] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[354] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[355] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , 0.00 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[356] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[357] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[358] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[359] = IntegrationPointType( 0.00 , -0.363117463826178158710752068709 , 1.00 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[360] = IntegrationPointType( 0.00 , 0.00 , -1.00 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[361] = IntegrationPointType( 0.00 , 0.00 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[362] = IntegrationPointType( 0.00 , 0.00 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[363] = IntegrationPointType( 0.00 , 0.00 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[364] = IntegrationPointType( 0.00 , 0.00 , 0.00 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[365] = IntegrationPointType( 0.00 , 0.00 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[366] = IntegrationPointType( 0.00 , 0.00 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[367] = IntegrationPointType( 0.00 , 0.00 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[368] = IntegrationPointType( 0.00 , 0.00 , 1.00 , 0.371519274376417233560090702948 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[369] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , -1.00 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[370] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[371] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[372] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[373] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , 0.00 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[374] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[375] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[376] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[377] = IntegrationPointType( 0.00 , 0.363117463826178158710752068709 , 1.00 , 0.371519274376417233560090702948 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[378] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , -1.00 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[379] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[380] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[381] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[382] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , 0.00 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[383] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[384] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[385] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[386] = IntegrationPointType( 0.00 , 0.677186279510737753445885427091 , 1.00 , 0.371519274376417233560090702948 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[387] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , -1.00 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[388] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[389] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[390] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[391] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , 0.00 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[392] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[393] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[394] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[395] = IntegrationPointType( 0.00 , 0.899757995411460157312345244418 , 1.00 , 0.371519274376417233560090702948 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[396] = IntegrationPointType( 0.00 , 1.00 , -1.00 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[397] = IntegrationPointType( 0.00 , 1.00 , -0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[398] = IntegrationPointType( 0.00 , 1.00 , -0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[399] = IntegrationPointType( 0.00 , 1.00 , -0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[400] = IntegrationPointType( 0.00 , 1.00 , 0.00 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[401] = IntegrationPointType( 0.00 , 1.00 , 0.363117463826178158710752068709 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[402] = IntegrationPointType( 0.00 , 1.00 , 0.677186279510737753445885427091 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[403] = IntegrationPointType( 0.00 , 1.00 , 0.899757995411460157312345244418 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[404] = IntegrationPointType( 0.00 , 1.00 , 1.00 , 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[405] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , -1.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[406] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[407] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[408] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[409] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , 0.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[410] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[411] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[412] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[413] = IntegrationPointType( 0.363117463826178158710752068709 , -1.00 , 1.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[414] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , -1.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[415] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[416] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[417] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[418] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[419] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[420] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[421] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[422] = IntegrationPointType( 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 1.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[423] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , -1.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[424] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[425] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[426] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[427] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[428] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[429] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[430] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[431] = IntegrationPointType( 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 1.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[432] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , -1.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[433] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[434] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[435] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[436] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[437] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[438] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[439] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[440] = IntegrationPointType( 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 1.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[441] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , -1.00 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[442] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[443] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[444] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[445] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , 0.00 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[446] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[447] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[448] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[449] = IntegrationPointType( 0.363117463826178158710752068709 , 0.00 , 1.00 , 0.34642851097304634511513153214 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[450] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , -1.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[451] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[452] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[453] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[454] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[455] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[456] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[457] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[458] = IntegrationPointType( 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 1.00 , 0.34642851097304634511513153214 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[459] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , -1.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[460] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[461] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[462] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[463] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[464] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[465] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[466] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[467] = IntegrationPointType( 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 1.00 , 0.34642851097304634511513153214 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[468] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , -1.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[469] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[470] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[471] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[472] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[473] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[474] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[475] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[476] = IntegrationPointType( 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 1.00 , 0.34642851097304634511513153214 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[477] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , -1.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[478] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , -0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[479] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , -0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[480] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , -0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[481] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , 0.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[482] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , 0.363117463826178158710752068709 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[483] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , 0.677186279510737753445885427091 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[484] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , 0.899757995411460157312345244418 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[485] = IntegrationPointType( 0.363117463826178158710752068709 , 1.00 , 1.00 , 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[486] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , -1.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[487] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[488] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[489] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[490] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , 0.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[491] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[492] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[493] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[494] = IntegrationPointType( 0.677186279510737753445885427091 , -1.00 , 1.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[495] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , -1.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[496] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[497] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[498] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[499] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[500] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[501] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[502] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[503] = IntegrationPointType( 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 1.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[504] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , -1.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[505] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[506] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[507] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[508] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[509] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[510] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[511] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[512] = IntegrationPointType( 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 1.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[513] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , -1.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[514] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[515] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[516] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[517] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[518] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[519] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[520] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[521] = IntegrationPointType( 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 1.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[522] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , -1.00 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[523] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[524] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[525] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[526] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , 0.00 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[527] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[528] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[529] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[530] = IntegrationPointType( 0.677186279510737753445885427091 , 0.00 , 1.00 , 0.274538712500161735280705618579 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[531] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , -1.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[532] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[533] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[534] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[535] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[536] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[537] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[538] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[539] = IntegrationPointType( 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 1.00 , 0.274538712500161735280705618579 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[540] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , -1.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[541] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[542] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[543] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[544] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[545] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[546] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[547] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[548] = IntegrationPointType( 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 1.00 , 0.274538712500161735280705618579 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[549] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , -1.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[550] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[551] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[552] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[553] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[554] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[555] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[556] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[557] = IntegrationPointType( 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 1.00 , 0.274538712500161735280705618579 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[558] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , -1.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[559] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , -0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[560] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , -0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[561] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , -0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[562] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , 0.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[563] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , 0.363117463826178158710752068709 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[564] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , 0.677186279510737753445885427091 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[565] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , 0.899757995411460157312345244418 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[566] = IntegrationPointType( 0.677186279510737753445885427091 , 1.00 , 1.00 , 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[567] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , -1.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[568] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[569] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[570] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[571] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , 0.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[572] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[573] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[574] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[575] = IntegrationPointType( 0.899757995411460157312345244418 , -1.00 , 1.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[576] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , -1.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[577] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[578] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[579] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[580] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[581] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[582] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[583] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[584] = IntegrationPointType( 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 1.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[585] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , -1.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[586] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[587] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[588] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[589] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[590] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[591] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[592] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[593] = IntegrationPointType( 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 1.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[594] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , -1.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[595] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[596] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[597] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[598] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[599] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[600] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[601] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[602] = IntegrationPointType( 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 1.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[603] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , -1.00 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[604] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[605] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[606] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[607] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , 0.00 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[608] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[609] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[610] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[611] = IntegrationPointType( 0.899757995411460157312345244418 , 0.00 , 1.00 , 0.16549536156080552504633972003 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[612] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , -1.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[613] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[614] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[615] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[616] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[617] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[618] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[619] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[620] = IntegrationPointType( 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 1.00 , 0.16549536156080552504633972003 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[621] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , -1.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[622] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[623] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[624] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[625] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[626] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[627] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[628] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[629] = IntegrationPointType( 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 1.00 , 0.16549536156080552504633972003 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[630] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , -1.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[631] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[632] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[633] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[634] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[635] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[636] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[637] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[638] = IntegrationPointType( 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 1.00 , 0.16549536156080552504633972003 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[639] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , -1.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[640] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , -0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[641] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , -0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[642] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , -0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[643] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , 0.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[644] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , 0.363117463826178158710752068709 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[645] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , 0.677186279510737753445885427091 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[646] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , 0.899757995411460157312345244418 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[647] = IntegrationPointType( 0.899757995411460157312345244418 , 1.00 , 1.00 , 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[648] = IntegrationPointType( 1.00 , -1.00 , -1.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[649] = IntegrationPointType( 1.00 , -1.00 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[650] = IntegrationPointType( 1.00 , -1.00 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[651] = IntegrationPointType( 1.00 , -1.00 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[652] = IntegrationPointType( 1.00 , -1.00 , 0.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[653] = IntegrationPointType( 1.00 , -1.00 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[654] = IntegrationPointType( 1.00 , -1.00 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[655] = IntegrationPointType( 1.00 , -1.00 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[656] = IntegrationPointType( 1.00 , -1.00 , 1.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[657] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , -1.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[658] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[659] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[660] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[661] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , 0.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[662] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[663] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[664] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[665] = IntegrationPointType( 1.00 , -0.899757995411460157312345244418 , 1.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[666] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , -1.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[667] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[668] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[669] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[670] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , 0.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[671] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[672] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[673] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[674] = IntegrationPointType( 1.00 , -0.677186279510737753445885427091 , 1.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[675] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , -1.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[676] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[677] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[678] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[679] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , 0.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[680] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[681] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[682] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[683] = IntegrationPointType( 1.00 , -0.363117463826178158710752068709 , 1.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[684] = IntegrationPointType( 1.00 , 0.00 , -1.00 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[685] = IntegrationPointType( 1.00 , 0.00 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[686] = IntegrationPointType( 1.00 , 0.00 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[687] = IntegrationPointType( 1.00 , 0.00 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[688] = IntegrationPointType( 1.00 , 0.00 , 0.00 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.371519274376417233560090702948 );
        msIntegrationPoints[689] = IntegrationPointType( 1.00 , 0.00 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.34642851097304634511513153214 );
        msIntegrationPoints[690] = IntegrationPointType( 1.00 , 0.00 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.274538712500161735280705618579 );
        msIntegrationPoints[691] = IntegrationPointType( 1.00 , 0.00 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.16549536156080552504633972003 );
        msIntegrationPoints[692] = IntegrationPointType( 1.00 , 0.00 , 1.00 , 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[693] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , -1.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[694] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[695] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[696] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[697] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , 0.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.371519274376417233560090702948 );
        msIntegrationPoints[698] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.34642851097304634511513153214 );
        msIntegrationPoints[699] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.274538712500161735280705618579 );
        msIntegrationPoints[700] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.16549536156080552504633972003 );
        msIntegrationPoints[701] = IntegrationPointType( 1.00 , 0.363117463826178158710752068709 , 1.00 , 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[702] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , -1.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[703] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[704] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[705] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[706] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , 0.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.371519274376417233560090702948 );
        msIntegrationPoints[707] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.34642851097304634511513153214 );
        msIntegrationPoints[708] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.274538712500161735280705618579 );
        msIntegrationPoints[709] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.16549536156080552504633972003 );
        msIntegrationPoints[710] = IntegrationPointType( 1.00 , 0.677186279510737753445885427091 , 1.00 , 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[711] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , -1.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[712] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[713] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[714] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[715] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , 0.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.371519274376417233560090702948 );
        msIntegrationPoints[716] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.34642851097304634511513153214 );
        msIntegrationPoints[717] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.274538712500161735280705618579 );
        msIntegrationPoints[718] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.16549536156080552504633972003 );
        msIntegrationPoints[719] = IntegrationPointType( 1.00 , 0.899757995411460157312345244418 , 1.00 , 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 * 0.0277777777777777777777777777778 );

        msIntegrationPoints[720] = IntegrationPointType( 1.00 , 1.00 , -1.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );
        msIntegrationPoints[721] = IntegrationPointType( 1.00 , 1.00 , -0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[722] = IntegrationPointType( 1.00 , 1.00 , -0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[723] = IntegrationPointType( 1.00 , 1.00 , -0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[724] = IntegrationPointType( 1.00 , 1.00 , 0.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.371519274376417233560090702948 );
        msIntegrationPoints[725] = IntegrationPointType( 1.00 , 1.00 , 0.363117463826178158710752068709 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.34642851097304634511513153214 );
        msIntegrationPoints[726] = IntegrationPointType( 1.00 , 1.00 , 0.677186279510737753445885427091 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.274538712500161735280705618579 );
        msIntegrationPoints[727] = IntegrationPointType( 1.00 , 1.00 , 0.899757995411460157312345244418 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.16549536156080552504633972003 );
        msIntegrationPoints[728] = IntegrationPointType( 1.00 , 1.00 , 1.00 , 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 * 0.0277777777777777777777777777778 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 9";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints9

class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints10
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00 , -1.00 , -1.00 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[1] = IntegrationPointType( -1.00 , -1.00 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[2] = IntegrationPointType( -1.00 , -1.00 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00 , -1.00 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[4] = IntegrationPointType( -1.00 , -1.00 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[5] = IntegrationPointType( -1.00 , -1.00 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[6] = IntegrationPointType( -1.00 , -1.00 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[7] = IntegrationPointType( -1.00 , -1.00 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[8] = IntegrationPointType( -1.00 , -1.00 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[9] = IntegrationPointType( -1.00 , -1.00 , 1.00 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[10] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , -1.00 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[11] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[12] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[13] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[14] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[15] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[16] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[17] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[18] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[19] = IntegrationPointType( -1.00 , -0.919533908166458813828932660822 , 1.00 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[20] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , -1.00 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[21] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[22] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[23] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[24] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[25] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[26] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[27] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[28] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[29] = IntegrationPointType( -1.00 , -0.73877386510550507500310617486 , 1.00 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[30] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , -1.00 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[31] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[32] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[33] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[34] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[35] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[36] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[37] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[38] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[39] = IntegrationPointType( -1.00 , -0.477924949810444495661175092731 , 1.00 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[40] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , -1.00 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[41] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[42] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[43] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[44] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[45] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[46] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[47] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[48] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[49] = IntegrationPointType( -1.00 , -0.165278957666387024626219765958 , 1.00 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[50] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , -1.00 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[51] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[52] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[53] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[54] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[55] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[56] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[57] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[58] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[59] = IntegrationPointType( -1.00 , 0.165278957666387024626219765958 , 1.00 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[60] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , -1.00 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[61] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[62] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[63] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[64] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[65] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[66] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[67] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[68] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[69] = IntegrationPointType( -1.00 , 0.477924949810444495661175092731 , 1.00 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[70] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , -1.00 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[71] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[72] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[73] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[74] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[75] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[76] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[77] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[78] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[79] = IntegrationPointType( -1.00 , 0.73877386510550507500310617486 , 1.00 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[80] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , -1.00 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[81] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[82] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[83] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[84] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[85] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[86] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[87] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[88] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[89] = IntegrationPointType( -1.00 , 0.919533908166458813828932660822 , 1.00 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[90] = IntegrationPointType( -1.00 , 1.00 , -1.00 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[91] = IntegrationPointType( -1.00 , 1.00 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[92] = IntegrationPointType( -1.00 , 1.00 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[93] = IntegrationPointType( -1.00 , 1.00 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[94] = IntegrationPointType( -1.00 , 1.00 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[95] = IntegrationPointType( -1.00 , 1.00 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[96] = IntegrationPointType( -1.00 , 1.00 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[97] = IntegrationPointType( -1.00 , 1.00 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[98] = IntegrationPointType( -1.00 , 1.00 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[99] = IntegrationPointType( -1.00 , 1.00 , 1.00 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[100] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , -1.00 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[101] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[102] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[103] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[104] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[105] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[106] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[107] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[108] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[109] = IntegrationPointType( -0.919533908166458813828932660822 , -1.00 , 1.00 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[110] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -1.00 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[111] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[112] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[113] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[114] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[115] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[116] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[117] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[118] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[119] = IntegrationPointType( -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 1.00 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[120] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -1.00 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[121] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[122] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[123] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[124] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[125] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[126] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[127] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[128] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[129] = IntegrationPointType( -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 1.00 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[130] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -1.00 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[131] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[132] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[133] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[134] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[135] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[136] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[137] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[138] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[139] = IntegrationPointType( -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 1.00 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[140] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -1.00 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[141] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[142] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[143] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[144] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[145] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[146] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[147] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[148] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[149] = IntegrationPointType( -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 1.00 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[150] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -1.00 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[151] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[152] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[153] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[154] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[155] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[156] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[157] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[158] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[159] = IntegrationPointType( -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 1.00 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[160] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -1.00 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[161] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[162] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[163] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[164] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[165] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[166] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[167] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[168] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[169] = IntegrationPointType( -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 1.00 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[170] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -1.00 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[171] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[172] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[173] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[174] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[175] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[176] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[177] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[178] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[179] = IntegrationPointType( -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 1.00 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[180] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -1.00 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[181] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[182] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[183] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[184] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[185] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[186] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[187] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[188] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[189] = IntegrationPointType( -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 1.00 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[190] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , -1.00 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[191] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[192] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[193] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[194] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[195] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[196] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[197] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[198] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[199] = IntegrationPointType( -0.919533908166458813828932660822 , 1.00 , 1.00 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[200] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , -1.00 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[201] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[202] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[203] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[204] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[205] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[206] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[207] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[208] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[209] = IntegrationPointType( -0.73877386510550507500310617486 , -1.00 , 1.00 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[210] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -1.00 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[211] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[212] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[213] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[214] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[215] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[216] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[217] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[218] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[219] = IntegrationPointType( -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 1.00 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[220] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -1.00 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[221] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[222] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[223] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[224] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[225] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[226] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[227] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[228] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[229] = IntegrationPointType( -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 1.00 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[230] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -1.00 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[231] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[232] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[233] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[234] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[235] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[236] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[237] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[238] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[239] = IntegrationPointType( -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 1.00 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[240] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -1.00 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[241] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[242] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[243] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[244] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[245] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[246] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[247] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[248] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[249] = IntegrationPointType( -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 1.00 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[250] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -1.00 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[251] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[252] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[253] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[254] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[255] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[256] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[257] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[258] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[259] = IntegrationPointType( -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 1.00 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[260] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -1.00 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[261] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[262] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[263] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[264] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[265] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[266] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[267] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[268] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[269] = IntegrationPointType( -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 1.00 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[270] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -1.00 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[271] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[272] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[273] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[274] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[275] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[276] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[277] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[278] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[279] = IntegrationPointType( -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 1.00 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[280] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -1.00 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[281] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[282] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[283] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[284] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[285] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[286] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[287] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[288] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[289] = IntegrationPointType( -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 1.00 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[290] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , -1.00 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[291] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[292] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[293] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[294] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[295] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[296] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[297] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[298] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[299] = IntegrationPointType( -0.73877386510550507500310617486 , 1.00 , 1.00 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[300] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , -1.00 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[301] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[302] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[303] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[304] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[305] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[306] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[307] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[308] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[309] = IntegrationPointType( -0.477924949810444495661175092731 , -1.00 , 1.00 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[310] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -1.00 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[311] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[312] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[313] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[314] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[315] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[316] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[317] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[318] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[319] = IntegrationPointType( -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 1.00 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[320] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -1.00 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[321] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[322] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[323] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[324] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[325] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[326] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[327] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[328] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[329] = IntegrationPointType( -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 1.00 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[330] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -1.00 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[331] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[332] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[333] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[334] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[335] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[336] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[337] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[338] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[339] = IntegrationPointType( -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 1.00 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[340] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -1.00 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[341] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[342] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[343] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[344] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[345] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[346] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[347] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[348] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[349] = IntegrationPointType( -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 1.00 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[350] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -1.00 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[351] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[352] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[353] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[354] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[355] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[356] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[357] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[358] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[359] = IntegrationPointType( -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 1.00 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[360] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -1.00 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[361] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[362] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[363] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[364] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[365] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[366] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[367] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[368] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[369] = IntegrationPointType( -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 1.00 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[370] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -1.00 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[371] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[372] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[373] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[374] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[375] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[376] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[377] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[378] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[379] = IntegrationPointType( -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 1.00 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[380] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -1.00 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[381] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[382] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[383] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[384] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[385] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[386] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[387] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[388] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[389] = IntegrationPointType( -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 1.00 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[390] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , -1.00 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[391] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[392] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[393] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[394] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[395] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[396] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[397] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[398] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[399] = IntegrationPointType( -0.477924949810444495661175092731 , 1.00 , 1.00 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[400] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , -1.00 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[401] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[402] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[403] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[404] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[405] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[406] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[407] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[408] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[409] = IntegrationPointType( -0.165278957666387024626219765958 , -1.00 , 1.00 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[410] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -1.00 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[411] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[412] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[413] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[414] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[415] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[416] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[417] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[418] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[419] = IntegrationPointType( -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 1.00 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[420] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -1.00 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[421] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[422] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[423] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[424] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[425] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[426] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[427] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[428] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[429] = IntegrationPointType( -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 1.00 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[430] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -1.00 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[431] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[432] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[433] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[434] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[435] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[436] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[437] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[438] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[439] = IntegrationPointType( -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 1.00 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[440] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -1.00 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[441] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[442] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[443] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[444] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[445] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[446] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[447] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[448] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[449] = IntegrationPointType( -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 1.00 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[450] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -1.00 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[451] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[452] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[453] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[454] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[455] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[456] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[457] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[458] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[459] = IntegrationPointType( -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 1.00 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[460] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -1.00 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[461] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[462] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[463] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[464] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[465] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[466] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[467] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[468] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[469] = IntegrationPointType( -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 1.00 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[470] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -1.00 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[471] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[472] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[473] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[474] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[475] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[476] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[477] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[478] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[479] = IntegrationPointType( -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 1.00 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[480] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -1.00 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[481] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[482] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[483] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[484] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[485] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[486] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[487] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[488] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[489] = IntegrationPointType( -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 1.00 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[490] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , -1.00 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[491] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[492] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[493] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[494] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[495] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[496] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[497] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[498] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[499] = IntegrationPointType( -0.165278957666387024626219765958 , 1.00 , 1.00 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[500] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , -1.00 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[501] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[502] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[503] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[504] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[505] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[506] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[507] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[508] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[509] = IntegrationPointType( 0.165278957666387024626219765958 , -1.00 , 1.00 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[510] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -1.00 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[511] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[512] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[513] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[514] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[515] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[516] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[517] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[518] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[519] = IntegrationPointType( 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 1.00 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[520] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -1.00 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[521] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[522] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[523] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[524] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[525] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[526] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[527] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[528] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[529] = IntegrationPointType( 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 1.00 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[530] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -1.00 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[531] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[532] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[533] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[534] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[535] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[536] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[537] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[538] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[539] = IntegrationPointType( 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 1.00 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[540] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -1.00 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[541] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[542] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[543] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[544] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[545] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[546] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[547] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[548] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[549] = IntegrationPointType( 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 1.00 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[550] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -1.00 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[551] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[552] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[553] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[554] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[555] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[556] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[557] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[558] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[559] = IntegrationPointType( 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 1.00 , 0.32753976118389745665651052792 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[560] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -1.00 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[561] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[562] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[563] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[564] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[565] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[566] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[567] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[568] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[569] = IntegrationPointType( 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 1.00 , 0.32753976118389745665651052792 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[570] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -1.00 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[571] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[572] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[573] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[574] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[575] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[576] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[577] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[578] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[579] = IntegrationPointType( 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 1.00 , 0.32753976118389745665651052792 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[580] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -1.00 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[581] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[582] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[583] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[584] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[585] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[586] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[587] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[588] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[589] = IntegrationPointType( 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 1.00 , 0.32753976118389745665651052792 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[590] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , -1.00 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[591] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , -0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[592] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , -0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[593] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , -0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[594] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , -0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[595] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , 0.165278957666387024626219765958 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[596] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , 0.477924949810444495661175092731 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[597] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , 0.73877386510550507500310617486 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[598] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , 0.919533908166458813828932660822 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[599] = IntegrationPointType( 0.165278957666387024626219765958 , 1.00 , 1.00 , 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[600] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , -1.00 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[601] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[602] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[603] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[604] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[605] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[606] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[607] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[608] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[609] = IntegrationPointType( 0.477924949810444495661175092731 , -1.00 , 1.00 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[610] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -1.00 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[611] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[612] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[613] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[614] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[615] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[616] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[617] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[618] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[619] = IntegrationPointType( 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 1.00 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[620] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -1.00 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[621] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[622] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[623] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[624] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[625] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[626] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[627] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[628] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[629] = IntegrationPointType( 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 1.00 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[630] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -1.00 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[631] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[632] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[633] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[634] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[635] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[636] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[637] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[638] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[639] = IntegrationPointType( 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 1.00 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[640] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -1.00 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[641] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[642] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[643] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[644] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[645] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[646] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[647] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[648] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[649] = IntegrationPointType( 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 1.00 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[650] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -1.00 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[651] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[652] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[653] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[654] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[655] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[656] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[657] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[658] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[659] = IntegrationPointType( 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 1.00 , 0.29204268367968375787558225737 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[660] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -1.00 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[661] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[662] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[663] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[664] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[665] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[666] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[667] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[668] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[669] = IntegrationPointType( 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 1.00 , 0.29204268367968375787558225737 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[670] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -1.00 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[671] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[672] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[673] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[674] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[675] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[676] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[677] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[678] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[679] = IntegrationPointType( 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 1.00 , 0.29204268367968375787558225737 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[680] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -1.00 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[681] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[682] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[683] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[684] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[685] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[686] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[687] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[688] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[689] = IntegrationPointType( 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 1.00 , 0.29204268367968375787558225737 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[690] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , -1.00 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[691] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , -0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[692] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , -0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[693] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , -0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[694] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , -0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[695] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , 0.165278957666387024626219765958 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[696] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , 0.477924949810444495661175092731 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[697] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , 0.73877386510550507500310617486 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[698] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , 0.919533908166458813828932660822 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[699] = IntegrationPointType( 0.477924949810444495661175092731 , 1.00 , 1.00 , 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[700] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , -1.00 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[701] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[702] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[703] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[704] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[705] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[706] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[707] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[708] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[709] = IntegrationPointType( 0.73877386510550507500310617486 , -1.00 , 1.00 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[710] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -1.00 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[711] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[712] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[713] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[714] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[715] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[716] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[717] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[718] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[719] = IntegrationPointType( 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 1.00 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[720] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -1.00 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[721] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[722] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[723] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[724] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[725] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[726] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[727] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[728] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[729] = IntegrationPointType( 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 1.00 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[730] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -1.00 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[731] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[732] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[733] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[734] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[735] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[736] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[737] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[738] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[739] = IntegrationPointType( 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 1.00 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[740] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -1.00 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[741] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[742] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[743] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[744] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[745] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[746] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[747] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[748] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[749] = IntegrationPointType( 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 1.00 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[750] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -1.00 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[751] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[752] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[753] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[754] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[755] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[756] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[757] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[758] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[759] = IntegrationPointType( 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 1.00 , 0.224889342063126452119457821731 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[760] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -1.00 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[761] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[762] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[763] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[764] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[765] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[766] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[767] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[768] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[769] = IntegrationPointType( 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 1.00 , 0.224889342063126452119457821731 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[770] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -1.00 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[771] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[772] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[773] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[774] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[775] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[776] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[777] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[778] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[779] = IntegrationPointType( 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 1.00 , 0.224889342063126452119457821731 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[780] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -1.00 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[781] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[782] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[783] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[784] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[785] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[786] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[787] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[788] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[789] = IntegrationPointType( 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 1.00 , 0.224889342063126452119457821731 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[790] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , -1.00 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[791] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , -0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[792] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , -0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[793] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , -0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[794] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , -0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[795] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , 0.165278957666387024626219765958 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[796] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , 0.477924949810444495661175092731 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[797] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , 0.73877386510550507500310617486 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[798] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , 0.919533908166458813828932660822 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[799] = IntegrationPointType( 0.73877386510550507500310617486 , 1.00 , 1.00 , 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[800] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , -1.00 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[801] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[802] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[803] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[804] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[805] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[806] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[807] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[808] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[809] = IntegrationPointType( 0.919533908166458813828932660822 , -1.00 , 1.00 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[810] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -1.00 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[811] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[812] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[813] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[814] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[815] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[816] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[817] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[818] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[819] = IntegrationPointType( 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 1.00 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[820] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -1.00 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[821] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[822] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[823] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[824] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[825] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[826] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[827] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[828] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[829] = IntegrationPointType( 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 1.00 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[830] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -1.00 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[831] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[832] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[833] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[834] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[835] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[836] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[837] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[838] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[839] = IntegrationPointType( 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 1.00 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[840] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -1.00 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[841] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[842] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[843] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[844] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[845] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[846] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[847] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[848] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[849] = IntegrationPointType( 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 1.00 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[850] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -1.00 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[851] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[852] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[853] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[854] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[855] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[856] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[857] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[858] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[859] = IntegrationPointType( 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 1.00 , 0.133305990851070111126227170755 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[860] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -1.00 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[861] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[862] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[863] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[864] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[865] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[866] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[867] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[868] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[869] = IntegrationPointType( 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 1.00 , 0.133305990851070111126227170755 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[870] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -1.00 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[871] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[872] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[873] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[874] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[875] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[876] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[877] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[878] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[879] = IntegrationPointType( 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 1.00 , 0.133305990851070111126227170755 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[880] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -1.00 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[881] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[882] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[883] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[884] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[885] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[886] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[887] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[888] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[889] = IntegrationPointType( 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 1.00 , 0.133305990851070111126227170755 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[890] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , -1.00 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[891] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , -0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[892] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , -0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[893] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , -0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[894] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , -0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[895] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , 0.165278957666387024626219765958 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[896] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , 0.477924949810444495661175092731 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[897] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , 0.73877386510550507500310617486 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[898] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , 0.919533908166458813828932660822 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[899] = IntegrationPointType( 0.919533908166458813828932660822 , 1.00 , 1.00 , 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[900] = IntegrationPointType( 1.00 , -1.00 , -1.00 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[901] = IntegrationPointType( 1.00 , -1.00 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[902] = IntegrationPointType( 1.00 , -1.00 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[903] = IntegrationPointType( 1.00 , -1.00 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[904] = IntegrationPointType( 1.00 , -1.00 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[905] = IntegrationPointType( 1.00 , -1.00 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[906] = IntegrationPointType( 1.00 , -1.00 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[907] = IntegrationPointType( 1.00 , -1.00 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[908] = IntegrationPointType( 1.00 , -1.00 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[909] = IntegrationPointType( 1.00 , -1.00 , 1.00 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[910] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , -1.00 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[911] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[912] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[913] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[914] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[915] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[916] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[917] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[918] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[919] = IntegrationPointType( 1.00 , -0.919533908166458813828932660822 , 1.00 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[920] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , -1.00 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[921] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[922] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[923] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[924] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[925] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[926] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[927] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[928] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[929] = IntegrationPointType( 1.00 , -0.73877386510550507500310617486 , 1.00 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[930] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , -1.00 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[931] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[932] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[933] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[934] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[935] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[936] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[937] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[938] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[939] = IntegrationPointType( 1.00 , -0.477924949810444495661175092731 , 1.00 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[940] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , -1.00 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[941] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[942] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[943] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[944] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[945] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[946] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[947] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[948] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[949] = IntegrationPointType( 1.00 , -0.165278957666387024626219765958 , 1.00 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[950] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , -1.00 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[951] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[952] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[953] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[954] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[955] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.32753976118389745665651052792 );
        msIntegrationPoints[956] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.29204268367968375787558225737 );
        msIntegrationPoints[957] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.224889342063126452119457821731 );
        msIntegrationPoints[958] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.133305990851070111126227170755 );
        msIntegrationPoints[959] = IntegrationPointType( 1.00 , 0.165278957666387024626219765958 , 1.00 , 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[960] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , -1.00 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[961] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[962] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[963] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[964] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[965] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.32753976118389745665651052792 );
        msIntegrationPoints[966] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.29204268367968375787558225737 );
        msIntegrationPoints[967] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.224889342063126452119457821731 );
        msIntegrationPoints[968] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.133305990851070111126227170755 );
        msIntegrationPoints[969] = IntegrationPointType( 1.00 , 0.477924949810444495661175092731 , 1.00 , 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[970] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , -1.00 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[971] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[972] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[973] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[974] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[975] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.32753976118389745665651052792 );
        msIntegrationPoints[976] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.29204268367968375787558225737 );
        msIntegrationPoints[977] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.224889342063126452119457821731 );
        msIntegrationPoints[978] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.133305990851070111126227170755 );
        msIntegrationPoints[979] = IntegrationPointType( 1.00 , 0.73877386510550507500310617486 , 1.00 , 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[980] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , -1.00 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[981] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[982] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[983] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[984] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[985] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.32753976118389745665651052792 );
        msIntegrationPoints[986] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.29204268367968375787558225737 );
        msIntegrationPoints[987] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.224889342063126452119457821731 );
        msIntegrationPoints[988] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.133305990851070111126227170755 );
        msIntegrationPoints[989] = IntegrationPointType( 1.00 , 0.919533908166458813828932660822 , 1.00 , 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 * 0.0222222222222222222222222222222 );

        msIntegrationPoints[990] = IntegrationPointType( 1.00 , 1.00 , -1.00 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );
        msIntegrationPoints[991] = IntegrationPointType( 1.00 , 1.00 , -0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[992] = IntegrationPointType( 1.00 , 1.00 , -0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[993] = IntegrationPointType( 1.00 , 1.00 , -0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[994] = IntegrationPointType( 1.00 , 1.00 , -0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[995] = IntegrationPointType( 1.00 , 1.00 , 0.165278957666387024626219765958 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.32753976118389745665651052792 );
        msIntegrationPoints[996] = IntegrationPointType( 1.00 , 1.00 , 0.477924949810444495661175092731 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.29204268367968375787558225737 );
        msIntegrationPoints[997] = IntegrationPointType( 1.00 , 1.00 , 0.73877386510550507500310617486 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.224889342063126452119457821731 );
        msIntegrationPoints[998] = IntegrationPointType( 1.00 , 1.00 , 0.919533908166458813828932660822 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.133305990851070111126227170755 );
        msIntegrationPoints[999] = IntegrationPointType( 1.00 , 1.00 , 1.00 , 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 * 0.0222222222222222222222222222222 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Lobatto quadrature 10";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLobattoIntegrationPoints10

///@name Type Definitions
///@{

template<int TDegree>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints;

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<1> : public HexahedronGaussLobattoIntegrationPoints1
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<2> : public HexahedronGaussLobattoIntegrationPoints2
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<3> : public HexahedronGaussLobattoIntegrationPoints3
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<4> : public HexahedronGaussLobattoIntegrationPoints4
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<5> : public HexahedronGaussLobattoIntegrationPoints5
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<6> : public HexahedronGaussLobattoIntegrationPoints6
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<7> : public HexahedronGaussLobattoIntegrationPoints7
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<8> : public HexahedronGaussLobattoIntegrationPoints8
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<9> : public HexahedronGaussLobattoIntegrationPoints9
{};

template<>
class KRATOS_API(KRATOS_CORE) HexahedronGaussLobattoIntegrationPoints<10> : public HexahedronGaussLobattoIntegrationPoints10
{};

}

#endif // KRATOS_HEXAHEDRON_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED defined 


