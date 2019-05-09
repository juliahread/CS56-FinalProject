#pragma once

#include "Command.hpp"
#include "Menu.hpp"

class MenuDown : public Command {
 private:
  Menu *m_menu;

 public:
  MenuDown(Menu *menu);
  ~MenuDown();
  void execute(Player &player);
  void execute();
};
