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
  struct JetpackCounts{
    unsigned int up;
    unsigned int down;
    unsigned int left;
    unsigned int right;
  };
  Vec2D m_pos;
  Vec2D m_vel;
  mutable float m_fuel;
  const float m_max_fuel;
  GrapplingHook *m_grappling_hook;
  SpriteSheet *m_sprsheet;
  SpriteSheet *m_jetpack_sprsheet;
  SDL_Rect m_bbox;
  Map *m_map;
  JetpackCounts m_jetpack_counts;

 public:
  Player(Vec2D pos, Vec2D vel, float fuel, SDL_Renderer *renderer, Map *map);
  ~Player();
  void render(SDL_Renderer *renderer) const;
  void update();
  Vec2D get_pos() const;
  Vec2D get_vel() const;
  void set_vel(Vec2D vel);
  void set_pos(Vec2D pos);
  void eject_mass(SDL_Point dir);
  GrapplingHook *getGrapplingHook();
  void jetpack(float dx, float dy, char dir);
  SDL_Rect get_bbox() const;
  SpriteSheet* get_sprite() const;
  void add_fuel(float) const;
  float *get_fuel();
  float get_max_fuel();
  bool stuck();
  // Sprite info
  static constexpr int WIDTH = 87;
  static constexpr int HEIGHT = 136;

  static constexpr float MASS_EJECTION_RATE = 10;
  static constexpr float MASS_EJECTION_VELOCITY = 10;
  static constexpr float MAX_VELOCITY = 25;
  static constexpr int JETPACK_FRAMES = 5;
  static constexpr int MAX_FUEL = 300;
};
