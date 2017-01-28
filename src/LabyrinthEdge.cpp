#include "LabyrinthEdge.hpp"

namespace labyrinth {

LabyrinthEdge::LabyrinthEdge(LabyrinthNode* source, LabyrinthNode* destination):
    source(source),
    destination(destination),
    open(false)
{}

LabyrinthNode* LabyrinthEdge::getSource() const
{
    return source;
}

LabyrinthNode* LabyrinthEdge::getDestination() const
{
    return destination;
}

bool LabyrinthEdge::isOpen() const
{
    return open;
}

void LabyrinthEdge::setOpen(bool _open)
{
    open = _open;
}

}

