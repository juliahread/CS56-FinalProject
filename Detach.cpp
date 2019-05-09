#include "Detach.hpp"
#include <iostream>
#include "Player.hpp"
#include "SDLHelper.hpp"

void Detach::execute(Player& player) {
  player.getGrapplingHook()->detach();
  std::cout << "Fired Grappling Hook" << std::endl;
}

void Detach::execute() {
  std::cout << "FireGrapple command requires a reference to the player"
            << std::endl;
}

Detach::~Detach() {}
