#include "Obstacle.hpp"

Obstacle::Obstacle() {}
Obstacle::Obstacle(std::string sprite_name, int num_sprites, int frame_number, SDL_Renderer* renderer, SDL_Rect bbox) : m_bbox(bbox), m_frame_number(frame_number), m_num_sprites(num_sprites) {
  m_loc = {bbox.x + WIDTH / 2, bbox.y + HEIGHT / 2};
  m_sprite = new SpriteSheet("images/" + sprite_name, renderer, m_num_sprites, frame_number);

}

void Obstacle::renderObstacle(SDL_Renderer* renderer) const {
  m_sprite->renderSpriteCentered(m_loc.x, m_loc.y, renderer, m_frame_number);
}

SDL_Rect Obstacle::get_bbox() const {
	return m_bbox;
}

SpriteSheet* Obstacle::get_sprite() const { 
	return m_sprite; 
}