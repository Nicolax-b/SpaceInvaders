#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
class HUD : public Drawable
{
private:
    Text vidasText;
    Text scoreText;
    int vidas;
    int score;

public:
    HUD(Font &font);
    void updateVidas(int v);
    void updateScore(int s);
    virtual void draw(RenderTarget &target, RenderStates states) const override;
};