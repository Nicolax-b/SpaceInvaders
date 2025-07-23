#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 

using namespace std;
using namespace sf;

class Enemie : public Drawable {
private:
    Sprite sprite;
    int vel;
    int state;
    int cadencia;
    int timer;
    Vector2f point;

    SoundBuffer shootBuffer; 
    Sound shootSound;        

public:
    Enemie(int x, int y, Texture &texture, Vector2f p);
    void Update();
    void ChangeDir();
    Vector2f Pos();
    void AumentarCadencia();
    void Disparar(); 
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};