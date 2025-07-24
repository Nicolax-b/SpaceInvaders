#include <iostream>
#include <SFML/Graphics.hpp>

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
<<<<<<< Updated upstream
    
    // sonido de disparo
    SoundBuffer shootBuffer; 
    Sound shootSound;

    // sonido de explosión
    SoundBuffer explosionBuffer;
    Sound explosionSound;
=======
>>>>>>> Stashed changes

public:
    Enemie(int x, int y, Texture &texture, Vector2f p);
    void update();
    void ChangeDir();
    Vector2f Pos();
    void AumentarCadencia();
<<<<<<< Updated upstream
    void Disparar(); 
    void Morir(); // NUEVO: método para reproducir sonido de explosión
=======
>>>>>>> Stashed changes
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};