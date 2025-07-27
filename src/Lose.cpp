#include "Lose.hpp"

Lose::Lose(float width, float height)
    : main_Game_Lose_selected(0)
{
    if (!font.loadFromFile("ARCADE_N.TTF.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    main_Game_Lose[0].setFont(font);
    main_Game_Lose[0].setFillColor(Color::Green);
    main_Game_Lose[0].setString("Play Again");
    main_Game_Lose[0].setPosition(width / 2 - 50, height / (Max_Game_Lose + 1) * 1);
    main_Game_Lose[0].setCharacterSize(24);
    
    main_Game_Lose[1].setFont(font);
    main_Game_Lose[1].setFillColor(Color::Red);
    main_Game_Lose[1].setString("Exit");
    main_Game_Lose[1].setPosition(width / 2 - 50, height / (Max_Game_Lose + 1) * 2);
    main_Game_Lose[1].setCharacterSize(24);

    gameOverText.setFont(font);
    gameOverText.setFillColor(Color::Blue);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(48);  
    gameOverText.setPosition(width / 2 - 100, height / 6);

    if (!LoseMusic.openFromFile("Music/game-over-39-199830.ogg")) {
        std::cerr << "Error loading lose music" << std::endl;
    }
}
void Lose::draw(sf::RenderWindow &window)
{
    window.draw(gameOverText);  
    for (int i = 0; i < Max_Game_Lose; i++) {
        window.draw(main_Game_Lose[i]);
    }
}
void Lose::MoveUp()
{
    if (main_Game_Lose_selected - 1 >= 0)
    {
        main_Game_Lose[main_Game_Lose_selected].setFillColor(sf::Color::White);
        main_Game_Lose_selected--;
        main_Game_Lose[main_Game_Lose_selected].setFillColor(sf::Color::Green);
    }
}

void Lose::MoveDown()
{
    if (main_Game_Lose_selected + 1 < Max_Game_Lose)
    {
        main_Game_Lose[main_Game_Lose_selected].setFillColor(sf::Color::White);
        main_Game_Lose_selected++;
        main_Game_Lose[main_Game_Lose_selected].setFillColor(sf::Color::Green);
    }
}

void Lose::PlayMusic()
{
    LoseMusic.play();
}

void Lose::StopMusic()
{
    LoseMusic.stop();
}
Lose::~Lose()
{
    // Destructor simple, sin recursos dinámicos que liberar
}