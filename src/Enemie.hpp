#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Enemie : public Drawable
{
private:
    Sprite sprite;
    int vel;
    int state;
    int timer;
    int cadencia;
    Vector2f point;
    bool shoot = false;
    int contadorDisparo = 0;

   //sonido de disparo
    SoundBuffer shootBuffer;
    Sound shootSound;

    // sonido de explosión
    SoundBuffer explosionBuffer;
    Sound explosionSound; 

public:
    Enemie(int x, int y, Texture &texture, Vector2f p);
    void Update();
    void ChangeDir();
    void ActivarDisparo();
    void UpdateDisparo();
    Vector2f Pos();
    void AumentarCadencia();
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};