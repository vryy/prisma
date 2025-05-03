//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//



#if !defined(KRATOS_SCHEME )
#define  KRATOS_SCHEME


// System includes

// External includes

// Project includes
#include "includes/define.h"
#include "includes/model_part.h"
#include "utilities/openmp_utils.h"

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
 * @class Scheme
 * @ingroup KratosCore
 * @brief This class provides the implementation of the basic tasks that are needed by the solution strategy.
 * @details It is intended to be the place for tailoring the solution strategies to problem specific tasks.
 * @tparam TSparseSpace The sparse space considered
 * @tparam TDenseSpace The dense space considered
 * @author Riccardo Rossi
 */
template<class TSparseSpace,
         class TDenseSpace, //= DenseSpace<double>
         class TModelPartType = ModelPart
         >
class Scheme
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of Scheme
    KRATOS_CLASS_POINTER_DEFINITION(Scheme);

    typedef typename TSparseSpace::DataType TDataType;
    typedef typename TSparseSpace::MatrixType TSystemMatrixType;
    typedef typename TSparseSpace::VectorType TSystemVectorType;

    typedef typename TDenseSpace::MatrixType LocalSystemMatrixType;
    typedef typename TDenseSpace::VectorType LocalSystemVectorType;

    typedef TModelPartType ModelPartType;

    typedef typename ModelPartType::DofType DofType;
    typedef typename ModelPartType::DofsArrayType DofsArrayType;
    typedef typename DofsArrayType::iterator DofIterator;
    typedef typename DofsArrayType::const_iterator DofConstantIterator;

    typedef typename ModelPartType::ElementType ElementType;
    typedef typename ModelPartType::ConditionType ConditionType;
    typedef typename ModelPartType::ElementsContainerType ElementsArrayType;
    typedef typename ModelPartType::ConditionsContainerType ConditionsArrayType;

    ///@}
    ///@name Life Cycle
    ///@{

    /**
     * @brief Default Constructor
     * @details Initializes the flags
     */
    Scheme()
    {
        mSchemeIsInitialized = false;
        mElementsAreInitialized = false;
        mConditionsAreInitialized = false;
    }


    /** Copy Constructor.
     */
    Scheme(Scheme& rOther)
    : mSchemeIsInitialized(rOther.mSchemeIsInitialized)
    , mElementsAreInitialized(rOther.mElementsAreInitialized)
    , mConditionsAreInitialized(rOther.mConditionsAreInitialized)
    {
    }

    /** Destructor.
     */
    virtual ~Scheme()
    {
    }

    ///@}
    ///@name Operators
    ///@{

    ///@}
    ///@name Operations
    ///@{


    /**
     * @brief Clone method
     * @return The pointer of the cloned scheme
     */
    virtual Pointer Clone()
    {
        return Pointer( new Scheme(*this) );
    }

    /**
     * @brief This is the place to initialize the Scheme.
     * @details This is intended to be called just once when the strategy is initialized
     * @param rModelPart The model part of the problem to solve
     */
    virtual void Initialize(ModelPartType& rModelPart)
    {
        KRATOS_TRY
        mSchemeIsInitialized = true;
        KRATOS_CATCH("")
    }

    /**
     * @brief This method returns if the scheme is initialized
     * @return True if initialized, false otherwise
     */
    bool SchemeIsInitialized()
    {
        return mSchemeIsInitialized;
    }

    /**
     * @brief This method sets if the elements have been initialized or not (true by default)
     * @param ElementsAreInitializedFlag If the flag must be set to true or false
     */
    void SetSchemeIsInitialized(bool SchemeIsInitializedFlag = true)
    {
        mSchemeIsInitialized = SchemeIsInitializedFlag;
    }

    /**
     * @brief This method returns if the elements are initialized
     * @return True if initialized, false otherwise
     */
    bool ElementsAreInitialized()
    {
        return mElementsAreInitialized;
    }

    /**
     * @brief This method sets if the elements have been initialized or not (true by default)
     * @param ElementsAreInitializedFlag If the flag must be set to true or false
     */
    void SetElementsAreInitialized(bool ElementsAreInitializedFlag = true)
    {
        mElementsAreInitialized = ElementsAreInitializedFlag;
    }

    /**
     * @brief This method returns if the conditions are initialized
     * @return True if initialized, false otherwise
     */
    bool ConditionsAreInitialized()
    {
        return mConditionsAreInitialized;
    }

    /**
     * @brief This method sets if the conditions have been initialized or not (true by default)
     * @param ConditionsAreInitializedFlag If the flag must be set to true or false
     */
    void SetConditionsAreInitialized(bool ConditionsAreInitializedFlag = true)
    {
        mConditionsAreInitialized = ConditionsAreInitializedFlag;
    }

    /**
     * @brief This is the place to initialize the elements.
     * @details This is intended to be called just once when the strategy is initialized
     * @param rModelPart The model part of the problem to solve
     */
    virtual void InitializeElements(ModelPartType& rModelPart)
    {
        KRATOS_TRY

        int NumThreads = OpenMPUtils::GetNumThreads();
        OpenMPUtils::PartitionVector ElementPartition;
        OpenMPUtils::DivideInPartitions(rModelPart.Elements().size(), NumThreads, ElementPartition);
        const ProcessInfo& CurrentProcessInfo = rModelPart.GetProcessInfo();

        #pragma omp parallel
        {
            int k = OpenMPUtils::ThisThread();
            typename ElementsArrayType::iterator ElemBegin = rModelPart.Elements().begin() + ElementPartition[k];
            typename ElementsArrayType::iterator ElemEnd = rModelPart.Elements().begin() + ElementPartition[k + 1];

            for (typename ElementsArrayType::iterator itElem = ElemBegin; itElem != ElemEnd; itElem++)
            {
                itElem->Initialize(CurrentProcessInfo); //function to initialize the element
            }
        }

        mElementsAreInitialized = true;

        KRATOS_CATCH("")
    }

    /**
     * @brief This is the place to initialize the conditions.
     * @details This is intended to be called just once when the strategy is initialized
     * @param rModelPart The model part of the problem to solve
     */
    virtual void InitializeConditions(ModelPartType& rModelPart)
    {
        KRATOS_TRY

        if(mElementsAreInitialized==false)
            KRATOS_ERROR << "Before initilizing Conditions, initialize Elements FIRST";

        int NumThreads = OpenMPUtils::GetNumThreads();
        OpenMPUtils::PartitionVector ConditionPartition;
        OpenMPUtils::DivideInPartitions(rModelPart.Conditions().size(), NumThreads, ConditionPartition);
        const ProcessInfo& CurrentProcessInfo = rModelPart.GetProcessInfo();

        #pragma omp parallel
        {
            int k = OpenMPUtils::ThisThread();
            typename ConditionsArrayType::iterator CondBegin = rModelPart.Conditions().begin() + ConditionPartition[k];
            typename ConditionsArrayType::iterator CondEnd = rModelPart.Conditions().begin() + ConditionPartition[k + 1];

            for (typename ConditionsArrayType::iterator itCond = CondBegin; itCond != CondEnd; itCond++)
            {
                itCond->Initialize(CurrentProcessInfo); //function to initialize the condition
            }

        }

        mConditionsAreInitialized = true;

        KRATOS_CATCH("")
    }

    /**
     * @brief Function called once at the beginning of each solution step.
     * @details The basic operations to be carried in there are the following:
     * - managing variables to be kept constant over the time step (for example time-Scheme constants depending on the actual time step)
     * @param rModelPart The model part of the problem to solve
     * @param A LHS matrix
     * @param Dx Incremental update of primary variables
     * @param b RHS Vector
     */
    virtual void InitializeSolutionStep(
        ModelPartType& rModelPart,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b
    )
    {
        KRATOS_TRY

        //initialize solution step for all of the elements
        ElementsArrayType& pElements = rModelPart.Elements();
        const ProcessInfo& CurrentProcessInfo = rModelPart.GetProcessInfo();

        for (typename ElementsArrayType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            (it) -> InitializeSolutionStep(CurrentProcessInfo);
        }

        ConditionsArrayType& pConditions = rModelPart.Conditions();
        for (typename ConditionsArrayType::iterator it = pConditions.begin(); it != pConditions.end(); ++it)
        {
            (it) -> InitializeSolutionStep(CurrentProcessInfo);
        }

        KRATOS_CATCH("")
    }

    /**
     * @brief Function called once at the end of a solution step, after convergence is reached if an iterative process is needed
     * @param rModelPart The model part of the problem to solve
     * @param A LHS matrix
     * @param Dx Incremental update of primary variables
     * @param b RHS Vector
     */
    virtual void FinalizeSolutionStep(
        ModelPartType& rModelPart,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b)
    {
        KRATOS_TRY

        // Finalizes solution step for all of the elements, conditions and constraints
        ElementsArrayType& rElements = rModelPart.Elements();
        const ProcessInfo& CurrentProcessInfo = rModelPart.GetProcessInfo();

        int NumThreads = OpenMPUtils::GetNumThreads();
        OpenMPUtils::PartitionVector ElementPartition;
        OpenMPUtils::DivideInPartitions(rElements.size(), NumThreads, ElementPartition);

        #pragma omp parallel
        {
            int k = OpenMPUtils::ThisThread();

            typename ElementsArrayType::iterator ElementsBegin = rElements.begin() + ElementPartition[k];
            typename ElementsArrayType::iterator ElementsEnd = rElements.begin() + ElementPartition[k + 1];

            for (typename ElementsArrayType::iterator itElem = ElementsBegin; itElem != ElementsEnd; itElem++)
            {
                itElem->FinalizeSolutionStep(CurrentProcessInfo);
            }
        }

        ConditionsArrayType& rConditions = rModelPart.Conditions();

        OpenMPUtils::PartitionVector ConditionPartition;
        OpenMPUtils::DivideInPartitions(rConditions.size(), NumThreads, ConditionPartition);

        #pragma omp parallel
        {
            int k = OpenMPUtils::ThisThread();

            typename ConditionsArrayType::iterator ConditionsBegin = rConditions.begin() + ConditionPartition[k];
            typename ConditionsArrayType::iterator ConditionsEnd = rConditions.begin() + ConditionPartition[k + 1];

            for (typename ConditionsArrayType::iterator itCond = ConditionsBegin; itCond != ConditionsEnd; itCond++)
            {
                itCond->FinalizeSolutionStep(CurrentProcessInfo);
            }
        }

        KRATOS_CATCH("")
    }

    /**
     * @brief unction to be called when it is needed to initialize an iteration. It is designed to be called at the beginning of each non linear iteration
     * @note Take care: the elemental function with the same name is NOT called here.
     * @warning Must be defined in derived classes
     * @details The function is called in the builder for memory efficiency
     * @param rModelPart The model part of the problem to solve
     * @param A LHS matrix
     * @param Dx Incremental update of primary variables
     * @param b RHS Vector
     */
    virtual void InitializeNonLinIteration(
        ModelPartType& rModelPart,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b
        )
    {
        KRATOS_TRY

        ElementsArrayType& pElements = rModelPart.Elements();
        const ProcessInfo& CurrentProcessInfo = rModelPart.GetProcessInfo();

        for (typename ElementsArrayType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            (it) -> InitializeNonLinearIteration(CurrentProcessInfo);
        }

        ConditionsArrayType& pConditions = rModelPart.Conditions();
        for (typename ConditionsArrayType::iterator it = pConditions.begin(); it != pConditions.end(); ++it)
        {
            (it) -> InitializeNonLinearIteration(CurrentProcessInfo);
        }

        KRATOS_CATCH("")
    }

    /**
     * @brief Function to be called when it is needed to finalize an iteration. It is designed to be called at the end of each non linear iteration
     * @param rModelPart The model part of the problem to solve
     * @param A LHS matrix
     * @param Dx Incremental update of primary variables
     * @param b RHS Vector
     */
    virtual void FinalizeNonLinIteration(
        ModelPartType& rModelPart,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b
        )
    {
        KRATOS_TRY

        ElementsArrayType& pElements = rModelPart.Elements();
        const ProcessInfo& CurrentProcessInfo = rModelPart.GetProcessInfo();

        for (typename ElementsArrayType::iterator it = pElements.begin(); it != pElements.end(); ++it)
        {
            (it) -> FinalizeNonLinearIteration(CurrentProcessInfo);
        }

        ConditionsArrayType& pConditions = rModelPart.Conditions();
        for (typename ConditionsArrayType::iterator it = pConditions.begin(); it != pConditions.end(); ++it)
        {
            (it) -> FinalizeNonLinearIteration(CurrentProcessInfo);
        }

        KRATOS_CATCH("")
    }

    /**
     * @brief Performing the prediction of the solution.
     * @warning Must be defined in derived classes
     * @param rModelPart The model part of the problem to solve
     * @param A LHS matrix
     * @param Dx Incremental update of primary variables
     * @param b RHS Vector
     */
    virtual void Predict(
        ModelPartType& rModelPart,
        DofsArrayType& rDofSet,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b
    )
    {
        KRATOS_TRY
        KRATOS_CATCH("")
    }

    /**
     * @brief Performing the update of the solution.
     * @warning Must be defined in derived classes
     * @param rModelPart The model part of the problem to solve
     * @param rDofSet Set of all primary variables
     * @param A LHS matrix
     * @param Dx Incremental update of primary variables
     * @param b RHS Vector
     */
    virtual void Update(
        ModelPartType& rModelPart,
        DofsArrayType& rDofSet,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b
        )
    {
        KRATOS_TRY
        KRATOS_CATCH("")
    }

    /**
     * @brief Functions to be called to prepare the data needed for the output of results.
     * @warning Must be defined in derived classes
     * @param rModelPart The model part of the problem to solve
     * @param rDofSet Set of all primary variables
     * @param A LHS matrix
     * @param Dx Incremental update of primary variables
     * @param b RHS Vector
     */
    virtual void CalculateOutputData(
        ModelPartType& rModelPart,
        DofsArrayType& rDofSet,
        TSystemMatrixType& A,
        TSystemVectorType& Dx,
        TSystemVectorType& b
        )
    {
        KRATOS_TRY
        KRATOS_CATCH("")
    }

    /**
     * @brief Functions that cleans the results data.
     * @warning Must be implemented in the derived classes
     */
    virtual void CleanOutputData()
    {
        KRATOS_TRY
        KRATOS_CATCH("")
    }

    /**
     * @brief This function is intended to be called at the end of the solution step to clean up memory storage not needed after the end of the solution step
     * @warning Must be implemented in the derived classes
     */
    virtual void Clean()
    {
        KRATOS_TRY
        KRATOS_CATCH("")
    }

    /**
    function to clean up "element" scratch space after each element is built.
     */
    virtual void CleanMemory(ElementType& rCurrentElement)
    {
        rCurrentElement.CleanMemory();
    }

    /**
    function to clean up "condition" scratch space after each condition is built.
     */
    virtual void CleanMemory(ConditionType& rCurrentCondition)
    {
        rCurrentCondition.CleanMemory();
    }

    /**
     * @brief Liberate internal storage.
     * @warning Must be implemented in the derived classes
     */
    virtual void Clear()
    {
        KRATOS_TRY
        KRATOS_CATCH("")
    }

    /**
     * @brief This function is designed to be called once to perform all the checks needed
     * on the input provided. Checks can be "expensive" as the function is designed
     * to catch user's errors.
     * @details Checks can be "expensive" as the function is designed
     * @param rModelPart The model part of the problem to solve
     * @return 0 all OK, 1 otherwise
     */
    virtual int Check(const ModelPartType& rModelPart) const
    {
        KRATOS_TRY

        for(typename ElementsArrayType::const_iterator it = rModelPart.ElementsBegin();
                it != rModelPart.ElementsEnd(); ++it)
        {
            it->Check(rModelPart.GetProcessInfo());
        }

        for(typename ConditionsArrayType::const_iterator it = rModelPart.ConditionsBegin();
                it != rModelPart.ConditionsEnd(); ++it)
        {
            it->Check(rModelPart.GetProcessInfo());
        }

        return 0;

        KRATOS_CATCH("");
    }

    /**
     * @brief This function is designed to be called in the builder and solver to introduce the selected time integration scheme.
     * @details It "asks" the matrix needed to the element and performs the operations needed to introduce the selected time integration scheme. This function calculates at the same time the contribution to the LHS and to the RHS of the system
     * @param rElement The element to compute
     * @param LHS_Contribution The LHS matrix contribution
     * @param RHS_Contribution The RHS vector contribution
     * @param rEquationIdVector The ID's of the element degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void CalculateSystemContributions(
        ElementType& rElement,
        LocalSystemMatrixType& LHS_Contribution,
        LocalSystemVectorType& RHS_Contribution,
        typename ElementType::EquationIdVectorType& rEquationIdVector,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
    }

    /**
     * @brief Functions totally analogous to the precedent but applied to the "condition" objects
     * @param rCondition The condition to compute
     * @param LHS_Contribution The LHS matrix contribution
     * @param RHS_Contribution The RHS vector contribution
     * @param rEquationIdVector The ID's of the condition degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void CalculateSystemContributions(
        ConditionType& rCondition,
        LocalSystemMatrixType& LHS_Contribution,
        LocalSystemVectorType& RHS_Contribution,
        typename ElementType::EquationIdVectorType& rEquationIdVector,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
    }

    /**
     * @brief This function is designed to calculate just the RHS contribution
     * @param rElement The element to compute
     * @param RHS_Contribution The RHS vector contribution
     * @param rEquationIdVector The ID's of the element degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void CalculateRHSContribution(
        ElementType& rElement,
        LocalSystemVectorType& RHS_Contribution,
        typename ElementType::EquationIdVectorType& rEquationIdVector,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
    }

    /**
     * @brief Functions totally analogous to the precedent but applied to the "condition" objects
     * @param rCondition The condition to compute
     * @param RHS_Contribution The RHS vector contribution
     * @param rEquationIdVector The ID's of the condition degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void CalculateRHSContribution(
        ConditionType& rCondition,
        LocalSystemVectorType& RHS_Contribution,
        typename ElementType::EquationIdVectorType& rEquationIdVector,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
    }

    /**
     * @brief This function is designed to calculate just the LHS contribution
     * @param rElement The element to compute
     * @param LHS_Contribution The RHS vector contribution
     * @param rEquationIdVector The ID's of the element degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void CalculateLHSContribution(
        ElementType& rElement,
        LocalSystemMatrixType& LHS_Contribution,
        typename ElementType::EquationIdVectorType& rEquationIdVector,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
    }

    /**
     * @brief Functions totally analogous to the precedent but applied to the "condition" objects
     * @param rCondition The condition to compute
     * @param LHS_Contribution The RHS vector contribution
     * @param rEquationIdVector The ID's of the condition degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void CalculateLHSContribution(
        ConditionType& rCondition,
        LocalSystemMatrixType& LHS_Contribution,
        typename ElementType::EquationIdVectorType& rEquationIdVector,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
    }

    /**
     * @brief This method gets the eqaution id corresponding to the current element
     * @param rElement The element to compute
     * @param rEquationId The ID's of the element degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void EquationId(
        const ElementType& rElement,
        typename ElementType::EquationIdVectorType& rEquationId,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
        rElement.EquationIdVector(rEquationId, rCurrentProcessInfo);
    }

    /**
     * @brief Functions totally analogous to the precedent but applied to the "condition" objects
     * @param rCondition The condition to compute
     * @param rEquationId The ID's of the condition degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void EquationId(
        const ConditionType& rCondition,
        typename ElementType::EquationIdVectorType& rEquationId,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
        rCondition.EquationIdVector(rEquationId, rCurrentProcessInfo);
    }

    /**
     * @brief Function that returns the list of Degrees of freedom to be assembled in the system for a Given element
     * @param pCurrentElement The element to compute
     * @param rDofList The list containing the element degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void GetDofList(
        const ElementType& rElement,
        typename ElementType::DofsVectorType& rDofList,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
        rElement.GetDofList(rDofList, rCurrentProcessInfo);
    }

    /**
     * @brief Function that returns the list of Degrees of freedom to be assembled in the system for a Given condition
     * @param rCondition The condition to compute
     * @param rDofList The list containing the condition degrees of freedom
     * @param rCurrentProcessInfo The current process info instance
     */
    virtual void GetDofList(
        const ConditionType& rCondition,
        typename ElementType::DofsVectorType& rDofList,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
        rCondition.GetDofList(rDofList, rCurrentProcessInfo);
    }

    ///@}
    ///@name Access
    ///@{

    ///@}
    ///@name Inquiry
    ///@{

    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    virtual std::string Info() const
    {
        return "Scheme";
    }

    /// Print information about this object.
    virtual void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << Info();
    }

    /// Print object's data.
    virtual void PrintData(std::ostream& rOStream) const
    {
        rOStream << Info();
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

    bool mSchemeIsInitialized;      /// Flag to be used in controlling if the Scheme has been initialized or not
    bool mElementsAreInitialized;   /// Flag taking in account if the elements were initialized correctly or not
    bool mConditionsAreInitialized; /// Flag taking in account if the conditions were initialized correctly or not

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

    ///@}
    ///@name Private Operators
    ///@{

    ///@}
    ///@name Private Operations
    ///@{

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

}; // Class Scheme

///@name Input and output
///@{

/// input stream function
template<class TSparseSpace, class TDenseSpace, class TModelPartType>
inline std::istream& operator >> (std::istream& rIStream, Scheme<TSparseSpace, TDenseSpace, TModelPartType>& rThis)
{
    return rIStream;
}

/// output stream function
template<class TSparseSpace, class TDenseSpace, class TModelPartType>
inline std::ostream& operator << (std::ostream& rOStream, const Scheme<TSparseSpace, TDenseSpace, TModelPartType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

} // namespace Kratos.

#endif /* KRATOS_SCHEME  defined */
