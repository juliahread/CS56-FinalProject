#pragma once
#include "Command.hpp"

class Detatch : public Command {
public:
  void execute(Player &player);
  void execute();
  ~Detatch();
};
