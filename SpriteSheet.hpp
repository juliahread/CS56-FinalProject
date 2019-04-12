#pragma once

#include <SDL2/SDL.h>
#include <string>

class SpriteSheet {
  public:
  SpriteSheet();
  ~SpriteSheet();
  bool loadFromFile( std::string path, SDL_Renderer* renderer, int num_sprites);
  //Renders texture at given point
  void renderSprite( int screenX, int screenY, SDL_Renderer* renderer, int spriteNumber);
  //Gets image dimensions
  int getWidth();
  int getHeight();
private:
  //Texture wrapper class
  SDL_Texture * m_texture;
  //Sprite size
  int spriteWidth;
  int spriteHeight;
  //For calculating dimensions
  int numSprites;
};
