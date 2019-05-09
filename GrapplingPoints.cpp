#include "GrapplingPoints.hpp"
#include "GrapplingPoint.hpp"

GrapplingPoints::GrapplingPoints() {}
GrapplingPoints::GrapplingPoints(std::vector<GrapplingPoint> list)
    : m_grappling_points(list) {}
GrapplingPoints::~GrapplingPoints() { m_grappling_points.clear(); }

void GrapplingPoints::addPoint(SDL_Point loc, SDL_Renderer* renderer) {
  m_grappling_points.push_back(
      GrapplingPoint("circle.png", {loc.x, loc.y, WIDTH, HEIGHT}, renderer));
}

void GrapplingPoints::addPoint(int x, int y, SDL_Renderer* renderer) {
  SDL_Point loc;
  loc.x = x;
  loc.y = y;
  m_grappling_points.push_back(
      GrapplingPoint("circle.png", {loc.x, loc.y, WIDTH, HEIGHT}, renderer));
}

void GrapplingPoints::render(SDL_Renderer* renderer) const {
  for (auto const& grappling_point : m_grappling_points) {
    grappling_point.render(renderer);
  }
}
void GrapplingPoints::update() {}

const SDL_Point* GrapplingPoints::findClosestGrapplePoint(SDL_Point loc) {
  const SDL_Point* closest = nullptr;
  float min_distance_sq = FLT_MAX;
  for (auto const& grappling_point : m_grappling_points) {
    const SDL_Point* grapple_loc = grappling_point.getLocation();
    float distance_sq = std::pow(std::abs(loc.x - grapple_loc->x), 2) +
                        std::pow(std::abs(loc.y - grapple_loc->y), 2);
    if (distance_sq < min_distance_sq) {
      closest = grapple_loc;
      min_distance_sq = distance_sq;
    }
  }
  return closest;
}

std::vector<GrapplingPoint>& GrapplingPoints::getGrapplingPoints() {
  return m_grappling_points;
}
