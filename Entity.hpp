#pragma once

#include "SDLHelper.hpp"
#include <iostream>

class Entity {
 public:
  virtual void render(SDL_Renderer *renderer) const = 0;
  virtual void update() = 0;
  virtual ~Entity() = 0;
};
