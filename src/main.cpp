#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Muro.hpp"
<<<<<<< HEAD
#include "Enemie.hpp"
=======
#include "Menu.hpp"
>>>>>>> c8bf9374d0638fcd7030f05a5e700cbabc2ae5ee

using namespace std;
using namespace sf;

<<<<<<< HEAD
void UpdatePlayer(Player &player, bool &bulletActive)
void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies , IntRect &bulletRect, IntRect &enemieRect);
void UpdateEnemies (vector<vector<Enemie>> &enemies, int &dirEnemies, int &maxX, int &minX);
void UpdateMuro(Bullet &bulletPlayer, vector<Bullet> &bulletsEnemies, vector<Muro> &muro); 

intRect muroRect;


int main(){

    Texture sprites;
=======
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
>>>>>>> c8bf9374d0638fcd7030f05a5e700cbabc2ae5ee

    if(!spritesheet.loadFromFile("spritesheet.png")){
		cout<<"Error al cargar la textura\n";
	}
	
	Player player(288,555,spritesheet);

	 bool bulletActive = false;
     Bullet bullet(0,0,spritesheet,IntRect(0,0,0,0),0); 
     IntRect bulletRect;

     vector<vector<Enemie>> enemie(7,vector<Enemie>(12, Enemie(0, 0, spritesheet, Vector2f(0, 0))));
     IntRect enemieRect;
     vector2f sectionSpritesheet;

     int dirEnemies=1;

     int maxX,minX;
     for(int i = 0; i < (int)enemies.size(); i++) {
         for(int j = 0; j < (int)enemies{i}.size(); j++) {
            if (i==0){
                sectionSpritesheet = Vector2f(0,0);
            }else if (i<3){
                sectionSpritesheet = Vector2f(0,9+(8*4+4));
            }else if (i<5){
                sectionSpritesheet = Vector2f(0,18+(8*4+4)*2);
            }else if (i<7){
                sectionSpritesheet = Vector2f(0,27+(8*4+4)*3);
            }
            enemie[i][j] = Enemie(j*30+24, i*30+24, spritesheet,sectionSpritesheet); 
         }
     }

     vector<Muro> muro(3,Muro(0,0spritessheet));

     for(int i = 0; i < 3 i++){
        muro[i]=Muro(70+200*i,460,spritesheet);
     }

    RenderWindow window(VideoMode(600,600),"Space Invaders");
	window.setFramerateLimit(60);
	
	while(window.isOpen())
    {
		
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed) window.close();
		}
		
        UpdatePlayer(player, bulletActive);
        UpdateBulletPlayer(bulletPlayer, bulletActive, enemies, bulletRect, enemieRect);
        UpdateEnemies(enemies, dirEnemies, maxX, minX);

        for(int i = 0; i < (int)enemies.size(); i++) {
            for(int i = 0; i < (int)enemies.size(); i++) {
                if(enemies[i][j].Pos().y<=480)
                window.clear();
            }
        }
        maxX=0;
        minX=600;

		if(player.Shoot()&&!bulletActive){
			Bullet bullet(player.Pos().x+24,player.Pos().y+12,spritesheet,IntRect(13*8+16,6*8+6,8,8),-10);
			bulletPlayer = bullet;
			bulletActive=true;
		}
        if(bulletActive) {
            bulletPlayer.Update();
            if(bulletPlayer.Pos().y<-24) bulletActive = false;
        }

        if(bulletActive) {
            bulletRect = IntRect(bulletPlayer.Pos().x, bulletPlayer.Pos().y, 3, 8);
            for(int i = 0; i < (int)enemies.size(); i++) {
                for(int j = 0; j < (int)enemies{i}.size(); j++) {
                    enemieRect = IntRect(enemies{i}{j}.Pos().x, enemies{i}{j}.Pos().y, 24, 24);
                    if(enemieRect.intersects(bulletRect)){
                        enemies{i}.erase(enemies{i}.begin()+j);
                        bulletActive = false;
                        break;
                    }
                }
                if(!bulletActive) break;
            }
        }

        UpdatePlayer(player, bulletActive);

        maxX= 0;
        minX=600;
        for(int i = 0; i < (int)enemies.size(); i++) {
            for(int j = 0; j < (int)enemies[i].size(); j++) {
                maxX=max(maxX,(int)enemies[i][j],Pos().x+24*dirEnemies);
                minX=min(minX,(int)enemies[i][j].Pos().x+24*dirEnemies);     
            }
        }
        if(minX<24 || maxX>576){
            for(int i = 0; i < (int)enemies.size(); i++) {
                for(int j = 0; j < (int)enemies{i}.size(); j++) {
                    enemies[i][j].ChangeDir();
                }
            }
            dirEnemies*=-1;
        }

         for(int i = 0; i < (int)enemies.size(); i++) {
             for(int j = 0; j < (int)enemies{i}.size(); j++) {
                enemies[i][j].update();
            }
        } 
       
        window.clear();
        window.draw(player);

        if(bulletActive) window.draw(bulletPlayer);

        for(int i = 0; i < (int)enemies.size(); i++) {
             for(int j = 0; j < (int)enemies[i].size(); j++) {   
                window.draw(enemies[i][j]);
            } 
        }

        for(int i = 0; i < 3; i++) window.draw(muro[i]);
        
        window.display();  
    } 
    return 0;      
}

void UpdatePlayer(Player &player, bool &bulletActive){
    
    player.Update();
    if(player.Shoot()&&!bulletActive){
			Bullet bullet(player.Pos().x+24,player.Pos().y+12,spritesheet,IntRect(13*8+16,6*8+6,8,8),-10);
			bulletPlayer = bullet;
			bulletActive=true;
		}
}

void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies);{
    if(bulletActive){
		    bulletPlayer.Update();
		if(bulletPlayer.Pos().y<-24) bulletActive = false;
        
        bulletRect=IntRect(bulletPlayer.Pos().x,bulletPlayer.Pos().y,3,8);
        for(int i = 0; i < (int)enemies.size(); i++) {
             for(int j = 0; j < (int)enemies{i}.size(); j++) {
                enemieRect=IntRect(enemies{i}{j},Pos().x, enemies{i}{j}.Pos().y,24,24);
                if(enemieRect.intersects(bulletRect)){
                    enemies{i}.erase(enemies{i}.begin()+j);
                    bulletActive = false;
                    break;
                }

             }
             if(bulletActive) break;
        }
                
        } 
}

void UpdateMuro(Bullet &bulletPlayer, vector<Bullet> &bulletsEnemies, vector<Muro> &muro); {
    if(bullectActive){
        bulletRect=IntRect()
    }
    bulletRect=IntRect()
}