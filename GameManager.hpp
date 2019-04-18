#pragma once

#include "Graphics.hpp"

class GameManager {

private:
    static GameManager* m_instance;
    bool m_quit;
    Graphics* m_graphics;
    SDL_Event m_events;

public:
    static GameManager* instance();
    static void close();
    void run();

private:
    GameManager();
    ~GameManager();

};
