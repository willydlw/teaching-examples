#include "vizPath.hpp"

VizPath::VizPath(int screenWidth, int screenHeight, const std::string& windowTitle, int tileSize, int frameRate) :
    m_grid(screenHeight/tileSize, screenWidth/tileSize, tileSize),
    m_window(sf::VideoMode(screenWidth, screenHeight), windowTitle) 
{
    m_window.setFramerateLimit(frameRate);
}


  

void VizPath::update()
{

}

void VizPath::display()
{

}

void VizPath::quit()
{

}
