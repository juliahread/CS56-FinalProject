#include "MenuDown.hpp"

MenuDown::MenuDown(Menu *menu): m_menu(menu) {}

MenuDown::~MenuDown() {}

void MenuDown::execute(Player &player) {}

void MenuDown::execute() {
m_menu->menuDown();
}
