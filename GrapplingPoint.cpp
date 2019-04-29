#include "GrapplingPoint.hpp"

GrapplingPoint::GrapplingPoint() {}

GrapplingPoint::GrapplingPoint(std::string sprite_name, SDL_Rect bbox, SDL_Renderer* renderer) : m_bbox(bbox) {
  m_pos = {bbox.x + WIDTH / 2, bbox.y + HEIGHT / 2};
  m_sprite = new SpriteSheet("images/" + sprite_name, renderer, 1);
}

GrapplingPoint::GrapplingPoint(std::string sprite_name, int x, int y, SDL_Renderer* renderer) {
  m_pos.x = m_bbox.x + WIDTH / 2;
  m_pos.y = m_bbox.y + HEIGHT / 2;
  m_sprite = new SpriteSheet("images/" + sprite_name, renderer, 1);
  m_bbox.x = x;
  m_bbox.y = y;
  m_bbox.w = WIDTH;
  m_bbox.h = HEIGHT;
}

void GrapplingPoint::render(SDL_Renderer* renderer) const {
  m_sprite->renderSpriteCentered(m_pos.x, m_pos.y, renderer, 0);
}

void GrapplingPoint::update() {}

const SDL_Point* GrapplingPoint::getLocation() const { 
	return &m_pos; 
}
