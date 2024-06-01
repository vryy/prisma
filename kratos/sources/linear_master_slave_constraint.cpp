//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Aditya Ghantasala
//

// System includes

// External includes

// Project includes
#include "includes/define.h"
#include "includes/linear_master_slave_constraint.h"

namespace Kratos
{

/**
 * @brief This method directly applies the master/slave relationship
 * @param rCurrentProcessInfo the current process info instance
 */
void LinearMasterSlaveConstraint::Apply(const ProcessInfo& rCurrentProcessInfo)
{
    // Saving the master dofs values
    Vector master_dofs_values(mMasterDofsVector.size());

    for (IndexType i = 0; i < mMasterDofsVector.size(); ++i) {
        master_dofs_values[i] = mMasterDofsVector[i]->GetSolutionStepValue();
    }

    // std::cout << "master dofs:";
    // for (IndexType i = 0; i < mMasterDofsVector.size(); ++i)
    //     std::cout << " (" << mMasterDofsVector[i]->Id() << ", " << mMasterDofsVector[i]->GetVariable().Name()
    //           << ", " << mMasterDofsVector[i]->GetSolutionStepValue() << ")";
    // std::cout << std::endl;

    // Apply the constraint to the slave dofs
    for (IndexType i = 0; i < mRelationMatrix.size1(); ++i) {
        DataType aux = mConstantVector[i];
        for(IndexType j = 0; j < mRelationMatrix.size2(); ++j) {
            aux += mRelationMatrix(i,j) * master_dofs_values[j];
        }

        #pragma omp atomic
        mSlaveDofsVector[i]->GetSolutionStepValue() += aux;
    }

    // std::cout << "slave dofs:";
    // for (IndexType i = 0; i < mSlaveDofsVector.size(); ++i)
    // std::cout << " (" << mSlaveDofsVector[i]->Id() << ", " << mSlaveDofsVector[i]->GetVariable().Name()
    //           << ", " << mSlaveDofsVector[i]->GetSolutionStepValue() << ")";
    // std::cout << std::endl;
}

} // namespace Kratos
