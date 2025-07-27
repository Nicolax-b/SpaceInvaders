#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Player : public Drawable
{
private:
    Sprite sprite;
    int vida;
    int vel;
    bool shoot = false;
    SoundBuffer shootBuffer;
    Sound shootSound;

public:
    Player(int x, int y, Texture &texture);
    void Update();
    bool Shoot();
    void QuitarVida();
    bool Vivo();
    Vector2f Pos();
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
