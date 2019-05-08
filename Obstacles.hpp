#pragma once

#include "Fuel.hpp"
#include "Depot.hpp"
#include "Entity.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "EndObject.hpp"
#include <vector>
#include <random>
#include <ctime>

class Obstacles : public Entity {
 private:
  std::vector<Obstacle> m_obstacles;
  std::vector<Depot> m_depots;
  std::vector<Fuel> m_fuel;
  std::vector<EndObject> m_end;
  std::mt19937 m_twister; // Random number generator for fuel generation
  std::uniform_int_distribution<int> rand_range;


 public:
  Obstacles();
  Obstacles(std::vector<Obstacle>);
  Obstacles(std::vector<Obstacle>, std::vector<Depot>, std::vector<EndObject>);
  ~Obstacles();
  void render(SDL_Renderer*) const;
  void update();
  void update(const Player&, SDL_Renderer*, int, int); // Update fuel and depots
  bool detectCollisions(const Player&);
  SDL_Point* intersectLine(SDL_Point lineStart, SDL_Point lineEnd);
  bool SDL_TransparentPixel(SDL_Surface*, int, int);
  bool SDL_Collide(SDL_Surface*, int, int, SDL_Surface*, int, int);
  const std::vector<EndObject>& getEnd();
};
