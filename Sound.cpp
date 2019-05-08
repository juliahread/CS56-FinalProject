#include "Sound.hpp"

Sound::Sound() {
  Mix_AllocateChannels(NUM_CHANNELS);
  // load music
  music = Mix_LoadMUS("sound/music.wav");
  // load sound effects
  grappling = Mix_LoadWAV("sound/grappling.wav");
  crash = Mix_LoadWAV("sound/crash.wav");
  refuel = Mix_LoadWAV("sound/refuel.wav");
  jetpack = Mix_LoadWAV("sound/jetpack.wav");
  // check load
  if (music == NULL || grappling == NULL || crash == NULL || refuel == NULL|| jetpack == NULL) {
    printf("Failed to load mixer! SDL_mixer Error: %s\n", Mix_GetError());
  }
}

Sound::~Sound() {
  Mix_HaltMusic();
  delete music;
  delete grappling;
  delete crash;
  delete refuel;
  delete jetpack;
}

void Sound::play() {
  if (Mix_PlayingMusic() == 0) {
    Mix_PlayMusic(music, -1);
  }
}

void Sound::playGrappling() {
  Mix_PlayChannel(0, grappling, 0);
}

void Sound::playCrash() {
  Mix_PlayChannel(1, crash, 0);
}

void Sound::playRefuel() {
  Mix_PlayChannel(2, refuel, 0);
}

void Sound::playJetpack() {
  if (not Mix_Playing(3)){
    Mix_PlayChannel(3, jetpack, 0);
  }
}
