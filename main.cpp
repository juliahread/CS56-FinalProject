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
#include "MenuInputHandler.hpp"

#include "Modes.hpp"
#include <ctime>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
char *WINDOW_NAME = (char *)"Disaster at the 5C's in 2200";
SDLHelper helper(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
// enum modes { MENU, CONTROLS, GAMEPLAY, ENDGAME };

#undef main
int main() {
  // Make rand() actually random
  srand(std::time(NULL));
  // Flag to close the game
  bool quit = false;
  // Initialize backgrounds
  Background menubg(game_modes::MENU, helper.renderer);
  Background controls(game_modes::CONTROLS, helper.renderer);
  Background gameplay(game_modes::GAMEPLAY, helper.renderer);
  Background endgame(game_modes::ENDGAME, helper.renderer);

  Star star1(50, 50, helper.renderer);
  Star star2(200, 400, helper.renderer);

  // Initialize map
  std::string map_file = "Map.png";
  Map map;
  map.load_map(map_file, helper.renderer);

  // Initialize menu
  Menu menu;
  menu.render(helper.renderer);

  int game_mode = game_modes::MENU;
  Vec2D start_loc(10, 10);
  Vec2D vel(10, 10);
  Player p1(start_loc, vel, 100, helper.renderer, &map);

  // Event handler
  SDL_Event e;
  InputHandler input;
  MenuInputHandler menu_input(&game_mode, &menu);

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      // User requests quit
      if (e.type == SDL_QUIT) {
        quit = true;
      } else {
          if (game_mode == game_modes::MENU) {
              Command *command = menu_input.handle_input(e);
              if (command != nullptr) {
                  command->execute();
              }
          } else if (game_mode == game_modes::GAMEPLAY) {
              Command *command = input.handle_input(e);
              if (command != nullptr) {
                command->execute(p1);
              }
          }
      }
    }

    SDL_SetRenderDrawColor(helper.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(helper.renderer);

    // displaying backgrounds, should eventually be in menu class probably
    if (game_mode == game_modes::MENU) {
      menubg.render(helper.renderer);
      menu.render(helper.renderer);
      star1.update();
      star2.update();
      star1.render(helper.renderer);
      star2.render(helper.renderer);
    }
    else if (game_mode == game_modes::CONTROLS) {
      controls.render(helper.renderer);
    }
    else if (game_mode == game_modes::GAMEPLAY) {
      p1.update();
      gameplay.render(helper.renderer);
      p1.render(helper.renderer);
      map.get_obstacle_list()->render(helper.renderer);
      map.get_grappling_point_list()->render(helper.renderer);
    }
    else if (game_mode == game_modes::ENDGAME) {
      endgame.render(helper.renderer);
    }

    SDL_RenderPresent(helper.renderer);
    SDL_Delay(30);
  }
  SDL_Quit();
  return 0;
}
