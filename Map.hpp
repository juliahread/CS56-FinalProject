#pragma once

#include "Depot.hpp"
#include "Fuel.hpp"
#include "GrapplingPoint.hpp"
#include "GrapplingPoints.hpp"
#include "Obstacle.hpp"
#include "Obstacles.hpp"
#include "EndObject.hpp"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

class Map {
 private:
  SDL_Point m_start;
  Obstacles* m_obstacle_list;
  GrapplingPoints* m_grappling_point_list;
  bool pixels_equal_tuple(std::tuple<Uint8, Uint8, Uint8>&, Uint8&, Uint8&,
                          Uint8&);

 public:
  Map();
  ~Map();
  void load_map(std::string, SDL_Renderer* renderer);
  Obstacles* get_obstacle_list();
  GrapplingPoints* get_grappling_point_list();
  SDL_Point* get_start();
  int map_height;
  int map_width;
  static constexpr int MAP_RATIO = 90; // Number of screen pixels per map pixel
  // Minimap
  void initMinimap(SDL_Renderer*);
  void renderMinimap(SDL_Renderer*);
  SDL_Texture* point_texture;
  SDL_Texture* end_texture;
  SDL_Texture* obstacle_texture;
};
