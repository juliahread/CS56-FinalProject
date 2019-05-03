#include "Jetpack.hpp"
#include "Player.hpp"

Jetpack::Jetpack(char direction) : m_direction(direction) {}

Jetpack::~Jetpack() {}

void Jetpack::execute(Player& player) {
  float dx = 0;
  float dy = 0;
  switch (m_direction) {
    case 'W':
      dy = -THRUST_FACTOR;
      break;
    case 'S':
      dy = THRUST_FACTOR;
      break;
    case 'A':
      dx = -THRUST_FACTOR;
      break;
    case 'D':
      dx = THRUST_FACTOR;
      break;
  }
  if (player.get_vel().get_length() < Player::MAX_VELOCITY){
    player.jetpack(dx, dy, m_direction);
  }
}

void Jetpack::execute() {}
