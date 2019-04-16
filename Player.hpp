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
  static const float WIDTH;
  static const float HEIGHT;
  static const float MASS_EJECTION_RATE;
  static const float MASS_EJECTION_VELOCITY;
public:
  Player(SDL_Point pos, SDL_Point vel, float fuel);
  ~Player();
	void render(SDL_Renderer *renderer);
	void update();
  SDL_Point get_pos();
	SDL_Point get_vel();
	void eject_mass(SDL_Point dir);
};
