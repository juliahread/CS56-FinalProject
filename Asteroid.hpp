#pragma once

#include "Entity.hpp"
#include "SpriteSheet.hpp"

class Asteroid : public Entity {
  private:
    SpriteSheet m_sprite_sheet;
  public:
    void render(SDL_Renderer *renderer);
    void update();
}
