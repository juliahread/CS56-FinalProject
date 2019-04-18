#include "GrapplingPoints.hpp"
#include "GrapplingPoint.hpp"

// constexpr char GrapplingPoints::SPRITE_FILE_NAME[];
// constexpr int GrapplingPoints::NUM_SPRITES;

GrapplingPoints::GrapplingPoints(SDL_Renderer *renderer){
  m_point_sprite = new SpriteSheet("images/circle.png", renderer, 1);
}
GrapplingPoints::GrapplingPoints(std::vector<GrapplingPoint> list, SDL_Renderer *renderer) : m_grappling_points(list)
{
  m_point_sprite = new SpriteSheet("images/circle.png", renderer, 1);
}
GrapplingPoints::~GrapplingPoints()
{
	m_grappling_points.clear();
}
void GrapplingPoints::addPoint(SDL_Point loc)
{
  m_grappling_points.push_back(GrapplingPoint (loc, m_point_sprite));
}

void GrapplingPoints::addPoint(int x, int y)
{
  SDL_Point loc;
  loc.x = x;
  loc.y = y;
  GrapplingPoint new_point(loc, m_point_sprite);
  m_grappling_points.push_back(new_point);
}
void GrapplingPoints::render(SDL_Renderer* renderer) const
{
		for (auto const& grappling_point : m_grappling_points)
		{
      grappling_point.render(renderer);
		}
}
void GrapplingPoints::update() { }
