#include "Game.h"
#include <SFML/Audio.hpp>
#include<string.h>
#include<iostream>
#define START_X 200
#define START_Y 680
#include<Font.h>
Game::Game(Sky *sky)
{
    this->sky=sky;
    Score.setColor(sf::Color::Red);
    GameOver_Text.setColor(sf::Color::Green);
    this->Score.setFont(Font::Font_Score);
    GameOver_Text.setFont(Font::Font_DEAD);
    GameOver_Text.setScale(1.2,1.2);
    GameOver_Text.setPosition(this->sky->getGlobalBounds().height/10.0,this->sky->getGlobalBounds().height/3.0);
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

	while (sky->window->pollEvent(event)){
		// Close window: exit

		if(gameOverFlat==1){

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1) {
                    init();
                    break;
                }



            }else{


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



    }

        if(gameOverFlat==1&&waitingForReset==0){
                showGameOver();
                waitingForReset=1;
                continue;
        }else if(gameOverFlat==0){
                sky->createEnemies();
                sky->moveBullet();
                sky->clearBullet();
                sky->refresh();

                if(sky->isEnd()){

                    if(sky->player->dead()){
                        gameOverFlat=1;
                        sky->player->setPosition(START_X,START_Y);
                        sky->clearEnemyAndBullet();
                        sky->window->clear();
                        continue;

                    }
                    sky->player->setPosition(START_X,START_Y);
                    sky->clearEnemyAndBullet();

                }

                showInfo();

                // Update the window
                sky->window->display();
            }
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
    char str[30];
    sprintf(str,"Score:%d \n life:%d",this->sky->player->getScore(),lifeRemain);
    Score.setString(str);
    this->sky->window->draw(Score);
}

void Game::showGameOver(){

    char str[80];
    sprintf(str,"YOUR ARE DEAD!!! \n YOUR Score:%d \n Pause F1 to replay",this->sky->player->getScore());
    GameOver_Text.setString(str);
    sky->window->draw(GameOver_Text);
    sky->window->display();


}
void Game::init(){
    gameOverFlat=0;
    waitingForReset=0;
    sky->player->init();

}
