#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"
#include "Player.hpp"
#include "GrapplingPoints.hpp"
#include "Map.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
char* WINDOW_NAME = (char *)"Disaster at the 5C's in 2200";
SDLHelper helper(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
enum modes {
  menu,
  controls,
  gameplay,
  endgame
};

#undef main
int main(int argc, char* argv[]){
  // Flag to close the game
  bool quit = false;
  SpriteSheet bg("images/menu_play.png", helper.renderer, 1);
  SpriteSheet star("images/starSprites.png", helper.renderer, 6);
  int mode = menu;
  SDL_Point start;
  start.x = 10;
  start.y = 10;
  SDL_Point start_vel;
  start_vel.x = 10;
  start_vel.y = 10;
  Player p1(start, start_vel, 100, helper.renderer);
  GrapplingPoints grapples(helper.renderer);
  grapples.addPoint(20,20);
  grapples.addPoint(30,30);
  grapples.addPoint(40,40);

  //Event handler
  SDL_Event e;

  //Initialize map
  std::string map_file = "Map.png";
  Map map;
  map.load_map(map_file, helper.renderer);

  while(!quit){
    while(SDL_PollEvent(&e) != 0) {
      //User requests quit
      if(e.type == SDL_QUIT) {
        quit = true;
      }
      else if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
          case SDLK_w:
            if (mode == menu) {
              bg.setSpriteSheet("images/menu_play.png", helper.renderer);
            }
            break;
          case SDLK_s:
            if (mode == menu) {
              bg.setSpriteSheet("images/menu_controls.png", helper.renderer);
            }
            break;
        }
      }
    }
    SDL_SetRenderDrawColor(helper.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(helper.renderer);
    // Temporarily using sprite as background
    bg.renderSprite(0, 0, helper.renderer, 0);
    p1.render(helper.renderer);
    p1.update();

    grapples.render(helper.renderer);
    // grapples.update();

	map.get_obstacle_list()->render(helper.renderer);
	//map.get_grappling_point_list()->render(helper.renderer);

    SDL_RenderPresent(helper.renderer);
    SDL_Delay(100);
  }
  return 0;
}
