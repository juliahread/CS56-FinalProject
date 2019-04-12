#pragma once
class Player {
private:
	// Attributes:
	Point m_location;
	int m_mass;
	std::tuple m_velocity;
	bool m_grappling_hook;
	SpriteSheet m_sprsheet;
	SDL_Rect m_bbox;
	// Powerups:
	bool m_powerup1;
	bool m_powerup2;
	// etc...
public:
	void render();
	void update();
	std::tuple get_velocity();
	void eject_mass();
};
