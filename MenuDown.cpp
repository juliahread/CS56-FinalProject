#include "MenuDown.hpp"

MenuDown::MenuDown(int *menu_mode) {
    m_menu_mode = menu_mode;
}

MenuDown::~MenuDown() {}

void MenuDown::execute(Player &player) {}

void MenuDown::execute() {
    *m_menu_mode = menu_modes::CONTROLS;
}
