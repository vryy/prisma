//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                     Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//  Contributors:    Hoang-Giang Bui
//

// System includes

// External includes

// Project includes
#include "includes/element.h"
#include "includes/legacy_structural_app_vars.h"
#include "includes/node.h"

namespace Kratos
{

template<class TNodeType>
typename BaseElement<TNodeType>::IntegrationMethod BaseElement<TNodeType>::GetIntegrationMethod() const
{
	if(this->Has( INTEGRATION_ORDER ))
    {
        if(this->GetValue(INTEGRATION_ORDER) == 1)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_1;
        }
        else if(this->GetValue(INTEGRATION_ORDER) == 2)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_2;
        }
        else if(this->GetValue(INTEGRATION_ORDER) == 3)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_3;
        }
        else if(this->GetValue(INTEGRATION_ORDER) == 4)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_4;
        }
        else if(this->GetValue(INTEGRATION_ORDER) == 5)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_5;
        }
        else
            KRATOS_ERROR << this->Info() << " does not support for integration order " << this->GetValue(INTEGRATION_ORDER);
    }
    else if(this->GetProperties().Has( INTEGRATION_ORDER ))
    {
        if(this->GetProperties()[INTEGRATION_ORDER] == 1)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_1;
        }
        else if(this->GetProperties()[INTEGRATION_ORDER] == 2)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_2;
        }
        else if(this->GetProperties()[INTEGRATION_ORDER] == 3)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_3;
        }
        else if(this->GetProperties()[INTEGRATION_ORDER] == 4)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_4;
        }
        else if(this->GetProperties()[INTEGRATION_ORDER] == 5)
        {
            return GeometryData::IntegrationMethod::GI_GAUSS_5;
        }
        else
            KRATOS_ERROR << this->Info() << " does not support for integration order " << this->GetProperties()[INTEGRATION_ORDER];
    }
    else
        return this->GetGeometry().GetDefaultIntegrationMethod(); // default method
}

template class BaseElement<RealNode>;
template class BaseElement<ComplexNode>;
template class BaseElement<GComplexNode>;

} // namespace Kratos.
