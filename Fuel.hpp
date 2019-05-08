#pragma once

#include "SDLHelper.hpp"
#include "SpriteSheet.hpp"
#include "Vec2D.hpp"
#include <cmath>

class Fuel {
private:
	SDL_Rect m_bbox;
	SpriteSheet* m_sprite;
	SDL_Point m_pos;
	int m_frame_number;
	int m_num_sprites;
	float m_vel_x;
	float m_vel_y;
public:
	Fuel();
	Fuel(std::string, int, int, SDL_Renderer*, SDL_Rect, float, float);
    static constexpr float FUEL_AMOUNT = 5;
	static constexpr int WIDTH = 35;
	static constexpr int HEIGHT = 35;
	void render(SDL_Renderer*) const;
	void update();
	SDL_Rect get_bbox() const;
	SpriteSheet* get_sprite() const;
};
