#include "Jetpack.hpp"
#include "Player.hpp"

Jetpack::Jetpack(char direction) : m_direction(direction) {}

Jetpack::~Jetpack() {}

void Jetpack::execute(Player& player) {
  int dx = 0;
  int dy = 0;
  switch (m_direction) {
    case 'W':
      dx = 0;
      dy = THRUST_FACTOR;
      break;
    case 'S':
      dx = 0;
      dy = -THRUST_FACTOR;
      player.jetpack(dx, -dy);
      break;
    case 'A':
      dx = THRUST_FACTOR;
      dy = 0;
      player.jetpack(-THRUST_FACTOR, 0);
      break;
    case 'D':
      dx = -THRUST_FACTOR;
      dy = 0;
      player.jetpack(THRUST_FACTOR, 0);
      break;
  }
  if (!((abs(player.get_vel().m_x + dx) > Player::MAX_VELOCITY) ||
        (abs(player.get_vel().m_y) > Player::MAX_VELOCITY))) {
    player.jetpack(dx, dy);
  }
}

void Jetpack::execute() {}
