#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Jugador.hpp"
#include "Bala.hpp"

<<<<<<< Updated upstream
=======
int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;
}
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Jugador.hpp"
#include "Bala.hpp"

>>>>>>> Stashed changes
using namespace std;
using namespace sf;

int main(){
    
    Texture spritesheet;

    if(!spritesheet.loadFromFile("Spritesheet.png")){
        cout<<'error al cargar la textura/n';
    }

    Player player(288,555,spritesheet);

    bool bulletActive = false;
    Bullet bulletPlayer(0,0,spritesheet,IntRect(0,0,0,0),0);
    
    RenderWindow window(Videomode(600, 600), "Space Invaders EPN");
    Window.setFramerateLimit(60);
    

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed) window.close();
        }
        player.update();
        
        if(player.Shoot()&&!bulletActive){
            Bullet bullet(player.Pos().x+24,player.Pos().y-24,spritesheet,IntRect(13*8+16,6*8+6,8,8),-5);
            bulletPlayer = bullet;
            bulletActive = true;
        }

        if(bulletActive) {
            bulletPlayer.Update();
            if(bulletPlayer.Pos().y<-24) bulletActive = false;

        }
        window.clear();
        window.draw(player);

        if(bulletActive) window.draw(bulletPlayer);

        }

        window.display();

    return 0;

    }
