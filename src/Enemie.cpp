#include "Enemie.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

<<<<<<< Updated upstream
Enemie::Enemie(int x, int y, Texture &texture, Vector2f p) {
=======
Enemie::Enemie(int x, int y, Texture &texture, Vector2f p)
{
>>>>>>> Stashed changes
    point = p;
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(point.x, point.y, 8, 8));
    sprite.setPosition(x, y);
    sprite.setScale(3, 3);
    state = 0;
    timer = 0;
    vel = 24;
    cadencia = 150;
<<<<<<< Updated upstream

    //  CARGA EL ARCHIVO DE AUDIO AQUÍ
    if (!shootBuffer.loadFromFile("sounds/shootenemy.wav")) {
        cerr << "Error: No se pudo cargar el sonido de disparo.\n";
    } else {
        shootSound.setBuffer(shootBuffer);
    }

    // NUEVO: cargar sonido de explosión
    if (!explosionBuffer.loadFromFile("sounds/explosionenemy.wav")) {
        cerr << "Error: No se pudo cargar el sonido de explosión.\n";
    } else {
        explosionSound.setBuffer(explosionBuffer);
    }
=======
>>>>>>> Stashed changes
}

void Enemie::update()
{
    if (timer >= cadencia)
    {
        sprite.move(vel, 0);
        state++;
        state %= 2;
        sprite.setTextureRect(IntRect(point.x + state * 9, point.y, 8, 8));
        timer = 0;
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

//  CARGA EL ARCHIVO DE AUDIO AQUÍ
if (!shootBuffer.loadFromFile("sounds/shootenemy.wav"))
{
    cerr << "Error: No se pudo cargar el sonido de disparo.\n";
}
else
{
    shootSound.setBuffer(shootBuffer);
}

void Enemie::Update()
{
    if (timer >= cadencia)
    {
        sprite.move(vel, 0);
        state++;
        state %= 2;
        sprite.setTextureRect(IntRect(point.x + state * 9, point.y, 8, 8));
        timer = 0;

        //  AQUÍ LLAMAMOS A LA FUNCIÓN QUE REPRODUCE EL SONIDO
        Disparar(); // Reproduce el sonido de disparo del enemigo
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

void Enemie::Disparar()
{
    shootSound.play();
}

<<<<<<< Updated upstream
void Enemie::Morir() {
    explosionSound.play(); // NUEVO: reproduce sonido de explosión
}

void Enemie::draw(RenderTarget &rt, RenderStates rs) const {
    rt.draw(sprite, rs);
}
=======
void Enemie::draw(RenderTarget &rt, RenderStates rs) const
{
    rt.draw(sprite, rs);
}
>>>>>>> Stashed changes
