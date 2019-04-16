#pragma once

#include "SpriteSheet.hpp"
#include "Entity.hpp"

class Background : public Entity {
public:
  Background(SpriteSheet *sprite_sheet);
  ~Background();
  void render(SDL_Renderer *renderer);
  void update();
private:
    SpriteSheet *m_sprite_sheet;
};
