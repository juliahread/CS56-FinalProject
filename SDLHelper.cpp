#include "SDLHelper.hpp"

SDLHelper::SDLHelper(const int screen_width, const int screen_height, char* window_name):SCREEN_WIDTH(screen_width), SCREEN_HEIGHT(screen_height), WINDOW_NAME(window_name) {
  bool initialized = SDLHelper::init();
  if (not initialized) {
    throw std::runtime_error("SDLHelper failed to initialize");
  }
}

SDLHelper::~SDLHelper() {
  SDLHelper::close();
}

bool SDLHelper::init() {
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else {
		//Set texture filtering to linear
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if(window == NULL) {
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else {
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags) & imgFlags)) {
					printf("SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

void SDLHelper::close() {
	//Destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int SDLHelper::getScreenWidth() const{
  return SCREEN_WIDTH;
}

int SDLHelper::getScreenHeight() const{
  return SCREEN_HEIGHT;
}

char* SDLHelper::getWindowName() const{
  return WINDOW_NAME;
}
