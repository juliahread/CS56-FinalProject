#pragma once

#include "SDLHelper.hpp"
#include <string>
#include "Entity.hpp"

class Text : public Entity {
public:
    Text(std::string text, int fontSize, SDL_Color color, SDL_Point pos);
    ~Text();
    void loadFont(int fontSize);
    void render(SDL_Renderer *renderer) const;
    void update();
private:
    std::string m_text;
    SDL_Color m_color;
    SDL_Point m_pos;
    TTF_Font *m_font;
    SDL_Renderer *m_renderer;
};
