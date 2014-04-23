#ifndef PLAYER_H
#define PLAYER_H

#include "Map.hpp"

class Player
{
public:
    Player(Map * map);
    void draw();
    int move(int dx, int dy);
    
private:
    Map* map_;
};

#endif
