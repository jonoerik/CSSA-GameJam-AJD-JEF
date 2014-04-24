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
    SetDest();
    path_ = std::unique_ptr<TCODPath>(new TCODPath(&(map_->TcodMap()), 0.0f));
}

void Drone::Render()
{
    TCODConsole::root->setCharForeground(x_, y_, TCODColor::red);
    TCODConsole::root->setChar(x_, y_, 'D');
}

void Drone::DoStep()
{
    if (x_ == destX_ && y_ == destY_) {
	SetDest();
    }
    if (path_->compute(x_, y_, destX_, destY_)) {
	int x,y;
	path_->get(0, &x, &y);
	x_ = static_cast<size_t>(x);
	y_ = static_cast<size_t>(y);
    }
}

void Drone::SetDest()
{
    do {
	destX_ = TCODRandom::getInstance()->getInt(0, map_->Width() - 1);
	destY_ = TCODRandom::getInstance()->getInt(0, map_->Height() - 1);
    } while ((x_ == destX_ && y_ == destY_) || (!map_->Walkable(destX_, destY_)));
}
