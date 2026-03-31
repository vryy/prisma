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

// System includes

// External includes

// Project includes
#include "includes/define_python.h"
#include "includes/element.h"
#include "geometries/point.h"
#include "geometries/geometry.h"
#include "geometries/triangle_2d_3.h"
#include "python/add_geometries_to_python.h"
#include "python/bounded_vector_python_interface.h"
#include "python/vector_scalar_operator_python.h"
#include "python/vector_vector_operator_python.h"

namespace Kratos
{

namespace Python
{


template<class TGeometryType>
bool Geometry_IsInside1(TGeometryType& rDummy, boost::python::list& point)
{
    typename TGeometryType::CoordinatesArrayType Point;
    Point[0] = boost::python::extract<double>(point[0]);
    Point[1] = boost::python::extract<double>(point[1]);
    Point[2] = boost::python::extract<double>(point[2]);

    typename TGeometryType::CoordinatesArrayType Result;
    return rDummy.IsInside(Point, Result);
}

template<class TGeometryType>
bool Geometry_IsInside2(TGeometryType& rDummy, typename TGeometryType::CoordinatesArrayType& rPoint)
{
    typename TGeometryType::CoordinatesArrayType Result;
    return rDummy.IsInside(rPoint, Result);
}

void  AddGeometriesToPython()
{

    typedef Element::GeometryType GeometryType;
    typedef typename GeometryType::PointType NodeType;

    class_<GeometryType, typename GeometryType::Pointer>("Geometry", init<>())
    .def(init< typename GeometryType::PointsArrayType& >())
    // .def("Points", &ConstGetPoints)
    .def("IsInside", &Geometry_IsInside1<GeometryType>)
    .def("IsInside", &Geometry_IsInside2<GeometryType>)
    .def("Center", &GeometryType::Center)
    ;

    class_<Triangle2D3<NodeType>, Triangle2D3<NodeType>::Pointer, bases< GeometryType > >("Triangle2D3", init<NodeType::Pointer, NodeType::Pointer, NodeType::Pointer>())
    ;

}

}  // namespace Python.

} // Namespace Kratos

