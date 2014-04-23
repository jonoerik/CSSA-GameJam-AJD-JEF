#include "libtcod.hpp"
#include "Map.hpp"
#include <iostream> //TODO remove

static size_t width = 150;
static size_t height = 80;

int main(int argc, char* argv[]) {
    TCODConsole::initRoot(width, height, "Escape the Thing", false, TCOD_RENDERER_GLSL);

    Map map(width, height);
    
    bool running = true;
    while (running && !TCODConsole::isWindowClosed()) {
	map.Render();
	TCODConsole::flush();

	TCOD_key_t key;
	do {
	    key = TCODConsole::checkForKeypress();
	    switch (key.vk) {
	    case TCODK_ESCAPE:
		running = false;
		std::cout << "esc" << std::endl;
		break;
	    }
	} while (key.vk != TCODK_NONE);
    }
    return 0;
}
