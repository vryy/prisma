#
# Find the backtrace includes and library
# backtrace is crucial for boost-stacktrace to print out the line numbers. This is documented here:
#   https://github.com/boostorg/stacktrace/issues/97
#
# There is a FindBacktrace.cmake in cmake default modules but it is useless/broken, hence we write our own module.
#
# Backtrace_INCLUDE_DIR - where to find backtrace.h
# Backtrace_LIBRARIES   - List of fully qualified libraries to link against.
# Backtrace_FOUND       - Do not attempt to use if "no" or undefined.

set(Backtrace_INCLUDE_DIR ${BACKTRACE_ROOT}/include)
set(Backtrace_LIBRARY_DIR ${BACKTRACE_ROOT}/lib)

include_directories(${Backtrace_INCLUDE_DIR})

find_library(Backtrace_LIBRARY PATHS ${Backtrace_LIBRARY_DIR} NAMES backtrace)

# handle the QUIETLY and REQUIRED arguments and set Backtrace_FOUND to TRUE if
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Backtrace DEFAULT_MSG Backtrace_LIBRARY Backtrace_INCLUDE_DIR)

if(Backtrace_FOUND AND NOT TARGET Backtrace::Backtrace)
  add_library(Backtrace::Backtrace UNKNOWN IMPORTED)
  set_target_properties(
    Backtrace::Backtrace
    PROPERTIES IMPORTED_LOCATION "${Backtrace_LIBRARY}"
               INTERFACE_INCLUDE_DIRECTORIES "${Backtrace_INCLUDE_DIR}"
    )
endif()
