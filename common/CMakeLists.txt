project(common)

set(SOURCES
    "src/file_utils.cpp"
    "src/string_utils.cpp"
)
if(MSVC)
    add_library(${PROJECT_NAME} STATIC ${SOURCES})

else()
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
endif(MSVC)

add_library(baas::common ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
