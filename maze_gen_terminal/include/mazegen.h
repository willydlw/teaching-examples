#pragma once 
#include "maze.h"
#include "randomNumberGenerator.h"

#include <iostream>
#include <random>

class MazeGenerator {

public:
    MazeGenerator();

    MazeGenerator(int width, int height);

    void setDimensions(int width, int height);

    void generate();
    void display() const;
    void saveToFile(const std::string& fileName);
    void loadFromFile(const std::string& fileName);


private:
    void carveMaze(int x, int y);

private:

    RandomNumberGenerator m_rng;
    Maze m_maze;
};