#pragma once
#include "Command.hpp"

class Detach : public Command {
public:
  void execute(Player &player);
  void execute();
  ~Detach();
};
