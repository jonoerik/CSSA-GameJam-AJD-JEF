#include "libtcod.hpp"
#include "Drone.hpp"

Drone::Drone(Map* map) :
    map_(map)
{
    bool posFound = false;
    while (!posFound) {
	x_ = TCODRandom::getInstance()->getInt(0, map_->Width() - 1);
	y_ = TCODRandom::getInstance()->getInt(0, map_->Height() - 1);
	if (map_->Walkable(x_, y_)) {
	    posFound = true;
	}
    }
}

void Drone::Render()
{
    TCODConsole::root->setCharForeground(x_, y_, TCODColor::red);
    TCODConsole::root->setChar(x_, y_, 'D');
}
