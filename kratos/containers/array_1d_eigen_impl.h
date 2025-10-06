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
//

#if !defined(KRATOS_ARRAY_1D_EIGEN_IMPL_H_INCLUDED)
#define  KRATOS_ARRAY_1D_EIGEN_IMPL_H_INCLUDED

#include <Eigen/Dense>
#include <algorithm>
#include <initializer_list>
#include <complex>
#include <stdexcept>

#include "includes/eigen_interface.h"

namespace Kratos
{

template<typename T, std::size_t N>
class array_1d
{
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using self_type = array_1d<T,N>;
    using closure_type = self_type&;
    using const_closure_type = const self_type&;
    using iterator = T*;
    using const_iterator = const T*;    // TODO we have to check, if it is safe to use pointer as iterator

    using array_type = Eigen::Matrix<T,N,1>;

    KRATOS_CLASS_POINTER_DEFINITION(array_1d);

    // Constructors
    array_1d() = default;

    explicit array_1d(size_type size)
    {
        if(size > N) throw std::runtime_error("Size exceeds array_1d capacity");
    }

    explicit array_1d(size_type size, value_type v)
    {
        if(size > N) throw std::runtime_error("Size exceeds array_1d capacity");
        data_.setConstant(v);
    }

    template<typename TVectorType>
    array_1d(const TVectorType& v)
    {
        KRATOS_DEBUG_ERROR_IF(v.rows() != N)
            << "Cannot construct array_1d of size " << N
            << " from vector of size " << v.rows() << std::endl;

        for (size_type i = 0; i < N; ++i)
            data_[i] = v[i];
    }

    array_1d(const std::initializer_list<value_type>& rInitList)
    {
        if(rInitList.size() > N) throw std::runtime_error("Initializer list size exceeds array_1d capacity");
        std::copy(rInitList.begin(), rInitList.end(), data_.data());
    }

    array_1d(const array_1d& other) = default;

    array_1d(const Eigen::EigenVector<T>& v)
    {
        KRATOS_DEBUG_ERROR_IF(v.rows() != N)
            << "Cannot construct array_1d of size " << N
            << " from vector of size " << v.rows() << std::endl;

        for (size_type i = 0; i < N; ++i)
            data_[i] = v[i];
    }

    operator Eigen::VectorXt<T>() const
    {
        Eigen::VectorXt<T> result(size());
        for (size_type i = 0; i < size(); ++i)
            result(i) = (*this)(i);
        return result;
    }

    size_type rows() const { return N; }

    // Element access
    reference operator()(size_type i) { return data_(i); }
    const_reference operator()(size_type i) const { return data_(i); }

    reference operator[](size_type i) { return data_(i); }
    const_reference operator[](size_type i) const { return data_(i); }

    // Assignment operators
    array_1d& operator=(const array_1d& other) { data_ = other.data_; return *this; }
    array_1d& operator=(const vector<T>& other) {
        assert(N == other.size());
        for (std::size_t i = 0; i < N; ++i) (*this)[i] = other[i];
        return *this;
    }

    // Arithmetic operators
    array_1d& operator*(T a)
    {
        this->data() *= a;
        return *this;
    }

    template<typename U = T>
    std::enable_if_t<std::is_same<U, std::complex<KRATOS_DOUBLE_TYPE>>::value, array_1d&>
    operator*(KRATOS_DOUBLE_TYPE a)
    {
        this->data() *= a;
        return *this;
    }

    array_1d& operator/(T a)
    {
        this->data() /= a;
        return *this;
    }

    template<typename U = T>
    std::enable_if_t<std::is_same<U, std::complex<KRATOS_DOUBLE_TYPE>>::value, array_1d&>
    operator/(KRATOS_DOUBLE_TYPE a)
    {
        this->data() /= a;
        return *this;
    }

    // array_1d& operator+(const array_1d& v)
    // {
    //     for (size_type i = 0; i < N; ++i)
    //         this->data()[i] += v[i];
    //     return *this;
    // }

    // template<typename Derived>
    // array_1d& operator+(const Eigen::MatrixBase<Derived>& expr)
    // {
    //     assert(N == expr.rows());
    //     for (size_type i = 0; i < size(); ++i)
    //         this->data()[i] += expr[i];
    //     return *this;
    // }

    // array_1d& operator-(const array_1d& v)
    // {
    //     for (size_type i = 0; i < N; ++i)
    //         this->data()[i] -= v[i];
    //     return *this;
    // }

    // template<typename Derived>
    // array_1d& operator-(const Eigen::MatrixBase<Derived>& expr)
    // {
    //     assert(N == expr.rows());
    //     for (size_type i = 0; i < size(); ++i)
    //         this->data()[i] -= expr[i];
    //     return *this;
    // }

    template<typename Derived>
    array_1d& operator=(const Eigen::MatrixBase<Derived>& expr)
    {
        data_ = expr;
        return *this;
    }

    template<typename TVectorType>
    array_1d& operator=(const TVectorType& v)
    {
        KRATOS_DEBUG_ERROR_IF(v.rows() != N)
            << "Cannot assign array_1d of size " << N
            << " from vector of size " << v.rows() << std::endl;

        for (size_type i = 0; i < N; ++i)
            data_[i] = v(i);

        return *this;
    }

    template<typename Derived>
    array_1d& plus_assign(const Eigen::MatrixBase<Derived>& expr)
    {
        data_ += expr;
        return *this;
    }

    template<typename Derived>
    array_1d& minus_assign(const Eigen::MatrixBase<Derived>& expr)
    {
        data_ -= expr;
        return *this;
    }

    template<typename AT>
    array_1d& operator*=(const AT& val) { data_ *= val; return *this; }

    template<typename AT>
    array_1d& operator/=(const AT& val) { data_ /= val; return *this; }

    array_1d& operator+=(const array_1d& other)
    {
        for(size_type i=0; i<N; ++i)
            data_(i) += other(i);
        return *this;
    }

    template<typename TVectorType>
    array_1d& operator+=(const TVectorType& v)
    {
        KRATOS_DEBUG_ERROR_IF(v.rows() != N)
            << "Cannot assign array_1d of size " << N
            << " from vector of size " << v.rows() << std::endl;
        for(size_type i=0; i<N; ++i)
            data_(i) += v[i];
        return *this;
    }

    array_1d& operator-=(const array_1d& other)
    {
        for(size_type i=0; i<N; ++i)
            data_(i) -= other(i);
        return *this;
    }

    template<typename TVectorType>
    array_1d& operator-=(const TVectorType& v)
    {
        KRATOS_DEBUG_ERROR_IF(v.rows() != N)
            << "Cannot assign array_1d of size " << N
            << " from vector of size " << v.rows() << std::endl;
        for(size_type i=0; i<N; ++i)
            data_(i) -= v[i];
        return *this;
    }

    self_type operator-() const
    {
        self_type result;
        for (size_type i = 0; i < size(); ++i)
            result(i) = -(*this)(i);
        return result;
    }

    value_type dot(const self_type& other) const
    {
        KRATOS_DEBUG_ERROR_IF(other.rows() != N);
        value_type sum = value_type();
        for (size_type i = 0; i < size(); ++i)
            sum += (*this)(i) * other(i);
        return sum;
    }

    // uBLAS-style assign
    template<typename Derived>
    array_1d& assign(const Eigen::MatrixBase<Derived>& expr)
    {
        data_ = expr;
        return *this;
    }

    // assign_temporary swaps contents with temporary
    array_1d& assign_temporary(array_1d& tmp)
    {
        swap(tmp);
        return *this;
    }

    // Comparison
    bool operator==(const array_1d& other) const { return data_ == other.data_; }

    // Inquiry
    size_type size() const { return N; }
    size_type size1() const { return N; } // uBLAS compatibility

    // Resize
    void resize(size_type size, bool preserve = true)
    {
        if(size > N) throw std::runtime_error("Resize exceeds array_1d capacity");
        if(!preserve) data_.setZero();
    }

    void clear() { data_.setZero(); }

    // Swap
    void swap(array_1d& other)
    {
        if(this != &other)
            data_.swap(other.data_);
    }

    friend void swap(array_1d& a, array_1d& b) { a.swap(b); }

    // Insert / erase
    reference insert_element(size_type i, const_reference val)
    {
        if(i >= N) throw std::out_of_range("Index out of range");
        data_(i) = val;
        return data_(i);
    }

    void erase_element(size_type i)
    {
        if(i >= N) throw std::out_of_range("Index out of range");
        data_(i) = value_type(0);
    }

    // Data access
    const array_type& data() const { return data_; }
    array_type& data() { return data_; }

    // Iterators
    const_iterator begin() const { return data_.data(); }
    const_iterator end() const { return data_.data() + N; }
    iterator begin() { return data_.data(); }
    iterator end() { return data_.data() + N; }

    // output stream operator
    friend std::ostream& operator<<(std::ostream& os, const array_1d& v)
    {
        os << "[";
        for(size_type i = 0; i < N; ++i)
        {
            os << v(i);
            if(i != N-1) os << ", ";
        }
        os << "]";
        return os;
    }

private:
    array_type data_;
};

template<typename T, std::size_t N>
array_1d<T,N> operator+(const array_1d<T,N>& lhs, const array_1d<T,N>& rhs)
{
    return array_1d<T,N>(lhs.data() + rhs.data());
}

template<typename T, std::size_t N, typename Derived>
array_1d<T,N> operator+(const array_1d<T,N>& lhs, const Eigen::MatrixBase<Derived>& rhs)
{
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N)
            << "Cannot perform additive operation between array_1d of size " << N
            << " and vector of size " << rhs.rows() << std::endl;
    array_1d<T,N> tmp(rhs);
    return lhs + tmp;
}

template<typename T, std::size_t N>
array_1d<T,N> operator+(const array_1d<T,N>& lhs, const Eigen::EigenVector<T>& rhs)
{
    array_1d<T,N> result(lhs);
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N) << "Dimension mismatch" << std::endl;
    for (std::size_t i = 0; i < N; ++i)
        result[i] += rhs[i];
    return result;
}

template<typename T, std::size_t N>
array_1d<T,N> operator+(const Eigen::EigenVector<T>& lhs, const array_1d<T,N>& rhs)
{
    array_1d<T,N> result(rhs);
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N) << "Dimension mismatch" << std::endl;
    for (std::size_t i = 0; i < N; ++i)
        result[i] += lhs[i];
    return result;
}

template<typename T, std::size_t N>
array_1d<T,N> operator+(const array_1d<T,N>& lhs, const Eigen::VectorXt<T>& rhs)
{
    array_1d<T,N> result(lhs);
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N) << "Dimension mismatch" << std::endl;
    for (std::size_t i = 0; i < N; ++i)
        result[i] += rhs[i];
    return result;
}

template<typename T, std::size_t N>
array_1d<T,N> operator+(const Eigen::VectorXt<T>& lhs, const array_1d<T,N>& rhs)
{
    array_1d<T,N> result(rhs);
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N) << "Dimension mismatch" << std::endl;
    for (std::size_t i = 0; i < N; ++i)
        result[i] += lhs[i];
    return result;
}

template<typename T, std::size_t N>
array_1d<T, N> operator+(const array_1d<T,N>& lhs, const Eigen::SparseVector<T>& rhs) {
    array_1d<T,N> result = lhs;
    for (typename Eigen::SparseVector<T>::InnerIterator it(rhs); it; ++it) {
        result[it.index()] += it.value();
    }
    return result;
}

template<typename T, std::size_t N>
array_1d<T, N> operator+(const Eigen::SparseVector<T>& lhs, const array_1d<T,N>& rhs) {
    array_1d<T,N> result = rhs;
    for (typename Eigen::SparseVector<T>::InnerIterator it(lhs); it; ++it) {
        result[it.index()] += it.value();
    }
    return result;
}

template<typename T, std::size_t N>
array_1d<T,N> operator-(const array_1d<T,N>& lhs, const array_1d<T,N>& rhs)
{
    return array_1d<T,N>(lhs.data() - rhs.data());
}

template<typename T, std::size_t N, typename Derived>
array_1d<T,N> operator-(const array_1d<T,N>& lhs, const Eigen::MatrixBase<Derived>& rhs)
{
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N)
            << "Cannot perform subtract operation between array_1d of size " << N
            << " and vector of size " << rhs.rows() << std::endl;
    array_1d<T,N> tmp(rhs);
    return lhs - tmp;
}

template<typename T, std::size_t N>
array_1d<T,N> operator-(const array_1d<T,N>& lhs, const Eigen::EigenVector<T>& rhs)
{
    array_1d<T,N> result(lhs);
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N) << "Dimension mismatch" << std::endl;
    for (std::size_t i = 0; i < N; ++i)
        result[i] -= rhs[i];
    return result;
}

template<typename T, std::size_t N>
array_1d<T,N> operator-(const Eigen::EigenVector<T>& lhs, const array_1d<T,N>& rhs)
{
    array_1d<T,N> result(-rhs);
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N) << "Dimension mismatch" << std::endl;
    for (std::size_t i = 0; i < N; ++i)
        result[i] += lhs[i];
    return result;
}

template<typename T, std::size_t N>
array_1d<T,N> operator-(const array_1d<T,N>& lhs, const Eigen::VectorXt<T>& rhs)
{
    array_1d<T,N> result(lhs);
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N) << "Dimension mismatch" << std::endl;
    for (std::size_t i = 0; i < N; ++i)
        result[i] -= rhs[i];
    return result;
}

template<typename T, std::size_t N>
array_1d<T,N> operator-(const Eigen::VectorXt<T>& lhs, const array_1d<T,N>& rhs)
{
    array_1d<T,N> result(-rhs);
    KRATOS_DEBUG_ERROR_IF(rhs.rows() != N) << "Dimension mismatch" << std::endl;
    for (std::size_t i = 0; i < N; ++i)
        result[i] += lhs[i];
    return result;
}

template<typename T, std::size_t N>
array_1d<T, N> operator-(const array_1d<T,N>& lhs, const Eigen::SparseVector<T>& rhs) {
    array_1d<T,N> result = lhs;
    for (typename Eigen::SparseVector<T>::InnerIterator it(rhs); it; ++it) {
        result[it.index()] -= it.value();
    }
    return result;
}

template<typename T, std::size_t N>
array_1d<T, N> operator-(const Eigen::SparseVector<T>& lhs, const array_1d<T,N>& rhs) {
    array_1d<T,N> result = -rhs;
    for (typename Eigen::SparseVector<T>::InnerIterator it(lhs); it; ++it) {
        result[it.index()] += it.value();
    }
    return result;
}

template<typename T, std::size_t N>
array_1d<T,N> operator*(T a, const array_1d<T,N>& p)
{
    return array_1d<T,N>(a*p.data());
}

template<typename T, std::size_t N>
std::enable_if_t<std::is_same<T, std::complex<KRATOS_DOUBLE_TYPE>>::value, array_1d<T,N>>
operator*(KRATOS_DOUBLE_TYPE a, const array_1d<T,N>& p)
{
    return array_1d<T,N>(a*p.data());
}

template<typename T, std::size_t N>
array_1d<T,N>& noalias(array_1d<T,N>& lhs)
{
    return lhs; // simple pass-through
}

/// Wrapper for inner_prod
template<typename T, std::size_t N>
auto inner_prod(const array_1d<T,N>& v1, const array_1d<T,N>& v2)
{
    return v1.dot(v2);
}

template<typename T, std::size_t N>
auto inner_prod(const array_1d<T,N>& v1, const Eigen::EigenVector<T>& v2)
{
    KRATOS_DEBUG_ERROR_IF(v2.size() != N) << "Dimension mismatch" << std::endl;
    T result(0);
    for (std::size_t i = 0; i < N; ++i)
        result += v1[i]*v2[i];
    return result;
}

template<typename T, std::size_t N>
auto inner_prod(const Eigen::EigenVector<T>& v1, const array_1d<T,N>& v2)
{
    KRATOS_DEBUG_ERROR_IF(v1.size() != N) << "Dimension mismatch" << std::endl;
    T result(0);
    for (std::size_t i = 0; i < N; ++i)
        result += v1[i]*v2[i];
    return result;
}

template<class T, std::size_t N, class Derived>
auto inner_prod(const array_1d<T,N>& v1, const Eigen::MatrixBase<Derived>& v2)
{
    KRATOS_DEBUG_ERROR_IF(v1.size() != v2.size())
        << "inner_prod: dimension mismatch (" << v1.size() << " vs " << v2.size() << ")";
    // return v2.dot(Eigen::Map<const Eigen::Matrix<T, Eigen::Dynamic, 1>>(v1.data().begin(), v1.size()));
    T result(0);
    for (std::size_t i = 0; i < N; ++i)
        result += v1[i]*v2[i];
    return result;
}

template<class T, std::size_t N, class Derived>
auto inner_prod(const Eigen::MatrixBase<Derived>& v1, const array_1d<T,N>& v2)
{
    KRATOS_DEBUG_ERROR_IF(v1.size() != v2.size())
        << "inner_prod: dimension mismatch (" << v1.size() << " vs " << v2.size() << ")";
    // return v1.dot(Eigen::Map<const Eigen::Matrix<T, Eigen::Dynamic, 1>>(v2.data().begin(), v2.size()));
    T result(0);
    for (std::size_t i = 0; i < N; ++i)
        result += v1[i]*v2[i];
    return result;
}

template<typename T, std::size_t N>
auto inner_prod(const array_1d<T,N>& v1, const Eigen::VectorXt<T>& v2)
{
    KRATOS_DEBUG_ERROR_IF(v2.size() != N) << "Dimension mismatch" << std::endl;
    T result(0);
    for (std::size_t i = 0; i < N; ++i)
        result += v1[i]*v2[i];
    return result;
}

template<typename T, std::size_t N>
auto inner_prod(const Eigen::VectorXt<T>& v1, const array_1d<T,N>& v2)
{
    KRATOS_DEBUG_ERROR_IF(v2.size() != N) << "Dimension mismatch" << std::endl;
    T result(0);
    for (std::size_t i = 0; i < N; ++i)
        result += v1[i]*v2[i];
    return result;
}

template<typename T, std::size_t N>
auto inner_prod(const array_1d<T,N>& v1, const Eigen::SparseVector<T>& v2) {
    T result = 0.0;
    for (typename Eigen::SparseVector<T>::InnerIterator it(v2); it; ++it) {
        result += v1[it.index()] * it.value();
    }
    return result;
}

template<typename T, std::size_t N>
auto inner_prod(const Eigen::SparseVector<T>& v1, const array_1d<T,N>& v2) {
    T result = 0.0;
    for (typename Eigen::SparseVector<T>::InnerIterator it(v1); it; ++it) {
        result += v2[it.index()] * it.value();
    }
    return result;
}

template<typename T, std::size_t N>
auto norm_2(const array_1d<T,N>& v)
{
    return std::sqrt(inner_prod(v, v));
}

template<typename T, std::size_t N1, std::size_t N2>
BoundedVector<T, N1> prod(const BoundedMatrix<T, N1, N2>& m, const array_1d<T, N2>& v)
{
    return m * v.data();
}

template<typename T, std::size_t N>
DenseVector<T> prod(const DenseMatrix<T>& m, const array_1d<T, N>& v)
{
    KRATOS_DEBUG_ERROR_IF(m.cols() != N)
            << "Incompatible matrix size of " << m.rows() << " x " << m.cols()
            << " and vector size of " << N << std::endl;
    return m * v.data();
}

template<typename Derived, typename T, std::size_t N>
auto prod(const Eigen::MatrixBase<Derived>& m, const array_1d<T, N>& v)
{
    return m * v.data();
}

} // namespace Kratos

#endif // KRATOS_ARRAY_1D_EIGEN_IMPL_H_INCLUDED
