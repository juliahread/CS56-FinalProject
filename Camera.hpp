#pragma once

#include <SDL2/SDL.h>
class Camera {
public:
  Camera(SDL_Point location);
  ~Camera();
private:
        SDL_Point m_location;
};
