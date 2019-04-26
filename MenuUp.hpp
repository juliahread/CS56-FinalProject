#pragma once
#include "Command.hpp"

class MenuUp : public Command {
public:
    void execute(Player &player);
    void execute();
    ~MenuUp();
}
