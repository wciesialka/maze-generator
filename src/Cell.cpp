#include "Cell.h"

Cell::Cell() : x (0) , y (0) , walls (UP | RIGHT | DOWN | LEFT) , wasVisited (false)
{}

Cell::Cell(int x, int y) : x (x) , y (y) , walls (UP | RIGHT | DOWN | LEFT) , wasVisited(false)
{}