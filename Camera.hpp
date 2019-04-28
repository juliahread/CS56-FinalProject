#pragma once

#include "SDLHelper.hpp"

class Camera {
 public:
  Camera(SDL_Point location);
  ~Camera();

 private:
  SDL_Point m_location;
};
