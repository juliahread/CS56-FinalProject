#pragma once

#include <tuple>
#include <list>

class ScoreLoader {
	public:
		std::list<std::tuple<std::string, int>> get_scores(std::string file);
		std::tuple<std::string, int> write_score(std::string file);
};
