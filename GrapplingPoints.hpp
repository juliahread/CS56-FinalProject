#pragma once
#include <SDL2/SDL.h>

#include "Entity.hpp"
#include "SpriteSheet.hpp"
#include <list>

class GrapplingPoints : public Entity {
	private:
  std::list<GrapplingPoints> m_grappling_points;
	public:
		GrapplingPoints();
    void addPoint(SDL_Point loc); // initialize location
    void render(SDL_Renderer *renderer);
    void update();
    struct GrapplingPoint{
      SDL_Point m_location;
      SDL_Rect m_bbox;
      SpriteSheet *m_image;
    };
};

