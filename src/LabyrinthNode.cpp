#include "LabyrinthNode.hpp"
#include <algorithm>

namespace labyrinth {

LabyrinthNode::LabyrinthNode(int x, int y):
    x(x),
    y(y),
    type(NodeType::Standard)
{}

LabyrinthNode::LabyrinthNode():
    x(0),
    y(0),
    type(NodeType::Standard)
{}


}

