#include "libtcod.hpp"
#include "Map.hpp"
#include "Drone.hpp"
#include "Player.hpp"
#include <vector>
#include <map>

static size_t width = 150;
static size_t height = 80;

#include <iostream> //TODO remove
int main(int argc, char* argv[]) {
    TCODConsole::initRoot(width, height, "Escape the Things", false, TCOD_RENDERER_GLSL);
    TCODConsole::setKeyboardRepeat(0, 0);
    Map map(width, height);
    std::vector<Drone> drones;
    for (int i = 0; i < 10; i++) {
	drones.emplace_back(&map);
    }

    Player player(map, 1, 1, 20, 5);
    
    enum class keystate {
	up,
	    pressed,
	    down
	    };
    std::map<TCOD_keycode_t, keystate> keys;
    for (auto k : {TCODK_UP, TCODK_DOWN, TCODK_LEFT, TCODK_RIGHT, TCODK_SPACE}) {
	keys[k] = keystate::up;
    }

    static uint32 lastStepTime = TCODSystem::getElapsedMilli();
    static uint32 stepPeriod = 100;
    
    bool running = true;
    while (running && !TCODConsole::isWindowClosed()) {
	TCOD_key_t key;
	do {
	    key = TCODConsole::checkForKeypress(TCOD_KEY_PRESSED | TCOD_KEY_RELEASED);
	    if (key.vk == TCODK_ESCAPE) {
		running = false;
	    } else {
		auto iter = keys.find(key.vk);
		if (iter != keys.end()) {
		    if (key.pressed) {
			iter->second = keystate::down;
		    } else {
			if (iter->second == keystate::down || iter->second == keystate::pressed) {
			    iter->second = keystate::pressed;
			} else {
			    iter->second = keystate::up;
			}
		    }
		}
	    }
	} while (key.vk != TCODK_NONE);

	if (TCODSystem::getElapsedMilli() - lastStepTime > stepPeriod) {
	    lastStepTime = TCODSystem::getElapsedMilli();
	    
	    if (keys[TCODK_UP] != keystate::up) {
		player.Move(0, -1);
		if (keys[TCODK_UP] == keystate::pressed) {
		    keys[TCODK_UP] = keystate::up;
		}
	    }
	    if (keys[TCODK_DOWN] != keystate::up) {
		player.Move(0, 1);
		if (keys[TCODK_DOWN] == keystate::pressed) {
		    keys[TCODK_DOWN] = keystate::up;
		}
	    }
	    if (keys[TCODK_LEFT] != keystate::up) {
		player.Move(-1, 0);
		if (keys[TCODK_LEFT] == keystate::pressed) {
		    keys[TCODK_LEFT] = keystate::up;
		}
	    }
	    if (keys[TCODK_RIGHT] != keystate::up) {
		player.Move(1, 0);
		if (keys[TCODK_RIGHT] == keystate::pressed) {
		    keys[TCODK_RIGHT] = keystate::up;
		}
	    }
	    if (keys[TCODK_SPACE] != keystate::up) {
		player.Hide();
		if (keys[TCODK_SPACE] == keystate::pressed) {
		    keys[TCODK_SPACE] = keystate::up;
		}
	    }

	    for (auto& drone : drones) {
		if (drone.X() == player.X() && drone.Y() == player.Y()) {
		    player.Collide();
		}
		drone.DoStep();
		if (drone.X() == player.X() && drone.Y() == player.Y()) {
		    player.Collide();
		}
	    }
	}
	
	map.Render();
	for (auto& drone : drones) {
	    drone.Render();
	}
	player.Render();

	// Scoring details
	TCODConsole::root->print(width - 40, 0, "  Lives: %d  ", player.Lives());
	TCODConsole::root->print(width - 30, 0, "  Energy: %d  ", player.Energy());
	if (player.IsHidden()) {
	    TCODConsole::root->print(width - 20, 0, "  Hide Time: %d  ", player.HiddenTime());
	}

	TCODConsole::flush();
    }
    return 0;
}

