#include "InputHandler.hpp"
#include "Detach.hpp"
#include "FireGrapple.hpp"
#include "Jetpack.hpp"

InputHandler::InputHandler(Sound * sound) {
  m_game_left_click = new FireGrapple(sound);
  m_game_right_click = new Detach();
  m_game_w_button = new Jetpack('W', sound);
  m_game_a_button = new Jetpack('A', sound);
  m_game_s_button = new Jetpack('S', sound);
  m_game_d_button = new Jetpack('D', sound);
}

InputHandler::~InputHandler() {
  delete m_game_left_click;
  delete m_game_right_click;
  delete m_game_w_button;
  delete m_game_a_button;
  delete m_game_s_button;
  delete m_game_d_button;
  }

Command* InputHandler::handle_input(SDL_Event e) {
  if (e.type == SDL_MOUSEBUTTONDOWN) {
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
