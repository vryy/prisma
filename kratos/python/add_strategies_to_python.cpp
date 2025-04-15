// Kratos Multi-Physics
//
// Copyright (c) 2016 Pooyan Dadvand, Riccardo Rossi, CIMNE (International Center for Numerical Methods in Engineering)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
//  -   Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//  -   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
//      in the documentation and/or other materials provided with the distribution.
//  -   All advertising materials mentioning features or use of this software must display the following acknowledgement:
//          This product includes Kratos Multi-Physics technology.
//  -   Neither the name of the CIMNE nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED ANDON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THISSOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



// System includes


// External includes
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>


// Project includes
#include "includes/define.h"
#include "python/add_strategies_to_python.h"
#include "includes/model_part.h"
#include "spaces/ublas_space.h"

//strategies
#include "solving_strategies/strategies/solving_strategy.h"
#include "solving_strategies/strategies/residualbased_linear_strategy.h"
#include "solving_strategies/strategies/residualbased_newton_raphson_strategy.h"
#include "solving_strategies/strategies/adaptive_residualbased_newton_raphson_strategy.h"
#include "solving_strategies/strategies/explicit_strategy.h"
//#include "solving_strategies/strategies/residualbased_arc_lenght_strategy.h"

//schemes
#include "solving_strategies/schemes/scheme.h"
#include "solving_strategies/schemes/residualbased_incrementalupdate_static_scheme.h"
#include "solving_strategies/schemes/residualbased_incrementalupdate_static_scheme_slip.h"

//convergence criterias
#include "solving_strategies/convergencecriterias/convergence_criteria.h"
#include "solving_strategies/convergencecriterias/displacement_criteria.h"
#include "solving_strategies/convergencecriterias/incremental_displacement_criteria.h"
#include "solving_strategies/convergencecriterias/residual_criteria.h"
#include "solving_strategies/convergencecriterias/and_criteria.h"
#include "solving_strategies/convergencecriterias/or_criteria.h"
//#include "solving_strategies/convergencecriterias/and_criteria.h"

//Builder And Solver
#include "solving_strategies/builder_and_solvers/builder_and_solver.h"
#include "solving_strategies/builder_and_solvers/residualbased_elimination_builder_and_solver_deactivation.h"
#include "solving_strategies/builder_and_solvers/residualbased_block_builder_and_solver.h"
#include "solving_strategies/builder_and_solvers/residualbased_block_builder_and_solver_with_constraints.h"
#include "solving_strategies/builder_and_solvers/residualbased_block_builder_and_solver_with_constraints_elementwise.h"
#include "solving_strategies/builder_and_solvers/residualbased_block_builder_and_solver_with_constraints_deactivation.h"
#include "solving_strategies/builder_and_solvers/residualbased_block_builder_and_solver_with_constraints_deactivation_elementwise.h"


//linear solvers
#include "linear_solvers/linear_solver.h"

//utilities
#include "python/pointer_vector_set_python_interface.h"


namespace Kratos
{

    namespace Python
    {
        using namespace boost::python;

        template<typename TSchemeType>
        void MoveMesh(TSchemeType& dummy, typename TSchemeType::ModelPartType::NodesContainerType& rNodes)
        {
            for (typename TSchemeType::ModelPartType::NodeIterator i = rNodes.begin(); i != rNodes.end(); ++i)
            {
                const auto& disp = i->FastGetSolutionStepValue(DISPLACEMENT);
                (i)->X() = (i)->X0() + disp[0];
                (i)->Y() = (i)->Y0() + disp[1];
                (i)->Z() = (i)->Z0() + disp[2];
            }
        }

        template<typename TSparseSpaceType, typename TLocalSpaceType, typename TModelPartType>
        void AddStrategiesToPythonImpl(const std::string& Prefix)
        {
            typedef TSparseSpaceType SparseSpaceType;
            typedef TLocalSpaceType LocalSpaceType;

            if constexpr(!std::is_same<typename SparseSpaceType::DataType, typename LocalSpaceType::DataType>::value)
                KRATOS_ERROR << "The data type of sparse space and local space is incompatible";

            typedef typename LocalSpaceType::DataType DataType;

            typedef LinearSolver< SparseSpaceType, LocalSpaceType > LinearSolverType;
            typedef SolvingStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType > BaseSolvingStrategyType;
            typedef Scheme< SparseSpaceType, LocalSpaceType, TModelPartType > BaseSchemeType;

            //********************************************************************
            //********************************************************************
            //strategy base class
            class_<BaseSolvingStrategyType, boost::noncopyable>((Prefix+"SolvingStrategy").c_str(), init<TModelPartType&, bool>())
                    .def("Predict", &BaseSolvingStrategyType::Predict)
                    .def("Initialize", &BaseSolvingStrategyType::Initialize)
                    .def("Solve", &BaseSolvingStrategyType::Solve)
                    .def("IsConverged", &BaseSolvingStrategyType::IsConverged)
                    .def("CalculateOutputData", &BaseSolvingStrategyType::CalculateOutputData)
                    .def("SetEchoLevel", &BaseSolvingStrategyType::SetEchoLevel)
                    .def("GetEchoLevel", &BaseSolvingStrategyType::GetEchoLevel)
                    .def("SetRebuildLevel", &BaseSolvingStrategyType::SetRebuildLevel)
                    .def("GetRebuildLevel", &BaseSolvingStrategyType::GetRebuildLevel)
                    .def("SetMoveMeshFlag", &BaseSolvingStrategyType::SetMoveMeshFlag)
                    .def("MoveMeshFlag", &BaseSolvingStrategyType::MoveMeshFlag)
                    .def("MoveMesh", &BaseSolvingStrategyType::MoveMesh)
                    .def("Clear", &BaseSolvingStrategyType::Clear)
                    .def("Check", &BaseSolvingStrategyType::Check)
                    .def("InitializeSolutionStep", &BaseSolvingStrategyType::InitializeSolutionStep)
                    .def("FinalizeSolutionStep", &BaseSolvingStrategyType::FinalizeSolutionStep)
                    .def("SolveSolutionStep", &BaseSolvingStrategyType::SolveSolutionStep)
                    //.def("GetModelPart", &BaseSolvingStrategyType::GetModelPart )
                    ;

            typedef ConvergenceCriteria<SparseSpaceType, LocalSpaceType> TConvergenceCriteriaType;
            typedef BuilderAndSolver<SparseSpaceType, LocalSpaceType, LinearSolverType> BuilderAndSolverType;

            class_< ResidualBasedLinearStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >, bases< BaseSolvingStrategyType >, boost::noncopyable >
                    ((Prefix+"ResidualBasedLinearStrategy").c_str(),init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, bool, bool, bool, bool >())
                    .def(init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename BuilderAndSolverType::Pointer, bool, bool, bool,  bool  >())
                    .def("GetResidualNorm", &ResidualBasedLinearStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::GetResidualNorm)
                    .def("SetBuilderAndSolver", &ResidualBasedLinearStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::SetBuilderAndSolver)
                    ;


            class_< ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >, bases< BaseSolvingStrategyType >, boost::noncopyable >
                    ((Prefix+"ResidualBasedNewtonRaphsonStrategy").c_str(), init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename TConvergenceCriteriaType::Pointer, int, bool, bool, bool >())
                    .def(init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename TConvergenceCriteriaType::Pointer, typename BuilderAndSolverType::Pointer, int, bool, bool, bool >())
                    .def("SetMaxIterationNumber", &ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::SetMaxIterationNumber)
                    .def("GetMaxIterationNumber", &ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::GetMaxIterationNumber)
                    .def("SetKeepSystemConstantDuringIterations", &ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::SetKeepSystemConstantDuringIterations)
                    .def("GetKeepSystemConstantDuringIterations", &ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::GetKeepSystemConstantDuringIterations)
                    ;

            class_< AdaptiveResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >, bases< BaseSolvingStrategyType >, boost::noncopyable >
                    ((Prefix+"AdaptiveResidualBasedNewtonRaphsonStrategy").c_str(),
                    init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename TConvergenceCriteriaType::Pointer, int, int, bool, bool, bool, DataType, DataType, int
                    >())
                    ;

            class_< ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >,
                    bases< BaseSolvingStrategyType >,  boost::noncopyable >
                    ((Prefix+"Explicit_Strategy").c_str(),
                    init<TModelPartType&, int, bool >() )
                    //AssembleLoop loops the elements calling AddExplicitContribution. Using processinfo the element is the one who "decides" which variable to modify.
                    .def("AssembleLoop", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::AssembleLoop)
                    //once the assembleloop has been performed, the variable must be normalized. (for example with the nodal mass or the nodal area). Loop on nodes.
                    .def("NormalizeVariable", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::NormalizeVariable)
                    //ExplicitUpdateLoop modifies a vectorial variable by adding another variable (the RHS, PRESS_PROJ,etc) multiplied by a user-given factor (ie delta_time)
                    .def("ExplicitUpdateLoop", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::ExplicitUpdateLoop)
                    //initialize and finalize.
                    .def("InitializeSolutionStep", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::InitializeSolutionStep)
                    .def("FinalizeSolutionStep", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::FinalizeSolutionStep)
                    ;

            //********************************************************************
            //********************************************************************
            class_< BaseSchemeType, boost::noncopyable >
                    ((Prefix+"Scheme").c_str(), init<>())
                    .def("Initialize", &BaseSchemeType::Initialize)
                    .def("SchemeIsInitialized", &BaseSchemeType::SchemeIsInitialized)
                    .def("ElementsAreInitialized", &BaseSchemeType::ElementsAreInitialized)
                    .def("ConditionsAreInitialized", &BaseSchemeType::ConditionsAreInitialized)
                    .def("InitializeElements", &BaseSchemeType::InitializeElements)
                    .def("InitializeConditions", &BaseSchemeType::InitializeConditions)
                    .def("InitializeSolutionStep", &BaseSchemeType::InitializeSolutionStep)
                    .def("FinalizeSolutionStep", &BaseSchemeType::FinalizeSolutionStep)
                    .def("InitializeNonLinIteration", &BaseSchemeType::InitializeNonLinIteration)
                    .def("FinalizeNonLinIteration", &BaseSchemeType::FinalizeNonLinIteration)
                    .def("Predict", &BaseSchemeType::Predict)
                    .def("Update", &BaseSchemeType::Update)
                    .def("CalculateOutputData", &BaseSchemeType::CalculateOutputData)
                    .def("Clean", &BaseSchemeType::Clean)
                    .def("Clear",&BaseSchemeType::Clear)
                    .def("MoveMesh", MoveMesh<BaseSchemeType>)
                    .def("Check", &BaseSchemeType::Check)
                    ;

            class_< ResidualBasedIncrementalUpdateStaticScheme< SparseSpaceType, LocalSpaceType>,
                    bases< BaseSchemeType >, boost::noncopyable >
                    ((Prefix+"ResidualBasedIncrementalUpdateStaticScheme").c_str(), init<>());

            class_< ResidualBasedIncrementalUpdateStaticSchemeSlip< SparseSpaceType, LocalSpaceType>,
                    bases< ResidualBasedIncrementalUpdateStaticScheme< SparseSpaceType, LocalSpaceType> >,
                    boost::noncopyable >
                    ((Prefix+"ResidualBasedIncrementalUpdateStaticSchemeSlip").c_str(), init<unsigned int, unsigned int>());


            //********************************************************************
            //********************************************************************
            //convergence criteria base class
            class_< ConvergenceCriteria< SparseSpaceType, LocalSpaceType >, boost::noncopyable > ((Prefix+"ConvergenceCriteria").c_str(), init<>())
                    .def("SetActualizeRHSFlag", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::SetActualizeRHSFlag)
                    .def("GetActualizeRHSflag", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::GetActualizeRHSflag)
                    .def("PreCriteria", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::PreCriteria)
                    .def("PostCriteria", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::PostCriteria)
                    .def("Initialize", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::Initialize)
                    .def("InitializeNonLinearIteration", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::InitializeNonLinearIteration)
                    .def("InitializeSolutionStep", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::InitializeSolutionStep)
                    .def("FinalizeNonLinearIteration", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::FinalizeNonLinearIteration)
                    .def("FinalizeSolutionStep", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::FinalizeSolutionStep)
                    .def("Check", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::Check)
                    ;

            class_< DisplacementCriteria<SparseSpaceType, LocalSpaceType >,
                    bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
                    boost::noncopyable >
                    ((Prefix+"DisplacementCriteria").c_str(), init< DataType, DataType>())
                    .def("SetEchoLevel", &DisplacementCriteria<SparseSpaceType, LocalSpaceType >::SetEchoLevel);

            class_< IncrementalDisplacementCriteria<SparseSpaceType, LocalSpaceType >,
                    bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
                    boost::noncopyable >
                    ((Prefix+"IncrementalDisplacementCriteria").c_str(), init< DataType, DataType>());

            class_<ResidualCriteria<SparseSpaceType, LocalSpaceType >,
                    bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
                    boost::noncopyable >
                    ((Prefix+"ResidualCriteria").c_str(), init< DataType, DataType>());

            /*          class_< ResidualCriteria< SparseSpaceType >,
                                             bases<ConvergenceCriteria< SparseSpaceType > >,
                                             boost::noncopyable >
                                            ("ResidualCriteria", init<Model::Pointer, DataType >() );

                                    class_< AndCriteria< SparseSpaceType >,
                                             bases<ConvergenceCriteria< SparseSpaceType > >,
                                             boost::noncopyable >
                                            ("AndCriteria", init<Model::Pointer, ConvergenceCriteria< SparseSpaceType >::Pointer, ConvergenceCriteria< SparseSpaceType >::Pointer >()*/
            //);


            class_<And_Criteria<SparseSpaceType, LocalSpaceType >,
                    bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
                    boost::noncopyable >
                    ((Prefix+"AndCriteria").c_str(), init<typename TConvergenceCriteriaType::Pointer, typename TConvergenceCriteriaType::Pointer> ());

            class_<Or_Criteria<SparseSpaceType, LocalSpaceType >,
                    bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
                    boost::noncopyable >
                    ((Prefix+"OrCriteria").c_str(), init<typename TConvergenceCriteriaType::Pointer, typename TConvergenceCriteriaType::Pointer> ());

            //********************************************************************
            //********************************************************************
            //

            //Builder and Solver
            typename BuilderAndSolverType::DofsArrayType&(BuilderAndSolverType::*BuilderAndSolver_GetDofSet)() = &BuilderAndSolverType::GetDofSet;

            class_< BuilderAndSolverType, boost::noncopyable > ((Prefix+"BuilderAndSolver").c_str(), init<typename LinearSolverType::Pointer > ())
                    .def("SetCalculateReactionsFlag", &BuilderAndSolverType::SetCalculateReactionsFlag)
                    .def("GetCalculateReactionsFlag", &BuilderAndSolverType::GetCalculateReactionsFlag)
                    .def("SetDofSetIsInitializedFlag", &BuilderAndSolverType::SetDofSetIsInitializedFlag)
                    .def("GetDofSetIsInitializedFlag", &BuilderAndSolverType::GetDofSetIsInitializedFlag)
                    .def("SetReshapeMatrixFlag", &BuilderAndSolverType::SetReshapeMatrixFlag)
                    .def("GetReshapeMatrixFlag", &BuilderAndSolverType::GetReshapeMatrixFlag)
                    .def("GetEquationSystemSize", &BuilderAndSolverType::GetEquationSystemSize)
                    .def("BuildLHS", &BuilderAndSolverType::BuildLHS)
                    .def("BuildRHS", &BuilderAndSolverType::BuildRHS)
                    .def("Build", &BuilderAndSolverType::Build)
                    .def("SystemSolve", &BuilderAndSolverType::SystemSolve)
                    .def("BuildAndSolve", &BuilderAndSolverType::BuildAndSolve)
                    .def("BuildRHSAndSolve", &BuilderAndSolverType::BuildRHSAndSolve)
                    .def("ApplyDirichletConditions", &BuilderAndSolverType::ApplyDirichletConditions)
                    .def("SetUpDofSet", &BuilderAndSolverType::SetUpDofSet)
                    .def("GetDofSet", BuilderAndSolver_GetDofSet, return_internal_reference<>())
                    .def("SetUpSystem", &BuilderAndSolverType::SetUpSystem)
                    .def("ResizeAndInitializeVectors", &BuilderAndSolver_ResizeAndInitializeVectors1<BuilderAndSolverType>)
                    .def("ResizeAndInitializeVectors", &BuilderAndSolver_ResizeAndInitializeVectors2<BuilderAndSolverType>)
                    .def("InitializeSolutionStep", &BuilderAndSolverType::InitializeSolutionStep)
                    .def("FinalizeSolutionStep", &BuilderAndSolverType::FinalizeSolutionStep)
                    .def("CalculateReactions", &BuilderAndSolverType::CalculateReactions)
                    .def("Clear", &BuilderAndSolverType::Clear)
                    .def("Check", &BuilderAndSolverType::Check)
                    .def("SetEchoLevel", &BuilderAndSolverType::SetEchoLevel)
                    .def("GetEchoLevel", &BuilderAndSolverType::GetEchoLevel)
                    ;

            typedef ResidualBasedEliminationBuilderAndSolver< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedEliminationBuilderAndSolverType;
            class_< ResidualBasedEliminationBuilderAndSolverType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedEliminationBuilderAndSolver").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolver< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverType;
            class_< ResidualBasedBlockBuilderAndSolverType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolver").c_str(), init< typename LinearSolverType::Pointer > ());


            typedef ResidualBasedEliminationBuilderAndSolverDeactivation< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedEliminationBuilderAndSolverDeactivationType;
            class_< ResidualBasedEliminationBuilderAndSolverDeactivationType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedEliminationBuilderAndSolverDeactivation").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolverWithConstraints< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverWithConstraintsType;
            class_< ResidualBasedBlockBuilderAndSolverWithConstraintsType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraints").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolverWithConstraintsElementWise< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverWithConstraintsElementWiseType;
            class_< ResidualBasedBlockBuilderAndSolverWithConstraintsElementWiseType, bases<ResidualBasedBlockBuilderAndSolverWithConstraintsType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsElementWise").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivation< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationType;
            class_< ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivation").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWise< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWiseType;
            class_< ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWiseType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWise").c_str(), init< typename LinearSolverType::Pointer > ());
        }

        // template<typename TSparseSpaceType, typename TLocalSpaceType>
        // void AddComplexStrategiesToPythonImpl(const std::string& Prefix)
        // {
        //     typedef TSparseSpaceType SparseSpaceType;
        //     typedef TLocalSpaceType LocalSpaceType;

        //     if constexpr(!std::is_same<typename SparseSpaceType::DataType, typename LocalSpaceType::DataType>::value)
        //         KRATOS_ERROR << "The data type of sparse space and local space is incompatible";

        //     typedef typename LocalSpaceType::DataType DataType;
        //     typedef Dof<DataType> DofType;
        //     typedef PointerVectorSet<DofType, SetIdentityFunction<DofType> > DofsArrayType;

        //     typedef LinearSolver< SparseSpaceType, LocalSpaceType > LinearSolverType;
        //     typedef SolvingStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType > BaseSolvingStrategyType;
        //     typedef Scheme< SparseSpaceType, LocalSpaceType, DofType, DofsArrayType > BaseSchemeType;

        //     //********************************************************************
        //     //********************************************************************
        //     //strategy base class
        //     class_<BaseSolvingStrategyType, boost::noncopyable>((Prefix+"SolvingStrategy").c_str(), init<TModelPartType&, bool>())
        //             .def("Predict", &BaseSolvingStrategyType::Predict)
        //             .def("Initialize", &BaseSolvingStrategyType::Initialize)
        //             .def("Solve", &BaseSolvingStrategyType::Solve)
        //             .def("IsConverged", &BaseSolvingStrategyType::IsConverged)
        //             .def("CalculateOutputData", &BaseSolvingStrategyType::CalculateOutputData)
        //             .def("SetEchoLevel", &BaseSolvingStrategyType::SetEchoLevel)
        //             .def("GetEchoLevel", &BaseSolvingStrategyType::GetEchoLevel)
        //             .def("SetRebuildLevel", &BaseSolvingStrategyType::SetRebuildLevel)
        //             .def("GetRebuildLevel", &BaseSolvingStrategyType::GetRebuildLevel)
        //             .def("SetMoveMeshFlag", &BaseSolvingStrategyType::SetMoveMeshFlag)
        //             .def("MoveMeshFlag", &BaseSolvingStrategyType::MoveMeshFlag)
        //             .def("MoveMesh", &BaseSolvingStrategyType::MoveMesh)
        //             .def("Clear", &BaseSolvingStrategyType::Clear)
        //             .def("Check", &BaseSolvingStrategyType::Check)
        //             .def("InitializeSolutionStep", &BaseSolvingStrategyType::InitializeSolutionStep)
        //             .def("FinalizeSolutionStep", &BaseSolvingStrategyType::FinalizeSolutionStep)
        //             .def("SolveSolutionStep", &BaseSolvingStrategyType::SolveSolutionStep)
        //             //.def("GetModelPart", &BaseSolvingStrategyType::GetModelPart )
        //             ;

        //     // typedef ConvergenceCriteria<SparseSpaceType, LocalSpaceType> TConvergenceCriteriaType;
        //     // typedef BuilderAndSolver<SparseSpaceType, LocalSpaceType, LinearSolverType> BuilderAndSolverType;

        //     // class_< ResidualBasedLinearStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >, bases< BaseSolvingStrategyType >, boost::noncopyable >
        //     //         ((Prefix+"ResidualBasedLinearStrategy").c_str(),init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, bool, bool, bool, bool >())
        //     //         .def(init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename BuilderAndSolverType::Pointer, bool, bool, bool,  bool  >())
        //     //         .def("GetResidualNorm", &ResidualBasedLinearStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::GetResidualNorm)
        //     //         .def("SetBuilderAndSolver", &ResidualBasedLinearStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::SetBuilderAndSolver)
        //     //         ;


        //     // class_< ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >, bases< BaseSolvingStrategyType >, boost::noncopyable >
        //     //         ((Prefix+"ResidualBasedNewtonRaphsonStrategy").c_str(), init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename TConvergenceCriteriaType::Pointer, int, bool, bool, bool >())
        //     //         .def(init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename TConvergenceCriteriaType::Pointer, typename BuilderAndSolverType::Pointer, int, bool, bool, bool >())
        //     //         .def("SetMaxIterationNumber", &ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::SetMaxIterationNumber)
        //     //         .def("GetMaxIterationNumber", &ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::GetMaxIterationNumber)
        //     //         .def("SetKeepSystemConstantDuringIterations", &ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::SetKeepSystemConstantDuringIterations)
        //     //         .def("GetKeepSystemConstantDuringIterations", &ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::GetKeepSystemConstantDuringIterations)
        //     //         ;

        //     // class_< AdaptiveResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >, bases< BaseSolvingStrategyType >, boost::noncopyable >
        //     //         ((Prefix+"AdaptiveResidualBasedNewtonRaphsonStrategy").c_str(),
        //     //         init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename TConvergenceCriteriaType::Pointer, int, int, bool, bool, bool, DataType, DataType, int
        //     //         >())
        //     //         ;

        //     // class_< ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >,
        //     //         bases< BaseSolvingStrategyType >,  boost::noncopyable >
        //     //         ((Prefix+"Explicit_Strategy").c_str(),
        //     //         init<TModelPartType&, int, bool >() )
        //     //         //AssembleLoop loops the elements calling AddExplicitContribution. Using processinfo the element is the one who "decides" which variable to modify.
        //     //         .def("AssembleLoop", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::AssembleLoop)
        //     //         //once the assembleloop has been performed, the variable must be normalized. (for example with the nodal mass or the nodal area). Loop on nodes.
        //     //         .def("NormalizeVariable", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::NormalizeVariable)
        //     //         //ExplicitUpdateLoop modifies a vectorial variable by adding another variable (the RHS, PRESS_PROJ,etc) multiplied by a user-given factor (ie delta_time)
        //     //         .def("ExplicitUpdateLoop", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::ExplicitUpdateLoop)
        //     //         //initialize and finalize.
        //     //         .def("InitializeSolutionStep", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::InitializeSolutionStep)
        //     //         .def("FinalizeSolutionStep", &ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType >::FinalizeSolutionStep)
        //     //         ;

        //     //********************************************************************
        //     //********************************************************************
        //     class_< BaseSchemeType, boost::noncopyable >
        //             ((Prefix+"Scheme").c_str(), init< >())
        //             .def("Initialize", &BaseSchemeType::Initialize)
        //             .def("SchemeIsInitialized", &BaseSchemeType::SchemeIsInitialized)
        //             .def("ElementsAreInitialized", &BaseSchemeType::ElementsAreInitialized)
        //             .def("ConditionsAreInitialized", &BaseSchemeType::ConditionsAreInitialized)
        //             .def("InitializeElements", &BaseSchemeType::InitializeElements)
        //             .def("InitializeConditions", &BaseSchemeType::InitializeConditions)
        //             .def("InitializeSolutionStep", &BaseSchemeType::InitializeSolutionStep)
        //             .def("FinalizeSolutionStep", &BaseSchemeType::FinalizeSolutionStep)
        //             .def("InitializeNonLinIteration", &BaseSchemeType::InitializeNonLinIteration)
        //             .def("FinalizeNonLinIteration", &BaseSchemeType::FinalizeNonLinIteration)
        //             .def("Predict", &BaseSchemeType::Predict)
        //             .def("Update", &BaseSchemeType::Update)
        //             .def("CalculateOutputData", &BaseSchemeType::CalculateOutputData)
        //             .def("Clean", &BaseSchemeType::Clean)
        //             .def("Clear",&BaseSchemeType::Clear)
        //             .def("MoveMesh", MoveMesh<BaseSchemeType>)
        //             .def("Check", &BaseSchemeType::Check)
        //             ;

        //     class_< ResidualBasedIncrementalUpdateStaticScheme< SparseSpaceType, LocalSpaceType, DofType, DofsArrayType >,
        //             bases< BaseSchemeType >, boost::noncopyable >
        //             ((Prefix+"ResidualBasedIncrementalUpdateStaticScheme").c_str(), init<>());

        //     // class_< ResidualBasedIncrementalUpdateStaticSchemeSlip< SparseSpaceType, LocalSpaceType>,
        //     //         bases< ResidualBasedIncrementalUpdateStaticScheme< SparseSpaceType, LocalSpaceType> >,
        //     //         boost::noncopyable >
        //     //         ((Prefix+"ResidualBasedIncrementalUpdateStaticSchemeSlip").c_str(), init<unsigned int, unsigned int>());


        //     // //********************************************************************
        //     // //********************************************************************
        //     // //convergence criteria base class
        //     // class_< ConvergenceCriteria< SparseSpaceType, LocalSpaceType >, boost::noncopyable > ((Prefix+"ConvergenceCriteria").c_str(), init<>())
        //     //         .def("SetActualizeRHSFlag", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::SetActualizeRHSFlag)
        //     //         .def("GetActualizeRHSflag", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::GetActualizeRHSflag)
        //     //         .def("PreCriteria", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::PreCriteria)
        //     //         .def("PostCriteria", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::PostCriteria)
        //     //         .def("Initialize", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::Initialize)
        //     //         .def("InitializeNonLinearIteration", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::InitializeNonLinearIteration)
        //     //         .def("InitializeSolutionStep", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::InitializeSolutionStep)
        //     //         .def("FinalizeNonLinearIteration", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::FinalizeNonLinearIteration)
        //     //         .def("FinalizeSolutionStep", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::FinalizeSolutionStep)
        //     //         .def("Check", &ConvergenceCriteria<SparseSpaceType, LocalSpaceType >::Check)
        //     //         ;

        //     // class_< DisplacementCriteria<SparseSpaceType, LocalSpaceType >,
        //     //         bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
        //     //         boost::noncopyable >
        //     //         ((Prefix+"DisplacementCriteria").c_str(), init< DataType, DataType>())
        //     //         .def("SetEchoLevel", &DisplacementCriteria<SparseSpaceType, LocalSpaceType >::SetEchoLevel);

        //     // class_< IncrementalDisplacementCriteria<SparseSpaceType, LocalSpaceType >,
        //     //         bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
        //     //         boost::noncopyable >
        //     //         ((Prefix+"IncrementalDisplacementCriteria").c_str(), init< DataType, DataType>());

        //     // class_<ResidualCriteria<SparseSpaceType, LocalSpaceType >,
        //     //         bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
        //     //         boost::noncopyable >
        //     //         ((Prefix+"ResidualCriteria").c_str(), init< DataType, DataType>());

        //     // /*          class_< ResidualCriteria< SparseSpaceType >,
        //     //                                  bases<ConvergenceCriteria< SparseSpaceType > >,
        //     //                                  boost::noncopyable >
        //     //                                 ("ResidualCriteria", init<Model::Pointer, DataType >() );

        //     //                         class_< AndCriteria< SparseSpaceType >,
        //     //                                  bases<ConvergenceCriteria< SparseSpaceType > >,
        //     //                                  boost::noncopyable >
        //     //                                 ("AndCriteria", init<Model::Pointer, ConvergenceCriteria< SparseSpaceType >::Pointer, ConvergenceCriteria< SparseSpaceType >::Pointer >()*/
        //     // //);


        //     // class_<And_Criteria<SparseSpaceType, LocalSpaceType >,
        //     //         bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
        //     //         boost::noncopyable >
        //     //         ((Prefix+"AndCriteria").c_str(), init<typename TConvergenceCriteriaType::Pointer, typename TConvergenceCriteriaType::Pointer> ());

        //     // class_<Or_Criteria<SparseSpaceType, LocalSpaceType >,
        //     //         bases<ConvergenceCriteria< SparseSpaceType, LocalSpaceType > >,
        //     //         boost::noncopyable >
        //     //         ((Prefix+"OrCriteria").c_str(), init<typename TConvergenceCriteriaType::Pointer, typename TConvergenceCriteriaType::Pointer> ());

        //     // //********************************************************************
        //     // //********************************************************************
        //     // //

        //     // //Builder and Solver
        //     // typename BuilderAndSolverType::DofsArrayType&(BuilderAndSolverType::*BuilderAndSolver_GetDofSet)() = &BuilderAndSolverType::GetDofSet;

        //     // class_< BuilderAndSolverType, boost::noncopyable > ((Prefix+"BuilderAndSolver").c_str(), init<typename LinearSolverType::Pointer > ())
        //     //         .def("SetCalculateReactionsFlag", &BuilderAndSolverType::SetCalculateReactionsFlag)
        //     //         .def("GetCalculateReactionsFlag", &BuilderAndSolverType::GetCalculateReactionsFlag)
        //     //         .def("SetDofSetIsInitializedFlag", &BuilderAndSolverType::SetDofSetIsInitializedFlag)
        //     //         .def("GetDofSetIsInitializedFlag", &BuilderAndSolverType::GetDofSetIsInitializedFlag)
        //     //         .def("SetReshapeMatrixFlag", &BuilderAndSolverType::SetReshapeMatrixFlag)
        //     //         .def("GetReshapeMatrixFlag", &BuilderAndSolverType::GetReshapeMatrixFlag)
        //     //         .def("GetEquationSystemSize", &BuilderAndSolverType::GetEquationSystemSize)
        //     //         .def("BuildLHS", &BuilderAndSolverType::BuildLHS)
        //     //         .def("BuildRHS", &BuilderAndSolverType::BuildRHS)
        //     //         .def("Build", &BuilderAndSolverType::Build)
        //     //         .def("SystemSolve", &BuilderAndSolverType::SystemSolve)
        //     //         .def("BuildAndSolve", &BuilderAndSolverType::BuildAndSolve)
        //     //         .def("BuildRHSAndSolve", &BuilderAndSolverType::BuildRHSAndSolve)
        //     //         .def("ApplyDirichletConditions", &BuilderAndSolverType::ApplyDirichletConditions)
        //     //         .def("SetUpDofSet", &BuilderAndSolverType::SetUpDofSet)
        //     //         .def("GetDofSet", BuilderAndSolver_GetDofSet, return_internal_reference<>())
        //     //         .def("SetUpSystem", &BuilderAndSolverType::SetUpSystem)
        //     //         .def("ResizeAndInitializeVectors", &BuilderAndSolver_ResizeAndInitializeVectors1<BuilderAndSolverType>)
        //     //         .def("ResizeAndInitializeVectors", &BuilderAndSolver_ResizeAndInitializeVectors2<BuilderAndSolverType>)
        //     //         .def("InitializeSolutionStep", &BuilderAndSolverType::InitializeSolutionStep)
        //     //         .def("FinalizeSolutionStep", &BuilderAndSolverType::FinalizeSolutionStep)
        //     //         .def("CalculateReactions", &BuilderAndSolverType::CalculateReactions)
        //     //         .def("Clear", &BuilderAndSolverType::Clear)
        //     //         .def("Check", &BuilderAndSolverType::Check)
        //     //         .def("SetEchoLevel", &BuilderAndSolverType::SetEchoLevel)
        //     //         .def("GetEchoLevel", &BuilderAndSolverType::GetEchoLevel)
        //     //         ;

        //     // typedef ResidualBasedEliminationBuilderAndSolver< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedEliminationBuilderAndSolverType;
        //     // class_< ResidualBasedEliminationBuilderAndSolverType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedEliminationBuilderAndSolver").c_str(), init< typename LinearSolverType::Pointer > ());

        //     // typedef ResidualBasedBlockBuilderAndSolver< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverType;
        //     // class_< ResidualBasedBlockBuilderAndSolverType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolver").c_str(), init< typename LinearSolverType::Pointer > ());


        //     // typedef ResidualBasedEliminationBuilderAndSolverDeactivation< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedEliminationBuilderAndSolverDeactivationType;
        //     // class_< ResidualBasedEliminationBuilderAndSolverDeactivationType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedEliminationBuilderAndSolverDeactivation").c_str(), init< typename LinearSolverType::Pointer > ());

        //     // typedef ResidualBasedBlockBuilderAndSolverWithConstraints< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverWithConstraintsType;
        //     // class_< ResidualBasedBlockBuilderAndSolverWithConstraintsType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraints").c_str(), init< typename LinearSolverType::Pointer > ());

        //     // typedef ResidualBasedBlockBuilderAndSolverWithConstraintsElementWise< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverWithConstraintsElementWiseType;
        //     // class_< ResidualBasedBlockBuilderAndSolverWithConstraintsElementWiseType, bases<ResidualBasedBlockBuilderAndSolverWithConstraintsType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsElementWise").c_str(), init< typename LinearSolverType::Pointer > ());

        //     // typedef ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivation< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationType;
        //     // class_< ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivation").c_str(), init< typename LinearSolverType::Pointer > ());

        //     // typedef ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWise< SparseSpaceType, LocalSpaceType, LinearSolverType > ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWiseType;
        //     // class_< ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWiseType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWise").c_str(), init< typename LinearSolverType::Pointer > ());
        // }

        void AddStrategiesToPython()
        {
            typedef UblasSpace<KRATOS_DOUBLE_TYPE, CompressedMatrix, Vector> SparseSpaceType;
            typedef UblasSpace<KRATOS_DOUBLE_TYPE, Matrix, Vector> LocalSpaceType;

            typedef UblasSpace<KRATOS_COMPLEX_TYPE, ComplexCompressedMatrix, ComplexVector> ComplexSparseSpaceType;
            typedef UblasSpace<KRATOS_COMPLEX_TYPE, ComplexMatrix, ComplexVector> ComplexLocalSpaceType;

            AddStrategiesToPythonImpl<SparseSpaceType, LocalSpaceType, ModelPart>("");
            // AddStrategiesToPythonImpl<ComplexSparseSpaceType, ComplexLocalSpaceType, ComplexModelPart>("Complex");
        }

    } // namespace Python.

} // Namespace Kratos
