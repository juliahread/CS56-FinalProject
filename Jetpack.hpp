#pragma once
#include "Command.hpp"

class Jetpack : public Command { 
public:
  Jetpack(char);
  ~Jetpack();
  void execute(Player &player);
  void execute();
 private:
  const float THRUST_FACTOR = 0.6;
  char m_direction;
};
