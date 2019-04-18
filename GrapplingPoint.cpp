#include "GrapplingPoint.hpp"

GrapplingPoint::GrapplingPoint(int x, int y, SpriteSheet* sprite_sheet) : m_image(sprite_sheet)
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

void GrapplingPoint::render(SDL_Renderer *renderer) const{
  m_image->renderSprite(m_location.x, m_location.y, renderer, 0);
}

void GrapplingPoint::update(){}

const SDL_Point* GrapplingPoint::getLocation() const{
  return &m_location;
}
