#include "MenuUp.hpp"

MenuUp::MenuUp(Menu *menu): m_menu(menu) {}

MenuUp::~MenuUp() {}

void MenuUp::execute(Player &player) {}

void MenuUp::execute() {
  m_menu->menuUp();
}
