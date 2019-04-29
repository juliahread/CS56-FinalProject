#pragma once
#include "Command.hpp"
#include "Modes.hpp"
#include <iostream>

class MenuSelect : public Command {
private:
    int *m_game_mode;
    int *m_menu_mode;
public:
    MenuSelect(int *game_mode, int *menu_mode);
    ~MenuSelect();
    void execute(Player &player);
    void execute();
};
