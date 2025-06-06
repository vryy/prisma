set(CMAKE_INCLUDE_CURRENT_DIR ON)

## generate variables with the sources
set( TETGEN_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/tetgen.cxx
)

set( UNOPTIMIZED_PREDICATES ${CMAKE_CURRENT_SOURCE_DIR}/predicates.cxx )

##removing optimizations
set_source_files_properties(${UNOPTIMIZED_PREDICATES} PROPERTIES COMPILE_FLAGS -O0)
set_source_files_properties(
    ${TETGEN_SOURCES}
    PROPERTIES COMPILE_FLAGS "$<$<CONFIG:Release>:-O2>"
)

###############################################################
add_definitions( -DTETLIBRARY )
#perform platform specific defintions
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions( -DCPU86 )
    add_definitions( -DNO_TIMER )
else(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions( -DLINUX )
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

add_definitions( -w )

###############################################################
add_library(tetgen150 STATIC ${TETGEN_SOURCES} ${UNOPTIMIZED_PREDICATES} )
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(tetgen150 m)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
