#include "Map.hpp"

Map::Map(size_t width, size_t height) :
    width_(width),
    height_(height),
    map_(MapGen::Generate(width, height)),
    tcodMap_(width, height),
    cell_states_(width, height)
{
    for (size_t y = 0; y < height_; y++) {
	for (size_t x = 0; x < width_; x++) {
	    tcodMap_.setProperties(x, y, map_(x,y) == MapGen::CellType::hallway, map_(x,y) == MapGen::CellType::hallway);
	    cell_states_(x, y) = CELL_UNVISITED;
	}
    }
}

void Map::ChangePlayerPos(size_t player_x, size_t player_y, int fov_radius)
{
    player_x_ = player_x;
    player_y_ = player_y;
    fov_radius_ = fov_radius;
    tcodMap_.computeFov(player_x_, player_y_, fov_radius_);
}

void Map::Render()
{
    for (size_t y = 0; y < height_; y++) {
	for (size_t x = 0; x < width_; x++) {
	    TCODConsole::root->setCharBackground(x,y,TCODColor::black);
	    TCODConsole::root->setCharForeground(x,y,TCODColor::white);
	    char c = ' ';
	    // Field of view
	    if (tcodMap_.isInFov(x, y)) {
		cell_states_(x, y) = CELL_VISIBLE;
	    } else if (cell_states_(x, y) == CELL_VISIBLE) {
		cell_states_(x, y) = CELL_VISITED;
	    }
	    
	    if (cell_states_(x, y) == CELL_UNVISITED) {
		c = ' ';
	    } else {
		if (cell_states_(x, y) == CELL_VISITED) {
		    TCODConsole::root->setCharForeground(x,y,TCODColor::grey);
		}
		switch (map_(x,y)) {
		case MapGen::CellType::wall:
		    c = '#';
		    break;
		case MapGen::CellType::hallway:
		    c = '.';
		    break;
		}
	    }
	    TCODConsole::root->setChar(x,y,c);
	}
    }
}

bool Map::Walkable(size_t x, size_t y)
{
    return map_(x, y) == MapGen::CellType::hallway;
}

cell_states_t Map::CellState(size_t px, size_t py)
{
    return cell_states_(px, py);
}
