//
//   Project Name:        Kratos
//   Last Modified by:    $Author: rrossi $
//   Date:                $Date: 2007-03-06 10:30:33 $
//   Revision:            $Revision: 1.2 $
//
//
#if !defined(KRATOS_MIXEDUP_SOLVER_H_INCLUDED )
#define  KRATOS_MIXEDUP_SOLVER_H_INCLUDED
// System includes
#include <string>
#include <iostream>
#include <sstream>
#include <cstddef>
// External includes
// Project includes
#include "includes/define.h"
#include "reorderer.h"
#include "solving_strategies/builder_and_solvers/builder_and_solver.h"
#include "includes/model_part.h"
#include "linear_solvers/iterative_solver.h"
#include <boost/numeric/ublas/vector.hpp>
#include "utilities/openmp_utils.h"

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
/** This solver is designed for the solution of mixed U-P problems.
 * It uses a block structure diving the matrix in UU PP UP PU blocks
 * and uses "standard" linear solvers for the different blocks as well as a GMRES for the outer part
*/
template<class TSparseSpaceType, class TDenseSpaceType,
         class TModelPartType,
         class TPreconditionerType = Preconditioner<TSparseSpaceType, TDenseSpaceType, TModelPartType>,
         class TReordererType = Reorderer<TSparseSpaceType, TDenseSpaceType> >
class MixedUPLinearSolver :
    public IterativeSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TPreconditionerType, TReordererType>
{
public:
    ///@name Type Definitions
    ///@{
    /// Pointer definition of MixedUPLinearSolver
    KRATOS_CLASS_POINTER_DEFINITION (MixedUPLinearSolver);
    typedef IterativeSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TPreconditionerType, TReordererType> BaseType;
    typedef LinearSolver<TSparseSpaceType, TDenseSpaceType, TModelPartType, TReordererType> LinearSolverType;
    typedef typename BaseType::SparseMatrixType SparseMatrixType;
    typedef typename BaseType::VectorType VectorType;
    typedef typename BaseType::DenseMatrixType DenseMatrixType;
    typedef typename BaseType::DenseVectorType DenseVectorType;
    typedef typename BaseType::IndexType IndexType;
    typedef typename BaseType::SizeType SizeType;
    typedef typename BaseType::DataType DataType;
    typedef typename BaseType::ValueType ValueType;
    typedef typename BaseType::ModelPartType ModelPartType;
    ///@}

    ///@name Life Cycle
    ///@{

    /// Default constructor.
    MixedUPLinearSolver (typename LinearSolverType::Pointer psolver_UU_block,
                         typename LinearSolverType::Pointer psolver_PP_block,
                         ValueType NewMaxTolerance,
                         unsigned int NewMaxIterationsNumber,
                         unsigned int m
                        ) : BaseType (NewMaxTolerance, NewMaxIterationsNumber)
    {
        //saving the linear solvers to be used in the solution process
        mpsolver_UU_block = psolver_UU_block;
        mpsolver_PP_block = psolver_PP_block;
        mBlocksAreAllocated = false;
        mis_initialized = false;
        mm = m;
    }

    /// Copy constructor.
    MixedUPLinearSolver (const MixedUPLinearSolver& Other)
    {
        KRATOS_ERROR << "copy constructor not correctly implemented";
    }

    /// Destructor.
    ~MixedUPLinearSolver() override {}

    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    MixedUPLinearSolver& operator= (const MixedUPLinearSolver& Other)
    {
        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    /** This function is designed to be called as few times as possible. It creates the data structures
     * that only depend on the connectivity of the matrix (and not on its coefficients)
     * so that the memory can be allocated once and expensive operations can be done only when strictly
     * needed
    @param rA. System matrix
    @param rX. Solution vector. it's also the initial guess for iterative linear solvers.
    @param rB. Right hand side vector.
    */
    void Initialize (SparseMatrixType& rA, VectorType& rX, VectorType& rB) override
    {
        if (mBlocksAreAllocated == true)
        {
            mpsolver_UU_block->Initialize(mK, mu, mru);
            mpsolver_PP_block->Initialize(mS, mp, mrp);
            mis_initialized = true;
        }
        else
        {
          std::cout << "linear solver intialization is deferred to the moment at which blocks are available" << std::endl;
        }
    }

    /** This function is designed to be called every time the coefficients change in the system
     * that is, normally at the beginning of each solve.
     * For example if we are implementing a direct solver, this is the place to do the factorization
     * so that then the backward substitution can be performed effectively more than once
    @param rA. System matrix
    @param rX. Solution vector. it's also the initial guess for iterative linear solvers.
    @param rB. Right hand side vector.
    */
    void InitializeSolutionStep (SparseMatrixType& rA, VectorType& rX, VectorType& rB) override
    {
        //copy to local matrices
        if (mBlocksAreAllocated == false)
        {
            FillBlockMatrices (true, rA, mK, mG, mD, mS);
            mBlocksAreAllocated = true;
        }
        else
        {
            FillBlockMatrices (false, rA, mK, mG, mD, mS);
            mBlocksAreAllocated = true;
        }

        if(mis_initialized == false) this->Initialize(rA,rX,rB);

        //initialize solvers
        mpsolver_UU_block->InitializeSolutionStep(mK, mu, mru);
        mpsolver_PP_block->InitializeSolutionStep(mS, mp, mrp);
    }

    /** This function actually performs the solution work, eventually taking advantage of what was done before in the
     * Initialize and InitializeSolutionStep functions.
    @param rA. System matrix
    @param rX. Solution vector. it's also the initial guess for iterative linear solvers.
    @param rB. Right hand side vector.
    */
    void PerformSolutionStep (SparseMatrixType& rA, VectorType& rX, VectorType& rB) override
    {
        unsigned int m = mm;
        unsigned int max_iter = BaseType::GetMaxIterationsNumber();
        ValueType tol = BaseType::GetTolerance();
        gmres_solve (rA,rX,rB,m,max_iter,tol);
    }

    /** This function is designed to be called at the end of the solve step.
     * for example this is the place to remove any data that we do not want to save for later
    @param rA. System matrix
    @param rX. Solution vector. it's also the initial guess for iterative linear solvers.
    @param rB. Right hand side vector.
    */
    void FinalizeSolutionStep (SparseMatrixType& rA, VectorType& rX, VectorType& rB) override
    {
        mpsolver_UU_block->FinalizeSolutionStep(mK, mu, mru);
        mpsolver_PP_block->FinalizeSolutionStep(mS, mp, mrp);
    }

    /** This function is designed to clean up all internal data in the solver.
     * Clear is designed to leave the solver object as if newly created.
     * After a clear a new Initialize is needed
     */
    void Clear() override
    {
        mK.clear();
        mG.clear();
        mD.clear();
        mS.clear();
        mBlocksAreAllocated = false;
        mpsolver_UU_block->Clear();
        mpsolver_PP_block->Clear();
        mu.clear();
        mp.clear();
        mru.clear();
        mrp.clear();
        mis_initialized = false;
    }

    /** Normal solve method.
    Solves the linear system Ax=b and puts the result on SystemVector& rX.
    rVectorx is also th initial guess for iterative methods.
    @param rA. System matrix
    @param rX. Solution vector. it's also the initial
    guess for iterative linear solvers.
     @param rB. Right hand side vector.
    */
    bool Solve(SparseMatrixType& rA, VectorType& rX, VectorType& rB) override
    {
        if (mis_initialized == false)
            this->Initialize (rA,rX,rB);

        this->InitializeSolutionStep (rA,rX,rB);

        this->PerformSolutionStep (rA,rX,rB);

        this->FinalizeSolutionStep (rA,rX,rB);

        return false;
    }

    /** Multi solve method for solving a set of linear systems with same coefficient matrix.
    Solves the linear system Ax=b and puts the result on SystemVector& rX.
    rVectorx is also th initial guess for iterative methods.
    @param rA. System matrix
    @param rX. Solution vector. it's also the initial
    guess for iterative linear solvers.
     @param rB. Right hand side vector.
    */
    bool Solve (SparseMatrixType& rA, DenseMatrixType& rX, DenseMatrixType& rB) override
    {
        return false;
    }

    /** Eigenvalue and eigenvector solve method for derived eigensolvers */
    virtual  void Solve (SparseMatrixType& K,
                         SparseMatrixType& M,
                         DenseVectorType& Eigenvalues,
                         DenseMatrixType& Eigenvectors)
    {}

    /** Some solvers may require a minimum degree of knowledge of the structure of the matrix. To make an example
     * when solving a mixed u-p problem, it is important to identify the row associated to v and p.
     * another example is the automatic prescription of rotation null-space for smoothed-aggregation solvers
     * which require knowledge on the spatial position of the nodes associated to a given dof.
     * This function tells if the solver requires such data
     */
    bool AdditionalPhysicalDataIsNeeded() override
    {
        return true;
    }

    /** Some solvers may require a minimum degree of knowledge of the structure of the matrix. To make an example
     * when solving a mixed u-p problem, it is important to identify the row associated to v and p.
     * another example is the automatic prescription of rotation null-space for smoothed-aggregation solvers
     * which require knowledge on the spatial position of the nodes associated to a given dof.
     * This function is the place to eventually provide such data
     */
    void ProvideAdditionalData (
        SparseMatrixType& rA,
        VectorType& rX,
        VectorType& rB,
        typename ModelPartType::DofsArrayType& rdof_set,
        ModelPartType& r_model_part
    ) override
    {
        //count pressure dofs
        unsigned int n_pressure_dofs = 0;
        unsigned int tot_active_dofs = 0;
        for (auto it = rdof_set.begin(); it!=rdof_set.end(); it++)
        {
          if (it->EquationId() < rA.size1())
          {
              tot_active_dofs += 1;
              if (it->GetVariable().Key() == PRESSURE)
              n_pressure_dofs += 1;
          }
        }

        if (tot_active_dofs != rA.size1() )
            KRATOS_ERROR << "total system size does not coincide with the free dof map";

        //resize arrays as needed
        mpressure_indices.resize (n_pressure_dofs,false);

        unsigned int other_dof_size = tot_active_dofs - n_pressure_dofs;
        mother_indices.resize (other_dof_size,false);
        mglobal_to_local_indexing.resize (tot_active_dofs,false);
        mis_pressure_block.resize (tot_active_dofs,false);
        //construct aux_lists as needed
        //"other_counter[i]" i will contain the position in the global system of the i-th NON-pressure node
        //"pressure_counter[i]" will contain the in the global system of the i-th NON-pressure node
        //
        //mglobal_to_local_indexing[i] will contain the position in the local blocks of the
        unsigned int pressure_counter = 0;
        unsigned int other_counter = 0;
        unsigned int global_pos = 0;
        for (auto it = rdof_set.begin(); it!=rdof_set.end(); it++)
        {
            if (it->EquationId() < rA.size1())
            {
                if (it->GetVariable().Key() == PRESSURE)
                {
                    mpressure_indices[pressure_counter] = global_pos;
                    mglobal_to_local_indexing[global_pos] = pressure_counter;
                    mis_pressure_block[global_pos] = true;
                    pressure_counter++;
                }
                else
                {
                    mother_indices[other_counter] = global_pos;
                    mglobal_to_local_indexing[global_pos] = other_counter;
                    mis_pressure_block[global_pos] = false;
                    other_counter++;
                }
                global_pos++;
            }
        }
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
    /// Turn back information as a string.
    std::string Info() const override
    {
        return "Linear solver";
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
    ///this function generates the subblocks of matrix A
    ///as A = ( K G ) u
    ///       ( D S ) p
    /// subblocks are allocated or nor depending on the value of "need_allocation"
    void FillBlockMatrices (bool need_allocation, SparseMatrixType& rA, SparseMatrixType& K, SparseMatrixType& G, SparseMatrixType& D, SparseMatrixType& S )
    {
        KRATOS_TRY
        //get access to A data
        const std::size_t* index1 = rA.index1_data().begin();
        const std::size_t* index2 = rA.index2_data().begin();
        const auto*        values = rA.value_data().begin();

        SparseMatrixType L(mpressure_indices.size(),mpressure_indices.size() );

        if (need_allocation == true)
        {
            K.clear();
            G.clear();
            D.clear();
            S.clear();
            L.clear();

            //do allocation
            K.resize (mother_indices.size()   ,mother_indices.size() );
            G.resize (mother_indices.size()   ,mpressure_indices.size() );
            D.resize (mpressure_indices.size(),mother_indices.size() );
            S.resize (mpressure_indices.size(),mpressure_indices.size() );

            mrp.resize(mpressure_indices.size() );
            mru.resize(mother_indices.size() );
            mp.resize(mpressure_indices.size());
            mu.resize(mother_indices.size());

            //KRATOS_WATCH (mglobal_to_local_indexing);
            //allocate the blocks by push_back
            for (unsigned int i=0; i<rA.size1(); i++)
            {
                unsigned int row_begin = index1[i];
                unsigned int row_end   = index1[i+1];
                unsigned int local_row_id = mglobal_to_local_indexing[i];

                if ( mis_pressure_block[i] == false) //either K or G
                {
                    for (unsigned int j=row_begin; j<row_end; j++)
                    {
                        unsigned int col_index = index2[j];
                        const auto value = values[j];
                        unsigned int local_col_id = mglobal_to_local_indexing[col_index];
                        if (mis_pressure_block[col_index] == false) //K block
                            K.push_back ( local_row_id, local_col_id, value);
                        else //G block
                            G.push_back ( local_row_id, local_col_id, value);
                    }
                }
                else //either D or S
                {
                    for (unsigned int j=row_begin; j<row_end; j++)
                    {
                        unsigned int col_index = index2[j];
                        const auto value = values[j];
                        unsigned int local_col_id = mglobal_to_local_indexing[col_index];
                        if (mis_pressure_block[col_index] == false) //D block
                            D.push_back ( local_row_id, local_col_id, value);
                        else //S block
                            L.push_back ( local_row_id, local_col_id, value);
                    }
                }
            }

            //allocate the schur complement
            ConstructSystemMatrix(S,G,D,L);

            VectorType diagK (mother_indices.size() );
            ComputeDiagonalByLumping (K,diagK);

            //fill the shur complement
            CalculateShurComplement(S,K,G,D,L,diagK);


        }
        else //allocation is not needed so only do copying
        {
            for (unsigned int i=0; i<rA.size1(); i++)
            {
                unsigned int row_begin = index1[i];
                unsigned int row_end   = index1[i+1];
                unsigned int local_row_id =  mglobal_to_local_indexing[i];
                if ( mis_pressure_block[i] == false ) //either K or G
                {
                    for (unsigned int j=row_begin; j<row_end; j++)
                    {
                        unsigned int col_index = index2[j];
                        const auto value = values[j];
                        unsigned int local_col_id = mglobal_to_local_indexing[col_index];
                        if (mis_pressure_block[col_index] == false) //K block
                            K( local_row_id, local_col_id) = value;
                        else //G block
                            G( local_row_id, local_col_id) = value;
                    }
                }
                else //either D or S
                {
                    for (unsigned int j=row_begin; j<row_end; j++)
                    {
                        unsigned int col_index = index2[j];
                        const auto value = values[j];
                        unsigned int local_col_id = mglobal_to_local_indexing[col_index];
                        if (mis_pressure_block[col_index] == false) //D block
                            D( local_row_id, local_col_id) = value;
                        else //S block
                            L( local_row_id, local_col_id) = value;
                    }
                }
            }

            VectorType diagK (mother_indices.size() );
            ComputeDiagonalByLumping (K,diagK);

            //fill the shur complement
            CalculateShurComplement(S,K,G,D,L,diagK);

        }





        KRATOS_CATCH ("")
    }
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
    /// A counted pointer to the reorderer object.
    typename LinearSolverType::Pointer mpsolver_UU_block;
    typename LinearSolverType::Pointer mpsolver_PP_block;
    unsigned int mm;
    bool mBlocksAreAllocated;
    bool mis_initialized;
    boost::numeric::ublas::vector<IndexType> mpressure_indices;
    boost::numeric::ublas::vector<IndexType> mother_indices;
    boost::numeric::ublas::vector<unsigned int> mglobal_to_local_indexing;
    boost::numeric::ublas::vector<bool> mis_pressure_block;
    SparseMatrixType mK;
    SparseMatrixType mG;
    SparseMatrixType mD;
    SparseMatrixType mS;

    VectorType mrp;
    VectorType mru;
    VectorType mp;
    VectorType mu;

    ///@}
    ///@name Private Operators
    ///@{
    inline void GeneratePlaneRotation (const DataType dx, const DataType dy, DataType& cs, DataType& sn)
    {
        if (std::abs(dy) == 0.0)
        {
            cs = 1.0;
            sn = 0.0;
        }
        else if (std::abs(dx) == 0.0)
        {
            cs = 0.0;
            sn = 1.0;
        }
        else
        {
            const DataType rnorm = 1/std::sqrt(dx*dx + dy*dy);
            cs = std::abs(dx) * rnorm;
            sn = cs * dy / dx;
        }
    }

    inline void ApplyPlaneRotation (DataType& dx, DataType& dy, const DataType cs, const DataType sn)
    {
        DataType temp  =  cs * dx + sn * dy;
        dy = cs * dy - sn * dx;
        dx = temp;
    }

    void Update (VectorType& y, VectorType& x, int k, DenseMatrixType& h, VectorType& s, std::vector< VectorType >& V)
    {
        for (unsigned int i=0; i<s.size(); i++)
            y[i] = s[i];
        /*      for(unsigned int i=s.size(); i<y.size(); i++)
                    y[i] = 0.0;*/
        // Backsolve:
        for (int i = k; i >= 0; --i)
        {
            y (i) /= h (i,i);
            for (int j = i - 1; j >= 0; --j)
                y (j) -= h (j,i) * y (i);
        }
        //create new search dir
        for (int j = 0; j <= k; ++j)
            TSparseSpaceType::UnaliasedAdd (x, y[j], V[j]);   // x +=  y(j)* V[j];
    }

    int gmres_solve ( SparseMatrixType& A,
                      VectorType& x,
                      const VectorType& b,
                      unsigned int m,
                      unsigned int max_iter,
                      ValueType tol)
    {
        const unsigned int dim = A.size1();
        if (m == 0)
            KRATOS_ERROR << "the dimension of the GMRES krylov space can not be set to zero. Please change the value of m";
            if (m > max_iter)
                m = max_iter;
        VectorType s (m+1), sn (m+1), w (dim), r (dim), y (m+1);
        VectorType cs (m+1);
        DenseMatrixType H (m+1, m+1);
        int restart = 0;
        //preconditioner solve b and store in Minv_b
        VectorType preconditioned_b (dim);
        //TSparseSpaceType::Copy(b, preconditioned_b); //preconditioned_b=b
        //apply preconditioner
        SolveBlockPreconditioner (b,preconditioned_b);
        ValueType normb = std::abs(TSparseSpaceType::TwoNorm (preconditioned_b));
        /*KRATOS_WATCH(normb);*/
        if (normb < 1e-16) //ARBITRARY SMALL NUMBER!
        {
            normb = 1e-16;
        }
        //r = b - Ax
        TSparseSpaceType::Mult (A,x,r);
        TSparseSpaceType::ScaleAndAdd (1.00, b, -1.00, r); //r = b - r
        //apply preconditioner and overwrite r
        SolveBlockPreconditioner (r,r);
        const ValueType rel_tol = tol*normb;
        ValueType beta = std::abs(TSparseSpaceType::TwoNorm(r));
        if (beta <= rel_tol)   //finalize!
        {
            tol = beta / normb;
            max_iter = 0;
            return 0;
        }
        unsigned int j;
//        int err = 0;
        std::vector< VectorType > V (m+1);
        for (j = 0; j <= m; ++j)
            V[j].resize (dim,false);
        j = 1;
        while (j <= max_iter)
        {
            TSparseSpaceType::Assign (V[0], 1.0/beta, r); //V[0] = r /(T)beta;
            TSparseSpaceType::SetToZero (s);
            s[0] = beta;
            for (unsigned int i = 0; (i < m) && (j <= max_iter); ++i, ++j)
            {
                TSparseSpaceType::Mult (A,V[i],w); //w = A*V[i];
                //apply preconditioner and overwrite r
                SolveBlockPreconditioner (w,w);
                for (unsigned int k = 0; k <= i; k++)
                {
                    H (k, i) = TSparseSpaceType::Dot (V[k], w);
                    w -= H (k, i) * V[k];
                }
                const DataType normw = TSparseSpaceType::TwoNorm (w);
                H (i+1, i) = normw;
                /*KRATOS_WATCH(normw);*/
                // This breakdown is a good one ...
                if (std::abs(normw) == 0)
                    TSparseSpaceType::Copy (V[i+1], w); //V[i+1] = w;
                else
                    TSparseSpaceType::Assign (V[i+1], 1/normw, w); //V[i+1] = w / normw;
                for (unsigned int k = 0; k < i; k++)
                    ApplyPlaneRotation (H (k,i), H (k+1,i), cs (k), sn (k) );
                GeneratePlaneRotation (H (i,i), H (i+1,i), cs (i), sn (i) );
                ApplyPlaneRotation (H (i,i), H (i+1,i), cs (i), sn (i) );
                ApplyPlaneRotation (s (i), s (i+1), cs (i), sn (i) );
                beta = std::abs(s (i+1) );
        std::cout << "iter = " <<  j << "  estimated res ratio = " << beta << std::endl;
//                 KRATOS_WATCH (beta);
                if (beta <= rel_tol)
                {
                    this->Update (y, x, i, H, s, V);
                    return 0;
                }
            }
            this->Update (y,x, m - 1, H, s, V);
            //r = b - Ax
            TSparseSpaceType::Mult (A,x,r);
            TSparseSpaceType::ScaleAndAdd (1.00, b, -1.00, r); //r = b - r
            beta = std::abs(TSparseSpaceType::TwoNorm (r));

        std::cout << "number of iterations at convergence = " << j << std::endl;
            if (beta < rel_tol)
            {
                return 0;
            }
            ++restart;
        }
//        err = 1;
        return 1;
    }

    //this function extracts from a vector which has the size of the
    //overall r, the part that corresponds to u-dofs
    void GetUPart (const VectorType& rtot, VectorType& ru)
    {
        if (ru.size() != mother_indices.size() )
            ru.resize (mother_indices.size(), false);
        #pragma omp parallel for
        for (int i = 0; i<static_cast<int>(ru.size()); i++)
            ru[i] = rtot[mother_indices[i]];
    }

    //this function extracts from a vector which has the size of the
    //overall r, the part that corresponds to p-dofs
    void GetPPart (const VectorType& rtot, VectorType& rp)
    {
        if (rp.size() != mpressure_indices.size() )
            rp.resize (mpressure_indices.size(), false);
        #pragma omp parallel for
        for (int i = 0; i<static_cast<int>(rp.size()); i++)
            rp[i] = rtot[mpressure_indices[i]];
    }

    void WriteUPart (VectorType& rtot, const VectorType& ru)
    {
        #pragma omp parallel for
        for (int i = 0; i< static_cast<int>(ru.size()); i++)
            rtot[mother_indices[i]] = ru[i];
    }

    void WritePPart (VectorType& rtot, const VectorType& rp)
    {
        #pragma omp parallel for
        for (int i = 0; i< static_cast<int>(rp.size()); i++)
            rtot[mpressure_indices[i]] = rp[i];
    }

    void ComputeDiagonalByLumping (const SparseMatrixType& A, VectorType& diagA)
    {
        if (diagA.size() != A.size1() )
            diagA.resize (A.size1() );
        //get access to A data
        const auto* index1 = A.index1_data().begin();
//        const auto* index2 = A.index2_data().begin();
        const auto* values = A.value_data().begin();

        #pragma omp parallel for
        for (int i=0; i< static_cast<int>(A.size1()); i++)
        {
            unsigned int row_begin = index1[i];
            unsigned int row_end   = index1[i+1];
            DataType temp = 0.0;
            for (unsigned int j=row_begin; j<row_end; j++)
                temp += values[j]*values[j];

            diagA[i] = sqrt(temp);
        }
    }

    DataType CheckMatrix (const SparseMatrixType& A)
    {
        //get access to A data
        const auto* index1 = A.index1_data().begin();
        const auto* index2 = A.index2_data().begin();
        const auto* values = A.value_data().begin();
        DataType norm = 0.0;
        for (unsigned int i=0; i<A.size1(); i++)
        {
            unsigned int row_begin = index1[i];
            unsigned int row_end   = index1[i+1];
            if (row_end - row_begin == 0)
                std::cout << "line " << i << " has no elements" << std::endl;
            //KRATOS_ERROR << "line found with no entries on line " << i;
            for (unsigned int j=row_begin; j<row_end; j++)
            {
                if (index2[j]>A.size2() )
                    KRATOS_ERROR << "array above size of A";
                    norm += values[j]*values[j];
            }
        }
        return sqrt (norm);
    }

    void SolveBlockPreconditioner (const VectorType& rtot, VectorType& x)
    {
        noalias(mp) = ZeroVector(mother_indices.size());
        noalias(mu)  = ZeroVector(mother_indices.size());
        VectorType uaux (mother_indices.size() );
        VectorType paux (mpressure_indices.size() );

        //get diagonal of K (to be removed)
        VectorType diagK (mother_indices.size() );
        ComputeDiagonalByLumping (mK,diagK);

    //get the u and p residuals
        GetUPart (rtot,mru);
        GetPPart (rtot,mrp);

    //solve u block
        mpsolver_UU_block->Solve (mK,mu,mru);

    //correct pressure block
        //rp -= D*u
        TSparseSpaceType::Mult (mD,mu,paux);
        TSparseSpaceType::UnaliasedAdd (mrp,-1.0,paux);

    //solve pressure
        //p = S⁻1*rp
        mpsolver_PP_block->Solve (mS,mp,mrp);

        //correct u block
        //u = G*p
        TSparseSpaceType::Mult (mG,mp,uaux);
        #pragma omp parallel for
        for (int i=0; i< static_cast<int>(mu.size()); i++)
            mu[i] += uaux[i]/diagK[i];

        //write back solution
        WriteUPart (x,mu);
        WritePPart (x,mp);
    }

    /// Compute the Pressure System Matrix
    /**
     *  Compute the System Matrix A = L - D*Inv(Diag(S))*G. The multiplication
     * is performed in random order, so each row will be stored in a temporary
     * variable, ordered and copied in input matrix A.
     */
    void CalculateShurComplement (
        SparseMatrixType& A,
        SparseMatrixType& K,
        SparseMatrixType& rG,
        SparseMatrixType& rD,
        SparseMatrixType& rL,
        VectorType& diagK
    )
    {
        // Retrieve matrices

        // Compute Inv(Diag(S))
        VectorType& rIDiagS = diagK;


        //KRATOS_WATCH(804)

        typedef boost::numeric::ublas::vector<int> IndexVector;
        //typedef typename SparseMatrixType::iterator1 OuterIt;
        //typedef typename SparseMatrixType::iterator2 InnerIt;
        typedef typename boost::numeric::ublas::matrix_row< SparseMatrixType > RowType;

        int DiagSize = int (diagK.size()); // to avoid comparison between int & unsigned int
        #pragma omp parallel for
        for ( int i = 0; i < DiagSize; i++)
            rIDiagS[i] = 1/diagK[i];
        OpenMPUtils::PartitionVector Partition;
        int NumThreads = OpenMPUtils::GetNumThreads();
        OpenMPUtils::DivideInPartitions (A.size1(),NumThreads,Partition);
        #pragma omp parallel
        {
            int k = OpenMPUtils::ThisThread();
            VectorType CurrentRow(K.size2());

            for (unsigned int i = 0; i < rL.size1(); i++) CurrentRow[i] = 0.0;

            IndexVector Next = IndexVector(rL.size1());
//IndexVector& Next = *pNext; // Keeps track of which columns were filled
            for (unsigned int m=0; m < rL.size1(); m++) Next[m] = -1;
            std::size_t NumTerms = 0; // Full positions in a row
            std::vector<unsigned int> UsedCols = std::vector<unsigned int>();
//             std::vector<unsigned int>& UsedCols = *pUsedCols;
            UsedCols.reserve (rL.size1());
            for ( int RowIndex = Partition[k] ;
                    RowIndex != Partition[k+1] ; RowIndex++ )
            {
                RowType RowD (rD,RowIndex);
                RowType RowL (rL,RowIndex);
                int head = -2;
                std::size_t Length = 0;
                // Write L in A
                for ( typename RowType::iterator ItL = RowL.begin();
                        ItL != RowL.end(); ItL++ )
                {
                    CurrentRow (ItL.index() ) = *ItL;
                    if ( Next[ItL.index()] == -1)
                    {
                        Next[ItL.index()] = head;
                        head = ItL.index();
                        Length++;
                    }
                }
                // Substract D*Inv(Diag(S))*G
                for ( typename RowType::iterator ItD = RowD.begin();
                        ItD != RowD.end(); ItD++ )
                {
                    RowType RowG (rG,ItD.index() );
                    for ( typename RowType::iterator ItG = RowG.begin();
                            ItG != RowG.end(); ItG++ )
                    {
                        CurrentRow[ItG.index()] -= (*ItD) * rIDiagS[ItD.index()] * (*ItG);
                        if ( Next[ItG.index()] == -1)
                        {
                            Next[ItG.index()] = head;
                            head = ItG.index();
                            Length++;
                        }
                    }
                }
                // Identify full terms for ordering
                for ( std::size_t i = 0; i < Length; i++)
                {
                    if ( Next[head] != -1 )
                    {
                        UsedCols.push_back (head);
                        NumTerms++;
                    }
                    int temp = head;
                    head = Next[head];
                    // Clear 'Next' for next iteration
                    Next[temp] = -1;
                }
                // Sort Column indices
                SortCols (UsedCols,NumTerms);
                // Fill matrix row, then clean temporary variables.
                RowType RowA (A,RowIndex);
                std::size_t n = 0;
                unsigned int Col;
                for ( typename RowType::iterator ItA = RowA.begin(); ItA != RowA.end(); ItA++)
                {
                    Col = UsedCols[n++];
                    *ItA = CurrentRow[Col];
                    CurrentRow[Col] = 0;
                }
                NumTerms = 0;
                UsedCols.resize (0,false);
            }


        }
        //KRATOS_WATCH(896)
        //add stabilization matrix L
        /*              const std::size_t* L_index1 = rL.index1_data().begin();
                        const std::size_t* L_index2 = rL.index2_data().begin();
                        const double*      L_values = rL.value_data().begin();
                        for (unsigned int i=0; i<rL.size1(); i++)
                        {
                            unsigned int row_begin = L_index1[i];
                            unsigned int row_end   = L_index1[i+1];
                            diagA[i] = 0.0;
                            for (unsigned int j=row_begin; j<row_end; j++)
                            {
                                unsigned int col = L_index2[j];
                                rS(i,col) += L_values[j];
                            }
                        }*/

    }

    /// Helper function for Sytem matrix functions
    void SortCols (
        std::vector<unsigned int>& ColList,
        std::size_t& NumCols)
    {
        bool swap = true;
        unsigned int d = NumCols;
        int temp;
        while ( swap || d > 1 )
        {
            swap = false;
            d = (d+1) /2;
            for ( unsigned int i=0; i< (NumCols - d); i++)
                if ( ColList[i+d] < ColList[i] )
                {
                    temp = ColList[i+d];
                    ColList[i+d] = ColList[i];
                    ColList[i] = temp;
                    swap = true;
                }
        }
    }

    /// Identify non-zero tems in the system matrix
    void ConstructSystemMatrix(
        SparseMatrixType& A,
        SparseMatrixType& rG,
        SparseMatrixType& rD,
        SparseMatrixType& rL
    )
    {
        typedef boost::numeric::ublas::vector<int> IndexVector;
        typedef OpenMPUtils::PartitionVector PartitionVector;
        //typedef typename SparseMatrixType::iterator1 OuterIt;
        //typedef typename SparseMatrixType::iterator2 InnerIt;
        typedef typename boost::numeric::ublas::matrix_row< SparseMatrixType > RowType;

        PartitionVector Partition;
        int NumThreads = OpenMPUtils::GetNumThreads();

        OpenMPUtils::DivideInPartitions(A.size1(),NumThreads,Partition);

        for ( int k = 0 ; k < NumThreads ; k++)
        {
            // This code is serial, the pragma is here to ensure that each
            // row block is assigned to the processor that will fill it
            #pragma omp parallel
            if ( OpenMPUtils::ThisThread() == k)
            {
//                 boost::shared_ptr< IndexVector > pNext( new IndexVector(rL.size1() ) );
//                 IndexVector& Next = *pNext; // Keeps track of which columns were filled
                IndexVector Next(rL.size1());
                for (unsigned int m = 0; m < rL.size1(); m++) Next[m] = -1;

                std::size_t NumTerms = 0; // Full positions in a row
                std::vector<unsigned int> UsedCols;
//                 std::vector<unsigned int>& UsedCols = *pUsedCols;
                UsedCols.reserve(rL.size1());

                for ( int RowIndex = Partition[k] ;
                        RowIndex != Partition[k+1] ; RowIndex++ )
                {
                    RowType RowD(rD,RowIndex);
                    RowType RowL(rL,RowIndex);

                    int head = -2;
                    std::size_t Length = 0;

                    // Terms filled by L
                    for ( typename RowType::iterator ItL = RowL.begin();
                            ItL != RowL.end(); ItL++ )
                    {
                        if ( Next[ItL.index()] == -1)
                        {
                            Next[ItL.index()] = head;
                            head = ItL.index();
                            Length++;
                        }
                    }

                    // Additional terms due to D*Inv(Diag(S))*G
                    for ( typename RowType::iterator ItD = RowD.begin();
                            ItD != RowD.end(); ItD++ )
                    {
                        RowType RowG(rG,ItD.index());

                        for ( typename RowType::iterator ItG = RowG.begin();
                                ItG != RowG.end(); ItG++ )
                        {
                            if ( Next[ItG.index()] == -1)
                            {
                                Next[ItG.index()] = head;
                                head = ItG.index();
                                Length++;
                            }
                        }
                    }

                    // Identify full terms for ordering
                    for ( std::size_t i = 0; i < Length; i++)
                    {
                        if ( Next[head] != -1 )
                        {
                            UsedCols.push_back(head);
                            NumTerms++;
                        }

                        int temp = head;
                        head = Next[head];

                        // Clear 'Next' for next iteration
                        Next[temp] = -1;
                    }

                    // Sort Column indices
                    SortCols(UsedCols,NumTerms);

                    // Store row in matrix, clean temporary variables
                    for ( unsigned int i = 0; i < NumTerms; i++)
                    {
                        A.push_back(RowIndex,UsedCols[i],0);
                    }
                    NumTerms = 0;
                    UsedCols.resize(0,false);
                }
            }
        }
    }
    ///@}
    ///@name Private Operations
    ///@{
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
}; // Class MixedUPLinearSolver
///@}
///@name Type Definitions
///@{
///@}
///@name Input and output
///@{
///@}
}  // namespace Kratos.
#endif // KRATOS_MIXEDUP_SOLVER_H_INCLUDED  defined
