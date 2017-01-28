#include "MazeEdge.hpp"

namespace maze {

MazeEdge::MazeEdge(MazeNode* source, MazeNode* destination):
    source(source),
    destination(destination),
    open(false)
{}

MazeNode* MazeEdge::getSource() const
{
    return source;
}

MazeNode* MazeEdge::getDestination() const
{
    return destination;
}

bool MazeEdge::isOpen() const
{
    return open;
}

void MazeEdge::setOpen(bool _open)
{
    open = _open;
}

}

