#include "GrapplingHook.hpp"
#include "Map.hpp"
#include "Obstacles.hpp"
#include "Player.hpp"
#include <iostream>

GrapplingHook::GrapplingHook(Player *shooter, Map *map) : m_fired(false), m_spin(None), m_distance_sq(0), m_anchor(nullptr), m_shooter(shooter), m_map(map) {
  // TODO: Load the appropriate sprite sheet
  m_bbox = nullptr;
  m_wrap_points = std::vector<SDL_Point>();
};

void GrapplingHook::shoot(SDL_Point click) {
  if (m_fired) {
    detach();
  }
  //check if the hook hits an obstacle
  const SDL_Point *potential_anchor = m_map->get_grappling_point_list()->findClosestGrapplePoint(click);
  Vec2D player_loc = m_shooter->get_pos();
  SDL_Point *intersection = m_map->get_obstacle_list()->intersectLine(player_loc.toSDL_Point(), *potential_anchor);
  if(intersection == nullptr){
    // No collision, so valid grapple
    m_anchor = potential_anchor;
    std::cout << "anchor x: " << m_anchor->x << " anchor y: " << m_anchor->y
              << std::endl;
    m_distance_sq = std::pow(std::abs(m_anchor->x - player_loc.m_x), 2) +
      std::pow(std::abs(m_anchor->y - player_loc.m_y), 2);
    m_fired = true;
  }
  // TODO: render the failure to grapple
};

void GrapplingHook::detach() {
  m_wrap_points.clear();
  m_fired = false;
  m_distance_sq = 0;
  // Set new velocity vector
  set_spin(None);
  m_anchor = nullptr;
}

void GrapplingHook::render(SDL_Renderer *renderer) const {
  if (m_fired) {
    // Draw each line from the shooter to the anchor with any wrap points in
    // between
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_Point start = m_shooter->get_pos().toSDL_Point();
    for (auto it : m_wrap_points) {
      SDL_Point next = it;
      SDL_RenderDrawLine(renderer, start.x, start.y, next.x, next.y);
      start = next;
    }
    SDL_Point next = *m_anchor;
    SDL_RenderDrawLine(renderer, start.x, start.y, next.x, next.y);
  }
}

void GrapplingHook::update() {
  // TODO: Implement fully
}

bool GrapplingHook::check_fired() const { 
	return m_fired; 
}

const SDL_Point *GrapplingHook::get_anchor() const { 
	return m_anchor; 
}

const SDL_Point *GrapplingHook::get_last_anchor() const {
  if (m_wrap_points.size() > 0) {
    return &m_wrap_points.back();
  } else {
    return m_anchor;
  }
}

float GrapplingHook::dist_sq_from_last_anchor() const {
  SDL_Point last_anchor;
  if (m_wrap_points.size() > 0) {
    last_anchor = m_wrap_points.back();
  } else {
    last_anchor = *m_anchor;
  }
  SDL_Point player_loc = m_shooter->get_pos().toSDL_Point();
  return std::pow(std::abs(last_anchor.x - player_loc.x), 2) + std::pow(std::abs(last_anchor.y - player_loc.y), 2);
}

float GrapplingHook::dist_from_last_anchor() const {
  return std::pow(dist_sq_from_last_anchor(), .5);
}

bool GrapplingHook::is_spinning() const {
  return m_fired and (dist_sq_from_last_anchor() >= m_distance_sq);
}

Spin GrapplingHook::get_spin() const {
	return m_spin;
}

void GrapplingHook::set_spin(Spin spin) {
	m_spin = spin;
}

void GrapplingHook::update_player_loc(Vec2D &player_loc) {
  SDL_Point last_anchor;
  if (m_wrap_points.size() > 0) {
    last_anchor = m_wrap_points.back();
  } else {
    last_anchor = *m_anchor;
  }
  float omega = m_shooter->get_vel().get_length() / dist_from_last_anchor();

  if (m_spin == CW){
    player_loc.rotateCCWAroundPoint(last_anchor.x, last_anchor.y, omega);
  } else {
    player_loc.rotateCWAroundPoint(last_anchor.x, last_anchor.y, omega);
  }
}

void GrapplingHook::update_player_vel() {
  Vec2D player_loc = m_shooter->get_pos();
  const SDL_Point *sdl_anchor_loc = get_last_anchor();
  Vec2D anchor_to_player(player_loc.m_x - sdl_anchor_loc->x, player_loc.m_y - sdl_anchor_loc->y);
  anchor_to_player.normalize();
  anchor_to_player.rotate(M_PI / 2);
  anchor_to_player.scale(m_shooter->get_vel().get_length());
  if (m_spin == CCW) {
    anchor_to_player.scale(-1);
  }
  m_shooter->set_vel(anchor_to_player);
}
