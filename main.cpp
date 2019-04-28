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
  Background menubg(MENU, helper.renderer);
  Background controls(CONTROLS, helper.renderer);
  Background gameplay(GAMEPLAY, helper.renderer);
  Background endgame(ENDGAME, helper.renderer);

  // Initialize map
  std::string map_file = "Map.png";
  Map map;
  map.load_map(map_file, helper.renderer);

  // Initialize menu
  Menu menu;
  menu.render(helper.renderer);

  int mode = MENU;
  Vec2D start_loc(map.get_start()->x, map.get_end()->y);
  Vec2D vel(5, 5);
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
      menubg.render(helper.renderer);
      menubg.update();
      menu.render(helper.renderer);
    }
    else if (mode == CONTROLS) {
      controls.render(helper.renderer);
      controls.update();
    }
    else if (mode == GAMEPLAY) {
      p1.update();
      gameplay.render(helper.renderer);
      gameplay.update();
      p1.render(helper.renderer);
      map.get_obstacle_list()->render(helper.renderer);
      map.get_grappling_point_list()->render(helper.renderer);
    }
    else if (mode == ENDGAME) {
      endgame.render(helper.renderer);
      endgame.update();
    }

    SDL_RenderPresent(helper.renderer);
    SDL_Delay(30);
  }
  SDL_Quit();
  return 0;
}
