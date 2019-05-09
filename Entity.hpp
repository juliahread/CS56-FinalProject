#pragma once

#include <iostream>
#include "SDLHelper.hpp"

class Entity {
 public:
  virtual void render(SDL_Renderer *renderer) const = 0;
  virtual void update() = 0;
  virtual ~Entity() = 0;
};
