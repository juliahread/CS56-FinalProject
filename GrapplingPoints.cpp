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
  delete m_point_sprite;
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

const SDL_Point* GrapplingPoints::findClosestGrapplePoint(SDL_Point loc){
  const SDL_Point *closest = nullptr;
  float min_distance_sq = FLT_MAX;
  for (auto const& grappling_point : m_grappling_points)
		{
      const SDL_Point *grapple_loc = grappling_point.getLocation();
      float distance_sq = std::pow(std::abs(loc.x - grapple_loc->x), 2) + std::pow(std::abs(loc.y - grapple_loc->y),2);
      if (distance_sq < min_distance_sq){
        closest = grapple_loc;
        min_distance_sq = distance_sq;
      }
		}
  return closest;
}
