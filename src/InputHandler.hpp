#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief Resultado de la entrada de usuario en el menú.
 */
enum class InputResult
{
    Nada,       ///< No se ha producido ninguna acción
    Subir,      ///< Mover selección hacia arriba
    Bajar,      ///< Mover selección hacia abajo
    Seleccionar ///< Confirmar selección (Enter o botón A)
};

/**
 * @brief Maneja la entrada del usuario desde teclado o joystick.
 * 
 * @param event Evento SFML recibido del sistema
 * @return InputResult Acción detectada a partir del evento
 */
inline InputResult manejarInputMenu(const sf::Event& event)
{
    using namespace sf;

    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::Up) return InputResult::Subir;
        if (event.key.code == Keyboard::Down) return InputResult::Bajar;
        if (event.key.code == Keyboard::Return) return InputResult::Seleccionar;
    }

    if (event.type == Event::JoystickMoved && event.joystickMove.axis == Joystick::Y)
    {
        if (event.joystickMove.position < -50) return InputResult::Subir;
        if (event.joystickMove.position > 50) return InputResult::Bajar;
    }

    if (event.type == Event::JoystickButtonPressed)
    {
        if (event.joystickButton.button == 0) return InputResult::Seleccionar; // botón A
    }

    return InputResult::Nada;
}