#if !defined(KRATOS_SUPERLU_SOLVER_H_INCLUDED )
#define  KRATOS_SUPERLU_SOLVER_H_INCLUDED

// #define BOOST_NUMERIC_BINDINGS_SUPERLU_PRINT

// External includes
#include "boost/smart_ptr.hpp"
// #include "utilities/superlu_interface.h"
#include "includes/ublas_interface.h"
//#include "boost/numeric/bindings/superlu/superlu.hpp"
// #include "boost/numeric/bindings/traits/traits.hpp"
// #include <boost/numeric/bindings/traits/ublas_sparse.hpp>
// #include "boost/numeric/bindings/traits/ublas_matrix.hpp"
// #include "structural_application/custom_utilities/ublas_matrix.hpp"
// #include "boost/numeric/bindings/traits/ublas_vector2.hpp"

// #include <boost/numeric/bindings/traits/sparse_traits.hpp>
// #include <boost/numeric/bindings/traits/ublas_matrix.hpp>
// #include <boost/numeric/bindings/traits/ublas_sparse.hpp>
// #include <boost/numeric/bindings/traits/ublas_vector.hpp>

#include <numeric/bindings/traits/sparse_traits.hpp>

#include "utilities/superlu.hpp"
// #include <boost/numeric/bindings/superlu/superlu.hpp>
#include <numeric/bindings/traits/ublas_matrix.hpp>
#include <numeric/bindings/traits/ublas_sparse.hpp>
#include <numeric/bindings/traits/ublas_vector.hpp>

// Project includes
#include "includes/define.h"
#include "linear_solvers/direct_solver.h"
namespace slu = boost::numeric::bindings::superlu;
namespace ublas = boost::numeric::ublas;

namespace Kratos
{
template< class TSparseSpaceType, class TDenseSpaceType,
          class TReordererType = Reorderer<TSparseSpaceType, TDenseSpaceType> >
class SuperLUSolver : public DirectSolver< TSparseSpaceType,
    TDenseSpaceType, TReordererType>
{
public:
    /**
     * Counted pointer of SuperLUSolver
     */
    KRATOS_CLASS_POINTER_DEFINITION( SuperLUSolver );

    typedef LinearSolver<TSparseSpaceType, TDenseSpaceType, TReordererType> BaseType;

    typedef typename TSparseSpaceType::MatrixType SparseMatrixType;

    typedef typename TSparseSpaceType::VectorType VectorType;

    typedef typename TDenseSpaceType::MatrixType DenseMatrixType;

    /**
     * Default constructor
     */
    SuperLUSolver() {}

    /**
     * Destructor
     */
    virtual ~SuperLUSolver() {}

    /**
     * Normal solve method.
     * Solves the linear system Ax=b and puts the result on SystemVector& rX.
     * rX is also th initial guess for iterative methods.
     * @param rA. System matrix
     * @param rX. Solution vector.
     * @param rB. Right hand side vector.
     */
    bool Solve(SparseMatrixType& rA, VectorType& rX, VectorType& rB)
    {
        //std::cout << "matrix size in solver: " << rA.size1() << std::endl;
        //std::cout << "RHS size in solver: " << rB.size() << std::endl;
        typedef boost::numeric::bindings::traits::sparse_matrix_traits<SparseMatrixType> matraits;
        typedef typename matraits::value_type val_t;

        typedef ublas::compressed_matrix<double, ublas::row_major, 0,
                ublas::unbounded_array<int>, ublas::unbounded_array<double> > cm_t;
        typedef ublas::matrix<double, ublas::row_major> m_t;

        if(IsNotConsistent(rA, rX, rB))
            return false;

        //manually create RHS matrix
        m_t b( rB.size(), 1 );
        for( int i=0; i<rB.size(); i++ )
        {
//                     if( ! (abs(rB[i])< 1.0e-15) )
            b(i,0) = rB[i];
//                     else b[i][0] = 0.0;
        }

//                 KRATOS_WATCH(b);

//                 for( int i=0; i< rA.index1_data().size(); i++ )
//                 {
//                     std::cout << rA.index1_data()[i]  << " ";
//                     row_index_vector[i] = rA.index1_data()[i];
//                 }
//                 std::cout << std::endl;
//                 for( int i=0; i< rA.index2_data().size(); i++ )
//                 {
//                     std::cout << rA.index2_data()[i]  << " ";
// //                     row_index_vector[i] = rA.index1_data()[i];
//                 }
//                 std::cout << std::endl;

        //call solver routine
        slu::gssv (rA, b, slu::atpla_min_degree);

        //resubstitution of results
        for( int i=0; i<rB.size(); i++ )
        {
            rX[i] = b(i,0);
        }

        return true;
    }

    /**
     * Multi solve method for solving a set of linear systems with same coefficient matrix.
     * Solves the linear system Ax=b and puts the result on SystemVector& rX.
     * rX is also th initial guess for iterative methods.
     * @param rA. System matrix
     * @param rX. Solution vector.
     * @param rB. Right hand side vector.
     */
    bool Solve(SparseMatrixType& rA, DenseMatrixType& rX, DenseMatrixType& rB)
    {
        //std::cout << "matrix size in solver: " << rA.size1() << std::endl;
        //std::cout << "RHS size in solver: " << rB.size() << std::endl;
        typedef boost::numeric::bindings::traits::sparse_matrix_traits<SparseMatrixType> matraits;
        typedef typename matraits::value_type val_t;

        typedef ublas::compressed_matrix<double, ublas::row_major, 0,
                ublas::unbounded_array<int>, ublas::unbounded_array<double> > cm_t;
        typedef ublas::matrix<double, ublas::row_major> m_t;

        if(IsNotConsistent(rA, rX, rB))
            return false;

        //manually create RHS matrix
        m_t b( rB.size1(), rB.size2() );
        for( int i=0; i<rB.size1(); i++ )
            for( int j=0; j<rB.size2(); j++ )
                b(i, j) = rB(i, j);

        //call solver routine
        slu::gssv (rA, b, slu::atpla_min_degree);

        //resubstitution of results
/*        for( int i=0; i<rB.size(); i++ )*/
/*            for( int j=0; j<rB.size2(); j++ )*/
/*                rX(i, j) = b(i, j);*/
        noalias(rX) = b;

        return is_solved;
    }

    /// Turn back information as a string.
    std::string Info() const override
    {
        return "SuperLUSolver";
    }

    /**
     * Print information about this object.
     */
    void  PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << "SuperLU solver finished.";
    }

private:

    /**
     * Assignment operator.
     */
    SuperLUSolver& operator=(const SuperLUSolver& Other);

    /**
     * Copy constructor.
     */
    SuperLUSolver(const SuperLUSolver& Other);

}; // Class SkylineLUFactorizationSolver

}  // namespace Kratos.

#endif // KRATOS_SUPERLU_SOLVER_H_INCLUDED  defined
