#include <SDL2/SDL.h>
#include "FireGrapple.hpp"
#include "Player.hpp"


void FireGrapple::execute(Player& player){
  int x = 0;
  int y = 0;
  SDL_GetMouseState(&x, &y);
  SDL_Point shoot_loc;
  shoot_loc.x = x;
  shoot_loc.y = y;
  player.getGrapplingHook()->shoot(shoot_loc);
}
