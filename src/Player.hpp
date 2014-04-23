#ifndef PLAYER_H
#define PLAYER_H

#include "Map.hpp"

class Player
{
public:
    Player(Map& map, int x, int y);
    void Render();
    int Move(int dx, int dy);
    bool IsHidden();
    
private:
    Map& map_;
    int x;
    int y;
};

#endif
