#include "GrapplingPoint.hpp"

GrapplingPoint::GrapplingPoint() { }
GrapplingPoint::GrapplingPoint(SDL_Point m_location, SDL_Rect m_bbox, SpriteSheet m_image) : m_location(this->m_location), m_bbox(this->m_bbox), m_image(this->m_image) { }
