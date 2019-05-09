#pragma once
#include <iostream>
#include "Command.hpp"
#include "Player.hpp"
#include "SDLHelper.hpp"

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
