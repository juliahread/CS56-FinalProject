#include "Player.hpp"
#include "GrapplingHook.hpp"
#include "SpriteSheet.hpp"
#include "GrapplingHook.hpp"
#include <cmath>
#include <iostream>

Player::Player(Vec2D pos, Vec2D vel, float fuel, SDL_Renderer *renderer, Map* map) : m_pos(pos), m_vel(vel), m_fuel(fuel), m_map(map)
{
  m_sprsheet = new SpriteSheet("images/astronaut.png", renderer, 1);
  m_grappling_hook = new GrapplingHook(this, map);
  SDL_Rect m_bbox;
  m_bbox.x = pos.m_x;
  m_bbox.y = pos.m_y;
  m_bbox.w = WIDTH;
  m_bbox.h = HEIGHT;
};

Player::~Player(){
  delete m_sprsheet;
  delete m_grappling_hook;
}

void Player::update(){
  if(m_grappling_hook->is_spinning()){
    // rotate player pos around last anchor if in spin mode
    // calc angular velocity
    float vel_magnitude = std::pow(std::pow(m_vel.m_x, 2) + std::pow(m_vel.m_y,2), .5);
    float omega = vel_magnitude / m_grappling_hook->dist_from_last_anchor();
    if (m_grappling_hook->get_spin() == None){
      // Compute direction of rotation by taking the cross product of vec from pos to anchor
      // with velocity vec and looking at if its up or down.
      const SDL_Point *anchor = m_grappling_hook->get_last_anchor();
      Vec2D anchor_loc(anchor->x, anchor->y);
      Vec2D pos_to_anchor(anchor_loc.m_x - m_pos.m_x, anchor_loc.m_y - m_pos.m_y);
      // pos_to_anchor cross vel
      float z_axis = pos_to_anchor.m_x * m_vel.m_y - pos_to_anchor.m_y * m_vel.m_x;
      if (z_axis > 0){
        m_grappling_hook->set_spin(CCW);
      } else {
        m_grappling_hook->set_spin(CW);
      }
    }
    int spin = m_grappling_hook->get_spin();
    if (spin == CW){
      m_grappling_hook->update_player_loc(omega, m_pos);
    } else {
      m_grappling_hook->update_player_loc(-1 *omega, m_pos);
    }

  } else {
    m_pos.m_x += m_vel.m_x;
    m_pos.m_y += m_vel.m_y;
  }
}

void Player::render(SDL_Renderer *renderer) const{
  m_sprsheet->renderSpriteCentered(m_pos.m_x, m_pos.m_y,  renderer, 0);
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

void Player::eject_mass(SDL_Point dir){
  //normalize dir
  float dir_length = dir.x * dir.x + dir.y * dir.y;
  dir.x /= dir_length;
  dir.y /= dir_length;

  float momentum = 1 * MASS_EJECTION_RATE * MASS_EJECTION_VELOCITY;
  // bad approximation of physics
  m_vel.m_x -= dir.x * momentum;
  m_vel.m_y -= dir.y * momentum;
}

GrapplingHook* Player::getGrapplingHook(){
  return m_grappling_hook;
}
