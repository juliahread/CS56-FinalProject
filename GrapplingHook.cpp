#include "GrapplingHook.hpp"
#include "Map.hpp"
#include "Obstacles.hpp"
#include "Player.hpp"
#include "Camera.hpp"
#include <iostream>
#include <cmath>

GrapplingHook::GrapplingHook(Player *shooter, Map *map, SDL_Renderer *renderer) : m_fired(false), m_spin(None), m_was_spinning(false), m_distance_sq(0), m_shooter(shooter), m_map(map) {
  // TODO: replace with actual sprite
  m_sprsheet = new SpriteSheet("images/square.png", renderer, 1);
  m_wrap_points = std::vector<Wrap>();
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
    m_wrap_points.push_back({*potential_anchor, None});
    std::cout << "anchor x: " << potential_anchor->x << " anchor y: " << potential_anchor->y
              << std::endl;
    m_distance_sq = std::pow(std::abs(potential_anchor->x - player_loc.m_x), 2) +
      std::pow(std::abs(potential_anchor->y - player_loc.m_y), 2);
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
}

void GrapplingHook::render(SDL_Renderer *renderer) const {
  if (m_fired) {
    // Draw each line from the shooter to the anchor with any wrap points in
    // between
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_Point offset = Camera::get_instance()->get_offset();
    for (auto it = m_wrap_points.begin(); it != m_wrap_points.end(); ++it) {
      SDL_Point start = it->point;
      auto next_it = next(it);
      if (next_it != m_wrap_points.end()){
        SDL_Point next = next_it->point;
        SDL_RenderDrawLine(renderer, start.x - offset.x, start.y - offset.y,
                           next.x - offset.x, next.y - offset.y);
      }
    }
    SDL_Point last_wrap = *get_last_anchor();
    SDL_Point player_loc = m_shooter->get_pos().toSDL_Point();
    SDL_RenderDrawLine(renderer, last_wrap.x - offset.x, last_wrap.y - offset.y,
                       player_loc.x - offset.x, player_loc.y - offset.y);

    //render the gun sprite rotated appropriately
    float angle = atan2(last_wrap.x - player_loc.x, last_wrap.y - player_loc.y);
    m_sprsheet->renderSpriteRotatedCentered(player_loc.x, player_loc.y, renderer, 1, -angle);
  }
}

void GrapplingHook::update() {
  if (m_fired){
    // Check for new wraps
    SDL_Point last_anchor = *get_last_anchor();
    SDL_Point shooter_pos = m_shooter->get_pos().toSDL_Point();
    SDL_Point * intersection = m_map->get_obstacle_list()->intersectLine(shooter_pos, last_anchor);
    if(intersection != nullptr){
      m_wrap_points.push_back({*intersection, m_spin});
      std::cout << "intersection pushed" << intersection->x << " " << intersection-> y << std::endl;
      std::cout << "num wraps: " << m_wrap_points.size() << std::endl;

      Vec2D player_loc = m_shooter->get_pos();
      m_distance_sq = std::pow(std::abs(intersection->x - player_loc.m_x), 2) +
        std::pow(std::abs(intersection->y - player_loc.m_y), 2);
    }

    // Check for new unwraps
    if(m_wrap_points.size() > 1){
      SDL_Point player_loc = m_shooter->get_pos().toSDL_Point();
      Wrap last_wrap = m_wrap_points.back();
      SDL_Point last_anchor = last_wrap.point;
      SDL_Point second_last = m_wrap_points.end()[-2].point;
      Vec2D current_line = player_loc - last_anchor;
      Vec2D prev_line = last_anchor - second_last;
      float z = current_line.cross_z(prev_line) / (current_line.get_length() * prev_line.get_length());
      if (last_wrap.wrap_dir == CW){
        if (z > .1){
          std::cout << "unwrapping CW" << std::endl;
          m_wrap_points.pop_back();
        }
      }
      if (last_wrap.wrap_dir == CCW){
        if (z < -.1){
          std::cout << "unwrapping CCW" << std::endl;
          m_wrap_points.pop_back();
        }
      }
    }

  }
}

bool GrapplingHook::check_fired() const {
	return m_fired;
}

const SDL_Point *GrapplingHook::get_last_anchor() const {
  return &m_wrap_points.back().point;
}

float GrapplingHook::dist_sq_from_last_anchor() const {
  SDL_Point last_anchor = *get_last_anchor();
  SDL_Point player_loc = m_shooter->get_pos().toSDL_Point();
  return std::pow(std::abs(last_anchor.x - player_loc.x), 2) + std::pow(std::abs(last_anchor.y - player_loc.y), 2);
}

float GrapplingHook::dist_from_last_anchor() const {
  return std::pow(dist_sq_from_last_anchor(), .5);
}

bool GrapplingHook::is_spinning() const {
  if (m_fired){
    SDL_Point player_loc = m_shooter->get_pos().toSDL_Point();
    Wrap last_wrap = m_wrap_points.back();
    SDL_Point last_anchor = last_wrap.point;
    Vec2D current_line = last_anchor - player_loc ;
    return (dist_sq_from_last_anchor() >= m_distance_sq) && (current_line.dot(m_shooter->get_vel()) <= 0);
  } else {
    return false;
  }
}

Spin GrapplingHook::get_spin() const {
	return m_spin;
}

void GrapplingHook::set_spin(Spin spin) {
	m_spin = spin;
}

void GrapplingHook::update_player(){
  update_player_loc();
  update_player_vel();
}

void GrapplingHook::update_player_loc() {
  Vec2D player_loc = m_shooter->get_pos();
  SDL_Point last_anchor = *get_last_anchor();
  float omega = m_shooter->get_vel().get_length() / dist_from_last_anchor();

  if (m_spin == CW){
    player_loc.rotateCCWAroundPoint(last_anchor.x, last_anchor.y, omega);
  } else {
    player_loc.rotateCWAroundPoint(last_anchor.x, last_anchor.y, omega);
  }
  m_shooter->set_pos(player_loc);
}

void GrapplingHook::update_player_vel() {
  Vec2D player_loc = m_shooter->get_pos();
  const SDL_Point *sdl_anchor_loc = get_last_anchor();
  Vec2D anchor_to_player(player_loc.m_x - sdl_anchor_loc->x, player_loc.m_y - sdl_anchor_loc->y);
  anchor_to_player.normalize();
  anchor_to_player.rotate(M_PI / 2);
  // if we just started spinning, reduce vel based on angle
  float cos_theta = 1;
  if (not m_was_spinning and is_spinning()){
    cos_theta = abs(anchor_to_player.dot(m_shooter->get_vel()) / (anchor_to_player.get_length() * m_shooter->get_vel().get_length()));
    if (isnan(cos_theta)){
      std::cout << "was nan" << std::endl;
      cos_theta = 1;
    }
    if (cos_theta > .95){
      cos_theta = 1;
    }
    m_was_spinning = true;
  }
  anchor_to_player.scale(m_shooter->get_vel().get_length());
  if (m_spin == CCW) {
    anchor_to_player.scale(-1);
  }
  anchor_to_player.scale(cos_theta);
  m_shooter->set_vel(anchor_to_player);
}

void GrapplingHook::set_was_spinning(bool was_spinning){
  m_was_spinning = was_spinning;
}
