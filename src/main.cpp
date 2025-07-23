#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Menu.hpp"

using namespace std;
using namespace sf;

int page_number;

int main()
{
    RenderWindow window(sf::VideoMode(600, 600), "Space Invaders EPN");
    Menu menu(600, 600);
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
                window.close();
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up) 
                {
                    menu.MoveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down) 
                {
                    menu.MoveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return) 
                {
                    if (menu.mainMenuPressed() == 0)
                    {
                        window.close();
                        page_number = 0;
                    }
                    if (menu.mainMenuPressed() == 1) 
                    {
                        window.close();
                        page_number = 1;
                    }
                }
                
            }
        }
        window.clear(sf::Color::Black);
        menu.draw(window);
        window.display();
    }
    if (page_number==0)
    {
        sf::RenderWindow window_play(VideoMode(300,300),"Play",sf::Style::Close);
        while (window_play.isOpen())
        {
            sf::Event event;
            while (window_play.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window_play.close();
            }
            window_play.clear(sf::Color::Black);
            // Aquí puedes agregar el código para el juego
            window_play.display();
        }
    }
    if (page_number==1)
    {
        //exit
        break;
    }
}
    if(!spritesheet.loadFromFile("Spritesheet.png")){
        cout<<'error al cargar la textura/n';
    }

    Player player(288,555,spritesheet);

    bool bulletActive = false;
    Bullet bulletPlayer(0,0,spritesheet,IntRect(0,0,0,0),0);
    
    RenderWindow window(Videomode(600, 600), "Space Invaders EPN");
    Window.setFramerateLimit(60);
    

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed) window.close();
        }
        player.update();
        
        if(player.Shoot()&&!bulletActive){
            Bullet bullet(player.Pos().x+24,player.Pos().y-24,spritesheet,IntRect(13*8+16,6*8+6,8,8),-5);
            bulletPlayer = bullet;
            bulletActive = true;
        }

        if(bulletActive) {
            bulletPlayer.Update();
            if(bulletPlayer.Pos().y<-24) bulletActive = false;

        }
        window.clear();
        window.draw(player);

        if(bulletActive) window.draw(bulletPlayer);

        }

        window.display();

    return 0;

    }
