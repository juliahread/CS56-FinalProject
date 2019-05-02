#include "SDLHelper.hpp"
#include <cmath>
#include "Obstacle.hpp"
#include "Obstacles.hpp"
#include "Vec2D.hpp"

Obstacles::Obstacles() : m_obstacles() {}
Obstacles::Obstacles(std::vector<Obstacle> list) : m_obstacles(list) {}
Obstacles::~Obstacles() { m_obstacles.clear(); }

void Obstacles::render(SDL_Renderer* renderer) const {
  if (!m_obstacles.empty()) {
    for (auto const& obstacle : m_obstacles) {
      obstacle.renderObstacle(renderer);
    }
  }
}

void Obstacles::update() {}

// Returns an a pointer to the intersection closest to the start point
SDL_Point* Obstacles::intersectLine(SDL_Point start_point,
                                    SDL_Point end_point) {
  bool intersection_found = false;
  SDL_Point closest_intersection;

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
      }
    }
  }
  if (intersection_found) {
    SDL_Point* intersection = new SDL_Point;
    intersection->x = closest_intersection.x;
    intersection->y = closest_intersection.y;
    return intersection;
  } else {
    return nullptr;
  }
}

bool SDL_TransparentPixel(SDL_Surface* surface, int x, int y) {
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

// Function adapted from http://www.angelfire.com/vamp/genjix/sdl_lib/SDL_Collide.h
#define SDL_COLLIDE_MAX(a, b) ((a > b) ? a : b)
#define SDL_COLLIDE_MIN(a, b) ((a < b) ? a : b)
int SDL_Collide(SDL_Surface* as, int ax, int ay, SDL_Surface* bs, int bx,
                int by) {
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
  return false;
}
