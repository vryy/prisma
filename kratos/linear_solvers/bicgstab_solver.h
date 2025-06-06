//
//   Project Name:        Kratos
//   Last Modified by:    $Author: rrossi $
//   Date:                $Date: 2008-03-05 09:39:14 $
//   Revision:            $Revision: 1.4 $
//
//


#if !defined(KRATOS_BICGSTAB_SOLVER_H_INCLUDED )
#define  KRATOS_BICGSTAB_SOLVER_H_INCLUDED



// System includes


// External includes

// Project includes
#include "includes/define.h"
#include "linear_solvers/iterative_solver.h"


namespace Kratos
{

///@name Kratos Globals
///@{

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
///@name Kratos Classes
///@{

/// Short class definition.
/** Detail class definition.
*/
template<class TSparseSpaceType, class TDenseSpaceType,
         class TModelPartType,
         class TPreconditionerType = Preconditioner<TSparseSpaceType, TDenseSpaceType, TModelPartType>,
         class TReordererType = Reorderer<TSparseSpaceType, TDenseSpaceType> >
class BICGSTABSolver : public IterativeSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TPreconditionerType, TReordererType>
{
public:
    ///@name Type Definitions
    ///@{

    /// Counted pointer of BICGSTABSolver
    KRATOS_CLASS_POINTER_DEFINITION(BICGSTABSolver);

    typedef IterativeSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TPreconditionerType, TReordererType> BaseType;

    typedef typename BaseType::DataType DataType;

    typedef typename BaseType::ValueType ValueType;

    typedef typename BaseType::SparseMatrixType SparseMatrixType;

    typedef typename BaseType::VectorType VectorType;

    typedef typename BaseType::DenseMatrixType DenseMatrixType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    BICGSTABSolver() {}

    BICGSTABSolver(ValueType NewTolerance) : BaseType(NewTolerance) {}

    BICGSTABSolver(ValueType NewTolerance, unsigned int NewMaxIterationsNumber) : BaseType(NewTolerance, NewMaxIterationsNumber) {}

    BICGSTABSolver(ValueType NewMaxTolerance, unsigned int NewMaxIterationsNumber, typename TPreconditionerType::Pointer pNewPreconditioner) :
        BaseType(NewMaxTolerance, NewMaxIterationsNumber, pNewPreconditioner) {}

    /// Copy constructor.
    BICGSTABSolver(const BICGSTABSolver& Other) : BaseType(Other) {}

    /// Destructor.
    ~BICGSTABSolver() override {}

    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    BICGSTABSolver& operator=(const BICGSTABSolver& Other)
    {
        BaseType::operator=(Other);
        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    /** Normal solve method.
    Solves the linear system Ax=b and puts the result on SystemVector& rX.
    rX is also th initial guess for iterative methods.
    @param rA. System matrix
    @param rX. Solution vector. it's also the initial
    guess for iterative linear solvers.
    @param rB. Right hand side vector.
    */
    bool Solve(SparseMatrixType& rA, VectorType& rX, VectorType& rB) override
    {
        if(this->IsNotConsistent(rA, rX, rB))
            return false;

        //GetTimeTable()->Start(Info());

// KRATOS_WATCH("ln161");
        BaseType::GetPreconditioner()->Initialize(rA,rX,rB);
// KRATOS_WATCH("ln163");
        BaseType::GetPreconditioner()->ApplyInverseRight(rX);
// KRATOS_WATCH("ln165");
        BaseType::GetPreconditioner()->ApplyLeft(rB);
// KRATOS_WATCH("ln167");
        bool is_solved = IterativeSolve(rA,rX,rB);
// KRATOS_WATCH("ln169");

        BaseType::GetPreconditioner()->Finalize(rX);

        //GetTimeTable()->Stop(Info());

        return is_solved;
    }

    /** Multi solve method for solving a set of linear systems with same coefficient matrix.
    Solves the linear system Ax=b and puts the result on SystemVector& rX.
    rX is also th initial guess for iterative methods.
    @param rA. System matrix
    @param rX. Solution vector. it's also the initial
    guess for iterative linear solvers.
    @param rB. Right hand side vector.
    */
    bool Solve(SparseMatrixType& rA, DenseMatrixType& rX, DenseMatrixType& rB) override
    {
        //GetTimeTable()->Start(Info());

        BaseType::GetPreconditioner()->Initialize(rA,rX,rB);

        bool is_solved = true;
        VectorType x(TDenseSpaceType::Size1(rX));
        VectorType b(TDenseSpaceType::Size1(rB));
        for(unsigned int i = 0 ; i < TDenseSpaceType::Size2(rX) ; i++)
        {
            TDenseSpaceType::GetColumn(i,rX, x);
            TDenseSpaceType::GetColumn(i,rB, b);

            BaseType::GetPreconditioner()->ApplyInverseRight(x);
            BaseType::GetPreconditioner()->ApplyLeft(b);

            is_solved &= IterativeSolve(rA,x,b);

            BaseType::GetPreconditioner()->Finalize(x);
        }

        //GetTimeTable()->Stop(Info());

        return is_solved;
    }

    ///@}
    ///@name Access
    ///@{


    ///@}
    ///@name Inquiry
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    /// Return information about this object.
    std::string Info() const override
    {
        std::stringstream buffer;
        buffer << "Biconjugate gradient stabilized linear solver with " << BaseType::GetPreconditioner()->Info();
        return  buffer.str();
    }

    /// Print information about this object.
    void PrintInfo(std::ostream& OStream) const override
    {
        OStream << "Biconjugate gradient stabilized linear solver with ";
        BaseType::GetPreconditioner()->PrintInfo(OStream);
    }

    ///@}
    ///@name Friends
    ///@{


    ///@}

protected:
    ///@name Protected static Member Variables
    ///@{


    ///@}
    ///@name Protected member Variables
    ///@{


    ///@}
    ///@name Protected Operators
    ///@{


    ///@}
    ///@name Protected Operations
    ///@{


    ///@}
    ///@name Protected  Access
    ///@{


    ///@}
    ///@name Protected Inquiry
    ///@{


    ///@}
    ///@name Protected LifeCycle
    ///@{


    ///@}

private:
    ///@name Static Member Variables
    ///@{


    ///@}
    ///@name Member Variables
    ///@{


    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{

    bool IterativeSolve(SparseMatrixType& rA, VectorType& rX, VectorType& rB)
    {
        const int size = TSparseSpaceType::Size(rX);
// KRATOS_WATCH("ln316");
        BaseType::mIterationsNumber = 0;

        VectorType r(size);
// KRATOS_WATCH(r.size());
// KRATOS_WATCH("ln319");
// KRATOS_WATCH(rA.size1());
// KRATOS_WATCH(rA.size2());
// KRATOS_WATCH(r.size());
// KRATOS_WATCH(rX.size());
// KRATOS_WATCH(rB.size());

        this->PreconditionedMult(rA,rX,r);
// KRATOS_WATCH("ln321");
        TSparseSpaceType::ScaleAndAdd(1.00, rB, -1.00, r);
// KRATOS_WATCH("ln322");
        BaseType::mBNorm = std::abs(TSparseSpaceType::TwoNorm(rB));
// KRATOS_WATCH("ln324");
        VectorType p(r);
        VectorType s(size);
        VectorType q(size);

        VectorType rs(r);
        VectorType qs(size);

        DataType roh0 = TSparseSpaceType::Dot(r, rs);
        DataType roh1 = roh0;
        DataType alpha = 0.00;
        DataType beta = 0.00;
        DataType omega = 0.00;
// KRATOS_WATCH("ln337");
//  if(roh0 < 1e-30) //we start from the real solution
//      return  BaseType::IsConverged();

        do
        {
            this->PreconditionedMult(rA,p,q);
// KRATOS_WATCH("ln344");
            alpha = TSparseSpaceType::Dot(rs,q);
            if (std::abs(alpha) <= 1.0e-40)
                break;
            alpha = roh0 / alpha;

            TSparseSpaceType::ScaleAndAdd(1.00, r, -alpha, q, s);
// KRATOS_WATCH("ln348");
            this->PreconditionedMult(rA,s,qs);

            omega = TSparseSpaceType::Dot(qs,qs);

            //if(omega == 0.00)
            if(std::abs(omega) <= 1.0e-40)
                break;
// KRATOS_WATCH("ln356");
            omega = TSparseSpaceType::Dot(qs,s) / omega;

            TSparseSpaceType::ScaleAndAdd(alpha, p, 1.00, rX);
            TSparseSpaceType::ScaleAndAdd(omega, s, 1.00, rX);
            TSparseSpaceType::ScaleAndAdd(-omega, qs, 1.00, s, r);

            roh1 = TSparseSpaceType::Dot(r,rs);

            //if((roh0 == 0.00) || (omega == 0.00))
            if((std::abs(roh0) <= 1.0e-40) || (std::abs(omega) <= 1.0e-40))
                break;

            beta = (roh1 * alpha) / (roh0 * omega);
// KRATOS_WATCH("ln370");
            TSparseSpaceType::ScaleAndAdd(1.00, p, -omega, q);
            TSparseSpaceType::ScaleAndAdd(1.00, r, beta, q, p);

            roh0 = roh1;

            BaseType::mResidualNorm = std::abs(TSparseSpaceType::TwoNorm(r));
            BaseType::mIterationsNumber++;

        }
        while(BaseType::IterationNeeded());

        return BaseType::IsConverged();
    }

    ///@}
    ///@name Private  Access
    ///@{


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}

}; // Class BICGSTABSolver

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

}  // namespace Kratos.

#endif // KRATOS_BICGSTAB_SOLVER_H_INCLUDED  defined
