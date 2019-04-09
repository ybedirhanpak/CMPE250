cmake_minimum_required(VERSION 3.6)
project(project3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

set(SOURCE_FILES main.cpp Graph.cpp Graph.h Node.cpp Node.h SCC.cpp SCC.h)
add_executable(project3 ${SOURCE_FILES})