#include "MiniMap.hpp"

MiniMap::MiniMap(Map* map, Player* player) : m_map(map), m_player(player) {}

MiniMap::~MiniMap() {}

void MiniMap::init(SDL_Renderer* renderer) {
  SDL_Surface* loadedSurface;

  loadedSurface = IMG_Load("images/point_map_icon.png");
  SDL_SetColorKey(loadedSurface, SDL_TRUE,
                  SDL_MapRGBA(loadedSurface->format, 0, 0, 0, 0xFF));
  point_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

  loadedSurface = IMG_Load("images/end_map_icon.png");
  SDL_SetColorKey(loadedSurface, SDL_TRUE,
                  SDL_MapRGBA(loadedSurface->format, 0, 0, 0, 0xFF));
  end_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

  loadedSurface = IMG_Load("images/obstacle_map_icon.png");
  SDL_SetColorKey(loadedSurface, SDL_TRUE,
                  SDL_MapRGBA(loadedSurface->format, 0, 0, 0, 0xFF));
  obstacle_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

  loadedSurface = IMG_Load("images/astronaut_mini.png");
  SDL_SetColorKey(loadedSurface, SDL_TRUE,
                  SDL_MapRGBA(loadedSurface->format, 0, 0, 0, 0xFF));
  player_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

  SDL_FreeSurface(loadedSurface);
}

void MiniMap::renderMiniMap(SDL_Renderer* renderer) {
  int SCREEN_WIDTH = 1280;
  int SCREEN_HEIGHT = 720;

  int map_width = 600;
  int map_height = 250;
  int map_center_x = 3 * SCREEN_WIDTH / 4;
  int map_center_y = 3 * SCREEN_HEIGHT / 4;

  SDL_Rect map_rect = {map_center_x, map_center_y, map_width, map_height};
  SDL_Surface* map = NULL;
  SDL_Texture* map_texture = NULL;

  map = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
  map_texture = SDL_CreateTextureFromSurface(renderer, map);

  SDL_SetTextureBlendMode(map_texture, SDL_BLENDMODE_BLEND);
  SDL_SetTextureAlphaMod(map_texture, 150);

  SDL_RenderCopy(renderer, map_texture, NULL, &map_rect);

  int scale = 20;
  int point_size = 120;

  SDL_Rect location;

  // Render obstacles
  for (auto obstacle : m_map->get_obstacle_list()->getObstacles()) {
    location = SDL_Rect{map_center_x + (obstacle.getLocation()->x) / scale,
                        map_center_y + (obstacle.getLocation()->y) / scale,
                        point_size / scale, point_size / scale};
    SDL_RenderCopy(renderer, obstacle_texture, NULL, &location);
  }
  // Render grappling points
  for (auto point : m_map->get_grappling_point_list()->getGrapplingPoints()) {
    location = SDL_Rect{map_center_x + (point.getLocation()->x) / scale,
                        map_center_y + (point.getLocation()->y) / scale,
                        point_size / scale, point_size / scale};
    SDL_RenderCopy(renderer, point_texture, NULL, &location);
  }
  // Render ends
  for (auto end : m_map->get_obstacle_list()->getEnds()) {
    location = SDL_Rect{map_center_x + (end.getLocation()->x) / scale,
                        map_center_y + (end.getLocation()->y) / scale,
                        point_size / scale, point_size / scale};
    SDL_RenderCopy(renderer, end_texture, NULL, &location);
  }

  int player_x = m_player->get_pos().toSDL_Point().x;
  int player_y = m_player->get_pos().toSDL_Point().y;
  location = SDL_Rect{map_center_x + player_x / scale - 12,
                      map_center_y + player_y / scale - 15, 24, 30};
  SDL_RenderCopy(renderer, player_texture, NULL, &location);
}

void MiniMap::update() {}
