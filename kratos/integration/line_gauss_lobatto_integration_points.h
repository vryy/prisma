//
//   Project Name:        Kratos
//   Last Modified by:    $Author :    JMCarbonell $
//   Date:                $Date:     December 2015 $
//   Revision:            $Revision:           0.0 $
//
//


#if !defined(KRATOS_LINE_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED )
#define  KRATOS_LINE_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED


// System includes

// External includes

// Project includes
#include "integration/quadrature.h"


namespace Kratos
{
class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints1
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(0.00, 2.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Lobatto quadrature 1 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

};


class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints2
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-1.00, 1.00);
        msIntegrationPoints[1] = IntegrationPointType( 1.00, 1.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Lobatto quadrature 2 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

};


class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints3
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-1.00, 1.00 / 3.00);
        msIntegrationPoints[1] = IntegrationPointType( 0.00, 4.00 / 3.00);
        msIntegrationPoints[2] = IntegrationPointType( 1.00, 1.00 / 3.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Lobatto quadrature 3 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLobattoIntegrationPoints3



class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints4
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-1.00, 1.00 / 6.00);
        msIntegrationPoints[1] = IntegrationPointType(-std::sqrt(5.00) / 5.00, 5.00 / 6.00);
        msIntegrationPoints[2] = IntegrationPointType( std::sqrt(5.00) / 5.00, 5.00 / 6.00);
        msIntegrationPoints[3] = IntegrationPointType( 1.00, 1.00 / 6.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Lobatto quadrature 4 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLobattoIntegrationPoints4



class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints5
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-1.00, 0.10);
        msIntegrationPoints[1] = IntegrationPointType(-std::sqrt(21.00) / 7.00, 49.00 / 90.00);
        msIntegrationPoints[2] = IntegrationPointType( 0.00, 32.00 / 45.00);
        msIntegrationPoints[3] = IntegrationPointType( std::sqrt(21.00) / 7.00, 49.00 / 90.00);
        msIntegrationPoints[4] = IntegrationPointType( 1.00, 0.10);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Lobatto quadrature 5 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLobattoIntegrationPoints4



class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints6
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

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType(-1.00, 1.00 / 15.00);
        msIntegrationPoints[1] = IntegrationPointType(-std::sqrt((7.00+2.00*std::sqrt(7)) / 21.00), (14.00-std::sqrt(7)) / 30.00);
        msIntegrationPoints[2] = IntegrationPointType(-std::sqrt((7.00-2.00*std::sqrt(7)) / 21.00), (14.00+std::sqrt(7)) / 30.00);
        msIntegrationPoints[3] = IntegrationPointType( std::sqrt((7.00-2.00*std::sqrt(7)) / 21.00), (14.00+std::sqrt(7)) / 30.00);
        msIntegrationPoints[4] = IntegrationPointType( std::sqrt((7.00+2.00*std::sqrt(7)) / 21.00), (14.00-std::sqrt(7)) / 30.00);
        msIntegrationPoints[5] = IntegrationPointType( 1.00, 1.00 / 15.00);
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Line Gauss-Lobatto quadrature 6 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class LineGaussLobattoIntegrationPoints6

///@}
///@name Type Definitions
///@{

template<int TDegree>
class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints;

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints<1> : public LineGaussLobattoIntegrationPoints1
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints<2> : public LineGaussLobattoIntegrationPoints2
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints<3> : public LineGaussLobattoIntegrationPoints3
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints<4> : public LineGaussLobattoIntegrationPoints4
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints<5> : public LineGaussLobattoIntegrationPoints5
{};

template<>
class KRATOS_API(KRATOS_CORE) LineGaussLobattoIntegrationPoints<6> : public LineGaussLobattoIntegrationPoints6
{};

///@}
///@name Input and output
///@{


///@}


}  // namespace Kratos.

#endif // KRATOS_LINE_GAUSS_LOBATTO_INTEGRATION_POINTS_H_INCLUDED  defined


