set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARIES})

############ module to include sys libs #############
include(InstallRequiredSystemLibraries)

## generate variables with the sources
set( EMBEDDED_PYTHON_SOURCES
     ${CMAKE_CURRENT_SOURCE_DIR}/krun_main.cpp
     )

###############################################################
add_executable(runkratos ${EMBEDDED_PYTHON_SOURCES} )

if(MSVC)
     if(PYTHON_LIBRARIES MATCHES "d$")
        add_compile_definitions(runkratos KRATOS_USE_DEBUG_PYTHON_LIBRARY)
     else()
        add_compile_definitions(runkratos KRATOS_USE_RELEASE_PYTHON_LIBRARY)
     endif()
endif()

target_link_libraries(runkratos ${EXTRA_LINK_LIBS} ${PYTHON_LIBRARIES})
install(TARGETS runkratos DESTINATION .)

