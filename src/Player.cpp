#include "libtcod.hpp"
#include "Player.hpp"

Player::Player(Map& map, int x, int y, int fov_radius) : map_(map), x(x), y(y), fov_radius(fov_radius)
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

bool Player::IsHidden()
{
    return false;
}

bool Player::IsVisible(int px, int py)
{
    int x_cur = x, y_cur = y;
    bool visible = true;
// todo: distance
    TCODLine::init(x, y, px, py);
    do {
	if (!map_.Walkable(x_cur, y_cur)) {
	    visible = false;
	    break;
	}
    } while (!TCODLine::step(&x_cur, &y_cur));
    return visible;
}

void Player::RenderVisibility() {
    for (size_t map_y = 0; map_y < map_.Height(); map_y++) {
	for (size_t map_x = 0; map_x < map_.Width(); map_x++) {
	    if (!IsVisible(map_x, map_y)) {
		TCODConsole::root->setChar(map_x, map_y, '_');
	    }
	}
    }
}
