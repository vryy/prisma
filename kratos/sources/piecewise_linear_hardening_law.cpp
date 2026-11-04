//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ \.
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//

#include "includes/piecewise_linear_hardening_law.h"

namespace Kratos
{

PiecewiseLinearHardeningLaw::PiecewiseLinearHardeningLaw() : HardeningLaw()
{}

PiecewiseLinearHardeningLaw::~PiecewiseLinearHardeningLaw()
{}

HardeningLaw::Pointer PiecewiseLinearHardeningLaw::Clone() const
{
    return HardeningLaw::Pointer(new PiecewiseLinearHardeningLaw());
}

bool PiecewiseLinearHardeningLaw::Has( const Variable<double>& rThisVariable ) const
{
    return false;
}

double& PiecewiseLinearHardeningLaw::GetValue( const Variable<double>& rThisVariable, double& rValue )
{
    return rValue;
}

void PiecewiseLinearHardeningLaw::SetValue( const Variable<double>& rThisVariable, const double rValue,
                                            const ProcessInfo& rCurrentProcessInfo )
{
}

double PiecewiseLinearHardeningLaw::GetValue(const double phi) const
{
    const std::size_t n = mPx.size();

    if (phi < mPx[0])
        return mPy[0];

    for (std::size_t i = 1; i < n; ++i)
    {
        if (phi < mPx[i])
        {
            return mPy[i-1] + (phi - mPx[i-1]) / (mPx[i] - mPx[i-1]) * (mPy[i] - mPy[i-1]);
        }
    }

    return mPy[n-1];
}

double PiecewiseLinearHardeningLaw::GetDerivative(const double phi) const
{
    const std::size_t n = mPx.size();

    if (phi < mPx[0])
        return 0.0;

    for (std::size_t i = 1; i < n; ++i)
    {
        if (phi < mPx[i])
        {
            return  (mPy[i] - mPy[i-1]) / (mPx[i] - mPx[i-1]);
        }
    }

    return 0.0;
}

} /* namespace Kratos.*/
