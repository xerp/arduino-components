cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/Arduino-toolchain.cmake)

project(Components CXX)

add_library(Components Base.cpp Base.h RotaryEncoder.cpp RotaryEncoder.h)
target_link_arduino_libraries(Components AUTO_PUBLIC)