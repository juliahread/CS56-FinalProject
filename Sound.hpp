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
private:
    Mix_Music *music;
    Mix_Chunk *grappling;
    Mix_Chunk *crash;
    Mix_Chunk *refuel;
};
