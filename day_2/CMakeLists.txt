project(day_2)

set(SOURCES
    "src/main.cpp"
    "src/game.cpp"
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
configure_file(${PROJECT_SOURCE_DIR}/input/data.txt input/data.txt COPYONLY)
