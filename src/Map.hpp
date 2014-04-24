#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include "MapGen.hpp"
#include "Vector2D.hpp"
#include "libtcod.hpp"

class Map
{
public:
    Map(size_t width, size_t height);
    void Render();
    size_t Width() const { return width_; }
    size_t Height() const { return height_; }
    bool Walkable(size_t x, size_t y);
    const TCODMap& TcodMap() { return tcodMap_; }

private:
    size_t width_;
    size_t height_;
    Vector2D<MapGen::CellType> map_;
    TCODMap tcodMap_;
};

#endif //MAP_H
