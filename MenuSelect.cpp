#include "MenuSelect.hpp"

MenuSelect::MenuSelect(int *game_mode, Menu *menu, Timer *timer) :
                       m_menu(menu), m_game_mode(game_mode), m_timer(timer) {}

MenuSelect::~MenuSelect() {}

void MenuSelect::execute(Player &player) {}

void MenuSelect::execute() {
  switch(m_menu->get_mode()){
  case 0:
    *m_game_mode = game_modes::GAMEPLAY;
    m_timer->start();
    break;
  case 1:
    *m_game_mode = game_modes::CONTROLS;
    break;
  case 2:
    *m_game_mode = game_modes::HIGHSCORES;
    break;
  }
}
