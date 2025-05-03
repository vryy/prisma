//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Josep Maria Carbonell
//
//

#if !defined(KRATOS_INCREMENTAL_DISPLACEMENT_CRITERIA )
#define  KRATOS_INCREMENTAL_DISPLACEMENT_CRITERIA


/* System includes */


/* External includes */


/* Project includes */
#include "solving_strategies/convergencecriterias/convergence_criteria.h"

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
         class TDenseSpace,
         class TModelPartType
         >
class IncrementalDisplacementCriteria : virtual public ConvergenceCriteria< TSparseSpace, TDenseSpace, TModelPartType >
{
public:
    /**@name Type Definitions */
    /*@{ */

    KRATOS_CLASS_POINTER_DEFINITION( IncrementalDisplacementCriteria );

    typedef ConvergenceCriteria< TSparseSpace, TDenseSpace, TModelPartType > BaseType;

    typedef TSparseSpace SparseSpaceType;

    typedef typename BaseType::TDataType TDataType;

    typedef typename BaseType::ValueType ValueType;

    typedef typename BaseType::ModelPartType ModelPartType;

    typedef typename BaseType::DofsArrayType DofsArrayType;

    typedef typename BaseType::TSystemMatrixType TSystemMatrixType;

    typedef typename BaseType::TSystemVectorType TSystemVectorType;

    /*@} */
    /**@name Life Cycle
    */
    /*@{ */

    /** Constructor.
    */
    IncrementalDisplacementCriteria(
        ValueType NewRatioTolerance,
        ValueType AlwaysConvergedNorm)
        : BaseType()
    {
        mRatioTolerance = NewRatioTolerance;
        mAlwaysConvergedNorm = AlwaysConvergedNorm;
    }


    /** Copy constructor.
    */
    IncrementalDisplacementCriteria( IncrementalDisplacementCriteria const& rOther)
      : BaseType(rOther)
      , mRatioTolerance(rOther.mRatioTolerance)
      , mAlwaysConvergedNorm(rOther.mAlwaysConvergedNorm)
      , mReferenceDispNorm(rOther.mReferenceDispNorm)
    {
    }


    /** Destructor.
    */
    ~IncrementalDisplacementCriteria() override {}


    /*@} */
    /**@name Operators
    */
    /*@{ */

    /*Criterias that need to be called after getting the solution */
    bool PostCriteria(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    ) override
    {
        if (SparseSpaceType::Size(Dx) != 0) //if we are solving for something
        {
            //TDataType FinalCorrectionNorm = sqrt(std::inner_product(Dx.begin(),Dx.end(),Dx.begin(),TDataType()));
            //TDataType FinalCorrectionNorm = sqrt(Dot(Dx,Dx));
            ValueType FinalCorrectionNorm = std::abs(TSparseSpace::TwoNorm(Dx));

            ValueType ratio = 0.00;

            CalculateReferenceNorm(rDofSet);

            ratio = FinalCorrectionNorm/mReferenceDispNorm;

            ValueType aaa = static_cast<ValueType>(SparseSpaceType::Size(Dx));

            ValueType AbsoluteNorm = (FinalCorrectionNorm/std::sqrt(aaa));
//KRATOS_WATCH(AbsoluteNorm)
//KRATOS_WATCH(mAlwaysConvergedNorm)
//KRATOS_WATCH(mRatioTolerance)
            if (this->GetEchoLevel() == 1)
                std::cout << "INCREMENTAL DISPLACEMENT CRITERIA :: Obtained tol = " << ratio << ";  Expected ratio = " << mRatioTolerance << "Absolute tol = " << AbsoluteNorm << std::endl;

            r_model_part.GetProcessInfo()[CONVERGENCE_RATIO] = ratio;
            r_model_part.GetProcessInfo()[RESIDUAL_NORM] = AbsoluteNorm;

            if ( ratio <= mRatioTolerance  ||  AbsoluteNorm<mAlwaysConvergedNorm )  //  || (FinalCorrectionNorm/x.size())<=1e-7)
            {
                if (this->GetEchoLevel() == 1)
                    KRATOS_WATCH("convergence is achieved")

                return true;
            }
            else
            {
                return false;
            }
        }
        else //in this case all the displacements are imposed!
        {
            return true;
        }
    }

    void Initialize(
        ModelPartType& r_model_part
    ) override
    {
        BaseType::mConvergenceCriteriaIsInitialized = true;
    }

    void InitializeSolutionStep(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    ) override
    {}

    void FinalizeSolutionStep(
        ModelPartType& r_model_part,
        DofsArrayType& rDofSet,
        const TSystemMatrixType& A,
        const TSystemVectorType& Dx,
        const TSystemVectorType& b
    ) override
    {}

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

protected:
    /**@name Protected static Member Variables */
    /*@{ */


    /*@} */
    /**@name Protected member Variables */
    /*@{ */


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

    ValueType mRatioTolerance;

    ValueType mAlwaysConvergedNorm;

    ValueType mReferenceDispNorm;

    /*@} */
    /**@name Private Operators*/
    /*@{ */

    void CalculateReferenceNorm(DofsArrayType& rDofSet)
    {
        mReferenceDispNorm = ValueType();

        //// x is set to its value at the beginning of the time step
        //typename DofsArrayType::iterator it2;
        //for (it2=rDofSet.begin();it2 != rDofSet.end(); ++it2)
        //{
        //  if ( !(*it2)->IsFixed()  )
        //  {
        //      temp = mpModel->Value(*it2);
        //      mReferenceDispNorm += temp*temp;
        //  }
        //}
        for(typename DofsArrayType::iterator i_dof = rDofSet.begin() ; i_dof != rDofSet.end() ; ++i_dof)
        {
            if(i_dof->IsFree())
            {
                //here we do: d_n+1^it-d_n
                ValueType temp = std::abs(i_dof->GetSolutionStepValue() - i_dof->GetSolutionStepValue(1));
                mReferenceDispNorm += temp*temp;
            }
        }
        mReferenceDispNorm = std::sqrt(mReferenceDispNorm);
    }

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

}  /* namespace Kratos.*/

#endif /* KRATOS_INCREMENTAL_DISPLACEMENT_CRITERIA  defined */
