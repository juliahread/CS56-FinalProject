#pragma once

#include "SDLHelper.hpp"
#include <string>
#include "Entity.hpp"

class Text : public Entity {
public:
  Text(std::string words, SDL_Point location);
  ~Text();
private:
  std::string m_words;
  SDL_Point m_location;
};
