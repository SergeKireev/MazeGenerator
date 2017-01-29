cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project (maze_maker)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(thirdparty/gtest)
