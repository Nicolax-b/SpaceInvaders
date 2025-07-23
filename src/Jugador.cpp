#include "Jugador.hpp"
#include <SFML/Audio.hpp>

Player(int x, int y, Texture& texture){
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(13*8+8, 7*8+7, 16,8));
    sprite.posicion(x,y);
    sprite.setscale(3,3);
    vida=100;
    vel=5;

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

void Player::update() {
    if(Keyboard::isKeyPressed(Keyboard::right)&&sprite.getPosition().x+vel<552){
        sprite.move(vel, 0);
    }
    if(Keyboard::isKeyPressed(Keyboard::left)&&sprite.getPosition().x+vel*-1>0) {
        sprite.move(vel*-1, 0);
    }
}

bool Player::Shoot(){
    if(keyboard::isKeyPressed(Keyboard::space)&& !shoot){
        shoot=true;
        shootSound.play();  // Aquí reproduzco el sonido al disparar
        return true;
    }else if(keyboard::isKeyPressed(Keyboard::space)){
        shoot=false;
    }
    return false;
}

Vector2f Player::pos() {
    return sprite.getPosition();
}

void draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(sprite, rs);
}
