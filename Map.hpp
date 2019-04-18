#pragma once

#include "Obstacle.hpp"
#include "Obstacles.hpp"
#include "GrapplingPoint.hpp"
#include "GrapplingPoints.hpp"
#include <vector>
#include <string>

class Map {
private:
	SDL_Point start_location;
	SDL_Point end_location;
	Obstacles* obstacle_list;
	GrapplingPoints* grappling_point_list;
public:
	Map();
	~Map();
	void load_map();
};
