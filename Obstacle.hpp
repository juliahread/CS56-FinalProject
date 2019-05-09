#pragma once

#include "Entity.hpp"
#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

class Obstacle {
 private:
  SDL_Rect m_bbox;
  SpriteSheet* m_sprite;
  SDL_Point m_pos;
  int m_frame_number;
  int m_num_sprites;

 public:
  Obstacle();
  Obstacle(std::string, int, int, SDL_Renderer*, SDL_Rect);
  static constexpr int WIDTH = 95;
  static constexpr int HEIGHT = 90;
  void render(SDL_Renderer*) const;
  SDL_Rect get_bbox() const;
  SpriteSheet* get_sprite() const;
  const SDL_Point* getLocation() const;
};
