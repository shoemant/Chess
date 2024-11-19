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

set(CMAKE_BUILD_TYPE Debug)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
target_link_libraries(chess sfml-system sfml-window sfml-graphics)

set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Set runtime output to build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Define asset path as a preprocessor definition
set(ASSETS_PATH "${CMAKE_SOURCE_DIR}/assets")
add_definitions(-DASSETS_PATH="${ASSETS_PATH}")

# Add custom command to copy the assets folder
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
    COMMENT "Copying assets folder to build directory"
)

# Make sure assets are copied before running the executable
add_dependencies(chess copy_assets)
