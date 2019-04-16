#pragma once

#include <SDL2/SDL.h>
#include "SpriteSheet.hpp"
#include "Entity.hpp"

class GrapplingHook;

class Player : public Entity {
private:
  SDL_Point m_pos;
  SDL_Point m_vel;
  float m_fuel;
	GrapplingHook *m_grappling_hook;
	SpriteSheet m_sprsheet;
	SDL_Rect m_bbox;
public:
  Player(SDL_Point pos, SDL_Point vel, float fuel);
  ~Player();
	void render(SDL_Renderer *renderer);
	void update();
	SDL_Point get_velocity();
	void eject_mass();
};
