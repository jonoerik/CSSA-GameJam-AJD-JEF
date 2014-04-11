#include "MapGen.hpp"

#include <utility>

Vector2D<MapGen::CellType> MapGen::Generate(size_t width, size_t height) {
    Vector2D<CellType> map(width, height);
    for (auto& cell : map.Data()) {
        cell = CellType::wall;
    }

    return std::move(map);
}
