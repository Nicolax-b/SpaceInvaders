#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define Max_Game_Lose 2

using namespace sf;

class Lose
{
public:
Lose (float width, float height);
~Lose();
void draw(sf::RenderWindow &window);
void MoveUp();
void MoveDown();
int GameLosePressed() 
     {
        return main_Game_Lose_selected;
     }
     void PlayMusic();
     void StopMusic();
     private:
    int main_Game_Lose_selected;          
    sf::Font font;                   
    sf::Text main_Game_Lose[Max_Game_Lose]; 
    sf::Text gameOverText;
    sf::Music LoseMusic;             
};