#include "Vec2D.hpp"
#include <cmath>
#include <iostream>

Vec2D::Vec2D(float x, float y) : m_x(x), m_y(y) {}
Vec2D::Vec2D() : m_x(0), m_y(0) {}
Vec2D::~Vec2D() {}
void Vec2D::rotateCCWAroundPoint(float x, float y, float angle_rads) {
  m_x -= x;
  m_y -= y;
  rotate(angle_rads);
  m_x += x;
  m_y += y;
}
void Vec2D::rotateCWAroundPoint(float x, float y, float angle_rads) {
  rotateCCWAroundPoint(x, y, -1 * angle_rads);
}

SDL_Point Vec2D::toSDL_Point() {
  SDL_Point val;
  val.x = m_x;
  val.y = m_y;
  return val;
}

void Vec2D::normalize() {
  float length = get_length();
  scale(1 / length);
}

void Vec2D::scale(float scalar) {
  m_x *= scalar;
  m_y *= scalar;
}

float Vec2D::get_length() const {
  return std::pow(std::pow(m_x, 2) + std::pow(m_y, 2), .5);
}

void Vec2D::rotate(float angle_rads) {
  float s = sin(angle_rads);
  float c = cos(angle_rads);
  float x_new = m_x * c - m_y * s;
  float y_new = m_x * s + m_y * c;
  m_x = x_new;
  m_y = y_new;
}

float Vec2D::dot(const Vec2D& other) const {
  return m_x * other.m_x + m_y * other.m_y;
}

float Vec2D::cross_z(const Vec2D& other) const {
  return m_x * other.m_y - m_y * other.m_x;
}

float Vec2D::dist_sq(const Vec2D& other) const {
  return std::pow(m_x - other.m_x, 2) + std::pow(m_y - other.m_y, 2);
}

Vec2D operator-(const SDL_Point a, const SDL_Point b) {
  Vec2D ret_val;
  ret_val.m_x = a.x - b.x;
  ret_val.m_y = a.y - b.y;
  return ret_val;
}
