#ifndef LABYRINTH_EDGE_HPP
#define LABYRINTH_EDGE_HPP

#include "LabyrinthNode.fwd.hpp"

namespace labyrinth {

class LabyrinthEdge {
public :
    LabyrinthEdge(LabyrinthNode* source, LabyrinthNode* destination);
    LabyrinthNode* getSource() const;
    LabyrinthNode* getDestination() const;
    bool isOpen() const;
    void setOpen(bool open);

private :
    LabyrinthNode* source;
    LabyrinthNode* destination;
    bool open;
};

}

#endif
