#include "Obstacle.hpp"

Obstacle::Obstacle() {}
Obstacle::Obstacle(std::string sprite_name, int num_sprites, int frame_number, SDL_Rect bbox, SDL_Renderer* renderer)
  : m_num_sprites(num_sprites), m_frame_number(frame_number), m_bbox(bbox) {
  m_sprite = new SpriteSheet("images/" + sprite_name, renderer, m_num_sprites);
}

void Obstacle::renderObstacle(SDL_Renderer* renderer) const {
  m_sprite->renderSprite(m_bbox.x, m_bbox.y, renderer, m_frame_number);
}

const SDL_Rect* Obstacle::get_bbox() const {
	return &m_bbox;
}
