#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "InputHandler.hpp"

#define Max_Game_Win 2

using namespace sf;

class Win  
{
public:
   Win(float width, float height);
   ~Win();
   void draw(sf::RenderWindow &window);
   void MoveUp();
   void MoveDown();
   int GameWinPressed()
   {
      return main_Game_Win_selected;
   }

   void PlayMusic();
   void StopMusic();

private:
   int main_Game_Win_selected;
   Font font;
   Text main_Game_Win[Max_Game_Win];
   Text gameWinText;
   Music WinMusic;
};