#pragma once

enum Wall {
    UP = 1 << 0,
    RIGHT = 1 << 1,
    DOWN = 1 << 2,
    LEFT = 1 << 3
};

class Cell
{
    public: 
        Cell();
        Cell(int x, int y);
        void addWall(Wall w);
        void removeWall(Wall w);
        bool hasWall(Wall w);
    private:
        int x;
        int y;
        char walls;
};

inline void Cell::addWall(Wall w)
{
    this->walls |= w;
}

inline void Cell::removeWall(Wall w)
{
    this->walls &= ~w;
}

inline bool Cell::hasWall(Wall w)
{
    return (this->walls & w) == w;
}