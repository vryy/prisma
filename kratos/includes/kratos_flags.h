// Kratos Multi-Physics
//
// Copyright (c) 2016 Pooyan Dadvand, Riccardo Rossi, CIMNE (International Center for Numerical Methods in Engineering)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
// 	-	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// 	-	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
// 		in the documentation and/or other materials provided with the distribution.
// 	-	All advertising materials mentioning features or use of this software must display the following acknowledgement:
// 			This product includes Kratos Multi-Physics technology.
// 	-	Neither the name of the CIMNE nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED ANDON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THISSOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



#if !defined(KRATOS_KRATOS_FLAGS_H_INCLUDED )
#define  KRATOS_KRATOS_FLAGS_H_INCLUDED



// System includes


// External includes


// Project includes
#include "includes/define.h"
#include "containers/flags.h"
#include "includes/kratos_components.h"


namespace Kratos
{
///@addtogroup Kratos
///@{

///@name Kratos Globals
///@{

KRATOS_CREATE_FLAG(STRUCTURE,       63);
KRATOS_CREATE_FLAG(FLUID,           62);
KRATOS_CREATE_FLAG(THERMAL,         61);
KRATOS_CREATE_FLAG(VISITED,         60);
KRATOS_CREATE_FLAG(SELECTED,        59);
KRATOS_CREATE_FLAG(BOUNDARY,        58);
KRATOS_CREATE_FLAG(INLET,           57);
KRATOS_CREATE_FLAG(OUTLET,          56);
KRATOS_CREATE_FLAG(SLIP,            55);
KRATOS_CREATE_FLAG(INTERFACE,       54);
KRATOS_CREATE_FLAG(CONTACT,         53);
KRATOS_CREATE_FLAG(TO_SPLIT,        52);
KRATOS_CREATE_FLAG(TO_ERASE,        51);
KRATOS_CREATE_FLAG(TO_REFINE,       50);
KRATOS_CREATE_FLAG(NEW_ENTITY,      49);
KRATOS_CREATE_FLAG(OLD_ENTITY,      48);
KRATOS_CREATE_FLAG(ACTIVE,          47);
KRATOS_CREATE_FLAG(MODIFIED,        46);
KRATOS_CREATE_FLAG(RIGID,           45);
KRATOS_CREATE_FLAG(SOLID,           44);
KRATOS_CREATE_FLAG(MPI_BOUNDARY,    43);
KRATOS_CREATE_FLAG(INTERACTION,     42);
KRATOS_CREATE_FLAG(ISOLATED,        41);
KRATOS_CREATE_FLAG(MASTER,          40);
KRATOS_CREATE_FLAG(SLAVE,           39);
KRATOS_CREATE_FLAG(INSIDE,          38);
KRATOS_CREATE_FLAG(FREE_SURFACE,    37);
KRATOS_CREATE_FLAG(BLOCKED,         36);
KRATOS_CREATE_FLAG(MARKER,          35);
KRATOS_CREATE_FLAG(HANGING,         34);


///@}
///@name Type Definitions
///@{

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}

///@} addtogroup block

}  // namespace Kratos.

#endif // KRATOS_KRATOS_FLAGS_H_INCLUDED  defined
