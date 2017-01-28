#include "Printer.hpp"
#include <numeric>

namespace display {

static const char EMPTY_BLOCK = ' ';
static const char FULL_BLOCK = '#';

namespace {

LabyrinthDisplay* printEdge(LabyrinthDisplay* labyrinthDisplay, const labyrinth::LabyrinthEdge& edge)
{
    const labyrinth::LabyrinthNode& source = *edge.getSource();
    const labyrinth::LabyrinthNode& destination = *edge.getDestination();
    int x = (source.x + destination.x)/2;
    int y = (source.y + destination.y)/2;

    if (edge.isOpen())
        (*labyrinthDisplay)[x][y] = EMPTY_BLOCK;
    return labyrinthDisplay;
}

LabyrinthDisplay* printNode(LabyrinthDisplay* labyrinthDisplay, const labyrinth::LabyrinthNode& node)
{
    (*labyrinthDisplay)[node.x][node.y] = EMPTY_BLOCK;
    std::accumulate(std::begin(node.neighborEdges), std::end(node.neighborEdges), labyrinthDisplay, &printEdge);
    return labyrinthDisplay;
}


LabyrinthDisplay* printRowNodes(LabyrinthDisplay* labyrinthDisplay, const std::vector<labyrinth::LabyrinthNode>& rowNodes)
{
    std::accumulate(rowNodes.begin(), rowNodes.end(), labyrinthDisplay, &printNode);
    return labyrinthDisplay;
}

} //anonymous

LabyrinthDisplay print(const labyrinth::Labyrinth& lab)
{
    const size_t SIZE = lab.size();
    LabyrinthDisplay labyrinthDisplay(2*SIZE+1, std::string(2*SIZE+1, FULL_BLOCK));
    std::accumulate(lab.begin(), lab.end(), &labyrinthDisplay, &printRowNodes);
    return labyrinthDisplay;
}

}
