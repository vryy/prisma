//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//












// System includes

// External includes


// Project includes
#include "includes/kratos_components.h"
#include "includes/element.h"
#include "includes/condition.h"
#include "includes/constitutive_law.h"
#include "includes/master_slave_constraint.h"


namespace Kratos
{

void AddKratosComponent(std::string const& Name, Variable<bool> const& ThisComponent)
{
    KratosComponents<Variable<bool> >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Variable<int> const& ThisComponent)
{
    KratosComponents<Variable<int> >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Variable<unsigned int> const& ThisComponent)
{
    KratosComponents<Variable<unsigned int> >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Variable<double> const& ThisComponent)
{
    KratosComponents<Variable<double> >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Variable<array_1d<double, 3> > const& ThisComponent)
{
    KratosComponents<Variable<array_1d<double, 3> > >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Variable<Vector> const& ThisComponent)
{
    KratosComponents<Variable<Vector> >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Variable<Matrix> const& ThisComponent)
{
    KratosComponents<Variable<Matrix> >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Variable<std::string> const& ThisComponent)
{
    KratosComponents<Variable<std::string> >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, VariableComponent<VectorComponentAdaptor<array_1d<double, 3> > > const& ThisComponent)
{
    KratosComponents<VariableComponent<VectorComponentAdaptor<array_1d<double, 3> > > >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Variable<Flags> const& ThisComponent)
{
    KratosComponents<Variable<Flags> >::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Element const& ThisComponent)
{
    KratosComponents<Element>::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, Condition const& ThisComponent)
{
    KratosComponents<Condition>::Add(Name, ThisComponent);
}

void AddKratosComponent(std::string const& Name, ConstitutiveLaw const& ThisComponent)
{
    KratosComponents<ConstitutiveLaw>::Add(Name, ThisComponent);
}

template class KratosComponents<MasterSlaveConstraint>;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<bool> >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<int> >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<unsigned int> >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<double> >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<array_1d<double, 3> > >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<array_1d<double, 4> > >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<array_1d<double, 6> > >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<array_1d<double, 9> > >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<Vector> >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<Matrix> >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<std::string> >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<VariableComponent<VectorComponentAdaptor<array_1d<double, 3> > > >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Variable<Flags> >;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Flags>;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Element>;
template class KRATOS_API(KRATOS_CORE) KratosComponents<ComplexElement>;
template class KRATOS_API(KRATOS_CORE) KratosComponents<GComplexElement>;
template class KRATOS_API(KRATOS_CORE) KratosComponents<Condition>;
template class KRATOS_API(KRATOS_CORE) KratosComponents<ComplexCondition>;
template class KRATOS_API(KRATOS_CORE) KratosComponents<GComplexCondition>;

// Specialize array of compenents for VariableData
KratosComponents<VariableData>::ComponentsContainerType KratosComponents<VariableData>::msComponents;

}  // namespace Kratos.
