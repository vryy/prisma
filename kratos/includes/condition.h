//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//

#if !defined(KRATOS_CONDITION_H_INCLUDED )
#define  KRATOS_CONDITION_H_INCLUDED

// System includes

// External includes

// Project includes
#include "includes/properties.h"
#include "includes/process_info.h"
#include "includes/geometrical_object.h"
#include "includes/node.h"
#include "containers/vector_map.h"


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

/// Base class for all Conditions.

/**
 * This is the base class for all conditions used in KRATOS
 * Conditions inherited from this class have to reimplement
 * all public functions that are needed to perform their designated
 * tasks. Due to a dummy implementation of every function though,
 * not all of them have to be implemented if they are not needed for
 * the actual problem
 */
template<class TNodeType>
class KRATOS_API(KRATOS_CORE) BaseCondition : public GeometricalObject<TNodeType>
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of BaseCondition
    KRATOS_CLASS_POINTER_DEFINITION(BaseCondition);

    ///base type: an GeometricalObject that automatically has a unique number
    typedef GeometricalObject<TNodeType> BaseType;

    ///definition of this class of condition type
    typedef BaseCondition<TNodeType> ConditionType;

    ///definition of this entity type
    typedef BaseCondition<TNodeType> EntityType;

    ///definition of node type (default is: Node<3>)
    typedef typename BaseType::NodeType NodeType;

    /**
     * Properties are used to store any parameters
     * related to the constitutive law
     */
    typedef Properties PropertiesType;

    ///definition of the geometry type with given NodeType
    typedef typename BaseType::GeometryType GeometryType;

    ///definition of nodes container type, redefined from GeometryType
    typedef typename GeometryType::PointsArrayType NodesArrayType;

    typedef typename BaseType::IndexType IndexType;

    typedef typename BaseType::SizeType SizeType;

    typedef typename NodeType::DofType DofType;

    typedef typename DofType::DataType DataType;

    typedef typename DataTypeToValueType<DataType>::value_type ValueType;

    typedef typename MatrixVectorTypeSelector<DataType>::VectorType VectorType;

    typedef typename MatrixVectorTypeSelector<DataType>::ZeroVectorType ZeroVectorType;

    typedef typename MatrixVectorTypeSelector<DataType>::MatrixType MatrixType;

    typedef typename MatrixVectorTypeSelector<DataType>::ZeroMatrixType ZeroMatrixType;

    typedef typename MatrixVectorTypeSelector<DataType>::IdentityMatrixType IdentityMatrixType;

    typedef std::vector<IndexType> EquationIdVectorType;

    typedef std::vector<typename DofType::Pointer> DofsVectorType;

    typedef PointerVectorSet<DofType, IndexedObject> DofsArrayType;

    typedef VectorMap<IndexType, DataValueContainer> SolutionStepsConditionalDataContainerType;

    ///Type definition for integration methods
    typedef GeometryData::IntegrationMethod IntegrationMethod;

    typedef GeometryData GeometryDataType;

    ///@}
    ///@name Life Cycle
    ///@{

    /**
     * CONDITIONS inherited from this class have to implement next
     * constructors, copy constructors and destructor: MANDATORY
     */

    /**
     * Constructor.
     */
    BaseCondition(IndexType NewId = 0)
        : BaseType(NewId)
        , mpProperties(new PropertiesType)
    {
    }

    /**
     * Constructor using an array of nodes
     */
    BaseCondition(IndexType NewId, const NodesArrayType& ThisNodes)
        : BaseType(NewId, typename GeometryType::Pointer(new GeometryType(ThisNodes)))
        , mpProperties(new PropertiesType)
    {
    }

    /**
     * Constructor using Geometry
     */
    BaseCondition(IndexType NewId, typename GeometryType::Pointer pGeometry)
        : BaseType(NewId,pGeometry)
        , mpProperties(new PropertiesType)
    {
    }

    /**
     * Constructor using Properties
     */
    BaseCondition(IndexType NewId, typename GeometryType::Pointer pGeometry, PropertiesType::Pointer pProperties)
        : BaseType(NewId,pGeometry)
        , mpProperties(pProperties)
    {
    }

    /// Copy constructor.
    BaseCondition(BaseCondition const& rOther)
        : BaseType(rOther)
        , mpProperties(rOther.mpProperties)
        , mData(rOther.mData)
    {
    }

    /// Destructor.
    ~BaseCondition() override
    {
    }

    ///@}
    ///@name Operators
    ///@{

    /**
     * CONDITIONS inherited from this class have to implement next
     * assignment operator: MANDATORY
     */

    /// Assignment operator.
    BaseCondition & operator=(BaseCondition const& rOther)
    {
        BaseType::operator=(rOther);
        mpProperties = rOther.mpProperties;

        return *this;
    }

    ///@}
    ///@name Informations
    ///@{

    /** Dimensional space of the condition geometry
    @return SizeType, working space dimension of this geometry.
    */
    virtual SizeType WorkingSpaceDimension() const
    {
        return this->pGetGeometry()->WorkingSpaceDimension();
    }

    ///@}
    ///@name Operations
    ///@{

    /**
     * CONDITIONS inherited from this class have to implement next
     * Create and Clone methods: MANDATORY
     */

    /**
     * @brief It creates a new condition pointer
     * @param NewId the ID of the new condition
     * @param ThisNodes the nodes of the new condition
     * @param pProperties the properties assigned to the new condition
     * @return a Pointer to the new condition
     */
    virtual Pointer Create(IndexType NewId, NodesArrayType const& ThisNodes,
               PropertiesType::Pointer pProperties) const
    {
        KRATOS_ERROR << "Please implement the First Create method in your derived Condition " << Info() << std::endl;
    }

    /**
     * @brief It creates a new condition pointer
     * @param NewId the ID of the new condition
     * @param pGeom the geometry to be employed
     * @param pProperties the properties assigned to the new condition
     * @return a Pointer to the new condition
     */
    virtual Pointer Create(IndexType NewId,
                           typename GeometryType::Pointer pGeom,
                           PropertiesType::Pointer pProperties) const
    {
        KRATOS_ERROR << "Please implement the Second Create method in your derived Condition " << Info() << std::endl;
    }

    /**
     * creates a new condition pointer based on a list of geometries
     * @param NewId: the ID of the new condition
     * @param pGeom: the geometry to be employed
     * @param pProperties: the properties assigned to the new condition
     * @return a Pointer to the new condition
     */
    virtual Pointer Create(IndexType NewId,
                           std::vector<typename GeometryType::Pointer> pGeom,
                           PropertiesType::Pointer pProperties) const
    {
        KRATOS_ERROR << "Please implement the Third Create method in your derived Condition " << Info() << std::endl;
    }

    /**
     * @brief It creates a new condition pointer and clones the previous condition data
     * @param NewId the ID of the new condition
     * @param ThisNodes the nodes of the new condition
     * @param pProperties the properties assigned to the new condition
     * @return a Pointer to the new condition
     */
    virtual Pointer Clone (IndexType NewId, NodesArrayType const& ThisNodes) const
    {
        KRATOS_ERROR << "Please implement the Clone method in your derived Condition " << Info() << std::endl;
    }

    /**
     * CONDITIONS inherited from this class have to implement next
     * EquationIdVector and GetDofList methods: MANDATORY
     */

    /**
     * this determines the condition equation ID vector for all condition
     * DOFs
     * @param rResult the condition equation ID vector
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void EquationIdVector(EquationIdVectorType& rResult,
                                  const ProcessInfo& rCurrentProcessInfo) const
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

#ifdef KRATOS_NONSQUARE_SUPPORT
    /**
     * this determines the row condition equation ID vector for all condition DOFs
     * By default, the equation ID vector of the squared version is returned
     * @param rResult the condition equation ID vector
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void RowEquationIdVector(EquationIdVectorType& rResult,
                                     const ProcessInfo& rCurrentProcessInfo) const
    {
        this->EquationIdVector(rResult, rCurrentProcessInfo);
    }

    /**
     * this determines the column condition equation ID vector for all condition DOFs
     * By default, the equation ID vector of the squared version is returned
     * @param rResult the condition equation ID vector
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void ColumnEquationIdVector(EquationIdVectorType& rResult,
                                        const ProcessInfo& rCurrentProcessInfo) const
    {
        this->EquationIdVector(rResult, rCurrentProcessInfo);
    }
#endif

    /**
     * determines the condition list of DOFs
     * @param ConditionDofList the list of DOFs
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void GetDofList(DofsVectorType& rConditionDofList,
                            const ProcessInfo& rCurrentProcessInfo) const
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

#ifdef KRATOS_NONSQUARE_SUPPORT
    /**
     * determines the row condition list of DOFs
     * By default, dof list of the squared version is returned
     * @param ConditionDofList the list of DOFs
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void GetRowDofList(DofsVectorType& rConditionDofList,
                               const ProcessInfo& rCurrentProcessInfo) const
    {
        this->GetDofList(rConditionDofList, rCurrentProcessInfo);
    }

    /**
     * determines the column condition list of DOFs
     * By default, dof list of the squared version is returned
     * @param ConditionDofList the list of DOFs
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void GetColumnDofList(DofsVectorType& rConditionDofList,
                                  const ProcessInfo& rCurrentProcessInfo) const
    {
        this->GetDofList(rConditionDofList, rCurrentProcessInfo);
    }
#endif

    /**
     * returns the used integration method. In the general case this is the
     * default integration method of the used geometry. I an other integration
     * method is used the method has to be overwritten within the condition
     * @return default integration method of the used Geometry
     * this method is: OPTIONAL ( is recommended to reimplement it in the derived class )
     */
    virtual IntegrationMethod GetIntegrationMethod() const
    {
        return this->pGetGeometry()->GetDefaultIntegrationMethod();
    }

    /**
     * CONDITIONS inherited from this class must implement this methods
     * if they need the values of the time derivatives of any of the dof
     * set by the condition. If the derivatives do not exist can set to zero
     * these methods are: MANDATORY ( when compatibility with dynamics is required )
     */

    /**
     * Getting method to obtain the variable which defines the degrees of freedom
     */
    virtual void GetValuesVector(VectorType& values, int Step = 0) const
    {
    }

    /**
     * Getting method to obtain the time derivative of variable which defines the degrees of freedom
     */
    virtual void GetFirstDerivativesVector(VectorType& values, int Step = 0) const
    {
    }

    /**
     * Getting method to obtain the second time derivative of variable which defines the degrees of freedom
     */
    virtual void GetSecondDerivativesVector(VectorType& values, int Step = 0) const
    {
    }

    /**
     * CONDITIONS inherited from this class must implement next methods
     * Initialize, ResetConstitutiveLaw
     * if the condition needs to perform any operation before any calculation is done
     * reset material and constitutive parameters
     * or clean memory deleting obsolete variables
     * these methods are: OPTIONAL
     */

    /**
     * is called to initialize the condition
     * if the condition needs to perform any operation before any calculation is done
     * the condition variables will be initialized and set using this method
     */
    virtual void Initialize(const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * is called to reset the constitutive law parameters and the material properties
     * the condition variables will be changed and reset using this method
     */
    virtual void ResetConstitutiveLaw()
    {
    }

    /**
     * is called to rewind the constitutive law parameters and the material properties
     * REMARK: EXPERIMENTAL METHOD
     */
    virtual void RewindConstitutiveLaw()
    {
    }

    /**
     * deletes all obsolete data from memory
     */
    virtual void CleanMemory()
    {
    }

    /**
     * CONDITIONS inherited from this class must implement next methods
     * InitializeSolutionStep, FinalizeSolutionStep,
     * InitializeNonLinearIteration, FinalizeNonLinearIteration
     * if the condition needs to perform any operation before and after the solution step
     * if the condition needs to perform any operation before and after the solution iteration
     * these methods are: OPTIONAL
     */

    /**
     * this is called in the beginning of each solution step
     */
    virtual void InitializeSolutionStep(const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * this is called for non-linear analysis at the beginning of the iteration process
     */
    virtual void InitializeNonLinearIteration(const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * this is called for non-linear analysis at the end of the iteration process
     */
    virtual void FinalizeNonLinearIteration(const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * this is called at the end of each solution step
     */
    virtual void FinalizeSolutionStep(const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * CONDITIONS inherited from this class have to implement next
     * CalculateLocalSystem, CalculateLeftHandSide and CalculateRightHandSide methods
     * they can be managed internally with a private method to do the same calculations
     * only once: MANDATORY
     */

    /**
     * this is called during the assembling process in order
     * to calculate all condition contributions to the global system
     * matrix and the right hand side
     * @param rLeftHandSideMatrix the condition left hand side matrix
     * @param rRightHandSideVector the condition right hand side
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateLocalSystem(MatrixType& rLeftHandSideMatrix,
                                      VectorType& rRightHandSideVector,
                                      const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this function provides a more general interface to the condition.
     * it is designed so that rLHSvariables and rRHSvariables are passed TO the condition
     * thus telling what is the desired output
     * @param rLeftHandSideMatrices: container with the output left hand side matrices
     * @param rLHSVariables: paramter describing the expected LHSs
     * @param rRightHandSideVectors: container for the desired RHS output
     * @param rRHSVariables: parameter describing the expected RHSs
     */
    virtual void CalculateLocalSystem(std::vector< MatrixType >& rLeftHandSideMatrices,
                                      const std::vector< Variable< MatrixType > >& rLHSVariables,
                                      std::vector< VectorType >& rRightHandSideVectors,
                                      const std::vector< Variable< VectorType > >& rRHSVariables,
                                      const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition left hand side matrix only
     * @param rLeftHandSideMatrix the condition left hand side matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateLeftHandSide(MatrixType& rLeftHandSideMatrix,
                                       const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this function provides a more general interface to the condition.
     * it is designed so that rLHSvariables are passed TO the condition
     * thus telling what is the desired output
     * @param rLeftHandSideMatrices: container for the desired LHS output
     * @param rLHSVariables: parameter describing the expected LHSs
     */
    virtual void CalculateLeftHandSide(std::vector< MatrixType >& rLeftHandSideMatrices,
                    const std::vector< Variable< MatrixType > >& rLHSVariables,
                    const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition right hand side vector only
     * @param rRightHandSideVector the condition right hand side vector
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateRightHandSide(VectorType& rRightHandSideVector,
                                        const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this function provides a more general interface to the condition.
     * it is designed so that rRHSvariables are passed TO the condition
     * thus telling what is the desired output
     * @param rRightHandSideVectors: container for the desired RHS output
     * @param rRHSVariables: parameter describing the expected RHSs
     */
    virtual void CalculateRightHandSide(std::vector< VectorType >& rRightHandSideVectors,
                    const std::vector< Variable< VectorType > >& rRHSVariables,
                    const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * CONDITIONS inherited from this class must implement this methods
     * if they need to add dynamic condition contributions
     * note: first derivatives means the velocities if the displacements are the dof of the analysis
     * note: time integration parameters must be set in the rCurrentProcessInfo before calling these methods
     * CalculateFirstDerivativesContributions,
     * CalculateFirstDerivativesLHS, CalculateFirstDerivativesRHS methods are : OPTIONAL
     */

    /**
     * this is called during the assembling process in order
     * to calculate the first derivatives contributions for the LHS and RHS
     * @param rLeftHandSideMatrix the condition left hand side matrix
     * @param rRightHandSideVector the condition right hand side
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateFirstDerivativesContributions(MatrixType& rLeftHandSideMatrix,
                                                        VectorType& rRightHandSideVector,
                                                        const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition left hand side matrix for the first derivatives contributions
     * @param rLeftHandSideMatrix the condition left hand side matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateFirstDerivativesLHS(MatrixType& rLeftHandSideMatrix,
                                              const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition right hand side vector for the first derivatives contributions
     * @param rRightHandSideVector the condition right hand side vector
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateFirstDerivativesRHS(VectorType& rRightHandSideVector,
                                              const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * CONDITIONS inherited from this class must implement this methods
     * if they need to add dynamic condition contributions
     * note: second derivatives means the accelerations if the displacements are the dof of the analysis
     * note: time integration parameters must be set in the rCurrentProcessInfo before calling these methods
     * CalculateSecondDerivativesContributions,
     * CalculateSecondDerivativesLHS, CalculateSecondDerivativesRHS methods are : OPTIONAL
     */

   /**
     * this is called during the assembling process in order
     * to calculate the second derivative contributions for the LHS and RHS
     * @param rLeftHandSideMatrix the condition left hand side matrix
     * @param rRightHandSideVector the condition right hand side
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateSecondDerivativesContributions(MatrixType& rLeftHandSideMatrix,
                                                         VectorType& rRightHandSideVector,
                                                         const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition left hand side matrix for the second derivatives contributions
     * @param rLeftHandSideMatrix the condition left hand side matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateSecondDerivativesLHS(MatrixType& rLeftHandSideMatrix,
                                               const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition right hand side vector for the second derivatives contributions
     * @param rRightHandSideVector the condition right hand side vector
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateSecondDerivativesRHS(VectorType& rRightHandSideVector,
                                               const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * CONDITIONS inherited from this class must implement this methods
     * if they need to add dynamic condition contributions
     * CalculateMassMatrix and CalculateDampingMatrix methods are: OPTIONAL
     */

    /**
     * this is called during the assembling process in order
     * to calculate the condition mass matrix
     * @param rMassMatrix the condition mass matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateMassMatrix(MatrixType& rMassMatrix, const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition damping matrix
     * @param rDampingMatrix the condition damping matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateDampingMatrix(MatrixType& rDampingMatrix, const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * CONDITIONS inherited from this class must implement this methods
     * if they need to write something at the condition geometry nodes
     * AddExplicitContribution methods are: OPTIONAL ( avoid to use them is not needed )
     */

    /**
     * this is called during the assembling process in order
     * to calculate the condition contribution in explicit calculation.
     * NodalData is modified Inside the function, so the
     * The "AddEXplicit" FUNCTIONS THE ONLY FUNCTIONS IN WHICH A CONDITION
     * IS ALLOWED TO WRITE ON ITS NODES.
     * the caller is expected to ensure thread safety hence
     * SET/UNSETLOCK MUST BE PERFORMED IN THE STRATEGY BEFORE CALLING THIS FUNCTION
      * @param rCurrentProcessInfo the current process info instance
     */
    virtual void AddExplicitContribution(const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * @brief This function is designed to make the condition to assemble an rRHS vector identified by a variable rRHSVariable by assembling it to the nodes on the variable rDestinationVariable. (This is the DataType version)
     * @details The "AddExplicit" FUNCTIONS THE ONLY FUNCTIONS IN WHICH A CONDITION IS ALLOWED TO WRITE ON ITS NODES. The caller is expected to ensure thread safety hence SET-/UNSET-LOCK MUST BE PERFORMED IN THE STRATEGY BEFORE CALLING THIS FUNCTION
     * @param rRHSVector input variable containing the RHS vector to be assembled
     * @param rRHSVariable variable describing the type of the RHS vector to be assembled
     * @param rDestinationVariable variable in the database to which the rRHSvector will be assembled
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void AddExplicitContribution(
        const VectorType& rRHSVector,
        const Variable<VectorType>& rRHSVariable,
        const Variable<DataType>& rDestinationVariable,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
        KRATOS_ERROR << "base condition classes is not able to assemble rRHS to the desired variable. destination variable is " << rDestinationVariable;
    }

    /**
     * @brief This function is designed to make the condition to assemble an rRHS vector identified by a variable rRHSVariable by assembling it to the nodes on the variable rDestinationVariable. (This is the vector version)
     * @details The "AddExplicit" FUNCTIONS THE ONLY FUNCTIONS IN WHICH A CONDITION IS ALLOWED TO WRITE ON ITS NODES. The caller is expected to ensure thread safety hence SET-/UNSET-LOCK MUST BE PERFORMED IN THE STRATEGY BEFORE CALLING THIS FUNCTION
     * @param rRHSVector input variable containing the RHS vector to be assembled
     * @param rRHSVariable variable describing the type of the RHS vector to be assembled
     * @param rDestinationVariable variable in the database to which the rRHSvector will be assembled
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void AddExplicitContribution(
        const VectorType& rRHSVector,
        const Variable<VectorType>& rRHSVariable,
        const Variable<array_1d<DataType, 3> >& rDestinationVariable,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
         KRATOS_ERROR << "base condition classes is not able to assemble rRHS to the desired variable. destination variable is " << rDestinationVariable;
    }

    /**
     * @brief This function is designed to make the condition to assemble an rRHS vector identified by a variable rRHSVariable by assembling it to the nodes on the variable rDestinationVariable. (This is the matrix version)
     * @details The "AddExplicit" FUNCTIONS THE ONLY FUNCTIONS IN WHICH A CONDITION IS ALLOWED TO WRITE ON ITS NODES. The caller is expected to ensure thread safety hence SET-/UNSET-LOCK MUST BE PERFORMED IN THE STRATEGY BEFORE CALLING THIS FUNCTION
     * @param rRHSVector input variable containing the RHS vector to be assembled
     * @param rRHSVariable variable describing the type of the RHS vector to be assembled
     * @param rDestinationVariable variable in the database to which the rRHSvector will be assembled
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void AddExplicitContribution(
        const MatrixType& rLHSMatrix,
        const Variable<MatrixType>& rLHSVariable,
        const Variable<MatrixType>& rDestinationVariable,
        const ProcessInfo& rCurrentProcessInfo
        )
    {
         KRATOS_ERROR << "base condition class is not able to assemble rLHS to the desired variable. destination variable is " << rDestinationVariable;
    }

    /**
     * Calculate a Condition variable usually associated to a integration point
     * the Output is given on integration points and characterizes the condition
     * Calculate(..) methods are: OPTIONAL
     */

    virtual void Calculate(const Variable<DataType>& rVariable,
               DataType& Output,
               const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void Calculate(const Variable< array_1d<DataType, 3> >& rVariable,
               array_1d<DataType, 3>& Output,
               const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void Calculate(const Variable<VectorType>& rVariable,
               VectorType& Output,
               const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void Calculate(const Variable<MatrixType>& rVariable,
               MatrixType& Output,
               const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * Calculate variables on Integration points.
     * This gives access to variables computed in the constitutive law on each integration point.
     * Specialisations of condition must specify the actual interface to the integration points!
     * Note, that these functions expect a std::vector of values for the specified variable type that
     * contains a value for each integration point!
     * CalculateValueOnIntegrationPoints: calculates the values of given Variable.
     */

    virtual void CalculateOnIntegrationPoints(
        const Variable<bool>& rVariable,
        std::vector<bool>& rOutput,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void CalculateOnIntegrationPoints(
        const Variable<int>& rVariable,
        std::vector<int>& rOutput,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void CalculateOnIntegrationPoints(
        const Variable<DataType>& rVariable,
        std::vector<DataType>& rOutput,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void CalculateOnIntegrationPoints(
        const Variable<array_1d<DataType, 3>>& rVariable,
        std::vector< array_1d<DataType, 3>>& rOutput,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void CalculateOnIntegrationPoints(
        const Variable<array_1d<DataType, 6>>& rVariable,
        std::vector<array_1d<DataType, 6>>& rOutput,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void CalculateOnIntegrationPoints(
        const Variable<VectorType>& rVariable,
        std::vector<VectorType>& rOutput,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void CalculateOnIntegrationPoints(
        const Variable<MatrixType>& rVariable,
        std::vector<MatrixType>& rOutput,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void CalculateOnIntegrationPoints(
        const Variable<std::string>& rVariable,
        std::vector<std::string>& rOutput,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * Access for variables on Integration points.
     * This gives access to variables stored in the constitutive law on each integration point.
     * Specializations of condition must specify the actual interface to the integration points!
     * Note, that these functions expect a std::vector of values for the specified variable type that
     * contains a value for each integration point!
     * SetValuesOnIntegrationPoints: set the values for given Variable.
     * GetValueOnIntegrationPoints: get the values for given Variable.
     * these methods are: OPTIONAL
     */

    //SET ON INTEGRATION POINTS - METHODS

    virtual void SetValuesOnIntegrationPoints(
        const Variable<bool>& rVariable,
        const std::vector<bool>& rValues,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void SetValuesOnIntegrationPoints(
        const Variable<int>& rVariable,
        const std::vector<int>& rValues,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void SetValuesOnIntegrationPoints(
        const Variable<DataType>& rVariable,
        const std::vector<DataType>& rValues,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void SetValuesOnIntegrationPoints(
        const Variable<array_1d<DataType, 3>>& rVariable,
        const std::vector<array_1d<DataType, 3>>& rValues,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void SetValuesOnIntegrationPoints(
        const Variable<array_1d<DataType, 6>>& rVariable,
        const std::vector<array_1d<DataType, 6>>& rValues,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void SetValuesOnIntegrationPoints(
        const Variable<VectorType>& rVariable,
        const std::vector<VectorType>& rValues,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void SetValuesOnIntegrationPoints(
        const Variable<MatrixType>& rVariable,
        const std::vector<MatrixType>& rValues,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    virtual void SetValuesOnIntegrationPoints(
        const Variable<std::string>& rVariable,
        const std::vector<std::string>& rValues,
        const ProcessInfo& rCurrentProcessInfo)
    {
    }

    //GET ON INTEGRATION POINTS METHODS

    void GetValuesOnIntegrationPoints(const Variable<int>& rVariable,
                         std::vector<int>& rValues,
                         const ProcessInfo& rCurrentProcessInfo)
    {
        this->CalculateOnIntegrationPoints(rVariable, rValues, rCurrentProcessInfo);
    }

    void GetValuesOnIntegrationPoints(const Variable<DataType>& rVariable,
                         std::vector<DataType>& rValues,
                         const ProcessInfo& rCurrentProcessInfo)
    {
        this->CalculateOnIntegrationPoints(rVariable, rValues, rCurrentProcessInfo);
    }

    void GetValuesOnIntegrationPoints(const Variable<array_1d<DataType, 3> >& rVariable,
                         std::vector<array_1d<DataType, 3> >& rValues,
                         const ProcessInfo& rCurrentProcessInfo)
    {
        this->CalculateOnIntegrationPoints(rVariable, rValues, rCurrentProcessInfo);
    }

    void GetValuesOnIntegrationPoints(const Variable<array_1d<DataType, 6> >& rVariable,
                         std::vector<array_1d<DataType, 6> >& rValues,
                         const ProcessInfo& rCurrentProcessInfo)
    {
        this->CalculateOnIntegrationPoints(rVariable, rValues, rCurrentProcessInfo);
    }

    void GetValuesOnIntegrationPoints(const Variable<VectorType>& rVariable,
                         std::vector<VectorType>& rValues,
                         const ProcessInfo& rCurrentProcessInfo)
    {
        this->CalculateOnIntegrationPoints(rVariable, rValues, rCurrentProcessInfo);
    }

    void GetValuesOnIntegrationPoints(const Variable<MatrixType>& rVariable,
                         std::vector<MatrixType>& rValues,
                         const ProcessInfo& rCurrentProcessInfo)
    {
        this->CalculateOnIntegrationPoints(rVariable, rValues, rCurrentProcessInfo);
    }

    void GetValuesOnIntegrationPoints(const Variable<std::string>& rVariable,
                         std::vector<std::string>& rValues,
                         const ProcessInfo& rCurrentProcessInfo)
    {
        this->CalculateOnIntegrationPoints(rVariable, rValues, rCurrentProcessInfo);
    }

    void GetValuesOnIntegrationPoints(const Variable<bool>& rVariable,
                         std::vector<bool>& rValues,
                         const ProcessInfo& rCurrentProcessInfo)
    {
        this->CalculateOnIntegrationPoints(rVariable, rValues, rCurrentProcessInfo);
    }

    /**
     * This method provides the place to perform checks on the completeness of the input
     * and the compatibility with the problem options as well as the contitutive laws selected
     * It is designed to be called only once (or anyway, not often) typically at the beginning
     * of the calculations, so to verify that nothing is missing from the input
     * or that no common error is found.
     * @param rCurrentProcessInfo
     * this method is: MANDATORY
     */
    virtual int Check(const ProcessInfo& rCurrentProcessInfo) const
    {
        KRATOS_TRY

        if (this->Id() < 1)
        {
            KRATOS_ERROR << "Condition found with Id 0 or negative";
        }
        if constexpr (std::is_arithmetic<DataType>::value)
        {
            if (this->GetGeometry().Area() < 0)
            {
                KRATOS_ERROR << "error on condition -> " << this->Id()
                             << ". Area cannot be less than 0";
            }
        }
        return 0;

        KRATOS_CATCH("");
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition mass matrix
     * @param rMassMatrix the condition mass matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void MassMatrix(MatrixType& rMassMatrix, const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * adds the mass matrix scaled by a given factor to the LHS
     * @param rLeftHandSideMatrix the condition LHS matrix
     * @param coeff the given factor
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void AddMassMatrix(MatrixType& rLeftHandSideMatrix,
                               DataType coeff, const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * this is called during the assembling process in order
     * to calculate the condition damping matrix
     * @param rDampMatrix the condition damping matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void DampMatrix(MatrixType& rDampMatrix, const ProcessInfo& rCurrentProcessInfo)
    {
        KRATOS_ERROR << "Condition " << this->Id() << ", type " << typeid(*this).name() << ": "
                     << __FUNCTION__ << " is not implemented";
    }

    /**
     * adds the inertia forces to the RHS --> performs residua = static_residua - coeff*M*acc
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void AddInertiaForces(VectorType& rRightHandSideVector, DataType coeff,
                                  const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * adds the damping forces to the RHS, e.g performs residua = static_residua - coeff*D*vel
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void AddDampingForces(VectorType& rRightHandSideVector, DataType coeff,
                                  const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * Calculate Mass matrix and add acceleration contribution to RHS
     * @param rMassMatrix the mass matrix
     * @param rRightHandSideVector the conditional right hand side matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateLocalAccelerationContribution(MatrixType& rMassMatrix,
            VectorType& rRightHandSideVector, const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * Calculate Damp matrix and add velocity contribution to RHS
     * @param rDampingMatrix the velocity-proportional "damping" matrix
     * @param rRightHandSideVector the condition right hand side matrix
     * @param rCurrentProcessInfo the current process info instance
     */
    virtual void CalculateLocalVelocityContribution(MatrixType& rDampingMatrix,
            VectorType& rRightHandSideVector, const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * Calculate the transposed gradient of the condition's residual w.r.t. design variable.
     */
    virtual void CalculateSensitivityMatrix(const Variable<double>& rDesignVariable,
                                            MatrixType& rOutput,
                                            const ProcessInfo& rCurrentProcessInfo)
    {
    }

    /**
     * Calculate the transposed gradient of the condition's residual w.r.t. design variable.
     */
    virtual void CalculateSensitivityMatrix(const Variable<array_1d<double,3> >& rDesignVariable,
                                            MatrixType& rOutput,
                                            const ProcessInfo& rCurrentProcessInfo)
    {
    }

    ///@}
    ///@name Access
    ///@{

    /**
    * @brief returns the pointer to the property of the condition.
    *        Does not throw an error, to allow copying of
    *        conditions which don't have any property assigned.
    * @return property pointer
    */
    PropertiesType::Pointer pGetProperties()
    {
        return mpProperties;
    }

    const PropertiesType::Pointer pGetProperties() const
    {
        return mpProperties;
    }

    PropertiesType& GetProperties()
    {
        return *mpProperties;
    }

    PropertiesType const& GetProperties() const
    {
        return *mpProperties;
    }

    void SetProperties(PropertiesType::Pointer pProperties)
    {
        mpProperties = pProperties;
    }

    ///@}
    ///@name Conditional Data
    ///@{

    /**
     * Set Data
     * (Allow to set data from external source, used when duplicating condition)
     */
    void SetData(const DataValueContainer& rData)
    {
        mData = rData;
    }

    /**
     * Access Data
     */
    const DataValueContainer& Data() const
    {
        return mData;
    }

    /**
     * Check if the Data exists with Has(..) methods:
     */
    template<class TDataType> bool Has(const Variable<TDataType>& rThisVariable) const
    {
        return mData.Has(rThisVariable);
    }

    template<class TAdaptorType> bool Has(
        const VariableComponent<TAdaptorType>& rThisVariable) const
    {
        return mData.Has(rThisVariable);
    }

    /**
     * Set Data with SetValue and the Variable to set:
     */
    template<class TVariableType> void SetValue(
        const TVariableType& rThisVariable,
        typename TVariableType::Type const& rValue)
    {
        mData.SetValue(rThisVariable, rValue);
    }

    /**
     * Get Data with GetValue and the Variable to get:
     */
    template<class TVariableType> typename TVariableType::Type& GetValue(
        const TVariableType& rThisVariable)
    {
        return mData.GetValue(rThisVariable);
    }

    template<class TVariableType> typename TVariableType::Type const& GetValue(
        const TVariableType& rThisVariable) const
    {
        return mData.GetValue(rThisVariable);
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
        std::stringstream buffer;
        if constexpr (std::is_same<TNodeType, RealNode>::value)
            buffer << "Condition #";
        else if constexpr (std::is_same<TNodeType, ComplexNode>::value)
            buffer << "ComplexCondition #";
        else if constexpr (std::is_same<TNodeType, GComplexNode>::value)
            buffer << "GComplexCondition #";
        else
            buffer << "BaseCondition #";
        buffer << this->Id();
        return buffer.str();
    }

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << this->Info();
    }

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const override
    {
        this->pGetGeometry()->PrintData(rOStream);
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

    /**
     * Access Data
     */
    DataValueContainer& Data()
    {
        return mData;
    }

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

    /**
     * pointer to the data related to this condition
     */
    DataValueContainer mData;

    /**
     * pointer to the condition properties
     */
    Properties::Pointer mpProperties;

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
        KRATOS_SERIALIZE_SAVE_BASE_CLASS(rSerializer, BaseType);
        rSerializer.save("Data", mData);
        rSerializer.save("Properties", mpProperties);
    }

    void load(Serializer& rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS(rSerializer, BaseType);
        rSerializer.load("Data", mData);
        rSerializer.load("Properties", mpProperties);
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

}; // Class BaseCondition

///@}
///@name Type Definitions
///@{
///@}
///@name Input and output
///@{

/// input stream function
template<class TNodeType>
inline std::istream & operator >>(std::istream& rIStream, BaseCondition<TNodeType>& rThis)
{
    return rIStream;
}

/// output stream function
template<class TNodeType>
inline std::ostream & operator <<(std::ostream& rOStream, const BaseCondition<TNodeType>& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << " : " << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

///@}

typedef BaseCondition<RealNode> Condition;
typedef BaseCondition<ComplexNode> ComplexCondition;
typedef BaseCondition<GComplexNode> GComplexCondition;

void KRATOS_API(KRATOS_CORE) AddKratosComponent(std::string const& Name, Condition const& ThisComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(std::string const& Name, ComplexCondition const& ThisComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(std::string const& Name, GComplexCondition const& ThisComponent);

/**
 * definition of condition specific variables
 */

#undef  KRATOS_EXPORT_MACRO
#define KRATOS_EXPORT_MACRO KRATOS_API

KRATOS_DEFINE_VARIABLE(WeakPointerVector< Condition >, NEIGHBOUR_CONDITIONS)

#undef  KRATOS_EXPORT_MACRO
#define KRATOS_EXPORT_MACRO KRATOS_NO_EXPORT

template<> struct DataTypeToString<WeakPointerVector<Condition> > { static inline constexpr const char* Get() {return "WeakPointerVector<Condition>";} };
template<> struct DataTypeToString<typename Condition::Pointer> { static inline constexpr const char* Get() {return "Condition::Pointer";} };

} // namespace Kratos.

#endif // KRATOS_CONDITION_H_INCLUDED  defined
