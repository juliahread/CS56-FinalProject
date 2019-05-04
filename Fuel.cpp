#include "Fuel.hpp"

Fuel::Fuel() {}
Fuel::Fuel(std::string sprite_name, int num_sprites, int frame_number, SDL_Renderer* renderer, SDL_Rect bbox, float vel_x, float vel_y) : m_bbox(bbox), m_frame_number(frame_number), m_num_sprites(num_sprites), m_vel_x(vel_x), m_vel_y(vel_y) {
  m_loc = {bbox.x + WIDTH / 2, bbox.y + HEIGHT / 2};
  m_sprite = new SpriteSheet("images/" + sprite_name, renderer, m_num_sprites);
}

void Fuel::render(SDL_Renderer* renderer) const {
  m_sprite->renderSpriteCentered(m_loc.x, m_loc.y, renderer, m_frame_number);
}

void Fuel::update() { 
	m_loc = {static_cast<int>(m_loc.x + m_vel_x), static_cast<int>(m_loc.y + m_vel_y)}; 
}

SDL_Rect Fuel::get_bbox() const {
        return m_bbox;
}

SpriteSheet* Fuel::get_sprite() const {
        return m_sprite;
}
