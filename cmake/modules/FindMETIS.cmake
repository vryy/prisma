# cmake/FindMETIS.cmake

find_path(METIS_INCLUDE_DIR metis.h
    HINTS "${METIS_ROOT_DIR}" $ENV{METIS_ROOT_DIR}
    PATH_SUFFIXES include
    NO_DEFAULT_PATH
)

find_library(METIS_LIBRARY metis
    HINTS "${METIS_ROOT_DIR}" $ENV{METIS_ROOT_DIR}
    PATH_SUFFIXES lib lib64
    NO_DEFAULT_PATH
)

# 1. Include the standard args module
include(FindPackageHandleStandardArgs)

# 2. Let CMake automatically check REQUIRED, QUIET, and populate METIS_FOUND
find_package_handle_standard_args(METIS
    REQUIRED_VARS METIS_LIBRARY METIS_INCLUDE_DIR
    FAIL_MESSAGE "Could NOT find METIS using METIS_ROOT_DIR: ${METIS_ROOT_DIR}"
)

# 3. Create the imported target if found
if(METIS_FOUND AND NOT TARGET METIS::METIS)
    add_library(METIS::METIS UNKNOWN IMPORTED)
    set_target_properties(METIS::METIS PROPERTIES
        IMPORTED_LOCATION "${METIS_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${METIS_INCLUDE_DIR}"
    )
endif()

mark_as_advanced(METIS_INCLUDE_DIR METIS_LIBRARY)
