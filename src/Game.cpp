#include "Game.h"
#include <SFML/Audio.hpp>
#include<string.h>
#include<iostream>
Game::Game(Sky *sky)
{
    this->sky=sky;
    font.loadFromFile("C:\\Windows\\Fonts\\BAUHS93.TTF");
     Score.setColor(sf::Color::Red);
    this->Score.setFont(this->font);
    this->lifeRemain=this->sky->player->getLife();
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
		if (event.type == sf::Event::Closed){
            sky->window->close();
            return ;

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

    if (event.type == sf::Event::KeyPressed  && event.key.code == sf::Keyboard::Space) {
        //up发射子弹,自带连发

        this->sky->player->fire();



    }

    }
	// Clear screen


   sky->refresh();

    if(sky->isEnd()){

        if(sky->player->dead()){
            std::cout<<"END";

        }
        sky->player->setPosition(200,680);
        sky->clearEnemyAndBullet();

    }

    showInfo();

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
void Game::showInfo(){
    this->lifeRemain=this->sky->player->getLife();
    char str[20];
    sprintf(str,"Score:%d \n life:%d",this->sky->player->getScore(),lifeRemain);
    Score.setString(str);
    this->sky->window->draw(Score);
}

