#pragma once

#include "Obstacle.hpp"
#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

class Depot : public Obstacle {
 private:
  SDL_Rect m_bbox;
  SpriteSheet* m_sprite;
  int m_frame_number;
  int m_num_sprites;

 public:
  SDL_Point m_pos;
  Depot();
  Depot(std::string, int, int, SDL_Renderer*, SDL_Rect);
  void render(SDL_Renderer* renderer) const;
  static constexpr int WIDTH = 250;
  static constexpr int HEIGHT = 150;
  SDL_Rect get_bbox() const;
  SpriteSheet* get_sprite() const;
};
