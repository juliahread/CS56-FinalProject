#pragma once

#include "Entity.hpp"
#include "SpriteSheet.hpp"

class Background : public Entity {
 public:
  Background(int type, SDL_Renderer* renderer);
  ~Background();
  void render(SDL_Renderer *renderer) const;
  void update();

 private:
  SpriteSheet *m_sprite_sheet;
};
