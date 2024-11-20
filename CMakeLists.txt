# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Project name
project(ArduinoComponents)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers directory
include_directories()
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add a subdirectory for source files
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# Specify include directories for the library
target_include_directories(ArduinoComponents PUBLIC ${PROJECT_SOURCE_DIR}/include)