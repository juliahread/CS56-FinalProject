#pragma once

#include "SDLHelper.hpp"

class Camera {
 public:
  ~Camera();
  static Camera *get_instance();
  static Camera *get_instance(SDL_Point location, int screen_width,
                              int screen_height);
  void update_location(SDL_Point location);
  SDL_Point get_location();
  SDL_Point get_offset();
  int get_width();
  int get_height();

 private:
  Camera(SDL_Point location, int screen_width, int screen_height);
  static Camera *m_camera;
  SDL_Point m_location;
  int m_screen_width;
  int m_screen_height;
};
