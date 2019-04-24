#pragma once

#include "SDLHelper.hpp"
#include <vector>
#include "Entity.hpp"
#include "Vec2D.hpp"

// Forward declarations
class SpriteSheet;
class Player;
class Map;
enum Spin { None, CW, CCW };

class GrapplingHook : public Entity {
 private:
  bool m_fired;
  Spin m_spin;
  float m_distance_sq;
  const SDL_Point *m_anchor;
  std::vector<SDL_Point> m_wrap_points;
  SDL_Rect *m_bbox;
  SpriteSheet *m_image;
  Player *m_shooter;
  Map *m_map;
  float dist_sq_from_last_anchor() const;

 public:
  GrapplingHook(Player *shooter, Map *map);
  void shoot(SDL_Point anchor);
  void detach();
  void render(SDL_Renderer *renderer) const;
  void update();
  bool check_fired() const;
  bool is_spinning() const;
  Spin get_spin() const;
  void set_spin(Spin spin);
  const SDL_Point *get_anchor() const;
  const SDL_Point *get_last_anchor() const;
  float dist_from_last_anchor() const;
  void update_player_loc(Vec2D &player_loc);
  void update_player_vel();
};
