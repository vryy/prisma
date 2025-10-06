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


//
//   Project Name:        Kratos
//   Last modified by:    $Author: rrossi $
//   Date:                $Date: 2007-03-06 10:30:34 $
//   Revision:            $Revision: 1.2 $
//
//


// System includes

// External includes
#include <boost/python.hpp>


// Project includes
#include "includes/define.h"
#include "geometries/point.h"
#include "python/add_points_to_python.h"
#include "python/bounded_vector_python_interface.h"
#include "python/vector_scalar_operator_python.h"
#include "python/vector_vector_operator_python.h"

namespace Kratos
{

namespace Python
{
template<class TPointType> inline
void PointSetX(TPointType& ThisPoint, typename TPointType::DataType Value)
{
    ThisPoint.X() = Value;
}

template<class TPointType> inline
void PointSetY(TPointType& ThisPoint, typename TPointType::DataType Value)
{
    ThisPoint.Y() = Value;
}

template<class TPointType> inline
void PointSetZ(TPointType& ThisPoint, typename TPointType::DataType Value)
{
    ThisPoint.Z() = Value;
}

template<class TPointType> inline
typename TPointType::DataType PointGetX(TPointType& ThisPoint)
{
    return ThisPoint.X();
}

template<class TPointType> inline
typename TPointType::DataType PointGetY(TPointType& ThisPoint)
{
    return ThisPoint.Y();
}

template<class TPointType> inline
typename TPointType::DataType PointGetZ(TPointType& ThisPoint)
{
    return ThisPoint.Z();
}

template<int TDim, typename TDataType>
void AddPointsToPythonImpl(const std::string& Name)
{
    typedef Point<TDim, TDataType> PointType;

    auto p = BoundedVectorPythonInterface<PointType, 3>::CreateInterface(Name.c_str());

    p.def(init<TDataType>())
    .def(init<TDataType, TDataType>())
    .def(init<TDataType, TDataType, TDataType>())
#ifdef KRATOS_USE_BOOST_UBLAS_FOR_LINEAR_ALGEBRA
    .def(init<vector_expression<vector<TDataType> > >())
#endif
    .def(VectorScalarOperatorPython<PointType, TDataType, PointType >())
    .def(VectorVectorOperatorPython<PointType, zero_vector<TDataType>, PointType >())
    .def(VectorVectorOperatorPython<PointType, unit_vector<TDataType>, PointType >())
    .def(VectorVectorOperatorPython<PointType, scalar_vector<TDataType>, PointType >())
    .def(VectorVectorOperatorPython<PointType, vector<TDataType>, PointType >())
    // .def(VectorVectorOperatorPython<PointType, mapped_vector<TDataType>, PointType >())
    // .def(VectorVectorOperatorPython<PointType, compressed_vector<TDataType>, PointType >())
    // .def(VectorVectorOperatorPython<PointType, coordinate_vector<TDataType>, PointType >())
    ;

    if constexpr (TDim > 0)
        p.add_property("X", PointGetX<PointType>, PointSetX<PointType>);
    if constexpr (TDim > 1)
        p.add_property("Y", PointGetY<PointType>, PointSetY<PointType>);
    if constexpr (TDim > 2)
        p.add_property("Z", PointGetZ<PointType>, PointSetZ<PointType>);
}

void AddPointsToPython()
{
    AddPointsToPythonImpl<1, KRATOS_DOUBLE_TYPE>("Point1D");
    AddPointsToPythonImpl<2, KRATOS_DOUBLE_TYPE>("Point2D");
    AddPointsToPythonImpl<3, KRATOS_DOUBLE_TYPE>("Point3D");
    AddPointsToPythonImpl<1, KRATOS_COMPLEX_TYPE>("ComplexPoint1D");
    AddPointsToPythonImpl<2, KRATOS_COMPLEX_TYPE>("ComplexPoint2D");
    AddPointsToPythonImpl<3, KRATOS_COMPLEX_TYPE>("ComplexPoint3D");
}

}  // namespace Python.

} // Namespace Kratos

