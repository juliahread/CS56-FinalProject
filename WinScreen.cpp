#include "WinScreen.hpp"
#include "Scores.hpp"
#include "Timer.hpp"
#include "Text.hpp"
#include "Modes.hpp"
#include <iostream>
#include <string>

WinScreen::WinScreen(Scores *score, Timer *timer, int &mode) : m_score(score), m_timer(timer), m_mode(mode){}
WinScreen::~WinScreen(){}

void WinScreen::handle_input(SDL_Event e){
  if (e.type == SDL_KEYDOWN){
    const char * keyname = SDL_GetKeyName(e.key.keysym.sym);
    if(e.key.keysym.sym == SDLK_RETURN){
      m_score->add_score({m_name, m_timer->get_time()});
      m_score->save_scores();
      m_mode = game_modes::HIGHSCORES;
    } else if(e.key.keysym.sym == SDLK_BACKSPACE){
      if (m_name.size() > 0){
        m_name.pop_back();
      }
    } else if(strlen(keyname) == 1 and isalpha(*keyname) and m_name.size() <= 10){
      m_name = m_name + keyname;
      std::cout << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
      std::cout << m_name << std::endl;
    }
  }
}

void WinScreen::render(SDL_Renderer *renderer) const{
  if (m_name.size() > 0){
    Text name(m_name, 100, {400, 400});
    name.render(renderer);
  }
}
