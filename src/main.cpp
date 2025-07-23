#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Enemie.hpp"

using namespace std;
using namespace sf;

void UpdatePlayer(Player &player, bool &bulletActive)
void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies , IntRect &bulletRect, IntRect &enemieRect);
void UpdateEnemies (vector<vector<Enemie>> &enemies, int &dirEnemies, int &maxX, int &minX);
 

int main(){

    Texture sprites;

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
                sectionSpritesheet = Vector2f(0,9);
            }else if (i<5){
                sectionSpritesheet = Vector2f(0,18);
            }else if (i<7){
                sectionSpritesheet = Vector2f(0,27);
            }
            enemie[i][j] = Enemie(j*30+24, i*30+24, spritesheet,sectionSpritesheet); 
         }
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