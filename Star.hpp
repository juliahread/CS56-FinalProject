#pragma once

#include "SpriteSheet.hpp"
#include "Entity.hpp"

class Star : public Entity {
  public:
    Star(int x, int y, SDL_Renderer* renderer);
    ~Star();
    void render(SDL_Renderer* renderer) const;
    void update();
  private:
    SpriteSheet *m_sprite_sheet;
    int m_frame_number;
    int m_x;
    int m_y;
    int m_wait;
    int m_speed;
    bool m_out;
    int m_min_frame;
    int m_max_frame;
};
