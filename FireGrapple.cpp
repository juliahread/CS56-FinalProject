#include "FireGrapple.hpp"
#include "Camera.hpp"

FireGrapple::FireGrapple() { }

void FireGrapple::execute(Player& player) {
  int x = 0;
  int y = 0;
  SDL_Point offset = Camera::get_instance()->get_offset();
  SDL_GetMouseState(&x, &y);
  SDL_Point shoot_loc;
  shoot_loc.x = x + offset.x;
  shoot_loc.y = y + offset.y;
  player.getGrapplingHook()->shoot(shoot_loc);
  std::cout << "Fired Grappling Hook" << std::endl;
}

void FireGrapple::execute() {
  std::cout << "FireGrapple command requires a reference to the player" << std::endl;
}

FireGrapple::~FireGrapple() {}
