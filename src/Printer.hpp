#ifndef PRINTER_HPP
#define PRINTER_HPP

#include "MazeGenerator.hpp"

namespace display {

   typedef std::vector<std::string> MazeDisplay;
   MazeDisplay print(const maze::Maze& lab);

}

#endif
