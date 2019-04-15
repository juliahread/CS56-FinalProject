#include <Entity.hpp>
#include <Map.hpp>

class Wall : public Entity {
  private:
    SDL_image SpriteSheet;
    Map map;
  public:
    void render();
    void update();
}
