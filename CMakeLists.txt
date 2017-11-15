cmake_minimum_required(VERSION 3.7.1)
project(SimHash)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/simhash.h src/simhash.cpp)
add_executable(SimHash ${SOURCE_FILES})