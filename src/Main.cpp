#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>

#define WIDTH 600
#define HEIGHT 600
#define CELL_SIZE 5
#define G_WIDTH (WIDTH/CELL_SIZE)
#define G_HEIGHT (HEIGHT/CELL_SIZE)
#define TITLE "Maze Generator"

void update(Grid* g, sf::RenderWindow * window)
{
}

int main()
{
    std::cout << "Starting up!" << std::endl;
    Grid * g = new Grid(G_WIDTH,G_HEIGHT);
    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT),TITLE);

    while(window->isOpen())
    {
        sf::Event ev;
        while(window->pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        update(g,window);
        window->display();
    }

    std::cout << "Ending!" << std::endl;
    delete g;
    delete window;
    return 0;
}