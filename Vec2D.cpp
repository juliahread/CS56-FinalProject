#include "Vec2D.hpp"
#include <cmath>
#include <iostream>

Vec2D::Vec2D(float x, float y) : m_x(x), m_y(y){}
Vec2D::Vec2D() : m_x(0), m_y(0) {}
Vec2D::~Vec2D(){}
void Vec2D::rotateCWAroundPoint(float x, float y, float angle_rads){
  // std::cout << "input: " << x << " " << y << " " << m_x << " " << m_y << " " << angle_rads << std::endl;
  float s = sin(angle_rads);
  float c = cos(angle_rads);
  m_x -= x;
  m_y -= y;
  float x_new = m_x * c - m_y * s;
  float y_new = m_x * s + m_y * c;
  m_x = x_new + x;
  m_y = y_new + y;
  // std::cout << "output: " << m_x << " " << m_y << std::endl;
}

SDL_Point Vec2D::toSDL_Point(){
  SDL_Point val;
  val.x = m_x;
  val.y = m_y;
  return val;
}
