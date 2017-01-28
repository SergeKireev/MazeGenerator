#ifndef PRINTER_HPP
#define PRINTER_HPP

#include "LabyrinthFactory.hpp"

namespace display {

   typedef std::vector<std::string> LabyrinthDisplay;
   LabyrinthDisplay print(const labyrinth::Labyrinth& lab);

}

#endif
