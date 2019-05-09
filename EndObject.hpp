#pragma once

#include "Entity.hpp"
#include "Obstacle.hpp"
#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

class EndObject : public Obstacle {
 private:
  SDL_Rect m_bbox;
  SpriteSheet* m_sprite;
  SDL_Point m_pos;
  int m_frame_number;
  int m_num_sprites;

 public:
  EndObject();
  EndObject(std::string, int, int, SDL_Renderer*, SDL_Rect);
  static constexpr int WIDTH = 416;
  static constexpr int HEIGHT = 124;
  void render(SDL_Renderer*) const;
  SDL_Rect get_bbox() const;
  SpriteSheet* get_sprite() const;
  const SDL_Point* getLocation() const;
};
