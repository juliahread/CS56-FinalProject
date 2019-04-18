#include "GameManager.hpp"

GameManager* GameManager::m_instance = NULL;

/**
 * Creates a new GameManager instance
 *
 */
GameManager* GameManager::instance() {
    if (m_instance == NULL) {
        m_instance = new GameManager();
    }

    return m_instance;
}
/**
 * Frees resources
 *
 */
void GameManager::close() {
    delete m_instance;
    m_instance = NULL;
}

/**
 * Ctor for GameManager
 *
 */
GameManager::GameManager() {
    m_quit = false;
    // create a new graphics instance
    m_graphics = Graphics::instance();

    // if graphics initialization fails, quit
    if (!Graphics::initialized) {
        printf("Failed to initialize!\n");
        m_quit = true;
    }
}

/**
 * Dtor for GameManager
 *
 */
GameManager::~GameManager() {
    Graphics::close();
    m_graphics = NULL;
}

/**
 * Runs the game loop
 *
 */
void GameManager::run() {

    while (!m_quit) {
        // handle events on queue
        while (SDL_PollEvent(&m_events) != 0) {
            // if user requests quit, quit
            if (m_events.type == SDL_QUIT) {
                m_quit = true;
            }

            // update the surface
            m_graphics->render();

        }
    }

}
