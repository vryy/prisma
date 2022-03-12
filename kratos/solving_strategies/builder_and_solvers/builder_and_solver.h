//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics 
//
//  License:		 BSD License 
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//                    
//
#if !defined(KRATOS_BUILDER_AND_SOLVER )
#define  KRATOS_BUILDER_AND_SOLVER


/* System includes */
#include <set>


/* External includes */
#include "boost/smart_ptr.hpp"


/* Project includes */
#include "includes/define.h"
#include "includes/model_part.h"
#include "solving_strategies/schemes/scheme.h"

//default linear solver
//#include "linear_solvers/linear_solver.h"


namespace Kratos
{

/**@name Kratos Globals */
/*@{ */


/*@} */
/**@name Type Definitions */
/*@{ */

/*@} */


/**@name  Enum's */
/*@{ */


/*@} */
/**@name  Functions */
/*@{ */



/*@} */
/**@name Kratos Classes */
/*@{ */

/** Short class definition.

Detail class definition.

        \URL[Example of use html]{ extended_documentation/no_ex_of_use.html}

          \URL[Example of use pdf]{ extended_documentation/no_ex_of_use.pdf}

                \URL[Example of use doc]{ extended_documentation/no_ex_of_use.doc}

                  \URL[Example of use ps]{ extended_documentation/no_ex_of_use.ps}


                          \URL[Extended documentation html]{ extended_documentation/no_ext_doc.html}

                                \URL[Extended documentation pdf]{ extended_documentation/no_ext_doc.pdf}

                                  \URL[Extended documentation doc]{ extended_documentation/no_ext_doc.doc}

                                        \URL[Extended documentation ps]{ extended_documentation/no_ext_doc.ps}


 */
template<class TSparseSpace,
         class TDenseSpace, // = DenseSpace<double>,
         class TLinearSolver //= LinearSolver<TSparseSpace,TDenseSpace>
         >
class BuilderAndSolver
{
public:


    /**@name Type Definitions */
    /*@{ */
    typedef typename TSparseSpace::DataType TDataType;
    typedef typename TSparseSpace::MatrixType TSystemMatrixType;
    typedef typename TSparseSpace::VectorType TSystemVectorType;

    typedef typename TSparseSpace::MatrixPointerType TSystemMatrixPointerType;
    typedef typename TSparseSpace::VectorPointerType TSystemVectorPointerType;

    typedef typename TDenseSpace::MatrixType LocalSystemMatrixType;
    typedef typename TDenseSpace::VectorType LocalSystemVectorType;

    typedef Scheme<TSparseSpace, TDenseSpace> TSchemeType;
    typedef TLinearSolver TLinearSolverType;
    typedef TSparseSpace TSparseSpaceType;

    typedef ModelPart::DofType TDofType;
    typedef ModelPart::DofsArrayType DofsArrayType;

    //typedef Dof<TDataType> TDofType;
    //typedef PointerVectorSet<TDofType, IdentityFunction<TDofType> > DofsArrayType;

    typedef typename DofsArrayType::iterator DofIterator;
    typedef typename DofsArrayType::const_iterator DofConstantIterator;

    typedef ModelPart::NodesContainerType NodesArrayType;
    typedef ModelPart::ElementsContainerType ElementsArrayType;
    typedef ModelPart::ConditionsContainerType ConditionsArrayType;

    typedef PointerVectorSet<Element, IndexedObject> ElementsContainerType;


    //pointer definition

    KRATOS_CLASS_POINTER_DEFINITION(BuilderAndSolver);


    /*@} */
    /**@name Life Cycle
     */
    /*@{ */

    /** Constructor.
     */
    BuilderAndSolver(
        typename TLinearSolver::Pointer pNewLinearSystemSolver)
    {
        mpLinearSystemSolver = pNewLinearSystemSolver;

        mDofSetIsInitialized = false;

        mReshapeMatrixFlag = false; //by default the matrix is shaped just once
        //		mVectorsAreInitialized = false;
    }

    /** Destructor.
     */
    virtual ~BuilderAndSolver()
    {
    }


    /*@} */
    /**@name Operators
     */

    /*@{ */


    /**
     * Component wise components Get method
     */

    void SetCalculateReactionsFlag(bool flag)
    {
        mCalculateReactionsFlag = flag;
    }

    bool GetCalculateReactionsFlag() const
    {
        return mCalculateReactionsFlag;
    }

    bool GetDofSetIsInitializedFlag() const
    {
        return mDofSetIsInitialized;
    }

    void SetDofSetIsInitializedFlag(bool flag)
    {
        mDofSetIsInitialized = flag;
    }

    void SetReshapeMatrixFlag(bool flag)
    {
        mReshapeMatrixFlag = flag;
    }

    bool GetReshapeMatrixFlag() const
    {
        return mReshapeMatrixFlag;
    }

    unsigned int GetEquationSystemSize() const
    {
        return mEquationSystemSize;
    }

    typename TLinearSolver::Pointer GetLinearSystemSolver() const
    {
      return mpLinearSystemSolver;
    }

    /**
            Function to perform the building of the LHS, depending on the implementation choosen
            the size of the matrix could be equal to the total number of Dofs or to the number
            of unrestrained dofs
     */
    virtual void BuildLHS(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A)
    {
    }

    /**
            Function to perform the build of the RHS. The vector could be sized as the total number
            of dofs or as the number of unrestrained ones
     */
    virtual void BuildRHS(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemVectorType& b)
    {
    }

    /**
            equivalent (but generally faster) then performing BuildLHS and BuildRHS
     */
    virtual void Build(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& b)
    {
    }

    /**
            build a rectangular matrix of size n*N where "n" is the number of unrestrained degrees of freedom
            and "N" is the total number of degrees of freedom involved.
            This matrix is obtained by building the total matrix without the lines
            corrisponding to the fixed degrees of freedom (but keeping the columns!!)
     */
    virtual void BuildLHS_CompleteOnFreeRows(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A)
    {
    }

    /**
            builds a  matrix of size N*N where "N" is the total number of degrees of freedom involved.
            This matrix is obtained by building the total matrix including the lines and columns corresponding to the
            fixed degrees of freedom
     */
    virtual void BuildLHS_Complete(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A)
    {
    }

    /**
            This is a call to the linear system solver
     */
    virtual void SystemSolve(
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b
    )
    {
    }

    /**
            Function to perform the building and solving phase at the same time.
            It is ideally the fastest and safer function to use when it is possible to solve
            just after building
     */
    virtual void BuildAndSolve(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b)
    {
    }

    /**
            corresponds to the previews, but the System's matrix is considered already built
            and only the RHS is built again
     */
    virtual void BuildRHSAndSolve(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b)
    {
    }

    /**
            applies the dirichlet conditions. This operation may be very heavy or completely
            unexpensive depending on the implementation choosen and on how the System Matrix
            is built. For explanation of how it works for a particular implementation the user
            should refer to the particular Builder And Solver choosen
     */
    virtual void ApplyDirichletConditions(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b)
    {
    }

    /**
            the same of the precedent but affecting only the LHS
     */
    virtual void ApplyDirichletConditions_LHS(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx)
    {
    }

    /**
            the same of the precedent but affecting only the RHS
     */
    virtual void ApplyDirichletConditions_RHS(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemVectorType& Dx,
        TSystemVectorType& b)
    {
    }

    /**
            Adds the point loads to the RHS
     */
    virtual void ApplyPointLoads(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemVectorType& b)
    {
    }

    /**
            Builds the list of the DofSets involved in the problem by "asking" to each element
            and condition its Dofs.
            The list of dofs is stores insde the BuilderAndSolver as it is closely connected to the
            way the matrix and RHS are built
     */
    virtual void SetUpDofSet(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part
    )
    {
    }

    /**
            allows to get the list of Dofs from the element
     */
    virtual DofsArrayType& GetDofSet()
    {
        return mDofSet;
    }

    /**
            allows to get the list of Dofs from the element
     */
    virtual const DofsArrayType& GetDofSet() const
    {
        return mDofSet;
    }

    /**
            organises the dofset in order to speed up the building phase
     */
    virtual void SetUpSystem(
        ModelPart& r_model_part
    )
    {
    }

    virtual void ResizeAndInitializeVectors(
        TSystemMatrixPointerType& pA,
        TSystemVectorPointerType& pDx,
        TSystemVectorPointerType& pb,
        ElementsArrayType& rElements,
        ConditionsArrayType& rConditions,
        ProcessInfo& CurrentProcessInfo
    )
    {
    }

    virtual void ResizeAndInitializeVectors(
        TSystemMatrixPointerType& pA,
        TSystemVectorPointerType& pDx,
        TSystemVectorPointerType& pb,
        ModelPart& rModelPart
    )
    {
    }

    virtual void InitializeSolutionStep(
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b)
    {
    }

    virtual void FinalizeSolutionStep(
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b)
    {
    }

    virtual void CalculateReactions(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b)
    {
    }

    /**
    this function is intended to be called at the end of the solution step to clean up memory
    storage not needed
     */
    virtual void Clear()
    {
        this->mDofSet = DofsArrayType();

        TSparseSpace::Clear(this->mpReactionsVector);
        // 			this->mReactionsVector = TSystemVectorType();

        if (this->GetEchoLevel() > 0)
        {

            std::cout << "BuilderAndSolver Clear Function called" << std::endl;
        }
    }

    /**
     * This function is designed to be called once to perform all the checks needed
     * on the input provided. Checks can be "expensive" as the function is designed
     * to catch user's errors.
     * @param r_model_part
     * @return 0 all ok
     */
    virtual int Check(ModelPart& r_model_part)
    {
        KRATOS_TRY

        return 0;
        KRATOS_CATCH("");
    }

    //level of echo for the solving strategy
    // 0 -> mute... no echo at all
    // 1 -> printing time and basic informations
    // 2 -> printing linear solver data
    // 3 -> Print of debug informations:
    //		Echo of stiffness matrix, Dx, b...

    void SetEchoLevel(int Level)
    {
        mEchoLevel = Level;
    }

    int GetEchoLevel() const
    {
        return mEchoLevel;
    }

    /*@} */
    /**@name Operations */
    /*@{ */


    /*@} */
    /**@name Access */
    /*@{ */


    /*@} */
    /**@name Inquiry */
    /*@{ */

    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "BuilderAndSolver";
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << Info();
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {
        rOStream << Info();
    }

    /*@} */
    /**@name Friends */
    /*@{ */


    /*@} */

protected:
    /**@name Protected static Member Variables */
    /*@{ */


    /*@} */
    /**@name Protected member Variables */
    /*@{ */

    /** Pointer to the Model.
     */
    typename TLinearSolver::Pointer mpLinearSystemSolver;

    DofsArrayType mDofSet;

    bool mReshapeMatrixFlag;
    //		bool mVectorsAreInitialized;

    /// flag taking care if the dof set was initialized ot not
    bool mDofSetIsInitialized;

    /// flag taking in account if it is needed or not to calculate the reactions
    bool mCalculateReactionsFlag;

    /// number of degrees of freedom of the problem to be solve
    unsigned int mEquationSystemSize;
    /*@} */
    /**@name Protected Operators*/
    /*@{ */

    int mEchoLevel;

    TSystemVectorPointerType mpReactionsVector;



    /*@} */
    /**@name Protected Operations*/
    /*@{ */


    /*@} */
    /**@name Protected  Access */
    /*@{ */


    /*@} */
    /**@name Protected Inquiry */
    /*@{ */


    /*@} */
    /**@name Protected LifeCycle */
    /*@{ */



    /*@} */

private:
    /**@name Static Member Variables */
    /*@{ */


    /*@} */
    /**@name Member Variables */
    /*@{ */

    /*@} */
    /**@name Private Operators*/
    /*@{ */


    /*@} */
    /**@name Private Operations*/
    /*@{ */


    /*@} */
    /**@name Private  Access */
    /*@{ */


    /*@} */
    /**@name Private Inquiry */
    /*@{ */


    /*@} */
    /**@name Un accessible methods */
    /*@{ */


    /*@} */

}; /* Class BuilderAndSolver */

/*@} */

/**@name Type Definitions */
/*@{ */


/*@} */

} /* namespace Kratos.*/

#endif /* KRATOS_BUILDER_AND_SOLVER  defined */

