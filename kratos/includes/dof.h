//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//
//

#if !defined(KRATOS_DOF_H_INCLUDED)
#define  KRATOS_DOF_H_INCLUDED

// System includes
#include <string>
#include <iostream>
#include <sstream>
#include <cstddef>

// External includes

// Project includes
#include "includes/define.h"
#include "containers/variables_list_data_value_container.h"
#include "containers/vector_component_adaptor.h"
#include "utilities/indexed_object.h"
#include "containers/array_1d.h"



namespace Kratos
{

#define KRATOS_DOF_TRAITS \
        KRATOS_MAKE_DOF_TRAIT(0) Variable<TDataType> KRATOS_END_DOF_TRAIT(0); \
        KRATOS_MAKE_DOF_TRAIT(1) VariableComponent<VectorComponentAdaptor<array_1d<TDataType, 3> > > KRATOS_END_DOF_TRAIT(1);


template<class TDataType, class TVariableType = Variable<TDataType> >
struct DofTrait
{
    static const int Id;
};


#define KRATOS_MAKE_DOF_TRAIT(id) \
        template<class TDataType> \
        struct DofTrait<TDataType,


#define KRATOS_END_DOF_TRAIT(id) \
        >{\
        static const int Id = id;\
        }


KRATOS_DOF_TRAITS


#undef KRATOS_MAKE_DOF_TRAIT
#undef KRATOS_END_DOF_TRAIT


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

/// Dof represents a degree of freedom (DoF).
/** It is a lightweight object which holds its variable, like TEMPERATURE, its
state of freedom, and a reference to its value in the data structure.
This class enables the system to work with different set of dofs and also
represents the Dirichlet condition assigned to each dof.
*/
template<class TDataType>
class Dof : public IndexedObject
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of Dof
    KRATOS_CLASS_POINTER_DEFINITION(Dof);

    typedef IndexedObject::IndexType IndexType;

    typedef TDataType DataType;

    typedef IndexType EquationIdType;

    typedef VariablesListDataValueContainer<DataType> SolutionStepsDataContainerType;

    ///@}
    ///@name Life Cycle
    ///@{

    /** Constructor. This constructor takes all necessary
    information to construct a degree of freedom. Also default
    values are used to make it easier to define for simple cases.


    @param ThisNodeIndex Index of the node which this degree of
    freedom belongs to it. It can be get by Node::Index() method.


    @param rThisVariable Variable which this degree of freedom
    holds. This variable considered as unknown of problem to solved
    and fixing by Fix() method also applied to it. It must be a
    TDataType variable or component not a vector. For example
    DISPLACEMENT_X in structural element.


    @param rThisReaction This is the right hand side variable in
    the system of equation correspounding to variable this dof
    holding. For example THERMAL_FLOW in thermal element. It will
    be none as default.


    @see Node
    @see Variable
    @see VariableComponent
    */
    template<class TVariableType>
    Dof(IndexType NodeId, SolutionStepsDataContainerType* pThisSolutionStepsData,
        const TVariableType& rThisVariable)
        : IndexedObject(NodeId),
          mIsFixed(false),
          mEquationId(IndexType()),
          mLocalEquationId(IndexType()),
          mpSolutionStepsData(pThisSolutionStepsData),
          mpVariable(&rThisVariable),
          mpReaction(&msNone),
          mVariableType(DofTrait<TDataType, TVariableType>::Id),
          mReactionType(DofTrait<TDataType, Variable<TDataType> >::Id)
    {
    }

    template<class TVariableType, class TReactionType>
    Dof(IndexType NodeId, SolutionStepsDataContainerType* pThisSolutionStepsData,
        const TVariableType& rThisVariable,
        const TReactionType& rThisReaction)
        : IndexedObject(NodeId),
          mIsFixed(false),
          mEquationId(IndexType()),
          mLocalEquationId(IndexType()),
          mpSolutionStepsData(pThisSolutionStepsData),
          mpVariable(&rThisVariable),
          mpReaction(&rThisReaction),
          mVariableType(DofTrait<TDataType, TVariableType>::Id),
          mReactionType(DofTrait<TDataType, TReactionType>::Id)
    {
    }

    //This default constructor is needed for pointer vector set
    Dof()
        : IndexedObject(0),
          mIsFixed(false),
          mEquationId(IndexType()),
          mLocalEquationId(IndexType()),
          mpSolutionStepsData(),
          mpVariable(&msNone),
          mpReaction(&msNone),
          mVariableType(DofTrait<TDataType, Variable<TDataType> >::Id),
          mReactionType(DofTrait<TDataType, Variable<TDataType> >::Id)
    {
    }

    /// Copy constructor.
    Dof(Dof const& rOther)
        : IndexedObject(rOther),
          mIsFixed(rOther.mIsFixed),
          mEquationId(rOther.mEquationId),
          mLocalEquationId(rOther.mLocalEquationId),
          mpSolutionStepsData(rOther.mpSolutionStepsData),
          mpVariable(rOther.mpVariable),
          mpReaction(rOther.mpReaction),
          mVariableType(rOther.mVariableType),
          mReactionType(rOther.mReactionType)
    {
    }


    /// Destructor.
    virtual ~Dof() {}


    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    Dof& operator=(Dof const& rOther)
    {
        IndexedObject::operator=(rOther);
        mIsFixed = rOther.mIsFixed;
        mEquationId = rOther.mEquationId;
        mLocalEquationId = rOther.mLocalEquationId;
        mpSolutionStepsData = rOther.mpSolutionStepsData;
        mpVariable = rOther.mpVariable;
        mpReaction = rOther.mpReaction;
        mVariableType = rOther.mVariableType;
        mReactionType = rOther.mReactionType;

        return *this;
    }

    template<class TVariableType>
    typename TVariableType::Type& operator()(const TVariableType& rThisVariable, IndexType SolutionStepIndex = 0)
    {
        return GetSolutionStepValue(rThisVariable, SolutionStepIndex);
    }

    template<class TVariableType>
    typename TVariableType::Type const& operator()(const TVariableType& rThisVariable, IndexType SolutionStepIndex = 0) const
    {
        return GetSolutionStepValue(rThisVariable, SolutionStepIndex);
    }

    TDataType& operator()(IndexType SolutionStepIndex = 0)
    {
        return GetSolutionStepValue(SolutionStepIndex);
    }

    TDataType const& operator()(IndexType SolutionStepIndex = 0) const
    {
        return GetSolutionStepValue(SolutionStepIndex);
    }

    TDataType& operator[](IndexType SolutionStepIndex)
    {
        return GetSolutionStepValue(SolutionStepIndex);
    }

    TDataType const& operator[](IndexType SolutionStepIndex) const
    {
        return GetSolutionStepValue(SolutionStepIndex);
    }

    ///@}
    ///@name Operations
    ///@{

    TDataType& GetSolutionStepValue(IndexType SolutionStepIndex = 0)
    {
        return GetReference(*mpVariable, *mpSolutionStepsData, SolutionStepIndex, mVariableType);
    }

    TDataType const& GetSolutionStepValue(IndexType SolutionStepIndex = 0) const
    {
        return GetReference(*mpVariable, *mpSolutionStepsData, SolutionStepIndex, mVariableType);
    }

    template<class TVariableType>
    typename TVariableType::Type& GetSolutionStepValue(const TVariableType& rThisVariable, IndexType SolutionStepIndex = 0)
    {
        return mpSolutionStepsData->GetValue(rThisVariable, SolutionStepIndex);
    }

    template<class TVariableType>
    typename TVariableType::Type const& GetSolutionStepValue(const TVariableType& rThisVariable, IndexType SolutionStepIndex = 0) const
    {
        return mpSolutionStepsData->GetValue(rThisVariable, SolutionStepIndex);
    }

    TDataType& GetSolutionStepReactionValue(IndexType SolutionStepIndex = 0)
    {
        return GetReference(*mpReaction, *mpSolutionStepsData, SolutionStepIndex, mReactionType);
    }

    TDataType const& GetSolutionStepReactionValue(IndexType SolutionStepIndex = 0) const
    {
        return GetReference(*mpReaction, *mpSolutionStepsData, SolutionStepIndex, mReactionType);
    }

    ///@}
    ///@name Access
    ///@{


    /** Returns variable assigned to this degree of freedom. */
    const VariableData& GetVariable() const
    {
        return *mpVariable;
    }

    /** Returns reaction variable of this degree of freedom. */
    const VariableData& GetReaction() const
    {
        return *mpReaction;
    }

    template<class TReactionType>
    void SetReaction(TReactionType const& rReaction)
    {
        mReactionType = DofTrait<TDataType, TReactionType>::Id;
        mpReaction = &rReaction;
    }

    /** Return the Equation Id related to this degree eof freedom.
     */
    EquationIdType EquationId() const
    {
        return mEquationId;
    }

    EquationIdType LocalEquationId() const
    {
        return mLocalEquationId;
    }

    /** Sets the Equation Id to the desired value
     */
    void SetEquationId(EquationIdType NewEquationId)
    {
        mEquationId = NewEquationId;
    }

    void SetLocalEquationId(EquationIdType NewEquationId)
    {
        mLocalEquationId = NewEquationId;
    }

    /** Fixes the Dof
     */
    void FixDof()
    {
        mIsFixed=true;
    }

    /** Frees the degree of freedom
     */
    void FreeDof()
    {
        mIsFixed=false;
    }

    SolutionStepsDataContainerType* GetSolutionStepsData()
    {
        return mpSolutionStepsData;
    }

    void SetSolutionStepsData(SolutionStepsDataContainerType* pNewSolutionStepsData)
    {
        mpSolutionStepsData = pNewSolutionStepsData;
    }

    ///@}
    ///@name Inquiry
    ///@{

    bool IsFixed() const
    {
        return mIsFixed;
    }


    bool IsFree() const
    {
        return !mIsFixed;
    }

    ///@}
    ///@name Input and output
    ///@{


    /// Turn back information as a string.
    virtual std::string Info() const
    {
        std::stringstream buffer;


        if(IsFixed())
            buffer << "Fix " << GetVariable().Name() << " degree of freedom";
        else
            buffer << "Free " << GetVariable().Name() << " degree of freedom";


        return buffer.str();
    }



    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << Info();
    }


    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {
        rOStream << "    Variable               : " << GetVariable().Name() << std::endl;
        rOStream << "    Reaction               : " << GetReaction().Name() << std::endl;
        if(IsFixed())
            rOStream << "    IsFixed                : True" << std::endl;
        else
            rOStream << "    IsFixed                : False" << std::endl;
        rOStream << "    Equation Id            : " << mEquationId << std::endl;
        rOStream << "    Local Equation Id            : " << mLocalEquationId << std::endl;
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

    static const Variable<TDataType> msNone;


    ///@}
    ///@name Member Variables
    ///@{


    /** True is is fixed */
    bool mIsFixed;

    /** Equation identificator of the degree of freedom */
    EquationIdType mEquationId;
    EquationIdType mLocalEquationId; // this is used for BDDC and FETI, also for the unassembled matrix format

    /** A pointer to solutionsteps data stored in node which is corresponded to this dof */
    SolutionStepsDataContainerType* mpSolutionStepsData;


    /** Variable of the degree of freedom.
     */
    const VariableData* mpVariable;

    /** Reaction variable for this degree of freedom.
     */
    const VariableData* mpReaction;


    int mVariableType;

    int mReactionType;

    ///@}
    ///@name Private Operators
    ///@{
#define KRATOS_MAKE_DOF_TRAIT(id) \
        case id : \
                return rData.GetValue(static_cast<


#define KRATOS_END_DOF_TRAIT(id) \
 const&>(ThisVariable), SolutionStepIndex);

    TDataType& GetReference(VariableData const& ThisVariable, VariablesListDataValueContainer<TDataType>& rData, IndexType SolutionStepIndex, int ThisId)
    {
        switch(ThisId)
        {
            KRATOS_DOF_TRAITS
        }
        KRATOS_ERROR << "Not supported type for Dof" << std::endl;
    }

    TDataType const& GetReference(VariableData const& ThisVariable, VariablesListDataValueContainer<TDataType> const& rData, IndexType SolutionStepIndex, int ThisId) const
    {
        switch(ThisId)
        {
            KRATOS_DOF_TRAITS
        }
        KRATOS_ERROR << "Not supported type for Dof" << std::endl;
    }

    ///@}
    ///@name Serialization
    ///@{

    friend class Serializer;

    virtual void save(Serializer& rSerializer) const
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, IndexedObject );
        rSerializer.save("Is Fixed", mIsFixed);
        rSerializer.save("Equation Id", mEquationId);
        rSerializer.save("Local Equation Id", mLocalEquationId);
        rSerializer.save("Solution Steps Data", mpSolutionStepsData);
        rSerializer.save("Variable", mpVariable->Name());
        rSerializer.save("Reaction", mpReaction->Name());
        rSerializer.save("Variable Type", mVariableType);
        rSerializer.save("Reaction Type", mReactionType);
    }

    virtual void load(Serializer& rSerializer)
    {
        std::string name;
        KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, IndexedObject );
        rSerializer.load("Is Fixed", mIsFixed);
        rSerializer.load("Equation Id", mEquationId);
        rSerializer.load("Local Equation Id", mLocalEquationId);
        rSerializer.load("Solution Steps Data", mpSolutionStepsData);
        rSerializer.load("Variable", name);
        mpVariable=KratosComponents<VariableData>::pGet(name);
        rSerializer.load("Reaction", name);
        if(name == "NONE")
            mpReaction = &msNone;
        else
            mpReaction=KratosComponents<VariableData>::pGet(name);
        rSerializer.load("Variable Type", mVariableType);
        rSerializer.load("Reaction Type", mReactionType);
    }
    ///@}
    ///@name Private Operations
    ///@{

    ///@}
    ///@name Private  Access
    ///@{

    ///@}
    ///@name Un accessible methods
    ///@{

    ///@}

}; // Class Dof
template<class TDataType> const Variable<TDataType> Dof<TDataType>::msNone("NONE");

///@}
///@name Type Definitions
///@{

///@}
///@name Input and output
///@{

/// input stream function
template<class TDataType>
inline std::istream& operator >> (std::istream& rIStream,
                                  Dof<TDataType>& rThis)
{
    return rIStream;
}

/// output stream function
template<class TDataType>
inline std::ostream& operator << (std::ostream& rOStream,
                                  const Dof<TDataType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}
///@}
///@name Operations
///@{


/// Greater than operator
template<class TDataType>
inline bool operator > ( Dof<TDataType> const& First,
                         Dof<TDataType> const& Second)
{
    if(First.Id() == Second.Id())
        return (First.GetVariable().Key() > Second.GetVariable().Key());

    return (First.Id() > Second.Id());
}

/// Less than operator
template<class TDataType>
inline bool operator < ( Dof<TDataType> const& First,
                         Dof<TDataType> const& Second)
{
    if(First.Id() == Second.Id())
        return (First.GetVariable().Key() < Second.GetVariable().Key());

    return (First.Id() < Second.Id());
}

/// Greater equal operator
template<class TDataType>
inline bool operator >= ( Dof<TDataType> const& First,
                          Dof<TDataType> const& Second)
{
    if(First.Id() == Second.Id())
        return (First.GetVariable().Key() >= Second.GetVariable().Key());

    return (First.Id() > Second.Id());
}

/// Less equal operator
template<class TDataType>
inline bool operator <= ( Dof<TDataType> const& First,
                          Dof<TDataType> const& Second)
{
    if(First.Id() == Second.Id())
        return (First.GetVariable().Key() <= Second.GetVariable().Key());

    return (First.Id() < Second.Id());
}

/// Equal operator
template<class TDataType>
inline bool operator == ( Dof<TDataType> const& First,
                          Dof<TDataType> const& Second)
{
    return ((First.Id() == Second.Id()) && (First.GetVariable().Key() == Second.GetVariable().Key()));
}

///@}

}  // namespace Kratos.

#undef KRATOS_DOF_TRAITS
#undef KRATOS_MAKE_DOF_TRAIT
#undef KRATOS_END_DOF_TRAIT

#endif // KRATOS_DOF_H_INCLUDED  defined
