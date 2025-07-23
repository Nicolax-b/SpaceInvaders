#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define Max_main_menu 2
using namespace sf;

class Menu
{
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

    void PlayMusic();  // NUEVO: iniciar música
    void StopMusic();  // NUEVO: parar música

 private:
    int main_menu_selected;
    sf::Font font;
    sf::Text main_menu[Max_main_menu];

    sf::Music menuMusic; // NUEVO: objeto para reproducir música
};