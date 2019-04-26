#pragma once

#include "Entity.hpp"
#include "Text.hpp"

#include <list>

class Menu : public Entity {
 private:
  std::list<Text> m_options;
  int m_index;

 public:
  Menu();
  ~Menu();
  void select();
  void update();
  void render(SDL_Renderer*);
};
