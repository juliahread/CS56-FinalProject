#pragma once

#include <vector>
#include "Depot.hpp"
#include "Entity.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"

class Obstacles : public Entity {
 private:
  std::vector<Obstacle> m_obstacles;

 public:
  std::vector<Depot> m_depots;  // TODO: getter
  Obstacles();
  Obstacles(std::vector<Obstacle>);
  Obstacles(std::vector<Obstacle>, std::vector<Depot>);
  ~Obstacles();
  void render(SDL_Renderer*) const;
  void update();
  bool detectCollisions(const Player&);
  SDL_Point* intersectLine(SDL_Point lineStart, SDL_Point lineEnd);
  bool SDL_TransparentPixel(SDL_Surface*, int, int);
  bool SDL_Collide(SDL_Surface*, int, int, SDL_Surface*, int, int);
};
