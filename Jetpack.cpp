#include "Jetpack.hpp"
#include "Player.hpp"

Jetpack::Jetpack(char direction) : m_direction(direction) {}

Jetpack::~Jetpack() {}

void Jetpack::execute(Player& player) { 
	switch (m_direction) { 
		case 'S':
            player.set_vel(Vec2D(player.get_vel().m_x, player.get_vel().m_y - 1));
            break;
	}
}

void Jetpack::execute() {

}


