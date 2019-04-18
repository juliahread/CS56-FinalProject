#pragma once

#include <SDL2/SDL.h>

class Command;

class EventHandler {
private:
  SDL_Event e;
  Command *m_game_left_click;
  Command *m_game_w_button;
  Command *m_game_a_button;
  Command *m_game_s_button;
  Command *m_game_d_button;
  Command *m_menu_w_button;
  Command *m_menu_s_button;
public:
  EventHandler();
  ~EventHandler();
  void poll();
};
