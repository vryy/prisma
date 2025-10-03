//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//
//

#if !defined(KRATOS_CONVERGENCE_CRITERIA )
#define  KRATOS_CONVERGENCE_CRITERIA


/* System includes */


/* External includes */


/* Project includes */
#include "includes/define.h"
#include "containers/variable.h"

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

/** Base class for all convergence criteria
*/
template<class TSparseSpace,
         class TDenseSpace, //= DenseSpace<double>
         class TModelPartType
         >
class ConvergenceCriteria
{
public:
    /**@name Type Definitions */
    /*@{ */

    typedef typename TSparseSpace::DataType TDataType;
    typedef typename TSparseSpace::MatrixType TSystemMatrixType;
    typedef typename TSparseSpace::VectorType TSystemVectorType;

    typedef typename TDenseSpace::MatrixType LocalSystemMatrixType;
    typedef typename TDenseSpace::VectorType LocalSystemVectorType;

    typedef TModelPartType ModelPartType;

    typedef typename ModelPartType::ValueType ValueType;
    typedef typename ModelPartType::DofType DofType;
    typedef typename ModelPartType::DofsArrayType DofsArrayType;

    /** Counted pointer of ConvergenceCriteria */
    KRATOS_CLASS_POINTER_DEFINITION(ConvergenceCriteria);

    /*@} */
    /**@name Life Cycle
     */
    /*@{ */

    /** Constructor.
     */
    ConvergenceCriteria()
    {
        mActualizeRHSIsNeeded = false;
        mConvergenceCriteriaIsInitialized = false;
        SetEchoLevel(1);
    }

    /** Copy constructor.
     */
    ConvergenceCriteria( ConvergenceCriteria const& rOther)
      : mActualizeRHSIsNeeded(rOther.mActualizeRHSIsNeeded)
      , mConvergenceCriteriaIsInitialized(rOther.mConvergenceCriteriaIsInitialized)
      , mEchoLevel(rOther.mEchoLevel)
    {
    }

    /** Destructor.
     */
    virtual ~ConvergenceCriteria()
    {
    }

    /*@} */
    /**@name Operators
     */

    /*@{ */

    /**
     * Get component wise element components
     */
    virtual std::vector<TSystemVectorType>&  GetRHS_Element_Components()
    {
        KRATOS_ERROR << "Asking for Global Components to the CONVERGENCE CRITERION base class which is not component wise and not contains this member variable";
    }

    /**
     * Get component wise element variables
     */
    virtual std::vector< Variable< LocalSystemVectorType > >&  GetRHS_Element_Variables()
    {
        KRATOS_ERROR << "Asking for Global Components to the CONVERGENCE CRITERION base class which is not component wise and not contains this member variable";
    }

    /**
     * Get component wise condition components
     */
    virtual std::vector<TSystemVectorType>&  GetRHS_Condition_Components()
    {
        KRATOS_ERROR << "Asking for Global Components to the CONVERGENCE CRITERION base class which is not component wise and not contains this member variable";
    }

    /**
     * Get component wise condition variables
     */
    virtual std::vector< Variable< LocalSystemVectorType > >&  GetRHS_Condition_Variables()
    {
        KRATOS_ERROR << "Asking for Global Components to the CONVERGENCE CRITERION base class which is not component wise and not contains this member variable";
    }

    //*********************************************************************************

    /**level of echo for the convergence criterion
    0 -> mute... no echo at all
    1 -> print basic informations
    2 -> print extra informations
     */
    virtual void SetEchoLevel(int Level)
    {
        mEchoLevel = Level;
    }

    int GetEchoLevel() const
    {
        return mEchoLevel;
    }

    void SetActualizeRHSFlag(bool flag)
    {
        mActualizeRHSIsNeeded = flag;
    }

    bool GetActualizeRHSflag() const
    {
        return mActualizeRHSIsNeeded;
    }

    bool ConvergenceCriteriaIsInitialized() const
    {
        return mConvergenceCriteriaIsInitialized;
    }

    /*Criterias that need to be called before getting the solution */
    virtual bool PreCriteria(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    )
    {
        return false;
    }

    /*Criterias that need to be called after getting the solution */
    virtual bool PostCriteria(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    )
    {
        return false;
    }

    virtual void Initialize(
        ModelPartType& r_model_part
    )
    {
        mConvergenceCriteriaIsInitialized = true;
    }

    virtual void InitializeSolutionStep(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    )
    {
    }

    virtual void InitializeNonLinearIteration(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    )
    {
    }

    virtual void FinalizeSolutionStep(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    )
    {
    }

    virtual void FinalizeNonLinearIteration(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    )
    {
    }

    /**
     * This function is designed to be called once to perform all the checks needed
     * on the input provided. Checks can be "expensive" as the function is designed
     * to catch user's errors.
     * @param r_model_part
     * @return 0 all ok
     */
    virtual int Check(const ModelPartType& r_model_part) const
    {
        KRATOS_TRY

        return 0;

        KRATOS_CATCH("");
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


    /*@} */
    /**@name Friends */
    /*@{ */


    /*@} */

    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "ConvergenceCriteria";
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

    ///@}

protected:
    /**@name Protected static Member Variables */
    /*@{ */

    /*@} */
    /**@name Protected member Variables */
    /*@{ */

    bool mConvergenceCriteriaIsInitialized;

    /*@} */
    /**@name Protected Operators*/
    /*@{ */


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

    bool mActualizeRHSIsNeeded;
    int  mEchoLevel;

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

}; /* Class ClassName */

/*@} */

/**@name Type Definitions */
/*@{ */

/*@} */

///@name Input and output
///@{

/// input stream function
template<class TSparseSpace, class TDenseSpace, class TModelPartType>
inline std::istream& operator >> (std::istream& rIStream, ConvergenceCriteria<TSparseSpace, TDenseSpace, TModelPartType>& rThis)
{
    return rIStream;
}

/// output stream function
template<class TSparseSpace, class TDenseSpace, class TModelPartType>
inline std::ostream& operator << (std::ostream& rOStream, const ConvergenceCriteria<TSparseSpace, TDenseSpace, TModelPartType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

} /* namespace Kratos.*/

#endif /* KRATOS_CONVERGENCE_CRITERIA  defined */
