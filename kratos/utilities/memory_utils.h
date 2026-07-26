//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang Giang Bui
//

#if !defined(KRATOS_MEMORY_UTILS_H_INCLUDED )
#define  KRATOS_MEMORY_UTILS_H_INCLUDED

#include "includes/matrix_vector_adapter.h"

namespace Kratos
{

template<typename TDataType>
struct MemorySizeHelper;

template<typename TDataType>
struct MemorySizeHelper<DenseVector<TDataType> >
{
    static inline std::size_t Compute(const DenseVector<TDataType>& rObject)
    {
        return sizeof(DenseVector<TDataType>) + rObject.size()*sizeof(TDataType);
    }
};

template<typename TDataType>
struct MemorySizeHelper<DenseMatrix<TDataType> >
{
    static inline std::size_t Compute(const DenseMatrix<TDataType>& rObject)
    {
        return sizeof(DenseMatrix<TDataType>) + rObject.size1()*rObject.size2()*sizeof(TDataType);
    }
};

class MemoryUtils
{
public:
    typedef std::size_t SizeType;

    template<typename TDataType>
    static inline SizeType GetDataSize(const TDataType& rObject)
    {
        return MemorySizeHelper<TDataType>::Compute(rObject);
    }

}; // class MemoryUtils

} // end namespace Kratos

#endif // KRATOS_MEMORY_UTILS_H_INCLUDED
