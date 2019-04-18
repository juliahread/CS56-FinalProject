#pragma once
#include "Map.hpp"
#include "Obstacle.hpp"
#include "Obstacles.hpp"
#include "GrapplingPoints.hpp"
#include "GrapplingHook.hpp"

// Load obstacle segment
std::vector<Obstacle> Map::load_map(std::string str, int x, int y)
{
	std::vector<Obstacle> obstacles;
	obstacles.push_back(Obstacle({ 0, 1, 2, 3 }, SpriteSheet()));
	return obstacles;
}

// Load grappling points
std::vector<GrapplingPoint> Map::load_map(std::string str)
{
	std::vector<GrapplingPoint> grappling_hooks;
	grappling_hooks.push_back(GrapplingPoint());
	return grappling_hooks;
}

// Load start/end_points
std::vector<SDL_Point> Map::load_map()
{
	std::vector<SDL_Point> critical_points;
	critical_points.push_back({ 0, 0 });
	critical_points.push_back({ 10, 10 });
	obstacle_list = new Obstacles(load_map("file", 0, 10));
	grappling_point_list = new GrapplingPoints(load_map("file"));
	return critical_points;
}

Map::Map() { }

Map::~Map()
{
	delete obstacle_list;
	delete grappling_point_list;
}
