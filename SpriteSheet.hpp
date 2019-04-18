#pragma once

#include <SDL2/SDL.h>
#include <string>

class SpriteSheet {
  public:
  SpriteSheet();
  SpriteSheet(std::string path, SDL_Renderer* renderer, int num_sprites);
  ~SpriteSheet();
  void loadFromFile(std::string path, SDL_Renderer* renderer, int num_sprites);
  //Renders texture at given point
  void renderSprite( int screenX, int screenY, SDL_Renderer* renderer, int spriteNumber);
  //Gets image dimensions
  int getWidth();
  int getHeight();
private:
  void render( int x, int y, SDL_Renderer* renderer, SDL_Rect* clip);
  //Texture wrapper class
  SDL_Texture *m_texture;
  //Sprite size
  int m_sprite_width;
  int m_sprite_height;
  //For calculating dimensions
  int m_num_sprites;
};
