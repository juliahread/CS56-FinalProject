#pragma once

#include "Command.hpp"
#include "Menu.hpp"

class MenuUp : public Command {
 private:
  Menu *m_menu;

 public:
  MenuUp(Menu *menu);
  ~MenuUp();
  void execute(Player &player);
  void execute();
};
