#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cmath>
#include <cstdlib> 
#include <time.h>
#include "Jugador.hpp"
#include "Bala.hpp"
#include "Enemie.hpp"
#include "Menu.hpp"
#include "Muro.hpp"
#include "Win.hpp"
#include "Lose.hpp"

using namespace std;
using namespace sf;

void UpdatePlayer(Player &player, bool &bulletActive, Bullet &bulletPlayer);
void UpdateBulletPlayer(Bullet &bulletPlayer, bool &bulletActive, vector<vector<Enemie>> &enemies, IntRect &bulletRect, IntRect &enemieRect);
void UpdateEnemies(vector<vector<Enemie>> &enemies);
void UpdateBulletsEnemies(Player &player);
void UpdateMuro(vector<Muro> &muro,Bullet &bulletPlayer);

Texture spritesheet;
Texture spritesheetmuro;

int timer = 0;
int cadencia = 125;

int dirEnemies=1; //1 para derecha, -1 para izquierda
int maxX,minX;
int cantEnemies;
// Variables para la resolución
int screenWidth;
int screenHeight;

vector<Bullet> bulletsEnemies;
vector<pair<int,Vector2f>> posicionMuro;
Vector2f sectionSpritesheet;

IntRect playerRect;
IntRect bulletRect;
IntRect enemieRect;
IntRect muroRect;

bool bulletActive = false;

// Lista de canciones para reproducir aleatoriamente
vector<string> canciones = {
    "Music/Play1.ogg",
    "Music/Play2.ogg"
};

Music musicaJuego;
int cancionActual = -1;
void ReproducirCancionAleatoria(vector<string>& canciones, Music& musicaJuego, int& cancionActual)
{
    int nuevaCancion;
    do {
        nuevaCancion = rand() % canciones.size();
    } while (nuevaCancion == cancionActual && canciones.size() > 1);

    cancionActual = nuevaCancion;

    if (!musicaJuego.openFromFile(canciones[cancionActual])) {
        cout << "No se pudo cargar la canción: " << canciones[cancionActual] << endl;
        return;
    }

    musicaJuego.play();
}

int main()
{
    RenderWindow menuWindow(VideoMode(1920, 1080), "MENU SPACE INVADERS EPN");
    Menu menu(menuWindow.getSize().x, menuWindow.getSize().y);
    menu.PlayMusic();

    while (menuWindow.isOpen())
    {
        Event event;
        while (menuWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                menuWindow.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                    menu.MoveUp();
                else if (event.key.code == Keyboard::Down)
                    menu.MoveDown();
                else if (event.key.code == Keyboard::Return)
                {
                    int selected = menu.mainMenuPressed();
                    if (selected == 0) // Play
                    {
                        menu.StopMusic();
                        menuWindow.close(); // Salir del menú
                    }
                    else if (selected == 1) // Exit
                    {
                        menuWindow.close();
                        return 0; // Salir del programa
                    }
                }
            }
        }

        menuWindow.clear();
        menu.draw(menuWindow);
        menuWindow.display();
    }
    
    RenderWindow window(VideoMode::getDesktopMode(), "Space Invaders EPN",Style::Fullscreen);
    window.setFramerateLimit(60);
    screenWidth = window.getSize().x;
    screenHeight = window.getSize().y;
    // Reproducir música de fondo
    srand(time(NULL));
    ReproducirCancionAleatoria(canciones, musicaJuego, cancionActual);
    if (!spritesheet.loadFromFile("spritesheetnuevo.png"))
    {
        cout << "Error al cargar la textura\n";
    };
    if (!spritesheetmuro.loadFromFile("spritesheet.png"))
    {
        cout << "Error al cargar la textura\n";
    };
    Player player(screenWidth/2-24,screenHeight-100, spritesheet);
    Bullet bulletPlayer(0, 0, spritesheet, IntRect(0, 0, 0, 0), 0);
    vector<vector<Enemie>> enemies(7, vector<Enemie>(12, Enemie(0, 0, spritesheet, Vector2f(0, 0))));
    Vector2f sectionSpritesheet;
    //variables para la resolución
    float offsetX = screenWidth / 15.f;
    float offsetY = screenHeight / 20.f;
    float startX = screenWidth / 8.f;
    float startY = screenHeight / 10.f;


    for (int i = 0; i < (int)enemies.size(); i++)
    {
        for (int j = 0; j < (int)enemies[i].size(); j++)
        { // Considerar para los sprites
            if (i == 0)
            {
                sectionSpritesheet = Vector2f(0, 0);
            }
            else if (i < 3)
            {
                sectionSpritesheet = Vector2f(0, 28);
            }
            else if (i < 5)
            {
                sectionSpritesheet = Vector2f(0, 56);
            }
            else if (i < 7)
            {
                sectionSpritesheet = Vector2f(0, 79);
            }
            float x = startX + j * offsetX;
            float y = startY + i * offsetY;
            enemies[i][j] = Enemie(x, y, spritesheet, sectionSpritesheet);
        }
    }

    vector<Muro> muro(4,Muro(0,0,spritesheetmuro));
	
	for(int i = 0; i < 4; i++){
		float muroY = screenHeight * 0.7f; // 70% de la pantalla
        float muroXBase = screenWidth * 0.15f;
        float muroDist = screenWidth * 0.22f;
        muro[i] = Muro(muroXBase + i * muroDist, muroY, spritesheetmuro);
	}

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //Actualizar
        UpdatePlayer(player, bulletActive, bulletPlayer);
        UpdateBulletPlayer(bulletPlayer, bulletActive, enemies, bulletRect, enemieRect);
        UpdateEnemies(enemies);
        UpdateBulletsEnemies(player);
        UpdateMuro(muro,bulletPlayer);

        if (!player.Vivo())
        {
            // Si el jugador no tiene vida, mostrar pantalla de derrota
            window.close();
            musicaJuego.stop();
            MostrarPantallaLose();  
            return 0;
        }
        for(int i = 0; i < (int)enemies.size(); i++){
			for(int j = 0; j < (int)enemies[i].size(); j++){
				if(enemies[i][j].Pos().y>=screenHeight * 0.9f)
                {
                    // Si un enemigo llega al borde inferior, mostrar pantalla de derrota
                    window.close();
                    musicaJuego.stop();
                    MostrarPantallaLose();
                    return 0;
                }
			}
		}
        cantEnemies=0;
		
		for(int i = 0; i < (int)enemies.size(); i++) cantEnemies+=(int)enemies[i].size();
		
		if(cantEnemies==0)
        {
            // Si no hay enemigos, mostrar pantalla de victoria
            window.close();
            musicaJuego.stop();
            MostrarPantallaWin();
            return 0;
        }

        window.clear(Color::Black);

        for (int i = 0; i < (int)bulletsEnemies.size(); i++)
        {
            window.draw(bulletsEnemies[i]);
        }
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
        for (int i = 0; i<4; i++)
        {
            window.draw(muro[i]);
        }
        window.draw(player);
        window.display();
        // Reproducir música de fondo
        if (musicaJuego.getStatus() == SoundSource::Status::Stopped)
        {
            ReproducirCancionAleatoria(canciones, musicaJuego, cancionActual);
        }
    }
    return 0;
}

void MostrarPantallaWin()
{
    RenderWindow winWindow(VideoMode(600, 600), "¡Ganaste!");
    Win win(winWindow.getSize().x, winWindow.getSize().y);
    win.PlayMusic();

    while (winWindow.isOpen())
    {
        Event event;
        while (winWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                winWindow.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                    win.MoveUp();
                else if (event.key.code == Keyboard::Down)
                    win.MoveDown();
                else if (event.key.code == Keyboard::Return)
                {
                    int selected = win.GameWinPressed();  // Revisa que tu método se llame así
                    if (selected == 0) // Play Again
                    {
                        win.StopMusic();
                        winWindow.close();
                        main(); // Reinicia el juego
                        return;
                    }
                    else if (selected == 1) // Exit
                    {
                        winWindow.close();
                        exit(0);
                    }
                }
            }
        }
        winWindow.clear();
        win.draw(winWindow);
        winWindow.display();
    }
}

void MostrarPantallaLose()
{
    RenderWindow loseWindow(VideoMode(600, 600), "Perdiste");
    Lose lose(loseWindow.getSize().x, loseWindow.getSize().y);
    lose.PlayMusic();

    while (loseWindow.isOpen())
    {
        Event event;
        while (loseWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                loseWindow.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                    lose.MoveUp();
                else if (event.key.code == Keyboard::Down)
                    lose.MoveDown();
                else if (event.key.code == Keyboard::Return)
                {
                    int selected = lose.GameLosePressed();
                    if (selected == 0) // Play Again
                    {
                        lose.StopMusic();
                        loseWindow.close();
                        main();
                        return;
                    }
                    else if (selected == 1) // Exit
                    {
                        loseWindow.close();
                        exit(0);
                    }
                }
            }
        }
        loseWindow.clear();
        lose.draw(loseWindow);
        loseWindow.display();
    }
}

void UpdatePlayer(Player &player, bool &bulletActive, Bullet &bulletPlayer)
{
    player.Update();

    if (player.Shoot() && !bulletActive) // Si el jugador dispara y no hay una bala activa
    {
        Bullet bullet(player.Pos().x + 24, player.Pos().y + 12, spritesheet, IntRect(75,122, 32, 32), -15); // Considerar para los sprites
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
        {
            bulletActive = false;       // Desactivar la bala
            return; // Salir de la función
        }
        // Colisión precisa: trayecto vertical de la bala
        float x = bulletPlayer.Pos().x;
        float y1 = bulletPlayer.getPreviousY();
        float y2 = bulletPlayer.Pos().y;
        float top = min(y1, y2);
        float height = fabs(y1 - y2);
        bulletRect = IntRect(bulletPlayer.Pos().x, bulletPlayer.Pos().y, 9, 32);
        // Verificar colisión con enemigos
        for (int i = 0; i < (int)enemies.size(); i++)
        {
            for (int j = 0; j < (int)enemies[i].size(); j++)
            {
                enemieRect = IntRect(static_cast<int>(enemies[i][j].Pos().x), static_cast<int>(enemies[i][j].Pos().y),32, 32);
                if (enemieRect.intersects(bulletRect))
                {                                             // Si la bala colisiona con un enemigo
                    enemies[i].erase(enemies[i].begin() + j); // Eliminar el enemigo
                    bulletActive = false;                     // Desactivar la bala
                    break;                                    // Salir del bucle de enemigos
                }
            }
            if (!bulletActive)
                break; // Si la bala ya no está activa, salir del bucle
        }
        if (!bulletActive)
        {
        for (int i = 0; i < (int)enemies.size(); i++)
        {
            for (int j = 0; j < (int)enemies[i].size(); j++)
            {
                enemies[i][j].AumentarCadencia(); // Aumentar la cadencia de disparo de los enemigos
            }
        }
        cadencia--;
        }
    }
}
void UpdateEnemies(vector<vector<Enemie>> &enemies)
{
    maxX = 0;
    minX = screenWidth;
    for (int i = 0; i < (int)enemies.size(); i++)
    {
        for (int j = 0; j < (int)enemies[i].size(); j++)
        {
            maxX = max(maxX, (int)enemies[i][j].Pos().x + 50 * dirEnemies);
            minX = min(minX, (int)enemies[i][j].Pos().x + 50 * dirEnemies);
        }
    }
    if (minX < 50 || maxX > screenWidth-50) // Considerar los límites de la pantalla
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
            enemies[i][j].UpdateDisparo();
        }
    }
    timer++;
    if (timer >= cadencia && (int)enemies.size() > 0) // Si ha pasado el tiempo de cadencia y hay enemigos
    {
        timer = 0;
        srand(time(NULL)); // Inicializar la semilla aleatoria
        int col = rand() % enemies[0].size();
        for (int fila = (int)enemies.size() - 1; fila >= 0; fila--)
        {
            if (col < (int)enemies[fila].size())
            {
                Enemie &enemigo= enemies[fila][col];
                enemigo.ActivarDisparo(); // Activar disparo del enemigo
                Bullet bullet = Bullet(enemigo.Pos().x + 9, enemigo.Pos().y - 12, spritesheet, IntRect(43,122, 32,32), 15); // sprites
                bulletsEnemies.push_back(bullet);  
                break;
            }
        }                                                                                                         
    }
}
void UpdateBulletsEnemies(Player &player)
{
    for (int i = 0; i < (int)bulletsEnemies.size(); i++)
    {
        bulletsEnemies[i].Update();
    }
    for (int i = 0; i < (int)bulletsEnemies.size(); i++)
    {
        if (bulletsEnemies[i].Pos().y > screenHeight) // Si la bala sale de la pantalla
        {
            bulletsEnemies.erase(bulletsEnemies.begin() + i); // Eliminar la bala
        }
    }
    playerRect = IntRect(player.Pos().x, player.Pos().y + 9, 48, 15); // En cuenta sprites
    for (int i = 0; i < (int)bulletsEnemies.size(); i++)
    {
        bulletRect = IntRect(bulletsEnemies[i].Pos().x, bulletsEnemies[i].Pos().y, 3, 24);
        if (playerRect.intersects(bulletRect))
        {
            bulletsEnemies.erase(bulletsEnemies.begin() + i);
            player.QuitarVida();
        }
    }
}
void UpdateMuro(vector<Muro> &muro,Bullet &bulletPlayer)
{
    if (bulletActive)
    {
        bulletRect= IntRect(bulletPlayer.Pos().x, bulletPlayer.Pos().y, 3, 8);
        for (int i = 0; i < 4; i++)
        {
            muro[i].Pos(posicionMuro);
            for(int i=0; i < 4; i++){
                muroRect=IntRect(posicionMuro[i].second.x, posicionMuro[i].second.y, 24, 24);
                if (muroRect.intersects(bulletRect))
                {
                    muro[i].Colision(posicionMuro[i].first, false); // Considerar sprites
                    bulletActive = false; // Desactivar la bala
                }
            }
            if(!bulletActive) break; // Si la bala ya no está activa, salir del bucle
        }
    }
    bool elim = false;
    for (int h=0; h<(int)bulletsEnemies.size();h++){
    bulletRect= IntRect(bulletsEnemies[h].Pos().x, bulletsEnemies[h].Pos().y, 3, 8);
        for (int i = 0; i < 4; i++)
        {
            muro[i].Pos(posicionMuro);
            for(int j=0; j < (int) posicionMuro.size(); j++){
                muroRect=IntRect(posicionMuro[j].second.x, posicionMuro[j].second.y, 24, 24);
                if (muroRect.intersects(bulletRect))
                {
                    muro[i].Colision(posicionMuro[j].first, true); // Considerar sprites
                    bulletsEnemies.erase(bulletsEnemies.begin() + h); // Eliminar la bala enemiga
                    elim = true;
                    break;
                }
            }
            if(elim) break; // Si la bala ya no está activa, salir del bucle
        }
    }
    for (int i = 0; i < 4; i++)
    {
        muro[i].Update(); // Actualizar el muro
    }
}
