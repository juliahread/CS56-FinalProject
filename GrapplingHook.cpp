#include "GrapplingHook.hpp"
#include "Player.hpp"

GrapplingHook::GrapplingHook(Player *shooter, Map *map) : m_fired(false), m_anchor(nullptr), m_shooter(shooter), m_map(map)
{
  // TODO: Load the appropriate sprite sheet
  m_bbox = nullptr;
  m_wrap_points = std::vector<SDL_Point>();
};

void GrapplingHook::shoot(SDL_Point *anchor){
  // TODO: Implement fully
  m_anchor = anchor;
  m_fired = true;
};

void GrapplingHook::detatch(){
  // TODO: Implement fully
  m_anchor = nullptr;
  m_fired = false;
}

void GrapplingHook::render(SDL_Renderer *renderer) const{
  if (m_fired){
    // Draw each line from the shooter to the anchor with any wrap points in between
    SDL_Point start = m_shooter->get_pos();
    for (auto it : m_wrap_points) {
      SDL_Point next = it;
      SDL_RenderDrawLine(renderer, start.x, start.y, next.x, next.y);
      start = next;
    }
    SDL_Point next = *m_anchor;
    SDL_RenderDrawLine(renderer, start.x, start.y, next.x, next.y);
  }
}

void GrapplingHook::update(){
  // TODO: Implement fully
}