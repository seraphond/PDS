cmake_minimum_required(VERSION 3.6)
project(TPTD2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES mdu.c)
add_executable(TPTD2 ${SOURCE_FILES})