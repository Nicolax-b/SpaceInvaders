#include "Enemie.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

Enemie::Enemie(int x, int y, Texture &texture, Vector2f p)
{
    point = p;
    sprite.setTexture(texture);
    state = 0;
    timer = 0;
    vel = 24;
    cadencia = 125;
    sprite.setTextureRect(IntRect(point.x, point.y, 32, 32));
    sprite.setPosition(x, y);
    sprite.setScale(2.5, 2.5);
   

    //  CARGA EL ARCHIVO DE AUDIO AQUÍ
    if (!shootBuffer.loadFromFile("sounds/shootenemy.wav"))
    {
        cerr << "Error: No se pudo cargar el sonido de disparo.\n";
    }
    else
    {
        shootSound.setBuffer(shootBuffer);
    } 

    // NUEVO: cargar sonido de explosión
     if (!explosionBuffer.loadFromFile("sounds/explosionenemy.wav"))
    {
        cerr << "Error: No se pudo cargar el sonido de explosión.\n";
    }
    else
    {
        explosionSound.setBuffer(explosionBuffer);
    }   
}
void Enemie::Update()
{
    if (timer >= cadencia)
    {
        sprite.move(vel, 0);
        state++;
        state %= 2;
        sprite.setTextureRect(IntRect(point.x + state * 33, point.y, 30, 30));
        timer = 0;

        //  AQUÍ LLAMAMOS A LA FUNCIÓN QUE REPRODUCE EL SONIDO
        //Disparar(); // Reproduce el sonido de disparo del enemigo
    }
    timer++;
}
void Enemie::ChangeDir()
{
    vel *= -1;
    sprite.move(0, abs(vel));
}

Vector2f Enemie::Pos()
{
    return sprite.getPosition();
}

void Enemie::AumentarCadencia()
{
    cadencia--;
}

void Enemie::draw(RenderTarget &rt, RenderStates rs) const
{
    rt.draw(sprite, rs);
}
void Enemie::ActivarDisparo()
{
    if (!shoot)
    {
        shoot = true;
        contadorDisparo = 180;
        shootSound.play(); // Reproducir sonido de disparo
        sprite.setTextureRect(IntRect(96, point.y, 30, 30)); // Cambiar a sprite de disparo
    }
}
void Enemie::UpdateDisparo()
{
    if (shoot)
    {
        contadorDisparo--;
        if (contadorDisparo <= 0)
        {
            shoot = false;
            sprite.setTextureRect(IntRect(point.x + state * 33, point.y, 30, 30)); // Volver al sprite normal
        }
    }
}