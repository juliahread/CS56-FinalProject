#pragma once

#include "Entity.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include <vector>

class Obstacles : public Entity {
 private:
  std::vector<Obstacle> m_obstacles;

 public:
  Obstacles();
  Obstacles(std::vector<Obstacle>);
  ~Obstacles();
  void render(SDL_Renderer*) const;
  void update();
  bool detectCollisions(const Player&);
  SDL_Point* intersectLine(SDL_Point lineStart, SDL_Point lineEnd);
};
