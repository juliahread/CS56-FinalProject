#pragma once

#include "Entity.hpp"
#include "SpriteSheet.hpp"
#include "Star.hpp"

#include <vector>

class Background : public Entity {
 public:
  Background(int type, SDL_Renderer* renderer);
  ~Background();
  void render(SDL_Renderer *renderer) const;
  void update();

 private:
  SpriteSheet* m_sprite_sheet;
  std::vector<Star> m_stars;
};
