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

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints1
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints1);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 1> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 1;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( 0.00 , 0.00 , 4.00 );
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 1 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints1

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints2
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints2);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 4> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 4;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -1.00/std::sqrt(3.0) , -1.00/std::sqrt(3.0), 1.00 );
        msIntegrationPoints[1] = IntegrationPointType(  1.00/std::sqrt(3.0) , -1.00/std::sqrt(3.0), 1.00 );
        msIntegrationPoints[2] = IntegrationPointType(  1.00/std::sqrt(3.0) ,  1.00/std::sqrt(3.0), 1.00 );
        msIntegrationPoints[3] = IntegrationPointType( -1.00/std::sqrt(3.0) ,  1.00/std::sqrt(3.0), 1.00 );
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 2 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints2

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints3
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints3);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 9> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()
    {
        return 9;
    }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        double a = std::sqrt(3.00/5.00);
        msIntegrationPoints[0] = IntegrationPointType( -a , -a, 25.00/81.00 );
        msIntegrationPoints[1] = IntegrationPointType(  a , -a, 25.00/81.00 );
        msIntegrationPoints[2] = IntegrationPointType( a, a, 25.00/81.00 );
        msIntegrationPoints[3] = IntegrationPointType( -a, a, 25.00/81.00 );
        msIntegrationPoints[4] = IntegrationPointType( 0.00 , -a, 40.00/81.00 );
        msIntegrationPoints[5] = IntegrationPointType( a, 0.00, 40.00/81.00 );
        msIntegrationPoints[6] = IntegrationPointType( 0.00, a, 40.00/81.00 );
        msIntegrationPoints[7] = IntegrationPointType( -a, 0.00, 40.00/81.00 );
        msIntegrationPoints[8] = IntegrationPointType( 0.00 , 0.00, 64.00/81.00 );

        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 3 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints3

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints4
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints4);
    typedef std::size_t SizeType;

    static const unsigned int Dimension = 2;

    typedef IntegrationPoint<2> IntegrationPointType;

    typedef boost::array<IntegrationPointType, 16> IntegrationPointsArrayType;

    typedef IntegrationPointType::PointType PointType;

    static SizeType IntegrationPointsNumber()    {  return 16; }

    static IntegrationPointsArrayType& IntegrationPoints()
    {
        msIntegrationPoints[0] = IntegrationPointType( -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[1] = IntegrationPointType( -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[2] = IntegrationPointType( -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[3] = IntegrationPointType( -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0));

        msIntegrationPoints[4] = IntegrationPointType( -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[5] = IntegrationPointType( -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[6] = IntegrationPointType( -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[7] = IntegrationPointType( -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0));

        msIntegrationPoints[8] = IntegrationPointType(  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[9] = IntegrationPointType(  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[10]= IntegrationPointType(  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[11]= IntegrationPointType(  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 + std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0));

        msIntegrationPoints[12]= IntegrationPointType(  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[13]= IntegrationPointType(  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), -std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[14]= IntegrationPointType(  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 - 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 + std::sqrt(5.0/6.0)/6.0));
        msIntegrationPoints[15]= IntegrationPointType(  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ),  std::sqrt( (3.0 + 2.0 * std::sqrt(6.0/5.0)) / 7.0 ), (0.5 - std::sqrt(5.0/6.0)/6.0)*(0.5 - std::sqrt(5.0/6.0)/6.0));
        return msIntegrationPoints;
    }

    std::string Info() const
    {
        std::stringstream buffer;
        buffer << "Quadrilateral Gauss-Legendre quadrature 4 ";
        return buffer.str();
    }
protected:

private:

    static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints4

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints5 {
public:
	KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints5);
	typedef std::size_t SizeType;

	static const unsigned int Dimension = 2;

	typedef IntegrationPoint<2> IntegrationPointType;

	typedef boost::array<IntegrationPointType, 25> IntegrationPointsArrayType;

	typedef IntegrationPointType::PointType PointType;

	static SizeType IntegrationPointsNumber() {return 25;}

	static IntegrationPointsArrayType& IntegrationPoints()
	{
        double a[] = {-0.906179845938664, -0.538469310105683, 0.000000000000000, 0.538469310105683, 0.906179845938664};
        double w[] = {0.236926885056189, 0.478628670499366, 0.568888888888889, 0.478628670499366, 0.236926885056189};

        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                msIntegrationPoints[5*i + j] = IntegrationPointType( a[i], a[j], w[i] * w[j]);
            
		return msIntegrationPoints;
	}

	std::string Info() const
	{
		std::stringstream buffer;
		buffer << "Quadrilateral Gauss-Legendre quadrature 5 ";
		return buffer.str();
	}
protected:

private:

	static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints5

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints6 {
public:
	KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints6);
	typedef std::size_t SizeType;

	static const unsigned int Dimension = 2;

	typedef IntegrationPoint<2> IntegrationPointType;

	typedef boost::array<IntegrationPointType, 36> IntegrationPointsArrayType;

	typedef IntegrationPointType::PointType PointType;

	static SizeType IntegrationPointsNumber() {return 36;}

	static IntegrationPointsArrayType& IntegrationPoints()
	{
        double a[] = {-0.9324695142031521, -0.6612093864662645, -0.2386191860831969, 0.2386191860831969, 0.6612093864662645, 0.9324695142031521};
        double w[] = {0.1713244923791704, 0.3607615730481386, 0.4679139345726910, 0.4679139345726910, 0.3607615730481386, 0.1713244923791704};

        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < 6; ++j)
                msIntegrationPoints[6*i + j] = IntegrationPointType( a[i], a[j], w[i] * w[j]);
            
		return msIntegrationPoints;
	}

	std::string Info() const
	{
		std::stringstream buffer;
		buffer << "Quadrilateral Gauss-Legendre quadrature 6 ";
		return buffer.str();
	}
protected:

private:

	static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints6

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints7 {
public:
	KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints7);
	typedef std::size_t SizeType;

	static const unsigned int Dimension = 2;

	typedef IntegrationPoint<2> IntegrationPointType;

	typedef boost::array<IntegrationPointType, 49> IntegrationPointsArrayType;

	typedef IntegrationPointType::PointType PointType;

	static SizeType IntegrationPointsNumber() {return 49;}

	static IntegrationPointsArrayType& IntegrationPoints()
	{
        double a[] = {-0.9491079123427585, -0.7415311855993945, -0.4058451513773972, 0.0000000000000000, 0.4058451513773972, 0.7415311855993945, 0.9491079123427585};
        double w[] = {0.1294849661688697, 0.2797053914892766, 0.3818300505051189, 0.4179591836734694, 0.3818300505051189, 0.2797053914892766, 0.1294849661688697};

        for(int i = 0; i < 7; ++i)
            for(int j = 0; j < 7; ++j)
                msIntegrationPoints[7*i + j] = IntegrationPointType( a[i], a[j], w[i] * w[j]);
            
		return msIntegrationPoints;
	}

	std::string Info() const
	{
		std::stringstream buffer;
		buffer << "Quadrilateral Gauss-Legendre quadrature 7 ";
		return buffer.str();
	}
protected:

private:

	static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints7

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints8 {
public:
	KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints8);
	typedef std::size_t SizeType;

	static const unsigned int Dimension = 2;

	typedef IntegrationPoint<2> IntegrationPointType;

	typedef boost::array<IntegrationPointType, 64> IntegrationPointsArrayType;

	typedef IntegrationPointType::PointType PointType;

	static SizeType IntegrationPointsNumber() {return 64;}

	static IntegrationPointsArrayType& IntegrationPoints()
	{
        double a[] = {-0.9602898564975363, -0.7966664774136267, -0.5255324099163290, -0.1834346424956498, 0.1834346424956498, 0.5255324099163290, 0.7966664774136267, 0.9602898564975363};
        double w[] = {0.1012285362903763, 0.2223810344533745, 0.3137066458778873, 0.3626837833783620, 0.3626837833783620, 0.3137066458778873, 0.2223810344533745, 0.1012285362903763};

        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j)
                msIntegrationPoints[8*i + j] = IntegrationPointType( a[i], a[j], w[i] * w[j]);
            
		return msIntegrationPoints;
	}

	std::string Info() const
	{
		std::stringstream buffer;
		buffer << "Quadrilateral Gauss-Legendre quadrature 8 ";
		return buffer.str();
	}
protected:

private:

	static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints8

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints9 {
public:
	KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints9);
	typedef std::size_t SizeType;

	static const unsigned int Dimension = 2;

	typedef IntegrationPoint<2> IntegrationPointType;

	typedef boost::array<IntegrationPointType, 81> IntegrationPointsArrayType;

	typedef IntegrationPointType::PointType PointType;

	static SizeType IntegrationPointsNumber() {return 81;}

	static IntegrationPointsArrayType& IntegrationPoints()
	{
        double a[] = {-0.9681602395076261, -0.8360311073266358, -0.6133714327005904, -0.3242534234038089, 0.0000000000000000, 0.3242534234038089, 0.6133714327005904, 0.8360311073266358, 0.9681602395076261};
        double w[] = {0.0812743883615744, 0.1806481606948574, 0.2606106964029354, 0.3123470770400029, 0.3302393550012598, 0.3123470770400029, 0.2606106964029354, 0.1806481606948574, 0.0812743883615744};

        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                msIntegrationPoints[9*i + j] = IntegrationPointType( a[i], a[j], w[i] * w[j]);
            
		return msIntegrationPoints;
	}

	std::string Info() const
	{
		std::stringstream buffer;
		buffer << "Quadrilateral Gauss-Legendre quadrature 9 ";
		return buffer.str();
	}
protected:

private:

	static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints9

class KRATOS_API(KRATOS_CORE) QuadrilateralGaussLegendreIntegrationPoints10 {
public:
	KRATOS_CLASS_POINTER_DEFINITION(QuadrilateralGaussLegendreIntegrationPoints10);
	typedef std::size_t SizeType;

	static const unsigned int Dimension = 2;

	typedef IntegrationPoint<2> IntegrationPointType;

	typedef boost::array<IntegrationPointType, 100> IntegrationPointsArrayType;

	typedef IntegrationPointType::PointType PointType;

	static SizeType IntegrationPointsNumber() {return 100;}

	static IntegrationPointsArrayType& IntegrationPoints()
	{
        double a[] = {-0.9739065285171717, -0.8650633666889845, -0.6794095682990244, -0.4333953941292472, -0.1488743389816312, 0.1488743389816312, 0.4333953941292472, 0.6794095682990244, 0.8650633666889845, 0.9739065285171717};
        double w[] = {0.0666713443086881, 0.1494513491505806, 0.2190863625159820, 0.2692667193099963, 0.2955242247147529, 0.2955242247147529, 0.2692667193099963, 0.2190863625159820, 0.1494513491505806, 0.0666713443086881};

        for(int i = 0; i < 10; ++i)
            for(int j = 0; j < 10; ++j)
                msIntegrationPoints[10*i + j] = IntegrationPointType( a[i], a[j], w[i] * w[j]);
            
		return msIntegrationPoints;
	}

	std::string Info() const
	{
		std::stringstream buffer;
		buffer << "Quadrilateral Gauss-Legendre quadrature 10 ";
		return buffer.str();
	}
protected:

private:

	static IntegrationPointsArrayType msIntegrationPoints;

}; // Class QuadrilateralGaussLegendreIntegrationPoints10

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}


}  // namespace Kratos.

#endif // KRATOS_QUADRILATERAL_GAUSS_LEGENDRE_INTEGRATION_POINTS_H_INCLUDED  defined 


