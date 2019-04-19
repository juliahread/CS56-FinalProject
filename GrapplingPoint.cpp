#include "GrapplingPoint.hpp"

GrapplingPoint::GrapplingPoint() { } 

GrapplingPoint::GrapplingPoint(std::string sprite_name, SDL_Rect bbox, SDL_Renderer* renderer) : m_bbox(bbox)
{
	m_location.x = m_bbox.x;
	m_location.y = m_bbox.y;
	m_sprite = new SpriteSheet("images/" + sprite_name, renderer, 1);	
}

GrapplingPoint::GrapplingPoint(std::string sprite_name, int x, int y, SDL_Renderer* renderer)
{
	m_location.x = x;
	m_location.y = y;
	m_sprite = new SpriteSheet("images/" + sprite_name, renderer, 1);
}

/*GrapplingPoint::GrapplingPoint(int x, int y, SpriteSheet* sprite_sheet) : m_sprite(sprite_sheet)
{
  m_location.x = x;
  m_location.y = y;
  m_bbox.x = x - WIDTH / 2;
  m_bbox.y = y - HEIGHT/ 2;
  m_bbox.w = WIDTH;
  m_bbox.h = HEIGHT;
}

GrapplingPoint::GrapplingPoint(SDL_Point location, SpriteSheet* sprite_sheet) : m_location(location), m_image(sprite_sheet)
{
  m_bbox.x = location.x - WIDTH / 2;
  m_bbox.y = location.y - HEIGHT/ 2;
  m_bbox.w = WIDTH;
  m_bbox.h = HEIGHT;
}
GrapplingPoint::GrapplingPoint(SDL_Point location, SDL_Rect bbox, SpriteSheet *image) : m_location(location), m_bbox(bbox), m_image(image) { }
*/
void GrapplingPoint::render(SDL_Renderer *renderer) const{
  m_sprite->renderSprite(m_location.x, m_location.y, renderer, 0);
}

void GrapplingPoint::update(){}

const SDL_Point* GrapplingPoint::getLocation() const{
  return &m_location;
}
