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



#if !defined(KRATOS_STRATEGIES_PYTHON_H_INCLUDED )
#define  KRATOS_STRATEGIES_PYTHON_H_INCLUDED



// System includes


// External includes


// Project includes
#include "includes/model_part.h"


namespace Kratos
{

namespace Python
{

template< class TBuilderAndSolverType >
void BuilderAndSolver_ResizeAndInitializeVectors1(TBuilderAndSolverType& rDummy,
    typename TBuilderAndSolverType::TSystemMatrixPointerType& pA,
    typename TBuilderAndSolverType::TSystemVectorPointerType& pDx,
    typename TBuilderAndSolverType::TSystemVectorPointerType& pb,
    typename TBuilderAndSolverType::ElementsContainerType& rElements,
    typename TBuilderAndSolverType::ConditionsContainerType& rConditions,
    const ProcessInfo& CurrentProcessInfo)
{
    rDummy.ResizeAndInitializeVectors(pA, pDx, pb, rElements, rConditions, CurrentProcessInfo);
}

template< class TBuilderAndSolverType >
void BuilderAndSolver_ResizeAndInitializeVectors2(TBuilderAndSolverType& rDummy,
    typename TBuilderAndSolverType::TSystemMatrixPointerType& pA,
    typename TBuilderAndSolverType::TSystemVectorPointerType& pDx,
    typename TBuilderAndSolverType::TSystemVectorPointerType& pb,
    typename TBuilderAndSolverType::ModelPartType& r_model_part)
{
    rDummy.ResizeAndInitializeVectors(pA, pDx, pb, r_model_part);
}

void AddStrategiesToPython();

}  // namespace Python.

}  // namespace Kratos.

#endif // KRATOS_STRATEGIES_PYTHON_H_INCLUDED  defined
