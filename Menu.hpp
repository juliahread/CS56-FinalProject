#pragma once

#include "Entity.hpp"
#include "Text.hpp"
#include "SDLHelper.hpp"
#include "Modes.hpp"

// forward declaration
#include "Background.hpp"

#include <vector>

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
  void render(SDL_Renderer* renderer) const;
  void menuUp();
  void menuDown();
};
