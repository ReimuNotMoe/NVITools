cmake_minimum_required(VERSION 2.8)
project(NVITools)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        DataDecoder.cpp)

add_executable(DataDecoder ${SOURCE_FILES})
add_executable(DataEncoder DataEncoder.cpp)