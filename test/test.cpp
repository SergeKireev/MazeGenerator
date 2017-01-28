#include "gtest/gtest.h"
#include "src/MazeGenerator.hpp"
#include "src/Printer.hpp"

TEST(MazeFactory, BasicDisplay)
{
    const int SIZE = 2;
    const char FULL_BLOCK = '#';

    maze::Maze maze = maze::MazeGenerator::create(SIZE, SIZE);
    display::MazeDisplay mazeDisplay = display::print(maze);

    std::vector<std::string>  expected = { "#####", "# # #", "#####", "# # #", "#####" };
    EXPECT_EQ(expected, mazeDisplay);
}

TEST(MazeFactory, TotalPruning)
{
    const int SIZE = 20;
    const char FULL_BLOCK = '#';

    std::random_device rd;
    maze::Maze maze = maze::MazeGenerator::create(SIZE, SIZE);

    display::MazeDisplay mazeDisplay = display::print(maze);

    std::for_each(mazeDisplay.begin(), mazeDisplay.end(), [](const std::string& row) {
        std::cout << row << std::endl;
    });

    std::vector<std::string>  expected = { "#####", "#   #", "# # #", "#   #", "#####" };
    EXPECT_EQ(expected, mazeDisplay);
}

