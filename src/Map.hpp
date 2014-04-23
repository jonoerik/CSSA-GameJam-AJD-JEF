#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include "MapGen.hpp"
#include "Vector2D.hpp"

class Map
{
public:
    Map(size_t width, size_t height);

private:
    size_t width_;
    size_t height_;
    Vector2D<MapGen::CellType> map_;
};

#endif //MAP_H
