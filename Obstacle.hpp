#pragma once

#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

class Obstacle {
 private:
  SDL_Rect m_bbox;
  SpriteSheet* m_sprite;
  static constexpr int OBSTACLE_WIDTH = 20;
  static constexpr int OBSTACLE_HEIGHT = 20;
  int m_frame_number;
  int m_num_sprites;

 public:
  Obstacle();
  Obstacle(std::string, int, int, SDL_Rect, SDL_Renderer*);
  void renderObstacle(SDL_Renderer*) const;
  const SDL_Rect* get_bbox() const;
};
