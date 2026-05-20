#FIND_PATH(ADOL_C_INCLUDE_DIR adolc.h
#    "${ADOL_C_DIR}/include/adolc"
#)

find_library(ADOL_C_LIBRARY adolc PATHS "${ADOL_C_DIR}/lib64" NO_DEFAULT_PATH)

# message("ADOL_C_DIR:" ${ADOL_C_DIR})
# message("ADOL_C_LIBRARY:" ${ADOL_C_LIBRARY})

if(ADOL_C_LIBRARY)
    set(ADOL_C_INCLUDE_DIR "${ADOL_C_DIR}/include")
    set(ADOL_C_FOUND TRUE)

    if(NOT TARGET ADOLC::lib)

        add_library(ADOLC::lib INTERFACE IMPORTED GLOBAL)

        target_link_libraries(ADOLC::lib INTERFACE ${ADOL_C_LIBRARY})

        target_include_directories(ADOLC::lib INTERFACE ${ADOL_C_INCLUDE_DIR})

        set_target_properties(ADOLC::lib PROPERTIES INTERFACE_LINK_DIRECTORIES "${ADOL_C_DIR}/lib64")

        if(CMAKE_INSTALL_RPATH_USE_LINK_PATH MATCHES TRUE)
            target_link_options(ADOLC::lib INTERFACE "-Wl,-rpath,${ADOL_C_DIR}/lib64")
        endif()

    endif()

    message("-- Found ADOL-C at " ${ADOL_C_DIR})
else()
    message("-- Finding ADOL-C failed, please try to set the var ADOL_C_DIR")
endif()
