#ifndef PLAYER_H
#define PLAYER_H

#include "Map.hpp"

class Player
{
public:
    Player(Map& map, int x, int y, int fov_radius);
    void Render();
    void RenderVisibility();
    int Move(int dx, int dy);
    bool IsHidden();
    bool IsVisible(int px, int py);
    
private:
    Map& map_;
    int x;
    int y;
    int fov_radius;
};

#endif
