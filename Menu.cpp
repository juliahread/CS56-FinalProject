#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Menu.hpp"

enum mode {play, controls};

Menu::Menu() {
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
    SDL_Point pos4 = {500, 500};
    Text text4("> Play", 110, white, pos4);
    SDL_Point pos5 = {600, 600};
    Text text5("Controls", 80, white, pos5);
    m_play.push_back(text4);
    m_play.push_back(text5);

    // Load controls text
    SDL_Point pos6 = {500, 500};
    Text text6("Play", 80, white, pos4);
    SDL_Point pos7 = {600, 600};
    Text text7("> Controls", 110, white, pos5);
    m_controls.push_back(text7);
    m_controls.push_back(text6);

    m_mode = play;
}

Menu::~Menu() {

}

void Menu::select() {

}

void Menu::update() {
    m_mode = play;
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
