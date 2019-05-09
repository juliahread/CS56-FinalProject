#pragma once

#include "Command.hpp"

class Sound;

class InputHandler {
 public:
  InputHandler(Sound *sound);
  ~InputHandler();
  Command *handle_input(SDL_Event e);
  Command *m_game_left_click;
  Command *m_game_right_click;
  Command *m_game_w_button;
  Command *m_game_a_button;
  Command *m_game_s_button;
  Command *m_game_d_button;
};
