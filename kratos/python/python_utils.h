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
#include "containers/array_1d.h"


namespace Kratos
{

namespace Python
{

struct PythonUtils
{

    template <typename T> struct is_vector_of_arithmetic : std::false_type {};
    template <typename T> struct is_vector_of_arithmetic<std::vector<T> > : std::is_arithmetic<T> {};

    template<typename T> struct is_array_1d : std::false_type {};
    template<typename TDataType, std::size_t TSize> struct is_array_1d<array_1d<TDataType, TSize> > : std::true_type {};

    /// Unpack a boost::python::list to std::vector
    template<typename TInputValueType, typename TOutputValueType = TInputValueType>
    static void Unpack(const boost::python::list& rValues, std::vector<TOutputValueType>& values)
    {
        using namespace boost::python;

        const int n = len(rValues);
        values.clear();
        values.reserve(n);

        for (int i = 0; i < n; ++i)
        {
            object item = rValues[i];
            extract<TInputValueType> ex(item);

            if (!ex.check())
            {
                KRATOS_ERROR << "List element " << i
                             << " cannot be converted to " << DataTypeToString<TInputValueType>::Get();
            }

            values.push_back(static_cast<TOutputValueType>(ex()));
        }
    }

    /// Unpack a boost::python::list to std::vector of specific size. The list should have sufficient size.
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

    /// Unpack a 2D boost::python::list to 2D std::vector
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

    /// Unpack a 2D boost::python::list to 2D std::vector of std::vector of specific size
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

    /// Unpack a boost::python::dict to 2D std::map with interger key
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

    /// Unpack a boost::python::dict to std::map
    template<typename TKeyType, typename TDataType>
    static void Unpack(const boost::python::dict& py_dict, std::map<TKeyType, TDataType>& out_map)
    {
        using namespace boost::python;

        list keys = py_dict.keys();
        const int nkeys = len(keys);

        out_map.clear();

        for (int i = 0; i < nkeys; ++i)
        {
            object py_key = keys[i];

            // ---- extract key ----
            extract<TKeyType> key_ex(py_key);
            if (!key_ex.check())
                KRATOS_ERROR << "Cannot convert Python dict key at index " << i
                             << " to TKeyType";

            TKeyType key = key_ex();

            // ---- extract value ----
            object py_val = py_dict.get(py_key);

            TDataType val;

            if constexpr (std::is_arithmetic<TDataType>::value)
            {
                extract<TDataType> ex(py_val);
                if (!ex.check())
                    KRATOS_ERROR << "Dictionary value for key '" << key
                                 << "' cannot be converted to arithmetic type";

                val = ex();
            }
            else if constexpr (is_vector_of_arithmetic<TDataType>::value)
            {
                extract<list> ex_list(py_val);
                if (!ex_list.check())
                {
                    KRATOS_ERROR << "Value for key '" << key
                                 << "' is expected to be a Python list";
                }

                // call your existing overload:
                // Unpack(const list&, vector<T>&)
                Unpack<typename TDataType::value_type>(
                    ex_list(),   // input python list
                    val          // output vector
                );
            }
            else
            {
                KRATOS_ERROR << "Unsupported TDataType in Unpack(dict, map)";
            }

            out_map[key] = std::move(val);
        }
    }

    /// Unpack a boost::python::dict to std::map
    template<typename TDataType>
    static void Unpack(const boost::python::dict& rNodalValues,
                       std::map<TDataType, TDataType>& nodal_values)
    {
        Unpack<TDataType, TDataType>(rNodalValues, nodal_values);
    }

    /// Unpack a boost::python::list to std::array
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

    /// Extend a boost::python::list with std::vector
    template<typename TInputValueType>
    static void Extend(boost::python::list& rValues, const std::vector<TInputValueType>& values)
    {
        for (auto v : values)
            rValues.append(v);
    }

    /// Pack a std::vector to boost::python::list
    template<typename TInputValueType>
    static boost::python::list Pack(const std::vector<TInputValueType>& vec)
    {
        using namespace boost::python;

        list py_list;

        if constexpr (std::is_arithmetic<TInputValueType>::value)
        {
            for (const auto& v : vec)
                py_list.append(v);
        }
        else if constexpr (is_vector_of_arithmetic<TInputValueType>::value)
        {
            for (const auto& subvec : vec)
                py_list.append(Pack(subvec)); // recursive call for vector<vector<T>>
        }
        else if constexpr (is_array_1d<TInputValueType>::value)
        {
            // vector of array_1d -> list of lists
            for (const auto& a : vec)
            {
                list inner_list;
                for (std::size_t i = 0; i < TInputValueType::array_type::static_size; ++i)
                    inner_list.append(a[i]);
                py_list.append(inner_list);
            }
        }
        else
        {
            KRATOS_ERROR << "Unsupported vector element type in Pack(vector)";
        }

        return py_list;
    }

    /// Pack a std::map to boost::python::dict
    template<typename TKeyType, typename TInputValueType>
    static boost::python::dict Pack(const std::map<TKeyType, TInputValueType>& map)
    {
        using namespace boost::python;
        boost::python::dict py_dict;
        for (const auto& kv : map)
        {
            object py_key(kv.first);
            object py_val(kv.second);  // fails here if no converter exists
            py_dict[py_key] = py_val;
        }
        return py_dict;
    }

    /// Print the keys of a python object, assuming it's a dictionary
    static void Print(PyObject* globalDict)
    {
        // Get the dictionary keys
        PyObject* keys = PyDict_Keys(globalDict);

        if (keys && PyList_Check(keys)) {
            Py_ssize_t n = PyList_Size(keys);
            for (Py_ssize_t i = 0; i < n; ++i) {
                PyObject* key = PyList_GetItem(keys, i); // borrowed ref
                PyObject* keyStr = PyObject_Str(key);
                if (keyStr) {
                    const char* cStr = PyUnicode_AsUTF8(keyStr);
                    if (cStr) {
                        std::cout << cStr << std::endl;
                    }
                    Py_DECREF(keyStr);
                }
            }
        }

        Py_XDECREF(keys);
    }

};

} // namespace Python

} // namespace Kratos.

#endif // KRATOS_PYTHON_UTILS_H_INCLUDED defined
