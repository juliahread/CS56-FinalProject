#pragma once

#include "SDLHelper.hpp"
#include "Text.hpp"
#include <list>

class LoseScreen {
public:
    LoseScreen();
    ~LoseScreen();
    void render(SDL_Renderer *renderer) const;
private:
    std::list<Text> m_lose_text;
    Text m_back;
};
