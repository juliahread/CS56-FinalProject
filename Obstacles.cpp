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

// a = starting point
// b = ending point, which is returned 
SDL_Point* IntersectLine(SDL_Rect rect, SDL_Point a, SDL_Point b) {
	int* x1 = &a.x;
	int* x2 = &b.x;
	int* y1 = &a.y;
	int* y2 = &a.x;
	SDL_Rect* rect_ptr = &rect;
	SDL_IntersectRectAndLine(rect_ptr, x1, y1, x2, y2);
       	SDL_Point intersection = {*x2, *y2};
	return &intersection;	
}
void Obstacles::renderObstacle(Obstacle obstacle, SDL_Renderer* renderer) const {
  obstacle.get_sprite()->renderSprite(obstacle.get_bbox().x,
                                      obstacle.get_bbox().y, renderer, 0);
}
