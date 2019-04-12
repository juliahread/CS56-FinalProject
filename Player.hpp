#pragma once
class Player extends Entity {
private:
	// Attributes:
	struct Location {
		// Position
		Point pos;
		// Velocity
		struct Velocity {
			int m_speed;
			int m_direction;
		};
	};
	bool m_grappling_hook;
	SpriteSheet m_sprsheet;
	SDL_Rect m_bbox;
public:
	void render();
	void update();
	std::tuple get_velocity();
	void eject_mass();
};
