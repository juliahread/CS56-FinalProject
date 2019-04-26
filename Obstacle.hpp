#pragma once

#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

class Obstacle {
 private:
  SDL_Rect m_bbox;
  SpriteSheet* m_sprite;
  SDL_Point m_loc;
  static constexpr int OBSTACLE_WIDTH = 85;
  static constexpr int OBSTACLE_HEIGHT = 85;
  static constexpr int BBOX_HEIGHT_OFFSET = 7;
  static constexpr int BBOX_WIDTH_OFFSET = 7;
  int m_frame_number;
  int m_num_sprites;

 public:
  Obstacle();
  Obstacle(std::string, int, int, SDL_Renderer*, SDL_Point);
  void renderObstacle(SDL_Renderer*) const;
  const SDL_Rect* get_bbox() const;
};
