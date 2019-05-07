#pragma once

#include "SDLHelper.hpp"

class Sound {
public:
    Sound();
    ~Sound();
    void play();
private:
    Mix_Music *music;
    Mix_Chunk *grappling;
    Mix_Chunk *crash;
    Mix_Chunk *refuel;
};
