#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
using namespace sf;

Menu::Menu(float width, float height) 
{
    if (!font.loadFromFile("arial.ttf")) {
        // Manejo de error si deseas
    }

    main_menu[0].setFont(font);
    main_menu[0].setFillColor(Color::Green);
    main_menu[0].setString("Play");
    main_menu[0].setCharacterSize(50);
    main_menu[0].setPosition(Vector2f(width / 2, height / 3));

    main_menu[1].setFont(font);
    main_menu[1].setFillColor(Color::Red);
    main_menu[1].setString("Exit");
    main_menu[1].setCharacterSize(50);
    main_menu[1].setPosition(Vector2f(width / 2, height / 3 * 2));

    main_menu_selected = 0;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow &window) 
{
    for (int i = 0; i < 2; i++) {
        window.draw(main_menu[i]);
    }
}

void Menu::MoveDown()
{
    main_menu[main_menu_selected].setFillColor(Color::White);
    main_menu_selected++;

    if (main_menu_selected > 1) {
        main_menu_selected = 0;
    }

    main_menu[main_menu_selected].setFillColor(Color::Green);
}

void Menu::MoveUp()
{
    main_menu[main_menu_selected].setFillColor(Color::White);
    main_menu_selected--;

    if (main_menu_selected < 0) {
        main_menu_selected = 1;
    }

    main_menu[main_menu_selected].setFillColor(Color::Green);
}

void Menu::Enter()
{
    if (main_menu_selected == 0)
    {
        // Acción para Play
    }
    else if (main_menu_selected == 1) 
    {
        exit(0);
    }
}

void Menu::PlayMusic() {
    if (!menuMusic.openFromFile("sounds/menu_music.ogg")) {
        std::cerr << "Error al cargar la música del menú.\n";
    } else {
        menuMusic.setLoop(true);
        menuMusic.play();
    }
}

void Menu::StopMusic() {
    menuMusic.stop();
}