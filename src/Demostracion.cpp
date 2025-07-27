#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Muro.hpp"
#include "Enemie.hpp"

using namespace std;
using namespace sf;

intRect muroRect;

void UpdatePlayer(Player &player, bool &bulletActive, Bullet &bulletPlayer);
void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies, IntRect &bulletRect, IntRect &enemieRect);
void UpdateEnemies(vector<vector<Enemie>> &enemies, int &dirEnemies, int &minX, int &maxX);
void UpdateBulletsEnemies(Player &player, IntRect &bulletrect);
void UpdateMuro(Bullet &bulletPlayer, vector<Bullet> &bulletsEnemies, vector<Muro> &muro); 


Texture spritesheet;

int timer = 0;
int cadencia = 125;
vector<Bullet> bulletsEnemies;

IntRect playerRect;

int main()
{
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

    RenderWindow window(VideoMode(600,600),"Space Invaders EPN", Style::Close | Style::Titlebar);
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

        UpdatePlayer(player, bulletActive, bulletPlayer);

        UpdateBulletPlayer(bulletPlayer, bulletActive, enemies, bulletRect, enemyRect);

        UpdateEnemies(enemies, dirEnemies, minX, maxX);

        UpdateBulletsEnemies(player, bulletRect);

        if (player.Vivo() == false)
            window.close();

        window.clear();
        window.draw(player);

        for (int i = 0; i < (int)bulletsEnemies.size(); i++)
        {
            window.draw(bulletsEnemies[i]);
        }

        if (bulletActive)
            window.draw(bulletPlayer);

        for (int i = 0; i < (int)enemies.size(); i++)
        {
            for (int j = 0; j < (int)enemies[i].size(); j++)
            {
                window.draw(enemies[i][j]);
            }
        }

        window.display();
    }
    return 0;
}

void UpdatePlayer(Player &player, bool &bulletActive, Bullet &bulletPlayer)
{
    player.update();

    if (player.Shoot() && !bulletActive)
    {
        Bullet bullet(player.pos().x + 24, player.pos().y + 12, spritesheet, IntRect(13 * 8 + 16, 6 * 8 + 6, 8, 8), -10); //Considerar para los sprites
        bulletActive = true;
    }
}

void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies, IntRect &bulletRect, IntRect &enemieRect)
{
    if (bulletActive)
    {
        bulletPlayer.update();
        if (bulletPlayer.Pos().y < -24)
            bulletActive = false;

        bulletRect = IntRect(bulletPlayer.Pos().x, bulletPlayer.Pos().y, 3, 8);
        for (int i = 0; i < (int)enemies.size(); i++)
        {
            for (int j = 0; j < (int)enemies[i].size(); j++)
            {
                enemieRect = IntRect(enemies[i][j].Pos().x, enemies[i][j].Pos().y, 24, 24);
                if (enemieRect.intersects(bulletRect))
                {
                    enemies[i].erase(enemies[i].begin() + j);
                    bulletActive = false;
                    break;
                }
            }
            if (!bulletActive)
                break;
        }   
        } 
}

void UpdateMuro(Bullet &bulletPlayer, vector<Bullet> &bulletsEnemies, vector<Muro> &muro); {
    if(bullectActive){
        bulletRect=IntRect()
    }
    bulletRect=IntRect()
}