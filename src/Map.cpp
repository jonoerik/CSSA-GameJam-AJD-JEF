#include "Map.hpp"

Map::Map(size_t width, size_t height) :
    width_(width),
    height_(height),
    map_(MapGen::Generate(width_, height_))
{
}
