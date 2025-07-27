#include "Win.hpp"

Win::Win(float width, float height)
    : main_Game_Win_selected(0)
{
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    main_Game_Win[0].setFont(font);
    main_Game_Win[0].setFillColor(Color::Green);
    main_Game_Win[0].setString("Play Again");
    main_Game_Win[0].setPosition(width / 2 - 50, height / 2 - 20);
    main_Game_Win[0].setCharacterSize(24);
    main_Game_Win[0].setFillColor(sf::Color::White);

    main_Game_Win[1].setFont(font);
    main_Game_Win[1].setFillColor(Color::Red);
    main_Game_Win[1].setString("Exit");
    main_Game_Win[1].setPosition(width / 2 - 50, height / 2 + 20);
    main_Game_Win[1].setCharacterSize(24);
    main_Game_Win[1].setFillColor(sf::Color::White);

    gameWinText.setFont(font);
    gameWinText.setFillColor(Color::Purple);
    gameWinText.setString("WELL DONE HERO¡¡¡");
    gameWinText.setCharacterSize(48);  // Más grande que las opciones
    gameWinText.setPosition(width / 2 - 100, height / 6);
    gameWinText.setOutlineColor(Color::White);
    gameWinText.setOutlineThickness(2);

    if (!WinMusic.openFromFile("Music/Win.ogg")) {
        std::cerr << "Error loading music" << std::endl;
    }
}
void Win::draw(sf::RenderWindow &window)
{
    window.draw(gameWinText);  
    for (int i = 0; i < Max_Game_Win; i++) {
        window.draw(main_Game_Win[i]);
    }
}