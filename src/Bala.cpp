#include "Bala.hpp"

Bullet:Bullet(int x, int y, Texture &texture, intrect intRect, int v) {
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect);
    sprite.posicion(x,y);
    sprite.setscale(3,3);
    vel=v;
}
void Bullet::update() {
    sprite.move(0, vel);
}

Vector2f Bullet::Pos() {
    return sprite.getPosition();
}

void Bullet::draw(RenderTarget &rt, RenderStates rs) const {
    rt.draw(sprite, rs);
}