#include "gtest/gtest.h"
#include "src/MazeGenerator.hpp"
#include "src/Printer.hpp"

TEST(MazeFactory, BasicInitialization)
{
    const int SIZE = 2;
    const char FULL_BLOCK = '#';

    maze::Maze maze = maze::MazeGenerator::init<SIZE, SIZE>();
    display::MazeDisplay mazeDisplay = display::print(maze);

    std::vector<std::string>  expected = { "#####", "# # #", "#####", "# # #", "#####" };
    EXPECT_EQ(expected, mazeDisplay);
}
