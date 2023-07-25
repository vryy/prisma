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











#include "includes/kernel.h"
#include "includes/kratos_version.h"


namespace Kratos
{
    Kernel::Kernel()
    {
        std::cout << "MAINTAINED" << std::endl;
        std::cout << " |  /           |" << std::endl;
        std::cout << " ' /   __| _` | __|  _ \\   __|" << std::endl;
        std::cout << " . \\  |   (   | |   (   |\\__ \\" << std::endl;
        std::cout << "_|\\_\\_|  \\__,_|\\__|\\___/ ____/" << std::endl;
        // std::cout << "           Multi-Physics "<< KRATOS_VERSION << std::endl;
        std::cout << "           Multi-Physics" << std::endl;
        std::cout << "             for Python 2" << std::endl;
        std::cout << "   by Hoang-Giang Bui" << std::endl;
        std::cout << "     Ruhr University Bochum, 2013-2021" << std::endl;
        std::cout << "     Helmholtz-Zentrum Hereon, 2022-2023" << std::endl;

        mKratosApplication.RegisterVariables();
    }

    void Kernel::Initialize()
    {
        unsigned int j = 0;
        for(KratosComponents<VariableData>::ComponentsContainerType::iterator i = KratosComponents<VariableData>::GetComponents().begin() ;
                i != KratosComponents<VariableData>::GetComponents().end() ; i++)
            //const_cast<VariableData&>(i->second.get()).SetKey(++j);
            i->second->SetKey(++j);
    }

    void Kernel::AddApplication(KratosApplication& NewApplication)
    {
        //typedef VariableComponent<VectorComponentAdaptor<array_1d<double, 3> > > array_1d_component_type;

        NewApplication.Register();

        /*
        KratosComponents<VariableData>::GetComponents().insert(NewApplication.GetVariables().begin(),NewApplication.GetVariables().end());

        KratosComponents<Variable<int> >::GetComponents().insert(NewApplication.GetComponents(Variable<int>("NONE")).begin(),
                NewApplication.GetComponents(Variable<int>("NONE")).end());
        KratosComponents<Variable<unsigned int> >::GetComponents().insert(NewApplication.GetComponents(Variable<unsigned int>("NONE")).begin(),
               NewApplication.GetComponents(Variable<unsigned int>("NONE")).end());
        KratosComponents<Variable<double> >::GetComponents().insert(NewApplication.GetComponents(Variable<double>("NONE")).begin(),
                NewApplication.GetComponents(Variable<double>("NONE")).end());
        KratosComponents<Variable<array_1d<double, 3> > >::GetComponents().insert(NewApplication.GetComponents(Variable<array_1d<double, 3> >("NONE")).begin(),
                NewApplication.GetComponents(Variable<array_1d<double, 3> >("NONE")).end());
        KratosComponents<Variable<Vector> >::GetComponents().insert(NewApplication.GetComponents(Variable<Vector>("NONE")).begin(),
                NewApplication.GetComponents(Variable<Vector>("NONE")).end());
        KratosComponents<Variable<Matrix> >::GetComponents().insert(NewApplication.GetComponents(Variable<Matrix>("NONE")).begin(),
                NewApplication.GetComponents(Variable<Matrix>("NONE")).end());

        Kratos::VectorComponentAdaptor<Kratos::array_1d<double, 3> > temp_adaptor(DISPLACEMENT, 0); // the displacement is not important, only an array_1d variable is needed!

        KratosComponents<array_1d_component_type>::GetComponents().insert(NewApplication.GetComponents(array_1d_component_type("NONE", temp_adaptor)).begin(),
                NewApplication.GetComponents(array_1d_component_type("NONE", temp_adaptor)).end());

        KratosComponents<Element>::GetComponents().insert(NewApplication.GetElements().begin(),
                NewApplication.GetElements().end());
        KratosComponents<Condition>::GetComponents().insert(NewApplication.GetConditions().begin(),
                NewApplication.GetConditions().end());

//        KratosComponents<Variable<double> >::GetComponents().insert(NewApplication.GetComponents(Variable<double>("NONE")).begin(),
//                NewApplication.GetComponents(Variable<double>("NONE")).end());


        Serializer::GetRegisteredObjects().insert(NewApplication.GetRegisteredObjects().begin(), NewApplication.GetRegisteredObjects().end());
        Serializer::GetRegisteredObjectsName().insert(NewApplication.GetRegisteredObjectsName().begin(), NewApplication.GetRegisteredObjectsName().end());
        */
    }

    void Kernel::InitializeApplication(KratosApplication& NewApplication)
    {
        /*
        NewApplication.SetComponents(KratosComponents<VariableData>::GetComponents());
        NewApplication.SetComponents(KratosComponents<Element>::GetComponents());
        NewApplication.SetComponents(KratosComponents<Condition>::GetComponents());

        NewApplication.GetRegisteredObjects().insert(Serializer::GetRegisteredObjects().begin(), Serializer::GetRegisteredObjects().end());
        NewApplication.GetRegisteredObjectsName().insert(Serializer::GetRegisteredObjectsName().begin(), Serializer::GetRegisteredObjectsName().end());
        */
    }

    std::string Kernel::Info() const
    {
        return "kernel";
    }

    void Kernel::PrintInfo(std::ostream& rOStream) const
    {
        rOStream << "kernel";
    }

    /// Print object's data.
    void Kernel::PrintData(std::ostream& rOStream) const
    {
        rOStream << "Variables:" << std::endl;
        KratosComponents<VariableData>().PrintData(rOStream);
        rOStream << std::endl;
        rOStream << "Elements:" << std::endl;
        KratosComponents<Element>().PrintData(rOStream);
        rOStream << std::endl;
        rOStream << "Conditions:" << std::endl;
        KratosComponents<Condition>().PrintData(rOStream);
    }
}



