//
//   Project Name:        Kratos
//   Last Modified by:    $Author: Giang Bui-Hoang $
//   Date:                $Date: 25 Feb 2018 $
//
//


#if !defined(KRATOS_ADOL_C_TAPE_UTILITY_INCLUDED )
#define  KRATOS_ADOL_C_TAPE_UTILITY_INCLUDED

// System includes

// External includes
#include <adolc/adolc.h>

// Project includes
#include "includes/define.h"
#ifdef _OPENMP
#include <omp.h>
#include <adolc/adolc_openmp.h>
#endif


namespace Kratos
{

class AdolCTapeUtility
{
public:
    KRATOS_CLASS_POINTER_DEFINITION( AdolCTapeUtility );

    template<typename TTape>
    static void Register()
    {
        TTape::Register();
    }
};

template<class TAdolCTapeType>
void AdolCTapeUtility_Register(AdolCTapeUtility& rDummy)
{
    rDummy.Register<TAdolCTapeType>();
}

}

#endif // KRATOS_ADOL_C_TAPE_UTILITY_INCLUDED defined
