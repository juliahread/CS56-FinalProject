#pragma once

#ifndef _WIN32
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#else
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#endif
#include <stdexcept>
#include <string>

/*
 * SDLHelper class
 * Holds the main window, renderer, and helper functions pertaining to them
 */
class SDLHelper {
 public:
  SDLHelper(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, char *WINDOW_NAME);
  ~SDLHelper();
  SDL_Window *window;
  SDL_Renderer *renderer;
  TTF_Font *font;
  int getScreenWidth() const;
  int getScreenHeight() const;
  char *getWindowName() const;

 private:
  bool init();
  void close();
  const int SCREEN_WIDTH;
  const int SCREEN_HEIGHT;
  char *WINDOW_NAME;
};
