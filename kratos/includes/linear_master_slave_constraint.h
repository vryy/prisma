//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Aditya Ghantasala
//

#if !defined(LINEAR_MASTER_SLAVE_CONSTRAINT_H)
#define LINEAR_MASTER_SLAVE_CONSTRAINT_H

// System includes

// External includes

// Project includes
#include "includes/define.h"
#include "includes/master_slave_constraint.h"

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
 * @class LinearMasterSlaveConstraint
 * @ingroup KratosCore
 * @brief This class allows to add a master-slave constraint which is of the form
 * SlaveDofVector = T * MasterDofVector + ConstantVector.
 *
 * or
 *
 * SlaveDof = weight * MasterDof + Constant
 * @details The data T and ConstantVector (or the equivalent scalars) are not stored in the base class, since they can be eventually evaluated runtime.
 * @author Aditya Ghantasala
 */
class KRATOS_API(KRATOS_CORE) LinearMasterSlaveConstraint
    :  public MasterSlaveConstraint
{
public:
    ///@name Type Definitions
    ///@{

    /// The definition of the base class, we take the rest of the definitions from the base class
    typedef MasterSlaveConstraint BaseType;

    /// The index type definition
    typedef BaseType::IndexType IndexType;

    /// The data type definition
    typedef BaseType::DataType DataType;

    /// The DoF type definition
    typedef BaseType::DofType DofType;

    /// The DoF pointer vector type definition
    typedef BaseType::DofPointerVectorType DofPointerVectorType;

    /// The node type definition
    typedef BaseType::NodeType NodeType;

    /// The equation Id vector type definition
    typedef BaseType::EquationIdVectorType EquationIdVectorType;

    /// The matrix type definition
    typedef BaseType::MatrixType MatrixType;

    /// The vector type definition
    typedef BaseType::VectorType VectorType;

    /// The variable type definition (DataType)
    typedef BaseType::VariableType VariableType;

    /// The component variable type definition
    typedef BaseType::VariableComponentType VariableComponentType;

    /// Pointer definition of DataValueContainer
    KRATOS_CLASS_POINTER_DEFINITION(LinearMasterSlaveConstraint);

    ///@}
    ///@name  Enum's
    ///@{

    ///@}
    ///@name Life Cycle
    ///@{

    /**
     * @brief The default constructor
     * @param IndexType The Id of the new created constraint
     */
    explicit LinearMasterSlaveConstraint(IndexType Id = 0)
        : BaseType(Id)
    {
    }

    /**
     * @brief Constructor by passing a vector of Master and slave dofs and corresponding Matrix and constant vector
     * @param IndexType The Id of the new created constraint
     * @param rMasterDofsVector The vector containing the DoF of the master side
     * @param rSlaveDofsVector The vector containing the DoF of the slave side
     * @param rRelationMatrix The relation matrix between the master/slave DoF
     * @param rConstantVector The vector containing the additional kinematic relationship
     */
    LinearMasterSlaveConstraint(
        IndexType Id,
        DofPointerVectorType& rMasterDofsVector,
        DofPointerVectorType& rSlaveDofsVector,
        const MatrixType& rRelationMatrix,
        const VectorType& rConstantVector
        ) : BaseType(Id),
            mSlaveDofsVector(rSlaveDofsVector),
            mMasterDofsVector(rMasterDofsVector),
            mRelationMatrix(rRelationMatrix),
            mConstantVector(rConstantVector)
    {
    }

    /**
     * @brief Constructor by passing a single Master and slave dofs and corresponding weight and constant for a variable component
     * @param IndexType The Id of the new created constraint
     * @param rMasterNode The node of master side
     * @param rMasterVariable The variable of the master DoF
     * @param rSlaveNode The node of slave side
     * @param rSlaveVariable The variable of the slave DoF
     * @param Weight The relation between the master/slave DoF
     * @param Constant The additional kinematic relationship
     */
    LinearMasterSlaveConstraint(
        IndexType Id,
        NodeType& rMasterNode,
        const VariableType& rMasterVariable,
        NodeType& rSlaveNode,
        const VariableType& rSlaveVariable,
        const DataType Weight,
        const DataType Constant
        ) : MasterSlaveConstraint(Id)
    {
        // Resizing the memeber variables
        mRelationMatrix.resize(1,1,false);
        mConstantVector.resize(1,false);

        // Obtaining the dofs from the variables
        mSlaveDofsVector.push_back(rSlaveNode.pGetDof(rSlaveVariable));
        mMasterDofsVector.push_back(rMasterNode.pGetDof(rMasterVariable));

        mRelationMatrix(0,0) = Weight;
        mConstantVector(0) = Constant;

        // Setting the slave flag on the node
        rSlaveNode.Set(SLAVE);
    }

    /**
     * @brief Constructor by passing a single Master and slave dofs and corresponding weight and constant for a variable component
     * @param IndexType The Id of the new created constraint
     * @param rMasterNode The node of master side
     * @param rMasterVariable The variable of the master DoF
     * @param rSlaveNode The node of slave side
     * @param rSlaveVariable The variable of the slave DoF
     * @param Weight The relation between the master/slave DoF
     * @param Constant The additional kinematic relationship
     */
    LinearMasterSlaveConstraint(
        IndexType Id,
        NodeType& rMasterNode,
        const VariableComponentType& rMasterVariable,
        NodeType& rSlaveNode,
        const VariableComponentType& rSlaveVariable,
        const DataType Weight,
        const DataType Constant
        ) : MasterSlaveConstraint(Id)
    {
        // Resizing the memeber variables
        mRelationMatrix.resize(1,1,false);
        mConstantVector.resize(1,false);

        // Obtaining the dofs from the variables
        mSlaveDofsVector.push_back(rSlaveNode.pGetDof(rSlaveVariable));
        mMasterDofsVector.push_back(rMasterNode.pGetDof(rMasterVariable));

        mRelationMatrix(0,0) = Weight;
        mConstantVector(0) = Constant;

        // Setting the slave flag on the node
        rSlaveNode.Set(SLAVE);
    }

    /// Destructor.
    ~LinearMasterSlaveConstraint() override
    {

    }

    /// Copy Constructor
    LinearMasterSlaveConstraint(const LinearMasterSlaveConstraint& rOther)
        : BaseType(rOther),
          mSlaveDofsVector(rOther.mSlaveDofsVector),
          mMasterDofsVector(rOther.mMasterDofsVector),
          mRelationMatrix(rOther.mRelationMatrix),
          mConstantVector(rOther.mConstantVector)
    {
    }

    /// Assignment operator
    LinearMasterSlaveConstraint& operator=(const LinearMasterSlaveConstraint& rOther)
    {
        BaseType::operator=( rOther );
        mSlaveDofsVector = rOther.mSlaveDofsVector;
        mMasterDofsVector = rOther.mMasterDofsVector;
        mRelationMatrix = rOther.mRelationMatrix;
        mConstantVector = rOther.mConstantVector;
        return *this;
    }

    ///@}
    ///@name Operators
    ///@{

    ///@}
    ///@name Operations
    ///@{

    /**
     * @brief Create method by passing a single Master and slave dofs and corresponding weight and constant for a variable component
     * @param IndexType The Id of the new created constraint
     * @param rMasterDofsVector The DoFs of master side
     * @param rSlaveDofsVector The DoFs of master side
     * @param rRelationMatrix The relation matrix between the master/slave DoF
     * @param rConstantVector The vector containing the additional kinematic relationship
     * @return A Pointer to the new constraint
     */
    MasterSlaveConstraint::Pointer Create(
        IndexType Id,
        DofPointerVectorType& rMasterDofsVector,
        DofPointerVectorType& rSlaveDofsVector,
        const MatrixType& rRelationMatrix,
        const VectorType& rConstantVector
        ) const override
    {
        return MasterSlaveConstraint::Pointer(new LinearMasterSlaveConstraint(Id, rMasterDofsVector, rSlaveDofsVector, rRelationMatrix, rConstantVector));
    }

    /**
     * @brief Create method by passing a single Master and slave dofs and corresponding weight and constant for a variable component
     * @param IndexType The Id of the new created constraint
     * @param rMasterNode The node of master side
     * @param rMasterVariable The variable of the master DoF
     * @param rSlaveNode The node of slave side
     * @param rSlaveVariable The variable of the slave DoF
     * @param Weight The relation between the master/slave DoF
     * @param Constant The additional kinematic relationship
     * @return A Pointer to the new constraint
     */
    MasterSlaveConstraint::Pointer Create(
        IndexType Id,
        NodeType& rMasterNode,
        const VariableType& rMasterVariable,
        NodeType& rSlaveNode,
        const VariableType& rSlaveVariable,
        const DataType Weight,
        const DataType Constant
        ) const override
    {
        return MasterSlaveConstraint::Pointer(new LinearMasterSlaveConstraint(Id, rMasterNode, rMasterVariable, rSlaveNode, rSlaveVariable, Weight, Constant));
    }

    /**
     * @brief Create method by passing a single Master and slave dofs and corresponding weight and constant for a variable component
     * @param IndexType The Id of the new created constraint
     * @param rMasterNode The node of master side
     * @param rMasterVariable The variable of the master DoF
     * @param rSlaveNode The node of slave side
     * @param rSlaveVariable The variable of the slave DoF
     * @param Weight The relation between the master/slave DoF
     * @param Constant The additional kinematic relationship
     * @return A Pointer to the new constraint
     */
    MasterSlaveConstraint::Pointer Create(
        IndexType Id,
        NodeType& rMasterNode,
        const VariableComponentType& rMasterVariable,
        NodeType& rSlaveNode,
        const VariableComponentType& rSlaveVariable,
        const DataType Weight,
        const DataType Constant
        ) const override
    {
        return MasterSlaveConstraint::Pointer(new LinearMasterSlaveConstraint(Id, rMasterNode, rMasterVariable, rSlaveNode, rSlaveVariable, Weight, Constant));
    }

    /**
     * @brief It creates a new constraint pointer and clones the previous constraint data
     * @param NewId the ID of the new constraint
     * @return a Pointer to the new constraint
     */
    MasterSlaveConstraint::Pointer Clone (IndexType NewId) const override
    {
        KRATOS_TRY

        MasterSlaveConstraint::Pointer p_new_const = boost::make_shared<LinearMasterSlaveConstraint>(*this);
        p_new_const->SetId(NewId);
        p_new_const->SetData(this->GetData());
        p_new_const->Set(Flags(*this));
        return p_new_const;

        KRATOS_CATCH("");
    }

    /**
     * @brief Determines the constrant's slvae and master list of DOFs
     * @param rSlaveDofsVector The list of slave DOFs
     * @param rMasterDofsVector The list of slave DOFs
     * @param rCurrentProcessInfo The current process info instance
     */
    void GetDofList(
        DofPointerVectorType& rSlaveDofsVector,
        DofPointerVectorType& rMasterDofsVector,
        const ProcessInfo& rCurrentProcessInfo
        ) const override
    {
        rSlaveDofsVector = mSlaveDofsVector;
        rMasterDofsVector = mMasterDofsVector;
    }

    /**
     * @brief Determines the constrant's slave and master list of DOFs
     * @param rSlaveDofsVector The list of slave DOFs
     * @param rMasterDofsVector The list of slave DOFs
     * @param rCurrentProcessInfo The current process info instance
     */
    void SetDofList(
        const DofPointerVectorType& rSlaveDofsVector,
        const DofPointerVectorType& rMasterDofsVector,
        const ProcessInfo& rCurrentProcessInfo
        ) override
    {
        mSlaveDofsVector = rSlaveDofsVector;
        mMasterDofsVector = rMasterDofsVector;
    }

    /**
     * @brief This determines the master equation IDs connected to this constraint
     * @param rSlaveEquationIds The vector of slave equation ids.
     * @param rMasterEquationIds The vector of master equation ids.
     * @param rCurrentProcessInfo The current process info instance
     */
    void EquationIdVector(
        EquationIdVectorType& rSlaveEquationIds,
        EquationIdVectorType& rMasterEquationIds,
        const ProcessInfo& rCurrentProcessInfo
        ) const override
    {
        if (rSlaveEquationIds.size() != mSlaveDofsVector.size())
            rSlaveEquationIds.resize(mSlaveDofsVector.size());

        if (rMasterEquationIds.size() != mMasterDofsVector.size())
            rMasterEquationIds.resize(mMasterDofsVector.size());

        for(IndexType i=0; i<rSlaveEquationIds.size(); ++i)
            rSlaveEquationIds[i] = mSlaveDofsVector[i]->EquationId();

        for(IndexType i=0; i<rMasterEquationIds.size(); ++i)
            rMasterEquationIds[i] = mMasterDofsVector[i]->EquationId();
    }

    /**
     * @brief This method returns the slave dof vector
     * @return The vector containing the slave dofs
     */
    const DofPointerVectorType& GetSlaveDofsVector() const override
    {
        return mSlaveDofsVector;
    }

    /**
     * @brief This method returns the slave dof vector
     * @return The vector containing the slave dofs
     */
    void SetSlaveDofsVector(const DofPointerVectorType& rSlaveDofsVector) override
    {
        mSlaveDofsVector = rSlaveDofsVector;
    }

    /**
     * @brief This method returns the slave dof vector
     * @return The vector containing the slave dofs
     */
    const DofPointerVectorType& GetMasterDofsVector() const override
    {
        return mMasterDofsVector;
    }

    /**
     * @brief This method returns the slave dof vector
     * @return The vector containing the slave dofs
     */
    void SetMasterDofsVector(const DofPointerVectorType& rMasterDofsVector) override
    {
        mMasterDofsVector = rMasterDofsVector;
    }

    /**
     * @brief This method resets the values of the slave dofs
     * @param rCurrentProcessInfo the current process info instance
     */
    void ResetSlaveDofs(const ProcessInfo& rCurrentProcessInfo) override
    {
        for (IndexType i = 0; i < mSlaveDofsVector.size(); ++i) {
            #pragma omp atomic
            mSlaveDofsVector[i]->GetSolutionStepValue() *= 0.0;
        }
    }

    /**
     * @brief This method directly applies the master/slave relationship
     * @param rCurrentProcessInfo the current process info instance
     */
    void Apply(const ProcessInfo& rCurrentProcessInfo) override
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

    /**
     * @brief This is called during the assembling process in order
     * @details To calculate the relation between the master and slave.
     * @param rRelationMatrix the matrix which relates the master and slave degree of freedom
     * @param rConstant The constant vector (one entry for each slave)
     * @param rCurrentProcessInfo the current process info instance
     */
    void CalculateLocalSystem(
        MatrixType& rRelationMatrix,
        VectorType& rConstantVector,
        const ProcessInfo& rCurrentProcessInfo
        ) const override
    {
        rRelationMatrix = mRelationMatrix;
        rConstantVector = mConstantVector;
    }

    ///@}
    ///@name Input and output
    ///@{

    /**
     * @brief Returns the string containing a detailed description of this object.
     * @return the string with informations
     */
    std::string GetInfo() const override
    {
        return "Linear User Provided Master Slave Constraint class !";
    }

    /**
     * @brief This method prints the current Constraint Id
     * @param rOStream The buffer where the information is given
     */
    void PrintInfo(std::ostream &rOStream) const override
    {
        rOStream << " LinearMasterSlaveConstraint Id  : " << this->Id() << std::endl;
        rOStream << " Number of Slaves          : " << mSlaveDofsVector.size() << std::endl;
        rOStream << " Number of Masters         : " << mMasterDofsVector.size() << std::endl;
        rOStream << " Relation Matrix           : " << mRelationMatrix << std::endl;
        rOStream << " Constant Vector           : " << mConstantVector << std::endl;
    }

    ///@}
protected:
    ///@name Protected static Member Variables
    ///@{

    ///@}
    ///@name Protected member Variables
    ///@{

    DofPointerVectorType mSlaveDofsVector;  /// The DoFs of slave side
    DofPointerVectorType mMasterDofsVector; /// The DoFs of master side
    MatrixType mRelationMatrix;             /// The relation matrix between the master/slave DoF
    VectorType mConstantVector;             /// The vector containing the additional kinematic relationship

    ///@}
    ///@name Protected Operators
    ///@{

    ///@}
    ///@name Protected Operations
    ///@{

    ///@}
    ///@name Protected  Access
    ///@{

    ///@}
    ///@name Protected Inquiry
    ///@{

    ///@}
    ///@name Protected LifeCycle
    ///@{

    ///@}

private:
    ///@name Static Member Variables
    ///@{

    ///@}
    ///@name Member Variables
    ///@{

    ///@name Serialization
    ///@{

    friend class Serializer;

    void save(Serializer &rSerializer) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, MasterSlaveConstraint);
        rSerializer.save("SlaveDofVec", mSlaveDofsVector);
        rSerializer.save("MasterDofVec", mMasterDofsVector);
        rSerializer.save("RelationMat", mRelationMatrix);
        rSerializer.save("ConstantVec", mConstantVector);
    }

    void load(Serializer &rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, MasterSlaveConstraint);
        rSerializer.load("SlaveDofVec", mSlaveDofsVector);
        rSerializer.load("MasterDofVec", mMasterDofsVector);
        rSerializer.load("RelationMat", mRelationMatrix);
        rSerializer.load("ConstantVec", mConstantVector);
    }
};

///@name Input/Output funcitons
///@{


///@}

} // namespace Kratos

#endif // USER_PROVIDED_LINEAR_MASTER_SLAVE_CONSTRAINT_H
