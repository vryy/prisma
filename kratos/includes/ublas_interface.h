//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//


#if !defined(KRATOS_UBLAS_INTERFACE_H_INCLUDED )
#define  KRATOS_UBLAS_INTERFACE_H_INCLUDED


// System includes
#include <complex>


// External includes
#include <boost/version.hpp>
#if BOOST_VERSION / 100 % 1000 > 60
#include <boost/serialization/array_wrapper.hpp>
#endif
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/hermitian.hpp>
#include <boost/numeric/ublas/banded.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/lu.hpp>

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/operation_sparse.hpp>

// Project includes
#include "define.h"


namespace Kratos
{

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

#ifdef KRATOS_USE_BOOST_UBLAS_FOR_LINEAR_ALGEBRA

    /// types for scalar linear algebra

    template <typename TDataType> using DenseMatrix = boost::numeric::ublas::matrix<TDataType>;
    template <typename TDataType> using DenseVector = boost::numeric::ublas::vector<TDataType>;

    template <typename TDataType, KRATOS_SIZE_TYPE TSize1, KRATOS_SIZE_TYPE TSize2> using BoundedMatrix = boost::numeric::ublas::bounded_matrix<TDataType, TSize1, TSize2>;
    template <typename TDataType, KRATOS_SIZE_TYPE TSize> using BoundedVector = boost::numeric::ublas::bounded_vector<TDataType, TSize>;

    typedef boost::numeric::ublas::vector<KRATOS_DOUBLE_TYPE> Vector;
    typedef boost::numeric::ublas::unit_vector<KRATOS_DOUBLE_TYPE> UnitVector;
    typedef boost::numeric::ublas::zero_vector<KRATOS_DOUBLE_TYPE> ZeroVector;
    typedef boost::numeric::ublas::scalar_vector<KRATOS_DOUBLE_TYPE> ScalarVector;
    typedef boost::numeric::ublas::mapped_vector<KRATOS_DOUBLE_TYPE> SparseVector;

    typedef boost::numeric::ublas::compressed_vector<KRATOS_DOUBLE_TYPE> CompressedVector;
    typedef boost::numeric::ublas::coordinate_vector<KRATOS_DOUBLE_TYPE> CoordinateVector;
    typedef boost::numeric::ublas::vector_range<Vector> VectorRange;
    typedef boost::numeric::ublas::vector_slice<Vector> VectorSlice;

    typedef boost::numeric::ublas::matrix<KRATOS_DOUBLE_TYPE> Matrix;
    typedef boost::numeric::ublas::identity_matrix<KRATOS_DOUBLE_TYPE> IdentityMatrix;
    typedef boost::numeric::ublas::zero_matrix<KRATOS_DOUBLE_TYPE> ZeroMatrix;
    typedef boost::numeric::ublas::scalar_matrix<KRATOS_DOUBLE_TYPE> ScalarMatrix;
    typedef boost::numeric::ublas::triangular_matrix<KRATOS_DOUBLE_TYPE> TriangularMatrix;
    typedef boost::numeric::ublas::symmetric_matrix<KRATOS_DOUBLE_TYPE> SymmetricMatrix;
    typedef boost::numeric::ublas::hermitian_matrix<KRATOS_DOUBLE_TYPE> HermitianMatrix;
    typedef boost::numeric::ublas::banded_matrix<KRATOS_DOUBLE_TYPE> BandedMatrix;
    typedef boost::numeric::ublas::mapped_matrix<KRATOS_DOUBLE_TYPE> SparseMatrix;
    typedef boost::numeric::ublas::coordinate_matrix<KRATOS_DOUBLE_TYPE> CoordinateMatrix;
    typedef boost::numeric::ublas::compressed_matrix<KRATOS_DOUBLE_TYPE> CompressedMatrix;
    typedef boost::numeric::ublas::matrix_column<Matrix> MatrixColumn;
    typedef boost::numeric::ublas::matrix_vector_range<Matrix> MatrixVectorRange;
    typedef boost::numeric::ublas::matrix_vector_slice<Matrix> MatrixVectorSlice;
    typedef boost::numeric::ublas::matrix_range<Matrix> MatrixRange;
    typedef boost::numeric::ublas::matrix_slice<Matrix> MatrixSlice;

    template <typename TExpressionType> using MatrixRow = boost::numeric::ublas::matrix_row<TExpressionType>;

    /// types for complex linear algebra

    typedef boost::numeric::ublas::vector<KRATOS_COMPLEX_TYPE> ComplexVector;
    typedef boost::numeric::ublas::unit_vector<KRATOS_COMPLEX_TYPE> ComplexUnitVector;
    typedef boost::numeric::ublas::zero_vector<KRATOS_COMPLEX_TYPE> ComplexZeroVector;
    typedef boost::numeric::ublas::scalar_vector<KRATOS_COMPLEX_TYPE> ComplexScalarVector;
    typedef boost::numeric::ublas::mapped_vector<KRATOS_COMPLEX_TYPE> ComplexSparseVector;

    typedef boost::numeric::ublas::compressed_vector<KRATOS_COMPLEX_TYPE> ComplexCompressedVector;
    typedef boost::numeric::ublas::coordinate_vector<KRATOS_COMPLEX_TYPE> ComplexCoordinateVector;
    typedef boost::numeric::ublas::vector_range<ComplexVector> ComplexVectorRange;
    typedef boost::numeric::ublas::vector_slice<ComplexVector> ComplexVectorSlice;

    typedef boost::numeric::ublas::matrix<KRATOS_COMPLEX_TYPE> ComplexMatrix;
    typedef boost::numeric::ublas::identity_matrix<KRATOS_COMPLEX_TYPE> ComplexIdentityMatrix;
    typedef boost::numeric::ublas::zero_matrix<KRATOS_COMPLEX_TYPE> ComplexZeroMatrix;
    typedef boost::numeric::ublas::scalar_matrix<KRATOS_COMPLEX_TYPE> ComplexScalarMatrix;
    typedef boost::numeric::ublas::triangular_matrix<KRATOS_COMPLEX_TYPE> ComplexTriangularMatrix;
    typedef boost::numeric::ublas::symmetric_matrix<KRATOS_COMPLEX_TYPE> ComplexSymmetricMatrix;
    typedef boost::numeric::ublas::hermitian_matrix<KRATOS_COMPLEX_TYPE> ComplexHermitianMatrix;
    typedef boost::numeric::ublas::banded_matrix<KRATOS_COMPLEX_TYPE> ComplexBandedMatrix;
    typedef boost::numeric::ublas::mapped_matrix<KRATOS_COMPLEX_TYPE> ComplexSparseMatrix;
    typedef boost::numeric::ublas::coordinate_matrix<KRATOS_COMPLEX_TYPE> ComplexCoordinateMatrix;
    typedef boost::numeric::ublas::compressed_matrix<KRATOS_COMPLEX_TYPE> ComplexCompressedMatrix;
    typedef boost::numeric::ublas::matrix_column<ComplexMatrix> ComplexMatrixColumn;
    typedef boost::numeric::ublas::matrix_vector_range<ComplexMatrix> ComplexMatrixVectorRange;
    typedef boost::numeric::ublas::matrix_vector_slice<ComplexMatrix> ComplexMatrixVectorSlice;
    typedef boost::numeric::ublas::matrix_range<ComplexMatrix> ComplexMatrixRange;
    typedef boost::numeric::ublas::matrix_slice<ComplexMatrix> ComplexMatrixSlice;

    // declare namespace usage to avoid downstream explosion of compilation errors
    using namespace boost::numeric::ublas;

    // selector for vector and matrix type
    template<typename TDataType>
    struct MatrixVectorTypeSelector
    {
        typedef boost::numeric::ublas::vector<TDataType> VectorType;
        typedef boost::numeric::ublas::matrix<TDataType> MatrixType;
        typedef boost::numeric::ublas::zero_vector<TDataType> ZeroVectorType;
        typedef boost::numeric::ublas::zero_matrix<TDataType> ZeroMatrixType;
        typedef boost::numeric::ublas::identity_matrix<TDataType> IdentityMatrixType;
        typedef boost::numeric::ublas::compressed_matrix<TDataType> CompressedMatrixType;
    };

    // more specialization for DataTypeToString
    template<> struct DataTypeToString<boost::numeric::ublas::vector<int> > { static inline constexpr const char* Get() {return "boost::numeric::ublas::vector<int>";} };
    template<> struct DataTypeToString<boost::numeric::ublas::vector<double> > { static inline constexpr const char* Get() {return "boost::numeric::ublas::vector<double>";} };
    template<> struct DataTypeToString<boost::numeric::ublas::vector<std::complex<double> > > { static inline constexpr const char* Get() {return "boost::numeric::ublas::vector<std::complex<double>>";} };
    template<> struct DataTypeToString<boost::numeric::ublas::matrix<double> > { static inline constexpr const char* Get() {return "boost::numeric::ublas::matrix<double>";} };
    template<> struct DataTypeToString<boost::numeric::ublas::matrix<std::complex<double> > > { static inline constexpr const char* Get() {return "boost::numeric::ublas::matrix<std::complex<double>>";} };

#endif

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

#endif // KRATOS_UBLAS_INTERFACE_H_INCLUDED  defined
