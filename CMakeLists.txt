# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Project name
project(ArduinoComponents)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Arduino AVR include files
include_directories("$ENV{ARDUINO_INCLUDE_DIR}")

# Include all header files from the root directory of the source
include_directories(${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_library(ArduinoComponentLibraries SHARED ${SOURCE_FILES})

# Specify include directories for the library
target_include_directories(ArduinoComponentLibraries
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/arch)


add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE ArduinoComponentLibraries)