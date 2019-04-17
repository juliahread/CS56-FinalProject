#pragma once

#include <SDL2/SDL.h>

#include "SpriteSheet.hpp"
#include "Entity.hpp"

#include <list>

class Player;

class Obstacles : public Entity {
private:
	std::list<Obstacle> m_obstacles;
public:
	Obstacles();
	Obstacles(std::list<Obstacle>);
	~Obstacles();
	void render(SDL_Renderer*);
	void renderObstacle(Obstacle, SDL_Renderer*);
	void update();
	bool detectCollisions(Player);
};
