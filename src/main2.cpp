#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Enemie.hpp"

using namespace std;
using namespace sf;

void UpdatePlayer(Player &player, bool &bulletActive, Bullet &bulletPlayer);
void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies, IntRect &bulletRect, IntRect &enemieRect);
void UpdateEnemies(vector<vector<Enemie>> &enemies, int &dirEnemies, int &minX, int &maxX);
Texture spritesheet;
int timer = 0;
int cadencia = 100;
vector<Bullet> bulletsEnemies;


int main()
{
    if (!spritesheet.loadFromFile("spritesheet.png"))
    {
        cout << "Error al cargar la textura\n";
    };
    Player player(288, 555, spritesheet);
    bool bulletActive = false;
    Bullet bulletPlayer(0, 0, spritesheet, IntRect(0, 0, 0, 0), 0);
    IntRect bulletRect;
    IntRect enemieRect;

    vector<vector<Enemie>> enemies(7, vector<Enemie>(12, Enemie(0, 0, spritesheet, Vector2f(0, 0))));
    Vector2f sectionSpritesheet;
    int dirEnemies = 1; // 1 para derecha, -1 para izquierda
    int maxX, minX;
    for (int i = 0; i < (int)enemies.size(); i++)
    {
        for (int j = 0; j < (int)enemies[i].size(); j++)
        {
            enemies[i][j] = Enemie(i * 30 + 24, j * 30 + 24, spritesheet, Vector2f(0, 0)); // Considerar para los sprites
            if (i == 0)
            {
                sectionSpritesheet = Vector2f(0, 0);
            }
            else if (i < 3)
            {
                sectionSpritesheet = Vector2f(0, 9 + (8 * 4 + 4));
            }
            else if (i < 5)
            {
                sectionSpritesheet = Vector2f(0, 18 + (8 * 4 + 4) * 2);
            }
            else if (i < 7)
            {
                sectionSpritesheet = Vector2f(0, 27 + (8 * 4 + 4) * 3);
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
        }
        UpdatePlayer(player, bulletActive, bulletPlayer);
        UpdateBulletPlayer(bulletPlayer, bulletActive, enemies, bulletRect, enemieRect);
        UpdateEnemies(enemies, dirEnemies, minX, maxX);
        window.clear();
        window.draw(player);
        if (bulletActive)
        {
            window.draw(bulletPlayer);
        }
        for (int i = 0; i < (int)enemies.size(); i++)
        {
            for (int j = 0; j < (int)enemies[i].size(); j++)
            {
                window.draw(enemies[i][j]);
            }
        }
        for (int i = 0; i < (int)bulletsEnemies.size(); i++)
        {
            window.draw(bulletsEnemies[i]);
        }
        window.display();
    }
    return 0;
}

void UpdatePlayer(Player &player, bool &bulletActive, Bullet &bulletPlayer)
{
    player.Update();

    if (player.Shoot() && !bulletActive) // Si el jugador dispara y no hay una bala activa
    {
        Bullet bullet(player.Pos().x + 12, player.Pos().y + 24, spritesheet, IntRect(13 * 8 + 16, 6 * 8 + 6, 8, 8), -10); // Considerar para los sprites
        bulletPlayer = bullet;
        bulletActive = true; // Activar la bala
    }
}
void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies, IntRect &bulletRect, IntRect &enemieRect)
{
    if (bulletActive)
    {
        bulletPlayer.Update();
        if (bulletPlayer.Pos().y < -24) // Si la bala sale de la pantalla
            bulletActive = false;       // Desactivar la bala
        bulletRect = IntRect(bulletPlayer.Pos().x, bulletPlayer.Pos().y, 3, 8);
        for (int i = 0; i < (int)enemies.size(); i++)
        {
            for (int j = 0; j < (int)enemies[i].size(); j++)
            {
                enemieRect = IntRect(enemies[i][j].Pos().x, enemies[i][j].Pos().y, 24, 24);
                if (enemieRect.intersects(bulletRect))
                {                                             // Si la bala colisiona con un enemigo
                    enemies[i].erase(enemies[i].begin() + j); // Eliminar el enemigo
                    bulletActive = false;                     // Desactivar la bala
                }
            }
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
            minX = min(minX, (int)enemies[i][j].Pos().x + 24 * dirEnemies);
        }
    }
    if (minX < 24 || maxX > 576) // Considerar los límites de la pantalla
    {
        for (int i = 0; i < (int)enemies.size(); i++)
        {
            for (int j = 0; j < (int)enemies[i].size(); j++)
            {
                enemies[i][j].ChangeDir(); // Cambiar dirección si se alcanza el borde
            }
        }
        dirEnemies *= -1; // Cambiar la dirección de movimiento
    }
    for (int i = 0; i < (int)enemies.size(); i++)
    {
        for (int j = 0; j < (int)enemies[i].size(); j++)
        {
            enemies[i][j].Update();
        }
    }
    timer++;
    if (timer >= cadencia&&(int)enemies.size() > 0) // Si ha pasado el tiempo de cadencia y hay enemigos
    {
        timer = 0;
        srand(time(NULL)); // Inicializar la semilla aleatoria
        int enem = rand() %(int)enemies.size();
        Bullet bullet = Bullet(enemies[0][enem].Pos().x+24, enemies[0][enem].Pos().y-24, spritesheet, IntRect(13 * 8 + 16, 6 * 8 + 6, 8, 8), 10);
        bulletsEnemies.push_back(bullet); // Agregar la bala a la lista de balas
    }
}