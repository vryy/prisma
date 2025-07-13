//
//   Project Name:        Kratos
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: 17 Sep 2023 $
//   Revision:            $Revision: 1.0 $
//
//

#if !defined(KRATOS_PYTHON_UTILS_H_INCLUDED )
#define  KRATOS_PYTHON_UTILS_H_INCLUDED

// System includes
#include <array>
#include <map>
#include <vector>

// External includes
#include <boost/foreach.hpp>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <boost/python/operators.hpp>

// Project includes
#include "includes/define.h"


namespace Kratos
{

namespace Python
{

struct PythonUtils
{

    template<typename TInputValueType, typename TOutputValueType = TInputValueType>
    static void Unpack(const boost::python::list& rValues, std::vector<TOutputValueType>& values)
    {
        typedef boost::python::stl_input_iterator<TInputValueType> iterator_value_type;
        BOOST_FOREACH(const typename iterator_value_type::value_type & v,
                      std::make_pair(iterator_value_type(rValues), iterator_value_type() ) )
        {
            values.push_back(static_cast<TOutputValueType>(v));
        }
    }

    template<typename TInputValueType, typename TOutputValueType = TInputValueType>
    static std::size_t Unpack(const boost::python::list& rValues, std::vector<TOutputValueType>& values, std::size_t Dim)
    {
        if (values.size() != Dim)
        {
            values.resize(Dim);
        }

        std::size_t dim = 0;
        typedef boost::python::stl_input_iterator<TInputValueType> iterator_value_type;
        BOOST_FOREACH(const typename iterator_value_type::value_type & v,
                      std::make_pair(iterator_value_type(rValues), iterator_value_type() ) )
        {
            values[dim++] = static_cast<TOutputValueType>(v);
            if (dim == Dim)
            {
                break;
            }
        }

        return dim;
    }

    template<typename TInputValueType, typename TOutputValueType = TInputValueType>
    static void Unpack(const boost::python::list& rValues, std::vector<std::vector<TOutputValueType> >& values)
    {
        typedef boost::python::stl_input_iterator<boost::python::list> iterator_value_type;
        BOOST_FOREACH(const iterator_value_type::value_type & rSubValues,
                      std::make_pair(iterator_value_type(rValues), // begin
                                     iterator_value_type() ) ) // end
        {
            std::vector<TOutputValueType> sub_values;

            typedef boost::python::stl_input_iterator<TInputValueType> iterator_value_type2;
            BOOST_FOREACH(const typename iterator_value_type2::value_type & x,
                          std::make_pair(iterator_value_type2(rSubValues), // begin
                                         iterator_value_type2() ) ) // end
            {
                sub_values.push_back(static_cast<TOutputValueType>(x));
            }

            values.push_back(sub_values);
        }
    }

    template<typename TInputValueType, typename TOutputValueType = TInputValueType>
    static std::size_t Unpack(const boost::python::list& rValues, std::vector<std::vector<TOutputValueType> >& values, std::size_t Dim)
    {
        if (values.size() != Dim)
        {
            values.resize(Dim);
        }

        std::size_t dim = 0;
        typedef boost::python::stl_input_iterator<boost::python::list> iterator_value_type;
        BOOST_FOREACH(const iterator_value_type::value_type & rSubValues,
                      std::make_pair(iterator_value_type(rValues), // begin
                                     iterator_value_type() ) ) // end
        {
            std::vector<TOutputValueType> sub_values;

            typedef boost::python::stl_input_iterator<TInputValueType> iterator_value_type2;
            BOOST_FOREACH(const typename iterator_value_type2::value_type & x,
                          std::make_pair(iterator_value_type2(rSubValues), // begin
                                         iterator_value_type2() ) ) // end
            {
                sub_values.push_back(static_cast<TOutputValueType>(x));
            }

            values[dim++] = sub_values;
            if (dim == Dim)
            {
                break;
            }
        }

        return dim;
    }

    template<typename TDataType>
    static void Unpack(const boost::python::dict& rNodalValues,
                       std::map<std::size_t, std::map<std::size_t, TDataType> >& nodal_values)
    {
        boost::python::list keys = rNodalValues.keys();

        typedef boost::python::stl_input_iterator<int> iterator_type;
        BOOST_FOREACH(const iterator_type::value_type & id,
                      std::make_pair(iterator_type(keys), // begin
                                     iterator_type() ) ) // end
        {
            boost::python::object o = rNodalValues.get(id);

            // here assumed that the nodal_data given as a dict
            boost::python::dict values = boost::python::extract<boost::python::dict>(o);

            boost::python::list keys2 = values.keys();

            std::map<std::size_t, TDataType> tmp_nodal_values;
            BOOST_FOREACH(const typename iterator_type::value_type & id2,
                          std::make_pair(iterator_type(keys2), // begin
                                         iterator_type() ) ) // end
            {
                boost::python::object o2 = values.get(id2);
                TDataType v = boost::python::extract<TDataType>(o2);
                tmp_nodal_values[static_cast<std::size_t>(id2)] = v;
            }

            nodal_values[static_cast<std::size_t>(id)] = tmp_nodal_values;
        }
    }

    template<typename TDataType>
    static void Unpack(const boost::python::dict& rNodalValues,
                       std::map<TDataType, TDataType>& nodal_values)
    {
        boost::python::list keys = rNodalValues.keys();

        typedef boost::python::stl_input_iterator<std::string> iterator_type;
        BOOST_FOREACH(const iterator_type::value_type & id,
                      std::make_pair(iterator_type(keys), // begin
                                     iterator_type() ) ) // end
        {
            boost::python::object o = rNodalValues.get(id);

            // here assumed that the patch_data given as a value
            TDataType v = boost::python::extract<TDataType>(o);

            nodal_values[static_cast<TDataType>(id)] = v;
        }
    }

    template<typename TInputValueType, typename TOutputValueType, std::size_t TSize>
    static void Unpack(const boost::python::list& rValues, std::array<TOutputValueType, TSize>& values)
    {
        if (boost::python::len(rValues) < TSize)
            KRATOS_ERROR << "Input list does not have sufficient dimension";
        std::size_t cnt = 0;
        typedef boost::python::stl_input_iterator<TInputValueType> iterator_value_type;
        BOOST_FOREACH(const typename iterator_value_type::value_type & v,
                      std::make_pair(iterator_value_type(rValues), iterator_value_type() ) )
        {
            values[cnt] = (static_cast<TOutputValueType>(v));
            ++cnt;
        }
    }

    template<typename TInputValueType>
    static void Extend(boost::python::list& rValues, const std::vector<TInputValueType>& values)
    {
        for (auto v : values)
            rValues.append(v);
    }

};

} // namespace Python

} // namespace Kratos.

#endif // KRATOS_PYTHON_UTILS_H_INCLUDED defined
