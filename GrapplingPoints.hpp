#pragma once
#include "GrapplingPoint.hpp"
#include <vector>

class GrapplingPoints : public Entity {
private:
	std::vector<GrapplingPoint> m_grappling_points;
public:
	GrapplingPoints();
	GrapplingPoints(std::vector<GrapplingPoint>);
	~GrapplingPoints();
	void addPoint(SDL_Point);
	void render(SDL_Renderer*);
	void update();
};
