#pragma once

#include <list>
#include "SDLHelper.hpp"
#include "Text.hpp"

class FuelDisplay : public Entity {
 private:
  Text m_label;
  float *m_player_fuel;
  int m_max_fuel;
  SDL_Rect m_fuel_bg;
  SDL_Rect m_fuel_remaining;
  int m_fuel_width;

 public:
  FuelDisplay(float *player_fuel, int max_fuel);
  ~FuelDisplay();
  void render(SDL_Renderer *renderer) const;
  void update();
};
