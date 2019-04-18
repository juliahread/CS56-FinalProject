#import "SDLHelper.hpp"
#import "SpriteSheet.hpp"

const int SCREEN_WIDTH = 1026;
const int SCREEN_HEIGHT = 540;
char* WINDOW_NAME = (char *)"Disaster at the 5 C's in 2200";
SDLHelper helper(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

int main(){
  // Flag to close the game
  bool quit = false;
  SpriteSheet bg("images/stars.png", helper.renderer, 1);

  //Event handler
  SDL_Event e;

  while(!quit){
    while(SDL_PollEvent(&e) != 0) {
      //User requests quit
      if(e.type == SDL_QUIT) {
        quit = true;
      }
    }
    SDL_SetRenderDrawColor(helper.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(helper.renderer);
    // Temporarily using sprite as background
    bg.renderSprite(0, 0, helper.renderer, 0);

    SDL_RenderPresent(helper.renderer);
    SDL_Delay(50);
  }
}
