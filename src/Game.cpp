#include "Game.h"
#include <SFML/Audio.hpp>

Game::Game(Sky *sky)
{
    this->sky=sky;
    //ctor
}

Game::~Game()
{
    //dtor
}
void Game::start(){
    this->playMusic();
    while (sky->window->isOpen()){
	// Process events

	sf::Event event;
    sky->createEnemies();
    sky->moveBullet();
    sky->clearBullet();
	while (sky->window->pollEvent(event)){
		// Close window: exit
		if (event.type == sf::Event::Closed)
            sky->window->close();
        }
	// Left  pressed
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        //向左
        if(this->sky->player->getPosition().x>0){
            sky->player->move('A');

        }


    }

    // Right  pressed
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        //向右

        if(this->sky->player->getPosition().x<this->sky->getTextureRect().width-170){
            sky->player->move('D');
        }
    }

    if (event.type == sf::Event::KeyReleased  && event.key.code == sf::Keyboard::Space) {
        //up发射子弹,自带连发

        this->sky->player->fire();



    }




	// Clear screen


   sky->refresh();


	// Update the window
	sky->window->display();
}


}
void Game::pause(){

}


void Game::playMusic(){
    this->BGM.play();
}

void Game::stopMusic(){
    this->BGM.stop();
}

