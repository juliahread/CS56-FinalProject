#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "Entity.hpp"
#include "GrapplingPoints.hpp"
#include "SpriteSheet.hpp"
#include "Player.hpp"

class GrapplingHook : public Entity {
	private:
    bool m_fired;
		SDL_Point *m_anchor;
		std::vector<SDL_Point> m_wrap_points;
		SDL_Rect *m_bbox;
		SpriteSheet m_image;
    Player *m_shooter;
	public:
  GrapplingHook(Player *shooter);
		void shoot(SDL_Point *anchor);
		void detatch();
    void render(SDL_Renderer *renderer);
    void update();
};
