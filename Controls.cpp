#include "Controls.hpp"

Controls::Controls(Background *controlsbg, SDL_Renderer *renderer) : m_controlsbg(controlsbg) {
    m_fuel = Fuel("apple.png", 1, 1, renderer,
         {200, 500, Fuel::WIDTH, Fuel::HEIGHT}, 0, 0);
    m_depot = Depot("oldenborg_smaller.png", 1, 0, renderer,
         {200, 550, Depot::WIDTH, Depot::HEIGHT});
    m_end = EndObject("end_smaller.png", 1, 0, renderer,
         {200, 600, EndObject::WIDTH, EndObject::HEIGHT});

    // load intro text
    m_intro.push_back(Text("It's the year 2200, and the Claremont Colleges", 42, {35, 20}));
    m_intro.push_back(Text("have successfully migrated to space...", 42, {35, 70}));
    m_intro.push_back(Text("But over-enrollment in CS 5 at HMC has caused a", 42, {35, 120}));
    m_intro.push_back(Text("singularity to form, and the Claremont Colleges", 42, {35, 170}));
    m_intro.push_back(Text("have been destroyed! You must reach Campus", 42, {35, 220}));
    m_intro.push_back(Text("Safety in order to survive. Good luck!", 42, {35, 270}));

    // load controls text
    m_controls.push_back(Text("Left Click - shoot the grappling hook", 36, {200, 350}));
    m_controls.push_back(Text("Right Click - detach the grappling hook", 36, {200, 400}));
    m_controls.push_back(Text("WASD - control the jetpack", 36, {200, 450}));
    m_controls.push_back(Text("- additional fuel", 36, {260, 500}));
    m_controls.push_back(Text("- fuel depot", 36, {280, 550}));
    m_controls.push_back(Text("- Campus Safety vehicle", 36, {330, 600}));

    // load back text
     m_back = Text("Press A to return to the menu...", 28, {720, 665});
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

    // render the back
    m_back.render(renderer);

    // render fuel, depot, and campsec vehicle
    m_fuel.get_sprite()->renderSpriteWithoutCamera(200, 500, renderer, 1);
    m_depot.get_sprite()->renderSpriteWithoutCamera(200, 550, renderer, 1);
    m_end.get_sprite()->renderSpriteWithoutCamera(200, 600, renderer, 1);
}
