// Kratos Multi-Physics
//
// Copyright (c) 2016 Pooyan Dadvand, Riccardo Rossi, CIMNE (International Center for Numerical Methods in Engineering)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//  - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
//    in the documentation and/or other materials provided with the distribution.
//  - All advertising materials mentioning features or use of this software must display the following acknowledgement:
//      This product includes Kratos Multi-Physics technology.
//  - Neither the name of the CIMNE nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
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


// Project includes
#include "includes/define.h"
#include "includes/ublas_interface.h"
#include "python/matrix_python_interface.h"
#include "python/matrix_scalar_operator_python.h"
#include "python/matrix_scalar_assignment_operator_python.h"
#include "python/matrix_matrix_operator_python.h"

namespace Kratos
{

namespace Python
{

using namespace boost::python;

template<typename TDataType>
void AddMatrixToPythonImpl(const std::string& Prefix)
{
    MatrixPythonInterface<matrix<TDataType> >::CreateInterface(Prefix + "Matrix")
    .def(init<typename matrix<TDataType>::size_type, typename matrix<TDataType>::size_type>())
    /*.def(MatrixScalarOperatorPython<matrix<TDataType>, TDataType>())
      .def(MatrixScalarAssignmentOperatorPython<matrix<TDataType>, TDataType>())
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, zero_matrix<TDataType>, matrix<TDataType> >())
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, identity_matrix<TDataType>, matrix<TDataType> >())
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, scalar_matrix<TDataType>, matrix<TDataType> >())
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, banded_matrix<TDataType>, matrix<TDataType> >())
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
    #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
    #endif
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, mapped_matrix<TDataType>, matrix<TDataType> >())
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, compressed_matrix<TDataType>, matrix<TDataType> >())
    #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
          .def(MatrixMatrixOperatorPython<matrix<TDataType>, coordinate_matrix<TDataType>, matrix<TDataType> >())
    #endif*/
    ;

    MatrixPythonInterface<compressed_matrix<TDataType> >::CreateInterface(Prefix + "CompressedMatrix")
    .def(init<typename compressed_matrix<TDataType>::size_type, typename compressed_matrix<TDataType>::size_type>())
    /*      .def(MatrixScalarOperatorPython<compressed_matrix<TDataType>, TDataType>())
          .def(MatrixScalarAssignmentOperatorPython<compressed_matrix<TDataType>, TDataType>())
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, zero_matrix<TDataType>, compressed_matrix<TDataType> >())
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, identity_matrix<TDataType>, compressed_matrix<TDataType> >())
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, scalar_matrix<TDataType>, compressed_matrix<TDataType> >())
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, banded_matrix<TDataType>, banded_matrix<TDataType> >())
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
    #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
    #endif
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, mapped_matrix<TDataType>, matrix<TDataType> >())
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, matrix<TDataType>, compressed_matrix<TDataType> >())
    #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
                .def(MatrixMatrixOperatorPython<compressed_matrix<TDataType>, coordinate_matrix<TDataType>, compressed_matrix<TDataType> >())
    #endif*/
    ;

    #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
    MatrixPythonInterface<coordinate_matrix<TDataType> >::CreateInterface(Prefix + "CoordinateMatrix")
    .def(init<typename coordinate_matrix<TDataType>::size_type, typename coordinate_matrix<TDataType>::size_type>())
    .def(MatrixScalarOperatorPython<coordinate_matrix<TDataType>, TDataType>())
    .def(MatrixScalarAssignmentOperatorPython<coordinate_matrix<TDataType>, TDataType>())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, zero_matrix<TDataType>, coordinate_matrix<TDataType> >())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, identity_matrix<TDataType>, coordinate_matrix<TDataType> >())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, scalar_matrix<TDataType>, coordinate_matrix<TDataType> >())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, banded_matrix<TDataType>, banded_matrix<TDataType> >())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
#if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
#endif
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, mapped_matrix<TDataType>, mapped_matrix<TDataType> >())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, compressed_matrix<TDataType>, compressed_matrix<TDataType> >())
    .def(MatrixMatrixOperatorPython<coordinate_matrix<TDataType>, matrix<TDataType>, matrix<TDataType> >())
    ;
    #endif

    ReadonlyMatrixPythonInterface<identity_matrix<TDataType> >::CreateInterface(Prefix + "IdentityMatrix")
    .def(init<typename identity_matrix<TDataType>::size_type>())
    .def(init<typename identity_matrix<TDataType>::size_type, typename identity_matrix<TDataType>::size_type>())
//      .def(MatrixScalarOperatorPython<identity_matrix<TDataType>, TDataType, matrix<TDataType>, matrix<TDataType> >())
//      .def(MatrixVectorOperatorPython<identity_matrix<TDataType>, vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<identity_matrix<TDataType>, zero_vector<TDataType>, vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<identity_matrix<TDataType>, unit_vector<TDataType>, vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<identity_matrix<TDataType>, scalar_vector<TDataType>, vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<identity_matrix<TDataType>, mapped_vector<TDataType>  >())
//      .def(MatrixVectorOperatorPython<identity_matrix<TDataType>, compressed_vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<identity_matrix<TDataType>, coordinate_vector<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, zero_matrix<TDataType>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, identity_matrix<TDataType>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, scalar_matrix<TDataType>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, matrix<TDataType>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, banded_matrix<TDataType>, banded_matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
// #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
// #endif
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, mapped_matrix<TDataType>, mapped_matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, compressed_matrix<TDataType>, compressed_matrix<TDataType> >())
// #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
//            .def(MatrixMatrixOperatorPython<identity_matrix<TDataType>, coordinate_matrix<TDataType>, coordinate_matrix<TDataType> >())
// #endif
    ;

    ReadonlyMatrixPythonInterface<zero_matrix<TDataType> >::CreateInterface(Prefix + "ZeroMatrix")
    .def(init<typename zero_matrix<TDataType>::size_type>())
    .def(init<typename zero_matrix<TDataType>::size_type, typename zero_matrix<TDataType>::size_type>())
//      .def(MatrixScalarOperatorPython<zero_matrix<TDataType>, TDataType, matrix<TDataType>, matrix<TDataType> >())
//      .def(MatrixVectorOperatorPython<zero_matrix<TDataType>, vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<zero_matrix<TDataType>, zero_vector<TDataType>, vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<zero_matrix<TDataType>, unit_vector<TDataType>, vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<zero_matrix<TDataType>, scalar_vector<TDataType>, vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<zero_matrix<TDataType>, mapped_vector<TDataType>  >())
//      .def(MatrixVectorOperatorPython<zero_matrix<TDataType>, compressed_vector<TDataType> >())
//      .def(MatrixVectorOperatorPython<zero_matrix<TDataType>, coordinate_vector<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, zero_matrix<TDataType>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, identity_matrix<TDataType>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, scalar_matrix<TDataType>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, matrix<TDataType>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, banded_matrix<TDataType>, banded_matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
// #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
// #endif
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, mapped_matrix<TDataType>, mapped_matrix<TDataType> >())
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, compressed_matrix<TDataType>, compressed_matrix<TDataType> >())
// #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
//            .def(MatrixMatrixOperatorPython<zero_matrix<TDataType>, coordinate_matrix<TDataType>, coordinate_matrix<TDataType> >())
// #endif
     ;

    ReadonlyMatrixPythonInterface<scalar_matrix<TDataType> >::CreateInterface(Prefix + "ScalarMatrix")
    .def(init<typename scalar_matrix<TDataType>::size_type, typename scalar_matrix<TDataType>::size_type>())
    .def(init<typename scalar_matrix<TDataType>::size_type, typename scalar_matrix<TDataType>::size_type, typename scalar_matrix<TDataType>::value_type>())
    // .def(MatrixScalarOperatorPython<scalar_matrix<TDataType>, TDataType, matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixVectorOperatorPython<scalar_matrix<TDataType>, vector<TDataType> >())
    // .def(MatrixVectorOperatorPython<scalar_matrix<TDataType>, zero_vector<TDataType>, vector<TDataType> >())
    // .def(MatrixVectorOperatorPython<scalar_matrix<TDataType>, unit_vector<TDataType>, vector<TDataType> >())
    // .def(MatrixVectorOperatorPython<scalar_matrix<TDataType>, scalar_vector<TDataType>, vector<TDataType> >())
    // .def(MatrixVectorOperatorPython<scalar_matrix<TDataType>, mapped_vector<TDataType>  >())
    // .def(MatrixVectorOperatorPython<scalar_matrix<TDataType>, compressed_vector<TDataType> >())
    // .def(MatrixVectorOperatorPython<scalar_matrix<TDataType>, coordinate_vector<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, zero_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, identity_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, scalar_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, banded_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
    // #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
    // #endif
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, mapped_matrix<TDataType>, mapped_matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, compressed_matrix<TDataType>, compressed_matrix<TDataType> >())
    // #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<scalar_matrix<TDataType>, coordinate_matrix<TDataType>, coordinate_matrix<TDataType> >())
    // #endif
    ;

    MatrixPythonInterface<mapped_matrix<TDataType> >::CreateInterface(Prefix + "SparseMatrix")
    .def(init<typename mapped_matrix<TDataType>::size_type, typename mapped_matrix<TDataType>::size_type>())
    // .def(MatrixScalarOperatorPython<mapped_matrix<TDataType>, TDataType>())
    // .def(MatrixScalarAssignmentOperatorPython<mapped_matrix<TDataType>, TDataType>())
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, zero_matrix<TDataType>, mapped_matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, identity_matrix<TDataType>, mapped_matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, scalar_matrix<TDataType>, mapped_matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, banded_matrix<TDataType>, banded_matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
    // #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
    // #endif
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, compressed_matrix<TDataType>, compressed_matrix<TDataType> >())
    // #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<mapped_matrix<TDataType>, coordinate_matrix<TDataType>, mapped_matrix<TDataType> >())
    // #endif
    ;

    MatrixPythonInterface<banded_matrix<TDataType> >::CreateInterface(Prefix + "BandedMatrix")
    .def(init<typename banded_matrix<TDataType>::size_type, typename banded_matrix<TDataType>::size_type>())
    .def(init<typename banded_matrix<TDataType>::size_type, typename banded_matrix<TDataType>::size_type, typename banded_matrix<TDataType>::size_type, typename banded_matrix<TDataType>::size_type>())
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, zero_matrix<TDataType>, banded_matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, identity_matrix<TDataType>, banded_matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, scalar_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
    // #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
    // #endif
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, mapped_matrix<TDataType>, banded_matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, compressed_matrix<TDataType>, banded_matrix<TDataType> >())
    // #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<banded_matrix<TDataType>, coordinate_matrix<TDataType>, banded_matrix<TDataType> >())
    // #endif
    ;

    MatrixPythonInterface<triangular_matrix<TDataType, upper>, upper>::CreateInterface(Prefix + "UpperTriangularMatrix")
    .def(init<typename triangular_matrix<TDataType, upper>::size_type, typename triangular_matrix<TDataType, upper>::size_type>())
    // .def(MatrixScalarOperatorPython<triangular_matrix<TDataType, upper>, TDataType, matrix<TDataType> >())
    ;

    MatrixPythonInterface<triangular_matrix<TDataType, lower>, lower>::CreateInterface(Prefix + "LowerTriangularMatrix")
    .def(init<typename triangular_matrix<TDataType, lower>::size_type, typename triangular_matrix<TDataType, lower>::size_type>())
    // .def(MatrixScalarOperatorPython<triangular_matrix<TDataType, lower>, TDataType, matrix<TDataType> >())
    ;

    MatrixPythonInterface<symmetric_matrix<TDataType, upper>, upper>::CreateInterface(Prefix + "SymmetricMatrix")
    .def(init<typename symmetric_matrix<TDataType, upper>::size_type>())
    .def(init<typename symmetric_matrix<TDataType, upper>::size_type, typename symmetric_matrix<TDataType, upper>::size_type>())
    // .def(MatrixScalarOperatorPython<symmetric_matrix<TDataType, upper>, TDataType>())
    // .def(MatrixScalarAssignmentOperatorPython<symmetric_matrix<TDataType, upper>, TDataType>())
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, zero_matrix<TDataType>, symmetric_matrix<TDataType, upper> >())
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, identity_matrix<TDataType>, symmetric_matrix<TDataType, upper> >())
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, scalar_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, banded_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, matrix<TDataType>, matrix<TDataType> >())
    // #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, hermitian_matrix<TDataType, upper>, matrix<TDataType> >())
    // #endif
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, mapped_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, compressed_matrix<TDataType>, matrix<TDataType> >())
    // #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<symmetric_matrix<TDataType, upper>, coordinate_matrix<TDataType>, matrix<TDataType> >())
    // #endif
    ;

    #if defined KRATOS_ADD_HERMITIAN_MATRIX_INTERFACE
    MatrixPythonInterface<hermitian_matrix<TDataType, upper>, upper>::CreateInterface(Prefix + "HermitianMatrix")
    .def(init<typename hermitian_matrix<TDataType, upper>::size_type>())
    .def(init<typename hermitian_matrix<TDataType, upper>::size_type, typename hermitian_matrix<TDataType, upper>::size_type>())
    // .def(MatrixScalarOperatorPython<hermitian_matrix<TDataType, upper>, TDataType>())
    // .def(MatrixScalarAssignmentOperatorPython<hermitian_matrix<TDataType, upper>, TDataType>())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, zero_matrix<TDataType>, hermitian_matrix<TDataType, upper> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, identity_matrix<TDataType>, hermitian_matrix<TDataType, upper> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, scalar_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, banded_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, triangular_matrix<TDataType, upper>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, triangular_matrix<TDataType, lower>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, symmetric_matrix<TDataType, upper>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, mapped_matrix<TDataType>, matrix<TDataType> >())
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, compressed_matrix<TDataType>, matrix<TDataType> >())
    // #if defined KRATOS_ADD_COORDINATE_MATRIX_INTERFACE
    // .def(MatrixMatrixOperatorPython<hermitian_matrix<TDataType, upper>, coordinate_matrix<TDataType>, matrix<TDataType> >())
    // #endif
    ;
    #endif
}

void AddMatrixToPython()
{
    AddMatrixToPythonImpl<KRATOS_DOUBLE_TYPE>("");
    AddMatrixToPythonImpl<KRATOS_COMPLEX_TYPE>("Complex");
}

}  // namespace Python.

} // Namespace Kratos
