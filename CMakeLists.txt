cmake_minimum_required (VERSION 2.6)

project (maze_maker)
add_subdirectory(src)
add_subdirectory(test)

add_definitions(-DBUILD_SHARED_LIBS=1)
add_subdirectory(thirdparty/gtest)
