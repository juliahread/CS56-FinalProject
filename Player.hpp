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
	SpriteSheet *m_sprsheet;
	SDL_Rect m_bbox;
  static constexpr float WIDTH = 10;
  static constexpr float HEIGHT = 10;
  static constexpr float MASS_EJECTION_RATE = 10;
  static constexpr float MASS_EJECTION_VELOCITY = 10;
public:
  Player(SDL_Point pos, SDL_Point vel, float fuel, SDL_Renderer *renderer);
  ~Player();
	void render(SDL_Renderer *renderer) const;
	void update();
  SDL_Point get_pos() const;
	SDL_Point get_vel() const;
	void eject_mass(SDL_Point dir);
};
