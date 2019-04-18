#pragma once
#include "SpriteSheet.hpp"
#include <SDL2/SDL.h>

class Obstacle
{
private:
	SDL_Rect m_bbox;
	SpriteSheet m_image;
public:
	Obstacle();
	Obstacle(SDL_Rect, SpriteSheet);
};
