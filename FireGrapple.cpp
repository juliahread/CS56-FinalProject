#include <SDL2/SDL.h>
#include "FireGrapple.hpp"
#include "Player.hpp"
#include <iostream>


void FireGrapple::execute(Player& player){
  int x = 0;
  int y = 0;
  SDL_GetMouseState(&x, &y);
  SDL_Point shoot_loc;
  shoot_loc.x = x;
  shoot_loc.y = y;
  player.getGrapplingHook()->shoot(&shoot_loc);
}

void FireGrapple::execute(){
  std::cout << "FireGrapple command requires a reference to the player" << std::endl;
}

FireGrapple::~FireGrapple(){}
