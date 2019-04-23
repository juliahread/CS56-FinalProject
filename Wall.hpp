#include "Entity.hpp"
#include "Map.hpp"

class Wall : public Entity {
 private:
  SpriteSheet *m_sprite_sheet;
  Map map;

 public:
  void render(SDL_Renderer *renderer);
  void update();
};
