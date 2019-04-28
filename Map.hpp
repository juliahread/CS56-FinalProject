#pragma once

#include "GrapplingPoint.hpp"
#include "GrapplingPoints.hpp"
#include "Obstacle.hpp"
#include "Obstacles.hpp"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

class Map {
 private:
  SDL_Point m_start;
  SDL_Point m_end;
  Obstacles* m_obstacle_list;
  GrapplingPoints* m_grappling_point_list;
  bool pixels_equal_tuple(std::tuple<Uint8, Uint8, Uint8>&, Uint8&, Uint8&, Uint8&);

 public:
  Map();
  ~Map();
  void load_map(std::string, SDL_Renderer* renderer);
  Obstacles* get_obstacle_list();
  GrapplingPoints* get_grappling_point_list();
  SDL_Point* get_start();
  SDL_Point* get_end();
};
