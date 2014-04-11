#ifndef MAPGEN_H
#define MAPGEN_H

#include "Vector2D.hpp"

class MapGen {
public:
    enum class CellType {
	wall,
	hallway
    };

    static Vector2D<CellType> Generate(size_t width, size_t height);
    
};

#endif //MAPGEN_H
