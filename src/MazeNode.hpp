#ifndef LABYRINTH_NODE_HPP
#define LABYRINTH_NODE_HPP

#include <memory>
#include <vector>
#include "MazeEdge.hpp"

namespace maze {

enum class NodeType {
    Standard,
    Initial,
    Final
};

struct MazeNode {
    MazeNode(int x, int y);
    MazeNode();
    int x;
    int y;
    std::vector<MazeEdge> neighborEdges;
    NodeType type;
};

}

#endif
