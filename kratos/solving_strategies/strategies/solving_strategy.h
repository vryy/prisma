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

#if !defined(KRATOS_SOLVING_STRATEGY )
#define  KRATOS_SOLVING_STRATEGY


/* System includes */
#include <set>

/* External includes */

/* Project includes */
#include "includes/define.h"
#include "includes/model_part.h"
#include "solving_strategies/schemes/scheme.h"
#include "solving_strategies/builder_and_solvers/builder_and_solver.h"


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
         class TLinearSolver, //= LinearSolver<TSparseSpace,TDenseSpace>
         class TModelPartType
         >
class SolvingStrategy
{
public:
    /**@name Type Definitions */
    /*@{ */

    /** Counted pointer of SolvingStrategy */
    KRATOS_CLASS_POINTER_DEFINITION(SolvingStrategy);

    typedef typename TSparseSpace::DataType TDataType;
    typedef typename DataTypeToValueType<TDataType>::value_type ValueType;
    typedef typename TSparseSpace::MatrixType TSystemMatrixType;
    typedef typename TSparseSpace::VectorType TSystemVectorType;

    typedef typename TSparseSpace::MatrixPointerType TSystemMatrixPointerType;
    typedef typename TSparseSpace::VectorPointerType TSystemVectorPointerType;

    typedef typename TDenseSpace::MatrixType LocalSystemMatrixType;
    typedef typename TDenseSpace::VectorType LocalSystemVectorType;

    typedef TModelPartType ModelPartType;
    typedef Scheme<TSparseSpace, TDenseSpace, ModelPartType> TSchemeType;
    typedef BuilderAndSolver<TSparseSpace, TDenseSpace, TLinearSolver, ModelPartType> TBuilderAndSolverType;

    typedef typename ModelPartType::DofType TDofType;
    typedef typename ModelPartType::DofsArrayType DofsArrayType;
    typedef typename ModelPartType::NodeType NodeType;
    typedef typename PointerVectorSet<TDofType, IndexedObject>::iterator DofIterator;
    typedef typename PointerVectorSet<TDofType, IndexedObject>::const_iterator DofConstantIterator;
    /*@} */

    /** Constructor.
     */

    /*@{ */

    SolvingStrategy(
        ModelPartType& model_part, bool MoveMeshFlag = false
    )
        : mr_model_part(model_part)
    {
        SetMoveMeshFlag(MoveMeshFlag);
    }
    /*@} */

    /** Destructor.
     */

    /*@{ */
    virtual ~SolvingStrategy()
    {
    }
    /*@} */

    //*********************************************************************************
    /**OPERATIONS ACCESSIBLE FROM THE INPUT:*/
    /*@{ */

    /**
    operation to predict the solution ... if it is not called a trivial predictor is used in which the
    values of the solution step of interest are assumed equal to the old values
     */
    virtual void Predict()
    {
    }

    /**
    Initialization of member variables and prior operations
     */
    virtual void Initialize()
    {
    }

    /**
    the problem of interest is solved.
    This function calls sequentially: Initialize(), InitializeSolutionStep(), Predict(), SolveSolutionStep() and FinalizeSolutionStep().
    All those functions can otherwise be called separately.
     */
    virtual double Solve()
    {
        Initialize();
        InitializeSolutionStep();
        Predict();
        SolveSolutionStep();
        FinalizeSolutionStep();
        return 0.00;
    }

    /**
    clears the internal storage
     */
    virtual void Clear()
    {
    }

    /**
    this should be considered as a "post solution" convergence check which is useful for coupled analysis
    - the convergence criteria used is the one used inside the "solve" step
     */
    virtual bool IsConverged()
    {
        return true;
    }

    /**
    this operations should be called before printing the results when non trivial results (e.g. stresses)
    need to be calculated given the solution of the step

      This operations should be called only when needed, before printing as it can involve a non negligible cost
     */
    virtual void CalculateOutputData()
    {
    }

    /**
    Performs all the required operations that should be done (for each step) before solving the solution step.
    A member variable should be used as a flag to make sure this function is called only once per step.
    */
    virtual void InitializeSolutionStep()
    {
    }

    /**
    Performs all the required operations that should be done (for each step) after solving the solution step.
    A member variable should be used as a flag to make sure this function is called only once per step.
    */
    virtual void FinalizeSolutionStep()
    {
    }

    /**
    Solves the current step. This function returns true if a solution has been found, false otherwise.
    */
    virtual bool SolveSolutionStep()
    {
        return true;
    }

    //*********************************************************************************

    /**level of echo for the solving strategy
    0 -> mute... no echo at all
    1 -> printing time and basic informations
    2 -> printing linear solver data
    3 -> Print of debug informations:
    Echo of stiffness matrix, Dx, b...
     */
    virtual void SetEchoLevel(int Level)
    {
        mEchoLevel = Level;
    }

    int GetEchoLevel() const
    {
        return mEchoLevel;
    }

    //*********************************************************************************

    /* 0 -> build StiffnessMatrix just once
    1 -> build StiffnessMatrix at the beginning of each solution step
    2 -> build StiffnessMatrix at each iteration*/
    virtual void SetRebuildLevel(int Level)
    {
        mRebuildLevel = Level;
        mStiffnessMatrixIsBuilt = false;
    }

    int GetRebuildLevel() const
    {
        return mRebuildLevel;
    }

    //*********************************************************************************

    /**
    0 -> No mesh movement
    1 -> move mesh
     */
    void SetMoveMeshFlag(bool Flag)
    {
        mMoveMeshFlag = Flag;
    }

    bool MoveMeshFlag() const
    {
        return mMoveMeshFlag;
    }

    //*********************************************************************************

    void MoveMesh()
    {
        KRATOS_TRY

        if constexpr (std::is_same<typename NodeType::CoordinateType, TDataType>::value)
        {
            for (auto i = GetModelPart().NodesBegin(); i != GetModelPart().NodesEnd(); ++i)
            {
                (i)->X() = (i)->X0() + i->GetSolutionStepValue(VARSELC(TDataType, DISPLACEMENT, X));
                (i)->Y() = (i)->Y0() + i->GetSolutionStepValue(VARSELC(TDataType, DISPLACEMENT, Y));
                (i)->Z() = (i)->Z0() + i->GetSolutionStepValue(VARSELC(TDataType, DISPLACEMENT, Z));
            }
        }
        else
        {
            KRATOS_ERROR << "MoveMesh cannot be performed on " << ModelPartTypeToString<ModelPartType>::Get()
                         << " due to incompatibility of nodal coordinates and displacement";
        }

        KRATOS_CATCH("")
    }

    //*********************************************************************************

    //operations to get the pointer to the model

    inline ModelPartType& GetModelPart()
    {
        return mr_model_part;
    };

    inline const ModelPartType& GetModelPart() const
    {
        return mr_model_part;
    };

    virtual double GetResidualNorm() const
    {
        return 0.0;
    }

    /**
     * function to perform expensive checks.
     * It is designed to be called ONCE to verify that the input is correct.
     */
    virtual int Check() const
    {
        KRATOS_TRY

        //check if displacement var is needed
        if (mMoveMeshFlag == true)
        {
            for (auto i = GetModelPart().NodesBegin(); i != GetModelPart().NodesEnd(); ++i)

                if (i->SolutionStepsDataHas(VARSEL(TDataType, DISPLACEMENT)) == false)
                {
                    std::cout << "problem on node with Id " << i->Id() << std::endl;
                    KRATOS_ERROR << "It is impossible to move the mesh since the " << VARSEL(TDataType, DISPLACEMENT).Name() << " var is not in the model_part."
                                 << " Either use SetMoveMeshFlag(False) or add " << VARSEL(TDataType, DISPLACEMENT).Name() << " to the list of variables";
                }
        }

        for (auto it = GetModelPart().ElementsBegin(); it != GetModelPart().ElementsEnd(); it++)
        {
            it->Check(GetModelPart().GetProcessInfo());
        }

        for (auto it = GetModelPart().ConditionsBegin(); it != GetModelPart().ConditionsEnd(); it++)
        {
            it->Check(GetModelPart().GetProcessInfo());
        }

        return 0;

        KRATOS_CATCH("")
    }

    /*@} */

protected:
    /**@name Protected static Member Variables */
    /*@{ */

    //level of echo for the solving strategy
    int mEchoLevel;

    //settings for the rebuilding of the stiffness matrix
    int mRebuildLevel;
    bool mStiffnessMatrixIsBuilt;

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


private:

    /*@} */
    /**@name Static Member Variables */
    /*@{ */


    /*@} */
    /**@name Member Variables */
    /*@{ */

    ModelPartType& mr_model_part;

    bool mMoveMeshFlag;


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

    /** Copy constructor.
     */
    SolvingStrategy(const SolvingStrategy& Other);


    /*@} */

}; /* Class NewSolvingStrategy */

/*@} */

/**@name Type Definitions */
/*@{ */


/*@} */

} /* namespace Kratos.*/

#endif /* KRATOS_SOLVING_STRATEGY  defined */
