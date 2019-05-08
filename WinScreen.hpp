#pragma once
#ifndef _WIN32
#include <SDL2/SDL.h>
#else
#include "SDL.h"
#endif
#include "Text.hpp"
#include <string>
#include <list>

class Scores;
class Timer;

class WinScreen {
public:
  WinScreen(Scores *score, Timer *timer, int &mode);
  ~WinScreen();
  void handle_input(SDL_Event e);
  void render(SDL_Renderer *renderer) const;
private:
  Scores *m_score;
  Timer *m_timer;
  int &m_mode;
  std::string m_name;
  std::list<Text> m_win_text;
  Text m_enter_name;
  bool m_entered_invalid;
};
