#if !defined(PYTHON_DEF_H_INCLUDED)
#define  PYTHON_DEF_H_INCLUDED

#ifdef slots
#undef slots // Undefine Qt's slots macro
#endif

#ifndef BOOST_DEBUG_PYTHON

// this is to tell the linker not to link with debug Python libraries
// since including <Python.h> will ALWAYS link wih the debug Python libraries by default.
// The remedy is to check if debug libraries can be used (via BOOST_DEBUG_PYTHON flag).
// If we enforce not using debug libraries (by not defining BOOST_DEBUG_PYTHON), then
// the logic below will temporarily disable the _DEBUG flag before including Python.h

    #ifdef _DEBUG
    #undef _DEBUG
    #include <Python.h>
    #define _DEBUG // Re-define _DEBUG after including Python.h
    #else
    #include <Python.h>
    #endif

#else // BOOST_DEBUG_PYTHON

    #include <Python.h>

#endif

#endif // PYTHON_DEF_H_INCLUDED
