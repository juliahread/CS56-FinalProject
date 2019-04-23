#pragma once

#include "Entity.hpp"
#include "SpriteSheet.hpp"

class Background : public Entity {
 public:
  Background(SpriteSheet *sprite_sheet);
  ~Background();
  void render(SDL_Renderer *renderer);
  void update();

 private:
  SpriteSheet *m_sprite_sheet;
};
