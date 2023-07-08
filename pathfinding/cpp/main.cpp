// #include "vizPath.hpp"

#include "bfs.hpp"
#include "grid.hpp"

// g++ -Wall -o test main.cpp grid.cpp tile.cpp pathfind.cpp bfs.cpp -lsfml-graphics -lsfml-window -lsfml-system

#define WIDTH 640
#define HEIGHT 480
#define SQUARE_SIZE 40

int main()
{
    
    int count = 1;
    int frameRate = 5;


    //VizPath vizpath(WIDTH, HEIGHT, "Path Visualization", SQUARE_SIZE, frameRate);
    
    int rows = HEIGHT / SQUARE_SIZE;
    int cols = WIDTH / SQUARE_SIZE;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Breadth First Search");

    window.setFramerateLimit(frameRate);

    Grid grid(rows, cols, SQUARE_SIZE);
    GridPosition startLocation(rows/2, cols/2);
    GridPosition goalLocation(1,1);

    BFS bfs(startLocation, goalLocation, grid);

    bool searchComplete = false;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }   

        if(!searchComplete)
        {
            window.clear(sf::Color::Black);
            searchComplete = bfs.search(grid);
        }
        else
        {
            if(bfs.goalReached() && count == 1)
            {
                std::cout << "searchComplete is true\n";
                bfs.constructPath(grid);
                ++count;
            }
        }
        
        grid.draw(window);

        window.display();

    }
    return 0;
}