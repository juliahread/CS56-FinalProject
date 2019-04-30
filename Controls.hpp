#pragma once

#include "Entity.hpp"
#include "Text.hpp"
#include "SDLHelper.hpp"
#include "Modes.hpp"

// forward declaration
#include "Background.hpp"

#include <list>

class Controls : public Entity {
private:
    std::list<Text> m_intro;
    std::list<Text> m_controls;
    std::list<Text> m_back;
    Background *m_controlsbg;

public:
    Controls(Background *controlsbg);
    ~Controls();
    void update();
    void render(SDL_Renderer* renderer) const;
};
