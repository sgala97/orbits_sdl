cmake_minimum_required(VERSION 3.25.2)

project(orbit)

file(GLOB SOURCES src/*)

file(GLOB HEADERS include/*)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER})

target_include_directories(orbit PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(orbit PRIVATE -lSDL2 -lSDL2_gfx)