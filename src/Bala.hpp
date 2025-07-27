#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Bullet : public Drawable {
    private:
        Sprite sprite;
        int vel;
        float ubi;
    public:
        Bullet(int x, int y, Texture &texture, IntRect intRect,int v);
        void Update(); 
        Vector2f Pos();
        float getPreviousY() const { return ubi; }  
        virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
