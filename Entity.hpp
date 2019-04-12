#pragma once

#include <SDL2/SDL.h>

class Entity {
public:
  virtual void render(SDL_Renderer *renderer) = 0;
  virtual void update() = 0;
  virtual ~Entity();
};
