#pragma once
#include "Entity.hpp"
#include "Text.hpp"

#include <string>
#include <vector>

class Scores : public Entity {
 public:
  struct Score {
    std::string name;
    unsigned int score;
  };
  Scores(std::string filename);
  ~Scores();
  std::vector<Score> get_scores();
  void add_score(Score);
  void save_scores();
  void update();
  void render(SDL_Renderer *) const;
private:
  std::vector<Score> m_scores;
  std::string m_filename;
  std::vector<Text> m_scores_text;
  Text header;
  void update_text();
};
