#pragma once

#include <string>
#include <vector>

class Scores {
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
private:
  std::vector<Score> m_scores;
  std::string m_filename;
};
