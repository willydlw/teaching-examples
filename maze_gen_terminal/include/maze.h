#pragma once 

#include <iostream>
#include <vector>

struct Maze
{
    int rows = 0;
    int cols = 0;
    std::vector<std::vector<char>> grid;

    Maze() = default;
    Maze(int r, int c) : rows(r), cols(c) {}

    friend std::ostream& operator<<(std::ostream& os, const Maze& maze);
};

