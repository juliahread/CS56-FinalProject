#include "Menu.hpp"

Menu::Menu(Background *menubg) : m_carrot(Text(">", 100, {450, 450})),
                                 m_selected_idx(0), m_menubg(menubg) {
    // load menu text
    m_title.push_back(Text("Distaster", 100, {335, 78}));
    m_title.push_back(Text("at the 5Cs", 75, {335, 190}));
    m_title.push_back(Text("in 2200", 110, {335, 300}));

    // load selectable text
    m_text_list.push_back(Text("Play", 100, {550, 450}));
    m_text_list.push_back(Text("Controls", 80, {550, 550}));
    m_text_list.push_back(Text("Highscores", 80, {550, 650}));

}

Menu::~Menu() {}

int Menu::get_mode() const{
    return m_selected_idx;
}

void Menu::update() {
    m_carrot.setPos({450, (int) (450 + (100 * m_selected_idx))});
    // update the background
    m_menubg->update();
}

void Menu::render(SDL_Renderer *renderer) const {
    // render the background
    m_menubg->render(renderer);

    // render the title text
    for (auto text : m_title) {
        text.render(renderer);
    }

    // render selectable text
    for (auto text : m_text_list) {
      text.render(renderer);
    }

    m_carrot.render(renderer);

}

void Menu::menuUp() {
  m_text_list[m_selected_idx].loadFont(80);
  m_selected_idx = (m_selected_idx + m_text_list.size() - 1) % m_text_list.size();
  m_text_list[m_selected_idx].loadFont(100);
}

void Menu::menuDown(){
  m_text_list[m_selected_idx].loadFont(80);
  m_selected_idx = (m_selected_idx + 1) % m_text_list.size();
  m_text_list[m_selected_idx].loadFont(100);
}
