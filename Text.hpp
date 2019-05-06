#pragma once

#include "SDLHelper.hpp"
#include <string>
#include "Entity.hpp"

class Text : public Entity {
public:
    Text(std::string text, int font_size, SDL_Point pos);
    Text(std::string text, int font_size, SDL_Point pos, SDL_Color color);
    ~Text();
    void loadFont(int font_size);
    void render(SDL_Renderer *renderer) const;
    void update();
    void setPos(SDL_Point pos);
private:
    std::string m_text;
    SDL_Color m_color;
    SDL_Point m_pos;
    TTF_Font *m_font;
    SDL_Renderer *m_renderer;
};
