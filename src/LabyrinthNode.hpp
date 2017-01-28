#ifndef LABYRINTH_NODE_HPP
#define LABYRINTH_NODE_HPP

#include <memory>
#include <vector>
#include "LabyrinthEdge.hpp"

namespace labyrinth {

enum class NodeType {
    Standard,
    Initial,
    Final
};

struct LabyrinthNode {
    LabyrinthNode(int x, int y);
    LabyrinthNode();
    int x;
    int y;
    std::vector<LabyrinthEdge> neighborEdges;
    NodeType type;
};

}

#endif
