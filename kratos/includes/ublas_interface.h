//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//


#if !defined(KRATOS_UBLAS_INTERFACE_H_INCLUDED )
#define  KRATOS_UBLAS_INTERFACE_H_INCLUDED


// System includes


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


namespace Kratos
{

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{
    using namespace boost::numeric::ublas;

    template <typename TDataType> using DenseMatrix = boost::numeric::ublas::matrix<TDataType>;
    template <typename TDataType> using DenseVector = boost::numeric::ublas::vector<TDataType>;

    template <typename TDataType, std::size_t TSize1, std::size_t TSize2> using BoundedMatrix = boost::numeric::ublas::bounded_matrix<TDataType, TSize1, TSize2>;
    template <typename TDataType, std::size_t TSize> using BoundedVector = boost::numeric::ublas::bounded_vector<TDataType, TSize>;


    typedef boost::numeric::ublas::vector<KRATOS_DOUBLE_TYPE> Vector;
    typedef unit_vector<KRATOS_DOUBLE_TYPE> UnitVector;
    typedef zero_vector<KRATOS_DOUBLE_TYPE> ZeroVector;
    typedef scalar_vector<KRATOS_DOUBLE_TYPE> ScalarVector;
    //typedef sparse_vector<KRATOS_DOUBLE_TYPE> SparseVector;
    typedef mapped_vector<KRATOS_DOUBLE_TYPE> SparseVector;

    typedef compressed_vector<KRATOS_DOUBLE_TYPE> CompressedVector;
    typedef coordinate_vector<KRATOS_DOUBLE_TYPE> CoordinateVector;
    typedef vector_range<Vector> VectorRange;
    typedef vector_slice<Vector> VectorSlice;

    typedef matrix<KRATOS_DOUBLE_TYPE> Matrix;
    typedef identity_matrix<KRATOS_DOUBLE_TYPE> IdentityMatrix;
    typedef zero_matrix<KRATOS_DOUBLE_TYPE> ZeroMatrix;
    typedef scalar_matrix<KRATOS_DOUBLE_TYPE> ScalarMatrix;
    typedef triangular_matrix<KRATOS_DOUBLE_TYPE> TriangularMatrix;
    typedef symmetric_matrix<KRATOS_DOUBLE_TYPE> SymmetricMatrix;
    typedef hermitian_matrix<KRATOS_DOUBLE_TYPE> HermitianMatrix;
    typedef banded_matrix<KRATOS_DOUBLE_TYPE> BandedMatrix;
    //typedef sparse_matrix<KRATOS_DOUBLE_TYPE> SparseMatrix;
    typedef mapped_matrix<KRATOS_DOUBLE_TYPE> SparseMatrix;
    typedef coordinate_matrix<KRATOS_DOUBLE_TYPE> CoordinateMatrix;
    typedef matrix_column<Matrix> MatrixColumn;
    typedef matrix_vector_range<Matrix> MatrixVectorRange;
    typedef matrix_vector_slice<Matrix> MatrixVectorSlice;
    typedef matrix_range<Matrix> MatrixRange;
    typedef matrix_slice<Matrix> MatrixSlice;

    template <typename TExpressionType> using MatrixRow = matrix_row<TExpressionType>;

    typedef boost::numeric::ublas::compressed_matrix<KRATOS_DOUBLE_TYPE> CompressedMatrix;

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

}  // namespace Kratos.

#endif // KRATOS_UBLAS_INTERFACE_H_INCLUDED  defined
