cmake_minimum_required (VERSION 2.6)

set(SRC_LIB
    LabyrinthFactory.cpp
    LabyrinthNode.cpp
    LabyrinthEdge.cpp
    Printer.cpp)

add_library(labyrinth_maker ${SRC_LIB})
