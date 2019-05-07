#include "FuelDisplay.hpp"

FuelDisplay::FuelDisplay(float *player_fuel, int max_fuel) {
    m_player_fuel = player_fuel;
    m_max_fuel = max_fuel;

    // make the fuel label
    SDL_Point label_pos = {25, 20};
    Text text("Fuel:", 50, label_pos);
    m_label = text;

    // make the fuel bar
    m_fuel_bar = {200, 20, 220, 50};

    // make the fuel remaining bar
    m_fuel_remaining = {210, 30, 200, 30};

}

FuelDisplay::~FuelDisplay() {}

void FuelDisplay::render(SDL_Renderer *renderer) const {
    // render fuel label
    m_label.render(renderer);

    // render fuel bar
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &m_fuel_bar);

    // render fuel remaining bar
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &m_fuel_remaining);
}

void FuelDisplay::update() {
    float width = *m_player_fuel / m_max_fuel * 200;
    m_fuel_remaining = {210, 30, (int)width, 30};
}
