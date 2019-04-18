#pragma once
#include "Map.hpp"

void Map::load_map()
{
	
}

Map::Map() { }

Map::~Map()
{
	delete obstacle_list;
	delete grappling_point_list;
}
