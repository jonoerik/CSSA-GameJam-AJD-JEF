#include "libtcod.hpp"
#include "Player.hpp"

Player::Player(Map& map, int x, int y, int fov_radius, int lives) : map_(map), x(x), y(y), fov_radius(fov_radius), lives_(lives)
{
    map_.TcodMap().computeFov(x, y, fov_radius);
}

void Player::Render()
{
    TCODConsole::root->setCharForeground(x, y, TCODColor::lightCyan);
    TCODConsole::root->setChar(x, y, '@');
}

int Player::Move(int dx, int dy)
{
    int new_x = x + dx;
    int new_y = y + dy;
    if (map_.Walkable(new_x, new_y)) {
	x += dx;
	y += dy;
	map_.ChangePlayerPos(x, y, fov_radius);
	return 1;
    }
    return 0;
}

bool Player::IsHidden()
{
    return false;
}

void Player::Collide() {
    lives_--;
    x = 1;
    y = 1;
    map_.ChangePlayerPos(x, y, fov_radius);
}
