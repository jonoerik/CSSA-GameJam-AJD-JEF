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
    void Hide();
    bool IsHidden();
    void Collide();
    int X() { return x; };
    int Y() { return y; };
    int Lives() { return lives_; }
    int Energy() { return energy_; }
    int HiddenTime() { return hidden_time_finish_ - TCODSystem::getElapsedMilli(); }
private:
    Map& map_;
    int x;
    int y;
    int fov_radius;
    int lives_;
    int hidden_time_finish_;
    int energy_;
};

#endif
