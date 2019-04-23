#pragma once

#include "Command.hpp"

class InputHandler {
 private:
  Command *m_game_left_click;
  Command *m_game_right_click;
  Command *m_game_w_button;
  Command *m_game_a_button;
  Command *m_game_s_button;
  Command *m_game_d_button;
  Command *m_menu_w_button;
  Command *m_menu_s_button;

 public:
  InputHandler();
  ~InputHandler();
  Command *handle_input(SDL_Event e, bool game);
};
