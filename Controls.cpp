#include "Controls.hpp"

Controls::Controls(Background *controlsbg, SDL_Renderer *renderer) {
    m_controlsbg = controlsbg;
    m_fuel = Fuel("apple.png", 1, 1, renderer,
         {200, 500, Fuel::WIDTH, Fuel::HEIGHT}, 0, 0);
    m_depot = Depot("oldenborg_smaller.png", 1, 0, renderer,
         {200, 550, Depot::WIDTH, Depot::HEIGHT});
    m_end = EndObject("end_smaller.png", 1, 0, renderer,
         {200, 600, EndObject::WIDTH, EndObject::HEIGHT});

    // load intro text
    SDL_Point pos1 = {25, 20};
    Text text1("It's the year 2200, and the Claremont Colleges", 42, pos1);
    SDL_Point pos2 = {25, 70};
    Text text2("have successfully migrated to space...", 42, pos2);
    SDL_Point pos3 = {25, 120};
    Text text3("But over-enrollment in CS 5 at HMC has caused a", 42, pos3);
    SDL_Point pos4 = {25, 170};
    Text text4("singularity to form, and the Claremont Colleges", 42, pos4);
    SDL_Point pos5 = {25, 220};
    Text text5("have been destroyed! You must reach Campus", 42, pos5);
    SDL_Point pos6 = {25, 270};
    Text text6("Safety in order to survive. Good luck!", 42, pos6);
    m_intro.push_back(text1);
    m_intro.push_back(text2);
    m_intro.push_back(text3);
    m_intro.push_back(text4);
    m_intro.push_back(text5);
    m_intro.push_back(text6);

    // load controls text
    SDL_Point pos_shoot = {200, 350};
    Text text_shoot("Left Click - shoot the grappling hook", 36, pos_shoot);
    SDL_Point pos_detach = {200, 400};
    Text text_detach("Right Click - detach the grappling hook", 36, pos_detach);
    SDL_Point pos_wasd = {200, 450};
    Text text_wasd("WASD - control the jetpack", 36, pos_wasd);
    SDL_Point pos_fuel = {260, 500};
    Text text_fuel("- additional fuel", 36, pos_fuel);
    SDL_Point pos_oldy = {280, 550};
    Text text_oldy("- fuel depot", 36, pos_oldy);
    SDL_Point pos_end = {330, 600};
    Text text_end("- Campus Safety vehicle", 36, pos_end);
    m_controls.push_back(text_shoot);
    m_controls.push_back(text_detach);
    m_controls.push_back(text_wasd);
    m_controls.push_back(text_fuel);
    m_controls.push_back(text_oldy);
    m_controls.push_back(text_end);

    // load back text
    SDL_Point pos_back = {720, 665};
    Text text_back("Press A to return to the menu...", 28, pos_back);
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
    for (auto text : m_intro) {
        text.render(renderer);
    }

    // render the controls text
    for (auto text : m_controls) {
        text.render(renderer);
    }

    // render the back text
    for (auto text : m_back) {
        text.render(renderer);
    }

    // render fuel, depot, and campsec vehicle
    m_fuel.get_sprite()->renderSpriteWithoutCamera(200, 500, renderer, 1);
    m_depot.get_sprite()->renderSpriteWithoutCamera(200, 550, renderer, 1);
    m_end.get_sprite()->renderSpriteWithoutCamera(200, 600, renderer, 1);
}
