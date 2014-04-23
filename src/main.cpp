#include "libtcod.hpp"
#include "Map.hpp"
#include "Drone.hpp"
#include <vector>

static size_t width = 150;
static size_t height = 80;

int main(int argc, char* argv[]) {
    TCODConsole::initRoot(width, height, "Escape the Thing", false, TCOD_RENDERER_GLSL);

    Map map(width, height);
    std::vector<Drone> drones;
    for (int i = 0; i < 10; i++) {
	drones.emplace_back(&map);
    }
    
    bool running = true;
    while (running && !TCODConsole::isWindowClosed()) {
	map.Render();
	for (auto& drone : drones) {
	    drone.Render();
	}
	TCODConsole::flush();

	TCOD_key_t key;
	do {
	    key = TCODConsole::checkForKeypress();
	    switch (key.vk) {
	    case TCODK_ESCAPE:
		running = false;
		break;
	    }
	} while (key.vk != TCODK_NONE);
    }
    return 0;
}
