project(common)

set(SOURCES
    "src/lib.cpp"
    "src/file_utils.cpp"
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_library(baas::common ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
