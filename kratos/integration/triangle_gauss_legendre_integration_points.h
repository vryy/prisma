//
//   Project Name:        Kratos
//   Last Modified by:    $Author:   JMCarbonell $
//   Date:                $Date:   December 2015 $
//   Revision:            $Revision:         1.5 $
//
//


#if !defined(KRATOS_TRIANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED )
#define  KRATOS_TRIANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED

// System includes

// External includes

// Project includes
#include "integration/quadrature.h"

namespace Kratos
{

class KRATOS_API(KRATOS_CORE) TriangleGaussLegendreIntegrationPoints1
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 1> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static constexpr SizeType IntegrationPointsNumber()
    {
        return 1;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( 1.00 / 3.00 , 1.00 / 3.00 , 1.00 / 2.00 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Triangle Gauss-Legendre quadrature 1 ";
        return buffer.str();
    }
}; // Class TriangleGaussLegendreIntegrationPoints1


class KRATOS_API(KRATOS_CORE) TriangleGaussLegendreIntegrationPoints2
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 3> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static constexpr SizeType IntegrationPointsNumber()
    {
        return 3;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( 1.00 / 6.00 , 1.00 / 6.00 , 1.00 / 6.00 ),
            IntegrationPointType( 2.00 / 3.00 , 1.00 / 6.00 , 1.00 / 6.00 ),
            IntegrationPointType( 1.00 / 6.00 , 2.00 / 3.00 , 1.00 / 6.00 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Triangle Gauss-Legendre quadrature 2 ";
        return buffer.str();
    }
}; // Class TriangleGaussLegendreIntegrationPoints2


class KRATOS_API(KRATOS_CORE) TriangleGaussLegendreIntegrationPoints3
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 4> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static constexpr SizeType IntegrationPointsNumber()
    {
        return 4;
    }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( 1.00 / 5.00 , 1.00 / 5.00 , 25.00 / 96.00 ),
            IntegrationPointType( 3.00 / 5.00 , 1.00 / 5.00 , 25.00 / 96.00 ),
            IntegrationPointType( 1.00 / 5.00 , 3.00 / 5.00 , 25.00 / 96.00 ),
            IntegrationPointType( 1.00 / 3.00 , 1.00 / 3.00 , -27.00 / 96.00 )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Triangle Gauss-Legendre quadrature 3 ";
        return buffer.str();
    }
}; // Class TriangleGaussLegendreIntegrationPoints2


class KRATOS_API(KRATOS_CORE) TriangleGaussLegendreIntegrationPoints4
{
public:
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 6> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static constexpr SizeType IntegrationPointsNumber()    {  return 6; }

    static const IntegrationPointsArrayType& IntegrationPoints()
    {
        // Reference:
        // +    https://people.sc.fsu.edu/~jburkardt/datasets/quadrature_rules_tri/strang5_x.txt
        // +    https://people.sc.fsu.edu/~jburkardt/datasets/quadrature_rules_tri/strang5_w.txt
        constexpr double wa = 0.109951743655322;
        constexpr double wb = 0.223381589678011;
        constexpr double Na1 = 0.816847572980459;
        constexpr double Nb1 = 0.108103018168070;
        constexpr double Na2 = 0.091576213509771;
        constexpr double Nb2 = 0.445948490915965;

        static const IntegrationPointsArrayType s_integration_points{{
            IntegrationPointType( Na2, Na2, wa ),
            IntegrationPointType( Na1, Na2, wa ),
            IntegrationPointType( Na2, Na1, wa ),
            IntegrationPointType( Nb2, Nb2, wb ),
            IntegrationPointType( Nb1, Nb2, wb ),
            IntegrationPointType( Nb2, Nb1, wb )
        }};
        return s_integration_points;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Triangle Gauss-Legendre quadrature 4 ";
        return buffer.str();
    }
}; // Class TriangleGaussLegendreIntegrationPoints4


///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}


}  // namespace Kratos.

#endif // KRATOS_TRIANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED  defined 
