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

#if !defined(KRATOS_RESIDUAL_BASED_ELIMINATION_BUILDER_AND_SOLVER )
#define  KRATOS_RESIDUAL_BASED_ELIMINATION_BUILDER_AND_SOLVER


/* System includes */
#include <set>

#ifdef _OPENMP
#include <omp.h>
#endif

/* External includes */
#include "utilities/timer.h"

/* Project includes */
#include "includes/define.h"
#include "solving_strategies/builder_and_solvers/builder_and_solver.h"
#include "includes/model_part.h"

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

Current class provides an implementation for standard builder and solving operations.

the RHS is constituted by the unbalanced loads (residual)

Degrees of freedom are reordered putting the restrained degrees of freedom at
the end of the system ordered in reverse order with respect to the DofSet.

Imposition of the dirichlet conditions is naturally dealt with as the residual already contains
this information.

Calculation of the reactions involves a cost very similiar to the calculation of the total residual

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
         class TDenseSpace, //= DenseSpace<double>,
         class TLinearSolver, //= LinearSolver<TSparseSpace,TDenseSpace>
         class TModelPartType
         >
class ResidualBasedEliminationBuilderAndSolver
    : public BuilderAndSolver< TSparseSpace, TDenseSpace, TLinearSolver, TModelPartType >
{
public:
    /**@name Type Definitions */
    /*@{ */
    KRATOS_CLASS_POINTER_DEFINITION(ResidualBasedEliminationBuilderAndSolver);

    typedef BuilderAndSolver<TSparseSpace, TDenseSpace, TLinearSolver, TModelPartType> BaseType;

    typedef typename BaseType::ModelPartType ModelPartType;

    typedef typename BaseType::TSchemeType TSchemeType;

    typedef typename BaseType::TSparseSpaceType TSparseSpaceType;

    typedef typename BaseType::TLinearSolverType TLinearSolverType;

    typedef typename BaseType::TDataType TDataType;

    typedef typename BaseType::ValueType ValueType;

    typedef typename BaseType::DofsArrayType DofsArrayType;

    typedef typename BaseType::TSystemMatrixType TSystemMatrixType;

    typedef typename BaseType::TSystemVectorType TSystemVectorType;

    typedef typename BaseType::LocalSystemVectorType LocalSystemVectorType;

    typedef typename BaseType::LocalSystemMatrixType LocalSystemMatrixType;

    typedef typename BaseType::TSystemMatrixPointerType TSystemMatrixPointerType;
    typedef typename BaseType::TSystemVectorPointerType TSystemVectorPointerType;

    typedef typename BaseType::ElementType ElementType;
    typedef typename BaseType::ConditionType ConditionType;

    typedef typename BaseType::NodesContainerType NodesContainerType;
    typedef typename BaseType::ElementsContainerType ElementsContainerType;
    typedef typename BaseType::ConditionsContainerType ConditionsContainerType;

    /*@} */
    /**@name Life Cycle
     */
    /*@{ */

    /** Constructor.
     */
    ResidualBasedEliminationBuilderAndSolver(
        typename TLinearSolver::Pointer pNewLinearSystemSolver)
        : BaseType(pNewLinearSystemSolver)
    {

        /* std::cout << "using the standard builder and solver " << std::endl; */

    }

    /** Destructor.
     */
    ~ResidualBasedEliminationBuilderAndSolver() override
    {
    }

    /*@} */
    /**@name Operators
     */
    /*@{ */

    //**************************************************************************
    //**************************************************************************

    void Build(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& b) override
    {
        KRATOS_TRY
        if (!pScheme)
            KRATOS_ERROR << "No scheme provided!";

        if(r_model_part.MasterSlaveConstraints().size() != 0)
            KRATOS_ERROR << "This builder and solver does not support constraints!";

        //getting the elements from the model
        ElementsContainerType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsContainerType& ConditionsArray = r_model_part.Conditions();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero(*(BaseType::mpReactionsVector));

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);
        LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

        //vector containing the localization in the system of the different
        //terms
        typename ElementType::EquationIdVectorType EquationId;

        //double StartTime = GetTickCount();

        // assemble all elements
#ifndef _OPENMP
        const ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        for (typename ElementsContainerType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            //calculate elemental contribution
            pScheme->CalculateSystemContributions(*it, LHS_Contribution, RHS_Contribution, EquationId, CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleLHS(A, LHS_Contribution, EquationId);
            AssembleRHS(b, RHS_Contribution, EquationId);

            // clean local elemental memory
            pScheme->CleanMemory(*it);
        }
        //double EndTime = GetTickCount();

        //std::cout << "total time " << EndTime - StartTime << std::endl;
        //std::cout << "writing in the system matrix " << ccc << std::endl;
        //std::cout << "calculating the elemental contrib " << ddd << std::endl;
        LHS_Contribution.resize(0, 0, false);
        RHS_Contribution.resize(0, false);

        // assemble all conditions
        for (typename ConditionsContainerType::iterator it = ConditionsArray.begin(); it != ConditionsArray.end(); ++it)
        {
            //calculate elemental contribution
            pScheme->CalculateSystemContributions(*it, LHS_Contribution, RHS_Contribution, EquationId, CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleLHS(A, LHS_Contribution, EquationId);
            AssembleRHS(b, RHS_Contribution, EquationId);
        }

#else
        //creating an array of lock variables of the size of the system matrix
        std::vector< omp_lock_t > lock_array(A.size1());

        int A_size = A.size1();
        for (int i = 0; i < A_size; i++)
            omp_init_lock(&lock_array[i]);

        //create a partition of the element array
        int number_of_threads = omp_get_max_threads();

        vector<unsigned int> element_partition;
        CreatePartition(number_of_threads, pElements.size(), element_partition);
        if( this->GetEchoLevel() > 2 && r_model_part.GetCommunicator().MyPID() == 0)
        {
            KRATOS_WATCH(number_of_threads);
            KRATOS_WATCH(element_partition);
        }


        double start_prod = omp_get_wtime();

        #pragma omp parallel for
        for (int k = 0; k < number_of_threads; k++)
        {
            //contributions to the system
            LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);
            LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

            //vector containing the localization in the system of the different
            //terms
            typename ElementType::EquationIdVectorType EquationId;
            const ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
            typename ElementsContainerType::iterator it_begin = pElements.begin() + element_partition[k];
            typename ElementsContainerType::iterator it_end = pElements.begin() + element_partition[k + 1];

            // assemble all elements
            for (typename ElementsContainerType::iterator it = it_begin; it != it_end; ++it)
            {

                //calculate elemental contribution
                pScheme->CalculateSystemContributions(*it, LHS_Contribution, RHS_Contribution, EquationId, CurrentProcessInfo);

                //assemble the elemental contribution
                Assemble(A, b, LHS_Contribution, RHS_Contribution, EquationId, lock_array);

                // clean local elemental memory
                pScheme->CleanMemory(*it);

                //                  #pragma omp critical
                //                  {
                //                      //assemble the elemental contribution
                //                      AssembleLHS(A,LHS_Contribution,EquationId);
                //                      AssembleRHS(b,RHS_Contribution,EquationId);
                //
                //                      // clean local elemental memory
                //                      pScheme->CleanMemory(*it);
                //                  }
            }
        }

        vector<unsigned int> condition_partition;
        CreatePartition(number_of_threads, ConditionsArray.size(), condition_partition);

        #pragma omp parallel for
        for (int k = 0; k < number_of_threads; k++)
        {
            //contributions to the system
            LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);
            LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

            Condition::EquationIdVectorType EquationId;

            ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

            typename ConditionsContainerType::iterator it_begin = ConditionsArray.begin() + condition_partition[k];
            typename ConditionsContainerType::iterator it_end = ConditionsArray.begin() + condition_partition[k + 1];

            // assemble all elements
            for (typename ConditionsContainerType::iterator it = it_begin; it != it_end; ++it)
            {
                //calculate elemental contribution
                pScheme->CalculateSystemContributions(*it, LHS_Contribution, RHS_Contribution, EquationId, CurrentProcessInfo);

                //assemble the elemental contribution
                Assemble(A, b, LHS_Contribution, RHS_Contribution, EquationId, lock_array);
            }
        }

        double stop_prod = omp_get_wtime();
        if (this->GetEchoLevel() > 2 && r_model_part.GetCommunicator().MyPID() == 0)
            std::cout << "time: " << stop_prod - start_prod << std::endl;

        for (int i = 0; i < A_size; i++)
            omp_destroy_lock(&lock_array[i]);
        if( this->GetEchoLevel() > 2 && r_model_part.GetCommunicator().MyPID() == 0)
        {
            KRATOS_WATCH("finished parallel building");
        }
#endif

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************

    void BuildLHS(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemMatrixType& A)
    {
        KRATOS_TRY

        //getting the elements from the model
        ElementsContainerType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsContainerType& ConditionsArray = r_model_part.Conditions();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero(*(BaseType::mpReactionsVector));

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);

        //vector containing the localization in the system of the different
        //terms
        typename ElementType::EquationIdVectorType EquationId;

        const ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        // assemble all elements
        for (typename ElementsContainerType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            //calculate elemental contribution
            pScheme->CalculateLHSContribution(*it, LHS_Contribution, EquationId, CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleLHS(A, LHS_Contribution, EquationId);

            // clean local elemental memory
            pScheme->CleanMemory(*it);
        }

        LHS_Contribution.resize(0, 0, false);

        // assemble all conditions
        for (typename ConditionsContainerType::iterator it = ConditionsArray.begin(); it != ConditionsArray.end(); ++it)
        {
            //calculate elemental contribution
            pScheme->CalculateLHSContribution(*it, LHS_Contribution, EquationId, CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleLHS(A, LHS_Contribution, EquationId);
        }

        KRATOS_CATCH("")

    }

    //**************************************************************************
    //**************************************************************************

    void BuildLHS_CompleteOnFreeRows(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemMatrixType& A)
    {
        KRATOS_TRY

        //getting the elements from the model
        ElementsContainerType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsContainerType& ConditionsArray = r_model_part.Conditions();

        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero(*(BaseType::mpReactionsVector));

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);

        //vector containing the localization in the system of the different
        //terms
        typename ElementType::EquationIdVectorType EquationId;

        // assemble all elements
        for (typename ElementsContainerType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            //calculate elemental contribution
            pScheme->CalculateLHSContribution(*it, LHS_Contribution, EquationId, CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleLHS_CompleteOnFreeRows(A, LHS_Contribution, EquationId);

            // clean local elemental memory
            pScheme->CleanMemory(*it);
        }

        LHS_Contribution.resize(0, 0, false);
        // assemble all conditions
        for (typename ConditionsContainerType::iterator it = ConditionsArray.begin(); it != ConditionsArray.end(); ++it)
        {
            //calculate elemental contribution
            pScheme->CalculateLHSContribution(*it, LHS_Contribution, EquationId, CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleLHS_CompleteOnFreeRows(A, LHS_Contribution, EquationId);

            // clean local conditional memory
            pScheme->CleanMemory(*it);
        }

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************

    void SystemSolve(
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b
    ) override
    {
        KRATOS_TRY

        ValueType norm_b;
        if (TSparseSpace::Size(b) != 0)
            norm_b = std::abs(TSparseSpace::TwoNorm(b));
        else
            norm_b = 0.00;

        if (norm_b != 0.00)
        {
            //do solve
            BaseType::mpLinearSystemSolver->Solve(A, Dx, b);
        }
        else
            TSparseSpace::SetToZero(Dx);

        //prints informations about the current time
        if (this->GetEchoLevel() > 1)
        {
            std::cout << *(BaseType::mpLinearSystemSolver) << std::endl;
        }

        KRATOS_CATCH("")
    }

    void SystemSolveWithPhysics(
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b,
        ModelPartType& r_model_part
    )
    {
        KRATOS_TRY

        ValueType norm_b;
        if (TSparseSpace::Size(b) != 0)
            norm_b = std::abs(TSparseSpace::TwoNorm(b));
        else
            norm_b = 0.00;

        if (norm_b != 0.00)
        {
            //provide physical data as needed
            if(BaseType::mpLinearSystemSolver->AdditionalPhysicalDataIsNeeded() )
                BaseType::mpLinearSystemSolver->ProvideAdditionalData(A, Dx, b, BaseType::mDofSet, r_model_part);

            //do solve
            BaseType::mpLinearSystemSolver->Solve(A, Dx, b);
        }
        else
        {
            TSparseSpace::SetToZero(Dx);
            std::cout << "ATTENTION! setting the RHS to zero!" << std::endl;
        }

        //prints informations about the current time
        if (this->GetEchoLevel() > 1)
        {
            std::cout << *(BaseType::mpLinearSystemSolver) << std::endl;
        }

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************

    void BuildAndSolve(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
        KRATOS_TRY

        //          boost::timer building_time;

        Timer::Start("Build");

        Build(pScheme, r_model_part, A, b);

        Timer::Stop("Build");

        //          if(this->GetEchoLevel()>0)
        //          {
        //              std::cout << "Building Time : " << building_time.elapsed() << std::endl;
        //          }

        //          ApplyPointLoads(pScheme,r_model_part,b);

        //does nothing...dirichlet conditions are naturally dealt with in defining the residual
        ApplyDirichletConditions(pScheme, r_model_part, A, Dx, b);

        if (this->GetEchoLevel() == 3)
        {
            std::cout << "before the solution of the system" << std::endl;
            std::cout << "System Matrix = " << A << std::endl;
            std::cout << "unknowns vector = " << Dx << std::endl;
            std::cout << "RHS vector = " << b << std::endl;
        }

        //          boost::timer solve_time;
        Timer::Start("Solve");

        SystemSolveWithPhysics(A, Dx, b, r_model_part);

        Timer::Stop("Solve");

        //          if(this->GetEchoLevel()>0)
        //          {
        //              std::cout << "System Solve Time : " << solve_time.elapsed() << std::endl;
        //          }
        if (this->GetEchoLevel() == 3)
        {
            std::cout << "after the solution of the system" << std::endl;
            std::cout << "System Matrix = " << A << std::endl;
            std::cout << "unknowns vector = " << Dx << std::endl;
            std::cout << "RHS vector = " << b << std::endl;
        }

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************

    void BuildRHSAndSolve(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
        KRATOS_TRY

        BuildRHS(pScheme, r_model_part, b);
        SystemSolve(A, Dx, b);

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************

    void BuildRHS(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemVectorType& b) override
    {
        KRATOS_TRY

        //Getting the Elements
        ElementsContainerType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsContainerType& ConditionsArray = r_model_part.Conditions();

        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero(*(BaseType::mpReactionsVector));

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);
        LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

        //vector containing the localization in the system of the different
        //terms
        typename ElementType::EquationIdVectorType EquationId;

        // assemble all elements
        for (typename ElementsContainerType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            //calculate elemental Right Hand Side Contribution
            pScheme->CalculateRHSContribution(*it, RHS_Contribution, EquationId, CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleRHS(b, RHS_Contribution, EquationId);
        }

        LHS_Contribution.resize(0, 0, false);
        RHS_Contribution.resize(0, false);

        // assemble all conditions
        for (typename ConditionsContainerType::iterator it = ConditionsArray.begin(); it != ConditionsArray.end(); ++it)
        {
            //calculate elemental contribution
            pScheme->CalculateRHSContribution(*it, RHS_Contribution, EquationId, CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleRHS(b, RHS_Contribution, EquationId);
        }

        KRATOS_CATCH("")

    }
    //**************************************************************************
    //**************************************************************************

    void SetUpDofSet(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part
    ) override
    {
        KRATOS_TRY;

        if( this->GetEchoLevel() > 0 && r_model_part.GetCommunicator().MyPID() == 0)
        {
            std::cout << "Setting up the dofs" << std::endl;
        }

        //Gets the array of elements from the modeler
        ElementsContainerType& pElements = r_model_part.Elements();

        typename ElementType::DofsVectorType ElementalDofList;

        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        DofsArrayType Doftemp;
        BaseType::mDofSet = DofsArrayType();
        //mDofSet.clear();

        //double StartTime = GetTickCount();
        for (auto it = pElements.begin(); it != pElements.end(); ++it)
        {
            // gets list of Dof involved on every element
            //aaa = GetTickCount();
            pScheme->GetDofList(*it, ElementalDofList, CurrentProcessInfo);
            //bbb += GetTickCount() - aaa;
            /*KRATOS_WATCH((*it)->Id());
            std::cout << "node ids" << std::endl;
            for(unsigned int i=0; i<((*it)->GetGeometry()).size(); i++)
                    std::cout << ((*it)->GetGeometry())[i].Id() << " ";
            std::cout << std::endl;
            for(unsigned int i=0; i<ElementalDofList.size(); i++)
                    std::cout << (ElementalDofList[i]->Id()) << " ";
            std::cout << std::endl;*/

            //KRATOS_WATCH(ElementalDofList);

            //ccc = GetTickCount();
            for (auto i = ElementalDofList.begin(); i != ElementalDofList.end(); ++i)
            {
                Doftemp.push_back(*i);
                //mDofSet.push_back(*i);
            }
            //ddd += GetTickCount() - ccc;
        }

        //std::cout << "searching " << bbb << std::endl;
        //std::cout << "inserting " << ddd << std::endl;

        //taking in account conditions
        ConditionsContainerType& pConditions = r_model_part.Conditions();
        for (auto it = pConditions.begin(); it != pConditions.end(); ++it)
        {
            // gets list of Dof involved on every element
            pScheme->GetDofList(*it, ElementalDofList, CurrentProcessInfo);

            //ccc = GetTickCount();
            for (auto i = ElementalDofList.begin(); i != ElementalDofList.end(); ++i)
            {
                //mDofSet.push_back(*i);
                Doftemp.push_back(*i);
            }
            //ddd += GetTickCount() - ccc;
        }
        //std::cout << "searching " << bbb << std::endl;
        //std::cout << "inserting " << ddd << std::endl;
        /*for (typename DofsArrayType::iterator dof_iterator = Doftemp.begin(); dof_iterator != Doftemp.end(); ++dof_iterator)
        {
                KRATOS_WATCH(*dof_iterator);
        }
        std::cout << "DofTemp before Unique" << Doftemp.size() << std::endl;
         */
        //ccc = GetTickCount();
        Doftemp.Unique();
        //std::cout << "DofTemp after Unique" << Doftemp.size() << std::endl;
        BaseType::mDofSet = Doftemp;

        //ddd = GetTickCount() - ccc;
        //std::cout << "Unique " << ddd << std::endl;

        //throws an execption if there are no Degrees of freedom involved in the analysis
        if (BaseType::mDofSet.size() == 0)
            KRATOS_THROW_ERROR(std::logic_error, "No degrees of freedom!", "");

        BaseType::mDofSetIsInitialized = true;
        if( this->GetEchoLevel() > 2 && r_model_part.GetCommunicator().MyPID() == 0)
        {
            std::cout << "finished setting up the dofs" << std::endl;
        }

        KRATOS_CATCH("");
    }

    //**************************************************************************
    //**************************************************************************

    void SetUpSystem(
        ModelPartType& r_model_part
    ) override
    {
        // Set equation id for degrees of freedom
        // the free degrees of freedom are positioned at the beginning of the system,
        // while the fixed one are at the end (in opposite order).
        //
        // that means that if the EquationId is greater than "mEquationSystemSize"
        // the pointed degree of freedom is restrained
        //
        int free_id = 0;
        int fix_id = BaseType::mDofSet.size();

        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
            if (dof_iterator->IsFixed())
                dof_iterator->SetEquationId(--fix_id);
            else
                dof_iterator->SetEquationId(free_id++);

        BaseType::mEquationSystemSize = fix_id;

    }

    //**************************************************************************
    //**************************************************************************

    void ResizeAndInitializeVectors(
        TSystemMatrixPointerType& pA,
        TSystemVectorPointerType& pDx,
        TSystemVectorPointerType& pb,
        ElementsContainerType& rElements,
        ConditionsContainerType& rConditions,
        const ProcessInfo& CurrentProcessInfo
    ) override
    {
        KRATOS_TRY
        if (pA == NULL) //if the pointer is not initialized initialize it to an empty matrix
        {
            TSystemMatrixPointerType pNewA = TSystemMatrixPointerType(new TSystemMatrixType(0, 0));
            pA.swap(pNewA);
        }
        if (pDx == NULL) //if the pointer is not initialized initialize it to an empty matrix
        {
            TSystemVectorPointerType pNewDx = TSystemVectorPointerType(new TSystemVectorType(0));
            pDx.swap(pNewDx);
        }
        if (pb == NULL) //if the pointer is not initialized initialize it to an empty matrix
        {
            TSystemVectorPointerType pNewb = TSystemVectorPointerType(new TSystemVectorType(0));
            pb.swap(pNewb);
        }
        if (BaseType::mpReactionsVector == NULL) //if the pointer is not initialized initialize it to an empty matrix
        {
            TSystemVectorPointerType pNewReactionsVector = TSystemVectorPointerType(new TSystemVectorType(0));
            BaseType::mpReactionsVector.swap(pNewReactionsVector);
        }

        TSystemMatrixType& A = *pA;
        TSystemVectorType& Dx = *pDx;
        TSystemVectorType& b = *pb;

        //resizing the system vectors and matrix
        if (A.size1() == 0 || BaseType::GetReshapeMatrixFlag() == true) //if the matrix is not initialized
        {
            A.resize(BaseType::mEquationSystemSize, BaseType::mEquationSystemSize, false);
            ConstructMatrixStructure(A, rElements, rConditions, CurrentProcessInfo);
        }
        else
        {
            if (A.size1() != BaseType::mEquationSystemSize || A.size2() != BaseType::mEquationSystemSize)
            {
                KRATOS_WATCH("it should not come here!!!!!!!! ... this is SLOW");
                A.resize(BaseType::mEquationSystemSize, BaseType::mEquationSystemSize, true);
                ConstructMatrixStructure(A, rElements, rConditions, CurrentProcessInfo);
            }
        }
        if (Dx.size() != BaseType::mEquationSystemSize)
            Dx.resize(BaseType::mEquationSystemSize, false);
        if (b.size() != BaseType::mEquationSystemSize)
            b.resize(BaseType::mEquationSystemSize, false);

        //


        //if needed resize the vector for the calculation of reactions
        if (BaseType::mCalculateReactionsFlag == true)
        {
            unsigned int ReactionsVectorSize = BaseType::mDofSet.size() - BaseType::mEquationSystemSize;
            if (BaseType::mpReactionsVector->size() != ReactionsVectorSize)
                BaseType::mpReactionsVector->resize(ReactionsVectorSize, false);
        }

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************

    void ResizeAndInitializeVectors(
        TSystemMatrixPointerType& pA,
        TSystemVectorPointerType& pDx,
        TSystemVectorPointerType& pb,
        ModelPartType& rModelPart
    ) override
    {
        ResizeAndInitializeVectors(pA, pDx, pb, rModelPart.Elements(), rModelPart.Conditions(), rModelPart.GetProcessInfo());
    }

    //**************************************************************************
    //**************************************************************************

    void InitializeSolutionStep(
        ModelPartType& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
        KRATOS_TRY
        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************

    void FinalizeSolutionStep(
        ModelPartType& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
    }


    //**************************************************************************
    //**************************************************************************

    void CalculateReactions(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
        //refresh RHS to have the correct reactions
        BuildRHS(pScheme, r_model_part, b);

        int i;
        int systemsize = BaseType::mDofSet.size() - TSparseSpace::Size(*BaseType::mpReactionsVector);

        typename DofsArrayType::ptr_iterator it2;
        // KRATOS_WATCH(*BaseType::mpReactionsVector);
        //updating variables
        TSystemVectorType& ReactionsVector = *BaseType::mpReactionsVector;
        for (it2 = BaseType::mDofSet.ptr_begin(); it2 != BaseType::mDofSet.ptr_end(); ++it2)
        {
            if ((*it2)->IsFixed())
            {
                i = (*it2)->EquationId();
                i -= systemsize;
                /*KRATOS_WATCH((*it2)->GetSolutionStepReactionValue());
                KRATOS_WATCH(ReactionsVector[i]);*/
                (*it2)->GetSolutionStepReactionValue() = ReactionsVector[i];
            }
        }
    }

    //**************************************************************************
    //**************************************************************************

    void ApplyDirichletConditions(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
    }

    //**************************************************************************
    //**************************************************************************

    void ApplyPointLoads(
        typename TSchemeType::Pointer pScheme,
        ModelPartType& r_model_part,
        TSystemVectorType& b)
    {
    }

    /**
    this function is intended to be called at the end of the solution step to clean up memory
    storage not needed
     */
    void Clear() override
    {
        this->mDofSet = DofsArrayType();

        if (this->mpReactionsVector != NULL)
            TSparseSpace::Clear((this->mpReactionsVector));
        //          this->mReactionsVector = TSystemVectorType();

        this->mpLinearSystemSolver->Clear();

        if (this->GetEchoLevel() > 0)
        {
            std::cout << "ResidualBasedEliminationBuilderAndSolver Clear Function called" << std::endl;
        }
    }

    /**
     * This function is designed to be called once to perform all the checks needed
     * on the input provided. Checks can be "expensive" as the function is designed
     * to catch user's errors.
     * @param r_model_part
     * @return 0 all ok
     */
    int Check(const ModelPartType& r_model_part) const override
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

protected:
    /**@name Protected static Member Variables */
    /*@{ */


    /*@} */
    /**@name Protected member Variables */
    /*@{ */


    /*@} */
    /**@name Protected Operators*/
    /*@{ */
    //**************************************************************************

    virtual void ConstructMatrixStructure(
        TSystemMatrixType& A,
        const ElementsContainerType& rElements,
        const ConditionsContainerType& rConditions,
        const ProcessInfo& CurrentProcessInfo) const
    {
        std::size_t equation_size = A.size1();
        std::vector<std::vector<std::size_t> > indices(equation_size);

        typename ElementType::EquationIdVectorType ids(3, 0);
        for (auto i_element = rElements.begin(); i_element != rElements.end(); i_element++)
        {
            (i_element)->EquationIdVector(ids, CurrentProcessInfo);

            for (std::size_t i = 0; i < ids.size(); i++)
                if (ids[i] < equation_size)
                {
                    std::vector<std::size_t>& row_indices = indices[ids[i]];
                    for (std::size_t j = 0; j < ids.size(); j++)
                        if (ids[j] < equation_size)
                        {
                            AddUnique(row_indices, ids[j]);
                            //indices[ids[i]].push_back(ids[j]);
                        }
                }
        }

        for (auto i_condition = rConditions.begin(); i_condition != rConditions.end(); i_condition++)
        {
            (i_condition)->EquationIdVector(ids, CurrentProcessInfo);
            for (std::size_t i = 0; i < ids.size(); i++)
                if (ids[i] < equation_size)
                {
                    std::vector<std::size_t>& row_indices = indices[ids[i]];
                    for (std::size_t j = 0; j < ids.size(); j++)
                        if (ids[j] < equation_size)
                        {
                            AddUnique(row_indices, ids[j]);
                            //  indices[ids[i]].push_back(ids[j]);
                        }
                }
        }

        //allocating the memory needed
        int data_size = 0;
        for (std::size_t i = 0; i < indices.size(); i++)
        {
            data_size += indices[i].size();
        }
        A.reserve(data_size, false);

        //filling with zero the matrix (creating the structure)
        Timer::Start("MatrixStructure");
#ifndef _OPENMP
        for (std::size_t i = 0; i < indices.size(); i++)
        {
            std::vector<std::size_t>& row_indices = indices[i];
            std::sort(row_indices.begin(), row_indices.end());

            for (std::vector<std::size_t>::iterator it = row_indices.begin(); it != row_indices.end(); it++)
            {
                A.push_back(i, *it, 0.00);
            }
            row_indices.clear();
        }
#else
        int number_of_threads = omp_get_max_threads();
        vector<unsigned int> matrix_partition;
        CreatePartition(number_of_threads, indices.size(), matrix_partition);
        if (this->GetEchoLevel() > 2)
        {
            KRATOS_WATCH(matrix_partition);
        }
        for (int k = 0; k < number_of_threads; k++)
        {
            #pragma omp parallel
            if (omp_get_thread_num() == k)
            {
                for (std::size_t i = matrix_partition[k]; i < matrix_partition[k + 1]; i++)
                {
                    std::vector<std::size_t>& row_indices = indices[i];
                    std::sort(row_indices.begin(), row_indices.end());

                    for (std::vector<std::size_t>::iterator it = row_indices.begin(); it != row_indices.end(); it++)
                    {
                        A.push_back(i, *it, 0.00);
                    }
                    row_indices.clear();
                }
            }
        }
#endif
        Timer::Stop("MatrixStructure");
    }

    //**************************************************************************

    void AssembleLHS(
        TSystemMatrixType& A,
        LocalSystemMatrixType& LHS_Contribution,
        typename ElementType::EquationIdVectorType& EquationId
    ) const
    {
        unsigned int local_size = LHS_Contribution.size1();

        for (unsigned int i_local = 0; i_local < local_size; i_local++)
        {
            unsigned int i_global = EquationId[i_local];
            if (i_global < BaseType::mEquationSystemSize)
            {
                for (unsigned int j_local = 0; j_local < local_size; j_local++)
                {
                    unsigned int j_global = EquationId[j_local];
                    if (j_global < BaseType::mEquationSystemSize)
                        A(i_global, j_global) += LHS_Contribution(i_local, j_local);
                }
            }
        }
    }

    //**************************************************************************

    void AssembleRHS(
        TSystemVectorType& b,
        LocalSystemVectorType& RHS_Contribution,
        typename ElementType::EquationIdVectorType& EquationId
    ) const
    {
        unsigned int local_size = RHS_Contribution.size();

        if (BaseType::mCalculateReactionsFlag == false) //if we don't need to calculate reactions
        {
            for (unsigned int i_local = 0; i_local < local_size; i_local++)
            {
                unsigned int i_global = EquationId[i_local];
                if (i_global < BaseType::mEquationSystemSize) //on "free" DOFs
                {
                    // ASSEMBLING THE SYSTEM VECTOR
                    b[i_global] += RHS_Contribution[i_local];
                }
            }
        }
        else   //when the calculation of reactions is needed
        {
            TSystemVectorType& ReactionsVector = *BaseType::mpReactionsVector;
            for (unsigned int i_local = 0; i_local < local_size; i_local++)
            {
                unsigned int i_global = EquationId[i_local];
                if (i_global < BaseType::mEquationSystemSize) //on "free" DOFs
                {
                    // ASSEMBLING THE SYSTEM VECTOR
                    b[i_global] += RHS_Contribution[i_local];
                }
                else   //on "fixed" DOFs
                {
                    // Assembling the Vector of REACTIONS
                    ReactionsVector[i_global - BaseType::mEquationSystemSize] -= RHS_Contribution[i_local];
                }
            }
        }
    }

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

    //**************************************************************************

    void AssembleLHS_CompleteOnFreeRows(
        TSystemMatrixType& A,
        LocalSystemMatrixType& LHS_Contribution,
        typename ElementType::EquationIdVectorType& EquationId
    ) const
    {
        unsigned int local_size = LHS_Contribution.size1();
        for (unsigned int i_local = 0; i_local < local_size; i_local++)
        {
            unsigned int i_global = EquationId[i_local];
            if (i_global < BaseType::mEquationSystemSize)
            {
                for (unsigned int j_local = 0; j_local < local_size; j_local++)
                {
                    int j_global = EquationId[j_local];

                    A(i_global, j_global) += LHS_Contribution(i_local, j_local);
                }
            }
        }
    }

    //******************************************************************************************
    //******************************************************************************************

    inline void AddUnique(std::vector<std::size_t>& v, const std::size_t& candidate) const
    {
        std::vector<std::size_t>::iterator i = v.begin();
        std::vector<std::size_t>::iterator endit = v.end();
        while (i != endit && (*i) != candidate)
        {
            i++;
        }
        if (i == endit)
        {
            v.push_back(candidate);
        }

    }

    //******************************************************************************************
    //******************************************************************************************

    inline void CreatePartition(unsigned int number_of_threads, const int number_of_rows, vector<unsigned int>& partitions) const
    {
        partitions.resize(number_of_threads + 1);
        int partition_size = number_of_rows / number_of_threads;
        partitions[0] = 0;
        partitions[number_of_threads] = number_of_rows;
        for (unsigned int i = 1; i < number_of_threads; i++)
            partitions[i] = partitions[i - 1] + partition_size;
    }

#ifdef _OPENMP
    void Assemble(
        TSystemMatrixType& A,
        TSystemVectorType& b,
        const LocalSystemMatrixType& LHS_Contribution,
        const LocalSystemVectorType& RHS_Contribution,
        typename ElementType::EquationIdVectorType& EquationId,
        std::vector< omp_lock_t >& lock_array
    ) const
    {
        unsigned int local_size = LHS_Contribution.size1();

        for (unsigned int i_local = 0; i_local < local_size; i_local++)
        {
            unsigned int i_global = EquationId[i_local];

            if (i_global < BaseType::mEquationSystemSize)
            {
                omp_set_lock(&lock_array[i_global]);

                b[i_global] += RHS_Contribution(i_local);
                for (unsigned int j_local = 0; j_local < local_size; j_local++)
                {
                    unsigned int j_global = EquationId[j_local];
                    if (j_global < BaseType::mEquationSystemSize)
                    {
                        A(i_global, j_global) += LHS_Contribution(i_local, j_local);
                    }
                }

                omp_unset_lock(&lock_array[i_global]);
            }
            //note that computation of reactions is not performed here!
        }
    }
#endif

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

}; /* Class ResidualBasedEliminationBuilderAndSolver */

/*@} */

/**@name Type Definitions */
/*@{ */


/*@} */

} /* namespace Kratos.*/

#endif /* KRATOS_RESIDUAL_BASED_ELIMINATION_BUILDER_AND_SOLVER  defined */
