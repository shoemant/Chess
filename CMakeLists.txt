cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "/msys64/ucrt64/bin/g++.exe")
set(CMAKE_C_COMPILER "/msys64/ucrt64/bin/gcc.exe")

# Project name
project(ChessProject)

# Set the runtime output directory to the project root
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Add the executable
file(GLOB_RECURSE SOURCE_FILES
    src/*.cpp
    src/pieces/*.cpp
)
add_executable(chess ${SOURCE_FILES})

# Include directories
include_directories(include src)

# Link SFML libraries
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
target_link_libraries(chess sfml-system sfml-window sfml-graphics)

# Set assets directory as a runtime path
set(ASSETS_PATH "${CMAKE_SOURCE_DIR}/assets")
add_definitions(-DASSETS_PATH="${ASSETS_PATH}")
