/*
see kratos/LICENSE.txt
*/


/* *********************************************************
*
*   Last Modified by:    $Author: Giang Bui-Hoang $
*   Date:                $Date: 1 Aug 17 $
*   Revision:            $Revision: 1.0 $
*
* ***********************************************************/

#if !defined(KRATOS_AD_UTILS )
#define  KRATOS_AD_UTILS

#ifdef KRATOS_USE_ADOL_C
#include <adolc/adtl.h>     // Tapeless double
#endif

namespace Kratos
{

template<typename TDataType>
inline double AD_Helper_GetValue(const TDataType& v) {return v.val();}

template<>
inline double AD_Helper_GetValue<double>(const double& v) {return v;}

#ifdef KRATOS_USE_ADOL_C
template<>
inline double AD_Helper_GetValue<adtl::adouble>(const adtl::adouble& v) {return v.getValue();}
#endif

template<typename TDataType>
inline double AD_Helper_GetADValue(const TDataType& v, const unsigned int index) {return v.dx(index);}

template<>
inline double AD_Helper_GetADValue<double>(const double& v, const unsigned int index) {return 0.0;}

#ifdef KRATOS_USE_ADOL_C
template<>
inline double AD_Helper_GetADValue<adtl::adouble>(const adtl::adouble& v, const unsigned int index) {return v.getADValue(index);}
#endif

struct AD_Helper_Base
{
    template<typename TDataType>
    static inline void Resize(std::vector<TDataType>& v, const std::size_t n)
    {
        v.resize(n);
    }

    template<typename TDataType>
    static inline void Resize(std::vector<std::vector<TDataType> >& v, const std::size_t n1, const std::size_t n2)
    {
        v.resize(n1);
        for (std::size_t i = 0; i < n1; ++i)
            v[i].resize(n2);
    }

    template<typename TDataType>
    static inline void Resize(std::vector<std::vector<std::vector<TDataType> > >& v, const std::size_t n1, const std::size_t n2, const std::size_t n3)
    {
        v.resize(n1);
        for (std::size_t i = 0; i < n1; ++i)
        {
            v[i].resize(n2);
            for (std::size_t j = 0; j < n2; ++j)
                v[i][j].resize(n3);
        }
    }

    template<typename TDataType>
    static inline void Clear(std::vector<TDataType>& v)
    {
        for (std::size_t i = 0; i < v.size(); ++i)
            v[i] = 0.0;
    }

    template<typename TDataType>
    static inline void Clear(std::vector<std::vector<TDataType> >& v)
    {
        for (std::size_t i = 0; i < v.size(); ++i)
            for (std::size_t j = 0; j < v[i].size(); ++j)
                v[i][j] = 0.0;
    }

    template<typename TDataType>
    static inline void Clear(std::vector<std::vector<std::vector<TDataType> > >& v)
    {
        for (std::size_t i = 0; i < v.size(); ++i)
            for (std::size_t j = 0; j < v[i].size(); ++j)
                for (std::size_t k = 0; k < v[i][j].size(); ++k)
                    v[i][j][k] = 0.0;
    }
};

template<typename TDataType>
struct AD_Helper : public AD_Helper_Base
{
    static inline void SetNumberOfADVariables(int ndirs) {/* DO NOTHING */}
    static inline double GetValue(const TDataType& v) {return AD_Helper_GetValue(v);}
    static inline void SetADValue(TDataType& v, const int& index, const unsigned int ndirs) { v.diff(index, ndirs); }
    static inline double GetADValue(const TDataType& v, const unsigned int index) {return AD_Helper_GetADValue(v, index);}
};

template<>
struct AD_Helper<double> : public AD_Helper_Base
{
    static inline void SetNumberOfADVariables(int ndirs) {/* DO NOTHING */}
    static inline double GetValue(const double& v) {return AD_Helper_GetValue(v);}
    static inline void SetADValue(double& v, const unsigned int index, const unsigned int ndirs) {/* DO NOTHING */}
    static inline double GetADValue(const double& v, const unsigned int index) {return 0.0;}
};

#ifdef KRATOS_USE_ADOL_C
template<>
struct AD_Helper<adtl::adouble> : public AD_Helper_Base
{
    static inline void SetNumberOfADVariables(int ndirs) {adtl::setNumDir(ndirs);}
    static inline double GetValue(const adtl::adouble& v) {return AD_Helper_GetValue(v);}
    static inline void SetADValue(adtl::adouble& v, const int& index, const unsigned int ndirs) { v.setADValue(index, 1.0); }
    static inline double GetADValue(const adtl::adouble& v, const unsigned int index) {return AD_Helper_GetADValue(v, index);}
};
#endif

/**
 * Defines several utility functions for operation with AD tensor
 */
template<std::size_t rank, std::size_t dim, typename TDataType>
class AD_Utils
{
public:
    /// Zero out an arbitrary first order tensor/1D array
    template<typename TTensorType>
    static inline void Zero( TTensorType& A, const std::size_t& size1 )
    {
        for(unsigned int i = 0; i < size1; ++i)
            A[i] = 0.0;
    }

    /// Zero out an arbitrary second order tensor/2D array
    template<typename TTensorType>
    static inline void Zero( TTensorType& A, const std::size_t& size1, const std::size_t& size2 )
    {
        for(unsigned int i = 0; i < size1; ++i)
            for(unsigned int j = 0; j < size2; ++j)
                A[i][j] = 0.0;
    }

    /// Zero out an arbitrary third order tensor/3D array
    template<typename TTensorType>
    static inline void Zero( TTensorType& A, const std::size_t& size1, const std::size_t& size2, const std::size_t& size3 )
    {
        for(unsigned int i = 0; i < size1; ++i)
            for(unsigned int j = 0; j < size2; ++j)
                for(unsigned int k = 0; k < size3; ++k)
                    A[i][j][k] = 0.0;
    }

    /// Zero out an arbitrary fourth order tensor
    template<typename TTensorType>
    static inline void Zero( TTensorType& A, const std::size_t& size1, const std::size_t& size2, const std::size_t& size3, const std::size_t& size4 )
    {
        for(unsigned int i = 0; i < size1; ++i)
            for(unsigned int j = 0; j < size2; ++j)
                for(unsigned int k = 0; k < size3; ++k)
                    for(unsigned int l = 0; l < size4; ++l)
                        A[i][j][k][l] = 0.0;
    }
}; /* Class AD_Utils */


template<std::size_t dim, typename TDataType>
class AD_Utils<1, dim, TDataType>
{
public:
    /// Assign A = B
    template<typename TTensorType>
    static inline void Assign( TTensorType& A, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i] = B[i];
    }

    /// Assign A = alpha*B
    template<typename TTensorType, typename TScalarType>
    static inline void Assign( TTensorType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i] = alpha * B[i];
    }

    /// Assign A = alpha*B
    template<typename TTensorType>
    static inline void Assign( TTensorType& A, const TDataType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i] = alpha * B[i];
    }

    /// Assign A = alpha*B
    template<typename TTensorType, typename TVectorType>
    static inline void Assign( TTensorType& A, const TDataType& alpha, const TVectorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i] = alpha * B(i);
    }

    /// Assign A = alpha*B
    template<typename TTensorType, typename TScalarType, typename TVectorType>
    static inline void Assign( TVectorType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A(i) = alpha * AD_Helper_GetValue(B[i]);
    }

    /// Add A += alpha*B
    template<typename TTensorType, typename TScalarType>
    static inline void Add( TTensorType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i] += alpha * B[i];
    }

    /// Add A += alpha*B
    template<typename TTensorType>
    static inline void Add( TTensorType& A, const TDataType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i] += alpha * B[i];
    }

    /// Add A += alpha*B
    template<typename TTensorType, typename TVectorType, typename TScalarType>
    static inline void Add( TVectorType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A(i) += alpha * AD_Helper_GetValue(B[i]);
    }

    /// Add A += alpha*B^T
    template<typename TTensorType, typename TScalarType>
    static inline void TransposeAdd( TTensorType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i] += alpha * B[i];
    }

    /// Zero out the first order tensor
    template<typename TTensorType>
    static inline void Zero( TTensorType& A )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i] = 0.0;
    }

    /// Compute the inner_prod of two first order tensor
    template<typename TTensorType>
    static inline TDataType inner_prod( const TTensorType& A, const TTensorType& B )
    {
        TDataType val = 0.0;
        for(unsigned int i = 0; i < dim; ++i)
            val += A[i] * B[i];
        return val;
    }

    /// Compute the inner_prod of two first order tensor
    template<typename TTensorType1, typename TTensorType2>
    static inline TDataType inner_prod( const TTensorType1& A, const TTensorType2& B )
    {
        TDataType val = 0.0;
        for(unsigned int i = 0; i < dim; ++i)
            val += A[i] * B[i];
        return val;
    }

    /// Compute the two-norm of first order tensor
    template<typename TTensorType>
    static inline TDataType norm_2( const TTensorType& A )
    {
        return sqrt(inner_prod(A, A));
    }

    /// Normalize a first order tensor
    template<typename TTensorType>
    static inline void Normalize(TTensorType& c)
    {
        TDataType normc = norm_2(c);
        for(unsigned int i = 0; i < dim; ++i)
            c[i] = c[i]/normc;
    }

    /// Compute the cross product of two first order tensor of dimension 3
    template<typename TTensorType>
    static inline void CrossProduct(TTensorType& c, const TTensorType& a, const TTensorType& b)
    {
        if (dim == 3)
        {
            c[0] = a[1]*b[2] - a[2]*b[1];
            c[1] = a[2]*b[0] - a[0]*b[2];
            c[2] = a[0]*b[1] - a[1]*b[0];
        }
        else
            std::cout << __FUNCTION__ <<  ": Invalid dimension" << std::endl;
    }

    /// Print the first order tensor
    template<typename TTensorType>
    static inline void Print( std::ostream& rOStream, TTensorType& v )
    {
        rOStream << "(";
        for(unsigned int i = 0; i < dim; ++i)
            rOStream << " " << v[i];
        rOStream << ")";
    }

    /// Print the first order tensor
    template<typename TTensorType>
    static inline void PrintValue( std::ostream& rOStream, TTensorType& v )
    {
        rOStream << "(";
        for(unsigned int i = 0; i < dim; ++i)
            rOStream << " " << AD_Helper_GetValue(v[i]);
        rOStream << ")";
    }
};

template<std::size_t dim, typename TDataType>
class AD_Utils<2, dim, TDataType>
{
public:
    /// Assign A = B
    template<typename TTensorType>
    static inline void Assign( TTensorType& A, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] = B[i][j];
    }

    /// Assign A = B
    template<typename TTensorType, typename TMatrixType>
    static inline void Assign( TTensorType& A, const TMatrixType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] = B(i, j);
    }

    /// Assign A = alpha*B
    template<typename TTensorType, typename TScalarType>
    static inline void Assign( TTensorType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] = alpha * B[i][j];
    }

    /// Assign A = alpha*B
    template<typename TTensorType>
    static inline void Assign( TTensorType& A, const TDataType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] = alpha * B[i][j];
    }

    /// Assign A = alpha*B
    template<typename TTensorType, typename TMatrixType>
    static inline void Assign( TTensorType& A, const TDataType& alpha, const TMatrixType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] = alpha * B(i, j);
    }

    /// Assign A = alpha*B
    template<typename TTensorType, typename TScalarType, typename TMatrixType>
    static inline void Assign( TMatrixType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A(i, j) = alpha * AD_Helper_GetValue(B[i][j]);
    }

    /// Add A += alpha*B
    template<typename TTensorType, typename TScalarType>
    static inline void Add( TTensorType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] += alpha * B[i][j];
    }

    /// Add A += alpha*B
    template<typename TTensorType>
    static inline void Add( TTensorType& A, const TDataType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] += alpha * B[i][j];
    }

    /// Add A += alpha*B
    template<typename TTensorType, typename TScalarType, typename TMatrixType>
    static inline void Add( TMatrixType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A(i, j) += alpha * AD_Helper_GetValue(B[i][j]);
    }

    /// Add A += alpha*B^T
    template<typename TTensorType, typename TScalarType>
    static inline void TransposeAdd( TTensorType& A, const TScalarType& alpha, const TTensorType& B )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] += alpha * B[j][i];
    }

    /// Add to the diagonal
    template<typename TTensorType>
    static inline void AddDiagonal( TTensorType& A, const TDataType& alpha )
    {
        for(unsigned int i = 0; i < dim; ++i)
            A[i][i] += alpha;
    }

    /// Zero out the second order tensor
    template<typename TTensorType>
    static inline void Zero( TTensorType& A )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                A[i][j] = 0.0;
    }

    /// Extract the deviatoric tensor and the volumetric value (trace)
    template<typename TTensorType>
    static inline void ExtractVolumetricDeviatoricTensor( const TTensorType& C, TTensorType& dev, TDataType& vol )
    {
        vol = 0.0;
        for(unsigned int i = 0; i < dim; ++i)
            vol += C[i][i];
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                dev[i][j] = C[i][j];
        for(unsigned int i = 0; i < dim; ++i)
            dev[i][i] -= vol / dim;
    }

    /// Compute the inner_prod of two second order tensor
    template<typename TTensorType>
    static inline TDataType inner_prod( const TTensorType& A, const TTensorType& B )
    {
        TDataType val = 0.0;
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                val += A[i][j] * B[i][j];
        return val;
    }

    /// Compute the Frobenius norm of second order tensor
    template<typename TTensorType>
    static inline TDataType norm_frobenius( const TTensorType& A )
    {
        TDataType val = 0.0;
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                val += A[i][j] * A[i][j];
        return sqrt(val);
    }

    /// Print the second order tensor
    template<typename TTensorType>
    static inline void Print( std::ostream& rOStream, TTensorType& v )
    {
        rOStream << "(";
        for(unsigned int i = 0; i < dim; ++i)
        {
            rOStream << ", (";
            for(unsigned int j = 0; j < dim; ++j)
                rOStream << " " << v[i][j];
            rOStream << ")";
        }
        rOStream << ")";
    }

    /// Print the second order tensor
    template<typename TTensorType>
    static inline void PrintValue( std::ostream& rOStream, TTensorType& v )
    {
        rOStream << "(";
        for(unsigned int i = 0; i < dim; ++i)
        {
            rOStream << ", (";
            for(unsigned int j = 0; j < dim; ++j)
                rOStream << " " << AD_Helper_GetValue(v[i][j]);
            rOStream << ")";
        }
        rOStream << ")";
    }
};


template<std::size_t dim, typename TDataType>
class AD_Utils<4, dim, TDataType>
{
public:

    /// Assign De = D(A)/D(X)
    template<typename TOtherTensorType, typename TTensorType>
    static inline void Assign( TOtherTensorType& De, const TTensorType& A )
    {
        for(unsigned int i = 0; i < dim; ++i)
            for(unsigned int j = 0; j < dim; ++j)
                for(unsigned int k = 0; k < dim; ++k)
                    for(unsigned int l = 0; l < dim; ++l)
                        De[i][j][k][l] = AD_Helper_GetADValue(A[i][j], 3*k + l);
    }
};


}  /* namespace Kratos.*/

#endif /* KRATOS_AD_UTILS  defined */

