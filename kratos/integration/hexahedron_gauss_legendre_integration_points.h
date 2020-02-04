//
//   Project Name:        Kratos
//   Last Modified by:    $Author :        VMataix $
//   Date:                $Date:            March 2016 $
//   Revision:            $Revision:                  1.6 $
//
//


#if !defined(KRATOS_HEXAHEDRON_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED )
#define  KRATOS_HEXAHEDRON_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED

// System includes

// External includes

// Project includes
#include "integration/quadrature.h"


namespace Kratos
{

class KRATOS_API(KRATOS_CORE) HexahedronGaussLegendreIntegrationPoints1
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(HexahedronGaussLegendreIntegrationPoints1);
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
       msIntegrationPoints[0] = IntegrationPointType( 0.00 , 0.00, 0.00 , 8.00 );
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Legendre quadrature 1 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLegendreIntegrationPoints1

class KRATOS_API(KRATOS_CORE) HexahedronGaussLegendreIntegrationPoints2
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(HexahedronGaussLegendreIntegrationPoints2);
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
       msIntegrationPoints[0] = IntegrationPointType( -1.00/std::sqrt(3.0) , -1.00/std::sqrt(3.0), -1.00/std::sqrt(3.0), 1.00 );
       msIntegrationPoints[1] = IntegrationPointType(  1.00/std::sqrt(3.0) , -1.00/std::sqrt(3.0), -1.00/std::sqrt(3.0), 1.00 );
       msIntegrationPoints[2] = IntegrationPointType(  1.00/std::sqrt(3.0) ,  1.00/std::sqrt(3.0), -1.00/std::sqrt(3.0), 1.00 );
       msIntegrationPoints[3] = IntegrationPointType( -1.00/std::sqrt(3.0) ,  1.00/std::sqrt(3.0), -1.00/std::sqrt(3.0), 1.00 );
       msIntegrationPoints[4] = IntegrationPointType( -1.00/std::sqrt(3.0) , -1.00/std::sqrt(3.0),  1.00/std::sqrt(3.0), 1.00 );
       msIntegrationPoints[5] = IntegrationPointType(  1.00/std::sqrt(3.0) , -1.00/std::sqrt(3.0),  1.00/std::sqrt(3.0), 1.00 );
       msIntegrationPoints[6] = IntegrationPointType(  1.00/std::sqrt(3.0) ,  1.00/std::sqrt(3.0),  1.00/std::sqrt(3.0), 1.00 );
       msIntegrationPoints[7] = IntegrationPointType( -1.00/std::sqrt(3.0) ,  1.00/std::sqrt(3.0),  1.00/std::sqrt(3.0), 1.00 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Legendre quadrature 2 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLegendreIntegrationPoints2

class KRATOS_API(KRATOS_CORE) HexahedronGaussLegendreIntegrationPoints3
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(HexahedronGaussLegendreIntegrationPoints3);
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
        const double a = std::sqrt(3.00/5.00);

        msIntegrationPoints[0] = IntegrationPointType(-a, -a, -a, 125.00 / 729.00);
        msIntegrationPoints[1] = IntegrationPointType(0.0, -a, -a, 200.00 / 729.00);
        msIntegrationPoints[2] = IntegrationPointType(a, -a, -a, 125.00 / 729.00);

        msIntegrationPoints[3] = IntegrationPointType(-a, 0.0, -a, 200.00 / 729.00);
        msIntegrationPoints[4] = IntegrationPointType(0.0, 0.0, -a, 320.00 / 729.00);
        msIntegrationPoints[5] = IntegrationPointType(a, 0.0, -a, 200.00 / 729.00);

        msIntegrationPoints[6] = IntegrationPointType(-a, a, -a, 125.00 / 729.00);
        msIntegrationPoints[7] = IntegrationPointType(0.0, a, -a, 200.00 / 729.00);
        msIntegrationPoints[8] = IntegrationPointType(a, a, -a, 125.00 / 729.00);

        msIntegrationPoints[9] = IntegrationPointType(-a, -a, 0.0, 200.00 / 729.00);
        msIntegrationPoints[10] = IntegrationPointType(0.0, -a, 0.0, 320.00 / 729.00);
        msIntegrationPoints[11] = IntegrationPointType(a, -a, 0.0, 200.00 / 729.00);

        msIntegrationPoints[12] = IntegrationPointType(-a, 0.0, 0.0, 320.00 / 729.00);
        msIntegrationPoints[13] = IntegrationPointType(0.0, 0.0, 0.0, 512.00 / 729.00);
        msIntegrationPoints[14] = IntegrationPointType(a, 0.0, 0.0, 320.00 / 729.00);

        msIntegrationPoints[15] = IntegrationPointType(-a, a, 0.0, 200.00 / 729.00);
        msIntegrationPoints[16] = IntegrationPointType(0.0, a, 0.0, 320.00 / 729.00);
        msIntegrationPoints[17] = IntegrationPointType(a, a, 0.0, 200.00 / 729.00);

        msIntegrationPoints[18] = IntegrationPointType(-a, -a, a, 125.00 / 729.00);
        msIntegrationPoints[19] = IntegrationPointType(0.0, -a, a, 200.00 / 729.00);
        msIntegrationPoints[20] = IntegrationPointType(a, -a, a, 125.00 / 729.00);

        msIntegrationPoints[21] = IntegrationPointType(-a, 0.0, a, 200.00 / 729.00);
        msIntegrationPoints[22] = IntegrationPointType(0.0, 0.0, a, 320.00 / 729.00);
        msIntegrationPoints[23] = IntegrationPointType(a, 0.0, a, 200.00 / 729.00);

        msIntegrationPoints[24] = IntegrationPointType(-a, a, a, 125.00 / 729.00);
        msIntegrationPoints[25] = IntegrationPointType(0.0, a, a, 200.00 / 729.00);
        msIntegrationPoints[26] = IntegrationPointType(a, a, a, 125.00 / 729.00);

       return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexadra Gauss-Legendre quadrature 3 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLegendreIntegrationPoints3

class KRATOS_API(KRATOS_CORE) HexahedronGaussLegendreIntegrationPoints4
{
public:
   KRATOS_CLASS_POINTER_DEFINITION(HexahedronGaussLegendreIntegrationPoints4);
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
       msIntegrationPoints[0] = IntegrationPointType(-0.86113631159405257522 , -0.86113631159405257522 , -0.86113631159405257522 , 0.04209147749053145454);
       msIntegrationPoints[1] = IntegrationPointType(-0.33998104358485626480 , -0.86113631159405257522 , -0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[2] = IntegrationPointType(0.33998104358485626480 , -0.86113631159405257522 , -0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[3] = IntegrationPointType(0.86113631159405257522 , -0.86113631159405257522 , -0.86113631159405257522 , 0.04209147749053145454);
       msIntegrationPoints[4] = IntegrationPointType(-0.86113631159405257522 , -0.33998104358485626480 , -0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[5] = IntegrationPointType(-0.33998104358485626480 , -0.33998104358485626480 , -0.86113631159405257522 , 0.14794033605678130087);
       msIntegrationPoints[6] = IntegrationPointType(0.33998104358485626480 , -0.33998104358485626480 , -0.86113631159405257522 , 0.14794033605678130087);
       msIntegrationPoints[7] = IntegrationPointType(0.86113631159405257522 , -0.33998104358485626480 , -0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[8] = IntegrationPointType(-0.86113631159405257522 , 0.33998104358485626480 , -0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[9] = IntegrationPointType(-0.33998104358485626480 , 0.33998104358485626480 , -0.86113631159405257522 , 0.14794033605678130087);
       msIntegrationPoints[10] = IntegrationPointType(0.33998104358485626480 , 0.33998104358485626480 , -0.86113631159405257522 , 0.14794033605678130087);
       msIntegrationPoints[11] = IntegrationPointType(0.86113631159405257522 , 0.33998104358485626480 , -0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[12] = IntegrationPointType(-0.86113631159405257522 , 0.86113631159405257522 , -0.86113631159405257522 , 0.04209147749053145454);
       msIntegrationPoints[13] = IntegrationPointType(-0.33998104358485626480 , 0.86113631159405257522 , -0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[14] = IntegrationPointType(0.33998104358485626480 , 0.86113631159405257522 , -0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[15] = IntegrationPointType(0.86113631159405257522 , 0.86113631159405257522 , -0.86113631159405257522 , 0.04209147749053145454);
       msIntegrationPoints[16] = IntegrationPointType(-0.86113631159405257522 , -0.86113631159405257522 , -0.33998104358485626480 , 0.07891151579507055098);
       msIntegrationPoints[17] = IntegrationPointType(-0.33998104358485626480 , -0.86113631159405257522 , -0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[18] = IntegrationPointType(0.33998104358485626480 , -0.86113631159405257522 , -0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[19] = IntegrationPointType(0.86113631159405257522 , -0.86113631159405257522 , -0.33998104358485626480 , 0.07891151579507055098);
       msIntegrationPoints[20] = IntegrationPointType(-0.86113631159405257522 , -0.33998104358485626480 , -0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[21] = IntegrationPointType(-0.33998104358485626480 , -0.33998104358485626480 , -0.33998104358485626480 , 0.27735296695391298990);
       msIntegrationPoints[22] = IntegrationPointType(0.33998104358485626480 , -0.33998104358485626480 , -0.33998104358485626480 , 0.27735296695391298990);
       msIntegrationPoints[23] = IntegrationPointType(0.86113631159405257522 , -0.33998104358485626480 , -0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[24] = IntegrationPointType(-0.86113631159405257522 , 0.33998104358485626480 , -0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[25] = IntegrationPointType(-0.33998104358485626480 , 0.33998104358485626480 , -0.33998104358485626480 , 0.27735296695391298990);
       msIntegrationPoints[26] = IntegrationPointType(0.33998104358485626480 , 0.33998104358485626480 , -0.33998104358485626480 , 0.27735296695391298990);
       msIntegrationPoints[27] = IntegrationPointType(0.86113631159405257522 , 0.33998104358485626480 , -0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[28] = IntegrationPointType(-0.86113631159405257522 , 0.86113631159405257522 , -0.33998104358485626480 , 0.07891151579507055098);
       msIntegrationPoints[29] = IntegrationPointType(-0.33998104358485626480 , 0.86113631159405257522 , -0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[30] = IntegrationPointType(0.33998104358485626480 , 0.86113631159405257522 , -0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[31] = IntegrationPointType(0.86113631159405257522 , 0.86113631159405257522 , -0.33998104358485626480 , 0.07891151579507055098);
       msIntegrationPoints[32] = IntegrationPointType(-0.86113631159405257522 , -0.86113631159405257522 , 0.33998104358485626480 , 0.07891151579507055098);
       msIntegrationPoints[33] = IntegrationPointType(-0.33998104358485626480 , -0.86113631159405257522 , 0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[34] = IntegrationPointType(0.33998104358485626480 , -0.86113631159405257522 , 0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[35] = IntegrationPointType(0.86113631159405257522 , -0.86113631159405257522 , 0.33998104358485626480 , 0.07891151579507055098);
       msIntegrationPoints[36] = IntegrationPointType(-0.86113631159405257522 , -0.33998104358485626480 , 0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[37] = IntegrationPointType(-0.33998104358485626480 , -0.33998104358485626480 , 0.33998104358485626480 , 0.27735296695391298990);
       msIntegrationPoints[38] = IntegrationPointType(0.33998104358485626480 , -0.33998104358485626480 , 0.33998104358485626480 , 0.27735296695391298990);
       msIntegrationPoints[39] = IntegrationPointType(0.86113631159405257522 , -0.33998104358485626480 , 0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[40] = IntegrationPointType(-0.86113631159405257522 , 0.33998104358485626480 , 0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[41] = IntegrationPointType(-0.33998104358485626480 , 0.33998104358485626480 , 0.33998104358485626480 , 0.27735296695391298990);
       msIntegrationPoints[42] = IntegrationPointType(0.33998104358485626480 , 0.33998104358485626480 , 0.33998104358485626480 , 0.27735296695391298990);
       msIntegrationPoints[43] = IntegrationPointType(0.86113631159405257522 , 0.33998104358485626480 , 0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[44] = IntegrationPointType(-0.86113631159405257522 , 0.86113631159405257522 , 0.33998104358485626480 , 0.07891151579507055098);
       msIntegrationPoints[45] = IntegrationPointType(-0.33998104358485626480 , 0.86113631159405257522 , 0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[46] = IntegrationPointType(0.33998104358485626480 , 0.86113631159405257522 , 0.33998104358485626480 , 0.14794033605678130087);
       msIntegrationPoints[47] = IntegrationPointType(0.86113631159405257522 , 0.86113631159405257522 , 0.33998104358485626480 , 0.07891151579507055098);
       msIntegrationPoints[48] = IntegrationPointType(-0.86113631159405257522 , -0.86113631159405257522 , 0.86113631159405257522 , 0.04209147749053145454);
       msIntegrationPoints[49] = IntegrationPointType(-0.33998104358485626480 , -0.86113631159405257522 , 0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[50] = IntegrationPointType(0.33998104358485626480 , -0.86113631159405257522 , 0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[51] = IntegrationPointType(0.86113631159405257522 , -0.86113631159405257522 , 0.86113631159405257522 , 0.04209147749053145454);
       msIntegrationPoints[52] = IntegrationPointType(-0.86113631159405257522 , -0.33998104358485626480 , 0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[53] = IntegrationPointType(-0.33998104358485626480 , -0.33998104358485626480 , 0.86113631159405257522 , 0.14794033605678130087);
       msIntegrationPoints[54] = IntegrationPointType(0.33998104358485626480 , -0.33998104358485626480 , 0.86113631159405257522 , 0.14794033605678130087);
       msIntegrationPoints[55] = IntegrationPointType(0.86113631159405257522 , -0.33998104358485626480 , 0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[56] = IntegrationPointType(-0.86113631159405257522 , 0.33998104358485626480 , 0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[57] = IntegrationPointType(-0.33998104358485626480 , 0.33998104358485626480 , 0.86113631159405257522 , 0.14794033605678130087);
       msIntegrationPoints[58] = IntegrationPointType(0.33998104358485626480 , 0.33998104358485626480 , 0.86113631159405257522 , 0.14794033605678130087);
       msIntegrationPoints[59] = IntegrationPointType(0.86113631159405257522 , 0.33998104358485626480 , 0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[60] = IntegrationPointType(-0.86113631159405257522 , 0.86113631159405257522 , 0.86113631159405257522 , 0.04209147749053145454);
       msIntegrationPoints[61] = IntegrationPointType(-0.33998104358485626480 , 0.86113631159405257522 , 0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[62] = IntegrationPointType(0.33998104358485626480 , 0.86113631159405257522 , 0.86113631159405257522 , 0.07891151579507055098);
       msIntegrationPoints[63] = IntegrationPointType(0.86113631159405257522 , 0.86113631159405257522 , 0.86113631159405257522 , 0.04209147749053145454);
       
       return msIntegrationPoints;
   }

   std::string Info() const
   {
       std::stringstream buffer;
       buffer << "Hexadra Gauss-Legendre quadrature 4 ";
       return buffer.str();
   }
protected:

private:

   static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLegendreIntegrationPoints4

class KRATOS_API(KRATOS_CORE) HexahedronGaussLegendreIntegrationPoints5
{
public:
   KRATOS_CLASS_POINTER_DEFINITION(HexahedronGaussLegendreIntegrationPoints5);
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
       msIntegrationPoints[0] = IntegrationPointType(-0.90617984593866399280 , -0.90617984593866399280 , -0.90617984593866399280 , 0.013299736420632648092);
       msIntegrationPoints[1] = IntegrationPointType(-0.53846931010568309104 , -0.90617984593866399280 , -0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[2] = IntegrationPointType(0 , -0.90617984593866399280 , -0.90617984593866399280 , 0.031934207352848290676);
       msIntegrationPoints[3] = IntegrationPointType(0.53846931010568309104 , -0.90617984593866399280 , -0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[4] = IntegrationPointType(0.90617984593866399280 , -0.90617984593866399280 , -0.90617984593866399280 , 0.013299736420632648092);
       msIntegrationPoints[5] = IntegrationPointType(-0.90617984593866399280 , -0.53846931010568309104 , -0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[6] = IntegrationPointType(-0.53846931010568309104 , -0.53846931010568309104 , -0.90617984593866399280 , 0.05427649123462815748);
       msIntegrationPoints[7] = IntegrationPointType(0 , -0.53846931010568309104 , -0.90617984593866399280 , 0.06451200000000000000);
       msIntegrationPoints[8] = IntegrationPointType(0.53846931010568309104 , -0.53846931010568309104 , -0.90617984593866399280 , 0.05427649123462815748);
       msIntegrationPoints[9] = IntegrationPointType(0.90617984593866399280 , -0.53846931010568309104 , -0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[10] = IntegrationPointType(-0.90617984593866399280 , 0 , -0.90617984593866399280 , 0.031934207352848290676);
       msIntegrationPoints[11] = IntegrationPointType(-0.53846931010568309104 , 0 , -0.90617984593866399280 , 0.06451200000000000000);
       msIntegrationPoints[12] = IntegrationPointType(0 , 0 , -0.90617984593866399280 , 0.07667773006934522489);
       msIntegrationPoints[13] = IntegrationPointType(0.53846931010568309104 , 0 , -0.90617984593866399280 , 0.06451200000000000000);
       msIntegrationPoints[14] = IntegrationPointType(0.90617984593866399280 , 0 , -0.90617984593866399280 , 0.031934207352848290676);
       msIntegrationPoints[15] = IntegrationPointType(-0.90617984593866399280 , 0.53846931010568309104 , -0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[16] = IntegrationPointType(-0.53846931010568309104 , 0.53846931010568309104 , -0.90617984593866399280 , 0.05427649123462815748);
       msIntegrationPoints[17] = IntegrationPointType(0 , 0.53846931010568309104 , -0.90617984593866399280 , 0.06451200000000000000);
       msIntegrationPoints[18] = IntegrationPointType(0.53846931010568309104 , 0.53846931010568309104 , -0.90617984593866399280 , 0.05427649123462815748);
       msIntegrationPoints[19] = IntegrationPointType(0.90617984593866399280 , 0.53846931010568309104 , -0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[20] = IntegrationPointType(-0.90617984593866399280 , 0.90617984593866399280 , -0.90617984593866399280 , 0.013299736420632648092);
       msIntegrationPoints[21] = IntegrationPointType(-0.53846931010568309104 , 0.90617984593866399280 , -0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[22] = IntegrationPointType(0 , 0.90617984593866399280 , -0.90617984593866399280 , 0.031934207352848290676);
       msIntegrationPoints[23] = IntegrationPointType(0.53846931010568309104 , 0.90617984593866399280 , -0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[24] = IntegrationPointType(0.90617984593866399280 , 0.90617984593866399280 , -0.90617984593866399280 , 0.013299736420632648092);
       msIntegrationPoints[25] = IntegrationPointType(-0.90617984593866399280 , -0.90617984593866399280 , -0.53846931010568309104 , 0.026867508765371842524);
       msIntegrationPoints[26] = IntegrationPointType(-0.53846931010568309104 , -0.90617984593866399280 , -0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[27] = IntegrationPointType(0 , -0.90617984593866399280 , -0.53846931010568309104 , 0.06451200000000000000);
       msIntegrationPoints[28] = IntegrationPointType(0.53846931010568309104 , -0.90617984593866399280 , -0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[29] = IntegrationPointType(0.90617984593866399280 , -0.90617984593866399280 , -0.53846931010568309104 , 0.026867508765371842524);
       msIntegrationPoints[30] = IntegrationPointType(-0.90617984593866399280 , -0.53846931010568309104 , -0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[31] = IntegrationPointType(-0.53846931010568309104 , -0.53846931010568309104 , -0.53846931010568309104 , 0.10964684245453881967);
       msIntegrationPoints[32] = IntegrationPointType(0 , -0.53846931010568309104 , -0.53846931010568309104 , 0.13032414106964827997);
       msIntegrationPoints[33] = IntegrationPointType(0.53846931010568309104 , -0.53846931010568309104 , -0.53846931010568309104 , 0.10964684245453881967);
       msIntegrationPoints[34] = IntegrationPointType(0.90617984593866399280 , -0.53846931010568309104 , -0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[35] = IntegrationPointType(-0.90617984593866399280 , 0 , -0.53846931010568309104 , 0.06451200000000000000);
       msIntegrationPoints[36] = IntegrationPointType(-0.53846931010568309104 , 0 , -0.53846931010568309104 , 0.13032414106964827997);
       msIntegrationPoints[37] = IntegrationPointType(0 , 0 , -0.53846931010568309104 , 0.15490078296220484370);
       msIntegrationPoints[38] = IntegrationPointType(0.53846931010568309104 , 0 , -0.53846931010568309104 , 0.13032414106964827997);
       msIntegrationPoints[39] = IntegrationPointType(0.90617984593866399280 , 0 , -0.53846931010568309104 , 0.06451200000000000000);
       msIntegrationPoints[40] = IntegrationPointType(-0.90617984593866399280 , 0.53846931010568309104 , -0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[41] = IntegrationPointType(-0.53846931010568309104 , 0.53846931010568309104 , -0.53846931010568309104 , 0.10964684245453881967);
       msIntegrationPoints[42] = IntegrationPointType(0 , 0.53846931010568309104 , -0.53846931010568309104 , 0.13032414106964827997);
       msIntegrationPoints[43] = IntegrationPointType(0.53846931010568309104 , 0.53846931010568309104 , -0.53846931010568309104 , 0.10964684245453881967);
       msIntegrationPoints[44] = IntegrationPointType(0.90617984593866399280 , 0.53846931010568309104 , -0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[45] = IntegrationPointType(-0.90617984593866399280 , 0.90617984593866399280 , -0.53846931010568309104 , 0.026867508765371842524);
       msIntegrationPoints[46] = IntegrationPointType(-0.53846931010568309104 , 0.90617984593866399280 , -0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[47] = IntegrationPointType(0 , 0.90617984593866399280 , -0.53846931010568309104 , 0.06451200000000000000);
       msIntegrationPoints[48] = IntegrationPointType(0.53846931010568309104 , 0.90617984593866399280 , -0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[49] = IntegrationPointType(0.90617984593866399280 , 0.90617984593866399280 , -0.53846931010568309104 , 0.026867508765371842524);
       msIntegrationPoints[50] = IntegrationPointType(-0.90617984593866399280 , -0.90617984593866399280 , 0 , 0.031934207352848290676);
       msIntegrationPoints[51] = IntegrationPointType(-0.53846931010568309104 , -0.90617984593866399280 , 0 , 0.06451200000000000000);
       msIntegrationPoints[52] = IntegrationPointType(0 , -0.90617984593866399280 , 0 , 0.07667773006934522489);
       msIntegrationPoints[53] = IntegrationPointType(0.53846931010568309104 , -0.90617984593866399280 , 0 , 0.06451200000000000000);
       msIntegrationPoints[54] = IntegrationPointType(0.90617984593866399280 , -0.90617984593866399280 , 0 , 0.031934207352848290676);
       msIntegrationPoints[55] = IntegrationPointType(-0.90617984593866399280 , -0.53846931010568309104 , 0 , 0.06451200000000000000);
       msIntegrationPoints[56] = IntegrationPointType(-0.53846931010568309104 , -0.53846931010568309104 , 0 , 0.13032414106964827997);
       msIntegrationPoints[57] = IntegrationPointType(0 , -0.53846931010568309104 , 0 , 0.15490078296220484370);
       msIntegrationPoints[58] = IntegrationPointType(0.53846931010568309104 , -0.53846931010568309104 , 0 , 0.13032414106964827997);
       msIntegrationPoints[59] = IntegrationPointType(0.90617984593866399280 , -0.53846931010568309104 , 0 , 0.06451200000000000000);
       msIntegrationPoints[60] = IntegrationPointType(-0.90617984593866399280 , 0 , 0 , 0.07667773006934522489);
       msIntegrationPoints[61] = IntegrationPointType(-0.53846931010568309104 , 0 , 0 , 0.15490078296220484370);
       msIntegrationPoints[62] = IntegrationPointType(0 , 0 , 0 , 0.18411210973936899863);
       msIntegrationPoints[63] = IntegrationPointType(0.53846931010568309104 , 0 , 0 , 0.15490078296220484370);
       msIntegrationPoints[64] = IntegrationPointType(0.90617984593866399280 , 0 , 0 , 0.07667773006934522489);
       msIntegrationPoints[65] = IntegrationPointType(-0.90617984593866399280 , 0.53846931010568309104 , 0 , 0.06451200000000000000);
       msIntegrationPoints[66] = IntegrationPointType(-0.53846931010568309104 , 0.53846931010568309104 , 0 , 0.13032414106964827997);
       msIntegrationPoints[67] = IntegrationPointType(0 , 0.53846931010568309104 , 0 , 0.15490078296220484370);
       msIntegrationPoints[68] = IntegrationPointType(0.53846931010568309104 , 0.53846931010568309104 , 0 , 0.13032414106964827997);
       msIntegrationPoints[69] = IntegrationPointType(0.90617984593866399280 , 0.53846931010568309104 , 0 , 0.06451200000000000000);
       msIntegrationPoints[70] = IntegrationPointType(-0.90617984593866399280 , 0.90617984593866399280 , 0 , 0.031934207352848290676);
       msIntegrationPoints[71] = IntegrationPointType(-0.53846931010568309104 , 0.90617984593866399280 , 0 , 0.06451200000000000000);
       msIntegrationPoints[72] = IntegrationPointType(0 , 0.90617984593866399280 , 0 , 0.07667773006934522489);
       msIntegrationPoints[73] = IntegrationPointType(0.53846931010568309104 , 0.90617984593866399280 , 0 , 0.06451200000000000000);
       msIntegrationPoints[74] = IntegrationPointType(0.90617984593866399280 , 0.90617984593866399280 , 0 , 0.031934207352848290676);
       msIntegrationPoints[75] = IntegrationPointType(-0.90617984593866399280 , -0.90617984593866399280 , 0.53846931010568309104 , 0.026867508765371842524);
       msIntegrationPoints[76] = IntegrationPointType(-0.53846931010568309104 , -0.90617984593866399280 , 0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[77] = IntegrationPointType(0 , -0.90617984593866399280 , 0.53846931010568309104 , 0.06451200000000000000);
       msIntegrationPoints[78] = IntegrationPointType(0.53846931010568309104 , -0.90617984593866399280 , 0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[79] = IntegrationPointType(0.90617984593866399280 , -0.90617984593866399280 , 0.53846931010568309104 , 0.026867508765371842524);
       msIntegrationPoints[80] = IntegrationPointType(-0.90617984593866399280 , -0.53846931010568309104 , 0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[81] = IntegrationPointType(-0.53846931010568309104 , -0.53846931010568309104 , 0.53846931010568309104 , 0.10964684245453881967);
       msIntegrationPoints[82] = IntegrationPointType(0 , -0.53846931010568309104 , 0.53846931010568309104 , 0.13032414106964827997);
       msIntegrationPoints[83] = IntegrationPointType(0.53846931010568309104 , -0.53846931010568309104 , 0.53846931010568309104 , 0.10964684245453881967);
       msIntegrationPoints[84] = IntegrationPointType(0.90617984593866399280 , -0.53846931010568309104 , 0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[85] = IntegrationPointType(-0.90617984593866399280 , 0 , 0.53846931010568309104 , 0.06451200000000000000);
       msIntegrationPoints[86] = IntegrationPointType(-0.53846931010568309104 , 0 , 0.53846931010568309104 , 0.13032414106964827997);
       msIntegrationPoints[87] = IntegrationPointType(0 , 0 , 0.53846931010568309104 , 0.15490078296220484370);
       msIntegrationPoints[88] = IntegrationPointType(0.53846931010568309104 , 0 , 0.53846931010568309104 , 0.13032414106964827997);
       msIntegrationPoints[89] = IntegrationPointType(0.90617984593866399280 , 0 , 0.53846931010568309104 , 0.06451200000000000000);
       msIntegrationPoints[90] = IntegrationPointType(-0.90617984593866399280 , 0.53846931010568309104 , 0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[91] = IntegrationPointType(-0.53846931010568309104 , 0.53846931010568309104 , 0.53846931010568309104 , 0.10964684245453881967);
       msIntegrationPoints[92] = IntegrationPointType(0 , 0.53846931010568309104 , 0.53846931010568309104 , 0.13032414106964827997);
       msIntegrationPoints[93] = IntegrationPointType(0.53846931010568309104 , 0.53846931010568309104 , 0.53846931010568309104 , 0.10964684245453881967);
       msIntegrationPoints[94] = IntegrationPointType(0.90617984593866399280 , 0.53846931010568309104 , 0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[95] = IntegrationPointType(-0.90617984593866399280 , 0.90617984593866399280 , 0.53846931010568309104 , 0.026867508765371842524);
       msIntegrationPoints[96] = IntegrationPointType(-0.53846931010568309104 , 0.90617984593866399280 , 0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[97] = IntegrationPointType(0 , 0.90617984593866399280 , 0.53846931010568309104 , 0.06451200000000000000);
       msIntegrationPoints[98] = IntegrationPointType(0.53846931010568309104 , 0.90617984593866399280 , 0.53846931010568309104 , 0.05427649123462815748);
       msIntegrationPoints[99] = IntegrationPointType(0.90617984593866399280 , 0.90617984593866399280 , 0.53846931010568309104 , 0.026867508765371842524);
       msIntegrationPoints[100] = IntegrationPointType(-0.90617984593866399280 , -0.90617984593866399280 , 0.90617984593866399280 , 0.013299736420632648092);
       msIntegrationPoints[101] = IntegrationPointType(-0.53846931010568309104 , -0.90617984593866399280 , 0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[102] = IntegrationPointType(0 , -0.90617984593866399280 , 0.90617984593866399280 , 0.031934207352848290676);
       msIntegrationPoints[103] = IntegrationPointType(0.53846931010568309104 , -0.90617984593866399280 , 0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[104] = IntegrationPointType(0.90617984593866399280 , -0.90617984593866399280 , 0.90617984593866399280 , 0.013299736420632648092);
       msIntegrationPoints[105] = IntegrationPointType(-0.90617984593866399280 , -0.53846931010568309104 , 0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[106] = IntegrationPointType(-0.53846931010568309104 , -0.53846931010568309104 , 0.90617984593866399280 , 0.05427649123462815748);
       msIntegrationPoints[107] = IntegrationPointType(0 , -0.53846931010568309104 , 0.90617984593866399280 , 0.06451200000000000000);
       msIntegrationPoints[108] = IntegrationPointType(0.53846931010568309104 , -0.53846931010568309104 , 0.90617984593866399280 , 0.05427649123462815748);
       msIntegrationPoints[109] = IntegrationPointType(0.90617984593866399280 , -0.53846931010568309104 , 0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[110] = IntegrationPointType(-0.90617984593866399280 , 0 , 0.90617984593866399280 , 0.031934207352848290676);
       msIntegrationPoints[111] = IntegrationPointType(-0.53846931010568309104 , 0 , 0.90617984593866399280 , 0.06451200000000000000);
       msIntegrationPoints[112] = IntegrationPointType(0 , 0 , 0.90617984593866399280 , 0.07667773006934522489);
       msIntegrationPoints[113] = IntegrationPointType(0.53846931010568309104 , 0 , 0.90617984593866399280 , 0.06451200000000000000);
       msIntegrationPoints[114] = IntegrationPointType(0.90617984593866399280 , 0 , 0.90617984593866399280 , 0.031934207352848290676);
       msIntegrationPoints[115] = IntegrationPointType(-0.90617984593866399280 , 0.53846931010568309104 , 0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[116] = IntegrationPointType(-0.53846931010568309104 , 0.53846931010568309104 , 0.90617984593866399280 , 0.05427649123462815748);
       msIntegrationPoints[117] = IntegrationPointType(0 , 0.53846931010568309104 , 0.90617984593866399280 , 0.06451200000000000000);
       msIntegrationPoints[118] = IntegrationPointType(0.53846931010568309104 , 0.53846931010568309104 , 0.90617984593866399280 , 0.05427649123462815748);
       msIntegrationPoints[119] = IntegrationPointType(0.90617984593866399280 , 0.53846931010568309104 , 0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[120] = IntegrationPointType(-0.90617984593866399280 , 0.90617984593866399280 , 0.90617984593866399280 , 0.013299736420632648092);
       msIntegrationPoints[121] = IntegrationPointType(-0.53846931010568309104 , 0.90617984593866399280 , 0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[122] = IntegrationPointType(0 , 0.90617984593866399280 , 0.90617984593866399280 , 0.031934207352848290676);
       msIntegrationPoints[123] = IntegrationPointType(0.53846931010568309104 , 0.90617984593866399280 , 0.90617984593866399280 , 0.026867508765371842524);
       msIntegrationPoints[124] = IntegrationPointType(0.90617984593866399280 , 0.90617984593866399280 , 0.90617984593866399280 , 0.013299736420632648092);

       return msIntegrationPoints;
   }

   std::string Info() const
   {
       std::stringstream buffer;
       buffer << "Hexadra Gauss-Legendre quadrature 5 ";
       return buffer.str();
   }
protected:

private:

   static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLegendreIntegrationPoints5

class KRATOS_API(KRATOS_CORE) HexahedronGaussLegendreIntegrationPoints6
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(HexahedronGaussLegendreIntegrationPoints6);
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
        msIntegrationPoints[0] = IntegrationPointType( -0.9324695142031520278123 , -0.9324695142031520278123 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[1] = IntegrationPointType( -0.9324695142031520278123 , -0.9324695142031520278123 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[2] = IntegrationPointType( -0.9324695142031520278123 , -0.9324695142031520278123 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[3] = IntegrationPointType( -0.9324695142031520278123 , -0.9324695142031520278123 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[4] = IntegrationPointType( -0.9324695142031520278123 , -0.9324695142031520278123 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[5] = IntegrationPointType( -0.9324695142031520278123 , -0.9324695142031520278123 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[6] = IntegrationPointType( -0.9324695142031520278123 , -0.6612093864662645136614 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[7] = IntegrationPointType( -0.9324695142031520278123 , -0.6612093864662645136614 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[8] = IntegrationPointType( -0.9324695142031520278123 , -0.6612093864662645136614 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[9] = IntegrationPointType( -0.9324695142031520278123 , -0.6612093864662645136614 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[10] = IntegrationPointType( -0.9324695142031520278123 , -0.6612093864662645136614 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[11] = IntegrationPointType( -0.9324695142031520278123 , -0.6612093864662645136614 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[12] = IntegrationPointType( -0.9324695142031520278123 , -0.2386191860831969086305 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[13] = IntegrationPointType( -0.9324695142031520278123 , -0.2386191860831969086305 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[14] = IntegrationPointType( -0.9324695142031520278123 , -0.2386191860831969086305 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[15] = IntegrationPointType( -0.9324695142031520278123 , -0.2386191860831969086305 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[16] = IntegrationPointType( -0.9324695142031520278123 , -0.2386191860831969086305 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[17] = IntegrationPointType( -0.9324695142031520278123 , -0.2386191860831969086305 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[18] = IntegrationPointType( -0.9324695142031520278123 , 0.2386191860831969086305 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[19] = IntegrationPointType( -0.9324695142031520278123 , 0.2386191860831969086305 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[20] = IntegrationPointType( -0.9324695142031520278123 , 0.2386191860831969086305 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[21] = IntegrationPointType( -0.9324695142031520278123 , 0.2386191860831969086305 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[22] = IntegrationPointType( -0.9324695142031520278123 , 0.2386191860831969086305 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[23] = IntegrationPointType( -0.9324695142031520278123 , 0.2386191860831969086305 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[24] = IntegrationPointType( -0.9324695142031520278123 , 0.6612093864662645136614 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[25] = IntegrationPointType( -0.9324695142031520278123 , 0.6612093864662645136614 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[26] = IntegrationPointType( -0.9324695142031520278123 , 0.6612093864662645136614 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[27] = IntegrationPointType( -0.9324695142031520278123 , 0.6612093864662645136614 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[28] = IntegrationPointType( -0.9324695142031520278123 , 0.6612093864662645136614 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[29] = IntegrationPointType( -0.9324695142031520278123 , 0.6612093864662645136614 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[30] = IntegrationPointType( -0.9324695142031520278123 , 0.9324695142031520278123 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[31] = IntegrationPointType( -0.9324695142031520278123 , 0.9324695142031520278123 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[32] = IntegrationPointType( -0.9324695142031520278123 , 0.9324695142031520278123 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[33] = IntegrationPointType( -0.9324695142031520278123 , 0.9324695142031520278123 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[34] = IntegrationPointType( -0.9324695142031520278123 , 0.9324695142031520278123 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[35] = IntegrationPointType( -0.9324695142031520278123 , 0.9324695142031520278123 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[36] = IntegrationPointType( -0.6612093864662645136614 , -0.9324695142031520278123 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[37] = IntegrationPointType( -0.6612093864662645136614 , -0.9324695142031520278123 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[38] = IntegrationPointType( -0.6612093864662645136614 , -0.9324695142031520278123 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[39] = IntegrationPointType( -0.6612093864662645136614 , -0.9324695142031520278123 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[40] = IntegrationPointType( -0.6612093864662645136614 , -0.9324695142031520278123 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[41] = IntegrationPointType( -0.6612093864662645136614 , -0.9324695142031520278123 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[42] = IntegrationPointType( -0.6612093864662645136614 , -0.6612093864662645136614 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[43] = IntegrationPointType( -0.6612093864662645136614 , -0.6612093864662645136614 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[44] = IntegrationPointType( -0.6612093864662645136614 , -0.6612093864662645136614 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[45] = IntegrationPointType( -0.6612093864662645136614 , -0.6612093864662645136614 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[46] = IntegrationPointType( -0.6612093864662645136614 , -0.6612093864662645136614 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[47] = IntegrationPointType( -0.6612093864662645136614 , -0.6612093864662645136614 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[48] = IntegrationPointType( -0.6612093864662645136614 , -0.2386191860831969086305 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[49] = IntegrationPointType( -0.6612093864662645136614 , -0.2386191860831969086305 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[50] = IntegrationPointType( -0.6612093864662645136614 , -0.2386191860831969086305 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[51] = IntegrationPointType( -0.6612093864662645136614 , -0.2386191860831969086305 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[52] = IntegrationPointType( -0.6612093864662645136614 , -0.2386191860831969086305 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[53] = IntegrationPointType( -0.6612093864662645136614 , -0.2386191860831969086305 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[54] = IntegrationPointType( -0.6612093864662645136614 , 0.2386191860831969086305 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[55] = IntegrationPointType( -0.6612093864662645136614 , 0.2386191860831969086305 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[56] = IntegrationPointType( -0.6612093864662645136614 , 0.2386191860831969086305 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[57] = IntegrationPointType( -0.6612093864662645136614 , 0.2386191860831969086305 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[58] = IntegrationPointType( -0.6612093864662645136614 , 0.2386191860831969086305 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[59] = IntegrationPointType( -0.6612093864662645136614 , 0.2386191860831969086305 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[60] = IntegrationPointType( -0.6612093864662645136614 , 0.6612093864662645136614 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[61] = IntegrationPointType( -0.6612093864662645136614 , 0.6612093864662645136614 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[62] = IntegrationPointType( -0.6612093864662645136614 , 0.6612093864662645136614 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[63] = IntegrationPointType( -0.6612093864662645136614 , 0.6612093864662645136614 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[64] = IntegrationPointType( -0.6612093864662645136614 , 0.6612093864662645136614 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[65] = IntegrationPointType( -0.6612093864662645136614 , 0.6612093864662645136614 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[66] = IntegrationPointType( -0.6612093864662645136614 , 0.9324695142031520278123 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[67] = IntegrationPointType( -0.6612093864662645136614 , 0.9324695142031520278123 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[68] = IntegrationPointType( -0.6612093864662645136614 , 0.9324695142031520278123 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[69] = IntegrationPointType( -0.6612093864662645136614 , 0.9324695142031520278123 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[70] = IntegrationPointType( -0.6612093864662645136614 , 0.9324695142031520278123 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[71] = IntegrationPointType( -0.6612093864662645136614 , 0.9324695142031520278123 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[72] = IntegrationPointType( -0.2386191860831969086305 , -0.9324695142031520278123 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[73] = IntegrationPointType( -0.2386191860831969086305 , -0.9324695142031520278123 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[74] = IntegrationPointType( -0.2386191860831969086305 , -0.9324695142031520278123 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[75] = IntegrationPointType( -0.2386191860831969086305 , -0.9324695142031520278123 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[76] = IntegrationPointType( -0.2386191860831969086305 , -0.9324695142031520278123 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[77] = IntegrationPointType( -0.2386191860831969086305 , -0.9324695142031520278123 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[78] = IntegrationPointType( -0.2386191860831969086305 , -0.6612093864662645136614 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[79] = IntegrationPointType( -0.2386191860831969086305 , -0.6612093864662645136614 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[80] = IntegrationPointType( -0.2386191860831969086305 , -0.6612093864662645136614 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[81] = IntegrationPointType( -0.2386191860831969086305 , -0.6612093864662645136614 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[82] = IntegrationPointType( -0.2386191860831969086305 , -0.6612093864662645136614 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[83] = IntegrationPointType( -0.2386191860831969086305 , -0.6612093864662645136614 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[84] = IntegrationPointType( -0.2386191860831969086305 , -0.2386191860831969086305 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[85] = IntegrationPointType( -0.2386191860831969086305 , -0.2386191860831969086305 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[86] = IntegrationPointType( -0.2386191860831969086305 , -0.2386191860831969086305 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[87] = IntegrationPointType( -0.2386191860831969086305 , -0.2386191860831969086305 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[88] = IntegrationPointType( -0.2386191860831969086305 , -0.2386191860831969086305 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[89] = IntegrationPointType( -0.2386191860831969086305 , -0.2386191860831969086305 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[90] = IntegrationPointType( -0.2386191860831969086305 , 0.2386191860831969086305 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[91] = IntegrationPointType( -0.2386191860831969086305 , 0.2386191860831969086305 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[92] = IntegrationPointType( -0.2386191860831969086305 , 0.2386191860831969086305 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[93] = IntegrationPointType( -0.2386191860831969086305 , 0.2386191860831969086305 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[94] = IntegrationPointType( -0.2386191860831969086305 , 0.2386191860831969086305 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[95] = IntegrationPointType( -0.2386191860831969086305 , 0.2386191860831969086305 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[96] = IntegrationPointType( -0.2386191860831969086305 , 0.6612093864662645136614 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[97] = IntegrationPointType( -0.2386191860831969086305 , 0.6612093864662645136614 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[98] = IntegrationPointType( -0.2386191860831969086305 , 0.6612093864662645136614 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[99] = IntegrationPointType( -0.2386191860831969086305 , 0.6612093864662645136614 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[100] = IntegrationPointType( -0.2386191860831969086305 , 0.6612093864662645136614 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[101] = IntegrationPointType( -0.2386191860831969086305 , 0.6612093864662645136614 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[102] = IntegrationPointType( -0.2386191860831969086305 , 0.9324695142031520278123 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[103] = IntegrationPointType( -0.2386191860831969086305 , 0.9324695142031520278123 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[104] = IntegrationPointType( -0.2386191860831969086305 , 0.9324695142031520278123 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[105] = IntegrationPointType( -0.2386191860831969086305 , 0.9324695142031520278123 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[106] = IntegrationPointType( -0.2386191860831969086305 , 0.9324695142031520278123 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[107] = IntegrationPointType( -0.2386191860831969086305 , 0.9324695142031520278123 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[108] = IntegrationPointType( 0.2386191860831969086305 , -0.9324695142031520278123 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[109] = IntegrationPointType( 0.2386191860831969086305 , -0.9324695142031520278123 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[110] = IntegrationPointType( 0.2386191860831969086305 , -0.9324695142031520278123 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[111] = IntegrationPointType( 0.2386191860831969086305 , -0.9324695142031520278123 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[112] = IntegrationPointType( 0.2386191860831969086305 , -0.9324695142031520278123 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[113] = IntegrationPointType( 0.2386191860831969086305 , -0.9324695142031520278123 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[114] = IntegrationPointType( 0.2386191860831969086305 , -0.6612093864662645136614 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[115] = IntegrationPointType( 0.2386191860831969086305 , -0.6612093864662645136614 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[116] = IntegrationPointType( 0.2386191860831969086305 , -0.6612093864662645136614 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[117] = IntegrationPointType( 0.2386191860831969086305 , -0.6612093864662645136614 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[118] = IntegrationPointType( 0.2386191860831969086305 , -0.6612093864662645136614 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[119] = IntegrationPointType( 0.2386191860831969086305 , -0.6612093864662645136614 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[120] = IntegrationPointType( 0.2386191860831969086305 , -0.2386191860831969086305 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[121] = IntegrationPointType( 0.2386191860831969086305 , -0.2386191860831969086305 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[122] = IntegrationPointType( 0.2386191860831969086305 , -0.2386191860831969086305 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[123] = IntegrationPointType( 0.2386191860831969086305 , -0.2386191860831969086305 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[124] = IntegrationPointType( 0.2386191860831969086305 , -0.2386191860831969086305 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[125] = IntegrationPointType( 0.2386191860831969086305 , -0.2386191860831969086305 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[126] = IntegrationPointType( 0.2386191860831969086305 , 0.2386191860831969086305 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[127] = IntegrationPointType( 0.2386191860831969086305 , 0.2386191860831969086305 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[128] = IntegrationPointType( 0.2386191860831969086305 , 0.2386191860831969086305 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[129] = IntegrationPointType( 0.2386191860831969086305 , 0.2386191860831969086305 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[130] = IntegrationPointType( 0.2386191860831969086305 , 0.2386191860831969086305 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[131] = IntegrationPointType( 0.2386191860831969086305 , 0.2386191860831969086305 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[132] = IntegrationPointType( 0.2386191860831969086305 , 0.6612093864662645136614 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[133] = IntegrationPointType( 0.2386191860831969086305 , 0.6612093864662645136614 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[134] = IntegrationPointType( 0.2386191860831969086305 , 0.6612093864662645136614 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[135] = IntegrationPointType( 0.2386191860831969086305 , 0.6612093864662645136614 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[136] = IntegrationPointType( 0.2386191860831969086305 , 0.6612093864662645136614 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[137] = IntegrationPointType( 0.2386191860831969086305 , 0.6612093864662645136614 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[138] = IntegrationPointType( 0.2386191860831969086305 , 0.9324695142031520278123 , -0.9324695142031520278123 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[139] = IntegrationPointType( 0.2386191860831969086305 , 0.9324695142031520278123 , -0.6612093864662645136614 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[140] = IntegrationPointType( 0.2386191860831969086305 , 0.9324695142031520278123 , -0.2386191860831969086305 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[141] = IntegrationPointType( 0.2386191860831969086305 , 0.9324695142031520278123 , 0.2386191860831969086305 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[142] = IntegrationPointType( 0.2386191860831969086305 , 0.9324695142031520278123 , 0.6612093864662645136614 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[143] = IntegrationPointType( 0.2386191860831969086305 , 0.9324695142031520278123 , 0.9324695142031520278123 , 0.46791393457269104739 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[144] = IntegrationPointType( 0.6612093864662645136614 , -0.9324695142031520278123 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[145] = IntegrationPointType( 0.6612093864662645136614 , -0.9324695142031520278123 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[146] = IntegrationPointType( 0.6612093864662645136614 , -0.9324695142031520278123 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[147] = IntegrationPointType( 0.6612093864662645136614 , -0.9324695142031520278123 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[148] = IntegrationPointType( 0.6612093864662645136614 , -0.9324695142031520278123 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[149] = IntegrationPointType( 0.6612093864662645136614 , -0.9324695142031520278123 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[150] = IntegrationPointType( 0.6612093864662645136614 , -0.6612093864662645136614 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[151] = IntegrationPointType( 0.6612093864662645136614 , -0.6612093864662645136614 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[152] = IntegrationPointType( 0.6612093864662645136614 , -0.6612093864662645136614 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[153] = IntegrationPointType( 0.6612093864662645136614 , -0.6612093864662645136614 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[154] = IntegrationPointType( 0.6612093864662645136614 , -0.6612093864662645136614 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[155] = IntegrationPointType( 0.6612093864662645136614 , -0.6612093864662645136614 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[156] = IntegrationPointType( 0.6612093864662645136614 , -0.2386191860831969086305 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[157] = IntegrationPointType( 0.6612093864662645136614 , -0.2386191860831969086305 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[158] = IntegrationPointType( 0.6612093864662645136614 , -0.2386191860831969086305 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[159] = IntegrationPointType( 0.6612093864662645136614 , -0.2386191860831969086305 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[160] = IntegrationPointType( 0.6612093864662645136614 , -0.2386191860831969086305 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[161] = IntegrationPointType( 0.6612093864662645136614 , -0.2386191860831969086305 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[162] = IntegrationPointType( 0.6612093864662645136614 , 0.2386191860831969086305 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[163] = IntegrationPointType( 0.6612093864662645136614 , 0.2386191860831969086305 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[164] = IntegrationPointType( 0.6612093864662645136614 , 0.2386191860831969086305 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[165] = IntegrationPointType( 0.6612093864662645136614 , 0.2386191860831969086305 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[166] = IntegrationPointType( 0.6612093864662645136614 , 0.2386191860831969086305 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[167] = IntegrationPointType( 0.6612093864662645136614 , 0.2386191860831969086305 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[168] = IntegrationPointType( 0.6612093864662645136614 , 0.6612093864662645136614 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[169] = IntegrationPointType( 0.6612093864662645136614 , 0.6612093864662645136614 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[170] = IntegrationPointType( 0.6612093864662645136614 , 0.6612093864662645136614 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[171] = IntegrationPointType( 0.6612093864662645136614 , 0.6612093864662645136614 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[172] = IntegrationPointType( 0.6612093864662645136614 , 0.6612093864662645136614 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[173] = IntegrationPointType( 0.6612093864662645136614 , 0.6612093864662645136614 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[174] = IntegrationPointType( 0.6612093864662645136614 , 0.9324695142031520278123 , -0.9324695142031520278123 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[175] = IntegrationPointType( 0.6612093864662645136614 , 0.9324695142031520278123 , -0.6612093864662645136614 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[176] = IntegrationPointType( 0.6612093864662645136614 , 0.9324695142031520278123 , -0.2386191860831969086305 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[177] = IntegrationPointType( 0.6612093864662645136614 , 0.9324695142031520278123 , 0.2386191860831969086305 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[178] = IntegrationPointType( 0.6612093864662645136614 , 0.9324695142031520278123 , 0.6612093864662645136614 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[179] = IntegrationPointType( 0.6612093864662645136614 , 0.9324695142031520278123 , 0.9324695142031520278123 , 0.3607615730481386075698 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[180] = IntegrationPointType( 0.9324695142031520278123 , -0.9324695142031520278123 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[181] = IntegrationPointType( 0.9324695142031520278123 , -0.9324695142031520278123 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[182] = IntegrationPointType( 0.9324695142031520278123 , -0.9324695142031520278123 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[183] = IntegrationPointType( 0.9324695142031520278123 , -0.9324695142031520278123 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[184] = IntegrationPointType( 0.9324695142031520278123 , -0.9324695142031520278123 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[185] = IntegrationPointType( 0.9324695142031520278123 , -0.9324695142031520278123 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        msIntegrationPoints[186] = IntegrationPointType( 0.9324695142031520278123 , -0.6612093864662645136614 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[187] = IntegrationPointType( 0.9324695142031520278123 , -0.6612093864662645136614 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[188] = IntegrationPointType( 0.9324695142031520278123 , -0.6612093864662645136614 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[189] = IntegrationPointType( 0.9324695142031520278123 , -0.6612093864662645136614 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[190] = IntegrationPointType( 0.9324695142031520278123 , -0.6612093864662645136614 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[191] = IntegrationPointType( 0.9324695142031520278123 , -0.6612093864662645136614 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[192] = IntegrationPointType( 0.9324695142031520278123 , -0.2386191860831969086305 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[193] = IntegrationPointType( 0.9324695142031520278123 , -0.2386191860831969086305 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[194] = IntegrationPointType( 0.9324695142031520278123 , -0.2386191860831969086305 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[195] = IntegrationPointType( 0.9324695142031520278123 , -0.2386191860831969086305 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[196] = IntegrationPointType( 0.9324695142031520278123 , -0.2386191860831969086305 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[197] = IntegrationPointType( 0.9324695142031520278123 , -0.2386191860831969086305 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[198] = IntegrationPointType( 0.9324695142031520278123 , 0.2386191860831969086305 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.1713244923791703450403 );
        msIntegrationPoints[199] = IntegrationPointType( 0.9324695142031520278123 , 0.2386191860831969086305 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[200] = IntegrationPointType( 0.9324695142031520278123 , 0.2386191860831969086305 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[201] = IntegrationPointType( 0.9324695142031520278123 , 0.2386191860831969086305 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.46791393457269104739 );
        msIntegrationPoints[202] = IntegrationPointType( 0.9324695142031520278123 , 0.2386191860831969086305 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.3607615730481386075698 );
        msIntegrationPoints[203] = IntegrationPointType( 0.9324695142031520278123 , 0.2386191860831969086305 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.46791393457269104739 * 0.1713244923791703450403 );

        msIntegrationPoints[204] = IntegrationPointType( 0.9324695142031520278123 , 0.6612093864662645136614 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.1713244923791703450403 );
        msIntegrationPoints[205] = IntegrationPointType( 0.9324695142031520278123 , 0.6612093864662645136614 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[206] = IntegrationPointType( 0.9324695142031520278123 , 0.6612093864662645136614 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[207] = IntegrationPointType( 0.9324695142031520278123 , 0.6612093864662645136614 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.46791393457269104739 );
        msIntegrationPoints[208] = IntegrationPointType( 0.9324695142031520278123 , 0.6612093864662645136614 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.3607615730481386075698 );
        msIntegrationPoints[209] = IntegrationPointType( 0.9324695142031520278123 , 0.6612093864662645136614 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.3607615730481386075698 * 0.1713244923791703450403 );

        msIntegrationPoints[210] = IntegrationPointType( 0.9324695142031520278123 , 0.9324695142031520278123 , -0.9324695142031520278123 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.1713244923791703450403 );
        msIntegrationPoints[211] = IntegrationPointType( 0.9324695142031520278123 , 0.9324695142031520278123 , -0.6612093864662645136614 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[212] = IntegrationPointType( 0.9324695142031520278123 , 0.9324695142031520278123 , -0.2386191860831969086305 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[213] = IntegrationPointType( 0.9324695142031520278123 , 0.9324695142031520278123 , 0.2386191860831969086305 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.46791393457269104739 );
        msIntegrationPoints[214] = IntegrationPointType( 0.9324695142031520278123 , 0.9324695142031520278123 , 0.6612093864662645136614 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.3607615730481386075698 );
        msIntegrationPoints[215] = IntegrationPointType( 0.9324695142031520278123 , 0.9324695142031520278123 , 0.9324695142031520278123 , 0.1713244923791703450403 * 0.1713244923791703450403 * 0.1713244923791703450403 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Legendre quadrature 6";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLegendreIntegrationPoints6

class KRATOS_API(KRATOS_CORE) HexahedronGaussLegendreIntegrationPoints7
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(HexahedronGaussLegendreIntegrationPoints7);
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
        msIntegrationPoints[0] = IntegrationPointType( -0.9491079123427585245262 , -0.9491079123427585245262 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[1] = IntegrationPointType( -0.9491079123427585245262 , -0.9491079123427585245262 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[2] = IntegrationPointType( -0.9491079123427585245262 , -0.9491079123427585245262 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[3] = IntegrationPointType( -0.9491079123427585245262 , -0.9491079123427585245262 , 0 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[4] = IntegrationPointType( -0.9491079123427585245262 , -0.9491079123427585245262 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[5] = IntegrationPointType( -0.9491079123427585245262 , -0.9491079123427585245262 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[6] = IntegrationPointType( -0.9491079123427585245262 , -0.9491079123427585245262 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[7] = IntegrationPointType( -0.9491079123427585245262 , -0.7415311855993944398639 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[8] = IntegrationPointType( -0.9491079123427585245262 , -0.7415311855993944398639 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[9] = IntegrationPointType( -0.9491079123427585245262 , -0.7415311855993944398639 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[10] = IntegrationPointType( -0.9491079123427585245262 , -0.7415311855993944398639 , 0 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[11] = IntegrationPointType( -0.9491079123427585245262 , -0.7415311855993944398639 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[12] = IntegrationPointType( -0.9491079123427585245262 , -0.7415311855993944398639 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[13] = IntegrationPointType( -0.9491079123427585245262 , -0.7415311855993944398639 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[14] = IntegrationPointType( -0.9491079123427585245262 , -0.4058451513773971669066 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[15] = IntegrationPointType( -0.9491079123427585245262 , -0.4058451513773971669066 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[16] = IntegrationPointType( -0.9491079123427585245262 , -0.4058451513773971669066 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[17] = IntegrationPointType( -0.9491079123427585245262 , -0.4058451513773971669066 , 0 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[18] = IntegrationPointType( -0.9491079123427585245262 , -0.4058451513773971669066 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[19] = IntegrationPointType( -0.9491079123427585245262 , -0.4058451513773971669066 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[20] = IntegrationPointType( -0.9491079123427585245262 , -0.4058451513773971669066 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[21] = IntegrationPointType( -0.9491079123427585245262 , 0 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.1294849661688696932706 );
        msIntegrationPoints[22] = IntegrationPointType( -0.9491079123427585245262 , 0 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[23] = IntegrationPointType( -0.9491079123427585245262 , 0 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[24] = IntegrationPointType( -0.9491079123427585245262 , 0 , 0 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.4179591836734693877551 );
        msIntegrationPoints[25] = IntegrationPointType( -0.9491079123427585245262 , 0 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[26] = IntegrationPointType( -0.9491079123427585245262 , 0 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[27] = IntegrationPointType( -0.9491079123427585245262 , 0 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.1294849661688696932706 );

        msIntegrationPoints[28] = IntegrationPointType( -0.9491079123427585245262 , 0.4058451513773971669066 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[29] = IntegrationPointType( -0.9491079123427585245262 , 0.4058451513773971669066 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[30] = IntegrationPointType( -0.9491079123427585245262 , 0.4058451513773971669066 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[31] = IntegrationPointType( -0.9491079123427585245262 , 0.4058451513773971669066 , 0 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[32] = IntegrationPointType( -0.9491079123427585245262 , 0.4058451513773971669066 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[33] = IntegrationPointType( -0.9491079123427585245262 , 0.4058451513773971669066 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[34] = IntegrationPointType( -0.9491079123427585245262 , 0.4058451513773971669066 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[35] = IntegrationPointType( -0.9491079123427585245262 , 0.7415311855993944398639 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[36] = IntegrationPointType( -0.9491079123427585245262 , 0.7415311855993944398639 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[37] = IntegrationPointType( -0.9491079123427585245262 , 0.7415311855993944398639 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[38] = IntegrationPointType( -0.9491079123427585245262 , 0.7415311855993944398639 , 0 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[39] = IntegrationPointType( -0.9491079123427585245262 , 0.7415311855993944398639 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[40] = IntegrationPointType( -0.9491079123427585245262 , 0.7415311855993944398639 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[41] = IntegrationPointType( -0.9491079123427585245262 , 0.7415311855993944398639 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[42] = IntegrationPointType( -0.9491079123427585245262 , 0.9491079123427585245262 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[43] = IntegrationPointType( -0.9491079123427585245262 , 0.9491079123427585245262 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[44] = IntegrationPointType( -0.9491079123427585245262 , 0.9491079123427585245262 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[45] = IntegrationPointType( -0.9491079123427585245262 , 0.9491079123427585245262 , 0 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[46] = IntegrationPointType( -0.9491079123427585245262 , 0.9491079123427585245262 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[47] = IntegrationPointType( -0.9491079123427585245262 , 0.9491079123427585245262 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[48] = IntegrationPointType( -0.9491079123427585245262 , 0.9491079123427585245262 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[49] = IntegrationPointType( -0.7415311855993944398639 , -0.9491079123427585245262 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[50] = IntegrationPointType( -0.7415311855993944398639 , -0.9491079123427585245262 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[51] = IntegrationPointType( -0.7415311855993944398639 , -0.9491079123427585245262 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[52] = IntegrationPointType( -0.7415311855993944398639 , -0.9491079123427585245262 , 0 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[53] = IntegrationPointType( -0.7415311855993944398639 , -0.9491079123427585245262 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[54] = IntegrationPointType( -0.7415311855993944398639 , -0.9491079123427585245262 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[55] = IntegrationPointType( -0.7415311855993944398639 , -0.9491079123427585245262 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[56] = IntegrationPointType( -0.7415311855993944398639 , -0.7415311855993944398639 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[57] = IntegrationPointType( -0.7415311855993944398639 , -0.7415311855993944398639 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[58] = IntegrationPointType( -0.7415311855993944398639 , -0.7415311855993944398639 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[59] = IntegrationPointType( -0.7415311855993944398639 , -0.7415311855993944398639 , 0 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[60] = IntegrationPointType( -0.7415311855993944398639 , -0.7415311855993944398639 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[61] = IntegrationPointType( -0.7415311855993944398639 , -0.7415311855993944398639 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[62] = IntegrationPointType( -0.7415311855993944398639 , -0.7415311855993944398639 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[63] = IntegrationPointType( -0.7415311855993944398639 , -0.4058451513773971669066 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[64] = IntegrationPointType( -0.7415311855993944398639 , -0.4058451513773971669066 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[65] = IntegrationPointType( -0.7415311855993944398639 , -0.4058451513773971669066 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[66] = IntegrationPointType( -0.7415311855993944398639 , -0.4058451513773971669066 , 0 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[67] = IntegrationPointType( -0.7415311855993944398639 , -0.4058451513773971669066 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[68] = IntegrationPointType( -0.7415311855993944398639 , -0.4058451513773971669066 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[69] = IntegrationPointType( -0.7415311855993944398639 , -0.4058451513773971669066 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[70] = IntegrationPointType( -0.7415311855993944398639 , 0 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.1294849661688696932706 );
        msIntegrationPoints[71] = IntegrationPointType( -0.7415311855993944398639 , 0 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[72] = IntegrationPointType( -0.7415311855993944398639 , 0 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[73] = IntegrationPointType( -0.7415311855993944398639 , 0 , 0 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.4179591836734693877551 );
        msIntegrationPoints[74] = IntegrationPointType( -0.7415311855993944398639 , 0 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[75] = IntegrationPointType( -0.7415311855993944398639 , 0 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[76] = IntegrationPointType( -0.7415311855993944398639 , 0 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.1294849661688696932706 );

        msIntegrationPoints[77] = IntegrationPointType( -0.7415311855993944398639 , 0.4058451513773971669066 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[78] = IntegrationPointType( -0.7415311855993944398639 , 0.4058451513773971669066 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[79] = IntegrationPointType( -0.7415311855993944398639 , 0.4058451513773971669066 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[80] = IntegrationPointType( -0.7415311855993944398639 , 0.4058451513773971669066 , 0 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[81] = IntegrationPointType( -0.7415311855993944398639 , 0.4058451513773971669066 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[82] = IntegrationPointType( -0.7415311855993944398639 , 0.4058451513773971669066 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[83] = IntegrationPointType( -0.7415311855993944398639 , 0.4058451513773971669066 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[84] = IntegrationPointType( -0.7415311855993944398639 , 0.7415311855993944398639 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[85] = IntegrationPointType( -0.7415311855993944398639 , 0.7415311855993944398639 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[86] = IntegrationPointType( -0.7415311855993944398639 , 0.7415311855993944398639 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[87] = IntegrationPointType( -0.7415311855993944398639 , 0.7415311855993944398639 , 0 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[88] = IntegrationPointType( -0.7415311855993944398639 , 0.7415311855993944398639 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[89] = IntegrationPointType( -0.7415311855993944398639 , 0.7415311855993944398639 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[90] = IntegrationPointType( -0.7415311855993944398639 , 0.7415311855993944398639 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[91] = IntegrationPointType( -0.7415311855993944398639 , 0.9491079123427585245262 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[92] = IntegrationPointType( -0.7415311855993944398639 , 0.9491079123427585245262 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[93] = IntegrationPointType( -0.7415311855993944398639 , 0.9491079123427585245262 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[94] = IntegrationPointType( -0.7415311855993944398639 , 0.9491079123427585245262 , 0 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[95] = IntegrationPointType( -0.7415311855993944398639 , 0.9491079123427585245262 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[96] = IntegrationPointType( -0.7415311855993944398639 , 0.9491079123427585245262 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[97] = IntegrationPointType( -0.7415311855993944398639 , 0.9491079123427585245262 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[98] = IntegrationPointType( -0.4058451513773971669066 , -0.9491079123427585245262 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[99] = IntegrationPointType( -0.4058451513773971669066 , -0.9491079123427585245262 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[100] = IntegrationPointType( -0.4058451513773971669066 , -0.9491079123427585245262 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[101] = IntegrationPointType( -0.4058451513773971669066 , -0.9491079123427585245262 , 0 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[102] = IntegrationPointType( -0.4058451513773971669066 , -0.9491079123427585245262 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[103] = IntegrationPointType( -0.4058451513773971669066 , -0.9491079123427585245262 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[104] = IntegrationPointType( -0.4058451513773971669066 , -0.9491079123427585245262 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[105] = IntegrationPointType( -0.4058451513773971669066 , -0.7415311855993944398639 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[106] = IntegrationPointType( -0.4058451513773971669066 , -0.7415311855993944398639 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[107] = IntegrationPointType( -0.4058451513773971669066 , -0.7415311855993944398639 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[108] = IntegrationPointType( -0.4058451513773971669066 , -0.7415311855993944398639 , 0 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[109] = IntegrationPointType( -0.4058451513773971669066 , -0.7415311855993944398639 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[110] = IntegrationPointType( -0.4058451513773971669066 , -0.7415311855993944398639 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[111] = IntegrationPointType( -0.4058451513773971669066 , -0.7415311855993944398639 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[112] = IntegrationPointType( -0.4058451513773971669066 , -0.4058451513773971669066 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[113] = IntegrationPointType( -0.4058451513773971669066 , -0.4058451513773971669066 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[114] = IntegrationPointType( -0.4058451513773971669066 , -0.4058451513773971669066 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[115] = IntegrationPointType( -0.4058451513773971669066 , -0.4058451513773971669066 , 0 , 0.38183005050511894495 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[116] = IntegrationPointType( -0.4058451513773971669066 , -0.4058451513773971669066 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[117] = IntegrationPointType( -0.4058451513773971669066 , -0.4058451513773971669066 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[118] = IntegrationPointType( -0.4058451513773971669066 , -0.4058451513773971669066 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[119] = IntegrationPointType( -0.4058451513773971669066 , 0 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.1294849661688696932706 );
        msIntegrationPoints[120] = IntegrationPointType( -0.4058451513773971669066 , 0 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[121] = IntegrationPointType( -0.4058451513773971669066 , 0 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[122] = IntegrationPointType( -0.4058451513773971669066 , 0 , 0 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.4179591836734693877551 );
        msIntegrationPoints[123] = IntegrationPointType( -0.4058451513773971669066 , 0 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[124] = IntegrationPointType( -0.4058451513773971669066 , 0 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[125] = IntegrationPointType( -0.4058451513773971669066 , 0 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.1294849661688696932706 );

        msIntegrationPoints[126] = IntegrationPointType( -0.4058451513773971669066 , 0.4058451513773971669066 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[127] = IntegrationPointType( -0.4058451513773971669066 , 0.4058451513773971669066 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[128] = IntegrationPointType( -0.4058451513773971669066 , 0.4058451513773971669066 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[129] = IntegrationPointType( -0.4058451513773971669066 , 0.4058451513773971669066 , 0 , 0.38183005050511894495 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[130] = IntegrationPointType( -0.4058451513773971669066 , 0.4058451513773971669066 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[131] = IntegrationPointType( -0.4058451513773971669066 , 0.4058451513773971669066 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[132] = IntegrationPointType( -0.4058451513773971669066 , 0.4058451513773971669066 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[133] = IntegrationPointType( -0.4058451513773971669066 , 0.7415311855993944398639 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[134] = IntegrationPointType( -0.4058451513773971669066 , 0.7415311855993944398639 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[135] = IntegrationPointType( -0.4058451513773971669066 , 0.7415311855993944398639 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[136] = IntegrationPointType( -0.4058451513773971669066 , 0.7415311855993944398639 , 0 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[137] = IntegrationPointType( -0.4058451513773971669066 , 0.7415311855993944398639 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[138] = IntegrationPointType( -0.4058451513773971669066 , 0.7415311855993944398639 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[139] = IntegrationPointType( -0.4058451513773971669066 , 0.7415311855993944398639 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[140] = IntegrationPointType( -0.4058451513773971669066 , 0.9491079123427585245262 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[141] = IntegrationPointType( -0.4058451513773971669066 , 0.9491079123427585245262 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[142] = IntegrationPointType( -0.4058451513773971669066 , 0.9491079123427585245262 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[143] = IntegrationPointType( -0.4058451513773971669066 , 0.9491079123427585245262 , 0 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[144] = IntegrationPointType( -0.4058451513773971669066 , 0.9491079123427585245262 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[145] = IntegrationPointType( -0.4058451513773971669066 , 0.9491079123427585245262 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[146] = IntegrationPointType( -0.4058451513773971669066 , 0.9491079123427585245262 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[147] = IntegrationPointType( 0 , -0.9491079123427585245262 , -0.9491079123427585245262 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[148] = IntegrationPointType( 0 , -0.9491079123427585245262 , -0.7415311855993944398639 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[149] = IntegrationPointType( 0 , -0.9491079123427585245262 , -0.4058451513773971669066 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[150] = IntegrationPointType( 0 , -0.9491079123427585245262 , 0 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[151] = IntegrationPointType( 0 , -0.9491079123427585245262 , 0.4058451513773971669066 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[152] = IntegrationPointType( 0 , -0.9491079123427585245262 , 0.7415311855993944398639 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[153] = IntegrationPointType( 0 , -0.9491079123427585245262 , 0.9491079123427585245262 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[154] = IntegrationPointType( 0 , -0.7415311855993944398639 , -0.9491079123427585245262 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[155] = IntegrationPointType( 0 , -0.7415311855993944398639 , -0.7415311855993944398639 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[156] = IntegrationPointType( 0 , -0.7415311855993944398639 , -0.4058451513773971669066 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[157] = IntegrationPointType( 0 , -0.7415311855993944398639 , 0 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[158] = IntegrationPointType( 0 , -0.7415311855993944398639 , 0.4058451513773971669066 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[159] = IntegrationPointType( 0 , -0.7415311855993944398639 , 0.7415311855993944398639 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[160] = IntegrationPointType( 0 , -0.7415311855993944398639 , 0.9491079123427585245262 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[161] = IntegrationPointType( 0 , -0.4058451513773971669066 , -0.9491079123427585245262 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[162] = IntegrationPointType( 0 , -0.4058451513773971669066 , -0.7415311855993944398639 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[163] = IntegrationPointType( 0 , -0.4058451513773971669066 , -0.4058451513773971669066 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[164] = IntegrationPointType( 0 , -0.4058451513773971669066 , 0 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[165] = IntegrationPointType( 0 , -0.4058451513773971669066 , 0.4058451513773971669066 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[166] = IntegrationPointType( 0 , -0.4058451513773971669066 , 0.7415311855993944398639 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[167] = IntegrationPointType( 0 , -0.4058451513773971669066 , 0.9491079123427585245262 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[168] = IntegrationPointType( 0 , 0 , -0.9491079123427585245262 , 0.4179591836734693877551 * 0.4179591836734693877551 * 0.1294849661688696932706 );
        msIntegrationPoints[169] = IntegrationPointType( 0 , 0 , -0.7415311855993944398639 , 0.4179591836734693877551 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[170] = IntegrationPointType( 0 , 0 , -0.4058451513773971669066 , 0.4179591836734693877551 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[171] = IntegrationPointType( 0 , 0 , 0 , 0.4179591836734693877551 * 0.4179591836734693877551 * 0.4179591836734693877551 );
        msIntegrationPoints[172] = IntegrationPointType( 0 , 0 , 0.4058451513773971669066 , 0.4179591836734693877551 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[173] = IntegrationPointType( 0 , 0 , 0.7415311855993944398639 , 0.4179591836734693877551 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[174] = IntegrationPointType( 0 , 0 , 0.9491079123427585245262 , 0.4179591836734693877551 * 0.4179591836734693877551 * 0.1294849661688696932706 );

        msIntegrationPoints[175] = IntegrationPointType( 0 , 0.4058451513773971669066 , -0.9491079123427585245262 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[176] = IntegrationPointType( 0 , 0.4058451513773971669066 , -0.7415311855993944398639 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[177] = IntegrationPointType( 0 , 0.4058451513773971669066 , -0.4058451513773971669066 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[178] = IntegrationPointType( 0 , 0.4058451513773971669066 , 0 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[179] = IntegrationPointType( 0 , 0.4058451513773971669066 , 0.4058451513773971669066 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[180] = IntegrationPointType( 0 , 0.4058451513773971669066 , 0.7415311855993944398639 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[181] = IntegrationPointType( 0 , 0.4058451513773971669066 , 0.9491079123427585245262 , 0.4179591836734693877551 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[182] = IntegrationPointType( 0 , 0.7415311855993944398639 , -0.9491079123427585245262 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[183] = IntegrationPointType( 0 , 0.7415311855993944398639 , -0.7415311855993944398639 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[184] = IntegrationPointType( 0 , 0.7415311855993944398639 , -0.4058451513773971669066 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[185] = IntegrationPointType( 0 , 0.7415311855993944398639 , 0 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[186] = IntegrationPointType( 0 , 0.7415311855993944398639 , 0.4058451513773971669066 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[187] = IntegrationPointType( 0 , 0.7415311855993944398639 , 0.7415311855993944398639 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[188] = IntegrationPointType( 0 , 0.7415311855993944398639 , 0.9491079123427585245262 , 0.4179591836734693877551 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[189] = IntegrationPointType( 0 , 0.9491079123427585245262 , -0.9491079123427585245262 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[190] = IntegrationPointType( 0 , 0.9491079123427585245262 , -0.7415311855993944398639 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[191] = IntegrationPointType( 0 , 0.9491079123427585245262 , -0.4058451513773971669066 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[192] = IntegrationPointType( 0 , 0.9491079123427585245262 , 0 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[193] = IntegrationPointType( 0 , 0.9491079123427585245262 , 0.4058451513773971669066 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[194] = IntegrationPointType( 0 , 0.9491079123427585245262 , 0.7415311855993944398639 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[195] = IntegrationPointType( 0 , 0.9491079123427585245262 , 0.9491079123427585245262 , 0.4179591836734693877551 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[196] = IntegrationPointType( 0.4058451513773971669066 , -0.9491079123427585245262 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[197] = IntegrationPointType( 0.4058451513773971669066 , -0.9491079123427585245262 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[198] = IntegrationPointType( 0.4058451513773971669066 , -0.9491079123427585245262 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[199] = IntegrationPointType( 0.4058451513773971669066 , -0.9491079123427585245262 , 0 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[200] = IntegrationPointType( 0.4058451513773971669066 , -0.9491079123427585245262 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[201] = IntegrationPointType( 0.4058451513773971669066 , -0.9491079123427585245262 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[202] = IntegrationPointType( 0.4058451513773971669066 , -0.9491079123427585245262 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[203] = IntegrationPointType( 0.4058451513773971669066 , -0.7415311855993944398639 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[204] = IntegrationPointType( 0.4058451513773971669066 , -0.7415311855993944398639 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[205] = IntegrationPointType( 0.4058451513773971669066 , -0.7415311855993944398639 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[206] = IntegrationPointType( 0.4058451513773971669066 , -0.7415311855993944398639 , 0 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[207] = IntegrationPointType( 0.4058451513773971669066 , -0.7415311855993944398639 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[208] = IntegrationPointType( 0.4058451513773971669066 , -0.7415311855993944398639 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[209] = IntegrationPointType( 0.4058451513773971669066 , -0.7415311855993944398639 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[210] = IntegrationPointType( 0.4058451513773971669066 , -0.4058451513773971669066 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[211] = IntegrationPointType( 0.4058451513773971669066 , -0.4058451513773971669066 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[212] = IntegrationPointType( 0.4058451513773971669066 , -0.4058451513773971669066 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[213] = IntegrationPointType( 0.4058451513773971669066 , -0.4058451513773971669066 , 0 , 0.38183005050511894495 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[214] = IntegrationPointType( 0.4058451513773971669066 , -0.4058451513773971669066 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[215] = IntegrationPointType( 0.4058451513773971669066 , -0.4058451513773971669066 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[216] = IntegrationPointType( 0.4058451513773971669066 , -0.4058451513773971669066 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[217] = IntegrationPointType( 0.4058451513773971669066 , 0 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.1294849661688696932706 );
        msIntegrationPoints[218] = IntegrationPointType( 0.4058451513773971669066 , 0 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[219] = IntegrationPointType( 0.4058451513773971669066 , 0 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[220] = IntegrationPointType( 0.4058451513773971669066 , 0 , 0 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.4179591836734693877551 );
        msIntegrationPoints[221] = IntegrationPointType( 0.4058451513773971669066 , 0 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[222] = IntegrationPointType( 0.4058451513773971669066 , 0 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[223] = IntegrationPointType( 0.4058451513773971669066 , 0 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.4179591836734693877551 * 0.1294849661688696932706 );

        msIntegrationPoints[224] = IntegrationPointType( 0.4058451513773971669066 , 0.4058451513773971669066 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[225] = IntegrationPointType( 0.4058451513773971669066 , 0.4058451513773971669066 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[226] = IntegrationPointType( 0.4058451513773971669066 , 0.4058451513773971669066 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[227] = IntegrationPointType( 0.4058451513773971669066 , 0.4058451513773971669066 , 0 , 0.38183005050511894495 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[228] = IntegrationPointType( 0.4058451513773971669066 , 0.4058451513773971669066 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[229] = IntegrationPointType( 0.4058451513773971669066 , 0.4058451513773971669066 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[230] = IntegrationPointType( 0.4058451513773971669066 , 0.4058451513773971669066 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[231] = IntegrationPointType( 0.4058451513773971669066 , 0.7415311855993944398639 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[232] = IntegrationPointType( 0.4058451513773971669066 , 0.7415311855993944398639 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[233] = IntegrationPointType( 0.4058451513773971669066 , 0.7415311855993944398639 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[234] = IntegrationPointType( 0.4058451513773971669066 , 0.7415311855993944398639 , 0 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[235] = IntegrationPointType( 0.4058451513773971669066 , 0.7415311855993944398639 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[236] = IntegrationPointType( 0.4058451513773971669066 , 0.7415311855993944398639 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[237] = IntegrationPointType( 0.4058451513773971669066 , 0.7415311855993944398639 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[238] = IntegrationPointType( 0.4058451513773971669066 , 0.9491079123427585245262 , -0.9491079123427585245262 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[239] = IntegrationPointType( 0.4058451513773971669066 , 0.9491079123427585245262 , -0.7415311855993944398639 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[240] = IntegrationPointType( 0.4058451513773971669066 , 0.9491079123427585245262 , -0.4058451513773971669066 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[241] = IntegrationPointType( 0.4058451513773971669066 , 0.9491079123427585245262 , 0 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[242] = IntegrationPointType( 0.4058451513773971669066 , 0.9491079123427585245262 , 0.4058451513773971669066 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[243] = IntegrationPointType( 0.4058451513773971669066 , 0.9491079123427585245262 , 0.7415311855993944398639 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[244] = IntegrationPointType( 0.4058451513773971669066 , 0.9491079123427585245262 , 0.9491079123427585245262 , 0.38183005050511894495 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[245] = IntegrationPointType( 0.7415311855993944398639 , -0.9491079123427585245262 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[246] = IntegrationPointType( 0.7415311855993944398639 , -0.9491079123427585245262 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[247] = IntegrationPointType( 0.7415311855993944398639 , -0.9491079123427585245262 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[248] = IntegrationPointType( 0.7415311855993944398639 , -0.9491079123427585245262 , 0 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[249] = IntegrationPointType( 0.7415311855993944398639 , -0.9491079123427585245262 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[250] = IntegrationPointType( 0.7415311855993944398639 , -0.9491079123427585245262 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[251] = IntegrationPointType( 0.7415311855993944398639 , -0.9491079123427585245262 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[252] = IntegrationPointType( 0.7415311855993944398639 , -0.7415311855993944398639 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[253] = IntegrationPointType( 0.7415311855993944398639 , -0.7415311855993944398639 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[254] = IntegrationPointType( 0.7415311855993944398639 , -0.7415311855993944398639 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[255] = IntegrationPointType( 0.7415311855993944398639 , -0.7415311855993944398639 , 0 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[256] = IntegrationPointType( 0.7415311855993944398639 , -0.7415311855993944398639 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[257] = IntegrationPointType( 0.7415311855993944398639 , -0.7415311855993944398639 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[258] = IntegrationPointType( 0.7415311855993944398639 , -0.7415311855993944398639 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[259] = IntegrationPointType( 0.7415311855993944398639 , -0.4058451513773971669066 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[260] = IntegrationPointType( 0.7415311855993944398639 , -0.4058451513773971669066 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[261] = IntegrationPointType( 0.7415311855993944398639 , -0.4058451513773971669066 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[262] = IntegrationPointType( 0.7415311855993944398639 , -0.4058451513773971669066 , 0 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[263] = IntegrationPointType( 0.7415311855993944398639 , -0.4058451513773971669066 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[264] = IntegrationPointType( 0.7415311855993944398639 , -0.4058451513773971669066 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[265] = IntegrationPointType( 0.7415311855993944398639 , -0.4058451513773971669066 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[266] = IntegrationPointType( 0.7415311855993944398639 , 0 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.1294849661688696932706 );
        msIntegrationPoints[267] = IntegrationPointType( 0.7415311855993944398639 , 0 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[268] = IntegrationPointType( 0.7415311855993944398639 , 0 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[269] = IntegrationPointType( 0.7415311855993944398639 , 0 , 0 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.4179591836734693877551 );
        msIntegrationPoints[270] = IntegrationPointType( 0.7415311855993944398639 , 0 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[271] = IntegrationPointType( 0.7415311855993944398639 , 0 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[272] = IntegrationPointType( 0.7415311855993944398639 , 0 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.4179591836734693877551 * 0.1294849661688696932706 );

        msIntegrationPoints[273] = IntegrationPointType( 0.7415311855993944398639 , 0.4058451513773971669066 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[274] = IntegrationPointType( 0.7415311855993944398639 , 0.4058451513773971669066 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[275] = IntegrationPointType( 0.7415311855993944398639 , 0.4058451513773971669066 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[276] = IntegrationPointType( 0.7415311855993944398639 , 0.4058451513773971669066 , 0 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[277] = IntegrationPointType( 0.7415311855993944398639 , 0.4058451513773971669066 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[278] = IntegrationPointType( 0.7415311855993944398639 , 0.4058451513773971669066 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[279] = IntegrationPointType( 0.7415311855993944398639 , 0.4058451513773971669066 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[280] = IntegrationPointType( 0.7415311855993944398639 , 0.7415311855993944398639 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[281] = IntegrationPointType( 0.7415311855993944398639 , 0.7415311855993944398639 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[282] = IntegrationPointType( 0.7415311855993944398639 , 0.7415311855993944398639 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[283] = IntegrationPointType( 0.7415311855993944398639 , 0.7415311855993944398639 , 0 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[284] = IntegrationPointType( 0.7415311855993944398639 , 0.7415311855993944398639 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[285] = IntegrationPointType( 0.7415311855993944398639 , 0.7415311855993944398639 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[286] = IntegrationPointType( 0.7415311855993944398639 , 0.7415311855993944398639 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[287] = IntegrationPointType( 0.7415311855993944398639 , 0.9491079123427585245262 , -0.9491079123427585245262 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[288] = IntegrationPointType( 0.7415311855993944398639 , 0.9491079123427585245262 , -0.7415311855993944398639 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[289] = IntegrationPointType( 0.7415311855993944398639 , 0.9491079123427585245262 , -0.4058451513773971669066 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[290] = IntegrationPointType( 0.7415311855993944398639 , 0.9491079123427585245262 , 0 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[291] = IntegrationPointType( 0.7415311855993944398639 , 0.9491079123427585245262 , 0.4058451513773971669066 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[292] = IntegrationPointType( 0.7415311855993944398639 , 0.9491079123427585245262 , 0.7415311855993944398639 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[293] = IntegrationPointType( 0.7415311855993944398639 , 0.9491079123427585245262 , 0.9491079123427585245262 , 0.2797053914892766679015 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[294] = IntegrationPointType( 0.9491079123427585245262 , -0.9491079123427585245262 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[295] = IntegrationPointType( 0.9491079123427585245262 , -0.9491079123427585245262 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[296] = IntegrationPointType( 0.9491079123427585245262 , -0.9491079123427585245262 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[297] = IntegrationPointType( 0.9491079123427585245262 , -0.9491079123427585245262 , 0 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[298] = IntegrationPointType( 0.9491079123427585245262 , -0.9491079123427585245262 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[299] = IntegrationPointType( 0.9491079123427585245262 , -0.9491079123427585245262 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[300] = IntegrationPointType( 0.9491079123427585245262 , -0.9491079123427585245262 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        msIntegrationPoints[301] = IntegrationPointType( 0.9491079123427585245262 , -0.7415311855993944398639 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[302] = IntegrationPointType( 0.9491079123427585245262 , -0.7415311855993944398639 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[303] = IntegrationPointType( 0.9491079123427585245262 , -0.7415311855993944398639 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[304] = IntegrationPointType( 0.9491079123427585245262 , -0.7415311855993944398639 , 0 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[305] = IntegrationPointType( 0.9491079123427585245262 , -0.7415311855993944398639 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[306] = IntegrationPointType( 0.9491079123427585245262 , -0.7415311855993944398639 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[307] = IntegrationPointType( 0.9491079123427585245262 , -0.7415311855993944398639 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[308] = IntegrationPointType( 0.9491079123427585245262 , -0.4058451513773971669066 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[309] = IntegrationPointType( 0.9491079123427585245262 , -0.4058451513773971669066 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[310] = IntegrationPointType( 0.9491079123427585245262 , -0.4058451513773971669066 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[311] = IntegrationPointType( 0.9491079123427585245262 , -0.4058451513773971669066 , 0 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[312] = IntegrationPointType( 0.9491079123427585245262 , -0.4058451513773971669066 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[313] = IntegrationPointType( 0.9491079123427585245262 , -0.4058451513773971669066 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[314] = IntegrationPointType( 0.9491079123427585245262 , -0.4058451513773971669066 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[315] = IntegrationPointType( 0.9491079123427585245262 , 0 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.1294849661688696932706 );
        msIntegrationPoints[316] = IntegrationPointType( 0.9491079123427585245262 , 0 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[317] = IntegrationPointType( 0.9491079123427585245262 , 0 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[318] = IntegrationPointType( 0.9491079123427585245262 , 0 , 0 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.4179591836734693877551 );
        msIntegrationPoints[319] = IntegrationPointType( 0.9491079123427585245262 , 0 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.38183005050511894495 );
        msIntegrationPoints[320] = IntegrationPointType( 0.9491079123427585245262 , 0 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.2797053914892766679015 );
        msIntegrationPoints[321] = IntegrationPointType( 0.9491079123427585245262 , 0 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.4179591836734693877551 * 0.1294849661688696932706 );

        msIntegrationPoints[322] = IntegrationPointType( 0.9491079123427585245262 , 0.4058451513773971669066 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.1294849661688696932706 );
        msIntegrationPoints[323] = IntegrationPointType( 0.9491079123427585245262 , 0.4058451513773971669066 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[324] = IntegrationPointType( 0.9491079123427585245262 , 0.4058451513773971669066 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[325] = IntegrationPointType( 0.9491079123427585245262 , 0.4058451513773971669066 , 0 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.4179591836734693877551 );
        msIntegrationPoints[326] = IntegrationPointType( 0.9491079123427585245262 , 0.4058451513773971669066 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.38183005050511894495 );
        msIntegrationPoints[327] = IntegrationPointType( 0.9491079123427585245262 , 0.4058451513773971669066 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.2797053914892766679015 );
        msIntegrationPoints[328] = IntegrationPointType( 0.9491079123427585245262 , 0.4058451513773971669066 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.38183005050511894495 * 0.1294849661688696932706 );

        msIntegrationPoints[329] = IntegrationPointType( 0.9491079123427585245262 , 0.7415311855993944398639 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.1294849661688696932706 );
        msIntegrationPoints[330] = IntegrationPointType( 0.9491079123427585245262 , 0.7415311855993944398639 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[331] = IntegrationPointType( 0.9491079123427585245262 , 0.7415311855993944398639 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[332] = IntegrationPointType( 0.9491079123427585245262 , 0.7415311855993944398639 , 0 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.4179591836734693877551 );
        msIntegrationPoints[333] = IntegrationPointType( 0.9491079123427585245262 , 0.7415311855993944398639 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.38183005050511894495 );
        msIntegrationPoints[334] = IntegrationPointType( 0.9491079123427585245262 , 0.7415311855993944398639 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.2797053914892766679015 );
        msIntegrationPoints[335] = IntegrationPointType( 0.9491079123427585245262 , 0.7415311855993944398639 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.2797053914892766679015 * 0.1294849661688696932706 );

        msIntegrationPoints[336] = IntegrationPointType( 0.9491079123427585245262 , 0.9491079123427585245262 , -0.9491079123427585245262 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.1294849661688696932706 );
        msIntegrationPoints[337] = IntegrationPointType( 0.9491079123427585245262 , 0.9491079123427585245262 , -0.7415311855993944398639 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[338] = IntegrationPointType( 0.9491079123427585245262 , 0.9491079123427585245262 , -0.4058451513773971669066 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[339] = IntegrationPointType( 0.9491079123427585245262 , 0.9491079123427585245262 , 0 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.4179591836734693877551 );
        msIntegrationPoints[340] = IntegrationPointType( 0.9491079123427585245262 , 0.9491079123427585245262 , 0.4058451513773971669066 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.38183005050511894495 );
        msIntegrationPoints[341] = IntegrationPointType( 0.9491079123427585245262 , 0.9491079123427585245262 , 0.7415311855993944398639 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.2797053914892766679015 );
        msIntegrationPoints[342] = IntegrationPointType( 0.9491079123427585245262 , 0.9491079123427585245262 , 0.9491079123427585245262 , 0.1294849661688696932706 * 0.1294849661688696932706 * 0.1294849661688696932706 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Legendre quadrature 7";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLegendreIntegrationPoints7

class KRATOS_API(KRATOS_CORE) HexahedronGaussLegendreIntegrationPoints8
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(HexahedronGaussLegendreIntegrationPoints8);
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
        msIntegrationPoints[0] = IntegrationPointType( -0.9602898564975362316836 , -0.9602898564975362316836 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[1] = IntegrationPointType( -0.9602898564975362316836 , -0.9602898564975362316836 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[2] = IntegrationPointType( -0.9602898564975362316836 , -0.9602898564975362316836 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[3] = IntegrationPointType( -0.9602898564975362316836 , -0.9602898564975362316836 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[4] = IntegrationPointType( -0.9602898564975362316836 , -0.9602898564975362316836 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[5] = IntegrationPointType( -0.9602898564975362316836 , -0.9602898564975362316836 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[6] = IntegrationPointType( -0.9602898564975362316836 , -0.9602898564975362316836 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[7] = IntegrationPointType( -0.9602898564975362316836 , -0.9602898564975362316836 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[8] = IntegrationPointType( -0.9602898564975362316836 , -0.7966664774136267395916 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[9] = IntegrationPointType( -0.9602898564975362316836 , -0.7966664774136267395916 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[10] = IntegrationPointType( -0.9602898564975362316836 , -0.7966664774136267395916 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[11] = IntegrationPointType( -0.9602898564975362316836 , -0.7966664774136267395916 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[12] = IntegrationPointType( -0.9602898564975362316836 , -0.7966664774136267395916 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[13] = IntegrationPointType( -0.9602898564975362316836 , -0.7966664774136267395916 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[14] = IntegrationPointType( -0.9602898564975362316836 , -0.7966664774136267395916 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[15] = IntegrationPointType( -0.9602898564975362316836 , -0.7966664774136267395916 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[16] = IntegrationPointType( -0.9602898564975362316836 , -0.5255324099163289858177 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[17] = IntegrationPointType( -0.9602898564975362316836 , -0.5255324099163289858177 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[18] = IntegrationPointType( -0.9602898564975362316836 , -0.5255324099163289858177 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[19] = IntegrationPointType( -0.9602898564975362316836 , -0.5255324099163289858177 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[20] = IntegrationPointType( -0.9602898564975362316836 , -0.5255324099163289858177 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[21] = IntegrationPointType( -0.9602898564975362316836 , -0.5255324099163289858177 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[22] = IntegrationPointType( -0.9602898564975362316836 , -0.5255324099163289858177 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[23] = IntegrationPointType( -0.9602898564975362316836 , -0.5255324099163289858177 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[24] = IntegrationPointType( -0.9602898564975362316836 , -0.1834346424956498049395 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[25] = IntegrationPointType( -0.9602898564975362316836 , -0.1834346424956498049395 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[26] = IntegrationPointType( -0.9602898564975362316836 , -0.1834346424956498049395 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[27] = IntegrationPointType( -0.9602898564975362316836 , -0.1834346424956498049395 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[28] = IntegrationPointType( -0.9602898564975362316836 , -0.1834346424956498049395 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[29] = IntegrationPointType( -0.9602898564975362316836 , -0.1834346424956498049395 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[30] = IntegrationPointType( -0.9602898564975362316836 , -0.1834346424956498049395 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[31] = IntegrationPointType( -0.9602898564975362316836 , -0.1834346424956498049395 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[32] = IntegrationPointType( -0.9602898564975362316836 , 0.1834346424956498049395 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[33] = IntegrationPointType( -0.9602898564975362316836 , 0.1834346424956498049395 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[34] = IntegrationPointType( -0.9602898564975362316836 , 0.1834346424956498049395 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[35] = IntegrationPointType( -0.9602898564975362316836 , 0.1834346424956498049395 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[36] = IntegrationPointType( -0.9602898564975362316836 , 0.1834346424956498049395 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[37] = IntegrationPointType( -0.9602898564975362316836 , 0.1834346424956498049395 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[38] = IntegrationPointType( -0.9602898564975362316836 , 0.1834346424956498049395 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[39] = IntegrationPointType( -0.9602898564975362316836 , 0.1834346424956498049395 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[40] = IntegrationPointType( -0.9602898564975362316836 , 0.5255324099163289858177 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[41] = IntegrationPointType( -0.9602898564975362316836 , 0.5255324099163289858177 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[42] = IntegrationPointType( -0.9602898564975362316836 , 0.5255324099163289858177 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[43] = IntegrationPointType( -0.9602898564975362316836 , 0.5255324099163289858177 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[44] = IntegrationPointType( -0.9602898564975362316836 , 0.5255324099163289858177 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[45] = IntegrationPointType( -0.9602898564975362316836 , 0.5255324099163289858177 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[46] = IntegrationPointType( -0.9602898564975362316836 , 0.5255324099163289858177 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[47] = IntegrationPointType( -0.9602898564975362316836 , 0.5255324099163289858177 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[48] = IntegrationPointType( -0.9602898564975362316836 , 0.7966664774136267395916 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[49] = IntegrationPointType( -0.9602898564975362316836 , 0.7966664774136267395916 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[50] = IntegrationPointType( -0.9602898564975362316836 , 0.7966664774136267395916 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[51] = IntegrationPointType( -0.9602898564975362316836 , 0.7966664774136267395916 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[52] = IntegrationPointType( -0.9602898564975362316836 , 0.7966664774136267395916 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[53] = IntegrationPointType( -0.9602898564975362316836 , 0.7966664774136267395916 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[54] = IntegrationPointType( -0.9602898564975362316836 , 0.7966664774136267395916 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[55] = IntegrationPointType( -0.9602898564975362316836 , 0.7966664774136267395916 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[56] = IntegrationPointType( -0.9602898564975362316836 , 0.9602898564975362316836 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[57] = IntegrationPointType( -0.9602898564975362316836 , 0.9602898564975362316836 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[58] = IntegrationPointType( -0.9602898564975362316836 , 0.9602898564975362316836 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[59] = IntegrationPointType( -0.9602898564975362316836 , 0.9602898564975362316836 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[60] = IntegrationPointType( -0.9602898564975362316836 , 0.9602898564975362316836 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[61] = IntegrationPointType( -0.9602898564975362316836 , 0.9602898564975362316836 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[62] = IntegrationPointType( -0.9602898564975362316836 , 0.9602898564975362316836 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[63] = IntegrationPointType( -0.9602898564975362316836 , 0.9602898564975362316836 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[64] = IntegrationPointType( -0.7966664774136267395916 , -0.9602898564975362316836 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[65] = IntegrationPointType( -0.7966664774136267395916 , -0.9602898564975362316836 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[66] = IntegrationPointType( -0.7966664774136267395916 , -0.9602898564975362316836 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[67] = IntegrationPointType( -0.7966664774136267395916 , -0.9602898564975362316836 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[68] = IntegrationPointType( -0.7966664774136267395916 , -0.9602898564975362316836 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[69] = IntegrationPointType( -0.7966664774136267395916 , -0.9602898564975362316836 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[70] = IntegrationPointType( -0.7966664774136267395916 , -0.9602898564975362316836 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[71] = IntegrationPointType( -0.7966664774136267395916 , -0.9602898564975362316836 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[72] = IntegrationPointType( -0.7966664774136267395916 , -0.7966664774136267395916 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[73] = IntegrationPointType( -0.7966664774136267395916 , -0.7966664774136267395916 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[74] = IntegrationPointType( -0.7966664774136267395916 , -0.7966664774136267395916 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[75] = IntegrationPointType( -0.7966664774136267395916 , -0.7966664774136267395916 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[76] = IntegrationPointType( -0.7966664774136267395916 , -0.7966664774136267395916 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[77] = IntegrationPointType( -0.7966664774136267395916 , -0.7966664774136267395916 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[78] = IntegrationPointType( -0.7966664774136267395916 , -0.7966664774136267395916 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[79] = IntegrationPointType( -0.7966664774136267395916 , -0.7966664774136267395916 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[80] = IntegrationPointType( -0.7966664774136267395916 , -0.5255324099163289858177 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[81] = IntegrationPointType( -0.7966664774136267395916 , -0.5255324099163289858177 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[82] = IntegrationPointType( -0.7966664774136267395916 , -0.5255324099163289858177 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[83] = IntegrationPointType( -0.7966664774136267395916 , -0.5255324099163289858177 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[84] = IntegrationPointType( -0.7966664774136267395916 , -0.5255324099163289858177 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[85] = IntegrationPointType( -0.7966664774136267395916 , -0.5255324099163289858177 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[86] = IntegrationPointType( -0.7966664774136267395916 , -0.5255324099163289858177 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[87] = IntegrationPointType( -0.7966664774136267395916 , -0.5255324099163289858177 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[88] = IntegrationPointType( -0.7966664774136267395916 , -0.1834346424956498049395 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[89] = IntegrationPointType( -0.7966664774136267395916 , -0.1834346424956498049395 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[90] = IntegrationPointType( -0.7966664774136267395916 , -0.1834346424956498049395 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[91] = IntegrationPointType( -0.7966664774136267395916 , -0.1834346424956498049395 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[92] = IntegrationPointType( -0.7966664774136267395916 , -0.1834346424956498049395 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[93] = IntegrationPointType( -0.7966664774136267395916 , -0.1834346424956498049395 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[94] = IntegrationPointType( -0.7966664774136267395916 , -0.1834346424956498049395 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[95] = IntegrationPointType( -0.7966664774136267395916 , -0.1834346424956498049395 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[96] = IntegrationPointType( -0.7966664774136267395916 , 0.1834346424956498049395 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[97] = IntegrationPointType( -0.7966664774136267395916 , 0.1834346424956498049395 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[98] = IntegrationPointType( -0.7966664774136267395916 , 0.1834346424956498049395 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[99] = IntegrationPointType( -0.7966664774136267395916 , 0.1834346424956498049395 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[100] = IntegrationPointType( -0.7966664774136267395916 , 0.1834346424956498049395 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[101] = IntegrationPointType( -0.7966664774136267395916 , 0.1834346424956498049395 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[102] = IntegrationPointType( -0.7966664774136267395916 , 0.1834346424956498049395 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[103] = IntegrationPointType( -0.7966664774136267395916 , 0.1834346424956498049395 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[104] = IntegrationPointType( -0.7966664774136267395916 , 0.5255324099163289858177 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[105] = IntegrationPointType( -0.7966664774136267395916 , 0.5255324099163289858177 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[106] = IntegrationPointType( -0.7966664774136267395916 , 0.5255324099163289858177 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[107] = IntegrationPointType( -0.7966664774136267395916 , 0.5255324099163289858177 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[108] = IntegrationPointType( -0.7966664774136267395916 , 0.5255324099163289858177 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[109] = IntegrationPointType( -0.7966664774136267395916 , 0.5255324099163289858177 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[110] = IntegrationPointType( -0.7966664774136267395916 , 0.5255324099163289858177 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[111] = IntegrationPointType( -0.7966664774136267395916 , 0.5255324099163289858177 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[112] = IntegrationPointType( -0.7966664774136267395916 , 0.7966664774136267395916 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[113] = IntegrationPointType( -0.7966664774136267395916 , 0.7966664774136267395916 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[114] = IntegrationPointType( -0.7966664774136267395916 , 0.7966664774136267395916 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[115] = IntegrationPointType( -0.7966664774136267395916 , 0.7966664774136267395916 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[116] = IntegrationPointType( -0.7966664774136267395916 , 0.7966664774136267395916 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[117] = IntegrationPointType( -0.7966664774136267395916 , 0.7966664774136267395916 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[118] = IntegrationPointType( -0.7966664774136267395916 , 0.7966664774136267395916 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[119] = IntegrationPointType( -0.7966664774136267395916 , 0.7966664774136267395916 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[120] = IntegrationPointType( -0.7966664774136267395916 , 0.9602898564975362316836 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[121] = IntegrationPointType( -0.7966664774136267395916 , 0.9602898564975362316836 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[122] = IntegrationPointType( -0.7966664774136267395916 , 0.9602898564975362316836 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[123] = IntegrationPointType( -0.7966664774136267395916 , 0.9602898564975362316836 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[124] = IntegrationPointType( -0.7966664774136267395916 , 0.9602898564975362316836 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[125] = IntegrationPointType( -0.7966664774136267395916 , 0.9602898564975362316836 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[126] = IntegrationPointType( -0.7966664774136267395916 , 0.9602898564975362316836 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[127] = IntegrationPointType( -0.7966664774136267395916 , 0.9602898564975362316836 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[128] = IntegrationPointType( -0.5255324099163289858177 , -0.9602898564975362316836 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[129] = IntegrationPointType( -0.5255324099163289858177 , -0.9602898564975362316836 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[130] = IntegrationPointType( -0.5255324099163289858177 , -0.9602898564975362316836 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[131] = IntegrationPointType( -0.5255324099163289858177 , -0.9602898564975362316836 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[132] = IntegrationPointType( -0.5255324099163289858177 , -0.9602898564975362316836 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[133] = IntegrationPointType( -0.5255324099163289858177 , -0.9602898564975362316836 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[134] = IntegrationPointType( -0.5255324099163289858177 , -0.9602898564975362316836 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[135] = IntegrationPointType( -0.5255324099163289858177 , -0.9602898564975362316836 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[136] = IntegrationPointType( -0.5255324099163289858177 , -0.7966664774136267395916 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[137] = IntegrationPointType( -0.5255324099163289858177 , -0.7966664774136267395916 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[138] = IntegrationPointType( -0.5255324099163289858177 , -0.7966664774136267395916 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[139] = IntegrationPointType( -0.5255324099163289858177 , -0.7966664774136267395916 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[140] = IntegrationPointType( -0.5255324099163289858177 , -0.7966664774136267395916 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[141] = IntegrationPointType( -0.5255324099163289858177 , -0.7966664774136267395916 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[142] = IntegrationPointType( -0.5255324099163289858177 , -0.7966664774136267395916 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[143] = IntegrationPointType( -0.5255324099163289858177 , -0.7966664774136267395916 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[144] = IntegrationPointType( -0.5255324099163289858177 , -0.5255324099163289858177 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[145] = IntegrationPointType( -0.5255324099163289858177 , -0.5255324099163289858177 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[146] = IntegrationPointType( -0.5255324099163289858177 , -0.5255324099163289858177 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[147] = IntegrationPointType( -0.5255324099163289858177 , -0.5255324099163289858177 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[148] = IntegrationPointType( -0.5255324099163289858177 , -0.5255324099163289858177 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[149] = IntegrationPointType( -0.5255324099163289858177 , -0.5255324099163289858177 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[150] = IntegrationPointType( -0.5255324099163289858177 , -0.5255324099163289858177 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[151] = IntegrationPointType( -0.5255324099163289858177 , -0.5255324099163289858177 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[152] = IntegrationPointType( -0.5255324099163289858177 , -0.1834346424956498049395 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[153] = IntegrationPointType( -0.5255324099163289858177 , -0.1834346424956498049395 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[154] = IntegrationPointType( -0.5255324099163289858177 , -0.1834346424956498049395 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[155] = IntegrationPointType( -0.5255324099163289858177 , -0.1834346424956498049395 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[156] = IntegrationPointType( -0.5255324099163289858177 , -0.1834346424956498049395 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[157] = IntegrationPointType( -0.5255324099163289858177 , -0.1834346424956498049395 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[158] = IntegrationPointType( -0.5255324099163289858177 , -0.1834346424956498049395 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[159] = IntegrationPointType( -0.5255324099163289858177 , -0.1834346424956498049395 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[160] = IntegrationPointType( -0.5255324099163289858177 , 0.1834346424956498049395 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[161] = IntegrationPointType( -0.5255324099163289858177 , 0.1834346424956498049395 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[162] = IntegrationPointType( -0.5255324099163289858177 , 0.1834346424956498049395 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[163] = IntegrationPointType( -0.5255324099163289858177 , 0.1834346424956498049395 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[164] = IntegrationPointType( -0.5255324099163289858177 , 0.1834346424956498049395 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[165] = IntegrationPointType( -0.5255324099163289858177 , 0.1834346424956498049395 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[166] = IntegrationPointType( -0.5255324099163289858177 , 0.1834346424956498049395 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[167] = IntegrationPointType( -0.5255324099163289858177 , 0.1834346424956498049395 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[168] = IntegrationPointType( -0.5255324099163289858177 , 0.5255324099163289858177 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[169] = IntegrationPointType( -0.5255324099163289858177 , 0.5255324099163289858177 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[170] = IntegrationPointType( -0.5255324099163289858177 , 0.5255324099163289858177 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[171] = IntegrationPointType( -0.5255324099163289858177 , 0.5255324099163289858177 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[172] = IntegrationPointType( -0.5255324099163289858177 , 0.5255324099163289858177 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[173] = IntegrationPointType( -0.5255324099163289858177 , 0.5255324099163289858177 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[174] = IntegrationPointType( -0.5255324099163289858177 , 0.5255324099163289858177 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[175] = IntegrationPointType( -0.5255324099163289858177 , 0.5255324099163289858177 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[176] = IntegrationPointType( -0.5255324099163289858177 , 0.7966664774136267395916 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[177] = IntegrationPointType( -0.5255324099163289858177 , 0.7966664774136267395916 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[178] = IntegrationPointType( -0.5255324099163289858177 , 0.7966664774136267395916 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[179] = IntegrationPointType( -0.5255324099163289858177 , 0.7966664774136267395916 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[180] = IntegrationPointType( -0.5255324099163289858177 , 0.7966664774136267395916 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[181] = IntegrationPointType( -0.5255324099163289858177 , 0.7966664774136267395916 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[182] = IntegrationPointType( -0.5255324099163289858177 , 0.7966664774136267395916 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[183] = IntegrationPointType( -0.5255324099163289858177 , 0.7966664774136267395916 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[184] = IntegrationPointType( -0.5255324099163289858177 , 0.9602898564975362316836 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[185] = IntegrationPointType( -0.5255324099163289858177 , 0.9602898564975362316836 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[186] = IntegrationPointType( -0.5255324099163289858177 , 0.9602898564975362316836 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[187] = IntegrationPointType( -0.5255324099163289858177 , 0.9602898564975362316836 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[188] = IntegrationPointType( -0.5255324099163289858177 , 0.9602898564975362316836 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[189] = IntegrationPointType( -0.5255324099163289858177 , 0.9602898564975362316836 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[190] = IntegrationPointType( -0.5255324099163289858177 , 0.9602898564975362316836 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[191] = IntegrationPointType( -0.5255324099163289858177 , 0.9602898564975362316836 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[192] = IntegrationPointType( -0.1834346424956498049395 , -0.9602898564975362316836 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[193] = IntegrationPointType( -0.1834346424956498049395 , -0.9602898564975362316836 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[194] = IntegrationPointType( -0.1834346424956498049395 , -0.9602898564975362316836 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[195] = IntegrationPointType( -0.1834346424956498049395 , -0.9602898564975362316836 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[196] = IntegrationPointType( -0.1834346424956498049395 , -0.9602898564975362316836 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[197] = IntegrationPointType( -0.1834346424956498049395 , -0.9602898564975362316836 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[198] = IntegrationPointType( -0.1834346424956498049395 , -0.9602898564975362316836 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[199] = IntegrationPointType( -0.1834346424956498049395 , -0.9602898564975362316836 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[200] = IntegrationPointType( -0.1834346424956498049395 , -0.7966664774136267395916 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[201] = IntegrationPointType( -0.1834346424956498049395 , -0.7966664774136267395916 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[202] = IntegrationPointType( -0.1834346424956498049395 , -0.7966664774136267395916 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[203] = IntegrationPointType( -0.1834346424956498049395 , -0.7966664774136267395916 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[204] = IntegrationPointType( -0.1834346424956498049395 , -0.7966664774136267395916 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[205] = IntegrationPointType( -0.1834346424956498049395 , -0.7966664774136267395916 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[206] = IntegrationPointType( -0.1834346424956498049395 , -0.7966664774136267395916 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[207] = IntegrationPointType( -0.1834346424956498049395 , -0.7966664774136267395916 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[208] = IntegrationPointType( -0.1834346424956498049395 , -0.5255324099163289858177 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[209] = IntegrationPointType( -0.1834346424956498049395 , -0.5255324099163289858177 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[210] = IntegrationPointType( -0.1834346424956498049395 , -0.5255324099163289858177 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[211] = IntegrationPointType( -0.1834346424956498049395 , -0.5255324099163289858177 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[212] = IntegrationPointType( -0.1834346424956498049395 , -0.5255324099163289858177 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[213] = IntegrationPointType( -0.1834346424956498049395 , -0.5255324099163289858177 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[214] = IntegrationPointType( -0.1834346424956498049395 , -0.5255324099163289858177 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[215] = IntegrationPointType( -0.1834346424956498049395 , -0.5255324099163289858177 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[216] = IntegrationPointType( -0.1834346424956498049395 , -0.1834346424956498049395 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[217] = IntegrationPointType( -0.1834346424956498049395 , -0.1834346424956498049395 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[218] = IntegrationPointType( -0.1834346424956498049395 , -0.1834346424956498049395 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[219] = IntegrationPointType( -0.1834346424956498049395 , -0.1834346424956498049395 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[220] = IntegrationPointType( -0.1834346424956498049395 , -0.1834346424956498049395 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[221] = IntegrationPointType( -0.1834346424956498049395 , -0.1834346424956498049395 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[222] = IntegrationPointType( -0.1834346424956498049395 , -0.1834346424956498049395 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[223] = IntegrationPointType( -0.1834346424956498049395 , -0.1834346424956498049395 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[224] = IntegrationPointType( -0.1834346424956498049395 , 0.1834346424956498049395 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[225] = IntegrationPointType( -0.1834346424956498049395 , 0.1834346424956498049395 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[226] = IntegrationPointType( -0.1834346424956498049395 , 0.1834346424956498049395 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[227] = IntegrationPointType( -0.1834346424956498049395 , 0.1834346424956498049395 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[228] = IntegrationPointType( -0.1834346424956498049395 , 0.1834346424956498049395 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[229] = IntegrationPointType( -0.1834346424956498049395 , 0.1834346424956498049395 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[230] = IntegrationPointType( -0.1834346424956498049395 , 0.1834346424956498049395 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[231] = IntegrationPointType( -0.1834346424956498049395 , 0.1834346424956498049395 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[232] = IntegrationPointType( -0.1834346424956498049395 , 0.5255324099163289858177 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[233] = IntegrationPointType( -0.1834346424956498049395 , 0.5255324099163289858177 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[234] = IntegrationPointType( -0.1834346424956498049395 , 0.5255324099163289858177 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[235] = IntegrationPointType( -0.1834346424956498049395 , 0.5255324099163289858177 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[236] = IntegrationPointType( -0.1834346424956498049395 , 0.5255324099163289858177 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[237] = IntegrationPointType( -0.1834346424956498049395 , 0.5255324099163289858177 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[238] = IntegrationPointType( -0.1834346424956498049395 , 0.5255324099163289858177 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[239] = IntegrationPointType( -0.1834346424956498049395 , 0.5255324099163289858177 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[240] = IntegrationPointType( -0.1834346424956498049395 , 0.7966664774136267395916 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[241] = IntegrationPointType( -0.1834346424956498049395 , 0.7966664774136267395916 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[242] = IntegrationPointType( -0.1834346424956498049395 , 0.7966664774136267395916 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[243] = IntegrationPointType( -0.1834346424956498049395 , 0.7966664774136267395916 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[244] = IntegrationPointType( -0.1834346424956498049395 , 0.7966664774136267395916 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[245] = IntegrationPointType( -0.1834346424956498049395 , 0.7966664774136267395916 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[246] = IntegrationPointType( -0.1834346424956498049395 , 0.7966664774136267395916 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[247] = IntegrationPointType( -0.1834346424956498049395 , 0.7966664774136267395916 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[248] = IntegrationPointType( -0.1834346424956498049395 , 0.9602898564975362316836 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[249] = IntegrationPointType( -0.1834346424956498049395 , 0.9602898564975362316836 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[250] = IntegrationPointType( -0.1834346424956498049395 , 0.9602898564975362316836 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[251] = IntegrationPointType( -0.1834346424956498049395 , 0.9602898564975362316836 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[252] = IntegrationPointType( -0.1834346424956498049395 , 0.9602898564975362316836 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[253] = IntegrationPointType( -0.1834346424956498049395 , 0.9602898564975362316836 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[254] = IntegrationPointType( -0.1834346424956498049395 , 0.9602898564975362316836 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[255] = IntegrationPointType( -0.1834346424956498049395 , 0.9602898564975362316836 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[256] = IntegrationPointType( 0.1834346424956498049395 , -0.9602898564975362316836 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[257] = IntegrationPointType( 0.1834346424956498049395 , -0.9602898564975362316836 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[258] = IntegrationPointType( 0.1834346424956498049395 , -0.9602898564975362316836 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[259] = IntegrationPointType( 0.1834346424956498049395 , -0.9602898564975362316836 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[260] = IntegrationPointType( 0.1834346424956498049395 , -0.9602898564975362316836 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[261] = IntegrationPointType( 0.1834346424956498049395 , -0.9602898564975362316836 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[262] = IntegrationPointType( 0.1834346424956498049395 , -0.9602898564975362316836 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[263] = IntegrationPointType( 0.1834346424956498049395 , -0.9602898564975362316836 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[264] = IntegrationPointType( 0.1834346424956498049395 , -0.7966664774136267395916 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[265] = IntegrationPointType( 0.1834346424956498049395 , -0.7966664774136267395916 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[266] = IntegrationPointType( 0.1834346424956498049395 , -0.7966664774136267395916 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[267] = IntegrationPointType( 0.1834346424956498049395 , -0.7966664774136267395916 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[268] = IntegrationPointType( 0.1834346424956498049395 , -0.7966664774136267395916 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[269] = IntegrationPointType( 0.1834346424956498049395 , -0.7966664774136267395916 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[270] = IntegrationPointType( 0.1834346424956498049395 , -0.7966664774136267395916 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[271] = IntegrationPointType( 0.1834346424956498049395 , -0.7966664774136267395916 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[272] = IntegrationPointType( 0.1834346424956498049395 , -0.5255324099163289858177 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[273] = IntegrationPointType( 0.1834346424956498049395 , -0.5255324099163289858177 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[274] = IntegrationPointType( 0.1834346424956498049395 , -0.5255324099163289858177 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[275] = IntegrationPointType( 0.1834346424956498049395 , -0.5255324099163289858177 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[276] = IntegrationPointType( 0.1834346424956498049395 , -0.5255324099163289858177 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[277] = IntegrationPointType( 0.1834346424956498049395 , -0.5255324099163289858177 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[278] = IntegrationPointType( 0.1834346424956498049395 , -0.5255324099163289858177 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[279] = IntegrationPointType( 0.1834346424956498049395 , -0.5255324099163289858177 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[280] = IntegrationPointType( 0.1834346424956498049395 , -0.1834346424956498049395 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[281] = IntegrationPointType( 0.1834346424956498049395 , -0.1834346424956498049395 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[282] = IntegrationPointType( 0.1834346424956498049395 , -0.1834346424956498049395 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[283] = IntegrationPointType( 0.1834346424956498049395 , -0.1834346424956498049395 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[284] = IntegrationPointType( 0.1834346424956498049395 , -0.1834346424956498049395 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[285] = IntegrationPointType( 0.1834346424956498049395 , -0.1834346424956498049395 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[286] = IntegrationPointType( 0.1834346424956498049395 , -0.1834346424956498049395 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[287] = IntegrationPointType( 0.1834346424956498049395 , -0.1834346424956498049395 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[288] = IntegrationPointType( 0.1834346424956498049395 , 0.1834346424956498049395 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[289] = IntegrationPointType( 0.1834346424956498049395 , 0.1834346424956498049395 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[290] = IntegrationPointType( 0.1834346424956498049395 , 0.1834346424956498049395 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[291] = IntegrationPointType( 0.1834346424956498049395 , 0.1834346424956498049395 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[292] = IntegrationPointType( 0.1834346424956498049395 , 0.1834346424956498049395 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[293] = IntegrationPointType( 0.1834346424956498049395 , 0.1834346424956498049395 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[294] = IntegrationPointType( 0.1834346424956498049395 , 0.1834346424956498049395 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[295] = IntegrationPointType( 0.1834346424956498049395 , 0.1834346424956498049395 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[296] = IntegrationPointType( 0.1834346424956498049395 , 0.5255324099163289858177 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[297] = IntegrationPointType( 0.1834346424956498049395 , 0.5255324099163289858177 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[298] = IntegrationPointType( 0.1834346424956498049395 , 0.5255324099163289858177 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[299] = IntegrationPointType( 0.1834346424956498049395 , 0.5255324099163289858177 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[300] = IntegrationPointType( 0.1834346424956498049395 , 0.5255324099163289858177 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[301] = IntegrationPointType( 0.1834346424956498049395 , 0.5255324099163289858177 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[302] = IntegrationPointType( 0.1834346424956498049395 , 0.5255324099163289858177 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[303] = IntegrationPointType( 0.1834346424956498049395 , 0.5255324099163289858177 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[304] = IntegrationPointType( 0.1834346424956498049395 , 0.7966664774136267395916 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[305] = IntegrationPointType( 0.1834346424956498049395 , 0.7966664774136267395916 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[306] = IntegrationPointType( 0.1834346424956498049395 , 0.7966664774136267395916 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[307] = IntegrationPointType( 0.1834346424956498049395 , 0.7966664774136267395916 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[308] = IntegrationPointType( 0.1834346424956498049395 , 0.7966664774136267395916 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[309] = IntegrationPointType( 0.1834346424956498049395 , 0.7966664774136267395916 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[310] = IntegrationPointType( 0.1834346424956498049395 , 0.7966664774136267395916 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[311] = IntegrationPointType( 0.1834346424956498049395 , 0.7966664774136267395916 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[312] = IntegrationPointType( 0.1834346424956498049395 , 0.9602898564975362316836 , -0.9602898564975362316836 , 0.362683783378361982965 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[313] = IntegrationPointType( 0.1834346424956498049395 , 0.9602898564975362316836 , -0.7966664774136267395916 , 0.362683783378361982965 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[314] = IntegrationPointType( 0.1834346424956498049395 , 0.9602898564975362316836 , -0.5255324099163289858177 , 0.362683783378361982965 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[315] = IntegrationPointType( 0.1834346424956498049395 , 0.9602898564975362316836 , -0.1834346424956498049395 , 0.362683783378361982965 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[316] = IntegrationPointType( 0.1834346424956498049395 , 0.9602898564975362316836 , 0.1834346424956498049395 , 0.362683783378361982965 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[317] = IntegrationPointType( 0.1834346424956498049395 , 0.9602898564975362316836 , 0.5255324099163289858177 , 0.362683783378361982965 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[318] = IntegrationPointType( 0.1834346424956498049395 , 0.9602898564975362316836 , 0.7966664774136267395916 , 0.362683783378361982965 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[319] = IntegrationPointType( 0.1834346424956498049395 , 0.9602898564975362316836 , 0.9602898564975362316836 , 0.362683783378361982965 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[320] = IntegrationPointType( 0.5255324099163289858177 , -0.9602898564975362316836 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[321] = IntegrationPointType( 0.5255324099163289858177 , -0.9602898564975362316836 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[322] = IntegrationPointType( 0.5255324099163289858177 , -0.9602898564975362316836 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[323] = IntegrationPointType( 0.5255324099163289858177 , -0.9602898564975362316836 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[324] = IntegrationPointType( 0.5255324099163289858177 , -0.9602898564975362316836 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[325] = IntegrationPointType( 0.5255324099163289858177 , -0.9602898564975362316836 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[326] = IntegrationPointType( 0.5255324099163289858177 , -0.9602898564975362316836 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[327] = IntegrationPointType( 0.5255324099163289858177 , -0.9602898564975362316836 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[328] = IntegrationPointType( 0.5255324099163289858177 , -0.7966664774136267395916 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[329] = IntegrationPointType( 0.5255324099163289858177 , -0.7966664774136267395916 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[330] = IntegrationPointType( 0.5255324099163289858177 , -0.7966664774136267395916 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[331] = IntegrationPointType( 0.5255324099163289858177 , -0.7966664774136267395916 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[332] = IntegrationPointType( 0.5255324099163289858177 , -0.7966664774136267395916 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[333] = IntegrationPointType( 0.5255324099163289858177 , -0.7966664774136267395916 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[334] = IntegrationPointType( 0.5255324099163289858177 , -0.7966664774136267395916 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[335] = IntegrationPointType( 0.5255324099163289858177 , -0.7966664774136267395916 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[336] = IntegrationPointType( 0.5255324099163289858177 , -0.5255324099163289858177 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[337] = IntegrationPointType( 0.5255324099163289858177 , -0.5255324099163289858177 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[338] = IntegrationPointType( 0.5255324099163289858177 , -0.5255324099163289858177 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[339] = IntegrationPointType( 0.5255324099163289858177 , -0.5255324099163289858177 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[340] = IntegrationPointType( 0.5255324099163289858177 , -0.5255324099163289858177 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[341] = IntegrationPointType( 0.5255324099163289858177 , -0.5255324099163289858177 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[342] = IntegrationPointType( 0.5255324099163289858177 , -0.5255324099163289858177 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[343] = IntegrationPointType( 0.5255324099163289858177 , -0.5255324099163289858177 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[344] = IntegrationPointType( 0.5255324099163289858177 , -0.1834346424956498049395 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[345] = IntegrationPointType( 0.5255324099163289858177 , -0.1834346424956498049395 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[346] = IntegrationPointType( 0.5255324099163289858177 , -0.1834346424956498049395 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[347] = IntegrationPointType( 0.5255324099163289858177 , -0.1834346424956498049395 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[348] = IntegrationPointType( 0.5255324099163289858177 , -0.1834346424956498049395 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[349] = IntegrationPointType( 0.5255324099163289858177 , -0.1834346424956498049395 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[350] = IntegrationPointType( 0.5255324099163289858177 , -0.1834346424956498049395 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[351] = IntegrationPointType( 0.5255324099163289858177 , -0.1834346424956498049395 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[352] = IntegrationPointType( 0.5255324099163289858177 , 0.1834346424956498049395 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[353] = IntegrationPointType( 0.5255324099163289858177 , 0.1834346424956498049395 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[354] = IntegrationPointType( 0.5255324099163289858177 , 0.1834346424956498049395 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[355] = IntegrationPointType( 0.5255324099163289858177 , 0.1834346424956498049395 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[356] = IntegrationPointType( 0.5255324099163289858177 , 0.1834346424956498049395 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[357] = IntegrationPointType( 0.5255324099163289858177 , 0.1834346424956498049395 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[358] = IntegrationPointType( 0.5255324099163289858177 , 0.1834346424956498049395 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[359] = IntegrationPointType( 0.5255324099163289858177 , 0.1834346424956498049395 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[360] = IntegrationPointType( 0.5255324099163289858177 , 0.5255324099163289858177 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[361] = IntegrationPointType( 0.5255324099163289858177 , 0.5255324099163289858177 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[362] = IntegrationPointType( 0.5255324099163289858177 , 0.5255324099163289858177 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[363] = IntegrationPointType( 0.5255324099163289858177 , 0.5255324099163289858177 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[364] = IntegrationPointType( 0.5255324099163289858177 , 0.5255324099163289858177 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[365] = IntegrationPointType( 0.5255324099163289858177 , 0.5255324099163289858177 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[366] = IntegrationPointType( 0.5255324099163289858177 , 0.5255324099163289858177 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[367] = IntegrationPointType( 0.5255324099163289858177 , 0.5255324099163289858177 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[368] = IntegrationPointType( 0.5255324099163289858177 , 0.7966664774136267395916 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[369] = IntegrationPointType( 0.5255324099163289858177 , 0.7966664774136267395916 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[370] = IntegrationPointType( 0.5255324099163289858177 , 0.7966664774136267395916 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[371] = IntegrationPointType( 0.5255324099163289858177 , 0.7966664774136267395916 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[372] = IntegrationPointType( 0.5255324099163289858177 , 0.7966664774136267395916 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[373] = IntegrationPointType( 0.5255324099163289858177 , 0.7966664774136267395916 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[374] = IntegrationPointType( 0.5255324099163289858177 , 0.7966664774136267395916 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[375] = IntegrationPointType( 0.5255324099163289858177 , 0.7966664774136267395916 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[376] = IntegrationPointType( 0.5255324099163289858177 , 0.9602898564975362316836 , -0.9602898564975362316836 , 0.313706645877887287338 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[377] = IntegrationPointType( 0.5255324099163289858177 , 0.9602898564975362316836 , -0.7966664774136267395916 , 0.313706645877887287338 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[378] = IntegrationPointType( 0.5255324099163289858177 , 0.9602898564975362316836 , -0.5255324099163289858177 , 0.313706645877887287338 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[379] = IntegrationPointType( 0.5255324099163289858177 , 0.9602898564975362316836 , -0.1834346424956498049395 , 0.313706645877887287338 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[380] = IntegrationPointType( 0.5255324099163289858177 , 0.9602898564975362316836 , 0.1834346424956498049395 , 0.313706645877887287338 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[381] = IntegrationPointType( 0.5255324099163289858177 , 0.9602898564975362316836 , 0.5255324099163289858177 , 0.313706645877887287338 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[382] = IntegrationPointType( 0.5255324099163289858177 , 0.9602898564975362316836 , 0.7966664774136267395916 , 0.313706645877887287338 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[383] = IntegrationPointType( 0.5255324099163289858177 , 0.9602898564975362316836 , 0.9602898564975362316836 , 0.313706645877887287338 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[384] = IntegrationPointType( 0.7966664774136267395916 , -0.9602898564975362316836 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[385] = IntegrationPointType( 0.7966664774136267395916 , -0.9602898564975362316836 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[386] = IntegrationPointType( 0.7966664774136267395916 , -0.9602898564975362316836 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[387] = IntegrationPointType( 0.7966664774136267395916 , -0.9602898564975362316836 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[388] = IntegrationPointType( 0.7966664774136267395916 , -0.9602898564975362316836 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[389] = IntegrationPointType( 0.7966664774136267395916 , -0.9602898564975362316836 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[390] = IntegrationPointType( 0.7966664774136267395916 , -0.9602898564975362316836 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[391] = IntegrationPointType( 0.7966664774136267395916 , -0.9602898564975362316836 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[392] = IntegrationPointType( 0.7966664774136267395916 , -0.7966664774136267395916 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[393] = IntegrationPointType( 0.7966664774136267395916 , -0.7966664774136267395916 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[394] = IntegrationPointType( 0.7966664774136267395916 , -0.7966664774136267395916 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[395] = IntegrationPointType( 0.7966664774136267395916 , -0.7966664774136267395916 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[396] = IntegrationPointType( 0.7966664774136267395916 , -0.7966664774136267395916 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[397] = IntegrationPointType( 0.7966664774136267395916 , -0.7966664774136267395916 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[398] = IntegrationPointType( 0.7966664774136267395916 , -0.7966664774136267395916 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[399] = IntegrationPointType( 0.7966664774136267395916 , -0.7966664774136267395916 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[400] = IntegrationPointType( 0.7966664774136267395916 , -0.5255324099163289858177 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[401] = IntegrationPointType( 0.7966664774136267395916 , -0.5255324099163289858177 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[402] = IntegrationPointType( 0.7966664774136267395916 , -0.5255324099163289858177 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[403] = IntegrationPointType( 0.7966664774136267395916 , -0.5255324099163289858177 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[404] = IntegrationPointType( 0.7966664774136267395916 , -0.5255324099163289858177 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[405] = IntegrationPointType( 0.7966664774136267395916 , -0.5255324099163289858177 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[406] = IntegrationPointType( 0.7966664774136267395916 , -0.5255324099163289858177 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[407] = IntegrationPointType( 0.7966664774136267395916 , -0.5255324099163289858177 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[408] = IntegrationPointType( 0.7966664774136267395916 , -0.1834346424956498049395 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[409] = IntegrationPointType( 0.7966664774136267395916 , -0.1834346424956498049395 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[410] = IntegrationPointType( 0.7966664774136267395916 , -0.1834346424956498049395 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[411] = IntegrationPointType( 0.7966664774136267395916 , -0.1834346424956498049395 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[412] = IntegrationPointType( 0.7966664774136267395916 , -0.1834346424956498049395 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[413] = IntegrationPointType( 0.7966664774136267395916 , -0.1834346424956498049395 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[414] = IntegrationPointType( 0.7966664774136267395916 , -0.1834346424956498049395 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[415] = IntegrationPointType( 0.7966664774136267395916 , -0.1834346424956498049395 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[416] = IntegrationPointType( 0.7966664774136267395916 , 0.1834346424956498049395 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[417] = IntegrationPointType( 0.7966664774136267395916 , 0.1834346424956498049395 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[418] = IntegrationPointType( 0.7966664774136267395916 , 0.1834346424956498049395 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[419] = IntegrationPointType( 0.7966664774136267395916 , 0.1834346424956498049395 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[420] = IntegrationPointType( 0.7966664774136267395916 , 0.1834346424956498049395 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[421] = IntegrationPointType( 0.7966664774136267395916 , 0.1834346424956498049395 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[422] = IntegrationPointType( 0.7966664774136267395916 , 0.1834346424956498049395 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[423] = IntegrationPointType( 0.7966664774136267395916 , 0.1834346424956498049395 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[424] = IntegrationPointType( 0.7966664774136267395916 , 0.5255324099163289858177 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[425] = IntegrationPointType( 0.7966664774136267395916 , 0.5255324099163289858177 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[426] = IntegrationPointType( 0.7966664774136267395916 , 0.5255324099163289858177 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[427] = IntegrationPointType( 0.7966664774136267395916 , 0.5255324099163289858177 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[428] = IntegrationPointType( 0.7966664774136267395916 , 0.5255324099163289858177 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[429] = IntegrationPointType( 0.7966664774136267395916 , 0.5255324099163289858177 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[430] = IntegrationPointType( 0.7966664774136267395916 , 0.5255324099163289858177 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[431] = IntegrationPointType( 0.7966664774136267395916 , 0.5255324099163289858177 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[432] = IntegrationPointType( 0.7966664774136267395916 , 0.7966664774136267395916 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[433] = IntegrationPointType( 0.7966664774136267395916 , 0.7966664774136267395916 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[434] = IntegrationPointType( 0.7966664774136267395916 , 0.7966664774136267395916 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[435] = IntegrationPointType( 0.7966664774136267395916 , 0.7966664774136267395916 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[436] = IntegrationPointType( 0.7966664774136267395916 , 0.7966664774136267395916 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[437] = IntegrationPointType( 0.7966664774136267395916 , 0.7966664774136267395916 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[438] = IntegrationPointType( 0.7966664774136267395916 , 0.7966664774136267395916 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[439] = IntegrationPointType( 0.7966664774136267395916 , 0.7966664774136267395916 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[440] = IntegrationPointType( 0.7966664774136267395916 , 0.9602898564975362316836 , -0.9602898564975362316836 , 0.222381034453374470544 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[441] = IntegrationPointType( 0.7966664774136267395916 , 0.9602898564975362316836 , -0.7966664774136267395916 , 0.222381034453374470544 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[442] = IntegrationPointType( 0.7966664774136267395916 , 0.9602898564975362316836 , -0.5255324099163289858177 , 0.222381034453374470544 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[443] = IntegrationPointType( 0.7966664774136267395916 , 0.9602898564975362316836 , -0.1834346424956498049395 , 0.222381034453374470544 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[444] = IntegrationPointType( 0.7966664774136267395916 , 0.9602898564975362316836 , 0.1834346424956498049395 , 0.222381034453374470544 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[445] = IntegrationPointType( 0.7966664774136267395916 , 0.9602898564975362316836 , 0.5255324099163289858177 , 0.222381034453374470544 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[446] = IntegrationPointType( 0.7966664774136267395916 , 0.9602898564975362316836 , 0.7966664774136267395916 , 0.222381034453374470544 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[447] = IntegrationPointType( 0.7966664774136267395916 , 0.9602898564975362316836 , 0.9602898564975362316836 , 0.222381034453374470544 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[448] = IntegrationPointType( 0.9602898564975362316836 , -0.9602898564975362316836 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[449] = IntegrationPointType( 0.9602898564975362316836 , -0.9602898564975362316836 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[450] = IntegrationPointType( 0.9602898564975362316836 , -0.9602898564975362316836 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[451] = IntegrationPointType( 0.9602898564975362316836 , -0.9602898564975362316836 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[452] = IntegrationPointType( 0.9602898564975362316836 , -0.9602898564975362316836 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[453] = IntegrationPointType( 0.9602898564975362316836 , -0.9602898564975362316836 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[454] = IntegrationPointType( 0.9602898564975362316836 , -0.9602898564975362316836 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[455] = IntegrationPointType( 0.9602898564975362316836 , -0.9602898564975362316836 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.101228536290376259153 * 0.101228536290376259153 );

        msIntegrationPoints[456] = IntegrationPointType( 0.9602898564975362316836 , -0.7966664774136267395916 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[457] = IntegrationPointType( 0.9602898564975362316836 , -0.7966664774136267395916 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[458] = IntegrationPointType( 0.9602898564975362316836 , -0.7966664774136267395916 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[459] = IntegrationPointType( 0.9602898564975362316836 , -0.7966664774136267395916 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[460] = IntegrationPointType( 0.9602898564975362316836 , -0.7966664774136267395916 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[461] = IntegrationPointType( 0.9602898564975362316836 , -0.7966664774136267395916 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[462] = IntegrationPointType( 0.9602898564975362316836 , -0.7966664774136267395916 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[463] = IntegrationPointType( 0.9602898564975362316836 , -0.7966664774136267395916 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[464] = IntegrationPointType( 0.9602898564975362316836 , -0.5255324099163289858177 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[465] = IntegrationPointType( 0.9602898564975362316836 , -0.5255324099163289858177 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[466] = IntegrationPointType( 0.9602898564975362316836 , -0.5255324099163289858177 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[467] = IntegrationPointType( 0.9602898564975362316836 , -0.5255324099163289858177 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[468] = IntegrationPointType( 0.9602898564975362316836 , -0.5255324099163289858177 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[469] = IntegrationPointType( 0.9602898564975362316836 , -0.5255324099163289858177 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[470] = IntegrationPointType( 0.9602898564975362316836 , -0.5255324099163289858177 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[471] = IntegrationPointType( 0.9602898564975362316836 , -0.5255324099163289858177 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[472] = IntegrationPointType( 0.9602898564975362316836 , -0.1834346424956498049395 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[473] = IntegrationPointType( 0.9602898564975362316836 , -0.1834346424956498049395 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[474] = IntegrationPointType( 0.9602898564975362316836 , -0.1834346424956498049395 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[475] = IntegrationPointType( 0.9602898564975362316836 , -0.1834346424956498049395 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[476] = IntegrationPointType( 0.9602898564975362316836 , -0.1834346424956498049395 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[477] = IntegrationPointType( 0.9602898564975362316836 , -0.1834346424956498049395 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[478] = IntegrationPointType( 0.9602898564975362316836 , -0.1834346424956498049395 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[479] = IntegrationPointType( 0.9602898564975362316836 , -0.1834346424956498049395 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[480] = IntegrationPointType( 0.9602898564975362316836 , 0.1834346424956498049395 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.362683783378361982965 * 0.101228536290376259153 );
        msIntegrationPoints[481] = IntegrationPointType( 0.9602898564975362316836 , 0.1834346424956498049395 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[482] = IntegrationPointType( 0.9602898564975362316836 , 0.1834346424956498049395 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[483] = IntegrationPointType( 0.9602898564975362316836 , 0.1834346424956498049395 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[484] = IntegrationPointType( 0.9602898564975362316836 , 0.1834346424956498049395 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.362683783378361982965 * 0.362683783378361982965 );
        msIntegrationPoints[485] = IntegrationPointType( 0.9602898564975362316836 , 0.1834346424956498049395 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.362683783378361982965 * 0.313706645877887287338 );
        msIntegrationPoints[486] = IntegrationPointType( 0.9602898564975362316836 , 0.1834346424956498049395 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.362683783378361982965 * 0.222381034453374470544 );
        msIntegrationPoints[487] = IntegrationPointType( 0.9602898564975362316836 , 0.1834346424956498049395 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.362683783378361982965 * 0.101228536290376259153 );

        msIntegrationPoints[488] = IntegrationPointType( 0.9602898564975362316836 , 0.5255324099163289858177 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.313706645877887287338 * 0.101228536290376259153 );
        msIntegrationPoints[489] = IntegrationPointType( 0.9602898564975362316836 , 0.5255324099163289858177 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[490] = IntegrationPointType( 0.9602898564975362316836 , 0.5255324099163289858177 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[491] = IntegrationPointType( 0.9602898564975362316836 , 0.5255324099163289858177 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[492] = IntegrationPointType( 0.9602898564975362316836 , 0.5255324099163289858177 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.313706645877887287338 * 0.362683783378361982965 );
        msIntegrationPoints[493] = IntegrationPointType( 0.9602898564975362316836 , 0.5255324099163289858177 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.313706645877887287338 * 0.313706645877887287338 );
        msIntegrationPoints[494] = IntegrationPointType( 0.9602898564975362316836 , 0.5255324099163289858177 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.313706645877887287338 * 0.222381034453374470544 );
        msIntegrationPoints[495] = IntegrationPointType( 0.9602898564975362316836 , 0.5255324099163289858177 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.313706645877887287338 * 0.101228536290376259153 );

        msIntegrationPoints[496] = IntegrationPointType( 0.9602898564975362316836 , 0.7966664774136267395916 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.222381034453374470544 * 0.101228536290376259153 );
        msIntegrationPoints[497] = IntegrationPointType( 0.9602898564975362316836 , 0.7966664774136267395916 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[498] = IntegrationPointType( 0.9602898564975362316836 , 0.7966664774136267395916 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[499] = IntegrationPointType( 0.9602898564975362316836 , 0.7966664774136267395916 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[500] = IntegrationPointType( 0.9602898564975362316836 , 0.7966664774136267395916 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.222381034453374470544 * 0.362683783378361982965 );
        msIntegrationPoints[501] = IntegrationPointType( 0.9602898564975362316836 , 0.7966664774136267395916 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.222381034453374470544 * 0.313706645877887287338 );
        msIntegrationPoints[502] = IntegrationPointType( 0.9602898564975362316836 , 0.7966664774136267395916 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.222381034453374470544 * 0.222381034453374470544 );
        msIntegrationPoints[503] = IntegrationPointType( 0.9602898564975362316836 , 0.7966664774136267395916 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.222381034453374470544 * 0.101228536290376259153 );

        msIntegrationPoints[504] = IntegrationPointType( 0.9602898564975362316836 , 0.9602898564975362316836 , -0.9602898564975362316836 , 0.101228536290376259153 * 0.101228536290376259153 * 0.101228536290376259153 );
        msIntegrationPoints[505] = IntegrationPointType( 0.9602898564975362316836 , 0.9602898564975362316836 , -0.7966664774136267395916 , 0.101228536290376259153 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[506] = IntegrationPointType( 0.9602898564975362316836 , 0.9602898564975362316836 , -0.5255324099163289858177 , 0.101228536290376259153 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[507] = IntegrationPointType( 0.9602898564975362316836 , 0.9602898564975362316836 , -0.1834346424956498049395 , 0.101228536290376259153 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[508] = IntegrationPointType( 0.9602898564975362316836 , 0.9602898564975362316836 , 0.1834346424956498049395 , 0.101228536290376259153 * 0.101228536290376259153 * 0.362683783378361982965 );
        msIntegrationPoints[509] = IntegrationPointType( 0.9602898564975362316836 , 0.9602898564975362316836 , 0.5255324099163289858177 , 0.101228536290376259153 * 0.101228536290376259153 * 0.313706645877887287338 );
        msIntegrationPoints[510] = IntegrationPointType( 0.9602898564975362316836 , 0.9602898564975362316836 , 0.7966664774136267395916 , 0.101228536290376259153 * 0.101228536290376259153 * 0.222381034453374470544 );
        msIntegrationPoints[511] = IntegrationPointType( 0.9602898564975362316836 , 0.9602898564975362316836 , 0.9602898564975362316836 , 0.101228536290376259153 * 0.101228536290376259153 * 0.101228536290376259153 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Hexahedron Gauss-Legendre quadrature 8";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class HexahedronGaussLegendreIntegrationPoints8

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}


}  // namespace Kratos.

#endif // KRATOS_HEXAHEDRON_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED  defined 


