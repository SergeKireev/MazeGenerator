#ifndef MAZE_FACTORY_HPP
#define MAZE_FACTORY_HPP

#include <vector>
#include <string>
#include "MazeNode.hpp"

namespace maze {

typedef std::vector<std::vector<MazeNode>> Maze;

class MazeGenerator {
public:
    template <int W, int H>
    static Maze init();

    template <int W, int H>
    static void build(Maze& maze);
};

}
#include "MazeGenerator.inl.hpp"

#endif
