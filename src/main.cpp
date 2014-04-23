#include "libtcod.hpp"
#include "Map.hpp"
#include "Drone.hpp"
#include "Player.hpp"
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

    Player player(&map, 1, 1);
    
    bool running = true;
    while (running && !TCODConsole::isWindowClosed()) {
	map.Render();
	for (auto& drone : drones) {
	    drone.Render();
	}
	player.Render();
	TCODConsole::flush();

	TCOD_key_t key;
	do {
	    key = TCODConsole::checkForKeypress();
	    switch (key.vk) {
	    case TCODK_ESCAPE:
		running = false;
		break;
	    case TCODK_LEFT:
		player.move(-1, 0);
		break;
	    case TCODK_RIGHT:
		player.move(1, 0);
		break;
	    case TCODK_DOWN:
		player.move(0, 1);
		break;
	    case TCODK_UP:
		player.move(0, -1);
		break;
	    }
	} while (key.vk != TCODK_NONE);
    }
    return 0;
}
