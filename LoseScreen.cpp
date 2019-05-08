#include "LoseScreen.hpp"

LoseScreen::LoseScreen() : m_back(Text("Press A to return to the menu...",  24, {780, 665})) {
    m_lose_text.push_back(Text("YOU LOSE :(", 100, {375, 40}));
    m_lose_text.push_back(Text("You weren't able to make it to the CampSec", 42, {100, 200}));
    m_lose_text.push_back(Text("vehicle, and now you are lost in the void of", 42, {75, 250}));
    m_lose_text.push_back(Text("space...", 42, {300, 300}));
}

LoseScreen::~LoseScreen() {}

void LoseScreen::render(SDL_Renderer *renderer) const {
    m_back.render(renderer);
    for (auto text : m_lose_text) {
        text.render(renderer);
    }
}
