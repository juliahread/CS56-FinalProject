#pragma once

#include "SpriteSheet.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include <vector>

class Obstacles : public Entity {
private:
	std::vector<Obstacle> m_obstacles;
	void renderObstacle(Obstacle, SDL_Renderer*);
public:
	Obstacles();
	Obstacles(std::vector<Obstacle>);
	~Obstacles();
	void render(SDL_Renderer*);
	void update();
	bool detectCollisions(Player);
};
