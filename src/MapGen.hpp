#ifndef MAPGEN_H
#define MAPGEN_H
#include "Vector2D.hpp"

class MapGen
{
public:
    enum class CellType
    {
        wall,
        hallway
    };

    static Vector2D<CellType> Generate(size_t width, size_t height);

private:
    struct Region {
        size_t x_,y_,width_,height_;
        Region(size_t x, size_t y, size_t width, size_t height) :
            x_(x), y_(y),
            width_(width), height_(height)
        {
        }
    };

    static void DivideHoriz(Vector2D<CellType>& map, std::vector<Region>& areas, const Region& r);
    static void DivideVert(Vector2D<CellType>& map, std::vector<Region>& areas, const Region& r);

    static const size_t minRoomSize_ = 3;
};

#endif //MAPGEN_H
