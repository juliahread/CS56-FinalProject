#include "GrapplingPoints.hpp"
#include "InputHandler.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"
#include "Vec2D.hpp"
#include "Text.hpp"
#include "Star.hpp"
#include "Jetpack.hpp"
#include "Background.hpp"
#include "Menu.hpp"
#include <ctime>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
char *WINDOW_NAME = (char *)"Disaster at the 5C's in 2200";
SDLHelper helper(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
enum modes { MENU, CONTROLS, GAMEPLAY, ENDGAME };

#undef main
int main() {
  // Make rand() actually random
  srand(std::time(NULL));
  // Flag to close the game
  bool quit = false;
  // Initialize backgrounds
  Background menu(MENU, helper.renderer);
  Background controls(CONTROLS, helper.renderer);
  Background gameplay(GAMEPLAY, helper.renderer);
  Background endgame(ENDGAME, helper.renderer);

  Star star1(50, 50, helper.renderer);
  Star star2(200, 400, helper.renderer);

  // Initialize map
  std::string map_file = "Map.png";
  Map map;
  map.load_map(map_file, helper.renderer);

  // Initialize Menu
  Menu menu;
  menu.render(helper.renderer);

  int mode = GAMEPLAY;
  Vec2D start_loc(10, 10);
  Vec2D vel(10, 10);
  Player p1(start_loc, vel, 100, helper.renderer, &map);

  // Event handler
  SDL_Event e;
  InputHandler input;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      // User requests quit
      if (e.type == SDL_QUIT) {
        quit = true;
      } else {
        Command *command = input.handle_input(e, mode == GAMEPLAY);
        if (command != nullptr) {
          command->execute(p1);
        }
      }
    }

    SDL_SetRenderDrawColor(helper.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(helper.renderer);

    // displaying backgrounds, should eventually be in menu class probably
    if (mode == MENU) {
      menu.render(helper.renderer);
      text1.render(helper.renderer);
      text2.render(helper.renderer);
      text3.render(helper.renderer);
      star1.update();
      star2.update();
      star1.render(helper.renderer);
      star2.render(helper.renderer);
    }
    else if (mode == CONTROLS) {
      controls.render(helper.renderer);
    }
    else if (mode == GAMEPLAY) {
      p1.update();
      gameplay.render(helper.renderer);
      p1.render(helper.renderer);
      map.get_obstacle_list()->render(helper.renderer);
      map.get_grappling_point_list()->render(helper.renderer);
    }
    else if (mode == ENDGAME) {
      endgame.render(helper.renderer);
    }

    SDL_RenderPresent(helper.renderer);
    SDL_Delay(30);
  }
  SDL_Quit();
  return 0;
}
