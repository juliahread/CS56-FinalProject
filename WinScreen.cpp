#include "WinScreen.hpp"
#include "Scores.hpp"
#include "Timer.hpp"
#include "Text.hpp"
#include "Modes.hpp"
#include <iostream>
#include <string>

WinScreen::WinScreen(Scores *score, Timer *timer, int &mode) : m_score(score), m_timer(timer), m_mode(mode){
    // load intro text
    SDL_Point pos1 = {375, 40};
    Text text1("YOU WIN!", 120, pos1);
    SDL_Point pos2 = {100, 200};
    Text text2("You made it safely to the CampSec vehicle!", 42, pos2);
    SDL_Point pos3 = {100, 250};
    Text text3("A CampSec officer asks for your name......", 42, pos3);
    m_win_text.push_back(text1);
    m_win_text.push_back(text2);
    m_win_text.push_back(text3);
}

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
    } else if(strlen(keyname) == 1 and isalpha(*keyname) and m_name.size() <= 8){
      m_name = m_name + keyname;
      std::cout << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
      std::cout << m_name << std::endl;
    }
  }
}

void WinScreen::render(SDL_Renderer *renderer) const{
  for (auto text : m_win_text) {
      text.render(renderer);
  }

  if (m_name.size() > 0){
    Text name(m_name, 100, {400, 400});
    name.render(renderer);
  }
}
