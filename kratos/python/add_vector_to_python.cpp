// Kratos Multi-Physics
//
// Copyright (c) 2016 Pooyan Dadvand, Riccardo Rossi, CIMNE (International Center for Numerical Methods in Engineering)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
// 	-	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// 	-	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
// 		in the documentation and/or other materials provided with the distribution.
// 	-	All advertising materials mentioning features or use of this software must display the following acknowledgement:
// 			This product includes Kratos Multi-Physics technology.
// 	-	Neither the name of the CIMNE nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
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
#include "containers/array_1d.h"
#include "python/add_vector_to_python.h"
#include "python/vector_python_interface.h"
#include "python/vector_scalar_operator_python.h"
#include "python/vector_vector_operator_python.h"

namespace Kratos
{

namespace Python
{

using namespace boost::python;

template<class TContainerType>
struct UblasVectorModifier
{
    typedef typename TContainerType::size_type index_type;
    static void Resize(TContainerType& ThisContainer, typename TContainerType::size_type NewSize)
    {
        ThisContainer.resize(NewSize, true);
    }
    static void MoveSlice(TContainerType& ThisContainer, index_type Index, index_type From, index_type To)
    {
        if(Index > From)
        {
            ThisContainer.resize(ThisContainer.size() + Index - From, true);
            std::copy_backward(ThisContainer.begin() + From, ThisContainer.begin() + To, ThisContainer.begin() + Index + To - From);
        }
        else
        {
            std::copy(ThisContainer.begin() + From, ThisContainer.begin() + To, ThisContainer.begin() + Index);
            ThisContainer.resize(ThisContainer.size() + Index - From, true);
        }
    }
};

template<typename TDataType>
void AddVectorToPythonImpl(const std::string& Prefix)
{
    ReadonlyVectorPythonInterface<zero_vector<TDataType> >::CreateInterface(Prefix + "ZeroVector")
    .def(init<typename zero_vector<TDataType>::size_type>())
//       .def(VectorScalarOperatorPython<zero_vector<TDataType>, TDataType, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<zero_vector<TDataType>, unit_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<zero_vector<TDataType>, scalar_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<zero_vector<TDataType>, vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<zero_vector<TDataType>, mapped_vector<TDataType>, mapped_vector<TDataType> >())
//       .def(VectorVectorOperatorPython<zero_vector<TDataType>, compressed_vector<TDataType>, compressed_vector<TDataType> >())
//       .def(VectorVectorOperatorPython<zero_vector<TDataType>, coordinate_vector<TDataType>, coordinate_vector<TDataType> >())
    ;

    ReadonlyVectorPythonInterface<unit_vector<TDataType> >::CreateInterface(Prefix + "UnitVector")
    .def(init<typename unit_vector<TDataType>::size_type, typename vector<TDataType>::size_type>())
//       .def(VectorScalarOperatorPython<unit_vector<TDataType>, TDataType, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<unit_vector<TDataType>, zero_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<unit_vector<TDataType>, scalar_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<unit_vector<TDataType>, vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<unit_vector<TDataType>, mapped_vector<TDataType>, mapped_vector<TDataType> >())
//       .def(VectorVectorOperatorPython<unit_vector<TDataType>, compressed_vector<TDataType>, compressed_vector<TDataType> >())
//       .def(VectorVectorOperatorPython<unit_vector<TDataType>, coordinate_vector<TDataType>, coordinate_vector<TDataType> >())
    ;

    ReadonlyVectorPythonInterface<scalar_vector<TDataType> >::CreateInterface(Prefix + "ScalarVector")
    .def(init<typename scalar_vector<TDataType>::size_type, typename scalar_vector<TDataType>::value_type>())
//       .def(VectorScalarOperatorPython<scalar_vector<TDataType>, TDataType, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<scalar_vector<TDataType>, zero_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<scalar_vector<TDataType>, unit_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<scalar_vector<TDataType>, vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<scalar_vector<TDataType>, mapped_vector<TDataType>, mapped_vector<TDataType> >())
//       .def(VectorVectorOperatorPython<scalar_vector<TDataType>, compressed_vector<TDataType>, compressed_vector<TDataType> >())
//       .def(VectorVectorOperatorPython<scalar_vector<TDataType>, coordinate_vector<TDataType>, coordinate_vector<TDataType> >())
    ;

    VectorPythonInterface<vector<TDataType>, UblasVectorModifier<vector<TDataType> > >::CreateInterface(Prefix + "Vector")
    .def(init<typename vector<TDataType>::size_type>())
    .def(init<vector_expression<vector<TDataType> > >())
    .def(init<array_1d<TDataType, 3> >())
    .def(VectorScalarOperatorPython<vector<TDataType>, TDataType, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<vector<TDataType>, zero_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<vector<TDataType>, unit_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<vector<TDataType>, scalar_vector<TDataType>, vector<TDataType> >())
//       .def(VectorVectorOperatorPython<vector<TDataType>, mapped_vector<TDataType>, vector<TDataType> >())
   ;
}

void AddVectorToPython()
{
    VectorPythonInterface<vector<int>, UblasVectorModifier<vector<int> > >::CreateInterface("IntegerVector")
    .def(init<vector<int>::size_type>())
    ;

    AddVectorToPythonImpl<KRATOS_DOUBLE_TYPE>("");
    AddVectorToPythonImpl<KRATOS_COMPLEX_TYPE>("Complex");
}

}  // namespace Python.

} // Namespace Kratos

