#ifndef MAZE_FACTORY_HPP
#define MAZE_FACTORY_HPP

#include <vector>
#include <string>
#include "MazeNode.hpp"

namespace maze {

typedef std::vector<std::vector<MazeNode>> Maze;

class MazeGenerator {
public:
    static Maze create(const int W, const int H);
};

}

#endif
