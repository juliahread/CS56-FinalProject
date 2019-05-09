#include "FuelDisplay.hpp"

FuelDisplay::FuelDisplay(float *player_fuel, int max_fuel)
    : m_player_fuel(player_fuel),
      m_max_fuel(max_fuel),
      m_label(Text("Fuel:", 50, {25, 20})),
      m_fuel_bg({200, 20, 220, 50}),
      m_fuel_remaining({210, 30, 200, 30}) {
  m_fuel_width = m_fuel_remaining.w;
}

FuelDisplay::~FuelDisplay() {}

void FuelDisplay::render(SDL_Renderer *renderer) const {
  // render fuel label
  m_label.render(renderer);

  // render fuel bar
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &m_fuel_bg);

  // render fuel remaining bar
  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(renderer, &m_fuel_remaining);
}

void FuelDisplay::update() {
  float width = *m_player_fuel / m_max_fuel * m_fuel_width;
  m_fuel_remaining.w = (int)width;
}
