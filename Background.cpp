#include "Background.hpp"
#include "Star.hpp"

Background::Background(int type, SDL_Renderer* renderer) : m_stars() {
  // menu
  if (type == 0) {
    m_sprite_sheet = new SpriteSheet("images/menu.png", renderer, 1);
    m_stars.push_back(Star(50, 50, renderer));
    m_stars.push_back(Star(150, 300, renderer));
    m_stars.push_back(Star(300, 620, renderer));
    m_stars.push_back(Star(900, 75, renderer));
    m_stars.push_back(Star(700, 400, renderer));
    m_stars.push_back(Star(1150, 570, renderer));
    m_stars.push_back(Star(1200, 20, renderer));
  }
  // controls
  else if (type == 1) {
    m_sprite_sheet = new SpriteSheet("images/gameplay.png", renderer, 1);
  }
  // gameplay
  else if (type == 2) {
    m_sprite_sheet = new SpriteSheet("images/gameplay.png", renderer, 1);
  }
  // endgame
  else if (type == 3) {
    m_sprite_sheet = new SpriteSheet("images/menu.png", renderer, 1);
  }
}

Background::~Background() {
  delete m_sprite_sheet;
}

void Background::render(SDL_Renderer *renderer) const {
  m_sprite_sheet->renderSprite(0, 0, renderer, 0);
  for (auto const& star : m_stars) {
    star.render(renderer);
  }
}

void Background::update() {
  for (auto &star : m_stars) {
    star.update();
  }
}
