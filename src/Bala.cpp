#include "Bala.hpp"
#include <iostream>  // si necesitas para mensajes, si no, puedes quitar también

Bullet::Bullet(int x, int y, Texture &texture, IntRect intRect, int v)
    : sprite(texture, intRect)
{
    sprite.setPosition(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
    sprite.setScale(sf::Vector2f(3.0f, 3.0f));
    vel = v;
}

void Bullet::update() {
    sprite.move(sf::Vector2f(0, vel));
}

Vector2f Bullet::Pos() {
    return sprite.getPosition();
}

void Bullet::draw(RenderTarget &rt, RenderStates rs) const {
    rt.draw(sprite, rs);
}
