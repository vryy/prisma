/* *********************************************************
*
*   Last Modified by:    $Author:  $
*   Date:                $Date: 2009-09-18 $
*   Revision:            $Revision: 1.0 $
*
* ***********************************************************/



#if !defined(EXPLICIT_STRATEGY)
#define  EXPLICIT_STRATEGY


/* System includes */
#include <string>
#include <iostream>
#include <algorithm>

/////////#define _OPENMP

/* External includes */
#ifdef _OPENMP
#include <omp.h>
#endif

#include "boost/smart_ptr.hpp"


/* Project includes */
#include "includes/define.h"
#include "includes/model_part.h"
#include "includes/element.h"
#include "solving_strategies/strategies/solving_strategy.h"
#include "solving_strategies/schemes/scheme.h"
#include "includes/variables.h"
#include "containers/array_1d.h"


namespace Kratos
{

template<
    class TSparseSpace,
    class TDenseSpace,
    class TLinearSolver,
    class TModelPartTypeType>
class ExplicitStrategy : public SolvingStrategy<TSparseSpace, TDenseSpace, TLinearSolver, TModelPartTypeType>
{
public:

    KRATOS_CLASS_POINTER_DEFINITION(ExplicitStrategy);

    typedef SolvingStrategy<TSparseSpace, TDenseSpace, TLinearSolver, TModelPartTypeType> BaseType;

    typedef typename BaseType::TDataType TDataType;

    typedef TSparseSpace SparseSpaceType;

    typedef typename BaseType::ModelPartType ModelPartType;

    typedef typename BaseType::TSchemeType TSchemeType;

    typedef typename BaseType::DofsArrayType DofsArrayType;

    typedef typename BaseType::TSystemMatrixType TSystemMatrixType;

    typedef typename BaseType::TSystemVectorType TSystemVectorType;

    typedef typename BaseType::LocalSystemVectorType LocalSystemVectorType;

    typedef typename BaseType::LocalSystemMatrixType LocalSystemMatrixType;

    typedef typename BaseType::TSystemMatrixPointerType TSystemMatrixPointerType;
    typedef typename BaseType::TSystemVectorPointerType TSystemVectorPointerType;

    ExplicitStrategy(
        ModelPartType&   model_part,
        const int        dimension,
        const bool       move_mesh_flag
        )
    : BaseType(model_part, move_mesh_flag)
    {
        std::cout<< "*************************************"<< std::endl;
        std::cout <<"*   EXPLICIT CALCULATIONS STRATEGY  *"<< std::endl;
        std::cout<< "*************************************"<< std::endl;
    }

    ~ExplicitStrategy () override {}

    //***************************************************************************
    //***************************************************************************

    void AssembleLoop()
    {
        KRATOS_TRY

        ModelPartType& r_model_part = BaseType::GetModelPart();
        const ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
        auto& pElements = r_model_part.Elements();

        auto it_begin = pElements.begin() ;
        auto it_end   = pElements.end();
        for (auto it = it_begin; it != it_end; ++it)
        {
            it->AddExplicitContribution(CurrentProcessInfo);
        }

        KRATOS_CATCH("")
    }

    //***************************************************************************
    //***************************************************************************

    void NormalizeVariable(const Variable<array_1d<TDataType, 3 > >& rRHSVariable, const Variable<TDataType >& rNormalizationVariable)
    {
        KRATOS_TRY

        ModelPartType& r_model_part = BaseType::GetModelPart();
        auto& pNodes = r_model_part.Nodes();

        #ifdef _OPENMP
        int number_of_threads = omp_get_max_threads();
        #else
        int number_of_threads = 1;
        #endif

        vector<unsigned int> node_partition;
        CreatePartition(number_of_threads, pNodes.size(), node_partition);

        #pragma omp parallel for
        for(int k=0; k<number_of_threads; k++)
        {
            auto i_begin = pNodes.begin()+node_partition[k];
            auto i_end = pNodes.begin()+node_partition[k+1];

            for(auto i=i_begin; i!= i_end; ++i)
            {
               auto& node_rhs_variable = (i)->FastGetSolutionStepValue(rRHSVariable);
               auto& normalization_variable = (i)->FastGetSolutionStepValue(rNormalizationVariable);

               node_rhs_variable /= normalization_variable;
            }
        }

        KRATOS_CATCH("")
    }

    void ExplicitUpdateLoop(const Variable<array_1d<TDataType, 3 > >& rUpdateVariable, const Variable<array_1d<TDataType, 3 > >& rRHSVariable, const TDataType& factor)
    {
        KRATOS_TRY

        ModelPartType& r_model_part = BaseType::GetModelPart();
        auto& pNodes = r_model_part.Nodes();

        #ifdef _OPENMP
        int number_of_threads = omp_get_max_threads();
        #else
        int number_of_threads = 1;
        #endif

        vector<unsigned int> node_partition;
        CreatePartition(number_of_threads, pNodes.size(), node_partition);

        #pragma omp parallel for
        for(int k=0; k<number_of_threads; k++)
        {
            auto i_begin = pNodes.begin()+node_partition[k];
            auto i_end = pNodes.begin()+node_partition[k+1];

            for(auto i=i_begin; i!= i_end; ++i)
            {
               auto& node_update_variable = (i)->FastGetSolutionStepValue(rUpdateVariable);
               auto& node_rhs_variable = (i)->FastGetSolutionStepValue(rRHSVariable);
               noalias(node_update_variable) += factor* node_rhs_variable  ;
            }
        }

        KRATOS_CATCH("")
    }

    inline void CreatePartition(unsigned int number_of_threads, const int number_of_rows, vector<unsigned int>& partitions) const
    {
        partitions.resize(number_of_threads+1);
        int partition_size = number_of_rows / number_of_threads;
        partitions[0] = 0;
        partitions[number_of_threads] = number_of_rows;
        for(unsigned int i = 1; i<number_of_threads; i++)
        partitions[i] = partitions[i-1] + partition_size ;
    }

    //********************************************
    //********************************************
    void InitializeSolutionStep() override
    {
        KRATOS_TRY

        ModelPartType& r_model_part = BaseType::GetModelPart();
        const ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
        auto& pElements = r_model_part.Elements();

        auto it_begin = pElements.begin() ;
        auto it_end   = pElements.end();
        for (auto it = it_begin; it != it_end; ++it)
        {
            it->InitializeSolutionStep(CurrentProcessInfo);
        }

        KRATOS_CATCH("")
    }

    void FinalizeSolutionStep() override
    {
        KRATOS_TRY

        ModelPartType& r_model_part = BaseType::GetModelPart();
        const ProcessInfo& CurrentProcessInfo = r_model_part.GetProcessInfo();
        auto& pElements = r_model_part.Elements();

        auto it_begin = pElements.begin() ;
        auto it_end   = pElements.end();
        for (auto it = it_begin; it != it_end; ++it)
        {
            it->FinalizeSolutionStep(CurrentProcessInfo);
        }

        KRATOS_CATCH("")
    }

};

} /* namespace Kratos.*/

#endif /* EXPLICT_STRATEGY */
