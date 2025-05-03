// Kratos Multi-Physics
//
// Copyright (c) 2016 Pooyan Dadvand, Riccardo Rossi, CIMNE (International Center for Numerical Methods in Engineering)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
//  -   Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//  -   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
//      in the documentation and/or other materials provided with the distribution.
//  -   All advertising materials mentioning features or use of this software must display the following acknowledgement:
//          This product includes Kratos Multi-Physics technology.
//  -   Neither the name of the CIMNE nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED ANDON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THISSOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



// System includes


// External includes
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>


// Project includes
#include "includes/define.h"
#include "python/add_spaces_to_python.h"
#include "spaces/ublas_space.h"
#ifdef _OPENMP
#include "spaces/parallel_ublas_space.h"
#endif

namespace Kratos
{

    namespace Python
    {
        using namespace boost::python;

        //ADDED BY PAOLO (next two)

        template<class SparseSpaceType>
        typename SparseSpaceType::DataType Dot(SparseSpaceType& dummy, const typename SparseSpaceType::VectorType& rX, const typename SparseSpaceType::VectorType& rY)
        {
            return dummy.Dot(rX, rY);
        }

        template<class SparseSpaceType>
        void ScaleAndAdd(SparseSpaceType& dummy, const typename SparseSpaceType::DataType A, const typename SparseSpaceType::VectorType& rX, const typename SparseSpaceType::DataType B, typename SparseSpaceType::VectorType& rY)
        //(const DataType A,const  VectorType& rX, const DataType B, VectorType& rY) // rY = (A * rX) + (B * rY)
        {
            dummy.ScaleAndAdd(A, rX, B, rY);
        }

        template<class SparseSpaceType>
        void Mult(SparseSpaceType& dummy, typename SparseSpaceType::MatrixType& rA, typename SparseSpaceType::VectorType& rX, typename SparseSpaceType::VectorType& rY)
        //rY=A*rX (the product is stored inside the rY)
        {
            dummy.Mult(rA, rX, rY);
        }

        template<class SparseSpaceType>
        void TransposeMult(SparseSpaceType& dummy, typename SparseSpaceType::MatrixType& rA, typename SparseSpaceType::VectorType& rX, typename SparseSpaceType::VectorType& rY)
        //rY=A*rX (the product is stored inside the rY)
        {
            dummy.TransposeMult(rA, rX, rY);
        }

        template<class SparseSpaceType>
        typename SparseSpaceType::IndexType Size(SparseSpaceType& dummy, typename SparseSpaceType::VectorType const& rV)
        {
            return rV.size();
        }

        template<class SparseSpaceType>
        typename SparseSpaceType::IndexType Size1(SparseSpaceType& dummy, typename SparseSpaceType::MatrixType const& rM)
        {
            return rM.size1();
        }

        template<class SparseSpaceType>
        typename SparseSpaceType::IndexType Size2(SparseSpaceType& dummy, typename SparseSpaceType::MatrixType const& rM)
        {
            return rM.size2();
        }

        template<class SparseSpaceType>
        void ResizeMatrix(SparseSpaceType& dummy, typename SparseSpaceType::MatrixType& A, unsigned int i1, unsigned int i2)
        {
            dummy.Resize(A, i1, i2);
        }

        template<class SparseSpaceType>
        void ResizeVector(SparseSpaceType& dummy, typename SparseSpaceType::VectorType& x, unsigned int i1)
        {
            dummy.Resize(x, i1);
        }

        template<class SparseSpaceType>
        void SetToZeroMatrix(SparseSpaceType& dummy, typename SparseSpaceType::MatrixType& A)
        {
            dummy.SetToZero(A);
        }

        template<class SparseSpaceType>
        void SetToZeroVector(SparseSpaceType& dummy, typename SparseSpaceType::VectorType& x)
        {
            dummy.SetToZero(x);
        }

        template<class SparseSpaceType>
        void ClearMatrix(SparseSpaceType& dummy, typename SparseSpaceType::MatrixPointerType& A)
        {
            dummy.Clear(A);
        }

        template<class SparseSpaceType>
        void ClearVector(SparseSpaceType& dummy, typename SparseSpaceType::VectorPointerType& x)
        {
            dummy.Clear(x);
        }

        template<class SparseSpaceType>
        typename SparseSpaceType::DataType TwoNorm(SparseSpaceType& dummy, const typename SparseSpaceType::VectorType& x)
        {
            return dummy.TwoNorm(x);
        }

        template<class SparseSpaceType>
        void UnaliasedAdd(SparseSpaceType& dummy, typename SparseSpaceType::VectorType& x, const typename SparseSpaceType::DataType A, const typename SparseSpaceType::VectorType& rY) // x+= a*Y
        {
            dummy.UnaliasedAdd(x, A, rY);
        }

        template<class SparseSpaceType>
        void CopyVector(SparseSpaceType& dummy, typename SparseSpaceType::VectorType const& rX, typename SparseSpaceType::VectorType& rY)
        {
            dummy.Copy(rX, rY);
        }

        template<class SparseSpaceType>
        void CopyMatrix(SparseSpaceType& dummy, typename SparseSpaceType::MatrixType const& rX, typename SparseSpaceType::MatrixType& rY)
        {
            dummy.Copy(rX, rY);
        }

        template<class SparseSpaceType>
        typename SparseSpaceType::MatrixPointerType CreateEmptyMatrixPointer(SparseSpaceType& dummy)
        {
            return dummy.CreateEmptyMatrixPointer();
        }

        template<class SparseSpaceType>
        typename SparseSpaceType::VectorPointerType CreateEmptyVectorPointer(SparseSpaceType& dummy)
        {
            return dummy.CreateEmptyVectorPointer();
        }

        template<class SparseSpaceType>
        void PrintMatrixInfo(SparseSpaceType& dummy, const typename SparseSpaceType::MatrixType& rA, const int level)
        {
            dummy.PrintMatrixInfo(std::cout, rA, level);
        }

        template<class SparseSpaceType>
        void PrintVectorInfo(SparseSpaceType& dummy, const typename SparseSpaceType::VectorType& rX, const int level)
        {
            dummy.PrintVectorInfo(std::cout, rX, level);
        }

        //  boost::shared_ptr< CompressedMatrix > CreateEmptyMatrixPointer()
        //  {
        //      boost::shared_ptr<CompressedMatrix> pNewMat = boost::shared_ptr<CompressedMatrix>(new CompressedMatrix() );
        //      return pNewMat;
        //  }
        //
        //  boost::shared_ptr< Vector > CreateEmptyVectorPointer()
        //  {
        //      boost::shared_ptr<Vector > pNewVec = boost::shared_ptr<Vector >(new Vector() );
        //      return pNewVec;
        //  }

        template<class CompressedMatrixType>
        CompressedMatrixType& GetMatRef(boost::shared_ptr<CompressedMatrixType>& dummy)
        {
            return *dummy;
        }

        template<class VectorType>
        VectorType& GetVecRef(boost::shared_ptr<VectorType>& dummy)
        {
            return *dummy;
        }

        template<class SparseSpaceType, class TOtherMatrixType>
        bool WriteMatrixMarketMatrix(SparseSpaceType& dummy, const char* FileName, TOtherMatrixType& M, bool Symmetric)
        {
            return dummy.WriteMatrixMarketMatrix(FileName, M, Symmetric);
        }

        template<class SparseSpaceType, class VectorType>
        bool WriteMatrixMarketVector(SparseSpaceType& dummy, const char* FileName, VectorType& V)
        {
            return dummy.WriteMatrixMarketVector(FileName, V);
        }

        template<class SparseSpaceType, class CompressedMatrixType>
        bool ReadMatrixMarketMatrixImpl(SparseSpaceType& dummy, const char* FileName, CompressedMatrixType& M)
        {
            return ReadMatrixMarketMatrix<CompressedMatrixType>(FileName, M);
        }

        template<class SparseSpaceType, class VectorType>
        bool ReadMatrixMarketVectorImpl(SparseSpaceType& dummy, const char* FileName, VectorType& M)
        {
            return ReadMatrixMarketVector<VectorType>(FileName, M);
        }

        template<typename TMatrixType>
        void AddMatrixToPython(const std::string& Name)
        {
            class_< boost::shared_ptr<TMatrixType> >(Name.c_str(), init<boost::shared_ptr<TMatrixType> >())
            .def("GetReference", GetMatRef<TMatrixType>, return_value_policy<reference_existing_object > ())
            ;
        }

        template<typename TVectorType>
        void AddVectorToPython(const std::string& Name)
        {
            class_< boost::shared_ptr<TVectorType> >(Name.c_str(), init< boost::shared_ptr<TVectorType> >())
            .def("GetReference", GetVecRef<TVectorType>, return_value_policy<reference_existing_object > ())
            ;
        }

        template<typename TSpaceType>
        void AddSpacesToPythonImpl(const std::string& Name)
        {
            class_< TSpaceType, boost::noncopyable > space(Name.c_str(), init<>());

            space
            .def("ClearMatrix", &ClearMatrix<TSpaceType>)
            .def("ClearVector", &ClearVector<TSpaceType>)
            .def("ResizeMatrix", &ResizeMatrix<TSpaceType>)
            .def("ResizeVector", &ResizeVector<TSpaceType>)
            .def("SetToZeroMatrix", &SetToZeroMatrix<TSpaceType>)
            .def("SetToZeroVector", &SetToZeroVector<TSpaceType>)
            .def("TwoNorm", &TwoNorm<TSpaceType>)
            .def("Copy", &CopyVector<TSpaceType>)
            .def("Copy", &CopyMatrix<TSpaceType>)
            //the dot product of two vectors
            .def("Dot", &Dot<TSpaceType>)
            //the matrix-vector multiplication
            .def("Mult", &Mult<TSpaceType>)
            .def("TransposeMult", &TransposeMult<TSpaceType>)
            .def("Size", &Size<TSpaceType>)
            .def("Size1", &Size1<TSpaceType>)
            .def("Size2", &Size2<TSpaceType>)
            .def("UnaliasedAdd", &UnaliasedAdd<TSpaceType>)
            .def("ScaleAndAdd", &ScaleAndAdd<TSpaceType>)
            .def("CreateEmptyMatrixPointer", &CreateEmptyMatrixPointer<TSpaceType>)
            .def("CreateEmptyVectorPointer", &CreateEmptyVectorPointer<TSpaceType>)
            .def("PrintMatrixInfo", &PrintMatrixInfo<TSpaceType>)
            .def("PrintVectorInfo", &PrintVectorInfo<TSpaceType>)
            .def(self_ns::str(self))
            ;

            if constexpr (std::is_arithmetic<typename TSpaceType::DataType>::value)
            {
                space
                .def("WriteMatrixMarketMatrix", &WriteMatrixMarketMatrix<TSpaceType, typename TSpaceType::MatrixType>)
                .def("WriteMatrixMarketVector", &WriteMatrixMarketVector<TSpaceType, typename TSpaceType::VectorType>)
                .def("ReadMatrixMarketMatrix", &ReadMatrixMarketMatrixImpl<TSpaceType, typename TSpaceType::MatrixType>)
                .def("ReadMatrixMarketVector", &ReadMatrixMarketVectorImpl<TSpaceType, typename TSpaceType::VectorType>)
                ;
            }
        }

        void AddSpacesToPython()
        {
            typedef UblasSpace<KRATOS_DOUBLE_TYPE, CompressedMatrix, Vector> UblasSparseSpaceType;
            typedef UblasSpace<KRATOS_DOUBLE_TYPE, Matrix, Vector> UblasLocalSpaceType;

            typedef UblasSpace<KRATOS_COMPLEX_TYPE, ComplexCompressedMatrix, ComplexVector> UblasComplexSparseSpaceType;
            typedef UblasSpace<KRATOS_COMPLEX_TYPE, ComplexMatrix, ComplexVector> UblasComplexLocalSpaceType;

            AddMatrixToPython<typename UblasSparseSpaceType::MatrixType>("CompressedMatrixPointer");
            AddMatrixToPython<typename UblasComplexSparseSpaceType::MatrixType>("ComplexCompressedMatrixPointer");
            AddVectorToPython<typename UblasSparseSpaceType::VectorType>("VectorPointer");
            AddVectorToPython<typename UblasComplexSparseSpaceType::VectorType>("ComplexVectorPointer");

            AddSpacesToPythonImpl<UblasSparseSpaceType>("UblasSparseSpace");
            // AddSpacesToPythonImpl<UblasLocalSpaceType>("UblasLocalSpace");
            AddSpacesToPythonImpl<UblasComplexSparseSpaceType>("ComplexUblasSparseSpace");
            // AddSpacesToPythonImpl<UblasComplexLocalSpaceType>("ComplexUblasLocalSpace");

            #ifdef _OPENMP
            typedef ParallelUblasSpace<KRATOS_DOUBLE_TYPE, CompressedMatrix, Vector> ParallelUblasSparseSpaceType;
            typedef UblasSpace<KRATOS_DOUBLE_TYPE, Matrix, Vector> ParallelUblasLocalSpaceType;

            AddSpacesToPythonImpl<ParallelUblasSparseSpaceType>("ParallelUblasSparseSpace");
            #endif
        }

    } // namespace Python.

} // Namespace Kratos
