#include "HUD.hpp"

HUD::HUD(Font &font)
{
    // Inicializar texto de vidas
    vidasText.setFont(font);
    vidasText.setCharacterSize(24);
    vidasText.setFillColor(sf::Color::Red);
    vidasText.setPosition(20.f, 10.f);
    vidas = 3; // valor por defecto
    updateVidas(vidas);

    // Inicializar texto de puntaje
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreText.setPosition(20.f, 40.f);
    score = 0;
    updateScore(score);
}

void HUD::updateVidas(int nuevasVidas)
{
    vidas = nuevasVidas;
    vidasText.setString("Vidas: " + std::to_string(vidas));
}

void HUD::updateScore(int nuevoScore)
{
    score = nuevoScore;
    scoreText.setString("Score: " + std::to_string(score));
}

void HUD::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(vidasText, states);
    target.draw(scoreText, states);
}
