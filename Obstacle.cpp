#include "Obstacle.hpp"

// Obstacle::Obstacle() { }
Obstacle::Obstacle(SDL_Rect bbox, SpriteSheet sprite) : m_bbox(bbox), m_image(sprite) { }
