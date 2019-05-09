#pragma once

#include "Camera.hpp"
#include "Entity.hpp"
#include "SpriteSheet.hpp"
#include "Star.hpp"

#include <vector>

class Background : public Entity {
 public:
  Background(int type, SDL_Renderer* renderer, Camera* cam);
  ~Background();
  void render(SDL_Renderer* renderer) const;
  void update();

 private:
  SpriteSheet* m_sprite_sheet;
  std::vector<Star> m_stars;
  bool m_gp;
  Camera* m_cam;
};
