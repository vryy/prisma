//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//

// System includes

// External includes
#include <boost/python.hpp>


// Project includes
#include "includes/define.h"
#include "geometries/point.h"
#include "includes/node.h"
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

const PointerVector< Node<3> >& ConstGetPoints( const Geometry<Node<3> >& geom ) { return geom.Points(); }

bool Geometry_IsInside1(Geometry<Node<3> >& rDummy, boost::python::list& point)
{
    Geometry<Node<3> >::CoordinatesArrayType Point;
    Point[0] = boost::python::extract<double>(point[0]);
    Point[1] = boost::python::extract<double>(point[1]);
    Point[2] = boost::python::extract<double>(point[2]);

    Geometry<Node<3> >::CoordinatesArrayType Result;
    return rDummy.IsInside(Point, Result);
}

bool Geometry_IsInside2(Geometry<Node<3> >& rDummy, Geometry<Node<3> >::CoordinatesArrayType& rPoint)
{
    Geometry<Node<3> >::CoordinatesArrayType Result;
    return rDummy.IsInside(rPoint, Result);
}

void  AddGeometriesToPython()
{

    typedef Geometry<Node<3> > GeometryType;
    class_<GeometryType, GeometryType::Pointer >("Geometry", init<>())
    .def(init< GeometryType::PointsArrayType& >())
    // .def("Points", &ConstGetPoints)
    .def("IsInside", &Geometry_IsInside1)
    .def("IsInside", &Geometry_IsInside2)
    ;

    class_<Triangle2D3<Node<3> >, Triangle2D3<Node<3> >::Pointer, bases< GeometryType > >("Triangle2D3", init<Node<3>::Pointer, Node<3>::Pointer, Node<3>::Pointer>())
    ;


//     class_<GeometryType, GeometryType::Pointer, bases<PointerVector< Node<3> > > >("Geometry", init<>())
//      .def(init< GeometryType::PointsArrayType& >())
//      ;

}

}  // namespace Python.

} // Namespace Kratos

