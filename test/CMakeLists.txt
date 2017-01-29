cmake_minimum_required (VERSION 2.6)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/gtest/googletest/include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/gtest/googlemock/include)

MESSAGE( STATUS "GTEST_SOURCE_DIR:         " ${gtest_SOURCE_DIR} )

add_executable(Maze-test test.cpp)
target_link_libraries(Maze-test maze_maker gtest gtest_main)
enable_testing()
add_test(NAME maze_tests COMMAND Maze-test)
