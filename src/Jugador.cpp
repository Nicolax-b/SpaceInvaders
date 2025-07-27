#include "Jugador.hpp"
#include <SFML/Audio.hpp>
#include <iostream>


Player::Player(int x, int y, Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 118, 32, 32));
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
}

void Player::Update()
{
    //Teclado
    if (Keyboard::isKeyPressed(Keyboard::Right) && sprite.getPosition().x + vel < 1840) //considerar para los sprites y mando
    {
        sprite.move(vel, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left) && sprite.getPosition().x + vel * -1 > 0)
    {
        sprite.move(vel * -1, 0);
    }
    //Mando
    if (Joystick::isConnected(0))
    {
        float axisX = Joystick::getAxisPosition(0, Joystick::X);

        if (axisX > 50 && sprite.getPosition().x + vel < 1840)
        {
            sprite.move(vel, 0);
        }
        else if (axisX < -50 && sprite.getPosition().x - vel > 0)
        {
            sprite.move(-vel, 0);
        }
    }
}

bool Player::Shoot()
{
    //Teclado
    if (Keyboard::isKeyPressed(Keyboard::Space) && !shoot) //considerar mando
    {
        shoot = true;
        shootSound.play(); // Aquí reproduzco el sonido al disparar
        return true;
    }
    else if (!Keyboard::isKeyPressed(Keyboard::Space))
    {
        shoot = false;
    }
    //Mando
    if (Joystick::isConnected(0))
    {
        if (Joystick::isButtonPressed(0, 0) && !shoot)
        {
            shoot = true;
            shootSound.play();
            return true;
        }
        else if (!Joystick::isButtonPressed(0, 0))
        {
            shoot = false;
        }
    }

    return false;
}

Vector2f Player::Pos()
{
    return sprite.getPosition();
}

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
    rt.draw(sprite, rs);
}