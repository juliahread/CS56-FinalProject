#pragma once

#include <SDL2/SDL.h>

class Timer {
public:
  void start();
  void stop();
  void set(int new_time);
  int getTime();

private:
  int m_time;

};
