#pragma once

class Menu extends Entity {
	private:
		List<Text> m_options;
		int m_index;
	public:
		Menu();
		void select();	
}
