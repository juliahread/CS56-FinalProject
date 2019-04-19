#pragma once

#include "GrapplingPoint.hpp"
#include "SpriteSheet.hpp"
#include <cmath>
#include <vector>
#include <string>

class GrapplingPoints : public Entity {
private:
	std::vector<GrapplingPoint> m_grappling_points;
	static constexpr int WIDTH = 5;
	static constexpr int HEIGHT = 5;
public:
	GrapplingPoints();
	GrapplingPoints(std::vector<GrapplingPoint>);
	~GrapplingPoints();
	void addPoint(SDL_Point loc, SDL_Renderer*);
	void addPoint(int x, int y, SDL_Renderer*);
	void render(SDL_Renderer* renderer) const;
	void update();
  const SDL_Point* findClosestGrapplePoint(SDL_Point loc);
};
