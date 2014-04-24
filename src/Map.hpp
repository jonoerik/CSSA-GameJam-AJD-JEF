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
    TCODMap& TcodMap() { return tcodMap_; }
    void ChangePlayerPos(size_t player_x, size_t player_y, int fov_radius);

private:
    size_t width_;
    size_t height_;
    Vector2D<MapGen::CellType> map_;
    TCODMap tcodMap_;
    
    enum cell_states_t {
	CELL_UNVISITED,
	CELL_VISITED,
	CELL_VISIBLE
    };
    Vector2D<cell_states_t> cell_states_;
    
    int player_x_;
    int player_y_;
    int fov_radius_;
    
};

#endif //MAP_H
