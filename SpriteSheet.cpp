#include "SpriteSheet.hpp"
#include "Camera.hpp"
#include "Player.hpp"

SpriteSheet::SpriteSheet() {}

// SpriteSheet constructor initializes variables
SpriteSheet::SpriteSheet(std::string path, SDL_Renderer* renderer,
                         int num_sprites, int frame)
    : m_num_sprites(num_sprites) {
  m_texture = nullptr;
  setSpriteSheet(path, renderer, frame);
}

// SpriteSheet destructor deallocates texture
SpriteSheet::~SpriteSheet() {
  if (m_texture != nullptr) {
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
    m_sprite_width = 0;
    m_sprite_height = 0;
  }
}

void SpriteSheet::setSpriteSheet(std::string path, SDL_Renderer* renderer,
                                 int frame) {
  // Load image at specified path
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());

  if (loadedSurface == nullptr) {
    printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
           IMG_GetError());
  } else {
    // Color key image
    SDL_SetColorKey(loadedSurface, SDL_TRUE,
                    SDL_MapRGBA(loadedSurface->format, 0, 0, 0, 0xFF));

    // Create texture from surface pixels
    m_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

    if (m_texture == nullptr) {
      printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(),
             SDL_GetError());
    } else {
      // Get image dimensions
      m_sprite_width = loadedSurface->w / m_num_sprites;
      m_sprite_height = loadedSurface->h;
    }

    initSurfaceByBlitting(loadedSurface, frame);

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }
}

// Renders texture to the screen
void SpriteSheet::render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip) {
  // retrieve the camera instance
  Camera* cam = Camera::get_instance();
  int offset_x = x - cam->get_location().x + cam->get_width() / 2;
  int offset_y = y - cam->get_location().y + cam->get_height() / 2;

  // Set rendering space and render to screen
  SDL_Rect renderQuad = {offset_x, offset_y, m_sprite_width, m_sprite_height};

  // Set clip rendering dimensions
  if (clip != NULL) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  // Render to screen
  SDL_RenderCopy(renderer, m_texture, clip, &renderQuad);
}

// Renders texture to the screen
void SpriteSheet::renderWithoutCamera(int x, int y, SDL_Renderer* renderer,
                                      SDL_Rect* clip) {
  // Set rendering space and render to screen
  SDL_Rect renderQuad = {x, y, m_sprite_width, m_sprite_height};

  // Set clip rendering dimensions
  if (clip != NULL) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  // Render to screen
  SDL_RenderCopy(renderer, m_texture, clip, &renderQuad);
}

void SpriteSheet::renderRotated(int x, int y, SDL_Renderer* renderer,
                                SDL_Rect* clip, double angle) {
  // retrieve the camera instance
  Camera* cam = Camera::get_instance();
  int offset_x = x - cam->get_location().x + cam->get_width() / 2;
  int offset_y = y - cam->get_location().y + cam->get_height() / 2;

  // Set rendering space and render to screen
  SDL_Rect renderQuad = {offset_x, offset_y, m_sprite_width, m_sprite_height};

  // Set clip rendering dimensions
  if (clip != NULL) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  // Render to screen
  SDL_RenderCopyEx(renderer, m_texture, clip, &renderQuad, angle, nullptr,
                   SDL_FLIP_NONE);
}

void SpriteSheet::renderCentered(int x, int y, SDL_Renderer* renderer,
                                 SDL_Rect* clip) {
  x -= m_sprite_width / 2;
  y -= m_sprite_height / 2;
  render(x, y, renderer, clip);
}

void SpriteSheet::renderRotatedCentered(int x, int y, SDL_Renderer* renderer,
                                        SDL_Rect* clip, double angle) {
  x -= m_sprite_width / 2;
  y -= m_sprite_height / 2;
  renderRotated(x, y, renderer, clip, angle);
}

// Renders correct sprite at given position
void SpriteSheet::renderSprite(int screenX, int screenY, SDL_Renderer* renderer,
                               int frameNumber) {
  int spriteNumber = frameNumber % m_num_sprites;
  SDL_Rect coords = {spriteNumber * m_sprite_width, 0, m_sprite_width,
                     m_sprite_height};
  render(screenX, screenY, renderer, &coords);
}

// Renders correct sprite at given position
void SpriteSheet::renderSpriteWithoutCamera(int screenX, int screenY,
                                            SDL_Renderer* renderer,
                                            int frameNumber) {
  int spriteNumber = frameNumber % m_num_sprites;
  SDL_Rect coords = {spriteNumber * m_sprite_width, 0, m_sprite_width,
                     m_sprite_height};
  renderWithoutCamera(screenX, screenY, renderer, &coords);
}

void SpriteSheet::renderSpriteCentered(int screenX, int screenY,
                                       SDL_Renderer* renderer,
                                       int frameNumber) {
  int spriteNumber = frameNumber % m_num_sprites;
  SDL_Rect coords = {spriteNumber * m_sprite_width, 0, m_sprite_width,
                     m_sprite_height};
  renderCentered(screenX, screenY, renderer, &coords);
}

void SpriteSheet::renderSpriteRotated(int screenX, int screenY,
                                      SDL_Renderer* renderer, int frameNumber,
                                      double angle) {
  int spriteNumber = frameNumber % m_num_sprites;
  SDL_Rect coords = {spriteNumber * m_sprite_width, 0, m_sprite_width,
                     m_sprite_height};
  renderRotated(screenX, screenY, renderer, &coords, angle * 180 / M_PI);
}

void SpriteSheet::renderSpriteRotatedCentered(int screenX, int screenY,
                                              SDL_Renderer* renderer,
                                              int frameNumber, double angle) {
  int spriteNumber = frameNumber % m_num_sprites;
  SDL_Rect coords = {spriteNumber * m_sprite_width, 0, m_sprite_width,
                     m_sprite_height};
  renderRotatedCentered(screenX, screenY, renderer, &coords,
                        angle * 180 / M_PI);
}

int SpriteSheet::getWidth() { return m_sprite_width; }

int SpriteSheet::getHeight() { return m_sprite_height; }

void SpriteSheet::setSurface(SDL_Surface surface) { m_surface = surface; }

SDL_Surface* SpriteSheet::getSurface() { return &m_surface; }

void SpriteSheet::initSurfaceByBlitting(SDL_Surface* source, int frame) {
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  unsigned int rmask = 0xff000000;
  unsigned int gmask = 0x00ff0000;
  unsigned int bmask = 0x0000ff00;
  unsigned int amask = 0x000000ff;
#else
  unsigned int rmask = 0x000000ff;
  unsigned int gmask = 0x0000ff00;
  unsigned int bmask = 0x00ff0000;
  unsigned int amask = 0xff000000;
#endif

  // Init surface to dimensions of sprite
  m_surface = *SDL_CreateRGBSurface(0, m_sprite_width, m_sprite_height,
                                    source->format->BitsPerPixel, rmask, gmask,
                                    bmask, amask);

  // Fill surface with transparent pixel value
  SDL_FillRect(getSurface(), NULL, transparent_pixel_value);

  // Blit surface
  SDL_Rect* source_rect = new SDL_Rect{(frame * m_sprite_width), 0,
                                       m_sprite_width, m_sprite_height};
  SDL_BlitSurface(source, source_rect, getSurface(), NULL);
}
