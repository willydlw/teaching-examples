#include "maze.h"


std::ostream& operator<<(std::ostream& os, const Maze& maze)
{
    os << "rows: " << maze.rows << ", cols: " << maze.cols << "\n";
    return os;
}