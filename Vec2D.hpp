#pragma once
#include "SDLHelper.hpp"

class Vec2D {
public:
  Vec2D(float x, float y);
  Vec2D();
  ~Vec2D();
  void rotateCCWAroundPoint(float x, float y, float angle_rads);
  void rotateCWAroundPoint(float x, float y, float angle_rads);
  void normalize();
  void rotate(float angle);
  void scale(float scalar);
  float get_length();
  float m_x;
  float m_y;
  SDL_Point toSDL_Point();
  float dot(const Vec2D& other);
  float cross_z(const Vec2D& other);
};

Vec2D operator- (const SDL_Point a, const SDL_Point b);
