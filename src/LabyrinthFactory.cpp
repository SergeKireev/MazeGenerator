#include "LabyrinthFactory.hpp"
#include <algorithm>

namespace labyrinth {

namespace {

void initEdgesForNode(Labyrinth& lab, int W, int H, int i, int j)
{
    LabyrinthNode& labNode = lab[i][j];
    if ((i-1) >= 0)
        labNode.neighborEdges.push_back(LabyrinthEdge(&labNode, &lab[i-1][j]));
    if ((i+1) < W)
        labNode.neighborEdges.push_back(LabyrinthEdge(&labNode, &lab[i+1][j]));
    if ((j-1) >= 0)
        labNode.neighborEdges.push_back(LabyrinthEdge(&labNode, &lab[i][j-1]));
    if ((j+1) < H)
        labNode.neighborEdges.push_back(LabyrinthEdge(&labNode, &lab[i][j+1]));
}

void initEdges(Labyrinth& lab, int W, int H)
{
    for(int i = 0; i<W; ++i)
        for(int j = 0; j<H; ++j)
            initEdgesForNode(lab, W, H, i, j);
}

void initNodes(Labyrinth& lab, int W, int H)
{
    for(int i = 0; i<W; ++i)
        for(int j = 0; j<H; ++j)
            lab[i][j] = LabyrinthNode(2*i+1, 2*j+1);
}

void walkFromNode(LabyrinthNode& labNode, std::vector<std::vector<bool>>& visited)
{
    visited[labNode.x][labNode.y] = true;
    std::random_shuffle(labNode.neighborEdges.begin(), labNode.neighborEdges.end());
    std::for_each(std::begin(labNode.neighborEdges), std::end(labNode.neighborEdges),
                    [&visited](LabyrinthEdge& edge) {
                        LabyrinthNode& destination = *edge.getDestination();
                        if (!visited[destination.x][destination.y])
                        {
                            edge.setOpen(true);
                            walkFromNode(destination, visited);
                        }
                    });
}


void openEdges(Labyrinth& lab, const int W, const int H)
{
    std::vector<std::vector<bool>> visited(2*W+1, std::vector<bool>(2*H+1, false));
    walkFromNode(lab[0][0], visited);
}

} //anonymous

Labyrinth LabyrinthFactory::create(const int W, const int H)
{
    Labyrinth lab(W, std::vector<LabyrinthNode>(H));
    initNodes(lab, W, H);
    initEdges(lab, W, H);
    openEdges(lab, W, H);
    return lab;
}

}
