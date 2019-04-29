#include "Menu.hpp"

Menu::Menu() {
    m_mode = menu_modes::PLAY;

    // load menu text
    SDL_Color white = {255, 255, 255};
    SDL_Point pos1 = {335, 78};
    Text text1("Disaster", 100, white, pos1);
    SDL_Point pos2 = {335, 190};
    Text text2("at the 5Cs", 75, white, pos2);
    SDL_Point pos3 = {335, 300};
    Text text3("in 2200", 110, white, pos3);
    m_title.push_back(text1);
    m_title.push_back(text2);
    m_title.push_back(text3);

    // load play text
    SDL_Point pos4 = {450, 450};
    Text text4(">", 100, white, pos4);
    SDL_Point pos5 = {550, 450};
    Text text5("Play", 100, white, pos5);
    SDL_Point pos6 = {550, 550};
    Text text6("Controls", 80, white, pos6);
    m_play.push_back(text4);
    m_play.push_back(text5);
    m_play.push_back(text6);

    // Load controls text
    SDL_Point pos7 = {450, 450};
    Text text7(">", 100, white, pos7);
    SDL_Point pos8 = {400, 500};
    Text text8("Play", 80, white, pos8);
    SDL_Point pos9= {500, 600};
    Text text9("> Controls", 100, white, pos9);
    m_controls.push_back(text7);
    m_controls.push_back(text8);
    m_controls.push_back(text9);
}

Menu::~Menu() {

}

int *Menu::get_mode() {
    return &m_mode;
}

void Menu::set_mode(int mode) {
    m_mode = mode;
}

void Menu::update() {
}

void Menu::render(SDL_Renderer *renderer) const {
    // render the title text
    for (auto it = m_title.begin(); it != m_title.end(); it++) {
        it->render(renderer);
    }

    // render the play text
    for (auto it = m_play.begin(); it != m_play.end(); it++) {
        it->render(renderer);
    }
}
