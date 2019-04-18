#pragma once
#include "GrapplingPoint.hpp"
#include "SpriteSheet.hpp"
#include <vector>
#include <string>

class GrapplingPoints : public Entity {
private:
	std::vector<GrapplingPoint> m_grappling_points;
  SpriteSheet *m_point_sprite;
  // static constexpr char SPRITE_FILE_NAME[] = "images/circle.png";
  // static constexpr int NUM_SPRITES = 1;
public:
	GrapplingPoints(SDL_Renderer *renderer);
	GrapplingPoints(std::vector<GrapplingPoint>, SDL_Renderer *renderer);
	~GrapplingPoints();
	void addPoint(SDL_Point loc);
	void addPoint(int x, int y);
	void render(SDL_Renderer* renderer) const;
	void update();
  const SDL_Point* findClosestGrapplePoint(SDL_Point loc);
};
