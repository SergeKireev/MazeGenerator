#include "Printer.hpp"
#include <numeric>

namespace display {

static const char EMPTY_BLOCK = ' ';
static const char FULL_BLOCK = '#';

namespace {

MazeDisplay* printEdge(MazeDisplay* mazeDisplay, const maze::MazeEdge& edge)
{
    const maze::MazeNode& source = *edge.getSource();
    const maze::MazeNode& destination = *edge.getDestination();
    int x = (source.x + destination.x)/2;
    int y = (source.y + destination.y)/2;

    if (edge.isOpen())
        (*mazeDisplay)[x][y] = EMPTY_BLOCK;
    return mazeDisplay;
}

MazeDisplay* printNode(MazeDisplay* mazeDisplay, const maze::MazeNode& node)
{
    (*mazeDisplay)[node.x][node.y] = EMPTY_BLOCK;
    std::accumulate(std::begin(node.neighborEdges), std::end(node.neighborEdges), mazeDisplay, &printEdge);
    return mazeDisplay;
}


MazeDisplay* printRowNodes(MazeDisplay* mazeDisplay, const std::vector<maze::MazeNode>& rowNodes)
{
    std::accumulate(rowNodes.begin(), rowNodes.end(), mazeDisplay, &printNode);
    return mazeDisplay;
}

} //anonymous

MazeDisplay print(const maze::Maze& lab)
{
    const size_t SIZE = lab.size();
    MazeDisplay mazeDisplay(2*SIZE+1, std::string(2*SIZE+1, FULL_BLOCK));
    std::accumulate(lab.begin(), lab.end(), &mazeDisplay, &printRowNodes);
    return mazeDisplay;
}

}
