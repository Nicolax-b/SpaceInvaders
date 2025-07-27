#include "Win.hpp"

Win::Win(float width, float height)
    : main_Game_Win_selected(0)
{
    if (!font.loadFromFile("fonts/ARCADE_N.TTF")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
    }

     // -------- Texto principal centrado --------
    gameWinText.setFont(font);
    gameWinText.setFillColor(Color::Yellow);
    gameWinText.setString("WELL DONE HERO¡¡¡");
    gameWinText.setCharacterSize(60);
    gameWinText.setOutlineColor(Color::White);
    gameWinText.setOutlineThickness(2);
    FloatRect textRect = gameWinText.getLocalBounds();
    gameWinText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    gameWinText.setPosition(width / 2.f, height / 6.f);

    // -------- Opción: Play Again centrado --------
    main_Game_Win[0].setFont(font);
    main_Game_Win[0].setFillColor(Color::Green);
    main_Game_Win[0].setString("Play Again");
    main_Game_Win[0].setCharacterSize(40);
    textRect = main_Game_Win[0].getLocalBounds();
    main_Game_Win[0].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    main_Game_Win[0].setPosition(width / 2.f, height / 2.f - 20.f);

    // -------- Opción: Exit centrado --------
    main_Game_Win[1].setFont(font);
    main_Game_Win[1].setFillColor(Color::Red);
    main_Game_Win[1].setString("Exit");
    main_Game_Win[1].setCharacterSize(40);
    textRect = main_Game_Win[1].getLocalBounds();
    main_Game_Win[1].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    main_Game_Win[1].setPosition(width / 2.f, height / 2.f + 20.f);

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
void Win::MoveUp()
{
    if (main_Game_Win_selected - 1 >= 0)
    {
        main_Game_Win[main_Game_Win_selected].setFillColor(sf::Color::White);
        main_Game_Win_selected--;
        main_Game_Win[main_Game_Win_selected].setFillColor(sf::Color::Green);
    }
}

void Win::MoveDown()
{
    if (main_Game_Win_selected + 1 < Max_Game_Win)
    {
        main_Game_Win[main_Game_Win_selected].setFillColor(sf::Color::White);
        main_Game_Win_selected++;
        main_Game_Win[main_Game_Win_selected].setFillColor(sf::Color::Green);
    }
}

void Win::PlayMusic()
{
    WinMusic.play();
}

void Win::StopMusic()
{
    WinMusic.stop();
}

Win::~Win()
{
    // Destructor implementation if needed
    // Currently, no dynamic memory allocation is done, so nothing specific to clean up
}