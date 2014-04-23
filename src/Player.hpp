#ifndef PLAYER_H
#define PLAYER_H

#include "Map.hpp"

class Player
{
public:
    Player(Map * map, int x, int y);
    void Render();
    int move(int dx, int dy);
    
private:
    Map* map_;
    int x;
    int y;
};

#endif
