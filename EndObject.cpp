#include "EndObject.hpp"

EndObject::EndObject() {}
EndObject::EndObject(std::string sprite_name, int num_sprites, int frame_number,
                     SDL_Renderer* renderer, SDL_Rect bbox)
    : m_bbox(bbox), m_frame_number(frame_number), m_num_sprites(num_sprites) {
  m_pos = {bbox.x + WIDTH / 2, bbox.y + HEIGHT / 2};
  m_sprite = new SpriteSheet("images/" + sprite_name, renderer, m_num_sprites,
                             frame_number);
}

void EndObject::render(SDL_Renderer* renderer) const {
  m_sprite->renderSpriteCentered(m_pos.x, m_pos.y, renderer, m_frame_number);
}

SDL_Rect EndObject::get_bbox() const { return m_bbox; }

SpriteSheet* EndObject::get_sprite() const { return m_sprite; }

const SDL_Point* EndObject::getLocation() const { return &m_pos; }
