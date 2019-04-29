#pragma once

#include "Command.hpp"
#include "Modes.hpp"

class MenuDown : public Command {
private:
    int *m_menu_mode;
public:
    MenuDown(int *menu_mode);
    ~MenuDown();
    void execute(Player &player);
    void execute();
};
