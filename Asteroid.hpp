#include <Entity.hpp>

class Asteroid : public Entity {
  private:
    SDL_image SpriteSheet;
  public:
    void render();
    void update();
}
