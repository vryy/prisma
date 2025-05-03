/*
==============================================================================
Kratos
A General Purpose Software for Multi-Physics Finite Element Analysis
Version 1.0 (Released on march 05, 2007).

Copyright 2007
Pooyan Dadvand, Riccardo Rossi
pooyan@cimne.upc.edu
rrossi@cimne.upc.edu
CIMNE (International Center for Numerical Methods in Engineering),
Gran Capita' s/n, 08034 Barcelona, Spain

Permission is hereby granted, free  of charge, to any person obtaining
a  copy  of this  software  and  associated  documentation files  (the
"Software"), to  deal in  the Software without  restriction, including
without limitation  the rights to  use, copy, modify,  merge, publish,
distribute,  sublicense and/or  sell copies  of the  Software,  and to
permit persons to whom the Software  is furnished to do so, subject to
the following condition:

Distribution of this code for  any  commercial purpose  is permissible
ONLY BY DIRECT ARRANGEMENT WITH THE COPYRIGHT OWNER.

The  above  copyright  notice  and  this permission  notice  shall  be
included in all copies or substantial portions of the Software.

THE  SOFTWARE IS  PROVIDED  "AS  IS", WITHOUT  WARRANTY  OF ANY  KIND,
EXPRESS OR  IMPLIED, INCLUDING  BUT NOT LIMITED  TO THE  WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT  SHALL THE AUTHORS OR COPYRIGHT HOLDERS  BE LIABLE FOR ANY
CLAIM, DAMAGES OR  OTHER LIABILITY, WHETHER IN AN  ACTION OF CONTRACT,
TORT  OR OTHERWISE, ARISING  FROM, OUT  OF OR  IN CONNECTION  WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

==============================================================================
*/

//
//   Project Name:        Kratos
//   Last Modified by:    $Author: rrossi $
//   Date:                $Date: 2007-03-06 10:30:33 $
//   Revision:            $Revision: 1.2 $
//
//


#if !defined(KRATOS_DIRECT_SOLVER_H_INCLUDED )
#define  KRATOS_DIRECT_SOLVER_H_INCLUDED



// System includes


// External includes

// Project includes
#include "linear_solver.h"


namespace Kratos
{



// Base class for all direct solvers in Kratos.
/* This class define the general interface for direct solvers in Kratos.
   direct solver is a template class with this parameter:
   - TSparseSpaceType which specify type
     of the unknowns, coefficients, sparse matrix, vector of
   unknowns, right hand side vector and their respective operators.
   - TDenseMatrixType which specify type of the
     matrices used as temporary matrices or multi solve unknowns and
   right hand sides and their operators.
   - TReordererType which specify type of the Orderer that performs the reordering of matrix to optimize the solution.
*/
template<class TSparseSpaceType, class TDenseSpaceType, class TModelPartType, class TReordererType = Reorderer<TSparseSpaceType, TDenseSpaceType> >
class DirectSolver : public LinearSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TReordererType>
{
public:

    /// Counted pointer of DirectSolver
    KRATOS_CLASS_POINTER_DEFINITION(DirectSolver);

    typedef LinearSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TReordererType> BaseType;

    typedef typename BaseType::SparseMatrixType SparseMatrixType;

    typedef typename BaseType::VectorType VectorType;

    typedef typename BaseType::DenseMatrixType DenseMatrixType;

    typedef typename BaseType::DataType DataType;

    /// Default constructor.
    DirectSolver() {}

    /// Destructor.
    ~DirectSolver() override {}

    /// Copy constructor.
    DirectSolver(const DirectSolver& Other) {}

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << "Direct solver";
    }

    /// Print object's data.
    void  PrintData(std::ostream& rOStream) const override
    {
    }

private:

    /// Assignment operator.
    DirectSolver& operator=(const DirectSolver& Other);

}; // class DirectSolver

}  // namespace Kratos.

#endif // KRATOS_DIRECT_SOLVER_H_INCLUDED  defined
