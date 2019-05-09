#pragma once

#include <string>
#include "Entity.hpp"
#include "SDLHelper.hpp"

class Text : public Entity {
 public:
  Text();
  Text(std::string text, int font_size, SDL_Point pos);
  Text(std::string text, int font_size, SDL_Point pos, SDL_Color color);
  ~Text();
  void loadFont(int font_size);
  void render(SDL_Renderer *renderer) const;
  void update();
  void set_text(std::string text);
  void setPos(SDL_Point pos);

 private:
  std::string m_text;
  SDL_Color m_color;
  SDL_Point m_pos;
  TTF_Font *m_font;
  SDL_Renderer *m_renderer;
  static constexpr int MAX_NAME_LEN = 10;
};
