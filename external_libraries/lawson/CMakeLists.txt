set(LAWSON_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/lawson.f
)

add_library(lawson STATIC ${LAWSON_SOURCE})
