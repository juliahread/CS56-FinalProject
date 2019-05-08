#pragma once

#include "Entity.hpp"
#include "Text.hpp"
#include "SDLHelper.hpp"
#include "Modes.hpp"
#include "Fuel.hpp"
#include "Depot.hpp"
#include "EndObject.hpp"
#include "Background.hpp"
#include <list>
#include <iostream>

class Controls : public Entity {
private:
    std::list<Text> m_intro;
    std::list<Text> m_controls;
    std::list<Text> m_back;
    Background *m_controlsbg;
    Fuel m_fuel;
    Depot m_depot;
    EndObject m_end;

public:
    Controls(Background *controlsbg, SDL_Renderer *renderer);
    ~Controls();
    void update();
    void render(SDL_Renderer* renderer) const;
};
