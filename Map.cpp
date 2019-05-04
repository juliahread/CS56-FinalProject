#include "Map.hpp"

Map::Map() { 
  m_twister = std::mt19937(std::time(NULL));
  rand_range = std::uniform_int_distribution<int>(-10, 10);  // Randomize fuel generation
}

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

// Number of screen pixels per map pixel
const int MAP_RATIO = 20;

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

  SDL_Surface* map_image = IMG_Load(file.c_str());
  SDL_LockSurface(map_image);

  Uint32 pixel = 0;
  Uint8 red = 0, green = 0, blue = 0;

  // Number of obstacles in most recent sequence of obstacles
  int num_obstacles = 0;

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
                                         {(x-1) * MAP_RATIO, y * MAP_RATIO,
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
            obstacles.push_back(
                Obstacle("rock.png", 4, 3, renderer,
                         {(x) * MAP_RATIO, y * MAP_RATIO,
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
        m_end = {x * MAP_RATIO, y * MAP_RATIO};
      } else if (pixels_equal_tuple(depot_color, red, green, blue)) {
        depots.push_back(
            Depot("dining_hall.png", 1, 0, renderer,
                  {x * MAP_RATIO, y * MAP_RATIO, Depot::WIDTH, Depot::HEIGHT}));
      } else if (pixels_equal_tuple(background_color, red, green, blue)) {
      } else {
        std::cout << "Unrecognized color at (" << x + 1 << ", " << y + 1 << ")";
      }
    }
  }
  SDL_FreeSurface(map_image);

  m_obstacle_list = new Obstacles(obstacles, depots);
  m_grappling_point_list = new GrapplingPoints(grappling_points);
}

Obstacles* Map::get_obstacle_list() { return m_obstacle_list; }

GrapplingPoints* Map::get_grappling_point_list() {
  return m_grappling_point_list;
}

SDL_Point* Map::get_start() { return &m_start; }

SDL_Point* Map::get_end() { return &m_end; }

void Map::update_depots_and_fuel(SDL_Renderer* renderer) {
  if (!m_obstacle_list->m_depots.empty()) {
    // Spew fuel from all depots
    for (auto const& depot : m_obstacle_list->m_depots) {
      m_fuel_list.push_back(Fuel(
          "fuel.png", 1, 1, renderer,
          {depot.m_loc.x, depot.m_loc.y, Fuel::WIDTH, Fuel::HEIGHT},
          rand_range(m_twister), rand_range(m_twister)));
    }
  }
  // Update fuel
  if (!m_fuel_list.empty()) {
    for (auto itr = begin(m_fuel_list); itr != end(m_fuel_list); ++itr) {
      itr->update();
    }
  }
}

void Map::render_fuel(SDL_Renderer* renderer) {
  if (!m_fuel_list.empty()) {
    for (auto const& fuel : m_fuel_list) {
      fuel.render(renderer);
    }
  }
}
