#import "InputHandler.hpp"
#import "FireGrapple.hpp"

InputHandler::InputHandler()
{
  m_game_left_click = new FireGrapple();
  m_game_w_button = nullptr;
  m_game_a_button = nullptr;
  m_game_s_button = nullptr;
  m_game_d_button = nullptr;
  m_menu_w_button = nullptr;
  m_menu_s_button = nullptr;
}

InputHandler::~InputHandler()
{
  delete m_game_left_click;
}

// TODO: Probably better to have one of these functions for the menu vs the game
// instead of always having to check which one we are in

Command* InputHandler::handle_input(SDL_Event e, bool game){
  if(e.type == SDL_KEYDOWN){
    switch (e.key.keysym.sym) {
    case SDLK_w:
      if (game) {
        return m_game_w_button;
      } else {
        return m_menu_w_button;
      }
      break;
    case SDLK_s:
      if (game) {
        return m_game_s_button;
      } else {
        return m_menu_s_button;
      }
      break;
    case SDLK_a:
      if (game) {
        return m_game_a_button;
      } else {
        return nullptr;
      }
      break;
    case SDLK_d:
      if (game) {
        return m_game_d_button;
      } else {
        return nullptr;
      }
      break;
    }
  } else if(e.type == SDL_MOUSEBUTTONDOWN){
    switch(e.button.button) {
      case SDL_BUTTON_LEFT:
        if (game) {
          return m_game_left_click;
        } else {
          return nullptr;
        }
        break;
    }
  }
  return nullptr;

}
