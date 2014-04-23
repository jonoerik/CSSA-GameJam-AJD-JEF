#include "libtcod.hpp"
#include "Player.hpp"

Player::Player(Map * map, int x, int y) : map_(map), x(x), y(y)
{

}

void Player::Render()
{
    TCODConsole::root->setChar(x, y, '@');
}

int Player::move(int dx, int dy)
{
    x += dx;
    y += dy;
}
