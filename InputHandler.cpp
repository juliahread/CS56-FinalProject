#include "InputHandler.hpp"
#include "Detach.hpp"
#include "FireGrapple.hpp"
#include "Jetpack.hpp"

InputHandler::InputHandler() {
  m_game_left_click = new FireGrapple();
  m_game_right_click = new Detach();
  m_game_w_button = new Jetpack('W');
  m_game_a_button = new Jetpack('A');
  m_game_s_button = new Jetpack('S');
  m_game_d_button = new Jetpack('D');
  m_menu_w_button = nullptr;
  m_menu_s_button = nullptr;
}

InputHandler::~InputHandler() { delete m_game_left_click; }

// TODO: Probably better to have one of these functions for the menu vs the game
// instead of always having to check which one we are in

Command* InputHandler::handle_input(SDL_Event e) {
  if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_w:
          return m_game_w_button;
          break;
        case SDLK_s:
          return m_game_s_button;
          break;
        case SDLK_a:
          return m_game_a_button;
          break;
        case SDLK_d:
          return m_game_d_button;
          break;
      }
  } else if (e.type == SDL_MOUSEBUTTONDOWN) {
    switch (e.button.button) {
      case SDL_BUTTON_LEFT:
        return m_game_left_click;
        break;
      case SDL_BUTTON_RIGHT:
        return m_game_right_click;
        break;
    }
  }
  return nullptr;
}
