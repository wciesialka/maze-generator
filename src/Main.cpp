#include <iostream>
#include "Grid.h"
#include "Cell.h"
#include <stack>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#define WIDTH 600
#define HEIGHT 600
#define CELL_SIZE 5
#define G_WIDTH (WIDTH/CELL_SIZE)
#define G_HEIGHT (HEIGHT/CELL_SIZE)
#define TITLE "Maze Generator"

Cell * current = nullptr;
std::stack<Cell*> s;
bool done = false;

void gridUpdate(Grid* g)
{
    int choices = 0;
    std::vector<Cell*> valid;
    int x = current->getX();
    int y = current->getY();
    if(x > 0)
    {
        Cell * tmp = g->getCell(x-1,y);
        if(!tmp->visited())
        {
            valid.push_back(tmp);
            choices++;
        }
    }
    if(x < G_WIDTH - 1)
    {
        Cell * tmp = g->getCell(x+1,y);
        if(!tmp->visited())
        {
            valid.push_back(tmp);
            choices++;
        }
    }
    if(y > 0)
    {
        Cell * tmp = g->getCell(x,y-1);
        if(!tmp->visited())
        {
            valid.push_back(tmp);
            choices++;
        }
    }
    if(y < G_HEIGHT - 1)
    {
        Cell * tmp = g->getCell(x,y+1);
        if(!tmp->visited())
        {
            valid.push_back(tmp);
            choices++;
        }
    }
    if(choices == 0)
    {
        if(s.size() == 0)
        {
            std::cout << "Done!" << std::endl;
            done = true;
        }
        else
        {
            current = s.top();
            s.pop();
        }
    }
    else
    {
        int choice = rand() % choices;
        Cell* chosen = valid.at(choice);
        int nX = chosen->getX();
        int nY = chosen->getY();
        if(nX > x)
        {
            current->removeWall(RIGHT);
            chosen->removeWall(LEFT);
        } else if(nX < x)
        {
            current->removeWall(LEFT);
            chosen->removeWall(RIGHT);
        } else if(nY > y)
        {
            current->removeWall(DOWN);
            chosen->removeWall(UP);
        } else if(nY < y)
        {
            current->removeWall(UP);
            chosen->removeWall(DOWN);
        }
        current = chosen;
        current->visit();
        s.push(current);
        chosen = nullptr;
    }
}

void drawLine(sf::RenderWindow * window, int x1, int y1, int x2, int y2)
{
    sf::VertexArray line(sf::LineStrip, 2);
    line[0].position = sf::Vector2f(x1, y1);
    line[0].color  = sf::Color::Black;
    line[1].position = sf::Vector2f(x2, y2);
    line[1].color = sf::Color::Black;
    window->draw(line);
}

void update(Grid* g, sf::RenderWindow * window)
{
    sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(WIDTH,HEIGHT));
    bg.setFillColor(sf::Color::White);
    window->draw(bg);

    gridUpdate(g);

    for(int y = 0; y < G_HEIGHT; y++)
    {
        for(int x = 0; x < G_WIDTH; x++)
        {
            Cell * c = g->getCell(x,y);
            if(c->hasWall(UP))
            {
                drawLine(window,CELL_SIZE*x,CELL_SIZE*y,CELL_SIZE*x + CELL_SIZE, CELL_SIZE*y);
            }
            if(c->hasWall(RIGHT))
            {
                drawLine(window,CELL_SIZE*x + CELL_SIZE,CELL_SIZE*y,CELL_SIZE*x + CELL_SIZE, CELL_SIZE*y + CELL_SIZE);
            }
            if(c->hasWall(DOWN))
            {
                drawLine(window,CELL_SIZE*x,CELL_SIZE*y + CELL_SIZE, CELL_SIZE*x + CELL_SIZE, CELL_SIZE*y + CELL_SIZE);
            }
            if(c->hasWall(LEFT))
            {
                drawLine(window,CELL_SIZE*x,CELL_SIZE*y,CELL_SIZE*x,CELL_SIZE*y+CELL_SIZE);
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    std::cout << "Starting up!" << std::endl;
    Grid * g = new Grid(G_WIDTH,G_HEIGHT);
    current = g->getCell(0,0);
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

        if(!done)
        {
            update(g,window);
            window->display();
        }
    }

    std::cout << "Ending!" << std::endl;
    delete g;
    delete window;
    return 0;
}