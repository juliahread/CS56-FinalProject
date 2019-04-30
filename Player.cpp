#include "Player.hpp"
#include <cmath>
#include <iostream>
#include "GrapplingHook.hpp"
#include "Map.hpp"
#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

Player::Player(Vec2D pos, Vec2D vel, float fuel, SDL_Renderer* renderer,
               Map* map)
    : m_pos(pos), m_vel(vel), m_fuel(fuel), m_map(map), m_jetpack_fired(false) {
  m_bbox = SDL_Rect{static_cast<int>(m_pos.m_x - HEIGHT / 2),
						static_cast<int>(m_pos.m_y - WIDTH / 2),
						WIDTH, HEIGHT};
  m_sprsheet = new SpriteSheet("images/player.png", renderer, 1);
  m_grappling_hook = new GrapplingHook(this, map);
}

Player::~Player() {
  delete m_sprsheet;
  delete m_grappling_hook;
}

void Player::update() {
  // Update the grappling hook
  m_grappling_hook->update();

  if (m_grappling_hook->is_spinning()) {
    // rotate player pos around last anchor if in spin mode
    // calc angular velocity

    // Compute direction of rotation by taking the cross product of vec from pos
    // to anchor with velocity vec and looking at if its up or down.
    const SDL_Point* anchor = m_grappling_hook->get_last_anchor();
    Vec2D anchor_loc(anchor->x, anchor->y);
    Vec2D pos_to_anchor(anchor_loc.m_x - m_pos.m_x, anchor_loc.m_y - m_pos.m_y);
    // pos_to_anchor cross vel
    // float z_axis = pos_to_anchor.m_x * m_vel.m_y - pos_to_anchor.m_y *
    // m_vel.m_x;
    float z_axis = pos_to_anchor.cross_z(m_vel);
    if (z_axis > 0) {
      m_grappling_hook->set_spin(CCW);
    } else {
      m_grappling_hook->set_spin(CW);
    }
    m_grappling_hook->update_player_loc(m_pos);
    m_grappling_hook->update_player_vel();
  } else {
    m_pos.m_x += m_vel.m_x;
    m_pos.m_y += m_vel.m_y;
  }
  // Update bbox x and y to reflect player's position
  m_bbox.x = m_pos.m_x - WIDTH / 2;
  m_bbox.y = m_pos.m_y - HEIGHT / 2;
  // It seems that the motion of the player necessitates the below code
  // for its bbox width and height to ! become 0
  m_bbox.w = WIDTH;
  m_bbox.h = HEIGHT;

  // Check for collisions
  if (m_map->get_obstacle_list()->detectCollisions(*this)) {
    std::cout << "Player collided with obstacle" << std::endl;
    // Move the player back to where they were before the collision
    m_pos.m_x -= m_vel.m_x;
    m_pos.m_y -= m_vel.m_y;
    // Set vel to 0
    set_vel(Vec2D(0, 0));
  }
}

void Player::render(SDL_Renderer* renderer) const {
  m_sprsheet->renderSpriteCentered(m_pos.m_x, m_pos.m_y, renderer, 0);
  m_grappling_hook->render(renderer);
}

Vec2D Player::get_pos() const{
  return m_pos;
}

Vec2D Player::get_vel() const{
  return m_vel;
}

void Player::set_vel(Vec2D vel){
	m_vel = vel;
}

void Player::eject_mass(SDL_Point dir) {
  // normalize dir
  float dir_length = dir.x * dir.x + dir.y * dir.y;
  dir.x /= dir_length;
  dir.y /= dir_length;

  float momentum = 1 * MASS_EJECTION_RATE * MASS_EJECTION_VELOCITY;
  // bad approximation of physics
  m_vel.m_x -= dir.x * momentum;
  m_vel.m_y -= dir.y * momentum;
}

GrapplingHook* Player::getGrapplingHook() {
	return m_grappling_hook;
}

SDL_Rect Player::get_bbox() const {
	return m_bbox;
}

SpriteSheet* Player::get_sprite() const {
	return m_sprsheet;
}

void Player::jetpack(float dx, float dy) {
  std::cout << "player fuel: " << m_fuel << std::endl;
  if (m_fuel > 0){
    m_fuel -= 1;
    m_vel.m_x += dx;
    m_vel.m_y += dy;
  }
}
