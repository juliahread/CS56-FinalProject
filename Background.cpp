#include "Background.hpp"
#include "Star.hpp"
#include "Modes.hpp"

Background::Background(int type, SDL_Renderer* renderer, Camera* cam) : m_stars() {
  m_gp = false;
  m_cam = cam;
  // menu
  if (type == game_modes::MENU) {
    m_sprite_sheet = new SpriteSheet("images/menu.png", renderer, 1, 0);
    m_stars.push_back(Star(50, 50, renderer));
    m_stars.push_back(Star(150, 300, renderer));
    m_stars.push_back(Star(300, 620, renderer));
    m_stars.push_back(Star(900, 75, renderer));
    m_stars.push_back(Star(1150, 570, renderer));
    m_stars.push_back(Star(1200, 20, renderer));
  }
  // controls
  else if (type == game_modes::CONTROLS) {
    m_sprite_sheet = new SpriteSheet("images/gameplay.png", renderer, 1, 0);
  }
  // gameplay
  else if (type == game_modes::GAMEPLAY) {
    m_sprite_sheet = new SpriteSheet("images/gameplayBig.png", renderer, 1, 0);
    for (int i = 0; i < 10; i++) {
      int x = rand() % 1500;
      int y = rand() % 844;
      m_stars.push_back(Star(x, y, renderer));
    }
    m_gp = true;
  }
  // endgame
  else if (type == game_modes::WIN) {
    m_sprite_sheet = new SpriteSheet("images/menu.png", renderer, 1, 0);
  }
}

Background::~Background() {
  delete m_sprite_sheet;
}

void Background::render(SDL_Renderer *renderer) const {
  if (m_gp) {
    SDL_Point offset = m_cam->get_offset();
    m_sprite_sheet->renderSpriteWithoutCamera(-110 - offset.x / 50,
                                              -62 - offset.y / 50, renderer, 0);
    for (auto const& star : m_stars) {
      star.render(renderer, offset.x / 30, offset.y / 30);
    }
  }
  else {
    m_sprite_sheet->renderSpriteWithoutCamera(0, 0, renderer, 0);
    for (auto const& star : m_stars) {
      star.render(renderer, 0, 0);
    }
  }
}

void Background::update() {
  for (auto &star : m_stars) {
    star.update();
  }
}
