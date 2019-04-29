#include "MenuUp.hpp"

MenuUp::MenuUp(int *menu_mode) {
    m_menu_mode = menu_mode;
}

MenuUp::~MenuUp() {}

void MenuUp::execute(Player &player) {}

void MenuUp::execute() {
    *m_menu_mode = menu_modes::PLAY;
}
