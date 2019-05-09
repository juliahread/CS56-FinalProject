#pragma once

#include "Command.hpp"
#include "Modes.hpp"
// forward declaration
#include "Menu.hpp"
#include "Timer.hpp"

class MenuInputHandler {
 private:
  Command *m_menu_w_button;
  Command *m_menu_s_button;
  Command *m_menu_enter_button;

 public:
  MenuInputHandler(int *game_mode, Menu *menu, Timer *timer);
  ~MenuInputHandler();
  Command *handle_input(SDL_Event e);
};
