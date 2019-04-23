#include "SDLHelper.hpp"

<<<<<<< HEAD
SDLHelper::SDLHelper(const int screen_width, const int screen_height, char* window_name):SCREEN_WIDTH(screen_width), SCREEN_HEIGHT(screen_height), WINDOW_NAME(window_name) {
=======
SDLHelper::SDLHelper(const int screen_width, const int screen_height,
                     char* window_name)
    : SCREEN_WIDTH(screen_width),
      SCREEN_HEIGHT(screen_height),
      WINDOW_NAME(window_name) {
>>>>>>> 880ab8fe20c8f50848afd8d23e1751560aeaa317
  bool initialized = SDLHelper::init();
  if (not initialized) {
    throw std::runtime_error("SDLHelper failed to initialize");
  }
}

<<<<<<< HEAD
SDLHelper::~SDLHelper() {
  SDLHelper::close();
}

bool SDLHelper::init() {
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else {
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else {
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf("SDL_image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
					success = false;
				}
                //Initialize SDL_ttf
                if (TTF_Init() == -1) {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}

void SDLHelper::close() {
    //Free global font
    TTF_CloseFont(font);
    font = NULL;

	//Destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
    TTF_Quit();
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
=======
SDLHelper::~SDLHelper() { SDLHelper::close(); }

bool SDLHelper::init() {
  // Initialization flag
  bool success = true;
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    success = false;
  } else {
    // Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      printf("Warning: Linear texture filtering not enabled!");
    }
    // Create window
    window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      success = false;
    } else {
      // Create renderer for window
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
      if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n",
               SDL_GetError());
        success = false;
      } else {
        // Initialize renderer color
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        // Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
          printf("SDL_image could not initialize! SDL_mage Error: %s\n",
                 IMG_GetError());
          success = false;
        }
      }
    }
  }
  return success;
}

void SDLHelper::close() {
  // Destroy window
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  window = NULL;
  renderer = NULL;
  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

int SDLHelper::getScreenWidth() const { return SCREEN_WIDTH; }

int SDLHelper::getScreenHeight() const { return SCREEN_HEIGHT; }

char* SDLHelper::getWindowName() const { return WINDOW_NAME; }
>>>>>>> 880ab8fe20c8f50848afd8d23e1751560aeaa317
