#pragma once

#include "Depot.hpp"
#include "Fuel.hpp"
#include "GrapplingPoint.hpp"
#include "GrapplingPoints.hpp"
#include "Obstacle.hpp"
#include "Obstacles.hpp"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <random>
#include <ctime>

class Map {
 private:
  SDL_Point m_start;
  SDL_Point m_end;
  Obstacles* m_obstacle_list;
  GrapplingPoints* m_grappling_point_list;
  std::vector<Fuel> m_fuel_list;
  bool pixels_equal_tuple(std::tuple<Uint8, Uint8, Uint8>&, Uint8&, Uint8&,
                          Uint8&);
  std::mt19937 m_twister;
  std::uniform_int_distribution<int> rand_range;  // Random number generator for fuel generation

 public:
  Map();
  ~Map();
  void load_map(std::string, SDL_Renderer* renderer);
  Obstacles* get_obstacle_list();
  GrapplingPoints* get_grappling_point_list();
  void update_depots_and_fuel(SDL_Renderer* renderer);
  void render_fuel(SDL_Renderer* renderer);
  SDL_Point* get_start();
  SDL_Point* get_end();
};
