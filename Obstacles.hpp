#pragma once

#include <SDL2/SDL.h>

#include "SpriteSheet.hpp"
#include "Entity.hpp"

#include <list>

class Obstacles : public Entity{
public:
  Obstacles();
  ~Obstacles();
  struct Obstacle {
    SDL_Rect m_bbox;
    SpriteSheet *m_sprite;
  };
  void render(SDL_Renderer *renderer);
  void update();
  bool detectCollisions(Player player);
private:
  std::list<Obstacle> m_obstacles;
  void renderObstacle(Obstacle obstacle, SDL_Renderer *renderer);
}
