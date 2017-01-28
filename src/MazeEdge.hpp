#ifndef MAZE_EDGE_HPP
#define MAZE_EDGE_HPP

#include "MazeNode.fwd.hpp"

namespace maze {

class MazeEdge {
public :
    MazeEdge(MazeNode* source, MazeNode* destination);
    MazeNode* getSource() const;
    MazeNode* getDestination() const;
    bool isOpen() const;
    void setOpen(bool open);

private :
    MazeNode* source;
    MazeNode* destination;
    bool open;
};

}

#endif
