//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui + ChatGPT
//
//

#if !defined(KRATOS_CONST_DEREF_ITERATOR_H_INCLUDED )
#define  KRATOS_CONST_DEREF_ITERATOR_H_INCLUDED

// System includes

// External includes
#include <boost/iterator/indirect_iterator.hpp>

// Project includes

namespace Kratos
{

// An iterator that can unwrap the object under pointer container
// and provide const reference access
template <typename BaseIterator>
class ConstDerefIterator {
public:
    using base_value_type = typename BaseIterator::value_type::element_type;
    using value_type = const base_value_type;
    using reference = const base_value_type&;
    using pointer = const base_value_type*;
    using difference_type = typename std::iterator_traits<BaseIterator>::difference_type;
    using iterator_category = std::random_access_iterator_tag;

    ConstDerefIterator() = default;
    explicit ConstDerefIterator(BaseIterator it) : mIt(it) {}

    // Optional: allow conversion from boost::indirect_iterator
    template <typename OtherIt>
    ConstDerefIterator(boost::indirect_iterator<OtherIt> boostIt)
        : mIt(boostIt.base()) {}

    reference operator*() const { return *static_cast<const base_value_type*>(mIt->get()); }
    pointer operator->() const { return static_cast<const base_value_type*>(mIt->get()); }

    ConstDerefIterator& operator++() { ++mIt; return *this; }
    ConstDerefIterator operator++(int) { ConstDerefIterator tmp = *this; ++(*this); return tmp; }

    ConstDerefIterator& operator--() { --mIt; return *this; }
    ConstDerefIterator operator--(int) { ConstDerefIterator tmp = *this; --(*this); return tmp; }

    ConstDerefIterator& operator+=(difference_type n) { mIt += n; return *this; }
    ConstDerefIterator& operator-=(difference_type n) { mIt -= n; return *this; }

    ConstDerefIterator operator+(difference_type n) const { return ConstDerefIterator(mIt + n); }
    ConstDerefIterator operator-(difference_type n) const { return ConstDerefIterator(mIt - n); }

    difference_type operator-(const ConstDerefIterator& other) const { return mIt - other.mIt; }

    reference operator[](difference_type n) const { return *static_cast<const base_value_type*>(mIt[n].get()); }

    // STL comparisons
    bool operator==(const ConstDerefIterator& other) const { return mIt == other.mIt; }
    bool operator!=(const ConstDerefIterator& other) const { return mIt != other.mIt; }
    bool operator<(const ConstDerefIterator& other) const { return mIt < other.mIt; }
    bool operator<=(const ConstDerefIterator& other) const { return mIt <= other.mIt; }
    bool operator>(const ConstDerefIterator& other) const { return mIt > other.mIt; }
    bool operator>=(const ConstDerefIterator& other) const { return mIt >= other.mIt; }

    // Access to base iterator
    BaseIterator base() const { return mIt; }

private:
    BaseIterator mIt;
};

// Interop: compare with boost::indirect_iterator
// ==
template <typename I1, typename I2>
bool operator==(const boost::indirect_iterator<I1>& lhs, const ConstDerefIterator<I2>& rhs) {
    return lhs.base() == rhs.base();
}

template <typename I1, typename I2>
bool operator==(const ConstDerefIterator<I2>& lhs, const boost::indirect_iterator<I1>& rhs) {
    return lhs.base() == rhs.base();
}

// !=
template <typename I1, typename I2>
bool operator!=(const boost::indirect_iterator<I1>& lhs, const ConstDerefIterator<I2>& rhs) {
    return lhs.base() != rhs.base();
}

template <typename I1, typename I2>
bool operator!=(const ConstDerefIterator<I2>& lhs, const boost::indirect_iterator<I1>& rhs) {
    return lhs.base() != rhs.base();
}

// <
template <typename I1, typename I2>
bool operator<(const boost::indirect_iterator<I1>& lhs, const ConstDerefIterator<I2>& rhs) {
    return lhs.base() < rhs.base();
}

template <typename I1, typename I2>
bool operator<(const ConstDerefIterator<I2>& lhs, const boost::indirect_iterator<I1>& rhs) {
    return lhs.base() < rhs.base();
}

// <=
template <typename I1, typename I2>
bool operator<=(const boost::indirect_iterator<I1>& lhs, const ConstDerefIterator<I2>& rhs) {
    return lhs.base() <= rhs.base();
}

template <typename I1, typename I2>
bool operator<=(const ConstDerefIterator<I2>& lhs, const boost::indirect_iterator<I1>& rhs) {
    return lhs.base() <= rhs.base();
}

// >
template <typename I1, typename I2>
bool operator>(const boost::indirect_iterator<I1>& lhs, const ConstDerefIterator<I2>& rhs) {
    return lhs.base() > rhs.base();
}

template <typename I1, typename I2>
bool operator>(const ConstDerefIterator<I2>& lhs, const boost::indirect_iterator<I1>& rhs) {
    return lhs.base() > rhs.base();
}

// >=
template <typename I1, typename I2>
bool operator>=(const boost::indirect_iterator<I1>& lhs, const ConstDerefIterator<I2>& rhs) {
    return lhs.base() >= rhs.base();
}

template <typename I1, typename I2>
bool operator>=(const ConstDerefIterator<I2>& lhs, const boost::indirect_iterator<I1>& rhs) {
    return lhs.base() >= rhs.base();
}

// ConstDerefIterator + n
template <typename I>
ConstDerefIterator<I> operator+(ConstDerefIterator<I> it, typename ConstDerefIterator<I>::difference_type n) {
    it += n;
    return it;
}

template <typename I>
ConstDerefIterator<I> operator+(typename ConstDerefIterator<I>::difference_type n, ConstDerefIterator<I> it) {
    return it + n;
}

// ConstDerefIterator - n
template <typename I>
ConstDerefIterator<I> operator-(ConstDerefIterator<I> it, typename ConstDerefIterator<I>::difference_type n) {
    it -= n;
    return it;
}

// boost::indirect_iterator - ConstDerefIterator
template <typename I1, typename I2>
typename ConstDerefIterator<I2>::difference_type operator-(
    const boost::indirect_iterator<I1>& lhs,
    const ConstDerefIterator<I2>& rhs)
{
    return lhs.base() - rhs.base();
}

template <typename I1, typename I2>
typename ConstDerefIterator<I2>::difference_type operator-(
    const ConstDerefIterator<I2>& lhs,
    const boost::indirect_iterator<I1>& rhs)
{
    return lhs.base() - rhs.base();
}

} // end namespace Kratos

#endif // KRATOS_CONST_DEREF_ITERATOR_H_INCLUDED
