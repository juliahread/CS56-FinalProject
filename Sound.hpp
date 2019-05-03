#pragma once

#include "SDLHelper.hpp"

class Sound {
public:
    Sound();
    ~Sound();
    void play();
private:
    Mix_Music *music;
};
