#pragma once
#include "Entity.hpp"
#include "SpriteSheet.hpp"

class GrapplingPoint : public Entity {
private:
	SDL_Point m_location;
	SDL_Rect m_bbox;
	SpriteSheet *m_image;
  static constexpr int WIDTH = 5;
  static constexpr int HEIGHT = 5;
public:
	GrapplingPoint(int x, int y, SpriteSheet * sprite_sheet);
	GrapplingPoint(SDL_Point loc, SpriteSheet * sprite_sheet);
	GrapplingPoint(SDL_Point location, SDL_Rect bbox, SpriteSheet *image);
  void render(SDL_Renderer *renderer) const;
  void update();
};
