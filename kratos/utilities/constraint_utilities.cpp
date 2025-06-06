//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Vicente Mataix Ferrandiz
//

// System includes
#include <type_traits>
#include <unordered_set>
#include <unordered_map>

// External includes

// Project includes
#include "utilities/constraint_utilities.h"

namespace Kratos
{

template<class TModelPartType>
void ConstraintUtilities<TModelPartType>::ResetSlaveDofs(TModelPartType& rModelPart)
{
    KRATOS_TRY

    // The number of constraints
    const int number_of_constraints = static_cast<int>(rModelPart.MasterSlaveConstraints().size());

    // The current process info
    const ProcessInfo& r_current_process_info = rModelPart.GetProcessInfo();

    // Setting to zero the slave dofs
    #pragma omp parallel
    {
        #pragma omp for schedule(guided, 512)
        for (int i_const = 0; i_const < number_of_constraints; ++i_const) {
            auto it_const = rModelPart.MasterSlaveConstraints().begin() + i_const;

            // Detect if the constraint is active or not. If the user did not make any choice the constraint
            // It is active by default
            bool constraint_is_active = true;
            if (it_const->IsDefined(ACTIVE))
                constraint_is_active = it_const->Is(ACTIVE);

            if (constraint_is_active) {
                it_const->ResetSlaveDofs(r_current_process_info);
            }
        }
    }

    KRATOS_CATCH("")
}

/***********************************************************************************/
/***********************************************************************************/

template<class TModelPartType>
void ConstraintUtilities<TModelPartType>::ApplyConstraints(TModelPartType& rModelPart)
{
    KRATOS_TRY

    // The number of constraints
    const int number_of_constraints = static_cast<int>(rModelPart.MasterSlaveConstraints().size());

    // The current process info
    const ProcessInfo& r_current_process_info = rModelPart.GetProcessInfo();

    // Adding MPC contribution
    #pragma omp parallel
    {
        #pragma omp for schedule(guided, 512)
        for (int i_const = 0; i_const < number_of_constraints; ++i_const) {
            auto it_const = rModelPart.MasterSlaveConstraints().begin() + i_const;

            // Detect if the constraint is active or not. If the user did not make any choice the constraint
            // It is active by default
            bool constraint_is_active = true;
            if (it_const->IsDefined(ACTIVE))
                constraint_is_active = it_const->Is(ACTIVE);

            if (constraint_is_active) {
                it_const->Apply(r_current_process_info);
            }
        }
    }

    KRATOS_CATCH("")
}

/***********************************************************************************/
/***********************************************************************************/

template<class TModelPartType>
void ConstraintUtilities<TModelPartType>::PreComputeExplicitConstraintConstribution(
    TModelPartType& rModelPart,
    const std::vector<std::string>& rDofVariableNames,
    const std::vector<std::string>& rResidualDofVariableNames
    )
{
    KRATOS_TRY

    if (rDofVariableNames.size() == rResidualDofVariableNames.size())
        KRATOS_ERROR << "PreComputeExplicitConstraintConstribution not properly defined variables";

    // Defining variable maps
    std::unordered_map<std::size_t, Variable<DataType>> double_variable_map;
    typedef typename TModelPartType::VariableComponentType VariableComponentType;
    std::unordered_map<std::size_t, VariableComponentType> components_variable_map;

    std::size_t counter = 0;
    for (auto& r_dof_variable_name : rDofVariableNames) {
        const std::string& r_reaction_variable_name = rResidualDofVariableNames[counter];

        if (KratosComponents<Variable<DataType>>::Has(r_dof_variable_name)) {
            double_variable_map.insert(std::pair<std::size_t, Variable<DataType>>(KratosComponents<Variable<DataType>>::Get(r_dof_variable_name).Key(), KratosComponents<Variable<DataType>>::Get(r_reaction_variable_name)));
        } else if (KratosComponents<Variable<array_1d<DataType, 3>>>::Has(r_dof_variable_name)) {
            // Getting the dof to check
            const VariableComponentType& r_check_dof_x = KratosComponents<VariableComponentType>::Get(r_dof_variable_name + "_X");
            const VariableComponentType& r_check_dof_y = KratosComponents<VariableComponentType>::Get(r_dof_variable_name + "_Y");
            const VariableComponentType& r_check_dof_z = KratosComponents<VariableComponentType>::Get(r_dof_variable_name + "_Z");

            // Getting the residual dofs
            const VariableComponentType& r_residual_dof_x = KratosComponents<VariableComponentType>::Get(r_reaction_variable_name + "_X");
            const VariableComponentType& r_residual_dof_y = KratosComponents<VariableComponentType>::Get(r_reaction_variable_name + "_Y");
            const VariableComponentType& r_residual_dof_z = KratosComponents<VariableComponentType>::Get(r_reaction_variable_name + "_Z");

            components_variable_map.insert(std::pair<std::size_t, VariableComponentType>(r_check_dof_x.Key(), r_residual_dof_x));
            components_variable_map.insert(std::pair<std::size_t, VariableComponentType>(r_check_dof_y.Key(), r_residual_dof_y));
            components_variable_map.insert(std::pair<std::size_t, VariableComponentType>(r_check_dof_z.Key(), r_residual_dof_z));
        } else {
            KRATOS_ERROR << "Variable is not an array or a double";
        }

        ++counter;
    }

    // Getting auxiliar variables
    const ProcessInfo& r_current_process_info = rModelPart.GetProcessInfo();
    const int number_of_constraints = static_cast<int>(rModelPart.MasterSlaveConstraints().size());
    const auto it_cont_begin = rModelPart.MasterSlaveConstraints().begin();

    // Auxiliar values
    typename TModelPartType::MatrixType transformation_matrix;
    typename TModelPartType::VectorType constant_vector, slave_solution_vector, master_solution_vector;
    typename TModelPartType::NodeType::Pointer p_master_node = *(rModelPart.Nodes().begin()).base();
    typename TModelPartType::NodeType::Pointer p_slave_node = *(rModelPart.Nodes().begin()).base();

    #pragma omp parallel firstprivate(transformation_matrix, constant_vector, slave_solution_vector, master_solution_vector, p_master_node, p_slave_node)
    {
        #pragma omp for schedule(guided, 512)
        for (int i_const = 0; i_const < number_of_constraints; ++i_const) {
            auto it_const = it_cont_begin + i_const;

            // Getting the transformation matrix and constant vector
            it_const->CalculateLocalSystem(transformation_matrix, constant_vector, r_current_process_info);

            // Resizing vectors
            if (slave_solution_vector.size() != transformation_matrix.size1())
                slave_solution_vector.resize(transformation_matrix.size1());
            if (master_solution_vector.size() != transformation_matrix.size2())
                master_solution_vector.resize(transformation_matrix.size2());

            std::size_t counter = 0;
            for (auto& r_dof_slave: it_const->GetSlaveDofsVector()) {
                const std::size_t slave_variable_key = r_dof_slave->GetVariable().Key();

                // Updating pointer
                if (r_dof_slave->Id() != p_slave_node->Id())
                    p_slave_node = rModelPart.pGetNode(r_dof_slave->Id());

                if (double_variable_map.find(slave_variable_key) != double_variable_map.end()) {
                    const auto& r_aux_var = double_variable_map.find(slave_variable_key)->second;
                    slave_solution_vector[counter] = p_slave_node->FastGetSolutionStepValue(r_aux_var);
                } else if (components_variable_map.find(slave_variable_key) != components_variable_map.end()) {
                    const auto& r_aux_var = components_variable_map.find(slave_variable_key)->second;
                    slave_solution_vector[counter] = p_slave_node->FastGetSolutionStepValue(r_aux_var);
                } else {
                    slave_solution_vector[counter] = 0.0;
                }

                ++counter;
            }

            // Computing transfered solution
            noalias(master_solution_vector) = prod(trans(transformation_matrix), slave_solution_vector);

            counter = 0;
            for (auto& r_dof_master: it_const->GetMasterDofsVector()) {
                const std::size_t master_variable_key = r_dof_master->GetVariable().Key();

                // Updating pointer
                if (r_dof_master->Id() != p_master_node->Id())
                    p_master_node = rModelPart.pGetNode(r_dof_master->Id());

                if (double_variable_map.find(master_variable_key) != double_variable_map.end()) {
                    const auto& r_aux_var = double_variable_map.find(master_variable_key)->second;
                    DataType& aux_value = p_master_node->FastGetSolutionStepValue(r_aux_var);
                    if constexpr (std::is_arithmetic<DataType>::value)
                    {
                        #pragma omp atomic
                        aux_value += master_solution_vector[counter];
                    }
                    else
                        aux_value += master_solution_vector[counter];
                } else if (components_variable_map.find(master_variable_key) != components_variable_map.end()) {
                    const auto& r_aux_var = components_variable_map.find(master_variable_key)->second;
                    DataType& aux_value = p_master_node->FastGetSolutionStepValue(r_aux_var);
                    if constexpr (std::is_arithmetic<DataType>::value)
                    {
                        #pragma omp atomic
                        aux_value += master_solution_vector[counter];
                    }
                    else
                        aux_value += master_solution_vector[counter];
                }

                ++counter;
            }
        }
    }

    KRATOS_CATCH("")
}

/***********************************************************************************/
/***********************************************************************************/

template<class TModelPartType>
void ConstraintUtilities<TModelPartType>::PreComputeExplicitConstraintMassAndInertia(
    TModelPartType& rModelPart,
    const std::string& DofDisplacementVariableName,
    const std::string& MassVariableName,
    const std::string& DofRotationVariableName,
    const std::string& InertiaVariableName
    )
{
    KRATOS_TRY

    // Defining variable maps
    typedef typename TModelPartType::VariableComponentType VariableComponentType;
    std::unordered_map<std::size_t, Variable<DataType>> displacement_variable_map;
//     std::unordered_map<std::size_t, VariableComponentType> displacement_variable_map; // NOTE: Mass should be components for consistency
//     std::unordered_map<std::size_t, VariableComponentType> rotation_variable_map; // TODO: Add in the future

    // Getting the displacement dof to check
    const VariableComponentType& r_check_dof_x = KratosComponents<VariableComponentType>::Get(DofDisplacementVariableName + "_X");
    const VariableComponentType& r_check_dof_y = KratosComponents<VariableComponentType>::Get(DofDisplacementVariableName + "_Y");
    const VariableComponentType& r_check_dof_z = KratosComponents<VariableComponentType>::Get(DofDisplacementVariableName + "_Z");

    // Getting the residual dofs
    const Variable<DataType>& r_mass_dof_x = KratosComponents<Variable<DataType>>::Get(MassVariableName);
    const Variable<DataType>& r_mass_dof_y = r_mass_dof_x;
    const Variable<DataType>& r_mass_dof_z = r_mass_dof_x;

    displacement_variable_map.insert(std::pair<std::size_t, Variable<DataType>>(r_check_dof_x.Key(), r_mass_dof_x));
    displacement_variable_map.insert(std::pair<std::size_t, Variable<DataType>>(r_check_dof_y.Key(), r_mass_dof_y));
    displacement_variable_map.insert(std::pair<std::size_t, Variable<DataType>>(r_check_dof_z.Key(), r_mass_dof_z));

    // Getting auxiliar variables
    const ProcessInfo& r_current_process_info = rModelPart.GetProcessInfo();
    const int number_of_constraints = static_cast<int>(rModelPart.MasterSlaveConstraints().size());
    const auto it_cont_begin = rModelPart.MasterSlaveConstraints().begin();

    // Auxiliar values
    typename TModelPartType::MatrixType transformation_matrix;
    typename TModelPartType::VectorType constant_vector, slave_solution_vector, master_solution_vector;
    typename TModelPartType::NodeType::Pointer p_master_node = *(rModelPart.Nodes().begin()).base();
    typename TModelPartType::NodeType::Pointer p_slave_node = *(rModelPart.Nodes().begin()).base();

    // Auxiliar map to count the mass added (NOTE: mass should be components for sake of consistency)
    std::unordered_set<std::size_t> slave_mass_map_counter, mass_mass_map_counter;

    for (int i_const = 0; i_const < number_of_constraints; ++i_const) {
        auto it_const = it_cont_begin + i_const;

        // Clear counter
        slave_mass_map_counter.clear();
        mass_mass_map_counter.clear();

        // Getting the transformation matrix and constant vector
        it_const->CalculateLocalSystem(transformation_matrix, constant_vector, r_current_process_info);

        // Resizing vectors
        if (slave_solution_vector.size() != transformation_matrix.size1())
            slave_solution_vector.resize(transformation_matrix.size1());
        if (master_solution_vector.size() != transformation_matrix.size2())
            master_solution_vector.resize(transformation_matrix.size2());

        std::size_t counter = 0;
        for (auto& r_dof_slave : it_const->GetSlaveDofsVector()) {
            const std::size_t slave_variable_key = r_dof_slave->GetVariable().Key();

            // Updating pointer
            const std::size_t dof_id = r_dof_slave->Id();
            if (dof_id != p_slave_node->Id())
                p_slave_node = rModelPart.pGetNode(dof_id);

            if (displacement_variable_map.find(slave_variable_key) != displacement_variable_map.end()) {
                if (slave_mass_map_counter.find(dof_id) == slave_mass_map_counter.end()) {
                    const auto& r_aux_var = displacement_variable_map.find(slave_variable_key)->second;
                    slave_solution_vector[counter] = p_slave_node->GetValue(r_aux_var);
                    slave_mass_map_counter.insert(dof_id);
                } else {
                    slave_solution_vector[counter] = 0.0;
                }
            } else {
                slave_solution_vector[counter] = 0.0;
            }

            ++counter;
        }

        // Computing transfered solution
        noalias(master_solution_vector) = prod(trans(transformation_matrix), slave_solution_vector);

        counter = 0;
        for (auto& r_dof_master : it_const->GetMasterDofsVector()) {
            const std::size_t master_variable_key = r_dof_master->GetVariable().Key();

            // Updating pointer
            const std::size_t dof_id = r_dof_master->Id();
            if (dof_id != p_master_node->Id())
                p_master_node = rModelPart.pGetNode(dof_id);

            if (displacement_variable_map.find(master_variable_key) != displacement_variable_map.end()) {
                if (mass_mass_map_counter.find(dof_id) == mass_mass_map_counter.end()) {
                    const auto& r_aux_var = displacement_variable_map.find(master_variable_key)->second;
                    DataType& aux_value = p_master_node->GetValue(r_aux_var);

                    if constexpr (std::is_arithmetic<DataType>::value)
                    {
                        #pragma omp atomic
                        aux_value += master_solution_vector[counter];
                    }
                    else
                        aux_value += master_solution_vector[counter];

                    mass_mass_map_counter.insert(dof_id);
                }
            }

            ++counter;
        }
    }

    KRATOS_CATCH("")
}

/***********************************************************************************/
/***********************************************************************************/

template class ConstraintUtilities<ModelPart>;
template class ConstraintUtilities<ComplexModelPart>;

} // namespace Kratos
