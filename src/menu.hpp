#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define Max_main_menu 2 ///< Número máximo de opciones del menú.

using namespace sf;

/**
 * @class Menu
 * @brief Clase que representa un menú principal con opciones y música de fondo.
 * 
 * Permite mostrar opciones de menú, navegar entre ellas,
 * y reproducir música de fondo para el menú.
 */
class Menu
{
public:
    /**
     * @brief Constructor que inicializa el menú con dimensiones para posicionar opciones.
     * 
     * @param width Ancho de la ventana para centrar los textos.
     * @param height Alto de la ventana para distribuir verticalmente las opciones.
     */
    Menu(float width, float height);

    /**
     * @brief Destructor de la clase Menu.
     */
    ~Menu();

    /**
     * @brief Dibuja las opciones del menú en la ventana proporcionada.
     * 
     * @param window Referencia a la ventana SFML donde se dibujará el menú.
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Cambia la selección activa hacia arriba.
     * 
     * La selección se mueve cíclicamente al llegar al inicio.
     */
    void MoveUp();

    /**
     * @brief Cambia la selección activa hacia abajo.
     * 
     * La selección se mueve cíclicamente al llegar al final.
     */
    void MoveDown();

    /**
     * @brief Obtiene el índice de la opción actualmente seleccionada.
     * 
     * @return int Índice de la opción seleccionada (0 a Max_main_menu - 1).
     */
    int mainMenuPressed() {
        return main_menu_selected;
    }

    /**
     * @brief Inicia la reproducción de la música de fondo del menú.
     */
    void PlayMusic();

    /**
     * @brief Detiene la reproducción de la música de fondo del menú.
     */
    void StopMusic();

private:
    int main_menu_selected;          ///< Índice de la opción actualmente seleccionada.
    sf::Font font;                   ///< Fuente utilizada para mostrar el texto.
    sf::Text main_menu[Max_main_menu]; ///< Array con los textos de las opciones del menú.

    sf::Music menuMusic;             ///< Objeto para manejar la reproducción de música.
};