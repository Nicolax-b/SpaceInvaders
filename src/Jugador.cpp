#include "Jugador.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

Player::Player(int x, int y, Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(13 * 8 + 8, 7 * 8 + 7, 16, 8));
    sprite.setPosition(x, y);
    sprite.setScale(3, 3);
    vida = 3;
    vel = 5;

    // Cargo el sonido para disparo
    if (!shootBuffer.loadFromFile("sounds/Bala.wav"))
    {
        cerr << "Error: No se pudo cargar el sonido de disparo.\n";
    }
    else
    {
        shootSound.setBuffer(shootBuffer);
    }

    //  AÑADIDO: cargar sonido de explosión
    if (!deathBuffer.loadFromFile("sounds/explosionjugador.wav")) {
        cerr << "Error: No se pudo cargar el sonido de explosión.\n";
    } else {
        deathSound.setBuffer(deathBuffer);
    }
}

void Player::update()
{
    if (Keyboard::isKeyPressed(Keyboard::Right) && sprite.getPosition().x + vel < 552)
    {
        sprite.move(vel, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left) && sprite.getPosition().x + vel * -1 > 0)
    {
        sprite.move(vel * -1, 0);
    }
}

bool Player::Shoot()
{
    if (Keyboard::isKeyPressed(Keyboard::Space) && !shoot)
    {
        shoot = true;
        shootSound.play(); // Aquí reproduzco el sonido al disparar
        return true;
    }
    else if (!Keyboard::isKeyPressed(Keyboard::Space))
    {
        shoot = false;
    }
    return false;
}

Vector2f Player::pos()
{
    return sprite.getPosition();
}

<<<<<<< Updated upstream
//  AÑADIDO: método para reproducir sonido de muerte
void Player::die() {
    deathSound.play();
}

void draw(RenderTarget &rt, RenderStates rs) const{
=======
void Player::QuitarVida()
{
    vida--;
}

bool Player::Vivo()
{
    return (vida != 0);
}

void Player::draw(RenderTarget &rt, RenderStates rs) const
{
>>>>>>> Stashed changes
    rt.draw(sprite, rs);
}