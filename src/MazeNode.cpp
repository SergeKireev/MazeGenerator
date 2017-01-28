#include "MazeNode.hpp"
#include <algorithm>

namespace maze {

MazeNode::MazeNode(int x, int y):
    x(x),
    y(y),
    type(NodeType::Standard)
{}

MazeNode::MazeNode():
    x(0),
    y(0),
    type(NodeType::Standard)
{}


}

