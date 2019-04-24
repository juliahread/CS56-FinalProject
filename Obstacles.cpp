#include "Obstacles.hpp"
#include "Obstacle.hpp"
#include "Vec2D.hpp"

Obstacles::Obstacles() : m_obstacles() {}
Obstacles::Obstacles(std::vector<Obstacle> list) : m_obstacles(list) {}
Obstacles::~Obstacles() { m_obstacles.clear(); }
void Obstacles::render(SDL_Renderer* renderer) const {
  if (!m_obstacles.empty()) {
    for (auto const& obstacle : m_obstacles) {
      renderObstacle(obstacle, renderer);
    }
  }
}
void Obstacles::update() {}
bool Obstacles::detectCollisions(Player player) {
	std::cout << player.get_bbox().w;
	std::cout << player.get_bbox().h;
	return false;
}

// Returns an a pointer to the intersection closest to the start point
SDL_Point* Obstacles::intersectLine(SDL_Point start_point, SDL_Point end_point) {
  bool intersection_found = false;
  SDL_Point closest_intersection;

  float min_dist_sq = FLT_MAX;
  for (auto const& obstacle: m_obstacles){
    SDL_Point start_copy = start_point;
    SDL_Point end_copy = end_point;
    int* x1 = &start_copy.x;
    int* x2 = &end_copy.x;
    int* y1 = &start_copy.y;
    int* y2 = &end_copy.y;
    SDL_Rect bbox = obstacle.get_bbox();
    SDL_IntersectRectAndLine(&bbox, x1, y1, x2, y2);
    if(*x1 != start_point.x or *y1 != start_point.y){
      float dist_sq = std::pow(start_point.x - *x1, 2) + std::pow(start_point.y - *y1, 2);
      if (dist_sq < min_dist_sq){
          closest_intersection.x = *x1;
          closest_intersection.y = *y1;
          intersection_found = true;
      }
    }
  }
  if (intersection_found){
    SDL_Point *intersection = new SDL_Point;
    intersection->x = closest_intersection.x;
    intersection->y = closest_intersection.y;
    return intersection;
  } else {
    return nullptr;
  }
}
void Obstacles::renderObstacle(Obstacle obstacle, SDL_Renderer* renderer) const {
  obstacle.get_sprite()->renderSprite(obstacle.get_bbox().x,
                                      obstacle.get_bbox().y, renderer, 0);
}
