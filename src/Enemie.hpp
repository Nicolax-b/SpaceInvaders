#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf; 
class Enemie :public Drawable {
    private:  
        Sprite sprite;
        int vel;
        int state:
        int timer;
        Vector2f point;
    public:
        Enemie(int x, int y, Texture &texture, Vector2f p); 
        void update();
        void ChangeDir(); 
        vector2f pos();
        virtual void draw(RenderTarget &rt , RenderStates rs) const ;
};