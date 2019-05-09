#pragma once

#include <vector>
#include "Background.hpp"
#include "Entity.hpp"
#include "Modes.hpp"
#include "SDLHelper.hpp"
#include "Text.hpp"

class Menu : public Entity {
 private:
  std::vector<Text> m_title;
  std::vector<Text> m_text_list;
  Text m_carrot;
  unsigned int m_selected_idx;
  Background *m_menubg;

 public:
  Menu(Background *menubg);
  ~Menu();
  int get_mode() const;
  void update();
  void render(SDL_Renderer *renderer) const;
  void menuUp();
  void menuDown();
};
