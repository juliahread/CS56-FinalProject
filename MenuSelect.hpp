#pragma once

#include "Command.hpp"
#include "Menu.hpp"
#include "Modes.hpp"
#include "Timer.hpp"

class MenuSelect : public Command {
 private:
  Menu *m_menu;
  int *m_game_mode;
  Timer *m_timer;

 public:
  MenuSelect(int *game_mode, Menu *menu, Timer *timer);
  ~MenuSelect();
  void execute(Player &player);
  void execute();
};
