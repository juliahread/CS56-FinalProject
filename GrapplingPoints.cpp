#include "GrapplingPoints.hpp"

GrapplingPoints::GrapplingPoints() { }
GrapplingPoints::GrapplingPoints(std::vector<GrapplingPoint> list) : m_grappling_points(list) { }
GrapplingPoints::~GrapplingPoints() 
{ 
	m_grappling_points.clear();
}
void GrapplingPoints::addPoint(SDL_Point loc)
{
	// TODO
}
void GrapplingPoints::render(SDL_Renderer* renderer)
{
	if (!m_grappling_points.empty())
	{
		for (auto const& grappling_point : m_grappling_points)
		{
			// TODO
			// renderSprite(grappling_point.x, grappling_point.y, renderer, int spriteNumber);
		}
	}
}
void GrapplingPoints::update() { }
