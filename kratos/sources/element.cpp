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
#include "includes/element.h"


namespace Kratos
{

template class BaseElement<RealNode>;
template class BaseElement<ComplexNode>;
template class BaseElement<GComplexNode>;

} // namespace Kratos.
