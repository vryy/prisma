//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//


#if !defined(KRATOS_EIGEN_INTERFACE_H_INCLUDED )
#define  KRATOS_EIGEN_INTERFACE_H_INCLUDED


// System includes
#include <algorithm>
#include <complex>
#include <cassert>


// External includes
#include <Eigen/Dense>
#include <Eigen/Sparse>


// Project includes
#include "define.h"

#ifdef KRATOS_USE_EIGEN_FOR_LINEAR_ALGEBRA

// // forward declaration
// namespace Kratos
// {
//     template<typename T, std::size_t N>
//     class array_1d;
// }

namespace Eigen
{

    /// Extends Eigen matrix to support extra functions
    template<typename TDataType>
    class MatrixXt : public Eigen::Matrix<TDataType, Eigen::Dynamic, Eigen::Dynamic>
    {
    public:
        using Base = Eigen::Matrix<TDataType, Eigen::Dynamic, Eigen::Dynamic>;
        using Base::Base; // inherit constructors

        // boost::ublas compatible typedefs
        using value_type = TDataType;
        using reference = TDataType&;
        using const_reference = const TDataType&;
        using pointer = TDataType*;
        using const_pointer = const TDataType*;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using self_type = MatrixXt<TDataType>;
        using closure_type = self_type&;
        using const_closure_type = const self_type&;
        // using storage_category = boost::numeric::ublas::dense_tag;

        // uBLAS iterators (dummy, satisfy template)
        using iterator1 = int*;
        using iterator2 = int*;
        using const_iterator1 = const int*;
        using const_iterator2 = const int*;

        // orientation_category for uBLAS
        // using orientation_category = boost::numeric::ublas::row_major_tag;

        // copy constructor
        MatrixXt(const MatrixXt& other) = default;

        template<typename Derived>
        MatrixXt(const Eigen::MatrixBase<Derived>& expr) { *this = expr; }

        size_type size1() const { return this->rows(); }
        size_type size2() const { return this->cols(); }

        void clear() { this->setZero(); } // I do not want to do resize(0) because ublas::vector::clear() somehow does not resize

        void resize(size_type rows, size_type cols, bool preserve = true)
        {
            if (!preserve)
            {
                Base::resize(rows, cols); // just resize normally
                return;
            }

            if (this->rows() == rows && this->cols() == cols)
                return;  // nothing to do

            MatrixXt<TDataType> mat_new(rows, cols);
            auto min_rows = std::min(this->rows(), static_cast<Eigen::Index>(rows));
            auto min_cols = std::min(this->cols(), static_cast<Eigen::Index>(cols));
            if (min_rows > 0 && min_cols > 0)
                mat_new.topLeftCorner(min_rows, min_cols) = this->topLeftCorner(min_rows, min_cols);

            (*this) = std::move(mat_new);
        }

        // Arithmetic
        template<typename Derived>
        self_type& plus_assign(const Eigen::MatrixBase<Derived>& expr) { *this += expr; return *this; }
        template<typename Derived>
        self_type& minus_assign(const Eigen::MatrixBase<Derived>& expr) { *this -= expr; return *this; }

        template<typename AT>
        self_type& operator*=(const AT& val) { Base::operator*=(val); return *this; }
        template<typename AT>
        self_type& operator/=(const AT& val) { Base::operator/=(val); return *this; }

        template<typename Derived>
        self_type& assign(const Eigen::MatrixBase<Derived>& expr) { *this = expr; return *this; }

        self_type& assign_temporary(MatrixXt& tmp) { std::swap(*this,tmp); return *this; }

        // Data access
        Base& data() { return *this; }
        const Base& data() const { return *this; }
    };

    /// Wrapper class for symmetric matrix using Eigen
    template<typename TDataType, int StorageOrder = Eigen::RowMajor>
    class SymmetricMatrix
    {
    public:
        typedef std::size_t index_type;
        typedef std::size_t size_type;

        SymmetricMatrix(size_type n) : n_(n), data_(n, n)
        {
            data_.setZero();
        }

        TDataType& operator()(index_type i, index_type j)
        {
            assert(i < n_ && j < n_);
            if (i >= j) return data_(i, j);
            else return data_(j, i);
        }

        TDataType operator()(index_type i, index_type j) const
        {
            assert(i < n_ && j < n_);
            if (i >= j) return data_(i, j);
            else return data_(j, i);
        }

        auto selfadjointView()
        {
            return data_.template selfadjointView<Eigen::Lower>();
        }

        auto selfadjointView() const
        {
            return data_.template selfadjointView<Eigen::Lower>();
        }

        size_type rows() const {return n_;}
        size_type cols() const {return n_;}

    private:
        size_type n_;
        Eigen::Matrix<TDataType, Eigen::Dynamic, Eigen::Dynamic, StorageOrder> data_;
    };

    /// Wrapper class for identity matrix using Eigen
    template<typename TDataType>
    class IdentityMatrix
    {
    public:
        typedef std::size_t index_type;
        typedef std::size_t size_type;
        typedef TDataType Scalar; // to be compatible with Eigen matrix's Scalar

        explicit IdentityMatrix(size_type n) : n_(n) {}

        // Size access like uBLAS
        size_type rows() const { return n_; }
        size_type cols() const { return n_; }

        // Element access
        TDataType operator()(index_type i, index_type j) const
        {
            assert(i >= 0 && i < n_ && j >= 0 && j < n_);
            return (i == j) ? TDataType(1) : TDataType(0);
        }

        // Multiply with Eigen vector (optimized)
        template<typename Derived>
        Eigen::Matrix<typename Derived::Scalar, Derived::RowsAtCompileTime, Derived::ColsAtCompileTime>
        operator*(const Eigen::MatrixBase<Derived>& vec) const
        {
            assert(vec.rows() == n_);
            return vec; // Identity times vector = vector
        }

    private:
        size_type n_;
    };

    /// Wrapper class for zero matrix using Eigen
    template<typename TDataType>
    class ZeroMatrix
    {
    public:
        typedef std::size_t index_type;
        typedef std::size_t size_type;
        typedef TDataType Scalar; // to be compatible with Eigen matrix's Scalar

        explicit ZeroMatrix(size_type rows, size_type cols) : rows_(rows), cols_(cols) {}

        // Size access like uBLAS
        size_type rows() const { return rows_; }
        size_type cols() const { return cols_; }

        // Element access
        TDataType operator()(index_type i, index_type j) const
        {
            assert(i >= 0 && i < rows_ && j >= 0 && j < cols_);
            return TDataType(0);
        }

        // Multiply with Eigen vector (optimized)
        template<typename Derived>
        Eigen::Matrix<typename Derived::Scalar, Eigen::Dynamic, 1>
        operator*(const Eigen::MatrixBase<Derived>& vec) const
        {
            assert(vec.rows() == cols_);
            return Eigen::Matrix<typename Derived::Scalar, Eigen::Dynamic, 1>::Zero(rows_);
        }

        // Multiply with Eigen matrix (optimized)
        template<typename Derived>
        Eigen::Matrix<typename Derived::Scalar, Eigen::Dynamic, Eigen::Dynamic>
        operator*(const Eigen::MatrixBase<Derived>& mat) const
        {
            assert(mat.rows() == cols_);
            return Eigen::Matrix<typename Derived::Scalar, Eigen::Dynamic, Eigen::Dynamic>::Zero(rows_, mat.cols());
        }

        // Conversion operator to be compatiable with Eigen's matrix
        operator MatrixXt<TDataType>() const
        {
            return MatrixXt<TDataType>::Zero(rows_, cols_);
        }

    private:
        size_type rows_, cols_;
    };

    /// Wrapper class for scalar matrix
    template <typename TDataType>
    class ScalarMatrix
    {
    public:
        using Index = Eigen::Index;
        using DenseType = Eigen::Matrix<TDataType, Eigen::Dynamic, Eigen::Dynamic>;
        using DenseType2 = Eigen::MatrixXt<TDataType>;

        ScalarMatrix(Index rows, Index cols, TDataType value)
            : rows_(rows), cols_(cols), value_(value) {}

        // Dimensions
        Index rows() const { return rows_; }
        Index cols() const { return cols_; }

        // Access element
        TDataType operator()(Index i, Index j) const {
            if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
                throw std::out_of_range("Index out of range");
            return value_;
        }

        // Convert to dense matrix
        DenseType toDense() const {
            return DenseType::Constant(rows_, cols_, value_);
        }

        // **Implicit conversion to Eigen dense matrix**
        operator DenseType() const {
            return toDense();
        }

        // **Implicit conversion to Eigen dense matrix**
        operator DenseType2() const {
            return toDense();
        }

        // Multiply by Eigen matrix
        template <typename Derived>
        auto operator*(const Eigen::MatrixBase<Derived>& mat) const {
            if (mat.rows() != cols_) throw std::invalid_argument("Size mismatch");
            return Eigen::Matrix<TDataType, Eigen::Dynamic, Eigen::Dynamic>::Constant(rows_, mat.cols(), value_ * mat.colwise().sum().array());
        }

    private:
        Index rows_, cols_;
        TDataType value_;
    };

    /// Base for all wrapper classes for zero vector using Eigen
    template<typename TDataType>
    class EigenVector
    {
    public:
        using Index = Eigen::Index;

        using index_type = Index;
        using value_type = TDataType;
        using reference = TDataType&;
        using const_reference = const TDataType&;
        using pointer = TDataType*;
        using const_pointer = const TDataType*;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        typedef TDataType Scalar; // to be compatible with Eigen matrix's Scalar

        explicit EigenVector(size_type rows) : rows_(rows) {}

        // Size access like uBLAS
        size_type rows() const { return rows_; }
        size_type size() const { return rows_; }

        // Element access
        virtual TDataType operator()(index_type i) const
        {
            assert(i >= 0 && i < rows_);
            return TDataType(0);
        }

        virtual TDataType operator[](index_type i) const
        {
            assert(i >= 0 && i < rows_);
            return TDataType(0);
        }

    private:
        size_type rows_;
    };

    /// Extends Eigen matrix to vector and support extra functions
    template<typename TDataType>
    class VectorXt : public Eigen::Matrix<TDataType, Eigen::Dynamic, 1>
    {
    public:
        using Base = Eigen::Matrix<TDataType, Eigen::Dynamic, 1>;
        using Base::Base; // inherit constructors

        // boost::ublas compatible typedefs
        typedef TDataType value_type;
        typedef TDataType& reference;
        typedef const TDataType& const_reference;
        typedef TDataType* pointer;
        typedef const TDataType* const_pointer;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        using self_type = VectorXt<TDataType>;
        using closure_type = self_type&;
        using const_closure_type = const self_type&;

        // copy constructor
        VectorXt(const VectorXt& other) = default;

        template<typename Derived>
        VectorXt(const Eigen::MatrixBase<Derived>& expr) { *this = expr; }

        VectorXt(const EigenVector<TDataType>& u)
            : Base(u.Size())
        {
            for (int i = 0; i < u.Size(); ++i)
                (*this)(i) = u[i];
        }

        size_type size() const { return this->rows(); }
        void clear() { this->setZero(); } // I do not want to do resize(0) because ublas::vector::clear() somehow does not resize

        // Resize
        void resize(size_type n, bool preserve = true)
        {
            if(!preserve)
            {
                Base::resize(n);
            }
            else
            {
                Eigen::Matrix<TDataType, Eigen::Dynamic, 1> tmp;
                if constexpr (std::is_arithmetic_v<TDataType>) tmp = Base::Zero(n);
                Eigen::Index min_n = std::min(Eigen::Index(n), this->rows());
                if(min_n > 0)
                    tmp.topRows(min_n) = this->topRows(min_n);
                *this = std::move(tmp);
            }
        }

        // Arithmetic
        template<typename Derived>
        self_type& plus_assign(const Eigen::MatrixBase<Derived>& expr) { *this += expr; return *this; }
        template<typename Derived>
        self_type& minus_assign(const Eigen::MatrixBase<Derived>& expr) { *this -= expr; return *this; }

        template<typename AT>
        self_type& operator*=(const AT& val) { Base::operator*=(val); return *this; }
        template<typename AT>
        self_type& operator/=(const AT& val) { Base::operator/=(val); return *this; }

        self_type& operator+=(const EigenVector<TDataType>& v)
        {
            assert(v.size() == this->size());
            for (size_type i = 0; i < this->size(); ++i)
                data()[i] += v[i];
            return *this;
        }

        self_type& operator-=(const EigenVector<TDataType>& v)
        {
            assert(v.size() == this->size());
            for (size_type i = 0; i < this->size(); ++i)
                data()[i] -= v[i];
            return *this;
        }

        self_type& operator=(const EigenVector<TDataType>& v)
        {
            assert(v.size() == this->size());
            for (size_type i = 0; i < this->size(); ++i)
                data()[i] = v[i];
            return *this;
        }

        template<typename Derived>
        self_type& assign(const Eigen::MatrixBase<Derived>& expr) { *this = expr; return *this; }

        self_type& assign_temporary(VectorXt& tmp) { std::swap(*this,tmp); return *this; }

        reference insert_element (size_type i, const_reference t)
        {
            assert(i < this->size());
            return (data()[i] = t);
        }

        void erase_element (size_type i)
        {
            assert(i < this->size());
            data()[i] = value_type/*zero*/();
        }

        // Data access
        Base& data() { return *this; }
        const Base& data() const { return *this; }
    };

    /// Wrapper class for zero vector using Eigen
    template<typename TDataType>
    class ZeroVector : public EigenVector<TDataType>
    {
    public:
        using BaseType = EigenVector<TDataType>;
        using typename BaseType::index_type;
        using typename BaseType::size_type;

        struct iterator {
            index_type i;
            size_type n;
            iterator(index_type start, index_type end) : i(start), n(end) {}
            bool operator!=(const iterator& other) const { return i != other.i; }
            void operator++() { ++i; }
            TDataType operator*() const { return TDataType(0); }
        };

        explicit ZeroVector() : BaseType(0) {}
        explicit ZeroVector(size_type rows) : BaseType(rows) {}

        // Element access
        TDataType operator()(index_type i) const override
        {
            assert(i >= 0 && i < rows_);
            return TDataType(0);
        }

        TDataType operator[](index_type i) const override
        {
            assert(i >= 0 && i < rows_);
            return TDataType(0);
        }

        // Conversion operator to be compatiable with Eigen's vector
        operator VectorXt<TDataType>() const
        {
            return VectorXt<TDataType>::Zero(BaseType::size());
        }

        iterator begin() const { return iterator(0, BaseType::size()); }
        iterator end() const { return iterator(BaseType::size(), BaseType::size()); }

        // // Conversion to array_1d if needed
        // template<std::size_t N>
        // operator Kratos::array_1d<TDataType, N>() const
        // {
        //     Kratos::array_1d<TDataType, N> result;
        //     std::fill(result.data().begin(), result.data().end(), TDataType(0));
        //     return result;
        // }
    };

    /// Wrapper class for unit vector using Eigen
    template <typename TDataType>
    class UnitVector : public EigenVector<TDataType>
    {
    public:
        using BaseType = EigenVector<TDataType>;
        using typename BaseType::index_type;
        using typename BaseType::size_type;

        UnitVector(size_type size, index_type one_index = 0)
            : BaseType(size), one_index_(one_index)
        {
            if (one_index_ < 0 || one_index_ >= BaseType::size()) {
                KRATOS_ERROR << "Index of 1 is out of range";
            }
        }

        // Access element
        TDataType operator()(Index i) const override {
            assert(i >= 0 && i < BaseType::size());
            return (i == one_index_) ? TDataType(1) : TDataType(0);
        }

        TDataType operator[](Index i) const override {
            assert(i >= 0 && i < BaseType::size());
            return (i == one_index_) ? TDataType(1) : TDataType(0);
        }

        // Convert to a dense Eigen vector
        Eigen::Matrix<TDataType, Eigen::Dynamic, 1> toDense() const {
            Eigen::Matrix<TDataType, Eigen::Dynamic, 1> vec = Eigen::Matrix<TDataType, Eigen::Dynamic, 1>::Zero(BaseType::size());
            vec(one_index_) = TDataType(1);
            return vec;
        }

        // Multiply by Eigen matrix
        template <typename Derived>
        auto operator*(const Eigen::MatrixBase<Derived>& mat) const {
            return toDense().transpose() * mat;
        }

    private:
        index_type one_index_;
    };

    /// Wrapper class for scalar vector
    template <typename TDataType>
    class ScalarVector : public EigenVector<TDataType>
    {
    public:
        using BaseType = EigenVector<TDataType>;
        using typename BaseType::index_type;
        using typename BaseType::size_type;

        ScalarVector(size_type size, TDataType value)
            : BaseType(size), value_(value) {}

        // Access element
        TDataType operator()(Index i) const override {
            assert(i >= 0 && i < BaseType::size());
            return value_;
        }

        // Access element
        TDataType operator[](Index i) const override {
            assert(i >= 0 && i < BaseType::size());
            return value_;
        }

        // Convert to a dense Eigen vector
        Eigen::Matrix<TDataType, Eigen::Dynamic, 1> toDense() const {
            return Eigen::Matrix<TDataType, Eigen::Dynamic, 1>::Constant(BaseType::size(), value_);
        }

        // Multiply by Eigen matrix
        template <typename Derived>
        auto operator*(const Eigen::MatrixBase<Derived>& mat) const {
            return toDense().transpose() * mat;
        }

        // Add to an Eigen vector
        template <typename Derived>
        auto operator+(const Eigen::MatrixBase<Derived>& vec) const {
            if (vec.size() != BaseType::size()) KRATOS_ERROR << "Size mismatch";
            return vec.array() + value_;
        }

    private:
        TDataType value_;
    };

    /// Implement operator >> for Eigen matrix
    template<typename Derived>
    std::istream& operator>>(std::istream& is, Eigen::MatrixBase<Derived>& m)
    {
        for (std::size_t i = 0; i < m.rows(); ++i)
            for (std::size_t j = 0; j < m.cols(); ++j)
                is >> m(i, j);
        return is;
    }

    /// Implement operator >> for Eigen symmetric matrix
    template<typename TDataType, int StorageOrder>
    std::istream& operator>>(std::istream& is, Eigen::SymmetricMatrix<TDataType, StorageOrder>& m)
    {
        for (std::size_t i = 0; i < m.rows(); ++i)
            for (std::size_t j = i; j < m.rows(); ++j)
                is >> m(i, j);
        return is;
    }

    /// Implement operator << for Eigen symmetric matrix
    template<typename TDataType, int StorageOrder>
    std::ostream& operator<<(std::ostream& os, const Eigen::SymmetricMatrix<TDataType, StorageOrder>& m)
    {
        for (std::size_t i = 0; i < m.rows(); ++i)
            for (std::size_t j = i; j < m.rows(); ++j)
                os << m(i, j) << " ";
        return os;
    }

    template<typename TDataType>
    EigenVector<TDataType> operator+(const EigenVector<TDataType>& lhs, const EigenVector<TDataType>& rhs)
    {
        assert(lhs.size() == rhs.size());
        EigenVector<TDataType> v(lhs);
        for (std::size_t i = 0; i < lhs.size(); ++i)
            v[i] += rhs[i];
        return v;
    }

    template<typename TDataType>
    EigenVector<TDataType> operator-(const EigenVector<TDataType>& lhs, const EigenVector<TDataType>& rhs)
    {
        assert(lhs.size() == rhs.size());
        EigenVector<TDataType> v(lhs);
        for (std::size_t i = 0; i < lhs.size(); ++i)
            v[i] -= rhs[i];
        return v;
    }
} // end namespace Eigen

namespace Kratos
{

    /// Implement the proxy row() function as in Boost::ublas
    template<typename TMatrixType> auto row(TMatrixType& A, Eigen::Index i) {return A.row(i);}
    template<typename TMatrixType> auto row(const TMatrixType& A, Eigen::Index i) {return A.row(i);}

    /// Implement the proxy column() function as in Boost::ublas
    template<typename TMatrixType> auto column(TMatrixType& A, Eigen::Index i) {return A.column(i);}
    template<typename TMatrixType> auto column(const TMatrixType& A, Eigen::Index i) {return A.column(i);}

    /// Wrapper function for outer_prod
    template<typename VectorU, typename VectorV>
    auto outer_prod(const Eigen::MatrixBase<VectorU>& u, const Eigen::MatrixBase<VectorV>& v)
    {
        return u * v.transpose();
    }

    // Generic prod for two Eigen types (matrix-matrix, matrix-vector, vector-matrix)
    template<typename Lhs, typename Rhs>
    inline auto prod(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs * rhs) {
        return lhs * rhs;
    }

    /// Wrapper function for norm_2
    template<typename Derived>
    typename Derived::Scalar norm_2(const Eigen::MatrixBase<Derived>& v)
    {
        return v.norm();
    }

    /// Wrapper function for norm_frobenius
    template<typename Derived>
    typename Derived::Scalar norm_frobenius(const Eigen::MatrixBase<Derived>& v)
    {
        return v.norm();
    }

    /// Implementation for noalias that mimicks boost::ublas
    template<typename Derived>
    Eigen::MatrixBase<Derived>& noalias(Eigen::MatrixBase<Derived>& mat)
    {
        return mat;
    }

    /// Implementation for trans that mimicks boost::ublas
    template<typename T>
    inline auto trans(const T& M) -> decltype(M.transpose()) {
        return M.transpose();
    }

    /// Wrapper for inner_prod
    template<typename Derived1, typename Derived2>
    auto inner_prod(const Eigen::MatrixBase<Derived1>& v1, const Eigen::MatrixBase<Derived2>& v2)
    {
        return v1.dot(v2);
    }

    /// Wrapper for inner_prod
    template<typename TDataType>
    auto inner_prod(const Eigen::EigenVector<TDataType>& v1, const Eigen::EigenVector<TDataType>& v2)
    {
        assert(v1.size() == v2.size());
        TDataType r(0);
        for (std::size_t i = 0; i < v1.size(); ++i)
            r += v1[i]*v2[i];
        return r;
    }
} // end namespace Kratos

namespace Kratos
{

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

    /// types for scalar linear algebra

    template <typename TDataType> using DenseMatrix = Eigen::MatrixXt<TDataType>;
    template <typename TDataType> using DenseVector = Eigen::VectorXt<TDataType>;

    template <typename TDataType> using vector = Eigen::VectorXt<TDataType>;
    template <typename TDataType> using unit_vector = Eigen::UnitVector<TDataType>;
    template <typename TDataType> using zero_vector = Eigen::ZeroVector<TDataType>;
    template <typename TDataType> using scalar_vector = Eigen::ScalarVector<TDataType>;
    template <typename TDataType> using mapped_vector = Eigen::SparseVector<TDataType>;
    template <typename TDataType> using compressed_vector = Eigen::SparseVector<TDataType>;
    template <typename TDataType> using matrix = Eigen::MatrixXt<TDataType>;
    template <typename TDataType> using identity_matrix = Eigen::IdentityMatrix<TDataType>;
    template <typename TDataType> using zero_matrix = Eigen::ZeroMatrix<TDataType>;
    template <typename TDataType> using scalar_matrix = Eigen::ScalarMatrix<TDataType>;
    template <typename TDataType> using symmetric_matrix = Eigen::SymmetricMatrix<TDataType>;
    template <typename TDataType> using compressed_matrix = Eigen::SparseMatrix<TDataType>;
    template <typename TDataType> using mapped_matrix = Eigen::SparseMatrix<TDataType>;
    template <typename TDataType> using banded_matrix = Eigen::SparseMatrix<TDataType>;

    template <typename TDataType, KRATOS_SIZE_TYPE TSize1, KRATOS_SIZE_TYPE TSize2> using BoundedMatrix = Eigen::Matrix<TDataType, TSize1, TSize2>;
    template <typename TDataType, KRATOS_SIZE_TYPE TSize> using BoundedVector = Eigen::Matrix<TDataType, TSize, 1>;

    typedef Eigen::VectorXt<KRATOS_DOUBLE_TYPE> Vector;
    typedef Eigen::UnitVector<KRATOS_DOUBLE_TYPE> UnitVector;
    typedef Eigen::ZeroVector<KRATOS_DOUBLE_TYPE> ZeroVector;
    typedef Eigen::ScalarVector<KRATOS_DOUBLE_TYPE> ScalarVector;
    typedef Eigen::SparseVector<KRATOS_DOUBLE_TYPE> SparseVector;

    typedef Eigen::SparseVector<KRATOS_DOUBLE_TYPE> CompressedVector;
    // typedef boost::numeric::ublas::coordinate_vector<KRATOS_DOUBLE_TYPE> CoordinateVector;
    // typedef boost::numeric::ublas::vector_range<Vector> VectorRange;
    // typedef boost::numeric::ublas::vector_slice<Vector> VectorSlice;

    typedef Eigen::MatrixXt<KRATOS_DOUBLE_TYPE> Matrix;
    typedef Eigen::IdentityMatrix<KRATOS_DOUBLE_TYPE> IdentityMatrix;
    typedef Eigen::ZeroMatrix<KRATOS_DOUBLE_TYPE> ZeroMatrix;
    typedef Eigen::ScalarMatrix<KRATOS_DOUBLE_TYPE> ScalarMatrix;
    // typedef boost::numeric::ublas::triangular_matrix<KRATOS_DOUBLE_TYPE> TriangularMatrix;
    typedef Eigen::SymmetricMatrix<KRATOS_DOUBLE_TYPE> SymmetricMatrix;
    // typedef boost::numeric::ublas::hermitian_matrix<KRATOS_DOUBLE_TYPE> HermitianMatrix;
    // typedef boost::numeric::ublas::banded_matrix<KRATOS_DOUBLE_TYPE> BandedMatrix;
    // typedef boost::numeric::ublas::mapped_matrix<KRATOS_DOUBLE_TYPE> SparseMatrix;
    // typedef boost::numeric::ublas::coordinate_matrix<KRATOS_DOUBLE_TYPE> CoordinateMatrix;
    typedef Eigen::SparseMatrix<KRATOS_DOUBLE_TYPE> CompressedMatrix;
    // typedef boost::numeric::ublas::matrix_column<Matrix> MatrixColumn;
    // typedef boost::numeric::ublas::matrix_vector_range<Matrix> MatrixVectorRange;
    // typedef boost::numeric::ublas::matrix_vector_slice<Matrix> MatrixVectorSlice;
    // typedef boost::numeric::ublas::matrix_range<Matrix> MatrixRange;
    // typedef boost::numeric::ublas::matrix_slice<Matrix> MatrixSlice;

    // template <typename TExpressionType> using MatrixRow = boost::numeric::ublas::matrix_row<TExpressionType>;

    /// types for complex linear algebra

    typedef Eigen::VectorXt<KRATOS_COMPLEX_TYPE> ComplexVector;
    typedef Eigen::UnitVector<KRATOS_COMPLEX_TYPE> ComplexUnitVector;
    typedef Eigen::ZeroVector<KRATOS_COMPLEX_TYPE> ComplexZeroVector;
    typedef Eigen::ScalarVector<KRATOS_COMPLEX_TYPE> ComplexScalarVector;
    typedef Eigen::SparseVector<KRATOS_COMPLEX_TYPE> ComplexSparseVector;

    typedef Eigen::SparseVector<KRATOS_COMPLEX_TYPE> ComplexCompressedVector;
    // typedef boost::numeric::ublas::coordinate_vector<KRATOS_COMPLEX_TYPE> ComplexCoordinateVector;
    // typedef boost::numeric::ublas::vector_range<ComplexVector> ComplexVectorRange;
    // typedef boost::numeric::ublas::vector_slice<ComplexVector> ComplexVectorSlice;

    typedef Eigen::MatrixXt<KRATOS_COMPLEX_TYPE> ComplexMatrix;
    typedef Eigen::IdentityMatrix<KRATOS_COMPLEX_TYPE> ComplexIdentityMatrix;
    typedef Eigen::ZeroMatrix<KRATOS_COMPLEX_TYPE> ComplexZeroMatrix;
    typedef Eigen::ScalarMatrix<KRATOS_COMPLEX_TYPE> ComplexScalarMatrix;
    // typedef boost::numeric::ublas::triangular_matrix<KRATOS_COMPLEX_TYPE> ComplexTriangularMatrix;
    typedef Eigen::SymmetricMatrix<KRATOS_COMPLEX_TYPE> ComplexSymmetricMatrix;
    // typedef boost::numeric::ublas::hermitian_matrix<KRATOS_COMPLEX_TYPE> ComplexHermitianMatrix;
    // typedef boost::numeric::ublas::banded_matrix<KRATOS_COMPLEX_TYPE> ComplexBandedMatrix;
    // typedef boost::numeric::ublas::mapped_matrix<KRATOS_COMPLEX_TYPE> ComplexSparseMatrix;
    // typedef boost::numeric::ublas::coordinate_matrix<KRATOS_COMPLEX_TYPE> ComplexCoordinateMatrix;
    typedef Eigen::SparseMatrix<KRATOS_COMPLEX_TYPE> ComplexCompressedMatrix;
    // typedef boost::numeric::ublas::matrix_column<ComplexMatrix> ComplexMatrixColumn;
    // typedef boost::numeric::ublas::matrix_vector_range<ComplexMatrix> ComplexMatrixVectorRange;
    // typedef boost::numeric::ublas::matrix_vector_slice<ComplexMatrix> ComplexMatrixVectorSlice;
    // typedef boost::numeric::ublas::matrix_range<ComplexMatrix> ComplexMatrixRange;
    // typedef boost::numeric::ublas::matrix_slice<ComplexMatrix> ComplexMatrixSlice;

    // // declare namespace usage to avoid downstream explosion of compilation errors
    // using namespace boost::numeric::ublas;

    // selector for vector and matrix type
    template<typename TDataType>
    struct MatrixVectorTypeSelector
    {
        typedef Eigen::VectorXt<TDataType> VectorType;
        typedef Eigen::MatrixXt<TDataType> MatrixType;
        typedef Eigen::ZeroVector<TDataType> ZeroVectorType;
        typedef Eigen::ZeroMatrix<TDataType> ZeroMatrixType;
        typedef Eigen::IdentityMatrix<TDataType> IdentityMatrixType;
        typedef Eigen::SparseMatrix<TDataType> CompressedMatrixType;
    };

    // more specialization for DataTypeToString
    template<> struct DataTypeToString<Eigen::Matrix<int, Eigen::Dynamic, 1> > { static inline constexpr const char* Get() {return "Eigen::Matrix<int, Eigen::Dynamic, 1>";} };
    template<> struct DataTypeToString<Eigen::Matrix<double, Eigen::Dynamic, 1> > { static inline constexpr const char* Get() {return "Eigen::Matrix<double, Eigen::Dynamic, 1>";} };
    template<> struct DataTypeToString<Eigen::Matrix<std::complex<double>, Eigen::Dynamic, 1> > { static inline constexpr const char* Get() {return "Eigen::Matrix<std::complex<double>, Eigen::Dynamic, 1>";} };
    template<> struct DataTypeToString<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> > { static inline constexpr const char* Get() {return "Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>";} };
    template<> struct DataTypeToString<Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic> > { static inline constexpr const char* Get() {return "Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic>";} };

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

#endif // KRATOS_EIGEN_INTERFACE_H_INCLUDED  defined
