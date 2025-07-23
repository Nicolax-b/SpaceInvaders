#include <iostream>
#include <SFML/Graphics.hpp>
#define Max_main_menu 2
using namespace sf;
#pragma once

class Menu {
 public:
    Menu(float width, float height);
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int mainMenuPressed()
    {
      return main_menu_selected;
    }
    ~Menu();
    private:
    int main_menu_selected;
    sf::Font font;
    sf::Text main_menu[Max_main_menu];

};