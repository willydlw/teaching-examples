#include "tile.hpp"

Tile::Tile() : 
    xypos(0,0), 
    visited(false), 
    tileState(OPEN), 
    parent(nullptr)
{

}

Tile::Tile(const Location& pos) : 
    xypos(pos.x, pos.y), 
    visited(false), 
    tileState(OPEN), 
    parent(nullptr)
{

}

Tile::Tile(const Location& pos, TILE_STATE tstate) : 
    xypos(pos.x, pos.y), 
    visited(false), 
    tileState(tstate), 
    parent(nullptr)
{

}



void Tile::draw(sf::RenderWindow& window, int squareSize)
{
    sf::RectangleShape rect(sf::Vector2f(squareSize, squareSize));
    rect.setPosition(sf::Vector2f(xypos.x, xypos.y));
    switch(tileState)
    {
        case OPEN:
            rect.setFillColor(sf::Color::White);
            break;
        case::OBSTACLE:
            rect.setFillColor(sf::Color::Yellow);
            break;
        case::START:
            rect.setFillColor(sf::Color::Green);
            break;
        case GOAL:
            rect.setFillColor(sf::Color::Red);
            break; 
        case CURRENT:
            rect.setFillColor(sf::Color::Yellow);
            break;
        case VISITED:
            rect.setFillColor(sf::Color::Blue);
            break;
        case FRONTIER:
            rect.setFillColor(sf::Color::Cyan);
            break;
        case PATH:
            rect.setFillColor(sf::Color::Magenta);
            break;
    }

    rect.setOutlineThickness(2.0f);
    rect.setOutlineColor(sf::Color::Black);
    window.draw(rect);
}


std::ostream&  operator<< (std::ostream& out, const Tile& tile)
{
    out << "Position, x: " << tile.xypos.x << ", y: " << tile.xypos.y << "\n";
    out << "visited    : " << (tile.visited ? "true" : "false") << "\n";
    out << "state      : " << tile.tileState << "\n";
    if(tile.parent != nullptr)
    {
        out << "parent,   x: " << tile.parent->xypos.x << ", y: " << tile.parent->xypos.y << "\n\n";
    } 
    else 
    {
        out << "parent  is nullptr\n\n";
    }
    
    return out;
}