#pragma once
#include <vector>

class GrapplingHook extends Entity {
	private:
		Point m_location;
		GrapplingPoint m_anchor;
		std::Vector<SDL_Line> m_lines;
		SDL_Rect m_bbox;
		SpriteSheet m_image;
	public:
		GrapplingHook(Point, m_anchor, m_lines); 
		void shoot();
		void detatch();
}
