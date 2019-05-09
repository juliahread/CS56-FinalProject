#include "Map.hpp"
#include "Camera.hpp"

Map::Map() {}

Map::~Map() {
  delete m_obstacle_list;
  delete m_grappling_point_list;
}

// Define map image relationships
std::tuple<Uint8, Uint8, Uint8> obstacle_color =
    std::make_tuple(255, 255, 255);  // black
std::tuple<Uint8, Uint8, Uint8> grappling_hook_color =
    std::make_tuple(0, 255, 0);  // magenta
std::tuple<Uint8, Uint8, Uint8> start_color =
    std::make_tuple(0, 255, 255);  // red
std::tuple<Uint8, Uint8, Uint8> end_color =
    std::make_tuple(255, 0, 255);  // green
std::tuple<Uint8, Uint8, Uint8> background_color =
    std::make_tuple(0, 0, 0);  // white
std::tuple<Uint8, Uint8, Uint8> depot_color =
    std::make_tuple(255, 255, 0);  // blue

// From the SDL documentation
Uint32 get_pixel(SDL_Surface* surface, int x, int y) {
  int bpp = surface->format->BytesPerPixel;
  Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

  switch (bpp) {
    case 1:
      return *p;
      break;
    case 2:
      return *(Uint16*)p;
      break;
    case 3:
      if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
        return p[0] << 16 | p[1] << 8 | p[2];
      else
        return p[0] | p[1] << 8 | p[2] << 16;
      break;
    case 4:
      return *(Uint32*)p;
      break;
    default:
      return 0;
  }
}

bool Map::pixels_equal_tuple(std::tuple<Uint8, Uint8, Uint8>& tuple, Uint8& red,
                             Uint8& green, Uint8& blue) {
  return ((red == std::get<0>(tuple)) && (green == std::get<1>(tuple)) &&
          (blue == std::get<2>(tuple)));
}

// Loads the map with objects pointing to &renderer from a .png file with an
// alpha layer
void Map::load_map(std::string file, SDL_Renderer* renderer) {
  std::vector<Obstacle> obstacles;
  std::vector<GrapplingPoint> grappling_points;
  std::vector<Depot> depots;
  std::vector<EndObject> ends;

  SDL_Surface* map_image = IMG_Load(("images/" + file).c_str());
  SDL_LockSurface(map_image);

  Uint32 pixel = 0;
  Uint8 red = 0, green = 0, blue = 0;

  // Number of obstacles in most recent sequence of obstacles
  int num_obstacles = 0;

  // Set map dimensions in screen space
  map_width = map_image->w * MAP_RATIO;
  map_height = map_image->h * MAP_RATIO;

  // Iterates through the map image left->right, top->bottom and creates objects
  // for specially colored pixels
  for (int y = 0; y < map_image->h; y++) {
    for (int x = 0; x < map_image->w; x++) {
      pixel = ~get_pixel(map_image, x, y);
      SDL_GetRGB(pixel, map_image->format, &red, &green, &blue);
      if (pixels_equal_tuple(obstacle_color, red, green, blue)) {
        num_obstacles++;
      } else {
        // Create finished obstacle sequence
        if (num_obstacles > 0) {
          if (num_obstacles == 1) {
            obstacles.push_back(Obstacle("rock.png", 4, 0, renderer,
                                         {(x - 1) * MAP_RATIO, y * MAP_RATIO,
                                          Obstacle::WIDTH, Obstacle::HEIGHT}));
          } else if (num_obstacles == 2) {
            obstacles.push_back(Obstacle("rock.png", 4, 1, renderer,
                                         {(x - 2) * MAP_RATIO, y * MAP_RATIO,
                                          Obstacle::WIDTH, Obstacle::HEIGHT}));
            obstacles.push_back(Obstacle("rock.png", 4, 3, renderer,
                                         {(x - 1) * MAP_RATIO, y * MAP_RATIO,
                                          Obstacle::WIDTH, Obstacle::HEIGHT}));
          } else if (num_obstacles > 2) {
            obstacles.push_back(
                Obstacle("rock.png", 4, 1, renderer,
                         {(x - num_obstacles) * MAP_RATIO, y * MAP_RATIO,
                          Obstacle::WIDTH, Obstacle::HEIGHT}));
            for (int i = num_obstacles - 1; i; i--) {
              obstacles.push_back(
                  Obstacle("rock.png", 4, 2, renderer,
                           {(x - i) * MAP_RATIO, y * MAP_RATIO, Obstacle::WIDTH,
                            Obstacle::HEIGHT}));
            }
            obstacles.push_back(Obstacle("rock.png", 4, 3, renderer,
                                         {x * MAP_RATIO, y * MAP_RATIO,
                                          Obstacle::WIDTH, Obstacle::HEIGHT}));
          }
          num_obstacles = 0;
        }
      }

      if (pixels_equal_tuple(grappling_hook_color, red, green, blue)) {
        grappling_points.push_back(
            GrapplingPoint("target.png",
                           {x * MAP_RATIO, y * MAP_RATIO, GrapplingPoint::WIDTH,
                            GrapplingPoint::HEIGHT},
                           renderer));

      } else if (pixels_equal_tuple(start_color, red, green, blue)) {
        m_start = {x * MAP_RATIO, y * MAP_RATIO};
      } else if (pixels_equal_tuple(end_color, red, green, blue)) {
        ends.push_back(EndObject("end.png", 1, 0, renderer,
                                 {x * MAP_RATIO, y * MAP_RATIO,
                                  EndObject::WIDTH, EndObject::HEIGHT}));
      } else if (pixels_equal_tuple(depot_color, red, green, blue)) {
        depots.push_back(
            Depot("oldenborg.png", 1, 0, renderer,
                  {x * MAP_RATIO, y * MAP_RATIO, Depot::WIDTH, Depot::HEIGHT}));
      } else if (pixels_equal_tuple(background_color, red, green, blue)) {
      }
    }
  }
  SDL_FreeSurface(map_image);

  m_obstacle_list = new Obstacles(obstacles, depots, ends);
  m_grappling_point_list = new GrapplingPoints(grappling_points);
}

Obstacles* Map::get_obstacle_list() { return m_obstacle_list; }

GrapplingPoints* Map::get_grappling_point_list() {
  return m_grappling_point_list;
}

SDL_Point* Map::get_start() { return &m_start; }


void Map::initMinimap(SDL_Renderer* renderer) {
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

  SDL_FreeSurface(loadedSurface);
}

void Map::renderMinimap(SDL_Renderer* renderer) {
  Camera* cam = Camera::get_instance();
  int cam_x = cam->get_location().x;
  int cam_y = cam->get_location().y;

  int SCREEN_WIDTH = 1280;
  int SCREEN_HEIGHT = 720;

  int map_width = 600;
  int map_height = 250;
  int map_center_x = map_width / 2;
  int map_center_y = SCREEN_HEIGHT - (map_height / 2);

  // Map begins in left corner
  SDL_Rect map = {0, SCREEN_HEIGHT - map_height, map_width, map_height};
  const SDL_Rect* m = &map;

  int scale = 15;
  int point_size = 90;

  SDL_Rect* result = new SDL_Rect();
  SDL_Rect* location;

  // Render obstacles
  for (auto obstacle : m_obstacle_list->getObstacles()) {
    location =
        new SDL_Rect{map_center_x + (obstacle.getLocation()->x - cam_x) / scale,
                     map_center_y + (obstacle.getLocation()->y - cam_y) / scale,
                     point_size / scale, point_size / scale};
    if (SDL_IntersectRect(&map, location, result)) {
      SDL_RenderCopy(renderer, obstacle_texture, NULL, location);
    }

    delete location;
  }
  // Render grappling points
  for (auto point : m_grappling_point_list->getGrapplingPoints()) {
    location =
        new SDL_Rect{map_center_x + (point.getLocation()->x - cam_x) / scale,
                     map_center_y + (point.getLocation()->y - cam_y) / scale,
                     point_size / scale, point_size / scale};
    if (SDL_IntersectRect(&map, location, result)) {
      SDL_RenderCopy(renderer, point_texture, NULL, location);
    }

    delete location;
  }
  // Render ends
  for (auto end : m_obstacle_list->getEnds()) {
    location =
        new SDL_Rect{map_center_x + (end.getLocation()->x - cam_x) / scale,
                     map_center_y + (end.getLocation()->y - cam_y) / scale,
                     point_size / scale, point_size / scale};
    if (SDL_IntersectRect(&map, location, result)) {
      SDL_RenderCopy(renderer, end_texture, NULL, location);
    }
    delete location;
  }

  delete result;
}
