#include "Text.hpp"

Text::Text(std::string text, SDL_Color color, SDL_Point pos, SDL_Renderer *renderer) {
    m_text = text;
    m_color = color;
    m_pos = pos;
    m_renderer = renderer;
}

Text::~Text() {
}

void Text::loadFont(int fontSize) {
    m_font = TTF_OpenFont("ttf/LCD_Solid.ttf", fontSize);
    if (m_font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
    }
}

void Text::render(SDL_Renderer* renderer) const {
    SDL_Texture *texture;
    // render text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(m_font, m_text.c_str(), m_color);
    if (textSurface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        // create texture from surface
        texture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
        if (texture == NULL) {
            printf("Unable to create texture from renered text! SDL_ttf Error: %s\n", SDL_GetError());
        }
    }

    SDL_Rect textRect;
    textRect.x = m_pos.x;
    textRect.y = m_pos.y;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    // render to screen
    SDL_RenderCopy(renderer, texture, NULL, &textRect);

    // get rid of old surface
    SDL_FreeSurface(textSurface);
}

void Text::update() {
}
