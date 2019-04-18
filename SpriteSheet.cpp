#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SpriteSheet.hpp"
#include <string>

//SpriteSheet constructor initializes variables
SpriteSheet::SpriteSheet(std::string path, SDL_Renderer* renderer, int num_sprites): m_num_sprites(num_sprites) {
	m_texture = nullptr;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == nullptr) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//Create texture from surface pixels
    m_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		if (m_texture == nullptr) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else {
			//Get image dimensions
			m_sprite_width = loadedSurface->w;
			m_sprite_height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
}

//SpriteSheet destructor deallocates texture
SpriteSheet::~SpriteSheet() {
	if (m_texture != nullptr) {
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_sprite_width = 0;
		m_sprite_height = 0;
	}
}

//Renders texture to the screen
void SpriteSheet::render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip) {
	//Set rendering space and render to screen
	SDL_Rect renderQuad = {x, y, m_sprite_width, m_sprite_height};

	//Set clip rendering dimensions
	if(clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(renderer, m_texture, clip, &renderQuad);
}

//Renders correct sprite at given position
void SpriteSheet::renderSprite( int screenX, int screenY, SDL_Renderer* renderer, int frameNumber) {
  int spriteNumber = frameNumber % m_num_sprites;
  SDL_Rect coords = { spriteNumber * m_sprite_width, 0, m_sprite_width, m_sprite_height};
  render(screenX, screenY, renderer, &coords);
}

int SpriteSheet::getWidth() {
	return m_sprite_width;
}

int SpriteSheet::getHeight() {
	return m_sprite_height;
}
