#pragma once

#include "SDLHelper.hpp"
#include "Text.hpp"
#include <ctime>
#include <string>

class Timer : public Entity {
 public:
    Timer();
    ~Timer();
    void start();
    void stop();
    void set(int new_time);
    int get_time();
    void render(SDL_Renderer *renderer) const;
    void update();

 private:
     std::time_t start_time;
     std::time_t stop_time;
     int m_time;
     Text m_text_timer;
};
