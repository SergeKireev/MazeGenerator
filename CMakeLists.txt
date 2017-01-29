cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_VERSION VERSION_EQUAL 3.1 OR CMAKE_VERSION VERSION_GREATER 3.1)
  set(CMAKE_CXX_STANDARD 14)
  MESSAGE(STATUS "Cmake superior to 3.1")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

MESSAGE( STATUS "Flags : ${CMAKE_CXX_FLAGS}")

project (maze_maker)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(thirdparty/gtest)
