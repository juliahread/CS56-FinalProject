#include <ctime>
#include "Background.hpp"
#include "Camera.hpp"
#include "Controls.hpp"
#include "FuelDisplay.hpp"
#include "GrapplingPoints.hpp"
#include "InputHandler.hpp"
#include "Jetpack.hpp"
#include "LoseScreen.hpp"
#include "Map.hpp"
#include "Menu.hpp"
#include "MenuInputHandler.hpp"
#include "MiniMap.hpp"
#include "Modes.hpp"
#include "Player.hpp"
#include "SDLHelper.hpp"
#include "Scores.hpp"
#include "Sound.hpp"
#include "SpriteSheet.hpp"
#include "Star.hpp"
#include "Text.hpp"
#include "Timer.hpp"
#include "Vec2D.hpp"
#include "WinScreen.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
char *WINDOW_NAME = (char *)"Disaster at the 5C's in 2200";
SDLHelper helper(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

std::string map_file = "Map.png";
std::string score_file = "Highscores.txt";

#undef main
int main() {
  // Make rand() actually random
  srand(std::time(NULL));
  // Flag to close the game
  bool quit = false;

  // Initialize map
  Map map;
  map.load_map(map_file, helper.renderer);

  Scores scores(score_file);

  // Initialize camera
  Camera *cam = Camera::get_instance(*map.get_start(), helper.getScreenWidth(),
                                     helper.getScreenHeight());

  // Initialize backgrounds
  Background menubg(game_modes::MENU, helper.renderer, cam);
  Background controlsbg(game_modes::CONTROLS, helper.renderer, cam);
  Background gameplay(game_modes::GAMEPLAY, helper.renderer, cam);
  Background endgame(game_modes::WIN, helper.renderer, cam);

  // Initialize menu
  Menu menu(&menubg);

  // Initialize controls screen
  Controls controls(&controlsbg, helper.renderer);

  // Initialize sound
  Sound sound;

  int game_mode = game_modes::MENU;
  Vec2D start_loc(map.get_start()->x, map.get_start()->y);
  Vec2D vel(5, 5);
  Player p1(start_loc, vel, Player::MAX_FUEL, helper.renderer, &map);

  // Initialize fuel display
  FuelDisplay fuel(p1.get_fuel(), Player::MAX_FUEL);

  // Initialize timer
  Timer timer;
  timer.set(100);

  // Initialize minimap
  MiniMap minimap(&map, &p1);
  minimap.init(helper.renderer);

  // Event handler
  SDL_Event e;
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);
  InputHandler input(&sound);
  MenuInputHandler menu_input(&game_mode, &menu, &timer);
  WinScreen win_input(&scores, &timer, game_mode);
  LoseScreen lose;

  while (!quit) {
    // Handle single mouse events
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
                   game_mode == game_modes::HIGHSCORES ||
                   game_mode == game_modes::LOSE) {
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
        } else if (game_mode == game_modes::WIN) {
          win_input.handle_input(e);
        }
      }
    }

    // Handle continous key inputs for jetpack
    if (game_mode == game_modes::GAMEPLAY) {
      if (keystate[SDL_SCANCODE_W]) {
        input.m_game_w_button->execute(p1);
      }
      if (keystate[SDL_SCANCODE_S]) {
        input.m_game_s_button->execute(p1);
      }
      if (keystate[SDL_SCANCODE_A]) {
        input.m_game_a_button->execute(p1);
      }
      if (keystate[SDL_SCANCODE_D]) {
        input.m_game_d_button->execute(p1);
      }
    }

    sound.play();

    SDL_SetRenderDrawColor(helper.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(helper.renderer);

    // Check for win or lose conditions
    if (game_mode == game_modes::GAMEPLAY) {
      if (p1.stuck() or timer.get_time() == 0) {
        game_mode = game_modes::LOSE;
        p1.reset(start_loc, vel, Player::MAX_FUEL);
      }
      if (p1.won()) {
        std::cout << "won" << std::endl;
        game_mode = game_modes::WIN;
        timer.stop();
        p1.reset(start_loc, vel, Player::MAX_FUEL);
      }
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
        gameplay.render(helper.renderer);
        map.get_obstacle_list()->render(helper.renderer);
        map.get_obstacle_list()->update(p1, helper.renderer, map.map_width,
                                        map.map_height);
        map.get_grappling_point_list()->render(helper.renderer);
        minimap.renderMiniMap(helper.renderer);
        p1.render(helper.renderer);
        p1.update();
        gameplay.update();
        cam->update_location(p1.get_pos().toSDL_Point());
        fuel.render(helper.renderer);
        fuel.update();
        timer.render(helper.renderer);
        timer.update();
        break;
      case game_modes::WIN:
        endgame.render(helper.renderer);
        endgame.update();
        win_input.render(helper.renderer);
        break;
      case game_modes::LOSE:
        endgame.render(helper.renderer);
        endgame.update();
        lose.render(helper.renderer);
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
