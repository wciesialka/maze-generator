#include "Grid.h"

Grid::Grid() : w(0) , h(0), cells(nullptr)
{
}

Grid::Grid(int w, int h) : w(w) , h(h) , cells(new Cell[w*h])
{
    for(size_t j = 0; j < h; j++)
    {
        for(size_t i = 0; i < w; i++)
        {
            this->cells[i + (j*this->w)] = Cell(i,j);
        }
    }
}

Grid::~Grid()
{
    delete[] cells;
    cells = nullptr;
}