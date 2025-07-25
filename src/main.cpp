#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "Jugador.hpp"
#include "Bala.hpp"
<<<<<<< HEAD
#include "Muro.hpp"
<<<<<<< HEAD
=======
>>>>>>> 9e3b7b2756a7962a0d2847498052c48de3dfb3a4
#include "Enemie.hpp"

using namespace std;
using namespace sf;

<<<<<<< HEAD
<<<<<<< HEAD
void UpdatePlayer(Player &player, bool &bulletActive)
void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies , IntRect &bulletRect, IntRect &enemieRect);
void UpdateEnemies (vector<vector<Enemie>> &enemies, int &dirEnemies, int &maxX, int &minX);
void UpdateMuro(Bullet &bulletPlayer, vector<Bullet> &bulletsEnemies, vector<Muro> &muro); 

intRect muroRect;

=======
void UpdatePlayer(Player &player, bool &bulletActive, Bullet &bulletPlayer);
void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies, IntRect &bulletRect, IntRect &enemieRect);
void UpdateEnemies(vector<vector<Enemie>> &enemies, int &dirEnemies, int &minX, int &maxX);
void UpdateBulletsEnemies(Player &player, IntRect &bulletrect);
>>>>>>> 9e3b7b2756a7962a0d2847498052c48de3dfb3a4

Texture spritesheet;

int timer = 0;
int cadencia = 125;
vector<Bullet> bulletsEnemies;

IntRect playerRect;

int main()
{

    if (!spritesheet.loadFromFile("Spritesheet.png"))
    {
        cout << 'error al cargar la textura\n';
    }

    Player player(288, 555, spritesheet);

    bool bulletActive = false;
    Bullet bulletPlayer(0, 0, spritesheet, IntRect(0, 0, 0, 0), 0);
    IntRect bulletRect;

    vector<vector<Enemie>> enemies(7, vector<Enemie>(12, Enemie(0, 0, spritesheet, Vector2f(0, 0))));
    IntRect enemyRect;
    Vector2f sectionSpritesheet;

    int dirEnemies = 1;

    int maxX, minX;

    int dirEnemies = 1;

    int maxX, minX;

    for (int i = 0; i < (int)enemies.size(); i++)
    {
        for (int j = 0; j < (int)enemies[i].size(); j++)
        {
            if (i == 0)
            {
                sectionSpritesheet = Vector2f(0, 0);
            }
            else if (i < 3)
            {
                sectionSpritesheet = Vector2f(0, 9);
            }
            else if (i < 5)
            {
                sectionSpritesheet = Vector2f(0, 18);
            }
            else if (i < 7)
            {
                sectionSpritesheet = Vector2f(0, 27);
            }
            enemies[i][j] = Enemie(j * 30 + 24, i * 30 + 24, spritesheet, sectionSpritesheet);
        }
    }

    RenderWindow window(VideoMode(600, 600), "Space Invaders EPN");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
<<<<<<< HEAD
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
=======
>>>>>>> 9e3b7b2756a7962a0d2847498052c48de3dfb3a4
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

<<<<<<< HEAD
        for(int i = 0; i < 3; i++) window.draw(muro[i]);
        
        window.display();  
    } 
    return 0;      
=======
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
>>>>>>> 9e3b7b2756a7962a0d2847498052c48de3dfb3a4
}

void UpdatePlayer(Player &player, bool &bulletActive, Bullet &bulletPlayer)
{
    player.update();

    if (player.Shoot() && !bulletActive)
    {
        Bullet bullet(player.pos().x + 24, player.pos().y + 12, spritesheet, IntRect(13 * 8 + 16, 6 * 8 + 6, 8, 8), -10);
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
<<<<<<< HEAD
                
        } 
}

void UpdateMuro(Bullet &bulletPlayer, vector<Bullet> &bulletsEnemies, vector<Muro> &muro); {
    if(bullectActive){
        bulletRect=IntRect()
    }
    bulletRect=IntRect()
=======
        if (!bulletActive)
        {
            for (int i = 0; i < (int)enemies.size(); i++)
            {
                for (int j = 0; j < (int)enemies[i].size(); j++)
                {
                    enemies[i][j].AumentarCadencia();
                }
            }
            cadencia -= 5;
        }
    }
}
void UpdateEnemies(vector<vector<Enemie>> &enemies, int &dirEnemies, int &minX, int &maxX)
{
    maxX = 0;
    minX = 600;
    for (int i = 0; i < (int)enemies.size(); i++)
    {
        for (int j = 0; j < (int)enemies[i].size(); j++)
        {
            maxX = max(maxX, (int)enemies[i][j].Pos().x + 24 * dirEnemies);
            minX = min(minX, (int)enemies[i][j].Pos().x - 24 * dirEnemies);
        }
    }
    if (minX < 24 || maxX > 576)
    {
        for (int i = 0; i < (int)enemies.size(); i++)
        {
            for (int j = 0; j < (int)enemies[i].size(); j++)
            {
                enemies[i][j].ChangeDir();
            }
        }
        dirEnemies *= -1;
    }

    for (int i = 0; i < (int)enemies.size(); i++)
    {
        for (int j = 0; j < (int)enemies[i].size(); j++)
        {
            enemies[i][j].update();
        }
    }

    timer++;

    if (timer >= cadencia && (int)enemies[0].size() > 0)
    {
        timer = 0;
        srand(time(NULL));
        int enem = rand() % (int)enemies[0].size();
        Bullet bullet = Bullet(enemies[0][enem].Pos().x + 9, enemies[0][enem].Pos().y + 24, spritesheet, IntRect(13 * 8 + 8, 8 * 2 + 2, 8, 8), 10);
        bulletsEnemies.push_back(bullet);
    }
}
void UpdateBulletsEnemies(Player &player, IntRect &bulletRect)
{

    for (int i = 0; i < (int)bulletsEnemies.size(); i++)
    {
        bulletsEnemies[i].update();
    }

    for (int i = 0; i < (int)bulletsEnemies.size(); i++)
    {
        if (bulletsEnemies[i].Pos().y > 600)
        {
            bulletsEnemies.erase(bulletsEnemies.begin() + i);
        }
    }

    playerRect = IntRect(player.pos().x, player.pos().y + 9, 48, 15);
    for (int i = 0; i < (int)bulletsEnemies.size(); i++)
    {
        bulletRect = IntRect(bulletsEnemies[i].Pos().x, bulletsEnemies[i].Pos().y, 3, 24);
        if (playerRect.intersects(bulletRect))
        {
            bulletsEnemies.erase(bulletsEnemies.begin() + i);
            player.QuitarVida();
        }
    }
>>>>>>> 9e3b7b2756a7962a0d2847498052c48de3dfb3a4
}