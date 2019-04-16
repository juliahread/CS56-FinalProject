#pragma once

#include <SDL2/SDL.h>
#include <list>
#include "Obstacles.hpp"
#include "GrapplingPoints.hpp"

class Map {
  private:
    Obstacles *m_obstacles;
    GrapplingPoints *m_grappling_points;
    SDL_Point m_start_location;
    SDL_Point m_end_location;
  public:
    void load_map(std::string);
}
