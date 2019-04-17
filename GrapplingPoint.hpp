#pragma once
#include "GrapplingHook.hpp"

class GrapplingPoint : public Entity {
	SDL_Point m_location;
	SDL_Rect m_bbox;
	SpriteSheet* m_image;
};
