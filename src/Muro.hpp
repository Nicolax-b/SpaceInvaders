#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class muro : public Drawable{
    private:
        vector<Sprite> sprites;
        vector<pair<int,int>> state;
    public:
        Muro(int x, int y, Texture &texture);
        void Pos(vector<Vector2f> &pos);
        void Update();
        void Colision(int indice, bool up);
        virtual void draw(RenderTarget &rt, RenderStates rs) const;
}