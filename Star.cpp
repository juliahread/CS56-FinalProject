#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Star.hpp"
#include <string>

Star::Star(int x, int y, SDL_Renderer* renderer) : m_x(x), m_y(y), m_wait(0) {
  m_speed = rand() % 3 + 10;
  if (rand() % 2) {
    m_out = true;
  }
  if (rand() % 2) {
    m_min_frame = 0;
    m_max_frame = 2;
    m_frame_number = rand() % 3;
    printf("%d %d\n", m_min_frame, m_frame_number);
  }
  else {
    m_min_frame = 3;
    m_max_frame = 5;
    m_frame_number = rand() % 3 + 3;
    printf("%d %d\n", m_min_frame, m_frame_number);
  }
  m_sprite_sheet = new SpriteSheet("images/starSprites.png", renderer, 6);
}

Star::~Star() {
  delete m_sprite_sheet;
}

void Star::render(SDL_Renderer* renderer) const {
  m_sprite_sheet->renderSprite(m_x, m_y, renderer, m_frame_number);
}

void Star::update() {
  if (m_wait == m_speed) {
    if (m_out) {
      if (m_frame_number < m_max_frame) {
        m_frame_number++;
        m_wait = 0;
      }
      if (m_frame_number == m_max_frame) {
        m_out = false;
      }
    }
    else {
      if (m_frame_number > m_min_frame) {
        m_frame_number--;
        m_wait = 0;
      }
      if (m_frame_number == m_min_frame) {
        m_out = true;
      }
    }
  }
  else {
    m_wait++;
  }
}
