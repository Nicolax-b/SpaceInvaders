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
void draw(RenderWindow &window);
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
    Font font;                   
    Text main_Game_Lose[Max_Game_Lose]; 
    Text gameOverText;
    Music LoseMusic;             
};