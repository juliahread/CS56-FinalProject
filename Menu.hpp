#pragma once

#include "Entity.hpp"
#include "Text.hpp"
#include "SDLHelper.hpp"
#include "Modes.hpp"

// forward declaration
#include "Background.hpp"

#include <list>

class Menu : public Entity {
private:
    std::list<Text> m_title;
    std::list<Text> m_play;
    std::list<Text> m_controls;
    int m_mode;
    Background *m_menubg;

public:
  Menu(Background *menubg);
  ~Menu();
  int *get_mode();
  void update();
  void render(SDL_Renderer* renderer) const;
};
