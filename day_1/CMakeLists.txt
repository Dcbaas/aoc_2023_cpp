project(day_1)

set(SOURCES
    "src/main.cpp"
    "src/spelled_numbers.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    baas::common
)

configure_file(${PROJECT_SOURCE_DIR}/input/example.txt input/example.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/input/example2.txt input/example2.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/input/data.txt input/data.txt COPYONLY)
