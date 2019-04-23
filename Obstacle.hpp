#pragma once

#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

class Obstacle {
 private:
  SDL_Rect m_bbox;
  SpriteSheet* m_sprite;
  static constexpr int OBSTACLE_WIDTH = 20;
  static constexpr int OBSTACLE_HEIGHT = 20;

 public:
  Obstacle();
  Obstacle(std::string, SDL_Rect, SDL_Renderer*);
  SDL_Rect get_bbox() const;
  SpriteSheet* get_sprite() const;
};
