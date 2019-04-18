#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>

class Graphics {

public:
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

private:
    static Graphics* m_instance;
    static bool m_initialized;
    SDL_Window* m_window;
    SDL_Surface* m_screen_surface;

public:
    static Graphics* instance();
    static bool initialized();
    // static bool load_media();
    // static SDL_Surface* load_surface(std::string);
    static void close();
    void render();

private:
    Graphics();
    ~Graphics();
    bool init();
    
};
