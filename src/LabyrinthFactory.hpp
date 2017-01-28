#ifndef LABYRINTH_FACTORY_HPP
#define LABYRINTH_FACTORY_HPP

#include <vector>
#include <string>
#include "LabyrinthNode.hpp"
#include "Pruner.hpp"

namespace labyrinth {

typedef std::vector<std::vector<LabyrinthNode>> Labyrinth;

class LabyrinthFactory {
public:
    static Labyrinth create(int W, int H);
};

}

#endif
