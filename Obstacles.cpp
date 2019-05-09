#include "Obstacles.hpp"
#include <cmath>
#include "Depot.hpp"
#include "Fuel.hpp"
#include "Map.hpp"
#include "Obstacle.hpp"
#include "SDLHelper.hpp"
#include "Vec2D.hpp"

Obstacles::Obstacles(std::vector<Obstacle> o_list) : m_obstacles(o_list) {}
Obstacles::Obstacles(std::vector<Obstacle> o_list, std::vector<Depot> d_list,
                     std::vector<EndObject> e_list)
    : m_obstacles(o_list), m_depots(d_list), m_end(e_list) {
  m_twister = std::mt19937(std::time(NULL));
  rand_range = std::uniform_real_distribution<float>(
      -10, 10);  // Randomize fuel generation
}
Obstacles::~Obstacles() { m_obstacles.clear(); }

void Obstacles::render(SDL_Renderer* renderer) const {
  // Render m_obstacles
  if (!m_obstacles.empty()) {
    for (auto const& obstacle : m_obstacles) {
      obstacle.render(renderer);
    }
  }
  // Render m_depots
  if (!m_depots.empty()) {
    for (auto const& depot : m_depots) {
      depot.render(renderer);
    }
  }
  // Render m_fuel
  if (!m_fuel.empty()) {
    for (auto const& fuel : m_fuel) {
      fuel.render(renderer);
    }
  }
  // Render m_end
  if (!m_end.empty()) {
    for (auto const& end : m_end) {
      end.render(renderer);
    }
  }
}

void Obstacles::update() {}

void Obstacles::update(const Player& player, SDL_Renderer* renderer,
                       int map_width, int map_height) {
  if (!m_depots.empty()) {
    // Spew fuel from all depots
    for (auto const& depot : m_depots) {
      if ((rand() % 100) % 20 == 0) {
        m_fuel.push_back(
            Fuel("apple.png", 1, 1, renderer,
                 {depot.m_pos.x, depot.m_pos.y, Fuel::WIDTH, Fuel::HEIGHT},
                 rand_range(m_twister), rand_range(m_twister)));
      }
    }
  }

  // Update fuel, or if necessary due to collision (add fuel) or leaving map
  // area, destroy it
  SDL_Rect* result = new SDL_Rect{0, 0, 0, 0};
  if (!m_fuel.empty()) {
    for (auto itr = begin(m_fuel); itr != m_fuel.end();) {
      auto p_bbox = player.get_bbox();
      auto f_bbox = itr->get_bbox();
      if ((SDL_IntersectRect(&p_bbox, &f_bbox, result) == SDL_FALSE) &&
          ((itr->get_bbox().x > 0) && (itr->get_bbox().y > 0)) &&
          (itr->get_bbox().x < map_width) && (itr->get_bbox().y < map_height)) {
        itr->update();
      } else {
        if ((SDL_IntersectRect(&p_bbox, &f_bbox, result) == SDL_TRUE)) {
          player.add_fuel(Fuel::FUEL_AMOUNT);
        }
        itr = m_fuel.erase(itr);
        if (itr != m_fuel.begin()) {
          itr = std::prev(itr);
          continue;
        }
      }
      if (itr != m_fuel.end()) {
        ++itr;
      }
    }
  }
}

// Returns an a pointer to the intersection closest to the start point
SDL_Point* Obstacles::intersectLine(SDL_Point start_point,
                                    SDL_Point end_point) {
  bool intersection_found = false;
  SDL_Point closest_intersection;
  Obstacle intersection_obstacle;

  float min_dist_sq = FLT_MAX;
  for (auto const& obstacle : m_obstacles) {
    SDL_Point start_copy = start_point;
    SDL_Point end_copy = end_point;
    int* x1 = &start_copy.x;
    int* x2 = &end_copy.x;
    int* y1 = &start_copy.y;
    int* y2 = &end_copy.y;
    SDL_Rect bbox = obstacle.get_bbox();
    SDL_IntersectRectAndLine(&bbox, x1, y1, x2, y2);
    if (*x1 != start_point.x || *y1 != start_point.y) {
      float dist_from_start_sq =
          std::pow(start_point.x - *x1, 2) + std::pow(start_point.y - *y1, 2);
      float dist_from_end_sq =
          std::pow(end_point.x - *x1, 2) + std::pow(end_point.y - *y1, 2);
      if (dist_from_start_sq < min_dist_sq && dist_from_end_sq > 40) {
        closest_intersection.x = *x1;
        closest_intersection.y = *y1;
        intersection_found = true;
        intersection_obstacle = obstacle;
      }
    }
  }
  if (intersection_found) {
    // TODO: make this code way less ugly
    SDL_Rect intersection_bbox = intersection_obstacle.get_bbox();
    // top left
    SDL_Point current_corner{intersection_bbox.x, intersection_bbox.y};
    SDL_Point best_corner = current_corner;
    float min_corner_dist_sq =
        std::pow(current_corner.x - closest_intersection.x, 2) +
        std::pow(current_corner.y - closest_intersection.y, 2);
    // top right
    current_corner = {intersection_bbox.x + intersection_bbox.w,
                      intersection_bbox.y};
    if (std::pow(current_corner.x - closest_intersection.x, 2) +
            std::pow(current_corner.y - closest_intersection.y, 2) <
        min_corner_dist_sq) {
      best_corner = current_corner;
      min_corner_dist_sq =
          std::pow(current_corner.x - closest_intersection.x, 2) +
          std::pow(current_corner.y - closest_intersection.y, 2);
    }
    // bottom left
    current_corner = {intersection_bbox.x,
                      intersection_bbox.y + intersection_bbox.h};
    if (std::pow(current_corner.x - closest_intersection.x, 2) +
            std::pow(current_corner.y - closest_intersection.y, 2) <
        min_corner_dist_sq) {
      best_corner = current_corner;
      min_corner_dist_sq =
          std::pow(current_corner.x - closest_intersection.x, 2) +
          std::pow(current_corner.y - closest_intersection.y, 2);
    }
    // bottom right
    current_corner = {intersection_bbox.x + intersection_bbox.w,
                      intersection_bbox.y + intersection_bbox.h};
    if (std::pow(current_corner.x - closest_intersection.x, 2) +
            std::pow(current_corner.y - closest_intersection.y, 2) <
        min_corner_dist_sq) {
      best_corner = current_corner;
      min_corner_dist_sq =
          std::pow(current_corner.x - closest_intersection.x, 2) +
          std::pow(current_corner.y - closest_intersection.y, 2);
    }
    SDL_Point* intersection = new SDL_Point;
    intersection->x = best_corner.x;
    intersection->y = best_corner.y;
    return intersection;
  } else {
    return nullptr;
  }
}

bool Obstacles::SDL_TransparentPixel(SDL_Surface* surface, int x, int y) {
  int bpp = surface->format->BytesPerPixel;
  Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
  Uint32 pixelcolor = 0;

  switch (bpp) {
    case (1):
      pixelcolor = *p;
      break;
    case (2):
      pixelcolor = *(Uint16*)p;
      break;
    case (3):
      if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
        pixelcolor = p[0] << 16 | p[1] << 8 | p[2];
      else
        pixelcolor = p[0] | p[1] << 8 | p[2] << 16;
      break;
    case (4):
      pixelcolor = *(Uint32*)p;
      break;
  }
  return (pixelcolor == SpriteSheet::transparent_pixel_value);
}

// Function adapted from
// http://www.angelfire.com/vamp/genjix/sdl_lib/SDL_Collide.h
#define SDL_COLLIDE_MAX(a, b) ((a > b) ? a : b)
#define SDL_COLLIDE_MIN(a, b) ((a < b) ? a : b)
bool Obstacles::SDL_Collide(SDL_Surface* as, int ax, int ay, SDL_Surface* bs,
                            int bx, int by) {
  int ax1 = ax + as->w - 1;
  int ay1 = ay + as->h - 1;

  int bx1 = bx + bs->w - 1;
  int by1 = by + bs->h - 1;

  // Skip per-pixel detection if bounding boxes don't overlap
  if ((bx1 < ax) || (ax1 < bx)) return 0;
  if ((by1 < ay) || (ay1 < by)) return 0;

  int inter_x0 = SDL_COLLIDE_MAX(ax, bx);
  int inter_x1 = SDL_COLLIDE_MIN(ax1, bx1);

  int inter_y0 = SDL_COLLIDE_MAX(ay, by);
  int inter_y1 = SDL_COLLIDE_MIN(ay1, by1);

  for (int y = inter_y0; y <= inter_y1; y++) {
    for (int x = inter_x0; x <= inter_x1; x++) {
      if (!SDL_TransparentPixel(as, x - ax, y - ay) &&
          !SDL_TransparentPixel(bs, x - bx, y - by))
        return 1;
    }
  }
  return 0;
}

bool Obstacles::detectCollisions(const Player& player) {
  SDL_Surface* p_surface = player.get_sprite()->getSurface();
  for (auto const& obstacle : m_obstacles) {
    SDL_Surface* o_surface = obstacle.get_sprite()->getSurface();
    if (SDL_Collide(p_surface, player.get_bbox().x, player.get_bbox().y,
                    o_surface, obstacle.get_bbox().x, obstacle.get_bbox().y))
      return true;
  }
  for (auto const& depot : m_depots) {
    SDL_Surface* d_surface = depot.get_sprite()->getSurface();
    if (SDL_Collide(p_surface, player.get_bbox().x, player.get_bbox().y,
                    d_surface, depot.get_bbox().x, depot.get_bbox().y))
      return true;
  }

  return false;
}

const std::vector<EndObject>& Obstacles::getEnds() { return m_end; }

const std::vector<Obstacle>& Obstacles::getObstacles() { return m_obstacles; }
