cmake_minimum_required(VERSION 3.6)
project(Gestionnaire_de_prossess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Gestionnaire_de_prossess ${SOURCE_FILES})