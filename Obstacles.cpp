#include "Obstacles.hpp"
#include "Obstacle.hpp"
#include "Vec2D.hpp"
#include <cmath>

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

// If the player and any obstacle collide, return an SDL_Rect** to the
// overlapping areas, or else return an empty vector.
// Is temporarily passed SDL_Renderer for debug-drawing the area
std::vector<SDL_Rect> Obstacles::detectCollisions(const Player& player) {
  std::vector<SDL_Rect> collisions_vector;
  SDL_Rect* overlapping_rectangle = new SDL_Rect;
  for (auto const& obstacle : m_obstacles) {
    SDL_Rect player_bbox = player.get_bbox();
    const SDL_Rect* obstacle_bbox = obstacle.get_bbox();
    if (SDL_IntersectRect(obstacle_bbox, &player_bbox,
                          overlapping_rectangle) == SDL_TRUE) {
      collisions_vector.push_back(*overlapping_rectangle);
    }
  }
  delete overlapping_rectangle;
  return collisions_vector;
}

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
    SDL_Rect bbox = *obstacle.get_bbox();
    SDL_IntersectRectAndLine(&bbox, x1, y1, x2, y2);
    if (*x1 != start_point.x or *y1 != start_point.y) {
      float dist_from_start_sq =
          std::pow(start_point.x - *x1, 2) + std::pow(start_point.y - *y1, 2);
      float dist_from_end_sq =
        std::pow(end_point.x - *x1, 2) + std::pow(end_point.y - *y1, 2);
      if (dist_from_start_sq < min_dist_sq and dist_from_end_sq > 40) {
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
