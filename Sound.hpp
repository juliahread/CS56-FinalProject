#pragma once

#include "SDLHelper.hpp"

class Sound {
 public:
  Sound();
  ~Sound();
  void play();
  void playGrappling();
  void playCrash();
  void playRefuel();
  void playJetpack();

 private:
  Mix_Music *music;
  Mix_Chunk *grappling;
  Mix_Chunk *crash;
  Mix_Chunk *refuel;
  Mix_Chunk *jetpack;
  // Update this whenever you add a sound effect
  static constexpr int NUM_CHANNELS = 4;
};
