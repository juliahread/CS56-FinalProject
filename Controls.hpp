#pragma once

#include <iostream>
#include <list>
#include "Background.hpp"
#include "Depot.hpp"
#include "EndObject.hpp"
#include "Entity.hpp"
#include "Fuel.hpp"
#include "Modes.hpp"
#include "SDLHelper.hpp"
#include "Text.hpp"

class Controls : public Entity {
 private:
  std::list<Text> m_intro;
  std::list<Text> m_controls;
  Text m_back;
  Background *m_controlsbg;
  Fuel m_fuel;
  Depot m_depot;
  EndObject m_end;

 public:
  Controls(Background *controlsbg, SDL_Renderer *renderer);
  ~Controls();
  void update();
  void render(SDL_Renderer *renderer) const;
};
