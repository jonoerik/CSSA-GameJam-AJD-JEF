#include "libtcod.hpp"
#include "Map.hpp"

static size_t width = 150;
static size_t height = 80;

int main(int argc, char* argv[]) {
    TCODConsole::initRoot(width, height, "Escape the Thing", false, TCOD_RENDERER_GLSL);

    Map map(width, height);
    
    bool running = true;
    while (running && !TCODConsole::isWindowClosed()) {
	map.Render();
	TCODConsole::flush();
    }
    return 0;
}
