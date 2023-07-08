#ifndef VIZUALIZE_PATH_HPP
#define VIZUALIZE_PATH_HPP

#include "grid.hpp"
#include <SFML/Graphics.hpp>

class VizPath
{
public:
    VizPath(int screenWidth, int screenHeight, const std::string& windowTitle, int tileSize, int frameRate);


    VizPath(const VizPath& v) = delete;         // disallow copy
    VizPath(const VizPath&& v) = delete;        // disallow move

    VizPath& operator= (const VizPath& v) = delete;     // disallow assignment

    void update();
    void display();
    void quit();

private:

    Grid m_grid;
    sf::RenderWindow m_window;

};

#endif 