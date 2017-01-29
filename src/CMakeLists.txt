cmake_minimum_required (VERSION 2.6)

set(SRC_LIB
    MazeNode.cpp
    MazeEdge.cpp
    Printer.cpp)

if(CMAKE_VERSION VERSION_EQUAL 3.1 OR CMAKE_VERSION VERSION_GREATER 3.1)
  set(CMAKE_CXX_STANDARD 11)
  MESSAGE(STATUS "Cmake superior to 3.1")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

MESSAGE( STATUS "Flags : ${CMAKE_CXX_FLAGS}")
add_library(maze_maker ${SRC_LIB})
