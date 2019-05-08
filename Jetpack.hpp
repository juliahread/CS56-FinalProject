#pragma once
#include "Command.hpp"

class Sound;

class Jetpack : public Command { 
public:
  Jetpack(char dir, Sound *sound);
  ~Jetpack();
  void execute(Player &player);
  void execute();
 private:
  const float THRUST_FACTOR = 0.7;
  char m_direction;
  Sound *m_sound;
};
