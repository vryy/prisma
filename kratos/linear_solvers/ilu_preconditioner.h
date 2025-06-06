#if !defined(KRATOS_ILU_PRECONDITIONER_H_INCLUDED )
#define  KRATOS_ILU_PRECONDITIONER_H_INCLUDED




// System includes



// External includes

// Project includes
#include "includes/define.h"



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

///@name  Preconditioners
///@{

/// ILUPreconditioner class.
/**   */
template<class TSparseSpaceType, class TDenseSpaceType, class TModelPartType>
class ILUPreconditioner : public Preconditioner<TSparseSpaceType, TDenseSpaceType, TModelPartType>
{
public:
    ///@name Type Definitions
    ///@{

    /// Counted pointer of ILUPreconditioner
    KRATOS_CLASS_POINTER_DEFINITION(ILUPreconditioner);

    typedef Preconditioner<TSparseSpaceType, TDenseSpaceType, TModelPartType> BaseType;

    typedef typename TSparseSpaceType::DataType DataType;

    typedef typename TSparseSpaceType::MatrixType SparseMatrixType;

    typedef typename TSparseSpaceType::VectorType VectorType;

    typedef typename TDenseSpaceType::MatrixType DenseMatrixType;

    ///@}
    ///@name Life Cycle
    ///@{

    /// Default constructor.
    ILUPreconditioner()
    {
        L = NULL;
        iL = NULL;
        jL = NULL;
        U = NULL;
        iU = NULL;
        jU = NULL;
    }


    /// Copy constructor.
    ILUPreconditioner(const ILUPreconditioner& Other) {}


    /// Destructor.
    ~ILUPreconditioner() override
    {
        if ( L!=NULL) delete[]  L;
        if (iL!=NULL) delete[] iL;
        if (jL!=NULL) delete[] jL;
        if ( U!=NULL) delete[]  U;
        if (iU!=NULL) delete[] iU;
        if (jU!=NULL) delete[] jU;

        L = NULL;
        iL = NULL;
        jL = NULL;
        U = NULL;
        iU = NULL;
        jU = NULL;
    }



    ///@}
    ///@name Operators
    ///@{

    /// Assignment operator.
    ILUPreconditioner& operator=(const ILUPreconditioner& Other)
    {
        mILUSize = Other.mILUSize;
        unsigned int size = Other.iL[mILUSize];
        L = new DataType[size];
        U = new DataType[size];
        iL = new int[mILUSize+1];
        jL = new int[size];
        iU = new int[mILUSize+1];
        jU = new int[size];


        std::copy(Other.L, Other.L+size, L);
        std::copy(Other.U, Other.U+size, U);
        std::copy(Other.iL, Other.iL+mILUSize+1, iL);
        std::copy(Other.jL, Other.jL+size, jL);
        std::copy(Other.iU, Other.iU+mILUSize+1, iU);
        std::copy(Other.jU, Other.jU+size, jU);


        return *this;
    }



    ///@}
    ///@name Operations
    ///@{

    void Mult(SparseMatrixType& rA, VectorType& rX, VectorType& rY) override
    {
        VectorType z = rX;
        TSparseSpaceType::Mult(rA,z, rY);
        ApplyLeft(rY);
    }

    void TransposeMult(SparseMatrixType& rA, VectorType& rX, VectorType& rY) override
    {
        VectorType z = rX;
        ApplyTransposeLeft(z);
        TSparseSpaceType::TransposeMult(rA,z, rY);
    }

    /** multiply first rX by L^-1 and store result in temp
        then multiply temp by U^-1 and store result in rX
        @param rX  Unknows of preconditioner suystem
    */
    VectorType& ApplyLeft(VectorType& rX) override
    {
        const int size = TSparseSpaceType::Size(rX);
        VectorType temp(size);
        DataType sum;
        int i, indexj;
        for (i=0; i<size; i++)
        {
            sum=rX[i];
            for (indexj=iL[i]; indexj<iL[i+1]; indexj++)
            {
                sum=sum-L[indexj]*temp[jL[indexj]];
            }
            temp[i]=sum;
        }
        for (i=size-1; i>=0; i--)
        {
            sum=temp[i];
            for (indexj=iU[i]+1; indexj<iU[i+1]; indexj++)
            {
                sum=sum-U[indexj]*rX[jU[indexj]];
            }
            rX[i]=sum/U[iU[i]];
        }
        return rX;
    }

    /** Multiply first rX by U^-T and store result in temp
        then multiply temp by L^-T and store result in rX
        @param rX  Unknows of preconditioner suystem
    */
    VectorType& ApplyTransposeLeft(VectorType& rX) override
    {
        const int size = TSparseSpaceType::Size(rX);
        VectorType temp(size);
        int i, indexj;
        DataType tempi, rxi;
        for (i=0; i<size; i++) temp[i]=rX[i];
        for (i=0; i<size; i++)
        {
            temp[i]=temp[i]/U[iU[i]];
            tempi=temp[i];
            for (indexj=iU[i]+1; indexj<iU[i+1]; indexj++)
            {
                temp[jU[indexj]]=temp[jU[indexj]]-tempi*U[indexj];
            }
        }
        for (i=0; i<size; i++) rX[i]=temp[i];
        for (i=size-1; i>=0; i--)
        {
            rxi=rX[i];
            for (indexj=iL[i]; indexj<iL[i+1]; indexj++)
            {
                rX[jL[indexj]]=rX[jL[indexj]]-rxi*L[indexj];
            }
        }
        return rX;
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

    /// Return information about this object.
    std::string Info() const override
    {
        return "ILUPreconditioner";
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

    unsigned int mILUSize;
    int *iL, *jL, *iU, *jU;
    DataType *L, *U;


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

}; // Class ILUPreconditioner

///@}


///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

}  // namespace Kratos.

#endif // KRATOS_ILU_PRECONDITIONER_H_INCLUDED  defined
