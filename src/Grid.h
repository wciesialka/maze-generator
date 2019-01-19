#pragma once
#include "Cell.h"

typedef unsigned int size_t;

class Grid
{
    public:
        Grid();
        Grid(int w, int h);
        ~Grid();
        int index(int x, int y);
        Cell & getCell(int x, int y);
    private:
        int w;
        int h;
        Cell * cells;
};

inline int Grid::index(int i, int j)
{
    return i + (j*this->w);
}

inline Cell& Grid::getCell(int x, int y)
{
    return this->cells[x + (y*this->w)];
}