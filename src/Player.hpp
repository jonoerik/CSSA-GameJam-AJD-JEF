#ifndef PLAYER_H
#define PLAYER_H

#include "Map.hpp"
#include "libtcod.hpp"

class Player
{
public:
    Player(Map& map, int x, int y, int fov_radius, int lives);
    void Render();
    int Move(int dx, int dy);
    bool IsHidden();
    void Collide();
    int X() { return x; };
    int Y() { return y; };
    int lives() { return lives_; }
private:
    Map& map_;
    int x;
    int y;
    int fov_radius;
    int lives_;
};

#endif
