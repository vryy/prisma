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
#include "includes/model_part.h"
#include "includes/mesh.h"
#include "includes/properties.h"
#include "includes/element.h"
#include "includes/condition.h"
#include "python/add_mesh_to_python.h"
#include "python/pointer_vector_set_python_interface.h"
//#include "python/variable_indexing_python.h"
//#include "python/solution_step_variable_indexing_python.h"

namespace Kratos
{

namespace Python
{

using namespace boost::python;

template< class TContainerType, class TVariableType >
bool HasHelperFunction(TContainerType& el, const TVariableType& rVar)
{
    return el.Has(rVar);
}

template< class TContainerType, class TVariableType >
void SetValueHelperFunction(TContainerType& el, const TVariableType& rVar,const typename TVariableType::Type& Data)
{
    el.SetValue(rVar, Data);
}

template< class TContainerType, class TVariableType >
typename TVariableType::Type GetValueHelperFunction(TContainerType& el, const TVariableType& rVar)
{
    return el.GetValue(rVar);
}

template<class TEntityType>
typename TEntityType::DataType GetAreaFromEntity( TEntityType& dummy )
{
    return( dummy.GetGeometry().Area() );
}

template<class TEntityType>
Properties::Pointer GetPropertiesFromEntity( TEntityType& elem )
{
    return( elem.pGetProperties() );
}

template<class TEntityType>
void SetPropertiesForEntity( TEntityType& elem, Properties::Pointer pProperties )
{
    elem.SetProperties(pProperties);
}

template<class TEntityType>
typename TEntityType::NodeType::Pointer GetNodeFromEntity( TEntityType& dummy, unsigned int index )
{
    return( dummy.GetGeometry().pGetPoint(index) );
}

template<class TEntityType>
boost::python::list GetNodesFromEntity( TEntityType& dummy )
{
    boost::python::list nodes_list;
    for( unsigned int i = 0; i < dummy.GetGeometry().size(); i++ )
    {
        nodes_list.append( dummy.GetGeometry().pGetPoint(i) );
    }
    return( nodes_list );
}

template<class TEntityType>
typename TEntityType::GeometryType::Pointer GetGeometryFromEntity( TEntityType& dummy )
{
    return dummy.pGetGeometry();
}

template<class TEntityType>
int GetIntegrationMethodFromEntity( TEntityType& dummy )
{
    return static_cast<int>(dummy.GetIntegrationMethod());
}

template<class TEntityType>
boost::python::list GetIntegrationPointsFromEntity( TEntityType& dummy )
{
    boost::python::list integration_points_list;
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    for( unsigned int i=0; i< integration_points.size(); i++ )
    {
        boost::python::list item;
        typename TEntityType::GeometryType::CoordinatesArrayType pnt;
        dummy.GetGeometry().GlobalCoordinates(pnt, integration_points[i]);
        for( unsigned int j=0; j<3; j++ )
            item.append( pnt[j] );
        integration_points_list.append( item );
    }
    return( integration_points_list );
}

template<class TEntityType>
boost::python::list GetIntegrationPointsFromEntityInReferenceFrame( TEntityType& dummy )
{
    boost::python::list integration_points_list;
    const typename TEntityType::GeometryType::IntegrationPointsArrayType& integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    typename TEntityType::GeometryType::MatrixType DeltaPosition(dummy.GetGeometry().size(), dummy.GetGeometry().WorkingSpaceDimension());
    for (std::size_t i = 0; i < dummy.GetGeometry().size(); ++i)
        for (std::size_t j = 0; j < dummy.GetGeometry().WorkingSpaceDimension(); ++j)
            DeltaPosition(i, j) = dummy.GetGeometry()[i].Coordinates()[j] - dummy.GetGeometry()[i].GetInitialPosition()[j];
    for( unsigned int i=0; i< integration_points.size(); i++ )
    {
        boost::python::list item;
        typename TEntityType::GeometryType::CoordinatesArrayType pnt;
        dummy.GetGeometry().GlobalCoordinates(pnt, integration_points[i], DeltaPosition);
        for( unsigned int j=0; j<3; j++ )
            item.append( pnt[j] );
        integration_points_list.append( item );
    }
    return( integration_points_list );
}

template<class TEntityType>
boost::python::list GetIntegrationPointsFromEntityInLocalCoordinates( TEntityType& dummy )
{
    boost::python::list integration_points_list;
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    for( unsigned int i=0; i< integration_points.size(); i++ )
    {
        integration_points_list.append( integration_points[i] );
    }
    return( integration_points_list );
}

template<class TEntityType>
boost::python::list GetIntegrationPointsLocalCoordinatesFromEntity( TEntityType& dummy )
{
    boost::python::list integration_points_list;
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points = dummy.GetGeometry().IntegrationPoints(
                dummy.GetIntegrationMethod() );
    for( unsigned int i=0; i < integration_points.size(); i++ )
    {
        const auto& p = integration_points[i];
        integration_points_list.append( p );
    }
    return( integration_points_list );
}

template<class TEntityType, typename TDataType>
boost::python::list GetValuesOnIntegrationPointsDouble( TEntityType& dummy,
        const Variable<TDataType>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    boost::python::list values_list;
    std::vector<TDataType> values;
    dummy.CalculateOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
    for( unsigned int i=0; i<values.size(); i++ )
    {
        boost::python::list integration_point_value;
        integration_point_value.append( values[i] );
        values_list.append( integration_point_value );
    }
    return( values_list );
}

template<class TEntityType, typename TDataType>
boost::python::list CalculateOnIntegrationPointsDouble( TEntityType& dummy,
        const Variable<TDataType>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    return GetValuesOnIntegrationPointsDouble<TEntityType, TDataType>(dummy, rVariable, rCurrentProcessInfo);
}

template<class TEntityType, typename TDataType>
void SetValuesOnIntegrationPointsDouble( TEntityType& dummy, const Variable<TDataType>& rVariable,
        boost::python::list values_list, const ProcessInfo& rCurrentProcessInfo )
{
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    if (boost::python::len(values_list) != integration_points.size())
        KRATOS_ERROR << "Incompatiable number of integration points and given values";
    std::vector<TDataType> values( integration_points.size() );
    for( unsigned int i=0; i<integration_points.size(); i++ )
    {
        boost::python::extract<TDataType> x( values_list[i] );
        if( x.check() )
        {
            values[i] = x();
        }
        else
            break;
    }
    dummy.SetValuesOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
}

template<class TEntityType>
boost::python::list GetValuesOnIntegrationPointsInt( TEntityType& dummy,
        const Variable<int>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    boost::python::list values_list;
    std::vector<int> values;
    dummy.CalculateOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
    for( unsigned int i=0; i<values.size(); i++ )
    {
        boost::python::list integration_point_value;
        integration_point_value.append( values[i] );
        values_list.append( integration_point_value );
    }
    return( values_list );
}

template<class TEntityType>
boost::python::list CalculateOnIntegrationPointsInt( TEntityType& dummy,
        const Variable<int>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    return GetValuesOnIntegrationPointsInt<TEntityType>(dummy, rVariable, rCurrentProcessInfo);
}

template<class TEntityType>
void SetValuesOnIntegrationPointsInt( TEntityType& dummy, const Variable<int>& rVariable, boost::python::list values_list,  const ProcessInfo& rCurrentProcessInfo )
{
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    if (boost::python::len(values_list) != integration_points.size())
        KRATOS_ERROR << "Incompatiable number of integration points and given values "
                     << boost::python::len(values_list) << " != " << integration_points.size();
    std::vector<int> values( integration_points.size() );
    for( unsigned int i=0; i<integration_points.size(); i++ )
    {
        boost::python::extract<int> x( values_list[i] );
        if( x.check() )
        {
            values[i] = x();
        }
        else
            break;
    }
    dummy.SetValuesOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
}

template<class TEntityType>
boost::python::list GetValuesOnIntegrationPointsBool( TEntityType& dummy,
        const Variable<bool>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    boost::python::list values_list;
    std::vector<bool> values;
    dummy.CalculateOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
    for( unsigned int i=0; i<values.size(); i++ )
    {
        boost::python::list integration_point_value;
        integration_point_value.append( values[i] );
        values_list.append( integration_point_value );
    }
    return( values_list );
}

// template<class TEntityType>
// boost::python::list CalculateOnIntegrationPointsInt( TEntityType& dummy,
//         const Variable<int>& rVariable, const ProcessInfo& rCurrentProcessInfo )
// {
//     return GetValuesOnIntegrationPointsInt<TEntityType>(dummy, rVariable, rCurrentProcessInfo);
// }

template<class TEntityType>
void SetValuesOnIntegrationPointsBool( TEntityType& dummy, const Variable<bool>& rVariable, boost::python::list values_list,  const ProcessInfo& rCurrentProcessInfo )
{
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    if (boost::python::len(values_list) != integration_points.size())
        KRATOS_ERROR << "Incompatiable number of integration points and given values "
                     << boost::python::len(values_list) << " != " << integration_points.size();
    std::vector<bool> values( integration_points.size() );
    for( unsigned int i=0; i<integration_points.size(); i++ )
    {
        boost::python::extract<bool> x( values_list[i] );
        if( x.check() )
        {
            values[i] = x();
        }
        else
            break;
    }
    dummy.SetValuesOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
}

template<class TEntityType>
boost::python::list GetValuesOnIntegrationPointsString( TEntityType& dummy,
        const Variable<std::string>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    boost::python::list values_list;
    std::vector<std::string> values;
    dummy.CalculateOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
    for( unsigned int i=0; i<values.size(); i++ )
    {
        values_list.append( values[i] );
    }
    return( values_list );
}

template<class TEntityType>
boost::python::list CalculateOnIntegrationPointsString( TEntityType& dummy,
        const Variable<std::string>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    return GetValuesOnIntegrationPointsString<TEntityType>(dummy, rVariable, rCurrentProcessInfo);
}

template<class TEntityType>
void SetValuesOnIntegrationPointsString( TEntityType& dummy, const Variable<std::string>& rVariable, boost::python::list values_list,  const ProcessInfo& rCurrentProcessInfo )
{
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points
            = dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    if (boost::python::len(values_list) != integration_points.size())
        KRATOS_ERROR << "Incompatiable number of integration points and given values "
                     << boost::python::len(values_list) << " != " << integration_points.size();
    std::vector<std::string> values( integration_points.size() );
    for( unsigned int i=0; i<integration_points.size(); i++ )
    {
        boost::python::extract<std::string> x( values_list[i] );
        if( x.check() )
        {
            values[i] = x();
        }
        else
            break;
    }
    dummy.SetValuesOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
}

template<class TEntityType, typename TDataType>
boost::python::list GetValuesOnIntegrationPointsArray1d( TEntityType& dummy,
        const Variable<array_1d<TDataType, 3> >& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    boost::python::list values_list;
    std::vector<array_1d<TDataType, 3> > values;
    dummy.CalculateOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
    for( unsigned int i=0; i<values.size(); i++ )
    {
        boost::python::list integration_point_value;
        for( int j=0; j<3; j++ )
            integration_point_value.append( values[i][j] );
        values_list.append( integration_point_value );
    }
    return( values_list );
}

template<class TEntityType, typename TDataType>
boost::python::list CalculateOnIntegrationPointsArray1d( TEntityType& dummy,
        const Variable<array_1d<TDataType, 3> >& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    return GetValuesOnIntegrationPointsArray1d<TEntityType, TDataType>(dummy, rVariable, rCurrentProcessInfo);
}

template<class TEntityType, typename TDataType>
void SetValuesOnIntegrationPointsArray1d( TEntityType& dummy, const Variable< array_1d<TDataType, 3> >& rVariable, boost::python::list values_list,  const ProcessInfo& rCurrentProcessInfo )
{
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    if (boost::python::len(values_list) != integration_points.size())
        KRATOS_ERROR << "Incompatiable number of integration points and given values "
                     << boost::python::len(values_list) << " != " << integration_points.size();
    std::vector< array_1d<TDataType, 3> > values( integration_points.size() );
    for( unsigned int i=0; i<integration_points.size(); i++ )
    {
        boost::python::extract< array_1d<TDataType, 3> > x( values_list[i] );
        if( x.check() )
        {
            values[i] = x();
        }
        else
            break;
    }
    dummy.SetValuesOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
}

template<class TEntityType, typename TVectorType>
boost::python::list GetValuesOnIntegrationPointsVector( TEntityType& dummy,
        const Variable<TVectorType>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    boost::python::list values_list;
    std::vector<TVectorType> values;
    dummy.CalculateOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
    for( unsigned int i=0; i<values.size(); i++ )
    {
        boost::python::list integration_point_value;
        for( unsigned int j=0; j<values[i].size(); j++ )
            integration_point_value.append( values[i][j] );
        values_list.append( integration_point_value );
    }
    return( values_list );
}

template<class TEntityType, typename TVectorType>
boost::python::list CalculateOnIntegrationPointsVector( TEntityType& dummy,
        const Variable<TVectorType>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    return GetValuesOnIntegrationPointsVector<TEntityType, TVectorType>(dummy, rVariable, rCurrentProcessInfo);
}

template<class TEntityType, typename TVectorType>
void SetValuesOnIntegrationPointsVector( TEntityType& dummy,
        const Variable<TVectorType>& rVariable, boost::python::list values_list, unsigned int len_values_list_item, const ProcessInfo& rCurrentProcessInfo )
{
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    if (boost::python::len(values_list) != integration_points.size())
        KRATOS_ERROR << "Incompatiable number of integration points and given values "
                     << boost::python::len(values_list) << " != " << integration_points.size();
    std::vector<TVectorType> values( integration_points.size() );
    for( unsigned int i=0; i<integration_points.size(); i++ )
    {
        TVectorType value_item(len_values_list_item);
        value_item.clear();
        for( unsigned int j=0; j<len_values_list_item; j++ )
        {
            boost::python::extract<typename TVectorType::value_type> x( values_list[i][j] );
            if( x.check() )
            {
                value_item[j] = x();
            }
            else
                break;
        }
        values[i] = value_item;
    }
    dummy.SetValuesOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
}

template<class TEntityType, typename TVectorType>
void SetValuesOnIntegrationPointsVectorVariableLength( TEntityType& dummy,
        const Variable<TVectorType>& rVariable, boost::python::list values_list, boost::python::list len_values_list_item, const ProcessInfo& rCurrentProcessInfo )
{
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    if (boost::python::len(values_list) != integration_points.size())
        KRATOS_ERROR << "Incompatiable number of integration points and given values "
                     << boost::python::len(values_list) << " != " << integration_points.size();
    std::vector<TVectorType> values( integration_points.size() );
    for( unsigned int i=0; i<integration_points.size(); i++ )
    {
        boost::python::extract<int> len( len_values_list_item[i] );
        if( len.check() )
        {
            TVectorType value_item(len());
            value_item.clear();
            boost::python::extract<TVectorType> x(values_list[i]);
            if( x.check() )
            {
                values[i] = x();
            }
            else
                break;
        }
        else
            break;
    }
    dummy.SetValuesOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
}

template<class TEntityType, typename TMatrixType>
boost::python::list GetValuesOnIntegrationPointsMatrix( TEntityType& dummy,
        const Variable<TMatrixType>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    boost::python::list values_list;
    std::vector<TMatrixType> values;
    dummy.CalculateOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
    for( unsigned int i=0; i<values.size(); i++ )
    {
        boost::python::list integration_point_value;
        for( unsigned int j=0; j<values[i].size1(); j++ )
            for( unsigned int k=0; k<values[i].size2(); k++ )
                integration_point_value.append( values[i](j,k) );
        values_list.append( integration_point_value );
    }
    return( values_list );
}

template<class TEntityType, typename TMatrixType>
boost::python::list CalculateOnIntegrationPointsMatrix( TEntityType& dummy,
        const Variable<TMatrixType>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    return GetValuesOnIntegrationPointsMatrix<TEntityType, TMatrixType>(dummy, rVariable, rCurrentProcessInfo);
}

template<class TEntityType, typename TDataType>
TDataType ElementCalculateInterface(TEntityType& dummy, const Variable<TDataType>& rVariable, const ProcessInfo& rCurrentProcessInfo)
{
    TDataType aux;
    dummy.Calculate(rVariable, aux, rCurrentProcessInfo);
    return aux;
}

template<class TEntityType>
boost::python::list GetValuesOnIntegrationPointsConstitutiveLaw( TEntityType& dummy,
        const Variable<typename TEntityType::ConstitutiveLawType::Pointer>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    boost::python::list values_list;
    std::vector<typename TEntityType::ConstitutiveLawType::Pointer> values;
    dummy.CalculateOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
    for( unsigned int i=0; i<values.size(); i++ )
    {
        values_list.append( values[i] );
    }
    return( values_list );
}

template<class TEntityType>
boost::python::list CalculateOnIntegrationPointsConstitutiveLaw( TEntityType& dummy,
        const Variable<typename TEntityType::ConstitutiveLawType::Pointer>& rVariable, const ProcessInfo& rCurrentProcessInfo )
{
    return GetValuesOnIntegrationPointsConstitutiveLaw<TEntityType>(dummy, rVariable, rCurrentProcessInfo);
}

template<class TEntityType>
void SetValuesOnIntegrationPointsConstitutiveLaw( TEntityType& dummy, const Variable<typename TEntityType::ConstitutiveLawType::Pointer>& rVariable, boost::python::list values_list, const ProcessInfo& rCurrentProcessInfo )
{
    typename TEntityType::GeometryType::IntegrationPointsArrayType integration_points =
            dummy.GetGeometry().IntegrationPoints( dummy.GetIntegrationMethod() );
    if (boost::python::len(values_list) != integration_points.size())
        KRATOS_ERROR << "Incompatiable number of integration points and given values "
                     << boost::python::len(values_list) << " != " << integration_points.size();
    std::vector<typename TEntityType::ConstitutiveLawType::Pointer> values( integration_points.size() );
    for( unsigned int i=0; i<integration_points.size(); i++ )
    {
        typename TEntityType::ConstitutiveLawType::Pointer value_item;
        boost::python::extract<typename TEntityType::ConstitutiveLawType::Pointer> x( values_list[i] );
        values[i] = x();
    }
    dummy.SetValuesOnIntegrationPoints( rVariable, values, rCurrentProcessInfo );
}

template< class TEntityType, typename TDataType >
TDataType CalculateOnPointScalar( TEntityType& rDummy, const Variable<TDataType>& rVariable,
        const typename TEntityType::GeometryType::CoordinatesArrayType& rCoordinates )
{
    typename TEntityType::GeometryType::LocalCoordinatesArrayType rLocalCoordinates;

    rLocalCoordinates = rDummy.GetGeometry().PointLocalCoordinates(rLocalCoordinates, rCoordinates);

    Vector N;
    rDummy.GetGeometry().ShapeFunctionsValues(N, rLocalCoordinates);

    TDataType rResult = 0.0;
    for (std::size_t i = 0; i < rDummy.GetGeometry().size(); ++i)
    {
        rResult += N[i] * rDummy.GetGeometry()[i].GetSolutionStepValue(rVariable);
    }

    return rResult;
}

template< class TEntityType, typename TDataType >
TDataType CalculateOnPointMatrixVector( TEntityType& rDummy, const Variable<TDataType>& rVariable,
        const typename TEntityType::GeometryType::CoordinatesArrayType& rCoordinates )
{
    typename TEntityType::GeometryType::LocalCoordinatesArrayType rLocalCoordinates;

    rLocalCoordinates = rDummy.GetGeometry().PointLocalCoordinates(rLocalCoordinates, rCoordinates);

    Vector N;
    rDummy.GetGeometry().ShapeFunctionsValues(N, rLocalCoordinates);

    TDataType rResult = N[0] * rDummy.GetGeometry()[0].GetSolutionStepValue(rVariable);
    for (std::size_t i = 1; i < rDummy.GetGeometry().size(); ++i)
    {
        noalias(rResult) += N[i] * rDummy.GetGeometry()[i].GetSolutionStepValue(rVariable);
    }

    return rResult;
}

template<class TMeshType>
void AddMeshToPython(const std::string& Prefix)
{
    typedef TMeshType MeshType;
    typedef typename MeshType::IndexType IndexType;
    typedef typename MeshType::ElementType ElementType;
    typedef typename MeshType::ConditionType ConditionType;
    typedef typename MeshType::NodeType NodeType;
    typedef typename NodeType::DofType::DataType DataType;

    typedef typename ElementType::VectorType VectorType;
    typedef typename ElementType::MatrixType MatrixType;

    class_<GeometricalObject<NodeType>, typename GeometricalObject<NodeType>::Pointer, bases<IndexedObject, Flags> >
    ((Prefix+"GeometricalObject").c_str(), init<int>())
    ;

    class_<ElementType, typename ElementType::Pointer, bases<typename ElementType::BaseType> >
    ((Prefix+"Element").c_str(), init<IndexType>())
    .add_property("Properties", GetPropertiesFromEntity<ElementType>, SetPropertiesForEntity<ElementType>)
    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< array_1d<DataType, 3>  > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< array_1d<DataType, 3>  > >)
    .def("Has", HasHelperFunction< ElementType, Variable< array_1d<DataType, 3>  > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< array_1d<DataType, 3>  > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< array_1d<DataType, 3>  > >)

    .def("SetValue", SetValueHelperFunction< Condition, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)

    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< VectorType > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< VectorType > >)
    .def("Has", HasHelperFunction< ElementType, Variable< VectorType > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< VectorType > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< VectorType > >)

    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< vector<int> > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< vector<int> > >)
    .def("Has", HasHelperFunction< ElementType, Variable< vector<int> > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< vector<int> > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< vector<int> > >)

    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< MatrixType > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< MatrixType > >)
    .def("Has", HasHelperFunction< ElementType, Variable< MatrixType > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< MatrixType > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< MatrixType > >)

    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< int > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< int > >)
    .def("Has", HasHelperFunction< ElementType, Variable< int > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< int > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< int > >)

    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< DataType > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< DataType > >)
    .def("Has", HasHelperFunction< ElementType, Variable< DataType > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< DataType > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< DataType > >)

    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< bool > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< bool > >)
    .def("Has", HasHelperFunction< ElementType, Variable< bool > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< bool > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< bool > >)

    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< typename ElementType::ConstitutiveLawType::Pointer > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< typename ElementType::ConstitutiveLawType::Pointer > >)
    .def("Has", HasHelperFunction< ElementType, Variable< typename ElementType::ConstitutiveLawType::Pointer > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< typename ElementType::ConstitutiveLawType::Pointer > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< typename ElementType::ConstitutiveLawType::Pointer > >)

    .def("__setitem__", SetValueHelperFunction< ElementType, Variable< std::string > >)
    .def("__getitem__", GetValueHelperFunction< ElementType, Variable< std::string > >)
    .def("Has", HasHelperFunction< ElementType, Variable< std::string > >)
    .def("SetValue", SetValueHelperFunction< ElementType, Variable< std::string > >)
    .def("GetValue", GetValueHelperFunction< ElementType, Variable< std::string > >)

    .def("GetArea", GetAreaFromEntity<ElementType> )
    .def("GetNode", GetNodeFromEntity<ElementType> )
    .def("GetNodes", GetNodesFromEntity<ElementType> )
    .def("GetGeometry", GetGeometryFromEntity<ElementType> )
    .def("GetIntegrationMethod", GetIntegrationMethodFromEntity<ElementType> )
    .def("GetIntegrationPoints", GetIntegrationPointsFromEntity<ElementType> )
    .def("GetIntegrationPointsInReferenceFrame", GetIntegrationPointsFromEntityInReferenceFrame<ElementType> )
    .def("GetIntegrationPointsInLocalCoordinates", GetIntegrationPointsFromEntityInLocalCoordinates<ElementType> )
    .def("GetIntegrationPointsLocalCoordinates", GetIntegrationPointsLocalCoordinatesFromEntity<ElementType> )
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsVector<ElementType, VectorType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsString<ElementType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsArray1d<ElementType, DataType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsMatrix<ElementType, MatrixType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsDouble<ElementType, DataType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsInt<ElementType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsConstitutiveLaw<ElementType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsBool<ElementType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsInt<ElementType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsDouble<ElementType, DataType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsArray1d<ElementType, DataType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsVector<ElementType, VectorType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsMatrix<ElementType, MatrixType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsString<ElementType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsConstitutiveLaw<ElementType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsVector<ElementType, VectorType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsVectorVariableLength<ElementType, VectorType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsConstitutiveLaw<ElementType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsDouble<ElementType, DataType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsInt<ElementType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsBool<ElementType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsString<ElementType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsArray1d<ElementType, DataType>)
    .def("ResetConstitutiveLaw", &ElementType::ResetConstitutiveLaw)
    .def("Calculate", &ElementCalculateInterface<ElementType, DataType>)
    .def("Calculate", &ElementCalculateInterface<ElementType, array_1d<DataType, 3> >)
    .def("Calculate", &ElementCalculateInterface<ElementType, VectorType >)
    .def("Calculate", &ElementCalculateInterface<ElementType, MatrixType >)
    .def("CalculateOnPoint", &CalculateOnPointScalar<ElementType, DataType>)
    .def("CalculateOnPoint", &CalculateOnPointMatrixVector<ElementType, array_1d<DataType, 3> >)
    .def("CalculateOnPoint", &CalculateOnPointMatrixVector<ElementType, VectorType>)
    .def("CalculateOnPoint", &CalculateOnPointMatrixVector<ElementType, MatrixType>)
    //.def("__setitem__", SetValueHelperFunction< ElementType, Variable< VectorComponentAdaptor< array_1d<DataType, 3>  > > >)
    //.def("__getitem__", GetValueHelperFunction< ElementType, Variable< VectorComponentAdaptor< array_1d<DataType, 3>  > > >)
    //.def("SetValue", SetValueHelperFunction< ElementType, Variable< VectorComponentAdaptor< array_1d<DataType, 3>  > > >)
    //.def("GetValue", GetValueHelperFunction< ElementType, Variable< VectorComponentAdaptor< array_1d<DataType, 3>  > > >)

    /*                  .def(VariableIndexingPython<ElementType, Variable<int> >())
                        .def(VariableIndexingPython<ElementType, Variable<DataType> >())
                        .def(VariableIndexingPython<ElementType, Variable<array_1d<DataType, 3> > >())
                        .def(VariableIndexingPython<ElementType, Variable< VectorType > >())
                        .def(VariableIndexingPython<ElementType, Variable< MatrixType > >())
                        .def(VariableIndexingPython<ElementType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >())
                        .def(SolutionStepVariableIndexingPython<ElementType, Variable<int> >())
                        .def(SolutionStepVariableIndexingPython<ElementType, Variable<DataType> >())
                        .def(SolutionStepVariableIndexingPython<ElementType, Variable<array_1d<DataType, 3> > >())
                        .def(SolutionStepVariableIndexingPython<ElementType, Variable<vector<DataType> > >())
                        .def(SolutionStepVariableIndexingPython<ElementType, Variable<matrix<DataType> > >())
                        .def(SolutionStepVariableIndexingPython<ElementType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >()) */
    .def("Initialize", &ElementType::Initialize)
    //.def("CalculateLocalSystem", &ElementType::CalculateLocalSystem)
    .def("Check", &ElementType::Check)
    .def("InitializeSolutionStep", &ElementType::InitializeSolutionStep)
    .def("InitializeNonLinearIteration", &ElementType::InitializeNonLinearIteration)
    .def("FinalizeNonLinearIteration", &ElementType::FinalizeNonLinearIteration)
    .def("FinalizeSolutionStep", &ElementType::FinalizeSolutionStep)
    .def("Info", &ElementType::Info)
    .def(self_ns::str(self))
    ;

    PointerVectorSetPythonInterface<typename MeshType::ElementsContainerType>::CreateInterface((Prefix+"ElementsArray").c_str())
    ;

    class_<ConditionType, typename ConditionType::Pointer, bases<typename ConditionType::BaseType> >
    ((Prefix+"Condition").c_str(), init<int>())
    .add_property("Properties", GetPropertiesFromEntity<ConditionType>, SetPropertiesForEntity<ConditionType>)
    .def("__setitem__", SetValueHelperFunction< ConditionType, Variable< array_1d<DataType, 3>  > >)
    .def("__getitem__", GetValueHelperFunction< ConditionType, Variable< array_1d<DataType, 3>  > >)
    .def("Has", HasHelperFunction< ConditionType, Variable< array_1d<DataType, 3>  > >)
    .def("SetValue", SetValueHelperFunction< ConditionType, Variable< array_1d<DataType, 3>  > >)
    .def("GetValue", GetValueHelperFunction< ConditionType, Variable< array_1d<DataType, 3>  > >)

    .def("SetValue", SetValueHelperFunction< ConditionType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >)

    .def("__setitem__", SetValueHelperFunction< ConditionType, Variable< VectorType > >)
    .def("__getitem__", GetValueHelperFunction< ConditionType, Variable< VectorType > >)
    .def("Has", HasHelperFunction< ConditionType, Variable< VectorType > >)
    .def("SetValue", SetValueHelperFunction< ConditionType, Variable< VectorType > >)
    .def("GetValue", GetValueHelperFunction< ConditionType, Variable< VectorType > >)

    .def("__setitem__", SetValueHelperFunction< ConditionType, Variable< vector<int> > >)
    .def("__getitem__", GetValueHelperFunction< ConditionType, Variable< vector<int> > >)
    .def("Has", HasHelperFunction< ConditionType, Variable< vector<int> > >)
    .def("SetValue", SetValueHelperFunction< ConditionType, Variable< vector<int> > >)
    .def("GetValue", GetValueHelperFunction< ConditionType, Variable< vector<int> > >)

    .def("__setitem__", SetValueHelperFunction< ConditionType, Variable< MatrixType > >)
    .def("__getitem__", GetValueHelperFunction< ConditionType, Variable< MatrixType > >)
    .def("Has", HasHelperFunction< ConditionType, Variable< MatrixType > >)
    .def("SetValue", SetValueHelperFunction< ConditionType, Variable< MatrixType > >)
    .def("GetValue", GetValueHelperFunction< ConditionType, Variable< MatrixType > >)

    .def("__setitem__", SetValueHelperFunction< ConditionType, Variable< int > >)
    .def("__getitem__", GetValueHelperFunction< ConditionType, Variable< int > >)
    .def("Has", HasHelperFunction< ConditionType, Variable< int > >)
    .def("SetValue", SetValueHelperFunction< ConditionType, Variable< int > >)
    .def("GetValue", GetValueHelperFunction< ConditionType, Variable< int > >)

    .def("__setitem__", SetValueHelperFunction< ConditionType, Variable< DataType > >)
    .def("__getitem__", GetValueHelperFunction< ConditionType, Variable< DataType > >)
    .def("Has", HasHelperFunction< ConditionType, Variable< DataType > >)
    .def("SetValue", SetValueHelperFunction< ConditionType, Variable< DataType > >)
    .def("GetValue", GetValueHelperFunction< ConditionType, Variable< DataType > >)

    .def("__setitem__", SetValueHelperFunction< ConditionType, Variable< bool > >)
    .def("__getitem__", GetValueHelperFunction< ConditionType, Variable< bool > >)
    .def("Has", HasHelperFunction< ConditionType, Variable< bool > >)
    .def("SetValue", SetValueHelperFunction< ConditionType, Variable< bool > >)
    .def("GetValue", GetValueHelperFunction< ConditionType, Variable< bool > >)

    .def("__setitem__", SetValueHelperFunction< ConditionType, Variable< std::string > >)
    .def("__getitem__", GetValueHelperFunction< ConditionType, Variable< std::string > >)
    .def("Has", HasHelperFunction< ConditionType, Variable< std::string > >)
    .def("SetValue", SetValueHelperFunction< ConditionType, Variable< std::string > >)
    .def("GetValue", GetValueHelperFunction< ConditionType, Variable< std::string > >)

    .def("GetArea", GetAreaFromEntity<ConditionType>)
    .def("GetNode", GetNodeFromEntity<ConditionType> )
    .def("GetNodes", GetNodesFromEntity<ConditionType> )
    .def("GetGeometry", GetGeometryFromEntity<ConditionType> )

    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsVector<ConditionType, VectorType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsString<ConditionType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsArray1d<ConditionType, DataType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsMatrix<ConditionType, MatrixType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsDouble<ConditionType, DataType>)
    .def("CalculateOnIntegrationPoints", CalculateOnIntegrationPointsInt<ConditionType>)

    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsDouble<ConditionType, DataType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsArray1d<ConditionType, DataType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsVector<ConditionType, VectorType>)
    .def("GetValuesOnIntegrationPoints", GetValuesOnIntegrationPointsMatrix<ConditionType, MatrixType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsVector<ConditionType, VectorType>)
    //.def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsConstitutiveLaw<ConditionType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsDouble<ConditionType, DataType>)
    .def("SetValuesOnIntegrationPoints", SetValuesOnIntegrationPointsArray1d<ConditionType, DataType>)
    .def("Calculate", &ElementCalculateInterface<ConditionType, DataType>)
    .def("Calculate", &ElementCalculateInterface<ConditionType, array_1d<DataType, 3> >)
    .def("Calculate", &ElementCalculateInterface<ConditionType, VectorType >)
    .def("Calculate", &ElementCalculateInterface<ConditionType, MatrixType >)
    .def("CalculateOnPoint", &CalculateOnPointScalar<ConditionType, DataType>)
    .def("CalculateOnPoint", &CalculateOnPointMatrixVector<ConditionType, array_1d<DataType, 3> >)
    .def("CalculateOnPoint", &CalculateOnPointMatrixVector<ConditionType, VectorType>)
    .def("CalculateOnPoint", &CalculateOnPointMatrixVector<ConditionType, MatrixType>)
//              .def(VariableIndexingPython<ConditionType, Variable<int> >())
//              .def(VariableIndexingPython<ConditionType, Variable<DataType> >())
//              .def(VariableIndexingPython<ConditionType, Variable<array_1d<DataType, 3> > >())
//              .def(VariableIndexingPython<ConditionType, Variable< VectorType > >())
//              .def(VariableIndexingPython<ConditionType, Variable< MatrixType > >())
//              .def(VariableIndexingPython<ConditionType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >())
    /*              .def(SolutionStepVariableIndexingPython<ConditionType, Variable<int> >())
                    .def(SolutionStepVariableIndexingPython<ConditionType, Variable<DataType> >())
                    .def(SolutionStepVariableIndexingPython<ConditionType, Variable<array_1d<DataType, 3> > >())
                    .def(SolutionStepVariableIndexingPython<ConditionType, Variable<vector<DataType> > >())
                    .def(SolutionStepVariableIndexingPython<ConditionType, Variable<matrix<DataType> > >())
                    .def(SolutionStepVariableIndexingPython<ConditionType, VariableComponent<VectorComponentAdaptor<array_1d<DataType, 3> > > >())
    */
    .def("Initialize", &ConditionType::Initialize)
    //.def("CalculateLocalSystem", &ConditionType::CalculateLocalSystem)
    .def("Info", &ConditionType::Info)
    .def("Check", &ConditionType::Check)
    .def(self_ns::str(self))
    ;

    PointerVectorSetPythonInterface<typename MeshType::ConditionsContainerType>::CreateInterface((Prefix+"ConditionsArray").c_str())
    ;

    class_<MeshType, typename MeshType::Pointer, bases<DataValueContainer, Flags>, boost::noncopyable >((Prefix+"Mesh").c_str())
    .add_property("Nodes", &MeshType::pNodes, &MeshType::SetNodes)
    .def("NodesArray", &MeshType::NodesArray, return_internal_reference<>())
    .add_property("Elements", &MeshType::pElements, &MeshType::SetElements)
    // .def("ElementsArray", &MeshType::ElementsArray, return_internal_reference<>())
    .add_property("Conditions", &MeshType::pConditions, &MeshType::SetConditions)
    // .def("ConditionsArray", &MeshType::ConditionsArray, return_internal_reference<>())
    .add_property("Properties", &MeshType::pProperties, &MeshType::SetProperties)
    // .def("PropertiesArray", &MeshType::PropertiesArray, return_internal_reference<>())
    .def("HasNode", &MeshType::HasNode)
    .def("HasProperties", &MeshType::HasProperties)
    .def("HasElement", &MeshType::HasElement)
    .def("HasCondition", &MeshType::HasCondition)
    .def(self_ns::str(self))
    ;

    PointerVectorSetPythonInterface<typename MeshType::NodesContainerType>::CreateInterface((Prefix+"NodesArray").c_str())
    ;
}

void AddMeshToPython()
{
    AddMeshToPython<ModelPart::MeshType>("");
    AddMeshToPython<ComplexModelPart::MeshType>("Complex");
    AddMeshToPython<GComplexModelPart::MeshType>("GComplex");
}

}  // namespace Python.

} // Namespace Kratos
