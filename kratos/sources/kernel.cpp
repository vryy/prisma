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
        Welcome(std::cout);
        mKratosApplication.RegisterVariables();
    }

    void Kernel::Welcome(std::ostream& rOStream)
    {
        rOStream << " ____       _" << std::endl;
        rOStream << "|  _ \\ _ __(_)___ _ __ ___   __ _" << std::endl;
        rOStream << "| |_) | '__| / __| '_ ` _ \\ / _` |" << std::endl;
        rOStream << "|  __/| |  | \\__ \\ | | | | | (_| |" << std::endl;
        rOStream << "|_|   |_|  |_|___/_| |_| |_|\\__,_|" << std::endl;
        #if PY_MAJOR_VERSION==3
        rOStream << "         A Solver for Coupled Problems (with interface to Python 3)" << std::endl;
        #elif PY_MAJOR_VERSION==2
        rOStream << "         A Solver for Coupled Problems (with interface to Python 2)" << std::endl;
        #else
        #error "PY_MAJOR_VERSION is undefined"
        #endif
        rOStream << "   maintained by Hoang-Giang Bui" << std::endl;
        rOStream << "     Ruhr University Bochum     2013-2021" << std::endl;
        rOStream << "     Helmholtz-Zentrum Hereon   2022-2024" << std::endl;
        rOStream << "     University of Birmingham   2025" << std::endl;
        rOStream << "     Durham University          2026" << std::endl;
        rOStream << ">>>This product includes Kratos Multi-Physics technology<<<" << std::endl;
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
