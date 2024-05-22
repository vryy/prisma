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
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 1> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 1;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(0.00, 2.00)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 1 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints1


class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints2
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 2> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 2;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-std::sqrt(1.00 / 3.00), 1.00),
            IntegrationPointType( std::sqrt(1.00 / 3.00), 1.00)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 2 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints2


class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints3
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 3> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 3;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-std::sqrt(3.00 / 5.00), 5.00 / 9.00),
            IntegrationPointType( 0.00                  , 8.00 / 9.00),
            IntegrationPointType( std::sqrt(3.00 / 5.00), 5.00 / 9.00)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 3 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints3



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints4
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 4> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 4;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-std::sqrt(3.00/7.00 + 2.00/7.00*std::sqrt(6.00/5.00)), (18.00 - std::sqrt(30.00))/36.00),
            IntegrationPointType(-std::sqrt(3.00/7.00 - 2.00/7.00*std::sqrt(6.00/5.00)), (18.00 + std::sqrt(30.00))/36.00),
            IntegrationPointType(std::sqrt(3.00/7.00 - 2.00/7.00*std::sqrt(6.00/5.00)), (18.00 + std::sqrt(30.00))/36.00),
            IntegrationPointType(std::sqrt(3.00/7.00 + 2.00/7.00*std::sqrt(6.00/5.00)), (18.00 - std::sqrt(30.00))/36.00)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 4 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints4



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints5
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 5> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 5;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-std::sqrt(5.00 + 2.00*std::sqrt(10.00/7.00))/3.00, (322.00 - 13.00*std::sqrt(70.00))/900.00),
            IntegrationPointType(-std::sqrt(5.00 - 2.00*std::sqrt(10.00/7.00))/3.00, (322.00 + 13.00*std::sqrt(70.00))/900.00),
            IntegrationPointType(0.000000000000000, 128.00/225.00),
            IntegrationPointType(std::sqrt(5.00 - 2.00*std::sqrt(10.00/7.00))/3.00, (322.00 + 13.00*std::sqrt(70.00))/900.00),
            IntegrationPointType(std::sqrt(5.00 + 2.00*std::sqrt(10.00/7.00))/3.00, (322.00 - 13.00*std::sqrt(70.00))/900.00)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 5 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints4



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints6
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 6> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 6;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-0.9324695142031520278123, 0.1713244923791703450403),
            IntegrationPointType(-0.661209386466264513661, 0.3607615730481386075698),
            IntegrationPointType(-0.2386191860831969086305, 0.4679139345726910473899),
            IntegrationPointType(0.2386191860831969086305, 0.4679139345726910473899),
            IntegrationPointType(0.661209386466264513661, 0.3607615730481386075698),
            IntegrationPointType(0.9324695142031520278123, 0.1713244923791703450403)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 6 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints6



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints7
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 7> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 7;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-0.9491079123427585245262, 0.1294849661688696932706),
            IntegrationPointType(-0.7415311855993944398639, 0.2797053914892766679015),
            IntegrationPointType(-0.4058451513773971669066, 0.38183005050511894495),
            IntegrationPointType(0, 0.417959183673469387755),
            IntegrationPointType(0.4058451513773971669066, 0.38183005050511894495),
            IntegrationPointType(0.7415311855993944398639, 0.2797053914892766679015),
            IntegrationPointType(0.9491079123427585245262, 0.1294849661688696932706)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 7 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints7



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints8
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 8> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 8;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-0.9602898564975362316836, 0.1012285362903762591525),
            IntegrationPointType(-0.7966664774136267395916, 0.2223810344533744705444),
            IntegrationPointType(-0.5255324099163289858177, 0.313706645877887287338),
            IntegrationPointType(-0.1834346424956498049395, 0.3626837833783619829652),
            IntegrationPointType( 0.1834346424956498049395, 0.3626837833783619829652),
            IntegrationPointType( 0.5255324099163289858177, 0.313706645877887287338),
            IntegrationPointType( 0.7966664774136267395916, 0.2223810344533744705444),
            IntegrationPointType( 0.9602898564975362316836, 0.1012285362903762591525)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 8 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints8



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints9
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 9> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 9;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-0.9681602395076260898356, 0.0812743883615744119719),
            IntegrationPointType(-0.8360311073266357942994, 0.1806481606948574040585),
            IntegrationPointType(-0.6133714327005903973087, 0.2606106964029354623187),
            IntegrationPointType(-0.3242534234038089290385, 0.312347077040002840069),
            IntegrationPointType(0, 0.330239355001259763165),
            IntegrationPointType( 0.3242534234038089290385, 0.312347077040002840069),
            IntegrationPointType( 0.6133714327005903973087, 0.2606106964029354623187),
            IntegrationPointType( 0.8360311073266357942994, 0.1806481606948574040585),
            IntegrationPointType( 0.9681602395076260898356, 0.0812743883615744119719)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 9 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints9



class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints10
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 1;

    typedef IntegrationPoint<1> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 10> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 10;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType(-0.973906528517171720078, 0.0666713443086881375936),
            IntegrationPointType(-0.8650633666889845107321, 0.149451349150580593146),
            IntegrationPointType(-0.6794095682990244062343, 0.219086362515982043996),
            IntegrationPointType(-0.4333953941292471907993, 0.2692667193099963550912),
            IntegrationPointType(-0.1488743389816312108848, 0.2955242247147528701739),
            IntegrationPointType( 0.1488743389816312108848, 0.2955242247147528701739),
            IntegrationPointType( 0.4333953941292471907993, 0.2692667193099963550912),
            IntegrationPointType( 0.6794095682990244062343, 0.219086362515982043996),
            IntegrationPointType( 0.8650633666889845107321, 0.149451349150580593146),
            IntegrationPointType( 0.973906528517171720078, 0.0666713443086881375936)
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Legendre quadrature 10 ";
        return buffer.str();
    }
}; // Class LineGaussLegendreIntegrationPoints10

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

template<int TDegree>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints;

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<1> : public LineGaussLegendreIntegrationPoints1
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<2> : public LineGaussLegendreIntegrationPoints2
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<3> : public LineGaussLegendreIntegrationPoints3
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<4> : public LineGaussLegendreIntegrationPoints4
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<5> : public LineGaussLegendreIntegrationPoints5
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<6> : public LineGaussLegendreIntegrationPoints6
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<7> : public LineGaussLegendreIntegrationPoints7
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<8> : public LineGaussLegendreIntegrationPoints8
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<9> : public LineGaussLegendreIntegrationPoints9
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLegendreIntegrationPoints<10> : public LineGaussLegendreIntegrationPoints10
{};

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
