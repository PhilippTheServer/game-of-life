cmake_minimum_required(VERSION 3.10)

# Project name
project(game-of-life)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER g++)

add_executable(game-of-life 
    src/main.cpp
    src/terminal/terminal.cpp
    src/world/world.cpp
    src/renderer/renderer.cpp
)

set_directory_properties(PROPERTIES
    ADDITIONAL_MAKE_CLEAN_FILES
    "${CMAKE_BINARY_DIR}/logs"
)
