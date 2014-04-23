#include "MapGen.hpp"

#include <utility>
#include <vector>
#include <random>
#include <chrono>

Vector2D<MapGen::CellType> MapGen::Generate(size_t width, size_t height)
{
    Vector2D<CellType> map(width, height);
    for (auto& cell : map.Data()) {
        cell = CellType::wall;
    }

    std::vector<Region> areas;
    areas.push_back(Region(2, 2, width - 4, height - 4));
    for (size_t x = 1; x < width - 1; x++) {
        map(x, 1) = CellType::hallway;
        map(x, height - 2) = CellType::hallway;
    }
    for (size_t y = 1; y < height - 1; y++) {
        map(1, y) = CellType::hallway;
        map(width - 2, y) = CellType::hallway;
    }

    std::default_random_engine rand;
    rand.seed(std::chrono::system_clock::now().time_since_epoch().count());
    while (areas.size() > 0) {
        Region r = areas.back();
        areas.pop_back();

        if (r.width_ > minRoomSize_ * 2 + 1 && static_cast<double>(r.width_) / static_cast<double>(r.height_) > 1.8) {
            DivideVert(map, areas, r);
        } else if (r.height_ > minRoomSize_ * 2 + 1 && static_cast<double>(r.height_) / static_cast<double>(r.width_) > 1.8) {
            DivideHoriz(map, areas, r);
        } else if (r.width_ > minRoomSize_ * 2 + 1 && r.height_ > minRoomSize_ * 2 + 1) {
            if (rand() % 2 == 0) {
                DivideHoriz(map, areas, r);
            } else {
                DivideVert(map, areas, r);
            }
        } else if (r.width_ > minRoomSize_ * 2 + 1) {
            DivideVert(map, areas, r);
        } else if (r.height_ > minRoomSize_ * 2 + 1) {
            DivideHoriz(map, areas, r);
        }
    }
    return std::move(map);
}

//Place horizontal dividing wall
void MapGen::DivideHoriz(Vector2D<CellType>& map, std::vector<Region>& areas, const Region& r)
{
    size_t splitPoint = r.y_ + minRoomSize_ + rand() % (r.height_ - 2 * minRoomSize_);
    for (size_t x = r.x_; x < r.x_ + r.width_ + 1; x++) {
        map(x, splitPoint) = CellType::hallway;
    }
    areas.push_back(Region(r.x_, r.y_, r.width_, splitPoint - r.y_ - 1));
    areas.push_back(Region(r.x_, splitPoint + 1, r.width_, r.y_ + r.height_ - 1 - splitPoint));
}

//Place vertical dividing wall
void MapGen::DivideVert(Vector2D<CellType>& map, std::vector<Region>& areas, const Region& r)
{
    size_t splitPoint = r.x_ + minRoomSize_ + rand() % (r.width_ - 2 * minRoomSize_);
    for (size_t y = r.y_; y < r.y_ + r.height_ + 1; y++) {
        map(splitPoint, y) = CellType::hallway;
    }
    areas.push_back(Region(r.x_, r.y_, splitPoint - r.x_ - 1, r.height_));
    areas.push_back(Region(splitPoint + 1, r.y_, r.x_ + r.width_ - 1 - splitPoint, r.height_));
}
