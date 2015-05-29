#include "Game.h"
#include <SFML/Audio.hpp>
#include<string.h>
#include<iostream>
#define START_X 200
#define START_Y 680
#include<Font.h>
#include<Mission.h>
Game::Game(Sky *sky)
{
    this->sky=sky;
    Score.setColor(sf::Color::Red);
    GameOver_Text.setColor(sf::Color::Green);
    this->Score.setFont(Font::Font_Score);
    GameOver_Text.setFont(Font::Font_DEAD);
    GameOver_Text.setScale(1.2,1.2);
    GameOver_Text.setPosition(this->sky->getGlobalBounds().height/10.0,this->sky->getGlobalBounds().height/3.0);
    this->lifeRemain=this->sky->player->lifeTime;

    //ctor
}

Game::~Game()
{
    //dtor
}
void Game::start(){

    this->playMusic();
    while (sky->window->isOpen()){
    //程序最核心代码
	// Process events

	sf::Event event;

	while (sky->window->pollEvent(event)){

            if (event.type == sf::Event::Closed){
                sky->window->close();
                //退出游戏
                return ;
            }


		if(gameOverFlat==1){

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1) {
                    init();//重新开始游戏 F1
                    playMusic();
                    break;
                }

            }else{

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                    //向左
                    if(this->sky->player->getPosition().x>0){
                        sky->player->move('A');

                    }


                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                    //向右

                    if(this->sky->player->getPosition().x<this->sky->getTextureRect().width-170){
                        sky->player->move('D');
                    }
                }



                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                    //向左
                    if(this->sky->player->getPosition().y>0){
                        sky->player->move('W');

                    }


                }


                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                    //向右

                    if(this->sky->player->getPosition().y<(this->sky->window->getSize().y-this->sky->player->getGlobalBounds().height)){
                        sky->player->move('S');
                    }
                }


                if (event.type == sf::Event::KeyPressed  && event.key.code == sf::Keyboard::Space) {

                    this->sky->player->isFiring=!(this->sky->player->isFiring);

                }


            }



    }

        if(this->sky->player->isFiring){
             this->sky->player->fire();

        }


        if(gameOverFlat==1&&waitingForReset==0){
                showGameOver();
                waitingForReset=1;
                continue;
        }else if(gameOverFlat==0){
               cheakNextMission();
                if(sky->isEnd()){

                    sky->player->isFiring=false;
                    if(sky->player->dead()){
                        gameOverFlat=1;
                        stopMusic();
                        sky->player->setPosition(START_X,START_Y);
                        sky->clearEnemyAndBullet();
                        sky->window->clear();
                        continue;
                    }
                    sky->player->setPosition(START_X,START_Y);
                    sky->clearEnemyAndBullet();


                }

                sky->createEnemies();//随机生成敌机
                sky->enemyRandFire();
                sky->moveBullet();//移动所有子弹
                sky->clearBullet();//子弹边界处理
                sky->itemMoveAndCheak();
                sky->refresh();//刷新显示

                showInfo();//显示当前分数信息

                // Update the window
                sky->window->display();
            }
    }


}



void Game::playMusic(){
    this->BGM.play();
}

void Game::stopMusic(){
    this->BGM.stop();
}
void Game::showInfo(){
    this->lifeRemain=this->sky->player->lifeTime;
    char str[80];
    sprintf(str,"Mission:%d \nScore:%d \n life:%d",this->MissionOfNow,this->sky->player->getScore(),lifeRemain);
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
    MissionOfNow=0;
    sky->player->init();

}
void Game::cheakNextMission(){

                if(MissionOfNow==7){
                    std::cout<<"END";

                }else{
                    if(this->sky->player->getScore()>=Mission::listOfMission[MissionOfNow].Score){
                            this->sky->player->addLife(Mission::listOfMission[MissionOfNow].addLife);
                            this->sky->player->setSpeed(Mission::listOfMission[MissionOfNow].PlayerSpeed);
                            this->sky->player->setfireDensity(Mission::listOfMission[MissionOfNow].playerFireSpeed);
                            this->sky->player->setFireSpeed(Mission::listOfMission[MissionOfNow].playerDulletSpeed);
                            this->sky->setEnemyCreateRate(Mission::listOfMission[MissionOfNow].enemyCreateRate);
                            this->sky->setEnemySpeed(Mission::listOfMission[MissionOfNow].enemySpeed);
                            this->sky->setEnemyFireRate(Mission::listOfMission[MissionOfNow].enemyFireRate);
                            this->sky->setEnemyBulletSpeed(Mission::listOfMission[MissionOfNow].enemyBulletSpeed);
                            MissionOfNow++;
                            std::cout<<MissionOfNow;

                    }
                }

}
