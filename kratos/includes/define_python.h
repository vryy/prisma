//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//

#pragma once

// System includes

// External includes
#include <boost/python.hpp>

// Project includes

// This function is used to print the ofstream-operator
// i.e. printing an object will give the same result in Python as in C++
// To be defined as the "__str__" function
// e.g. ".def("__str__", PrintObject<ProcessInfo>)"
// It replicates the function "self_ns::str(self))" of boost-python
template< class T>
std::string PrintObject(const T& rObject)
{
    std::stringstream ss;
    ss << rObject;
    return ss.str();
}
