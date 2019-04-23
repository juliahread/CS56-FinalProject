#pragma once

#ifndef _WIN32
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
<<<<<<< HEAD
#include <SDL2/SDL_ttf.h>
#else
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#endif
#include <string>
#include <stdexcept>
=======
#else
#include "SDL.h"
#include "SDL_image.h"
#endif
#include <stdexcept>
#include <string>
>>>>>>> 880ab8fe20c8f50848afd8d23e1751560aeaa317

/*
 * SDLHelper class
 * Holds the main window, renderer, and helper functions pertaining to them
 */
<<<<<<< HEAD
class SDLHelper{
public:
  SDLHelper(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, char* WINDOW_NAME);
  ~SDLHelper();
  SDL_Window *window;
  SDL_Renderer *renderer;
  TTF_Font *font;
  int getScreenWidth() const;
  int getScreenHeight() const;
  char *getWindowName() const;
private:
=======
class SDLHelper {
 public:
  SDLHelper(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, char *WINDOW_NAME);
  ~SDLHelper();
  SDL_Window *window;
  SDL_Renderer *renderer;
  int getScreenWidth() const;
  int getScreenHeight() const;
  char *getWindowName() const;

 private:
>>>>>>> 880ab8fe20c8f50848afd8d23e1751560aeaa317
  bool init();
  void close();
  const int SCREEN_WIDTH;
  const int SCREEN_HEIGHT;
  char *WINDOW_NAME;
<<<<<<< HEAD
};
=======
};
>>>>>>> 880ab8fe20c8f50848afd8d23e1751560aeaa317
