#include "Obstacles.hpp"
#include "Obstacle.hpp"
#include "Entity.hpp"
#include "GrapplingHook.hpp"
#include "GrapplingPoint.hpp"
#include <tuple>

Obstacles::Obstacles() : m_obstacles(NULL) { }
Obstacles::Obstacles(std::list<Obstacle> list) : m_obstacles(list) { }
Obstacles::~Obstacles() { }
void Obstacles::render(SDL_Renderer* renderer)
{
	if (!m_obstacles.empty())
	{
		for (auto const& obstacle : m_obstacles)
		{
			//TODO
			//renderSprite(obstacle.x, obstacle.y, renderer, int spriteNumber);
		}
	}
}
void Obstacles::update() { }
bool Obstacles::detectCollisions(Player player) 
{ 
	//TODO
	return false;
}
void Obstacles::renderObstacle(Obstacle obstacle, SDL_Renderer* renderer) 
{ 
	//TODO
	//renderSprite(obstacle.x, obstacle.y, renderer, int spriteNumber);
}
