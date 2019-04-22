#include <SDL2/SDL.h>
#include "Detatch.hpp"
#include "Player.hpp"
#include <iostream>


void Detatch::execute(Player& player){
  player.getGrapplingHook()->detatch();
  std::cout << "Fired Grappling Hook" << std::endl;
}

void Detatch::execute(){
  std::cout << "FireGrapple command requires a reference to the player" << std::endl;
}

Detatch::~Detatch(){}
