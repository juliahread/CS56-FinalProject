#pragma once
#include "Entity.hpp"
#include "SpriteSheet.hpp"
#include "GrapplingPoint.hpp"
#include <list>

class GrapplingPoints : public Entity {
private:
	std::list<GrapplingPoint> m_grappling_points;
public:
	GrapplingPoints();
	GrapplingPoints(std::list<GrapplingPoint>);
	~GrapplingPoints();
	void addPoint(SDL_Point loc); // initialize location
	void render(SDL_Renderer*);
	void update();
};


