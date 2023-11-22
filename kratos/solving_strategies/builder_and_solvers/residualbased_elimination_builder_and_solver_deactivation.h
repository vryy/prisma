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

/* *********************************************************
*
*   Last Modified by:    $Author: rrossi $
*   Date:                $Date: 2008-11-19 16:12:53 $
*   Revision:            $Revision: 1.10 $
*
* ***********************************************************/


#if !defined(KRATOS_RESIDUAL_BASED_ELIMINATION_BUILDER_AND_SOLVER_DEACTIVATION )
#define  KRATOS_RESIDUAL_BASED_ELIMINATION_BUILDER_AND_SOLVER_DEACTIVATION


/* System includes */
#include <set>
#include <iomanip>

#ifdef _OPENMP
#include <omp.h>
#endif

/* External includes */
#include "boost/smart_ptr.hpp"

/* Project includes */
#include "includes/define.h"
#include "includes/matrix_market_interface.h"
#include "includes/kratos_flags.h"
#include "includes/deprecated_variables.h"
#include "utilities/timer.h"
#include "utilities/openmp_utils.h"
#include "solving_strategies/builder_and_solvers/builder_and_solver.h"

// #define ENABLE_LOG

//#define BUILDER_AND_SOLVER_DEBUG_LEVEL1
//#define BUILDER_AND_SOLVER_DEBUG_LEVEL2
// #define EXPORT_LHS_MATRIX
// #define EXPORT_RHS_VECTOR
//#define EXPORT_LOCAL_LHS_MATRIX
// #define EXPORT_SOL_VECTOR
// #define EXPORT_LHS_MATRIX_SAMPLING
// #define EXPORT_RHS_VECTOR_SAMPLING
// #define EXPORT_SOL_VECTOR_SAMPLING
//#define EXPORT_NODE_INFO

#define DOF_ENUMERATION_STRAIGHT
//#define DOF_ENUMERATION_FULL_STRAIGHT
//#define DOF_ENUMERATION_REVERSE //default method

#define QUERY_RESIDUAL_NORM
#define QUERY_DOFSET
#define QUERY_DOF_EQUATION_ID
#define QUERY_EQUATION_ID_AT_BUILD
//#define QUERY_DIAGONAL

#define DETECT_NAN_AT_BUILD // to enable this, must enable -fno-finite-math-only after -ffast-math in the compile flags
// REF: https://stackoverflow.com/questions/22931147/stdisinf-does-not-work-with-ffast-math-how-to-check-for-infinity

//#define ENABLE_FILTER_SMALL_ENTRIES

// #define ENABLE_SYSTEM_REORDERING

//#define MONITOR_MATRIX_ELEMENT_16_15
//#define MONITOR_EQUATIONID_20040

// #ifdef ENABLE_SYSTEM_REORDERING
// #include "utilities/rcm_utils.h"
// #endif

#define MODIFY_INACTIVE_PART_OF_THE_MATRIX
#define MODIFY_NEGATIVE_DIAGONAL
// #define INCLUDE_INACTIVE_ELEMENTS_IN_SETUP_DOFSET

// #define MEASURE_TIME_CUT_CELL

#ifdef ENABLE_LOG
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

BOOST_LOG_ATTRIBUTE_KEYWORD(my_timestamp, "TimeStamp", boost::log::attributes::local_clock::value_type)
BOOST_LOG_ATTRIBUTE_KEYWORD(my_process_id, "ProcessID", boost::log::attributes::current_process_id::value_type)
BOOST_LOG_ATTRIBUTE_KEYWORD(my_thread_id, "ThreadID", boost::log::attributes::current_thread_id::value_type)

#define MY_LOG_TRACE BOOST_LOG_SEV(m_log_level, boost::log::trivial::trace)

#endif


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
         class TDenseSpace , //= DenseSpace<double>,
         class TLinearSolver //= LinearSolver<TSparseSpace,TDenseSpace>
         >
class ResidualBasedEliminationBuilderAndSolverDeactivation
    : public BuilderAndSolver< TSparseSpace,TDenseSpace,TLinearSolver >
{
public:
    /**@name Type Definitions */
    /*@{ */
    //typedef boost::shared_ptr< ResidualBasedEliminationBuilderAndSolverDeactivation<TSparseSpace,TDenseSpace,TLinearSolver> > Pointer;
    KRATOS_CLASS_POINTER_DEFINITION( ResidualBasedEliminationBuilderAndSolverDeactivation );

    typedef BuilderAndSolver<TSparseSpace,TDenseSpace, TLinearSolver> BaseType;

    typedef typename BaseType::TSchemeType TSchemeType;

    typedef typename BaseType::TSparseSpaceType TSparseSpaceType;

    typedef typename BaseType::TLinearSolverType TLinearSolverType;

    typedef typename BaseType::TDataType TDataType;

    typedef typename BaseType::DofsArrayType DofsArrayType;

    typedef typename BaseType::TSystemMatrixType TSystemMatrixType;

    typedef typename BaseType::TSystemVectorType TSystemVectorType;

    typedef typename BaseType::LocalSystemVectorType LocalSystemVectorType;

    typedef typename BaseType::LocalSystemMatrixType LocalSystemMatrixType;

    typedef typename BaseType::TSystemMatrixPointerType TSystemMatrixPointerType;
    typedef typename BaseType::TSystemVectorPointerType TSystemVectorPointerType;

    typedef typename BaseType::NodesArrayType NodesArrayType;
    typedef typename BaseType::ElementsArrayType ElementsArrayType;
    typedef typename BaseType::ConditionsArrayType ConditionsArrayType;

    typedef typename BaseType::ElementsContainerType ElementsContainerType;

    /*@} */
    /**@name Life Cycle
    */
    /*@{ */

    /** Constructor.
    */
    ResidualBasedEliminationBuilderAndSolverDeactivation(
        typename TLinearSolver::Pointer pNewLinearSystemSolver)
        : BuilderAndSolver< TSparseSpace,TDenseSpace,TLinearSolver >(pNewLinearSystemSolver)
    {
        #ifdef ENABLE_LOG
        std::stringstream log_filename;
        log_filename << "residualbased_elimination_builder_and_solver_deactivation.log";
        this->init_logging(log_filename.str());
        #endif
        mLocalCounter = 0;
        mStepCounter = 0;
    }


    /** Destructor.
    */
    ~ResidualBasedEliminationBuilderAndSolverDeactivation() override
    {
    }


    /*@} */
    /**@name Operators
    */
    /*@{ */

    #ifdef ENABLE_LOG
    void init_logging(const std::string& filename)
    {
        typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_ostream_backend> text_sink_t;
        boost::shared_ptr<text_sink_t> sink = boost::make_shared<text_sink_t>();

        sink->locked_backend()->add_stream(boost::make_shared<std::ofstream>(filename));

        // Set the formatter
        sink->set_formatter
        (
            boost::log::expressions::stream
                #ifdef ENABLE_LOG_TIMESTAMP
                << "[" << my_timestamp << "]"
                #endif
                #ifdef ENABLE_LOG_PROCESS_AND_THREAD_ID
                << " [" my_process_id << ":" << my_thread_id << "] "
                #endif
                << boost::log::expressions::smessage
        );

        boost::log::core::get()->add_sink(sink);
        boost::log::add_common_attributes();
    }
    #endif

    //**************************************************************************
    //**************************************************************************
    void Build(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& b) override
    {
        KRATOS_TRY

        double building_time_start = Timer::GetTime();
        Timer::Start("Build");

        #ifdef MEASURE_TIME_CUT_CELL
        // if (!KratosComponents<VariableData>::Has("CUT_STATUS"))
        //     KRATOS_THROW_ERROR(std::logic_error, "The CUT_STATUS variable is not registerred in Kratos database. Please import FiniteCellApplication.", "")
        Variable<int>& CUT_STATUS_var = static_cast<Variable<int>&>(KratosComponents<VariableData>::Get("CUT_STATUS"));
        #endif

        if(!pScheme)
            KRATOS_THROW_ERROR(std::runtime_error, "No scheme provided!", "");

        if(r_model_part.MasterSlaveConstraints().size() != 0) {
            KRATOS_THROW_ERROR(std::logic_error, "This builder and solver does not support constraints!", "");
        }

        //getting the elements from the model
        ElementsArrayType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsArrayType& ConditionsArray = r_model_part.Conditions();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero( *(BaseType::mpReactionsVector) );

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0,0);
        LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

        //vector containing the localization in the system of the different
        //terms
        Element::EquationIdVectorType EquationId;

        //double StartTime = GetTickCount();

//        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
        // assemble all elements
#ifndef _OPENMP
        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
        for (typename ElementsArrayType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
                //calculate elemental contribution
                pScheme->CalculateSystemContributions(*it,LHS_Contribution,RHS_Contribution,EquationId,CurrentProcessInfo);

                #if defined(ENABLE_LOG) && defined(QUERY_EQUATION_ID_AT_BUILD)
                std::stringstream ss;
                ss << "Element " << it->Id() << " is accounted for Build, EquationId:";
                for(unsigned int i = 0; i < EquationId.size(); ++i)
                    ss << " " << EquationId[i];
                ss << std::endl;
                MY_LOG_TRACE << ss.str();
                #endif

                //assemble the elemental contribution
                AssembleLHS(A,LHS_Contribution,EquationId);
                AssembleRHS(b,RHS_Contribution,EquationId);

                // clean local elemental memory
                pScheme->CleanMemory(*it);
            }
        }
        //double EndTime = GetTickCount();

//std::cout << "total time " << EndTime - StartTime << std::endl;
//std::cout << "writing in the system matrix " << ccc << std::endl;
//std::cout << "calculating the elemental contrib " << ddd << std::endl;
        LHS_Contribution.resize(0, 0, false);
        RHS_Contribution.resize(0, false);

        // assemble all conditions
        for (typename ConditionsArrayType::iterator it = ConditionsArray.begin(); it != ConditionsArray.end(); ++it)
        {
            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
                //calculate elemental contribution
                pScheme->CalculateSystemContributions(*it,LHS_Contribution,RHS_Contribution,EquationId,CurrentProcessInfo);

                #if defined(ENABLE_LOG) && defined(QUERY_EQUATION_ID_AT_BUILD)
                std::stringstream ss;
                ss << "Condition " << it->Id() << " is accounted for Build, EquationId:";
                for(unsigned int i = 0; i < EquationId.size(); ++i)
                    ss << " " << EquationId[i];
                ss << std::endl;
                MY_LOG_TRACE << ss.str();
                #endif

                //assemble the elemental contribution
                AssembleLHS(A,LHS_Contribution,EquationId);
                AssembleRHS(b,RHS_Contribution,EquationId);

                // clean local conditional memory
//                pScheme->CleanMemory(*it); //not existing method
            }
        }
#else
//        KRATOS_WATCH("in Build: openmp initial");

        #ifdef MODIFY_INACTIVE_PART_OF_THE_MATRIX
        std::set<std::size_t> ActiveIdSet;
        std::set<std::size_t> InactiveIdSet;
        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
        for (typename ElementsArrayType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            it->EquationIdVector(EquationId, CurrentProcessInfo);

            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
                // for active elements, the equation id set is stored
                for(unsigned int i = 0; i < EquationId.size(); ++i)
                {
                    if(EquationId[i] < BaseType::mEquationSystemSize)
                        ActiveIdSet.insert(EquationId[i]);
                }
            }
            else
            // for IS_INACTIVE elements, the EquationId is stored to modify the diagonal later on
            {
                it->EquationIdVector(EquationId, CurrentProcessInfo);
                for(unsigned int i = 0; i < EquationId.size(); ++i)
                {
                    if(EquationId[i] < BaseType::mEquationSystemSize)
                        InactiveIdSet.insert(EquationId[i]);
                }
            }
        }

        for (typename ConditionsArrayType::iterator it = ConditionsArray.begin(); it != ConditionsArray.end(); ++it)
        {
            it->EquationIdVector(EquationId, CurrentProcessInfo);

            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
                // for active conditions, the equation id set is stored
                for(unsigned int i = 0; i < EquationId.size(); ++i)
                {
                    if(EquationId[i] < BaseType::mEquationSystemSize)
                        ActiveIdSet.insert(EquationId[i]);
                }
            }
            else
            // for IS_INACTIVE conditions, the EquationId is stored to modify the diagonal later on
            {
                it->EquationIdVector(EquationId, CurrentProcessInfo);
                for(unsigned int i = 0; i < EquationId.size(); ++i)
                {
                    if(EquationId[i] < BaseType::mEquationSystemSize)
                        InactiveIdSet.insert(EquationId[i]);
                }
            }
        }

        // for debugging: to check if all the active ids & inactive ids fully cover the range of mEquationSystemSize
        #ifdef ENABLE_LOG
        std::set<std::size_t> AllIdSet = ActiveIdSet;
        // AllIdSet.merge(InactiveIdSet);
        for(std::set<std::size_t>::iterator it = InactiveIdSet.begin(); it != InactiveIdSet.end(); ++it)
            AllIdSet.insert(*it);
        std::stringstream ss1;
        int cnt = 0;
        ss1 << "AllIdSet:" << std::endl;
        for(std::set<std::size_t>::iterator it = AllIdSet.begin(); it != AllIdSet.end(); ++it)
        {
            ss1 << " " << (*it);
            ++cnt;
            if (cnt == 30)
            {
                ss1 << std::endl;
                cnt = 0;
            }
        }
        ss1 << std::endl;
        MY_LOG_TRACE << ss1.str();
        #endif

        // remove the duplicated ids
        std::vector<std::size_t> tempVector(InactiveIdSet.size());
        std::vector<std::size_t>::iterator it
            = std::set_difference(InactiveIdSet.begin(), InactiveIdSet.end(),
                                 ActiveIdSet.begin(), ActiveIdSet.end(),
                                 tempVector.begin());
        tempVector.resize(it - tempVector.begin());

        InactiveIdSet.clear();
        for(std::vector<std::size_t>::iterator it = tempVector.begin(); it != tempVector.end(); ++it)
            InactiveIdSet.insert(*it);

        // size check
        std::cout << "There are " << ActiveIdSet.size() << " active id's and " << InactiveIdSet.size() << " inactive id's" << std::endl;
        if((ActiveIdSet.size() + InactiveIdSet.size()) != BaseType::mEquationSystemSize)
        {
            KRATOS_WATCH(ActiveIdSet.size())
            KRATOS_WATCH(InactiveIdSet.size())
            KRATOS_WATCH(BaseType::mEquationSystemSize)
            KRATOS_THROW_ERROR(std::logic_error, "Error: The active set of equation id's and inactive set of equation id's do not cover whole mEquationSystemSize. Check the enumeration.", __FUNCTION__)
        }
        #endif

        std::vector< omp_lock_t > lock_array(A.size1());

        int A_size = A.size1();
        for(int i = 0; i < A_size; ++i)
            omp_init_lock(&lock_array[i]);

        //create a partition of the element array
        int number_of_threads = omp_get_max_threads();

        boost::numeric::ublas::vector<unsigned int> element_partition;
        OpenMPUtils::CreatePartition(number_of_threads, pElements.size(), element_partition);
        KRATOS_WATCH( number_of_threads );
        KRATOS_WATCH( element_partition );

        double start_prod = omp_get_wtime();

//        KRATOS_WATCH("in Build: before thread looping for elements");

        double DiagonalSum = 0.0;

        #pragma omp parallel for reduction(+:DiagonalSum)
        for(int k = 0; k < number_of_threads; ++k)
        {
//            std::cout << "thread " << k << " is spawned" << std::endl;

            //contributions to the system
            LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);
            LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

            //vector containing the localization in the system of the different
            //terms
            Element::EquationIdVectorType EquationId;
            ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
            typename ElementsArrayType::iterator it_begin = pElements.ptr_begin() + element_partition[k];
            typename ElementsArrayType::iterator it_end = pElements.ptr_begin() + element_partition[k+1];

            // assemble all elements
            for (typename ElementsArrayType::iterator it = it_begin; it != it_end; ++it)
            {
                #ifdef MEASURE_TIME_CUT_CELL
                if(it->GetValue(CUT_STATUS_var) == -1)
                    Timer::Start("Build_Cut_Element");
                #endif

                if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
                {
                    //calculate elemental contribution
                    pScheme->CalculateSystemContributions(*it,LHS_Contribution,RHS_Contribution,EquationId,CurrentProcessInfo);

                    #ifdef DETECT_NAN_AT_BUILD
                    double norm_elem_k = norm_frobenius(LHS_Contribution);
                    double norm_elem_r = norm_2(RHS_Contribution);

                    if (std::isnan(norm_elem_k) || std::isnan(norm_elem_r))
                    {
                        KRATOS_WATCH(norm_elem_k)
                        KRATOS_WATCH(norm_elem_r)
                        KRATOS_WATCH(LHS_Contribution)
                        KRATOS_WATCH(RHS_Contribution)
                        std::cout << "type of element: " << typeid((*it)).name() << std::endl;
                        std::cout << "element Properties " << it->GetProperties().Id() << ": " << it->GetProperties() << std::endl;
                        KRATOS_WATCH((*it))
                        KRATOS_THROW_ERROR(std::logic_error, "NaN is detected at element ", it->Id())
                    }
                    #endif

                    // for (int i = 0; i < EquationId.size(); ++i)
                    // {
                    //     if (EquationId[i] == 0)
                    //     {
                    //         std::cout << "Element " << it->Id() << " contributes " << RHS_Contribution(i) << " to row " << EquationId[i] << std::endl;
                    //         std::cout << "EquationId:";
                    //         for (int i = 0; i < EquationId.size(); ++i)
                    //             std::cout << " " << EquationId[i];
                    //         std::cout << std::endl;
                    //         break;
                    //     }
                    // }

//                    KRATOS_WATCH(LHS_Contribution);
//                    KRATOS_WATCH(RHS_Contribution);
                    #ifdef EXPORT_LOCAL_LHS_MATRIX
                    std::stringstream lhs_filename;
                    lhs_filename << "ke_" << mStepCounter << "_" << mLocalCounter << "_" << it->Id() << ".mm";
                    CompressedMatrix tmp_lhs = LHS_Contribution;
                    WriteMatrixMarketMatrix(lhs_filename.str().c_str(), tmp_lhs, false);

                    std::stringstream eqid_filename;
                    eqid_filename << "eq_" << mStepCounter << "_" << mLocalCounter << "_" << it->Id() << ".txt";
                    std::ofstream eqfid;
                    eqfid.open(eqid_filename.str().c_str());
                    for (std::size_t i = 0; i < EquationId.size(); ++i)
                        eqfid << EquationId[i] << std::endl;
                    eqfid.close();
                    #endif

                    #if defined(ENABLE_LOG) && defined(QUERY_EQUATION_ID_AT_BUILD)
                    std::stringstream ss;
                    ss << "Element " << it->Id() << " is accounted for Build, EquationId:";
                    for(unsigned int i = 0; i < EquationId.size(); ++i)
                        ss << " " << EquationId[i];
                    ss << std::endl;
                    MY_LOG_TRACE << ss.str();
                    #endif

                    //assemble the elemental contribution
                    Assemble(A,b,LHS_Contribution,RHS_Contribution,EquationId,lock_array);
                    // clean local elemental memory
                    pScheme->CleanMemory(*it);

                    //compute sum of the diagonal
                    double LocalDiagonalSum = 0.0;
                    for(unsigned int i = 0; i < EquationId.size(); ++i)
                    {
                        if(EquationId[i] < BaseType::mEquationSystemSize)
                            LocalDiagonalSum += LHS_Contribution(i, i);
                    }

                    //update the global diagonal sum
                    DiagonalSum += LocalDiagonalSum;
                }

                #ifdef MEASURE_TIME_CUT_CELL
                if(it->GetValue(CUT_STATUS_var) == -1)
                    Timer::Stop("Build_Cut_Element");
                #endif
            }
        }
        std::cout << "Element assembly completed" << std::endl;

        boost::numeric::ublas::vector<unsigned int> condition_partition;
        OpenMPUtils::CreatePartition(number_of_threads, ConditionsArray.size(), condition_partition);
        KRATOS_WATCH( condition_partition );

//        KRATOS_WATCH("in Build: before thread looping for conditions");

        #pragma omp parallel for reduction(+:DiagonalSum)
        for(int k = 0; k < number_of_threads; ++k)
        {
            //contributions to the system
            LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);
            LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

            Condition::EquationIdVectorType EquationId;

            ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

            typename ConditionsArrayType::iterator it_begin = ConditionsArray.ptr_begin() + condition_partition[k];
            typename ConditionsArrayType::iterator it_end = ConditionsArray.ptr_begin() + condition_partition[k+1];

            // assemble all conditions
            for (typename ConditionsArrayType::iterator it = it_begin; it != it_end; ++it)
            {
                if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
                {
//                    std::cout << "Condition " << it->Id() << " is considerred, type: " << typeid((*it)).name() << std::endl;
                    //calculate elemental contribution
                    pScheme->CalculateSystemContributions(*it,LHS_Contribution,RHS_Contribution,EquationId,CurrentProcessInfo);

                    #ifdef DETECT_NAN_AT_BUILD
                    double norm_cond_k = norm_frobenius(LHS_Contribution);
                    double norm_cond_r = norm_2(RHS_Contribution);

                    if (std::isnan(norm_cond_k) || std::isnan(norm_cond_r))
                    {
                        KRATOS_WATCH(norm_cond_k)
                        KRATOS_WATCH(norm_cond_r)
                        std::cout << "type of condition: " << typeid((*it)).name() << std::endl;
                        std::cout << "condition Properties " << it->GetProperties().Id() << ": " << it->GetProperties() << std::endl;
                        KRATOS_WATCH((*it))
                        KRATOS_THROW_ERROR(std::logic_error, "NaN is detected at condition ", it->Id())
                    }
                    #endif

                    // for (int i = 0; i < EquationId.size(); ++i)
                    // {
                    //     if (EquationId[i] == 0)
                    //     {
                    //         std::cout << "Condition " << it->Id() << " contributes " << RHS_Contribution(i) << " to row " << EquationId[i] << std::endl;
                    //         std::cout << "EquationId:";
                    //         for (int i = 0; i < EquationId.size(); ++i)
                    //             std::cout << " " << EquationId[i];
                    //         std::cout << std::endl;
                    //         break;
                    //     }
                    // }

                    #if defined(ENABLE_LOG) && defined(QUERY_EQUATION_ID_AT_BUILD)
                    std::stringstream ss;
                    ss << "Condition " << it->Id() << " is accounted for Build, EquationId:";
                    for(unsigned int i = 0; i < EquationId.size(); ++i)
                        ss << " " << EquationId[i];
                    ss << std::endl;
                    MY_LOG_TRACE << ss.str();
                    #endif

                    //assemble the conditional contribution
                    Assemble(A,b,LHS_Contribution,RHS_Contribution,EquationId,lock_array);
                    // clean local conditional memory
//                    pScheme->CleanMemory(*it); //not existing method

                    //compute sum of the diagonal
                    double LocalDiagonalSum = 0.0;
                    for(unsigned int i = 0; i < EquationId.size(); ++i)
                    {
                        if(EquationId[i] < BaseType::mEquationSystemSize)
                            LocalDiagonalSum += LHS_Contribution(i, i);
                    }

                    //update the global diagonal sum
                    DiagonalSum += LocalDiagonalSum;
//                    std::cout << "Condition " << it->Id() << " rhs: " << RHS_Contribution << std::endl;
//                    std::cout << "Condition " << it->Id() << " is assembled" << std::endl;
                }
            }
        }
        std::cout << "Condition assembly completed" << std::endl;

        double stop_prod = omp_get_wtime();
        for(int i = 0; i < A_size; ++i)
            omp_destroy_lock(&lock_array[i]);

        #ifdef MODIFY_INACTIVE_PART_OF_THE_MATRIX

        // compute the modification factor: simply average of the diagonal
        double DiagonalAverage = DiagonalSum / (BaseType::mEquationSystemSize - mFixedLength);
        KRATOS_WATCH(DiagonalAverage)

        // modify the matrix as needed
        for(std::set<std::size_t>::iterator it = InactiveIdSet.begin(); it != InactiveIdSet.end(); ++it)
        {
            if(*it < BaseType::mEquationSystemSize)
                A(*it, *it) = DiagonalAverage;
        }
        int fixed_offset = BaseType::mEquationSystemSize - mFixedLength;
        for(unsigned int i = 0; i < mFixedLength; ++i)
        {
            unsigned int j = fixed_offset + i;
            noalias(row(A, j)) = ZeroVector(BaseType::mEquationSystemSize);
            A(j, j) = DiagonalAverage;
            b(j)    = 0.0;
        }

        std::cout << "modification of diagonal for inactive part completed, " << InactiveIdSet.size() << " entries are modified" << std::endl;
        #endif
        std::cout << "finished parallel building: " << stop_prod - start_prod << " s" << std::endl;
#endif

        //finalize the build of compressed matrix
        A.complete_index1_data();

        unsigned int counter = 0;
        #ifdef ENABLE_FILTER_SMALL_ENTRIES
        //remove the small entries to improve the condition of the matrix
        double drop_tol = 1e-6;
        for(unsigned int row = 0; row < BaseType::mEquationSystemSize; ++row)
        {
            unsigned int nonzeros = A.index1_data()[row + 1] - A.index1_data()[row];
            for(unsigned int j = 0; j < nonzeros; ++j)
            {
                unsigned int col = A.index2_data()[counter];

                //make a check for base of indice. Here we assume that A(0,0) is nonzero
                if(counter == 0)
                {
                    if(col != 0)
                    {
                        KRATOS_THROW_ERROR(std::logic_error, "Base indice for CSR must be 0", "")
                    }
                }

                double val = A.value_data()[counter];

                if( ( fabs(val) < drop_tol ) && ( row != col ) )
                {
                    A(row, col) = 0;
                    //A.erase_element(row, col);
                }

                ++counter;
            }
        }

        // check the right hand side vector at inactive set
        double sum_inactive_rhs = 0.0;
        for(std::set<std::size_t>::iterator it = InactiveIdSet.begin(); it != InactiveIdSet.end(); ++it)
        {
            if(*it < BaseType::mEquationSystemSize)
                sum_inactive_rhs += fabs(b[*it]);
        }
        if(sum_inactive_rhs > 0.0)
        {
            KRATOS_THROW_ERROR(std::logic_error, "Error: Right hand side at inactive id's is nonzero. Check the assembly or enumeration", __FUNCTION__)
        }
        else
            std::cout << "Sum of inactive ids is zero, which is ok" << std::endl;

        #ifdef MODIFY_NEGATIVE_DIAGONAL
        // detect the negative diagonal and multiply LHS & RHS as needed
        for(std::set<std::size_t>::iterator it = ActiveIdSet.begin(); it != ActiveIdSet.end(); ++it)
        {
            if(*it < BaseType::mEquationSystemSize)
                if(A(*it, *it) < 0)
                {
                    ++counter;
                    row(A, *it) *= (-1.0);
                    b(*it) *= (-1.0);
                }
        }
        std::cout << "Modify negative diagonal completed, " << counter << " row is multiplied with -1" << std::endl;
        #endif

        #endif

        Timer::Stop("Build");
        double building_time_stop = Timer::GetTime();

        if(this->GetEchoLevel()>0)
        {
            std::cout << "Building Time : " << (building_time_stop - building_time_start) << std::endl;
        }

        #ifdef EXPORT_LHS_MATRIX
        std::stringstream lhs_filename;
        lhs_filename << "A_" << mStepCounter << "." << mLocalCounter << ".mm";
        WriteMatrixMarketMatrix(lhs_filename.str().c_str(), A, false);
        #endif

        #ifdef EXPORT_LHS_MATRIX_SAMPLING
        if(mLocalCounter == 0 && mStepCounter == 0)
        {
            std::stringstream lhs_filename;
            lhs_filename << "A_" << mStepCounter << "." << mLocalCounter << ".mm";
            WriteMatrixMarketMatrix(lhs_filename.str().c_str(), A, false);
        }
        #endif

        #ifdef EXPORT_RHS_VECTOR
        std::stringstream rhs_filename;
        rhs_filename << "b_" << mStepCounter << "." << mLocalCounter << ".mm";
        WriteMatrixMarketVector(rhs_filename.str().c_str(), b);
        #endif

        #ifdef EXPORT_RHS_VECTOR_SAMPLING
        if(mLocalCounter == 0 && mStepCounter == 0)
        {
            std::stringstream rhs_filename;
            rhs_filename << "b_" << mStepCounter << "." << mLocalCounter << ".mm";
            WriteMatrixMarketVector(rhs_filename.str().c_str(), b);
        }
        #endif

        #ifdef ENABLE_LOG
        MY_LOG_TRACE << "Build completed, mStepCounter = " << mStepCounter << ", mLocalCounter = " << mLocalCounter << std::endl;
        #endif
        ++mLocalCounter;

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************
    void BuildLHS(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A) override
    {
        KRATOS_TRY

        //getting the elements from the model
        ElementsArrayType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsArrayType& ConditionsArray = r_model_part.Conditions();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero( *(BaseType::mpReactionsVector) );

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0,0);

        //vector containing the localization in the system of the different
        //terms
        Element::EquationIdVectorType EquationId;

        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        // assemble all elements
        for (typename ElementsArrayType::iterator it=pElements.begin(); it!=pElements.end(); ++it)
        {
            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
                //calculate elemental contribution
                pScheme->CalculateLHSContribution(*it,LHS_Contribution,EquationId,CurrentProcessInfo);

                //assemble the elemental contribution
                AssembleLHS(A,LHS_Contribution,EquationId);

                // clean local elemental memory
                pScheme->CleanMemory(*it);
            }
        }

        LHS_Contribution.resize(0,0,false);

        // assemble all conditions
        for (typename ConditionsArrayType::iterator it=ConditionsArray.begin(); it!=ConditionsArray.end(); ++it)
        {
            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
                //calculate elemental contribution
                pScheme->CalculateLHSContribution(*it,LHS_Contribution,EquationId,CurrentProcessInfo);

                //assemble the elemental contribution
                AssembleLHS(A,LHS_Contribution,EquationId);
            }
        }

        KRATOS_CATCH("")

    }

    //**************************************************************************
    //**************************************************************************
    void BuildLHS_CompleteOnFreeRows(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A) override
    {
        KRATOS_TRY

        //getting the elements from the model
        ElementsArrayType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsArrayType& ConditionsArray = r_model_part.Conditions();

        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero( *(BaseType::mpReactionsVector) );

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0,0);

        //vector containing the localization in the system of the different
        //terms
        Element::EquationIdVectorType EquationId;

        // assemble all elements
        for (typename ElementsArrayType::iterator it=pElements.begin(); it!=pElements.end(); ++it)
        {
            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
                //calculate elemental contribution
                pScheme->CalculateLHSContribution(*it,LHS_Contribution,EquationId,CurrentProcessInfo);

                //assemble the elemental contribution
                AssembleLHS_CompleteOnFreeRows(A,LHS_Contribution,EquationId);

                // clean local elemental memory
                pScheme->CleanMemory(*it);
            }
        }

        LHS_Contribution.resize(0,0,false);
        // assemble all conditions
        for (typename ConditionsArrayType::iterator it=ConditionsArray.begin(); it!=ConditionsArray.end(); ++it)
        {
            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
                //calculate elemental contribution
                pScheme->CalculateLHSContribution(*it,LHS_Contribution,EquationId,CurrentProcessInfo);

                //assemble the elemental contribution
                AssembleLHS_CompleteOnFreeRows(A,LHS_Contribution,EquationId);
            }
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

        double solve_time_start = Timer::GetTime();
        Timer::Start("SystemSolve");

        double norm_b;
        if( TSparseSpace::Size(b) != 0)
            norm_b = TSparseSpace::TwoNorm(b);
        else
            norm_b = 0.00;

        if(norm_b != 0.00)
            BaseType::mpLinearSystemSolver->Solve(A,Dx,b);
        else
            TSparseSpace::SetToZero(Dx);

        //prints informations about the current time
        if(this->GetEchoLevel() > 1)
        {
            std::cout << *(BaseType::mpLinearSystemSolver) << std::endl;
        }

        double solve_time_stop = Timer::GetTime();
        Timer::Stop("SystemSolve");

        if(this->GetEchoLevel()>0)
        {
            std::cout << "System Solve Time : " << (solve_time_stop - solve_time_start) << std::endl;
        }

        #ifdef EXPORT_SOL_VECTOR_SAMPLING
        if(mLocalCounter == 1 && mStepCounter == 0)
        {
            std::stringstream dx_filename;
            dx_filename << "dx_" << mStepCounter << "." << mLocalCounter-1 << ".mm";
            WriteMatrixMarketVector(dx_filename.str().c_str(), Dx);
        }
        #endif

        #ifdef EXPORT_SOL_VECTOR
        std::stringstream dx_filename;
        dx_filename << "dx_" << mStepCounter << "." << mLocalCounter-1 << ".mm";
        WriteMatrixMarketVector(dx_filename.str().c_str(), Dx);
        #endif

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************
    void BuildAndSolve(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
        KRATOS_TRY

        Build(pScheme,r_model_part,A,b);

        #ifdef EXPORT_NODE_INFO
        std::stringstream fn;
        fn << "info_" << mStepCounter << "." << mLocalCounter << ".dat";
//        fn << "info_" << r_model_part.GetProcessInfo()[TIME] << ".dat";
        std::ofstream info;
        info.open(fn.str().c_str());
        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin();
                    dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
        {
            if(dof_iterator->EquationId() < BaseType::mEquationSystemSize)
            {
                ModelPart::NodeType& node = r_model_part.GetNode(dof_iterator->Id());
                info << (dof_iterator->EquationId() + 1) << " " << dof_iterator->GetVariable().Name() << " "
                     << dof_iterator->Id() << " " << node.X0() << " " << node.Y0() << " " << node.Z0() << std::endl;
            }
        }
        info.close();
        std::cout << "Exported " << fn.str() << std::endl;
        #endif

//          ApplyPointLoads(pScheme,r_model_part,b);

        //does nothing...dirichlet conditions are naturally dealt with in defining the residual
        ApplyDirichletConditions(pScheme,r_model_part,A,Dx,b);

        if (this->GetEchoLevel()== 3)
        {
            std::cout << "before the solution of the system" << std::endl;
            std::cout << "System Matrix = " << A << std::endl;
            std::cout << "unknowns vector = " << Dx << std::endl;
            std::cout << "RHS vector = " << b << std::endl;
        }

        #ifdef QUERY_RESIDUAL_NORM
        TSystemVectorType b_0 = b;
        #endif

        #ifdef QUERY_DIAGONAL
        for(int i = 0; i < BaseType::mEquationSystemSize; ++i)
        {
            if(A(i, i) < 0.0)
                std::cout << "Warning: the diagonal is negative at (" << i << ", " << i << "): " << A(i, i) << std::endl;
        }
        #endif

        //provide additional data to the solver/preconditioner
        BaseType::mpLinearSystemSolver->ProvideAdditionalData(A, Dx, b, BaseType::mDofSet, r_model_part);

        //solve the system
        SystemSolve(A,Dx,b);

        if (this->GetEchoLevel()== 3)
        {
            std::cout << "after the solution of the system" << std::endl;
            std::cout << "System Matrix = " << A << std::endl;
            std::cout << "unknowns vector = " << Dx << std::endl;
            std::cout << "RHS vector = " << b << std::endl;
        }

        #ifdef QUERY_RESIDUAL_NORM
        double norm_b = TSparseSpace::TwoNorm(b_0);
        TSystemVectorType r(BaseType::mEquationSystemSize);
        TSparseSpace::Mult(A, Dx, r);
        TSparseSpace::UnaliasedAdd(r, -1.0, b_0);
        double norm_r = TSparseSpace::TwoNorm(r);
        std::cout << "||r||_2 / ||b||_2: " << norm_r/norm_b << std::endl;
        std::cout << "||r||_2: " << norm_r << std::endl;
        std::cout << "||b||_2: " << norm_b << std::endl;
        #endif

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************
    void BuildRHSAndSolve(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
        KRATOS_TRY

        BuildRHS(pScheme,r_model_part,b);
        SystemSolve(A,Dx,b);

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************
    void BuildRHS(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemVectorType& b) override
    {
        KRATOS_TRY

        //Getting the Elements
        ElementsArrayType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsArrayType& ConditionsArray = r_model_part.Conditions();

        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero( *(BaseType::mpReactionsVector) );

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0,0);
        LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

        //vector containing the localization in the system of the different
        //terms
        Element::EquationIdVectorType EquationId;

        // assemble all elements
        for (typename ElementsArrayType::iterator it=pElements.begin(); it!=pElements.end(); ++it)
        {
            //calculate elemental Right Hand Side Contribution
            pScheme->CalculateRHSContribution(*it,RHS_Contribution,EquationId,CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleRHS(b,RHS_Contribution,EquationId);
        }

        LHS_Contribution.resize(0,0,false);
        RHS_Contribution.resize(0,false);

        // assemble all conditions
        for (typename ConditionsArrayType::iterator it=ConditionsArray.begin(); it!=ConditionsArray.end(); ++it)
        {
            //calculate elemental contribution
            pScheme->CalculateRHSContribution(*it,RHS_Contribution,EquationId,CurrentProcessInfo);

            //assemble the elemental contribution
            AssembleRHS(b,RHS_Contribution,EquationId);
        }

        KRATOS_CATCH("")

    }

    //**************************************************************************
    //**************************************************************************
    void BuildRHSreactions(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemVectorType& b)
    {
        KRATOS_TRY

        //Getting the Elements
        ElementsArrayType& pElements = r_model_part.Elements();

        //getting the array of the conditions
        ConditionsArrayType& ConditionsArray = r_model_part.Conditions();

        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        //resetting to zero the vector of reactions
        TSparseSpace::SetToZero( *(BaseType::mpReactionsVector) );

        //contributions to the system
        LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0,0);
        LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

        //vector containing the localization in the system of the different
        //terms

        #ifndef _OPENMP
            Element::EquationIdVectorType EquationId;
            // assemble all elements
            for (typename ElementsArrayType::iterator it = pElements.begin(); it != pElements.end(); ++it)
            {
                if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
                {
                    //calculate elemental Right Hand Side Contribution
                    pScheme->CalculateRHSContribution(*it,RHS_Contribution,EquationId,CurrentProcessInfo);

                    //assemble the elemental contribution
                    AssembleRHSreactions(b,RHS_Contribution,EquationId);
                }
            }
        #else
            int number_of_threads = omp_get_max_threads();
            boost::numeric::ublas::vector<unsigned int> element_partition;
            OpenMPUtils::CreatePartition(number_of_threads, pElements.size(), element_partition);
            std::cout << "number_of_threads for BuildRHSreactions: " << number_of_threads << std::endl;

            #pragma omp parallel for
            for(unsigned int k = 0; k < number_of_threads; ++k)
            {
                //contributions to the system
                LocalSystemMatrixType LHS_Contribution = LocalSystemMatrixType(0, 0);
                LocalSystemVectorType RHS_Contribution = LocalSystemVectorType(0);

                //vector containing the localization in the system of the different terms
                Element::EquationIdVectorType EquationId;
                ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
                typename ElementsArrayType::iterator it_begin = pElements.ptr_begin() + element_partition[k];
                typename ElementsArrayType::iterator it_end = pElements.ptr_begin() + element_partition[k + 1];

                for (typename ElementsArrayType::iterator it = it_begin; it != it_end; ++it)
                {
                    if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
                    {
                        //calculate elemental Right Hand Side Contribution
                        pScheme->CalculateRHSContribution(*it,RHS_Contribution,EquationId,CurrentProcessInfo);

                        //assemble the elemental contribution
                        AssembleRHSreactions(b,RHS_Contribution,EquationId);
                    }
                }
            }
        #endif

        //conditions shall not be accounted when calculating reactions

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************
    void SetUpDofSet(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part
    ) override
    {
        KRATOS_TRY

        std::cout << "setting up the dofs" << std::endl;
        Timer::Start("SetUpDofSet");

        // obtain the dofs from elements

        Element::DofsVectorType DofList;

        ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();

        DofsArrayType Doftemp;
        // BaseType::mDofSet = DofsArrayType();
        //mDofSet.clear();

        mAllDofs.clear();

        ElementsArrayType& pElements = r_model_part.Elements();
        std::size_t num_active_elements = 0;
        for (typename ElementsArrayType::iterator it=pElements.begin(); it!=pElements.end(); ++it)
        {
            // gets list of Dof involved on every element
            pScheme->GetDofList(*it,DofList,CurrentProcessInfo);

            for(typename Element::DofsVectorType::iterator i = DofList.begin() ; i != DofList.end() ; ++i)
                mAllDofs.push_back(*i);

            #ifndef INCLUDE_INACTIVE_ELEMENTS_IN_SETUP_DOFSET
            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
            #endif
                for(typename Element::DofsVectorType::iterator i = DofList.begin() ; i != DofList.end() ; ++i)
                    Doftemp.push_back(*i);
                ++num_active_elements;
            #ifndef INCLUDE_INACTIVE_ELEMENTS_IN_SETUP_DOFSET
            }
            #endif
        }
        KRATOS_WATCH(pElements.size());
        KRATOS_WATCH(num_active_elements);

        // taking in account conditions
        ConditionsArrayType& pConditions = r_model_part.Conditions();
        std::size_t num_active_conditions = 0;
        for (typename ConditionsArrayType::iterator it=pConditions.begin(); it!=pConditions.end(); ++it)
        {
            // gets list of Dof involved on every condition
            pScheme->GetDofList(*it,DofList,CurrentProcessInfo);

            for(typename Element::DofsVectorType::iterator i = DofList.begin() ; i != DofList.end() ; ++i)
                mAllDofs.push_back(*i);

            #ifndef INCLUDE_INACTIVE_ELEMENTS_IN_SETUP_DOFSET
            if( !it->GetValue( IS_INACTIVE ) || it->Is( ACTIVE ) )
            {
            #endif
                for(typename Element::DofsVectorType::iterator i = DofList.begin() ; i != DofList.end() ; ++i)
                    Doftemp.push_back(*i);
                ++num_active_conditions;
            #ifndef INCLUDE_INACTIVE_ELEMENTS_IN_SETUP_DOFSET
            }
            #endif
        }
        KRATOS_WATCH(pConditions.size());
        KRATOS_WATCH(num_active_conditions)

        Doftemp.Unique();

        BaseType::mDofSet = Doftemp;

        KRATOS_WATCH(mAllDofs.size())
        KRATOS_WATCH(BaseType::mDofSet.size())

        //throws an execption if there are no Degrees of freedom involved in the analysis
//        if (BaseType::mDofSet.size()==0)
//            KRATOS_THROW_ERROR(std::logic_error, "No degrees of freedom!", "");

        BaseType::mDofSetIsInitialized = true;

        Timer::Stop("SetUpDofSet");

        #if defined(ENABLE_LOG) && defined(QUERY_DOFSET)
        MY_LOG_TRACE << "At SetUpDofSet: try to probe all dofs of the current process" << std::endl;
        MY_LOG_TRACE << "There are " << BaseType::mDofSet.size() << " dofs in the problem" << std::endl;
        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
        {
            MY_LOG_TRACE << "dof " << dof_iterator->GetVariable().Name() << ", node = " << dof_iterator->Id() << std::endl;
        }
        MY_LOG_TRACE << "#########################SetUpDofSet completed####################" << std::endl;
        #endif

        KRATOS_CATCH("")
    }

    //**************************************************************************
    //**************************************************************************
    #ifdef DOF_ENUMERATION_REVERSE
    void SetUpSystem(
        ModelPart& r_model_part
    ) override
    {
        // initialize the equation id for every dofs in the system. This is to avoid any untouched dofs when the elements are deactivated.
        for (typename DofsArrayType::iterator dof_iterator = mAllDofs.begin(); dof_iterator != mAllDofs.end(); ++dof_iterator)
        {
            dof_iterator->SetEquationId(-1);
        }

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
        mFixedLength = 0;

        KRATOS_WATCH(BaseType::mEquationSystemSize)

        #if defined(ENABLE_LOG) && defined(QUERY_DOF_EQUATION_ID)
        MY_LOG_TRACE << "SetUpSystem: try to probe equation id of all dofs of the current process" << std::endl;
        MY_LOG_TRACE << "There are " << BaseType::mDofSet.size() << " dofs in the current process" << std::endl;
        MY_LOG_TRACE << "(* Step = " << mStepCounter << ", Substep = " << mLocalCounter << " *)" << std::endl;
        MY_LOG_TRACE << "dof\tnode\tEquationId" << std::endl;
        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
            MY_LOG_TRACE << dof_iterator->GetVariable().Name() << '\t' << dof_iterator->Id() << '\t' << dof_iterator->EquationId() << std::endl;
        MY_LOG_TRACE << "#########################SetUpSystem completed####################" << std::endl;
        #endif
    }
    #endif

    //a different enumeration strategy to compare with parallel enumeration strategy
    #ifdef DOF_ENUMERATION_STRAIGHT
    void SetUpSystem(
        ModelPart& r_model_part
    ) override
    {
        #ifdef ENABLE_LOG
        MY_LOG_TRACE << "DOF_ENUMERATION_STRAIGHT" << std::endl;
        #endif

        // initialize the equation id for every dofs in the system. This is to avoid any untouched dofs when the elements are deactivated.
        for (typename DofsArrayType::iterator dof_iterator = mAllDofs.begin(); dof_iterator != mAllDofs.end(); ++dof_iterator)
        {
            dof_iterator->SetEquationId(-1);
        }

        int free_size = 0; //number of free d.o.fs in the partition 'rank'
        int fixed_size = 0; //number of fixed d.o.fs in the partition 'rank'

        // Calculating number of fixed and free dofs
        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
        {
            if (dof_iterator->IsFixed())
                ++fixed_size;
            else
                ++free_size;
        }

        BaseType::mEquationSystemSize = free_size;
        mFixedLength = 0;
        int fixed_offset = BaseType::mEquationSystemSize;
        int free_offset = 0;

        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
        {
            if (dof_iterator->IsFixed())
                dof_iterator->SetEquationId(fixed_offset++);
            else
                dof_iterator->SetEquationId(free_offset++);
        }

        KRATOS_WATCH(BaseType::mEquationSystemSize)

        #if defined(ENABLE_LOG) && defined(QUERY_DOF_EQUATION_ID)
        MY_LOG_TRACE << "SetUpSystem: try to probe equation id of all dofs of the current process" << std::endl;
        MY_LOG_TRACE << "There are " << BaseType::mDofSet.size() << " dofs in the current process" << std::endl;
        MY_LOG_TRACE << "(* Step = " << mStepCounter << ", Substep = " << mLocalCounter << " *)" << std::endl;
        MY_LOG_TRACE << "dof\tnode\tEquationId" << std::endl;
        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
            MY_LOG_TRACE << dof_iterator->GetVariable().Name() << '\t' << dof_iterator->Id() << '\t' << dof_iterator->EquationId() << std::endl;
        MY_LOG_TRACE << "#########################SetUpSystem completed####################" << std::endl;
        #endif

//        r_model_part.GetProcessInfo()[SYSTEM_SIZE] = BaseType::mEquationSystemSize;
    }
    #endif

    #ifdef DOF_ENUMERATION_FULL_STRAIGHT
    void SetUpSystem(
        ModelPart& r_model_part
    ) override
    {
        #ifdef ENABLE_LOG
        MY_LOG_TRACE << "DOF_ENUMERATION_FULL_STRAIGHT" << std::endl;
        #endif

        // initialize the equation id for every dofs in the system. This is to avoid any untouched dofs when the elements are deactivated.
        for (typename DofsArrayType::iterator dof_iterator = mAllDofs.begin(); dof_iterator != mAllDofs.end(); ++dof_iterator)
        {
            dof_iterator->SetEquationId(-1);
        }

        int free_size = 0; //number of free d.o.fs in the partition 'rank'
        int fixed_size = 0; //number of fixed d.o.fs in the partition 'rank'

        // Calculating number of fixed and free dofs
        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
        {
            if (dof_iterator->IsFixed())
                ++fixed_size;
            else
                ++free_size;
        }

        BaseType::mEquationSystemSize = free_size + fixed_size;
        mFixedLength = fixed_size;
        int fixed_offset = free_size;
        int free_offset = 0;

        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
        {
            if (dof_iterator->IsFixed())
                dof_iterator->SetEquationId(fixed_offset++);
            else
                dof_iterator->SetEquationId(free_offset++);
        }

        KRATOS_WATCH(BaseType::mEquationSystemSize)

        #if defined(ENABLE_LOG) && defined(QUERY_DOF_EQUATION_ID)
        MY_LOG_TRACE << "SetUpSystem: try to probe equation id of all dofs of the current process" << std::endl;
        MY_LOG_TRACE << "There are " << BaseType::mDofSet.size() << " dofs in the current process" << std::endl;
        MY_LOG_TRACE << "(* Step = " << mStepCounter << ", Substep = " << mLocalCounter << " *)" << std::endl;
        MY_LOG_TRACE << "dof\tnode\tEquationId" << std::endl;
        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
            MY_LOG_TRACE << dof_iterator->GetVariable().Name() << '\t' << dof_iterator->Id() << '\t' << dof_iterator->EquationId() << std::endl;
        MY_LOG_TRACE << "#########################SetUpSystem completed####################" << std::endl;
        #endif

//        r_model_part.GetProcessInfo()[SYSTEM_SIZE] = BaseType::mEquationSystemSize;
    }
    #endif

    //**************************************************************************
    //**************************************************************************
    void ResizeAndInitializeVectors(
        TSystemMatrixPointerType& pA,
        TSystemVectorPointerType& pDx,
        TSystemVectorPointerType& pb,
        ElementsArrayType& rElements,
        ConditionsArrayType& rConditions,
        ProcessInfo& CurrentProcessInfo
    ) override
    {
        KRATOS_TRY
        if(pA == NULL) //if the pointer is not initialized initialize it to an empty matrix
        {
            TSystemMatrixPointerType pNewA = TSystemMatrixPointerType(new TSystemMatrixType(0,0) );
            pA.swap(pNewA);
        }
        if(pDx == NULL) //if the pointer is not initialized initialize it to an empty matrix
        {
            TSystemVectorPointerType pNewDx = TSystemVectorPointerType(new TSystemVectorType(0) );
            pDx.swap(pNewDx);
        }
        if(pb == NULL) //if the pointer is not initialized initialize it to an empty matrix
        {
            TSystemVectorPointerType pNewb = TSystemVectorPointerType(new TSystemVectorType(0) );
            pb.swap(pNewb);
        }
        if(BaseType::mpReactionsVector == NULL) //if the pointer is not initialized initialize it to an empty matrix
        {
            TSystemVectorPointerType pNewReactionsVector = TSystemVectorPointerType(new TSystemVectorType(0) );
            BaseType::mpReactionsVector.swap(pNewReactionsVector);
        }

        TSystemMatrixType& A  = *pA;
        TSystemVectorType& Dx = *pDx;
        TSystemVectorType& b  = *pb;

        //resizing the system vectors and matrix; also construct the structure of the stiffness matrix a priori for inserting element later on
        if (A.size1() == 0 || BaseType::GetReshapeMatrixFlag() == true) //if the matrix is not initialized
        {
            A.resize(BaseType::mEquationSystemSize,BaseType::mEquationSystemSize,false);
            ConstructMatrixStructure(A,rElements,rConditions,CurrentProcessInfo);
        }
        else
        {
            if(A.size1() != BaseType::mEquationSystemSize || A.size2() != BaseType::mEquationSystemSize)
            {
                KRATOS_WATCH("it should not come here!!!!!!!! ... this is SLOW");
                A.resize(BaseType::mEquationSystemSize,BaseType::mEquationSystemSize,true);
                ConstructMatrixStructure(A,rElements,rConditions,CurrentProcessInfo);
            }
        }
        if(Dx.size() != BaseType::mEquationSystemSize)
            Dx.resize(BaseType::mEquationSystemSize,false);
        if(b.size() != BaseType::mEquationSystemSize)
            b.resize(BaseType::mEquationSystemSize,false);

        //if needed resize the vector for the calculation of reactions
        if(BaseType::mCalculateReactionsFlag == true)
        {
            unsigned int ReactionsVectorSize = BaseType::mDofSet.size()-BaseType::mEquationSystemSize;
            if(BaseType::mpReactionsVector->size() != ReactionsVectorSize)
                BaseType::mpReactionsVector->resize(ReactionsVectorSize,false);
        }

        KRATOS_CATCH("")

    }

    //**************************************************************************
    //**************************************************************************
    void ResizeAndInitializeVectors(
        TSystemMatrixPointerType& pA,
        TSystemVectorPointerType& pDx,
        TSystemVectorPointerType& pb,
        ModelPart& rModelPart
    ) override
    {
        ResizeAndInitializeVectors(pA, pDx, pb, rModelPart.Elements(), rModelPart.Conditions(), rModelPart.GetProcessInfo());
    }

    //**************************************************************************
    //**************************************************************************
    void InitializeSolutionStep(
        ModelPart& r_model_part,
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
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
        ++mStepCounter;
        mLocalCounter = 0;
    }

    //**************************************************************************
    //**************************************************************************
    void CalculateReactions(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {
        //build RHS with reactions
        BuildRHSreactions(pScheme,r_model_part,b);

//        KRATOS_WATCH(*BaseType::mpReactionsVector)

        int i;
        int systemsize = BaseType::mDofSet.size() - TSparseSpace::Size(*BaseType::mpReactionsVector);

        typename DofsArrayType::ptr_iterator it2;

        //updating variables
        TSystemVectorType& ReactionsVector = *BaseType::mpReactionsVector;
        for (it2=BaseType::mDofSet.ptr_begin(); it2 != BaseType::mDofSet.ptr_end(); ++it2)
        {
            i = (*it2)->EquationId();

            if(i >= systemsize)
            {
                i -= systemsize;
                (*it2)->GetSolutionStepReactionValue() = ReactionsVector[i];
                // std::cout << "node " << (*it2)->Id() << " is assigned reaction value " << (*it2)->GetSolutionStepReactionValue() << std::endl;
            }
            else
            {
                (*it2)->GetSolutionStepReactionValue() = -b[i];
            }
        }
    }

    //**************************************************************************
    //**************************************************************************
    void ApplyDirichletConditions(
        typename TSchemeType::Pointer pScheme,
        ModelPart& r_model_part,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b) override
    {}

    /**
    this function is intended to be called at the end of the solution step to clean up memory
    storage not needed
    */
    void Clear() override
    {
        this->mDofSet = DofsArrayType();

        if(this->mpReactionsVector != NULL)
            TSparseSpace::Clear( (this->mpReactionsVector) );
//          this->mReactionsVector = TSystemVectorType();

        if (this->GetEchoLevel()>0)
        {
            KRATOS_WATCH("ResidualBasedEliminationBuilderAndSolverDeactivation Clear Function called");
        }
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
    std::string Info() const override
    {
        return "ResidualBasedEliminationBuilderAndSolverDeactivation";
    }

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << Info();
    }

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const override
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


    /*@} */
    /**@name Protected Operators*/
    /*@{ */
    //**************************************************************************
    virtual void ConstructMatrixStructure(
        TSystemMatrixType& A,
        ElementsContainerType& rElements,
        ConditionsArrayType& rConditions,
        ProcessInfo& CurrentProcessInfo)
    {
        std::cout << "Warning: ConstructMatrixStructure is called." << std::endl;
        double start_time = OpenMPUtils::GetCurrentTime();

        std::size_t equation_size = A.size1();
        Element::EquationIdVectorType ids;

        #ifdef ENABLE_SYSTEM_REORDERING
        //build the adjacency matrix of the stiffness matrix and reorder the global equation ids
//        RCMUtils reorderer;
//        std::vector<int>& PermutedSystemIds = reorderer.CalculateIndexPermutation(rElements, rConditions, CurrentProcessInfo, BaseType::mEquationSystemSize);
//        std::vector<int>& PermutedSystemIds = reorderer.CalculateIndexPermutation2(rElements, rConditions, CurrentProcessInfo, BaseType::mEquationSystemSize);
//        for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
//        {
//            int id = dof_iterator->EquationId();
//            if (id < BaseType::mEquationSystemSize)
//                dof_iterator->SetEquationId(PermutedSystemIds[id]);
//        }

        if(CurrentProcessInfo.Has(SYSTEM_PERMUTATION_VECTOR))
        {
            boost::numeric::ublas::vector<int> PermutedSystemIds = CurrentProcessInfo[SYSTEM_PERMUTATION_VECTOR];
            for (typename DofsArrayType::iterator dof_iterator = BaseType::mDofSet.begin(); dof_iterator != BaseType::mDofSet.end(); ++dof_iterator)
            {
                int id = dof_iterator->EquationId();
                if (id < BaseType::mEquationSystemSize)
                    dof_iterator->SetEquationId(PermutedSystemIds[id]);
            }
        }
        else
            std::cout << "SYSTEM_PERMUTATION_VECTOR is not set for ProcessInfo. The system reordering will not be performed" << std::endl;
        #endif

        std::vector<std::vector<std::size_t> > indices(equation_size);
        for(typename ElementsContainerType::iterator i_element = rElements.begin(); i_element != rElements.end(); ++i_element)
        {
            (i_element)->EquationIdVector(ids, CurrentProcessInfo);
            for(std::size_t i = 0; i < ids.size(); ++i)
            {
                if(ids[i] < equation_size)
                {
                    std::vector<std::size_t>& row_indices = indices[ids[i]];
                    for(std::size_t j = 0; j < ids.size(); ++j)
                    {
                        if(ids[j] < equation_size)
                            AddUnique(row_indices,ids[j]);
                    }
                }
            }
        }

        for(typename ConditionsArrayType::iterator i_condition = rConditions.begin(); i_condition != rConditions.end(); ++i_condition)
        {
            (i_condition)->EquationIdVector(ids, CurrentProcessInfo);
            for(std::size_t i = 0; i < ids.size(); ++i)
            {
                if(ids[i] < equation_size)
                {
                    std::vector<std::size_t>& row_indices = indices[ids[i]];
                    for(std::size_t j = 0; j < ids.size(); ++j)
                    {
                        if(ids[j] < equation_size)
                            AddUnique(row_indices,ids[j]);
                    }
                }
            }
        }

        //allocating the memory needed
        std::size_t data_size = 0;
        for(std::size_t i = 0; i < indices.size(); ++i)
            data_size += indices[i].size();
        A.reserve(data_size, false);

        //filling with zero the matrix (creating the structure)
        Timer::Start("MatrixStructure");
#ifndef _OPENMP
        for(std::size_t i = 0; i < indices.size(); ++i)
        {
            std::vector<std::size_t>& row_indices = indices[i];
            std::sort(row_indices.begin(), row_indices.end());

            for(std::vector<std::size_t>::iterator it = row_indices.begin(); it != row_indices.end(); ++it)
                A.push_back(i,*it,0.00);
            row_indices.clear();
        }
#else
        int number_of_threads = omp_get_max_threads();
        boost::numeric::ublas::vector<unsigned int> matrix_partition;
        OpenMPUtils::CreatePartition(number_of_threads, indices.size(), matrix_partition);
        KRATOS_WATCH( matrix_partition );
        for(int k = 0; k < number_of_threads; ++k)
        {
            #pragma omp parallel
            if(omp_get_thread_num() == k)
            {
                for(std::size_t i = matrix_partition[k]; i < matrix_partition[k+1]; ++i)
                {
                    std::vector<std::size_t>& row_indices = indices[i];
                    std::sort(row_indices.begin(), row_indices.end());

                    for(std::vector<std::size_t>::iterator it = row_indices.begin(); it != row_indices.end(); ++it)
                        A.push_back(i, *it, 0.00);
                    row_indices.clear();
                }
            }
        }
#endif
        Timer::Stop("MatrixStructure");

        double end_time = OpenMPUtils::GetCurrentTime();
        std::cout << "ConstructMatrixStructure completed: " << end_time - start_time << " s" << std::endl;
    }

    //**************************************************************************
    void AssembleLHS(
        TSystemMatrixType& A,
        LocalSystemMatrixType& LHS_Contribution,
        Element::EquationIdVectorType& EquationId
    )
    {
        unsigned int local_size = LHS_Contribution.size1();

        for (unsigned int i_local = 0; i_local < local_size; ++i_local)
        {
            unsigned int i_global = EquationId[i_local];
            if ( i_global < BaseType::mEquationSystemSize )
            {
                for (unsigned int j_local = 0; j_local<local_size; ++j_local)
                {
                    unsigned int j_global = EquationId[j_local];
                    if ( j_global < BaseType::mEquationSystemSize )
                        A(i_global,j_global) += LHS_Contribution(i_local,j_local);
                }
            }
        }
    }



    //**************************************************************************
    void AssembleRHS(
        TSystemVectorType& b,
        LocalSystemVectorType& RHS_Contribution,
        Element::EquationIdVectorType& EquationId
    )
    {
        unsigned int local_size = RHS_Contribution.size();

        if (BaseType::mCalculateReactionsFlag == false) //if we don't need to calculate reactions
        {
            for (unsigned int i_local = 0; i_local < local_size; ++i_local)
            {
                unsigned int i_global = EquationId[i_local];
                if ( i_global < BaseType::mEquationSystemSize ) //on "free" DOFs
                {
                    // ASSEMBLING THE SYSTEM VECTOR
                    b[i_global] += RHS_Contribution[i_local];
                }
            }
        }
        else //when the calculation of reactions is needed
        {
            TSystemVectorType& ReactionsVector = *BaseType::mpReactionsVector;
            for (unsigned int i_local = 0; i_local < local_size; ++i_local)
            {
                unsigned int i_global = EquationId[i_local];
                if ( i_global < BaseType::mEquationSystemSize ) //on "free" DOFs
                {
                    // ASSEMBLING THE SYSTEM VECTOR
                    b[i_global] += RHS_Contribution[i_local];
                }
                else //on "fixed" DOFs
                {
                    // Assembling the Vector of REACTIONS
                    ReactionsVector[i_global - BaseType::mEquationSystemSize] -= RHS_Contribution[i_local];
                }
            }
        }
    }


    //**************************************************************************
    void AssembleRHSreactions(
        TSystemVectorType& b,
        LocalSystemVectorType& RHS_Contribution,
        Element::EquationIdVectorType& EquationId
    )
    {
        unsigned int local_size = RHS_Contribution.size();

        if (BaseType::mCalculateReactionsFlag == false) //if we don't need to calculate reactions
        {
            for (unsigned int i_local = 0; i_local < local_size; ++i_local)
            {
                unsigned int i_global = EquationId[i_local];
                if ( i_global < BaseType::mEquationSystemSize ) //on "free" DOFs
                {
                    // ASSEMBLING THE SYSTEM VECTOR
                    #pragma omp atomic update
                    // {
                        b[i_global] += RHS_Contribution[i_local];
                    // }
                }
            }
        }
        else //when the calculation of reactions is needed
        {
            TSystemVectorType& ReactionsVector = *BaseType::mpReactionsVector;
            for (unsigned int i_local = 0; i_local < local_size; ++i_local)
            {
                unsigned int i_global = EquationId[i_local];
                if ( i_global < BaseType::mEquationSystemSize ) //on "free" DOFs
                {
                    // ASSEMBLING THE SYSTEM VECTOR
                    #pragma omp atomic update
                    // {
                        b[i_global] += RHS_Contribution[i_local];
                    // }
                }
                else //on "fixed" DOFs
                {
                    // Assembling the Vector of REACTIONS
                    #pragma omp atomic update
                    // {
                        ReactionsVector[i_global-BaseType::mEquationSystemSize] -= RHS_Contribution[i_local];
                    // }
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

    unsigned int mLocalCounter;
    unsigned int mStepCounter;
    unsigned int mFixedLength;

    DofsArrayType mAllDofs; // carry all possible dofs in the mesh

    #ifdef ENABLE_LOG
    boost::log::sources::severity_logger<boost::log::trivial::severity_level> m_log_level;
    #endif

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
        Element::EquationIdVectorType& EquationId
    )
    {
        unsigned int local_size = LHS_Contribution.size1();
        for (unsigned int i_local = 0; i_local < local_size; ++i_local)
        {
            unsigned int i_global = EquationId[i_local];
            if ( i_global < BaseType::mEquationSystemSize )
            {
                for (unsigned int j_local = 0; j_local < local_size; ++j_local)
                {
                    int j_global = EquationId[j_local];

                    A(i_global, j_global) += LHS_Contribution(i_local, j_local);
                }
            }
        }
    }

    //******************************************************************************************
    //******************************************************************************************
    inline void AddUnique(std::vector<std::size_t>& v, const std::size_t& candidate)
    {
        std::vector<std::size_t>::iterator i = v.begin();
        std::vector<std::size_t>::iterator endit = v.end();
        while ( i != endit && (*i) != candidate)
            ++i;
        if( i == endit )
            v.push_back(candidate);
    }

#ifdef _OPENMP
    void Assemble(
        TSystemMatrixType& A,
        TSystemVectorType& b,
        const LocalSystemMatrixType& LHS_Contribution,
        const LocalSystemVectorType& RHS_Contribution,
        Element::EquationIdVectorType& EquationId,
        std::vector< omp_lock_t >& lock_array
    )
    {
        unsigned int local_size = LHS_Contribution.size1();

        for (unsigned int i_local = 0; i_local < local_size; ++i_local)
        {
            unsigned int i_global = EquationId[i_local];

            if ( i_global < BaseType::mEquationSystemSize )
            {
                omp_set_lock(&lock_array[i_global]);

                b[i_global] += RHS_Contribution(i_local);
                for (unsigned int j_local = 0; j_local < local_size; ++j_local)
                {
                    unsigned int j_global = EquationId[j_local];
                    if ( j_global < BaseType::mEquationSystemSize )
                    {
                        A(i_global, j_global) += LHS_Contribution(i_local, j_local);
                    }
                }

                omp_unset_lock(&lock_array[i_global]);
            }
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

}; /* Class ResidualBasedEliminationBuilderAndSolverDeactivation */

/*@} */

/**@name Type Definitions */
/*@{ */


/*@} */

}  /* namespace Kratos.*/

#undef BUILDER_AND_SOLVER_DEBUG_LEVEL1
#undef BUILDER_AND_SOLVER_DEBUG_LEVEL2
#undef BUILDER_AND_SOLVER_DEBUG_LEVEL3
#undef EXPORT_LHS_MATRIX
#undef EXPORT_RHS_VECTOR
#undef EXPORT_SOL_VECTOR
#undef EXPORT_LHS_MATRIX_SAMPLING
#undef EXPORT_RHS_VECTOR_SAMPLING
#undef ACCOUNT_DOFS_FOR_CONDITION
#undef DOF_ENUMERATION_STRAIGHT
#undef DOF_ENUMERATION_REVERSE
#undef ENABLE_DEACTIVATION_SETUP_DOFSET
#undef ENABLE_SYSTEM_REORDERING
#undef QUERY_RESIDUAL_NORM
#undef QUERY_DOFSET
#undef QUERY_DOF_EQUATION_ID
#undef QUERY_EQUATION_ID_AT_BUILD
#undef MODIFY_INACTIVE_PART_OF_THE_MATRIX
#undef INCLUDE_INACTIVE_ELEMENTS_IN_SETUP_DOFSET
#undef ENABLE_FILTER_SMALL_ENTRIES
#undef MODIFY_NEGATIVE_DIAGONAL
#undef MONITOR_MATRIX_ELEMENT_16_15
#undef MONITOR_EQUATIONID_20040
#undef ENABLE_LOG
#undef ENABLE_LOG_TIMESTAMP
#undef ENABLE_LOG_PROCESS_AND_THREAD_ID
#undef MEASURE_TIME_CUT_CELL

#endif /* KRATOS_RESIDUAL_BASED_ELIMINATION_BUILDER_AND_SOLVER_DEACTIVATION  defined */
