//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//  Contributors:    Hoang-Giang Bui
//
//

// System includes

// External includes

// Project includes
#include "utilities/indexed_object.h"


namespace Kratos
{

template class KRATOS_API(KRATOS_CORE) BaseIndexedObject<KRATOS_INDEX_TYPE>;

#if KRATOS_INDEX_TYPE_IS_INT==0
template class KRATOS_API(KRATOS_CORE) BaseIndexedObject<int>;
#endif

}  // namespace Kratos.
