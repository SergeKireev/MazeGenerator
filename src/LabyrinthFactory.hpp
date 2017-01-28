#ifndef LABYRINTH_FACTORY_HPP
#define LABYRINTH_FACTORY_HPP

#include <vector>
#include <string>
#include "LabyrinthNode.hpp"

namespace labyrinth {

typedef std::vector<std::vector<LabyrinthNode>> Labyrinth;

class LabyrinthFactory {
public:
    static Labyrinth create(const int W, const int H);
};

}

#endif
