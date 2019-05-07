#pragma once

#include "SpriteSheet.hpp"
#include "Entity.hpp"

class Star : public Entity {
  public:
    Star(int x, int y, SDL_Renderer* renderer);
    Star() = default;
    Star(const Star& s);
    ~Star();
    void render(SDL_Renderer* renderer) const;
    void render(SDL_Renderer* renderer, int offx, int offy) const;
    void update();
    int getX() const;
    int getY() const;
    int getSpeed() const;
    bool getOut() const;
    int getMinf() const;
    int getMaxf() const;
    int getFnum() const;
    SDL_Renderer* getRenderer() const;
  private:
    SpriteSheet* m_sprite_sheet;
    SDL_Renderer* m_renderer;
    int m_frame_number;
    int m_x;
    int m_y;
    int m_wait;
    int m_speed;
    bool m_out;
    int m_min_frame;
    int m_max_frame;
};
