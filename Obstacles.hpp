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
  std::vector<SDL_Rect> detectCollisions(Player&, SDL_Renderer*);
  void renderObstacle(Obstacle, SDL_Renderer*) const;
  SDL_Point* intersectLine(SDL_Point lineStart, SDL_Point lineEnd);
};
