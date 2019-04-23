#pragma once

#include "Obstacle.hpp"
#include "Obstacles.hpp"
#include "GrapplingPoint.hpp"
#include "GrapplingPoints.hpp"
#include <vector>
#include <string>
#include <tuple>
#include <iostream>

class Map {
private:
	SDL_Point start_location;
	SDL_Point end_location;
	Obstacles* m_obstacle_list;
	GrapplingPoints* m_grappling_point_list;
	bool pixels_equal_tuple(std::tuple<Uint8, Uint8, Uint8>&, Uint8&, Uint8&, Uint8&);
public:
	Map();
	~Map();
	void load_map(std::string, SDL_Renderer* renderer);
	Obstacles* get_obstacle_list();
	GrapplingPoints* get_grappling_point_list();
};
