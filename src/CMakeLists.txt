cmake_minimum_required (VERSION 2.6)

set(SRC_LIB
    MazeNode.cpp
    MazeEdge.cpp
    Printer.cpp)

add_library(maze_maker ${SRC_LIB})
