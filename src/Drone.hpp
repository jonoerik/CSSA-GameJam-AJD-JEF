#ifndef DRONE_H
#define DRONE_H

#include "Map.hpp"
#include <memory>

class Drone
{
public:
    Drone(Map* map);
    void Render();
    void DoStep(size_t playerX, size_t playerY);
    int X() { return x_; }
    int Y() { return y_; }
    
private:
    void SetDest();
    
    Map* map_;
    size_t x_;
    size_t y_;
    size_t destX_;
    size_t destY_;
    std::unique_ptr<TCODPath> path_;
    std::unique_ptr<TCODMap> fovMap_;
};

#endif //DRONE_H
