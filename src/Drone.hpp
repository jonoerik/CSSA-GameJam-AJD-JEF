#ifndef DRONE_H
#define DRONE_H

#include "Map.hpp"

class Drone
{
public:
    Drone(Map* map);
    void Render();
    
private:
    Map* map_;
    size_t x_;
    size_t y_;
};

#endif //DRONE_H
