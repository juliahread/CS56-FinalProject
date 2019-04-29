#include "MenuInputHandler.hpp"

MenuInputHandler::MenuInputHandler(int *game_mode, Menu *menu) {
    m_menu_w_button = nullptr;
    m_menu_s_button = nullptr;
    m_menu_enter_button = new MenuSelect(game_mode, menu->get_mode());
}

MenuInputHandler::~MenuInputHandler() {
    delete m_menu_enter_button;
}

Command* MenuInputHandler::handle_input(SDL_Event e) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_w:
                return m_menu_w_button;
            case SDLK_s:
                return m_menu_s_button;
            case SDLK_RETURN:
                return m_menu_enter_button;
        }
    }
    return nullptr;
}
