#pragma once

#include "SDLHelper.hpp"

class Camera {
 public:
  Camera(SDL_Point location);
  ~Camera();
  void update_location(SDL_Point location);

 private:
  SDL_Point m_location;
};
