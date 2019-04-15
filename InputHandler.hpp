#pragma once

class InputHandler {
	private:
		Command* left_click;
		Command* right_click;
		Command* spacebar;
		Command* w_key;
		Command* a_key;
		Command* s_key;
		Command* d_key;
	public:
		Command* handle_input();
};
