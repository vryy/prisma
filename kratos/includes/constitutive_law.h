//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//                   Janosch Stascheit
//                   Nelson Maireni Lafontaine
//                   Josep Maria Carbonell
//


#if !defined(KRATOS_CONSTITUTIVE_LAW )
#define  KRATOS_CONSTITUTIVE_LAW

/* System includes */

/* External includes */

/* Project includes */
#include "includes/define.h"
#include "includes/serializer.h"
#include "includes/node.h"
#include "includes/properties.h"
#include "geometries/geometry.h"
#include "includes/process_info.h"
#include "includes/ublas_interface.h"
#include "includes/kratos_parameters.h"
#include "containers/flags.h"


namespace Kratos
{

/**
 * Base class of constitutive laws.
 */
class KRATOS_API(KRATOS_CORE) BaseConstitutiveLaw : public Flags
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(BaseConstitutiveLaw);

    BaseConstitutiveLaw() : Flags() {}

    ~BaseConstitutiveLaw() override = default;

    enum StrainMeasure
    {
        StrainMeasure_Infinitesimal,   //strain measure small displacements
        StrainMeasure_GreenLagrange,   //strain measure reference configuration
        StrainMeasure_Almansi,         //strain measure current configuration

        // True strain:
        StrainMeasure_Hencky_Material, //strain measure reference configuration
        StrainMeasure_Hencky_Spatial,  //strain measure current   configuration

        // Deformation measures:
        StrainMeasure_Deformation_Gradient, //material deformation gradient as a strain measure
        StrainMeasure_Right_CauchyGreen,    //right cauchy-green tensor as a strain measure
        StrainMeasure_Left_CauchyGreen,     //left  cauchy-green tensor as a strain measure
        StrainMeasure_Velocity_Gradient     //spatial velocity gradient as a strain measure
    };

    enum StressMeasure
    {
        StressMeasure_PK1,            //stress related to reference configuration non-symmetric
        StressMeasure_PK2,            //stress related to reference configuration
        StressMeasure_Kirchhoff,      //stress related to current   configuration
        StressMeasure_Cauchy          //stress related to current   configuration
    };

    // enum type for plasticity code
    enum class PlasticCode : char
    {
        ELASTIC   = 0,
        PLASTIC   = 1,
        FAILURE   = 8,
        RETURN_ON_SMOOTH_PLANE  = 2,
        RETURN_ON_EDGE          = 3,
        RETURN_ON_LEFT_EDGE     = 4,
        RETURN_ON_RIGHT_EDGE    = 5,
        RETURN_ON_CORNER        = 6,
        RETURN_ON_APEX          = 7,
        RETURN_FAILED           = 99, // 100-1 // do that because char is unsigned char with target=aarch64-none-linux-android24
        RETURN_INVALID          = 98, // 100-2,
    };

    /**
     * Flags related to the Parameters of the Contitutive Law
     */
    KRATOS_DEFINE_LOCAL_FLAG( COMPUTE_STRAIN );
    KRATOS_DEFINE_LOCAL_FLAG( COMPUTE_STRESS );
    KRATOS_DEFINE_LOCAL_FLAG( COMPUTE_CONSTITUTIVE_TENSOR );
    KRATOS_DEFINE_LOCAL_FLAG( COMPUTE_STRAIN_ENERGY );

    KRATOS_DEFINE_LOCAL_FLAG( ISOCHORIC_TENSOR_ONLY );
    KRATOS_DEFINE_LOCAL_FLAG( VOLUMETRIC_TENSOR_ONLY );

    KRATOS_DEFINE_LOCAL_FLAG( TOTAL_TENSOR );

    KRATOS_DEFINE_LOCAL_FLAG( FINALIZE_MATERIAL_RESPONSE );

    /**
     * Flags related to the Features of the Contitutive Law
     */

    KRATOS_DEFINE_LOCAL_FLAG( FINITE_STRAINS );
    KRATOS_DEFINE_LOCAL_FLAG( INFINITESIMAL_STRAINS );

    KRATOS_DEFINE_LOCAL_FLAG( THREE_DIMENSIONAL_LAW );
    KRATOS_DEFINE_LOCAL_FLAG( PLANE_STRAIN_LAW );
    KRATOS_DEFINE_LOCAL_FLAG( PLANE_STRESS_LAW );
    KRATOS_DEFINE_LOCAL_FLAG( AXISYMMETRIC_LAW );

    KRATOS_DEFINE_LOCAL_FLAG( U_P_LAW );

    KRATOS_DEFINE_LOCAL_FLAG( ISOTROPIC );
    KRATOS_DEFINE_LOCAL_FLAG( ANISOTROPIC );

    struct Features
    {
    public:
        KRATOS_CLASS_POINTER_DEFINITION(Features);

        /**
         * Structure "Features" to be used by the element to get the the constitutive law characteristics*
         * its variables will be used to check constitutive law and element compatibility
         * @param mOptions        flags  with the current constitutive law characteristics
         * @param mStrainSize     SizeType with the strain vector size
         * @param mStrainMeasures vector with the strain measures accepted by the constitutive law
         */

        /**
         * Constructor.
         */
        Features()
        {
        }

        /**
         * Destructor.
         */
        ~Features()
        {
        }

        // Set variables
        void SetOptions        (const Flags&  rOptions)             {mOptions = rOptions;}
        void SetStrainSize     (const unsigned int StrainSize)      {mStrainSize = StrainSize;}
        void SetSpaceDimension (const unsigned int SpaceDimension)  {mSpaceDimension = SpaceDimension;}
        void SetStrainMeasure  (const StrainMeasure Measure)        {mStrainMeasures.push_back(Measure);}

        void SetStrainMeasures (const std::vector<StrainMeasure>& MeasuresVector) {mStrainMeasures = MeasuresVector;}

        // Get variables
        const Flags& GetOptions() const {return mOptions;}

        const unsigned int GetStrainSize() const {return mStrainSize;}
        const unsigned int GetSpaceDimension() const {return mSpaceDimension;}
        const std::vector<StrainMeasure>& GetStrainMeasures() const {return mStrainMeasures;}

    private:
        Flags                mOptions;
        unsigned int         mStrainSize;
        unsigned int         mSpaceDimension;
        std::vector< StrainMeasure > mStrainMeasures;
    }; // end Features

protected:
    static const unsigned int msIndexVoigt3D6C[6][2];
    static const unsigned int msIndexVoigt2D4C[4][2];
    static const unsigned int msIndexVoigt2D3C[3][2];
}; // end BaseConstitutiveLaw

/**
 * Abstract definition and implementation of constitutive laws.
 */
template<class TNodeType>
class KRATOS_API(KRATOS_CORE) ConstitutiveLawImpl : public BaseConstitutiveLaw
{
public:

    /**
     * Type definitions
     * NOTE: geometries are assumed to be of type Node<3> for all problems
     */
    typedef ProcessInfo ProcessInfoType;
    typedef Geometry<TNodeType> GeometryType;
    typedef KRATOS_SIZE_TYPE SizeType;
    typedef typename TNodeType::DofType::DataType DataType;
    typedef typename MatrixVectorTypeSelector<DataType>::VectorType VectorType;
    typedef typename MatrixVectorTypeSelector<DataType>::MatrixType MatrixType;

    typedef VectorType StrainVectorType;
    typedef VectorType StressVectorType;
    typedef MatrixType VoigtSizeMatrixType;           // Constitutive Matrix
    typedef MatrixType DeformationGradientMatrixType; // Def. gradient tensor

    /**
     * Counted pointer of ConstitutiveLawImpl
     */
    KRATOS_CLASS_POINTER_DEFINITION(ConstitutiveLawImpl);

    struct Parameters
    {
        KRATOS_CLASS_POINTER_DEFINITION(Parameters);

        /**
         * Structure "Parameters" to be used by the element to pass the parameters into the constitutive law *

         * @param mOptions flags for the current Constitutive Law Parameters (input data)

         * KINEMATIC PARAMETERS:

         *** NOTE: Pointers are used only to point to a certain variable, no "new" or "malloc" can be used for this Parameters ***

         * @param mDeterminantF copy of the determinant of the Current DeformationGradient (although Current F  is also included as a matrix) (input data)
         * @param mpDeformationGradientF  pointer to the current deformation gradient (can be an empty matrix if a linear strain measure is used) (input data)
         * @param mpStrainVector pointer to the current strains (total strains) (input data) (*can be also OUTPUT with COMPUTE_STRAIN flag)
         * @param mpStressVector pointer to the current stresses (*OUTPUT with COMPUTE_STRESS flag)
         * @param mpConstitutiveMatrix pointer to the material tangent matrix (*OUTPUT with COMPUTE_CONSTITUTIVE_TENSOR flag)

         * GEOMETRIC PARAMETERS:
         * @param mpShapeFunctionsValues pointer to the shape functions values in the current integration point (input data)
         * @param mpShapeFunctionsDerivatives pointer to the shape functions derivatives values in the current integration point (input data)
         * @param mpElementGeometry pointer to the element's geometry (input data)

         * MATERIAL PROPERTIES:
         * @param mpMaterialProperties pointer to the material's Properties object (input data)

         * PROCESS PROPERTIES:
         * @param mpCurrentProcessInfo pointer to current ProcessInfo instance (input data)

         */

    private:

      /*** NOTE: Member Pointers are used only to point to a certain variable, no "new" or "malloc" can be used for this Parameters ***/

      Flags                                mOptions;
      DataType                             mDeterminantF;

      StrainVectorType*                    mpStrainVector;
      StressVectorType*                    mpStressVector;

      const Vector*                        mpShapeFunctionsValues;
      const Matrix*                        mpShapeFunctionsDerivatives;

      const DeformationGradientMatrixType* mpDeformationGradientF;
      VoigtSizeMatrixType*                 mpConstitutiveMatrix;

      const ProcessInfo*                   mpCurrentProcessInfo;
      const Properties*                    mpMaterialProperties;
      const GeometryType*                  mpElementGeometry;

    public:

      /**
       * Constructor.
       */
      Parameters ()
      {
          //Initialize pointers to nullptr
          mDeterminantF=0;
          mpStrainVector=nullptr;
          mpStressVector=nullptr;
          mpShapeFunctionsValues=nullptr;
          mpShapeFunctionsDerivatives=nullptr;
          mpDeformationGradientF=nullptr;
          mpConstitutiveMatrix=nullptr;
          mpCurrentProcessInfo=nullptr;
          mpMaterialProperties=nullptr;
          mpElementGeometry=nullptr;
      }

      /**
       * Constructor with Properties, Geometry and ProcessInfo
       */
      Parameters (const GeometryType& rElementGeometry,
          const Properties& rMaterialProperties,
          const ProcessInfo& rCurrentProcessInfo)
      : mpCurrentProcessInfo(&rCurrentProcessInfo)
      , mpMaterialProperties(&rMaterialProperties)
      , mpElementGeometry(&rElementGeometry)
      {
          //Initialize pointers to nullptr
          mDeterminantF=0;
          mpStrainVector=nullptr;
          mpStressVector=nullptr;
          mpShapeFunctionsValues=nullptr;
          mpShapeFunctionsDerivatives=nullptr;
          mpDeformationGradientF=nullptr;
          mpConstitutiveMatrix=nullptr;
      }

      /**
       * Copy Constructor.
       */
      Parameters (const Parameters & rNewParameters)
        :mOptions(rNewParameters.mOptions)
        ,mDeterminantF(rNewParameters.mDeterminantF)
        ,mpStrainVector(rNewParameters.mpStrainVector)
        ,mpStressVector(rNewParameters.mpStressVector)
        ,mpShapeFunctionsValues(rNewParameters.mpShapeFunctionsValues)
        ,mpShapeFunctionsDerivatives(rNewParameters.mpShapeFunctionsDerivatives)
        ,mpDeformationGradientF(rNewParameters.mpDeformationGradientF)
        ,mpConstitutiveMatrix(rNewParameters.mpConstitutiveMatrix)
        ,mpCurrentProcessInfo(rNewParameters.mpCurrentProcessInfo)
        ,mpMaterialProperties(rNewParameters.mpMaterialProperties)
        ,mpElementGeometry(rNewParameters.mpElementGeometry)
      {
      }

      /**
       * Destructor.
       */
      ~Parameters()
      {
      }

      /**
       * Verify Parameters
       */
      bool CheckAllParameters () const
      {
        if(CheckMechanicalVariables() &&  CheckShapeFunctions() && CheckInfoMaterialGeometry ())
            return 1;
        else
            return 0;
      }

      /**
       *Check currentprocessinfo, material properties and geometry
       */
      bool CheckShapeFunctions () const
      {
        if(!mpShapeFunctionsValues)
            KRATOS_ERROR << "ShapeFunctionsValues NOT SET" << std::endl;

        if(!mpShapeFunctionsDerivatives)
            KRATOS_ERROR << "ShapeFunctionsDerivatives NOT SET" << std::endl;

        return 1;
      }

      /**
       *Check currentprocessinfo, material properties and geometry
       */
      bool CheckInfoMaterialGeometry () const
      {
        if(!mpCurrentProcessInfo)
            KRATOS_ERROR << "CurrentProcessInfo NOT SET" << std::endl;

        if(!mpMaterialProperties)
            KRATOS_ERROR << "MaterialProperties NOT SET" << std::endl;

        if(!mpElementGeometry)
            KRATOS_ERROR << "ElementGeometry NOT SET" << std::endl;

        return 1;
      }

      /**
       *Check deformation gradient, strains and stresses assigned
       */
      bool CheckMechanicalVariables () const
      {
          if constexpr (std::is_arithmetic<DataType>::value)
          {
            if(mDeterminantF <= 0)
              KRATOS_ERROR << "DeterminantF NOT SET, value <= 0" << std::endl;
          }

          if(!mpDeformationGradientF)
            KRATOS_ERROR << "DeformationGradientF NOT SET" << std::endl;

          if(!mpStrainVector)
            KRATOS_ERROR << "StrainVector NOT SET" << std::endl;

          if(!mpStressVector)
            KRATOS_ERROR << "StressVector NOT SET" << std::endl;

          if(!mpConstitutiveMatrix)
            KRATOS_ERROR << "ConstitutiveMatrix NOT SET" << std::endl;

          return 1;
      }

      /**
       * Public Methods to access variables of the struct class
       */

      /**
       * sets the variable or the pointer of a specified variable: assigns the direction of the pointer for the mpvariables, only non const values can be modified
       */

      void Set                             (Flags ThisFlag)                           {mOptions.Set(ThisFlag);}
      void Reset                           (Flags ThisFlag)                           {mOptions.Reset(ThisFlag);}

      void SetOptions                      (const Flags&  rOptions)                   {mOptions=rOptions;}
      void SetDeterminantF                 (const DataType DeterminantF)              {mDeterminantF=DeterminantF;}
      // void SetDeterminantF                 (const DataType& rDeterminantF)            {mDeterminantF=&rDeterminantF;}

      void SetShapeFunctionsValues         (const Vector& rShapeFunctionsValues)      {mpShapeFunctionsValues=&rShapeFunctionsValues;}
      void SetShapeFunctionsDerivatives    (const Matrix& rShapeFunctionsDerivatives) {mpShapeFunctionsDerivatives=&rShapeFunctionsDerivatives;}

      void SetDeformationGradientF         (const DeformationGradientMatrixType& rDeformationGradientF)      {mpDeformationGradientF=&rDeformationGradientF;}

      void SetStrainVector                 (StrainVectorType& rStrainVector)                       {mpStrainVector=&rStrainVector;}
      void SetStressVector                 (StressVectorType& rStressVector)                       {mpStressVector=&rStressVector;}
      void SetConstitutiveMatrix           (VoigtSizeMatrixType& rConstitutiveMatrix)              {mpConstitutiveMatrix =&rConstitutiveMatrix;}

      void SetProcessInfo                  (const ProcessInfo& rProcessInfo)          {mpCurrentProcessInfo =&rProcessInfo;}
      void SetMaterialProperties           (const Properties&  rMaterialProperties)   {mpMaterialProperties =&rMaterialProperties;}
      void SetElementGeometry              (const GeometryType& rElementGeometry)     {mpElementGeometry =&rElementGeometry;}

      /**
       * Returns the reference or the value of a specified variable: returns the value of the parameter, only non const values can be modified
       */
      Flags& GetOptions () {return mOptions;}

      const DataType& GetDeterminantF              () const {return mDeterminantF;}
      const Vector& GetShapeFunctionsValues        () const {return *mpShapeFunctionsValues;}
      const Matrix& GetShapeFunctionsDerivatives   () const {return *mpShapeFunctionsDerivatives;}
      const DeformationGradientMatrixType& GetDeformationGradientF    () const {return *mpDeformationGradientF;}

      StrainVectorType& GetStrainVector          () {return *mpStrainVector;}
      StressVectorType& GetStressVector          () {return *mpStressVector;}

      VoigtSizeMatrixType& GetConstitutiveMatrix () {return *mpConstitutiveMatrix;}

      const ProcessInfo&  GetProcessInfo         () const {return *mpCurrentProcessInfo;}
      const Properties&   GetMaterialProperties  () const {return *mpMaterialProperties;}
      const GeometryType& GetElementGeometry     () const {return *mpElementGeometry;}

      /**
       * Returns the reference to the value of a specified variable with not constant access
       */

      DataType& GetDeterminantF                              (DataType& rDeterminantF) {rDeterminantF=mDeterminantF; return rDeterminantF;}
      StrainVectorType& GetStrainVector                      (StrainVectorType& rStrainVector) {rStrainVector=*mpStrainVector; return rStrainVector;}
      DeformationGradientMatrixType& GetDeformationGradientF (DeformationGradientMatrixType& rDeformationGradientF)  {rDeformationGradientF=*mpDeformationGradientF;   return rDeformationGradientF;}
      StressVectorType& GetStressVector                      (StressVectorType& rStressVector) {rStressVector=*mpStressVector; return rStressVector;}
      VoigtSizeMatrixType& GetConstitutiveMatrix             (VoigtSizeMatrixType& rConstitutiveMatrix) {rConstitutiveMatrix=*mpConstitutiveMatrix; return rConstitutiveMatrix;}

      /**
       * Returns if the different components has been set
       */

      bool IsSetDeterminantF              () const
      {
        if constexpr (std::is_arithmetic<DataType>::value)
            return (mDeterminantF > 0.0);
        else
            return true;
      }

      bool IsSetShapeFunctionsValues      () const {return (mpShapeFunctionsValues != nullptr);}
      bool IsSetShapeFunctionsDerivatives () const {return (mpShapeFunctionsDerivatives != nullptr);}
      bool IsSetDeformationGradientF      () const {return (mpDeformationGradientF != nullptr);}

      bool IsSetStrainVector              () const {return (mpStrainVector != nullptr);}
      bool IsSetStressVector              () const {return (mpStressVector != nullptr);}

      bool IsSetConstitutiveMatrix        () const {return (mpConstitutiveMatrix != nullptr);}

      bool IsSetProcessInfo               () const {return (mpCurrentProcessInfo != nullptr);}
      bool IsSetMaterialProperties        () const {return (mpMaterialProperties != nullptr);}
      bool IsSetElementGeometry           () const {return (mpElementGeometry != nullptr);}

    }; // struct Parameters end

    /**
     * Constructor.
     */
    ConstitutiveLawImpl();

    /**
     * Destructor.
     */
    ~ConstitutiveLawImpl() override = default;

    /**
     * @brief Clone function (has to be implemented by any derived class)
     * @return a pointer to a new instance of this constitutive law
     * @note implementation scheme:
     *      ConstitutiveLawImpl::Pointer p_clone(new ConstitutiveLawImpl());
     *      return p_clone;
     */
    virtual ConstitutiveLawImpl::Pointer Clone() const;

    /**
     * @brief It creates a new constitutive law pointer
     * @param NewParameters The configuration parameters of the new constitutive law
     * @return a Pointer to the new constitutive law
     */
    virtual Pointer Create(Kratos::Parameters NewParameters) const;

    /**
     * @brief It creates a new constitutive law pointer (version with properties)
     * @param NewParameters The configuration parameters of the new constitutive law
     * @param rProperties The properties of the material
     * @return a Pointer to the new constitutive law
     */
    virtual Pointer Create(
        Kratos::Parameters NewParameters,
        const Properties& rProperties
        ) const;

    /**
     * @return The working space dimension of the current constitutive law
     * @note This function HAS TO BE IMPLEMENTED by any derived class
     */
    virtual SizeType WorkingSpaceDimension();

    /**
     * @return The size of the strain vector of the current constitutive law
     * @note This function HAS TO BE IMPLEMENTED by any derived class
     */
    virtual SizeType GetStrainSize() const;

    /**
     * @brief Returns whether this constitutive Law has specified variable (boolean)
     * @param rThisVariable the variable to be checked for
     * @return true if the variable is defined in the constitutive law
     */
    virtual bool Has(const Variable<bool>& rThisVariable);

    /**
     * @brief Returns whether this constitutive Law has specified variable (integer)
     * @param rThisVariable the variable to be checked for
     * @return true if the variable is defined in the constitutive law
     */
    virtual bool Has(const Variable<int>& rThisVariable);

    /**
     * @brief Returns whether this constitutive Law has specified variable (DataType)
     * @param rThisVariable the variable to be checked for
     * @return true if the variable is defined in the constitutive law
     */
    virtual bool Has(const Variable<DataType>& rThisVariable);

    /**
     * @brief Returns whether this constitutive Law has specified variable (Vector)
     * @param rThisVariable the variable to be checked for
     * @return true if the variable is defined in the constitutive law
     */
    virtual bool Has(const Variable<VectorType>& rThisVariable);

    /**
     * @brief Returns whether this constitutive Law has specified variable (Matrix)
     * @param rThisVariable the variable to be checked for
     * @return true if the variable is defined in the constitutive law
     */
    virtual bool Has(const Variable<MatrixType>& rThisVariable);

    /**
     * @brief Returns whether this constitutive Law has specified variable (array of 3 components)
     * @param rThisVariable the variable to be checked for
     * @return true if the variable is defined in the constitutive law
     * @note Fixed size array of 3 DataTypes (e.g. for 2D stresses, plastic strains, ...)
     */
    virtual bool Has(const Variable<array_1d<DataType, 3 > >& rThisVariable);

    /**
     * @brief Returns whether this constitutive Law has specified variable (array of 6 components)
     * @param rThisVariable the variable to be checked for
     * @return true if the variable is defined in the constitutive law
     * @note Fixed size array of 6 DataTypes (e.g. for stresses, plastic strains, ...)
     */
    virtual bool Has(const Variable<array_1d<DataType, 6 > >& rThisVariable);

    /**
     * @brief Returns the value of a specified variable (boolean)
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @return rValue output: the value of the specified variable
     */
    virtual bool& GetValue(const Variable<bool>& rThisVariable, bool& rValue);

    /**
     * Returns the value of a specified variable (integer)
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @return rValue output: the value of the specified variable
     */
    virtual int& GetValue(const Variable<int>& rThisVariable, int& rValue);

    /**
     * @brief Returns the value of a specified variable (DataType)
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @return rValue output: the value of the specified variable
     */
    virtual DataType& GetValue(const Variable<DataType>& rThisVariable, DataType& rValue);

    /**
     * @brief Returns the value of a specified variable (VectorType)
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @return rValue output: the value of the specified variable
     */
    virtual VectorType& GetValue(const Variable<VectorType>& rThisVariable, VectorType& rValue);

    /**
     * @brief Returns the value of a specified variable (Matrix)
     * @param rThisVariable the variable to be returned
     * @return rValue output: the value of the specified variable
     */
    virtual MatrixType& GetValue(const Variable<MatrixType>& rThisVariable, MatrixType& rValue);

    /**
     * @brief Returns the value of a specified variable
     * @param rThisVariable the variable to be returned
     * @return the value of the specified variable
     */
    virtual std::string& GetValue(const Variable<std::string>& rThisVariable, std::string& rValue);

    /**
     * @brief Returns the value of a specified variable (array of 3 components)
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @return rValue output: the value of the specified variable
     */
    virtual array_1d<DataType, 3 > & GetValue(const Variable<array_1d<DataType, 3 > >& rThisVariable,
                                            array_1d<DataType, 3 > & rValue);

    /**
     * @brief Returns the value of a specified variable (array of 6 components)
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @return the value of the specified variable
     */
    virtual array_1d<DataType, 6 > & GetValue(const Variable<array_1d<DataType, 6 > >& rThisVariable,
                                            array_1d<DataType, 6 > & rValue);

    /**
     * @brief Sets the value of a specified variable (boolean)
     * @param rVariable the variable to be returned
     * @param Value new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<bool>& rVariable,
                          const bool& Value,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * @brief Sets the value of a specified variable (integer)
     * @param rVariable the variable to be returned
     * @param Value new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<int>& rVariable,
                          const int& Value,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * @brief Sets the value of a specified variable (DataType)
     * @param rVariable the variable to be returned
     * @param rValue new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<DataType>& rVariable,
                          const DataType& rValue,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * @brief Sets the value of a specified variable (VectorType)
     * @param rVariable the variable to be returned
     * @param rValue new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<VectorType>& rVariable,
                          const VectorType& rValue,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * @brief Sets the value of a specified variable (Matrix)
     * @param rVariable the variable to be returned
     * @param rValue new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<MatrixType>& rVariable,
                          const MatrixType& rValue,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * sets the value of a specified variable
     * @param rVariable the variable to be returned
     * @param rValue new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<std::string>& rThisVariable,
                          const std::string& rValue,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * @brief Sets the value of a specified variable (array of 3 components)
     * @param rVariable the variable to be returned
     * @param rValue new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<array_1d<DataType, 3 > >& rVariable,
                          const array_1d<DataType, 3 > & rValue,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * @brief Sets the value of a specified variable (array of 6 components)
     * @param rVariable the variable to be returned
     * @param rValue new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<array_1d<DataType, 6 > >& rVariable,
                          const array_1d<DataType, 6 > & rValue,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * @brief Sets the value of a specified variable
     * @param rVariable the variable to be returned
     * @param rValue new value of the specified variable
     * @param rCurrentProcessInfo the process info
     */
    virtual void SetValue(const Variable<ConstitutiveLawImpl::Pointer>& rVariable,
                          ConstitutiveLawImpl::Pointer rValue,
                          const ProcessInfo& rCurrentProcessInfo);

    /**
     * @brief Calculates the value of a specified variable (bool)
     * @param rParameterValues the needed parameters for the CL calculation
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @param rValue output: the value of the specified variable
     */
    virtual bool& CalculateValue(Parameters& rParameterValues, const Variable<bool>& rThisVariable, bool& rValue);

    /**
     * @brief Calculates the value of a specified variable (int)
     * @param rParameterValues the needed parameters for the CL calculation
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @param rValue output: the value of the specified variable
     */
    virtual int& CalculateValue(Parameters& rParameterValues, const Variable<int>& rThisVariable, int& rValue);

    /**
     * @brief Calculates the value of a specified variable (DataType)
     * @param rParameterValues the needed parameters for the CL calculation
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @param rValue output: the value of the specified variable
     */
    virtual DataType& CalculateValue(Parameters& rParameterValues, const Variable<DataType>& rThisVariable, DataType& rValue);

    /**
     * @brief Calculates the value of a specified variable (VectorType)
     * @param rParameterValues the needed parameters for the CL calculation
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @param rValue output: the value of the specified variable
     */
    virtual VectorType& CalculateValue(Parameters& rParameterValues, const Variable<VectorType>& rThisVariable, VectorType& rValue);

    /**
     * @brief Calculates the value of a specified variable (Matrix)
     * @param rParameterValues the needed parameters for the CL calculation
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @param rValue output: the value of the specified variable
     */
    virtual MatrixType& CalculateValue(Parameters& rParameterValues, const Variable<MatrixType>& rThisVariable, MatrixType& rValue);

    /**
     * @brief Calculates the value of a specified variable (array of 3 components)
     * @param rParameterValues the needed parameters for the CL calculation
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @param rValue output: the value of the specified variable
     */
    virtual array_1d<DataType, 3 > & CalculateValue(Parameters& rParameterValues, const Variable<array_1d<DataType, 3 > >& rVariable,
                          array_1d<DataType, 3 > & rValue);

    /**
     * returns the value of a specified variable (array of 6 components)
     * @param rThisVariable the variable to be returned
     * @param rValue a reference to the returned value
     * @return the value of the specified variable
     */
    virtual array_1d<DataType, 6 > & CalculateValue(Parameters& rParameterValues, const Variable<array_1d<DataType, 6 > >& rVariable,
                          array_1d<DataType, 6 > & rValue);

    /**
     * Is called to check whether the provided material parameters in the Properties
     * match the requirements of current constitutive model.
     * @param rMaterialProperties the current Properties to be validated against.
     * @return true, if parameters are correct; false, if parameters are insufficient / faulty
     * NOTE: this has to be implemented by each constitutive model. Returns false in base class since
     * no valid implementation is contained here.
     */
    virtual bool ValidateInput(const Properties& rMaterialProperties);

    /**
     * returns the expected strain measure of this constitutive law (by default linear strains)
     * @return the expected strain measure
     */
    virtual StrainMeasure GetStrainMeasure();

    /**
     * returns the stress measure of this constitutive law (by default 1st Piola-Kirchhoff stress in voigt notation)
     * @return the expected stress measure
     */
    virtual StressMeasure GetStressMeasure();

    /**
     * returns whether this constitutive model is formulated in incremental strains/stresses
     * NOTE: by default, all constitutive models should be formulated in total strains
     * @return true, if formulated in incremental strains/stresses, false otherwise
     */
    virtual bool IsIncremental();

    /**
     * This is to be called at the very beginning of the calculation
     * (e.g. from InitializeElement) in order to initialize all relevant
     * attributes of the constitutive law
     * @param rMaterialProperties the Properties instance of the current element
     * @param rElementGeometry the geometry of the current element
     * @param rShapeFunctionsValues the shape functions values in the current integration point
     */
    virtual void InitializeMaterial(const Properties& rMaterialProperties,
                                    const GeometryType& rElementGeometry,
                                    const Vector& rShapeFunctionsValues);

    /**
     * to be called at the beginning of each solution step
     * (e.g. from Element::InitializeSolutionStep)
     * @param rMaterialProperties the Properties instance of the current element
     * @param rElementGeometry the geometry of the current element
     * @param rShapeFunctionsValues the shape functions values in the current integration point
     * @param the current ProcessInfo instance
     */
    virtual void InitializeSolutionStep(const Properties& rMaterialProperties,
                                        const GeometryType& rElementGeometry, //this is just to give the array of nodes
                                        const Vector& rShapeFunctionsValues,
                                        const ProcessInfo& rCurrentProcessInfo);

    /**
     * to be called at the end of each solution step
     * (e.g. from Element::FinalizeSolutionStep)
     * @param rMaterialProperties the Properties instance of the current element
     * @param rElementGeometry the geometry of the current element
     * @param rShapeFunctionsValues the shape functions values in the current integration point
     * @param the current ProcessInfo instance
     */
    virtual void FinalizeSolutionStep(const Properties& rMaterialProperties,
                                      const GeometryType& rElementGeometry,
                                      const Vector& rShapeFunctionsValues,
                                      const ProcessInfo& rCurrentProcessInfo);



    /**
     * to be called at the beginning of each step iteration
     * (e.g. from Element::InitializeNonLinearIteration)
     * @param rMaterialProperties the Properties instance of the current element
     * @param rElementGeometry the geometry of the current element
     * @param rShapeFunctionsValues the shape functions values in the current integration point
     * @param the current ProcessInfo instance
     */
    virtual void InitializeNonLinearIteration(const Properties& rMaterialProperties,
                          const GeometryType& rElementGeometry,
                          const Vector& rShapeFunctionsValues,
                          const ProcessInfo& rCurrentProcessInfo);



    /**
     * to be called at the end of each step iteration
     * (e.g. from Element::FinalizeNonLinearIteration)
     * @param rMaterialProperties the Properties instance of the current element
     * @param rElementGeometry the geometry of the current element
     * @param rShapeFunctionsValues the shape functions values in the current integration point
     * @param the current ProcessInfo instance
     */
    virtual void FinalizeNonLinearIteration(const Properties& rMaterialProperties,
                        const GeometryType& rElementGeometry,
                        const Vector& rShapeFunctionsValues,
                        const ProcessInfo& rCurrentProcessInfo);



    /**
     * Computes the material response in terms of stresses and constitutive tensor
     * @see Parameters
     * @see StressMeasure
     */
    void CalculateMaterialResponse (Parameters& rValues,const StressMeasure& rStressMeasure);



    /**
     * Computes the material response in terms of 1st Piola-Kirchhoff stresses and constitutive tensor
     * @see Parameters
     */
    virtual void CalculateMaterialResponsePK1 (Parameters& rValues);


    /**
     * Computes the material response in terms of 2nd Piola-Kirchhoff stresses and constitutive tensor
     * @see Parameters
     */
    virtual void CalculateMaterialResponsePK2 (Parameters& rValues);


    /**
     * Computes the material response in terms of Kirchhoff stresses and constitutive tensor
     * @see Parameters
     */
    virtual void CalculateMaterialResponseKirchhoff (Parameters& rValues);


    /**
     * Computes the material response in terms of Cauchy stresses and constitutive tensor
     * @see Parameters
     */
    virtual void CalculateMaterialResponseCauchy (Parameters& rValues);

    /**
     * @brief If the CL requires to initialize the material response, called by the element in InitializeSolutionStep.
     */
    virtual bool RequiresInitializeMaterialResponse()
    {
        return true;
    }

    /**
     * Computes the material response in terms of Cauchy stresses and constitutive tensor, returns internal variables.
     * @see Parameters
     */
    virtual void CalculateStressResponse (Parameters& rValues, VectorType& rInternalVariables);

    /**
     * @brief Initialize the material response,  called by the element in InitializeSolutionStep.
     * @see Parameters
     * @see StressMeasures
     */
    void InitializeMaterialResponse (Parameters& rValues,const StressMeasure& rStressMeasure);

    /**
     * Initialize the material response in terms of 1st Piola-Kirchhoff stresses
     * @see Parameters
     */

    virtual void InitializeMaterialResponsePK1 (Parameters& rValues);

    /**
     * Initialize the material response in terms of 2nd Piola-Kirchhoff stresses
     * @see Parameters
     */

    virtual void InitializeMaterialResponsePK2 (Parameters& rValues);

    /**
     * Initialize the material response in terms of Kirchhoff stresses
     * @see Parameters
     */

    virtual void InitializeMaterialResponseKirchhoff (Parameters& rValues);

    /**
     * Initialize the material response in terms of Cauchy stresses
     * @see Parameters
     */

    virtual void InitializeMaterialResponseCauchy (Parameters& rValues);

    /**
     * @brief If the CL requires to finalize the material response, called by the element in FinalizeSolutionStep.
     */
    virtual bool RequiresFinalizeMaterialResponse()
    {
        return true;
    }

    /**
     * @brief Finalize the material response,  called by the element in FinalizeSolutionStep.
     * @see Parameters
     * @see StressMeasures
     */
    void FinalizeMaterialResponse (Parameters& rValues,const StressMeasure& rStressMeasure);


    /**
     * Finalize the material response in terms of 1st Piola-Kirchhoff stresses
     * @see Parameters
     */

    virtual void FinalizeMaterialResponsePK1 (Parameters& rValues);

    /**
     * Finalize the material response in terms of 2nd Piola-Kirchhoff stresses
     * @see Parameters
     */

    virtual void FinalizeMaterialResponsePK2 (Parameters& rValues);

    /**
     * Finalize the material response in terms of Kirchhoff stresses
     * @see Parameters
     */

    virtual void FinalizeMaterialResponseKirchhoff (Parameters& rValues);

    /**
     * Finalize the material response in terms of Cauchy stresses
     * @see Parameters
     */

    virtual void FinalizeMaterialResponseCauchy (Parameters& rValues);

    /**
     * This can be used in order to reset all internal variables of the
     * constitutive law (e.g. if a model should be reset to its reference state)
     * @param rMaterialProperties the Properties instance of the current element
     * @param rElementGeometry the geometry of the current element
     * @param rShapeFunctionsValues the shape functions values in the current integration point
     * @param the current ProcessInfo instance
     */
    virtual void ResetMaterial (const Properties& rMaterialProperties,
                                const GeometryType& rElementGeometry,
                                const Vector& rShapeFunctionsValues);

    /**
     * This can be used in order to rewind all internal variables of the
     * constitutive law (e.g. if a model should be rewinded to a previous state)
     * REMARK: EXPERIMENTAL METHOD
     * @param rMaterialProperties the Properties instance of the current element
     * @param rElementGeometry the geometry of the current element
     * @param rShapeFunctionsValues the shape functions values in the current integration point
     * @param the current ProcessInfo instance
     */
    virtual void RewindMaterial (const Properties& rMaterialProperties,
                                 const GeometryType& rElementGeometry,
                                 const Vector& rShapeFunctionsValues);

    /**
     * Methods to transform strain Vectors:
     * @param rStrainVector the strain tensor in matrix which its stress measure will be changed
     * @param rF the DeformationGradientF matrix between the configurations
     * @param rdetF the determinant of the DeformationGradientF matrix between the configurations
     * @param rStrainInitial the measure of stress of the given  rStrainVector
     * @param rStrainFinal the measure of stress of the returned rStrainVector
     */
    virtual VectorType& TransformStrains (VectorType& rStrainVector,
                                          const MatrixType &rF,
                                          StrainMeasure rStrainInitial,
                                          StrainMeasure rStrainFinal);

    /**
     * Methods to transform stress Matrices:
     * @param rStressMatrix the stress tensor in matrix which its stress measure will be changed
     * @param rF the DeformationGradientF matrix between the configurations
     * @param rdetF the determinant of the DeformationGradientF matrix between the configurations
     * @param rStressInitial the measure of stress of the given  rStressMatrix
     * @param rStressFinal the measure of stress of the returned rStressMatrix
     */
    virtual MatrixType& TransformStresses (MatrixType& rStressMatrix,
                                           const MatrixType &rF,
                                           const DataType &rdetF,
                                           StressMeasure rStressInitial,
                                           StressMeasure rStressFinal);

    /**
     * Methods to transform stress Vectors:
     * @param rStressVector the stress tensor in matrix which its stress measure will be changed
     * @param rF the DeformationGradientF matrix between the configurations
     * @param rdetF the determinant of the DeformationGradientF matrix between the configurations
     * @param rStressInitial the measure of stress of the given  rStressVector
     * @param rStressFinal the measure of stress of the returned rStressVector
     */
    virtual VectorType& TransformStresses (VectorType& rStressVector,
                                           const MatrixType &rF,
                                           const DataType &rdetF,
                                           StressMeasure rStressInitial,
                                           StressMeasure rStressFinal);

    /**
     * Methods to transform stress Vectors specialized with the initial stress Measure PK1:
     * @param rStressVector the stress tensor in matrix which its stress measure will be changed
     * @param rF the DeformationGradientF matrix between the configurations
     * @param rdetF the determinant of the DeformationGradientF matrix between the configurations
     * @param rStressFinal the measure of stress of the returned rStressVector
     */
    VectorType& TransformPK1Stresses (VectorType& rStressVector,
                                      const MatrixType &rF,
                                      const DataType &rdetF,
                                      StressMeasure rStressFinal);

    /**
     * Methods to transform stress Vectors specialized with the initial stress Measure PK2:
     * @param rStressVector the stress tensor in matrix which its stress measure will be changed
     * @param rF the DeformationGradientF matrix between the configurations
     * @param rdetF the determinant of the DeformationGradientF matrix between the configurations
     * @param rStressFinal the measure of stress of the returned rStressVector
     */
    VectorType& TransformPK2Stresses (VectorType& rStressVector,
                                      const MatrixType &rF,
                                      const DataType &rdetF,
                                      StressMeasure rStressFinal);

    /**
     * Methods to transform stress Vectors specialized with the initial stress Measure Kirchhoff:
     * @param rStressVector the stress tensor in matrix which its stress measure will be changed
     * @param rF the DeformationGradientF matrix between the configurations
     * @param rdetF the determinant of the DeformationGradientF matrix between the configurations
     * @param rStressFinal the measure of stress of the returned rStressVector
     */
    VectorType& TransformKirchhoffStresses (VectorType& rStressVector,
                                            const MatrixType &rF,
                                            const DataType &rdetF,
                                            StressMeasure rStressFinal);

    /**
     * Methods to transform stress Vectors specialized with the initial stress Measure Cauchy:
     * @param rStressVector the stress tensor in matrix which its stress measure will be changed
     * @param rF the DeformationGradientF matrix between the configurations
     * @param rdetF the determinant of the DeformationGradientF matrix between the configurations
     * @param rStressFinal the measure of stress of the returned rStressVector
     */
    VectorType& TransformCauchyStresses (VectorType& rStressVector,
                                         const MatrixType &rF,
                                         const DataType &rdetF,
                                         StressMeasure rStressFinal);

    /**
     * Methods to transform Constitutive Matrices:
     * @param rConstitutiveMatrix the constitutive matrix
     * @param rF the DeformationGradientF matrix between the configurations
     */

    /**
     * This method performs a pull-back of the constitutive matrix
     */
    void PullBackConstitutiveMatrix ( MatrixType& rConstitutiveMatrix, const MatrixType& rF );

    /**
     * This method performs a push-forward of the constitutive matrix
     */
    void PushForwardConstitutiveMatrix ( MatrixType& rConstitutiveMatrix, const MatrixType& rF );

    /**
     * This function is designed to be called once to check compatibility with element
     * @param rFeatures
     */
    virtual void GetLawFeatures(Features& rFeatures);

    /**
     * This function is designed to be called once to perform all the checks needed
     * on the input provided. Checks can be "expensive" as the function is designed
     * to catch user's errors.
     * @param rMaterialProperties
     * @param rElementGeometry
     * @param rCurrentProcessInfo
     * @return
     */
    virtual int Check(const Properties& rMaterialProperties,
                      const GeometryType& rElementGeometry,
                      const ProcessInfo& rCurrentProcessInfo) const;

    // VM

    virtual void CalculateCauchyStresses(VectorType& Cauchy_StressVector,
                                         const MatrixType& F,
                                         const VectorType& PK2_StressVector,
                                         const VectorType& GreenLagrangeStrainVector);


    //*** OUTDATED METHODS: ***//

    /**
     * Computes the material response in terms of stresses and algorithmic tangent
     * @param StrainVector the current strains (total strains, input)
     * @param DeformationGradient the current deformation gradient (can be an empty matrix if a linear strain measure is used)
     * @param StressVector the computed stresses (output)
     * @param algorithmicTangent the material tangent matrix (output)
     * @param rCurrentProcessInfo current ProcessInfo instance
     * @param rMaterialProperties the material's Properties object
     * @param rElementGeometry the element's geometry
     * @param rShapeFunctionsValues the shape functions values in the current integration pointer
     * @param CalculateStresses flag whether or not to compute the stress response
     * @param CalculateTangent flag to determine if to compute the material tangent
     * NOTE: the CalculateTangent flag is defined as int to allow for distinctive variants of the tangent
     * @param SaveInternalVariables flag whether or not to store internal (history) variables
     */
    virtual void CalculateMaterialResponse(const VectorType& StrainVector,
                                           const MatrixType& DeformationGradient,
                                           VectorType& StressVector,
                                           MatrixType& AlgorithmicTangent,
                                           const ProcessInfo& rCurrentProcessInfo,
                                           const Properties& rMaterialProperties,
                                           const GeometryType& rElementGeometry,
                                           const Vector& rShapeFunctionsValues,
                                           bool CalculateStresses = true,
                                           int CalculateTangent = true,
                                           bool SaveInternalVariables = true);

    /**
     * Computes the volumetric part of the material response in terms of stresses and algorithmic tangent
     * @param StrainVector the current strains (total strains, input)
     * @param DeformationGradient the current deformation gradient (can be an empty matrix if a linear
     * @param StressVector the computed stresses (output)
     * @param algorithmicTangent the material tangent matrix (output)
     * @param rCurrentProcessInfo current ProcessInfo instance
     * @param rMaterialProperties the material's Properties object
     * @param rElementGeometry the element's geometry
     * @param rShapeFunctionsValues the shape functions values in the current integration pointer
     * @param CalculateStresses flag whether or not to compute the stress response
     * @param CalculateTangent flag to determine if to compute the material tangent
     * NOTE: the CalculateTangent flag is defined as int to allow for distinctive variants of the tangent
     * @param SaveInternalVariables flag whether or not to store internal (history) variables
     */
    virtual void CalculateVolumetricResponse(const DataType VolumetricStrain,
               const MatrixType& DeformationGradient,
               DataType& VolumetricStress,
               DataType& AlgorithmicBulk,
               const ProcessInfo& rCurrentProcessInfo,
               const Properties& rMaterialProperties,
               const GeometryType& rElementGeometry,
               const Vector& rShapeFunctionsValues,
               bool CalculateStresses,
               int CalculateTangent,
               bool SaveInternalVariables);

    /**
     * Computes the deviatoric part of the material response in terms of stresses and algorithmic tangent
     * @param StrainVector the current strains (total strains, input)
     * @param DeformationGradient the current deformation gradient (can be an empty matrix if a linear
     * @param StressVector the computed stresses (output)
     * @param algorithmicTangent the material tangent matrix (output)
     * @param rCurrentProcessInfo current ProcessInfo instance
     * @param rMaterialProperties the material's Properties object
     * @param rElementGeometry the element's geometry
     * @param rShapeFunctionsValues the shape functions values in the current integration pointer
     * @param CalculateStresses flag whether or not to compute the stress response
     * @param CalculateTangent flag to determine if to compute the material tangent
     * NOTE: the CalculateTangent flag is defined as int to allow for distinctive variants of the tangent
     * @param SaveInternalVariables flag whether or not to store internal (history) variables

     * TODO: add proper definition for algorithmic tangent
     */
    virtual void CalculateDeviatoricResponse(const VectorType& StrainVector,
               const MatrixType& DeformationGradient,
               VectorType& StressVector,
               MatrixType& AlgorithmicTangent,
               const ProcessInfo& rCurrentProcessInfo,
               const Properties& rMaterialProperties,
               const GeometryType& rElementGeometry,
               const Vector& rShapeFunctionsValues,
               bool CalculateStresses = true,
               int CalculateTangent = true,
               bool SaveInternalVariables = true);

    /**
     * @brief This method is used to check that two Constitutive Laws are the same type (references)
     * @param rLHS The first argument
     * @param rRHS The second argument
     */
    inline static bool HasSameType(const ConstitutiveLawImpl& rLHS, const ConstitutiveLawImpl& rRHS) {
        return (typeid(rLHS) == typeid(rRHS));
    }

    /**
     * @brief This method is used to check that two Constitutive Laws are the same type (pointers)
     * @param rLHS The first argument
     * @param rRHS The second argument
     */
    inline static bool HasSameType(const ConstitutiveLawImpl* rLHS, const ConstitutiveLawImpl* rRHS) {
        return ConstitutiveLawImpl::HasSameType(*rLHS, *rRHS);
    }

    ///@}
    ///@}
    ///@name Inquiry
    ///@{
    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    std::string Info() const override
    {
        return "ConstitutiveLaw";
    }

    /// Print information about this object.
    void PrintInfo(std::ostream& rOStream) const override
    {
        rOStream << Info();
    }

    /// Print object's data.
    void PrintData(std::ostream& rOStream) const override
    {
      rOStream << "ConstitutiveLaw has no data";
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

    /**
     * This method performs a contra-variant push-forward between to tensors
     * i.e. 2nd PK stress to Kirchhoff stress
     */
    void ContraVariantPushForward( MatrixType& rMatrix, const MatrixType& rF );

    /**
     * This method performs a contra-variant pull-back between to tensors
     * i.e. Kirchhoff stress to 2nd PK stress
     */
    void ContraVariantPullBack( MatrixType& rMatrix, const MatrixType& rF );

    /**
     * This method performs a co-variant push-forward between to tensors
     * i.e. Green-Lagrange strain to Almansi strain
     */
    void CoVariantPushForward( MatrixType& rMatrix, const MatrixType& rF );

    /**
     * This method performs a co-variant pull-back between to tensors
     * i.e. Almansi strain to Green-Lagrange strain
     */
    void CoVariantPullBack( MatrixType& rMatrix, const MatrixType& rF );

    /**
     * This method performs a pull-back or a push-forward between two constitutive matrices
     */
    void ConstitutiveMatrixTransformation ( MatrixType& rConstitutiveMatrix,
                                            const MatrixType& rOriginalConstitutiveMatrix,
                                            const MatrixType& rF );


    /**
     * This method performs a pull-back or a push-forward between two constitutive tensor components
     */
    DataType& TransformConstitutiveComponent(DataType & rCabcd,
                                             const MatrixType & rConstitutiveMatrix,
                                             const MatrixType & rF,
                                             const unsigned int a, const unsigned int b,
                                             const unsigned int c, const unsigned int d);

    /**
     * This method gets the constitutive tensor components
     * from a consitutive matrix supplied in voigt notation
     */
    DataType& GetConstitutiveComponent(DataType & rCabcd,
                                       const MatrixType& rConstitutiveMatrix,
                                       const unsigned int a, const unsigned int b,
                                       const unsigned int c, const unsigned int d);


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

    ///@}
    ///@name Serialization
    ///@{

    friend class Serializer;

    void save(Serializer& rSerializer) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS( rSerializer, Flags );
    }

    void load(Serializer& rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS( rSerializer, Flags );
    }

    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{

    ///@}

}; /* Class ConstitutiveLawImpl */

///@}
///@name Type Definitions
///@{
///@}
///@name Input and output
///@{

/// input stream function
inline std::istream & operator >>(std::istream& rIStream,
                                  BaseConstitutiveLaw& rThis)
{
    return rIStream;
}

/// output stream function
inline std::ostream & operator <<(std::ostream& rOStream,
                                  const BaseConstitutiveLaw& rThis)
{
    rThis.PrintInfo(rOStream);
    rOStream << " : " << std::endl;
    rThis.PrintData(rOStream);

    return rOStream;
}

inline std::ostream& operator<<(std::ostream& os, const BaseConstitutiveLaw::PlasticCode p)
{
    switch (p)
    {
        case BaseConstitutiveLaw::PlasticCode::ELASTIC:                 os << "elastic";  break;
        case BaseConstitutiveLaw::PlasticCode::PLASTIC:                 os << "plastic";  break;
        case BaseConstitutiveLaw::PlasticCode::FAILURE:                 os << "failure";  break;
        case BaseConstitutiveLaw::PlasticCode::RETURN_ON_SMOOTH_PLANE:  os << "smooth";   break;
        case BaseConstitutiveLaw::PlasticCode::RETURN_ON_EDGE:          os << "edge";     break;
        case BaseConstitutiveLaw::PlasticCode::RETURN_ON_LEFT_EDGE:     os << "left";     break;
        case BaseConstitutiveLaw::PlasticCode::RETURN_ON_RIGHT_EDGE:    os << "right";    break;
        case BaseConstitutiveLaw::PlasticCode::RETURN_ON_CORNER:        os << "corner";   break;
        case BaseConstitutiveLaw::PlasticCode::RETURN_ON_APEX:          os << "apex";     break;
        default:    os << "failed"; break;
    }
    return os;
}

///@}
///@} addtogroup block

typedef ConstitutiveLawImpl<Node<3, KRATOS_DOUBLE_TYPE, Dof<KRATOS_DOUBLE_TYPE> > > ConstitutiveLaw;
typedef ConstitutiveLawImpl<Node<3, KRATOS_DOUBLE_TYPE, Dof<KRATOS_COMPLEX_TYPE> > > ComplexConstitutiveLaw;
typedef ConstitutiveLawImpl<Node<3, KRATOS_COMPLEX_TYPE, Dof<KRATOS_COMPLEX_TYPE> > > GComplexConstitutiveLaw;

void KRATOS_API(KRATOS_CORE) AddKratosComponent(std::string const& Name, ConstitutiveLaw const& ThisComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(std::string const& Name, ComplexConstitutiveLaw const& ThisComponent);
void KRATOS_API(KRATOS_CORE) AddKratosComponent(std::string const& Name, GComplexConstitutiveLaw const& ThisComponent);

/**
 * Definition of ConstitutiveLaw variable
 */

#undef  KRATOS_EXPORT_MACRO
#define KRATOS_EXPORT_MACRO KRATOS_API

#ifdef KRATOS_DEFINE_CONSTITUTIVE_LAW_VARIABLE
#undef KRATOS_DEFINE_CONSTITUTIVE_LAW_VARIABLE
#endif
#define KRATOS_DEFINE_CONSTITUTIVE_LAW_VARIABLE(name)                                   \
    KRATOS_DEFINE_VARIABLE_IMPLEMENTATION(KRATOS_CORE, ConstitutiveLaw::Pointer, name)  \
    KRATOS_DEFINE_VARIABLE_IMPLEMENTATION(KRATOS_CORE, ComplexConstitutiveLaw::Pointer, COMPLEX##_##name)          \
    KRATOS_DEFINE_VARIABLE_IMPLEMENTATION(KRATOS_CORE, GComplexConstitutiveLaw::Pointer, GCOMPLEX##_##name)        \
\
template<typename T> struct KRATOS_EXPORT_MACRO(KRATOS_CORE) VariableSelector_##name;   \
template<> struct KRATOS_EXPORT_MACRO(KRATOS_CORE) VariableSelector_##name<ConstitutiveLaw> {static constexpr Variable<ConstitutiveLaw::Pointer>& Get() {return name;}};  \
template<> struct KRATOS_EXPORT_MACRO(KRATOS_CORE) VariableSelector_##name<ComplexConstitutiveLaw> {static constexpr Variable<ComplexConstitutiveLaw::Pointer>& Get() {return COMPLEX##_##name;}};    \
template<> struct KRATOS_EXPORT_MACRO(KRATOS_CORE) VariableSelector_##name<GComplexConstitutiveLaw> {static constexpr Variable<GComplexConstitutiveLaw::Pointer>& Get() {return GCOMPLEX##_##name;}}; \

#ifdef KRATOS_DEFINE_APPLICATION_CONSTITUTIVE_LAW_VARIABLE
#undef KRATOS_DEFINE_APPLICATION_CONSTITUTIVE_LAW_VARIABLE
#endif
#define KRATOS_DEFINE_APPLICATION_CONSTITUTIVE_LAW_VARIABLE(application, name)        \
    KRATOS_API(application) extern Variable<ConstitutiveLaw::Pointer> name;           \
    KRATOS_API(application) extern Variable<ComplexConstitutiveLaw::Pointer> COMPLEX##_##name;            \
    KRATOS_API(application) extern Variable<GComplexConstitutiveLaw::Pointer> GCOMPLEX##_##name;          \
\
template<typename T> struct KRATOS_API(application) VariableSelector_##name;    \
template<> struct KRATOS_API(application) VariableSelector_##name<ConstitutiveLaw> {static constexpr Variable<ConstitutiveLaw::Pointer>& Get() {return name;}};   \
template<> struct KRATOS_API(application) VariableSelector_##name<ComplexConstitutiveLaw> {static constexpr Variable<ComplexConstitutiveLaw::Pointer>& Get() {return COMPLEX##_##name;}};     \
template<> struct KRATOS_API(application) VariableSelector_##name<GComplexConstitutiveLaw> {static constexpr Variable<GComplexConstitutiveLaw::Pointer>& Get() {return GCOMPLEX##_##name;}};  \

#ifdef KRATOS_CREATE_CONSTITUTIVE_LAW_VARIABLE
#undef KRATOS_CREATE_CONSTITUTIVE_LAW_VARIABLE
#endif
#define KRATOS_CREATE_CONSTITUTIVE_LAW_VARIABLE(name)                 \
    /*const*/ Kratos::Variable<ConstitutiveLaw::Pointer> name(#name); \
    /*const*/ Kratos::Variable<ComplexConstitutiveLaw::Pointer> COMPLEX##_##name("COMPLEX_" #name);       \
    /*const*/ Kratos::Variable<GComplexConstitutiveLaw::Pointer> GCOMPLEX##_##name("GCOMPLEX_" #name);    \

#ifdef KRATOS_REGISTER_CONSTITUTIVE_LAW_VARIABLE
#undef KRATOS_REGISTER_CONSTITUTIVE_LAW_VARIABLE
#endif
#define KRATOS_REGISTER_CONSTITUTIVE_LAW_VARIABLE(name)               \
    KRATOS_REGISTER_VARIABLE_IMPLEMENTATION(name)                     \
    KRATOS_REGISTER_VARIABLE_IMPLEMENTATION(COMPLEX##_##name)         \
    KRATOS_REGISTER_VARIABLE_IMPLEMENTATION(GCOMPLEX##_##name)        \

////////////

KRATOS_DEFINE_CONSTITUTIVE_LAW_VARIABLE( CONSTITUTIVE_LAW )

#undef  KRATOS_EXPORT_MACRO
#define KRATOS_EXPORT_MACRO KRATOS_NO_EXPORT

template<> struct DataTypeToString<ConstitutiveLaw::Pointer> { static inline constexpr const char* Get() {return "ConstitutiveLaw::Pointer";} };
template<> struct DataTypeToString<ComplexConstitutiveLaw::Pointer> { static inline constexpr const char* Get() {return "ComplexConstitutiveLaw::Pointer";} };
template<> struct DataTypeToString<GComplexConstitutiveLaw::Pointer> { static inline constexpr const char* Get() {return "GComplexConstitutiveLaw::Pointer";} };

} /* namespace Kratos.*/

#endif /* KRATOS_CONSTITUTIVE_LAW  defined */
