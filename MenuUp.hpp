#pragma once

#include "Command.hpp"
#include "Modes.hpp"

class MenuUp : public Command {
private:
    int *m_menu_mode;
public:
    MenuUp(int *menu_mode);
    ~MenuUp();
    void execute(Player &player);
    void execute();
};
