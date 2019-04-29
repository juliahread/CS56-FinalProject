#pragma once

#include "Entity.hpp"
#include "Text.hpp"
#include "SDLHelper.hpp"
#include "Modes.hpp"
// #include "MenuInputHandler.hpp"

#include <list>

class Menu : public Entity {
private:
    std::list<Text> m_title;
    std::list<Text> m_play;
    std::list<Text> m_controls;
    int m_mode;
    int m_index;

 public:
  Menu();
  ~Menu();
  int *get_mode();
  void set_mode(int mode);
  void update();
  void render(SDL_Renderer*) const;
};
