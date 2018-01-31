//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.6 $
//
//


#if !defined(KRATOS_LINE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED )
#define  KRATOS_LINE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED

// System includes

// External includes

// Project includes
#include "integration/quadrature.h"

namespace Kratos
{
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints1
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints1);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 1> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 1;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        // This is added to solve the problem of static initialization. Pooyan.
        msIntegrationPoints[0] = IntegrationPointType(0.00, 2.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 1 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints1


class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints2
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints2);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 2> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 2;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-std::sqrt(1.00 / 3.00), 1.00);
        msIntegrationPoints[1] = IntegrationPointType( std::sqrt(1.00 / 3.00), 1.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 2 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints2


class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints3
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints3);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 3> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 3;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-std::sqrt(3.00 / 5.00), 5.00 / 9.00);
        msIntegrationPoints[1] = IntegrationPointType( 0.00                  , 8.00 / 9.00);
        msIntegrationPoints[2] = IntegrationPointType( std::sqrt(3.00 / 5.00), 5.00 / 9.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 3 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints3



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints4
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints4);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 4> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 4;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-std::sqrt(3.00/7.00 + 2.00/7.00*std::sqrt(6.00/5.00)), (18.00 - std::sqrt(30.00))/36.00);
        msIntegrationPoints[1] = IntegrationPointType(-std::sqrt(3.00/7.00 - 2.00/7.00*std::sqrt(6.00/5.00)), (18.00 + std::sqrt(30.00))/36.00);
        msIntegrationPoints[2] = IntegrationPointType(std::sqrt(3.00/7.00 - 2.00/7.00*std::sqrt(6.00/5.00)), (18.00 + std::sqrt(30.00))/36.00);
        msIntegrationPoints[3] = IntegrationPointType(std::sqrt(3.00/7.00 + 2.00/7.00*std::sqrt(6.00/5.00)), (18.00 - std::sqrt(30.00))/36.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 4 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints4



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints5
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints5);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 5> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 5;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-std::sqrt(5.00 + 2.00*std::sqrt(10.00/7.00))/3.00, (322.00 - 13.00*std::sqrt(70.00))/900.00);
        msIntegrationPoints[1] = IntegrationPointType(-std::sqrt(5.00 - 2.00*std::sqrt(10.00/7.00))/3.00, (322.00 + 13.00*std::sqrt(70.00))/900.00);
        msIntegrationPoints[2] = IntegrationPointType(0.000000000000000, 128.00/225.00);
        msIntegrationPoints[3] = IntegrationPointType(std::sqrt(5.00 - 2.00*std::sqrt(10.00/7.00))/3.00, (322.00 + 13.00*std::sqrt(70.00))/900.00);
        msIntegrationPoints[4] = IntegrationPointType(std::sqrt(5.00 + 2.00*std::sqrt(10.00/7.00))/3.00, (322.00 - 13.00*std::sqrt(70.00))/900.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 5 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints4



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints6
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints6);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 6> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 6;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-0.9324695142031520278123, 0.1713244923791703450403);
        msIntegrationPoints[1] = IntegrationPointType(-0.661209386466264513661, 0.3607615730481386075698);
        msIntegrationPoints[2] = IntegrationPointType(-0.2386191860831969086305, 0.4679139345726910473899);
        msIntegrationPoints[3] = IntegrationPointType(0.2386191860831969086305, 0.4679139345726910473899);
        msIntegrationPoints[4] = IntegrationPointType(0.661209386466264513661, 0.3607615730481386075698);
        msIntegrationPoints[5] = IntegrationPointType(0.9324695142031520278123, 0.1713244923791703450403);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 6 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints6



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints7
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints7);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 7> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 7;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-0.9491079123427585245262, 0.1294849661688696932706);
        msIntegrationPoints[1] = IntegrationPointType(-0.7415311855993944398639, 0.2797053914892766679015);
        msIntegrationPoints[2] = IntegrationPointType(-0.4058451513773971669066, 0.38183005050511894495);
        msIntegrationPoints[3] = IntegrationPointType(0, 0.417959183673469387755);
        msIntegrationPoints[4] = IntegrationPointType(0.4058451513773971669066, 0.38183005050511894495);
        msIntegrationPoints[5] = IntegrationPointType(0.7415311855993944398639, 0.2797053914892766679015);
        msIntegrationPoints[6] = IntegrationPointType(0.9491079123427585245262, 0.1294849661688696932706);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 7 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints7



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints8
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints8);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 8> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 8;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-0.9602898564975362316836, 0.1012285362903762591525);
        msIntegrationPoints[1] = IntegrationPointType(-0.7966664774136267395916, 0.2223810344533744705444);
        msIntegrationPoints[2] = IntegrationPointType(-0.5255324099163289858177, 0.313706645877887287338);
        msIntegrationPoints[3] = IntegrationPointType(-0.1834346424956498049395, 0.3626837833783619829652);
        msIntegrationPoints[4] = IntegrationPointType( 0.1834346424956498049395, 0.3626837833783619829652);
        msIntegrationPoints[5] = IntegrationPointType( 0.5255324099163289858177, 0.313706645877887287338);
        msIntegrationPoints[6] = IntegrationPointType( 0.7966664774136267395916, 0.2223810344533744705444);
        msIntegrationPoints[7] = IntegrationPointType( 0.9602898564975362316836, 0.1012285362903762591525);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 8 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints8



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints9
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints9);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 9> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 9;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-0.9681602395076260898356, 0.0812743883615744119719);
        msIntegrationPoints[1] = IntegrationPointType(-0.8360311073266357942994, 0.1806481606948574040585);
        msIntegrationPoints[2] = IntegrationPointType(-0.6133714327005903973087, 0.2606106964029354623187);
        msIntegrationPoints[3] = IntegrationPointType(-0.3242534234038089290385, 0.312347077040002840069);
        msIntegrationPoints[4] = IntegrationPointType(0, 0.330239355001259763165);
        msIntegrationPoints[5] = IntegrationPointType( 0.3242534234038089290385, 0.312347077040002840069);
        msIntegrationPoints[6] = IntegrationPointType( 0.6133714327005903973087, 0.2606106964029354623187);
        msIntegrationPoints[7] = IntegrationPointType( 0.8360311073266357942994, 0.1806481606948574040585);
        msIntegrationPoints[8] = IntegrationPointType( 0.9681602395076260898356, 0.0812743883615744119719);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 9 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints9



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints10
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineGaussLegendreIntegrationPoints10);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 10> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 10;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-0.973906528517171720078, 0.0666713443086881375936);
        msIntegrationPoints[1] = IntegrationPointType(-0.8650633666889845107321, 0.149451349150580593146);
        msIntegrationPoints[2] = IntegrationPointType(-0.6794095682990244062343, 0.219086362515982043996);
        msIntegrationPoints[3] = IntegrationPointType(-0.4333953941292471907993, 0.2692667193099963550912);
        msIntegrationPoints[4] = IntegrationPointType(-0.1488743389816312108848, 0.2955242247147528701739);
        msIntegrationPoints[5] = IntegrationPointType( 0.1488743389816312108848, 0.2955242247147528701739);
        msIntegrationPoints[6] = IntegrationPointType( 0.4333953941292471907993, 0.2692667193099963550912);
        msIntegrationPoints[7] = IntegrationPointType( 0.6794095682990244062343, 0.219086362515982043996);
        msIntegrationPoints[8] = IntegrationPointType( 0.8650633666889845107321, 0.149451349150580593146);
        msIntegrationPoints[9] = IntegrationPointType( 0.973906528517171720078, 0.0666713443086881375936);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 10 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLegendreIntegrationPoints10


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

///@}
///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}


}  // namespace Kratos.

#endif // KRATOS_LINE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED  defined 


