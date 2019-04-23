#pragma once

#include "SDLHelper.hpp"
#include "Entity.hpp"
#include "GrapplingHook.hpp"
#include "SpriteSheet.hpp"
#include "Vec2D.hpp"

class Map;
class SpriteSheet;

class Player : public Entity {
 private:
  Vec2D m_pos;
  Vec2D m_vel;
  float m_fuel;
  GrapplingHook *m_grappling_hook;
  SpriteSheet *m_sprsheet;
  SDL_Rect m_bbox;
  Map *m_map;
  static constexpr float WIDTH = 171;
  static constexpr float HEIGHT = 213;
  static constexpr float MASS_EJECTION_RATE = 10;
  static constexpr float MASS_EJECTION_VELOCITY = 10;

 public:
  Player(Vec2D pos, Vec2D vel, float fuel, SDL_Renderer *renderer, Map *map);
  ~Player();
  void render(SDL_Renderer *renderer) const;
  void update();
  Vec2D get_pos() const;
  Vec2D get_vel() const;
  void set_vel(Vec2D vel);
  void eject_mass(SDL_Point dir);
  GrapplingHook *getGrapplingHook();
};
