cmake_minimum_required (VERSION 2.6)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/googletest/googletest/include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/googletest/googlemock/include)

MESSAGE( STATUS "GTEST_SOURCE_DIR:         " ${gtest_SOURCE_DIR} )

add_executable(Labyrinth-test test.cpp)
target_link_libraries(Labyrinth-test labyrinth_maker gtest gtest_main)
enable_testing()
add_test(NAME labyrinth_tests COMMAND Labyrinth-test)
