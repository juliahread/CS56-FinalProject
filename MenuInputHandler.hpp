#pragma once
#include "Command.hpp"
#include "SDLHelper.hpp"
#include "MenuSelect.hpp"
#include "Modes.hpp"

// forward declaration
#include "Menu.hpp"

class MenuInputHandler {
 private:
  Command *m_menu_w_button;
  Command *m_menu_s_button;
  Command *m_menu_enter_button;

public:
    MenuInputHandler(int *game_mode, Menu *menu);
    ~MenuInputHandler();
    Command *handle_input(SDL_Event e);
};
