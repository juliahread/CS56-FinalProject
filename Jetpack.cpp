#include "Jetpack.hpp"
#include "Player.hpp"

Jetpack::Jetpack(char direction) : m_direction(direction) {}

Jetpack::~Jetpack() {}

void Jetpack::execute(Player& player) {
	switch (m_direction) {
		case 'S':
			player.jetpack(0, THRUST_FACTOR);
            		break;
		case 'W':
			player.jetpack(0, -THRUST_FACTOR);
			break;
		case 'A':
			player.jetpack(-THRUST_FACTOR, 0);
			break;
		case 'D':
			player.jetpack(THRUST_FACTOR, 0);
			break;
	}
}

void Jetpack::execute() {

}
