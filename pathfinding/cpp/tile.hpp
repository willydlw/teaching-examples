#ifndef TILE_HPP
#define TILE_HPP


#include <iostream>

#include <SFML/Graphics.hpp>


#include "location.hpp"

enum TILE_STATE
{
    OPEN, 
    OBSTACLE, 
    START, 
    GOAL, 
    CURRENT,
    VISITED,
    FRONTIER,
    PATH
};


struct Tile
{    
        Location        xypos;        // x,y location
        bool            visited;
        TILE_STATE      tileState;
        Tile*           parent;

        Tile();
        Tile(const Location& pos);
        Tile(const Location& pos, TILE_STATE tstate);

        void draw(sf::RenderWindow& window, int squareSize);

        friend std::ostream&  operator<< (std::ostream& out, const Tile& tile);

};


#endif