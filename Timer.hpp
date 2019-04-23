#pragma once

#include "SDLHelper.hpp"

class Timer {
 public:
  void start();
  void stop();
  void set(int new_time);
  int getTime();

 private:
  int m_time;
};
