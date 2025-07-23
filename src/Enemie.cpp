#include "Enemie.hpp"

Enemie::Enemie(int x, int y, Texture &texture, Vector2f p){
	point = p;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(point.x,point.y,8,8));
	sprite.setPosition(x,y);
	sprite.setScale(3,3);
	state=0;
	timer=0;
	vel=24;
}

void Enemie::update() {
    if (state == 100) {
       sprite.move(vel,0);
       state++;
       state%=2;
       sprite.setTextureRect(IntRect(point.x+state*9, point.y 8, 8));
        timer=0;
    }
    timer++;
} 
void Enemie::ChangeDir() {
   vel*=-1;
   sprite.move)0,abs(vel));
}

vector2f Enemie::Pos(){
   return sprite.getPosition();
}
       
void Enimer::draw(RenderTarget &rt , RenderStates rs) const {
    rt.draw(sprite, rs);
}   