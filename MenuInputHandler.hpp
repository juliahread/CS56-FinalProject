#pragma once
#include "Command.hpp"
#include "SDLHelper.hpp"

class MenuInputHandler {
 private:
  Command *m_menu_w_button;
  Command *m_menu_s_button;
  Command *m_menu_enter_button;

 public:
  MenuInputHandler();
  ~MenuInputHandler();
  Command *handle_input(SDL_Event e, bool game);
};
