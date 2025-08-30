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
#ifdef _OPENMP
#include "spaces/parallel_ublas_space.h"
#endif

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
#ifdef KRATOS_NONSQUARE_SUPPORT
#include "solving_strategies/builder_and_solvers/residualbased_elimination_builder_and_solver_deactivation_nonsquare.h"
#endif
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
            for (auto i = rNodes.begin(); i != rNodes.end(); ++i)
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

            if constexpr(!std::is_same<typename SparseSpaceType::DataType, typename TModelPartType::DataType>::value)
                KRATOS_ERROR << "The data type of sparse space and model part is incompatible";

            typedef typename LocalSpaceType::DataType DataType;
            typedef typename DataTypeToValueType<DataType>::value_type ValueType;

            typedef LinearSolver< SparseSpaceType, LocalSpaceType, TModelPartType, Reorderer<SparseSpaceType, LocalSpaceType> > LinearSolverType;
            typedef SolvingStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > BaseSolvingStrategyType;
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

            typedef ConvergenceCriteria<SparseSpaceType, LocalSpaceType, TModelPartType> ConvergenceCriteriaType;
            typedef BuilderAndSolver<SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType> BuilderAndSolverType;

            typedef ResidualBasedLinearStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedLinearStrategyType;
            class_< ResidualBasedLinearStrategyType, bases< BaseSolvingStrategyType >, boost::noncopyable >
                    ((Prefix+"ResidualBasedLinearStrategy").c_str(),init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, bool, bool, bool, bool >())
                    .def(init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename BuilderAndSolverType::Pointer, bool, bool, bool,  bool  >())
                    .def("GetResidualNorm", &ResidualBasedLinearStrategyType::GetResidualNorm)
                    .def("SetBuilderAndSolver", &ResidualBasedLinearStrategyType::SetBuilderAndSolver)
                    ;

            typedef ResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedNewtonRaphsonStrategyType;
            class_< ResidualBasedNewtonRaphsonStrategyType, bases< BaseSolvingStrategyType >, boost::noncopyable >
                    ((Prefix+"ResidualBasedNewtonRaphsonStrategy").c_str(), init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename ConvergenceCriteriaType::Pointer, int, bool, bool, bool >())
                    .def(init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename ConvergenceCriteriaType::Pointer, typename BuilderAndSolverType::Pointer, int, bool, bool, bool >())
                    .def("SetMaxIterationNumber", &ResidualBasedNewtonRaphsonStrategyType::SetMaxIterationNumber)
                    .def("GetMaxIterationNumber", &ResidualBasedNewtonRaphsonStrategyType::GetMaxIterationNumber)
                    .def("SetKeepSystemConstantDuringIterations", &ResidualBasedNewtonRaphsonStrategyType::SetKeepSystemConstantDuringIterations)
                    .def("GetKeepSystemConstantDuringIterations", &ResidualBasedNewtonRaphsonStrategyType::GetKeepSystemConstantDuringIterations)
                    .def("SetBuilderAndSolver", &ResidualBasedNewtonRaphsonStrategyType::SetBuilderAndSolver)
                    .def("GetBuilderAndSolver", &ResidualBasedNewtonRaphsonStrategyType::GetBuilderAndSolver)
                    ;

            typedef AdaptiveResidualBasedNewtonRaphsonStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > AdaptiveResidualBasedNewtonRaphsonStrategyType;
            class_< AdaptiveResidualBasedNewtonRaphsonStrategyType, bases< BaseSolvingStrategyType >, boost::noncopyable >
                    ((Prefix+"AdaptiveResidualBasedNewtonRaphsonStrategy").c_str(),
                    init < TModelPartType&, typename BaseSchemeType::Pointer, typename LinearSolverType::Pointer, typename ConvergenceCriteriaType::Pointer, int, int, bool, bool, bool, ValueType, ValueType, int
                    >())
                    ;

            typedef ExplicitStrategy< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ExplicitStrategyType;
            class_< ExplicitStrategyType, bases< BaseSolvingStrategyType >,  boost::noncopyable >
                    ((Prefix+"Explicit_Strategy").c_str(),
                    init<TModelPartType&, int, bool >() )
                    //AssembleLoop loops the elements calling AddExplicitContribution. Using processinfo the element is the one who "decides" which variable to modify.
                    .def("AssembleLoop", &ExplicitStrategyType::AssembleLoop)
                    //once the assembleloop has been performed, the variable must be normalized. (for example with the nodal mass or the nodal area). Loop on nodes.
                    .def("NormalizeVariable", &ExplicitStrategyType::NormalizeVariable)
                    //ExplicitUpdateLoop modifies a vectorial variable by adding another variable (the RHS, PRESS_PROJ,etc) multiplied by a user-given factor (ie delta_time)
                    .def("ExplicitUpdateLoop", &ExplicitStrategyType::ExplicitUpdateLoop)
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
                    .def(self_ns::str(self))
                    ;

            class_< ResidualBasedIncrementalUpdateStaticScheme< SparseSpaceType, LocalSpaceType, TModelPartType>,
                    bases< BaseSchemeType >, boost::noncopyable >
                    ((Prefix+"ResidualBasedIncrementalUpdateStaticScheme").c_str(), init<>());

            class_< ResidualBasedIncrementalUpdateStaticSchemeSlip< SparseSpaceType, LocalSpaceType, TModelPartType >,
                    bases< ResidualBasedIncrementalUpdateStaticScheme< SparseSpaceType, LocalSpaceType, TModelPartType > >,
                    boost::noncopyable >
                    ((Prefix+"ResidualBasedIncrementalUpdateStaticSchemeSlip").c_str(), init<unsigned int, unsigned int>());

            //********************************************************************
            //********************************************************************
            //convergence criteria base class
            class_< ConvergenceCriteriaType, boost::noncopyable > ((Prefix+"ConvergenceCriteria").c_str(), init<>())
                    .def("SetActualizeRHSFlag", &ConvergenceCriteriaType::SetActualizeRHSFlag)
                    .def("GetActualizeRHSflag", &ConvergenceCriteriaType::GetActualizeRHSflag)
                    .def("PreCriteria", &ConvergenceCriteriaType::PreCriteria)
                    .def("PostCriteria", &ConvergenceCriteriaType::PostCriteria)
                    .def("Initialize", &ConvergenceCriteriaType::Initialize)
                    .def("InitializeNonLinearIteration", &ConvergenceCriteriaType::InitializeNonLinearIteration)
                    .def("InitializeSolutionStep", &ConvergenceCriteriaType::InitializeSolutionStep)
                    .def("FinalizeNonLinearIteration", &ConvergenceCriteriaType::FinalizeNonLinearIteration)
                    .def("FinalizeSolutionStep", &ConvergenceCriteriaType::FinalizeSolutionStep)
                    .def("SetEchoLevel", &ConvergenceCriteriaType::SetEchoLevel)
                    .def("Check", &ConvergenceCriteriaType::Check)
                    .def(self_ns::str(self))
                    ;

            class_< DisplacementCriteria<SparseSpaceType, LocalSpaceType, TModelPartType>,
                    bases<ConvergenceCriteriaType>, boost::noncopyable >
                    ((Prefix+"DisplacementCriteria").c_str(), init< ValueType, ValueType>())
                    ;

            class_< IncrementalDisplacementCriteria<SparseSpaceType, LocalSpaceType, TModelPartType>,
                    bases<ConvergenceCriteriaType>, boost::noncopyable >
                    ((Prefix+"IncrementalDisplacementCriteria").c_str(), init< ValueType, ValueType>());

            class_<ResidualCriteria<SparseSpaceType, LocalSpaceType, TModelPartType>,
                    bases<ConvergenceCriteriaType>, boost::noncopyable >
                    ((Prefix+"ResidualCriteria").c_str(), init< ValueType, ValueType>());

            class_<And_Criteria<SparseSpaceType, LocalSpaceType, TModelPartType>,
                    bases<ConvergenceCriteriaType>, boost::noncopyable >
                    ((Prefix+"AndCriteria").c_str(), init<typename ConvergenceCriteriaType::Pointer, typename ConvergenceCriteriaType::Pointer> ());

            class_<Or_Criteria<SparseSpaceType, LocalSpaceType, TModelPartType>,
                    bases<ConvergenceCriteriaType>, boost::noncopyable >
                    ((Prefix+"OrCriteria").c_str(), init<typename ConvergenceCriteriaType::Pointer, typename ConvergenceCriteriaType::Pointer> ());

            //********************************************************************
            //********************************************************************

            //Builder and Solver
            typename BuilderAndSolverType::DofsArrayType&(BuilderAndSolverType::*BuilderAndSolver_GetDofSet)() = &BuilderAndSolverType::GetDofSet;

            class_< BuilderAndSolverType, typename BuilderAndSolverType::Pointer, boost::noncopyable > ((Prefix+"BuilderAndSolver").c_str(), init<typename LinearSolverType::Pointer > ())
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

            typedef ResidualBasedEliminationBuilderAndSolver< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedEliminationBuilderAndSolverType;
            class_< ResidualBasedEliminationBuilderAndSolverType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedEliminationBuilderAndSolver").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedEliminationBuilderAndSolverDeactivation< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedEliminationBuilderAndSolverDeactivationType;
            class_< ResidualBasedEliminationBuilderAndSolverDeactivationType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedEliminationBuilderAndSolverDeactivation").c_str(), init< typename LinearSolverType::Pointer > ());

#ifdef KRATOS_NONSQUARE_SUPPORT
            typedef ResidualBasedEliminationBuilderAndSolverDeactivationNonSquare< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedEliminationBuilderAndSolverDeactivationNonSquareType;
            class_< ResidualBasedEliminationBuilderAndSolverDeactivationNonSquareType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedEliminationBuilderAndSolverDeactivationNonSquare").c_str(), init< typename LinearSolverType::Pointer > ());
#endif

            typedef ResidualBasedBlockBuilderAndSolver< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedBlockBuilderAndSolverType;
            class_< ResidualBasedBlockBuilderAndSolverType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolver").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolverWithConstraints< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedBlockBuilderAndSolverWithConstraintsType;
            class_< ResidualBasedBlockBuilderAndSolverWithConstraintsType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraints").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolverWithConstraintsElementWise< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedBlockBuilderAndSolverWithConstraintsElementWiseType;
            class_< ResidualBasedBlockBuilderAndSolverWithConstraintsElementWiseType, bases<ResidualBasedBlockBuilderAndSolverWithConstraintsType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsElementWise").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivation< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationType;
            class_< ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivation").c_str(), init< typename LinearSolverType::Pointer > ());

            typedef ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWise< SparseSpaceType, LocalSpaceType, LinearSolverType, TModelPartType > ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWiseType;
            class_< ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWiseType, bases<BuilderAndSolverType>, boost::noncopyable > ((Prefix+"ResidualBasedBlockBuilderAndSolverWithConstraintsDeactivationElementWise").c_str(), init< typename LinearSolverType::Pointer > ());
        }

        void AddStrategiesToPython()
        {
            typedef UblasSpace<KRATOS_DOUBLE_TYPE, CompressedMatrix, Vector> SparseSpaceType;
            typedef UblasSpace<KRATOS_DOUBLE_TYPE, Matrix, Vector> LocalSpaceType;

            typedef UblasSpace<KRATOS_COMPLEX_TYPE, ComplexCompressedMatrix, ComplexVector> ComplexSparseSpaceType;
            typedef UblasSpace<KRATOS_COMPLEX_TYPE, ComplexMatrix, ComplexVector> ComplexLocalSpaceType;

            AddStrategiesToPythonImpl<SparseSpaceType, LocalSpaceType, ModelPart>("");
            AddStrategiesToPythonImpl<ComplexSparseSpaceType, ComplexLocalSpaceType, ComplexModelPart>("Complex");
            AddStrategiesToPythonImpl<ComplexSparseSpaceType, ComplexLocalSpaceType, GComplexModelPart>("GComplex");

            #ifdef _OPENMP
            typedef ParallelUblasSpace<KRATOS_DOUBLE_TYPE, CompressedMatrix, Vector> ParallelSparseSpaceType;
            typedef UblasSpace<KRATOS_DOUBLE_TYPE, Matrix, Vector> ParallelLocalSpaceType;

            typedef ParallelUblasSpace<KRATOS_COMPLEX_TYPE, ComplexCompressedMatrix, ComplexVector> ParallelComplexSparseSpaceType;
            typedef UblasSpace<KRATOS_COMPLEX_TYPE, ComplexMatrix, ComplexVector> ParallelComplexLocalSpaceType;

            AddStrategiesToPythonImpl<ParallelSparseSpaceType, ParallelLocalSpaceType, ModelPart>("Parallel");
            AddStrategiesToPythonImpl<ParallelComplexSparseSpaceType, ParallelComplexLocalSpaceType, ComplexModelPart>("ParallelComplex");
            AddStrategiesToPythonImpl<ParallelComplexSparseSpaceType, ParallelComplexLocalSpaceType, GComplexModelPart>("ParallelGComplex");
            #endif
        }

    } // namespace Python.

} // Namespace Kratos
