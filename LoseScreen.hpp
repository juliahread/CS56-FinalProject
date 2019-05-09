#pragma once

#include <list>
#include "SDLHelper.hpp"
#include "Text.hpp"

class LoseScreen {
 public:
  LoseScreen();
  ~LoseScreen();
  void render(SDL_Renderer *renderer) const;

 private:
  std::list<Text> m_lose_text;
  Text m_back;
};
