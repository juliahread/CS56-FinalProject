#pragma once

#include "Map.hpp"
#include "Player.hpp"

class MiniMap {
 private:
  Map* m_map;
  Player* m_player;
  SDL_Texture* point_texture;
  SDL_Texture* end_texture;
  SDL_Texture* obstacle_texture;
  SDL_Texture* player_texture;

 public:
  MiniMap(Map* map, Player* player);
  ~MiniMap();
  void init(SDL_Renderer*);
  void renderMiniMap(SDL_Renderer*);
  void update();
};
