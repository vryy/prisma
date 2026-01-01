set(CMAKE_INCLUDE_CURRENT_DIR ON)

#include cotire (CMake module to hep generating precompiled header to speed-up the build process)
# include(cotire)

# ## add the include directories needed for the compilation
# message("current dir = " ${CMAKE_CURRENT_SOURCE_DIR})
# include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/sources )
# include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/container )
# include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/python )


## generate variables with the sources
set( KRATOS_CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/containers/variable_data.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/containers/variables_list.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/containers/variables_list_data_value_container.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/containers/model.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/geometries/point.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/mmio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/code_location.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/kratos_exception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/io.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/kratos_components.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/communicator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/element.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/condition.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/constitutive_law.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/serializer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/variables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/global_variables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/deprecated_variables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/c2c_variables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/cfd_variables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/dem_variables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/legacy_structural_app_vars.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/model_part.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/model_part_io.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/periodic_condition.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/kratos_application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/kernel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/reorder_consecutive_model_part_io.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/bounding_volume_tree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/kratos_filesystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/kratos_parameters.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/math_utils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/io.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/model_part_io.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/reorder_consecutive_model_part_io.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utilities/logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utilities/constraint_utilities.cpp
)

if (MSVC)
    # for some reason, explicit instantiation is necessary for the Microsoft compiler
    set(KRATOS_CORE_SOURCES ${KRATOS_CORE_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/utilities/indexed_object.cpp
    )
endif()

if(${MPI_FOUND})
    set(KRATOS_CORE_SOURCES ${KRATOS_CORE_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/mpi_communicator.cpp)
endif()

if( ${KRATOS_PYTHON} MATCHES TRUE)
    set( KRATOS_PYTHON_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_model_part_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_model_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_constant_matrix_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_points_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_variables_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_deprecated_variables_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_c2c_variables_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_cfd_variables_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_dem_variables_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_legacy_structural_app_vars_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_containers_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_constitutive_law_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_processes_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_quadratures_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_geometries_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_integration_points_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_io_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_kernel_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_vector_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_kratos_application_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_matrix_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_mesh_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/vectorial_spaces_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_properties_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_node_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_linear_solvers_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_strategies_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_spaces_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_utilities_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_process_info_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_matrix_market_interface_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_serializer_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_table_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_search_strategies_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_kratos_parameters_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/add_constraint_to_python.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/python/kratos_python.cpp
    )
endif()

###############################################################
## define library KratosCore to be included in all of the others
add_library(KratosCore SHARED ${KRATOS_CORE_SOURCES})
if(KRATOS_INDEX_TYPE STREQUAL "int")
    target_compile_definitions(KratosCore PRIVATE KRATOS_INDEX_TYPE_IS_INT=1)
else()
    target_compile_definitions(KratosCore PRIVATE KRATOS_INDEX_TYPE_IS_INT=0)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Android")
    target_compile_definitions(KratosCore PRIVATE KRATOS_CORE=)
else()
    target_compile_definitions(KratosCore PRIVATE KRATOS_CORE=EXPORT)
endif()

if(MSVC)
    target_compile_options(KratosCore PRIVATE /bigobj)
    target_compile_options(KratosCore PRIVATE /permissive) # enforce stricter compliant with C++ standard
endif()
if((${CMAKE_CXX_COMPILER_ID} MATCHES Clang) OR (${CMAKE_CXX_COMPILER_ID} MATCHES GNU))
    target_compile_options(KratosCore PRIVATE -pedantic-errors) # enforce strict compliant with C++ standard
endif()

if(${KRATOS_PYTHON} MATCHES TRUE)
    target_link_libraries(KratosCore PUBLIC ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${PYTHON_LIBRARIES} gidpost )
else()
    target_link_libraries(KratosCore PUBLIC ${Boost_LIBRARIES} gidpost )
endif()

if(${MPI_FOUND})
    target_compile_definitions(KratosCore PUBLIC KRATOS_USING_MPI)
    target_link_libraries(KratosCore PUBLIC MPI::MPI_CXX )
endif()

set(KRATOS_STACKTRACE_LEVEL 1 CACHE STRING "Stacktrace level for Kratos with boost::stacktrace")
message("KRATOS_STACKTRACE_LEVEL: " ${KRATOS_STACKTRACE_LEVEL})
target_compile_definitions(KratosCore PRIVATE KRATOS_STACKTRACE_LEVEL=${KRATOS_STACKTRACE_LEVEL})
if(Backtrace_FOUND)
    target_compile_definitions(KratosCore PRIVATE KRATOS_USE_BACKTRACE)
    target_link_libraries(KratosCore PUBLIC ${Backtrace_LIBRARY})
else()
    target_compile_definitions(KratosCore PRIVATE BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED=1)
endif()

# expose the parent directory to any linking target in case it wants to link with external_libraries
target_include_directories(KratosCore PUBLIC ${CMAKE_SOURCE_DIR})
# expose the kratos directory to any linking target
target_include_directories(KratosCore PUBLIC ${CMAKE_SOURCE_DIR}/kratos)
# expose the applications directory in case the target wants to include like appname_application/custom...
target_include_directories(KratosCore PUBLIC ${CMAKE_SOURCE_DIR}/applications)
if(MSVC AND ${KRATOS_USE_INTEL_OPENMP} MATCHES ON)
    target_link_libraries(KratosCore ${INTEL_OPENMP_LIBRARY})
endif()
# cotire(KratosCore)

# if(${ADOL_C_FOUND} MATCHES TRUE)
#     target_link_libraries(KratosCore PRIVATE ${ADOL_C_LIBRARIES} )
# endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Android")
    # DO NOT INSTALL ON ANDROID
else()
    install(TARGETS KratosCore DESTINATION libs )
endif()

if(${INSTALL_PYTHON_FILES} MATCHES ON)
  get_filename_component (CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/python_scripts DESTINATION kratos/  FILES_MATCHING PATTERN "*.py"  PATTERN ".svn" EXCLUDE)
endif(${INSTALL_PYTHON_FILES} MATCHES ON)

###############################################################
if(${KRATOS_PYTHON} MATCHES TRUE)
    ## define library Kratos which defines the basic python interface
    add_library(Kratos SHARED ${KRATOS_PYTHON_SOURCES})
    if(MSVC)
        target_compile_options(Kratos PRIVATE /bigobj)
    endif()
    target_link_libraries(Kratos PRIVATE KratosCore)
    target_compile_definitions(Kratos PRIVATE KRATOS_CORE=IMPORT)
    set_target_properties(Kratos PROPERTIES PREFIX "")

    # changing the .dll suffix to .pyd
    if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set_target_properties(Kratos PROPERTIES SUFFIX .pyd)
    endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

    # changing the .dylib suffix to .so
    if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set_target_properties(Kratos PROPERTIES SUFFIX .so)
    endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

    install(TARGETS Kratos DESTINATION libs )
endif()
###############################################################

add_subdirectory(tests)
