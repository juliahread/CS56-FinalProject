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
#include "Controls.hpp"
#include "Camera.hpp"
#include "Sound.hpp"

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

  // Initialize map
  std::string map_file = "Map.png";
  Map map;
  map.load_map(map_file, helper.renderer);

  // Initialize camera
  Camera *cam = Camera::get_instance(*map.get_start(), helper.getScreenWidth(),
                helper.getScreenHeight());

  // Initialize backgrounds
  Background menubg(game_modes::MENU, helper.renderer);
  Background controlsbg(game_modes::CONTROLS, helper.renderer);
  Background gameplay(game_modes::GAMEPLAY, helper.renderer);
  Background endgame(game_modes::ENDGAME, helper.renderer);

  // Initialize menu
  Menu menu(&menubg);
  menu.render(helper.renderer);

  // Initialize controls screen
  Controls controls(&controlsbg);

  // Initialize sound
  Sound sound;

  int game_mode = game_modes::MENU;
  Vec2D start_loc(map.get_start()->x, map.get_end()->y);
  Vec2D vel(5, 5);
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
          } else if (game_mode == game_modes::CONTROLS) {
              if (e.type == SDL_KEYDOWN) {
                  switch (e.key.keysym.sym) {
                      case SDLK_a:
                        game_mode = game_modes::MENU;
                  }
              }
          } else if (game_mode == game_modes::GAMEPLAY) {
              Command *command = input.handle_input(e);
              if (command != nullptr) {
                command->execute(p1);
              }
          }
      }
    }

    sound.play();

    SDL_SetRenderDrawColor(helper.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(helper.renderer);

    // displaying current game mode
    if (game_mode == game_modes::MENU) {
      menu.render(helper.renderer);
      menu.update();
    }
    else if (game_mode == game_modes::CONTROLS) {
      controls.render(helper.renderer);
      controls.update();
    }
    else if (game_mode == game_modes::GAMEPLAY) {
      gameplay.render(helper.renderer);
      map.get_obstacle_list()->render(helper.renderer);
      map.get_grappling_point_list()->render(helper.renderer);
      p1.render(helper.renderer);
      p1.update();
      gameplay.update();
      cam->update_location(p1.get_pos().toSDL_Point());
    }
    else if (game_mode == game_modes::ENDGAME) {
      endgame.render(helper.renderer);
      endgame.update();
    }

    SDL_RenderPresent(helper.renderer);
    SDL_Delay(30);
  }
  SDL_Quit();
  return 0;
}
