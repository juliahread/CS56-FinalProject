#include "Graphics.hpp"

Graphics* Graphics::m_instance = NULL;
bool Graphics::m_initialized = false;

/**
 * Creates a new Graphics instance
 *
 */
Graphics* Graphics::instance() {
    if (m_instance == NULL) {
        m_instance = new Graphics();
    }
    return m_instance;
}

/**
 * Returns true if the Graphics object was initialized
 *
 */
bool Graphics::initialized() {
    return m_initialized;
}

/**
 * Loads PNG surface
 *
 */
// bool Graphics::load_media() {
//
// }

/**
 * Loads surface to screen
 * @param: path = path to image
 *
 */
// static SDL_Surface* load_surface(std::string path) {
//
// }

/**
 * Frees resources
 *
 */
void Graphics::close() {
    delete m_instance;
    m_instance = NULL;
    m_initialized = false;
}

/**
 * Updates the graphics window
 *
 */
void Graphics::render() {
    SDL_UpdateWindowSurface(m_window);
}

//----------------------------------------------------------------------------//

/**
 * Ctor for Graphics object
 *
 */
Graphics::Graphics() {
    m_screen_surface = NULL;
    m_initialized = init();
}

/**
 * Dtor for Graphics object
 *
 */
Graphics::~Graphics() {
    // frees loaded image
    // SDL_FreeSurface( gPNGSurface );
    // gPNGSurface = NULL;

    // destroys window
    SDL_DestroyWindow(m_window);
    m_window = NULL;

    // quits SDL subsystems
    // IMG_Quit();
    SDL_Quit();
}

/**
 * Initializes SDL
 * @returns: true if SDL was successfully initialized
 *
 */
bool Graphics::init() {

    // initialize SDL
    if  (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    // create window
    m_window = SDL_CreateWindow("Disaster at the 5Cs in 2200",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_window == NULL) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // initialize PNG loading
    // int imgFlags = IMG_INIT_PNG;
    // if (!(IMG_Init(imgFlags) && imgFlags)) {
    //     printf("SDL_image could not initialize! SDL_image Error: %s\n",
    //             IMG_GetError());
    //     return false;
    // }

    // get window surface
    m_screen_surface = SDL_GetWindowSurface(m_window);

    return true;
}
