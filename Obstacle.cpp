#include "Obstacle.hpp"

Obstacle::Obstacle() { }
Obstacle::Obstacle(SDL_Rect m_bbox, SpriteSheet sprite) : m_bbox(this->m_bbox), m_sprite(this->m_sprite) { }
