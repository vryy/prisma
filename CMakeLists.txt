cmake_minimum_required (VERSION 2.8.6...3.19.4)
project (KratosMultiphysics)

if(${CMAKE_SYSTEM_NAME} MATCHES "Android")
    message("kratos_bcn2 is compiled on Android")
    include(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.android.txt)
else()
    include(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.unix.txt)
endif()
