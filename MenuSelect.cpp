#include "MenuSelect.hpp"
#include "Menu.hpp"
#include "Modes.hpp"

MenuSelect::MenuSelect(int *game_mode, Menu* menu) : m_menu(menu), m_game_mode(game_mode){}

MenuSelect::~MenuSelect() {}

void MenuSelect::execute(Player &player) {}

void MenuSelect::execute() {
  switch(m_menu->get_mode()){
  case 0:
    *m_game_mode = game_modes::GAMEPLAY;
    break;
  case 1:
    *m_game_mode = game_modes::CONTROLS;
    break;
  case 2:
    *m_game_mode = game_modes::HIGHSCORES;
    break;
  }
}
