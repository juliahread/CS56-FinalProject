#include "Sound.hpp"

Sound::Sound() {
  music = Mix_LoadMUS("sound/music.wav");
  if (music == NULL) {
    printf("Failed to load mixer! SDL_mixer Error: %s\n", Mix_GetError());
  }
}

Sound::~Sound() {
  Mix_HaltMusic();
  delete music;
}

void Sound::play() {
  if (Mix_PlayingMusic() == 0) {
    Mix_PlayMusic(music, -1);
  }
}
