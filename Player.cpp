#include <SDL2/SDL.h>

#include "Player.hpp"

Player::Player(SDL_Point pos, SDL_Point vel, float fuel) : m_pos(pos), m_vel(vel), m_fuel(fuel)
{
  // TODO: Create the sprite sheet
  m_grappling_hook = new GrapplingHook();
  SDL_Rect m_bbox;
  m_bbox.x = pos.x;
  m_bbox.y = pos.y;
  m_bbox.w = WIDTH;
  m_bbox.h = HEIGHT;
};

Player::~Player(){
  delete m_grappling_hook;
}

void Player::update(){
  m_pos.x += m_vel.x;
  m_pos.y += m_vel.y;
}

void Player::render(SDL_Renderer *renderer){
  // TODO: implement
}

SDL_Point Player::get_pos(){
  return m_pos;
}

SDL_Point Player::get_vel(){
  return m_vel;
}

void Player::eject_mass(SDL_Point dir){
  //normalize dir
  float dir_length = dir.x * dir.x + dir.y * dir.y;
  dir.x /= dir_length;
  dir.y /= dir_length;

  float momentum = 1 * MASS_EJECTION_RATE * MASS_EJECTION_VELOCITY;
  // bad approximation of physics
  m_vel.x -= dir.x * momentum;
  m_vel.y -= dir.y * momentum;
}
