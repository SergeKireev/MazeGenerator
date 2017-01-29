cmake_minimum_required (VERSION 2.6)

set(SRC_LIB
    MazeNode.cpp
    MazeEdge.cpp
    Printer.cpp)

MESSAGE( STATUS "Flags : ${CMAKE_CXX_FLAGS}")
add_library(maze_maker ${SRC_LIB})
