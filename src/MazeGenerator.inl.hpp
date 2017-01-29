#include <algorithm>

namespace maze {

namespace {

template<int W, int H>
void initEdgesForNode(Maze& lab, int i, int j)
{
    MazeNode& labNode = lab[i][j];
    if ((i-1) >= 0)
        labNode.neighborEdges.push_back(MazeEdge(&labNode, &lab[i-1][j]));
    if ((i+1) < W)
        labNode.neighborEdges.push_back(MazeEdge(&labNode, &lab[i+1][j]));
    if ((j-1) >= 0)
        labNode.neighborEdges.push_back(MazeEdge(&labNode, &lab[i][j-1]));
    if ((j+1) < H)
        labNode.neighborEdges.push_back(MazeEdge(&labNode, &lab[i][j+1]));
}


template <int W, int H>
void initEdges(Maze& lab)
{
    for(int i = 0; i<W; ++i)
        for(int j = 0; j<H; ++j)
            initEdgesForNode<W,H>(lab,i,j);
}

template <int W, int H>
void initNodes(Maze& lab)
{
    for(int i = 0; i<W; ++i)
        for(int j = 0; j<H; ++j)
            lab[i][j] = MazeNode(2*i+1, 2*j+1);
}

void walkFromNode(MazeNode& labNode, std::vector<std::vector<bool>>& visited);

struct WalkOnEdge {

    WalkOnEdge(std::vector<std::vector<bool>>& visited):
        visited(visited)
    {}

    void operator()(MazeEdge& edge) {
        MazeNode& destination = *edge.getDestination();
        if (!visited[destination.x][destination.y])
        {
            edge.setOpen(true);
            walkFromNode(destination, visited);
        }
    }

    std::vector<std::vector<bool>>& visited;
};

void walkFromNode(MazeNode& labNode, std::vector<std::vector<bool>>& visited)
{
    visited[labNode.x][labNode.y] = true;
    std::random_shuffle(labNode.neighborEdges.begin(), labNode.neighborEdges.end());
    std::for_each(std::begin(labNode.neighborEdges), std::end(labNode.neighborEdges), WalkOnEdge(visited));
}

template <int W, int H>
void openEdges(Maze& lab)
{
    std::vector<std::vector<bool>> visited(2*W+1, std::vector<bool>(2*H+1, false));
    walkFromNode(lab[0][0], visited);
}

} //anonymous

template <int W, int H>
Maze MazeGenerator::init()
{
    Maze lab(W, std::vector<MazeNode>(H));
    initNodes<W,H>(lab);
    initEdges<W,H>(lab);
    return lab;
}

template <int W, int H>
void MazeGenerator::build(Maze& maze)
{
    openEdges<W,H>(maze);
}

}
