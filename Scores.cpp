#include "Scores.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

Scores::Scores(std::string filename) : m_filename(filename), header(Text("Highscores", 60, {400, 50})){
  std::ifstream file;
  file.open(filename);
  if(file.is_open()){
    std::cout << "loaded high scores" << std::endl;
    std::string name;
    unsigned int score;
    while (file >> name){
      file >> score;
      m_scores.push_back(Score{name, score});
    }
    update_text();
  } else {
    std::cout << "Failed to load high score file" << std::endl;
  }
  file.close();
}

void Scores::update_text(){
  m_scores_text.clear();
  int start_y = 200;
  int name_x = 400;
  int score_x = 700;
  int line_height = 100;
  int line = 0;
  for (auto highscore: m_scores){
    m_scores_text.push_back(Text(highscore.name, 50, {name_x, start_y + (line * line_height)}));
    m_scores_text.push_back(Text(std::to_string(highscore.score), 50, {score_x, start_y + (line++ * line_height)}));
  }
}

void strip_whitespace(std::string s){
  std::replace(s.begin(), s.end(), ' ', '_');
}

Scores::~Scores(){
  std::cout << "Saving high score file" << std::endl;
  save_scores();
}
void Scores::add_score(Score new_entry){
  for (auto it = m_scores.begin(); it != m_scores.end(); it++){
    strip_whitespace(new_entry.name);
    if (it->score < new_entry.score){
      m_scores.insert(it, new_entry);
      update_text();
      return;
    }
  }
  m_scores.insert(m_scores.end(), new_entry);
  update_text();
}

void Scores::save_scores(){
  std::ofstream file(m_filename);
  for (auto it = m_scores.begin(); it != m_scores.end(); it++){
    file << it->name << " " << it->score << std::endl;
  }
  file.close();
}

void Scores::update(){}
void Scores::render(SDL_Renderer *renderer) const{
  header.render(renderer);
  for (int i = 0; i < 10 and i < m_scores_text.size(); i++){
    m_scores_text[i].render(renderer);
  }
}

