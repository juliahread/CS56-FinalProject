#pragma once
#include <SDL2/SDL.h>

class Vec2D {
public:
  Vec2D(float x, float y);
  Vec2D();
  ~Vec2D();
  void rotateCWAroundPoint(float x, float y, float angle_rads);
  float m_x;
  float m_y;
  SDL_Point toSDL_Point();
};
