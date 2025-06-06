set(CMAKE_INCLUDE_CURRENT_DIR ON)

## generate variables with the sources
set( MPI_PYTHON_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/python_interface.cpp
)

add_definitions( -w )

###############################################################
add_library(mpipython SHARED ${MPI_PYTHON_SOURCES})

if(CMAKE_VERSION VERSION_LESS "3.30")
    target_include_directories(mpipython PRIVATE ${MPI_INCLUDE_PATH})
    target_link_libraries(mpipython ${Boost_PYTHON${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}_LIBRARIES} ${PYTHON_LIBRARIES} ${MPI_LIBRARIES})
else()
    target_link_libraries(mpipython PUBLIC Boost::python MPI::MPI_CXX ${PYTHON_LIBRARIES})
endif()

set_target_properties(mpipython PROPERTIES PREFIX "")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set_target_properties(mpipython PROPERTIES SUFFIX .pyd)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# changing the .dylib suffix to .so
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set_target_properties(mpipython PROPERTIES SUFFIX .so)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# Install library and Python file
install(TARGETS mpipython DESTINATION libs )
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/mpi.py" DESTINATION KratosMultiphysics )
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/nompi.py" DESTINATION KratosMultiphysics )
