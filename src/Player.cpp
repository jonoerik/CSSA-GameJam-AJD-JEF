#include "libtcod.hpp"
#include "Player.hpp"

Player::Player(Map& map, int x, int y) : map_(map), x(x), y(y)
{

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
	return 1;
    }
    return 0;
}

bool Player::IsHidden() {
    return false;
}
