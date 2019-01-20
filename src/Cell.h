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
        int getX() { return this->x; }
        int getY() { return this->y; }
        bool hasWall(Wall w);
        bool visited();
        void visit();
    private:
        int x;
        int y;
        char walls;
        bool wasVisited;
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

inline void Cell::visit()
{
    this->wasVisited = true;
}

inline bool Cell::visited()
{
    return this->wasVisited;
}