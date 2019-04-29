#pragma 
#include "SDLHelper.hpp"
#include "Command.hpp"
#include "Player.hpp"
#include <iostream>

class FireGrapple : public Command {
 public:
  FireGrapple();
  ~FireGrapple();
  void execute(Player &player);
  void execute();
};
