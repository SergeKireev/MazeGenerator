cmake_minimum_required (VERSION 2.6)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/gtest/googletest/include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/gtest/googlemock/include)

MESSAGE( STATUS "GTEST_SOURCE_DIR:         " ${gtest_SOURCE_DIR} )

if(CMAKE_VERSION VERSION_EQUAL 3.1 OR CMAKE_VERSION VERSION_GREATER 3.1)
  set(CMAKE_CXX_STANDARD 11)
  MESSAGE(STATUS "Cmake superior to 3.1")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

add_executable(Maze-test test.cpp)
target_link_libraries(Maze-test maze_maker gtest gtest_main)
enable_testing()
add_test(NAME maze_tests COMMAND Maze-test)
