//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:     BSD License
//           Kratos default license: kratos/license.txt
//
//  Main authors:    Carlos A. Roig Pina
//

#ifndef KRATOS_EXPORT_API_H
#define KRATOS_EXPORT_API_H

#undef KRATOS_API_EXPORT
#undef KRATOS_API_IMPORT
#undef KRATOS_API_NONE
#if _WIN32
    #if defined(__MINGW32__) || defined(__MINGW64__)
        #define KRATOS_API_EXPORT __attribute__((visibility("default")))
        #define KRATOS_API_IMPORT __attribute__((visibility("default")))
        #define KRATOS_API_NONE
    #else
        #define KRATOS_API_EXPORT __declspec(dllexport)
        #define KRATOS_API_IMPORT __declspec(dllimport)
        #define KRATOS_API_NONE
    #endif
#else
    #define KRATOS_API_EXPORT __attribute__((visibility("default")))
    #define KRATOS_API_IMPORT __attribute__((visibility("default")))
    #define KRATOS_API_NONE
#endif

#define KRATOS_APPEND_MACRO(base, suffix) base##suffix

// If KRATOS_API_NO_DLL is defined ignore the DLL api
#ifndef KRATOS_API_NO_DLL
    #define KRATOS_API(MACRO) KRATOS_APPEND_MACRO(KRATOS_API_, MACRO)
    #define KRATOS_NO_EXPORT(...)
#else
    #define KRATOS_API(...)
    #define KRATOS_NO_EXPORT(...)
#endif

// Conditionally declare explicit template instances, since explicit instiation does not play nice with dllexport
#undef KRATOS_API_EXTERN
#ifdef _WIN32
    #if defined(__MINGW32__) || defined(__MINGW64__)
        #define KRATOS_API_EXTERN extern
    #else
        #define KRATOS_API_EXTERN
    #endif
#else
    #define KRATOS_API_EXTERN extern
#endif

#endif
