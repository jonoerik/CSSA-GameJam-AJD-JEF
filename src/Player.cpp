#include "libtcod.hpp"
#include "Player.hpp"

Player::Player(Map& map, int x, int y, int fov_radius, int lives) : map_(map), x(x), y(y), fov_radius(fov_radius), lives_(lives)
{
    map_.TcodMap().computeFov(x, y, fov_radius);
    hidden_time_finish_ = 0;
    energy_ = 5;
}

void Player::Render()
{
    TCODConsole::root->setCharForeground(x, y,
					 IsHidden() ? TCODColor::grey : TCODColor::lightCyan);
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

void Player::Hide()
{
    if (!IsHidden() && energy_ > 0) {
	hidden_time_finish_ = TCODSystem::getElapsedMilli() + 5000;
	energy_--;
    }
}

bool Player::IsHidden()
{
    return hidden_time_finish_ > TCODSystem::getElapsedMilli();
}

void Player::Collide() {
    lives_--;
    x = 1;
    y = 1;
    map_.ChangePlayerPos(x, y, fov_radius);
}
