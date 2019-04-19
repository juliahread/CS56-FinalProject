#include "Obstacles.hpp"
#include "Obstacle.hpp"
#include "Entity.hpp"

Obstacles::Obstacles() : m_obstacles() { }
Obstacles::Obstacles(std::vector<Obstacle> list) : m_obstacles(list) { }
Obstacles::~Obstacles()
{
	m_obstacles.clear();
}
void Obstacles::render(SDL_Renderer* renderer) const
{
	if (!m_obstacles.empty())
	{
		for (auto const& obstacle : m_obstacles)
		{
			// obstacle.m_sprite->renderSprite(obstacle.x, obstacle.y, renderer, 0);
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
	// obstacle->m_sprite->renderSprite(obstacle.x, obstacle.y, renderer, 0);
}
