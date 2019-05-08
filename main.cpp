#include "Background.hpp"
#include "Camera.hpp"
#include "Controls.hpp"
#include "FuelDisplay.hpp"
#include "GrapplingPoints.hpp"
#include "InputHandler.hpp"
#include "Jetpack.hpp"
#include "Map.hpp"
#include "Menu.hpp"
#include "MenuInputHandler.hpp"
#include "Player.hpp"
#include "SDLHelper.hpp"
#include "Scores.hpp"
#include "Sound.hpp"
#include "SpriteSheet.hpp"
#include "Star.hpp"
#include "Text.hpp"
#include "Timer.hpp"
#include "Vec2D.hpp"
#include "Modes.hpp"
#include <ctime>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
char *WINDOW_NAME = (char *)"Disaster at the 5C's in 2200";
SDLHelper helper(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

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

  std::string score_file = "Highscores.txt";
  Scores scores(score_file);

  // Initialize camera
  Camera *cam = Camera::get_instance(*map.get_start(), helper.getScreenWidth(),
                                     helper.getScreenHeight());

  // Initialize backgrounds
  Background menubg(game_modes::MENU, helper.renderer, cam);
  Background controlsbg(game_modes::CONTROLS, helper.renderer, cam);
  Background gameplay(game_modes::GAMEPLAY, helper.renderer, cam);
  Background endgame(game_modes::ENDGAME, helper.renderer, cam);

  // Initialize menu
  Menu menu(&menubg);

  // Initialize controls screen
  Controls controls(&controlsbg);

  // Initialize sound
  Sound sound;

  int game_mode = game_modes::MENU;
  Vec2D start_loc(map.get_start()->x, map.get_start()->y);
  Vec2D vel(5, 5);
  int max_fuel = 100;
  Player p1(start_loc, vel, max_fuel, helper.renderer, &map);

  // Initialize fuel display
  FuelDisplay fuel(p1.get_fuel(), p1.MAX_FUEL);

  // Initialize timer
  Timer timer;
  timer.set(100);

  // Event handler
  SDL_Event e;
  InputHandler input(&sound);
  MenuInputHandler menu_input(&game_mode, &menu, &timer);

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
        } else if (game_mode == game_modes::CONTROLS ||
                   game_mode == game_modes::HIGHSCORES) {
          if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
              case SDLK_a:
                game_mode = game_modes::MENU;
                sound.playRefuel();
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

    if(p1.stuck() or timer.get_time() == 0){
      game_mode = game_modes::LOSE;
    }

    // displaying current game mode
    switch (game_mode) {
      case game_modes::MENU:
        menu.render(helper.renderer);
        menu.update();
        break;
      case game_modes::CONTROLS:
        controls.render(helper.renderer);
        controls.update();
        break;
      case game_modes::GAMEPLAY:
        // Check for win condition
        for (const auto &end : map.get_obstacle_list()->getEnd()) {
          SDL_Surface *e_surface = end.get_sprite()->getSurface();
          if (map.get_obstacle_list()->SDL_Collide(
                  p1.get_sprite()->getSurface(), p1.get_bbox().x,
                  p1.get_bbox().y, e_surface, end.get_bbox().x,
                  end.get_bbox().y)) {
            // Win
            quit = true;
          }
        }

        gameplay.render(helper.renderer);
        map.get_obstacle_list()->render(helper.renderer);
        map.get_obstacle_list()->update(p1, helper.renderer, map.map_width,
                                        map.map_height);
        map.get_grappling_point_list()->render(helper.renderer);
        p1.render(helper.renderer);
        p1.update();
        gameplay.update();
        cam->update_location(p1.get_pos().toSDL_Point());
        fuel.render(helper.renderer);
        fuel.update();
        timer.render(helper.renderer);
        timer.update();
        break;
      case game_modes::ENDGAME:
      case game_modes::LOSE:
        endgame.render(helper.renderer);
        endgame.update();
        break;
      case game_modes::HIGHSCORES:
        endgame.render(helper.renderer);
        scores.render(helper.renderer);
        break;
    }
    SDL_RenderPresent(helper.renderer);
    SDL_Delay(30);
  }
  SDL_Quit();
  return 0;
}
