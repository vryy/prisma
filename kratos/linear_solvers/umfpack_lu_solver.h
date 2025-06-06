#if !defined(KRATOS_UMFPACK_LU_SOLVER_H_INCLUDED )
#define  KRATOS_UMFPACK_LU_SOLVER_H_INCLUDED



// External includes

// Project includes
#include "includes/define.h"
#include "linear_solvers/direct_solver.h"
#include <boost/numeric/bindings/traits/ublas_vector.hpp>
#include <boost/numeric/bindings/traits/ublas_sparse.hpp>
#include <boost/numeric/bindings/umfpack/umfpack.hpp>

namespace umf = boost::numeric::bindings::umfpack;

namespace Kratos
{


template<class TSparseSpaceType, class TDenseSpaceType,
         class TModelPartType,
         class TReordererType = Reorderer<TSparseSpaceType, TDenseSpaceType> >
class UMFpackLUsolver
    : public DirectSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TReordererType>
{
public:

    /// Counted pointer of UMFpackLUsolver
    KRATOS_CLASS_POINTER_DEFINITION(UMFpackLUsolver);

    typedef LinearSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TReordererType> BaseType;

    typedef typename TSparseSpaceType::MatrixType SparseMatrixType;

    typedef typename TSparseSpaceType::VectorType VectorType;

    typedef typename TDenseSpaceType::MatrixType DenseMatrixType;

    /// Default constructor.
    UMFpackLUsolver() {}

    /// Destructor.
    ~UMFpackLUsolver() override {}

    /** Normal solve method.
    Solves the linear system Ax=b and puts the result on SystemVector& rX.
    rX is also th initial guess for iterative methods.
    @param rA. System matrix
    @param rX. Solution vector.
    @param rB. Right hand side vector.
    */
    bool Solve(SparseMatrixType& rA, VectorType& rX, VectorType& rB) override
    {
        KRATOS_TRY

        if(IsNotConsistent(rA, rX, rB))
            return false;

        umf::symbolic_type< TSparseSpaceType::DataType > Symbolic;
        umf::numeric_type< TSparseSpaceType::DataType > Numeric;

        umf::symbolic(A, Symbolic);
        umf::numeric(A, Symbolic, Numeric);
        umf::symbolic(A,x,b,Numeric);

        return true;

        KRATOS_CATCH("");
    }

    /** Multi solve method for solving a set of linear systems with same coefficient matrix.
    Solves the linear system Ax=b and puts the result on SystemVector& rX.
    rX is also th initial guess for iterative methods.
    @param rA. System matrix
    @param rX. Solution vector.
    @param rB. Right hand side vector.
    */
    //bool Solve(SparseMatrixType& rA, DenseMatrixType& rX, DenseMatrixType& rB)
    //{


    //      return is_solved;
    //}

    /// Turn back information as a string.
    std::string Info() const override
    {
        return "UMFpackLUsolver";
    }

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << "Umfpack LU factorization solver finished.";
    }

private:

    /// Assignment operator.
    UMFpackLUsolver& operator=(const UMFpackLUsolver& Other);

    /// Copy constructor.
    UMFpackLUsolver(const UMFpackLUsolver& Other);


}; // Class UMFpackLUsolver

}  // namespace Kratos.

#endif // KRATOS_UMFPACK_LU_SOLVER_H_INCLUDED  defined
