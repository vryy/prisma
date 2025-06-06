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


// Project includes
#include "includes/io.h"

namespace Kratos
{

    /// Local Flags
    KRATOS_CREATE_LOCAL_FLAG(BaseIO, READ,   1);
    KRATOS_CREATE_LOCAL_FLAG(BaseIO, WRITE,  2);
    KRATOS_CREATE_LOCAL_FLAG(BaseIO, APPEND, 3);
    KRATOS_CREATE_LOCAL_FLAG(BaseIO, IGNORE_VARIABLES_ERROR, 4); // before adding a new flag be aware that some derived classes have some defined.

}  // namespace Kratos.
