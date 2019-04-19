#include "GrapplingPoint.hpp"

GrapplingPoint::GrapplingPoint() { }

GrapplingPoint::GrapplingPoint(std::string sprite_name, SDL_Rect bbox, SDL_Renderer* renderer) : m_bbox(bbox)
{
	m_location.x = m_bbox.x + m_bbox.w / 2;
	m_location.y = m_bbox.y + m_bbox.h / 2;
	m_sprite = new SpriteSheet("images/" + sprite_name, renderer, 1);
}

GrapplingPoint::GrapplingPoint(std::string sprite_name, int x, int y, SDL_Renderer* renderer)
{
	m_location.x = x;
	m_location.y = y;
	m_sprite = new SpriteSheet("images/" + sprite_name, renderer, 1);
  int width = m_sprite->getWidth();
  int height = m_sprite->getHeight();
  m_bbox.x = x - width / 2;
  m_bbox.y = y - height/ 2;
  m_bbox.w = width;
  m_bbox.h = height;
}

void GrapplingPoint::render(SDL_Renderer *renderer) const{
  m_sprite->renderSpriteCentered(m_location.x, m_location.y, renderer, 0);
}

void GrapplingPoint::update(){}

const SDL_Point* GrapplingPoint::getLocation() const{
  return &m_location;
}
