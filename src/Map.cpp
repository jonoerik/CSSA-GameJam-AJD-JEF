#include "libtcod.hpp"
#include "Map.hpp"

Map::Map(size_t width, size_t height) :
    width_(width),
    height_(height),
    map_(MapGen::Generate(width_, height_))
{
}

void Map::Render()
{
    for (size_t y = 0; y < height_; y++) {
	for (size_t x = 0; x < width_; x++) {
	    TCODConsole::root->setCharBackground(x,y,TCODColor::black);
	    TCODConsole::root->setCharForeground(x,y,TCODColor::white);
	    char c = ' ';
	    switch (map_(x,y)) {
		case MapGen::CellType::wall:
		    c = '#';
		    break;
		case MapGen::CellType::hallway:
		    c = '.';
		    break;
	    }
	    TCODConsole::root->setChar(x,y,c);
	}
    }
}

bool Map::Walkable(size_t x, size_t y)
{
    return map_(x, y) == MapGen::CellType::hallway;
}
