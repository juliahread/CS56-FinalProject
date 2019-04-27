#include "Player.hpp"
#include "GrapplingHook.hpp"
#include "SpriteSheet.hpp"
#include "GrapplingHook.hpp"
#include "Map.hpp"
#include <cmath>
#include <iostream>

Player::Player(Vec2D pos, Vec2D vel, float fuel, SDL_Renderer *renderer, Map* map) : m_pos(pos), m_vel(vel), m_fuel(fuel), m_map(map), m_jetpack_fired(false)
{
  m_sprsheet = new SpriteSheet("images/player.png", renderer, 1);
  m_grappling_hook = new GrapplingHook(this, map);
  SDL_Rect m_bbox;
  m_bbox.x = m_pos.m_x - HEIGHT / 2;
  m_bbox.y = m_pos.m_y - WIDTH / 2;
  m_bbox.w = WIDTH;
  m_bbox.h = HEIGHT;
};

Player::~Player(){
  delete m_sprsheet;
  delete m_grappling_hook;
}

void Player::update(){
  // Update the grappling hook
  m_grappling_hook->update();

  if(m_grappling_hook->is_spinning()){
    // rotate player pos around last anchor if in spin mode
    // calc angular velocity

    // Compute direction of rotation by taking the cross product of vec from pos to anchor
    // with velocity vec and looking at if its up or down.
    const SDL_Point *anchor = m_grappling_hook->get_last_anchor();
    Vec2D anchor_loc(anchor->x, anchor->y);
    Vec2D pos_to_anchor(anchor_loc.m_x - m_pos.m_x, anchor_loc.m_y - m_pos.m_y);
    // pos_to_anchor cross vel
    // float z_axis = pos_to_anchor.m_x * m_vel.m_y - pos_to_anchor.m_y * m_vel.m_x;
    float z_axis = pos_to_anchor.cross_z(m_vel);
    if (z_axis > 0){
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
  std::vector<SDL_Rect> collisions = m_map->get_obstacle_list()->detectCollisions(*this);
  if (collisions.size() > 0){
    std::cout << "Player collided with " << collisions.size() << " obstacles" << std::endl;
    // Move the player back to where they were before the collision
    m_pos.m_x -= m_vel.m_x;
    m_pos.m_y -= m_vel.m_y;
    // Set vel to 0
    set_vel(Vec2D(0,0));
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
  //Enforce velocity limit
  if (!((abs(vel.m_x) > MAX_VELOCITY) || (abs(vel.m_y) > MAX_VELOCITY)))
  {
	m_vel = vel;
  }
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

SDL_Rect Player::get_bbox() const{
	return m_bbox;
}

void Player::jetpack(float dx, float dy){
  m_jetpack_fired = true;
  if (dx == 0) { // W or S	
	set_vel(Vec2D(get_vel().m_x, get_vel().m_y+dy));
  } else { // A or D, dy = 0
	set_vel(Vec2D(get_vel().m_x+dx, get_vel().m_y));
  }
}

