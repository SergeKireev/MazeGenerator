#include "gtest/gtest.h"
#include "src/LabyrinthFactory.hpp"
#include "src/Printer.hpp"

TEST(LabyrinthFactory, BasicDisplay)
{
    const int SIZE = 2;
    const char FULL_BLOCK = '#';

    labyrinth::Labyrinth labyrinth = labyrinth::LabyrinthFactory::create(SIZE, SIZE);
    display::LabyrinthDisplay labyrinthDisplay = display::print(labyrinth);

    std::vector<std::string>  expected = { "#####", "# # #", "#####", "# # #", "#####" };
    EXPECT_EQ(expected, labyrinthDisplay);
}

TEST(LabyrinthFactory, TotalPruning)
{
    const int SIZE = 20;
    const char FULL_BLOCK = '#';

    std::random_device rd;
    labyrinth::Labyrinth labyrinth = labyrinth::LabyrinthFactory::create(SIZE, SIZE);

    display::LabyrinthDisplay labyrinthDisplay = display::print(labyrinth);

    std::for_each(labyrinthDisplay.begin(), labyrinthDisplay.end(), [](const std::string& row) {
        std::cout << row << std::endl;
    });

    std::vector<std::string>  expected = { "#####", "#   #", "# # #", "#   #", "#####" };
    EXPECT_EQ(expected, labyrinthDisplay);
}

