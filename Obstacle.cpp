#include "Obstacle.hpp"

Obstacle::Obstacle() {}
Obstacle::Obstacle(std::string sprite_name, int num_sprites, int frame_number, SDL_Renderer* renderer, SDL_Point loc) : m_loc(loc), m_frame_number(frame_number), m_num_sprites(num_sprites) {
  m_sprite = new SpriteSheet("images/" + sprite_name, renderer, m_num_sprites);
  m_bbox.x = m_loc.x - OBSTACLE_WIDTH / 2;
  m_bbox.y = m_loc.y - OBSTACLE_HEIGHT/ 2;
  m_bbox.w = OBSTACLE_WIDTH;
  m_bbox.h = OBSTACLE_HEIGHT;
}

void Obstacle::renderObstacle(SDL_Renderer* renderer) const {
  m_sprite->renderSpriteCentered(m_loc.x, m_loc.y, renderer, m_frame_number);
}

const SDL_Rect* Obstacle::get_bbox() const {
	return &m_bbox;
}
