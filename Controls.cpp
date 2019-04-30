#include "Controls.hpp"

Controls::Controls(Background *controlsbg) {
    m_controlsbg = controlsbg;

    // load intro text
    SDL_Point pos1 = {30, 20};
    Text text1("It is the year 2200, and the Claremont Colleges", 42, pos1);
    SDL_Point pos2 = {30, 70};
    Text text2("have successfully migrated to space...", 42, pos2);
    m_intro.push_back(text1);
    m_intro.push_back(text2);

    // load back text
    SDL_Point pos_back = {30, 650};
    Text text_back("Press A to return to the menu...", 42, pos_back);
    m_back.push_back(text_back);


}

Controls::~Controls() {}

void Controls::update() {
    // update the background
    m_controlsbg->update();
}

void Controls::render(SDL_Renderer* renderer) const {
    // render the background
    m_controlsbg->render(renderer);

    // render the intro text
    for (auto it = m_intro.begin(); it != m_intro.end(); it++) {
        it->render(renderer);
    }

    // render the back text
    for (auto it = m_back.begin(); it != m_back.end(); it++) {
        it->render(renderer);
    }

}
