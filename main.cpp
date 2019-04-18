#include "GameManager.hpp"

int main(int argc, char** argv) {

    GameManager* game = GameManager::instance();
    game->run();
    GameManager::close();
    game = NULL;

    return 0;

}
