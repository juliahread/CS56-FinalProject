#include "Obstacles.hpp"
#include "Obstacle.hpp"

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
			renderObstacle(obstacle, renderer);
		}
	}
}
void Obstacles::update() { }
bool Obstacles::detectCollisions(Player player)
{
	//TODO
	return false;
}
void Obstacles::renderObstacle(Obstacle obstacle, SDL_Renderer* renderer) const
{
	obstacle.get_sprite()->renderSprite(obstacle.get_bbox().x, obstacle.get_bbox().y, renderer, 0);
}

SDL_Point* Obstacles::intersectLine(SDL_Point lineStart, SDL_Point lineEnd){
  return nullptr;
}
