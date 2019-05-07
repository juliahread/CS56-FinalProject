#include "SDLHelper.hpp"
#include "Star.hpp"
#include <string>

Star::Star(int x, int y, SDL_Renderer* renderer) : m_x(x), m_y(y), m_wait(0) {
  m_renderer = renderer;
  m_speed = rand() % 3 + 8;
  if (rand() % 2) {
    m_out = true;
  }
  if (rand() % 2) {
    m_min_frame = 0;
    m_max_frame = 2;
    m_frame_number = rand() % 3;
  }
  else {
    m_min_frame = 3;
    m_max_frame = 5;
    m_frame_number = rand() % 3 + 3;
  }
  m_sprite_sheet = new SpriteSheet("images/starSprites.png", renderer, 6, 0);
}

Star::Star(const Star& s) : m_wait(0) {
  m_renderer = s.getRenderer();
  m_sprite_sheet = new SpriteSheet("images/starSprites.png", m_renderer, 6, 0);
  m_x = s.getX();
  m_y = s.getY();
  m_speed = s.getSpeed();
  m_out = s.getOut();
  m_min_frame = s.getMinf();
  m_max_frame = s.getMaxf();
  m_frame_number = s.getFnum();
}

Star::~Star() {
  delete m_sprite_sheet;
}

void Star::render(SDL_Renderer* renderer) const {
  m_sprite_sheet->renderSpriteWithoutCamera(m_x, m_y, renderer, m_frame_number);
}

void Star::update() {
  if (m_wait == m_speed) {
    if (m_out) {
      if (m_frame_number == m_max_frame) {
        m_out = false;
      }
      if (m_frame_number < m_max_frame) {
        m_frame_number++;
      }
    }
    else {
      if (m_frame_number == m_min_frame) {
        m_out = true;
      }
      if (m_frame_number > m_min_frame) {
        m_frame_number--;
      }
    }
    m_wait = 0;
  }
  else {
    m_wait++;
  }
}

int Star::getX() const { return m_x; }
int Star::getY() const { return m_y; }
int Star::getSpeed() const { return m_speed; }
bool Star::getOut() const { return m_out; }
int Star::getMinf() const { return m_min_frame; }
int Star::getMaxf() const { return m_max_frame; }
int Star::getFnum() const { return m_frame_number; }
SDL_Renderer* Star::getRenderer() const { return m_renderer; }
