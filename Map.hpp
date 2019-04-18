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
	std::vector<Obstacle> load_map(std::string, int, int);
	std::vector<GrapplingPoint> load_map(std::string);
	std::vector<SDL_Point> load_map();
};
