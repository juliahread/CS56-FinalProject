#pragma once

class GrapplingPoint extends Entity {
	private:
		Point m_location;
		SDL_Rect m_bbox;
		SpriteSheet m_image;
	public: 
		GrapplingPoint(Point); // initialize location
};

