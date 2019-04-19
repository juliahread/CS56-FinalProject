#pragma once

#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"

class Obstacle
{
private:
	SDL_Rect m_bbox;
	SpriteSheet* m_sprite;
public:
	Obstacle();
	Obstacle(std::string, SDL_Rect, SDL_Renderer*);
	SDL_Rect get_bbox() const;
	SpriteSheet* get_sprite() const;
};
