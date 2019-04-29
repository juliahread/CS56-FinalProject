#include "MenuSelect.hpp"

MenuSelect::MenuSelect(int *game_mode, int *menu_mode) {
    m_game_mode = game_mode;
    m_menu_mode = menu_mode;
}

MenuSelect::~MenuSelect() {}

void MenuSelect::execute(Player &player) {}

void MenuSelect::execute() {
    if (*m_menu_mode == (int) menu_modes::PLAY) {
        *m_game_mode = (int) game_modes::GAMEPLAY;
    } else if (*m_menu_mode == (int) menu_modes::CONTROLS) {
        *m_game_mode = (int) game_modes::CONTROLS;
    }
}
