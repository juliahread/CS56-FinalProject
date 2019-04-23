#pragma once

#include <string>
#include "Entity.hpp"
#include "SDLHelper.hpp"

class Text : public Entity {
 public:
  Text(std::string words, SDL_Point location);
  ~Text();

 private:
  std::string m_words;
  SDL_Point m_location;
};