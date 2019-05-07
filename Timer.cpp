#include "Timer.hpp"

Timer::Timer() {
    SDL_Point timer_pos = {950, 20};
    Text text("Time: " + std::to_string(m_time), 50, timer_pos);
    m_text_timer = text;
}

Timer::~Timer() {}

void Timer::start() {
    std::time(&start_time);
}

void Timer::stop() {
    std::time(&stop_time);
}

void Timer::set(int new_time) {
    m_time = new_time;
}

int Timer::get_time() {
    stop();
    if  (difftime(stop_time, start_time) > m_time) {
        return 0;
    } else {
        return m_time - difftime(stop_time, start_time);
    }
}

void Timer::render(SDL_Renderer *renderer) const {
    m_text_timer.render(renderer);
}

void Timer::update() {
    m_text_timer.set_text("Time: " + std::to_string(get_time()));
}
