#include "Player.hpp"
#include "GrapplingHook.hpp"
#include "SpriteSheet.hpp"
#include "GrapplingHook.hpp"

Player::Player(SDL_Point pos, SDL_Point vel, float fuel, SDL_Renderer *renderer, Map* map) : m_pos(pos), m_vel(vel), m_fuel(fuel), m_map(map)
{
  m_sprsheet = new SpriteSheet("images/astronaut.png", renderer, 1);
  m_grappling_hook = new GrapplingHook(this, map);
  SDL_Rect m_bbox;
  m_bbox.x = pos.x;
  m_bbox.y = pos.y;
  m_bbox.w = WIDTH;
  m_bbox.h = HEIGHT;
};

Player::~Player(){
  delete m_sprsheet;
  delete m_grappling_hook;
}

void Player::update(){
  m_pos.x += m_vel.x;
  m_pos.y += m_vel.y;
}

void Player::render(SDL_Renderer *renderer) const{
  m_sprsheet->renderSprite(m_pos.x, m_pos.y,  renderer, 0);
  m_grappling_hook->render(renderer);
}

SDL_Point Player::get_pos() const{
  return m_pos;
}

SDL_Point Player::get_center() const{
  SDL_Point center;
  center.x = m_pos.x + WIDTH / 2;
  center.y = m_pos.y + HEIGHT / 2;
  return center;
}

SDL_Point Player::get_vel() const{
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

GrapplingHook* Player::getGrapplingHook(){
  return m_grappling_hook;
}
