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
//                   Riccardo Rossi
//  Contributors:    Hoang-Giang Bui
//
//

// System includes

// External includes

// Project includes
#include "includes/node.h"
#include "includes/communicator.h"

namespace Kratos
{

template class Communicator<RealNode>;
template class Communicator<ComplexNode>;
template class Communicator<GComplexNode>;

} // namespace Kratos.
