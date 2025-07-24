#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

<<<<<<< Updated upstream
class Player : public Drawable {
    private:
        Sprite sprite;
        int vida;
        int vel;
        bool shoot=false;
        SoundBuffer shootBuffer;
        Sound shootSound;

        // AÑADIDO PARA EXPLOSIÓN
        SoundBuffer deathBuffer;
        Sound deathSound;

    public:
        Player(int x, int y, Texture& texture);
        void update();
        bool Shooy();
        Vector2f pos();
    
        // AÑADIDO: método para sonar explosión
        void die();

        virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
=======
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
    void update();
    bool Shoot();
    void QuitarVida();
    bool Vivo();
    Vector2f pos();
    virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
>>>>>>> Stashed changes
