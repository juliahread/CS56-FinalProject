#pragma once

#include <SDL2/SDL.h>
#include <string>

/*
 * SDLHelper class
 * Holds the main window, renderer, and helper functions pertaining to them
 */
class SDLHelper{
public:
  SDLHelper(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, char* WINDOW_NAME);
  ~SDLHelper();
  SDL_Window *window;
  SDL_Renderer *renderer;
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
