#pragma once
#include "SDLHelper.hpp"
#include "Command.hpp"
#include "Player.hpp"
#include <iostream>

class Sound;

class FireGrapple : public Command {
 public:
  FireGrapple(Sound *sound);
  ~FireGrapple();
  void execute(Player &player);
  void execute();
private:
  Sound *m_sound;
};
