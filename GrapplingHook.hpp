#pragma once

#include "SDLHelper.hpp"
#include "Entity.hpp"
#include <vector>

// Forward declarations
class SpriteSheet;
class Player;
class Map;

class GrapplingHook : public Entity {
	private:
    bool m_fired;
		const SDL_Point *m_anchor;
		std::vector<SDL_Point> m_wrap_points;
		SDL_Rect *m_bbox;
		SpriteSheet *m_image;
    Player *m_shooter;
    Map * m_map;
	public:
    GrapplingHook(Player *shooter, Map *map);
		void shoot(SDL_Point anchor);
		void detatch();
    void render(SDL_Renderer *renderer) const;
    void update();
};
