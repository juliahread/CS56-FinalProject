#pragma once

#include "Player.hpp"

class Command {
 public:
  virtual void execute() = 0;
  virtual void execute(Player& player) = 0;
  virtual ~Command(){};
};
