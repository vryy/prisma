# Find the MKL includes and libraries which includes high performance (and free) PARDISO solver
#
# It creates the target MKLSolverLibraries which can be linked against using
#   target_link_libraries(KratosMKLSolversApplication PUBLIC MKLSolverLibraries)
# but the configure script must provide
#   MKLSOLVER_INCLUDE_DIR - where to find the headers
#   MKLSOLVER_LIB_DIR     - where to find the libraries

find_path(MKLSOLVER_INCLUDE_DIR mkl_blas.h ${MKLSOLVER_INCLUDE_DIR})

# set(LIB_MKL_LIST mkl_intel_ilp64 mkl_intel_thread mkl_core mkl_solver_ilp64 mkl_mc mkl_mc3 mkl_lapack pthread mkl_p4n iomp5)

find_library(AUX1 mkl_intel_ilp64 ${MKLSOLVER_LIB_DIR})

if(CMAKE_COMPILER_IS_GNUCXX)
    find_library(AUX2 mkl_gnu_thread ${MKLSOLVER_LIB_DIR})
else()
    find_library(AUX2 mkl_intel_thread ${MKLSOLVER_LIB_DIR})
endif()

find_library(AUX3 mkl_core ${MKLSOLVER_LIB_DIR})

#find_library(AUX5 mkl_mc # kernel library for SSE3
#  ${MKLSOLVER_LIB_DIR}
#)

if(NOT(${CMAKE_SYSTEM_NAME} MATCHES "Windows"))
  find_library(AUX6 mkl_mc3 ${MKLSOLVER_LIB_DIR}) # kernel library for SSE4.2
endif()

#find_library(AUX7 mkl_lapack95_ilp64 ${MKLSOLVER_LIB_DIR})

if(NOT(${CMAKE_SYSTEM_NAME} MATCHES "Windows"))
  find_library(AUX8 pthread ${MKLSOLVER_LIB_DIR})
endif()

#find_library(AUX9 mkl_p4n ${MKLSOLVER_LIB_DIR})

##ATTENTION! the order of libraries is FUNDAMENTAL!! take care!!!
if(MKLSOLVER_INCLUDE_DIR AND AUX1)
    set( MKLSOLVER_FOUND "YES" )

    if(NOT TARGET MKLSOLVER::lib)

        add_library(MKLSOLVER::lib INTERFACE IMPORTED GLOBAL)

        target_compile_definitions(MKLSOLVER::lib INTERFACE MKL_ILP64)

        target_link_libraries(MKLSOLVER::lib INTERFACE
            ${AUX1} ${AUX2} ${AUX3} ${AUX4}  ${AUX7} ${AUX5} ${AUX6} ${AUX8}  ${AUX9}
        )

        target_include_directories(MKLSOLVER::lib INTERFACE ${MKLSOLVER_INCLUDE_DIR})

        set_target_properties(MKLSOLVER::lib PROPERTIES INTERFACE_LINK_DIRECTORIES "${MKLSOLVER_LIB_DIR}")

        if(CMAKE_INSTALL_RPATH_USE_LINK_PATH)
          target_link_options(MKLSOLVER::lib INTERFACE "-Wl,-rpath,${MKLSOLVER_LIB_DIR}")
        endif()

        message("************ mkl solver libraries found ************")

    endif()
else()
    message("finding MKLSOLVER includes failed. Try to set MKLSOLVER_INCLUDE_DIR and MKLSOLVER_LIB_DIR.")
endif()
