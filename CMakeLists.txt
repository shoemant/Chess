cmake_minimum_required(VERSION 3.10)

set( CMAKE_CXX_COMPILER "/msys64/ucrt64/bin/g++.exe")
set( CMAKE_C_COMPILER "/msys64/ucrt64/bin/gcc.exe")

project(ChessProject)

file(GLOB_RECURSE SOURCE_FILES
    src/*.cpp
    src/pieces/*.cpp
    src/ChessEngine/*.cpp
)
add_executable(chess ${SOURCE_FILES})

include_directories(include src)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
target_link_libraries(chess sfml-system sfml-window sfml-graphics)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(ASSETS_PATH "${CMAKE_SOURCE_DIR}/assets")
add_definitions(-DASSETS_PATH="${ASSETS_PATH}")
