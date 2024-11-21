# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Project name
project(ArduinoComponents)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include all header files
include_directories(${CMAKE_SOURCE_DIR})

# Add a subdirectory for source files
add_subdirectory(${PROJECT_SOURCE_DIR}/arch)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# Specify include directories for the library
target_include_directories(ArduinoComponents
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/arch)