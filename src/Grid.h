#pragma once
#include "Cell.h"

class Grid
{
    public:
        Grid();
        Grid(int w, int h);
        int index(int x, int y);
        int getCell(int x, int y);
    private:
        Cell cells[];
};