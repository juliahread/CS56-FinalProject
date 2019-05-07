#include "Sound.hpp"

Sound::Sound() {
  // load music
  music = Mix_LoadMUS("sound/music.wav");
  // load sound effects
  // grappling = Mix_LoadWAV("sound/grappling.wav");
  // crash = Mix_LoadWAV("sound/crash.wav");
  // refuel = Mix_LoadWAV("sound/refuel.wav");
  // check load
  if (music == NULL || grappling == NULL || crash == NULL || refuel == NULL) {
    printf("Failed to load mixer! SDL_mixer Error: %s\n", Mix_GetError());
  }
}

Sound::~Sound() {
  Mix_HaltMusic();
  Mix_FreeMusic(music);
  // Mix_FreeChunk(grappling);
  // Mix_FreeChunk(crash);
  // Mix_FreeChunk(refuel);
  // delete music;
  // delete grappling;
  // delete crash;
  // delete refuel;
}

void Sound::play() {
  if (Mix_PlayingMusic() == 0) {
    Mix_PlayMusic(music, -1);
  }
}
