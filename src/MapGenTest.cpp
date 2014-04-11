#include "MapGen.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    auto map = MapGen::Generate(150, 30);
    for (size_t y = 0; y < map.Height(); y++) {
	for (size_t x = 0; x < map.Width(); x++) {
	    char c = '?';
	    switch (map(x, y)) {
	    case MapGen::CellType::wall:
		c = '#';
		break;
	    case MapGen::CellType::hallway:
		c = '.';
		break;
	    }
	    std::cout << c;
	}
	std::cout << std::endl;
    }
    return 0;
}
