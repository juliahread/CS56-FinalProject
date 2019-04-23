#pragma once

#include "Entity.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include <vector>

class Obstacles : public Entity {
private:
        std::vector<Obstacle> m_obstacles;
public:
        Obstacles();
        Obstacles(std::vector<Obstacle>);
        ~Obstacles();
        void render(SDL_Renderer*) const;
        void update();
        bool detectCollisions(Player);
		void renderObstacle(Obstacle, SDL_Renderer*) const;
};
