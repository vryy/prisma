# temporarily disable our own finders for module lookup
list(REMOVE_ITEM CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

# Get Trilinos as one entity
# message("Trilinos_PREFIX: " ${Trilinos_PREFIX})
set(CMAKE_PREFIX_PATH ${Trilinos_PREFIX})
set(Trilinos_DIR "${Trilinos_PREFIX}/lib/cmake/Trilinos")

# call the built-in finder with the specifications set outside
find_package(Trilinos)

# re-enable our own finders
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

# Echo trilinos build info just for fun
message(STATUS "Found Trilinos: ${Trilinos_DIR} (Version ${Trilinos_VERSION})")
message(STATUS "Trilinos packages: ${Trilinos_PACKAGE_LIST}")
message(STATUS "Trilinos TPLs: ${Trilinos_TPL_LIST}")

if(Trilinos_FOUND AND NOT TARGET Trilinos::all_selected_libs)
  # In preparation for newer Trilinos releases, create a target
  # Trilinos::all_selected_libs with the correct dependencies
  add_library(Trilinos::all_selected_libs IMPORTED INTERFACE)
  target_include_directories(
    Trilinos::all_selected_libs
    SYSTEM
    INTERFACE ${Trilinos_INCLUDE_DIRS}
    INTERFACE ${Trilinos_TPL_INCLUDE_DIRS}
    )
  target_link_libraries(
    Trilinos::all_selected_libs INTERFACE ${Trilinos_LIBRARIES} ${Trilinos_TPL_LIBRARIES}
    )
endif()

# add_trilinos_package_definitions(Trilinos::all_selected_libs "${Trilinos_PACKAGE_LIST}")
