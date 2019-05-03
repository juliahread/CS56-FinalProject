#include "Scores.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

Scores::Scores(std::string filename) : m_filename(filename){
  std::ifstream file;
  file.open(filename);
  if(file.is_open()){
    std::cout << "loaded high scores" << std::endl;
    std::string name;
    uint score;
    while (file >> name){
      file >> score;
      m_scores.push_back(Score{name, score});
    }
  } else {
    std::cout << "Failed to load high score file" << std::endl;
  }
  file.close();
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
      return;
    }
  }
  m_scores.insert(m_scores.end(), new_entry);
}

void Scores::save_scores(){
  std::ofstream file(m_filename);
  for (auto it = m_scores.begin(); it != m_scores.end(); it++){
    file << it->name << " " << it->score << std::endl;
  }
  file.close();
}

