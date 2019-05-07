#pragma once

#include "SDLHelper.hpp"
#include "Text.hpp"
#include <list>

class FuelDisplay : public Entity {
private:
    Text m_label;
    float *m_player_fuel;
    int m_max_fuel;
    SDL_Rect m_fuel_bar;
    SDL_Rect m_fuel_remaining;
    SDL_Rect m_fuel_used;

public:
    FuelDisplay(float *player_fuel, int max_fuel);
    ~FuelDisplay();
    void render(SDL_Renderer *renderer) const;
    void update();
};
