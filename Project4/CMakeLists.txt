cmake_minimum_required(VERSION 2.8.12.2)
project(project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

set(SOURCE_FILES main.cpp Graph.cpp Graph.h Node.cpp Node.h Ladder.cpp Ladder.h)
add_executable(project4 ${SOURCE_FILES})