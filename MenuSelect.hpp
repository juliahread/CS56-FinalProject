#pragma once

#include "Command.hpp"
#include "Menu.hpp"

class MenuSelect : public Command {
private:
  Menu *m_menu;
    int *m_game_mode;
public:
    MenuSelect(int *game_mode, Menu *menu);
    ~MenuSelect();
    void execute(Player &player);
    void execute();
};
