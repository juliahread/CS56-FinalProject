#pragma once

#include "Entity.hpp"
#include "SpriteSheet.hpp"

class GrapplingPoint : public Entity {
 private:
  SDL_Point m_pos;
  SDL_Rect m_bbox;
  SpriteSheet* m_sprite;

 public:
  GrapplingPoint();
  GrapplingPoint(std::string, SDL_Rect, SDL_Renderer*);
  GrapplingPoint(std::string, int, int, SDL_Renderer*);
  void render(SDL_Renderer* renderer) const;
  void update();
  const SDL_Point* getLocation() const;
  // Sprite info
  static constexpr int WIDTH = 50;
  static constexpr int HEIGHT = 50;
};
