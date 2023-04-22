#include <SFML/Graphics.hpp>
#include <iostream>

#include "button.hpp"


// g++ -Wall -Wextra main.cpp button.cpp -lsfml-graphics -lsfml-window -lsfml-system


int main()
{
    sf::RenderWindow window(sf::VideoMode(600,600), "SFML Button");
    window.setFramerateLimit(2);

    sf::Font font;
    if(!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cout << "Font not found\n";

    }

    Button button1("Click", {200,100}, {300,300}, font);


    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
            {
                button1.update(event, sf::Mouse::getPosition(window));
            }
        }

        window.clear();
        window.draw(button1);
        window.display();
    }
    return 0;
}