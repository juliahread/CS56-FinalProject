#pragma once
#include "Entity.hpp"
#include "SpriteSheet.hpp"

class GrapplingPoint : public Entity {
private:
	SDL_Point m_location;
	SDL_Rect m_bbox;
	SpriteSheet m_image;
public:
	GrapplingPoint();
	GrapplingPoint(SDL_Point, SDL_Rect, SpriteSheet);
};
