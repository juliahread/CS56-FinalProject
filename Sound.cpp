#include "Sound.hpp"

Sound::Sound() {
  // load music
  music = Mix_LoadMUS("sound/music.wav");
  // load sound effects
  grappling = Mix_LoadWAV("sound/grappling.wav");
  crash = Mix_LoadWAV("sound/crash.wav");
  refuel = Mix_LoadWAV("sound/refuel.wav");
  // check load
  if (music == NULL || grappling == NULL || crash == NULL || refuel == NULL) {
    printf("Failed to load mixer! SDL_mixer Error: %s\n", Mix_GetError());
  }
}

Sound::~Sound() {
  Mix_HaltMusic();
  delete music;
  delete grappling;
  delete crash;
  delete refuel;
}

void Sound::play() {
  if (Mix_PlayingMusic() == 0) {
    Mix_PlayMusic(music, -1);
  }
}

void Sound::playGrappling() {
  Mix_PlayChannel(-1, grappling, 0);
}

void Sound::playCrash() {
  Mix_PlayChannel(-1, crash, 0);
}

void Sound::playRefuel() {
  Mix_PlayChannel(-1, refuel, 0);
}
