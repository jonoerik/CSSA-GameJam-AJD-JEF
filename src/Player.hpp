#ifndef PLAYER_H
#define PLAYER_H

#include "Map.hpp"
#include "libtcod.hpp"

class Player
{
public:
    Player(Map& map, int x, int y, int fov_radius);
    void Render();
    int Move(int dx, int dy);
    bool IsHidden();
    
private:
    Map& map_;
    int x;
    int y;
    int fov_radius;
};

#endif
