#include "Menu.hpp"

/**
 * @brief Constructor de la clase Menu.
 * 
 * Inicializa las opciones del menú principal, carga la fuente y
 * posiciona las opciones "Play" y "Exit" en pantalla.
 * 
 * @param width Ancho de la ventana para centrar las opciones horizontalmente.
 * @param height Alto de la ventana para distribuir verticalmente las opciones.
 */
Menu::Menu(float width, float height) {
    if (!font.loadFromFile("fonts/ARCADE_N.TTF")) {
        std::cerr << "Error al cargar la fuente.\n";
    }

    // Configuración de la opción "Play"
    main_menu[0].setFont(font);
    main_menu[0].setFillColor(Color::Green);
    main_menu[0].setString("Play");
    main_menu[0].setCharacterSize(200);
    FloatRect textBounds0 = main_menu[0].getLocalBounds();
    main_menu[0].setOrigin(textBounds0.left + textBounds0.width / 2.0f, textBounds0.top);
    main_menu[0].setPosition(Vector2f(width / 2.f, height / 2.0f));

    // Configuración de la opción "Exit"
    main_menu[1].setFont(font);
    main_menu[1].setFillColor(Color::Red);
    main_menu[1].setString("Exit");
    main_menu[1].setCharacterSize(50);
    FloatRect textBounds1 = main_menu[1].getLocalBounds();
    main_menu[1].setOrigin(textBounds1.left + textBounds1.width / 2.0f, textBounds1.top);
    main_menu[1].setPosition(Vector2f(width / 2.f, height / 3.f * 2.f));

    main_menu_selected = 0; ///< Índice de la opción actualmente seleccionada.
}

/**
 * @brief Destructor de la clase Menu.
 * 
 * No realiza operaciones especiales, se mantiene vacío.
 */
Menu::~Menu() {}

/**
 * @brief Dibuja todas las opciones del menú en la ventana proporcionada.
 * 
 * @param window Referencia a la ventana SFML donde se dibujará el menú.
 */
void Menu::draw(RenderWindow &window) {
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(main_menu[i]);
    }
}

/**
 * @brief Cambia la selección del menú hacia arriba.
 * 
 * Modifica el color para reflejar la nueva opción seleccionada,
 * implementando un ciclo continuo cuando se supera el límite superior.
 */
void Menu::MoveUp() {
    main_menu[main_menu_selected].setFillColor(Color::White);
    main_menu_selected--;
    if (main_menu_selected < 0)
        main_menu_selected = Max_main_menu - 1;
    main_menu[main_menu_selected].setFillColor(Color::Green);
}

/**
 * @brief Cambia la selección del menú hacia abajo.
 * 
 * Modifica el color para reflejar la nueva opción seleccionada,
 * implementando un ciclo continuo cuando se supera el límite inferior.
 */
void Menu::MoveDown() {
    main_menu[main_menu_selected].setFillColor(Color::White);
    main_menu_selected++;
    if (main_menu_selected >= Max_main_menu)
        main_menu_selected = 0;
    main_menu[main_menu_selected].setFillColor(Color::Green);
}

/**
 * @brief Inicia la reproducción de la música de fondo del menú.
 * 
 * Intenta cargar el archivo de audio especificado y, en caso de éxito,
 * ajusta el volumen y reproduce la música.
 * En caso de error, muestra un mensaje en la consola.
 */
void Menu::PlayMusic() {
    if (!menuMusic.openFromFile("Music/menu.ogg")) {
        std::cerr << "Error al cargar la música del menú.\n";
    } else {
        menuMusic.setVolume(60);
        menuMusic.play();
    }
}

/**
 * @brief Detiene la reproducción de la música de fondo del menú.
 */
void Menu::StopMusic() {
    menuMusic.stop();
}
int Menu::getSelectedOption() const {
    return main_menu_selected;
}
