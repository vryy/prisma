/*
==============================================================================
Kratos
A General Purpose Software for Multi-Physics Finite Element Analysis
Version 1.0 (Released on march 05, 2007).

Copyright 2007
Pooyan Dadvand, Riccardo Rossi
pooyan@cimne.upc.edu
rrossi@cimne.upc.edu
CIMNE (International Center for Numerical Methods in Engineering),
Gran Capita' s/n, 08034 Barcelona, Spain

Permission is hereby granted, free  of charge, to any person obtaining
a  copy  of this  software  and  associated  documentation files  (the
"Software"), to  deal in  the Software without  restriction, including
without limitation  the rights to  use, copy, modify,  merge, publish,
distribute,  sublicense and/or  sell copies  of the  Software,  and to
permit persons to whom the Software  is furnished to do so, subject to
the following condition:

Distribution of this code for  any  commercial purpose  is permissible
ONLY BY DIRECT ARRANGEMENT WITH THE COPYRIGHT OWNER.

The  above  copyright  notice  and  this permission  notice  shall  be
included in all copies or substantial portions of the Software.

THE  SOFTWARE IS  PROVIDED  "AS  IS", WITHOUT  WARRANTY  OF ANY  KIND,
EXPRESS OR  IMPLIED, INCLUDING  BUT NOT LIMITED  TO THE  WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT  SHALL THE AUTHORS OR COPYRIGHT HOLDERS  BE LIABLE FOR ANY
CLAIM, DAMAGES OR  OTHER LIABILITY, WHETHER IN AN  ACTION OF CONTRACT,
TORT  OR OTHERWISE, ARISING  FROM, OUT  OF OR  IN CONNECTION  WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

==============================================================================
*/

#ifndef KRATOS_RESIDUALBASED_INCREMENTALUPDATE_STATIC_SCHEME_SLIP_H
#define KRATOS_RESIDUALBASED_INCREMENTALUPDATE_STATIC_SCHEME_SLIP_H

/* System includes */


/* External includes */
#include "boost/smart_ptr.hpp"


/* Project includes */
#include "includes/define.h"
#include "includes/model_part.h"
#include "includes/deprecated_variables.h"
//#include "includes/variables.h"
#include "solving_strategies/schemes/scheme.h"
#include "solving_strategies/schemes/residualbased_incrementalupdate_static_scheme.h"
#include "utilities/coordinate_transformation_utilities.h"

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

/// Scheme for the solution of problems involving a slip condition.
/** This Scheme is a reimplementation of ResidualBasedIncrementalUpdateStaticScheme that can be used to
  * apply slip conditions along the edges of the model. The problem is solved using rotated coordinate axes on
  * the nodes where this condition will be applied, with the first coordinate of the rotated system aligned with the
  * normal to the boundary on each of these nodes.
  */
template<class TSparseSpace,
         class TDenseSpace, //= DenseSpace<double>
         class TModelPartType = ModelPart
         >
class ResidualBasedIncrementalUpdateStaticSchemeSlip : public ResidualBasedIncrementalUpdateStaticScheme<TSparseSpace, TDenseSpace, TModelPartType>
{

public:
    ///@name Type Definitions
    ///@{

    KRATOS_CLASS_POINTER_DEFINITION( ResidualBasedIncrementalUpdateStaticSchemeSlip);

    typedef ResidualBasedIncrementalUpdateStaticScheme<TSparseSpace, TDenseSpace, TModelPartType> BaseType;

    typedef typename BaseType::TDataType TDataType;

    typedef typename BaseType::DofsArrayType DofsArrayType;

    typedef typename BaseType::ModelPartType ModelPartType;

    typedef typename ModelPartType::NodeType NodeType;

    typedef typename BaseType::ElementType ElementType;

    typedef typename BaseType::ConditionType ConditionType;

    typedef typename BaseType::TSystemMatrixType TSystemMatrixType;

    typedef typename BaseType::TSystemVectorType TSystemVectorType;

    typedef typename BaseType::LocalSystemVectorType LocalSystemVectorType;
    typedef typename BaseType::LocalSystemMatrixType LocalSystemMatrixType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Constructor.
    /** @param DomainSize Number of spatial dimensions (2 or 3).
      * @param BlockSize Number of matrix and vector rows associated to each node. Only the first DomainSize rows will be rotated.
      */
    ResidualBasedIncrementalUpdateStaticSchemeSlip(unsigned int DomainSize, unsigned int BlockSize)
        : BaseType()
        , mRotationTool(DomainSize, BlockSize, STRUCTURE)
    {}

    /// Destructor.
    ~ResidualBasedIncrementalUpdateStaticSchemeSlip() override
    {}

    ///@}
    ///@name Operators
    ///@{


    ///@}
    ///@name Operations
    ///@{

    /// Update the degrees of freedom after a solution iteration.
    void Update(ModelPartType& r_model_part,
                DofsArrayType& rDofSet,
                TSystemMatrixType& A,
                TSystemVectorType& Dx,
                TSystemVectorType& b) override
    {
        KRATOS_TRY;

        mRotationTool.RotateVelocities(r_model_part);

        BaseType::Update(r_model_part, rDofSet, A, Dx, b);

        mRotationTool.RecoverVelocities(r_model_part);

        KRATOS_CATCH("");
    }


    /// Obtain an element's local contribution to the system and apply slip conditions if needed.
    void CalculateSystemContributions(ElementType& rCurrentElement,
                                      LocalSystemMatrixType& LHS_Contribution,
                                      LocalSystemVectorType& RHS_Contribution,
                                      typename ElementType::EquationIdVectorType& EquationId,
                                      const ProcessInfo& CurrentProcessInfo) override
    {
        KRATOS_TRY;

        BaseType::CalculateSystemContributions(rCurrentElement, LHS_Contribution, RHS_Contribution, EquationId, CurrentProcessInfo);

        mRotationTool.Rotate(LHS_Contribution, RHS_Contribution, rCurrentElement.GetGeometry());
        mRotationTool.ApplySlipCondition(LHS_Contribution, RHS_Contribution, rCurrentElement.GetGeometry());

        KRATOS_CATCH("");
    }

    /// Obtain an element's local contribution to the RHS and apply slip conditions if needed.
    void CalculateRHSContribution(ElementType& rCurrentElement,
                                  LocalSystemVectorType& RHS_Contribution,
                                  typename ElementType::EquationIdVectorType& EquationId,
                                  const ProcessInfo& CurrentProcessInfo) override
    {
        KRATOS_TRY;

        BaseType::CalculateRHSContribution(rCurrentElement,RHS_Contribution,EquationId,CurrentProcessInfo);

        mRotationTool.Rotate(RHS_Contribution, rCurrentElement.GetGeometry());
        mRotationTool.ApplySlipCondition(RHS_Contribution, rCurrentElement.GetGeometry());

        KRATOS_CATCH("");
    }

    /// Obtain an element's local contribution to the system matrix and apply slip conditions if needed.
    void CalculateLHSContribution(ElementType& rCurrentElement,
                                  LocalSystemMatrixType& LHS_Contribution,
                                  typename ElementType::EquationIdVectorType& EquationId,
                                  const ProcessInfo& CurrentProcessInfo) override
    {
        KRATOS_TRY;

        BaseType::CalculateLHSContribution(rCurrentElement,LHS_Contribution,EquationId,CurrentProcessInfo);

        LocalSystemVectorType Temp = ZeroVector(LHS_Contribution.size1());
        mRotationTool.Rotate(LHS_Contribution, Temp, rCurrentElement.GetGeometry());
        mRotationTool.ApplySlipCondition(LHS_Contribution, Temp, rCurrentElement.GetGeometry());

        KRATOS_CATCH("");
    }


    /// Obtain a condition's local contribution to the system and apply slip conditions if needed.
    void CalculateSystemContributions(ConditionType& rCurrentCondition,
                                      LocalSystemMatrixType& LHS_Contribution,
                                      LocalSystemVectorType& RHS_Contribution,
                                      typename ElementType::EquationIdVectorType& EquationId,
                                      const ProcessInfo& CurrentProcessInfo) override
    {
        KRATOS_TRY;

        BaseType::CalculateSystemContributions(rCurrentCondition,LHS_Contribution,RHS_Contribution,EquationId,CurrentProcessInfo);

        mRotationTool.Rotate(LHS_Contribution, RHS_Contribution, rCurrentCondition.GetGeometry());
        mRotationTool.ApplySlipCondition(LHS_Contribution, RHS_Contribution,rCurrentCondition.GetGeometry());

        KRATOS_CATCH("");
    }

    /// Obtain a condition's local contribution to the RHS and apply slip conditions if needed.
    void CalculateRHSContribution(ConditionType& rCurrentCondition,
                                  LocalSystemVectorType& RHS_Contribution,
                                  typename ElementType::EquationIdVectorType& EquationId,
                                  const ProcessInfo& CurrentProcessInfo) override
    {
        KRATOS_TRY;

        BaseType::CalculateRHSContribution(rCurrentCondition, RHS_Contribution, EquationId, CurrentProcessInfo);

        mRotationTool.Rotate(RHS_Contribution, rCurrentCondition.GetGeometry());
        mRotationTool.ApplySlipCondition(RHS_Contribution, rCurrentCondition.GetGeometry());

        KRATOS_CATCH("");
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
    std::string Info() const override
    {
        return "ResidualBasedIncrementalUpdateStaticSchemeSlip";
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

    /// Rotation tool instance
    CoordinateTransformationUtils<NodeType> mRotationTool;

    ///@}
    ///@name Serialization
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

}; // class

///@}
///@name Type Definitions
///@{

///@}

///@} // group

}  // namespace Kratos

#endif // KRATOS_RESIDUALBASED_INCREMENTALUPDATE_STATIC_SCHEME_SLIP_H
