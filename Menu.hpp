#pragma once

#include "Entity.hpp"
#include "Text.hpp"
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
  void select();
  void render(SDL_Renderer *renderer) const;
  void update();
};
