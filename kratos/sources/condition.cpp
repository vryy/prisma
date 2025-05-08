//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                     Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//  Contributors:    Hoang-Giang Bui
//


// System includes

// External includes

// Project includes
#include "includes/node.h"
#include "includes/condition.h"


namespace Kratos
{

template class BaseCondition<RealNode>;
template class BaseCondition<ComplexNode>;
template class BaseCondition<GComplexNode>;

} // namespace Kratos.
