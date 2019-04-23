#include "Obstacle.hpp"

Obstacle::Obstacle() {}
Obstacle::Obstacle(std::string sprite_name, SDL_Rect bbox, SDL_Renderer* renderer) : m_bbox(bbox) {
  m_sprite = new SpriteSheet("images/" + sprite_name, renderer, 1);
}

SDL_Rect Obstacle::get_bbox() const { 
	return m_bbox; 
}
SpriteSheet* Obstacle::get_sprite() const { 
	return m_sprite; 
}
