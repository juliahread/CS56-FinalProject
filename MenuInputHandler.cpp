#include "MenuInputHandler.hpp"

MenuInputHandler::MenuInputHandler() {
    m_menu_w_button = nullptr;
    m_menu_s_button = nullptr;
    m_menu_enter_button = nullptr;
}

MenuInputHandler::~MenuInputHandler() {}

Command* MenuInputHandler::handle_input(SDL_Event e, bool game) {
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
