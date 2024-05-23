//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//



#if !defined( KRATOS_PROCESS_INFO_WITH_DOFS_H_INCLUDED )
#define  KRATOS_PROCESS_INFO_WITH_DOFS_H_INCLUDED



// System includes
#include <deque>


// External includes


// Project includes
#include "includes/dof.h"
#include "includes/process_info.h"
#include "includes/kratos_components.h"


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

/// Short class definition.
/** Detail class definition.
*/
class ProcessInfoWithDofs : public ProcessInfo
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of ProcessInfoWithDofs
    KRATOS_CLASS_POINTER_DEFINITION(ProcessInfoWithDofs);

    typedef ProcessInfo BaseType;

    typedef Dof<KRATOS_DOUBLE_TYPE> DofType;

    typedef std::deque<DofType::Pointer> DofsContainerType;

    typedef VariablesListDataValueContainer SolutionStepsNodalDataContainerType;

    typedef BaseType::SizeType SizeType;

    typedef BaseType::IndexType IndexType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    ProcessInfoWithDofs() : BaseType(), mId(-1), mBufferSize(1)
    {
    }

    /// Copy constructor.
    ProcessInfoWithDofs(const ProcessInfoWithDofs& Other) : BaseType(Other)
    {
    }

    /// Destructor.
    virtual ~ProcessInfoWithDofs()
    {
        Finalize();
        std::cout << "ProcessInfoWithDofs destructor is called" << std::endl;
    }


    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    ProcessInfoWithDofs& operator=(const ProcessInfoWithDofs& rOther)
    {
        BaseType::operator=(rOther);

        mDofs = rOther.mDofs;
        mId = rOther.mId;
        mBufferSize = rOther.mBufferSize;

        return *this;
    }

    ///@}
    ///@name Operations
    ///@{

    void SetSolutionStepVariablesList(VariablesList& rVariablesList)
    {
        std::cout << "SetSolutionStepVariablesList is called" << std::endl;
        mpVariablesList = &rVariablesList;
    }

    void SetBufferSize(IndexType NewBufferSize)
    {
        std::cout << "SetBufferSize is called" << std::endl;
        mBufferSize = NewBufferSize;
        for (auto it = mSolutionStepsNodalData.begin(); it != mSolutionStepsNodalData.end(); ++it)
            it->Resize(NewBufferSize);
    }

    void CloneSolutionStepData()
    {
        for (auto it = mSolutionStepsNodalData.begin(); it != mSolutionStepsNodalData.end(); ++it)
            it->CloneFront();
    }

    template<class TVariableType>
    inline void AddDof(TVariableType const& rDofVariable)
    {
        KRATOS_TRY_LEVEL_3

        mSolutionStepsNodalData.push_back(SolutionStepsNodalDataContainerType());
        mSolutionStepsNodalData.back().SetVariablesList(mpVariablesList);
        mSolutionStepsNodalData.back().Resize(mBufferSize);
        mDofs.push_back(DofType::Pointer(new DofType(mId--, &mSolutionStepsNodalData.back(), rDofVariable)));
        std::cout << "Dof " << rDofVariable.Name() << " is added at position " << mDofs.size()-1 << std::endl;

        KRATOS_CATCH_LEVEL_3(*this);
    }

    template<class TVariableType>
    inline void FixDof(
        TVariableType const& rDofVariable,
        const int Position
        )
    {
        pGetDof(rDofVariable, Position)->FixDof();
    }

    ///@}
    ///@name Access
    ///@{

    template<class TVariableType>
    inline const DofType& GetDof(
        TVariableType const& rDofVariable,
        const int Position
        ) const
    {
        return *pGetDof(rDofVariable, Position);
    }

    // template<class TVariableType>
    // inline const typename DofType::Pointer pGetDofConst(
    //     TVariableType const& rDofVariable,
    //     const int Position
    //     ) const
    // {
    //     return pGetDof(rDofVariable, Position);
    // }

    template<class TVariableType>
    inline const typename DofType::Pointer pGetDof(
        TVariableType const& rDofVariable,
        const int Position
        ) const
    {
        // find the dof in the array
        int cnt = 0;
        for (auto it_dof = mDofs.begin(); it_dof != mDofs.end(); ++it_dof)
        {
            if( (*it_dof)->GetVariable() == rDofVariable)
            {
                if (cnt == Position)
                    return *it_dof;
                else
                    ++cnt;
            }
        }

        KRATOS_ERROR << "Dof " << rDofVariable.Name() << " does not exist at position " << Position;
        return NULL;
    }

    template<class TVariableType>
    inline const typename DofType::Pointer pGetDof(
        TVariableType const& rDofVariable,
        const int Position
        )
    {
        // find the dof in the array
        int cnt = 0;
        for (auto it_dof = mDofs.begin(); it_dof != mDofs.end(); ++it_dof)
        {
            if( (*it_dof)->GetVariable() == rDofVariable)
            {
                if (cnt == Position)
                    return *it_dof;
                else
                    ++cnt;
            }
        }

        // if not found, add the missing dofs
        for (int i = 0; i < Position - cnt + 1; ++i)
        {
            AddDof(rDofVariable);
        }

        return mDofs.back();
    }

    void Finalize()
    {
        for (auto it = mSolutionStepsNodalData.begin(); it != mSolutionStepsNodalData.end(); ++it)
            it->Clear();
        mSolutionStepsNodalData.clear();
        mDofs.clear();
        mpVariablesList = NULL;
    }

    ///@}
    ///@name Inquiry
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    std::string Info() const override
    {
        return "Process Info With Dofs";
    }

    ///@}
    ///@name Friends
    ///@{


    ///@}

protected:
    ///@name Protected static Member Variables
    ///@{


    ///@}
    ///@name Protected member Variables
    ///@{


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

    DofsContainerType mDofs;
    std::deque<SolutionStepsNodalDataContainerType> mSolutionStepsNodalData;
    VariablesList* mpVariablesList;
    SizeType mId;
    IndexType mBufferSize;

    ///@}
    ///@name Private Operators
    ///@{

    ///@}
    ///@name Private Operations
    ///@{

    ///@}
    ///@name Serialization
    ///@{

    friend class Serializer;

    void save(Serializer& rSerializer) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, BaseType );
        std::vector<DofType::Pointer> DofsVector(mDofs.begin(), mDofs.end());
        rSerializer.save("Dofs", DofsVector);
    }

    void load(Serializer& rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, BaseType );
        std::vector<DofType::Pointer> DofsVector;
        rSerializer.load("Dofs", DofsVector);
        mDofs.clear();
        std::copy(DofsVector.begin(), DofsVector.end(), mDofs.begin());
    }

    ///@}
    ///@name Private  Access
    ///@{


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{


    ///@}

}; // Class ProcessInfoWithDofs

}  // namespace Kratos.

#endif // KRATOS_PROCESS_INFO_WITH_DOFS_H_INCLUDED  defined
