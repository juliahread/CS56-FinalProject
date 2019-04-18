#pragma once

#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

class Obstacle
{
private:
	SDL_Rect m_bbox;
	SpriteSheet m_sprite;
public:
	Obstacle();
	Obstacle(SDL_Rect, SpriteSheet);
};
