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
//                   Klaus B Sautter
//

#if !defined(KRATOS_CONSTRAINT_UTILITIES)
#define KRATOS_CONSTRAINT_UTILITIES

// System includes

// External includes

// Project includes
#include "includes/model_part.h"

namespace Kratos
{
///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}
///@name Kratos Classes
///@{
/**
 * @namespace ConstraintUtilities
 * @ingroup KratosCore
 * @brief This namespace includes several utilities necessaries for the computation of the MPC
 * @author Vicente Mataix Ferrandiz
 */
template<class TModelPartType>
class ConstraintUtilities
{
public:

    typedef typename TModelPartType::DataType DataType;

    typedef typename TModelPartType::MasterSlaveConstraintType MasterSlaveConstraintType;

    /**
     * @brief This method resets the values of the slave dofs
     * @param rModelPart The model of the problem to solve
     */
    static void KRATOS_API(KRATOS_CORE) ResetSlaveDofs(TModelPartType& rModelPart);

    /**
     * @brief This method resets the values of the slave dofs
     * @param rModelPart The model of the problem to solve
     */
    static void KRATOS_API(KRATOS_CORE) ApplyConstraints(TModelPartType& rModelPart);

    /**
     * @brief This method precomputes the contribution of the explicit MPC over nodal residual forces
     * @param rModelPart The model of the problem to solve
     * @param rDofVariableNames The name of the Dof variables to check
     * @param rResidualDofVariableNames The name name of the corresponding residual variables
     */
    static void KRATOS_API(KRATOS_CORE) PreComputeExplicitConstraintConstribution(
        TModelPartType& rModelPart,
        const std::vector<std::string>& rDofVariableNames,
        const std::vector<std::string>& rResidualDofVariableNames
        );

    /**
     * @brief This method precomputes the contribution of the explicit MPC over nodal masses and inertias
     * @todo The inertia must be computed using the Steiner theorem https://en.wikipedia.org/wiki/Parallel_axis_theorem
     * @param rModelPart The model of the problem to solve
     * @param DofDisplacementVariableName The name of the Dof variables to check
     * @param MassVariableName The name of the variable of the nodal mass
     * @param DofRotationVariableName The name of the rotational variable name
     * @param InertiaVariableName The inertia variable to be considered
     */
    static void KRATOS_API(KRATOS_CORE) PreComputeExplicitConstraintMassAndInertia(
        TModelPartType& rModelPart,
        const std::string& DofDisplacementVariableName = "DISPLACEMENT",
        const std::string& MassVariableName = "NODAL_MASS",
        const std::string& DofRotationVariableName = "ROTATION",
        const std::string& InertiaVariableName = "NODAL_INERTIA_TENSOR"
        );

    /**
     * Add a complex linear constraint to the model_part. The constraint is of type
     *   u1 = a*u2 + b*u3 + c*u4 + ...
     * @param rModelPart the model_part to add the constraint
     * @param pSlaveNode the slave node carrying the slave d.o.f
     * @param pMasterNodes the master nodes carrying the master d.o.fs
     * @param rVariable the variable representing the nodal d.o.f
     * @param r_relation_matrix the relation matrix of size(1, number_of_master_nodes)
     * @param r_constant_vector the constant vector of size 1
     */
    template<typename TVariableType>
    static typename MasterSlaveConstraintType::Pointer CreateLinearConstraint(TModelPartType& rModelPart,
        const std::string& r_constraint_name,
        const typename TModelPartType::IndexType& r_constraint_id,
        typename TModelPartType::NodeType::Pointer pSlaveNode,
        std::vector<typename TModelPartType::NodeType::Pointer> pMasterNodes,
        const TVariableType& rVariable,
        const typename TModelPartType::MatrixType& r_relation_matrix,
        const typename TModelPartType::VectorType& r_constant_vector)
    {
        pSlaveNode->Set(SLAVE);

        typedef typename TModelPartType::DofType DofType;

        std::vector<typename DofType::Pointer> slave_dofs(1);
        slave_dofs[0] = pSlaveNode->pGetDof(rVariable);

        std::vector<typename DofType::Pointer> master_dofs(pMasterNodes.size());
        for (std::size_t i = 0; i < pMasterNodes.size(); ++i)
            master_dofs[i] = pMasterNodes[i]->pGetDof(rVariable);

        return rModelPart.CreateNewMasterSlaveConstraint(r_constraint_name, r_constraint_id, master_dofs, slave_dofs, r_relation_matrix, r_constant_vector);
    }

    /**
     * Add a complex linear constraint to the model_part. The constraint is of type
     *   u1 = a*u2 + b*u3 + c*u4 + ...
     * @param rModelPart the model_part to add the constraint
     * @param pSlaveNode the slave node carrying the slave d.o.f
     * @param pMasterNodes the master nodes carrying the master d.o.fs
     * @param rVariable the variable representing the nodal d.o.f
     * @param r_relation_matrix the relation matrix of size(1, number_of_master_nodes)
     * @param r_constant_vector the constant vector of size 1
     */
    template<typename TVariableType>
    static typename MasterSlaveConstraintType::Pointer CreateLinearConstraintNoUnique(TModelPartType& rModelPart,
        const std::string& r_constraint_name,
        const typename TModelPartType::IndexType& r_constraint_id,
        typename TModelPartType::NodeType::Pointer pSlaveNode,
        std::vector<typename TModelPartType::NodeType::Pointer> pMasterNodes,
        const TVariableType& rVariable,
        const typename TModelPartType::MatrixType& r_relation_matrix,
        const typename TModelPartType::VectorType& r_constant_vector)
    {
        pSlaveNode->Set(SLAVE);

        typedef typename TModelPartType::DofType DofType;

        std::vector<typename DofType::Pointer> slave_dofs(1);
        slave_dofs[0] = pSlaveNode->pGetDof(rVariable);

        std::vector<typename DofType::Pointer> master_dofs(pMasterNodes.size());
        for (std::size_t i = 0; i < pMasterNodes.size(); ++i)
            master_dofs[i] = pMasterNodes[i]->pGetDof(rVariable);

        return rModelPart.CreateNewMasterSlaveConstraintNoUnique(r_constraint_name, r_constraint_id, master_dofs, slave_dofs, r_relation_matrix, r_constant_vector);
    }

    /**
     * Print the values associated with the constraint
     */
    static void PrintConstraint(const MasterSlaveConstraintType& rConstraint)
    {
        typedef typename MasterSlaveConstraintType::DofPointerVectorType DofPointerVectorType;

        const DofPointerVectorType& slave_dofs = rConstraint.GetSlaveDofsVector();
        const DofPointerVectorType& master_dofs = rConstraint.GetMasterDofsVector();

        std::cout << "Constraint " << rConstraint.Id() << ":" << std::endl;
        std::cout << " Slave dofs:" << std::endl;
        for (std::size_t i = 0; i < slave_dofs.size(); ++i)
            std::cout << "  " << slave_dofs[i]->Id() << " " << slave_dofs[i]->GetVariable().Name() << " " << slave_dofs[i]->GetSolutionStepValue() << std::endl;
        std::cout << " Master dofs:" << std::endl;
        for (std::size_t i = 0; i < master_dofs.size(); ++i)
            std::cout << "  " << master_dofs[i]->Id() << " " << master_dofs[i]->GetVariable().Name() << " " << master_dofs[i]->GetSolutionStepValue() << std::endl;
    }

}; // namespace ConstraintUtilities

}  // namespace Kratos

#endif /* KRATOS_CONSTRAINT_UTILITIES defined */
