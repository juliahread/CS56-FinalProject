#include "GrapplingPoints.hpp"
#include "InputHandler.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"
#include "Vec2D.hpp"
#include "Text.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
char *WINDOW_NAME = (char *)"Disaster at the 5C's in 2200";
SDLHelper helper(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
enum modes { menu, controls, gameplay, endgame };

#undef main
int main() {
  // Flag to close the game
  bool quit = false;
  SpriteSheet bg("images/menu_play.png", helper.renderer, 1);
  SpriteSheet star("images/starSprites.png", helper.renderer, 6);

  // Initialize map
  std::string map_file = "Map.png";
  Map map;
  map.load_map(map_file, helper.renderer);

  // load menu text
  SDL_Color textColor = {255, 255, 255};
  SDL_Point pos1 = {335, 78};
  Text text1("Disaster", textColor, pos1, helper.renderer);
  text1.loadFont(100);
  SDL_Point pos2 = {335, 190};
  Text text2("at the 5Cs", textColor, pos2, helper.renderer);
  text2.loadFont(75);
  SDL_Point pos3 = {335, 300};
  Text text3("in 2200", textColor, pos3, helper.renderer);
  text3.loadFont(110);


  int mode = gameplay;
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
        Command *command = input.handle_input(e, mode == gameplay);
        if (command != nullptr) {
          command->execute(p1);
        }
      }
    }
    SDL_SetRenderDrawColor(helper.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(helper.renderer);
    // Temporarily using sprite as background
    bg.renderSprite(0, 0, helper.renderer, 0);
    p1.render(helper.renderer);
    p1.update();

    text1.render(helper.renderer);
    text2.render(helper.renderer);
    text3.render(helper.renderer);

    map.get_obstacle_list()->render(helper.renderer);
    map.get_grappling_point_list()->render(helper.renderer);


    SDL_RenderPresent(helper.renderer);
    SDL_Delay(30);
  }
  return 0;
}
