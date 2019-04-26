#pragma once
#include "Command.hpp"

class Jetpack : public Command { 
public:
  Jetpack(char);
  ~Jetpack();
  void execute(Player &player);
  void execute();
 private:
  char m_direction;
};
