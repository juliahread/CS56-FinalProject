#include "Background.hpp"

Background::Background(int type, SDL_Renderer* renderer) {
  // menu
  if (type == 0) {
    m_sprite_sheet = new SpriteSheet("images/menu.png", renderer, 1);
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
}

void Background::update() {

}
