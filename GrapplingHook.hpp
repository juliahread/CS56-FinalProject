#pragma once

#include "SDLHelper.hpp"
#include <vector>
#include "Entity.hpp"
#include "Vec2D.hpp"

// Forward declarations
class SpriteSheet;
class Player;
class Map;
enum Spin {None, CW, CCW };

class GrapplingHook : public Entity {
 private:
  struct Wrap{
    SDL_Point point;
    Spin wrap_dir;
  };
  bool m_fired;
  Spin m_spin;
  bool m_was_spinning;
  float m_distance_sq;
  std::vector<Wrap> m_wrap_points;
  SpriteSheet *m_sprsheet;
  Player *m_shooter;
  Map *m_map;
  float dist_sq_from_last_anchor() const;
  void update_player_loc();
  void update_player_vel();

 public:
  GrapplingHook(Player *shooter, Map *map, SDL_Renderer *renderer);
  void shoot(SDL_Point anchor);
  void detach();
  void render(SDL_Renderer *renderer) const;
  void update();
  bool check_fired() const;
  bool is_spinning() const;
  Spin get_spin() const;
  void set_spin(Spin spin);
  void set_was_spinning(bool was_spinning);
  const SDL_Point *get_last_anchor() const;
  float dist_from_last_anchor() const;
  void update_player();
};
