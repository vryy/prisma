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
        std::cout << " |  /           |" << std::endl;
        std::cout << " ' /   __| _` | __|  _ \\   __|" << std::endl;
        std::cout << " . \\  |   (   | |   (   |\\__ \\" << std::endl;
        std::cout << "_|\\_\\_|  \\__,_|\\__|\\___/ ____/" << std::endl;
        #if PY_MAJOR_VERSION==3
        std::cout << "         Multi-Physics (with interface to Python 3)" << std::endl;
        #else
        std::cout << "         Multi-Physics (with interface to Python 2)" << std::endl;
        #endif
        std::cout << "   maintained by Hoang-Giang Bui" << std::endl;
        std::cout << "     Ruhr University Bochum     2013-2021" << std::endl;
        std::cout << "     Helmholtz-Zentrum Hereon   2022-2024" << std::endl;
        std::cout << "     University of Birmingham   2025-2026" << std::endl;

        mKratosApplication.RegisterVariables();
    }

    void Kernel::Initialize()
    {
        unsigned int j = 0;
        for(KratosComponents<VariableData>::ComponentsContainerType::iterator i = KratosComponents<VariableData>::GetComponents().begin() ;
                i != KratosComponents<VariableData>::GetComponents().end() ; i++)
            i->second->SetKey(++j);
    }

    void Kernel::AddApplication(KratosApplication& NewApplication)
    {
        NewApplication.Register();
    }

    void Kernel::InitializeApplication(KratosApplication& NewApplication)
    {
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
