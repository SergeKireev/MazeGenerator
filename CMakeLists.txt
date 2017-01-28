cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)

project (maze_maker)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(thirdparty/gtest)
